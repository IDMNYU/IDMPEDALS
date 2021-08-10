#include "Reverb.h"

namespace Reverb {

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
	Delay m_delay_5;
	Delay m_delay_7;
	Delay m_delay_6;
	Delay m_delay_8;
	Delay m_delay_10;
	Delay m_delay_9;
	Delay m_delay_11;
	Sah __m_sah_12;
	int __exception;
	int vectorsize;
	t_sample m_history_4;
	t_sample samplerate;
	t_sample m_knob4_wetdry_2;
	t_sample m_knob3_size_1;
	t_sample m_sw_3;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_knob3_size_1 = ((int)0);
		m_knob4_wetdry_2 = ((int)0);
		m_sw_3 = ((int)0);
		m_history_4 = ((int)0);
		m_delay_5.reset("m_delay_5", samplerate);
		m_delay_6.reset("m_delay_6", samplerate);
		m_delay_7.reset("m_delay_7", samplerate);
		m_delay_8.reset("m_delay_8", ((int)3374));
		m_delay_9.reset("m_delay_9", ((int)3202));
		m_delay_10.reset("m_delay_10", ((int)4106));
		m_delay_11.reset("m_delay_11", ((int)4502));
		__m_sah_12.reset(0);
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
		t_sample sqrt_3563 = sqrt(m_knob4_wetdry_2);
		t_sample rsub_3568 = (((int)1) - m_knob4_wetdry_2);
		t_sample sqrt_3567 = sqrt(rsub_3568);
		t_sample mul_3622 = (m_knob3_size_1 * ((int)347));
		t_sample mul_3615 = (m_knob3_size_1 * ((int)113));
		t_sample mul_3608 = (m_knob3_size_1 * ((int)37));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_2887 = __m_sah_12(m_history_4, m_sw_3, ((int)0));
			t_sample gen_3572 = sah_2887;
			t_sample rsub_2885 = (((int)1) - sah_2887);
			t_sample history_2886_next_2888 = fixdenorm(rsub_2885);
			t_sample out3 = gen_3572;
			t_sample add_3575 = (gen_3572 + ((int)1));
			t_sample choice_13 = int(add_3575);
			t_sample gate_3573 = (((choice_13 >= 1) && (choice_13 < 2)) ? in1 : 0);
			t_sample gate_3574 = ((choice_13 >= 2) ? in1 : 0);
			t_sample mul_3566 = (gate_3574 * sqrt_3567);
			t_sample tap_3627 = m_delay_5.read_linear(mul_3622);
			t_sample mul_3625 = (tap_3627 * (-1));
			t_sample add_3624 = (gate_3574 + mul_3625);
			t_sample mul_3623 = (add_3624 * ((t_sample)0.7));
			t_sample gen_3628 = (mul_3623 + tap_3627);
			t_sample tap_3620 = m_delay_6.read_linear(mul_3615);
			t_sample mul_3618 = (tap_3620 * (-1));
			t_sample add_3617 = (gen_3628 + mul_3618);
			t_sample mul_3616 = (add_3617 * ((t_sample)0.7));
			t_sample gen_3621 = (mul_3616 + tap_3620);
			t_sample tap_3613 = m_delay_7.read_linear(mul_3608);
			t_sample mul_3611 = (tap_3613 * (-1));
			t_sample add_3610 = (gen_3621 + mul_3611);
			t_sample mul_3609 = (add_3610 * ((t_sample)0.7));
			t_sample gen_3614 = (mul_3609 + tap_3613);
			t_sample tap_3605 = m_delay_8.read_step(((int)3374));
			t_sample mul_3603 = (tap_3605 * (-1));
			t_sample add_3606 = (gen_3614 + mul_3603);
			t_sample mul_3602 = (add_3606 * ((t_sample)0.773));
			t_sample tap_3599 = m_delay_9.read_step(((int)3202));
			t_sample mul_3597 = (tap_3599 * (-1));
			t_sample add_3600 = (gen_3614 + mul_3597);
			t_sample mul_3596 = (add_3600 * ((t_sample)0.802));
			t_sample tap_3593 = m_delay_10.read_step(((int)4106));
			t_sample mul_3591 = (tap_3593 * (-1));
			t_sample add_3594 = (gen_3614 + mul_3591);
			t_sample mul_3590 = (add_3594 * ((t_sample)0.753));
			t_sample tap_3587 = m_delay_11.read_step(((int)4502));
			t_sample mul_3585 = (tap_3587 * (-1));
			t_sample add_3588 = (gen_3614 + mul_3585);
			t_sample mul_3584 = (add_3588 * ((t_sample)0.733));
			t_sample add_3578 = (mul_3596 + mul_3584);
			t_sample mul_3576 = (add_3578 * (-1));
			t_sample add_3579 = (mul_3602 + mul_3590);
			t_sample mul_3577 = (add_3579 * (-1));
			t_sample mul_3570 = ((add_3579 + mul_3576) * sqrt_3563);
			t_sample add_3565 = (mul_3566 + mul_3570);
			t_sample out1 = (gate_3573 + add_3565);
			t_sample mul_3569 = ((mul_3577 + add_3578) * sqrt_3563);
			t_sample add_3564 = (mul_3566 + mul_3569);
			t_sample out2 = (gate_3573 + add_3564);
			m_history_4 = history_2886_next_2888;
			m_delay_11.write(mul_3584);
			m_delay_10.write(mul_3590);
			m_delay_9.write(mul_3596);
			m_delay_8.write(mul_3602);
			m_delay_7.write(mul_3609);
			m_delay_6.write(mul_3616);
			m_delay_5.write(mul_3623);
			m_delay_5.step();
			m_delay_6.step();
			m_delay_7.step();
			m_delay_8.step();
			m_delay_9.step();
			m_delay_10.step();
			m_delay_11.step();
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
	inline void set_knob3_size(t_param _value) {
		m_knob3_size_1 = (_value < 1 ? 1 : (_value > 100 ? 100 : _value));
	};
	inline void set_knob4_wetdry(t_param _value) {
		m_knob4_wetdry_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 3; }

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
		case 0: self->set_knob3_size(value); break;
		case 1: self->set_knob4_wetdry(value); break;
		case 2: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_size_1; break;
		case 1: *value = self->m_knob4_wetdry_2; break;
		case 2: *value = self->m_sw_3; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(3 * sizeof(ParamInfo));
	self->__commonstate.numparams = 3;
	// initialize parameter 0 ("m_knob3_size_1")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_size";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_size_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_wetdry_2")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_wetdry_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_sw_3")
	pi = self->__commonstate.params + 2;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_3;
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


} // Reverb::
