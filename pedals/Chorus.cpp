#include "Chorus.h"

namespace Chorus {

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
	Sah __m_sah_21;
	SineCycle __m_cycle_24;
	SineCycle __m_cycle_23;
	SineCycle __m_cycle_30;
	SineCycle __m_cycle_25;
	SineCycle __m_cycle_27;
	SineCycle __m_cycle_26;
	SineCycle __m_cycle_29;
	SineCycle __m_cycle_28;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_10;
	t_sample m_history_5;
	t_sample m_history_6;
	t_sample m_history_4;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample m_history_7;
	t_sample samplerate;
	t_sample m_history_9;
	t_sample m_sw_20;
	t_sample m_knob6_taps_18;
	t_sample m_history_13;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_knob5_breadth_19;
	t_sample m_history_8;
	t_sample m_knob3_depth_16;
	t_sample m_sw_15;
	t_sample m_knob4_rate_17;
	t_sample m_history_14;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)20000));
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
		m_sw_15 = ((int)0);
		m_knob3_depth_16 = ((int)0);
		m_knob4_rate_17 = ((int)0);
		m_knob6_taps_18 = ((int)0);
		m_knob5_breadth_19 = 256;
		m_sw_20 = ((int)0);
		__m_sah_21.reset(0);
		__m_cycle_23.reset(samplerate, 0);
		__m_cycle_24.reset(samplerate, 0);
		__m_cycle_25.reset(samplerate, 0);
		__m_cycle_26.reset(samplerate, 0);
		__m_cycle_27.reset(samplerate, 0);
		__m_cycle_28.reset(samplerate, 0);
		__m_cycle_29.reset(samplerate, 0);
		__m_cycle_30.reset(samplerate, 0);
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
		t_sample expr_12388 = (((int)1) - sqrt(sqrt((((int)1) - m_knob3_depth_16))));
		t_sample expr_12387 = (((int)1) - sqrt(sqrt((((int)1) - m_knob4_rate_17))));
		t_sample div_12270 = (m_sw_15 * ((t_sample)0.5));
		t_sample add_12269 = (div_12270 + ((t_sample)0.5));
		t_sample mul_12278 = (expr_12388 * ((int)1000));
		t_sample add_12277 = (mul_12278 + ((int)2));
		t_sample mul_12275 = (expr_12387 * ((int)10));
		t_sample add_12276 = (mul_12275 + ((t_sample)0.01));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_12381 = __m_sah_21(m_history_14, m_sw_20, ((int)0));
			t_sample gen_12383 = sah_12381;
			t_sample rsub_12379 = (((int)1) - sah_12381);
			t_sample history_12380_next_12382 = fixdenorm(rsub_12379);
			t_sample out3 = gen_12383;
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample add_12384 = (gen_12383 + ((int)1));
			t_sample choice_22 = int(add_12384);
			t_sample gate_12376 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_12377 = ((choice_22 >= 2) ? in1 : 0);
			t_sample switch_12314 = (m_sw_15 ? ((int)0) : gate_12377);
			t_sample mix_12546 = (m_history_13 + (((t_sample)0.0019634941468452) * (m_knob6_taps_18 - m_history_13)));
			t_sample mix_12284 = mix_12546;
			t_sample mix_12547 = (m_history_12 + (((t_sample)0.0019634941468452) * (mix_12284 - m_history_12)));
			t_sample mix_12282 = mix_12547;
			t_sample mix_12548 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_12282 - m_history_11)));
			t_sample mix_12280 = mix_12548;
			t_sample gen_12312 = mix_12280;
			t_sample history_12286_next_12289 = fixdenorm(mix_12284);
			t_sample history_12283_next_12290 = fixdenorm(mix_12282);
			t_sample history_12281_next_12291 = fixdenorm(mix_12280);
			t_sample sub_12552 = (gen_12312 - ((int)0));
			t_sample scale_12549 = ((safepow((sub_12552 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.5)) + ((int)1));
			t_sample sub_12556 = (gen_12312 - ((int)0));
			t_sample scale_12553 = ((safepow((sub_12556 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-2));
			t_sample clamp_12298 = ((scale_12553 <= ((int)0)) ? ((int)0) : ((scale_12553 >= ((int)1)) ? ((int)1) : scale_12553));
			t_sample sub_12560 = (gen_12312 - ((int)0));
			t_sample scale_12557 = ((safepow((sub_12560 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-3));
			t_sample clamp_12296 = ((scale_12557 <= ((int)0)) ? ((int)0) : ((scale_12557 >= ((int)1)) ? ((int)1) : scale_12557));
			t_sample sub_12564 = (gen_12312 - ((int)0));
			t_sample scale_12561 = ((safepow((sub_12564 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-1));
			t_sample clamp_12300 = ((scale_12561 <= ((int)0)) ? ((int)0) : ((scale_12561 >= ((int)1)) ? ((int)1) : scale_12561));
			t_sample mix_12565 = (m_history_10 + (((t_sample)0.0019634941468452) * (m_knob5_breadth_19 - m_history_10)));
			t_sample mix_12393 = mix_12565;
			t_sample mix_12566 = (m_history_9 + (((t_sample)0.0019634941468452) * (mix_12393 - m_history_9)));
			t_sample mix_12392 = mix_12566;
			t_sample mix_12567 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_12392 - m_history_8)));
			t_sample mix_12394 = mix_12567;
			t_sample gen_12292 = mix_12394;
			t_sample history_12286_next_12400 = fixdenorm(mix_12393);
			t_sample history_12283_next_12398 = fixdenorm(mix_12392);
			t_sample history_12281_next_12389 = fixdenorm(mix_12394);
			t_sample mul_12279 = (gen_12292 * ((int)1));
			t_sample mul_12295 = (gen_12292 * ((int)2));
			t_sample mul_12294 = (gen_12292 * ((int)3));
			t_sample mul_12293 = (gen_12292 * ((int)4));
			t_sample mix_12568 = (m_history_7 + (((t_sample)0.0019634941468452) * (add_12277 - m_history_7)));
			t_sample mix_12409 = mix_12568;
			t_sample mix_12569 = (m_history_6 + (((t_sample)0.0019634941468452) * (mix_12409 - m_history_6)));
			t_sample mix_12408 = mix_12569;
			t_sample mix_12570 = (m_history_5 + (((t_sample)0.0019634941468452) * (mix_12408 - m_history_5)));
			t_sample mix_12410 = mix_12570;
			t_sample gen_12386 = mix_12410;
			t_sample history_12286_next_12414 = fixdenorm(mix_12409);
			t_sample history_12283_next_12413 = fixdenorm(mix_12408);
			t_sample history_12281_next_12404 = fixdenorm(mix_12410);
			t_sample mix_12571 = (m_history_4 + (((t_sample)0.0019634941468452) * (add_12276 - m_history_4)));
			t_sample mix_12427 = mix_12571;
			t_sample mix_12572 = (m_history_3 + (((t_sample)0.0019634941468452) * (mix_12427 - m_history_3)));
			t_sample mix_12426 = mix_12572;
			t_sample mix_12573 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_12426 - m_history_2)));
			t_sample mix_12428 = mix_12573;
			t_sample gen_12323 = mix_12428;
			t_sample history_12286_next_12430 = fixdenorm(mix_12427);
			t_sample history_12283_next_12419 = fixdenorm(mix_12426);
			t_sample history_12281_next_12424 = fixdenorm(mix_12428);
			t_sample mul_12327 = (gen_12323 * ((int)1));
			__m_cycle_23.freq(mul_12327);
			t_sample cycle_12365 = __m_cycle_23(__sinedata);
			t_sample cycleindex_12366 = __m_cycle_23.phase();
			t_sample mul_12363 = (cycle_12365 * gen_12386);
			t_sample add_12364 = (mul_12363 + mul_12279);
			t_sample mul_12358 = (gen_12323 * ((t_sample)1.51));
			__m_cycle_24.freq(mul_12358);
			t_sample cycle_12361 = __m_cycle_24(__sinedata);
			t_sample cycleindex_12362 = __m_cycle_24.phase();
			t_sample mul_12359 = (cycle_12361 * gen_12386);
			t_sample add_12360 = (mul_12359 + mul_12279);
			t_sample mul_12326 = (gen_12323 * ((t_sample)0.48));
			__m_cycle_25.freq(mul_12326);
			t_sample cycle_12355 = __m_cycle_25(__sinedata);
			t_sample cycleindex_12356 = __m_cycle_25.phase();
			t_sample mul_12353 = (cycle_12355 * gen_12386);
			t_sample add_12354 = (mul_12353 + mul_12295);
			t_sample mul_12348 = (gen_12323 * ((t_sample)0.73));
			__m_cycle_26.freq(mul_12348);
			t_sample cycle_12351 = __m_cycle_26(__sinedata);
			t_sample cycleindex_12352 = __m_cycle_26.phase();
			t_sample mul_12349 = (cycle_12351 * gen_12386);
			t_sample add_12350 = (mul_12349 + mul_12295);
			t_sample mul_12325 = (gen_12323 * ((t_sample)1.245));
			__m_cycle_27.freq(mul_12325);
			t_sample cycle_12344 = __m_cycle_27(__sinedata);
			t_sample cycleindex_12345 = __m_cycle_27.phase();
			t_sample mul_12342 = (cycle_12344 * gen_12386);
			t_sample add_12343 = (mul_12342 + mul_12294);
			t_sample mul_12337 = (gen_12323 * ((t_sample)0.81));
			__m_cycle_28.freq(mul_12337);
			t_sample cycle_12340 = __m_cycle_28(__sinedata);
			t_sample cycleindex_12341 = __m_cycle_28.phase();
			t_sample mul_12338 = (cycle_12340 * gen_12386);
			t_sample add_12339 = (mul_12338 + mul_12294);
			t_sample mul_12324 = (gen_12323 * ((t_sample)1.93));
			__m_cycle_29.freq(mul_12324);
			t_sample cycle_12335 = __m_cycle_29(__sinedata);
			t_sample cycleindex_12336 = __m_cycle_29.phase();
			t_sample mul_12333 = (cycle_12335 * gen_12386);
			t_sample add_12334 = (mul_12333 + mul_12293);
			t_sample mul_12328 = (gen_12323 * ((t_sample)2.11));
			__m_cycle_30.freq(mul_12328);
			t_sample cycle_12331 = __m_cycle_30(__sinedata);
			t_sample cycleindex_12332 = __m_cycle_30.phase();
			t_sample mul_12329 = (cycle_12331 * gen_12386);
			t_sample add_12330 = (mul_12329 + mul_12293);
			t_sample tap_12368 = m_delay_1.read_linear(add_12364);
			t_sample tap_12369 = m_delay_1.read_linear(add_12360);
			t_sample tap_12370 = m_delay_1.read_linear(add_12354);
			t_sample tap_12371 = m_delay_1.read_linear(add_12350);
			t_sample tap_12372 = m_delay_1.read_linear(add_12343);
			t_sample tap_12373 = m_delay_1.read_linear(add_12339);
			t_sample tap_12374 = m_delay_1.read_linear(add_12334);
			t_sample tap_12375 = m_delay_1.read_linear(add_12330);
			t_sample mul_12310 = (tap_12373 * clamp_12298);
			t_sample mul_12309 = (tap_12374 * clamp_12296);
			t_sample mul_12305 = (tap_12370 * clamp_12300);
			t_sample mul_12306 = (tap_12369 * ((int)1));
			t_sample mul_12346 = ((((mul_12306 + mul_12305) + mul_12309) + mul_12310) * scale_12549);
			t_sample add_12357 = (switch_12314 + mul_12346);
			t_sample mul_12271 = (add_12269 * add_12357);
			t_sample out2 = (gate_12376 + mul_12271);
			t_sample mul_12311 = (tap_12372 * clamp_12298);
			t_sample mul_12308 = (tap_12375 * clamp_12296);
			t_sample mul_12304 = (tap_12371 * clamp_12300);
			t_sample mul_12307 = (tap_12368 * ((int)1));
			t_sample mul_12347 = ((((mul_12307 + mul_12304) + mul_12308) + mul_12311) * scale_12549);
			t_sample add_12385 = (switch_12314 + mul_12347);
			t_sample mul_12272 = (add_12269 * add_12385);
			t_sample out1 = (gate_12376 + mul_12272);
			m_history_14 = history_12380_next_12382;
			m_history_13 = history_12286_next_12289;
			m_history_11 = history_12281_next_12291;
			m_history_12 = history_12283_next_12290;
			m_history_10 = history_12286_next_12400;
			m_history_8 = history_12281_next_12389;
			m_history_9 = history_12283_next_12398;
			m_history_7 = history_12286_next_12414;
			m_history_5 = history_12281_next_12404;
			m_history_6 = history_12283_next_12413;
			m_history_4 = history_12286_next_12430;
			m_history_2 = history_12281_next_12424;
			m_history_3 = history_12283_next_12419;
			m_delay_1.write(gate_12377);
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
	inline void set_sw5(t_param _value) {
		m_sw_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_taps(t_param _value) {
		m_knob6_taps_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_breadth(t_param _value) {
		m_knob5_breadth_19 = (_value < 240 ? 240 : (_value > 2400 ? 2400 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_knob3_depth(value); break;
		case 1: self->set_knob4_rate(value); break;
		case 2: self->set_knob5_breadth(value); break;
		case 3: self->set_knob6_taps(value); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_depth_16; break;
		case 1: *value = self->m_knob4_rate_17; break;
		case 2: *value = self->m_knob5_breadth_19; break;
		case 3: *value = self->m_knob6_taps_18; break;
		case 4: *value = self->m_sw_20; break;
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
	// initialize parameter 0 ("m_knob3_depth_16")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_17")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_breadth_19")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_breadth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_breadth_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 240;
	pi->outputmax = 2400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_taps_18")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_taps";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_taps_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_20")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_20;
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


} // Chorus::
