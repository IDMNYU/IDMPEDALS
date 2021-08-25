#include "Glitch.h"

namespace Glitch {

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
	Change __m_change_97;
	Change __m_change_91;
	Change __m_change_79;
	Change __m_change_85;
	DCBlock __m_dcblock_104;
	DCBlock __m_dcblock_103;
	Data m_segments_30;
	Delay m_delay_12;
	Delay m_delay_10;
	Delay m_delay_11;
	Delay m_delay_8;
	Delay m_delay_9;
	Delay m_delay_6;
	Delay m_delay_5;
	Delay m_delay_7;
	PlusEquals __m_pluseq_69;
	PlusEquals __m_pluseq_49;
	PlusEquals __m_pluseq_74;
	PlusEquals __m_pluseq_59;
	PlusEquals __m_pluseq_33;
	PlusEquals __m_pluseq_64;
	PlusEquals __m_pluseq_44;
	PlusEquals __m_pluseq_39;
	PlusEquals __m_pluseq_80;
	PlusEquals __m_pluseq_54;
	PlusEquals __m_pluseq_92;
	PlusEquals __m_pluseq_98;
	PlusEquals __m_pluseq_86;
	Sah __m_sah_99;
	Sah __m_sah_94;
	Sah __m_sah_61;
	Sah __m_sah_100;
	Sah __m_sah_56;
	Sah __m_sah_60;
	Sah __m_sah_93;
	Sah __m_sah_55;
	Sah __m_sah_76;
	Sah __m_sah_65;
	Sah __m_sah_82;
	Sah __m_sah_75;
	Sah __m_sah_88;
	Sah __m_sah_71;
	Sah __m_sah_66;
	Sah __m_sah_70;
	Sah __m_sah_87;
	Sah __m_sah_81;
	Sah __m_sah_41;
	Sah __m_sah_50;
	Sah __m_sah_31;
	Sah __m_sah_45;
	Sah __m_sah_40;
	Sah __m_sah_51;
	Sah __m_sah_46;
	int vectorsize;
	int __exception;
	t_sample m_sw_27;
	t_sample m_history_4;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_3;
	t_sample m_history_1;
	t_sample m_history_2;
	t_sample __m_slide_36;
	t_sample samplerate;
	t_sample m_knob3_thresh_28;
	t_sample m_history_16;
	t_sample m_history_18;
	t_sample m_knob5_glitchlen_24;
	t_sample m_knob4_buflen_25;
	t_sample m_knob6_density_26;
	t_sample m_history_17;
	t_sample m_sw_23;
	t_sample m_history_21;
	t_sample m_history_22;
	t_sample m_history_19;
	t_sample m_knob1_wetdry_29;
	t_sample m_history_20;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_delay_5.reset("m_delay_5", ((int)4));
		m_delay_6.reset("m_delay_6", ((int)3));
		m_delay_7.reset("m_delay_7", ((int)7));
		m_delay_8.reset("m_delay_8", ((int)5));
		m_delay_9.reset("m_delay_9", ((int)5));
		m_delay_10.reset("m_delay_10", ((int)3));
		m_delay_11.reset("m_delay_11", ((int)9));
		m_delay_12.reset("m_delay_12", ((int)2));
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_sw_23 = ((int)0);
		m_knob5_glitchlen_24 = ((int)0);
		m_knob4_buflen_25 = ((int)0);
		m_knob6_density_26 = ((int)0);
		m_sw_27 = ((int)0);
		m_knob3_thresh_28 = ((int)0);
		m_knob1_wetdry_29 = ((int)0);
		m_segments_30.reset("segments", ((int)480000), ((int)1));
		__m_sah_31.reset(0);
		__m_pluseq_33.reset(0);
		__m_slide_36 = 0;
		__m_pluseq_39.reset(0);
		__m_sah_40.reset(0);
		__m_sah_41.reset(0);
		__m_pluseq_44.reset(0);
		__m_sah_45.reset(0);
		__m_sah_46.reset(0);
		__m_pluseq_49.reset(0);
		__m_sah_50.reset(0);
		__m_sah_51.reset(0);
		__m_pluseq_54.reset(0);
		__m_sah_55.reset(0);
		__m_sah_56.reset(0);
		__m_pluseq_59.reset(0);
		__m_sah_60.reset(0);
		__m_sah_61.reset(0);
		__m_pluseq_64.reset(0);
		__m_sah_65.reset(0);
		__m_sah_66.reset(0);
		__m_pluseq_69.reset(0);
		__m_sah_70.reset(0);
		__m_sah_71.reset(0);
		__m_pluseq_74.reset(0);
		__m_sah_75.reset(0);
		__m_sah_76.reset(0);
		__m_change_79.reset(0);
		__m_pluseq_80.reset(0);
		__m_sah_81.reset(0);
		__m_sah_82.reset(0);
		__m_change_85.reset(0);
		__m_pluseq_86.reset(0);
		__m_sah_87.reset(0);
		__m_sah_88.reset(0);
		__m_change_91.reset(0);
		__m_pluseq_92.reset(0);
		__m_sah_93.reset(0);
		__m_sah_94.reset(0);
		__m_change_97.reset(0);
		__m_pluseq_98.reset(0);
		__m_sah_99.reset(0);
		__m_sah_100.reset(0);
		__m_dcblock_103.reset();
		__m_dcblock_104.reset();
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
		int segments_dim = m_segments_30.dim;
		int segments_channels = m_segments_30.channels;
		t_sample mstosamps_374 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_372 = (((int)100) * (samplerate * 0.001));
		t_sample iup_37 = (1 / maximum(1, abs(mstosamps_374)));
		t_sample idown_38 = (1 / maximum(1, abs(mstosamps_372)));
		t_sample mul_320 = (m_knob3_thresh_28 * ((t_sample)0.95));
		t_sample mul_319 = (m_knob3_thresh_28 * ((t_sample)1.03));
		t_sample mul_318 = (m_knob3_thresh_28 * ((t_sample)0.98));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_380 = __m_sah_31(m_history_22, m_sw_27, ((int)0));
			t_sample gen_382 = sah_380;
			t_sample rsub_378 = (((int)1) - sah_380);
			t_sample history_379_next_381 = fixdenorm(rsub_378);
			t_sample out3 = gen_382;
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample mix_6495 = (m_history_21 + (((t_sample)0.0042742627044161) * (m_knob4_buflen_25 - m_history_21)));
			t_sample mix_237 = mix_6495;
			t_sample mix_6496 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_237 - m_history_20)));
			t_sample mix_235 = mix_6496;
			t_sample mix_6497 = (m_history_19 + (((t_sample)0.0042742627044161) * (mix_235 - m_history_19)));
			t_sample mix_233 = mix_6497;
			t_sample gen_358 = mix_233;
			t_sample history_238_next_240 = fixdenorm(mix_237);
			t_sample history_236_next_241 = fixdenorm(mix_235);
			t_sample history_234_next_242 = fixdenorm(mix_233);
			t_sample expr_6374 = (((int)1) - sqrt((((int)1) - gen_358)));
			t_sample add_385 = (gen_382 + ((int)1));
			t_sample choice_32 = int(add_385);
			t_sample gate_383 = (((choice_32 >= 1) && (choice_32 < 2)) ? in1 : 0);
			t_sample gate_384 = ((choice_32 >= 2) ? in1 : 0);
			t_sample mix_6498 = (m_history_18 + (((t_sample)0.0042742627044161) * (m_knob1_wetdry_29 - m_history_18)));
			t_sample mix_6383 = mix_6498;
			t_sample mix_6499 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_6383 - m_history_17)));
			t_sample mix_6379 = mix_6499;
			t_sample mix_6500 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_6379 - m_history_16)));
			t_sample mix_6376 = mix_6500;
			t_sample gen_2159 = mix_6376;
			t_sample history_238_next_6382 = fixdenorm(mix_6383);
			t_sample history_236_next_6381 = fixdenorm(mix_6379);
			t_sample history_234_next_6378 = fixdenorm(mix_6376);
			t_sample sqrt_3380 = sqrt(gen_2159);
			t_sample rsub_1923 = (((int)1) - gen_2159);
			t_sample sqrt_2080 = sqrt(rsub_1923);
			t_sample mul_2550 = (sqrt_2080 * gate_384);
			t_sample mul_903 = (expr_6374 * ((int)480000));
			t_sample plusequals_376 = __m_pluseq_33.post(((int)1), m_history_1, 0);
			t_sample switch_356 = (m_sw_23 ? ((int)-1) : plusequals_376);
			int index_trunc_34 = fixnan(floor(switch_356));
			bool index_ignore_35 = ((index_trunc_34 >= segments_dim) || (index_trunc_34 < 0));
			if ((!index_ignore_35)) {
				m_segments_30.write(gate_384, index_trunc_34, 0);
				
			};
			int gte_362 = (plusequals_376 >= mul_903);
			int eq_361 = (gte_362 == ((int)1));
			t_sample abs_377 = fabs(gate_384);
			t_sample mul_586 = (abs_377 * ((int)30));
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_586 > __m_slide_36) ? iup_37 : idown_38) * (mul_586 - __m_slide_36))));
			t_sample slide_375 = __m_slide_36;
			t_sample clamp_370 = ((slide_375 <= ((int)0)) ? ((int)0) : ((slide_375 >= ((int)1)) ? ((int)1) : slide_375));
			t_sample out4 = clamp_370;
			t_sample mix_6501 = (m_history_15 + (((t_sample)0.0042742627044161) * (m_knob6_density_26 - m_history_15)));
			t_sample mix_6389 = mix_6501;
			t_sample mix_6502 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_6389 - m_history_14)));
			t_sample mix_6397 = mix_6502;
			t_sample mix_6503 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_6397 - m_history_13)));
			t_sample mix_6390 = mix_6503;
			t_sample gen_243 = mix_6390;
			t_sample history_238_next_6394 = fixdenorm(mix_6389);
			t_sample history_236_next_6396 = fixdenorm(mix_6397);
			t_sample history_234_next_6388 = fixdenorm(mix_6390);
			t_sample sub_6507 = (gen_243 - ((int)0));
			t_sample scale_6504 = ((safepow((sub_6507 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_24 = m_delay_12.read_step(((int)8));
			t_sample tap_22 = m_delay_11.read_step(((int)9));
			t_sample tap_20 = m_delay_10.read_step(((int)8));
			t_sample tap_18 = m_delay_9.read_step(((int)8));
			t_sample tap_28 = m_delay_8.read_step(((int)8));
			t_sample tap_26 = m_delay_7.read_step(((int)8));
			t_sample tap_32 = m_delay_6.read_step(((int)8));
			t_sample tap_30 = m_delay_5.read_step(((int)8));
			t_sample mul_14 = (gen_243 * ((int)12));
			int gte_5 = (mul_14 >= ((int)8));
			int gte_4 = (mul_14 >= ((int)9));
			int gte_3 = (mul_14 >= ((int)10));
			int gte_2 = (mul_14 >= ((int)11));
			int gte_7 = (mul_14 >= ((int)6));
			int gte_6 = (mul_14 >= ((int)7));
			int gte_9 = (mul_14 >= ((int)4));
			int gte_8 = (mul_14 >= ((int)5));
			int gte_13 = (mul_14 >= ((int)0));
			int gte_12 = (mul_14 >= ((int)1));
			int gte_11 = (mul_14 >= ((int)2));
			int gte_10 = (mul_14 >= ((int)3));
			t_sample mix_6508 = (m_history_4 + (((t_sample)0.0042742627044161) * (m_knob5_glitchlen_24 - m_history_4)));
			t_sample mix_6409 = mix_6508;
			t_sample mix_6509 = (m_history_3 + (((t_sample)0.0042742627044161) * (mix_6409 - m_history_3)));
			t_sample mix_6410 = mix_6509;
			t_sample mix_6510 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_6410 - m_history_2)));
			t_sample mix_6411 = mix_6510;
			t_sample gen_245 = mix_6411;
			t_sample history_238_next_6418 = fixdenorm(mix_6409);
			t_sample history_236_next_6417 = fixdenorm(mix_6410);
			t_sample history_234_next_6415 = fixdenorm(mix_6411);
			t_sample mul_4728 = (mul_903 * gen_245);
			t_sample clamp_5020 = ((mul_4728 <= ((int)50)) ? ((int)50) : ((mul_4728 >= ((int)480000)) ? ((int)480000) : mul_4728));
			t_sample plusequals_6247 = __m_pluseq_39.post(((int)1), tap_24, 0);
			t_sample noise_6242 = noise();
			t_sample abs_6241 = fabs(noise_6242);
			t_sample sub_6233 = (clamp_5020 - ((int)50));
			t_sample mul_6240 = (abs_6241 * sub_6233);
			t_sample sah_6243 = __m_sah_40(mul_6240, tap_24, ((t_sample)0.5));
			t_sample add_6230 = (sah_6243 + ((int)50));
			t_sample mod_6239 = safemod(plusequals_6247, add_6230);
			t_sample div_6236 = safediv(mod_6239, add_6230);
			t_sample expr_6252 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_6236))));
			t_sample noise_6250 = noise();
			t_sample abs_6249 = fabs(noise_6250);
			t_sample mul_6248 = (abs_6249 * mul_903);
			t_sample sah_6251 = __m_sah_41(mul_6248, tap_24, ((t_sample)0.5));
			t_sample add_6245 = (sah_6251 + mod_6239);
			t_sample mod_6244 = safemod(add_6245, mul_903);
			t_sample switch_6231 = (gte_5 ? mod_6244 : ((int)-1));
			int index_trunc_42 = fixnan(floor(switch_6231));
			bool index_ignore_43 = ((index_trunc_42 >= segments_dim) || (index_trunc_42 < 0));
			// samples segments channel 1;
			t_sample sample_segments_6237 = (index_ignore_43 ? 0 : m_segments_30.read(index_trunc_42, 0));
			t_sample index_segments_6238 = switch_6231;
			t_sample mul_6234 = (sample_segments_6237 * expr_6252);
			t_sample plusequals_6271 = __m_pluseq_44.post(((int)1), tap_22, 0);
			t_sample noise_6266 = noise();
			t_sample abs_6265 = fabs(noise_6266);
			t_sample sub_6257 = (clamp_5020 - ((int)50));
			t_sample mul_6264 = (abs_6265 * sub_6257);
			t_sample sah_6267 = __m_sah_45(mul_6264, tap_22, ((t_sample)0.5));
			t_sample add_6254 = (sah_6267 + ((int)50));
			t_sample mod_6263 = safemod(plusequals_6271, add_6254);
			t_sample div_6260 = safediv(mod_6263, add_6254);
			t_sample expr_6276 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_6260))));
			t_sample noise_6274 = noise();
			t_sample abs_6273 = fabs(noise_6274);
			t_sample mul_6272 = (abs_6273 * mul_903);
			t_sample sah_6275 = __m_sah_46(mul_6272, tap_22, ((t_sample)0.5));
			t_sample add_6269 = (sah_6275 + mod_6263);
			t_sample mod_6268 = safemod(add_6269, mul_903);
			t_sample switch_6255 = (gte_4 ? mod_6268 : ((int)-1));
			int index_trunc_47 = fixnan(floor(switch_6255));
			bool index_ignore_48 = ((index_trunc_47 >= segments_dim) || (index_trunc_47 < 0));
			// samples segments channel 1;
			t_sample sample_segments_6261 = (index_ignore_48 ? 0 : m_segments_30.read(index_trunc_47, 0));
			t_sample index_segments_6262 = switch_6255;
			t_sample mul_6258 = (sample_segments_6261 * expr_6276);
			t_sample mul_227 = ((mul_6258 + mul_6234) * ((t_sample)0.5));
			t_sample mul_228 = ((mul_6258 + mul_6234) * ((t_sample)0.2));
			t_sample plusequals_6295 = __m_pluseq_49.post(((int)1), tap_20, 0);
			t_sample noise_6290 = noise();
			t_sample abs_6289 = fabs(noise_6290);
			t_sample sub_6281 = (clamp_5020 - ((int)50));
			t_sample mul_6288 = (abs_6289 * sub_6281);
			t_sample sah_6291 = __m_sah_50(mul_6288, tap_20, ((t_sample)0.5));
			t_sample add_6278 = (sah_6291 + ((int)50));
			t_sample mod_6287 = safemod(plusequals_6295, add_6278);
			t_sample div_6284 = safediv(mod_6287, add_6278);
			t_sample expr_6300 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_6284))));
			t_sample noise_6298 = noise();
			t_sample abs_6297 = fabs(noise_6298);
			t_sample mul_6296 = (abs_6297 * mul_903);
			t_sample sah_6299 = __m_sah_51(mul_6296, tap_20, ((t_sample)0.5));
			t_sample add_6293 = (sah_6299 + mod_6287);
			t_sample mod_6292 = safemod(add_6293, mul_903);
			t_sample switch_6279 = (gte_3 ? mod_6292 : ((int)-1));
			int index_trunc_52 = fixnan(floor(switch_6279));
			bool index_ignore_53 = ((index_trunc_52 >= segments_dim) || (index_trunc_52 < 0));
			// samples segments channel 1;
			t_sample sample_segments_6285 = (index_ignore_53 ? 0 : m_segments_30.read(index_trunc_52, 0));
			t_sample index_segments_6286 = switch_6279;
			t_sample mul_6282 = (sample_segments_6285 * expr_6300);
			t_sample plusequals_6367 = __m_pluseq_54.post(((int)1), tap_18, 0);
			t_sample noise_6362 = noise();
			t_sample abs_6361 = fabs(noise_6362);
			t_sample sub_6353 = (clamp_5020 - ((int)50));
			t_sample mul_6360 = (abs_6361 * sub_6353);
			t_sample sah_6363 = __m_sah_55(mul_6360, tap_18, ((t_sample)0.5));
			t_sample add_6350 = (sah_6363 + ((int)50));
			t_sample mod_6359 = safemod(plusequals_6367, add_6350);
			t_sample div_6356 = safediv(mod_6359, add_6350);
			t_sample expr_6372 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_6356))));
			t_sample noise_6370 = noise();
			t_sample abs_6369 = fabs(noise_6370);
			t_sample mul_6368 = (abs_6369 * mul_903);
			t_sample sah_6371 = __m_sah_56(mul_6368, tap_18, ((t_sample)0.5));
			t_sample add_6365 = (sah_6371 + mod_6359);
			t_sample mod_6364 = safemod(add_6365, mul_903);
			t_sample switch_6351 = (gte_2 ? mod_6364 : ((int)-1));
			int index_trunc_57 = fixnan(floor(switch_6351));
			bool index_ignore_58 = ((index_trunc_57 >= segments_dim) || (index_trunc_57 < 0));
			// samples segments channel 1;
			t_sample sample_segments_6357 = (index_ignore_58 ? 0 : m_segments_30.read(index_trunc_57, 0));
			t_sample index_segments_6358 = switch_6351;
			t_sample mul_6354 = (sample_segments_6357 * expr_6372);
			t_sample mul_225 = ((mul_6354 + mul_6282) * ((t_sample)0.2));
			t_sample mul_226 = ((mul_6354 + mul_6282) * ((t_sample)0.5));
			t_sample plusequals_6223 = __m_pluseq_59.post(((int)1), tap_28, 0);
			t_sample noise_6218 = noise();
			t_sample abs_6217 = fabs(noise_6218);
			t_sample sub_6209 = (clamp_5020 - ((int)50));
			t_sample mul_6216 = (abs_6217 * sub_6209);
			t_sample sah_6219 = __m_sah_60(mul_6216, tap_28, ((t_sample)0.5));
			t_sample add_6206 = (sah_6219 + ((int)50));
			t_sample mod_6215 = safemod(plusequals_6223, add_6206);
			t_sample div_6212 = safediv(mod_6215, add_6206);
			t_sample expr_6228 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_6212))));
			t_sample noise_6226 = noise();
			t_sample abs_6225 = fabs(noise_6226);
			t_sample mul_6224 = (abs_6225 * mul_903);
			t_sample sah_6227 = __m_sah_61(mul_6224, tap_28, ((t_sample)0.5));
			t_sample add_6221 = (sah_6227 + mod_6215);
			t_sample mod_6220 = safemod(add_6221, mul_903);
			t_sample switch_6207 = (gte_7 ? mod_6220 : ((int)-1));
			int index_trunc_62 = fixnan(floor(switch_6207));
			bool index_ignore_63 = ((index_trunc_62 >= segments_dim) || (index_trunc_62 < 0));
			// samples segments channel 1;
			t_sample sample_segments_6213 = (index_ignore_63 ? 0 : m_segments_30.read(index_trunc_62, 0));
			t_sample index_segments_6214 = switch_6207;
			t_sample mul_6210 = (sample_segments_6213 * expr_6228);
			t_sample plusequals_6343 = __m_pluseq_64.post(((int)1), tap_26, 0);
			t_sample noise_6338 = noise();
			t_sample abs_6337 = fabs(noise_6338);
			t_sample sub_6329 = (clamp_5020 - ((int)50));
			t_sample mul_6336 = (abs_6337 * sub_6329);
			t_sample sah_6339 = __m_sah_65(mul_6336, tap_26, ((t_sample)0.5));
			t_sample add_6326 = (sah_6339 + ((int)50));
			t_sample mod_6335 = safemod(plusequals_6343, add_6326);
			t_sample div_6332 = safediv(mod_6335, add_6326);
			t_sample expr_6348 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_6332))));
			t_sample noise_6346 = noise();
			t_sample abs_6345 = fabs(noise_6346);
			t_sample mul_6344 = (abs_6345 * mul_903);
			t_sample sah_6347 = __m_sah_66(mul_6344, tap_26, ((t_sample)0.5));
			t_sample add_6341 = (sah_6347 + mod_6335);
			t_sample mod_6340 = safemod(add_6341, mul_903);
			t_sample switch_6327 = (gte_6 ? mod_6340 : ((int)-1));
			int index_trunc_67 = fixnan(floor(switch_6327));
			bool index_ignore_68 = ((index_trunc_67 >= segments_dim) || (index_trunc_67 < 0));
			// samples segments channel 1;
			t_sample sample_segments_6333 = (index_ignore_68 ? 0 : m_segments_30.read(index_trunc_67, 0));
			t_sample index_segments_6334 = switch_6327;
			t_sample mul_6330 = (sample_segments_6333 * expr_6348);
			t_sample mul_229 = ((mul_6330 + mul_6210) * ((t_sample)0.3));
			t_sample mul_230 = ((mul_6330 + mul_6210) * ((t_sample)0.4));
			t_sample plusequals_6151 = __m_pluseq_69.post(((int)1), tap_32, 0);
			t_sample noise_6146 = noise();
			t_sample abs_6145 = fabs(noise_6146);
			t_sample sub_6137 = (clamp_5020 - ((int)50));
			t_sample mul_6144 = (abs_6145 * sub_6137);
			t_sample sah_6147 = __m_sah_70(mul_6144, tap_32, ((t_sample)0.5));
			t_sample add_6134 = (sah_6147 + ((int)50));
			t_sample mod_6143 = safemod(plusequals_6151, add_6134);
			t_sample div_6140 = safediv(mod_6143, add_6134);
			t_sample expr_6156 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_6140))));
			t_sample noise_6154 = noise();
			t_sample abs_6153 = fabs(noise_6154);
			t_sample mul_6152 = (abs_6153 * mul_903);
			t_sample sah_6155 = __m_sah_71(mul_6152, tap_32, ((t_sample)0.5));
			t_sample add_6149 = (sah_6155 + mod_6143);
			t_sample mod_6148 = safemod(add_6149, mul_903);
			t_sample switch_6135 = (gte_9 ? mod_6148 : ((int)-1));
			int index_trunc_72 = fixnan(floor(switch_6135));
			bool index_ignore_73 = ((index_trunc_72 >= segments_dim) || (index_trunc_72 < 0));
			// samples segments channel 1;
			t_sample sample_segments_6141 = (index_ignore_73 ? 0 : m_segments_30.read(index_trunc_72, 0));
			t_sample index_segments_6142 = switch_6135;
			t_sample mul_6138 = (sample_segments_6141 * expr_6156);
			t_sample plusequals_6175 = __m_pluseq_74.post(((int)1), tap_30, 0);
			t_sample noise_6170 = noise();
			t_sample abs_6169 = fabs(noise_6170);
			t_sample sub_6161 = (clamp_5020 - ((int)50));
			t_sample mul_6168 = (abs_6169 * sub_6161);
			t_sample sah_6171 = __m_sah_75(mul_6168, tap_30, ((t_sample)0.5));
			t_sample add_6158 = (sah_6171 + ((int)50));
			t_sample mod_6167 = safemod(plusequals_6175, add_6158);
			t_sample div_6164 = safediv(mod_6167, add_6158);
			t_sample expr_6180 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_6164))));
			t_sample noise_6178 = noise();
			t_sample abs_6177 = fabs(noise_6178);
			t_sample mul_6176 = (abs_6177 * mul_903);
			t_sample sah_6179 = __m_sah_76(mul_6176, tap_30, ((t_sample)0.5));
			t_sample add_6173 = (sah_6179 + mod_6167);
			t_sample mod_6172 = safemod(add_6173, mul_903);
			t_sample switch_6159 = (gte_8 ? mod_6172 : ((int)-1));
			int index_trunc_77 = fixnan(floor(switch_6159));
			bool index_ignore_78 = ((index_trunc_77 >= segments_dim) || (index_trunc_77 < 0));
			// samples segments channel 1;
			t_sample sample_segments_6165 = (index_ignore_78 ? 0 : m_segments_30.read(index_trunc_77, 0));
			t_sample index_segments_6166 = switch_6159;
			t_sample mul_6162 = (sample_segments_6165 * expr_6180);
			t_sample mul_231 = ((mul_6162 + mul_6138) * ((t_sample)0.4));
			t_sample mul_232 = ((mul_6162 + mul_6138) * ((t_sample)0.3));
			int gt_367 = (clamp_370 > m_knob3_thresh_28);
			int change_366 = __m_change_79(gt_367);
			int eq_365 = (change_366 == ((int)1));
			int plusequals_6103 = __m_pluseq_80.post(((int)1), eq_365, 0);
			t_sample noise_6098 = noise();
			t_sample abs_6097 = fabs(noise_6098);
			t_sample sub_6089 = (clamp_5020 - ((int)50));
			t_sample mul_6096 = (abs_6097 * sub_6089);
			t_sample sah_6099 = __m_sah_81(mul_6096, eq_365, ((t_sample)0.5));
			t_sample add_6086 = (sah_6099 + ((int)50));
			t_sample mod_6095 = safemod(plusequals_6103, add_6086);
			t_sample div_6092 = safediv(mod_6095, add_6086);
			t_sample expr_6108 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_6092))));
			t_sample noise_6106 = noise();
			t_sample abs_6105 = fabs(noise_6106);
			t_sample mul_6104 = (abs_6105 * mul_903);
			t_sample sah_6107 = __m_sah_82(mul_6104, eq_365, ((t_sample)0.5));
			t_sample add_6101 = (sah_6107 + mod_6095);
			t_sample mod_6100 = safemod(add_6101, mul_903);
			t_sample switch_6087 = (gte_13 ? mod_6100 : ((int)-1));
			int index_trunc_83 = fixnan(floor(switch_6087));
			bool index_ignore_84 = ((index_trunc_83 >= segments_dim) || (index_trunc_83 < 0));
			// samples segments channel 1;
			t_sample sample_segments_6093 = (index_ignore_84 ? 0 : m_segments_30.read(index_trunc_83, 0));
			t_sample index_segments_6094 = switch_6087;
			t_sample mul_6090 = (sample_segments_6093 * expr_6108);
			int gt_329 = (clamp_370 > mul_320);
			int change_328 = __m_change_85(gt_329);
			int eq_327 = (change_328 == ((int)1));
			int plusequals_6127 = __m_pluseq_86.post(((int)1), eq_327, 0);
			t_sample noise_6122 = noise();
			t_sample abs_6121 = fabs(noise_6122);
			t_sample sub_6113 = (clamp_5020 - ((int)50));
			t_sample mul_6120 = (abs_6121 * sub_6113);
			t_sample sah_6123 = __m_sah_87(mul_6120, eq_327, ((t_sample)0.5));
			t_sample add_6110 = (sah_6123 + ((int)50));
			t_sample mod_6119 = safemod(plusequals_6127, add_6110);
			t_sample div_6116 = safediv(mod_6119, add_6110);
			t_sample expr_6132 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_6116))));
			t_sample noise_6130 = noise();
			t_sample abs_6129 = fabs(noise_6130);
			t_sample mul_6128 = (abs_6129 * mul_903);
			t_sample sah_6131 = __m_sah_88(mul_6128, eq_327, ((t_sample)0.5));
			t_sample add_6125 = (sah_6131 + mod_6119);
			t_sample mod_6124 = safemod(add_6125, mul_903);
			t_sample switch_6111 = (gte_12 ? mod_6124 : ((int)-1));
			int index_trunc_89 = fixnan(floor(switch_6111));
			bool index_ignore_90 = ((index_trunc_89 >= segments_dim) || (index_trunc_89 < 0));
			// samples segments channel 1;
			t_sample sample_segments_6117 = (index_ignore_90 ? 0 : m_segments_30.read(index_trunc_89, 0));
			t_sample index_segments_6118 = switch_6111;
			t_sample mul_6114 = (sample_segments_6117 * expr_6132);
			int gt_326 = (clamp_370 > mul_319);
			int change_325 = __m_change_91(gt_326);
			int eq_324 = (change_325 == ((int)1));
			int plusequals_6199 = __m_pluseq_92.post(((int)1), eq_324, 0);
			t_sample noise_6194 = noise();
			t_sample abs_6193 = fabs(noise_6194);
			t_sample sub_6185 = (clamp_5020 - ((int)50));
			t_sample mul_6192 = (abs_6193 * sub_6185);
			t_sample sah_6195 = __m_sah_93(mul_6192, eq_324, ((t_sample)0.5));
			t_sample add_6182 = (sah_6195 + ((int)50));
			t_sample mod_6191 = safemod(plusequals_6199, add_6182);
			t_sample div_6188 = safediv(mod_6191, add_6182);
			t_sample expr_6204 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_6188))));
			t_sample noise_6202 = noise();
			t_sample abs_6201 = fabs(noise_6202);
			t_sample mul_6200 = (abs_6201 * mul_903);
			t_sample sah_6203 = __m_sah_94(mul_6200, eq_324, ((t_sample)0.5));
			t_sample add_6197 = (sah_6203 + mod_6191);
			t_sample mod_6196 = safemod(add_6197, mul_903);
			t_sample switch_6183 = (gte_11 ? mod_6196 : ((int)-1));
			int index_trunc_95 = fixnan(floor(switch_6183));
			bool index_ignore_96 = ((index_trunc_95 >= segments_dim) || (index_trunc_95 < 0));
			// samples segments channel 1;
			t_sample sample_segments_6189 = (index_ignore_96 ? 0 : m_segments_30.read(index_trunc_95, 0));
			t_sample index_segments_6190 = switch_6183;
			t_sample mul_6186 = (sample_segments_6189 * expr_6204);
			int gt_323 = (clamp_370 > mul_318);
			int change_322 = __m_change_97(gt_323);
			int eq_321 = (change_322 == ((int)1));
			int plusequals_6319 = __m_pluseq_98.post(((int)1), eq_321, 0);
			t_sample noise_6314 = noise();
			t_sample abs_6313 = fabs(noise_6314);
			t_sample sub_6305 = (clamp_5020 - ((int)50));
			t_sample mul_6312 = (abs_6313 * sub_6305);
			t_sample sah_6315 = __m_sah_99(mul_6312, eq_321, ((t_sample)0.5));
			t_sample add_6302 = (sah_6315 + ((int)50));
			t_sample mod_6311 = safemod(plusequals_6319, add_6302);
			t_sample div_6308 = safediv(mod_6311, add_6302);
			t_sample expr_6324 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_6308))));
			t_sample noise_6322 = noise();
			t_sample abs_6321 = fabs(noise_6322);
			t_sample mul_6320 = (abs_6321 * mul_903);
			t_sample sah_6323 = __m_sah_100(mul_6320, eq_321, ((t_sample)0.5));
			t_sample add_6317 = (sah_6323 + mod_6311);
			t_sample mod_6316 = safemod(add_6317, mul_903);
			t_sample switch_6303 = (gte_10 ? mod_6316 : ((int)-1));
			int index_trunc_101 = fixnan(floor(switch_6303));
			bool index_ignore_102 = ((index_trunc_101 >= segments_dim) || (index_trunc_101 < 0));
			// samples segments channel 1;
			t_sample sample_segments_6309 = (index_ignore_102 ? 0 : m_segments_30.read(index_trunc_101, 0));
			t_sample index_segments_6310 = switch_6303;
			t_sample mul_6306 = (sample_segments_6309 * expr_6324);
			t_sample mul_330 = ((((mul_6306 + mul_6186) + mul_6114) + mul_6090) * ((t_sample)0.7));
			t_sample mul_1186 = (((((mul_330 + mul_231) + mul_229) + mul_225) + mul_227) * scale_6504);
			t_sample dcblock_4088 = __m_dcblock_103(mul_1186);
			t_sample mul_3103 = (sqrt_3380 * dcblock_4088);
			t_sample out2 = ((mul_3103 + mul_2550) + gate_383);
			t_sample mul_1115 = (((((mul_330 + mul_232) + mul_230) + mul_226) + mul_228) * scale_6504);
			t_sample dcblock_3769 = __m_dcblock_104(mul_1115);
			t_sample mul_3104 = (sqrt_3380 * dcblock_3769);
			t_sample out1 = ((mul_3104 + mul_2550) + gate_383);
			t_sample history_360_next_6422 = fixdenorm(eq_361);
			m_history_22 = history_379_next_381;
			m_history_21 = history_238_next_240;
			m_history_19 = history_234_next_242;
			m_history_20 = history_236_next_241;
			m_history_18 = history_238_next_6382;
			m_history_16 = history_234_next_6378;
			m_history_17 = history_236_next_6381;
			m_history_15 = history_238_next_6394;
			m_history_13 = history_234_next_6388;
			m_history_14 = history_236_next_6396;
			m_delay_12.write(tap_32);
			m_delay_11.write(tap_30);
			m_delay_10.write(tap_28);
			m_delay_9.write(tap_26);
			m_delay_8.write(eq_324);
			m_delay_7.write(eq_321);
			m_delay_6.write(eq_365);
			m_delay_5.write(eq_327);
			m_history_4 = history_238_next_6418;
			m_history_2 = history_234_next_6415;
			m_history_3 = history_236_next_6417;
			m_history_1 = history_360_next_6422;
			m_delay_5.step();
			m_delay_6.step();
			m_delay_7.step();
			m_delay_8.step();
			m_delay_9.step();
			m_delay_10.step();
			m_delay_11.step();
			m_delay_12.step();
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
		m_sw_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_glitchlen(t_param _value) {
		m_knob5_glitchlen_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_density(t_param _value) {
		m_knob6_density_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_thresh(t_param _value) {
		m_knob3_thresh_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_segments(void * _value) {
		m_segments_30.setbuffer(_value);
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
		case 1: self->set_knob3_thresh(value); break;
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
		case 0: *value = self->m_knob1_wetdry_29; break;
		case 1: *value = self->m_knob3_thresh_28; break;
		case 2: *value = self->m_knob4_buflen_25; break;
		case 3: *value = self->m_knob5_glitchlen_24; break;
		case 4: *value = self->m_knob6_density_26; break;
		
		case 6: *value = self->m_sw_27; break;
		case 7: *value = self->m_sw_23; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_29")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_thresh_28")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_thresh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_thresh_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_buflen_25")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_buflen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_buflen_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_glitchlen_24")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_glitchlen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_glitchlen_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_density_26")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_density";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_density_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_segments_30")
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
	// initialize parameter 6 ("m_sw_27")
	pi = self->__commonstate.params + 6;
	pi->name = "sw1";
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
	// initialize parameter 7 ("m_sw_23")
	pi = self->__commonstate.params + 7;
	pi->name = "sw2";
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


} // Glitch::
