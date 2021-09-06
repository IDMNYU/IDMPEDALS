#include "Parametric.h"

namespace Parametric {

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
	Sah __m_sah_19;
	int vectorsize;
	int __exception;
	t_sample m_history_1;
	t_sample m_history_13;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_history_14;
	t_sample m_sw_16;
	t_sample m_knob4_gain_15;
	t_sample m_knob5_Q_17;
	t_sample samplerate;
	t_sample m_history_10;
	t_sample m_knob3_pitch_18;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample m_history_9;
	t_sample m_history_4;
	t_sample m_history_6;
	t_sample m_history_5;
	t_sample m_history_7;
	t_sample m_history_8;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
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
		m_knob4_gain_15 = 0.5;
		m_sw_16 = ((int)0);
		m_knob5_Q_17 = ((int)0);
		m_knob3_pitch_18 = 23;
		__m_sah_19.reset(0);
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
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_3006 = __m_sah_19(m_history_14, m_sw_16, ((int)0));
			t_sample gen_3008 = sah_3006;
			t_sample rsub_3004 = (((int)1) - sah_3006);
			t_sample history_3005_next_3007 = fixdenorm(rsub_3004);
			t_sample out3 = gen_3008;
			t_sample mix_3064 = (m_history_13 + (((t_sample)0.003926980723806) * (m_knob5_Q_17 - m_history_13)));
			t_sample mix_2962 = mix_3064;
			t_sample mix_3065 = (m_history_12 + (((t_sample)0.003926980723806) * (mix_2962 - m_history_12)));
			t_sample mix_2960 = mix_3065;
			t_sample mix_3066 = (m_history_11 + (((t_sample)0.003926980723806) * (mix_2960 - m_history_11)));
			t_sample mix_2958 = mix_3066;
			t_sample gen_2969 = mix_2958;
			t_sample history_2963_next_2965 = fixdenorm(mix_2962);
			t_sample history_2961_next_2966 = fixdenorm(mix_2960);
			t_sample history_2959_next_2967 = fixdenorm(mix_2958);
			t_sample expr_3011 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_2969)))));
			t_sample add_3009 = (gen_3008 + ((int)1));
			t_sample choice_20 = int(add_3009);
			t_sample gate_3002 = (((choice_20 >= 1) && (choice_20 < 2)) ? in1 : 0);
			t_sample gate_3003 = ((choice_20 >= 2) ? in1 : 0);
			t_sample mul_2956 = (expr_3011 * ((int)30));
			t_sample mix_3067 = (m_history_10 + (((t_sample)0.003926980723806) * (m_knob3_pitch_18 - m_history_10)));
			t_sample mix_3015 = mix_3067;
			t_sample mix_3068 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_3015 - m_history_9)));
			t_sample mix_3017 = mix_3068;
			t_sample mix_3069 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_3017 - m_history_8)));
			t_sample mix_3012 = mix_3069;
			t_sample gen_3001 = mix_3012;
			t_sample history_2963_next_3018 = fixdenorm(mix_3015);
			t_sample history_2961_next_3013 = fixdenorm(mix_3017);
			t_sample history_2959_next_3019 = fixdenorm(mix_3012);
			t_sample mtof_3000 = mtof(gen_3001, ((int)440));
			t_sample mix_3070 = (m_history_7 + (((t_sample)0.003926980723806) * (m_knob4_gain_15 - m_history_7)));
			t_sample mix_3026 = mix_3070;
			t_sample mix_3071 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_3026 - m_history_6)));
			t_sample mix_3025 = mix_3071;
			t_sample mix_3072 = (m_history_5 + (((t_sample)0.003926980723806) * (mix_3025 - m_history_5)));
			t_sample mix_3027 = mix_3072;
			t_sample gen_2968 = mix_3027;
			t_sample history_2963_next_3028 = fixdenorm(mix_3026);
			t_sample history_2961_next_3029 = fixdenorm(mix_3025);
			t_sample history_2959_next_3032 = fixdenorm(mix_3027);
			int gt_2955 = (gen_2968 > ((t_sample)0.5));
			t_sample sub_3076 = (gen_2968 - ((t_sample)0.5));
			t_sample scale_3073 = ((safepow((sub_3076 * ((t_sample)2)), ((int)1)) * ((int)19)) + ((int)1));
			t_sample scale_2952 = scale_3073;
			t_sample mul_2953 = (gen_2968 * ((int)2));
			t_sample switch_2954 = (gt_2955 ? scale_2952 : mul_2953);
			t_sample min_2978 = ((mtof_3000 < ((int)0)) ? ((int)0) : mtof_3000);
			t_sample min_2977 = ((switch_2954 < ((int)0)) ? ((int)0) : switch_2954);
			t_sample min_2976 = ((mul_2956 < ((t_sample)1e-06)) ? ((t_sample)1e-06) : mul_2956);
			t_sample omega = safediv((min_2978 * ((t_sample)6.2831853071796)), samplerate);
			t_sample sn = sin(omega);
			t_sample cs = cos(omega);
			t_sample alpha = safediv((sn * ((t_sample)0.5)), min_2976);
			t_sample A = sqrt(min_2977);
			t_sample one_over_A = safediv(((int)1), A);
			t_sample b0 = safediv(((int)1), (((int)1) + (alpha * one_over_A)));
			t_sample a0 = ((((int)1) + (alpha * A)) * b0);
			t_sample b1 = ((((int)-2) * cs) * b0);
			t_sample a2 = ((((int)1) - (alpha * A)) * b0);
			t_sample b2 = ((((int)1) - (alpha * one_over_A)) * b0);
			t_sample expr_2994 = a0;
			t_sample expr_2995 = b1;
			t_sample expr_2996 = a2;
			t_sample expr_2997 = b1;
			t_sample expr_2998 = b2;
			t_sample mul_2988 = (gate_3003 * expr_2994);
			t_sample mul_2985 = (m_history_2 * expr_2995);
			t_sample mul_2983 = (m_history_4 * expr_2996);
			t_sample mul_2979 = (m_history_3 * expr_2998);
			t_sample mul_2981 = (m_history_1 * expr_2997);
			t_sample sub_2987 = (((mul_2983 + mul_2985) + mul_2988) - (mul_2981 + mul_2979));
			t_sample gen_2993 = sub_2987;
			t_sample history_2984_next_2989 = fixdenorm(m_history_2);
			t_sample history_2980_next_2990 = fixdenorm(m_history_1);
			t_sample history_2986_next_2991 = fixdenorm(gate_3003);
			t_sample history_2982_next_2992 = fixdenorm(sub_2987);
			t_sample add_3010 = (gate_3002 + gen_2993);
			t_sample out2 = add_3010;
			t_sample out1 = add_3010;
			m_history_14 = history_3005_next_3007;
			m_history_13 = history_2963_next_2965;
			m_history_11 = history_2959_next_2967;
			m_history_12 = history_2961_next_2966;
			m_history_10 = history_2963_next_3018;
			m_history_8 = history_2959_next_3019;
			m_history_9 = history_2961_next_3013;
			m_history_7 = history_2963_next_3028;
			m_history_5 = history_2959_next_3032;
			m_history_6 = history_2961_next_3029;
			m_history_4 = history_2984_next_2989;
			m_history_3 = history_2980_next_2990;
			m_history_2 = history_2986_next_2991;
			m_history_1 = history_2982_next_2992;
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
	inline void set_knob4_gain(t_param _value) {
		m_knob4_gain_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_Q(t_param _value) {
		m_knob5_Q_17 = (_value < 0.001 ? 0.001 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_pitch(t_param _value) {
		m_knob3_pitch_18 = (_value < 60 ? 60 : (_value > 127 ? 127 : _value));
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
int num_params() { return 4; }

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
		case 0: self->set_knob3_pitch(value); break;
		case 1: self->set_knob4_gain(value); break;
		case 2: self->set_knob5_Q(value); break;
		case 3: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_pitch_18; break;
		case 1: *value = self->m_knob4_gain_15; break;
		case 2: *value = self->m_knob5_Q_17; break;
		case 3: *value = self->m_sw_16; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(4 * sizeof(ParamInfo));
	self->__commonstate.numparams = 4;
	// initialize parameter 0 ("m_knob3_pitch_18")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_pitch";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_pitch_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 60;
	pi->outputmax = 127;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_gain_15")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_gain";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_gain_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_Q_17")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_Q";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_Q_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.001;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_sw_16")
	pi = self->__commonstate.params + 3;
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Parametric::
