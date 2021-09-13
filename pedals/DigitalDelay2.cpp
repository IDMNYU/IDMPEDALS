#include "DigitalDelay2.h"

namespace DigitalDelay2 {

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
	Sah __m_sah_18;
	int __exception;
	int vectorsize;
	t_sample m_knob4_fb_12;
	t_sample m_knob3_level_11;
	t_sample m_history_10;
	t_sample m_sw_13;
	t_sample m_sw_15;
	t_sample m_knob6_multitap_14;
	t_sample m_knob5_time_16;
	t_sample samplerate;
	t_sample m_history_9;
	t_sample m_history_7;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample m_history_17;
	t_sample m_history_4;
	t_sample m_history_6;
	t_sample m_history_5;
	t_sample m_history_8;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)192000));
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_knob3_level_11 = ((int)0);
		m_knob4_fb_12 = ((int)0);
		m_sw_13 = ((int)0);
		m_knob6_multitap_14 = ((int)0);
		m_sw_15 = ((int)0);
		m_knob5_time_16 = ((int)0);
		m_history_17 = ((int)0);
		__m_sah_18.reset(0);
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
		t_sample add_2957 = (m_sw_13 + ((int)1));
		t_sample choice_20 = int(add_2957);
		t_sample choice_21 = int(add_2957);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_2962 = __m_sah_18(m_history_17, m_sw_15, ((int)0));
			t_sample gen_2964 = sah_2962;
			t_sample rsub_2960 = (((int)1) - sah_2962);
			t_sample history_2961_next_2963 = fixdenorm(rsub_2960);
			t_sample out3 = gen_2964;
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample add_2965 = (gen_2964 + ((int)1));
			t_sample choice_19 = int(add_2965);
			t_sample gate_2958 = (((choice_19 >= 1) && (choice_19 < 2)) ? in1 : 0);
			t_sample gate_2959 = ((choice_19 >= 2) ? in1 : 0);
			t_sample pass_2977 = gate_2959;
			t_sample mix_3030 = (m_history_10 + (((t_sample)0.003926980723806) * (m_knob4_fb_12 - m_history_10)));
			t_sample mix_2945 = mix_3030;
			t_sample mix_3031 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_2945 - m_history_9)));
			t_sample mix_2943 = mix_3031;
			t_sample mix_3032 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_2943 - m_history_8)));
			t_sample mix_2941 = mix_3032;
			t_sample gen_2972 = mix_2941;
			t_sample history_2946_next_2948 = fixdenorm(mix_2945);
			t_sample history_2944_next_2949 = fixdenorm(mix_2943);
			t_sample history_2942_next_2950 = fixdenorm(mix_2941);
			t_sample mix_3033 = (m_history_7 + (((t_sample)0.003926980723806) * (m_knob5_time_16 - m_history_7)));
			t_sample mix_2984 = mix_3033;
			t_sample mix_3034 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_2984 - m_history_6)));
			t_sample mix_2983 = mix_3034;
			t_sample mix_3035 = (m_history_5 + (((t_sample)0.003926980723806) * (mix_2983 - m_history_5)));
			t_sample mix_2978 = mix_3035;
			t_sample gen_2966 = mix_2978;
			t_sample history_2946_next_2980 = fixdenorm(mix_2984);
			t_sample history_2944_next_2982 = fixdenorm(mix_2983);
			t_sample history_2942_next_2979 = fixdenorm(mix_2978);
			t_sample sub_3039 = (gen_2966 - ((int)0));
			t_sample scale_3036 = ((safepow((sub_3039 * ((t_sample)1)), ((int)1)) * ((int)96000)) + ((int)0));
			t_sample mix_3040 = (m_history_4 + (((t_sample)0.003926980723806) * (m_knob6_multitap_14 - m_history_4)));
			t_sample mix_2996 = mix_3040;
			t_sample mix_3041 = (m_history_3 + (((t_sample)0.003926980723806) * (mix_2996 - m_history_3)));
			t_sample mix_2998 = mix_3041;
			t_sample mix_3042 = (m_history_2 + (((t_sample)0.003926980723806) * (mix_2998 - m_history_2)));
			t_sample mix_2993 = mix_3042;
			t_sample gen_2951 = mix_2993;
			t_sample history_2946_next_2994 = fixdenorm(mix_2996);
			t_sample history_2944_next_2991 = fixdenorm(mix_2998);
			t_sample history_2942_next_2997 = fixdenorm(mix_2993);
			t_sample round_2937 = round(gen_2951);
			t_sample rdiv_2952 = safediv(((int)1), round_2937);
			t_sample mul_2936 = (scale_3036 * rdiv_2952);
			t_sample add_2938 = (scale_3036 + mul_2936);
			t_sample tap_2975 = m_delay_1.read_cubic(scale_3036);
			t_sample tap_2976 = m_delay_1.read_cubic(add_2938);
			t_sample mul_2971 = (tap_2975 * m_knob3_level_11);
			t_sample gate_2955 = (((choice_20 >= 1) && (choice_20 < 2)) ? mul_2971 : 0);
			t_sample gate_2956 = ((choice_20 >= 2) ? mul_2971 : 0);
			t_sample mul_2968 = (tap_2976 * m_knob3_level_11);
			t_sample gate_2953 = (((choice_21 >= 1) && (choice_21 < 2)) ? mul_2968 : 0);
			t_sample gate_2954 = ((choice_21 >= 2) ? mul_2968 : 0);
			t_sample add_2970 = ((gate_2958 + pass_2977) + ((gate_2953 + gate_2955) + gate_2956));
			t_sample out1 = add_2970;
			t_sample add_2967 = ((gate_2958 + pass_2977) + ((gate_2953 + gate_2954) + gate_2955));
			t_sample out2 = add_2967;
			t_sample mul_2969 = (tap_2976 * gen_2972);
			t_sample mul_2973 = (tap_2975 * gen_2972);
			m_history_17 = history_2961_next_2963;
			m_history_10 = history_2946_next_2948;
			m_history_8 = history_2942_next_2950;
			m_history_9 = history_2944_next_2949;
			m_history_7 = history_2946_next_2980;
			m_history_5 = history_2942_next_2979;
			m_history_6 = history_2944_next_2982;
			m_history_4 = history_2946_next_2994;
			m_history_2 = history_2942_next_2997;
			m_history_3 = history_2944_next_2991;
			m_delay_1.write(((mul_2973 + mul_2969) + pass_2977));
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
	inline void set_knob3_level(t_param _value) {
		m_knob3_level_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_fb(t_param _value) {
		m_knob4_fb_12 = (_value < 0 ? 0 : (_value > 0.48 ? 0.48 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_multitap(t_param _value) {
		m_knob6_multitap_14 = (_value < 1 ? 1 : (_value > 6 ? 6 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_time(t_param _value) {
		m_knob5_time_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_knob3_level(value); break;
		case 1: self->set_knob4_fb(value); break;
		case 2: self->set_knob5_time(value); break;
		case 3: self->set_knob6_multitap(value); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_level_11; break;
		case 1: *value = self->m_knob4_fb_12; break;
		case 2: *value = self->m_knob5_time_16; break;
		case 3: *value = self->m_knob6_multitap_14; break;
		case 4: *value = self->m_sw_15; break;
		case 5: *value = self->m_sw_13; break;
		
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
	// initialize parameter 0 ("m_knob3_level_11")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_level";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_level_11;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_fb_12")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.48;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_time_16")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_time";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_time_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_multitap_14")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_multitap";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_multitap_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_15")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_13")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_13;
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


} // DigitalDelay2::
