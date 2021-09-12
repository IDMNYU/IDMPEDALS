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
	t_sample m_knob4_rate_19;
	t_sample m_history_8;
	t_sample m_knob5_breadth_16;
	t_sample m_sw_15;
	t_sample m_knob3_depth_17;
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
		m_knob5_breadth_16 = 256;
		m_knob3_depth_17 = ((int)0);
		m_knob6_taps_18 = ((int)0);
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
		t_sample expr_318 = (((int)1) - sqrt(sqrt((((int)1) - m_knob4_rate_19))));
		t_sample expr_319 = (((int)1) - sqrt(sqrt((((int)1) - m_knob3_depth_17))));
		t_sample div_203 = (m_sw_15 * ((t_sample)0.5));
		t_sample add_202 = (div_203 + ((t_sample)0.5));
		t_sample mul_211 = (expr_319 * ((int)1000));
		t_sample add_210 = (mul_211 + ((int)2));
		t_sample mul_208 = (expr_318 * ((int)10));
		t_sample add_209 = (mul_208 + ((t_sample)0.01));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_312 = __m_sah_21(m_history_14, m_sw_20, ((int)0));
			t_sample gen_314 = sah_312;
			t_sample rsub_310 = (((int)1) - sah_312);
			t_sample history_311_next_313 = fixdenorm(rsub_310);
			t_sample out3 = gen_314;
			t_sample add_315 = (gen_314 + ((int)1));
			t_sample choice_22 = int(add_315);
			t_sample gate_307 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_308 = ((choice_22 >= 2) ? in1 : 0);
			t_sample switch_245 = (m_sw_15 ? ((int)0) : gate_308);
			t_sample mix_415 = (m_history_13 + (((t_sample)0.003926980723806) * (m_knob6_taps_18 - m_history_13)));
			t_sample mix_217 = mix_415;
			t_sample mix_416 = (m_history_12 + (((t_sample)0.003926980723806) * (mix_217 - m_history_12)));
			t_sample mix_215 = mix_416;
			t_sample mix_417 = (m_history_11 + (((t_sample)0.003926980723806) * (mix_215 - m_history_11)));
			t_sample mix_213 = mix_417;
			t_sample gen_243 = mix_213;
			t_sample history_218_next_220 = fixdenorm(mix_217);
			t_sample history_216_next_221 = fixdenorm(mix_215);
			t_sample history_214_next_222 = fixdenorm(mix_213);
			t_sample sub_421 = (gen_243 - ((int)0));
			t_sample scale_418 = ((safepow((sub_421 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.5)) + ((int)1));
			t_sample sub_425 = (gen_243 - ((int)0));
			t_sample scale_422 = ((safepow((sub_425 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-2));
			t_sample clamp_229 = ((scale_422 <= ((int)0)) ? ((int)0) : ((scale_422 >= ((int)1)) ? ((int)1) : scale_422));
			t_sample sub_429 = (gen_243 - ((int)0));
			t_sample scale_426 = ((safepow((sub_429 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-3));
			t_sample clamp_227 = ((scale_426 <= ((int)0)) ? ((int)0) : ((scale_426 >= ((int)1)) ? ((int)1) : scale_426));
			t_sample sub_433 = (gen_243 - ((int)0));
			t_sample scale_430 = ((safepow((sub_433 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-1));
			t_sample clamp_231 = ((scale_430 <= ((int)0)) ? ((int)0) : ((scale_430 >= ((int)1)) ? ((int)1) : scale_430));
			t_sample mix_434 = (m_history_10 + (((t_sample)0.003926980723806) * (m_knob5_breadth_16 - m_history_10)));
			t_sample mix_324 = mix_434;
			t_sample mix_435 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_324 - m_history_9)));
			t_sample mix_326 = mix_435;
			t_sample mix_436 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_326 - m_history_8)));
			t_sample mix_320 = mix_436;
			t_sample gen_223 = mix_320;
			t_sample history_218_next_328 = fixdenorm(mix_324);
			t_sample history_216_next_325 = fixdenorm(mix_326);
			t_sample history_214_next_322 = fixdenorm(mix_320);
			t_sample mul_212 = (gen_223 * ((int)1));
			t_sample mul_226 = (gen_223 * ((int)2));
			t_sample mul_225 = (gen_223 * ((int)3));
			t_sample mul_224 = (gen_223 * ((int)4));
			t_sample mix_437 = (m_history_7 + (((t_sample)0.003926980723806) * (add_210 - m_history_7)));
			t_sample mix_341 = mix_437;
			t_sample mix_438 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_341 - m_history_6)));
			t_sample mix_337 = mix_438;
			t_sample mix_439 = (m_history_5 + (((t_sample)0.003926980723806) * (mix_337 - m_history_5)));
			t_sample mix_333 = mix_439;
			t_sample gen_317 = mix_333;
			t_sample history_218_next_340 = fixdenorm(mix_341);
			t_sample history_216_next_338 = fixdenorm(mix_337);
			t_sample history_214_next_335 = fixdenorm(mix_333);
			t_sample mix_440 = (m_history_4 + (((t_sample)0.003926980723806) * (add_209 - m_history_4)));
			t_sample mix_349 = mix_440;
			t_sample mix_441 = (m_history_3 + (((t_sample)0.003926980723806) * (mix_349 - m_history_3)));
			t_sample mix_350 = mix_441;
			t_sample mix_442 = (m_history_2 + (((t_sample)0.003926980723806) * (mix_350 - m_history_2)));
			t_sample mix_346 = mix_442;
			t_sample gen_254 = mix_346;
			t_sample history_218_next_347 = fixdenorm(mix_349);
			t_sample history_216_next_354 = fixdenorm(mix_350);
			t_sample history_214_next_353 = fixdenorm(mix_346);
			t_sample mul_258 = (gen_254 * ((int)1));
			__m_cycle_23.freq(mul_258);
			t_sample cycle_296 = __m_cycle_23(__sinedata);
			t_sample cycleindex_297 = __m_cycle_23.phase();
			t_sample mul_294 = (cycle_296 * gen_317);
			t_sample add_295 = (mul_294 + mul_212);
			t_sample mul_289 = (gen_254 * ((t_sample)1.51));
			__m_cycle_24.freq(mul_289);
			t_sample cycle_292 = __m_cycle_24(__sinedata);
			t_sample cycleindex_293 = __m_cycle_24.phase();
			t_sample mul_290 = (cycle_292 * gen_317);
			t_sample add_291 = (mul_290 + mul_212);
			t_sample mul_257 = (gen_254 * ((t_sample)0.48));
			__m_cycle_25.freq(mul_257);
			t_sample cycle_286 = __m_cycle_25(__sinedata);
			t_sample cycleindex_287 = __m_cycle_25.phase();
			t_sample mul_284 = (cycle_286 * gen_317);
			t_sample add_285 = (mul_284 + mul_226);
			t_sample mul_279 = (gen_254 * ((t_sample)0.73));
			__m_cycle_26.freq(mul_279);
			t_sample cycle_282 = __m_cycle_26(__sinedata);
			t_sample cycleindex_283 = __m_cycle_26.phase();
			t_sample mul_280 = (cycle_282 * gen_317);
			t_sample add_281 = (mul_280 + mul_226);
			t_sample mul_256 = (gen_254 * ((t_sample)1.245));
			__m_cycle_27.freq(mul_256);
			t_sample cycle_275 = __m_cycle_27(__sinedata);
			t_sample cycleindex_276 = __m_cycle_27.phase();
			t_sample mul_273 = (cycle_275 * gen_317);
			t_sample add_274 = (mul_273 + mul_225);
			t_sample mul_268 = (gen_254 * ((t_sample)0.81));
			__m_cycle_28.freq(mul_268);
			t_sample cycle_271 = __m_cycle_28(__sinedata);
			t_sample cycleindex_272 = __m_cycle_28.phase();
			t_sample mul_269 = (cycle_271 * gen_317);
			t_sample add_270 = (mul_269 + mul_225);
			t_sample mul_255 = (gen_254 * ((t_sample)1.93));
			__m_cycle_29.freq(mul_255);
			t_sample cycle_266 = __m_cycle_29(__sinedata);
			t_sample cycleindex_267 = __m_cycle_29.phase();
			t_sample mul_264 = (cycle_266 * gen_317);
			t_sample add_265 = (mul_264 + mul_224);
			t_sample mul_259 = (gen_254 * ((t_sample)2.11));
			__m_cycle_30.freq(mul_259);
			t_sample cycle_262 = __m_cycle_30(__sinedata);
			t_sample cycleindex_263 = __m_cycle_30.phase();
			t_sample mul_260 = (cycle_262 * gen_317);
			t_sample add_261 = (mul_260 + mul_224);
			t_sample tap_299 = m_delay_1.read_linear(add_295);
			t_sample tap_300 = m_delay_1.read_linear(add_291);
			t_sample tap_301 = m_delay_1.read_linear(add_285);
			t_sample tap_302 = m_delay_1.read_linear(add_281);
			t_sample tap_303 = m_delay_1.read_linear(add_274);
			t_sample tap_304 = m_delay_1.read_linear(add_270);
			t_sample tap_305 = m_delay_1.read_linear(add_265);
			t_sample tap_306 = m_delay_1.read_linear(add_261);
			t_sample mul_242 = (tap_303 * clamp_229);
			t_sample mul_239 = (tap_306 * clamp_227);
			t_sample mul_235 = (tap_302 * clamp_231);
			t_sample mul_238 = (tap_299 * ((int)1));
			t_sample mul_278 = ((((mul_238 + mul_235) + mul_239) + mul_242) * scale_418);
			t_sample add_316 = (switch_245 + mul_278);
			t_sample mul_205 = (add_202 * add_316);
			t_sample out1 = (gate_307 + mul_205);
			t_sample mul_241 = (tap_304 * clamp_229);
			t_sample mul_240 = (tap_305 * clamp_227);
			t_sample mul_236 = (tap_301 * clamp_231);
			t_sample mul_237 = (tap_300 * ((int)1));
			t_sample mul_277 = ((((mul_237 + mul_236) + mul_240) + mul_241) * scale_418);
			t_sample add_288 = (switch_245 + mul_277);
			t_sample mul_204 = (add_202 * add_288);
			t_sample out2 = (gate_307 + mul_204);
			m_history_14 = history_311_next_313;
			m_history_13 = history_218_next_220;
			m_history_11 = history_214_next_222;
			m_history_12 = history_216_next_221;
			m_history_10 = history_218_next_328;
			m_history_8 = history_214_next_322;
			m_history_9 = history_216_next_325;
			m_history_7 = history_218_next_340;
			m_history_5 = history_214_next_335;
			m_history_6 = history_216_next_338;
			m_history_4 = history_218_next_347;
			m_history_2 = history_214_next_353;
			m_history_3 = history_216_next_354;
			m_delay_1.write(gate_308);
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
	inline void set_knob5_breadth(t_param _value) {
		m_knob5_breadth_16 = (_value < 240 ? 240 : (_value > 2400 ? 2400 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_taps(t_param _value) {
		m_knob6_taps_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_depth_17; break;
		case 1: *value = self->m_knob4_rate_19; break;
		case 2: *value = self->m_knob5_breadth_16; break;
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
	// initialize parameter 0 ("m_knob3_depth_17")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_17;
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
	// initialize parameter 2 ("m_knob5_breadth_16")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_breadth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_breadth_16;
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
