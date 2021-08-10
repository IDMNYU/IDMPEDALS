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
	t_sample m_knob5_breadth_20;
	t_sample m_sw_18;
	t_sample m_history_13;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_knob4_rate_19;
	t_sample m_history_8;
	t_sample m_knob3_depth_16;
	t_sample m_sw_15;
	t_sample m_knob6_taps_17;
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
		m_knob6_taps_17 = ((int)0);
		m_sw_18 = ((int)0);
		m_knob4_rate_19 = ((int)0);
		m_knob5_breadth_20 = 256;
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
		t_sample expr_269 = (((int)1) - sqrt(sqrt((((int)1) - m_knob3_depth_16))));
		t_sample expr_268 = (((int)1) - sqrt(sqrt((((int)1) - m_knob4_rate_19))));
		t_sample div_151 = (m_sw_15 * ((t_sample)0.5));
		t_sample add_150 = (div_151 + ((t_sample)0.5));
		t_sample mul_159 = (expr_269 * ((int)1000));
		t_sample add_158 = (mul_159 + ((int)2));
		t_sample mul_156 = (expr_268 * ((int)10));
		t_sample add_157 = (mul_156 + ((t_sample)0.01));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_262 = __m_sah_21(m_history_14, m_sw_18, ((int)0));
			t_sample gen_264 = sah_262;
			t_sample rsub_260 = (((int)1) - sah_262);
			t_sample history_261_next_263 = fixdenorm(rsub_260);
			t_sample out3 = gen_264;
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample add_265 = (gen_264 + ((int)1));
			t_sample choice_22 = int(add_265);
			t_sample gate_257 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_258 = ((choice_22 >= 2) ? in1 : 0);
			t_sample switch_195 = (m_sw_15 ? ((int)0) : gate_258);
			t_sample mix_399 = (m_history_13 + (((t_sample)0.0019634941468452) * (m_knob6_taps_17 - m_history_13)));
			t_sample mix_165 = mix_399;
			t_sample mix_400 = (m_history_12 + (((t_sample)0.0019634941468452) * (mix_165 - m_history_12)));
			t_sample mix_163 = mix_400;
			t_sample mix_401 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_163 - m_history_11)));
			t_sample mix_161 = mix_401;
			t_sample gen_193 = mix_161;
			t_sample history_167_next_170 = fixdenorm(mix_165);
			t_sample history_164_next_171 = fixdenorm(mix_163);
			t_sample history_162_next_172 = fixdenorm(mix_161);
			t_sample sub_405 = (gen_193 - ((int)0));
			t_sample scale_402 = ((safepow((sub_405 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.5)) + ((int)1));
			t_sample sub_409 = (gen_193 - ((int)0));
			t_sample scale_406 = ((safepow((sub_409 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-2));
			t_sample clamp_179 = ((scale_406 <= ((int)0)) ? ((int)0) : ((scale_406 >= ((int)1)) ? ((int)1) : scale_406));
			t_sample sub_413 = (gen_193 - ((int)0));
			t_sample scale_410 = ((safepow((sub_413 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-3));
			t_sample clamp_177 = ((scale_410 <= ((int)0)) ? ((int)0) : ((scale_410 >= ((int)1)) ? ((int)1) : scale_410));
			t_sample sub_417 = (gen_193 - ((int)0));
			t_sample scale_414 = ((safepow((sub_417 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-1));
			t_sample clamp_181 = ((scale_414 <= ((int)0)) ? ((int)0) : ((scale_414 >= ((int)1)) ? ((int)1) : scale_414));
			t_sample mix_418 = (m_history_10 + (((t_sample)0.0019634941468452) * (m_knob5_breadth_20 - m_history_10)));
			t_sample mix_271 = mix_418;
			t_sample mix_419 = (m_history_9 + (((t_sample)0.0019634941468452) * (mix_271 - m_history_9)));
			t_sample mix_274 = mix_419;
			t_sample mix_420 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_274 - m_history_8)));
			t_sample mix_272 = mix_420;
			t_sample gen_173 = mix_272;
			t_sample history_167_next_279 = fixdenorm(mix_271);
			t_sample history_164_next_278 = fixdenorm(mix_274);
			t_sample history_162_next_276 = fixdenorm(mix_272);
			t_sample mul_160 = (gen_173 * ((int)1));
			t_sample mul_176 = (gen_173 * ((int)2));
			t_sample mul_175 = (gen_173 * ((int)3));
			t_sample mul_174 = (gen_173 * ((int)4));
			t_sample mix_421 = (m_history_7 + (((t_sample)0.0019634941468452) * (add_158 - m_history_7)));
			t_sample mix_286 = mix_421;
			t_sample mix_422 = (m_history_6 + (((t_sample)0.0019634941468452) * (mix_286 - m_history_6)));
			t_sample mix_289 = mix_422;
			t_sample mix_423 = (m_history_5 + (((t_sample)0.0019634941468452) * (mix_289 - m_history_5)));
			t_sample mix_287 = mix_423;
			t_sample gen_267 = mix_287;
			t_sample history_167_next_294 = fixdenorm(mix_286);
			t_sample history_164_next_293 = fixdenorm(mix_289);
			t_sample history_162_next_292 = fixdenorm(mix_287);
			t_sample mix_424 = (m_history_4 + (((t_sample)0.0019634941468452) * (add_157 - m_history_4)));
			t_sample mix_304 = mix_424;
			t_sample mix_425 = (m_history_3 + (((t_sample)0.0019634941468452) * (mix_304 - m_history_3)));
			t_sample mix_305 = mix_425;
			t_sample mix_426 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_305 - m_history_2)));
			t_sample mix_301 = mix_426;
			t_sample gen_204 = mix_301;
			t_sample history_167_next_310 = fixdenorm(mix_304);
			t_sample history_164_next_307 = fixdenorm(mix_305);
			t_sample history_162_next_303 = fixdenorm(mix_301);
			t_sample mul_208 = (gen_204 * ((int)1));
			__m_cycle_23.freq(mul_208);
			t_sample cycle_246 = __m_cycle_23(__sinedata);
			t_sample cycleindex_247 = __m_cycle_23.phase();
			t_sample mul_244 = (cycle_246 * gen_267);
			t_sample add_245 = (mul_244 + mul_160);
			t_sample mul_239 = (gen_204 * ((t_sample)1.51));
			__m_cycle_24.freq(mul_239);
			t_sample cycle_242 = __m_cycle_24(__sinedata);
			t_sample cycleindex_243 = __m_cycle_24.phase();
			t_sample mul_240 = (cycle_242 * gen_267);
			t_sample add_241 = (mul_240 + mul_160);
			t_sample mul_207 = (gen_204 * ((t_sample)0.48));
			__m_cycle_25.freq(mul_207);
			t_sample cycle_236 = __m_cycle_25(__sinedata);
			t_sample cycleindex_237 = __m_cycle_25.phase();
			t_sample mul_234 = (cycle_236 * gen_267);
			t_sample add_235 = (mul_234 + mul_176);
			t_sample mul_229 = (gen_204 * ((t_sample)0.73));
			__m_cycle_26.freq(mul_229);
			t_sample cycle_232 = __m_cycle_26(__sinedata);
			t_sample cycleindex_233 = __m_cycle_26.phase();
			t_sample mul_230 = (cycle_232 * gen_267);
			t_sample add_231 = (mul_230 + mul_176);
			t_sample mul_206 = (gen_204 * ((t_sample)1.245));
			__m_cycle_27.freq(mul_206);
			t_sample cycle_225 = __m_cycle_27(__sinedata);
			t_sample cycleindex_226 = __m_cycle_27.phase();
			t_sample mul_223 = (cycle_225 * gen_267);
			t_sample add_224 = (mul_223 + mul_175);
			t_sample mul_218 = (gen_204 * ((t_sample)0.81));
			__m_cycle_28.freq(mul_218);
			t_sample cycle_221 = __m_cycle_28(__sinedata);
			t_sample cycleindex_222 = __m_cycle_28.phase();
			t_sample mul_219 = (cycle_221 * gen_267);
			t_sample add_220 = (mul_219 + mul_175);
			t_sample mul_205 = (gen_204 * ((t_sample)1.93));
			__m_cycle_29.freq(mul_205);
			t_sample cycle_216 = __m_cycle_29(__sinedata);
			t_sample cycleindex_217 = __m_cycle_29.phase();
			t_sample mul_214 = (cycle_216 * gen_267);
			t_sample add_215 = (mul_214 + mul_174);
			t_sample mul_209 = (gen_204 * ((t_sample)2.11));
			__m_cycle_30.freq(mul_209);
			t_sample cycle_212 = __m_cycle_30(__sinedata);
			t_sample cycleindex_213 = __m_cycle_30.phase();
			t_sample mul_210 = (cycle_212 * gen_267);
			t_sample add_211 = (mul_210 + mul_174);
			t_sample tap_249 = m_delay_1.read_linear(add_245);
			t_sample tap_250 = m_delay_1.read_linear(add_241);
			t_sample tap_251 = m_delay_1.read_linear(add_235);
			t_sample tap_252 = m_delay_1.read_linear(add_231);
			t_sample tap_253 = m_delay_1.read_linear(add_224);
			t_sample tap_254 = m_delay_1.read_linear(add_220);
			t_sample tap_255 = m_delay_1.read_linear(add_215);
			t_sample tap_256 = m_delay_1.read_linear(add_211);
			t_sample mul_192 = (tap_253 * clamp_179);
			t_sample mul_189 = (tap_256 * clamp_177);
			t_sample mul_185 = (tap_252 * clamp_181);
			t_sample mul_188 = (tap_249 * ((int)1));
			t_sample mul_228 = ((((mul_188 + mul_185) + mul_189) + mul_192) * scale_402);
			t_sample add_266 = (switch_195 + mul_228);
			t_sample mul_153 = (add_150 * add_266);
			t_sample out1 = (gate_257 + mul_153);
			t_sample mul_191 = (tap_254 * clamp_179);
			t_sample mul_190 = (tap_255 * clamp_177);
			t_sample mul_186 = (tap_251 * clamp_181);
			t_sample mul_187 = (tap_250 * ((int)1));
			t_sample mul_227 = ((((mul_187 + mul_186) + mul_190) + mul_191) * scale_402);
			t_sample add_238 = (switch_195 + mul_227);
			t_sample mul_152 = (add_150 * add_238);
			t_sample out2 = (gate_257 + mul_152);
			m_history_14 = history_261_next_263;
			m_history_13 = history_167_next_170;
			m_history_11 = history_162_next_172;
			m_history_12 = history_164_next_171;
			m_history_10 = history_167_next_279;
			m_history_8 = history_162_next_276;
			m_history_9 = history_164_next_278;
			m_history_7 = history_167_next_294;
			m_history_5 = history_162_next_292;
			m_history_6 = history_164_next_293;
			m_history_4 = history_167_next_310;
			m_history_2 = history_162_next_303;
			m_history_3 = history_164_next_307;
			m_delay_1.write(gate_258);
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
	inline void set_knob6_taps(t_param _value) {
		m_knob6_taps_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_breadth(t_param _value) {
		m_knob5_breadth_20 = (_value < 240 ? 240 : (_value > 2400 ? 2400 : _value));
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
		case 2: *value = self->m_knob5_breadth_20; break;
		case 3: *value = self->m_knob6_taps_17; break;
		case 4: *value = self->m_sw_18; break;
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
	// initialize parameter 2 ("m_knob5_breadth_20")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_breadth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_breadth_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 240;
	pi->outputmax = 2400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_taps_17")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_taps";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_taps_17;
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
