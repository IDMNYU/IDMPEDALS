#include "Glitch2.h"

namespace Glitch2 {

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
	Change __m_change_87;
	Change __m_change_81;
	Change __m_change_93;
	Change __m_change_99;
	DCBlock __m_dcblock_105;
	DCBlock __m_dcblock_106;
	Data m_segments_34;
	Delay m_delay_11;
	Delay m_delay_13;
	Delay m_delay_12;
	Delay m_delay_14;
	Delay m_delay_16;
	Delay m_delay_10;
	Delay m_delay_15;
	Delay m_delay_9;
	Phasor __m_phasor_40;
	PlusEquals __m_pluseq_51;
	PlusEquals __m_pluseq_56;
	PlusEquals __m_pluseq_46;
	PlusEquals __m_pluseq_100;
	PlusEquals __m_pluseq_37;
	PlusEquals __m_pluseq_61;
	PlusEquals __m_pluseq_94;
	PlusEquals __m_pluseq_71;
	PlusEquals __m_pluseq_66;
	PlusEquals __m_pluseq_76;
	PlusEquals __m_pluseq_88;
	PlusEquals __m_pluseq_82;
	PlusEquals __m_pluseq_41;
	Sah __m_sah_63;
	Sah __m_sah_47;
	Sah __m_sah_48;
	Sah __m_sah_73;
	Sah __m_sah_43;
	Sah __m_sah_42;
	Sah __m_sah_72;
	Sah __m_sah_53;
	Sah __m_sah_58;
	Sah __m_sah_52;
	Sah __m_sah_57;
	Sah __m_sah_68;
	Sah __m_sah_67;
	Sah __m_sah_77;
	Sah __m_sah_83;
	Sah __m_sah_96;
	Sah __m_sah_101;
	Sah __m_sah_102;
	Sah __m_sah_78;
	Sah __m_sah_95;
	Sah __m_sah_89;
	Sah __m_sah_84;
	Sah __m_sah_90;
	Sah __m_sah_35;
	Sah __m_sah_62;
	int vectorsize;
	int __exception;
	t_sample m_history_17;
	t_sample m_history_2;
	t_sample m_history_1;
	t_sample m_knob5_glitchlen_33;
	t_sample m_history_25;
	t_sample m_history_3;
	t_sample m_knob1_wetdry_32;
	t_sample samplerate;
	t_sample m_sw_28;
	t_sample m_knob3_rate_31;
	t_sample m_knob6_density_29;
	t_sample m_knob4_buflen_30;
	t_sample m_history_26;
	t_sample m_history_4;
	t_sample samples_to_seconds;
	t_sample m_history_8;
	t_sample m_history_20;
	t_sample m_history_19;
	t_sample m_history_18;
	t_sample m_history_24;
	t_sample m_history_21;
	t_sample m_history_22;
	t_sample m_history_5;
	t_sample m_history_7;
	t_sample m_history_6;
	t_sample m_history_23;
	t_sample m_sw_27;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_delay_9.reset("m_delay_9", ((int)9));
		m_delay_10.reset("m_delay_10", ((int)2));
		m_delay_11.reset("m_delay_11", ((int)5));
		m_delay_12.reset("m_delay_12", ((int)3));
		m_delay_13.reset("m_delay_13", ((int)7));
		m_delay_14.reset("m_delay_14", ((int)5));
		m_delay_15.reset("m_delay_15", ((int)4));
		m_delay_16.reset("m_delay_16", ((int)3));
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_history_23 = ((int)0);
		m_history_24 = ((int)0);
		m_history_25 = ((int)0);
		m_history_26 = ((int)0);
		m_sw_27 = ((int)0);
		m_sw_28 = ((int)0);
		m_knob6_density_29 = ((int)0);
		m_knob4_buflen_30 = ((int)0);
		m_knob3_rate_31 = ((int)0);
		m_knob1_wetdry_32 = ((int)0);
		m_knob5_glitchlen_33 = ((int)0);
		m_segments_34.reset("segments", ((int)480000), ((int)1));
		__m_sah_35.reset(0);
		__m_pluseq_37.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_40.reset(0);
		__m_pluseq_41.reset(0);
		__m_sah_42.reset(0);
		__m_sah_43.reset(0);
		__m_pluseq_46.reset(0);
		__m_sah_47.reset(0);
		__m_sah_48.reset(0);
		__m_pluseq_51.reset(0);
		__m_sah_52.reset(0);
		__m_sah_53.reset(0);
		__m_pluseq_56.reset(0);
		__m_sah_57.reset(0);
		__m_sah_58.reset(0);
		__m_pluseq_61.reset(0);
		__m_sah_62.reset(0);
		__m_sah_63.reset(0);
		__m_pluseq_66.reset(0);
		__m_sah_67.reset(0);
		__m_sah_68.reset(0);
		__m_pluseq_71.reset(0);
		__m_sah_72.reset(0);
		__m_sah_73.reset(0);
		__m_pluseq_76.reset(0);
		__m_sah_77.reset(0);
		__m_sah_78.reset(0);
		__m_change_81.reset(0);
		__m_pluseq_82.reset(0);
		__m_sah_83.reset(0);
		__m_sah_84.reset(0);
		__m_change_87.reset(0);
		__m_pluseq_88.reset(0);
		__m_sah_89.reset(0);
		__m_sah_90.reset(0);
		__m_change_93.reset(0);
		__m_pluseq_94.reset(0);
		__m_sah_95.reset(0);
		__m_sah_96.reset(0);
		__m_change_99.reset(0);
		__m_pluseq_100.reset(0);
		__m_sah_101.reset(0);
		__m_sah_102.reset(0);
		__m_dcblock_105.reset();
		__m_dcblock_106.reset();
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
		int segments_dim = m_segments_34.dim;
		int segments_channels = m_segments_34.channels;
		samples_to_seconds = (1 / samplerate);
		t_sample mstosamps_41 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_30 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_19 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_8 = (((int)1) * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_426 = __m_sah_35(m_history_26, m_sw_28, ((int)0));
			t_sample gen_428 = sah_426;
			t_sample rsub_424 = (((int)1) - sah_426);
			t_sample history_425_next_427 = fixdenorm(rsub_424);
			t_sample out3 = gen_428;
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample mix_8453 = (m_history_25 + (((t_sample)0.0042742627044161) * (m_knob4_buflen_30 - m_history_25)));
			t_sample mix_56 = mix_8453;
			t_sample mix_8454 = (m_history_24 + (((t_sample)0.0042742627044161) * (mix_56 - m_history_24)));
			t_sample mix_54 = mix_8454;
			t_sample mix_8455 = (m_history_23 + (((t_sample)0.0042742627044161) * (mix_54 - m_history_23)));
			t_sample mix_52 = mix_8455;
			t_sample gen_410 = mix_52;
			t_sample history_57_next_59 = fixdenorm(mix_56);
			t_sample history_55_next_60 = fixdenorm(mix_54);
			t_sample history_53_next_61 = fixdenorm(mix_52);
			t_sample expr_8332 = (((int)1) - sqrt((((int)1) - gen_410)));
			t_sample add_431 = (gen_428 + ((int)1));
			t_sample choice_36 = int(add_431);
			t_sample gate_429 = (((choice_36 >= 1) && (choice_36 < 2)) ? in1 : 0);
			t_sample gate_430 = ((choice_36 >= 2) ? in1 : 0);
			t_sample mul_411 = (expr_8332 * ((int)480000));
			t_sample mix_8456 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_knob1_wetdry_32 - m_history_22)));
			t_sample mix_8338 = mix_8456;
			t_sample mix_8457 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_8338 - m_history_21)));
			t_sample mix_8335 = mix_8457;
			t_sample mix_8458 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_8335 - m_history_20)));
			t_sample mix_8341 = mix_8458;
			t_sample gen_3332 = mix_8341;
			t_sample history_57_next_8337 = fixdenorm(mix_8338);
			t_sample history_55_next_8334 = fixdenorm(mix_8335);
			t_sample history_53_next_8342 = fixdenorm(mix_8341);
			t_sample sqrt_3330 = sqrt(gen_3332);
			t_sample rsub_3334 = (((int)1) - gen_3332);
			t_sample sqrt_3333 = sqrt(rsub_3334);
			t_sample mul_3331 = (sqrt_3333 * gate_430);
			t_sample plusequals_423 = __m_pluseq_37.post(((int)1), m_history_1, 0);
			t_sample switch_408 = (m_sw_27 ? ((int)-1) : plusequals_423);
			int index_trunc_38 = fixnan(floor(switch_408));
			bool index_ignore_39 = ((index_trunc_38 >= segments_dim) || (index_trunc_38 < 0));
			if ((!index_ignore_39)) {
				m_segments_34.write(gate_430, index_trunc_38, 0);
				
			};
			int gte_414 = (plusequals_423 >= mul_411);
			int eq_413 = (gte_414 == ((int)1));
			t_sample switch_7748 = (gen_428 ? m_knob3_rate_31 : ((int)0));
			t_sample phasor_422 = __m_phasor_40(switch_7748, samples_to_seconds);
			t_sample out4 = phasor_422;
			t_sample mix_8459 = (m_history_19 + (((t_sample)0.0042742627044161) * (m_knob6_density_29 - m_history_19)));
			t_sample mix_8354 = mix_8459;
			t_sample mix_8460 = (m_history_18 + (((t_sample)0.0042742627044161) * (mix_8354 - m_history_18)));
			t_sample mix_8348 = mix_8460;
			t_sample mix_8461 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_8348 - m_history_17)));
			t_sample mix_8351 = mix_8461;
			t_sample gen_298 = mix_8351;
			t_sample history_57_next_8349 = fixdenorm(mix_8354);
			t_sample history_55_next_8347 = fixdenorm(mix_8348);
			t_sample history_53_next_8346 = fixdenorm(mix_8351);
			t_sample sub_8465 = (gen_298 - ((int)0));
			t_sample scale_8462 = ((safepow((sub_8465 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_97 = m_delay_16.read_step(((int)8));
			t_sample tap_95 = m_delay_15.read_step(((int)8));
			t_sample tap_93 = m_delay_14.read_step(((int)8));
			t_sample tap_91 = m_delay_13.read_step(((int)8));
			t_sample tap_85 = m_delay_12.read_step(((int)8));
			t_sample tap_83 = m_delay_11.read_step(((int)8));
			t_sample tap_89 = m_delay_10.read_step(((int)8));
			t_sample tap_87 = m_delay_9.read_step(((int)9));
			t_sample mul_79 = (gen_298 * ((int)12));
			int gte_78 = (mul_79 >= ((int)0));
			int gte_77 = (mul_79 >= ((int)1));
			int gte_76 = (mul_79 >= ((int)2));
			int gte_75 = (mul_79 >= ((int)3));
			int gte_74 = (mul_79 >= ((int)4));
			int gte_73 = (mul_79 >= ((int)5));
			int gte_72 = (mul_79 >= ((int)6));
			int gte_71 = (mul_79 >= ((int)7));
			int gte_68 = (mul_79 >= ((int)10));
			int gte_67 = (mul_79 >= ((int)11));
			int gte_70 = (mul_79 >= ((int)8));
			int gte_69 = (mul_79 >= ((int)9));
			t_sample mix_8466 = (m_history_8 + (((t_sample)0.0042742627044161) * (m_knob5_glitchlen_33 - m_history_8)));
			t_sample mix_8371 = mix_8466;
			t_sample mix_8467 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_8371 - m_history_7)));
			t_sample mix_8372 = mix_8467;
			t_sample mix_8468 = (m_history_6 + (((t_sample)0.0042742627044161) * (mix_8372 - m_history_6)));
			t_sample mix_8373 = mix_8468;
			t_sample gen_300 = mix_8373;
			t_sample history_57_next_8369 = fixdenorm(mix_8371);
			t_sample history_55_next_8368 = fixdenorm(mix_8372);
			t_sample history_53_next_8367 = fixdenorm(mix_8373);
			t_sample mul_45 = (mul_411 * gen_300);
			t_sample clamp_299 = ((mul_45 <= ((int)50)) ? ((int)50) : ((mul_45 >= ((int)480000)) ? ((int)480000) : mul_45));
			t_sample plusequals_7181 = __m_pluseq_41.post(((int)-1), tap_97, 0);
			t_sample noise_7177 = noise();
			t_sample abs_7176 = fabs(noise_7177);
			t_sample sub_7172 = (clamp_299 - ((int)50));
			t_sample mul_7175 = (abs_7176 * sub_7172);
			t_sample sah_7178 = __m_sah_42(mul_7175, tap_97, ((t_sample)0.5));
			t_sample add_7169 = (sah_7178 + ((int)50));
			t_sample wrap_7179 = wrap(plusequals_7181, ((int)0), add_7169);
			t_sample div_7166 = safediv(wrap_7179, add_7169);
			t_sample expr_7186 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_7166))));
			t_sample noise_7184 = noise();
			t_sample abs_7183 = fabs(noise_7184);
			t_sample mul_7182 = (abs_7183 * mul_411);
			t_sample sah_7185 = __m_sah_43(mul_7182, tap_97, ((t_sample)0.5));
			t_sample add_7167 = (sah_7185 + wrap_7179);
			t_sample switch_7170 = (gte_74 ? add_7167 : ((int)-1));
			int index_trunc_44 = fixnan(floor(switch_7170));
			bool index_ignore_45 = ((index_trunc_44 >= segments_dim) || (index_trunc_44 < 0));
			// samples segments channel 1;
			t_sample sample_segments_7173 = (index_ignore_45 ? 0 : m_segments_34.read(index_trunc_44, 0));
			t_sample index_segments_7174 = switch_7170;
			t_sample mul_7164 = (sample_segments_7173 * expr_7186);
			t_sample plusequals_7205 = __m_pluseq_46.post(((int)-1), tap_95, 0);
			t_sample noise_7201 = noise();
			t_sample abs_7200 = fabs(noise_7201);
			t_sample sub_7196 = (clamp_299 - ((int)50));
			t_sample mul_7199 = (abs_7200 * sub_7196);
			t_sample sah_7202 = __m_sah_47(mul_7199, tap_95, ((t_sample)0.5));
			t_sample add_7193 = (sah_7202 + ((int)50));
			t_sample wrap_7203 = wrap(plusequals_7205, ((int)0), add_7193);
			t_sample div_7190 = safediv(wrap_7203, add_7193);
			t_sample expr_7210 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_7190))));
			t_sample noise_7208 = noise();
			t_sample abs_7207 = fabs(noise_7208);
			t_sample mul_7206 = (abs_7207 * mul_411);
			t_sample sah_7209 = __m_sah_48(mul_7206, tap_95, ((t_sample)0.5));
			t_sample add_7191 = (sah_7209 + wrap_7203);
			t_sample switch_7194 = (gte_73 ? add_7191 : ((int)-1));
			int index_trunc_49 = fixnan(floor(switch_7194));
			bool index_ignore_50 = ((index_trunc_49 >= segments_dim) || (index_trunc_49 < 0));
			// samples segments channel 1;
			t_sample sample_segments_7197 = (index_ignore_50 ? 0 : m_segments_34.read(index_trunc_49, 0));
			t_sample index_segments_7198 = switch_7194;
			t_sample mul_7188 = (sample_segments_7197 * expr_7210);
			t_sample mul_296 = ((mul_7188 + mul_7164) * ((t_sample)0.4));
			t_sample mul_297 = ((mul_7188 + mul_7164) * ((t_sample)0.3));
			t_sample plusequals_7253 = __m_pluseq_51.post(((int)-1), tap_93, 0);
			t_sample noise_7249 = noise();
			t_sample abs_7248 = fabs(noise_7249);
			t_sample sub_7244 = (clamp_299 - ((int)50));
			t_sample mul_7247 = (abs_7248 * sub_7244);
			t_sample sah_7250 = __m_sah_52(mul_7247, tap_93, ((t_sample)0.5));
			t_sample add_7241 = (sah_7250 + ((int)50));
			t_sample wrap_7251 = wrap(plusequals_7253, ((int)0), add_7241);
			t_sample div_7238 = safediv(wrap_7251, add_7241);
			t_sample expr_7258 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_7238))));
			t_sample noise_7256 = noise();
			t_sample abs_7255 = fabs(noise_7256);
			t_sample mul_7254 = (abs_7255 * mul_411);
			t_sample sah_7257 = __m_sah_53(mul_7254, tap_93, ((t_sample)0.5));
			t_sample add_7239 = (sah_7257 + wrap_7251);
			t_sample switch_7242 = (gte_72 ? add_7239 : ((int)-1));
			int index_trunc_54 = fixnan(floor(switch_7242));
			bool index_ignore_55 = ((index_trunc_54 >= segments_dim) || (index_trunc_54 < 0));
			// samples segments channel 1;
			t_sample sample_segments_7245 = (index_ignore_55 ? 0 : m_segments_34.read(index_trunc_54, 0));
			t_sample index_segments_7246 = switch_7242;
			t_sample mul_7236 = (sample_segments_7245 * expr_7258);
			t_sample plusequals_7373 = __m_pluseq_56.post(((int)-1), tap_91, 0);
			t_sample noise_7369 = noise();
			t_sample abs_7368 = fabs(noise_7369);
			t_sample sub_7364 = (clamp_299 - ((int)50));
			t_sample mul_7367 = (abs_7368 * sub_7364);
			t_sample sah_7370 = __m_sah_57(mul_7367, tap_91, ((t_sample)0.5));
			t_sample add_7361 = (sah_7370 + ((int)50));
			t_sample wrap_7371 = wrap(plusequals_7373, ((int)0), add_7361);
			t_sample div_7358 = safediv(wrap_7371, add_7361);
			t_sample expr_7378 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_7358))));
			t_sample noise_7376 = noise();
			t_sample abs_7375 = fabs(noise_7376);
			t_sample mul_7374 = (abs_7375 * mul_411);
			t_sample sah_7377 = __m_sah_58(mul_7374, tap_91, ((t_sample)0.5));
			t_sample add_7359 = (sah_7377 + wrap_7371);
			t_sample switch_7362 = (gte_71 ? add_7359 : ((int)-1));
			int index_trunc_59 = fixnan(floor(switch_7362));
			bool index_ignore_60 = ((index_trunc_59 >= segments_dim) || (index_trunc_59 < 0));
			// samples segments channel 1;
			t_sample sample_segments_7365 = (index_ignore_60 ? 0 : m_segments_34.read(index_trunc_59, 0));
			t_sample index_segments_7366 = switch_7362;
			t_sample mul_7356 = (sample_segments_7365 * expr_7378);
			t_sample mul_294 = ((mul_7356 + mul_7236) * ((t_sample)0.3));
			t_sample mul_295 = ((mul_7356 + mul_7236) * ((t_sample)0.4));
			t_sample plusequals_7349 = __m_pluseq_61.post(((int)-1), tap_85, 0);
			t_sample noise_7345 = noise();
			t_sample abs_7344 = fabs(noise_7345);
			t_sample sub_7340 = (clamp_299 - ((int)50));
			t_sample mul_7343 = (abs_7344 * sub_7340);
			t_sample sah_7346 = __m_sah_62(mul_7343, tap_85, ((t_sample)0.5));
			t_sample add_7337 = (sah_7346 + ((int)50));
			t_sample wrap_7347 = wrap(plusequals_7349, ((int)0), add_7337);
			t_sample div_7334 = safediv(wrap_7347, add_7337);
			t_sample expr_7354 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_7334))));
			t_sample noise_7352 = noise();
			t_sample abs_7351 = fabs(noise_7352);
			t_sample mul_7350 = (abs_7351 * mul_411);
			t_sample sah_7353 = __m_sah_63(mul_7350, tap_85, ((t_sample)0.5));
			t_sample add_7335 = (sah_7353 + wrap_7347);
			t_sample switch_7338 = (gte_68 ? add_7335 : ((int)-1));
			int index_trunc_64 = fixnan(floor(switch_7338));
			bool index_ignore_65 = ((index_trunc_64 >= segments_dim) || (index_trunc_64 < 0));
			// samples segments channel 1;
			t_sample sample_segments_7341 = (index_ignore_65 ? 0 : m_segments_34.read(index_trunc_64, 0));
			t_sample index_segments_7342 = switch_7338;
			t_sample mul_7332 = (sample_segments_7341 * expr_7354);
			t_sample plusequals_7397 = __m_pluseq_66.post(((int)-1), tap_83, 0);
			t_sample noise_7393 = noise();
			t_sample abs_7392 = fabs(noise_7393);
			t_sample sub_7388 = (clamp_299 - ((int)50));
			t_sample mul_7391 = (abs_7392 * sub_7388);
			t_sample sah_7394 = __m_sah_67(mul_7391, tap_83, ((t_sample)0.5));
			t_sample add_7385 = (sah_7394 + ((int)50));
			t_sample wrap_7395 = wrap(plusequals_7397, ((int)0), add_7385);
			t_sample div_7382 = safediv(wrap_7395, add_7385);
			t_sample expr_7402 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_7382))));
			t_sample noise_7400 = noise();
			t_sample abs_7399 = fabs(noise_7400);
			t_sample mul_7398 = (abs_7399 * mul_411);
			t_sample sah_7401 = __m_sah_68(mul_7398, tap_83, ((t_sample)0.5));
			t_sample add_7383 = (sah_7401 + wrap_7395);
			t_sample switch_7386 = (gte_67 ? add_7383 : ((int)-1));
			int index_trunc_69 = fixnan(floor(switch_7386));
			bool index_ignore_70 = ((index_trunc_69 >= segments_dim) || (index_trunc_69 < 0));
			// samples segments channel 1;
			t_sample sample_segments_7389 = (index_ignore_70 ? 0 : m_segments_34.read(index_trunc_69, 0));
			t_sample index_segments_7390 = switch_7386;
			t_sample mul_7380 = (sample_segments_7389 * expr_7402);
			t_sample mul_290 = ((mul_7380 + mul_7332) * ((t_sample)0.2));
			t_sample mul_291 = ((mul_7380 + mul_7332) * ((t_sample)0.5));
			t_sample plusequals_7301 = __m_pluseq_71.post(((int)-1), tap_89, 0);
			t_sample noise_7297 = noise();
			t_sample abs_7296 = fabs(noise_7297);
			t_sample sub_7292 = (clamp_299 - ((int)50));
			t_sample mul_7295 = (abs_7296 * sub_7292);
			t_sample sah_7298 = __m_sah_72(mul_7295, tap_89, ((t_sample)0.5));
			t_sample add_7289 = (sah_7298 + ((int)50));
			t_sample wrap_7299 = wrap(plusequals_7301, ((int)0), add_7289);
			t_sample div_7286 = safediv(wrap_7299, add_7289);
			t_sample expr_7306 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_7286))));
			t_sample noise_7304 = noise();
			t_sample abs_7303 = fabs(noise_7304);
			t_sample mul_7302 = (abs_7303 * mul_411);
			t_sample sah_7305 = __m_sah_73(mul_7302, tap_89, ((t_sample)0.5));
			t_sample add_7287 = (sah_7305 + wrap_7299);
			t_sample switch_7290 = (gte_70 ? add_7287 : ((int)-1));
			int index_trunc_74 = fixnan(floor(switch_7290));
			bool index_ignore_75 = ((index_trunc_74 >= segments_dim) || (index_trunc_74 < 0));
			// samples segments channel 1;
			t_sample sample_segments_7293 = (index_ignore_75 ? 0 : m_segments_34.read(index_trunc_74, 0));
			t_sample index_segments_7294 = switch_7290;
			t_sample mul_7284 = (sample_segments_7293 * expr_7306);
			t_sample plusequals_7325 = __m_pluseq_76.post(((int)-1), tap_87, 0);
			t_sample noise_7321 = noise();
			t_sample abs_7320 = fabs(noise_7321);
			t_sample sub_7316 = (clamp_299 - ((int)50));
			t_sample mul_7319 = (abs_7320 * sub_7316);
			t_sample sah_7322 = __m_sah_77(mul_7319, tap_87, ((t_sample)0.5));
			t_sample add_7313 = (sah_7322 + ((int)50));
			t_sample wrap_7323 = wrap(plusequals_7325, ((int)0), add_7313);
			t_sample div_7310 = safediv(wrap_7323, add_7313);
			t_sample expr_7330 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_7310))));
			t_sample noise_7328 = noise();
			t_sample abs_7327 = fabs(noise_7328);
			t_sample mul_7326 = (abs_7327 * mul_411);
			t_sample sah_7329 = __m_sah_78(mul_7326, tap_87, ((t_sample)0.5));
			t_sample add_7311 = (sah_7329 + wrap_7323);
			t_sample switch_7314 = (gte_69 ? add_7311 : ((int)-1));
			int index_trunc_79 = fixnan(floor(switch_7314));
			bool index_ignore_80 = ((index_trunc_79 >= segments_dim) || (index_trunc_79 < 0));
			// samples segments channel 1;
			t_sample sample_segments_7317 = (index_ignore_80 ? 0 : m_segments_34.read(index_trunc_79, 0));
			t_sample index_segments_7318 = switch_7314;
			t_sample mul_7308 = (sample_segments_7317 * expr_7330);
			t_sample mul_292 = ((mul_7308 + mul_7284) * ((t_sample)0.5));
			t_sample mul_293 = ((mul_7308 + mul_7284) * ((t_sample)0.2));
			int gt_419 = (phasor_422 > ((t_sample)0.5));
			int change_418 = __m_change_81(gt_419);
			int eq_417 = (change_418 == ((int)1));
			t_sample add_39 = (m_history_5 + ((int)1));
			int gt_38 = (m_history_5 > mstosamps_41);
			int mul_37 = (eq_417 * gt_38);
			int and_35 = (gt_38 && eq_417);
			t_sample switch_36 = (and_35 ? ((int)0) : add_39);
			t_sample history_40_next_43 = fixdenorm(switch_36);
			int plusequals_7133 = __m_pluseq_82.post(((int)-1), mul_37, 0);
			t_sample noise_7129 = noise();
			t_sample abs_7128 = fabs(noise_7129);
			t_sample sub_7124 = (clamp_299 - ((int)50));
			t_sample mul_7127 = (abs_7128 * sub_7124);
			t_sample sah_7130 = __m_sah_83(mul_7127, mul_37, ((t_sample)0.5));
			t_sample add_7121 = (sah_7130 + ((int)50));
			t_sample wrap_7131 = wrap(plusequals_7133, ((int)0), add_7121);
			t_sample div_7118 = safediv(wrap_7131, add_7121);
			t_sample expr_7601 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_7118))));
			t_sample noise_7136 = noise();
			t_sample abs_7135 = fabs(noise_7136);
			t_sample mul_7134 = (abs_7135 * mul_411);
			t_sample sah_7137 = __m_sah_84(mul_7134, mul_37, ((t_sample)0.5));
			t_sample add_7119 = (sah_7137 + wrap_7131);
			t_sample switch_7122 = (gte_78 ? add_7119 : ((int)-1));
			int index_trunc_85 = fixnan(floor(switch_7122));
			bool index_ignore_86 = ((index_trunc_85 >= segments_dim) || (index_trunc_85 < 0));
			// samples segments channel 1;
			t_sample sample_segments_7125 = (index_ignore_86 ? 0 : m_segments_34.read(index_trunc_85, 0));
			t_sample index_segments_7126 = switch_7122;
			t_sample mul_7116 = (sample_segments_7125 * expr_7601);
			int gt_381 = (phasor_422 > ((t_sample)0.49));
			int change_380 = __m_change_87(gt_381);
			int eq_379 = (change_380 == ((int)1));
			t_sample add_28 = (m_history_4 + ((int)1));
			int gt_27 = (m_history_4 > mstosamps_30);
			int mul_26 = (eq_379 * gt_27);
			int and_24 = (gt_27 && eq_379);
			t_sample switch_25 = (and_24 ? ((int)0) : add_28);
			t_sample history_29_next_32 = fixdenorm(switch_25);
			int plusequals_7157 = __m_pluseq_88.post(((int)-1), mul_26, 0);
			t_sample noise_7153 = noise();
			t_sample abs_7152 = fabs(noise_7153);
			t_sample sub_7148 = (clamp_299 - ((int)50));
			t_sample mul_7151 = (abs_7152 * sub_7148);
			t_sample sah_7154 = __m_sah_89(mul_7151, mul_26, ((t_sample)0.5));
			t_sample add_7145 = (sah_7154 + ((int)50));
			t_sample wrap_7155 = wrap(plusequals_7157, ((int)0), add_7145);
			t_sample div_7142 = safediv(wrap_7155, add_7145);
			t_sample expr_7162 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_7142))));
			t_sample noise_7160 = noise();
			t_sample abs_7159 = fabs(noise_7160);
			t_sample mul_7158 = (abs_7159 * mul_411);
			t_sample sah_7161 = __m_sah_90(mul_7158, mul_26, ((t_sample)0.5));
			t_sample add_7143 = (sah_7161 + wrap_7155);
			t_sample switch_7146 = (gte_77 ? add_7143 : ((int)-1));
			int index_trunc_91 = fixnan(floor(switch_7146));
			bool index_ignore_92 = ((index_trunc_91 >= segments_dim) || (index_trunc_91 < 0));
			// samples segments channel 1;
			t_sample sample_segments_7149 = (index_ignore_92 ? 0 : m_segments_34.read(index_trunc_91, 0));
			t_sample index_segments_7150 = switch_7146;
			t_sample mul_7140 = (sample_segments_7149 * expr_7162);
			int gt_378 = (phasor_422 > ((t_sample)0.51));
			int change_377 = __m_change_93(gt_378);
			int eq_376 = (change_377 == ((int)1));
			t_sample add_17 = (m_history_3 + ((int)1));
			int gt_16 = (m_history_3 > mstosamps_19);
			int mul_15 = (eq_376 * gt_16);
			int and_13 = (gt_16 && eq_376);
			t_sample switch_14 = (and_13 ? ((int)0) : add_17);
			t_sample history_18_next_21 = fixdenorm(switch_14);
			int plusequals_7229 = __m_pluseq_94.post(((int)-1), mul_15, 0);
			t_sample noise_7225 = noise();
			t_sample abs_7224 = fabs(noise_7225);
			t_sample sub_7220 = (clamp_299 - ((int)50));
			t_sample mul_7223 = (abs_7224 * sub_7220);
			t_sample sah_7226 = __m_sah_95(mul_7223, mul_15, ((t_sample)0.5));
			t_sample add_7217 = (sah_7226 + ((int)50));
			t_sample wrap_7227 = wrap(plusequals_7229, ((int)0), add_7217);
			t_sample div_7214 = safediv(wrap_7227, add_7217);
			t_sample expr_7234 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_7214))));
			t_sample noise_7232 = noise();
			t_sample abs_7231 = fabs(noise_7232);
			t_sample mul_7230 = (abs_7231 * mul_411);
			t_sample sah_7233 = __m_sah_96(mul_7230, mul_15, ((t_sample)0.5));
			t_sample add_7215 = (sah_7233 + wrap_7227);
			t_sample switch_7218 = (gte_76 ? add_7215 : ((int)-1));
			int index_trunc_97 = fixnan(floor(switch_7218));
			bool index_ignore_98 = ((index_trunc_97 >= segments_dim) || (index_trunc_97 < 0));
			// samples segments channel 1;
			t_sample sample_segments_7221 = (index_ignore_98 ? 0 : m_segments_34.read(index_trunc_97, 0));
			t_sample index_segments_7222 = switch_7218;
			t_sample mul_7212 = (sample_segments_7221 * expr_7234);
			int gt_375 = (phasor_422 > ((t_sample)0.48));
			int change_374 = __m_change_99(gt_375);
			int eq_373 = (change_374 == ((int)1));
			t_sample add_6 = (m_history_2 + ((int)1));
			int gt_5 = (m_history_2 > mstosamps_8);
			int mul_4 = (eq_373 * gt_5);
			int and_2 = (gt_5 && eq_373);
			t_sample switch_3 = (and_2 ? ((int)0) : add_6);
			t_sample history_7_next_10 = fixdenorm(switch_3);
			int plusequals_7277 = __m_pluseq_100.post(((int)-1), mul_4, 0);
			t_sample noise_7273 = noise();
			t_sample abs_7272 = fabs(noise_7273);
			t_sample sub_7268 = (clamp_299 - ((int)50));
			t_sample mul_7271 = (abs_7272 * sub_7268);
			t_sample sah_7274 = __m_sah_101(mul_7271, mul_4, ((t_sample)0.5));
			t_sample add_7265 = (sah_7274 + ((int)50));
			t_sample wrap_7275 = wrap(plusequals_7277, ((int)0), add_7265);
			t_sample div_7262 = safediv(wrap_7275, add_7265);
			t_sample expr_7282 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_7262))));
			t_sample noise_7280 = noise();
			t_sample abs_7279 = fabs(noise_7280);
			t_sample mul_7278 = (abs_7279 * mul_411);
			t_sample sah_7281 = __m_sah_102(mul_7278, mul_4, ((t_sample)0.5));
			t_sample add_7263 = (sah_7281 + wrap_7275);
			t_sample switch_7266 = (gte_75 ? add_7263 : ((int)-1));
			int index_trunc_103 = fixnan(floor(switch_7266));
			bool index_ignore_104 = ((index_trunc_103 >= segments_dim) || (index_trunc_103 < 0));
			// samples segments channel 1;
			t_sample sample_segments_7269 = (index_ignore_104 ? 0 : m_segments_34.read(index_trunc_103, 0));
			t_sample index_segments_7270 = switch_7266;
			t_sample mul_7260 = (sample_segments_7269 * expr_7282);
			t_sample mul_382 = ((((mul_7260 + mul_7212) + mul_7140) + mul_7116) * ((t_sample)0.7));
			t_sample mul_80 = (((((mul_292 + mul_290) + mul_294) + mul_296) + mul_382) * scale_8462);
			t_sample dcblock_46 = __m_dcblock_105(mul_80);
			t_sample mul_49 = (sqrt_3330 * dcblock_46);
			t_sample out2 = ((mul_3331 + mul_49) + gate_429);
			t_sample mul_81 = (((((mul_293 + mul_291) + mul_295) + mul_297) + mul_382) * scale_8462);
			t_sample dcblock_47 = __m_dcblock_106(mul_81);
			t_sample mul_50 = (sqrt_3330 * dcblock_47);
			t_sample out1 = ((mul_3331 + mul_50) + gate_429);
			t_sample history_412_next_8380 = fixdenorm(eq_413);
			m_history_26 = history_425_next_427;
			m_history_25 = history_57_next_59;
			m_history_23 = history_53_next_61;
			m_history_24 = history_55_next_60;
			m_history_22 = history_57_next_8337;
			m_history_20 = history_53_next_8342;
			m_history_21 = history_55_next_8334;
			m_history_19 = history_57_next_8349;
			m_history_17 = history_53_next_8346;
			m_history_18 = history_55_next_8347;
			m_delay_16.write(mul_37);
			m_delay_15.write(mul_26);
			m_delay_14.write(mul_15);
			m_delay_13.write(mul_4);
			m_delay_12.write(tap_93);
			m_delay_11.write(tap_91);
			m_delay_10.write(tap_97);
			m_delay_9.write(tap_95);
			m_history_8 = history_57_next_8369;
			m_history_6 = history_53_next_8367;
			m_history_7 = history_55_next_8368;
			m_history_5 = history_40_next_43;
			m_history_4 = history_29_next_32;
			m_history_3 = history_18_next_21;
			m_history_2 = history_7_next_10;
			m_history_1 = history_412_next_8380;
			m_delay_9.step();
			m_delay_10.step();
			m_delay_11.step();
			m_delay_12.step();
			m_delay_13.step();
			m_delay_14.step();
			m_delay_15.step();
			m_delay_16.step();
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
	inline void set_sw2(t_param _value) {
		m_sw_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_density(t_param _value) {
		m_knob6_density_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_rate(t_param _value) {
		m_knob3_rate_31 = (_value < 0.01 ? 0.01 : (_value > 16 ? 16 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_glitchlen(t_param _value) {
		m_knob5_glitchlen_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_segments(void * _value) {
		m_segments_34.setbuffer(_value);
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
int num_params() { return 8; }

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
		case 1: self->set_knob3_rate(value); break;
		case 2: self->set_knob4_buflen(value); break;
		case 3: self->set_knob5_glitchlen(value); break;
		case 4: self->set_knob6_density(value); break;
		case 5: self->set_segments(ref); break;
		case 6: self->set_sw1(value); break;
		case 7: self->set_sw2(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_wetdry_32; break;
		case 1: *value = self->m_knob3_rate_31; break;
		case 2: *value = self->m_knob4_buflen_30; break;
		case 3: *value = self->m_knob5_glitchlen_33; break;
		case 4: *value = self->m_knob6_density_29; break;
		
		case 6: *value = self->m_sw_28; break;
		case 7: *value = self->m_sw_27; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(8 * sizeof(ParamInfo));
	self->__commonstate.numparams = 8;
	// initialize parameter 0 ("m_knob1_wetdry_32")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_rate_31")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_rate_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_buflen_30")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_buflen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_buflen_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_glitchlen_33")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_glitchlen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_glitchlen_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_density_29")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_density";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_density_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_segments_34")
	pi = self->__commonstate.params + 5;
	pi->name = "segments";
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
	// initialize parameter 6 ("m_sw_28")
	pi = self->__commonstate.params + 6;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_sw_27")
	pi = self->__commonstate.params + 7;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_27;
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


} // Glitch2::
