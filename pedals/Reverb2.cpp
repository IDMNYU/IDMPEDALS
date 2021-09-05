#include "Reverb2.h"

namespace Reverb2 {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2016 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Delay m_delay_14;
	Delay m_delay_18;
	Delay m_delay_8;
	Delay m_delay_20;
	Delay m_delay_10;
	Delay m_delay_12;
	Delay m_delay_16;
	Delay m_delay_31;
	Delay m_delay_22;
	Delay m_delay_25;
	Delay m_delay_29;
	Delay m_delay_30;
	Delay m_delay_24;
	Delay m_delay_28;
	Delay m_delay_26;
	Delay m_delay_27;
	Sah __m_sah_32;
	int __exception;
	int vectorsize;
	t_sample m_knob4_fb_3;
	t_sample m_history_11;
	t_sample m_knob1_wetdry_2;
	t_sample m_knob5_fb_1;
	t_sample samplerate;
	t_sample m_knob6_spread_4;
	t_sample m_history_13;
	t_sample m_sw_5;
	t_sample m_knob3_damp_6;
	t_sample m_history_9;
	t_sample m_history_17;
	t_sample m_history_23;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample m_history_7;
	t_sample m_history_15;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_knob5_fb_1 = ((t_sample)0.5);
		m_knob1_wetdry_2 = ((int)0);
		m_knob4_fb_3 = ((t_sample)0.9);
		m_knob6_spread_4 = ((int)0);
		m_sw_5 = ((int)0);
		m_knob3_damp_6 = ((t_sample)0.5);
		m_history_7 = ((int)0);
		m_delay_8.reset("m_delay_8", ((int)4000));
		m_history_9 = ((int)0);
		m_delay_10.reset("m_delay_10", ((int)4000));
		m_history_11 = ((int)0);
		m_delay_12.reset("m_delay_12", ((int)4000));
		m_history_13 = ((int)0);
		m_delay_14.reset("m_delay_14", ((int)4000));
		m_history_15 = ((int)0);
		m_delay_16.reset("m_delay_16", ((int)4000));
		m_history_17 = ((int)0);
		m_delay_18.reset("m_delay_18", ((int)4000));
		m_history_19 = ((int)0);
		m_delay_20.reset("m_delay_20", ((int)4000));
		m_history_21 = ((int)0);
		m_delay_22.reset("m_delay_22", ((int)4000));
		m_history_23 = ((int)0);
		m_delay_24.reset("m_delay_24", ((int)4000));
		m_delay_25.reset("m_delay_25", ((int)4000));
		m_delay_26.reset("m_delay_26", ((int)4000));
		m_delay_27.reset("m_delay_27", ((int)4000));
		m_delay_28.reset("m_delay_28", ((int)4000));
		m_delay_29.reset("m_delay_29", ((int)4000));
		m_delay_30.reset("m_delay_30", ((int)4000));
		m_delay_31.reset("m_delay_31", ((int)4000));
		__m_sah_32.reset(0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		t_sample * __out6 = __outs[5];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample sqrt_3740 = sqrt(m_knob1_wetdry_2);
		t_sample rsub_3744 = (((int)1) - m_knob1_wetdry_2);
		t_sample sqrt_3743 = sqrt(rsub_3744);
		t_sample mul_3739 = (m_knob5_fb_1 * ((t_sample)0.9));
		t_sample mul_3794 = (m_knob5_fb_1 * ((t_sample)0.9));
		t_sample add_3734 = (((int)456) + m_knob6_spread_4);
		t_sample add_3780 = (((int)450) + m_knob6_spread_4);
		t_sample add_3736 = (((int)676) + m_knob6_spread_4);
		t_sample add_3782 = (((int)682) + m_knob6_spread_4);
		t_sample add_3738 = (((int)888) + m_knob6_spread_4);
		t_sample add_3792 = (((int)882) + m_knob6_spread_4);
		t_sample add_3732 = (((int)1106) + m_knob6_spread_4);
		t_sample add_3778 = (((int)1112) + m_knob6_spread_4);
		t_sample add_3785 = (((int)3114) + m_knob6_spread_4);
		t_sample rsub_3747 = (((int)1) - m_knob3_damp_6);
		t_sample add_3784 = (((int)3234) + m_knob6_spread_4);
		t_sample rsub_3807 = (((int)1) - m_knob3_damp_6);
		t_sample add_3786 = (((int)2982) + m_knob6_spread_4);
		t_sample rsub_3823 = (((int)1) - m_knob3_damp_6);
		t_sample add_3787 = (((int)2844) + m_knob6_spread_4);
		t_sample rsub_3830 = (((int)1) - m_knob3_damp_6);
		t_sample add_3788 = (((int)2712) + m_knob6_spread_4);
		t_sample rsub_3842 = (((int)1) - m_knob3_damp_6);
		t_sample add_3789 = (((int)2554) + m_knob6_spread_4);
		t_sample rsub_3855 = (((int)1) - m_knob3_damp_6);
		t_sample add_3790 = (((int)2376) + m_knob6_spread_4);
		t_sample rsub_3867 = (((int)1) - m_knob3_damp_6);
		t_sample add_3791 = (((int)2232) + m_knob6_spread_4);
		t_sample rsub_3881 = (((int)1) - m_knob3_damp_6);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_3799 = __m_sah_32(m_history_7, m_sw_5, ((int)0));
			t_sample gen_3801 = sah_3799;
			t_sample rsub_3797 = (((int)1) - sah_3799);
			t_sample history_3798_next_3800 = fixdenorm(rsub_3797);
			t_sample out3 = gen_3801;
			t_sample add_3804 = (gen_3801 + ((int)1));
			t_sample choice_33 = int(add_3804);
			t_sample gate_3802 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_3803 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_3742 = (gate_3803 * sqrt_3743);
			t_sample mul_3796 = (gate_3803 * ((t_sample)0.015));
			t_sample tap_3754 = m_delay_8.read_linear(add_3785);
			t_sample gen_3776 = tap_3754;
			t_sample mul_3752 = (tap_3754 * m_knob3_damp_6);
			t_sample mul_3750 = (m_history_9 * rsub_3747);
			t_sample add_3751 = (mul_3752 + mul_3750);
			t_sample mul_3748 = (add_3751 * m_knob4_fb_3);
			t_sample add_3755 = (mul_3796 + mul_3748);
			t_sample history_3749_next_3756 = fixdenorm(add_3751);
			t_sample tap_3805 = m_delay_10.read_linear(add_3784);
			t_sample gen_3795 = tap_3805;
			t_sample mul_3812 = (tap_3805 * m_knob3_damp_6);
			t_sample mul_3811 = (m_history_11 * rsub_3807);
			t_sample add_3809 = (mul_3812 + mul_3811);
			t_sample mul_3808 = (add_3809 * m_knob4_fb_3);
			t_sample add_3810 = (mul_3796 + mul_3808);
			t_sample history_3749_next_3806 = fixdenorm(add_3809);
			t_sample tap_3817 = m_delay_12.read_linear(add_3786);
			t_sample gen_3775 = tap_3817;
			t_sample mul_3824 = (tap_3817 * m_knob3_damp_6);
			t_sample mul_3822 = (m_history_13 * rsub_3823);
			t_sample add_3820 = (mul_3824 + mul_3822);
			t_sample mul_3819 = (add_3820 * m_knob4_fb_3);
			t_sample add_3821 = (mul_3796 + mul_3819);
			t_sample history_3749_next_3818 = fixdenorm(add_3820);
			t_sample tap_3836 = m_delay_14.read_linear(add_3787);
			t_sample gen_3774 = tap_3836;
			t_sample mul_3838 = (tap_3836 * m_knob3_damp_6);
			t_sample mul_3835 = (m_history_15 * rsub_3830);
			t_sample add_3831 = (mul_3838 + mul_3835);
			t_sample mul_3833 = (add_3831 * m_knob4_fb_3);
			t_sample add_3832 = (mul_3796 + mul_3833);
			t_sample history_3749_next_3829 = fixdenorm(add_3831);
			t_sample tap_3848 = m_delay_16.read_linear(add_3788);
			t_sample gen_3773 = tap_3848;
			t_sample mul_3850 = (tap_3848 * m_knob3_damp_6);
			t_sample mul_3847 = (m_history_17 * rsub_3842);
			t_sample add_3843 = (mul_3850 + mul_3847);
			t_sample mul_3845 = (add_3843 * m_knob4_fb_3);
			t_sample add_3844 = (mul_3796 + mul_3845);
			t_sample history_3749_next_3841 = fixdenorm(add_3843);
			t_sample tap_3853 = m_delay_18.read_linear(add_3789);
			t_sample gen_3772 = tap_3853;
			t_sample mul_3862 = (tap_3853 * m_knob3_damp_6);
			t_sample mul_3860 = (m_history_19 * rsub_3855);
			t_sample add_3856 = (mul_3862 + mul_3860);
			t_sample mul_3858 = (add_3856 * m_knob4_fb_3);
			t_sample add_3857 = (mul_3796 + mul_3858);
			t_sample history_3749_next_3854 = fixdenorm(add_3856);
			t_sample tap_3865 = m_delay_20.read_linear(add_3790);
			t_sample gen_3771 = tap_3865;
			t_sample mul_3874 = (tap_3865 * m_knob3_damp_6);
			t_sample mul_3871 = (m_history_21 * rsub_3867);
			t_sample add_3868 = (mul_3874 + mul_3871);
			t_sample mul_3870 = (add_3868 * m_knob4_fb_3);
			t_sample add_3869 = (mul_3796 + mul_3870);
			t_sample history_3749_next_3866 = fixdenorm(add_3868);
			t_sample tap_3884 = m_delay_22.read_linear(add_3791);
			t_sample gen_3770 = tap_3884;
			t_sample mul_3879 = (tap_3884 * m_knob3_damp_6);
			t_sample mul_3883 = (m_history_23 * rsub_3881);
			t_sample add_3878 = (mul_3879 + mul_3883);
			t_sample mul_3880 = (add_3878 * m_knob4_fb_3);
			t_sample add_3882 = (mul_3796 + mul_3880);
			t_sample history_3749_next_3877 = fixdenorm(add_3878);
			t_sample pass_3793 = (((((((gen_3770 + gen_3771) + gen_3772) + gen_3773) + gen_3774) + gen_3775) + gen_3795) + gen_3776);
			t_sample tap_3730 = m_delay_24.read_linear(add_3732);
			t_sample sub_3726 = (pass_3793 - tap_3730);
			t_sample mul_3728 = (tap_3730 * mul_3739);
			t_sample add_3727 = (pass_3793 + mul_3728);
			t_sample tap_3891 = m_delay_25.read_linear(add_3738);
			t_sample sub_3890 = (sub_3726 - tap_3891);
			t_sample mul_3889 = (tap_3891 * mul_3739);
			t_sample add_3892 = (sub_3726 + mul_3889);
			t_sample tap_3897 = m_delay_26.read_linear(add_3736);
			t_sample sub_3896 = (sub_3890 - tap_3897);
			t_sample mul_3895 = (tap_3897 * mul_3739);
			t_sample add_3898 = (sub_3890 + mul_3895);
			t_sample tap_3903 = m_delay_27.read_linear(add_3734);
			t_sample sub_3902 = (sub_3896 - tap_3903);
			t_sample mul_3901 = (tap_3903 * mul_3739);
			t_sample add_3904 = (sub_3896 + mul_3901);
			t_sample mul_3721 = (sub_3902 * sqrt_3740);
			t_sample add_3720 = (mul_3742 + mul_3721);
			t_sample out2 = (add_3720 + gate_3802);
			t_sample tap_3909 = m_delay_28.read_linear(add_3778);
			t_sample sub_3908 = (pass_3793 - tap_3909);
			t_sample mul_3907 = (tap_3909 * mul_3794);
			t_sample add_3910 = (pass_3793 + mul_3907);
			t_sample tap_3915 = m_delay_29.read_linear(add_3792);
			t_sample sub_3914 = (sub_3908 - tap_3915);
			t_sample mul_3913 = (tap_3915 * mul_3794);
			t_sample add_3916 = (sub_3908 + mul_3913);
			t_sample tap_3921 = m_delay_30.read_linear(add_3782);
			t_sample sub_3920 = (sub_3914 - tap_3921);
			t_sample mul_3919 = (tap_3921 * mul_3794);
			t_sample add_3922 = (sub_3914 + mul_3919);
			t_sample tap_3927 = m_delay_31.read_linear(add_3780);
			t_sample sub_3926 = (sub_3920 - tap_3927);
			t_sample mul_3925 = (tap_3927 * mul_3794);
			t_sample add_3928 = (sub_3920 + mul_3925);
			t_sample mul_3745 = (sub_3926 * sqrt_3740);
			t_sample add_3741 = (mul_3742 + mul_3745);
			t_sample out1 = (gate_3802 + add_3741);
			m_history_7 = history_3798_next_3800;
			m_delay_31.write(add_3928);
			m_delay_30.write(add_3922);
			m_delay_29.write(add_3916);
			m_delay_28.write(add_3910);
			m_delay_27.write(add_3904);
			m_delay_26.write(add_3898);
			m_delay_25.write(add_3892);
			m_delay_24.write(add_3727);
			m_history_23 = history_3749_next_3877;
			m_delay_22.write(add_3882);
			m_history_21 = history_3749_next_3866;
			m_delay_20.write(add_3869);
			m_history_19 = history_3749_next_3854;
			m_delay_18.write(add_3857);
			m_history_17 = history_3749_next_3841;
			m_delay_16.write(add_3844);
			m_history_15 = history_3749_next_3829;
			m_delay_14.write(add_3832);
			m_history_13 = history_3749_next_3818;
			m_delay_12.write(add_3821);
			m_history_11 = history_3749_next_3806;
			m_delay_10.write(add_3810);
			m_history_9 = history_3749_next_3756;
			m_delay_8.write(add_3755);
			m_delay_8.step();
			m_delay_10.step();
			m_delay_12.step();
			m_delay_14.step();
			m_delay_16.step();
			m_delay_18.step();
			m_delay_20.step();
			m_delay_22.step();
			m_delay_24.step();
			m_delay_25.step();
			m_delay_26.step();
			m_delay_27.step();
			m_delay_28.step();
			m_delay_29.step();
			m_delay_30.step();
			m_delay_31.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			(*(__out6++)) = out6;
			
		};
		return __exception;
		
	};
	inline void set_knob5_fb2(t_param _value) {
		m_knob5_fb_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_4 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 1;
int gen_kernel_numouts = 6;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 6; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_knob1_wetdry(value); break;
		case 1: self->set_knob3_damp(value); break;
		case 2: self->set_knob4_fb1(value); break;
		case 3: self->set_knob5_fb2(value); break;
		case 4: self->set_knob6_spread(value); break;
		case 5: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_wetdry_2; break;
		case 1: *value = self->m_knob3_damp_6; break;
		case 2: *value = self->m_knob4_fb_3; break;
		case 3: *value = self->m_knob5_fb_1; break;
		case 4: *value = self->m_knob6_spread_4; break;
		case 5: *value = self->m_sw_5; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(6 * sizeof(ParamInfo));
	self->__commonstate.numparams = 6;
	// initialize parameter 0 ("m_knob1_wetdry_2")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_damp_6")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_fb_3")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_fb_1")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_spread_4")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_5")
	pi = self->__commonstate.params + 5;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Reverb2::
