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
	t_sample m_knob5_rate_21;
	t_sample m_s_3;
	t_sample m_knob6_res_22;
	t_sample m_knob3_manual_20;
	t_sample m_history_19;
	t_sample m_sw_23;
	t_sample m_sw_24;
	t_sample m_knob4_depth_25;
	t_sample samples_to_seconds;
	t_sample m_history_18;
	t_sample __m_slide_28;
	t_sample samplerate;
	t_sample m_s_2;
	t_sample m_history_17;
	t_sample m_history_15;
	t_sample m_s_7;
	t_sample m_s_8;
	t_sample m_s_6;
	t_sample m_s_4;
	t_sample m_s_5;
	t_sample m_history_16;
	t_sample m_slim_9;
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
		m_s_8 = ((int)0);
		m_slim_9 = ((int)0);
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
		m_knob5_rate_21 = 0.1;
		m_knob6_res_22 = 0.5;
		m_sw_23 = ((int)0);
		m_sw_24 = ((int)0);
		m_knob4_depth_25 = 1;
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
		t_sample add_7298 = (m_sw_23 + ((int)1));
		t_sample mstosamps_7296 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_7295 = (((int)100) * (samplerate * 0.001));
		t_sample iup_29 = (1 / maximum(1, abs(mstosamps_7296)));
		t_sample idown_30 = (1 / maximum(1, abs(mstosamps_7295)));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_33 = int(add_7298);
		t_sample minb_34 = ((((t_sample)1e-05) < m_knob6_res_22) ? m_knob6_res_22 : ((t_sample)1e-05));
		t_sample maxb_35 = safediv(((t_sample)12.5), samplerate);
		t_sample minb_36 = ((((t_sample)0.0001) < maxb_35) ? maxb_35 : ((t_sample)0.0001));
		t_sample expr_7201 = sqrt(((minb_36 < ((int)1)) ? minb_36 : ((int)1)));
		t_sample expr_7200 = (((int)-1) * log(expr_7201));
		int min_39 = (-1);
		int min_42 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_7307 = __m_sah_26(m_history_19, m_sw_24, ((int)0));
			t_sample gen_7309 = sah_7307;
			t_sample rsub_7305 = (((int)1) - sah_7307);
			t_sample history_7306_next_7308 = fixdenorm(rsub_7305);
			t_sample out3 = gen_7309;
			t_sample add_7310 = (gen_7309 + ((int)1));
			t_sample choice_27 = int(add_7310);
			t_sample gate_7302 = (((choice_27 >= 1) && (choice_27 < 2)) ? in1 : 0);
			t_sample gate_7303 = ((choice_27 >= 2) ? in1 : 0);
			t_sample mix_7476 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_knob3_manual_20 - m_history_18)));
			t_sample mix_7171 = mix_7476;
			t_sample mix_7477 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_7171 - m_history_17)));
			t_sample mix_7169 = mix_7477;
			t_sample mix_7478 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_7169 - m_history_16)));
			t_sample mix_7167 = mix_7478;
			t_sample gen_7179 = mix_7167;
			t_sample history_7173_next_7176 = fixdenorm(mix_7171);
			t_sample history_7170_next_7177 = fixdenorm(mix_7169);
			t_sample history_7168_next_7178 = fixdenorm(mix_7167);
			t_sample abs_7301 = fabs(gate_7303);
			__m_slide_28 = fixdenorm((__m_slide_28 + (((abs_7301 > __m_slide_28) ? iup_29 : idown_30) * (abs_7301 - __m_slide_28))));
			t_sample slide_7300 = __m_slide_28;
			t_sample mul_7297 = (slide_7300 * ((int)10));
			t_sample mix_7479 = (m_history_15 + (((t_sample)0.0019634941468452) * (m_knob5_rate_21 - m_history_15)));
			t_sample mix_7443 = mix_7479;
			t_sample mix_7480 = (m_history_14 + (((t_sample)0.0019634941468452) * (mix_7443 - m_history_14)));
			t_sample mix_7434 = mix_7480;
			t_sample mix_7481 = (m_history_13 + (((t_sample)0.0019634941468452) * (mix_7434 - m_history_13)));
			t_sample mix_7444 = mix_7481;
			t_sample gen_7292 = mix_7444;
			t_sample history_7173_next_7436 = fixdenorm(mix_7443);
			t_sample history_7170_next_7442 = fixdenorm(mix_7434);
			t_sample history_7168_next_7435 = fixdenorm(mix_7444);
			t_sample rsub_7313 = (((int)1) - gen_7292);
			t_sample sqrt_7312 = sqrt(rsub_7313);
			t_sample rsub_7311 = (((int)1) - sqrt_7312);
			t_sample mul_7317 = (rsub_7311 * ((int)10));
			t_sample phasor_7316 = __m_phasor_31(mul_7317, samples_to_seconds);
			__m_cycle_32.phase(phasor_7316);
			t_sample cycle_7290 = __m_cycle_32(__sinedata);
			t_sample cycleindex_7291 = __m_cycle_32.phase();
			t_sample sub_7485 = (cycle_7290 - (-1));
			t_sample scale_7482 = ((safepow((sub_7485 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_7166 = scale_7482;
			t_sample selector_7299 = ((choice_33 >= 2) ? mul_7297 : ((choice_33 >= 1) ? scale_7166 : 0));
			t_sample mul_7289 = (selector_7299 * m_knob4_depth_25);
			t_sample add_7181 = (mul_7289 + gen_7179);
			t_sample clamp_7180 = ((add_7181 <= ((int)0)) ? ((int)0) : ((add_7181 >= ((int)1)) ? ((int)1) : add_7181));
			t_sample sub_7489 = (clamp_7180 - ((int)0));
			t_sample scale_7486 = ((safepow((sub_7489 * ((t_sample)1)), ((int)1)) * ((int)120)) + ((int)15));
			t_sample scale_7182 = scale_7486;
			t_sample expr_7276 = (((((t_sample)1.05) * ((minb_34 < ((int)1)) ? minb_34 : ((int)1))) - m_rc_11) * ((t_sample)0.25));
			t_sample add_7245 = (m_rc_11 + expr_7276);
			t_sample noise_7205 = noise();
			t_sample expr_7261 = (gate_7303 + (((t_sample)1e-11) * noise_7205));
			t_sample fixdenorm_7206 = fixdenorm(m_previn_10);
			t_sample mul_7228 = (m_s_4 * ((t_sample)0.3));
			t_sample gen_7204 = m_fc_12;
			t_sample mul_7188 = (scale_7182 * ((t_sample)0.90193));
			t_sample add_7185 = (mul_7188 + ((t_sample)7.29));
			t_sample div_7184 = (add_7185 * ((t_sample)0.0078740157480315));
			t_sample clamp_7190 = ((div_7184 <= ((int)0)) ? ((int)0) : ((div_7184 >= ((t_sample)0.99)) ? ((t_sample)0.99) : div_7184));
			t_sample mul_7189 = (clamp_7190 * expr_7200);
			t_sample expr_7202 = (((t_sample)0.99999636) + ((((t_sample)0.031261316) + ((((t_sample)0.00048274797) + (((t_sample)5.949053e-06) * mul_7189)) * mul_7189)) * mul_7189));
			t_sample mul_7197 = (expr_7202 * expr_7202);
			t_sample mul_7196 = (mul_7197 * mul_7197);
			t_sample mul_7195 = (mul_7196 * mul_7196);
			t_sample mul_7194 = (mul_7195 * mul_7195);
			t_sample mul_7193 = (mul_7194 * mul_7194);
			t_sample mul_7187 = (mul_7193 * expr_7201);
			t_sample sub_7186 = (mul_7187 - m_fc_12);
			t_sample div_7183 = (sub_7186 * ((t_sample)0.5));
			t_sample add_7199 = (m_fc_12 + div_7183);
			t_sample fc_next_7203 = fixdenorm(add_7199);
			t_sample expr_7275 = (gen_7204 * gen_7204);
			t_sample expr_7274 = (expr_7275 * (((int)1) - m_rc_11));
			t_sample expr_7273 = (expr_7275 + (expr_7274 * expr_7274));
			t_sample expr_7272 = ((((t_sample)1.25) + ((((t_sample)-0.74375) + (((t_sample)0.3) * expr_7273)) * expr_7273)) * expr_7273);
			t_sample expr_7271 = (m_rc_11 * (((t_sample)1.4) + ((((t_sample)0.108) + ((((t_sample)-0.164) - (((t_sample)0.069) * expr_7272)) * expr_7272)) * expr_7272)));
			t_sample expr_7270 = (((t_sample)0.18) + (((t_sample)0.25) * (expr_7271 * expr_7271)));
			t_sample expr_7269 = ((fixdenorm_7206 * expr_7270) - (expr_7271 * m_s_2));
			t_sample maxb_37 = (((((t_sample)0.062) * expr_7269) * expr_7269) + (((t_sample)0.993) * m_slim_9));
			t_sample minb_38 = ((((int)-1) < maxb_37) ? maxb_37 : ((int)-1));
			t_sample expr_7268 = ((minb_38 < ((int)1)) ? minb_38 : ((int)1));
			t_sample expr_7267 = (expr_7269 * ((((int)1) - expr_7268) + ((((t_sample)0.5) * expr_7268) * expr_7268)));
			t_sample rsub_7246 = (((int)1) - expr_7272);
			t_sample expr_7266 = ((expr_7267 * expr_7272) + (rsub_7246 * m_s_8));
			t_sample mul_7221 = (expr_7266 * ((t_sample)0.3));
			t_sample mul_7231 = (m_s_6 * ((t_sample)0.3));
			t_sample mul_7239 = (m_s_8 * ((t_sample)0.3));
			t_sample add_7237 = (expr_7266 + mul_7239);
			t_sample expr_7265 = ((add_7237 * expr_7272) + (rsub_7246 * m_s_7));
			t_sample mul_7218 = (expr_7265 * ((t_sample)0.3));
			t_sample mul_7236 = (m_s_7 * ((t_sample)0.3));
			t_sample add_7234 = (expr_7265 + mul_7236);
			t_sample clamp_7233 = ((add_7234 <= min_39) ? min_39 : ((add_7234 >= ((int)1)) ? ((int)1) : add_7234));
			t_sample expr_7264 = (clamp_7233 * (((int)1) - ((((t_sample)0.3333333) * clamp_7233) * clamp_7233)));
			t_sample expr_7263 = ((expr_7264 * expr_7272) + (rsub_7246 * m_s_6));
			t_sample add_7229 = (expr_7263 + mul_7231);
			t_sample expr_7262 = ((add_7229 * expr_7272) + (rsub_7246 * m_s_4));
			t_sample add_7226 = (expr_7262 + mul_7228);
			t_sample expr_7260 = ((expr_7261 * expr_7270) - (expr_7271 * add_7226));
			t_sample maxb_40 = (((((t_sample)0.062) * expr_7260) * expr_7260) + (((t_sample)0.993) * expr_7268));
			t_sample minb_41 = ((((int)-1) < maxb_40) ? maxb_40 : ((int)-1));
			t_sample expr_7259 = ((minb_41 < ((int)1)) ? minb_41 : ((int)1));
			t_sample expr_7258 = (expr_7260 * ((((int)1) - expr_7259) + ((((t_sample)0.5) * expr_7259) * expr_7259)));
			t_sample expr_7257 = ((expr_7258 * expr_7272) + (rsub_7246 * expr_7266));
			t_sample add_7219 = (expr_7257 + mul_7221);
			t_sample expr_7256 = ((add_7219 * expr_7272) + (rsub_7246 * expr_7265));
			t_sample add_7216 = (expr_7256 + mul_7218);
			t_sample clamp_7215 = ((add_7216 <= min_42) ? min_42 : ((add_7216 >= ((int)1)) ? ((int)1) : add_7216));
			t_sample expr_7255 = (clamp_7215 * (((int)1) - ((((t_sample)0.3333333) * clamp_7215) * clamp_7215)));
			t_sample expr_7254 = ((expr_7255 * expr_7272) + (rsub_7246 * expr_7263));
			t_sample mul_7210 = (expr_7262 * ((t_sample)0.3));
			t_sample mul_7213 = (expr_7263 * ((t_sample)0.3));
			t_sample add_7211 = (expr_7254 + mul_7213);
			t_sample expr_7253 = ((add_7211 * expr_7272) + (rsub_7246 * expr_7262));
			t_sample add_7208 = (expr_7253 + mul_7210);
			t_sample expr_7252 = (((((t_sample)0.19) * (add_7208 + m_s_5)) + (((t_sample)0.57) * (add_7226 + m_s_1))) - (((t_sample)0.52) * m_s_3));
			t_sample gen_7288 = expr_7252;
			t_sample rc_next_7277 = fixdenorm(add_7245);
			t_sample previn_next_7278 = fixdenorm(expr_7261);
			t_sample slim_next_7279 = fixdenorm(expr_7259);
			t_sample s1_next_7280 = fixdenorm(expr_7257);
			t_sample s2_next_7281 = fixdenorm(expr_7256);
			t_sample s3_next_7282 = fixdenorm(expr_7254);
			t_sample s8_next_7283 = fixdenorm(add_7226);
			t_sample s4_next_7284 = fixdenorm(expr_7253);
			t_sample s6_next_7285 = fixdenorm(expr_7252);
			t_sample s5_next_7286 = fixdenorm(add_7208);
			t_sample s7_next_7287 = fixdenorm(add_7208);
			t_sample add_7315 = (gen_7288 + gate_7302);
			t_sample out1 = add_7315;
			t_sample add_7314 = (gen_7288 + gate_7302);
			t_sample out2 = add_7314;
			m_history_19 = history_7306_next_7308;
			m_history_18 = history_7173_next_7176;
			m_history_16 = history_7168_next_7178;
			m_history_17 = history_7170_next_7177;
			m_history_15 = history_7173_next_7436;
			m_history_13 = history_7168_next_7435;
			m_history_14 = history_7170_next_7442;
			m_fc_12 = fc_next_7203;
			m_s_1 = s7_next_7287;
			m_s_2 = s5_next_7286;
			m_s_3 = s6_next_7285;
			m_s_4 = s4_next_7284;
			m_s_5 = s8_next_7283;
			m_s_6 = s3_next_7282;
			m_s_7 = s2_next_7281;
			m_s_8 = s1_next_7280;
			m_slim_9 = slim_next_7279;
			m_previn_10 = previn_next_7278;
			m_rc_11 = rc_next_7277;
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
	inline void set_knob5_rate(t_param _value) {
		m_knob5_rate_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_res(t_param _value) {
		m_knob6_res_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_depth(t_param _value) {
		m_knob4_depth_25 = (_value < -1 ? -1 : (_value > 1 ? 1 : _value));
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
		case 1: *value = self->m_knob4_depth_25; break;
		case 2: *value = self->m_knob5_rate_21; break;
		case 3: *value = self->m_knob6_res_22; break;
		case 4: *value = self->m_sw_24; break;
		case 5: *value = self->m_sw_23; break;
		
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
	// initialize parameter 1 ("m_knob4_depth_25")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_depth_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -1;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_rate_21")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_rate_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_res_22")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_res_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_24")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_23")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_23;
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
