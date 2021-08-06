#include "Compressor.h"

namespace Compressor {

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
	Sah __m_sah_10;
	int vectorsize;
	int __exception;
	t_sample m_knob3_threshold_6;
	t_sample m_sw_7;
	t_sample m_knob1_input_8;
	t_sample m_history_9;
	t_sample m_knob4_ratio_5;
	t_sample m_sw_4;
	t_sample m_knob5_attack_2;
	t_sample m_knob2_output_3;
	t_sample samplerate;
	t_sample m_knob6_release_1;
	t_sample __m_slide_12;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_knob6_release_1 = ((int)0);
		m_knob5_attack_2 = ((int)0);
		m_knob2_output_3 = ((int)0);
		m_sw_4 = ((int)0);
		m_knob4_ratio_5 = ((int)0);
		m_knob3_threshold_6 = ((int)0);
		m_sw_7 = ((int)0);
		m_knob1_input_8 = ((int)0);
		m_history_9 = ((int)0);
		__m_sah_10.reset(0);
		__m_slide_12 = 0;
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
		t_sample dbtoa_80 = dbtoa(m_knob2_output_3);
		t_sample dbtoa_99 = dbtoa(m_knob1_input_8);
		t_sample mul_83 = (samplerate * ((t_sample)0.001));
		t_sample mul_84 = (m_knob5_attack_2 * mul_83);
		t_sample mul_82 = (m_knob6_release_1 * mul_83);
		t_sample iup_13 = (1 / maximum(1, abs(mul_84)));
		t_sample idown_14 = (1 / maximum(1, abs(mul_82)));
		t_sample switch_69 = (m_sw_7 ? ((int)10000) : m_knob4_ratio_5);
		t_sample rdiv_93 = safediv(((int)1), switch_69);
		t_sample rsub_92 = (((int)1) - rdiv_93);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_77 = __m_sah_10(m_history_9, m_sw_4, ((int)0));
			t_sample gen_79 = sah_77;
			t_sample rsub_75 = (((int)1) - sah_77);
			t_sample history_76_next_78 = fixdenorm(rsub_75);
			t_sample out3 = gen_79;
			t_sample add_70 = (gen_79 + ((int)1));
			t_sample choice_11 = int(add_70);
			t_sample gate_71 = (((choice_11 >= 1) && (choice_11 < 2)) ? in1 : 0);
			t_sample gate_72 = ((choice_11 >= 2) ? in1 : 0);
			t_sample mul_101 = (gate_72 * dbtoa_99);
			t_sample add_97 = (mul_101 + ((int)0));
			t_sample abs_98 = fabs(add_97);
			__m_slide_12 = fixdenorm((__m_slide_12 + (((abs_98 > __m_slide_12) ? iup_13 : idown_14) * (abs_98 - __m_slide_12))));
			t_sample slide_85 = __m_slide_12;
			t_sample atodb_96 = atodb(slide_85);
			int gt_94 = (atodb_96 > m_knob3_threshold_6);
			t_sample sub_95 = (m_knob3_threshold_6 - atodb_96);
			t_sample mul_91 = (sub_95 * rsub_92);
			t_sample dbtoa_90 = dbtoa(mul_91);
			t_sample rsub_89 = (((int)1) - dbtoa_90);
			t_sample mul_88 = (rsub_89 * (-1));
			t_sample mul_87 = (gt_94 * mul_88);
			t_sample add_86 = (mul_87 + ((int)1));
			t_sample clamp_73 = ((add_86 <= ((int)0)) ? ((int)0) : ((add_86 >= ((int)1)) ? ((int)1) : add_86));
			t_sample mul_100 = (mul_101 * clamp_73);
			t_sample mul_81 = (mul_100 * dbtoa_80);
			t_sample out2 = (gate_71 + mul_81);
			t_sample out1 = (gate_71 + mul_81);
			m_history_9 = history_76_next_78;
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
	inline void set_knob6_release(t_param _value) {
		m_knob6_release_1 = (_value < 5 ? 5 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_knob5_attack(t_param _value) {
		m_knob5_attack_2 = (_value < 0.5 ? 0.5 : (_value > 200 ? 200 : _value));
	};
	inline void set_knob2_output(t_param _value) {
		m_knob2_output_3 = (_value < -70 ? -70 : (_value > 15 ? 15 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_ratio(t_param _value) {
		m_knob4_ratio_5 = (_value < 1 ? 1 : (_value > 20 ? 20 : _value));
	};
	inline void set_knob3_threshold(t_param _value) {
		m_knob3_threshold_6 = (_value < -70 ? -70 : (_value > 6 ? 6 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_7 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_input(t_param _value) {
		m_knob1_input_8 = (_value < -70 ? -70 : (_value > 15 ? 15 : _value));
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
int num_params() { return 8; }

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
		case 0: self->set_knob1_input(value); break;
		case 1: self->set_knob2_output(value); break;
		case 2: self->set_knob3_threshold(value); break;
		case 3: self->set_knob4_ratio(value); break;
		case 4: self->set_knob5_attack(value); break;
		case 5: self->set_knob6_release(value); break;
		case 6: self->set_sw1(value); break;
		case 7: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_input_8; break;
		case 1: *value = self->m_knob2_output_3; break;
		case 2: *value = self->m_knob3_threshold_6; break;
		case 3: *value = self->m_knob4_ratio_5; break;
		case 4: *value = self->m_knob5_attack_2; break;
		case 5: *value = self->m_knob6_release_1; break;
		case 6: *value = self->m_sw_4; break;
		case 7: *value = self->m_sw_7; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(8 * sizeof(ParamInfo));
	self->__commonstate.numparams = 8;
	// initialize parameter 0 ("m_knob1_input_8")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_input";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_input_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -70;
	pi->outputmax = 15;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob2_output_3")
	pi = self->__commonstate.params + 1;
	pi->name = "knob2_output";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_output_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -70;
	pi->outputmax = 15;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob3_threshold_6")
	pi = self->__commonstate.params + 2;
	pi->name = "knob3_threshold";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_threshold_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -70;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob4_ratio_5")
	pi = self->__commonstate.params + 3;
	pi->name = "knob4_ratio";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_ratio_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 20;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob5_attack_2")
	pi = self->__commonstate.params + 4;
	pi->name = "knob5_attack";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_attack_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 200;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob6_release_1")
	pi = self->__commonstate.params + 5;
	pi->name = "knob6_release";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_release_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 5;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_sw_4")
	pi = self->__commonstate.params + 6;
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
	// initialize parameter 7 ("m_sw_7")
	pi = self->__commonstate.params + 7;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_7;
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


} // Compressor::
