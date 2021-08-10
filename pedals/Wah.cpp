#include "Wah.h"

namespace Wah {

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
	Phasor __m_phasor_31;
	Sah __m_sah_26;
	SineCycle __m_cycle_32;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_knob6_res_21;
	t_sample m_s_3;
	t_sample m_sw_22;
	t_sample m_knob3_manual_20;
	t_sample m_history_19;
	t_sample m_knob5_rate_23;
	t_sample m_knob4_depth_24;
	t_sample m_sw_25;
	t_sample samples_to_seconds;
	t_sample m_history_18;
	t_sample __m_slide_28;
	t_sample samplerate;
	t_sample m_s_2;
	t_sample m_history_17;
	t_sample m_history_15;
	t_sample m_s_7;
	t_sample m_slim_8;
	t_sample m_s_6;
	t_sample m_s_4;
	t_sample m_s_5;
	t_sample m_history_16;
	t_sample m_s_9;
	t_sample m_rc_11;
	t_sample m_s_1;
	t_sample m_previn_10;
	t_sample m_history_13;
	t_sample m_fc_12;
	t_sample m_history_14;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_s_1 = ((int)0);
		m_s_2 = ((int)0);
		m_s_3 = ((int)0);
		m_s_4 = ((int)0);
		m_s_5 = ((int)0);
		m_s_6 = ((int)0);
		m_s_7 = ((int)0);
		m_slim_8 = ((int)0);
		m_s_9 = ((int)0);
		m_previn_10 = ((int)0);
		m_rc_11 = ((int)0);
		m_fc_12 = ((int)1);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_knob3_manual_20 = 0;
		m_knob6_res_21 = 0.5;
		m_sw_22 = ((int)0);
		m_knob5_rate_23 = 0.1;
		m_knob4_depth_24 = 1;
		m_sw_25 = ((int)0);
		__m_sah_26.reset(0);
		__m_slide_28 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_31.reset(0);
		__m_cycle_32.reset(samplerate, 0);
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
		t_sample add_44413 = (m_sw_25 + ((int)1));
		t_sample mstosamps_44411 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_44410 = (((int)100) * (samplerate * 0.001));
		t_sample iup_29 = (1 / maximum(1, abs(mstosamps_44411)));
		t_sample idown_30 = (1 / maximum(1, abs(mstosamps_44410)));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_33 = int(add_44413);
		t_sample minb_34 = ((((t_sample)1e-05) < m_knob6_res_21) ? m_knob6_res_21 : ((t_sample)1e-05));
		t_sample maxb_35 = safediv(((t_sample)12.5), samplerate);
		t_sample minb_36 = ((((t_sample)0.0001) < maxb_35) ? maxb_35 : ((t_sample)0.0001));
		t_sample expr_44316 = sqrt(((minb_36 < ((int)1)) ? minb_36 : ((int)1)));
		t_sample expr_44315 = (((int)-1) * log(expr_44316));
		int min_39 = (-1);
		int min_42 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_44422 = __m_sah_26(m_history_19, m_sw_22, ((int)0));
			t_sample gen_44424 = sah_44422;
			t_sample rsub_44420 = (((int)1) - sah_44422);
			t_sample history_44421_next_44423 = fixdenorm(rsub_44420);
			t_sample out3 = gen_44424;
			t_sample add_44425 = (gen_44424 + ((int)1));
			t_sample choice_27 = int(add_44425);
			t_sample gate_44417 = (((choice_27 >= 1) && (choice_27 < 2)) ? in1 : 0);
			t_sample gate_44418 = ((choice_27 >= 2) ? in1 : 0);
			t_sample mix_44504 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_knob3_manual_20 - m_history_18)));
			t_sample mix_44286 = mix_44504;
			t_sample mix_44505 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_44286 - m_history_17)));
			t_sample mix_44284 = mix_44505;
			t_sample mix_44506 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_44284 - m_history_16)));
			t_sample mix_44282 = mix_44506;
			t_sample gen_44294 = mix_44282;
			t_sample history_44288_next_44291 = fixdenorm(mix_44286);
			t_sample history_44285_next_44292 = fixdenorm(mix_44284);
			t_sample history_44283_next_44293 = fixdenorm(mix_44282);
			t_sample abs_44416 = fabs(gate_44418);
			__m_slide_28 = fixdenorm((__m_slide_28 + (((abs_44416 > __m_slide_28) ? iup_29 : idown_30) * (abs_44416 - __m_slide_28))));
			t_sample slide_44415 = __m_slide_28;
			t_sample mul_44412 = (slide_44415 * ((int)10));
			t_sample mix_44507 = (m_history_15 + (((t_sample)0.0019634941468452) * (m_knob5_rate_23 - m_history_15)));
			t_sample mix_44437 = mix_44507;
			t_sample mix_44508 = (m_history_14 + (((t_sample)0.0019634941468452) * (mix_44437 - m_history_14)));
			t_sample mix_44435 = mix_44508;
			t_sample mix_44509 = (m_history_13 + (((t_sample)0.0019634941468452) * (mix_44435 - m_history_13)));
			t_sample mix_44434 = mix_44509;
			t_sample gen_44407 = mix_44434;
			t_sample history_44288_next_44442 = fixdenorm(mix_44437);
			t_sample history_44285_next_44436 = fixdenorm(mix_44435);
			t_sample history_44283_next_44443 = fixdenorm(mix_44434);
			t_sample rsub_44428 = (((int)1) - gen_44407);
			t_sample sqrt_44427 = sqrt(rsub_44428);
			t_sample rsub_44426 = (((int)1) - sqrt_44427);
			t_sample mul_44432 = (rsub_44426 * ((int)10));
			t_sample phasor_44431 = __m_phasor_31(mul_44432, samples_to_seconds);
			__m_cycle_32.phase(phasor_44431);
			t_sample cycle_44405 = __m_cycle_32(__sinedata);
			t_sample cycleindex_44406 = __m_cycle_32.phase();
			t_sample sub_44513 = (cycle_44405 - (-1));
			t_sample scale_44510 = ((safepow((sub_44513 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_44281 = scale_44510;
			t_sample selector_44414 = ((choice_33 >= 2) ? mul_44412 : ((choice_33 >= 1) ? scale_44281 : 0));
			t_sample mul_44404 = (selector_44414 * m_knob4_depth_24);
			t_sample add_44296 = (mul_44404 + gen_44294);
			t_sample clamp_44295 = ((add_44296 <= ((int)0)) ? ((int)0) : ((add_44296 >= ((int)1)) ? ((int)1) : add_44296));
			t_sample sub_44517 = (clamp_44295 - ((int)0));
			t_sample scale_44514 = ((safepow((sub_44517 * ((t_sample)1)), ((int)1)) * ((int)120)) + ((int)15));
			t_sample scale_44297 = scale_44514;
			t_sample expr_44391 = (((((t_sample)1.05) * ((minb_34 < ((int)1)) ? minb_34 : ((int)1))) - m_rc_11) * ((t_sample)0.25));
			t_sample add_44360 = (m_rc_11 + expr_44391);
			t_sample fixdenorm_44321 = fixdenorm(m_previn_10);
			t_sample noise_44320 = noise();
			t_sample expr_44376 = (gate_44418 + (((t_sample)1e-11) * noise_44320));
			t_sample mul_44343 = (m_s_4 * ((t_sample)0.3));
			t_sample mul_44354 = (m_s_7 * ((t_sample)0.3));
			t_sample gen_44319 = m_fc_12;
			t_sample mul_44303 = (scale_44297 * ((t_sample)0.90193));
			t_sample add_44300 = (mul_44303 + ((t_sample)7.29));
			t_sample div_44299 = (add_44300 * ((t_sample)0.0078740157480315));
			t_sample clamp_44305 = ((div_44299 <= ((int)0)) ? ((int)0) : ((div_44299 >= ((t_sample)0.99)) ? ((t_sample)0.99) : div_44299));
			t_sample mul_44304 = (clamp_44305 * expr_44315);
			t_sample expr_44317 = (((t_sample)0.99999636) + ((((t_sample)0.031261316) + ((((t_sample)0.00048274797) + (((t_sample)5.949053e-06) * mul_44304)) * mul_44304)) * mul_44304));
			t_sample mul_44312 = (expr_44317 * expr_44317);
			t_sample mul_44311 = (mul_44312 * mul_44312);
			t_sample mul_44310 = (mul_44311 * mul_44311);
			t_sample mul_44309 = (mul_44310 * mul_44310);
			t_sample mul_44308 = (mul_44309 * mul_44309);
			t_sample mul_44302 = (mul_44308 * expr_44316);
			t_sample sub_44301 = (mul_44302 - m_fc_12);
			t_sample div_44298 = (sub_44301 * ((t_sample)0.5));
			t_sample add_44314 = (m_fc_12 + div_44298);
			t_sample fc_next_44318 = fixdenorm(add_44314);
			t_sample expr_44390 = (gen_44319 * gen_44319);
			t_sample expr_44389 = (expr_44390 * (((int)1) - m_rc_11));
			t_sample expr_44388 = (expr_44390 + (expr_44389 * expr_44389));
			t_sample expr_44387 = ((((t_sample)1.25) + ((((t_sample)-0.74375) + (((t_sample)0.3) * expr_44388)) * expr_44388)) * expr_44388);
			t_sample expr_44386 = (m_rc_11 * (((t_sample)1.4) + ((((t_sample)0.108) + ((((t_sample)-0.164) - (((t_sample)0.069) * expr_44387)) * expr_44387)) * expr_44387)));
			t_sample expr_44385 = (((t_sample)0.18) + (((t_sample)0.25) * (expr_44386 * expr_44386)));
			t_sample expr_44384 = ((fixdenorm_44321 * expr_44385) - (expr_44386 * m_s_2));
			t_sample maxb_37 = (((((t_sample)0.062) * expr_44384) * expr_44384) + (((t_sample)0.993) * m_slim_8));
			t_sample minb_38 = ((((int)-1) < maxb_37) ? maxb_37 : ((int)-1));
			t_sample expr_44383 = ((minb_38 < ((int)1)) ? minb_38 : ((int)1));
			t_sample expr_44382 = (expr_44384 * ((((int)1) - expr_44383) + ((((t_sample)0.5) * expr_44383) * expr_44383)));
			t_sample rsub_44361 = (((int)1) - expr_44387);
			t_sample expr_44381 = ((expr_44382 * expr_44387) + (rsub_44361 * m_s_7));
			t_sample add_44352 = (expr_44381 + mul_44354);
			t_sample expr_44380 = ((add_44352 * expr_44387) + (rsub_44361 * m_s_6));
			t_sample mul_44346 = (m_s_5 * ((t_sample)0.3));
			t_sample mul_44336 = (expr_44381 * ((t_sample)0.3));
			t_sample mul_44333 = (expr_44380 * ((t_sample)0.3));
			t_sample mul_44351 = (m_s_6 * ((t_sample)0.3));
			t_sample add_44349 = (expr_44380 + mul_44351);
			t_sample clamp_44348 = ((add_44349 <= min_39) ? min_39 : ((add_44349 >= ((int)1)) ? ((int)1) : add_44349));
			t_sample expr_44379 = (clamp_44348 * (((int)1) - ((((t_sample)0.3333333) * clamp_44348) * clamp_44348)));
			t_sample expr_44378 = ((expr_44379 * expr_44387) + (rsub_44361 * m_s_5));
			t_sample add_44344 = (expr_44378 + mul_44346);
			t_sample expr_44377 = ((add_44344 * expr_44387) + (rsub_44361 * m_s_4));
			t_sample add_44341 = (expr_44377 + mul_44343);
			t_sample expr_44375 = ((expr_44376 * expr_44385) - (expr_44386 * add_44341));
			t_sample maxb_40 = (((((t_sample)0.062) * expr_44375) * expr_44375) + (((t_sample)0.993) * expr_44383));
			t_sample minb_41 = ((((int)-1) < maxb_40) ? maxb_40 : ((int)-1));
			t_sample expr_44374 = ((minb_41 < ((int)1)) ? minb_41 : ((int)1));
			t_sample expr_44373 = (expr_44375 * ((((int)1) - expr_44374) + ((((t_sample)0.5) * expr_44374) * expr_44374)));
			t_sample expr_44372 = ((expr_44373 * expr_44387) + (rsub_44361 * expr_44381));
			t_sample add_44334 = (expr_44372 + mul_44336);
			t_sample expr_44371 = ((add_44334 * expr_44387) + (rsub_44361 * expr_44380));
			t_sample add_44331 = (expr_44371 + mul_44333);
			t_sample clamp_44330 = ((add_44331 <= min_42) ? min_42 : ((add_44331 >= ((int)1)) ? ((int)1) : add_44331));
			t_sample expr_44370 = (clamp_44330 * (((int)1) - ((((t_sample)0.3333333) * clamp_44330) * clamp_44330)));
			t_sample expr_44369 = ((expr_44370 * expr_44387) + (rsub_44361 * expr_44378));
			t_sample mul_44325 = (expr_44377 * ((t_sample)0.3));
			t_sample mul_44328 = (expr_44378 * ((t_sample)0.3));
			t_sample add_44326 = (expr_44369 + mul_44328);
			t_sample expr_44368 = ((add_44326 * expr_44387) + (rsub_44361 * expr_44377));
			t_sample add_44323 = (expr_44368 + mul_44325);
			t_sample expr_44367 = (((((t_sample)0.19) * (add_44323 + m_s_9)) + (((t_sample)0.57) * (add_44341 + m_s_1))) - (((t_sample)0.52) * m_s_3));
			t_sample gen_44403 = expr_44367;
			t_sample rc_next_44392 = fixdenorm(add_44360);
			t_sample previn_next_44393 = fixdenorm(expr_44376);
			t_sample s8_next_44394 = fixdenorm(add_44341);
			t_sample slim_next_44395 = fixdenorm(expr_44374);
			t_sample s1_next_44396 = fixdenorm(expr_44372);
			t_sample s2_next_44397 = fixdenorm(expr_44371);
			t_sample s3_next_44398 = fixdenorm(expr_44369);
			t_sample s4_next_44399 = fixdenorm(expr_44368);
			t_sample s6_next_44400 = fixdenorm(expr_44367);
			t_sample s5_next_44401 = fixdenorm(add_44323);
			t_sample s7_next_44402 = fixdenorm(add_44323);
			t_sample add_44430 = (gen_44403 + gate_44417);
			t_sample out1 = add_44430;
			t_sample add_44429 = (gen_44403 + gate_44417);
			t_sample out2 = add_44429;
			m_history_19 = history_44421_next_44423;
			m_history_18 = history_44288_next_44291;
			m_history_16 = history_44283_next_44293;
			m_history_17 = history_44285_next_44292;
			m_history_15 = history_44288_next_44442;
			m_history_13 = history_44283_next_44443;
			m_history_14 = history_44285_next_44436;
			m_fc_12 = fc_next_44318;
			m_s_1 = s7_next_44402;
			m_s_2 = s5_next_44401;
			m_s_3 = s6_next_44400;
			m_s_4 = s4_next_44399;
			m_s_5 = s3_next_44398;
			m_s_6 = s2_next_44397;
			m_s_7 = s1_next_44396;
			m_slim_8 = slim_next_44395;
			m_s_9 = s8_next_44394;
			m_previn_10 = previn_next_44393;
			m_rc_11 = rc_next_44392;
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
		m_knob3_manual_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_res(t_param _value) {
		m_knob6_res_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_rate(t_param _value) {
		m_knob5_rate_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_depth(t_param _value) {
		m_knob4_depth_24 = (_value < -1 ? -1 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_manual_20; break;
		case 1: *value = self->m_knob4_depth_24; break;
		case 2: *value = self->m_knob5_rate_23; break;
		case 3: *value = self->m_knob6_res_21; break;
		case 4: *value = self->m_sw_22; break;
		case 5: *value = self->m_sw_25; break;
		
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
	// initialize parameter 0 ("m_knob3_manual_20")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_manual";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_manual_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_depth_24")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_depth_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -1;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_rate_23")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_rate_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_res_21")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_res_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_22")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_25")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_25;
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


} // Wah::
