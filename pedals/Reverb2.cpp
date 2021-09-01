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
	t_sample m_sw_3;
	t_sample m_history_11;
	t_sample m_knob3_damp_2;
	t_sample m_knob1_wetdry_1;
	t_sample samplerate;
	t_sample m_knob5_fb_4;
	t_sample m_history_13;
	t_sample m_knob6_spread_5;
	t_sample m_knob4_fb_6;
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
		m_knob1_wetdry_1 = ((int)0);
		m_knob3_damp_2 = ((t_sample)0.5);
		m_sw_3 = ((int)0);
		m_knob5_fb_4 = ((t_sample)0.5);
		m_knob6_spread_5 = ((int)0);
		m_knob4_fb_6 = ((t_sample)0.9);
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
		t_sample sqrt_2247 = sqrt(m_knob1_wetdry_1);
		t_sample rsub_2251 = (((int)1) - m_knob1_wetdry_1);
		t_sample sqrt_2250 = sqrt(rsub_2251);
		t_sample mul_2246 = (m_knob5_fb_4 * ((t_sample)0.9));
		t_sample mul_2301 = (m_knob5_fb_4 * ((t_sample)0.9));
		t_sample add_2241 = (((int)456) + m_knob6_spread_5);
		t_sample add_2287 = (((int)450) + m_knob6_spread_5);
		t_sample add_2243 = (((int)676) + m_knob6_spread_5);
		t_sample add_2289 = (((int)682) + m_knob6_spread_5);
		t_sample add_2245 = (((int)888) + m_knob6_spread_5);
		t_sample add_2299 = (((int)882) + m_knob6_spread_5);
		t_sample add_2239 = (((int)1106) + m_knob6_spread_5);
		t_sample add_2285 = (((int)1112) + m_knob6_spread_5);
		t_sample add_2292 = (((int)3114) + m_knob6_spread_5);
		t_sample rsub_2254 = (((int)1) - m_knob3_damp_2);
		t_sample add_2291 = (((int)3234) + m_knob6_spread_5);
		t_sample rsub_2318 = (((int)1) - m_knob3_damp_2);
		t_sample add_2293 = (((int)2982) + m_knob6_spread_5);
		t_sample rsub_2324 = (((int)1) - m_knob3_damp_2);
		t_sample add_2294 = (((int)2844) + m_knob6_spread_5);
		t_sample rsub_2340 = (((int)1) - m_knob3_damp_2);
		t_sample add_2295 = (((int)2712) + m_knob6_spread_5);
		t_sample rsub_2351 = (((int)1) - m_knob3_damp_2);
		t_sample add_2296 = (((int)2554) + m_knob6_spread_5);
		t_sample rsub_2364 = (((int)1) - m_knob3_damp_2);
		t_sample add_2297 = (((int)2376) + m_knob6_spread_5);
		t_sample rsub_2377 = (((int)1) - m_knob3_damp_2);
		t_sample add_2298 = (((int)2232) + m_knob6_spread_5);
		t_sample rsub_2388 = (((int)1) - m_knob3_damp_2);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_2306 = __m_sah_32(m_history_7, m_sw_3, ((int)0));
			t_sample gen_2308 = sah_2306;
			t_sample rsub_2304 = (((int)1) - sah_2306);
			t_sample history_2305_next_2307 = fixdenorm(rsub_2304);
			t_sample out3 = gen_2308;
			t_sample add_2311 = (gen_2308 + ((int)1));
			t_sample choice_33 = int(add_2311);
			t_sample gate_2309 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_2310 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_2249 = (gate_2310 * sqrt_2250);
			t_sample mul_2303 = (gate_2310 * ((t_sample)0.015));
			t_sample tap_2261 = m_delay_8.read_linear(add_2292);
			t_sample gen_2283 = tap_2261;
			t_sample mul_2259 = (tap_2261 * m_knob3_damp_2);
			t_sample mul_2257 = (m_history_9 * rsub_2254);
			t_sample add_2258 = (mul_2259 + mul_2257);
			t_sample mul_2255 = (add_2258 * m_knob4_fb_6);
			t_sample add_2262 = (mul_2303 + mul_2255);
			t_sample history_2256_next_2263 = fixdenorm(add_2258);
			t_sample tap_2315 = m_delay_10.read_linear(add_2291);
			t_sample gen_2302 = tap_2315;
			t_sample mul_2319 = (tap_2315 * m_knob3_damp_2);
			t_sample mul_2314 = (m_history_11 * rsub_2318);
			t_sample add_2320 = (mul_2319 + mul_2314);
			t_sample mul_2317 = (add_2320 * m_knob4_fb_6);
			t_sample add_2316 = (mul_2303 + mul_2317);
			t_sample history_2256_next_2321 = fixdenorm(add_2320);
			t_sample tap_2328 = m_delay_12.read_linear(add_2293);
			t_sample gen_2282 = tap_2328;
			t_sample mul_2331 = (tap_2328 * m_knob3_damp_2);
			t_sample mul_2327 = (m_history_13 * rsub_2324);
			t_sample add_2332 = (mul_2331 + mul_2327);
			t_sample mul_2330 = (add_2332 * m_knob4_fb_6);
			t_sample add_2329 = (mul_2303 + mul_2330);
			t_sample history_2256_next_2333 = fixdenorm(add_2332);
			t_sample tap_2337 = m_delay_14.read_linear(add_2294);
			t_sample gen_2281 = tap_2337;
			t_sample mul_2336 = (tap_2337 * m_knob3_damp_2);
			t_sample mul_2341 = (m_history_15 * rsub_2340);
			t_sample add_2343 = (mul_2336 + mul_2341);
			t_sample mul_2342 = (add_2343 * m_knob4_fb_6);
			t_sample add_2338 = (mul_2303 + mul_2342);
			t_sample history_2256_next_2345 = fixdenorm(add_2343);
			t_sample tap_2348 = m_delay_16.read_linear(add_2295);
			t_sample gen_2280 = tap_2348;
			t_sample mul_2356 = (tap_2348 * m_knob3_damp_2);
			t_sample mul_2352 = (m_history_17 * rsub_2351);
			t_sample add_2355 = (mul_2356 + mul_2352);
			t_sample mul_2353 = (add_2355 * m_knob4_fb_6);
			t_sample add_2349 = (mul_2303 + mul_2353);
			t_sample history_2256_next_2357 = fixdenorm(add_2355);
			t_sample tap_2361 = m_delay_18.read_linear(add_2296);
			t_sample gen_2279 = tap_2361;
			t_sample mul_2360 = (tap_2361 * m_knob3_damp_2);
			t_sample mul_2365 = (m_history_19 * rsub_2364);
			t_sample add_2367 = (mul_2360 + mul_2365);
			t_sample mul_2366 = (add_2367 * m_knob4_fb_6);
			t_sample add_2362 = (mul_2303 + mul_2366);
			t_sample history_2256_next_2369 = fixdenorm(add_2367);
			t_sample tap_2374 = m_delay_20.read_linear(add_2297);
			t_sample gen_2278 = tap_2374;
			t_sample mul_2372 = (tap_2374 * m_knob3_damp_2);
			t_sample mul_2378 = (m_history_21 * rsub_2377);
			t_sample add_2379 = (mul_2372 + mul_2378);
			t_sample mul_2380 = (add_2379 * m_knob4_fb_6);
			t_sample add_2375 = (mul_2303 + mul_2380);
			t_sample history_2256_next_2381 = fixdenorm(add_2379);
			t_sample tap_2386 = m_delay_22.read_linear(add_2298);
			t_sample gen_2277 = tap_2386;
			t_sample mul_2384 = (tap_2386 * m_knob3_damp_2);
			t_sample mul_2389 = (m_history_23 * rsub_2388);
			t_sample add_2392 = (mul_2384 + mul_2389);
			t_sample mul_2390 = (add_2392 * m_knob4_fb_6);
			t_sample add_2391 = (mul_2303 + mul_2390);
			t_sample history_2256_next_2393 = fixdenorm(add_2392);
			t_sample pass_2300 = (((((((gen_2277 + gen_2278) + gen_2279) + gen_2280) + gen_2281) + gen_2282) + gen_2302) + gen_2283);
			t_sample tap_2237 = m_delay_24.read_linear(add_2239);
			t_sample sub_2233 = (pass_2300 - tap_2237);
			t_sample mul_2235 = (tap_2237 * mul_2246);
			t_sample add_2234 = (pass_2300 + mul_2235);
			t_sample tap_2400 = m_delay_25.read_linear(add_2245);
			t_sample sub_2399 = (sub_2233 - tap_2400);
			t_sample mul_2398 = (tap_2400 * mul_2246);
			t_sample add_2397 = (sub_2233 + mul_2398);
			t_sample tap_2406 = m_delay_26.read_linear(add_2243);
			t_sample sub_2405 = (sub_2399 - tap_2406);
			t_sample mul_2404 = (tap_2406 * mul_2246);
			t_sample add_2403 = (sub_2399 + mul_2404);
			t_sample tap_2412 = m_delay_27.read_linear(add_2241);
			t_sample sub_2411 = (sub_2405 - tap_2412);
			t_sample mul_2410 = (tap_2412 * mul_2246);
			t_sample add_2409 = (sub_2405 + mul_2410);
			t_sample mul_2228 = (sub_2411 * sqrt_2247);
			t_sample add_2227 = (mul_2249 + mul_2228);
			t_sample out2 = (add_2227 + gate_2309);
			t_sample tap_2418 = m_delay_28.read_linear(add_2285);
			t_sample sub_2417 = (pass_2300 - tap_2418);
			t_sample mul_2416 = (tap_2418 * mul_2301);
			t_sample add_2415 = (pass_2300 + mul_2416);
			t_sample tap_2424 = m_delay_29.read_linear(add_2299);
			t_sample sub_2423 = (sub_2417 - tap_2424);
			t_sample mul_2422 = (tap_2424 * mul_2301);
			t_sample add_2421 = (sub_2417 + mul_2422);
			t_sample tap_2430 = m_delay_30.read_linear(add_2289);
			t_sample sub_2429 = (sub_2423 - tap_2430);
			t_sample mul_2428 = (tap_2430 * mul_2301);
			t_sample add_2427 = (sub_2423 + mul_2428);
			t_sample tap_2436 = m_delay_31.read_linear(add_2287);
			t_sample sub_2435 = (sub_2429 - tap_2436);
			t_sample mul_2434 = (tap_2436 * mul_2301);
			t_sample add_2433 = (sub_2429 + mul_2434);
			t_sample mul_2252 = (sub_2435 * sqrt_2247);
			t_sample add_2248 = (mul_2249 + mul_2252);
			t_sample out1 = (gate_2309 + add_2248);
			m_history_7 = history_2305_next_2307;
			m_delay_31.write(add_2433);
			m_delay_30.write(add_2427);
			m_delay_29.write(add_2421);
			m_delay_28.write(add_2415);
			m_delay_27.write(add_2409);
			m_delay_26.write(add_2403);
			m_delay_25.write(add_2397);
			m_delay_24.write(add_2234);
			m_history_23 = history_2256_next_2393;
			m_delay_22.write(add_2391);
			m_history_21 = history_2256_next_2381;
			m_delay_20.write(add_2375);
			m_history_19 = history_2256_next_2369;
			m_delay_18.write(add_2362);
			m_history_17 = history_2256_next_2357;
			m_delay_16.write(add_2349);
			m_history_15 = history_2256_next_2345;
			m_delay_14.write(add_2338);
			m_history_13 = history_2256_next_2333;
			m_delay_12.write(add_2329);
			m_history_11 = history_2256_next_2321;
			m_delay_10.write(add_2316);
			m_history_9 = history_2256_next_2263;
			m_delay_8.write(add_2262);
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
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb2(t_param _value) {
		m_knob5_fb_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_5 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
	};
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob1_wetdry_1; break;
		case 1: *value = self->m_knob3_damp_2; break;
		case 2: *value = self->m_knob4_fb_6; break;
		case 3: *value = self->m_knob5_fb_4; break;
		case 4: *value = self->m_knob6_spread_5; break;
		case 5: *value = self->m_sw_3; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_1")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_damp_2")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_fb_6")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_fb_4")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_spread_5")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_3")
	pi = self->__commonstate.params + 5;
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


} // Reverb2::
