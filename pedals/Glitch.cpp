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
	Change __m_change_89;
	Change __m_change_83;
	Change __m_change_95;
	Change __m_change_101;
	DCBlock __m_dcblock_107;
	DCBlock __m_dcblock_108;
	Data m_segments_34;
	Delay m_delay_11;
	Delay m_delay_13;
	Delay m_delay_12;
	Delay m_delay_15;
	Delay m_delay_16;
	Delay m_delay_10;
	Delay m_delay_14;
	Delay m_delay_9;
	PlusEquals __m_pluseq_53;
	PlusEquals __m_pluseq_58;
	PlusEquals __m_pluseq_48;
	PlusEquals __m_pluseq_102;
	PlusEquals __m_pluseq_37;
	PlusEquals __m_pluseq_63;
	PlusEquals __m_pluseq_96;
	PlusEquals __m_pluseq_73;
	PlusEquals __m_pluseq_68;
	PlusEquals __m_pluseq_90;
	PlusEquals __m_pluseq_78;
	PlusEquals __m_pluseq_84;
	PlusEquals __m_pluseq_43;
	Sah __m_sah_65;
	Sah __m_sah_49;
	Sah __m_sah_50;
	Sah __m_sah_75;
	Sah __m_sah_45;
	Sah __m_sah_44;
	Sah __m_sah_74;
	Sah __m_sah_55;
	Sah __m_sah_60;
	Sah __m_sah_54;
	Sah __m_sah_59;
	Sah __m_sah_70;
	Sah __m_sah_69;
	Sah __m_sah_79;
	Sah __m_sah_85;
	Sah __m_sah_98;
	Sah __m_sah_103;
	Sah __m_sah_104;
	Sah __m_sah_80;
	Sah __m_sah_97;
	Sah __m_sah_91;
	Sah __m_sah_35;
	Sah __m_sah_92;
	Sah __m_sah_86;
	Sah __m_sah_64;
	int vectorsize;
	int __exception;
	t_sample m_history_17;
	t_sample m_history_2;
	t_sample m_history_1;
	t_sample m_sw_32;
	t_sample m_knob6_density_33;
	t_sample m_history_3;
	t_sample m_knob1_wetdry_31;
	t_sample samplerate;
	t_sample m_knob5_glitchlen_27;
	t_sample m_knob3_thresh_30;
	t_sample m_sw_28;
	t_sample m_knob4_buflen_29;
	t_sample m_history_25;
	t_sample m_history_4;
	t_sample m_history_23;
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
	t_sample __m_slide_40;
	t_sample m_history_26;
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
		m_delay_9.reset("m_delay_9", ((int)2));
		m_delay_10.reset("m_delay_10", ((int)9));
		m_delay_11.reset("m_delay_11", ((int)3));
		m_delay_12.reset("m_delay_12", ((int)5));
		m_delay_13.reset("m_delay_13", ((int)5));
		m_delay_14.reset("m_delay_14", ((int)7));
		m_delay_15.reset("m_delay_15", ((int)3));
		m_delay_16.reset("m_delay_16", ((int)4));
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
		m_knob5_glitchlen_27 = ((int)0);
		m_sw_28 = ((int)0);
		m_knob4_buflen_29 = ((int)0);
		m_knob3_thresh_30 = ((int)0);
		m_knob1_wetdry_31 = ((int)0);
		m_sw_32 = ((int)0);
		m_knob6_density_33 = ((int)0);
		m_segments_34.reset("segments", ((int)480000), ((int)1));
		__m_sah_35.reset(0);
		__m_pluseq_37.reset(0);
		__m_slide_40 = 0;
		__m_pluseq_43.reset(0);
		__m_sah_44.reset(0);
		__m_sah_45.reset(0);
		__m_pluseq_48.reset(0);
		__m_sah_49.reset(0);
		__m_sah_50.reset(0);
		__m_pluseq_53.reset(0);
		__m_sah_54.reset(0);
		__m_sah_55.reset(0);
		__m_pluseq_58.reset(0);
		__m_sah_59.reset(0);
		__m_sah_60.reset(0);
		__m_pluseq_63.reset(0);
		__m_sah_64.reset(0);
		__m_sah_65.reset(0);
		__m_pluseq_68.reset(0);
		__m_sah_69.reset(0);
		__m_sah_70.reset(0);
		__m_pluseq_73.reset(0);
		__m_sah_74.reset(0);
		__m_sah_75.reset(0);
		__m_pluseq_78.reset(0);
		__m_sah_79.reset(0);
		__m_sah_80.reset(0);
		__m_change_83.reset(0);
		__m_pluseq_84.reset(0);
		__m_sah_85.reset(0);
		__m_sah_86.reset(0);
		__m_change_89.reset(0);
		__m_pluseq_90.reset(0);
		__m_sah_91.reset(0);
		__m_sah_92.reset(0);
		__m_change_95.reset(0);
		__m_pluseq_96.reset(0);
		__m_sah_97.reset(0);
		__m_sah_98.reset(0);
		__m_change_101.reset(0);
		__m_pluseq_102.reset(0);
		__m_sah_103.reset(0);
		__m_sah_104.reset(0);
		__m_dcblock_107.reset();
		__m_dcblock_108.reset();
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
		t_sample mstosamps_589 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_587 = (((int)100) * (samplerate * 0.001));
		t_sample iup_41 = (1 / maximum(1, abs(mstosamps_589)));
		t_sample idown_42 = (1 / maximum(1, abs(mstosamps_587)));
		t_sample mstosamps_200 = (((int)1) * (samplerate * 0.001));
		t_sample mul_535 = (m_knob3_thresh_30 * ((t_sample)0.95));
		t_sample mstosamps_189 = (((int)1) * (samplerate * 0.001));
		t_sample mul_534 = (m_knob3_thresh_30 * ((t_sample)1.03));
		t_sample mstosamps_178 = (((int)1) * (samplerate * 0.001));
		t_sample mul_533 = (m_knob3_thresh_30 * ((t_sample)0.98));
		t_sample mstosamps_167 = (((int)1) * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_595 = __m_sah_35(m_history_26, m_sw_32, ((int)0));
			t_sample gen_597 = sah_595;
			t_sample rsub_593 = (((int)1) - sah_595);
			t_sample history_594_next_596 = fixdenorm(rsub_593);
			t_sample out3 = gen_597;
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample mix_690 = (m_history_25 + (((t_sample)0.003926980723806) * (m_knob4_buflen_29 - m_history_25)));
			t_sample mix_215 = mix_690;
			t_sample mix_691 = (m_history_24 + (((t_sample)0.003926980723806) * (mix_215 - m_history_24)));
			t_sample mix_213 = mix_691;
			t_sample mix_692 = (m_history_23 + (((t_sample)0.003926980723806) * (mix_213 - m_history_23)));
			t_sample mix_211 = mix_692;
			t_sample gen_573 = mix_211;
			t_sample history_216_next_218 = fixdenorm(mix_215);
			t_sample history_214_next_219 = fixdenorm(mix_213);
			t_sample history_212_next_220 = fixdenorm(mix_211);
			t_sample expr_601 = (((int)1) - sqrt((((int)1) - gen_573)));
			t_sample add_600 = (gen_597 + ((int)1));
			t_sample choice_36 = int(add_600);
			t_sample gate_598 = (((choice_36 >= 1) && (choice_36 < 2)) ? in1 : 0);
			t_sample gate_599 = ((choice_36 >= 2) ? in1 : 0);
			t_sample mix_693 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob1_wetdry_31 - m_history_22)));
			t_sample mix_605 = mix_693;
			t_sample mix_694 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_605 - m_history_21)));
			t_sample mix_610 = mix_694;
			t_sample mix_695 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_610 - m_history_20)));
			t_sample mix_609 = mix_695;
			t_sample gen_221 = mix_609;
			t_sample history_216_next_604 = fixdenorm(mix_605);
			t_sample history_214_next_608 = fixdenorm(mix_610);
			t_sample history_212_next_606 = fixdenorm(mix_609);
			t_sample sqrt_207 = sqrt(gen_221);
			t_sample rsub_223 = (((int)1) - gen_221);
			t_sample sqrt_222 = sqrt(rsub_223);
			t_sample mul_210 = (sqrt_222 * gate_599);
			t_sample mul_574 = (expr_601 * ((int)480000));
			t_sample plusequals_591 = __m_pluseq_37.post(((int)1), m_history_1, 0);
			t_sample switch_571 = (m_sw_28 ? ((int)-1) : plusequals_591);
			int index_trunc_38 = fixnan(floor(switch_571));
			bool index_ignore_39 = ((index_trunc_38 >= segments_dim) || (index_trunc_38 < 0));
			if ((!index_ignore_39)) {
				m_segments_34.write(gate_599, index_trunc_38, 0);
				
			};
			int gte_577 = (plusequals_591 >= mul_574);
			int eq_576 = (gte_577 == ((int)1));
			t_sample abs_592 = fabs(gate_599);
			t_sample mul_225 = (abs_592 * ((int)30));
			__m_slide_40 = fixdenorm((__m_slide_40 + (((mul_225 > __m_slide_40) ? iup_41 : idown_42) * (mul_225 - __m_slide_40))));
			t_sample slide_590 = __m_slide_40;
			t_sample clamp_585 = ((slide_590 <= ((int)0)) ? ((int)0) : ((slide_590 >= ((int)1)) ? ((int)1) : slide_590));
			t_sample out4 = clamp_585;
			t_sample mix_696 = (m_history_19 + (((t_sample)0.003926980723806) * (m_knob6_density_33 - m_history_19)));
			t_sample mix_622 = mix_696;
			t_sample mix_697 = (m_history_18 + (((t_sample)0.003926980723806) * (mix_622 - m_history_18)));
			t_sample mix_615 = mix_697;
			t_sample mix_698 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_615 - m_history_17)));
			t_sample mix_624 = mix_698;
			t_sample gen_458 = mix_624;
			t_sample history_216_next_621 = fixdenorm(mix_622);
			t_sample history_214_next_620 = fixdenorm(mix_615);
			t_sample history_212_next_617 = fixdenorm(mix_624);
			t_sample sub_702 = (gen_458 - ((int)0));
			t_sample scale_699 = ((safepow((sub_702 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_255 = m_delay_16.read_step(((int)8));
			t_sample tap_257 = m_delay_15.read_step(((int)8));
			t_sample tap_251 = m_delay_14.read_step(((int)8));
			t_sample tap_253 = m_delay_13.read_step(((int)8));
			t_sample tap_243 = m_delay_12.read_step(((int)8));
			t_sample tap_245 = m_delay_11.read_step(((int)8));
			t_sample tap_247 = m_delay_10.read_step(((int)9));
			t_sample tap_249 = m_delay_9.read_step(((int)8));
			t_sample mul_239 = (gen_458 * ((int)12));
			int gte_237 = (mul_239 >= ((int)1));
			int gte_236 = (mul_239 >= ((int)2));
			int gte_235 = (mul_239 >= ((int)3));
			int gte_238 = (mul_239 >= ((int)0));
			int gte_233 = (mul_239 >= ((int)5));
			int gte_234 = (mul_239 >= ((int)4));
			int gte_231 = (mul_239 >= ((int)7));
			int gte_232 = (mul_239 >= ((int)6));
			int gte_227 = (mul_239 >= ((int)11));
			int gte_228 = (mul_239 >= ((int)10));
			int gte_229 = (mul_239 >= ((int)9));
			int gte_230 = (mul_239 >= ((int)8));
			t_sample mix_703 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob5_glitchlen_27 - m_history_8)));
			t_sample mix_633 = mix_703;
			t_sample mix_704 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_633 - m_history_7)));
			t_sample mix_628 = mix_704;
			t_sample mix_705 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_628 - m_history_6)));
			t_sample mix_634 = mix_705;
			t_sample gen_460 = mix_634;
			t_sample history_216_next_636 = fixdenorm(mix_633);
			t_sample history_214_next_632 = fixdenorm(mix_628);
			t_sample history_212_next_629 = fixdenorm(mix_634);
			t_sample mul_204 = (mul_574 * gen_460);
			t_sample clamp_459 = ((mul_204 <= ((int)50)) ? ((int)50) : ((mul_204 >= ((int)480000)) ? ((int)480000) : mul_204));
			t_sample plusequals_419 = __m_pluseq_43.post(((int)1), tap_255, 0);
			t_sample noise_414 = noise();
			t_sample abs_413 = fabs(noise_414);
			t_sample sub_405 = (clamp_459 - ((int)50));
			t_sample mul_412 = (abs_413 * sub_405);
			t_sample sah_415 = __m_sah_44(mul_412, tap_255, ((t_sample)0.5));
			t_sample add_402 = (sah_415 + ((int)50));
			t_sample mod_411 = safemod(plusequals_419, add_402);
			t_sample div_408 = safediv(mod_411, add_402);
			t_sample expr_424 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_408))));
			t_sample noise_422 = noise();
			t_sample abs_421 = fabs(noise_422);
			t_sample mul_420 = (abs_421 * mul_574);
			t_sample sah_423 = __m_sah_45(mul_420, tap_255, ((t_sample)0.5));
			t_sample add_417 = (sah_423 + mod_411);
			t_sample mod_416 = safemod(add_417, mul_574);
			t_sample switch_403 = (gte_233 ? mod_416 : ((int)-1));
			int index_trunc_46 = fixnan(floor(switch_403));
			bool index_ignore_47 = ((index_trunc_46 >= segments_dim) || (index_trunc_46 < 0));
			// samples segments channel 1;
			t_sample sample_segments_409 = (index_ignore_47 ? 0 : m_segments_34.read(index_trunc_46, 0));
			t_sample index_segments_410 = switch_403;
			t_sample mul_406 = (sample_segments_409 * expr_424);
			t_sample plusequals_443 = __m_pluseq_48.post(((int)1), tap_257, 0);
			t_sample noise_438 = noise();
			t_sample abs_437 = fabs(noise_438);
			t_sample sub_429 = (clamp_459 - ((int)50));
			t_sample mul_436 = (abs_437 * sub_429);
			t_sample sah_439 = __m_sah_49(mul_436, tap_257, ((t_sample)0.5));
			t_sample add_426 = (sah_439 + ((int)50));
			t_sample mod_435 = safemod(plusequals_443, add_426);
			t_sample div_432 = safediv(mod_435, add_426);
			t_sample expr_448 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_432))));
			t_sample noise_446 = noise();
			t_sample abs_445 = fabs(noise_446);
			t_sample mul_444 = (abs_445 * mul_574);
			t_sample sah_447 = __m_sah_50(mul_444, tap_257, ((t_sample)0.5));
			t_sample add_441 = (sah_447 + mod_435);
			t_sample mod_440 = safemod(add_441, mul_574);
			t_sample switch_427 = (gte_234 ? mod_440 : ((int)-1));
			int index_trunc_51 = fixnan(floor(switch_427));
			bool index_ignore_52 = ((index_trunc_51 >= segments_dim) || (index_trunc_51 < 0));
			// samples segments channel 1;
			t_sample sample_segments_433 = (index_ignore_52 ? 0 : m_segments_34.read(index_trunc_51, 0));
			t_sample index_segments_434 = switch_427;
			t_sample mul_430 = (sample_segments_433 * expr_448);
			t_sample mul_457 = ((mul_430 + mul_406) * ((t_sample)0.3));
			t_sample mul_456 = ((mul_430 + mul_406) * ((t_sample)0.4));
			t_sample plusequals_371 = __m_pluseq_53.post(((int)1), tap_251, 0);
			t_sample noise_366 = noise();
			t_sample abs_365 = fabs(noise_366);
			t_sample sub_357 = (clamp_459 - ((int)50));
			t_sample mul_364 = (abs_365 * sub_357);
			t_sample sah_367 = __m_sah_54(mul_364, tap_251, ((t_sample)0.5));
			t_sample add_354 = (sah_367 + ((int)50));
			t_sample mod_363 = safemod(plusequals_371, add_354);
			t_sample div_360 = safediv(mod_363, add_354);
			t_sample expr_376 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_360))));
			t_sample noise_374 = noise();
			t_sample abs_373 = fabs(noise_374);
			t_sample mul_372 = (abs_373 * mul_574);
			t_sample sah_375 = __m_sah_55(mul_372, tap_251, ((t_sample)0.5));
			t_sample add_369 = (sah_375 + mod_363);
			t_sample mod_368 = safemod(add_369, mul_574);
			t_sample switch_355 = (gte_231 ? mod_368 : ((int)-1));
			int index_trunc_56 = fixnan(floor(switch_355));
			bool index_ignore_57 = ((index_trunc_56 >= segments_dim) || (index_trunc_56 < 0));
			// samples segments channel 1;
			t_sample sample_segments_361 = (index_ignore_57 ? 0 : m_segments_34.read(index_trunc_56, 0));
			t_sample index_segments_362 = switch_355;
			t_sample mul_358 = (sample_segments_361 * expr_376);
			t_sample plusequals_395 = __m_pluseq_58.post(((int)1), tap_253, 0);
			t_sample noise_390 = noise();
			t_sample abs_389 = fabs(noise_390);
			t_sample sub_381 = (clamp_459 - ((int)50));
			t_sample mul_388 = (abs_389 * sub_381);
			t_sample sah_391 = __m_sah_59(mul_388, tap_253, ((t_sample)0.5));
			t_sample add_378 = (sah_391 + ((int)50));
			t_sample mod_387 = safemod(plusequals_395, add_378);
			t_sample div_384 = safediv(mod_387, add_378);
			t_sample expr_400 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_384))));
			t_sample noise_398 = noise();
			t_sample abs_397 = fabs(noise_398);
			t_sample mul_396 = (abs_397 * mul_574);
			t_sample sah_399 = __m_sah_60(mul_396, tap_253, ((t_sample)0.5));
			t_sample add_393 = (sah_399 + mod_387);
			t_sample mod_392 = safemod(add_393, mul_574);
			t_sample switch_379 = (gte_232 ? mod_392 : ((int)-1));
			int index_trunc_61 = fixnan(floor(switch_379));
			bool index_ignore_62 = ((index_trunc_61 >= segments_dim) || (index_trunc_61 < 0));
			// samples segments channel 1;
			t_sample sample_segments_385 = (index_ignore_62 ? 0 : m_segments_34.read(index_trunc_61, 0));
			t_sample index_segments_386 = switch_379;
			t_sample mul_382 = (sample_segments_385 * expr_400);
			t_sample mul_455 = ((mul_382 + mul_358) * ((t_sample)0.4));
			t_sample mul_454 = ((mul_382 + mul_358) * ((t_sample)0.3));
			t_sample plusequals_275 = __m_pluseq_63.post(((int)1), tap_243, 0);
			t_sample noise_270 = noise();
			t_sample abs_269 = fabs(noise_270);
			t_sample sub_261 = (clamp_459 - ((int)50));
			t_sample mul_268 = (abs_269 * sub_261);
			t_sample sah_271 = __m_sah_64(mul_268, tap_243, ((t_sample)0.5));
			t_sample add_258 = (sah_271 + ((int)50));
			t_sample mod_267 = safemod(plusequals_275, add_258);
			t_sample div_264 = safediv(mod_267, add_258);
			t_sample expr_280 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_264))));
			t_sample noise_278 = noise();
			t_sample abs_277 = fabs(noise_278);
			t_sample mul_276 = (abs_277 * mul_574);
			t_sample sah_279 = __m_sah_65(mul_276, tap_243, ((t_sample)0.5));
			t_sample add_273 = (sah_279 + mod_267);
			t_sample mod_272 = safemod(add_273, mul_574);
			t_sample switch_259 = (gte_227 ? mod_272 : ((int)-1));
			int index_trunc_66 = fixnan(floor(switch_259));
			bool index_ignore_67 = ((index_trunc_66 >= segments_dim) || (index_trunc_66 < 0));
			// samples segments channel 1;
			t_sample sample_segments_265 = (index_ignore_67 ? 0 : m_segments_34.read(index_trunc_66, 0));
			t_sample index_segments_266 = switch_259;
			t_sample mul_262 = (sample_segments_265 * expr_280);
			t_sample plusequals_299 = __m_pluseq_68.post(((int)1), tap_245, 0);
			t_sample noise_294 = noise();
			t_sample abs_293 = fabs(noise_294);
			t_sample sub_285 = (clamp_459 - ((int)50));
			t_sample mul_292 = (abs_293 * sub_285);
			t_sample sah_295 = __m_sah_69(mul_292, tap_245, ((t_sample)0.5));
			t_sample add_282 = (sah_295 + ((int)50));
			t_sample mod_291 = safemod(plusequals_299, add_282);
			t_sample div_288 = safediv(mod_291, add_282);
			t_sample expr_304 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_288))));
			t_sample noise_302 = noise();
			t_sample abs_301 = fabs(noise_302);
			t_sample mul_300 = (abs_301 * mul_574);
			t_sample sah_303 = __m_sah_70(mul_300, tap_245, ((t_sample)0.5));
			t_sample add_297 = (sah_303 + mod_291);
			t_sample mod_296 = safemod(add_297, mul_574);
			t_sample switch_283 = (gte_228 ? mod_296 : ((int)-1));
			int index_trunc_71 = fixnan(floor(switch_283));
			bool index_ignore_72 = ((index_trunc_71 >= segments_dim) || (index_trunc_71 < 0));
			// samples segments channel 1;
			t_sample sample_segments_289 = (index_ignore_72 ? 0 : m_segments_34.read(index_trunc_71, 0));
			t_sample index_segments_290 = switch_283;
			t_sample mul_286 = (sample_segments_289 * expr_304);
			t_sample mul_451 = ((mul_286 + mul_262) * ((t_sample)0.5));
			t_sample mul_450 = ((mul_286 + mul_262) * ((t_sample)0.2));
			t_sample plusequals_323 = __m_pluseq_73.post(((int)1), tap_247, 0);
			t_sample noise_318 = noise();
			t_sample abs_317 = fabs(noise_318);
			t_sample sub_309 = (clamp_459 - ((int)50));
			t_sample mul_316 = (abs_317 * sub_309);
			t_sample sah_319 = __m_sah_74(mul_316, tap_247, ((t_sample)0.5));
			t_sample add_306 = (sah_319 + ((int)50));
			t_sample mod_315 = safemod(plusequals_323, add_306);
			t_sample div_312 = safediv(mod_315, add_306);
			t_sample expr_328 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_312))));
			t_sample noise_326 = noise();
			t_sample abs_325 = fabs(noise_326);
			t_sample mul_324 = (abs_325 * mul_574);
			t_sample sah_327 = __m_sah_75(mul_324, tap_247, ((t_sample)0.5));
			t_sample add_321 = (sah_327 + mod_315);
			t_sample mod_320 = safemod(add_321, mul_574);
			t_sample switch_307 = (gte_229 ? mod_320 : ((int)-1));
			int index_trunc_76 = fixnan(floor(switch_307));
			bool index_ignore_77 = ((index_trunc_76 >= segments_dim) || (index_trunc_76 < 0));
			// samples segments channel 1;
			t_sample sample_segments_313 = (index_ignore_77 ? 0 : m_segments_34.read(index_trunc_76, 0));
			t_sample index_segments_314 = switch_307;
			t_sample mul_310 = (sample_segments_313 * expr_328);
			t_sample plusequals_347 = __m_pluseq_78.post(((int)1), tap_249, 0);
			t_sample noise_342 = noise();
			t_sample abs_341 = fabs(noise_342);
			t_sample sub_333 = (clamp_459 - ((int)50));
			t_sample mul_340 = (abs_341 * sub_333);
			t_sample sah_343 = __m_sah_79(mul_340, tap_249, ((t_sample)0.5));
			t_sample add_330 = (sah_343 + ((int)50));
			t_sample mod_339 = safemod(plusequals_347, add_330);
			t_sample div_336 = safediv(mod_339, add_330);
			t_sample expr_352 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_336))));
			t_sample noise_350 = noise();
			t_sample abs_349 = fabs(noise_350);
			t_sample mul_348 = (abs_349 * mul_574);
			t_sample sah_351 = __m_sah_80(mul_348, tap_249, ((t_sample)0.5));
			t_sample add_345 = (sah_351 + mod_339);
			t_sample mod_344 = safemod(add_345, mul_574);
			t_sample switch_331 = (gte_230 ? mod_344 : ((int)-1));
			int index_trunc_81 = fixnan(floor(switch_331));
			bool index_ignore_82 = ((index_trunc_81 >= segments_dim) || (index_trunc_81 < 0));
			// samples segments channel 1;
			t_sample sample_segments_337 = (index_ignore_82 ? 0 : m_segments_34.read(index_trunc_81, 0));
			t_sample index_segments_338 = switch_331;
			t_sample mul_334 = (sample_segments_337 * expr_352);
			t_sample mul_453 = ((mul_334 + mul_310) * ((t_sample)0.2));
			t_sample mul_452 = ((mul_334 + mul_310) * ((t_sample)0.5));
			int gt_582 = (clamp_585 > m_knob3_thresh_30);
			int change_581 = __m_change_83(gt_582);
			int eq_580 = (change_581 == ((int)1));
			t_sample add_198 = (m_history_5 + ((int)1));
			int gt_197 = (m_history_5 > mstosamps_200);
			int mul_196 = (eq_580 * gt_197);
			int and_194 = (gt_197 && eq_580);
			t_sample switch_195 = (and_194 ? ((int)0) : add_198);
			t_sample history_199_next_202 = fixdenorm(switch_195);
			int plusequals_563 = __m_pluseq_84.post(((int)1), mul_196, 0);
			t_sample noise_558 = noise();
			t_sample abs_557 = fabs(noise_558);
			t_sample sub_549 = (clamp_459 - ((int)50));
			t_sample mul_556 = (abs_557 * sub_549);
			t_sample sah_559 = __m_sah_85(mul_556, mul_196, ((t_sample)0.5));
			t_sample add_546 = (sah_559 + ((int)50));
			t_sample mod_555 = safemod(plusequals_563, add_546);
			t_sample div_552 = safediv(mod_555, add_546);
			t_sample expr_568 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_552))));
			t_sample noise_566 = noise();
			t_sample abs_565 = fabs(noise_566);
			t_sample mul_564 = (abs_565 * mul_574);
			t_sample sah_567 = __m_sah_86(mul_564, mul_196, ((t_sample)0.5));
			t_sample add_561 = (sah_567 + mod_555);
			t_sample mod_560 = safemod(add_561, mul_574);
			t_sample switch_547 = (gte_238 ? mod_560 : ((int)-1));
			int index_trunc_87 = fixnan(floor(switch_547));
			bool index_ignore_88 = ((index_trunc_87 >= segments_dim) || (index_trunc_87 < 0));
			// samples segments channel 1;
			t_sample sample_segments_553 = (index_ignore_88 ? 0 : m_segments_34.read(index_trunc_87, 0));
			t_sample index_segments_554 = switch_547;
			t_sample mul_550 = (sample_segments_553 * expr_568);
			int gt_544 = (clamp_585 > mul_535);
			int change_543 = __m_change_89(gt_544);
			int eq_542 = (change_543 == ((int)1));
			t_sample add_187 = (m_history_4 + ((int)1));
			int gt_186 = (m_history_4 > mstosamps_189);
			int mul_185 = (eq_542 * gt_186);
			int and_183 = (gt_186 && eq_542);
			t_sample switch_184 = (and_183 ? ((int)0) : add_187);
			t_sample history_188_next_191 = fixdenorm(switch_184);
			int plusequals_526 = __m_pluseq_90.post(((int)1), mul_185, 0);
			t_sample noise_521 = noise();
			t_sample abs_520 = fabs(noise_521);
			t_sample sub_512 = (clamp_459 - ((int)50));
			t_sample mul_519 = (abs_520 * sub_512);
			t_sample sah_522 = __m_sah_91(mul_519, mul_185, ((t_sample)0.5));
			t_sample add_509 = (sah_522 + ((int)50));
			t_sample mod_518 = safemod(plusequals_526, add_509);
			t_sample div_515 = safediv(mod_518, add_509);
			t_sample expr_531 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_515))));
			t_sample noise_529 = noise();
			t_sample abs_528 = fabs(noise_529);
			t_sample mul_527 = (abs_528 * mul_574);
			t_sample sah_530 = __m_sah_92(mul_527, mul_185, ((t_sample)0.5));
			t_sample add_524 = (sah_530 + mod_518);
			t_sample mod_523 = safemod(add_524, mul_574);
			t_sample switch_510 = (gte_237 ? mod_523 : ((int)-1));
			int index_trunc_93 = fixnan(floor(switch_510));
			bool index_ignore_94 = ((index_trunc_93 >= segments_dim) || (index_trunc_93 < 0));
			// samples segments channel 1;
			t_sample sample_segments_516 = (index_ignore_94 ? 0 : m_segments_34.read(index_trunc_93, 0));
			t_sample index_segments_517 = switch_510;
			t_sample mul_513 = (sample_segments_516 * expr_531);
			int gt_541 = (clamp_585 > mul_534);
			int change_540 = __m_change_95(gt_541);
			int eq_539 = (change_540 == ((int)1));
			t_sample add_176 = (m_history_3 + ((int)1));
			int gt_175 = (m_history_3 > mstosamps_178);
			int mul_174 = (eq_539 * gt_175);
			int and_172 = (gt_175 && eq_539);
			t_sample switch_173 = (and_172 ? ((int)0) : add_176);
			t_sample history_177_next_180 = fixdenorm(switch_173);
			int plusequals_502 = __m_pluseq_96.post(((int)1), mul_174, 0);
			t_sample noise_497 = noise();
			t_sample abs_496 = fabs(noise_497);
			t_sample sub_488 = (clamp_459 - ((int)50));
			t_sample mul_495 = (abs_496 * sub_488);
			t_sample sah_498 = __m_sah_97(mul_495, mul_174, ((t_sample)0.5));
			t_sample add_485 = (sah_498 + ((int)50));
			t_sample mod_494 = safemod(plusequals_502, add_485);
			t_sample div_491 = safediv(mod_494, add_485);
			t_sample expr_507 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_491))));
			t_sample noise_505 = noise();
			t_sample abs_504 = fabs(noise_505);
			t_sample mul_503 = (abs_504 * mul_574);
			t_sample sah_506 = __m_sah_98(mul_503, mul_174, ((t_sample)0.5));
			t_sample add_500 = (sah_506 + mod_494);
			t_sample mod_499 = safemod(add_500, mul_574);
			t_sample switch_486 = (gte_236 ? mod_499 : ((int)-1));
			int index_trunc_99 = fixnan(floor(switch_486));
			bool index_ignore_100 = ((index_trunc_99 >= segments_dim) || (index_trunc_99 < 0));
			// samples segments channel 1;
			t_sample sample_segments_492 = (index_ignore_100 ? 0 : m_segments_34.read(index_trunc_99, 0));
			t_sample index_segments_493 = switch_486;
			t_sample mul_489 = (sample_segments_492 * expr_507);
			int gt_538 = (clamp_585 > mul_533);
			int change_537 = __m_change_101(gt_538);
			int eq_536 = (change_537 == ((int)1));
			t_sample add_165 = (m_history_2 + ((int)1));
			int gt_164 = (m_history_2 > mstosamps_167);
			int mul_163 = (eq_536 * gt_164);
			int and_161 = (gt_164 && eq_536);
			t_sample switch_162 = (and_161 ? ((int)0) : add_165);
			t_sample history_166_next_169 = fixdenorm(switch_162);
			int plusequals_478 = __m_pluseq_102.post(((int)1), mul_163, 0);
			t_sample noise_473 = noise();
			t_sample abs_472 = fabs(noise_473);
			t_sample sub_464 = (clamp_459 - ((int)50));
			t_sample mul_471 = (abs_472 * sub_464);
			t_sample sah_474 = __m_sah_103(mul_471, mul_163, ((t_sample)0.5));
			t_sample add_461 = (sah_474 + ((int)50));
			t_sample mod_470 = safemod(plusequals_478, add_461);
			t_sample div_467 = safediv(mod_470, add_461);
			t_sample expr_483 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_467))));
			t_sample noise_481 = noise();
			t_sample abs_480 = fabs(noise_481);
			t_sample mul_479 = (abs_480 * mul_574);
			t_sample sah_482 = __m_sah_104(mul_479, mul_163, ((t_sample)0.5));
			t_sample add_476 = (sah_482 + mod_470);
			t_sample mod_475 = safemod(add_476, mul_574);
			t_sample switch_462 = (gte_235 ? mod_475 : ((int)-1));
			int index_trunc_105 = fixnan(floor(switch_462));
			bool index_ignore_106 = ((index_trunc_105 >= segments_dim) || (index_trunc_105 < 0));
			// samples segments channel 1;
			t_sample sample_segments_468 = (index_ignore_106 ? 0 : m_segments_34.read(index_trunc_105, 0));
			t_sample index_segments_469 = switch_462;
			t_sample mul_465 = (sample_segments_468 * expr_483);
			t_sample mul_545 = ((((mul_550 + mul_465) + mul_489) + mul_513) * ((t_sample)0.7));
			t_sample mul_241 = (((((mul_453 + mul_451) + mul_455) + mul_457) + mul_545) * scale_699);
			t_sample dcblock_206 = __m_dcblock_107(mul_241);
			t_sample mul_209 = (sqrt_207 * dcblock_206);
			t_sample out1 = ((mul_209 + mul_210) + gate_598);
			t_sample mul_240 = (((((mul_452 + mul_450) + mul_454) + mul_456) + mul_545) * scale_699);
			t_sample dcblock_205 = __m_dcblock_108(mul_240);
			t_sample mul_208 = (sqrt_207 * dcblock_205);
			t_sample out2 = ((mul_208 + mul_210) + gate_598);
			t_sample history_575_next_641 = fixdenorm(eq_576);
			m_history_26 = history_594_next_596;
			m_history_25 = history_216_next_218;
			m_history_23 = history_212_next_220;
			m_history_24 = history_214_next_219;
			m_history_22 = history_216_next_604;
			m_history_20 = history_212_next_606;
			m_history_21 = history_214_next_608;
			m_history_19 = history_216_next_621;
			m_history_17 = history_212_next_617;
			m_history_18 = history_214_next_620;
			m_delay_16.write(mul_185);
			m_delay_15.write(mul_196);
			m_delay_14.write(mul_163);
			m_delay_13.write(mul_174);
			m_delay_12.write(tap_251);
			m_delay_11.write(tap_253);
			m_delay_10.write(tap_255);
			m_delay_9.write(tap_257);
			m_history_8 = history_216_next_636;
			m_history_6 = history_212_next_629;
			m_history_7 = history_214_next_632;
			m_history_5 = history_199_next_202;
			m_history_4 = history_188_next_191;
			m_history_3 = history_177_next_180;
			m_history_2 = history_166_next_169;
			m_history_1 = history_575_next_641;
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
	inline void set_knob5_glitchlen(t_param _value) {
		m_knob5_glitchlen_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_thresh(t_param _value) {
		m_knob3_thresh_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_density(t_param _value) {
		m_knob6_density_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob1_wetdry_31; break;
		case 1: *value = self->m_knob3_thresh_30; break;
		case 2: *value = self->m_knob4_buflen_29; break;
		case 3: *value = self->m_knob5_glitchlen_27; break;
		case 4: *value = self->m_knob6_density_33; break;
		
		case 6: *value = self->m_sw_32; break;
		case 7: *value = self->m_sw_28; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_31")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_thresh_30")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_thresh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_thresh_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_buflen_29")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_buflen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_buflen_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_glitchlen_27")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_glitchlen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_glitchlen_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_density_33")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_density";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_density_33;
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
	// initialize parameter 6 ("m_sw_32")
	pi = self->__commonstate.params + 6;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_sw_28")
	pi = self->__commonstate.params + 7;
	pi->name = "sw2";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Glitch::
