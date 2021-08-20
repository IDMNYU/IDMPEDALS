#include "Reverb2.h"

namespace Reverb2 {

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
	Delay m_delay_14;
	Delay m_delay_18;
	Delay m_delay_8;
	Delay m_delay_20;
	Delay m_delay_10;
	Delay m_delay_12;
	Delay m_delay_16;
	Delay m_delay_31;
	Delay m_delay_22;
	Delay m_delay_25;
	Delay m_delay_29;
	Delay m_delay_30;
	Delay m_delay_24;
	Delay m_delay_28;
	Delay m_delay_26;
	Delay m_delay_27;
	Sah __m_sah_32;
	int __exception;
	int vectorsize;
	t_sample m_knob4_fb_3;
	t_sample m_history_11;
	t_sample m_knob5_fb_2;
	t_sample m_knob6_spread_1;
	t_sample samplerate;
	t_sample m_knob3_damp_4;
	t_sample m_history_13;
	t_sample m_sw_5;
	t_sample m_knob1_wetdry_6;
	t_sample m_history_9;
	t_sample m_history_17;
	t_sample m_history_23;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample m_history_7;
	t_sample m_history_15;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_knob6_spread_1 = ((int)0);
		m_knob5_fb_2 = ((t_sample)0.5);
		m_knob4_fb_3 = ((t_sample)0.9);
		m_knob3_damp_4 = ((t_sample)0.5);
		m_sw_5 = ((int)0);
		m_knob1_wetdry_6 = ((int)0);
		m_history_7 = ((int)0);
		m_delay_8.reset("m_delay_8", ((int)4000));
		m_history_9 = ((int)0);
		m_delay_10.reset("m_delay_10", ((int)4000));
		m_history_11 = ((int)0);
		m_delay_12.reset("m_delay_12", ((int)4000));
		m_history_13 = ((int)0);
		m_delay_14.reset("m_delay_14", ((int)4000));
		m_history_15 = ((int)0);
		m_delay_16.reset("m_delay_16", ((int)4000));
		m_history_17 = ((int)0);
		m_delay_18.reset("m_delay_18", ((int)4000));
		m_history_19 = ((int)0);
		m_delay_20.reset("m_delay_20", ((int)4000));
		m_history_21 = ((int)0);
		m_delay_22.reset("m_delay_22", ((int)4000));
		m_history_23 = ((int)0);
		m_delay_24.reset("m_delay_24", ((int)4000));
		m_delay_25.reset("m_delay_25", ((int)4000));
		m_delay_26.reset("m_delay_26", ((int)4000));
		m_delay_27.reset("m_delay_27", ((int)4000));
		m_delay_28.reset("m_delay_28", ((int)4000));
		m_delay_29.reset("m_delay_29", ((int)4000));
		m_delay_30.reset("m_delay_30", ((int)4000));
		m_delay_31.reset("m_delay_31", ((int)4000));
		__m_sah_32.reset(0);
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
		t_sample sqrt_241 = sqrt(m_knob1_wetdry_6);
		t_sample rsub_245 = (((int)1) - m_knob1_wetdry_6);
		t_sample sqrt_244 = sqrt(rsub_245);
		t_sample mul_295 = (m_knob5_fb_2 * ((t_sample)0.9));
		t_sample mul_240 = (m_knob5_fb_2 * ((t_sample)0.9));
		t_sample add_281 = (((int)450) + m_knob6_spread_1);
		t_sample add_235 = (((int)456) + m_knob6_spread_1);
		t_sample add_283 = (((int)682) + m_knob6_spread_1);
		t_sample add_237 = (((int)676) + m_knob6_spread_1);
		t_sample add_293 = (((int)882) + m_knob6_spread_1);
		t_sample add_239 = (((int)888) + m_knob6_spread_1);
		t_sample add_279 = (((int)1112) + m_knob6_spread_1);
		t_sample add_233 = (((int)1106) + m_knob6_spread_1);
		t_sample add_286 = (((int)3114) + m_knob6_spread_1);
		t_sample rsub_248 = (((int)1) - m_knob3_damp_4);
		t_sample add_285 = (((int)3234) + m_knob6_spread_1);
		t_sample rsub_306 = (((int)1) - m_knob3_damp_4);
		t_sample add_287 = (((int)2982) + m_knob6_spread_1);
		t_sample rsub_318 = (((int)1) - m_knob3_damp_4);
		t_sample add_288 = (((int)2844) + m_knob6_spread_1);
		t_sample rsub_333 = (((int)1) - m_knob3_damp_4);
		t_sample add_289 = (((int)2712) + m_knob6_spread_1);
		t_sample rsub_345 = (((int)1) - m_knob3_damp_4);
		t_sample add_290 = (((int)2554) + m_knob6_spread_1);
		t_sample rsub_357 = (((int)1) - m_knob3_damp_4);
		t_sample add_291 = (((int)2376) + m_knob6_spread_1);
		t_sample rsub_370 = (((int)1) - m_knob3_damp_4);
		t_sample add_292 = (((int)2232) + m_knob6_spread_1);
		t_sample rsub_379 = (((int)1) - m_knob3_damp_4);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_300 = __m_sah_32(m_history_7, m_sw_5, ((int)0));
			t_sample gen_302 = sah_300;
			t_sample rsub_298 = (((int)1) - sah_300);
			t_sample history_299_next_301 = fixdenorm(rsub_298);
			t_sample out3 = gen_302;
			t_sample add_305 = (gen_302 + ((int)1));
			t_sample choice_33 = int(add_305);
			t_sample gate_303 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_304 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_243 = (gate_304 * sqrt_244);
			t_sample mul_297 = (gate_304 * ((t_sample)0.015));
			t_sample tap_255 = m_delay_8.read_linear(add_286);
			t_sample gen_277 = tap_255;
			t_sample mul_253 = (tap_255 * m_knob3_damp_4);
			t_sample mul_251 = (m_history_9 * rsub_248);
			t_sample add_252 = (mul_253 + mul_251);
			t_sample mul_249 = (add_252 * m_knob4_fb_3);
			t_sample add_256 = (mul_297 + mul_249);
			t_sample history_250_next_257 = fixdenorm(add_252);
			t_sample tap_310 = m_delay_10.read_linear(add_285);
			t_sample gen_296 = tap_310;
			t_sample mul_309 = (tap_310 * m_knob3_damp_4);
			t_sample mul_312 = (m_history_11 * rsub_306);
			t_sample add_315 = (mul_309 + mul_312);
			t_sample mul_308 = (add_315 * m_knob4_fb_3);
			t_sample add_311 = (mul_297 + mul_308);
			t_sample history_250_next_313 = fixdenorm(add_315);
			t_sample tap_322 = m_delay_12.read_linear(add_287);
			t_sample gen_276 = tap_322;
			t_sample mul_321 = (tap_322 * m_knob3_damp_4);
			t_sample mul_324 = (m_history_13 * rsub_318);
			t_sample add_327 = (mul_321 + mul_324);
			t_sample mul_319 = (add_327 * m_knob4_fb_3);
			t_sample add_323 = (mul_297 + mul_319);
			t_sample history_250_next_325 = fixdenorm(add_327);
			t_sample tap_337 = m_delay_14.read_linear(add_288);
			t_sample gen_275 = tap_337;
			t_sample mul_334 = (tap_337 * m_knob3_damp_4);
			t_sample mul_336 = (m_history_15 * rsub_333);
			t_sample add_332 = (mul_334 + mul_336);
			t_sample mul_330 = (add_332 * m_knob4_fb_3);
			t_sample add_335 = (mul_297 + mul_330);
			t_sample history_250_next_339 = fixdenorm(add_332);
			t_sample tap_349 = m_delay_16.read_linear(add_289);
			t_sample gen_274 = tap_349;
			t_sample mul_346 = (tap_349 * m_knob3_damp_4);
			t_sample mul_348 = (m_history_17 * rsub_345);
			t_sample add_344 = (mul_346 + mul_348);
			t_sample mul_342 = (add_344 * m_knob4_fb_3);
			t_sample add_347 = (mul_297 + mul_342);
			t_sample history_250_next_351 = fixdenorm(add_344);
			t_sample tap_361 = m_delay_18.read_linear(add_290);
			t_sample gen_273 = tap_361;
			t_sample mul_358 = (tap_361 * m_knob3_damp_4);
			t_sample mul_360 = (m_history_19 * rsub_357);
			t_sample add_356 = (mul_358 + mul_360);
			t_sample mul_354 = (add_356 * m_knob4_fb_3);
			t_sample add_359 = (mul_297 + mul_354);
			t_sample history_250_next_363 = fixdenorm(add_356);
			t_sample tap_374 = m_delay_20.read_linear(add_291);
			t_sample gen_272 = tap_374;
			t_sample mul_371 = (tap_374 * m_knob3_damp_4);
			t_sample mul_373 = (m_history_21 * rsub_370);
			t_sample add_369 = (mul_371 + mul_373);
			t_sample mul_367 = (add_369 * m_knob4_fb_3);
			t_sample add_372 = (mul_297 + mul_367);
			t_sample history_250_next_375 = fixdenorm(add_369);
			t_sample tap_381 = m_delay_22.read_linear(add_292);
			t_sample gen_271 = tap_381;
			t_sample mul_385 = (tap_381 * m_knob3_damp_4);
			t_sample mul_386 = (m_history_23 * rsub_379);
			t_sample add_384 = (mul_385 + mul_386);
			t_sample mul_378 = (add_384 * m_knob4_fb_3);
			t_sample add_380 = (mul_297 + mul_378);
			t_sample history_250_next_382 = fixdenorm(add_384);
			t_sample pass_294 = (((((((gen_271 + gen_272) + gen_273) + gen_274) + gen_275) + gen_276) + gen_296) + gen_277);
			t_sample tap_231 = m_delay_24.read_linear(add_279);
			t_sample sub_227 = (pass_294 - tap_231);
			t_sample mul_229 = (tap_231 * mul_295);
			t_sample add_228 = (pass_294 + mul_229);
			t_sample tap_394 = m_delay_25.read_linear(add_293);
			t_sample sub_391 = (sub_227 - tap_394);
			t_sample mul_390 = (tap_394 * mul_295);
			t_sample add_393 = (sub_227 + mul_390);
			t_sample tap_400 = m_delay_26.read_linear(add_283);
			t_sample sub_397 = (sub_391 - tap_400);
			t_sample mul_396 = (tap_400 * mul_295);
			t_sample add_399 = (sub_391 + mul_396);
			t_sample tap_406 = m_delay_27.read_linear(add_281);
			t_sample sub_403 = (sub_397 - tap_406);
			t_sample mul_402 = (tap_406 * mul_295);
			t_sample add_405 = (sub_397 + mul_402);
			t_sample mul_246 = (sub_403 * sqrt_241);
			t_sample add_242 = (mul_243 + mul_246);
			t_sample out1 = (gate_303 + add_242);
			t_sample tap_412 = m_delay_28.read_linear(add_233);
			t_sample sub_409 = (pass_294 - tap_412);
			t_sample mul_408 = (tap_412 * mul_240);
			t_sample add_411 = (pass_294 + mul_408);
			t_sample tap_418 = m_delay_29.read_linear(add_239);
			t_sample sub_415 = (sub_409 - tap_418);
			t_sample mul_414 = (tap_418 * mul_240);
			t_sample add_417 = (sub_409 + mul_414);
			t_sample tap_424 = m_delay_30.read_linear(add_237);
			t_sample sub_421 = (sub_415 - tap_424);
			t_sample mul_420 = (tap_424 * mul_240);
			t_sample add_423 = (sub_415 + mul_420);
			t_sample tap_430 = m_delay_31.read_linear(add_235);
			t_sample sub_427 = (sub_421 - tap_430);
			t_sample mul_426 = (tap_430 * mul_240);
			t_sample add_429 = (sub_421 + mul_426);
			t_sample mul_222 = (sub_427 * sqrt_241);
			t_sample add_221 = (mul_243 + mul_222);
			t_sample out2 = (add_221 + gate_303);
			m_history_7 = history_299_next_301;
			m_delay_31.write(add_429);
			m_delay_30.write(add_423);
			m_delay_29.write(add_417);
			m_delay_28.write(add_411);
			m_delay_27.write(add_405);
			m_delay_26.write(add_399);
			m_delay_25.write(add_393);
			m_delay_24.write(add_228);
			m_history_23 = history_250_next_382;
			m_delay_22.write(add_380);
			m_history_21 = history_250_next_375;
			m_delay_20.write(add_372);
			m_history_19 = history_250_next_363;
			m_delay_18.write(add_359);
			m_history_17 = history_250_next_351;
			m_delay_16.write(add_347);
			m_history_15 = history_250_next_339;
			m_delay_14.write(add_335);
			m_history_13 = history_250_next_325;
			m_delay_12.write(add_323);
			m_history_11 = history_250_next_313;
			m_delay_10.write(add_311);
			m_history_9 = history_250_next_257;
			m_delay_8.write(add_256);
			m_delay_8.step();
			m_delay_10.step();
			m_delay_12.step();
			m_delay_14.step();
			m_delay_16.step();
			m_delay_18.step();
			m_delay_20.step();
			m_delay_22.step();
			m_delay_24.step();
			m_delay_25.step();
			m_delay_26.step();
			m_delay_27.step();
			m_delay_28.step();
			m_delay_29.step();
			m_delay_30.step();
			m_delay_31.step();
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
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_1 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
	};
	inline void set_knob5_fb2(t_param _value) {
		m_knob5_fb_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_knob1_wetdry(value); break;
		case 1: self->set_knob3_damp(value); break;
		case 2: self->set_knob4_fb1(value); break;
		case 3: self->set_knob5_fb2(value); break;
		case 4: self->set_knob6_spread(value); break;
		case 5: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_wetdry_6; break;
		case 1: *value = self->m_knob3_damp_4; break;
		case 2: *value = self->m_knob4_fb_3; break;
		case 3: *value = self->m_knob5_fb_2; break;
		case 4: *value = self->m_knob6_spread_1; break;
		case 5: *value = self->m_sw_5; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_6")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_damp_4")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_fb_3")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_fb_2")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_spread_1")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_5")
	pi = self->__commonstate.params + 5;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_5;
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


} // Reverb2::
