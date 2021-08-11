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
	t_sample m_knob3_damp_3;
	t_sample m_history_11;
	t_sample m_knob5_fb_2;
	t_sample m_sw_1;
	t_sample samplerate;
	t_sample m_knob1_wetdry_4;
	t_sample m_history_13;
	t_sample m_knob4_fb_5;
	t_sample m_knob6_spread_6;
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
		m_sw_1 = ((int)0);
		m_knob5_fb_2 = ((t_sample)0.5);
		m_knob3_damp_3 = ((t_sample)0.5);
		m_knob1_wetdry_4 = ((int)0);
		m_knob4_fb_5 = ((t_sample)0.9);
		m_knob6_spread_6 = ((int)0);
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
		t_sample sqrt_13023 = sqrt(m_knob1_wetdry_4);
		t_sample rsub_13027 = (((int)1) - m_knob1_wetdry_4);
		t_sample sqrt_13026 = sqrt(rsub_13027);
		t_sample mul_14118 = (m_knob5_fb_2 * ((t_sample)0.9));
		t_sample mul_14275 = (m_knob5_fb_2 * ((t_sample)0.9));
		t_sample add_13063 = (((int)450) + m_knob6_spread_6);
		t_sample add_13017 = (((int)456) + m_knob6_spread_6);
		t_sample add_13065 = (((int)682) + m_knob6_spread_6);
		t_sample add_13019 = (((int)676) + m_knob6_spread_6);
		t_sample add_13075 = (((int)882) + m_knob6_spread_6);
		t_sample add_13021 = (((int)888) + m_knob6_spread_6);
		t_sample add_13061 = (((int)1112) + m_knob6_spread_6);
		t_sample add_13015 = (((int)1106) + m_knob6_spread_6);
		t_sample add_13068 = (((int)3114) + m_knob6_spread_6);
		t_sample rsub_13030 = (((int)1) - m_knob3_damp_3);
		t_sample add_13067 = (((int)3234) + m_knob6_spread_6);
		t_sample rsub_14283 = (((int)1) - m_knob3_damp_3);
		t_sample add_13069 = (((int)2982) + m_knob6_spread_6);
		t_sample rsub_14296 = (((int)1) - m_knob3_damp_3);
		t_sample add_13070 = (((int)2844) + m_knob6_spread_6);
		t_sample rsub_14305 = (((int)1) - m_knob3_damp_3);
		t_sample add_13071 = (((int)2712) + m_knob6_spread_6);
		t_sample rsub_14317 = (((int)1) - m_knob3_damp_3);
		t_sample add_13072 = (((int)2554) + m_knob6_spread_6);
		t_sample rsub_14329 = (((int)1) - m_knob3_damp_3);
		t_sample add_13073 = (((int)2376) + m_knob6_spread_6);
		t_sample rsub_14340 = (((int)1) - m_knob3_damp_3);
		t_sample add_13074 = (((int)2232) + m_knob6_spread_6);
		t_sample rsub_14355 = (((int)1) - m_knob3_damp_3);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_13082 = __m_sah_32(m_history_7, m_sw_1, ((int)0));
			t_sample gen_13084 = sah_13082;
			t_sample rsub_13080 = (((int)1) - sah_13082);
			t_sample history_13081_next_13083 = fixdenorm(rsub_13080);
			t_sample out3 = gen_13084;
			t_sample add_13087 = (gen_13084 + ((int)1));
			t_sample choice_33 = int(add_13087);
			t_sample gate_13085 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_13086 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_13025 = (gate_13086 * sqrt_13026);
			t_sample mul_13079 = (gate_13086 * ((t_sample)0.015));
			t_sample tap_13037 = m_delay_8.read_linear(add_13068);
			t_sample gen_13059 = tap_13037;
			t_sample mul_13035 = (tap_13037 * m_knob3_damp_3);
			t_sample mul_13033 = (m_history_9 * rsub_13030);
			t_sample add_13034 = (mul_13035 + mul_13033);
			t_sample mul_13031 = (add_13034 * m_knob4_fb_5);
			t_sample add_13038 = (mul_13079 + mul_13031);
			t_sample history_13032_next_13039 = fixdenorm(add_13034);
			t_sample tap_14284 = m_delay_10.read_linear(add_13067);
			t_sample gen_13078 = tap_14284;
			t_sample mul_14285 = (tap_14284 * m_knob3_damp_3);
			t_sample mul_14282 = (m_history_11 * rsub_14283);
			t_sample add_14278 = (mul_14285 + mul_14282);
			t_sample mul_14281 = (add_14278 * m_knob4_fb_5);
			t_sample add_14280 = (mul_13079 + mul_14281);
			t_sample history_13032_next_14279 = fixdenorm(add_14278);
			t_sample tap_14291 = m_delay_12.read_linear(add_13069);
			t_sample gen_13058 = tap_14291;
			t_sample mul_14297 = (tap_14291 * m_knob3_damp_3);
			t_sample mul_14295 = (m_history_13 * rsub_14296);
			t_sample add_14290 = (mul_14297 + mul_14295);
			t_sample mul_14294 = (add_14290 * m_knob4_fb_5);
			t_sample add_14293 = (mul_13079 + mul_14294);
			t_sample history_13032_next_14292 = fixdenorm(add_14290);
			t_sample tap_14309 = m_delay_14.read_linear(add_13070);
			t_sample gen_13057 = tap_14309;
			t_sample mul_14303 = (tap_14309 * m_knob3_damp_3);
			t_sample mul_14307 = (m_history_15 * rsub_14305);
			t_sample add_14306 = (mul_14303 + mul_14307);
			t_sample mul_14308 = (add_14306 * m_knob4_fb_5);
			t_sample add_14304 = (mul_13079 + mul_14308);
			t_sample history_13032_next_14302 = fixdenorm(add_14306);
			t_sample tap_14321 = m_delay_16.read_linear(add_13071);
			t_sample gen_13056 = tap_14321;
			t_sample mul_14315 = (tap_14321 * m_knob3_damp_3);
			t_sample mul_14319 = (m_history_17 * rsub_14317);
			t_sample add_14318 = (mul_14315 + mul_14319);
			t_sample mul_14320 = (add_14318 * m_knob4_fb_5);
			t_sample add_14316 = (mul_13079 + mul_14320);
			t_sample history_13032_next_14314 = fixdenorm(add_14318);
			t_sample tap_14333 = m_delay_18.read_linear(add_13072);
			t_sample gen_13055 = tap_14333;
			t_sample mul_14327 = (tap_14333 * m_knob3_damp_3);
			t_sample mul_14331 = (m_history_19 * rsub_14329);
			t_sample add_14330 = (mul_14327 + mul_14331);
			t_sample mul_14332 = (add_14330 * m_knob4_fb_5);
			t_sample add_14328 = (mul_13079 + mul_14332);
			t_sample history_13032_next_14326 = fixdenorm(add_14330);
			t_sample tap_14345 = m_delay_20.read_linear(add_13073);
			t_sample gen_13054 = tap_14345;
			t_sample mul_14338 = (tap_14345 * m_knob3_damp_3);
			t_sample mul_14342 = (m_history_21 * rsub_14340);
			t_sample add_14341 = (mul_14338 + mul_14342);
			t_sample mul_14344 = (add_14341 * m_knob4_fb_5);
			t_sample add_14339 = (mul_13079 + mul_14344);
			t_sample history_13032_next_14343 = fixdenorm(add_14341);
			t_sample tap_14350 = m_delay_22.read_linear(add_13074);
			t_sample gen_13298 = tap_14350;
			t_sample mul_14354 = (tap_14350 * m_knob3_damp_3);
			t_sample mul_14356 = (m_history_23 * rsub_14355);
			t_sample add_14351 = (mul_14354 + mul_14356);
			t_sample mul_14348 = (add_14351 * m_knob4_fb_5);
			t_sample add_14357 = (mul_13079 + mul_14348);
			t_sample history_13032_next_14349 = fixdenorm(add_14351);
			t_sample pass_13076 = (((((((gen_13298 + gen_13054) + gen_13055) + gen_13056) + gen_13057) + gen_13058) + gen_13078) + gen_13059);
			t_sample tap_13013 = m_delay_24.read_linear(add_13061);
			t_sample sub_13009 = (pass_13076 - tap_13013);
			t_sample mul_13011 = (tap_13013 * mul_14118);
			t_sample add_13010 = (pass_13076 + mul_13011);
			t_sample tap_14362 = m_delay_25.read_linear(add_13075);
			t_sample sub_14360 = (sub_13009 - tap_14362);
			t_sample mul_14361 = (tap_14362 * mul_14118);
			t_sample add_14363 = (sub_13009 + mul_14361);
			t_sample tap_14368 = m_delay_26.read_linear(add_13065);
			t_sample sub_14366 = (sub_14360 - tap_14368);
			t_sample mul_14367 = (tap_14368 * mul_14118);
			t_sample add_14369 = (sub_14360 + mul_14367);
			t_sample tap_14374 = m_delay_27.read_linear(add_13063);
			t_sample sub_14372 = (sub_14366 - tap_14374);
			t_sample mul_14373 = (tap_14374 * mul_14118);
			t_sample add_14375 = (sub_14366 + mul_14373);
			t_sample mul_13028 = (sub_14372 * sqrt_13023);
			t_sample add_13024 = (mul_13025 + mul_13028);
			t_sample out1 = (gate_13085 + add_13024);
			t_sample tap_14380 = m_delay_28.read_linear(add_13015);
			t_sample sub_14378 = (pass_13076 - tap_14380);
			t_sample mul_14379 = (tap_14380 * mul_14275);
			t_sample add_14381 = (pass_13076 + mul_14379);
			t_sample tap_14386 = m_delay_29.read_linear(add_13021);
			t_sample sub_14384 = (sub_14378 - tap_14386);
			t_sample mul_14385 = (tap_14386 * mul_14275);
			t_sample add_14387 = (sub_14378 + mul_14385);
			t_sample tap_14392 = m_delay_30.read_linear(add_13019);
			t_sample sub_14390 = (sub_14384 - tap_14392);
			t_sample mul_14391 = (tap_14392 * mul_14275);
			t_sample add_14393 = (sub_14384 + mul_14391);
			t_sample tap_14398 = m_delay_31.read_linear(add_13017);
			t_sample sub_14396 = (sub_14390 - tap_14398);
			t_sample mul_14397 = (tap_14398 * mul_14275);
			t_sample add_14399 = (sub_14390 + mul_14397);
			t_sample mul_13004 = (sub_14396 * sqrt_13023);
			t_sample add_13003 = (mul_13025 + mul_13004);
			t_sample out2 = (add_13003 + gate_13085);
			m_history_7 = history_13081_next_13083;
			m_delay_31.write(add_14399);
			m_delay_30.write(add_14393);
			m_delay_29.write(add_14387);
			m_delay_28.write(add_14381);
			m_delay_27.write(add_14375);
			m_delay_26.write(add_14369);
			m_delay_25.write(add_14363);
			m_delay_24.write(add_13010);
			m_history_23 = history_13032_next_14349;
			m_delay_22.write(add_14357);
			m_history_21 = history_13032_next_14343;
			m_delay_20.write(add_14339);
			m_history_19 = history_13032_next_14326;
			m_delay_18.write(add_14328);
			m_history_17 = history_13032_next_14314;
			m_delay_16.write(add_14316);
			m_history_15 = history_13032_next_14302;
			m_delay_14.write(add_14304);
			m_history_13 = history_13032_next_14292;
			m_delay_12.write(add_14293);
			m_history_11 = history_13032_next_14279;
			m_delay_10.write(add_14280);
			m_history_9 = history_13032_next_13039;
			m_delay_8.write(add_13038);
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
	inline void set_sw1(t_param _value) {
		m_sw_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb2(t_param _value) {
		m_knob5_fb_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_6 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
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
		case 0: *value = self->m_knob1_wetdry_4; break;
		case 1: *value = self->m_knob3_damp_3; break;
		case 2: *value = self->m_knob4_fb_5; break;
		case 3: *value = self->m_knob5_fb_2; break;
		case 4: *value = self->m_knob6_spread_6; break;
		case 5: *value = self->m_sw_1; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_4")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_damp_3")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_fb_5")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_5;
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
	// initialize parameter 4 ("m_knob6_spread_6")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_1")
	pi = self->__commonstate.params + 5;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_1;
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
