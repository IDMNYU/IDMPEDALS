#include "Wah.h"

namespace Wah {

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
	Phasor __m_phasor_31;
	Sah __m_sah_26;
	SineCycle __m_cycle_32;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_knob4_depth_21;
	t_sample m_s_3;
	t_sample m_knob5_rate_22;
	t_sample m_knob6_res_20;
	t_sample m_history_19;
	t_sample m_knob3_manual_23;
	t_sample m_sw_24;
	t_sample m_sw_25;
	t_sample samples_to_seconds;
	t_sample m_history_18;
	t_sample __m_slide_28;
	t_sample samplerate;
	t_sample m_s_2;
	t_sample m_history_17;
	t_sample m_history_15;
	t_sample m_s_7;
	t_sample m_slim_8;
	t_sample m_s_6;
	t_sample m_s_4;
	t_sample m_s_5;
	t_sample m_history_16;
	t_sample m_s_9;
	t_sample m_rc_11;
	t_sample m_s_1;
	t_sample m_previn_10;
	t_sample m_history_13;
	t_sample m_fc_12;
	t_sample m_history_14;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_s_1 = ((int)0);
		m_s_2 = ((int)0);
		m_s_3 = ((int)0);
		m_s_4 = ((int)0);
		m_s_5 = ((int)0);
		m_s_6 = ((int)0);
		m_s_7 = ((int)0);
		m_slim_8 = ((int)0);
		m_s_9 = ((int)0);
		m_previn_10 = ((int)0);
		m_rc_11 = ((int)0);
		m_fc_12 = ((int)1);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_knob6_res_20 = 0.5;
		m_knob4_depth_21 = 1;
		m_knob5_rate_22 = 0.1;
		m_knob3_manual_23 = 0;
		m_sw_24 = ((int)0);
		m_sw_25 = ((int)0);
		__m_sah_26.reset(0);
		__m_slide_28 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_31.reset(0);
		__m_cycle_32.reset(samplerate, 0);
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
		t_sample add_3912 = (m_sw_24 + ((int)1));
		t_sample mstosamps_3910 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_3909 = (((int)100) * (samplerate * 0.001));
		t_sample iup_29 = (1 / maximum(1, abs(mstosamps_3910)));
		t_sample idown_30 = (1 / maximum(1, abs(mstosamps_3909)));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_33 = int(add_3912);
		t_sample minb_34 = ((((t_sample)1e-05) < m_knob6_res_20) ? m_knob6_res_20 : ((t_sample)1e-05));
		t_sample maxb_35 = safediv(((t_sample)12.5), samplerate);
		t_sample minb_36 = ((((t_sample)0.0001) < maxb_35) ? maxb_35 : ((t_sample)0.0001));
		t_sample expr_3815 = sqrt(((minb_36 < ((int)1)) ? minb_36 : ((int)1)));
		t_sample expr_3814 = (((int)-1) * log(expr_3815));
		int min_39 = (-1);
		int min_42 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_3921 = __m_sah_26(m_history_19, m_sw_25, ((int)0));
			t_sample gen_3923 = sah_3921;
			t_sample rsub_3919 = (((int)1) - sah_3921);
			t_sample history_3920_next_3922 = fixdenorm(rsub_3919);
			t_sample out3 = gen_3923;
			t_sample add_3924 = (gen_3923 + ((int)1));
			t_sample choice_27 = int(add_3924);
			t_sample gate_3916 = (((choice_27 >= 1) && (choice_27 < 2)) ? in1 : 0);
			t_sample gate_3917 = ((choice_27 >= 2) ? in1 : 0);
			t_sample mix_4003 = (m_history_18 + (((t_sample)0.003926980723806) * (m_knob3_manual_23 - m_history_18)));
			t_sample mix_3785 = mix_4003;
			t_sample mix_4004 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_3785 - m_history_17)));
			t_sample mix_3783 = mix_4004;
			t_sample mix_4005 = (m_history_16 + (((t_sample)0.003926980723806) * (mix_3783 - m_history_16)));
			t_sample mix_3781 = mix_4005;
			t_sample gen_3793 = mix_3781;
			t_sample history_3787_next_3790 = fixdenorm(mix_3785);
			t_sample history_3784_next_3791 = fixdenorm(mix_3783);
			t_sample history_3782_next_3792 = fixdenorm(mix_3781);
			t_sample abs_3915 = fabs(gate_3917);
			__m_slide_28 = fixdenorm((__m_slide_28 + (((abs_3915 > __m_slide_28) ? iup_29 : idown_30) * (abs_3915 - __m_slide_28))));
			t_sample slide_3914 = __m_slide_28;
			t_sample mul_3911 = (slide_3914 * ((int)10));
			t_sample clamp_3780 = ((mul_3911 <= ((int)0)) ? ((int)0) : ((mul_3911 >= ((int)1)) ? ((int)1) : mul_3911));
			t_sample mix_4006 = (m_history_15 + (((t_sample)0.003926980723806) * (m_knob5_rate_22 - m_history_15)));
			t_sample mix_3942 = mix_4006;
			t_sample mix_4007 = (m_history_14 + (((t_sample)0.003926980723806) * (mix_3942 - m_history_14)));
			t_sample mix_3934 = mix_4007;
			t_sample mix_4008 = (m_history_13 + (((t_sample)0.003926980723806) * (mix_3934 - m_history_13)));
			t_sample mix_3932 = mix_4008;
			t_sample gen_3906 = mix_3932;
			t_sample history_3787_next_3935 = fixdenorm(mix_3942);
			t_sample history_3784_next_3940 = fixdenorm(mix_3934);
			t_sample history_3782_next_3937 = fixdenorm(mix_3932);
			t_sample rsub_3927 = (((int)1) - gen_3906);
			t_sample sqrt_3926 = sqrt(rsub_3927);
			t_sample rsub_3925 = (((int)1) - sqrt_3926);
			t_sample mul_3931 = (rsub_3925 * ((int)10));
			t_sample phasor_3930 = __m_phasor_31(mul_3931, samples_to_seconds);
			__m_cycle_32.phase(phasor_3930);
			t_sample cycle_3904 = __m_cycle_32(__sinedata);
			t_sample cycleindex_3905 = __m_cycle_32.phase();
			t_sample sub_4012 = (cycle_3904 - (-1));
			t_sample scale_4009 = ((safepow((sub_4012 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_3779 = scale_4009;
			t_sample selector_3913 = ((choice_33 >= 2) ? clamp_3780 : ((choice_33 >= 1) ? scale_3779 : 0));
			t_sample mul_3903 = (selector_3913 * m_knob4_depth_21);
			t_sample add_3795 = (mul_3903 + gen_3793);
			t_sample clamp_3794 = ((add_3795 <= ((int)0)) ? ((int)0) : ((add_3795 >= ((int)1)) ? ((int)1) : add_3795));
			t_sample sub_4016 = (clamp_3794 - ((int)0));
			t_sample scale_4013 = ((safepow((sub_4016 * ((t_sample)1)), ((int)1)) * ((int)120)) + ((int)15));
			t_sample scale_3796 = scale_4013;
			t_sample expr_3890 = (((((t_sample)1.05) * ((minb_34 < ((int)1)) ? minb_34 : ((int)1))) - m_rc_11) * ((t_sample)0.25));
			t_sample add_3859 = (m_rc_11 + expr_3890);
			t_sample fixdenorm_3820 = fixdenorm(m_previn_10);
			t_sample noise_3819 = noise();
			t_sample expr_3875 = (gate_3917 + (((t_sample)1e-11) * noise_3819));
			t_sample gen_3818 = m_fc_12;
			t_sample mul_3802 = (scale_3796 * ((t_sample)0.90193));
			t_sample add_3799 = (mul_3802 + ((t_sample)7.29));
			t_sample div_3798 = (add_3799 * ((t_sample)0.0078740157480315));
			t_sample clamp_3804 = ((div_3798 <= ((int)0)) ? ((int)0) : ((div_3798 >= ((t_sample)0.99)) ? ((t_sample)0.99) : div_3798));
			t_sample mul_3803 = (clamp_3804 * expr_3814);
			t_sample expr_3816 = (((t_sample)0.99999636) + ((((t_sample)0.031261316) + ((((t_sample)0.00048274797) + (((t_sample)5.949053e-06) * mul_3803)) * mul_3803)) * mul_3803));
			t_sample mul_3811 = (expr_3816 * expr_3816);
			t_sample mul_3810 = (mul_3811 * mul_3811);
			t_sample mul_3809 = (mul_3810 * mul_3810);
			t_sample mul_3808 = (mul_3809 * mul_3809);
			t_sample mul_3807 = (mul_3808 * mul_3808);
			t_sample mul_3801 = (mul_3807 * expr_3815);
			t_sample sub_3800 = (mul_3801 - m_fc_12);
			t_sample div_3797 = (sub_3800 * ((t_sample)0.5));
			t_sample add_3813 = (m_fc_12 + div_3797);
			t_sample fc_next_3817 = fixdenorm(add_3813);
			t_sample expr_3889 = (gen_3818 * gen_3818);
			t_sample expr_3888 = (expr_3889 * (((int)1) - m_rc_11));
			t_sample expr_3887 = (expr_3889 + (expr_3888 * expr_3888));
			t_sample expr_3886 = ((((t_sample)1.25) + ((((t_sample)-0.74375) + (((t_sample)0.3) * expr_3887)) * expr_3887)) * expr_3887);
			t_sample expr_3885 = (m_rc_11 * (((t_sample)1.4) + ((((t_sample)0.108) + ((((t_sample)-0.164) - (((t_sample)0.069) * expr_3886)) * expr_3886)) * expr_3886)));
			t_sample expr_3884 = (((t_sample)0.18) + (((t_sample)0.25) * (expr_3885 * expr_3885)));
			t_sample expr_3883 = ((fixdenorm_3820 * expr_3884) - (expr_3885 * m_s_3));
			t_sample maxb_37 = (((((t_sample)0.062) * expr_3883) * expr_3883) + (((t_sample)0.993) * m_slim_8));
			t_sample minb_38 = ((((int)-1) < maxb_37) ? maxb_37 : ((int)-1));
			t_sample expr_3882 = ((minb_38 < ((int)1)) ? minb_38 : ((int)1));
			t_sample expr_3881 = (expr_3883 * ((((int)1) - expr_3882) + ((((t_sample)0.5) * expr_3882) * expr_3882)));
			t_sample rsub_3860 = (((int)1) - expr_3886);
			t_sample expr_3880 = ((expr_3881 * expr_3886) + (rsub_3860 * m_s_7));
			t_sample mul_3842 = (m_s_4 * ((t_sample)0.3));
			t_sample mul_3835 = (expr_3880 * ((t_sample)0.3));
			t_sample mul_3845 = (m_s_5 * ((t_sample)0.3));
			t_sample mul_3853 = (m_s_7 * ((t_sample)0.3));
			t_sample add_3851 = (expr_3880 + mul_3853);
			t_sample expr_3879 = ((add_3851 * expr_3886) + (rsub_3860 * m_s_6));
			t_sample mul_3850 = (m_s_6 * ((t_sample)0.3));
			t_sample add_3848 = (expr_3879 + mul_3850);
			t_sample clamp_3847 = ((add_3848 <= min_39) ? min_39 : ((add_3848 >= ((int)1)) ? ((int)1) : add_3848));
			t_sample expr_3878 = (clamp_3847 * (((int)1) - ((((t_sample)0.3333333) * clamp_3847) * clamp_3847)));
			t_sample expr_3877 = ((expr_3878 * expr_3886) + (rsub_3860 * m_s_5));
			t_sample add_3843 = (expr_3877 + mul_3845);
			t_sample expr_3876 = ((add_3843 * expr_3886) + (rsub_3860 * m_s_4));
			t_sample add_3840 = (expr_3876 + mul_3842);
			t_sample expr_3874 = ((expr_3875 * expr_3884) - (expr_3885 * add_3840));
			t_sample maxb_40 = (((((t_sample)0.062) * expr_3874) * expr_3874) + (((t_sample)0.993) * expr_3882));
			t_sample minb_41 = ((((int)-1) < maxb_40) ? maxb_40 : ((int)-1));
			t_sample expr_3873 = ((minb_41 < ((int)1)) ? minb_41 : ((int)1));
			t_sample expr_3872 = (expr_3874 * ((((int)1) - expr_3873) + ((((t_sample)0.5) * expr_3873) * expr_3873)));
			t_sample expr_3871 = ((expr_3872 * expr_3886) + (rsub_3860 * expr_3880));
			t_sample add_3833 = (expr_3871 + mul_3835);
			t_sample expr_3870 = ((add_3833 * expr_3886) + (rsub_3860 * expr_3879));
			t_sample mul_3824 = (expr_3876 * ((t_sample)0.3));
			t_sample mul_3827 = (expr_3877 * ((t_sample)0.3));
			t_sample mul_3832 = (expr_3879 * ((t_sample)0.3));
			t_sample add_3830 = (expr_3870 + mul_3832);
			t_sample clamp_3829 = ((add_3830 <= min_42) ? min_42 : ((add_3830 >= ((int)1)) ? ((int)1) : add_3830));
			t_sample expr_3869 = (clamp_3829 * (((int)1) - ((((t_sample)0.3333333) * clamp_3829) * clamp_3829)));
			t_sample expr_3868 = ((expr_3869 * expr_3886) + (rsub_3860 * expr_3877));
			t_sample add_3825 = (expr_3868 + mul_3827);
			t_sample expr_3867 = ((add_3825 * expr_3886) + (rsub_3860 * expr_3876));
			t_sample add_3822 = (expr_3867 + mul_3824);
			t_sample expr_3866 = (((((t_sample)0.19) * (add_3822 + m_s_9)) + (((t_sample)0.57) * (add_3840 + m_s_1))) - (((t_sample)0.52) * m_s_2));
			t_sample gen_3902 = expr_3866;
			t_sample rc_next_3891 = fixdenorm(add_3859);
			t_sample previn_next_3892 = fixdenorm(expr_3875);
			t_sample s8_next_3893 = fixdenorm(add_3840);
			t_sample slim_next_3894 = fixdenorm(expr_3873);
			t_sample s1_next_3895 = fixdenorm(expr_3871);
			t_sample s2_next_3896 = fixdenorm(expr_3870);
			t_sample s3_next_3897 = fixdenorm(expr_3868);
			t_sample s4_next_3898 = fixdenorm(expr_3867);
			t_sample s5_next_3899 = fixdenorm(add_3822);
			t_sample s6_next_3900 = fixdenorm(expr_3866);
			t_sample s7_next_3901 = fixdenorm(add_3822);
			t_sample add_3928 = (gen_3902 + gate_3916);
			t_sample out2 = add_3928;
			t_sample add_3929 = (gen_3902 + gate_3916);
			t_sample out1 = add_3929;
			m_history_19 = history_3920_next_3922;
			m_history_18 = history_3787_next_3790;
			m_history_16 = history_3782_next_3792;
			m_history_17 = history_3784_next_3791;
			m_history_15 = history_3787_next_3935;
			m_history_13 = history_3782_next_3937;
			m_history_14 = history_3784_next_3940;
			m_fc_12 = fc_next_3817;
			m_s_1 = s7_next_3901;
			m_s_2 = s6_next_3900;
			m_s_3 = s5_next_3899;
			m_s_4 = s4_next_3898;
			m_s_5 = s3_next_3897;
			m_s_6 = s2_next_3896;
			m_s_7 = s1_next_3895;
			m_slim_8 = slim_next_3894;
			m_s_9 = s8_next_3893;
			m_previn_10 = previn_next_3892;
			m_rc_11 = rc_next_3891;
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
	inline void set_knob6_res(t_param _value) {
		m_knob6_res_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_depth(t_param _value) {
		m_knob4_depth_21 = (_value < -1 ? -1 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_rate(t_param _value) {
		m_knob5_rate_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_manual(t_param _value) {
		m_knob3_manual_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_knob3_manual(value); break;
		case 1: self->set_knob4_depth(value); break;
		case 2: self->set_knob5_rate(value); break;
		case 3: self->set_knob6_res(value); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_manual_23; break;
		case 1: *value = self->m_knob4_depth_21; break;
		case 2: *value = self->m_knob5_rate_22; break;
		case 3: *value = self->m_knob6_res_20; break;
		case 4: *value = self->m_sw_25; break;
		case 5: *value = self->m_sw_24; break;
		
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
	// initialize parameter 0 ("m_knob3_manual_23")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_manual";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_manual_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_depth_21")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_depth_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -1;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_rate_22")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_rate_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_res_20")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_res_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_25")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_24")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_24;
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


} // Wah::
