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
	t_sample m_knob5_breadth_18;
	t_sample m_history_13;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_knob4_rate_19;
	t_sample m_history_8;
	t_sample m_knob3_depth_16;
	t_sample m_knob6_taps_15;
	t_sample m_sw_17;
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
		m_knob6_taps_15 = ((int)0);
		m_knob3_depth_16 = ((int)0);
		m_sw_17 = ((int)0);
		m_knob5_breadth_18 = 256;
		m_knob4_rate_19 = ((int)0);
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
		t_sample expr_3339 = (((int)1) - sqrt(sqrt((((int)1) - m_knob4_rate_19))));
		t_sample expr_3340 = (((int)1) - sqrt(sqrt((((int)1) - m_knob3_depth_16))));
		t_sample mul_3230 = (expr_3340 * ((int)1000));
		t_sample add_3229 = (mul_3230 + ((int)2));
		t_sample mul_3227 = (expr_3339 * ((int)10));
		t_sample add_3228 = (mul_3227 + ((t_sample)0.01));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_3333 = __m_sah_21(m_history_14, m_sw_17, ((int)0));
			t_sample gen_3335 = sah_3333;
			t_sample rsub_3331 = (((int)1) - sah_3333);
			t_sample history_3332_next_3334 = fixdenorm(rsub_3331);
			t_sample out3 = gen_3335;
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample add_3336 = (gen_3335 + ((int)1));
			t_sample choice_22 = int(add_3336);
			t_sample gate_3328 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_3329 = ((choice_22 >= 2) ? in1 : 0);
			t_sample switch_3266 = (m_sw_20 ? ((int)0) : gate_3329);
			t_sample mix_3554 = (m_history_13 + (((t_sample)0.0019634941468452) * (m_knob6_taps_15 - m_history_13)));
			t_sample mix_3236 = mix_3554;
			t_sample mix_3555 = (m_history_12 + (((t_sample)0.0019634941468452) * (mix_3236 - m_history_12)));
			t_sample mix_3234 = mix_3555;
			t_sample mix_3556 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_3234 - m_history_11)));
			t_sample mix_3232 = mix_3556;
			t_sample gen_3264 = mix_3232;
			t_sample history_3238_next_3241 = fixdenorm(mix_3236);
			t_sample history_3235_next_3242 = fixdenorm(mix_3234);
			t_sample history_3233_next_3243 = fixdenorm(mix_3232);
			t_sample sub_3560 = (gen_3264 - ((int)0));
			t_sample scale_3557 = ((safepow((sub_3560 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.5)) + ((int)1));
			t_sample sub_3564 = (gen_3264 - ((int)0));
			t_sample scale_3561 = ((safepow((sub_3564 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-2));
			t_sample clamp_3250 = ((scale_3561 <= ((int)0)) ? ((int)0) : ((scale_3561 >= ((int)1)) ? ((int)1) : scale_3561));
			t_sample sub_3568 = (gen_3264 - ((int)0));
			t_sample scale_3565 = ((safepow((sub_3568 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-3));
			t_sample clamp_3248 = ((scale_3565 <= ((int)0)) ? ((int)0) : ((scale_3565 >= ((int)1)) ? ((int)1) : scale_3565));
			t_sample sub_3572 = (gen_3264 - ((int)0));
			t_sample scale_3569 = ((safepow((sub_3572 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-1));
			t_sample clamp_3252 = ((scale_3569 <= ((int)0)) ? ((int)0) : ((scale_3569 >= ((int)1)) ? ((int)1) : scale_3569));
			t_sample mix_3573 = (m_history_10 + (((t_sample)0.0019634941468452) * (m_knob5_breadth_18 - m_history_10)));
			t_sample mix_3342 = mix_3573;
			t_sample mix_3574 = (m_history_9 + (((t_sample)0.0019634941468452) * (mix_3342 - m_history_9)));
			t_sample mix_3345 = mix_3574;
			t_sample mix_3575 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_3345 - m_history_8)));
			t_sample mix_3350 = mix_3575;
			t_sample gen_3244 = mix_3350;
			t_sample history_3238_next_3347 = fixdenorm(mix_3342);
			t_sample history_3235_next_3346 = fixdenorm(mix_3345);
			t_sample history_3233_next_3341 = fixdenorm(mix_3350);
			t_sample mul_3231 = (gen_3244 * ((int)1));
			t_sample mul_3247 = (gen_3244 * ((int)2));
			t_sample mul_3246 = (gen_3244 * ((int)3));
			t_sample mul_3245 = (gen_3244 * ((int)4));
			t_sample mix_3576 = (m_history_7 + (((t_sample)0.0019634941468452) * (add_3229 - m_history_7)));
			t_sample mix_3358 = mix_3576;
			t_sample mix_3577 = (m_history_6 + (((t_sample)0.0019634941468452) * (mix_3358 - m_history_6)));
			t_sample mix_3362 = mix_3577;
			t_sample mix_3578 = (m_history_5 + (((t_sample)0.0019634941468452) * (mix_3362 - m_history_5)));
			t_sample mix_3357 = mix_3578;
			t_sample gen_3338 = mix_3357;
			t_sample history_3238_next_3361 = fixdenorm(mix_3358);
			t_sample history_3235_next_3360 = fixdenorm(mix_3362);
			t_sample history_3233_next_3356 = fixdenorm(mix_3357);
			t_sample mix_3579 = (m_history_4 + (((t_sample)0.0019634941468452) * (add_3228 - m_history_4)));
			t_sample mix_3378 = mix_3579;
			t_sample mix_3580 = (m_history_3 + (((t_sample)0.0019634941468452) * (mix_3378 - m_history_3)));
			t_sample mix_3374 = mix_3580;
			t_sample mix_3581 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_3374 - m_history_2)));
			t_sample mix_3375 = mix_3581;
			t_sample gen_3275 = mix_3375;
			t_sample history_3238_next_3381 = fixdenorm(mix_3378);
			t_sample history_3235_next_3371 = fixdenorm(mix_3374);
			t_sample history_3233_next_3373 = fixdenorm(mix_3375);
			t_sample mul_3279 = (gen_3275 * ((int)1));
			__m_cycle_23.freq(mul_3279);
			t_sample cycle_3317 = __m_cycle_23(__sinedata);
			t_sample cycleindex_3318 = __m_cycle_23.phase();
			t_sample mul_3315 = (cycle_3317 * gen_3338);
			t_sample add_3316 = (mul_3315 + mul_3231);
			t_sample mul_3310 = (gen_3275 * ((t_sample)1.51));
			__m_cycle_24.freq(mul_3310);
			t_sample cycle_3313 = __m_cycle_24(__sinedata);
			t_sample cycleindex_3314 = __m_cycle_24.phase();
			t_sample mul_3311 = (cycle_3313 * gen_3338);
			t_sample add_3312 = (mul_3311 + mul_3231);
			t_sample mul_3278 = (gen_3275 * ((t_sample)0.48));
			__m_cycle_25.freq(mul_3278);
			t_sample cycle_3307 = __m_cycle_25(__sinedata);
			t_sample cycleindex_3308 = __m_cycle_25.phase();
			t_sample mul_3305 = (cycle_3307 * gen_3338);
			t_sample add_3306 = (mul_3305 + mul_3247);
			t_sample mul_3300 = (gen_3275 * ((t_sample)0.73));
			__m_cycle_26.freq(mul_3300);
			t_sample cycle_3303 = __m_cycle_26(__sinedata);
			t_sample cycleindex_3304 = __m_cycle_26.phase();
			t_sample mul_3301 = (cycle_3303 * gen_3338);
			t_sample add_3302 = (mul_3301 + mul_3247);
			t_sample mul_3277 = (gen_3275 * ((t_sample)1.245));
			__m_cycle_27.freq(mul_3277);
			t_sample cycle_3296 = __m_cycle_27(__sinedata);
			t_sample cycleindex_3297 = __m_cycle_27.phase();
			t_sample mul_3294 = (cycle_3296 * gen_3338);
			t_sample add_3295 = (mul_3294 + mul_3246);
			t_sample mul_3289 = (gen_3275 * ((t_sample)0.81));
			__m_cycle_28.freq(mul_3289);
			t_sample cycle_3292 = __m_cycle_28(__sinedata);
			t_sample cycleindex_3293 = __m_cycle_28.phase();
			t_sample mul_3290 = (cycle_3292 * gen_3338);
			t_sample add_3291 = (mul_3290 + mul_3246);
			t_sample mul_3276 = (gen_3275 * ((t_sample)1.93));
			__m_cycle_29.freq(mul_3276);
			t_sample cycle_3287 = __m_cycle_29(__sinedata);
			t_sample cycleindex_3288 = __m_cycle_29.phase();
			t_sample mul_3285 = (cycle_3287 * gen_3338);
			t_sample add_3286 = (mul_3285 + mul_3245);
			t_sample mul_3280 = (gen_3275 * ((t_sample)2.11));
			__m_cycle_30.freq(mul_3280);
			t_sample cycle_3283 = __m_cycle_30(__sinedata);
			t_sample cycleindex_3284 = __m_cycle_30.phase();
			t_sample mul_3281 = (cycle_3283 * gen_3338);
			t_sample add_3282 = (mul_3281 + mul_3245);
			t_sample tap_3320 = m_delay_1.read_linear(add_3316);
			t_sample tap_3321 = m_delay_1.read_linear(add_3312);
			t_sample tap_3322 = m_delay_1.read_linear(add_3306);
			t_sample tap_3323 = m_delay_1.read_linear(add_3302);
			t_sample tap_3324 = m_delay_1.read_linear(add_3295);
			t_sample tap_3325 = m_delay_1.read_linear(add_3291);
			t_sample tap_3326 = m_delay_1.read_linear(add_3286);
			t_sample tap_3327 = m_delay_1.read_linear(add_3282);
			t_sample mul_3262 = (tap_3325 * clamp_3250);
			t_sample mul_3261 = (tap_3326 * clamp_3248);
			t_sample mul_3257 = (tap_3322 * clamp_3252);
			t_sample mul_3258 = (tap_3321 * ((int)1));
			t_sample mul_3298 = ((((mul_3258 + mul_3257) + mul_3261) + mul_3262) * scale_3557);
			t_sample add_3309 = (switch_3266 + mul_3298);
			t_sample out2 = (add_3309 + gate_3328);
			t_sample mul_3263 = (tap_3324 * clamp_3250);
			t_sample mul_3260 = (tap_3327 * clamp_3248);
			t_sample mul_3256 = (tap_3323 * clamp_3252);
			t_sample mul_3259 = (tap_3320 * ((int)1));
			t_sample mul_3299 = ((((mul_3259 + mul_3256) + mul_3260) + mul_3263) * scale_3557);
			t_sample add_3337 = (switch_3266 + mul_3299);
			t_sample out1 = (gate_3328 + add_3337);
			m_history_14 = history_3332_next_3334;
			m_history_13 = history_3238_next_3241;
			m_history_11 = history_3233_next_3243;
			m_history_12 = history_3235_next_3242;
			m_history_10 = history_3238_next_3347;
			m_history_8 = history_3233_next_3341;
			m_history_9 = history_3235_next_3346;
			m_history_7 = history_3238_next_3361;
			m_history_5 = history_3233_next_3356;
			m_history_6 = history_3235_next_3360;
			m_history_4 = history_3238_next_3381;
			m_history_2 = history_3233_next_3373;
			m_history_3 = history_3235_next_3371;
			m_delay_1.write(gate_3329);
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
	inline void set_knob6_taps(t_param _value) {
		m_knob6_taps_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_breadth(t_param _value) {
		m_knob5_breadth_18 = (_value < 240 ? 240 : (_value > 2400 ? 2400 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
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
		case 1: *value = self->m_knob4_rate_19; break;
		case 2: *value = self->m_knob5_breadth_18; break;
		case 3: *value = self->m_knob6_taps_15; break;
		case 4: *value = self->m_sw_17; break;
		case 5: *value = self->m_sw_20; break;
		
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
	// initialize parameter 1 ("m_knob4_rate_19")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_breadth_18")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_breadth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_breadth_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 240;
	pi->outputmax = 2400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_taps_15")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_taps";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_taps_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_17")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_20")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Chorus::
