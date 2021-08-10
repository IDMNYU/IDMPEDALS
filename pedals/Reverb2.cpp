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
	t_sample m_knob6_spread_3;
	t_sample m_history_11;
	t_sample m_knob1_wetdry_2;
	t_sample m_knob3_damp_1;
	t_sample samplerate;
	t_sample m_sw_4;
	t_sample m_history_13;
	t_sample m_knob5_fb_5;
	t_sample m_knob4_fb_6;
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
		m_knob3_damp_1 = ((t_sample)0.5);
		m_knob1_wetdry_2 = ((int)0);
		m_knob6_spread_3 = ((int)0);
		m_sw_4 = ((int)0);
		m_knob5_fb_5 = ((t_sample)0.5);
		m_knob4_fb_6 = ((t_sample)0.9);
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
		t_sample sqrt_2826 = sqrt(m_knob1_wetdry_2);
		t_sample rsub_2830 = (((int)1) - m_knob1_wetdry_2);
		t_sample sqrt_2829 = sqrt(rsub_2830);
		t_sample mul_2880 = (m_knob5_fb_5 * ((t_sample)0.5));
		t_sample mul_2825 = (m_knob5_fb_5 * ((t_sample)0.5));
		t_sample add_2866 = (((int)450) + m_knob6_spread_3);
		t_sample add_2820 = (((int)456) + m_knob6_spread_3);
		t_sample add_2868 = (((int)682) + m_knob6_spread_3);
		t_sample add_2822 = (((int)676) + m_knob6_spread_3);
		t_sample add_2878 = (((int)882) + m_knob6_spread_3);
		t_sample add_2824 = (((int)888) + m_knob6_spread_3);
		t_sample add_2864 = (((int)1112) + m_knob6_spread_3);
		t_sample add_2818 = (((int)1106) + m_knob6_spread_3);
		t_sample add_2871 = (((int)3114) + m_knob6_spread_3);
		t_sample rsub_2833 = (((int)1) - m_knob3_damp_1);
		t_sample add_2870 = (((int)3234) + m_knob6_spread_3);
		t_sample rsub_3997 = (((int)1) - m_knob3_damp_1);
		t_sample add_2872 = (((int)2982) + m_knob6_spread_3);
		t_sample rsub_4009 = (((int)1) - m_knob3_damp_1);
		t_sample add_2873 = (((int)2844) + m_knob6_spread_3);
		t_sample rsub_4021 = (((int)1) - m_knob3_damp_1);
		t_sample add_2874 = (((int)2712) + m_knob6_spread_3);
		t_sample rsub_4033 = (((int)1) - m_knob3_damp_1);
		t_sample add_2875 = (((int)2554) + m_knob6_spread_3);
		t_sample rsub_4045 = (((int)1) - m_knob3_damp_1);
		t_sample add_2876 = (((int)2376) + m_knob6_spread_3);
		t_sample rsub_4057 = (((int)1) - m_knob3_damp_1);
		t_sample add_2877 = (((int)2232) + m_knob6_spread_3);
		t_sample rsub_4069 = (((int)1) - m_knob3_damp_1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_2887 = __m_sah_32(m_history_7, m_sw_4, ((int)0));
			t_sample gen_2889 = sah_2887;
			t_sample rsub_2885 = (((int)1) - sah_2887);
			t_sample history_2886_next_2888 = fixdenorm(rsub_2885);
			t_sample out3 = gen_2889;
			t_sample add_2892 = (gen_2889 + ((int)1));
			t_sample choice_33 = int(add_2892);
			t_sample gate_2890 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_2891 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_2828 = (gate_2891 * sqrt_2829);
			t_sample mul_2882 = (gate_2891 * ((t_sample)0.015));
			t_sample tap_2840 = m_delay_8.read_linear(add_2871);
			t_sample gen_2862 = tap_2840;
			t_sample mul_2838 = (tap_2840 * m_knob3_damp_1);
			t_sample mul_2836 = (m_history_9 * rsub_2833);
			t_sample add_2837 = (mul_2838 + mul_2836);
			t_sample mul_2834 = (add_2837 * m_knob4_fb_6);
			t_sample add_2841 = (mul_2882 + mul_2834);
			t_sample history_2835_next_2842 = fixdenorm(add_2837);
			t_sample tap_4004 = m_delay_10.read_linear(add_2870);
			t_sample gen_3834 = tap_4004;
			t_sample mul_4002 = (tap_4004 * m_knob3_damp_1);
			t_sample mul_4000 = (m_history_11 * rsub_3997);
			t_sample add_3999 = (mul_4002 + mul_4000);
			t_sample mul_4003 = (add_3999 * m_knob4_fb_6);
			t_sample add_4001 = (mul_2882 + mul_4003);
			t_sample history_2835_next_3998 = fixdenorm(add_3999);
			t_sample tap_4016 = m_delay_12.read_linear(add_2872);
			t_sample gen_2861 = tap_4016;
			t_sample mul_4013 = (tap_4016 * m_knob3_damp_1);
			t_sample mul_4012 = (m_history_13 * rsub_4009);
			t_sample add_4014 = (mul_4013 + mul_4012);
			t_sample mul_4015 = (add_4014 * m_knob4_fb_6);
			t_sample add_4011 = (mul_2882 + mul_4015);
			t_sample history_2835_next_4010 = fixdenorm(add_4014);
			t_sample tap_4024 = m_delay_14.read_linear(add_2873);
			t_sample gen_2860 = tap_4024;
			t_sample mul_4030 = (tap_4024 * m_knob3_damp_1);
			t_sample mul_4022 = (m_history_15 * rsub_4021);
			t_sample add_4028 = (mul_4030 + mul_4022);
			t_sample mul_4023 = (add_4028 * m_knob4_fb_6);
			t_sample add_4029 = (mul_2882 + mul_4023);
			t_sample history_2835_next_4027 = fixdenorm(add_4028);
			t_sample tap_4036 = m_delay_16.read_linear(add_2874);
			t_sample gen_2859 = tap_4036;
			t_sample mul_4042 = (tap_4036 * m_knob3_damp_1);
			t_sample mul_4034 = (m_history_17 * rsub_4033);
			t_sample add_4040 = (mul_4042 + mul_4034);
			t_sample mul_4035 = (add_4040 * m_knob4_fb_6);
			t_sample add_4041 = (mul_2882 + mul_4035);
			t_sample history_2835_next_4039 = fixdenorm(add_4040);
			t_sample tap_4048 = m_delay_18.read_linear(add_2875);
			t_sample gen_2858 = tap_4048;
			t_sample mul_4053 = (tap_4048 * m_knob3_damp_1);
			t_sample mul_4046 = (m_history_19 * rsub_4045);
			t_sample add_4051 = (mul_4053 + mul_4046);
			t_sample mul_4047 = (add_4051 * m_knob4_fb_6);
			t_sample add_4052 = (mul_2882 + mul_4047);
			t_sample history_2835_next_4050 = fixdenorm(add_4051);
			t_sample tap_4060 = m_delay_20.read_linear(add_2876);
			t_sample gen_2857 = tap_4060;
			t_sample mul_4062 = (tap_4060 * m_knob3_damp_1);
			t_sample mul_4058 = (m_history_21 * rsub_4057);
			t_sample add_4065 = (mul_4062 + mul_4058);
			t_sample mul_4059 = (add_4065 * m_knob4_fb_6);
			t_sample add_4066 = (mul_2882 + mul_4059);
			t_sample history_2835_next_4064 = fixdenorm(add_4065);
			t_sample tap_4071 = m_delay_22.read_linear(add_2877);
			t_sample gen_2856 = tap_4071;
			t_sample mul_4072 = (tap_4071 * m_knob3_damp_1);
			t_sample mul_4074 = (m_history_23 * rsub_4069);
			t_sample add_4076 = (mul_4072 + mul_4074);
			t_sample mul_4070 = (add_4076 * m_knob4_fb_6);
			t_sample add_4077 = (mul_2882 + mul_4070);
			t_sample history_2835_next_4073 = fixdenorm(add_4076);
			t_sample pass_2879 = (((((((gen_2856 + gen_2857) + gen_2858) + gen_2859) + gen_2860) + gen_2861) + gen_3834) + gen_2862);
			t_sample tap_2816 = m_delay_24.read_linear(add_2864);
			t_sample sub_2812 = (pass_2879 - tap_2816);
			t_sample mul_2814 = (tap_2816 * mul_2880);
			t_sample add_2813 = (pass_2879 + mul_2814);
			t_sample tap_4084 = m_delay_25.read_linear(add_2878);
			t_sample sub_4081 = (sub_2812 - tap_4084);
			t_sample mul_4083 = (tap_4084 * mul_2880);
			t_sample add_4085 = (sub_2812 + mul_4083);
			t_sample tap_4090 = m_delay_26.read_linear(add_2868);
			t_sample sub_4087 = (sub_4081 - tap_4090);
			t_sample mul_4089 = (tap_4090 * mul_2880);
			t_sample add_4091 = (sub_4081 + mul_4089);
			t_sample tap_4096 = m_delay_27.read_linear(add_2866);
			t_sample sub_4093 = (sub_4087 - tap_4096);
			t_sample mul_4095 = (tap_4096 * mul_2880);
			t_sample add_4097 = (sub_4087 + mul_4095);
			t_sample mul_2831 = (sub_4093 * sqrt_2826);
			t_sample add_2827 = (mul_2828 + mul_2831);
			t_sample out1 = (gate_2890 + add_2827);
			t_sample tap_4102 = m_delay_28.read_linear(add_2818);
			t_sample sub_4099 = (pass_2879 - tap_4102);
			t_sample mul_4101 = (tap_4102 * mul_2825);
			t_sample add_4103 = (pass_2879 + mul_4101);
			t_sample tap_4108 = m_delay_29.read_linear(add_2824);
			t_sample sub_4105 = (sub_4099 - tap_4108);
			t_sample mul_4107 = (tap_4108 * mul_2825);
			t_sample add_4109 = (sub_4099 + mul_4107);
			t_sample tap_4114 = m_delay_30.read_linear(add_2822);
			t_sample sub_4111 = (sub_4105 - tap_4114);
			t_sample mul_4113 = (tap_4114 * mul_2825);
			t_sample add_4115 = (sub_4105 + mul_4113);
			t_sample tap_4120 = m_delay_31.read_linear(add_2820);
			t_sample sub_4117 = (sub_4111 - tap_4120);
			t_sample mul_4119 = (tap_4120 * mul_2825);
			t_sample add_4121 = (sub_4111 + mul_4119);
			t_sample mul_2807 = (sub_4117 * sqrt_2826);
			t_sample add_2806 = (mul_2828 + mul_2807);
			t_sample out2 = (add_2806 + gate_2890);
			m_history_7 = history_2886_next_2888;
			m_delay_31.write(add_4121);
			m_delay_30.write(add_4115);
			m_delay_29.write(add_4109);
			m_delay_28.write(add_4103);
			m_delay_27.write(add_4097);
			m_delay_26.write(add_4091);
			m_delay_25.write(add_4085);
			m_delay_24.write(add_2813);
			m_history_23 = history_2835_next_4073;
			m_delay_22.write(add_4077);
			m_history_21 = history_2835_next_4064;
			m_delay_20.write(add_4066);
			m_history_19 = history_2835_next_4050;
			m_delay_18.write(add_4052);
			m_history_17 = history_2835_next_4039;
			m_delay_16.write(add_4041);
			m_history_15 = history_2835_next_4027;
			m_delay_14.write(add_4029);
			m_history_13 = history_2835_next_4010;
			m_delay_12.write(add_4011);
			m_history_11 = history_2835_next_3998;
			m_delay_10.write(add_4001);
			m_history_9 = history_2835_next_2842;
			m_delay_8.write(add_2841);
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
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_3 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb2(t_param _value) {
		m_knob5_fb_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 1: *value = self->m_knob3_damp_1; break;
		case 2: *value = self->m_knob4_fb_6; break;
		case 3: *value = self->m_knob5_fb_5; break;
		case 4: *value = self->m_knob6_spread_3; break;
		case 5: *value = self->m_sw_4; break;
		
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
	// initialize parameter 1 ("m_knob3_damp_1")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_fb_6")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_fb_5")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_spread_3")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_4")
	pi = self->__commonstate.params + 5;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_4;
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
