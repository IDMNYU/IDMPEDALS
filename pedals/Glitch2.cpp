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
	t_sample m_knob4_buflen_33;
	t_sample m_history_25;
	t_sample m_history_3;
	t_sample m_sw_32;
	t_sample samplerate;
	t_sample m_knob6_density_28;
	t_sample m_knob3_rate_31;
	t_sample m_sw_29;
	t_sample m_knob5_glitchlen_30;
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
	t_sample m_knob1_wetdry_27;
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
		m_knob1_wetdry_27 = ((int)0);
		m_knob6_density_28 = ((int)0);
		m_sw_29 = ((int)0);
		m_knob5_glitchlen_30 = ((int)0);
		m_knob3_rate_31 = ((int)0);
		m_sw_32 = ((int)0);
		m_knob4_buflen_33 = ((int)0);
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
		t_sample mstosamps_2319 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_2308 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_2297 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_2330 = (((int)1) * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_2715 = __m_sah_35(m_history_26, m_sw_32, ((int)0));
			t_sample gen_2717 = sah_2715;
			t_sample rsub_2713 = (((int)1) - sah_2715);
			t_sample history_2714_next_2716 = fixdenorm(rsub_2713);
			t_sample out3 = gen_2717;
			t_sample mix_2810 = (m_history_25 + (((t_sample)0.003926980723806) * (m_knob4_buflen_33 - m_history_25)));
			t_sample mix_2345 = mix_2810;
			t_sample mix_2811 = (m_history_24 + (((t_sample)0.003926980723806) * (mix_2345 - m_history_24)));
			t_sample mix_2343 = mix_2811;
			t_sample mix_2812 = (m_history_23 + (((t_sample)0.003926980723806) * (mix_2343 - m_history_23)));
			t_sample mix_2341 = mix_2812;
			t_sample gen_2699 = mix_2341;
			t_sample history_2346_next_2348 = fixdenorm(mix_2345);
			t_sample history_2344_next_2349 = fixdenorm(mix_2343);
			t_sample history_2342_next_2350 = fixdenorm(mix_2341);
			t_sample expr_2721 = (((int)1) - sqrt((((int)1) - gen_2699)));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample add_2720 = (gen_2717 + ((int)1));
			t_sample choice_36 = int(add_2720);
			t_sample gate_2718 = (((choice_36 >= 1) && (choice_36 < 2)) ? in1 : 0);
			t_sample gate_2719 = ((choice_36 >= 2) ? in1 : 0);
			t_sample mix_2813 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob1_wetdry_27 - m_history_22)));
			t_sample mix_2731 = mix_2813;
			t_sample mix_2814 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_2731 - m_history_21)));
			t_sample mix_2722 = mix_2814;
			t_sample mix_2815 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_2722 - m_history_20)));
			t_sample mix_2730 = mix_2815;
			t_sample gen_2351 = mix_2730;
			t_sample history_2346_next_2725 = fixdenorm(mix_2731);
			t_sample history_2344_next_2729 = fixdenorm(mix_2722);
			t_sample history_2342_next_2728 = fixdenorm(mix_2730);
			t_sample sqrt_2337 = sqrt(gen_2351);
			t_sample rsub_2353 = (((int)1) - gen_2351);
			t_sample sqrt_2352 = sqrt(rsub_2353);
			t_sample mul_2340 = (sqrt_2352 * gate_2719);
			t_sample mul_2700 = (expr_2721 * ((int)480000));
			t_sample plusequals_2712 = __m_pluseq_37.post(((int)1), m_history_1, 0);
			t_sample switch_2697 = (m_sw_29 ? ((int)-1) : plusequals_2712);
			int index_trunc_38 = fixnan(floor(switch_2697));
			bool index_ignore_39 = ((index_trunc_38 >= segments_dim) || (index_trunc_38 < 0));
			if ((!index_ignore_39)) {
				m_segments_34.write(gate_2719, index_trunc_38, 0);
				
			};
			int gte_2703 = (plusequals_2712 >= mul_2700);
			int eq_2702 = (gte_2703 == ((int)1));
			t_sample switch_2289 = (gen_2717 ? m_knob3_rate_31 : ((int)0));
			t_sample phasor_2711 = __m_phasor_40(switch_2289, samples_to_seconds);
			t_sample out4 = phasor_2711;
			t_sample mix_2816 = (m_history_19 + (((t_sample)0.003926980723806) * (m_knob6_density_28 - m_history_19)));
			t_sample mix_2744 = mix_2816;
			t_sample mix_2817 = (m_history_18 + (((t_sample)0.003926980723806) * (mix_2744 - m_history_18)));
			t_sample mix_2736 = mix_2817;
			t_sample mix_2818 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_2736 - m_history_17)));
			t_sample mix_2735 = mix_2818;
			t_sample gen_2587 = mix_2735;
			t_sample history_2346_next_2739 = fixdenorm(mix_2744);
			t_sample history_2344_next_2740 = fixdenorm(mix_2736);
			t_sample history_2342_next_2737 = fixdenorm(mix_2735);
			t_sample sub_2822 = (gen_2587 - ((int)0));
			t_sample scale_2819 = ((safepow((sub_2822 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_2384 = m_delay_16.read_step(((int)8));
			t_sample tap_2386 = m_delay_15.read_step(((int)8));
			t_sample tap_2380 = m_delay_14.read_step(((int)8));
			t_sample tap_2382 = m_delay_13.read_step(((int)8));
			t_sample tap_2372 = m_delay_12.read_step(((int)8));
			t_sample tap_2374 = m_delay_11.read_step(((int)8));
			t_sample tap_2376 = m_delay_10.read_step(((int)9));
			t_sample tap_2378 = m_delay_9.read_step(((int)8));
			t_sample mul_2368 = (gen_2587 * ((int)12));
			int gte_2366 = (mul_2368 >= ((int)1));
			int gte_2365 = (mul_2368 >= ((int)2));
			int gte_2364 = (mul_2368 >= ((int)3));
			int gte_2367 = (mul_2368 >= ((int)0));
			int gte_2362 = (mul_2368 >= ((int)5));
			int gte_2363 = (mul_2368 >= ((int)4));
			int gte_2360 = (mul_2368 >= ((int)7));
			int gte_2361 = (mul_2368 >= ((int)6));
			int gte_2356 = (mul_2368 >= ((int)11));
			int gte_2357 = (mul_2368 >= ((int)10));
			int gte_2358 = (mul_2368 >= ((int)9));
			int gte_2359 = (mul_2368 >= ((int)8));
			t_sample mix_2823 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob5_glitchlen_30 - m_history_8)));
			t_sample mix_2752 = mix_2823;
			t_sample mix_2824 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_2752 - m_history_7)));
			t_sample mix_2748 = mix_2824;
			t_sample mix_2825 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_2748 - m_history_6)));
			t_sample mix_2757 = mix_2825;
			t_sample gen_2589 = mix_2757;
			t_sample history_2346_next_2755 = fixdenorm(mix_2752);
			t_sample history_2344_next_2751 = fixdenorm(mix_2748);
			t_sample history_2342_next_2749 = fixdenorm(mix_2757);
			t_sample mul_2334 = (mul_2700 * gen_2589);
			t_sample clamp_2588 = ((mul_2334 <= ((int)50)) ? ((int)50) : ((mul_2334 >= ((int)480000)) ? ((int)480000) : mul_2334));
			t_sample plusequals_2548 = __m_pluseq_41.post(((int)-1), tap_2384, 0);
			t_sample noise_2544 = noise();
			t_sample abs_2543 = fabs(noise_2544);
			t_sample sub_2539 = (clamp_2588 - ((int)50));
			t_sample mul_2542 = (abs_2543 * sub_2539);
			t_sample sah_2545 = __m_sah_42(mul_2542, tap_2384, ((t_sample)0.5));
			t_sample add_2536 = (sah_2545 + ((int)50));
			t_sample wrap_2546 = wrap(plusequals_2548, ((int)0), add_2536);
			t_sample div_2533 = safediv(wrap_2546, add_2536);
			t_sample expr_2553 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2533))));
			t_sample noise_2551 = noise();
			t_sample abs_2550 = fabs(noise_2551);
			t_sample mul_2549 = (abs_2550 * mul_2700);
			t_sample sah_2552 = __m_sah_43(mul_2549, tap_2384, ((t_sample)0.5));
			t_sample add_2534 = (sah_2552 + wrap_2546);
			t_sample switch_2537 = (gte_2362 ? add_2534 : ((int)-1));
			int index_trunc_44 = fixnan(floor(switch_2537));
			bool index_ignore_45 = ((index_trunc_44 >= segments_dim) || (index_trunc_44 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2540 = (index_ignore_45 ? 0 : m_segments_34.read(index_trunc_44, 0));
			t_sample index_segments_2541 = switch_2537;
			t_sample mul_2531 = (sample_segments_2540 * expr_2553);
			t_sample plusequals_2572 = __m_pluseq_46.post(((int)-1), tap_2386, 0);
			t_sample noise_2568 = noise();
			t_sample abs_2567 = fabs(noise_2568);
			t_sample sub_2563 = (clamp_2588 - ((int)50));
			t_sample mul_2566 = (abs_2567 * sub_2563);
			t_sample sah_2569 = __m_sah_47(mul_2566, tap_2386, ((t_sample)0.5));
			t_sample add_2560 = (sah_2569 + ((int)50));
			t_sample wrap_2570 = wrap(plusequals_2572, ((int)0), add_2560);
			t_sample div_2557 = safediv(wrap_2570, add_2560);
			t_sample expr_2577 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2557))));
			t_sample noise_2575 = noise();
			t_sample abs_2574 = fabs(noise_2575);
			t_sample mul_2573 = (abs_2574 * mul_2700);
			t_sample sah_2576 = __m_sah_48(mul_2573, tap_2386, ((t_sample)0.5));
			t_sample add_2558 = (sah_2576 + wrap_2570);
			t_sample switch_2561 = (gte_2363 ? add_2558 : ((int)-1));
			int index_trunc_49 = fixnan(floor(switch_2561));
			bool index_ignore_50 = ((index_trunc_49 >= segments_dim) || (index_trunc_49 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2564 = (index_ignore_50 ? 0 : m_segments_34.read(index_trunc_49, 0));
			t_sample index_segments_2565 = switch_2561;
			t_sample mul_2555 = (sample_segments_2564 * expr_2577);
			t_sample mul_2586 = ((mul_2555 + mul_2531) * ((t_sample)0.3));
			t_sample mul_2585 = ((mul_2555 + mul_2531) * ((t_sample)0.4));
			t_sample plusequals_2500 = __m_pluseq_51.post(((int)-1), tap_2380, 0);
			t_sample noise_2496 = noise();
			t_sample abs_2495 = fabs(noise_2496);
			t_sample sub_2491 = (clamp_2588 - ((int)50));
			t_sample mul_2494 = (abs_2495 * sub_2491);
			t_sample sah_2497 = __m_sah_52(mul_2494, tap_2380, ((t_sample)0.5));
			t_sample add_2488 = (sah_2497 + ((int)50));
			t_sample wrap_2498 = wrap(plusequals_2500, ((int)0), add_2488);
			t_sample div_2485 = safediv(wrap_2498, add_2488);
			t_sample expr_2505 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2485))));
			t_sample noise_2503 = noise();
			t_sample abs_2502 = fabs(noise_2503);
			t_sample mul_2501 = (abs_2502 * mul_2700);
			t_sample sah_2504 = __m_sah_53(mul_2501, tap_2380, ((t_sample)0.5));
			t_sample add_2486 = (sah_2504 + wrap_2498);
			t_sample switch_2489 = (gte_2360 ? add_2486 : ((int)-1));
			int index_trunc_54 = fixnan(floor(switch_2489));
			bool index_ignore_55 = ((index_trunc_54 >= segments_dim) || (index_trunc_54 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2492 = (index_ignore_55 ? 0 : m_segments_34.read(index_trunc_54, 0));
			t_sample index_segments_2493 = switch_2489;
			t_sample mul_2483 = (sample_segments_2492 * expr_2505);
			t_sample plusequals_2524 = __m_pluseq_56.post(((int)-1), tap_2382, 0);
			t_sample noise_2520 = noise();
			t_sample abs_2519 = fabs(noise_2520);
			t_sample sub_2515 = (clamp_2588 - ((int)50));
			t_sample mul_2518 = (abs_2519 * sub_2515);
			t_sample sah_2521 = __m_sah_57(mul_2518, tap_2382, ((t_sample)0.5));
			t_sample add_2512 = (sah_2521 + ((int)50));
			t_sample wrap_2522 = wrap(plusequals_2524, ((int)0), add_2512);
			t_sample div_2509 = safediv(wrap_2522, add_2512);
			t_sample expr_2529 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2509))));
			t_sample noise_2527 = noise();
			t_sample abs_2526 = fabs(noise_2527);
			t_sample mul_2525 = (abs_2526 * mul_2700);
			t_sample sah_2528 = __m_sah_58(mul_2525, tap_2382, ((t_sample)0.5));
			t_sample add_2510 = (sah_2528 + wrap_2522);
			t_sample switch_2513 = (gte_2361 ? add_2510 : ((int)-1));
			int index_trunc_59 = fixnan(floor(switch_2513));
			bool index_ignore_60 = ((index_trunc_59 >= segments_dim) || (index_trunc_59 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2516 = (index_ignore_60 ? 0 : m_segments_34.read(index_trunc_59, 0));
			t_sample index_segments_2517 = switch_2513;
			t_sample mul_2507 = (sample_segments_2516 * expr_2529);
			t_sample mul_2584 = ((mul_2507 + mul_2483) * ((t_sample)0.4));
			t_sample mul_2583 = ((mul_2507 + mul_2483) * ((t_sample)0.3));
			t_sample plusequals_2404 = __m_pluseq_61.post(((int)-1), tap_2372, 0);
			t_sample noise_2400 = noise();
			t_sample abs_2399 = fabs(noise_2400);
			t_sample sub_2395 = (clamp_2588 - ((int)50));
			t_sample mul_2398 = (abs_2399 * sub_2395);
			t_sample sah_2401 = __m_sah_62(mul_2398, tap_2372, ((t_sample)0.5));
			t_sample add_2392 = (sah_2401 + ((int)50));
			t_sample wrap_2402 = wrap(plusequals_2404, ((int)0), add_2392);
			t_sample div_2389 = safediv(wrap_2402, add_2392);
			t_sample expr_2409 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2389))));
			t_sample noise_2407 = noise();
			t_sample abs_2406 = fabs(noise_2407);
			t_sample mul_2405 = (abs_2406 * mul_2700);
			t_sample sah_2408 = __m_sah_63(mul_2405, tap_2372, ((t_sample)0.5));
			t_sample add_2390 = (sah_2408 + wrap_2402);
			t_sample switch_2393 = (gte_2356 ? add_2390 : ((int)-1));
			int index_trunc_64 = fixnan(floor(switch_2393));
			bool index_ignore_65 = ((index_trunc_64 >= segments_dim) || (index_trunc_64 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2396 = (index_ignore_65 ? 0 : m_segments_34.read(index_trunc_64, 0));
			t_sample index_segments_2397 = switch_2393;
			t_sample mul_2387 = (sample_segments_2396 * expr_2409);
			t_sample plusequals_2428 = __m_pluseq_66.post(((int)-1), tap_2374, 0);
			t_sample noise_2424 = noise();
			t_sample abs_2423 = fabs(noise_2424);
			t_sample sub_2419 = (clamp_2588 - ((int)50));
			t_sample mul_2422 = (abs_2423 * sub_2419);
			t_sample sah_2425 = __m_sah_67(mul_2422, tap_2374, ((t_sample)0.5));
			t_sample add_2416 = (sah_2425 + ((int)50));
			t_sample wrap_2426 = wrap(plusequals_2428, ((int)0), add_2416);
			t_sample div_2413 = safediv(wrap_2426, add_2416);
			t_sample expr_2433 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2413))));
			t_sample noise_2431 = noise();
			t_sample abs_2430 = fabs(noise_2431);
			t_sample mul_2429 = (abs_2430 * mul_2700);
			t_sample sah_2432 = __m_sah_68(mul_2429, tap_2374, ((t_sample)0.5));
			t_sample add_2414 = (sah_2432 + wrap_2426);
			t_sample switch_2417 = (gte_2357 ? add_2414 : ((int)-1));
			int index_trunc_69 = fixnan(floor(switch_2417));
			bool index_ignore_70 = ((index_trunc_69 >= segments_dim) || (index_trunc_69 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2420 = (index_ignore_70 ? 0 : m_segments_34.read(index_trunc_69, 0));
			t_sample index_segments_2421 = switch_2417;
			t_sample mul_2411 = (sample_segments_2420 * expr_2433);
			t_sample mul_2580 = ((mul_2411 + mul_2387) * ((t_sample)0.5));
			t_sample mul_2579 = ((mul_2411 + mul_2387) * ((t_sample)0.2));
			t_sample plusequals_2452 = __m_pluseq_71.post(((int)-1), tap_2376, 0);
			t_sample noise_2448 = noise();
			t_sample abs_2447 = fabs(noise_2448);
			t_sample sub_2443 = (clamp_2588 - ((int)50));
			t_sample mul_2446 = (abs_2447 * sub_2443);
			t_sample sah_2449 = __m_sah_72(mul_2446, tap_2376, ((t_sample)0.5));
			t_sample add_2440 = (sah_2449 + ((int)50));
			t_sample wrap_2450 = wrap(plusequals_2452, ((int)0), add_2440);
			t_sample div_2437 = safediv(wrap_2450, add_2440);
			t_sample expr_2457 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2437))));
			t_sample noise_2455 = noise();
			t_sample abs_2454 = fabs(noise_2455);
			t_sample mul_2453 = (abs_2454 * mul_2700);
			t_sample sah_2456 = __m_sah_73(mul_2453, tap_2376, ((t_sample)0.5));
			t_sample add_2438 = (sah_2456 + wrap_2450);
			t_sample switch_2441 = (gte_2358 ? add_2438 : ((int)-1));
			int index_trunc_74 = fixnan(floor(switch_2441));
			bool index_ignore_75 = ((index_trunc_74 >= segments_dim) || (index_trunc_74 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2444 = (index_ignore_75 ? 0 : m_segments_34.read(index_trunc_74, 0));
			t_sample index_segments_2445 = switch_2441;
			t_sample mul_2435 = (sample_segments_2444 * expr_2457);
			t_sample plusequals_2476 = __m_pluseq_76.post(((int)-1), tap_2378, 0);
			t_sample noise_2472 = noise();
			t_sample abs_2471 = fabs(noise_2472);
			t_sample sub_2467 = (clamp_2588 - ((int)50));
			t_sample mul_2470 = (abs_2471 * sub_2467);
			t_sample sah_2473 = __m_sah_77(mul_2470, tap_2378, ((t_sample)0.5));
			t_sample add_2464 = (sah_2473 + ((int)50));
			t_sample wrap_2474 = wrap(plusequals_2476, ((int)0), add_2464);
			t_sample div_2461 = safediv(wrap_2474, add_2464);
			t_sample expr_2481 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2461))));
			t_sample noise_2479 = noise();
			t_sample abs_2478 = fabs(noise_2479);
			t_sample mul_2477 = (abs_2478 * mul_2700);
			t_sample sah_2480 = __m_sah_78(mul_2477, tap_2378, ((t_sample)0.5));
			t_sample add_2462 = (sah_2480 + wrap_2474);
			t_sample switch_2465 = (gte_2359 ? add_2462 : ((int)-1));
			int index_trunc_79 = fixnan(floor(switch_2465));
			bool index_ignore_80 = ((index_trunc_79 >= segments_dim) || (index_trunc_79 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2468 = (index_ignore_80 ? 0 : m_segments_34.read(index_trunc_79, 0));
			t_sample index_segments_2469 = switch_2465;
			t_sample mul_2459 = (sample_segments_2468 * expr_2481);
			t_sample mul_2582 = ((mul_2459 + mul_2435) * ((t_sample)0.2));
			t_sample mul_2581 = ((mul_2459 + mul_2435) * ((t_sample)0.5));
			int gt_2670 = (phasor_2711 > ((t_sample)0.49));
			int change_2669 = __m_change_81(gt_2670);
			int eq_2668 = (change_2669 == ((int)1));
			t_sample add_2317 = (m_history_5 + ((int)1));
			int gt_2316 = (m_history_5 > mstosamps_2319);
			int mul_2315 = (eq_2668 * gt_2316);
			int and_2313 = (gt_2316 && eq_2668);
			t_sample switch_2314 = (and_2313 ? ((int)0) : add_2317);
			t_sample history_2318_next_2321 = fixdenorm(switch_2314);
			int plusequals_2655 = __m_pluseq_82.post(((int)-1), mul_2315, 0);
			t_sample noise_2651 = noise();
			t_sample abs_2650 = fabs(noise_2651);
			t_sample sub_2646 = (clamp_2588 - ((int)50));
			t_sample mul_2649 = (abs_2650 * sub_2646);
			t_sample sah_2652 = __m_sah_83(mul_2649, mul_2315, ((t_sample)0.5));
			t_sample add_2643 = (sah_2652 + ((int)50));
			t_sample wrap_2653 = wrap(plusequals_2655, ((int)0), add_2643);
			t_sample div_2640 = safediv(wrap_2653, add_2643);
			t_sample expr_2660 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2640))));
			t_sample noise_2658 = noise();
			t_sample abs_2657 = fabs(noise_2658);
			t_sample mul_2656 = (abs_2657 * mul_2700);
			t_sample sah_2659 = __m_sah_84(mul_2656, mul_2315, ((t_sample)0.5));
			t_sample add_2641 = (sah_2659 + wrap_2653);
			t_sample switch_2644 = (gte_2366 ? add_2641 : ((int)-1));
			int index_trunc_85 = fixnan(floor(switch_2644));
			bool index_ignore_86 = ((index_trunc_85 >= segments_dim) || (index_trunc_85 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2647 = (index_ignore_86 ? 0 : m_segments_34.read(index_trunc_85, 0));
			t_sample index_segments_2648 = switch_2644;
			t_sample mul_2638 = (sample_segments_2647 * expr_2660);
			int gt_2667 = (phasor_2711 > ((t_sample)0.51));
			int change_2666 = __m_change_87(gt_2667);
			int eq_2665 = (change_2666 == ((int)1));
			t_sample add_2306 = (m_history_4 + ((int)1));
			int gt_2305 = (m_history_4 > mstosamps_2308);
			int mul_2304 = (eq_2665 * gt_2305);
			int and_2302 = (gt_2305 && eq_2665);
			t_sample switch_2303 = (and_2302 ? ((int)0) : add_2306);
			t_sample history_2307_next_2310 = fixdenorm(switch_2303);
			int plusequals_2631 = __m_pluseq_88.post(((int)-1), mul_2304, 0);
			t_sample noise_2627 = noise();
			t_sample abs_2626 = fabs(noise_2627);
			t_sample sub_2622 = (clamp_2588 - ((int)50));
			t_sample mul_2625 = (abs_2626 * sub_2622);
			t_sample sah_2628 = __m_sah_89(mul_2625, mul_2304, ((t_sample)0.5));
			t_sample add_2619 = (sah_2628 + ((int)50));
			t_sample wrap_2629 = wrap(plusequals_2631, ((int)0), add_2619);
			t_sample div_2616 = safediv(wrap_2629, add_2619);
			t_sample expr_2636 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2616))));
			t_sample noise_2634 = noise();
			t_sample abs_2633 = fabs(noise_2634);
			t_sample mul_2632 = (abs_2633 * mul_2700);
			t_sample sah_2635 = __m_sah_90(mul_2632, mul_2304, ((t_sample)0.5));
			t_sample add_2617 = (sah_2635 + wrap_2629);
			t_sample switch_2620 = (gte_2365 ? add_2617 : ((int)-1));
			int index_trunc_91 = fixnan(floor(switch_2620));
			bool index_ignore_92 = ((index_trunc_91 >= segments_dim) || (index_trunc_91 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2623 = (index_ignore_92 ? 0 : m_segments_34.read(index_trunc_91, 0));
			t_sample index_segments_2624 = switch_2620;
			t_sample mul_2614 = (sample_segments_2623 * expr_2636);
			int gt_2664 = (phasor_2711 > ((t_sample)0.48));
			int change_2663 = __m_change_93(gt_2664);
			int eq_2662 = (change_2663 == ((int)1));
			t_sample add_2295 = (m_history_3 + ((int)1));
			int gt_2294 = (m_history_3 > mstosamps_2297);
			int mul_2293 = (eq_2662 * gt_2294);
			int and_2291 = (gt_2294 && eq_2662);
			t_sample switch_2292 = (and_2291 ? ((int)0) : add_2295);
			t_sample history_2296_next_2299 = fixdenorm(switch_2292);
			int plusequals_2607 = __m_pluseq_94.post(((int)-1), mul_2293, 0);
			t_sample noise_2603 = noise();
			t_sample abs_2602 = fabs(noise_2603);
			t_sample sub_2598 = (clamp_2588 - ((int)50));
			t_sample mul_2601 = (abs_2602 * sub_2598);
			t_sample sah_2604 = __m_sah_95(mul_2601, mul_2293, ((t_sample)0.5));
			t_sample add_2595 = (sah_2604 + ((int)50));
			t_sample wrap_2605 = wrap(plusequals_2607, ((int)0), add_2595);
			t_sample div_2592 = safediv(wrap_2605, add_2595);
			t_sample expr_2612 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2592))));
			t_sample noise_2610 = noise();
			t_sample abs_2609 = fabs(noise_2610);
			t_sample mul_2608 = (abs_2609 * mul_2700);
			t_sample sah_2611 = __m_sah_96(mul_2608, mul_2293, ((t_sample)0.5));
			t_sample add_2593 = (sah_2611 + wrap_2605);
			t_sample switch_2596 = (gte_2364 ? add_2593 : ((int)-1));
			int index_trunc_97 = fixnan(floor(switch_2596));
			bool index_ignore_98 = ((index_trunc_97 >= segments_dim) || (index_trunc_97 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2599 = (index_ignore_98 ? 0 : m_segments_34.read(index_trunc_97, 0));
			t_sample index_segments_2600 = switch_2596;
			t_sample mul_2590 = (sample_segments_2599 * expr_2612);
			int gt_2708 = (phasor_2711 > ((t_sample)0.5));
			int change_2707 = __m_change_99(gt_2708);
			int eq_2706 = (change_2707 == ((int)1));
			t_sample add_2328 = (m_history_2 + ((int)1));
			int gt_2327 = (m_history_2 > mstosamps_2330);
			int mul_2326 = (eq_2706 * gt_2327);
			int and_2324 = (gt_2327 && eq_2706);
			t_sample switch_2325 = (and_2324 ? ((int)0) : add_2328);
			t_sample history_2329_next_2332 = fixdenorm(switch_2325);
			int plusequals_2689 = __m_pluseq_100.post(((int)-1), mul_2326, 0);
			t_sample noise_2685 = noise();
			t_sample abs_2684 = fabs(noise_2685);
			t_sample sub_2680 = (clamp_2588 - ((int)50));
			t_sample mul_2683 = (abs_2684 * sub_2680);
			t_sample sah_2686 = __m_sah_101(mul_2683, mul_2326, ((t_sample)0.5));
			t_sample add_2677 = (sah_2686 + ((int)50));
			t_sample wrap_2687 = wrap(plusequals_2689, ((int)0), add_2677);
			t_sample div_2674 = safediv(wrap_2687, add_2677);
			t_sample expr_2694 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2674))));
			t_sample noise_2692 = noise();
			t_sample abs_2691 = fabs(noise_2692);
			t_sample mul_2690 = (abs_2691 * mul_2700);
			t_sample sah_2693 = __m_sah_102(mul_2690, mul_2326, ((t_sample)0.5));
			t_sample add_2675 = (sah_2693 + wrap_2687);
			t_sample switch_2678 = (gte_2367 ? add_2675 : ((int)-1));
			int index_trunc_103 = fixnan(floor(switch_2678));
			bool index_ignore_104 = ((index_trunc_103 >= segments_dim) || (index_trunc_103 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2681 = (index_ignore_104 ? 0 : m_segments_34.read(index_trunc_103, 0));
			t_sample index_segments_2682 = switch_2678;
			t_sample mul_2672 = (sample_segments_2681 * expr_2694);
			t_sample mul_2671 = ((((mul_2672 + mul_2590) + mul_2614) + mul_2638) * ((t_sample)0.7));
			t_sample mul_2370 = (((((mul_2582 + mul_2580) + mul_2584) + mul_2586) + mul_2671) * scale_2819);
			t_sample dcblock_2336 = __m_dcblock_105(mul_2370);
			t_sample mul_2339 = (sqrt_2337 * dcblock_2336);
			t_sample out1 = ((mul_2339 + mul_2340) + gate_2718);
			t_sample mul_2369 = (((((mul_2581 + mul_2579) + mul_2583) + mul_2585) + mul_2671) * scale_2819);
			t_sample dcblock_2335 = __m_dcblock_106(mul_2369);
			t_sample mul_2338 = (sqrt_2337 * dcblock_2335);
			t_sample out2 = ((mul_2338 + mul_2340) + gate_2718);
			t_sample history_2701_next_2761 = fixdenorm(eq_2702);
			m_history_26 = history_2714_next_2716;
			m_history_25 = history_2346_next_2348;
			m_history_23 = history_2342_next_2350;
			m_history_24 = history_2344_next_2349;
			m_history_22 = history_2346_next_2725;
			m_history_20 = history_2342_next_2728;
			m_history_21 = history_2344_next_2729;
			m_history_19 = history_2346_next_2739;
			m_history_17 = history_2342_next_2737;
			m_history_18 = history_2344_next_2740;
			m_delay_16.write(mul_2315);
			m_delay_15.write(mul_2326);
			m_delay_14.write(mul_2293);
			m_delay_13.write(mul_2304);
			m_delay_12.write(tap_2380);
			m_delay_11.write(tap_2382);
			m_delay_10.write(tap_2384);
			m_delay_9.write(tap_2386);
			m_history_8 = history_2346_next_2755;
			m_history_6 = history_2342_next_2749;
			m_history_7 = history_2344_next_2751;
			m_history_5 = history_2318_next_2321;
			m_history_4 = history_2307_next_2310;
			m_history_3 = history_2296_next_2299;
			m_history_2 = history_2329_next_2332;
			m_history_1 = history_2701_next_2761;
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
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_density(t_param _value) {
		m_knob6_density_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_glitchlen(t_param _value) {
		m_knob5_glitchlen_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_rate(t_param _value) {
		m_knob3_rate_31 = (_value < 0.01 ? 0.01 : (_value > 16 ? 16 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob1_wetdry_27; break;
		case 1: *value = self->m_knob3_rate_31; break;
		case 2: *value = self->m_knob4_buflen_33; break;
		case 3: *value = self->m_knob5_glitchlen_30; break;
		case 4: *value = self->m_knob6_density_28; break;
		
		case 6: *value = self->m_sw_32; break;
		case 7: *value = self->m_sw_29; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_27")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_27;
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
	// initialize parameter 2 ("m_knob4_buflen_33")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_buflen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_buflen_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_glitchlen_30")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_glitchlen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_glitchlen_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_density_28")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_density";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_density_28;
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
	// initialize parameter 7 ("m_sw_29")
	pi = self->__commonstate.params + 7;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_29;
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
