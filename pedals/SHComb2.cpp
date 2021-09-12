#include "SHComb2.h"

namespace SHComb2 {

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
	Data m_ms_5;
	Delay m_delay_1;
	Delay m_delay_3;
	Delay m_delay_4;
	Delay m_delay_2;
	Phasor __m_phasor_30;
	Phasor __m_phasor_29;
	Sah __m_sah_27;
	Sah __m_sah_31;
	int __exception;
	int vectorsize;
	t_sample m_history_8;
	t_sample m_sw_22;
	t_sample m_knob5_r_21;
	t_sample m_knob6_r_23;
	t_sample m_knob1_res_24;
	t_sample m_knob4_max_25;
	t_sample m_knob2_key_26;
	t_sample m_sw_20;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample m_history_7;
	t_sample m_knob3_min_19;
	t_sample m_history_17;
	t_sample m_history_11;
	t_sample m_history_10;
	t_sample m_history_9;
	t_sample m_history_18;
	t_sample m_history_12;
	t_sample m_history_6;
	t_sample m_history_13;
	t_sample m_history_16;
	t_sample m_history_15;
	t_sample m_history_14;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)6000));
		m_delay_2.reset("m_delay_2", ((int)6000));
		m_delay_3.reset("m_delay_3", ((int)6000));
		m_delay_4.reset("m_delay_4", ((int)6000));
		m_ms_5.reset("ms", ((int)12), ((int)1));
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_knob3_min_19 = ((int)0);
		m_sw_20 = ((int)0);
		m_knob5_r_21 = ((int)0);
		m_sw_22 = ((int)0);
		m_knob6_r_23 = ((int)0);
		m_knob1_res_24 = ((int)0);
		m_knob4_max_25 = ((int)0);
		m_knob2_key_26 = ((int)0);
		__m_sah_27.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_29.reset(0);
		__m_phasor_30.reset(0);
		__m_sah_31.reset(0);
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
		t_sample sqrt_7274 = sqrt(m_knob1_res_24);
		t_sample sqrt_7283 = sqrt(sqrt_7274);
		t_sample mul_7286 = (sqrt_7283 * ((t_sample)0.99));
		t_sample mul_7120 = (m_knob2_key_26 * ((int)12));
		t_sample round_7119 = round(mul_7120);
		samples_to_seconds = (1 / samplerate);
		int ms_dim = m_ms_5.dim;
		int ms_channels = m_ms_5.channels;
		bool index_ignore_32 = (((int)1) >= ms_dim);
		bool index_ignore_33 = (((int)2) >= ms_dim);
		bool index_ignore_34 = (((int)3) >= ms_dim);
		bool index_ignore_35 = (((int)4) >= ms_dim);
		bool index_ignore_36 = (((int)5) >= ms_dim);
		bool index_ignore_37 = (((int)6) >= ms_dim);
		bool index_ignore_38 = (((int)7) >= ms_dim);
		bool index_ignore_39 = (((int)8) >= ms_dim);
		bool index_ignore_40 = (((int)9) >= ms_dim);
		bool index_ignore_41 = (((int)10) >= ms_dim);
		bool index_ignore_42 = (((int)11) >= ms_dim);
		bool index_ignore_45 = (((int)1) >= ms_dim);
		bool index_ignore_46 = (((int)2) >= ms_dim);
		bool index_ignore_47 = (((int)3) >= ms_dim);
		bool index_ignore_48 = (((int)4) >= ms_dim);
		bool index_ignore_49 = (((int)5) >= ms_dim);
		bool index_ignore_50 = (((int)6) >= ms_dim);
		bool index_ignore_51 = (((int)7) >= ms_dim);
		bool index_ignore_52 = (((int)8) >= ms_dim);
		bool index_ignore_53 = (((int)9) >= ms_dim);
		bool index_ignore_54 = (((int)10) >= ms_dim);
		bool index_ignore_55 = (((int)11) >= ms_dim);
		bool index_ignore_58 = (((int)1) >= ms_dim);
		bool index_ignore_59 = (((int)2) >= ms_dim);
		bool index_ignore_60 = (((int)3) >= ms_dim);
		bool index_ignore_61 = (((int)4) >= ms_dim);
		bool index_ignore_62 = (((int)5) >= ms_dim);
		bool index_ignore_63 = (((int)6) >= ms_dim);
		bool index_ignore_64 = (((int)7) >= ms_dim);
		bool index_ignore_65 = (((int)8) >= ms_dim);
		bool index_ignore_66 = (((int)9) >= ms_dim);
		bool index_ignore_67 = (((int)10) >= ms_dim);
		bool index_ignore_68 = (((int)11) >= ms_dim);
		bool index_ignore_71 = (((int)1) >= ms_dim);
		bool index_ignore_72 = (((int)2) >= ms_dim);
		bool index_ignore_73 = (((int)3) >= ms_dim);
		bool index_ignore_74 = (((int)4) >= ms_dim);
		bool index_ignore_75 = (((int)5) >= ms_dim);
		bool index_ignore_76 = (((int)6) >= ms_dim);
		bool index_ignore_77 = (((int)7) >= ms_dim);
		bool index_ignore_78 = (((int)8) >= ms_dim);
		bool index_ignore_79 = (((int)9) >= ms_dim);
		bool index_ignore_80 = (((int)10) >= ms_dim);
		bool index_ignore_81 = (((int)11) >= ms_dim);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_7277 = __m_sah_27(m_history_18, m_sw_20, ((int)0));
			t_sample gen_7279 = sah_7277;
			t_sample rsub_7275 = (((int)1) - sah_7277);
			t_sample history_7276_next_7278 = fixdenorm(rsub_7275);
			t_sample out3 = gen_7279;
			t_sample add_7282 = (gen_7279 + ((int)1));
			t_sample choice_28 = int(add_7282);
			t_sample gate_7280 = (((choice_28 >= 1) && (choice_28 < 2)) ? in1 : 0);
			t_sample gate_7281 = ((choice_28 >= 2) ? in1 : 0);
			t_sample switch_7108 = (m_sw_22 ? gate_7281 : ((int)0));
			t_sample mix_7515 = (m_history_17 + (((t_sample)0.003926980723806) * (m_knob3_min_19 - m_history_17)));
			t_sample mix_7235 = mix_7515;
			t_sample mix_7516 = (m_history_16 + (((t_sample)0.003926980723806) * (mix_7235 - m_history_16)));
			t_sample mix_7233 = mix_7516;
			t_sample mix_7517 = (m_history_15 + (((t_sample)0.003926980723806) * (mix_7233 - m_history_15)));
			t_sample mix_7231 = mix_7517;
			t_sample gen_7272 = mix_7231;
			t_sample history_7236_next_7238 = fixdenorm(mix_7235);
			t_sample history_7234_next_7239 = fixdenorm(mix_7233);
			t_sample history_7232_next_7240 = fixdenorm(mix_7231);
			t_sample sub_7521 = (gen_7272 - ((int)0));
			t_sample scale_7518 = ((safepow((sub_7521 * ((t_sample)1)), ((int)1)) * ((int)84)) + ((int)24));
			t_sample mix_7522 = (m_history_14 + (((t_sample)0.003926980723806) * (m_knob4_max_25 - m_history_14)));
			t_sample mix_7290 = mix_7522;
			t_sample mix_7523 = (m_history_13 + (((t_sample)0.003926980723806) * (mix_7290 - m_history_13)));
			t_sample mix_7292 = mix_7523;
			t_sample mix_7524 = (m_history_12 + (((t_sample)0.003926980723806) * (mix_7292 - m_history_12)));
			t_sample mix_7297 = mix_7524;
			t_sample gen_7241 = mix_7297;
			t_sample history_7236_next_7293 = fixdenorm(mix_7290);
			t_sample history_7234_next_7296 = fixdenorm(mix_7292);
			t_sample history_7232_next_7298 = fixdenorm(mix_7297);
			t_sample sub_7528 = (gen_7241 - ((int)0));
			t_sample scale_7525 = ((safepow((sub_7528 * ((t_sample)1)), ((int)1)) * ((int)84)) + ((int)24));
			t_sample mix_7529 = (m_history_11 + (((t_sample)0.003926980723806) * (m_knob5_r_21 - m_history_11)));
			t_sample mix_7303 = mix_7529;
			t_sample mix_7530 = (m_history_10 + (((t_sample)0.003926980723806) * (mix_7303 - m_history_10)));
			t_sample mix_7307 = mix_7530;
			t_sample mix_7531 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_7307 - m_history_9)));
			t_sample mix_7310 = mix_7531;
			t_sample gen_7271 = mix_7310;
			t_sample history_7236_next_7308 = fixdenorm(mix_7303);
			t_sample history_7234_next_7305 = fixdenorm(mix_7307);
			t_sample history_7232_next_7306 = fixdenorm(mix_7310);
			t_sample mul_7284 = (gen_7271 * ((int)10));
			t_sample phasor_7285 = __m_phasor_29(mul_7284, samples_to_seconds);
			t_sample mix_7532 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob6_r_23 - m_history_8)));
			t_sample mix_7316 = mix_7532;
			t_sample mix_7533 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_7316 - m_history_7)));
			t_sample mix_7321 = mix_7533;
			t_sample mix_7534 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_7321 - m_history_6)));
			t_sample mix_7324 = mix_7534;
			t_sample gen_7270 = mix_7324;
			t_sample history_7236_next_7323 = fixdenorm(mix_7316);
			t_sample history_7234_next_7318 = fixdenorm(mix_7321);
			t_sample history_7232_next_7319 = fixdenorm(mix_7324);
			t_sample mul_7225 = (gen_7270 * ((int)10));
			t_sample phasor_7226 = __m_phasor_30(mul_7225, samples_to_seconds);
			t_sample sah_7227 = __m_sah_31(phasor_7285, phasor_7226, ((t_sample)0.5));
			t_sample add_7122 = (sah_7227 + ((t_sample)0.75));
			t_sample mod_7121 = safemod(add_7122, ((int)1));
			t_sample orange_7537 = (scale_7525 - scale_7518);
			t_sample sub_7538 = (mod_7121 - ((int)0));
			t_sample scale_7535 = ((safepow((sub_7538 * ((t_sample)1)), ((int)1)) * orange_7537) + scale_7518);
			m_ms_5.write(((int)0), 0, 0);
			if ((!index_ignore_32)) {
				m_ms_5.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_33)) {
				m_ms_5.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_34)) {
				m_ms_5.write(((int)4), ((int)3), 0);
				
			};
			if ((!index_ignore_35)) {
				m_ms_5.write(((int)4), ((int)4), 0);
				
			};
			if ((!index_ignore_36)) {
				m_ms_5.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_37)) {
				m_ms_5.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_38)) {
				m_ms_5.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_39)) {
				m_ms_5.write(((int)9), ((int)8), 0);
				
			};
			if ((!index_ignore_40)) {
				m_ms_5.write(((int)9), ((int)9), 0);
				
			};
			if ((!index_ignore_41)) {
				m_ms_5.write(((int)11), ((int)10), 0);
				
			};
			if ((!index_ignore_42)) {
				m_ms_5.write(((int)11), ((int)11), 0);
				
			};
			t_sample oct = floor((scale_7535 * ((t_sample)0.083333333333333)));
			t_sample pc = floor(safemod((scale_7535 + round_7119), ((int)12)));
			int index_trunc_43 = fixnan(floor(pc));
			bool index_ignore_44 = ((index_trunc_43 >= ms_dim) || (index_trunc_43 < 0));
			// samples ms channel 1;
			t_sample pc_grid = (index_ignore_44 ? 0 : m_ms_5.read(index_trunc_43, 0));
			t_sample outpitch = ((pc_grid + (oct * ((int)12))) - round_7119);
			t_sample mtof_7130 = mtof(outpitch, ((int)440));
			t_sample rdiv_7129 = safediv(((int)1000), mtof_7130);
			t_sample mstosamps_7128 = (rdiv_7129 * (samplerate * 0.001));
			t_sample tap_7158 = m_delay_4.read_linear(mstosamps_7128);
			t_sample mul_7156 = (tap_7158 * mul_7286);
			t_sample mul_7112 = (mul_7156 * ((t_sample)0.6));
			t_sample mul_7111 = (mul_7156 * ((t_sample)0.4));
			t_sample add_7124 = (sah_7227 + ((t_sample)0.5));
			t_sample mod_7123 = safemod(add_7124, ((int)1));
			t_sample orange_7541 = (scale_7525 - scale_7518);
			t_sample sub_7542 = (mod_7123 - ((int)0));
			t_sample scale_7539 = ((safepow((sub_7542 * ((t_sample)1)), ((int)1)) * orange_7541) + scale_7518);
			m_ms_5.write(((int)0), 0, 0);
			if ((!index_ignore_45)) {
				m_ms_5.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_46)) {
				m_ms_5.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_47)) {
				m_ms_5.write(((int)4), ((int)3), 0);
				
			};
			if ((!index_ignore_48)) {
				m_ms_5.write(((int)4), ((int)4), 0);
				
			};
			if ((!index_ignore_49)) {
				m_ms_5.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_50)) {
				m_ms_5.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_51)) {
				m_ms_5.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_52)) {
				m_ms_5.write(((int)9), ((int)8), 0);
				
			};
			if ((!index_ignore_53)) {
				m_ms_5.write(((int)9), ((int)9), 0);
				
			};
			if ((!index_ignore_54)) {
				m_ms_5.write(((int)11), ((int)10), 0);
				
			};
			if ((!index_ignore_55)) {
				m_ms_5.write(((int)11), ((int)11), 0);
				
			};
			t_sample oct_7330 = floor((scale_7539 * ((t_sample)0.083333333333333)));
			t_sample pc_7329 = floor(safemod((scale_7539 + round_7119), ((int)12)));
			int index_trunc_56 = fixnan(floor(pc_7329));
			bool index_ignore_57 = ((index_trunc_56 >= ms_dim) || (index_trunc_56 < 0));
			// samples ms channel 1;
			t_sample pc_grid_7331 = (index_ignore_57 ? 0 : m_ms_5.read(index_trunc_56, 0));
			t_sample outpitch_7332 = ((pc_grid_7331 + (oct_7330 * ((int)12))) - round_7119);
			t_sample mtof_7162 = mtof(outpitch_7332, ((int)440));
			t_sample rdiv_7161 = safediv(((int)1000), mtof_7162);
			t_sample mstosamps_7160 = (rdiv_7161 * (samplerate * 0.001));
			t_sample tap_7190 = m_delay_3.read_linear(mstosamps_7160);
			t_sample mul_7188 = (tap_7190 * mul_7286);
			t_sample mul_7114 = (mul_7188 * ((t_sample)0.9));
			t_sample mul_7113 = (mul_7188 * ((t_sample)0.1));
			t_sample add_7224 = (sah_7227 + ((int)0));
			t_sample mod_7223 = safemod(add_7224, ((int)1));
			t_sample orange_7545 = (scale_7525 - scale_7518);
			t_sample sub_7546 = (mod_7223 - ((int)0));
			t_sample scale_7543 = ((safepow((sub_7546 * ((t_sample)1)), ((int)1)) * orange_7545) + scale_7518);
			m_ms_5.write(((int)0), 0, 0);
			if ((!index_ignore_58)) {
				m_ms_5.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_59)) {
				m_ms_5.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_60)) {
				m_ms_5.write(((int)4), ((int)3), 0);
				
			};
			if ((!index_ignore_61)) {
				m_ms_5.write(((int)4), ((int)4), 0);
				
			};
			if ((!index_ignore_62)) {
				m_ms_5.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_63)) {
				m_ms_5.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_64)) {
				m_ms_5.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_65)) {
				m_ms_5.write(((int)9), ((int)8), 0);
				
			};
			if ((!index_ignore_66)) {
				m_ms_5.write(((int)9), ((int)9), 0);
				
			};
			if ((!index_ignore_67)) {
				m_ms_5.write(((int)11), ((int)10), 0);
				
			};
			if ((!index_ignore_68)) {
				m_ms_5.write(((int)11), ((int)11), 0);
				
			};
			t_sample oct_7334 = floor((scale_7543 * ((t_sample)0.083333333333333)));
			t_sample pc_7333 = floor(safemod((scale_7543 + round_7119), ((int)12)));
			int index_trunc_69 = fixnan(floor(pc_7333));
			bool index_ignore_70 = ((index_trunc_69 >= ms_dim) || (index_trunc_69 < 0));
			// samples ms channel 1;
			t_sample pc_grid_7335 = (index_ignore_70 ? 0 : m_ms_5.read(index_trunc_69, 0));
			t_sample outpitch_7336 = ((pc_grid_7335 + (oct_7334 * ((int)12))) - round_7119);
			t_sample mtof_7244 = mtof(outpitch_7336, ((int)440));
			t_sample rdiv_7243 = safediv(((int)1000), mtof_7244);
			t_sample mstosamps_7242 = (rdiv_7243 * (samplerate * 0.001));
			t_sample tap_7289 = m_delay_2.read_linear(mstosamps_7242);
			t_sample mul_7287 = (tap_7289 * mul_7286);
			t_sample mul_7117 = (mul_7287 * ((t_sample)0.1));
			t_sample mul_7118 = (mul_7287 * ((t_sample)0.9));
			t_sample add_7126 = (sah_7227 + ((t_sample)0.25));
			t_sample mod_7125 = safemod(add_7126, ((int)1));
			t_sample orange_7549 = (scale_7525 - scale_7518);
			t_sample sub_7550 = (mod_7125 - ((int)0));
			t_sample scale_7547 = ((safepow((sub_7550 * ((t_sample)1)), ((int)1)) * orange_7549) + scale_7518);
			m_ms_5.write(((int)0), 0, 0);
			if ((!index_ignore_71)) {
				m_ms_5.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_72)) {
				m_ms_5.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_73)) {
				m_ms_5.write(((int)4), ((int)3), 0);
				
			};
			if ((!index_ignore_74)) {
				m_ms_5.write(((int)4), ((int)4), 0);
				
			};
			if ((!index_ignore_75)) {
				m_ms_5.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_76)) {
				m_ms_5.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_77)) {
				m_ms_5.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_78)) {
				m_ms_5.write(((int)9), ((int)8), 0);
				
			};
			if ((!index_ignore_79)) {
				m_ms_5.write(((int)9), ((int)9), 0);
				
			};
			if ((!index_ignore_80)) {
				m_ms_5.write(((int)11), ((int)10), 0);
				
			};
			if ((!index_ignore_81)) {
				m_ms_5.write(((int)11), ((int)11), 0);
				
			};
			t_sample oct_7338 = floor((scale_7547 * ((t_sample)0.083333333333333)));
			t_sample pc_7337 = floor(safemod((scale_7547 + round_7119), ((int)12)));
			int index_trunc_82 = fixnan(floor(pc_7337));
			bool index_ignore_83 = ((index_trunc_82 >= ms_dim) || (index_trunc_82 < 0));
			// samples ms channel 1;
			t_sample pc_grid_7339 = (index_ignore_83 ? 0 : m_ms_5.read(index_trunc_82, 0));
			t_sample outpitch_7340 = ((pc_grid_7339 + (oct_7338 * ((int)12))) - round_7119);
			t_sample mtof_7194 = mtof(outpitch_7340, ((int)440));
			t_sample rdiv_7193 = safediv(((int)1000), mtof_7194);
			t_sample mstosamps_7192 = (rdiv_7193 * (samplerate * 0.001));
			t_sample tap_7222 = m_delay_1.read_linear(mstosamps_7192);
			t_sample mul_7220 = (tap_7222 * mul_7286);
			t_sample mul_7115 = (mul_7220 * ((t_sample)0.4));
			t_sample div_7109 = (((((mul_7115 + mul_7117) + switch_7108) + mul_7114) + mul_7112) * ((t_sample)0.25));
			t_sample out2 = (gate_7280 + div_7109);
			t_sample mul_7116 = (mul_7220 * ((t_sample)0.6));
			t_sample div_7110 = (((((mul_7116 + mul_7118) + switch_7108) + mul_7113) + mul_7111) * ((t_sample)0.25));
			t_sample out1 = (gate_7280 + div_7110);
			m_history_18 = history_7276_next_7278;
			m_history_17 = history_7236_next_7238;
			m_history_15 = history_7232_next_7240;
			m_history_16 = history_7234_next_7239;
			m_history_14 = history_7236_next_7293;
			m_history_12 = history_7232_next_7298;
			m_history_13 = history_7234_next_7296;
			m_history_11 = history_7236_next_7308;
			m_history_9 = history_7232_next_7306;
			m_history_10 = history_7234_next_7305;
			m_history_8 = history_7236_next_7323;
			m_history_6 = history_7232_next_7319;
			m_history_7 = history_7234_next_7318;
			m_delay_4.write((mul_7156 + gate_7281));
			m_delay_3.write((mul_7188 + gate_7281));
			m_delay_2.write((mul_7287 + gate_7281));
			m_delay_1.write((mul_7220 + gate_7281));
			m_delay_1.step();
			m_delay_2.step();
			m_delay_3.step();
			m_delay_4.step();
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
	inline void set_ms(void * _value) {
		m_ms_5.setbuffer(_value);
	};
	inline void set_knob3_min(t_param _value) {
		m_knob3_min_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_r1(t_param _value) {
		m_knob5_r_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_r2(t_param _value) {
		m_knob6_r_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_res(t_param _value) {
		m_knob1_res_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_max(t_param _value) {
		m_knob4_max_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2_key(t_param _value) {
		m_knob2_key_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 9; }

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
		case 0: self->set_knob1_res(value); break;
		case 1: self->set_knob2_key(value); break;
		case 2: self->set_knob3_min(value); break;
		case 3: self->set_knob4_max(value); break;
		case 4: self->set_knob5_r1(value); break;
		case 5: self->set_knob6_r2(value); break;
		case 6: self->set_ms(ref); break;
		case 7: self->set_sw1(value); break;
		case 8: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_res_24; break;
		case 1: *value = self->m_knob2_key_26; break;
		case 2: *value = self->m_knob3_min_19; break;
		case 3: *value = self->m_knob4_max_25; break;
		case 4: *value = self->m_knob5_r_21; break;
		case 5: *value = self->m_knob6_r_23; break;
		
		case 7: *value = self->m_sw_20; break;
		case 8: *value = self->m_sw_22; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(9 * sizeof(ParamInfo));
	self->__commonstate.numparams = 9;
	// initialize parameter 0 ("m_knob1_res_24")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_res_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob2_key_26")
	pi = self->__commonstate.params + 1;
	pi->name = "knob2_key";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_key_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob3_min_19")
	pi = self->__commonstate.params + 2;
	pi->name = "knob3_min";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_min_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob4_max_25")
	pi = self->__commonstate.params + 3;
	pi->name = "knob4_max";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_max_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob5_r_21")
	pi = self->__commonstate.params + 4;
	pi->name = "knob5_r1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_r_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob6_r_23")
	pi = self->__commonstate.params + 5;
	pi->name = "knob6_r2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_r_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_ms_5")
	pi = self->__commonstate.params + 6;
	pi->name = "ms";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_sw_20")
	pi = self->__commonstate.params + 7;
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
	// initialize parameter 8 ("m_sw_22")
	pi = self->__commonstate.params + 8;
	pi->name = "sw5";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // SHComb2::
