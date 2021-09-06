#include "SHComb.h"

namespace SHComb {

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
	Delay m_delay_1;
	Phasor __m_phasor_24;
	Phasor __m_phasor_25;
	Sah __m_sah_22;
	Sah __m_sah_26;
	int __exception;
	int vectorsize;
	t_sample m_history_4;
	t_sample m_sw_18;
	t_sample m_knob4_max_17;
	t_sample m_knob6_r_19;
	t_sample m_sw_16;
	t_sample m_knob3_min_20;
	t_sample samplerate;
	t_sample m_knob1_res_21;
	t_sample samples_to_seconds;
	t_sample m_history_3;
	t_sample m_knob5_r_15;
	t_sample m_history_13;
	t_sample m_history_7;
	t_sample m_history_6;
	t_sample m_history_5;
	t_sample m_history_14;
	t_sample m_history_8;
	t_sample m_history_10;
	t_sample m_history_9;
	t_sample m_history_2;
	t_sample m_history_11;
	t_sample m_history_12;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)6000));
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_knob5_r_15 = ((int)0);
		m_sw_16 = ((int)0);
		m_knob4_max_17 = ((int)0);
		m_sw_18 = ((int)0);
		m_knob6_r_19 = ((int)0);
		m_knob3_min_20 = ((int)0);
		m_knob1_res_21 = ((int)0);
		__m_sah_22.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_24.reset(0);
		__m_phasor_25.reset(0);
		__m_sah_26.reset(0);
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
		t_sample sqrt_3940 = sqrt(m_knob1_res_21);
		t_sample sqrt_3949 = sqrt(sqrt_3940);
		t_sample mul_3953 = (sqrt_3949 * ((t_sample)0.99));
		samples_to_seconds = (1 / samplerate);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample mix_4046 = (m_history_14 + (((t_sample)0.003926980723806) * (m_knob5_r_15 - m_history_14)));
			t_sample mix_3923 = mix_4046;
			t_sample mix_4047 = (m_history_13 + (((t_sample)0.003926980723806) * (mix_3923 - m_history_13)));
			t_sample mix_3921 = mix_4047;
			t_sample mix_4048 = (m_history_12 + (((t_sample)0.003926980723806) * (mix_3921 - m_history_12)));
			t_sample mix_3919 = mix_4048;
			t_sample gen_3935 = mix_3919;
			t_sample history_3924_next_3926 = fixdenorm(mix_3923);
			t_sample history_3922_next_3927 = fixdenorm(mix_3921);
			t_sample history_3920_next_3928 = fixdenorm(mix_3919);
			t_sample expr_3958 = (((int)1) - sqrt((((int)1) - gen_3935)));
			t_sample mix_4049 = (m_history_11 + (((t_sample)0.003926980723806) * (m_knob6_r_19 - m_history_11)));
			t_sample mix_3966 = mix_4049;
			t_sample mix_4050 = (m_history_10 + (((t_sample)0.003926980723806) * (mix_3966 - m_history_10)));
			t_sample mix_3960 = mix_4050;
			t_sample mix_4051 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_3960 - m_history_9)));
			t_sample mix_3963 = mix_4051;
			t_sample gen_3934 = mix_3963;
			t_sample history_3924_next_3964 = fixdenorm(mix_3966);
			t_sample history_3922_next_3965 = fixdenorm(mix_3960);
			t_sample history_3920_next_3962 = fixdenorm(mix_3963);
			t_sample expr_3957 = (((int)1) - sqrt((((int)1) - gen_3934)));
			t_sample sah_3943 = __m_sah_22(m_history_8, m_sw_16, ((int)0));
			t_sample gen_3945 = sah_3943;
			t_sample rsub_3941 = (((int)1) - sah_3943);
			t_sample history_3942_next_3944 = fixdenorm(rsub_3941);
			t_sample out3 = gen_3945;
			t_sample add_3948 = (gen_3945 + ((int)1));
			t_sample choice_23 = int(add_3948);
			t_sample gate_3946 = (((choice_23 >= 1) && (choice_23 < 2)) ? in1 : 0);
			t_sample gate_3947 = ((choice_23 >= 2) ? in1 : 0);
			t_sample mix_4052 = (m_history_7 + (((t_sample)0.003926980723806) * (m_knob3_min_20 - m_history_7)));
			t_sample mix_3975 = mix_4052;
			t_sample mix_4053 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_3975 - m_history_6)));
			t_sample mix_3977 = mix_4053;
			t_sample mix_4054 = (m_history_5 + (((t_sample)0.003926980723806) * (mix_3977 - m_history_5)));
			t_sample mix_3980 = mix_4054;
			t_sample gen_3936 = mix_3980;
			t_sample history_3924_next_3979 = fixdenorm(mix_3975);
			t_sample history_3922_next_3973 = fixdenorm(mix_3977);
			t_sample history_3920_next_3974 = fixdenorm(mix_3980);
			t_sample sub_4058 = (gen_3936 - ((int)0));
			t_sample scale_4055 = ((safepow((sub_4058 * ((t_sample)1)), ((int)1)) * ((int)84)) + ((int)24));
			t_sample mix_4059 = (m_history_4 + (((t_sample)0.003926980723806) * (m_knob4_max_17 - m_history_4)));
			t_sample mix_3989 = mix_4059;
			t_sample mix_4060 = (m_history_3 + (((t_sample)0.003926980723806) * (mix_3989 - m_history_3)));
			t_sample mix_3991 = mix_4060;
			t_sample mix_4061 = (m_history_2 + (((t_sample)0.003926980723806) * (mix_3991 - m_history_2)));
			t_sample mix_3988 = mix_4061;
			t_sample gen_3929 = mix_3988;
			t_sample history_3924_next_3993 = fixdenorm(mix_3989);
			t_sample history_3922_next_3986 = fixdenorm(mix_3991);
			t_sample history_3920_next_3987 = fixdenorm(mix_3988);
			t_sample sub_4065 = (gen_3929 - ((int)0));
			t_sample scale_4062 = ((safepow((sub_4065 * ((t_sample)1)), ((int)1)) * ((int)84)) + ((int)24));
			t_sample mul_3951 = (expr_3958 * ((int)10));
			t_sample phasor_3952 = __m_phasor_24(mul_3951, samples_to_seconds);
			t_sample mul_3913 = (expr_3957 * ((int)10));
			t_sample phasor_3914 = __m_phasor_25(mul_3913, samples_to_seconds);
			t_sample sah_3915 = __m_sah_26(phasor_3952, phasor_3914, ((t_sample)0.5));
			t_sample orange_4068 = (scale_4062 - scale_4055);
			t_sample sub_4069 = (sah_3915 - ((int)0));
			t_sample scale_4066 = ((safepow((sub_4069 * ((t_sample)1)), ((int)1)) * orange_4068) + scale_4055);
			t_sample round_3933 = round(scale_4066);
			t_sample switch_3911 = (m_sw_18 ? round_3933 : scale_4066);
			t_sample mtof_3932 = mtof(switch_3911, ((int)440));
			t_sample rdiv_3931 = safediv(((int)1000), mtof_3932);
			t_sample mstosamps_3930 = (rdiv_3931 * (samplerate * 0.001));
			t_sample tap_3956 = m_delay_1.read_linear(mstosamps_3930);
			t_sample add_3939 = (gate_3947 + tap_3956);
			t_sample div_3938 = (add_3939 * ((t_sample)0.5));
			t_sample out1 = (div_3938 + gate_3946);
			t_sample out2 = (div_3938 + gate_3946);
			t_sample mul_3954 = (tap_3956 * mul_3953);
			m_history_14 = history_3924_next_3926;
			m_history_12 = history_3920_next_3928;
			m_history_13 = history_3922_next_3927;
			m_history_11 = history_3924_next_3964;
			m_history_9 = history_3920_next_3962;
			m_history_10 = history_3922_next_3965;
			m_history_8 = history_3942_next_3944;
			m_history_7 = history_3924_next_3979;
			m_history_5 = history_3920_next_3974;
			m_history_6 = history_3922_next_3973;
			m_history_4 = history_3924_next_3993;
			m_history_2 = history_3920_next_3987;
			m_history_3 = history_3922_next_3986;
			m_delay_1.write((mul_3954 + gate_3947));
			m_delay_1.step();
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
	inline void set_knob5_r1(t_param _value) {
		m_knob5_r_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_max(t_param _value) {
		m_knob4_max_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_r2(t_param _value) {
		m_knob6_r_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_min(t_param _value) {
		m_knob3_min_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_res(t_param _value) {
		m_knob1_res_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 7; }

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
		case 0: self->set_knob1_res(value); break;
		case 1: self->set_knob3_min(value); break;
		case 2: self->set_knob4_max(value); break;
		case 3: self->set_knob5_r1(value); break;
		case 4: self->set_knob6_r2(value); break;
		case 5: self->set_sw1(value); break;
		case 6: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_res_21; break;
		case 1: *value = self->m_knob3_min_20; break;
		case 2: *value = self->m_knob4_max_17; break;
		case 3: *value = self->m_knob5_r_15; break;
		case 4: *value = self->m_knob6_r_19; break;
		case 5: *value = self->m_sw_16; break;
		case 6: *value = self->m_sw_18; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(7 * sizeof(ParamInfo));
	self->__commonstate.numparams = 7;
	// initialize parameter 0 ("m_knob1_res_21")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_res_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_min_20")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_min";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_min_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_max_17")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_max";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_max_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_r_15")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_r1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_r_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_r_19")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_r2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_r_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_16")
	pi = self->__commonstate.params + 5;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_sw_18")
	pi = self->__commonstate.params + 6;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_18;
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


} // SHComb::
