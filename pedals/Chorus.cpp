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
	t_sample m_history_20;
	t_sample m_knob3_depth_18;
	t_sample m_history_13;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_knob6_taps_19;
	t_sample m_history_8;
	t_sample m_sw_16;
	t_sample m_knob4_rate_15;
	t_sample m_knob5_breadth_17;
	t_sample m_sw_14;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)10000));
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
		m_sw_14 = ((int)0);
		m_knob4_rate_15 = ((int)0);
		m_sw_16 = ((int)0);
		m_knob5_breadth_17 = 127;
		m_knob3_depth_18 = ((int)0);
		m_knob6_taps_19 = ((int)0);
		m_history_20 = ((int)0);
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
		t_sample sub_395 = (m_knob6_taps_19 - ((int)0));
		t_sample scale_392 = ((safepow((sub_395 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.5)) + ((int)1));
		t_sample rsub_111 = (((int)1) - m_knob3_depth_18);
		t_sample sqrt_110 = sqrt(rsub_111);
		t_sample sqrt_109 = sqrt(sqrt_110);
		t_sample rsub_108 = (((int)1) - sqrt_109);
		t_sample mul_113 = (rsub_108 * ((int)500));
		t_sample add_112 = (mul_113 + ((int)2));
		t_sample rsub_105 = (((int)1) - m_knob4_rate_15);
		t_sample sqrt_104 = sqrt(rsub_105);
		t_sample sqrt_103 = sqrt(sqrt_104);
		t_sample rsub_102 = (((int)1) - sqrt_103);
		t_sample mul_106 = (rsub_102 * ((int)10));
		t_sample add_107 = (mul_106 + ((t_sample)0.01));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_229 = __m_sah_21(m_history_20, m_sw_16, ((int)0));
			t_sample gen_231 = sah_229;
			t_sample rsub_227 = (((int)1) - sah_229);
			t_sample history_228_next_230 = fixdenorm(rsub_227);
			t_sample out3 = gen_231;
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample add_232 = (gen_231 + ((int)1));
			t_sample choice_22 = int(add_232);
			t_sample gate_224 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_225 = ((choice_22 >= 2) ? in1 : 0);
			t_sample switch_149 = (m_sw_14 ? ((int)0) : gate_225);
			t_sample mix_396 = (m_history_13 + (((t_sample)0.003926980723806) * (m_knob6_taps_19 - m_history_13)));
			t_sample mix_119 = mix_396;
			t_sample mix_397 = (m_history_12 + (((t_sample)0.003926980723806) * (mix_119 - m_history_12)));
			t_sample mix_117 = mix_397;
			t_sample mix_398 = (m_history_11 + (((t_sample)0.003926980723806) * (mix_117 - m_history_11)));
			t_sample mix_115 = mix_398;
			t_sample gen_147 = mix_115;
			t_sample history_121_next_124 = fixdenorm(mix_119);
			t_sample history_118_next_125 = fixdenorm(mix_117);
			t_sample history_116_next_126 = fixdenorm(mix_115);
			t_sample sub_402 = (gen_147 - ((int)0));
			t_sample scale_399 = ((safepow((sub_402 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-2));
			t_sample clamp_133 = ((scale_399 <= ((int)0)) ? ((int)0) : ((scale_399 >= ((int)1)) ? ((int)1) : scale_399));
			t_sample sub_406 = (gen_147 - ((int)0));
			t_sample scale_403 = ((safepow((sub_406 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-3));
			t_sample clamp_131 = ((scale_403 <= ((int)0)) ? ((int)0) : ((scale_403 >= ((int)1)) ? ((int)1) : scale_403));
			t_sample sub_410 = (gen_147 - ((int)0));
			t_sample scale_407 = ((safepow((sub_410 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-1));
			t_sample clamp_135 = ((scale_407 <= ((int)0)) ? ((int)0) : ((scale_407 >= ((int)1)) ? ((int)1) : scale_407));
			t_sample mix_411 = (m_history_10 + (((t_sample)0.003926980723806) * (m_knob5_breadth_17 - m_history_10)));
			t_sample mix_238 = mix_411;
			t_sample mix_412 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_238 - m_history_9)));
			t_sample mix_239 = mix_412;
			t_sample mix_413 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_239 - m_history_8)));
			t_sample mix_246 = mix_413;
			t_sample gen_127 = mix_246;
			t_sample history_121_next_240 = fixdenorm(mix_238);
			t_sample history_118_next_237 = fixdenorm(mix_239);
			t_sample history_116_next_245 = fixdenorm(mix_246);
			t_sample mul_114 = (gen_127 * ((int)1));
			t_sample pass_206 = mul_114;
			t_sample mul_130 = (gen_127 * ((int)2));
			t_sample pass_195 = mul_130;
			t_sample mul_129 = (gen_127 * ((int)3));
			t_sample pass_183 = mul_129;
			t_sample mul_128 = (gen_127 * ((int)4));
			t_sample pass_173 = mul_128;
			t_sample mix_414 = (m_history_7 + (((t_sample)0.003926980723806) * (add_112 - m_history_7)));
			t_sample mix_251 = mix_414;
			t_sample mix_415 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_251 - m_history_6)));
			t_sample mix_252 = mix_415;
			t_sample mix_416 = (m_history_5 + (((t_sample)0.003926980723806) * (mix_252 - m_history_5)));
			t_sample mix_255 = mix_416;
			t_sample gen_234 = mix_255;
			t_sample history_121_next_257 = fixdenorm(mix_251);
			t_sample history_118_next_256 = fixdenorm(mix_252);
			t_sample history_116_next_254 = fixdenorm(mix_255);
			t_sample mix_417 = (m_history_4 + (((t_sample)0.003926980723806) * (add_107 - m_history_4)));
			t_sample mix_266 = mix_417;
			t_sample mix_418 = (m_history_3 + (((t_sample)0.003926980723806) * (mix_266 - m_history_3)));
			t_sample mix_267 = mix_418;
			t_sample mix_419 = (m_history_2 + (((t_sample)0.003926980723806) * (mix_267 - m_history_2)));
			t_sample mix_270 = mix_419;
			t_sample gen_167 = mix_270;
			t_sample history_121_next_272 = fixdenorm(mix_266);
			t_sample history_118_next_271 = fixdenorm(mix_267);
			t_sample history_116_next_269 = fixdenorm(mix_270);
			t_sample mul_171 = (gen_167 * ((int)1));
			__m_cycle_23.freq(mul_171);
			t_sample cycle_213 = __m_cycle_23(__sinedata);
			t_sample cycleindex_214 = __m_cycle_23.phase();
			t_sample mul_211 = (cycle_213 * gen_234);
			t_sample add_212 = (mul_211 + pass_206);
			t_sample mul_205 = (gen_167 * ((t_sample)1.5));
			__m_cycle_24.freq(mul_205);
			t_sample cycle_209 = __m_cycle_24(__sinedata);
			t_sample cycleindex_210 = __m_cycle_24.phase();
			t_sample mul_207 = (cycle_209 * gen_234);
			t_sample add_208 = (mul_207 + pass_206);
			t_sample mul_170 = (gen_167 * ((t_sample)0.5));
			__m_cycle_25.freq(mul_170);
			t_sample cycle_202 = __m_cycle_25(__sinedata);
			t_sample cycleindex_203 = __m_cycle_25.phase();
			t_sample mul_200 = (cycle_202 * gen_234);
			t_sample add_201 = (mul_200 + pass_195);
			t_sample mul_194 = (gen_167 * ((int)1));
			__m_cycle_26.freq(mul_194);
			t_sample cycle_198 = __m_cycle_26(__sinedata);
			t_sample cycleindex_199 = __m_cycle_26.phase();
			t_sample mul_196 = (cycle_198 * gen_234);
			t_sample add_197 = (mul_196 + pass_195);
			t_sample mul_169 = (gen_167 * ((t_sample)1.25));
			__m_cycle_27.freq(mul_169);
			t_sample cycle_190 = __m_cycle_27(__sinedata);
			t_sample cycleindex_191 = __m_cycle_27.phase();
			t_sample mul_188 = (cycle_190 * gen_234);
			t_sample add_189 = (mul_188 + pass_183);
			t_sample mul_182 = (gen_167 * ((t_sample)0.8));
			__m_cycle_28.freq(mul_182);
			t_sample cycle_186 = __m_cycle_28(__sinedata);
			t_sample cycleindex_187 = __m_cycle_28.phase();
			t_sample mul_184 = (cycle_186 * gen_234);
			t_sample add_185 = (mul_184 + pass_183);
			t_sample mul_168 = (gen_167 * ((t_sample)1.95));
			__m_cycle_29.freq(mul_168);
			t_sample cycle_180 = __m_cycle_29(__sinedata);
			t_sample cycleindex_181 = __m_cycle_29.phase();
			t_sample mul_178 = (cycle_180 * gen_234);
			t_sample add_179 = (mul_178 + pass_173);
			t_sample mul_172 = (gen_167 * ((int)0));
			__m_cycle_30.freq(mul_172);
			t_sample cycle_176 = __m_cycle_30(__sinedata);
			t_sample cycleindex_177 = __m_cycle_30.phase();
			t_sample mul_174 = (cycle_176 * gen_234);
			t_sample add_175 = (mul_174 + pass_173);
			t_sample tap_216 = m_delay_1.read_linear(add_212);
			t_sample tap_217 = m_delay_1.read_linear(add_208);
			t_sample tap_218 = m_delay_1.read_linear(add_201);
			t_sample tap_219 = m_delay_1.read_linear(add_197);
			t_sample tap_220 = m_delay_1.read_linear(add_189);
			t_sample tap_221 = m_delay_1.read_linear(add_185);
			t_sample tap_222 = m_delay_1.read_linear(add_179);
			t_sample tap_223 = m_delay_1.read_linear(add_175);
			t_sample mul_146 = (tap_220 * clamp_133);
			t_sample mul_143 = (tap_223 * clamp_131);
			t_sample mul_139 = (tap_219 * clamp_135);
			t_sample mul_142 = (tap_216 * ((int)1));
			t_sample mul_193 = ((((mul_142 + mul_139) + mul_143) + mul_146) * scale_392);
			t_sample add_233 = (switch_149 + mul_193);
			t_sample out1 = (gate_224 + add_233);
			t_sample mul_145 = (tap_221 * clamp_133);
			t_sample mul_144 = (tap_222 * clamp_131);
			t_sample mul_140 = (tap_218 * clamp_135);
			t_sample mul_141 = (tap_217 * ((int)1));
			t_sample mul_192 = ((((mul_141 + mul_140) + mul_144) + mul_145) * scale_392);
			t_sample add_204 = (switch_149 + mul_192);
			t_sample out2 = (add_204 + gate_224);
			m_history_20 = history_228_next_230;
			m_history_13 = history_121_next_124;
			m_history_11 = history_116_next_126;
			m_history_12 = history_118_next_125;
			m_history_10 = history_121_next_240;
			m_history_8 = history_116_next_245;
			m_history_9 = history_118_next_237;
			m_history_7 = history_121_next_257;
			m_history_5 = history_116_next_254;
			m_history_6 = history_118_next_256;
			m_history_4 = history_121_next_272;
			m_history_2 = history_116_next_269;
			m_history_3 = history_118_next_271;
			m_delay_1.write(gate_225);
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
		m_sw_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_breadth(t_param _value) {
		m_knob5_breadth_17 = (_value < 120 ? 120 : (_value > 1200 ? 1200 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_taps(t_param _value) {
		m_knob6_taps_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_depth_18; break;
		case 1: *value = self->m_knob4_rate_15; break;
		case 2: *value = self->m_knob5_breadth_17; break;
		case 3: *value = self->m_knob6_taps_19; break;
		case 4: *value = self->m_sw_16; break;
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
	// initialize parameter 0 ("m_knob3_depth_18")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_15")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_breadth_17")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_breadth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_breadth_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 120;
	pi->outputmax = 1200;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_taps_19")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_taps";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_taps_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_16")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_16;
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


} // Chorus::
