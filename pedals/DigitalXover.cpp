#include "DigitalXover.h"

namespace DigitalXover {

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
	t_sample m_hy_1;
	t_sample m_history_13;
	t_sample m_x_12;
	t_sample m_x_11;
	t_sample m_history_14;
	t_sample m_history_16;
	t_sample m_history_15;
	t_sample m_knob3_pitch_17;
	t_sample samplerate;
	t_sample m_x_10;
	t_sample m_sw_18;
	t_sample m_hy_3;
	t_sample m_hy_2;
	t_sample m_x_9;
	t_sample m_hy_4;
	t_sample m_ly_6;
	t_sample m_ly_5;
	t_sample m_ly_7;
	t_sample m_ly_8;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_hy_1 = ((int)0);
		m_hy_2 = ((int)0);
		m_hy_3 = ((int)0);
		m_hy_4 = ((int)0);
		m_ly_5 = ((int)0);
		m_ly_6 = ((int)0);
		m_ly_7 = ((int)0);
		m_ly_8 = ((int)0);
		m_x_9 = ((int)0);
		m_x_10 = ((int)0);
		m_x_11 = ((int)0);
		m_x_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_knob3_pitch_17 = 23;
		m_sw_18 = ((int)0);
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
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_175 = __m_sah_19(m_history_16, m_sw_18, ((int)0));
			t_sample gen_177 = sah_175;
			t_sample rsub_173 = (((int)1) - sah_175);
			t_sample history_174_next_176 = fixdenorm(rsub_173);
			t_sample out3 = gen_177;
			t_sample add_178 = (gen_177 + ((int)1));
			t_sample choice_20 = int(add_178);
			t_sample gate_171 = (((choice_20 >= 1) && (choice_20 < 2)) ? in1 : 0);
			t_sample gate_172 = ((choice_20 >= 2) ? in1 : 0);
			t_sample mix_199 = (m_history_15 + (((t_sample)0.0019634941468452) * (m_knob3_pitch_17 - m_history_15)));
			t_sample mix_164 = mix_199;
			t_sample mix_200 = (m_history_14 + (((t_sample)0.0019634941468452) * (mix_164 - m_history_14)));
			t_sample mix_162 = mix_200;
			t_sample mix_201 = (m_history_13 + (((t_sample)0.0019634941468452) * (mix_162 - m_history_13)));
			t_sample mix_160 = mix_201;
			t_sample gen_170 = mix_160;
			t_sample history_165_next_167 = fixdenorm(mix_164);
			t_sample history_163_next_168 = fixdenorm(mix_162);
			t_sample history_161_next_169 = fixdenorm(mix_160);
			t_sample mtof_159 = mtof(gen_170, ((int)440));
			t_sample x = gate_172;
			t_sample freq = mtof_159;
			t_sample rads = (((t_sample)6.2831853071796) * freq);
			t_sample k = safediv(rads, tan(safediv((((t_sample)3.1415926535898) * freq), samplerate)));
			t_sample temp = ((((((((int)4) * safepow(rads, ((int)2))) * safepow(k, ((int)2))) + ((((t_sample)2.8284271247462) * safepow(rads, ((int)3))) * k)) + safepow(k, ((int)4))) + ((((t_sample)2.8284271247462) * rads) * safepow(k, ((int)3)))) + safepow(rads, ((int)4)));
			t_sample la0 = safediv(safepow(rads, ((int)4)), temp);
			t_sample la1 = safediv((((int)4) * safepow(rads, ((int)4))), temp);
			t_sample la2 = safediv((((int)6) * safepow(rads, ((int)4))), temp);
			t_sample la3 = la1;
			t_sample la4 = la0;
			t_sample ha0 = safediv(safepow(k, ((int)4)), temp);
			t_sample ha1 = safediv((((int)-4) * safepow(k, ((int)4))), temp);
			t_sample ha2 = safediv((((int)6) * safepow(k, ((int)4))), temp);
			t_sample ha3 = ha1;
			t_sample ha4 = ha0;
			t_sample b1 = safediv(((((((int)4) * safepow(rads, ((int)4))) + ((((t_sample)5.6568542494924) * safepow(rads, ((int)3))) * k)) - (((int)4) * safepow(k, ((int)4)))) - ((((t_sample)5.6568542494924) * rads) * safepow(k, ((int)3)))), temp);
			t_sample b2 = safediv((((((int)6) * safepow(rads, ((int)4))) - ((((int)8) * safepow(rads, ((int)2))) * safepow(k, ((int)2)))) + (((int)6) * safepow(k, ((int)4)))), temp);
			t_sample b3 = safediv((((((((t_sample)-5.6568542494924) * safepow(rads, ((int)3))) * k) + (((int)4) * safepow(rads, ((int)4)))) + ((((t_sample)5.6568542494924) * rads) * safepow(k, ((int)3)))) - (((int)4) * safepow(k, ((int)4)))), temp);
			t_sample b4 = safediv(((((safepow(k, ((int)4)) - ((((t_sample)2.8284271247462) * safepow(rads, ((int)3))) * k)) + safepow(rads, ((int)4))) - ((((t_sample)2.8284271247462) * rads) * safepow(k, ((int)3)))) + ((((int)4) * safepow(rads, ((int)2))) * safepow(k, ((int)2)))), temp);
			t_sample ly = (((((((((la0 * x) + (la1 * m_x_12)) + (la2 * m_x_11)) + (la3 * m_x_10)) + (la4 * m_x_9)) - (b1 * m_ly_8)) - (b2 * m_ly_7)) - (b3 * m_ly_6)) - (b4 * m_ly_5));
			t_sample hy = (((((((((ha0 * x) + (ha1 * m_x_12)) + (ha2 * m_x_11)) + (ha3 * m_x_10)) + (ha4 * m_x_9)) - (b1 * m_hy_4)) - (b2 * m_hy_3)) - (b3 * m_hy_2)) - (b4 * m_hy_1));
			m_ly_5 = m_ly_6;
			m_ly_6 = m_ly_7;
			m_ly_7 = m_ly_8;
			m_ly_8 = ly;
			m_hy_1 = m_hy_2;
			m_hy_2 = m_hy_3;
			m_hy_3 = m_hy_4;
			m_hy_4 = hy;
			m_x_9 = m_x_10;
			m_x_10 = m_x_11;
			m_x_11 = m_x_12;
			m_x_12 = x;
			t_sample add_179 = (gate_171 + hy);
			t_sample out2 = add_179;
			t_sample add_180 = (gate_171 + ly);
			t_sample out1 = add_180;
			m_history_16 = history_174_next_176;
			m_history_15 = history_165_next_167;
			m_history_13 = history_161_next_169;
			m_history_14 = history_163_next_168;
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
	inline void set_knob3_pitch(t_param _value) {
		m_knob3_pitch_17 = (_value < 60 ? 60 : (_value > 127 ? 127 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 2; }

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
		case 1: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_pitch_17; break;
		case 1: *value = self->m_sw_18; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(2 * sizeof(ParamInfo));
	self->__commonstate.numparams = 2;
	// initialize parameter 0 ("m_knob3_pitch_17")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_pitch";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_pitch_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 60;
	pi->outputmax = 127;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_sw_18")
	pi = self->__commonstate.params + 1;
	pi->name = "sw1";
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


} // DigitalXover::
