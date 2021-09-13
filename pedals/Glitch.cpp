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
	t_sample m_knob3_thresh_32;
	t_sample m_sw_33;
	t_sample m_history_3;
	t_sample m_sw_31;
	t_sample samplerate;
	t_sample m_knob6_density_27;
	t_sample m_knob4_buflen_30;
	t_sample m_knob5_glitchlen_28;
	t_sample m_knob1_wetdry_29;
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
		m_knob6_density_27 = ((int)0);
		m_knob5_glitchlen_28 = ((int)0);
		m_knob1_wetdry_29 = ((int)0);
		m_knob4_buflen_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_knob3_thresh_32 = ((int)0);
		m_sw_33 = ((int)0);
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
		t_sample mstosamps_2742 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_2740 = (((int)100) * (samplerate * 0.001));
		t_sample iup_41 = (1 / maximum(1, abs(mstosamps_2742)));
		t_sample idown_42 = (1 / maximum(1, abs(mstosamps_2740)));
		t_sample mstosamps_2353 = (((int)1) * (samplerate * 0.001));
		t_sample mul_2688 = (m_knob3_thresh_32 * ((t_sample)0.95));
		t_sample mstosamps_2342 = (((int)1) * (samplerate * 0.001));
		t_sample mul_2687 = (m_knob3_thresh_32 * ((t_sample)1.03));
		t_sample mstosamps_2331 = (((int)1) * (samplerate * 0.001));
		t_sample mul_2686 = (m_knob3_thresh_32 * ((t_sample)0.98));
		t_sample mstosamps_2320 = (((int)1) * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_2748 = __m_sah_35(m_history_26, m_sw_33, ((int)0));
			t_sample gen_2750 = sah_2748;
			t_sample rsub_2746 = (((int)1) - sah_2748);
			t_sample history_2747_next_2749 = fixdenorm(rsub_2746);
			t_sample out3 = gen_2750;
			t_sample mix_2843 = (m_history_25 + (((t_sample)0.003926980723806) * (m_knob4_buflen_30 - m_history_25)));
			t_sample mix_2368 = mix_2843;
			t_sample mix_2844 = (m_history_24 + (((t_sample)0.003926980723806) * (mix_2368 - m_history_24)));
			t_sample mix_2366 = mix_2844;
			t_sample mix_2845 = (m_history_23 + (((t_sample)0.003926980723806) * (mix_2366 - m_history_23)));
			t_sample mix_2364 = mix_2845;
			t_sample gen_2726 = mix_2364;
			t_sample history_2369_next_2371 = fixdenorm(mix_2368);
			t_sample history_2367_next_2372 = fixdenorm(mix_2366);
			t_sample history_2365_next_2373 = fixdenorm(mix_2364);
			t_sample expr_2754 = (((int)1) - sqrt((((int)1) - gen_2726)));
			t_sample add_2753 = (gen_2750 + ((int)1));
			t_sample choice_36 = int(add_2753);
			t_sample gate_2751 = (((choice_36 >= 1) && (choice_36 < 2)) ? in1 : 0);
			t_sample gate_2752 = ((choice_36 >= 2) ? in1 : 0);
			t_sample mix_2846 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob1_wetdry_29 - m_history_22)));
			t_sample mix_2755 = mix_2846;
			t_sample mix_2847 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_2755 - m_history_21)));
			t_sample mix_2758 = mix_2847;
			t_sample mix_2848 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_2758 - m_history_20)));
			t_sample mix_2762 = mix_2848;
			t_sample gen_2374 = mix_2762;
			t_sample history_2369_next_2760 = fixdenorm(mix_2755);
			t_sample history_2367_next_2757 = fixdenorm(mix_2758);
			t_sample history_2365_next_2763 = fixdenorm(mix_2762);
			t_sample sqrt_2360 = sqrt(gen_2374);
			t_sample rsub_2376 = (((int)1) - gen_2374);
			t_sample sqrt_2375 = sqrt(rsub_2376);
			t_sample mul_2363 = (sqrt_2375 * gate_2752);
			t_sample mul_2727 = (expr_2754 * ((int)480000));
			t_sample plusequals_2744 = __m_pluseq_37.post(((int)1), m_history_1, 0);
			t_sample switch_2724 = (m_sw_31 ? ((int)-1) : plusequals_2744);
			int index_trunc_38 = fixnan(floor(switch_2724));
			bool index_ignore_39 = ((index_trunc_38 >= segments_dim) || (index_trunc_38 < 0));
			if ((!index_ignore_39)) {
				m_segments_34.write(gate_2752, index_trunc_38, 0);
				
			};
			int gte_2730 = (plusequals_2744 >= mul_2727);
			int eq_2729 = (gte_2730 == ((int)1));
			t_sample abs_2745 = fabs(gate_2752);
			t_sample mul_2378 = (abs_2745 * ((int)30));
			__m_slide_40 = fixdenorm((__m_slide_40 + (((mul_2378 > __m_slide_40) ? iup_41 : idown_42) * (mul_2378 - __m_slide_40))));
			t_sample slide_2743 = __m_slide_40;
			t_sample clamp_2738 = ((slide_2743 <= ((int)0)) ? ((int)0) : ((slide_2743 >= ((int)1)) ? ((int)1) : slide_2743));
			t_sample out4 = clamp_2738;
			t_sample mix_2849 = (m_history_19 + (((t_sample)0.003926980723806) * (m_knob6_density_27 - m_history_19)));
			t_sample mix_2772 = mix_2849;
			t_sample mix_2850 = (m_history_18 + (((t_sample)0.003926980723806) * (mix_2772 - m_history_18)));
			t_sample mix_2774 = mix_2850;
			t_sample mix_2851 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_2774 - m_history_17)));
			t_sample mix_2770 = mix_2851;
			t_sample gen_2611 = mix_2770;
			t_sample history_2369_next_2769 = fixdenorm(mix_2772);
			t_sample history_2367_next_2773 = fixdenorm(mix_2774);
			t_sample history_2365_next_2771 = fixdenorm(mix_2770);
			t_sample sub_2855 = (gen_2611 - ((int)0));
			t_sample scale_2852 = ((safepow((sub_2855 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_2408 = m_delay_16.read_step(((int)8));
			t_sample tap_2410 = m_delay_15.read_step(((int)8));
			t_sample tap_2404 = m_delay_14.read_step(((int)8));
			t_sample tap_2406 = m_delay_13.read_step(((int)8));
			t_sample tap_2396 = m_delay_12.read_step(((int)8));
			t_sample tap_2398 = m_delay_11.read_step(((int)8));
			t_sample tap_2400 = m_delay_10.read_step(((int)9));
			t_sample tap_2402 = m_delay_9.read_step(((int)8));
			t_sample mul_2392 = (gen_2611 * ((int)12));
			int gte_2390 = (mul_2392 >= ((int)1));
			int gte_2389 = (mul_2392 >= ((int)2));
			int gte_2388 = (mul_2392 >= ((int)3));
			int gte_2391 = (mul_2392 >= ((int)0));
			int gte_2386 = (mul_2392 >= ((int)5));
			int gte_2387 = (mul_2392 >= ((int)4));
			int gte_2384 = (mul_2392 >= ((int)7));
			int gte_2385 = (mul_2392 >= ((int)6));
			int gte_2380 = (mul_2392 >= ((int)11));
			int gte_2381 = (mul_2392 >= ((int)10));
			int gte_2382 = (mul_2392 >= ((int)9));
			int gte_2383 = (mul_2392 >= ((int)8));
			t_sample mix_2856 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob5_glitchlen_28 - m_history_8)));
			t_sample mix_2782 = mix_2856;
			t_sample mix_2857 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_2782 - m_history_7)));
			t_sample mix_2788 = mix_2857;
			t_sample mix_2858 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_2788 - m_history_6)));
			t_sample mix_2781 = mix_2858;
			t_sample gen_2613 = mix_2781;
			t_sample history_2369_next_2786 = fixdenorm(mix_2782);
			t_sample history_2367_next_2783 = fixdenorm(mix_2788);
			t_sample history_2365_next_2787 = fixdenorm(mix_2781);
			t_sample mul_2357 = (mul_2727 * gen_2613);
			t_sample clamp_2612 = ((mul_2357 <= ((int)50)) ? ((int)50) : ((mul_2357 >= ((int)480000)) ? ((int)480000) : mul_2357));
			t_sample plusequals_2572 = __m_pluseq_43.post(((int)1), tap_2408, 0);
			t_sample noise_2567 = noise();
			t_sample abs_2566 = fabs(noise_2567);
			t_sample sub_2558 = (clamp_2612 - ((int)50));
			t_sample mul_2565 = (abs_2566 * sub_2558);
			t_sample sah_2568 = __m_sah_44(mul_2565, tap_2408, ((t_sample)0.5));
			t_sample add_2555 = (sah_2568 + ((int)50));
			t_sample mod_2564 = safemod(plusequals_2572, add_2555);
			t_sample div_2561 = safediv(mod_2564, add_2555);
			t_sample expr_2577 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2561))));
			t_sample noise_2575 = noise();
			t_sample abs_2574 = fabs(noise_2575);
			t_sample mul_2573 = (abs_2574 * mul_2727);
			t_sample sah_2576 = __m_sah_45(mul_2573, tap_2408, ((t_sample)0.5));
			t_sample add_2570 = (sah_2576 + mod_2564);
			t_sample mod_2569 = safemod(add_2570, mul_2727);
			t_sample switch_2556 = (gte_2386 ? mod_2569 : ((int)-1));
			int index_trunc_46 = fixnan(floor(switch_2556));
			bool index_ignore_47 = ((index_trunc_46 >= segments_dim) || (index_trunc_46 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2562 = (index_ignore_47 ? 0 : m_segments_34.read(index_trunc_46, 0));
			t_sample index_segments_2563 = switch_2556;
			t_sample mul_2559 = (sample_segments_2562 * expr_2577);
			t_sample plusequals_2596 = __m_pluseq_48.post(((int)1), tap_2410, 0);
			t_sample noise_2591 = noise();
			t_sample abs_2590 = fabs(noise_2591);
			t_sample sub_2582 = (clamp_2612 - ((int)50));
			t_sample mul_2589 = (abs_2590 * sub_2582);
			t_sample sah_2592 = __m_sah_49(mul_2589, tap_2410, ((t_sample)0.5));
			t_sample add_2579 = (sah_2592 + ((int)50));
			t_sample mod_2588 = safemod(plusequals_2596, add_2579);
			t_sample div_2585 = safediv(mod_2588, add_2579);
			t_sample expr_2601 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2585))));
			t_sample noise_2599 = noise();
			t_sample abs_2598 = fabs(noise_2599);
			t_sample mul_2597 = (abs_2598 * mul_2727);
			t_sample sah_2600 = __m_sah_50(mul_2597, tap_2410, ((t_sample)0.5));
			t_sample add_2594 = (sah_2600 + mod_2588);
			t_sample mod_2593 = safemod(add_2594, mul_2727);
			t_sample switch_2580 = (gte_2387 ? mod_2593 : ((int)-1));
			int index_trunc_51 = fixnan(floor(switch_2580));
			bool index_ignore_52 = ((index_trunc_51 >= segments_dim) || (index_trunc_51 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2586 = (index_ignore_52 ? 0 : m_segments_34.read(index_trunc_51, 0));
			t_sample index_segments_2587 = switch_2580;
			t_sample mul_2583 = (sample_segments_2586 * expr_2601);
			t_sample mul_2610 = ((mul_2583 + mul_2559) * ((t_sample)0.3));
			t_sample mul_2609 = ((mul_2583 + mul_2559) * ((t_sample)0.4));
			t_sample plusequals_2524 = __m_pluseq_53.post(((int)1), tap_2404, 0);
			t_sample noise_2519 = noise();
			t_sample abs_2518 = fabs(noise_2519);
			t_sample sub_2510 = (clamp_2612 - ((int)50));
			t_sample mul_2517 = (abs_2518 * sub_2510);
			t_sample sah_2520 = __m_sah_54(mul_2517, tap_2404, ((t_sample)0.5));
			t_sample add_2507 = (sah_2520 + ((int)50));
			t_sample mod_2516 = safemod(plusequals_2524, add_2507);
			t_sample div_2513 = safediv(mod_2516, add_2507);
			t_sample expr_2529 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2513))));
			t_sample noise_2527 = noise();
			t_sample abs_2526 = fabs(noise_2527);
			t_sample mul_2525 = (abs_2526 * mul_2727);
			t_sample sah_2528 = __m_sah_55(mul_2525, tap_2404, ((t_sample)0.5));
			t_sample add_2522 = (sah_2528 + mod_2516);
			t_sample mod_2521 = safemod(add_2522, mul_2727);
			t_sample switch_2508 = (gte_2384 ? mod_2521 : ((int)-1));
			int index_trunc_56 = fixnan(floor(switch_2508));
			bool index_ignore_57 = ((index_trunc_56 >= segments_dim) || (index_trunc_56 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2514 = (index_ignore_57 ? 0 : m_segments_34.read(index_trunc_56, 0));
			t_sample index_segments_2515 = switch_2508;
			t_sample mul_2511 = (sample_segments_2514 * expr_2529);
			t_sample plusequals_2548 = __m_pluseq_58.post(((int)1), tap_2406, 0);
			t_sample noise_2543 = noise();
			t_sample abs_2542 = fabs(noise_2543);
			t_sample sub_2534 = (clamp_2612 - ((int)50));
			t_sample mul_2541 = (abs_2542 * sub_2534);
			t_sample sah_2544 = __m_sah_59(mul_2541, tap_2406, ((t_sample)0.5));
			t_sample add_2531 = (sah_2544 + ((int)50));
			t_sample mod_2540 = safemod(plusequals_2548, add_2531);
			t_sample div_2537 = safediv(mod_2540, add_2531);
			t_sample expr_2553 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2537))));
			t_sample noise_2551 = noise();
			t_sample abs_2550 = fabs(noise_2551);
			t_sample mul_2549 = (abs_2550 * mul_2727);
			t_sample sah_2552 = __m_sah_60(mul_2549, tap_2406, ((t_sample)0.5));
			t_sample add_2546 = (sah_2552 + mod_2540);
			t_sample mod_2545 = safemod(add_2546, mul_2727);
			t_sample switch_2532 = (gte_2385 ? mod_2545 : ((int)-1));
			int index_trunc_61 = fixnan(floor(switch_2532));
			bool index_ignore_62 = ((index_trunc_61 >= segments_dim) || (index_trunc_61 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2538 = (index_ignore_62 ? 0 : m_segments_34.read(index_trunc_61, 0));
			t_sample index_segments_2539 = switch_2532;
			t_sample mul_2535 = (sample_segments_2538 * expr_2553);
			t_sample mul_2608 = ((mul_2535 + mul_2511) * ((t_sample)0.4));
			t_sample mul_2607 = ((mul_2535 + mul_2511) * ((t_sample)0.3));
			t_sample plusequals_2428 = __m_pluseq_63.post(((int)1), tap_2396, 0);
			t_sample noise_2423 = noise();
			t_sample abs_2422 = fabs(noise_2423);
			t_sample sub_2414 = (clamp_2612 - ((int)50));
			t_sample mul_2421 = (abs_2422 * sub_2414);
			t_sample sah_2424 = __m_sah_64(mul_2421, tap_2396, ((t_sample)0.5));
			t_sample add_2411 = (sah_2424 + ((int)50));
			t_sample mod_2420 = safemod(plusequals_2428, add_2411);
			t_sample div_2417 = safediv(mod_2420, add_2411);
			t_sample expr_2433 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2417))));
			t_sample noise_2431 = noise();
			t_sample abs_2430 = fabs(noise_2431);
			t_sample mul_2429 = (abs_2430 * mul_2727);
			t_sample sah_2432 = __m_sah_65(mul_2429, tap_2396, ((t_sample)0.5));
			t_sample add_2426 = (sah_2432 + mod_2420);
			t_sample mod_2425 = safemod(add_2426, mul_2727);
			t_sample switch_2412 = (gte_2380 ? mod_2425 : ((int)-1));
			int index_trunc_66 = fixnan(floor(switch_2412));
			bool index_ignore_67 = ((index_trunc_66 >= segments_dim) || (index_trunc_66 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2418 = (index_ignore_67 ? 0 : m_segments_34.read(index_trunc_66, 0));
			t_sample index_segments_2419 = switch_2412;
			t_sample mul_2415 = (sample_segments_2418 * expr_2433);
			t_sample plusequals_2452 = __m_pluseq_68.post(((int)1), tap_2398, 0);
			t_sample noise_2447 = noise();
			t_sample abs_2446 = fabs(noise_2447);
			t_sample sub_2438 = (clamp_2612 - ((int)50));
			t_sample mul_2445 = (abs_2446 * sub_2438);
			t_sample sah_2448 = __m_sah_69(mul_2445, tap_2398, ((t_sample)0.5));
			t_sample add_2435 = (sah_2448 + ((int)50));
			t_sample mod_2444 = safemod(plusequals_2452, add_2435);
			t_sample div_2441 = safediv(mod_2444, add_2435);
			t_sample expr_2457 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2441))));
			t_sample noise_2455 = noise();
			t_sample abs_2454 = fabs(noise_2455);
			t_sample mul_2453 = (abs_2454 * mul_2727);
			t_sample sah_2456 = __m_sah_70(mul_2453, tap_2398, ((t_sample)0.5));
			t_sample add_2450 = (sah_2456 + mod_2444);
			t_sample mod_2449 = safemod(add_2450, mul_2727);
			t_sample switch_2436 = (gte_2381 ? mod_2449 : ((int)-1));
			int index_trunc_71 = fixnan(floor(switch_2436));
			bool index_ignore_72 = ((index_trunc_71 >= segments_dim) || (index_trunc_71 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2442 = (index_ignore_72 ? 0 : m_segments_34.read(index_trunc_71, 0));
			t_sample index_segments_2443 = switch_2436;
			t_sample mul_2439 = (sample_segments_2442 * expr_2457);
			t_sample mul_2604 = ((mul_2439 + mul_2415) * ((t_sample)0.5));
			t_sample mul_2603 = ((mul_2439 + mul_2415) * ((t_sample)0.2));
			t_sample plusequals_2476 = __m_pluseq_73.post(((int)1), tap_2400, 0);
			t_sample noise_2471 = noise();
			t_sample abs_2470 = fabs(noise_2471);
			t_sample sub_2462 = (clamp_2612 - ((int)50));
			t_sample mul_2469 = (abs_2470 * sub_2462);
			t_sample sah_2472 = __m_sah_74(mul_2469, tap_2400, ((t_sample)0.5));
			t_sample add_2459 = (sah_2472 + ((int)50));
			t_sample mod_2468 = safemod(plusequals_2476, add_2459);
			t_sample div_2465 = safediv(mod_2468, add_2459);
			t_sample expr_2481 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2465))));
			t_sample noise_2479 = noise();
			t_sample abs_2478 = fabs(noise_2479);
			t_sample mul_2477 = (abs_2478 * mul_2727);
			t_sample sah_2480 = __m_sah_75(mul_2477, tap_2400, ((t_sample)0.5));
			t_sample add_2474 = (sah_2480 + mod_2468);
			t_sample mod_2473 = safemod(add_2474, mul_2727);
			t_sample switch_2460 = (gte_2382 ? mod_2473 : ((int)-1));
			int index_trunc_76 = fixnan(floor(switch_2460));
			bool index_ignore_77 = ((index_trunc_76 >= segments_dim) || (index_trunc_76 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2466 = (index_ignore_77 ? 0 : m_segments_34.read(index_trunc_76, 0));
			t_sample index_segments_2467 = switch_2460;
			t_sample mul_2463 = (sample_segments_2466 * expr_2481);
			t_sample plusequals_2500 = __m_pluseq_78.post(((int)1), tap_2402, 0);
			t_sample noise_2495 = noise();
			t_sample abs_2494 = fabs(noise_2495);
			t_sample sub_2486 = (clamp_2612 - ((int)50));
			t_sample mul_2493 = (abs_2494 * sub_2486);
			t_sample sah_2496 = __m_sah_79(mul_2493, tap_2402, ((t_sample)0.5));
			t_sample add_2483 = (sah_2496 + ((int)50));
			t_sample mod_2492 = safemod(plusequals_2500, add_2483);
			t_sample div_2489 = safediv(mod_2492, add_2483);
			t_sample expr_2505 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2489))));
			t_sample noise_2503 = noise();
			t_sample abs_2502 = fabs(noise_2503);
			t_sample mul_2501 = (abs_2502 * mul_2727);
			t_sample sah_2504 = __m_sah_80(mul_2501, tap_2402, ((t_sample)0.5));
			t_sample add_2498 = (sah_2504 + mod_2492);
			t_sample mod_2497 = safemod(add_2498, mul_2727);
			t_sample switch_2484 = (gte_2383 ? mod_2497 : ((int)-1));
			int index_trunc_81 = fixnan(floor(switch_2484));
			bool index_ignore_82 = ((index_trunc_81 >= segments_dim) || (index_trunc_81 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2490 = (index_ignore_82 ? 0 : m_segments_34.read(index_trunc_81, 0));
			t_sample index_segments_2491 = switch_2484;
			t_sample mul_2487 = (sample_segments_2490 * expr_2505);
			t_sample mul_2606 = ((mul_2487 + mul_2463) * ((t_sample)0.2));
			t_sample mul_2605 = ((mul_2487 + mul_2463) * ((t_sample)0.5));
			int gt_2735 = (clamp_2738 > m_knob3_thresh_32);
			int change_2734 = __m_change_83(gt_2735);
			int eq_2733 = (change_2734 == ((int)1));
			t_sample add_2351 = (m_history_5 + ((int)1));
			int gt_2350 = (m_history_5 > mstosamps_2353);
			int mul_2349 = (eq_2733 * gt_2350);
			int and_2347 = (gt_2350 && eq_2733);
			t_sample switch_2348 = (and_2347 ? ((int)0) : add_2351);
			t_sample history_2352_next_2355 = fixdenorm(switch_2348);
			int plusequals_2716 = __m_pluseq_84.post(((int)1), mul_2349, 0);
			t_sample noise_2711 = noise();
			t_sample abs_2710 = fabs(noise_2711);
			t_sample sub_2702 = (clamp_2612 - ((int)50));
			t_sample mul_2709 = (abs_2710 * sub_2702);
			t_sample sah_2712 = __m_sah_85(mul_2709, mul_2349, ((t_sample)0.5));
			t_sample add_2699 = (sah_2712 + ((int)50));
			t_sample mod_2708 = safemod(plusequals_2716, add_2699);
			t_sample div_2705 = safediv(mod_2708, add_2699);
			t_sample expr_2721 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2705))));
			t_sample noise_2719 = noise();
			t_sample abs_2718 = fabs(noise_2719);
			t_sample mul_2717 = (abs_2718 * mul_2727);
			t_sample sah_2720 = __m_sah_86(mul_2717, mul_2349, ((t_sample)0.5));
			t_sample add_2714 = (sah_2720 + mod_2708);
			t_sample mod_2713 = safemod(add_2714, mul_2727);
			t_sample switch_2700 = (gte_2391 ? mod_2713 : ((int)-1));
			int index_trunc_87 = fixnan(floor(switch_2700));
			bool index_ignore_88 = ((index_trunc_87 >= segments_dim) || (index_trunc_87 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2706 = (index_ignore_88 ? 0 : m_segments_34.read(index_trunc_87, 0));
			t_sample index_segments_2707 = switch_2700;
			t_sample mul_2703 = (sample_segments_2706 * expr_2721);
			int gt_2697 = (clamp_2738 > mul_2688);
			int change_2696 = __m_change_89(gt_2697);
			int eq_2695 = (change_2696 == ((int)1));
			t_sample add_2340 = (m_history_4 + ((int)1));
			int gt_2339 = (m_history_4 > mstosamps_2342);
			int mul_2338 = (eq_2695 * gt_2339);
			int and_2336 = (gt_2339 && eq_2695);
			t_sample switch_2337 = (and_2336 ? ((int)0) : add_2340);
			t_sample history_2341_next_2344 = fixdenorm(switch_2337);
			int plusequals_2679 = __m_pluseq_90.post(((int)1), mul_2338, 0);
			t_sample noise_2674 = noise();
			t_sample abs_2673 = fabs(noise_2674);
			t_sample sub_2665 = (clamp_2612 - ((int)50));
			t_sample mul_2672 = (abs_2673 * sub_2665);
			t_sample sah_2675 = __m_sah_91(mul_2672, mul_2338, ((t_sample)0.5));
			t_sample add_2662 = (sah_2675 + ((int)50));
			t_sample mod_2671 = safemod(plusequals_2679, add_2662);
			t_sample div_2668 = safediv(mod_2671, add_2662);
			t_sample expr_2684 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2668))));
			t_sample noise_2682 = noise();
			t_sample abs_2681 = fabs(noise_2682);
			t_sample mul_2680 = (abs_2681 * mul_2727);
			t_sample sah_2683 = __m_sah_92(mul_2680, mul_2338, ((t_sample)0.5));
			t_sample add_2677 = (sah_2683 + mod_2671);
			t_sample mod_2676 = safemod(add_2677, mul_2727);
			t_sample switch_2663 = (gte_2390 ? mod_2676 : ((int)-1));
			int index_trunc_93 = fixnan(floor(switch_2663));
			bool index_ignore_94 = ((index_trunc_93 >= segments_dim) || (index_trunc_93 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2669 = (index_ignore_94 ? 0 : m_segments_34.read(index_trunc_93, 0));
			t_sample index_segments_2670 = switch_2663;
			t_sample mul_2666 = (sample_segments_2669 * expr_2684);
			int gt_2694 = (clamp_2738 > mul_2687);
			int change_2693 = __m_change_95(gt_2694);
			int eq_2692 = (change_2693 == ((int)1));
			t_sample add_2329 = (m_history_3 + ((int)1));
			int gt_2328 = (m_history_3 > mstosamps_2331);
			int mul_2327 = (eq_2692 * gt_2328);
			int and_2325 = (gt_2328 && eq_2692);
			t_sample switch_2326 = (and_2325 ? ((int)0) : add_2329);
			t_sample history_2330_next_2333 = fixdenorm(switch_2326);
			int plusequals_2655 = __m_pluseq_96.post(((int)1), mul_2327, 0);
			t_sample noise_2650 = noise();
			t_sample abs_2649 = fabs(noise_2650);
			t_sample sub_2641 = (clamp_2612 - ((int)50));
			t_sample mul_2648 = (abs_2649 * sub_2641);
			t_sample sah_2651 = __m_sah_97(mul_2648, mul_2327, ((t_sample)0.5));
			t_sample add_2638 = (sah_2651 + ((int)50));
			t_sample mod_2647 = safemod(plusequals_2655, add_2638);
			t_sample div_2644 = safediv(mod_2647, add_2638);
			t_sample expr_2660 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2644))));
			t_sample noise_2658 = noise();
			t_sample abs_2657 = fabs(noise_2658);
			t_sample mul_2656 = (abs_2657 * mul_2727);
			t_sample sah_2659 = __m_sah_98(mul_2656, mul_2327, ((t_sample)0.5));
			t_sample add_2653 = (sah_2659 + mod_2647);
			t_sample mod_2652 = safemod(add_2653, mul_2727);
			t_sample switch_2639 = (gte_2389 ? mod_2652 : ((int)-1));
			int index_trunc_99 = fixnan(floor(switch_2639));
			bool index_ignore_100 = ((index_trunc_99 >= segments_dim) || (index_trunc_99 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2645 = (index_ignore_100 ? 0 : m_segments_34.read(index_trunc_99, 0));
			t_sample index_segments_2646 = switch_2639;
			t_sample mul_2642 = (sample_segments_2645 * expr_2660);
			int gt_2691 = (clamp_2738 > mul_2686);
			int change_2690 = __m_change_101(gt_2691);
			int eq_2689 = (change_2690 == ((int)1));
			t_sample add_2318 = (m_history_2 + ((int)1));
			int gt_2317 = (m_history_2 > mstosamps_2320);
			int mul_2316 = (eq_2689 * gt_2317);
			int and_2314 = (gt_2317 && eq_2689);
			t_sample switch_2315 = (and_2314 ? ((int)0) : add_2318);
			t_sample history_2319_next_2322 = fixdenorm(switch_2315);
			int plusequals_2631 = __m_pluseq_102.post(((int)1), mul_2316, 0);
			t_sample noise_2626 = noise();
			t_sample abs_2625 = fabs(noise_2626);
			t_sample sub_2617 = (clamp_2612 - ((int)50));
			t_sample mul_2624 = (abs_2625 * sub_2617);
			t_sample sah_2627 = __m_sah_103(mul_2624, mul_2316, ((t_sample)0.5));
			t_sample add_2614 = (sah_2627 + ((int)50));
			t_sample mod_2623 = safemod(plusequals_2631, add_2614);
			t_sample div_2620 = safediv(mod_2623, add_2614);
			t_sample expr_2636 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2620))));
			t_sample noise_2634 = noise();
			t_sample abs_2633 = fabs(noise_2634);
			t_sample mul_2632 = (abs_2633 * mul_2727);
			t_sample sah_2635 = __m_sah_104(mul_2632, mul_2316, ((t_sample)0.5));
			t_sample add_2629 = (sah_2635 + mod_2623);
			t_sample mod_2628 = safemod(add_2629, mul_2727);
			t_sample switch_2615 = (gte_2388 ? mod_2628 : ((int)-1));
			int index_trunc_105 = fixnan(floor(switch_2615));
			bool index_ignore_106 = ((index_trunc_105 >= segments_dim) || (index_trunc_105 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2621 = (index_ignore_106 ? 0 : m_segments_34.read(index_trunc_105, 0));
			t_sample index_segments_2622 = switch_2615;
			t_sample mul_2618 = (sample_segments_2621 * expr_2636);
			t_sample mul_2698 = ((((mul_2703 + mul_2618) + mul_2642) + mul_2666) * ((t_sample)0.7));
			t_sample mul_2394 = (((((mul_2606 + mul_2604) + mul_2608) + mul_2610) + mul_2698) * scale_2852);
			t_sample dcblock_2359 = __m_dcblock_107(mul_2394);
			t_sample mul_2362 = (sqrt_2360 * dcblock_2359);
			t_sample out1 = ((mul_2362 + mul_2363) + gate_2751);
			t_sample mul_2393 = (((((mul_2605 + mul_2603) + mul_2607) + mul_2609) + mul_2698) * scale_2852);
			t_sample dcblock_2358 = __m_dcblock_108(mul_2393);
			t_sample mul_2361 = (sqrt_2360 * dcblock_2358);
			t_sample out2 = ((mul_2361 + mul_2363) + gate_2751);
			t_sample history_2728_next_2794 = fixdenorm(eq_2729);
			m_history_26 = history_2747_next_2749;
			m_history_25 = history_2369_next_2371;
			m_history_23 = history_2365_next_2373;
			m_history_24 = history_2367_next_2372;
			m_history_22 = history_2369_next_2760;
			m_history_20 = history_2365_next_2763;
			m_history_21 = history_2367_next_2757;
			m_history_19 = history_2369_next_2769;
			m_history_17 = history_2365_next_2771;
			m_history_18 = history_2367_next_2773;
			m_delay_16.write(mul_2338);
			m_delay_15.write(mul_2349);
			m_delay_14.write(mul_2316);
			m_delay_13.write(mul_2327);
			m_delay_12.write(tap_2404);
			m_delay_11.write(tap_2406);
			m_delay_10.write(tap_2408);
			m_delay_9.write(tap_2410);
			m_history_8 = history_2369_next_2786;
			m_history_6 = history_2365_next_2787;
			m_history_7 = history_2367_next_2783;
			m_history_5 = history_2352_next_2355;
			m_history_4 = history_2341_next_2344;
			m_history_3 = history_2330_next_2333;
			m_history_2 = history_2319_next_2322;
			m_history_1 = history_2728_next_2794;
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
	inline void set_knob6_density(t_param _value) {
		m_knob6_density_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_glitchlen(t_param _value) {
		m_knob5_glitchlen_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_thresh(t_param _value) {
		m_knob3_thresh_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob1_wetdry_29; break;
		case 1: *value = self->m_knob3_thresh_32; break;
		case 2: *value = self->m_knob4_buflen_30; break;
		case 3: *value = self->m_knob5_glitchlen_28; break;
		case 4: *value = self->m_knob6_density_27; break;
		
		case 6: *value = self->m_sw_33; break;
		case 7: *value = self->m_sw_31; break;
		
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
	// initialize parameter 1 ("m_knob3_thresh_32")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_thresh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_thresh_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
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
	// initialize parameter 3 ("m_knob5_glitchlen_28")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_glitchlen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_glitchlen_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_density_27")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_density";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_density_27;
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
	// initialize parameter 6 ("m_sw_33")
	pi = self->__commonstate.params + 6;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_sw_31")
	pi = self->__commonstate.params + 7;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_31;
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
