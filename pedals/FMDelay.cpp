#include "FMDelay.h"

namespace FMDelay {

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
	SineCycle __m_cycle_20;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_3;
	t_sample m_knob3_manual_14;
	t_sample m_knob5_rate_13;
	t_sample m_sw_12;
	t_sample m_sw_15;
	t_sample m_history_17;
	t_sample m_knob4_depth_16;
	t_sample m_history_2;
	t_sample m_knob6_res_11;
	t_sample samplerate;
	t_sample m_history_5;
	t_sample m_history_4;
	t_sample m_history_10;
	t_sample m_history_6;
	t_sample m_history_8;
	t_sample m_history_7;
	t_sample m_history_9;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)24000));
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_knob6_res_11 = ((int)0);
		m_sw_12 = ((int)0);
		m_knob5_rate_13 = ((int)0);
		m_knob3_manual_14 = ((int)0);
		m_sw_15 = ((int)0);
		m_knob4_depth_16 = ((int)0);
		m_history_17 = ((int)0);
		__m_sah_18.reset(0);
		__m_cycle_20.reset(samplerate, 0);
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
		t_sample sqrt_1031 = sqrt(m_knob6_res_11);
		t_sample sqrt_1040 = sqrt(sqrt_1031);
		t_sample mul_1049 = (sqrt_1040 * ((t_sample)0.99));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_1034 = __m_sah_18(m_history_17, m_sw_12, ((int)0));
			t_sample gen_1036 = sah_1034;
			t_sample rsub_1032 = (((int)1) - sah_1034);
			t_sample history_1033_next_1035 = fixdenorm(rsub_1032);
			t_sample out3 = gen_1036;
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample mix_1120 = (m_history_10 + (((t_sample)0.003926980723806) * (m_knob5_rate_13 - m_history_10)));
			t_sample mix_1016 = mix_1120;
			t_sample mix_1121 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_1016 - m_history_9)));
			t_sample mix_1014 = mix_1121;
			t_sample mix_1122 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_1014 - m_history_8)));
			t_sample mix_1012 = mix_1122;
			t_sample gen_1023 = mix_1012;
			t_sample history_1017_next_1019 = fixdenorm(mix_1016);
			t_sample history_1015_next_1020 = fixdenorm(mix_1014);
			t_sample history_1013_next_1021 = fixdenorm(mix_1012);
			t_sample expr_1057 = (((int)1) - sqrt(sqrt((((int)1) - gen_1023))));
			t_sample mix_1123 = (m_history_7 + (((t_sample)0.003926980723806) * (m_knob3_manual_14 - m_history_7)));
			t_sample mix_1060 = mix_1123;
			t_sample mix_1124 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_1060 - m_history_6)));
			t_sample mix_1066 = mix_1124;
			t_sample mix_1125 = (m_history_5 + (((t_sample)0.003926980723806) * (mix_1066 - m_history_5)));
			t_sample mix_1062 = mix_1125;
			t_sample gen_1024 = mix_1062;
			t_sample history_1017_next_1065 = fixdenorm(mix_1060);
			t_sample history_1015_next_1064 = fixdenorm(mix_1066);
			t_sample history_1013_next_1061 = fixdenorm(mix_1062);
			t_sample expr_1056 = (((int)1) - sqrt((((int)1) - gen_1024)));
			t_sample mix_1126 = (m_history_4 + (((t_sample)0.003926980723806) * (m_knob4_depth_16 - m_history_4)));
			t_sample mix_1075 = mix_1126;
			t_sample mix_1127 = (m_history_3 + (((t_sample)0.003926980723806) * (mix_1075 - m_history_3)));
			t_sample mix_1073 = mix_1127;
			t_sample mix_1128 = (m_history_2 + (((t_sample)0.003926980723806) * (mix_1073 - m_history_2)));
			t_sample mix_1076 = mix_1128;
			t_sample gen_1022 = mix_1076;
			t_sample history_1017_next_1072 = fixdenorm(mix_1075);
			t_sample history_1015_next_1079 = fixdenorm(mix_1073);
			t_sample history_1013_next_1071 = fixdenorm(mix_1076);
			t_sample expr_1055 = (((int)1) - sqrt(sqrt((((int)1) - gen_1022))));
			t_sample add_1039 = (gen_1036 + ((int)1));
			t_sample choice_19 = int(add_1039);
			t_sample gate_1037 = (((choice_19 >= 1) && (choice_19 < 2)) ? in1 : 0);
			t_sample gate_1038 = ((choice_19 >= 2) ? in1 : 0);
			t_sample switch_1011 = (m_sw_15 ? gate_1038 : ((int)0));
			t_sample mul_1051 = (expr_1056 * ((int)24000));
			t_sample mul_1048 = (expr_1055 * mul_1051);
			t_sample mul_1043 = (expr_1057 * ((int)127));
			t_sample mtof_1010 = mtof(mul_1043, ((int)440));
			__m_cycle_20.freq(mtof_1010);
			t_sample cycle_1044 = __m_cycle_20(__sinedata);
			t_sample cycleindex_1045 = __m_cycle_20.phase();
			t_sample mul_1042 = (cycle_1044 * mul_1048);
			t_sample add_1046 = (mul_1051 + mul_1042);
			t_sample clamp_1047 = ((add_1046 <= ((int)0)) ? ((int)0) : ((add_1046 >= ((int)48000)) ? ((int)48000) : add_1046));
			t_sample tap_1053 = m_delay_1.read_cubic(clamp_1047);
			t_sample tap_1054 = m_delay_1.read_cubic(mul_1051);
			t_sample add_1030 = (switch_1011 + tap_1053);
			t_sample div_1028 = (add_1030 * ((t_sample)0.5));
			t_sample out1 = (div_1028 + gate_1037);
			t_sample add_1029 = (switch_1011 + tap_1053);
			t_sample div_1027 = (add_1029 * ((t_sample)0.5));
			t_sample out2 = (div_1027 + gate_1037);
			t_sample mul_1050 = (tap_1054 * mul_1049);
			m_history_17 = history_1033_next_1035;
			m_history_10 = history_1017_next_1019;
			m_history_8 = history_1013_next_1021;
			m_history_9 = history_1015_next_1020;
			m_history_7 = history_1017_next_1065;
			m_history_5 = history_1013_next_1061;
			m_history_6 = history_1015_next_1064;
			m_history_4 = history_1017_next_1072;
			m_history_2 = history_1013_next_1071;
			m_history_3 = history_1015_next_1079;
			m_delay_1.write((mul_1050 + gate_1038));
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
	inline void set_knob6_res(t_param _value) {
		m_knob6_res_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_rate(t_param _value) {
		m_knob5_rate_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_manual(t_param _value) {
		m_knob3_manual_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_depth(t_param _value) {
		m_knob4_depth_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_manual_14; break;
		case 1: *value = self->m_knob4_depth_16; break;
		case 2: *value = self->m_knob5_rate_13; break;
		case 3: *value = self->m_knob6_res_11; break;
		case 4: *value = self->m_sw_12; break;
		case 5: *value = self->m_sw_15; break;
		
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
	// initialize parameter 0 ("m_knob3_manual_14")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_manual";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_manual_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_depth_16")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_depth_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_rate_13")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_rate_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_res_11")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_res_11;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_12")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_15")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // FMDelay::
