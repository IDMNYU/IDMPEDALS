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
	Phasor __m_phasor_37;
	PlusEquals __m_pluseq_100;
	PlusEquals __m_pluseq_38;
	PlusEquals __m_pluseq_51;
	PlusEquals __m_pluseq_56;
	PlusEquals __m_pluseq_46;
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
	t_sample m_knob5_glitchlen_32;
	t_sample samplerate;
	t_sample m_sw_28;
	t_sample m_knob6_density_31;
	t_sample m_sw_29;
	t_sample m_knob3_rate_30;
	t_sample m_history_26;
	t_sample m_history_4;
	t_sample m_history_24;
	t_sample m_history_8;
	t_sample m_history_20;
	t_sample m_history_19;
	t_sample m_history_18;
	t_sample samples_to_seconds;
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
		m_sw_28 = ((int)0);
		m_sw_29 = ((int)0);
		m_knob3_rate_30 = ((int)0);
		m_knob6_density_31 = ((int)0);
		m_knob5_glitchlen_32 = ((int)0);
		m_knob4_buflen_33 = ((int)0);
		m_segments_34.reset("segments", ((int)480000), ((int)1));
		__m_sah_35.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_37.reset(0);
		__m_pluseq_38.reset(0);
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
		samples_to_seconds = (1 / samplerate);
		int segments_dim = m_segments_34.dim;
		int segments_channels = m_segments_34.channels;
		t_sample mstosamps_2316 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_2305 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_2294 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_2327 = (((int)1) * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample mix_2807 = (m_history_26 + (((t_sample)0.003926980723806) * (m_knob4_buflen_33 - m_history_26)));
			t_sample mix_2342 = mix_2807;
			t_sample mix_2808 = (m_history_25 + (((t_sample)0.003926980723806) * (mix_2342 - m_history_25)));
			t_sample mix_2340 = mix_2808;
			t_sample mix_2809 = (m_history_24 + (((t_sample)0.003926980723806) * (mix_2340 - m_history_24)));
			t_sample mix_2338 = mix_2809;
			t_sample gen_2696 = mix_2338;
			t_sample history_2343_next_2345 = fixdenorm(mix_2342);
			t_sample history_2341_next_2346 = fixdenorm(mix_2340);
			t_sample history_2339_next_2347 = fixdenorm(mix_2338);
			t_sample expr_2718 = (((int)1) - sqrt((((int)1) - gen_2696)));
			t_sample sah_2712 = __m_sah_35(m_history_23, m_sw_28, ((int)0));
			t_sample gen_2714 = sah_2712;
			t_sample rsub_2710 = (((int)1) - sah_2712);
			t_sample history_2711_next_2713 = fixdenorm(rsub_2710);
			t_sample out3 = gen_2714;
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample add_2717 = (gen_2714 + ((int)1));
			t_sample choice_36 = int(add_2717);
			t_sample gate_2715 = (((choice_36 >= 1) && (choice_36 < 2)) ? in1 : 0);
			t_sample gate_2716 = ((choice_36 >= 2) ? in1 : 0);
			t_sample mix_2810 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob1_wetdry_27 - m_history_22)));
			t_sample mix_2720 = mix_2810;
			t_sample mix_2811 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_2720 - m_history_21)));
			t_sample mix_2726 = mix_2811;
			t_sample mix_2812 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_2726 - m_history_20)));
			t_sample mix_2728 = mix_2812;
			t_sample gen_2348 = mix_2728;
			t_sample history_2343_next_2722 = fixdenorm(mix_2720);
			t_sample history_2341_next_2719 = fixdenorm(mix_2726);
			t_sample history_2339_next_2725 = fixdenorm(mix_2728);
			t_sample sqrt_2334 = sqrt(gen_2348);
			t_sample rsub_2350 = (((int)1) - gen_2348);
			t_sample sqrt_2349 = sqrt(rsub_2350);
			t_sample mul_2337 = (sqrt_2349 * gate_2716);
			t_sample mul_2697 = (expr_2718 * ((int)480000));
			t_sample switch_2286 = (gen_2714 ? m_knob3_rate_30 : ((int)0));
			t_sample phasor_2708 = __m_phasor_37(switch_2286, samples_to_seconds);
			t_sample out4 = phasor_2708;
			t_sample plusequals_2709 = __m_pluseq_38.post(((int)1), m_history_1, 0);
			t_sample switch_2694 = (m_sw_29 ? ((int)-1) : plusequals_2709);
			int index_trunc_39 = fixnan(floor(switch_2694));
			bool index_ignore_40 = ((index_trunc_39 >= segments_dim) || (index_trunc_39 < 0));
			if ((!index_ignore_40)) {
				m_segments_34.write(gate_2716, index_trunc_39, 0);
				
			};
			int gte_2700 = (plusequals_2709 >= mul_2697);
			int eq_2699 = (gte_2700 == ((int)1));
			t_sample mix_2813 = (m_history_19 + (((t_sample)0.003926980723806) * (m_knob6_density_31 - m_history_19)));
			t_sample mix_2733 = mix_2813;
			t_sample mix_2814 = (m_history_18 + (((t_sample)0.003926980723806) * (mix_2733 - m_history_18)));
			t_sample mix_2740 = mix_2814;
			t_sample mix_2815 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_2740 - m_history_17)));
			t_sample mix_2738 = mix_2815;
			t_sample gen_2584 = mix_2738;
			t_sample history_2343_next_2741 = fixdenorm(mix_2733);
			t_sample history_2341_next_2737 = fixdenorm(mix_2740);
			t_sample history_2339_next_2736 = fixdenorm(mix_2738);
			t_sample sub_2819 = (gen_2584 - ((int)0));
			t_sample scale_2816 = ((safepow((sub_2819 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_2381 = m_delay_16.read_step(((int)8));
			t_sample tap_2383 = m_delay_15.read_step(((int)8));
			t_sample tap_2377 = m_delay_14.read_step(((int)8));
			t_sample tap_2379 = m_delay_13.read_step(((int)8));
			t_sample tap_2369 = m_delay_12.read_step(((int)8));
			t_sample tap_2371 = m_delay_11.read_step(((int)8));
			t_sample tap_2373 = m_delay_10.read_step(((int)9));
			t_sample tap_2375 = m_delay_9.read_step(((int)8));
			t_sample mul_2365 = (gen_2584 * ((int)12));
			int gte_2363 = (mul_2365 >= ((int)1));
			int gte_2362 = (mul_2365 >= ((int)2));
			int gte_2361 = (mul_2365 >= ((int)3));
			int gte_2364 = (mul_2365 >= ((int)0));
			int gte_2359 = (mul_2365 >= ((int)5));
			int gte_2360 = (mul_2365 >= ((int)4));
			int gte_2357 = (mul_2365 >= ((int)7));
			int gte_2358 = (mul_2365 >= ((int)6));
			int gte_2353 = (mul_2365 >= ((int)11));
			int gte_2354 = (mul_2365 >= ((int)10));
			int gte_2355 = (mul_2365 >= ((int)9));
			int gte_2356 = (mul_2365 >= ((int)8));
			t_sample mix_2820 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob5_glitchlen_32 - m_history_8)));
			t_sample mix_2751 = mix_2820;
			t_sample mix_2821 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_2751 - m_history_7)));
			t_sample mix_2746 = mix_2821;
			t_sample mix_2822 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_2746 - m_history_6)));
			t_sample mix_2748 = mix_2822;
			t_sample gen_2586 = mix_2748;
			t_sample history_2343_next_2752 = fixdenorm(mix_2751);
			t_sample history_2341_next_2749 = fixdenorm(mix_2746);
			t_sample history_2339_next_2745 = fixdenorm(mix_2748);
			t_sample mul_2331 = (mul_2697 * gen_2586);
			t_sample clamp_2585 = ((mul_2331 <= ((int)50)) ? ((int)50) : ((mul_2331 >= ((int)480000)) ? ((int)480000) : mul_2331));
			t_sample plusequals_2545 = __m_pluseq_41.post(((int)-1), tap_2381, 0);
			t_sample noise_2541 = noise();
			t_sample abs_2540 = fabs(noise_2541);
			t_sample sub_2536 = (clamp_2585 - ((int)50));
			t_sample mul_2539 = (abs_2540 * sub_2536);
			t_sample sah_2542 = __m_sah_42(mul_2539, tap_2381, ((t_sample)0.5));
			t_sample add_2533 = (sah_2542 + ((int)50));
			t_sample wrap_2543 = wrap(plusequals_2545, ((int)0), add_2533);
			t_sample div_2530 = safediv(wrap_2543, add_2533);
			t_sample expr_2550 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2530))));
			t_sample noise_2548 = noise();
			t_sample abs_2547 = fabs(noise_2548);
			t_sample mul_2546 = (abs_2547 * mul_2697);
			t_sample sah_2549 = __m_sah_43(mul_2546, tap_2381, ((t_sample)0.5));
			t_sample add_2531 = (sah_2549 + wrap_2543);
			t_sample switch_2534 = (gte_2359 ? add_2531 : ((int)-1));
			int index_trunc_44 = fixnan(floor(switch_2534));
			bool index_ignore_45 = ((index_trunc_44 >= segments_dim) || (index_trunc_44 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2537 = (index_ignore_45 ? 0 : m_segments_34.read(index_trunc_44, 0));
			t_sample index_segments_2538 = switch_2534;
			t_sample mul_2528 = (sample_segments_2537 * expr_2550);
			t_sample plusequals_2569 = __m_pluseq_46.post(((int)-1), tap_2383, 0);
			t_sample noise_2565 = noise();
			t_sample abs_2564 = fabs(noise_2565);
			t_sample sub_2560 = (clamp_2585 - ((int)50));
			t_sample mul_2563 = (abs_2564 * sub_2560);
			t_sample sah_2566 = __m_sah_47(mul_2563, tap_2383, ((t_sample)0.5));
			t_sample add_2557 = (sah_2566 + ((int)50));
			t_sample wrap_2567 = wrap(plusequals_2569, ((int)0), add_2557);
			t_sample div_2554 = safediv(wrap_2567, add_2557);
			t_sample expr_2574 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2554))));
			t_sample noise_2572 = noise();
			t_sample abs_2571 = fabs(noise_2572);
			t_sample mul_2570 = (abs_2571 * mul_2697);
			t_sample sah_2573 = __m_sah_48(mul_2570, tap_2383, ((t_sample)0.5));
			t_sample add_2555 = (sah_2573 + wrap_2567);
			t_sample switch_2558 = (gte_2360 ? add_2555 : ((int)-1));
			int index_trunc_49 = fixnan(floor(switch_2558));
			bool index_ignore_50 = ((index_trunc_49 >= segments_dim) || (index_trunc_49 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2561 = (index_ignore_50 ? 0 : m_segments_34.read(index_trunc_49, 0));
			t_sample index_segments_2562 = switch_2558;
			t_sample mul_2552 = (sample_segments_2561 * expr_2574);
			t_sample mul_2583 = ((mul_2552 + mul_2528) * ((t_sample)0.3));
			t_sample mul_2582 = ((mul_2552 + mul_2528) * ((t_sample)0.4));
			t_sample plusequals_2497 = __m_pluseq_51.post(((int)-1), tap_2377, 0);
			t_sample noise_2493 = noise();
			t_sample abs_2492 = fabs(noise_2493);
			t_sample sub_2488 = (clamp_2585 - ((int)50));
			t_sample mul_2491 = (abs_2492 * sub_2488);
			t_sample sah_2494 = __m_sah_52(mul_2491, tap_2377, ((t_sample)0.5));
			t_sample add_2485 = (sah_2494 + ((int)50));
			t_sample wrap_2495 = wrap(plusequals_2497, ((int)0), add_2485);
			t_sample div_2482 = safediv(wrap_2495, add_2485);
			t_sample expr_2502 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2482))));
			t_sample noise_2500 = noise();
			t_sample abs_2499 = fabs(noise_2500);
			t_sample mul_2498 = (abs_2499 * mul_2697);
			t_sample sah_2501 = __m_sah_53(mul_2498, tap_2377, ((t_sample)0.5));
			t_sample add_2483 = (sah_2501 + wrap_2495);
			t_sample switch_2486 = (gte_2357 ? add_2483 : ((int)-1));
			int index_trunc_54 = fixnan(floor(switch_2486));
			bool index_ignore_55 = ((index_trunc_54 >= segments_dim) || (index_trunc_54 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2489 = (index_ignore_55 ? 0 : m_segments_34.read(index_trunc_54, 0));
			t_sample index_segments_2490 = switch_2486;
			t_sample mul_2480 = (sample_segments_2489 * expr_2502);
			t_sample plusequals_2521 = __m_pluseq_56.post(((int)-1), tap_2379, 0);
			t_sample noise_2517 = noise();
			t_sample abs_2516 = fabs(noise_2517);
			t_sample sub_2512 = (clamp_2585 - ((int)50));
			t_sample mul_2515 = (abs_2516 * sub_2512);
			t_sample sah_2518 = __m_sah_57(mul_2515, tap_2379, ((t_sample)0.5));
			t_sample add_2509 = (sah_2518 + ((int)50));
			t_sample wrap_2519 = wrap(plusequals_2521, ((int)0), add_2509);
			t_sample div_2506 = safediv(wrap_2519, add_2509);
			t_sample expr_2526 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2506))));
			t_sample noise_2524 = noise();
			t_sample abs_2523 = fabs(noise_2524);
			t_sample mul_2522 = (abs_2523 * mul_2697);
			t_sample sah_2525 = __m_sah_58(mul_2522, tap_2379, ((t_sample)0.5));
			t_sample add_2507 = (sah_2525 + wrap_2519);
			t_sample switch_2510 = (gte_2358 ? add_2507 : ((int)-1));
			int index_trunc_59 = fixnan(floor(switch_2510));
			bool index_ignore_60 = ((index_trunc_59 >= segments_dim) || (index_trunc_59 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2513 = (index_ignore_60 ? 0 : m_segments_34.read(index_trunc_59, 0));
			t_sample index_segments_2514 = switch_2510;
			t_sample mul_2504 = (sample_segments_2513 * expr_2526);
			t_sample mul_2581 = ((mul_2504 + mul_2480) * ((t_sample)0.4));
			t_sample mul_2580 = ((mul_2504 + mul_2480) * ((t_sample)0.3));
			t_sample plusequals_2401 = __m_pluseq_61.post(((int)-1), tap_2369, 0);
			t_sample noise_2397 = noise();
			t_sample abs_2396 = fabs(noise_2397);
			t_sample sub_2392 = (clamp_2585 - ((int)50));
			t_sample mul_2395 = (abs_2396 * sub_2392);
			t_sample sah_2398 = __m_sah_62(mul_2395, tap_2369, ((t_sample)0.5));
			t_sample add_2389 = (sah_2398 + ((int)50));
			t_sample wrap_2399 = wrap(plusequals_2401, ((int)0), add_2389);
			t_sample div_2386 = safediv(wrap_2399, add_2389);
			t_sample expr_2406 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2386))));
			t_sample noise_2404 = noise();
			t_sample abs_2403 = fabs(noise_2404);
			t_sample mul_2402 = (abs_2403 * mul_2697);
			t_sample sah_2405 = __m_sah_63(mul_2402, tap_2369, ((t_sample)0.5));
			t_sample add_2387 = (sah_2405 + wrap_2399);
			t_sample switch_2390 = (gte_2353 ? add_2387 : ((int)-1));
			int index_trunc_64 = fixnan(floor(switch_2390));
			bool index_ignore_65 = ((index_trunc_64 >= segments_dim) || (index_trunc_64 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2393 = (index_ignore_65 ? 0 : m_segments_34.read(index_trunc_64, 0));
			t_sample index_segments_2394 = switch_2390;
			t_sample mul_2384 = (sample_segments_2393 * expr_2406);
			t_sample plusequals_2425 = __m_pluseq_66.post(((int)-1), tap_2371, 0);
			t_sample noise_2421 = noise();
			t_sample abs_2420 = fabs(noise_2421);
			t_sample sub_2416 = (clamp_2585 - ((int)50));
			t_sample mul_2419 = (abs_2420 * sub_2416);
			t_sample sah_2422 = __m_sah_67(mul_2419, tap_2371, ((t_sample)0.5));
			t_sample add_2413 = (sah_2422 + ((int)50));
			t_sample wrap_2423 = wrap(plusequals_2425, ((int)0), add_2413);
			t_sample div_2410 = safediv(wrap_2423, add_2413);
			t_sample expr_2430 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2410))));
			t_sample noise_2428 = noise();
			t_sample abs_2427 = fabs(noise_2428);
			t_sample mul_2426 = (abs_2427 * mul_2697);
			t_sample sah_2429 = __m_sah_68(mul_2426, tap_2371, ((t_sample)0.5));
			t_sample add_2411 = (sah_2429 + wrap_2423);
			t_sample switch_2414 = (gte_2354 ? add_2411 : ((int)-1));
			int index_trunc_69 = fixnan(floor(switch_2414));
			bool index_ignore_70 = ((index_trunc_69 >= segments_dim) || (index_trunc_69 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2417 = (index_ignore_70 ? 0 : m_segments_34.read(index_trunc_69, 0));
			t_sample index_segments_2418 = switch_2414;
			t_sample mul_2408 = (sample_segments_2417 * expr_2430);
			t_sample mul_2577 = ((mul_2408 + mul_2384) * ((t_sample)0.5));
			t_sample mul_2576 = ((mul_2408 + mul_2384) * ((t_sample)0.2));
			t_sample plusequals_2449 = __m_pluseq_71.post(((int)-1), tap_2373, 0);
			t_sample noise_2445 = noise();
			t_sample abs_2444 = fabs(noise_2445);
			t_sample sub_2440 = (clamp_2585 - ((int)50));
			t_sample mul_2443 = (abs_2444 * sub_2440);
			t_sample sah_2446 = __m_sah_72(mul_2443, tap_2373, ((t_sample)0.5));
			t_sample add_2437 = (sah_2446 + ((int)50));
			t_sample wrap_2447 = wrap(plusequals_2449, ((int)0), add_2437);
			t_sample div_2434 = safediv(wrap_2447, add_2437);
			t_sample expr_2454 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2434))));
			t_sample noise_2452 = noise();
			t_sample abs_2451 = fabs(noise_2452);
			t_sample mul_2450 = (abs_2451 * mul_2697);
			t_sample sah_2453 = __m_sah_73(mul_2450, tap_2373, ((t_sample)0.5));
			t_sample add_2435 = (sah_2453 + wrap_2447);
			t_sample switch_2438 = (gte_2355 ? add_2435 : ((int)-1));
			int index_trunc_74 = fixnan(floor(switch_2438));
			bool index_ignore_75 = ((index_trunc_74 >= segments_dim) || (index_trunc_74 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2441 = (index_ignore_75 ? 0 : m_segments_34.read(index_trunc_74, 0));
			t_sample index_segments_2442 = switch_2438;
			t_sample mul_2432 = (sample_segments_2441 * expr_2454);
			t_sample plusequals_2473 = __m_pluseq_76.post(((int)-1), tap_2375, 0);
			t_sample noise_2469 = noise();
			t_sample abs_2468 = fabs(noise_2469);
			t_sample sub_2464 = (clamp_2585 - ((int)50));
			t_sample mul_2467 = (abs_2468 * sub_2464);
			t_sample sah_2470 = __m_sah_77(mul_2467, tap_2375, ((t_sample)0.5));
			t_sample add_2461 = (sah_2470 + ((int)50));
			t_sample wrap_2471 = wrap(plusequals_2473, ((int)0), add_2461);
			t_sample div_2458 = safediv(wrap_2471, add_2461);
			t_sample expr_2478 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2458))));
			t_sample noise_2476 = noise();
			t_sample abs_2475 = fabs(noise_2476);
			t_sample mul_2474 = (abs_2475 * mul_2697);
			t_sample sah_2477 = __m_sah_78(mul_2474, tap_2375, ((t_sample)0.5));
			t_sample add_2459 = (sah_2477 + wrap_2471);
			t_sample switch_2462 = (gte_2356 ? add_2459 : ((int)-1));
			int index_trunc_79 = fixnan(floor(switch_2462));
			bool index_ignore_80 = ((index_trunc_79 >= segments_dim) || (index_trunc_79 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2465 = (index_ignore_80 ? 0 : m_segments_34.read(index_trunc_79, 0));
			t_sample index_segments_2466 = switch_2462;
			t_sample mul_2456 = (sample_segments_2465 * expr_2478);
			t_sample mul_2579 = ((mul_2456 + mul_2432) * ((t_sample)0.2));
			t_sample mul_2578 = ((mul_2456 + mul_2432) * ((t_sample)0.5));
			int gt_2667 = (phasor_2708 > ((t_sample)0.49));
			int change_2666 = __m_change_81(gt_2667);
			int eq_2665 = (change_2666 == ((int)1));
			t_sample add_2314 = (m_history_5 + ((int)1));
			int gt_2313 = (m_history_5 > mstosamps_2316);
			int mul_2312 = (eq_2665 * gt_2313);
			int and_2310 = (gt_2313 && eq_2665);
			t_sample switch_2311 = (and_2310 ? ((int)0) : add_2314);
			t_sample history_2315_next_2318 = fixdenorm(switch_2311);
			int plusequals_2652 = __m_pluseq_82.post(((int)-1), mul_2312, 0);
			t_sample noise_2648 = noise();
			t_sample abs_2647 = fabs(noise_2648);
			t_sample sub_2643 = (clamp_2585 - ((int)50));
			t_sample mul_2646 = (abs_2647 * sub_2643);
			t_sample sah_2649 = __m_sah_83(mul_2646, mul_2312, ((t_sample)0.5));
			t_sample add_2640 = (sah_2649 + ((int)50));
			t_sample wrap_2650 = wrap(plusequals_2652, ((int)0), add_2640);
			t_sample div_2637 = safediv(wrap_2650, add_2640);
			t_sample expr_2657 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2637))));
			t_sample noise_2655 = noise();
			t_sample abs_2654 = fabs(noise_2655);
			t_sample mul_2653 = (abs_2654 * mul_2697);
			t_sample sah_2656 = __m_sah_84(mul_2653, mul_2312, ((t_sample)0.5));
			t_sample add_2638 = (sah_2656 + wrap_2650);
			t_sample switch_2641 = (gte_2363 ? add_2638 : ((int)-1));
			int index_trunc_85 = fixnan(floor(switch_2641));
			bool index_ignore_86 = ((index_trunc_85 >= segments_dim) || (index_trunc_85 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2644 = (index_ignore_86 ? 0 : m_segments_34.read(index_trunc_85, 0));
			t_sample index_segments_2645 = switch_2641;
			t_sample mul_2635 = (sample_segments_2644 * expr_2657);
			int gt_2664 = (phasor_2708 > ((t_sample)0.51));
			int change_2663 = __m_change_87(gt_2664);
			int eq_2662 = (change_2663 == ((int)1));
			t_sample add_2303 = (m_history_4 + ((int)1));
			int gt_2302 = (m_history_4 > mstosamps_2305);
			int mul_2301 = (eq_2662 * gt_2302);
			int and_2299 = (gt_2302 && eq_2662);
			t_sample switch_2300 = (and_2299 ? ((int)0) : add_2303);
			t_sample history_2304_next_2307 = fixdenorm(switch_2300);
			int plusequals_2628 = __m_pluseq_88.post(((int)-1), mul_2301, 0);
			t_sample noise_2624 = noise();
			t_sample abs_2623 = fabs(noise_2624);
			t_sample sub_2619 = (clamp_2585 - ((int)50));
			t_sample mul_2622 = (abs_2623 * sub_2619);
			t_sample sah_2625 = __m_sah_89(mul_2622, mul_2301, ((t_sample)0.5));
			t_sample add_2616 = (sah_2625 + ((int)50));
			t_sample wrap_2626 = wrap(plusequals_2628, ((int)0), add_2616);
			t_sample div_2613 = safediv(wrap_2626, add_2616);
			t_sample expr_2633 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2613))));
			t_sample noise_2631 = noise();
			t_sample abs_2630 = fabs(noise_2631);
			t_sample mul_2629 = (abs_2630 * mul_2697);
			t_sample sah_2632 = __m_sah_90(mul_2629, mul_2301, ((t_sample)0.5));
			t_sample add_2614 = (sah_2632 + wrap_2626);
			t_sample switch_2617 = (gte_2362 ? add_2614 : ((int)-1));
			int index_trunc_91 = fixnan(floor(switch_2617));
			bool index_ignore_92 = ((index_trunc_91 >= segments_dim) || (index_trunc_91 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2620 = (index_ignore_92 ? 0 : m_segments_34.read(index_trunc_91, 0));
			t_sample index_segments_2621 = switch_2617;
			t_sample mul_2611 = (sample_segments_2620 * expr_2633);
			int gt_2661 = (phasor_2708 > ((t_sample)0.48));
			int change_2660 = __m_change_93(gt_2661);
			int eq_2659 = (change_2660 == ((int)1));
			t_sample add_2292 = (m_history_3 + ((int)1));
			int gt_2291 = (m_history_3 > mstosamps_2294);
			int mul_2290 = (eq_2659 * gt_2291);
			int and_2288 = (gt_2291 && eq_2659);
			t_sample switch_2289 = (and_2288 ? ((int)0) : add_2292);
			t_sample history_2293_next_2296 = fixdenorm(switch_2289);
			int plusequals_2604 = __m_pluseq_94.post(((int)-1), mul_2290, 0);
			t_sample noise_2600 = noise();
			t_sample abs_2599 = fabs(noise_2600);
			t_sample sub_2595 = (clamp_2585 - ((int)50));
			t_sample mul_2598 = (abs_2599 * sub_2595);
			t_sample sah_2601 = __m_sah_95(mul_2598, mul_2290, ((t_sample)0.5));
			t_sample add_2592 = (sah_2601 + ((int)50));
			t_sample wrap_2602 = wrap(plusequals_2604, ((int)0), add_2592);
			t_sample div_2589 = safediv(wrap_2602, add_2592);
			t_sample expr_2609 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2589))));
			t_sample noise_2607 = noise();
			t_sample abs_2606 = fabs(noise_2607);
			t_sample mul_2605 = (abs_2606 * mul_2697);
			t_sample sah_2608 = __m_sah_96(mul_2605, mul_2290, ((t_sample)0.5));
			t_sample add_2590 = (sah_2608 + wrap_2602);
			t_sample switch_2593 = (gte_2361 ? add_2590 : ((int)-1));
			int index_trunc_97 = fixnan(floor(switch_2593));
			bool index_ignore_98 = ((index_trunc_97 >= segments_dim) || (index_trunc_97 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2596 = (index_ignore_98 ? 0 : m_segments_34.read(index_trunc_97, 0));
			t_sample index_segments_2597 = switch_2593;
			t_sample mul_2587 = (sample_segments_2596 * expr_2609);
			int gt_2705 = (phasor_2708 > ((t_sample)0.5));
			int change_2704 = __m_change_99(gt_2705);
			int eq_2703 = (change_2704 == ((int)1));
			t_sample add_2325 = (m_history_2 + ((int)1));
			int gt_2324 = (m_history_2 > mstosamps_2327);
			int mul_2323 = (eq_2703 * gt_2324);
			int and_2321 = (gt_2324 && eq_2703);
			t_sample switch_2322 = (and_2321 ? ((int)0) : add_2325);
			t_sample history_2326_next_2329 = fixdenorm(switch_2322);
			int plusequals_2686 = __m_pluseq_100.post(((int)-1), mul_2323, 0);
			t_sample noise_2682 = noise();
			t_sample abs_2681 = fabs(noise_2682);
			t_sample sub_2677 = (clamp_2585 - ((int)50));
			t_sample mul_2680 = (abs_2681 * sub_2677);
			t_sample sah_2683 = __m_sah_101(mul_2680, mul_2323, ((t_sample)0.5));
			t_sample add_2674 = (sah_2683 + ((int)50));
			t_sample wrap_2684 = wrap(plusequals_2686, ((int)0), add_2674);
			t_sample div_2671 = safediv(wrap_2684, add_2674);
			t_sample expr_2691 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2671))));
			t_sample noise_2689 = noise();
			t_sample abs_2688 = fabs(noise_2689);
			t_sample mul_2687 = (abs_2688 * mul_2697);
			t_sample sah_2690 = __m_sah_102(mul_2687, mul_2323, ((t_sample)0.5));
			t_sample add_2672 = (sah_2690 + wrap_2684);
			t_sample switch_2675 = (gte_2364 ? add_2672 : ((int)-1));
			int index_trunc_103 = fixnan(floor(switch_2675));
			bool index_ignore_104 = ((index_trunc_103 >= segments_dim) || (index_trunc_103 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2678 = (index_ignore_104 ? 0 : m_segments_34.read(index_trunc_103, 0));
			t_sample index_segments_2679 = switch_2675;
			t_sample mul_2669 = (sample_segments_2678 * expr_2691);
			t_sample mul_2668 = ((((mul_2669 + mul_2587) + mul_2611) + mul_2635) * ((t_sample)0.7));
			t_sample mul_2367 = (((((mul_2579 + mul_2577) + mul_2581) + mul_2583) + mul_2668) * scale_2816);
			t_sample dcblock_2333 = __m_dcblock_105(mul_2367);
			t_sample mul_2336 = (sqrt_2334 * dcblock_2333);
			t_sample out1 = ((mul_2336 + mul_2337) + gate_2715);
			t_sample mul_2366 = (((((mul_2578 + mul_2576) + mul_2580) + mul_2582) + mul_2668) * scale_2816);
			t_sample dcblock_2332 = __m_dcblock_106(mul_2366);
			t_sample mul_2335 = (sqrt_2334 * dcblock_2332);
			t_sample out2 = ((mul_2335 + mul_2337) + gate_2715);
			t_sample history_2698_next_2758 = fixdenorm(eq_2699);
			m_history_26 = history_2343_next_2345;
			m_history_24 = history_2339_next_2347;
			m_history_25 = history_2341_next_2346;
			m_history_23 = history_2711_next_2713;
			m_history_22 = history_2343_next_2722;
			m_history_20 = history_2339_next_2725;
			m_history_21 = history_2341_next_2719;
			m_history_19 = history_2343_next_2741;
			m_history_17 = history_2339_next_2736;
			m_history_18 = history_2341_next_2737;
			m_delay_16.write(mul_2312);
			m_delay_15.write(mul_2323);
			m_delay_14.write(mul_2290);
			m_delay_13.write(mul_2301);
			m_delay_12.write(tap_2377);
			m_delay_11.write(tap_2379);
			m_delay_10.write(tap_2381);
			m_delay_9.write(tap_2383);
			m_history_8 = history_2343_next_2752;
			m_history_6 = history_2339_next_2745;
			m_history_7 = history_2341_next_2749;
			m_history_5 = history_2315_next_2318;
			m_history_4 = history_2304_next_2307;
			m_history_3 = history_2293_next_2296;
			m_history_2 = history_2326_next_2329;
			m_history_1 = history_2698_next_2758;
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
	inline void set_sw1(t_param _value) {
		m_sw_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_rate(t_param _value) {
		m_knob3_rate_30 = (_value < 0.01 ? 0.01 : (_value > 16 ? 16 : _value));
	};
	inline void set_knob6_density(t_param _value) {
		m_knob6_density_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_glitchlen(t_param _value) {
		m_knob5_glitchlen_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 1: *value = self->m_knob3_rate_30; break;
		case 2: *value = self->m_knob4_buflen_33; break;
		case 3: *value = self->m_knob5_glitchlen_32; break;
		case 4: *value = self->m_knob6_density_31; break;
		
		case 6: *value = self->m_sw_28; break;
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
	// initialize parameter 1 ("m_knob3_rate_30")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_rate_30;
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
	// initialize parameter 3 ("m_knob5_glitchlen_32")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_glitchlen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_glitchlen_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_density_31")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_density";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_density_31;
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
