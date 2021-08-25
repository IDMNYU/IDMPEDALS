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
	t_sample m_sw_14;
	t_sample m_knob5_rate_13;
	t_sample m_knob6_res_12;
	t_sample m_history_15;
	t_sample m_history_17;
	t_sample m_history_16;
	t_sample m_history_2;
	t_sample m_knob4_depth_11;
	t_sample samplerate;
	t_sample m_history_5;
	t_sample m_history_4;
	t_sample m_sw_10;
	t_sample m_history_6;
	t_sample m_history_8;
	t_sample m_history_7;
	t_sample m_knob3_manual_9;
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
		m_knob3_manual_9 = ((int)0);
		m_sw_10 = ((int)0);
		m_knob4_depth_11 = ((int)0);
		m_knob6_res_12 = ((int)0);
		m_knob5_rate_13 = ((int)0);
		m_sw_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
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
		t_sample sqrt_22 = sqrt(m_knob6_res_12);
		t_sample sqrt_31 = sqrt(sqrt_22);
		t_sample mul_40 = (sqrt_31 * ((t_sample)0.99));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample mix_1354 = (m_history_17 + (((t_sample)0.0042742627044161) * (m_knob3_manual_9 - m_history_17)));
			t_sample mix_7 = mix_1354;
			t_sample mix_1355 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_7 - m_history_16)));
			t_sample mix_5 = mix_1355;
			t_sample mix_1356 = (m_history_15 + (((t_sample)0.0042742627044161) * (mix_5 - m_history_15)));
			t_sample mix_3 = mix_1356;
			t_sample gen_15 = mix_3;
			t_sample history_8_next_10 = fixdenorm(mix_7);
			t_sample history_6_next_11 = fixdenorm(mix_5);
			t_sample history_4_next_12 = fixdenorm(mix_3);
			t_sample expr_1279 = (((int)1) - sqrt((((int)1) - gen_15)));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample mix_1357 = (m_history_8 + (((t_sample)0.0042742627044161) * (m_knob5_rate_13 - m_history_8)));
			t_sample mix_1284 = mix_1357;
			t_sample mix_1358 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_1284 - m_history_7)));
			t_sample mix_1282 = mix_1358;
			t_sample mix_1359 = (m_history_6 + (((t_sample)0.0042742627044161) * (mix_1282 - m_history_6)));
			t_sample mix_1287 = mix_1359;
			t_sample gen_14 = mix_1287;
			t_sample history_8_next_1285 = fixdenorm(mix_1284);
			t_sample history_6_next_1291 = fixdenorm(mix_1282);
			t_sample history_4_next_1289 = fixdenorm(mix_1287);
			t_sample expr_1280 = (((int)1) - sqrt(sqrt((((int)1) - gen_14))));
			t_sample sah_25 = __m_sah_18(m_history_5, m_sw_10, ((int)0));
			t_sample gen_27 = sah_25;
			t_sample rsub_23 = (((int)1) - sah_25);
			t_sample history_24_next_26 = fixdenorm(rsub_23);
			t_sample out3 = gen_27;
			t_sample mix_1360 = (m_history_4 + (((t_sample)0.0042742627044161) * (m_knob4_depth_11 - m_history_4)));
			t_sample mix_1296 = mix_1360;
			t_sample mix_1361 = (m_history_3 + (((t_sample)0.0042742627044161) * (mix_1296 - m_history_3)));
			t_sample mix_1302 = mix_1361;
			t_sample mix_1362 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_1302 - m_history_2)));
			t_sample mix_1303 = mix_1362;
			t_sample gen_13 = mix_1303;
			t_sample history_8_next_1300 = fixdenorm(mix_1296);
			t_sample history_6_next_1298 = fixdenorm(mix_1302);
			t_sample history_4_next_1304 = fixdenorm(mix_1303);
			t_sample expr_1281 = (((int)1) - sqrt(sqrt((((int)1) - gen_13))));
			t_sample add_30 = (gen_27 + ((int)1));
			t_sample choice_19 = int(add_30);
			t_sample gate_28 = (((choice_19 >= 1) && (choice_19 < 2)) ? in1 : 0);
			t_sample gate_29 = ((choice_19 >= 2) ? in1 : 0);
			t_sample switch_893 = (m_sw_14 ? gate_29 : ((int)0));
			t_sample mul_727 = (expr_1279 * ((int)24000));
			t_sample mul_39 = (expr_1281 * mul_727);
			t_sample mul_34 = (expr_1280 * ((int)127));
			t_sample mtof_1 = mtof(mul_34, ((int)440));
			__m_cycle_20.freq(mtof_1);
			t_sample cycle_35 = __m_cycle_20(__sinedata);
			t_sample cycleindex_36 = __m_cycle_20.phase();
			t_sample mul_33 = (cycle_35 * mul_39);
			t_sample add_37 = (mul_727 + mul_33);
			t_sample clamp_776 = ((add_37 <= ((int)0)) ? ((int)0) : ((add_37 >= ((int)48000)) ? ((int)48000) : add_37));
			t_sample tap_826 = m_delay_1.read_cubic(clamp_776);
			t_sample tap_827 = m_delay_1.read_cubic(mul_727);
			t_sample add_21 = (switch_893 + tap_826);
			t_sample div_19 = (add_21 * ((t_sample)0.5));
			t_sample out1 = (div_19 + gate_28);
			t_sample add_20 = (switch_893 + tap_826);
			t_sample div_18 = (add_20 * ((t_sample)0.5));
			t_sample out2 = (div_18 + gate_28);
			t_sample mul_41 = (tap_827 * mul_40);
			m_history_17 = history_8_next_10;
			m_history_15 = history_4_next_12;
			m_history_16 = history_6_next_11;
			m_history_8 = history_8_next_1285;
			m_history_6 = history_4_next_1289;
			m_history_7 = history_6_next_1291;
			m_history_5 = history_24_next_26;
			m_history_4 = history_8_next_1300;
			m_history_2 = history_4_next_1304;
			m_history_3 = history_6_next_1298;
			m_delay_1.write((gate_29 + mul_41));
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
	inline void set_knob3_manual(t_param _value) {
		m_knob3_manual_9 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_10 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_depth(t_param _value) {
		m_knob4_depth_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_res(t_param _value) {
		m_knob6_res_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_rate(t_param _value) {
		m_knob5_rate_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_manual_9; break;
		case 1: *value = self->m_knob4_depth_11; break;
		case 2: *value = self->m_knob5_rate_13; break;
		case 3: *value = self->m_knob6_res_12; break;
		case 4: *value = self->m_sw_10; break;
		case 5: *value = self->m_sw_14; break;
		
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
	// initialize parameter 0 ("m_knob3_manual_9")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_manual";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_manual_9;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_depth_11")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_depth_11;
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
	// initialize parameter 3 ("m_knob6_res_12")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_res_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_10")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_10;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_14")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_14;
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
