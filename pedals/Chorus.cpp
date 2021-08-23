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
	t_sample m_sw_18;
	t_sample m_history_13;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_knob4_rate_19;
	t_sample m_history_8;
	t_sample m_knob5_breadth_16;
	t_sample m_knob6_taps_15;
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
		m_knob6_taps_15 = ((int)0);
		m_knob5_breadth_16 = 256;
		m_knob3_depth_17 = ((int)0);
		m_sw_18 = ((int)0);
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
		t_sample expr_277 = (((int)1) - sqrt(sqrt((((int)1) - m_knob3_depth_17))));
		t_sample expr_276 = (((int)1) - sqrt(sqrt((((int)1) - m_knob4_rate_19))));
		t_sample div_161 = (m_sw_20 * ((t_sample)0.5));
		t_sample add_160 = (div_161 + ((t_sample)0.5));
		t_sample mul_169 = (expr_277 * ((int)1000));
		t_sample add_168 = (mul_169 + ((int)2));
		t_sample mul_166 = (expr_276 * ((int)10));
		t_sample add_167 = (mul_166 + ((t_sample)0.01));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_270 = __m_sah_21(m_history_14, m_sw_18, ((int)0));
			t_sample gen_272 = sah_270;
			t_sample rsub_268 = (((int)1) - sah_270);
			t_sample history_269_next_271 = fixdenorm(rsub_268);
			t_sample out3 = gen_272;
			t_sample add_273 = (gen_272 + ((int)1));
			t_sample choice_22 = int(add_273);
			t_sample gate_265 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_266 = ((choice_22 >= 2) ? in1 : 0);
			t_sample switch_203 = (m_sw_20 ? ((int)0) : gate_266);
			t_sample mix_373 = (m_history_13 + (((t_sample)0.0019634941468452) * (m_knob6_taps_15 - m_history_13)));
			t_sample mix_175 = mix_373;
			t_sample mix_374 = (m_history_12 + (((t_sample)0.0019634941468452) * (mix_175 - m_history_12)));
			t_sample mix_173 = mix_374;
			t_sample mix_375 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_173 - m_history_11)));
			t_sample mix_171 = mix_375;
			t_sample gen_201 = mix_171;
			t_sample history_176_next_178 = fixdenorm(mix_175);
			t_sample history_174_next_179 = fixdenorm(mix_173);
			t_sample history_172_next_180 = fixdenorm(mix_171);
			t_sample sub_379 = (gen_201 - ((int)0));
			t_sample scale_376 = ((safepow((sub_379 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.5)) + ((int)1));
			t_sample sub_383 = (gen_201 - ((int)0));
			t_sample scale_380 = ((safepow((sub_383 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-2));
			t_sample clamp_187 = ((scale_380 <= ((int)0)) ? ((int)0) : ((scale_380 >= ((int)1)) ? ((int)1) : scale_380));
			t_sample sub_387 = (gen_201 - ((int)0));
			t_sample scale_384 = ((safepow((sub_387 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-3));
			t_sample clamp_185 = ((scale_384 <= ((int)0)) ? ((int)0) : ((scale_384 >= ((int)1)) ? ((int)1) : scale_384));
			t_sample sub_391 = (gen_201 - ((int)0));
			t_sample scale_388 = ((safepow((sub_391 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-1));
			t_sample clamp_189 = ((scale_388 <= ((int)0)) ? ((int)0) : ((scale_388 >= ((int)1)) ? ((int)1) : scale_388));
			t_sample mix_392 = (m_history_10 + (((t_sample)0.0019634941468452) * (m_knob5_breadth_16 - m_history_10)));
			t_sample mix_282 = mix_392;
			t_sample mix_393 = (m_history_9 + (((t_sample)0.0019634941468452) * (mix_282 - m_history_9)));
			t_sample mix_287 = mix_393;
			t_sample mix_394 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_287 - m_history_8)));
			t_sample mix_286 = mix_394;
			t_sample gen_181 = mix_286;
			t_sample history_176_next_283 = fixdenorm(mix_282);
			t_sample history_174_next_279 = fixdenorm(mix_287);
			t_sample history_172_next_285 = fixdenorm(mix_286);
			t_sample mul_170 = (gen_181 * ((int)1));
			t_sample mul_184 = (gen_181 * ((int)2));
			t_sample mul_183 = (gen_181 * ((int)3));
			t_sample mul_182 = (gen_181 * ((int)4));
			t_sample mix_395 = (m_history_7 + (((t_sample)0.0019634941468452) * (add_168 - m_history_7)));
			t_sample mix_295 = mix_395;
			t_sample mix_396 = (m_history_6 + (((t_sample)0.0019634941468452) * (mix_295 - m_history_6)));
			t_sample mix_300 = mix_396;
			t_sample mix_397 = (m_history_5 + (((t_sample)0.0019634941468452) * (mix_300 - m_history_5)));
			t_sample mix_299 = mix_397;
			t_sample gen_275 = mix_299;
			t_sample history_176_next_296 = fixdenorm(mix_295);
			t_sample history_174_next_292 = fixdenorm(mix_300);
			t_sample history_172_next_298 = fixdenorm(mix_299);
			t_sample mix_398 = (m_history_4 + (((t_sample)0.0019634941468452) * (add_167 - m_history_4)));
			t_sample mix_306 = mix_398;
			t_sample mix_399 = (m_history_3 + (((t_sample)0.0019634941468452) * (mix_306 - m_history_3)));
			t_sample mix_310 = mix_399;
			t_sample mix_400 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_310 - m_history_2)));
			t_sample mix_307 = mix_400;
			t_sample gen_212 = mix_307;
			t_sample history_176_next_308 = fixdenorm(mix_306);
			t_sample history_174_next_312 = fixdenorm(mix_310);
			t_sample history_172_next_305 = fixdenorm(mix_307);
			t_sample mul_216 = (gen_212 * ((int)1));
			__m_cycle_23.freq(mul_216);
			t_sample cycle_254 = __m_cycle_23(__sinedata);
			t_sample cycleindex_255 = __m_cycle_23.phase();
			t_sample mul_252 = (cycle_254 * gen_275);
			t_sample add_253 = (mul_252 + mul_170);
			t_sample mul_247 = (gen_212 * ((t_sample)1.51));
			__m_cycle_24.freq(mul_247);
			t_sample cycle_250 = __m_cycle_24(__sinedata);
			t_sample cycleindex_251 = __m_cycle_24.phase();
			t_sample mul_248 = (cycle_250 * gen_275);
			t_sample add_249 = (mul_248 + mul_170);
			t_sample mul_215 = (gen_212 * ((t_sample)0.48));
			__m_cycle_25.freq(mul_215);
			t_sample cycle_244 = __m_cycle_25(__sinedata);
			t_sample cycleindex_245 = __m_cycle_25.phase();
			t_sample mul_242 = (cycle_244 * gen_275);
			t_sample add_243 = (mul_242 + mul_184);
			t_sample mul_237 = (gen_212 * ((t_sample)0.73));
			__m_cycle_26.freq(mul_237);
			t_sample cycle_240 = __m_cycle_26(__sinedata);
			t_sample cycleindex_241 = __m_cycle_26.phase();
			t_sample mul_238 = (cycle_240 * gen_275);
			t_sample add_239 = (mul_238 + mul_184);
			t_sample mul_214 = (gen_212 * ((t_sample)1.245));
			__m_cycle_27.freq(mul_214);
			t_sample cycle_233 = __m_cycle_27(__sinedata);
			t_sample cycleindex_234 = __m_cycle_27.phase();
			t_sample mul_231 = (cycle_233 * gen_275);
			t_sample add_232 = (mul_231 + mul_183);
			t_sample mul_226 = (gen_212 * ((t_sample)0.81));
			__m_cycle_28.freq(mul_226);
			t_sample cycle_229 = __m_cycle_28(__sinedata);
			t_sample cycleindex_230 = __m_cycle_28.phase();
			t_sample mul_227 = (cycle_229 * gen_275);
			t_sample add_228 = (mul_227 + mul_183);
			t_sample mul_213 = (gen_212 * ((t_sample)1.93));
			__m_cycle_29.freq(mul_213);
			t_sample cycle_224 = __m_cycle_29(__sinedata);
			t_sample cycleindex_225 = __m_cycle_29.phase();
			t_sample mul_222 = (cycle_224 * gen_275);
			t_sample add_223 = (mul_222 + mul_182);
			t_sample mul_217 = (gen_212 * ((t_sample)2.11));
			__m_cycle_30.freq(mul_217);
			t_sample cycle_220 = __m_cycle_30(__sinedata);
			t_sample cycleindex_221 = __m_cycle_30.phase();
			t_sample mul_218 = (cycle_220 * gen_275);
			t_sample add_219 = (mul_218 + mul_182);
			t_sample tap_257 = m_delay_1.read_linear(add_253);
			t_sample tap_258 = m_delay_1.read_linear(add_249);
			t_sample tap_259 = m_delay_1.read_linear(add_243);
			t_sample tap_260 = m_delay_1.read_linear(add_239);
			t_sample tap_261 = m_delay_1.read_linear(add_232);
			t_sample tap_262 = m_delay_1.read_linear(add_228);
			t_sample tap_263 = m_delay_1.read_linear(add_223);
			t_sample tap_264 = m_delay_1.read_linear(add_219);
			t_sample mul_200 = (tap_261 * clamp_187);
			t_sample mul_197 = (tap_264 * clamp_185);
			t_sample mul_193 = (tap_260 * clamp_189);
			t_sample mul_196 = (tap_257 * ((int)1));
			t_sample mul_236 = ((((mul_196 + mul_193) + mul_197) + mul_200) * scale_376);
			t_sample add_274 = (switch_203 + mul_236);
			t_sample mul_163 = (add_160 * add_274);
			t_sample out1 = (gate_265 + mul_163);
			t_sample mul_199 = (tap_262 * clamp_187);
			t_sample mul_198 = (tap_263 * clamp_185);
			t_sample mul_194 = (tap_259 * clamp_189);
			t_sample mul_195 = (tap_258 * ((int)1));
			t_sample mul_235 = ((((mul_195 + mul_194) + mul_198) + mul_199) * scale_376);
			t_sample add_246 = (switch_203 + mul_235);
			t_sample mul_162 = (add_160 * add_246);
			t_sample out2 = (gate_265 + mul_162);
			m_history_14 = history_269_next_271;
			m_history_13 = history_176_next_178;
			m_history_11 = history_172_next_180;
			m_history_12 = history_174_next_179;
			m_history_10 = history_176_next_283;
			m_history_8 = history_172_next_285;
			m_history_9 = history_174_next_279;
			m_history_7 = history_176_next_296;
			m_history_5 = history_172_next_298;
			m_history_6 = history_174_next_292;
			m_history_4 = history_176_next_308;
			m_history_2 = history_172_next_305;
			m_history_3 = history_174_next_312;
			m_delay_1.write(gate_266);
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
	inline void set_knob5_breadth(t_param _value) {
		m_knob5_breadth_16 = (_value < 240 ? 240 : (_value > 2400 ? 2400 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_depth_17; break;
		case 1: *value = self->m_knob4_rate_19; break;
		case 2: *value = self->m_knob5_breadth_16; break;
		case 3: *value = self->m_knob6_taps_15; break;
		case 4: *value = self->m_sw_18; break;
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
	// initialize parameter 4 ("m_sw_18")
	pi = self->__commonstate.params + 4;
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
