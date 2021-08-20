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
	Sah __m_sah_15;
	int vectorsize;
	int __exception;
	t_sample m_knob5_slew_13;
	t_sample m_history_9;
	t_sample m_knob3_base_14;
	t_sample m_knob6_res_10;
	t_sample m_history_8;
	t_sample m_sw_11;
	t_sample m_knob4_range_12;
	t_sample m_history_7;
	t_sample m_history_5;
	t_sample m_y_1;
	t_sample samplerate;
	t_sample m_history_6;
	t_sample m_y_2;
	t_sample m_history_4;
	t_sample m_history_3;
	t_sample __m_slide_17;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_y_1 = ((int)0);
		m_y_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_knob6_res_10 = 0.5;
		m_sw_11 = ((int)0);
		m_knob4_range_12 = 1;
		m_knob5_slew_13 = 1;
		m_knob3_base_14 = 0;
		__m_sah_15.reset(0);
		__m_slide_17 = 0;
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
		t_sample mul_3003 = (m_knob5_slew_13 * ((int)1));
		t_sample mstosamps_2623 = (mul_3003 * (samplerate * 0.001));
		t_sample mul_2956 = (m_knob5_slew_13 * ((int)10));
		t_sample mstosamps_2622 = (mul_2956 * (samplerate * 0.001));
		t_sample iup_18 = (1 / maximum(1, abs(mstosamps_2623)));
		t_sample idown_19 = (1 / maximum(1, abs(mstosamps_2622)));
		t_sample clamp_2611 = ((m_knob6_res_10 <= ((int)0)) ? ((int)0) : ((m_knob6_res_10 >= ((t_sample)0.999999)) ? ((t_sample)0.999999) : m_knob6_res_10));
		t_sample mul_2609 = (clamp_2611 * ((t_sample)0.125));
		t_sample exp_2610 = exp(mul_2609);
		t_sample mul_2608 = (exp_2610 * ((t_sample)0.882497));
		t_sample mul_2604 = (mul_2608 * mul_2608);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_2633 = __m_sah_15(m_history_9, m_sw_11, ((int)0));
			t_sample gen_2635 = sah_2633;
			t_sample rsub_2631 = (((int)1) - sah_2633);
			t_sample history_2632_next_2634 = fixdenorm(rsub_2631);
			t_sample out3 = gen_2635;
			t_sample add_2636 = (gen_2635 + ((int)1));
			t_sample choice_16 = int(add_2636);
			t_sample gate_2629 = (((choice_16 >= 1) && (choice_16 < 2)) ? in1 : 0);
			t_sample gate_2630 = ((choice_16 >= 2) ? in1 : 0);
			t_sample mix_4485 = (m_history_8 + (((t_sample)0.0019634941468452) * (m_knob3_base_14 - m_history_8)));
			t_sample mix_2588 = mix_4485;
			t_sample mix_4486 = (m_history_7 + (((t_sample)0.0019634941468452) * (mix_2588 - m_history_7)));
			t_sample mix_2586 = mix_4486;
			t_sample mix_4487 = (m_history_6 + (((t_sample)0.0019634941468452) * (mix_2586 - m_history_6)));
			t_sample mix_2584 = mix_4487;
			t_sample gen_2594 = mix_2584;
			t_sample history_2589_next_2591 = fixdenorm(mix_2588);
			t_sample history_2587_next_2592 = fixdenorm(mix_2586);
			t_sample history_2585_next_2593 = fixdenorm(mix_2584);
			t_sample mix_4488 = (m_history_5 + (((t_sample)0.0019634941468452) * (m_knob4_range_12 - m_history_5)));
			t_sample mix_4073 = mix_4488;
			t_sample mix_4489 = (m_history_4 + (((t_sample)0.0019634941468452) * (mix_4073 - m_history_4)));
			t_sample mix_4074 = mix_4489;
			t_sample mix_4490 = (m_history_3 + (((t_sample)0.0019634941468452) * (mix_4074 - m_history_3)));
			t_sample mix_4070 = mix_4490;
			t_sample gen_2750 = mix_4070;
			t_sample history_2589_next_4072 = fixdenorm(mix_4073);
			t_sample history_2587_next_4069 = fixdenorm(mix_4074);
			t_sample history_2585_next_4071 = fixdenorm(mix_4070);
			t_sample abs_2628 = fabs(gate_2630);
			__m_slide_17 = fixdenorm((__m_slide_17 + (((abs_2628 > __m_slide_17) ? iup_18 : idown_19) * (abs_2628 - __m_slide_17))));
			t_sample slide_2627 = __m_slide_17;
			t_sample mul_3574 = (slide_2627 * ((int)30));
			t_sample clamp_3880 = ((mul_3574 <= ((int)0)) ? ((int)0) : ((mul_3574 >= ((int)1)) ? ((int)1) : mul_3574));
			t_sample sqrt_3714 = sqrt(clamp_3880);
			t_sample mul_2616 = (sqrt_3714 * gen_2750);
			t_sample add_2596 = (mul_2616 + gen_2594);
			t_sample clamp_2595 = ((add_2596 <= ((int)0)) ? ((int)0) : ((add_2596 >= ((int)1)) ? ((int)1) : add_2596));
			t_sample sub_4494 = (clamp_2595 - ((int)0));
			t_sample scale_4491 = ((safepow((sub_4494 * ((t_sample)1)), ((int)1)) * ((int)120)) + ((int)15));
			t_sample scale_2597 = scale_4491;
			t_sample mtof_2707 = mtof(scale_2597, ((int)440));
			t_sample expr_2612 = safediv(((mtof_2707 * ((int)2)) * ((t_sample)3.1415926535898)), samplerate);
			t_sample cos_2607 = cos(expr_2612);
			t_sample mul_2600 = (mul_2604 * m_y_2);
			t_sample mul_2606 = (cos_2607 * mul_2608);
			t_sample mul_2605 = (mul_2606 * (-2));
			t_sample mul_2601 = (mul_2605 * m_y_1);
			t_sample add_2603 = ((mul_2604 + mul_2605) + ((int)1));
			t_sample mul_2602 = (gate_2630 * add_2603);
			t_sample sub_2599 = (mul_2602 - (mul_2600 + mul_2601));
			t_sample gen_2615 = sub_2599;
			t_sample y2_next_2613 = fixdenorm(m_y_1);
			t_sample y1_next_2614 = fixdenorm(sub_2599);
			t_sample add_2641 = (gen_2615 + gate_2629);
			t_sample out1 = add_2641;
			t_sample add_2640 = (gen_2615 + gate_2629);
			t_sample out2 = add_2640;
			m_history_9 = history_2632_next_2634;
			m_history_8 = history_2589_next_2591;
			m_history_6 = history_2585_next_2593;
			m_history_7 = history_2587_next_2592;
			m_history_5 = history_2589_next_4072;
			m_history_3 = history_2585_next_4071;
			m_history_4 = history_2587_next_4069;
			m_y_2 = y2_next_2613;
			m_y_1 = y1_next_2614;
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
		m_knob6_res_10 = (_value < 0.5 ? 0.5 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_range(t_param _value) {
		m_knob4_range_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_slew(t_param _value) {
		m_knob5_slew_13 = (_value < 1 ? 1 : (_value > 30 ? 30 : _value));
	};
	inline void set_knob3_base(t_param _value) {
		m_knob3_base_14 = (_value < 0 ? 0 : (_value > 0.8 ? 0.8 : _value));
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
int num_params() { return 5; }

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
		case 0: self->set_knob3_base(value); break;
		case 1: self->set_knob4_range(value); break;
		case 2: self->set_knob5_slew(value); break;
		case 3: self->set_knob6_res(value); break;
		case 4: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_base_14; break;
		case 1: *value = self->m_knob4_range_12; break;
		case 2: *value = self->m_knob5_slew_13; break;
		case 3: *value = self->m_knob6_res_10; break;
		case 4: *value = self->m_sw_11; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(5 * sizeof(ParamInfo));
	self->__commonstate.numparams = 5;
	// initialize parameter 0 ("m_knob3_base_14")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_base";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_base_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.8;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_range_12")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_range";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_range_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_slew_13")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_slew";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_slew_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 30;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_res_10")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_res_10;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_11")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_11;
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