#include "Subharmonic.h"

namespace Subharmonic {

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
	Sah __m_sah_17;
	Sah __m_sah_20;
	Sah __m_sah_18;
	Sah __m_sah_15;
	Sah __m_sah_19;
	int __exception;
	int vectorsize;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample __m_slide_21;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample __m_slide_24;
	t_sample m_history_10;
	t_sample m_history_8;
	t_sample m_knob3_dry_2;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample m_history_9;
	t_sample m_sw_3;
	t_sample m_knob4_oct_5;
	t_sample m_knob5_oct_4;
	t_sample m_history_7;
	t_sample m_knob6_smooth_6;
	t_sample __m_slide_27;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_knob3_dry_2 = ((int)0);
		m_sw_3 = ((int)0);
		m_knob5_oct_4 = ((int)0);
		m_knob4_oct_5 = ((int)0);
		m_knob6_smooth_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		__m_sah_15.reset(0);
		__m_sah_17.reset(1);
		__m_sah_18.reset(1);
		__m_sah_19.reset(0);
		__m_sah_20.reset(0);
		__m_slide_21 = 0;
		__m_slide_24 = 0;
		__m_slide_27 = 0;
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
		t_sample iup_22 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_23 = (1 / maximum(1, abs(((int)200))));
		t_sample rsub_2115 = (((int)1) - m_knob6_smooth_6);
		t_sample sqrt_2116 = sqrt(rsub_2115);
		t_sample rsub_2114 = (((int)1) - sqrt_2116);
		t_sample mul_2113 = (rsub_2114 * ((int)100));
		t_sample iup_25 = (1 / maximum(1, abs(mul_2113)));
		t_sample idown_26 = (1 / maximum(1, abs(mul_2113)));
		t_sample iup_28 = (1 / maximum(1, abs(mul_2113)));
		t_sample idown_29 = (1 / maximum(1, abs(mul_2113)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_2141 = __m_sah_15(m_history_1, m_sw_3, ((int)0));
			t_sample gen_2143 = sah_2141;
			t_sample rsub_2139 = (((int)1) - sah_2141);
			t_sample history_2140_next_2142 = fixdenorm(rsub_2139);
			t_sample out3 = gen_2143;
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample mul_2163 = (m_history_11 * (-1));
			t_sample mul_2149 = (m_history_12 * (-1));
			t_sample add_2144 = (gen_2143 + ((int)1));
			t_sample choice_16 = int(add_2144);
			t_sample gate_2137 = (((choice_16 >= 1) && (choice_16 < 2)) ? in1 : 0);
			t_sample gate_2138 = ((choice_16 >= 2) ? in1 : 0);
			t_sample mul_2156 = (gate_2138 * m_knob3_dry_2);
			t_sample add_2167 = (m_history_13 + ((int)1));
			t_sample mod_2166 = safemod(add_2167, ((int)2));
			int eq_2165 = (mod_2166 == ((int)0));
			t_sample sah_2164 = __m_sah_17(mul_2163, eq_2165, ((int)0));
			t_sample add_2153 = (m_history_14 + ((int)1));
			t_sample mod_2152 = safemod(add_2153, ((int)4));
			int eq_2151 = (mod_2152 == ((int)0));
			t_sample sah_2150 = __m_sah_18(mul_2149, eq_2151, ((int)0));
			t_sample mul_2131 = (gate_2138 * ((t_sample)0.027526));
			t_sample mul_2128 = (m_history_9 * ((t_sample)0.055053));
			t_sample mul_2126 = (m_history_7 * ((t_sample)0.027526));
			t_sample mul_2122 = (m_history_8 * ((t_sample)0.446463));
			t_sample mul_2124 = (m_history_10 * ((t_sample)-1.336357));
			t_sample sub_2130 = (((mul_2126 + mul_2128) + mul_2131) - (mul_2124 + mul_2122));
			t_sample gen_2136 = sub_2130;
			t_sample history_2127_next_2132 = fixdenorm(m_history_9);
			t_sample history_2123_next_2133 = fixdenorm(m_history_10);
			t_sample history_2129_next_2134 = fixdenorm(gate_2138);
			t_sample history_2125_next_2135 = fixdenorm(sub_2130);
			int gt_2170 = (gen_2136 > ((int)0));
			t_sample sah_2169 = __m_sah_19(mod_2166, gt_2170, ((int)0));
			t_sample sah_2155 = __m_sah_20(mod_2152, gt_2170, ((int)0));
			t_sample abs_2160 = fabs(gate_2138);
			__m_slide_21 = fixdenorm((__m_slide_21 + (((abs_2160 > __m_slide_21) ? iup_22 : idown_23) * (abs_2160 - __m_slide_21))));
			t_sample slide_2159 = __m_slide_21;
			__m_slide_24 = fixdenorm((__m_slide_24 + (((sah_2164 > __m_slide_24) ? iup_25 : idown_26) * (sah_2164 - __m_slide_24))));
			t_sample slide_2161 = __m_slide_24;
			t_sample mul_2158 = (slide_2159 * slide_2161);
			t_sample mul_2157 = (m_knob4_oct_5 * mul_2158);
			__m_slide_27 = fixdenorm((__m_slide_27 + (((sah_2150 > __m_slide_27) ? iup_28 : idown_29) * (sah_2150 - __m_slide_27))));
			t_sample slide_2147 = __m_slide_27;
			t_sample mul_2146 = (slide_2159 * slide_2147);
			t_sample mul_2145 = (m_knob5_oct_4 * mul_2146);
			t_sample out2 = (((gate_2137 + mul_2145) + mul_2156) + mul_2157);
			t_sample out1 = (((gate_2137 + mul_2145) + mul_2156) + mul_2157);
			t_sample history_2162_next_2172 = fixdenorm(sah_2164);
			t_sample history_2148_next_2173 = fixdenorm(sah_2150);
			t_sample history_2168_next_2174 = fixdenorm(sah_2169);
			t_sample history_2154_next_2175 = fixdenorm(sah_2155);
			m_history_1 = history_2140_next_2142;
			m_history_14 = history_2154_next_2175;
			m_history_13 = history_2168_next_2174;
			m_history_12 = history_2148_next_2173;
			m_history_11 = history_2162_next_2172;
			m_history_8 = history_2123_next_2133;
			m_history_9 = history_2129_next_2134;
			m_history_10 = history_2125_next_2135;
			m_history_7 = history_2127_next_2132;
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
	inline void set_knob3_dry(t_param _value) {
		m_knob3_dry_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_oct2(t_param _value) {
		m_knob5_oct_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_oct1(t_param _value) {
		m_knob4_oct_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_smooth(t_param _value) {
		m_knob6_smooth_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_knob3_dry(value); break;
		case 1: self->set_knob4_oct1(value); break;
		case 2: self->set_knob5_oct2(value); break;
		case 3: self->set_knob6_smooth(value); break;
		case 4: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_dry_2; break;
		case 1: *value = self->m_knob4_oct_5; break;
		case 2: *value = self->m_knob5_oct_4; break;
		case 3: *value = self->m_knob6_smooth_6; break;
		case 4: *value = self->m_sw_3; break;
		
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
	// initialize parameter 0 ("m_knob3_dry_2")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_dry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_dry_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_oct_5")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_oct1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_oct_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_oct_4")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_oct2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_oct_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_smooth_6")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_smooth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_smooth_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_3")
	pi = self->__commonstate.params + 4;
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


} // Subharmonic::
