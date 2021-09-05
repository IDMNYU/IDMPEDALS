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
	t_sample m_knob3_rate_33;
	t_sample m_history_25;
	t_sample m_history_3;
	t_sample m_knob6_density_32;
	t_sample samplerate;
	t_sample m_knob1_wetdry_28;
	t_sample m_knob4_buflen_31;
	t_sample m_sw_29;
	t_sample m_sw_30;
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
	t_sample m_knob5_glitchlen_27;
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
		m_knob1_wetdry_28 = ((int)0);
		m_sw_29 = ((int)0);
		m_sw_30 = ((int)0);
		m_knob4_buflen_31 = ((int)0);
		m_knob6_density_32 = ((int)0);
		m_knob3_rate_33 = ((int)0);
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
		t_sample mstosamps_2357 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_2346 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_2335 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_2368 = (((int)1) * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_2207 = __m_sah_35(m_history_26, m_sw_30, ((int)0));
			t_sample gen_2741 = sah_2207;
			t_sample rsub_2205 = (((int)1) - sah_2207);
			t_sample history_2206_next_2208 = fixdenorm(rsub_2205);
			t_sample out3 = gen_2741;
			t_sample mix_2834 = (m_history_25 + (((t_sample)0.003926980723806) * (m_knob4_buflen_31 - m_history_25)));
			t_sample mix_1827 = mix_2834;
			t_sample mix_2835 = (m_history_24 + (((t_sample)0.003926980723806) * (mix_1827 - m_history_24)));
			t_sample mix_1825 = mix_2835;
			t_sample mix_2836 = (m_history_23 + (((t_sample)0.003926980723806) * (mix_1825 - m_history_23)));
			t_sample mix_1823 = mix_2836;
			t_sample gen_2727 = mix_1823;
			t_sample history_1828_next_1830 = fixdenorm(mix_1827);
			t_sample history_1826_next_1831 = fixdenorm(mix_1825);
			t_sample history_1824_next_1832 = fixdenorm(mix_1823);
			t_sample expr_2745 = (((int)1) - sqrt((((int)1) - gen_2727)));
			t_sample add_2744 = (gen_2741 + ((int)1));
			t_sample choice_36 = int(add_2744);
			t_sample gate_2742 = (((choice_36 >= 1) && (choice_36 < 2)) ? in1 : 0);
			t_sample gate_2743 = ((choice_36 >= 2) ? in1 : 0);
			t_sample switch_2327 = (gen_2741 ? m_knob3_rate_33 : ((int)0));
			t_sample phasor_2739 = __m_phasor_37(switch_2327, samples_to_seconds);
			t_sample out4 = phasor_2739;
			t_sample mix_2837 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob1_wetdry_28 - m_history_22)));
			t_sample mix_2754 = mix_2837;
			t_sample mix_2838 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_2754 - m_history_21)));
			t_sample mix_2751 = mix_2838;
			t_sample mix_2839 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_2751 - m_history_20)));
			t_sample mix_2753 = mix_2839;
			t_sample gen_2379 = mix_2753;
			t_sample history_1828_next_2749 = fixdenorm(mix_2754);
			t_sample history_1826_next_2750 = fixdenorm(mix_2751);
			t_sample history_1824_next_2752 = fixdenorm(mix_2753);
			t_sample sqrt_2375 = sqrt(gen_2379);
			t_sample rsub_2381 = (((int)1) - gen_2379);
			t_sample sqrt_2380 = sqrt(rsub_2381);
			t_sample mul_2378 = (sqrt_2380 * gate_2743);
			t_sample plusequals_2740 = __m_pluseq_38.post(((int)1), m_history_1, 0);
			t_sample switch_2725 = (m_sw_29 ? ((int)-1) : plusequals_2740);
			int index_trunc_39 = fixnan(floor(switch_2725));
			bool index_ignore_40 = ((index_trunc_39 >= segments_dim) || (index_trunc_39 < 0));
			if ((!index_ignore_40)) {
				m_segments_34.write(gate_2743, index_trunc_39, 0);
				
			};
			t_sample mul_2728 = (expr_2745 * ((int)480000));
			int gte_2731 = (plusequals_2740 >= mul_2728);
			int eq_2730 = (gte_2731 == ((int)1));
			t_sample mix_2840 = (m_history_19 + (((t_sample)0.003926980723806) * (m_knob6_density_32 - m_history_19)));
			t_sample mix_2765 = mix_2840;
			t_sample mix_2841 = (m_history_18 + (((t_sample)0.003926980723806) * (mix_2765 - m_history_18)));
			t_sample mix_2762 = mix_2841;
			t_sample mix_2842 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_2762 - m_history_17)));
			t_sample mix_2766 = mix_2842;
			t_sample gen_2615 = mix_2766;
			t_sample history_1828_next_2760 = fixdenorm(mix_2765);
			t_sample history_1826_next_2764 = fixdenorm(mix_2762);
			t_sample history_1824_next_2759 = fixdenorm(mix_2766);
			t_sample sub_2846 = (gen_2615 - ((int)0));
			t_sample scale_2843 = ((safepow((sub_2846 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_2412 = m_delay_16.read_step(((int)8));
			t_sample tap_2414 = m_delay_15.read_step(((int)8));
			t_sample tap_2408 = m_delay_14.read_step(((int)8));
			t_sample tap_2410 = m_delay_13.read_step(((int)8));
			t_sample tap_2400 = m_delay_12.read_step(((int)8));
			t_sample tap_2402 = m_delay_11.read_step(((int)8));
			t_sample tap_2404 = m_delay_10.read_step(((int)9));
			t_sample tap_2406 = m_delay_9.read_step(((int)8));
			t_sample mul_2396 = (gen_2615 * ((int)12));
			int gte_2394 = (mul_2396 >= ((int)1));
			int gte_2393 = (mul_2396 >= ((int)2));
			int gte_2392 = (mul_2396 >= ((int)3));
			int gte_2395 = (mul_2396 >= ((int)0));
			int gte_2390 = (mul_2396 >= ((int)5));
			int gte_2391 = (mul_2396 >= ((int)4));
			int gte_2388 = (mul_2396 >= ((int)7));
			int gte_2389 = (mul_2396 >= ((int)6));
			int gte_2384 = (mul_2396 >= ((int)11));
			int gte_2385 = (mul_2396 >= ((int)10));
			int gte_2386 = (mul_2396 >= ((int)9));
			int gte_2387 = (mul_2396 >= ((int)8));
			t_sample mix_2847 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob5_glitchlen_27 - m_history_8)));
			t_sample mix_2780 = mix_2847;
			t_sample mix_2848 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_2780 - m_history_7)));
			t_sample mix_2773 = mix_2848;
			t_sample mix_2849 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_2773 - m_history_6)));
			t_sample mix_2776 = mix_2849;
			t_sample gen_2617 = mix_2776;
			t_sample history_1828_next_2779 = fixdenorm(mix_2780);
			t_sample history_1826_next_2775 = fixdenorm(mix_2773);
			t_sample history_1824_next_2778 = fixdenorm(mix_2776);
			t_sample mul_2372 = (mul_2728 * gen_2617);
			t_sample clamp_2616 = ((mul_2372 <= ((int)50)) ? ((int)50) : ((mul_2372 >= ((int)480000)) ? ((int)480000) : mul_2372));
			t_sample plusequals_2576 = __m_pluseq_41.post(((int)-1), tap_2412, 0);
			t_sample noise_2572 = noise();
			t_sample abs_2571 = fabs(noise_2572);
			t_sample sub_2567 = (clamp_2616 - ((int)50));
			t_sample mul_2570 = (abs_2571 * sub_2567);
			t_sample sah_2573 = __m_sah_42(mul_2570, tap_2412, ((t_sample)0.5));
			t_sample add_2564 = (sah_2573 + ((int)50));
			t_sample wrap_2574 = wrap(plusequals_2576, ((int)0), add_2564);
			t_sample div_2561 = safediv(wrap_2574, add_2564);
			t_sample expr_2581 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2561))));
			t_sample noise_2579 = noise();
			t_sample abs_2578 = fabs(noise_2579);
			t_sample mul_2577 = (abs_2578 * mul_2728);
			t_sample sah_2580 = __m_sah_43(mul_2577, tap_2412, ((t_sample)0.5));
			t_sample add_2562 = (sah_2580 + wrap_2574);
			t_sample switch_2565 = (gte_2390 ? add_2562 : ((int)-1));
			int index_trunc_44 = fixnan(floor(switch_2565));
			bool index_ignore_45 = ((index_trunc_44 >= segments_dim) || (index_trunc_44 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2568 = (index_ignore_45 ? 0 : m_segments_34.read(index_trunc_44, 0));
			t_sample index_segments_2569 = switch_2565;
			t_sample mul_2559 = (sample_segments_2568 * expr_2581);
			t_sample plusequals_2600 = __m_pluseq_46.post(((int)-1), tap_2414, 0);
			t_sample noise_2596 = noise();
			t_sample abs_2595 = fabs(noise_2596);
			t_sample sub_2591 = (clamp_2616 - ((int)50));
			t_sample mul_2594 = (abs_2595 * sub_2591);
			t_sample sah_2597 = __m_sah_47(mul_2594, tap_2414, ((t_sample)0.5));
			t_sample add_2588 = (sah_2597 + ((int)50));
			t_sample wrap_2598 = wrap(plusequals_2600, ((int)0), add_2588);
			t_sample div_2585 = safediv(wrap_2598, add_2588);
			t_sample expr_2605 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2585))));
			t_sample noise_2603 = noise();
			t_sample abs_2602 = fabs(noise_2603);
			t_sample mul_2601 = (abs_2602 * mul_2728);
			t_sample sah_2604 = __m_sah_48(mul_2601, tap_2414, ((t_sample)0.5));
			t_sample add_2586 = (sah_2604 + wrap_2598);
			t_sample switch_2589 = (gte_2391 ? add_2586 : ((int)-1));
			int index_trunc_49 = fixnan(floor(switch_2589));
			bool index_ignore_50 = ((index_trunc_49 >= segments_dim) || (index_trunc_49 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2592 = (index_ignore_50 ? 0 : m_segments_34.read(index_trunc_49, 0));
			t_sample index_segments_2593 = switch_2589;
			t_sample mul_2583 = (sample_segments_2592 * expr_2605);
			t_sample mul_2614 = ((mul_2583 + mul_2559) * ((t_sample)0.3));
			t_sample mul_2613 = ((mul_2583 + mul_2559) * ((t_sample)0.4));
			t_sample plusequals_2528 = __m_pluseq_51.post(((int)-1), tap_2408, 0);
			t_sample noise_2524 = noise();
			t_sample abs_2523 = fabs(noise_2524);
			t_sample sub_2519 = (clamp_2616 - ((int)50));
			t_sample mul_2522 = (abs_2523 * sub_2519);
			t_sample sah_2525 = __m_sah_52(mul_2522, tap_2408, ((t_sample)0.5));
			t_sample add_2516 = (sah_2525 + ((int)50));
			t_sample wrap_2526 = wrap(plusequals_2528, ((int)0), add_2516);
			t_sample div_2513 = safediv(wrap_2526, add_2516);
			t_sample expr_2533 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2513))));
			t_sample noise_2531 = noise();
			t_sample abs_2530 = fabs(noise_2531);
			t_sample mul_2529 = (abs_2530 * mul_2728);
			t_sample sah_2532 = __m_sah_53(mul_2529, tap_2408, ((t_sample)0.5));
			t_sample add_2514 = (sah_2532 + wrap_2526);
			t_sample switch_2517 = (gte_2388 ? add_2514 : ((int)-1));
			int index_trunc_54 = fixnan(floor(switch_2517));
			bool index_ignore_55 = ((index_trunc_54 >= segments_dim) || (index_trunc_54 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2520 = (index_ignore_55 ? 0 : m_segments_34.read(index_trunc_54, 0));
			t_sample index_segments_2521 = switch_2517;
			t_sample mul_2511 = (sample_segments_2520 * expr_2533);
			t_sample plusequals_2552 = __m_pluseq_56.post(((int)-1), tap_2410, 0);
			t_sample noise_2548 = noise();
			t_sample abs_2547 = fabs(noise_2548);
			t_sample sub_2543 = (clamp_2616 - ((int)50));
			t_sample mul_2546 = (abs_2547 * sub_2543);
			t_sample sah_2549 = __m_sah_57(mul_2546, tap_2410, ((t_sample)0.5));
			t_sample add_2540 = (sah_2549 + ((int)50));
			t_sample wrap_2550 = wrap(plusequals_2552, ((int)0), add_2540);
			t_sample div_2537 = safediv(wrap_2550, add_2540);
			t_sample expr_2557 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2537))));
			t_sample noise_2555 = noise();
			t_sample abs_2554 = fabs(noise_2555);
			t_sample mul_2553 = (abs_2554 * mul_2728);
			t_sample sah_2556 = __m_sah_58(mul_2553, tap_2410, ((t_sample)0.5));
			t_sample add_2538 = (sah_2556 + wrap_2550);
			t_sample switch_2541 = (gte_2389 ? add_2538 : ((int)-1));
			int index_trunc_59 = fixnan(floor(switch_2541));
			bool index_ignore_60 = ((index_trunc_59 >= segments_dim) || (index_trunc_59 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2544 = (index_ignore_60 ? 0 : m_segments_34.read(index_trunc_59, 0));
			t_sample index_segments_2545 = switch_2541;
			t_sample mul_2535 = (sample_segments_2544 * expr_2557);
			t_sample mul_2612 = ((mul_2535 + mul_2511) * ((t_sample)0.4));
			t_sample mul_2611 = ((mul_2535 + mul_2511) * ((t_sample)0.3));
			t_sample plusequals_2432 = __m_pluseq_61.post(((int)-1), tap_2400, 0);
			t_sample noise_2428 = noise();
			t_sample abs_2427 = fabs(noise_2428);
			t_sample sub_2423 = (clamp_2616 - ((int)50));
			t_sample mul_2426 = (abs_2427 * sub_2423);
			t_sample sah_2429 = __m_sah_62(mul_2426, tap_2400, ((t_sample)0.5));
			t_sample add_2420 = (sah_2429 + ((int)50));
			t_sample wrap_2430 = wrap(plusequals_2432, ((int)0), add_2420);
			t_sample div_2417 = safediv(wrap_2430, add_2420);
			t_sample expr_2437 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2417))));
			t_sample noise_2435 = noise();
			t_sample abs_2434 = fabs(noise_2435);
			t_sample mul_2433 = (abs_2434 * mul_2728);
			t_sample sah_2436 = __m_sah_63(mul_2433, tap_2400, ((t_sample)0.5));
			t_sample add_2418 = (sah_2436 + wrap_2430);
			t_sample switch_2421 = (gte_2384 ? add_2418 : ((int)-1));
			int index_trunc_64 = fixnan(floor(switch_2421));
			bool index_ignore_65 = ((index_trunc_64 >= segments_dim) || (index_trunc_64 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2424 = (index_ignore_65 ? 0 : m_segments_34.read(index_trunc_64, 0));
			t_sample index_segments_2425 = switch_2421;
			t_sample mul_2415 = (sample_segments_2424 * expr_2437);
			t_sample plusequals_2456 = __m_pluseq_66.post(((int)-1), tap_2402, 0);
			t_sample noise_2452 = noise();
			t_sample abs_2451 = fabs(noise_2452);
			t_sample sub_2447 = (clamp_2616 - ((int)50));
			t_sample mul_2450 = (abs_2451 * sub_2447);
			t_sample sah_2453 = __m_sah_67(mul_2450, tap_2402, ((t_sample)0.5));
			t_sample add_2444 = (sah_2453 + ((int)50));
			t_sample wrap_2454 = wrap(plusequals_2456, ((int)0), add_2444);
			t_sample div_2441 = safediv(wrap_2454, add_2444);
			t_sample expr_2461 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2441))));
			t_sample noise_2459 = noise();
			t_sample abs_2458 = fabs(noise_2459);
			t_sample mul_2457 = (abs_2458 * mul_2728);
			t_sample sah_2460 = __m_sah_68(mul_2457, tap_2402, ((t_sample)0.5));
			t_sample add_2442 = (sah_2460 + wrap_2454);
			t_sample switch_2445 = (gte_2385 ? add_2442 : ((int)-1));
			int index_trunc_69 = fixnan(floor(switch_2445));
			bool index_ignore_70 = ((index_trunc_69 >= segments_dim) || (index_trunc_69 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2448 = (index_ignore_70 ? 0 : m_segments_34.read(index_trunc_69, 0));
			t_sample index_segments_2449 = switch_2445;
			t_sample mul_2439 = (sample_segments_2448 * expr_2461);
			t_sample mul_2608 = ((mul_2439 + mul_2415) * ((t_sample)0.5));
			t_sample mul_2607 = ((mul_2439 + mul_2415) * ((t_sample)0.2));
			t_sample plusequals_2480 = __m_pluseq_71.post(((int)-1), tap_2404, 0);
			t_sample noise_2476 = noise();
			t_sample abs_2475 = fabs(noise_2476);
			t_sample sub_2471 = (clamp_2616 - ((int)50));
			t_sample mul_2474 = (abs_2475 * sub_2471);
			t_sample sah_2477 = __m_sah_72(mul_2474, tap_2404, ((t_sample)0.5));
			t_sample add_2468 = (sah_2477 + ((int)50));
			t_sample wrap_2478 = wrap(plusequals_2480, ((int)0), add_2468);
			t_sample div_2465 = safediv(wrap_2478, add_2468);
			t_sample expr_2485 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2465))));
			t_sample noise_2483 = noise();
			t_sample abs_2482 = fabs(noise_2483);
			t_sample mul_2481 = (abs_2482 * mul_2728);
			t_sample sah_2484 = __m_sah_73(mul_2481, tap_2404, ((t_sample)0.5));
			t_sample add_2466 = (sah_2484 + wrap_2478);
			t_sample switch_2469 = (gte_2386 ? add_2466 : ((int)-1));
			int index_trunc_74 = fixnan(floor(switch_2469));
			bool index_ignore_75 = ((index_trunc_74 >= segments_dim) || (index_trunc_74 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2472 = (index_ignore_75 ? 0 : m_segments_34.read(index_trunc_74, 0));
			t_sample index_segments_2473 = switch_2469;
			t_sample mul_2463 = (sample_segments_2472 * expr_2485);
			t_sample plusequals_2504 = __m_pluseq_76.post(((int)-1), tap_2406, 0);
			t_sample noise_2500 = noise();
			t_sample abs_2499 = fabs(noise_2500);
			t_sample sub_2495 = (clamp_2616 - ((int)50));
			t_sample mul_2498 = (abs_2499 * sub_2495);
			t_sample sah_2501 = __m_sah_77(mul_2498, tap_2406, ((t_sample)0.5));
			t_sample add_2492 = (sah_2501 + ((int)50));
			t_sample wrap_2502 = wrap(plusequals_2504, ((int)0), add_2492);
			t_sample div_2489 = safediv(wrap_2502, add_2492);
			t_sample expr_2509 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2489))));
			t_sample noise_2507 = noise();
			t_sample abs_2506 = fabs(noise_2507);
			t_sample mul_2505 = (abs_2506 * mul_2728);
			t_sample sah_2508 = __m_sah_78(mul_2505, tap_2406, ((t_sample)0.5));
			t_sample add_2490 = (sah_2508 + wrap_2502);
			t_sample switch_2493 = (gte_2387 ? add_2490 : ((int)-1));
			int index_trunc_79 = fixnan(floor(switch_2493));
			bool index_ignore_80 = ((index_trunc_79 >= segments_dim) || (index_trunc_79 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2496 = (index_ignore_80 ? 0 : m_segments_34.read(index_trunc_79, 0));
			t_sample index_segments_2497 = switch_2493;
			t_sample mul_2487 = (sample_segments_2496 * expr_2509);
			t_sample mul_2610 = ((mul_2487 + mul_2463) * ((t_sample)0.2));
			t_sample mul_2609 = ((mul_2487 + mul_2463) * ((t_sample)0.5));
			int gt_2698 = (phasor_2739 > ((t_sample)0.49));
			int change_2697 = __m_change_81(gt_2698);
			int eq_2696 = (change_2697 == ((int)1));
			t_sample add_2355 = (m_history_5 + ((int)1));
			int gt_2354 = (m_history_5 > mstosamps_2357);
			int mul_2353 = (eq_2696 * gt_2354);
			int and_2351 = (gt_2354 && eq_2696);
			t_sample switch_2352 = (and_2351 ? ((int)0) : add_2355);
			t_sample history_2356_next_2359 = fixdenorm(switch_2352);
			int plusequals_2683 = __m_pluseq_82.post(((int)-1), mul_2353, 0);
			t_sample noise_2679 = noise();
			t_sample abs_2678 = fabs(noise_2679);
			t_sample sub_2674 = (clamp_2616 - ((int)50));
			t_sample mul_2677 = (abs_2678 * sub_2674);
			t_sample sah_2680 = __m_sah_83(mul_2677, mul_2353, ((t_sample)0.5));
			t_sample add_2671 = (sah_2680 + ((int)50));
			t_sample wrap_2681 = wrap(plusequals_2683, ((int)0), add_2671);
			t_sample div_2668 = safediv(wrap_2681, add_2671);
			t_sample expr_2688 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2668))));
			t_sample noise_2686 = noise();
			t_sample abs_2685 = fabs(noise_2686);
			t_sample mul_2684 = (abs_2685 * mul_2728);
			t_sample sah_2687 = __m_sah_84(mul_2684, mul_2353, ((t_sample)0.5));
			t_sample add_2669 = (sah_2687 + wrap_2681);
			t_sample switch_2672 = (gte_2394 ? add_2669 : ((int)-1));
			int index_trunc_85 = fixnan(floor(switch_2672));
			bool index_ignore_86 = ((index_trunc_85 >= segments_dim) || (index_trunc_85 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2675 = (index_ignore_86 ? 0 : m_segments_34.read(index_trunc_85, 0));
			t_sample index_segments_2676 = switch_2672;
			t_sample mul_2666 = (sample_segments_2675 * expr_2688);
			int gt_2695 = (phasor_2739 > ((t_sample)0.51));
			int change_2694 = __m_change_87(gt_2695);
			int eq_2693 = (change_2694 == ((int)1));
			t_sample add_2344 = (m_history_4 + ((int)1));
			int gt_2343 = (m_history_4 > mstosamps_2346);
			int mul_2342 = (eq_2693 * gt_2343);
			int and_2340 = (gt_2343 && eq_2693);
			t_sample switch_2341 = (and_2340 ? ((int)0) : add_2344);
			t_sample history_2345_next_2348 = fixdenorm(switch_2341);
			int plusequals_2659 = __m_pluseq_88.post(((int)-1), mul_2342, 0);
			t_sample noise_2655 = noise();
			t_sample abs_2654 = fabs(noise_2655);
			t_sample sub_2650 = (clamp_2616 - ((int)50));
			t_sample mul_2653 = (abs_2654 * sub_2650);
			t_sample sah_2656 = __m_sah_89(mul_2653, mul_2342, ((t_sample)0.5));
			t_sample add_2647 = (sah_2656 + ((int)50));
			t_sample wrap_2657 = wrap(plusequals_2659, ((int)0), add_2647);
			t_sample div_2644 = safediv(wrap_2657, add_2647);
			t_sample expr_2664 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2644))));
			t_sample noise_2662 = noise();
			t_sample abs_2661 = fabs(noise_2662);
			t_sample mul_2660 = (abs_2661 * mul_2728);
			t_sample sah_2663 = __m_sah_90(mul_2660, mul_2342, ((t_sample)0.5));
			t_sample add_2645 = (sah_2663 + wrap_2657);
			t_sample switch_2648 = (gte_2393 ? add_2645 : ((int)-1));
			int index_trunc_91 = fixnan(floor(switch_2648));
			bool index_ignore_92 = ((index_trunc_91 >= segments_dim) || (index_trunc_91 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2651 = (index_ignore_92 ? 0 : m_segments_34.read(index_trunc_91, 0));
			t_sample index_segments_2652 = switch_2648;
			t_sample mul_2642 = (sample_segments_2651 * expr_2664);
			int gt_2692 = (phasor_2739 > ((t_sample)0.48));
			int change_2691 = __m_change_93(gt_2692);
			int eq_2690 = (change_2691 == ((int)1));
			t_sample add_2333 = (m_history_3 + ((int)1));
			int gt_2332 = (m_history_3 > mstosamps_2335);
			int mul_2331 = (eq_2690 * gt_2332);
			int and_2329 = (gt_2332 && eq_2690);
			t_sample switch_2330 = (and_2329 ? ((int)0) : add_2333);
			t_sample history_2334_next_2337 = fixdenorm(switch_2330);
			int plusequals_2635 = __m_pluseq_94.post(((int)-1), mul_2331, 0);
			t_sample noise_2631 = noise();
			t_sample abs_2630 = fabs(noise_2631);
			t_sample sub_2626 = (clamp_2616 - ((int)50));
			t_sample mul_2629 = (abs_2630 * sub_2626);
			t_sample sah_2632 = __m_sah_95(mul_2629, mul_2331, ((t_sample)0.5));
			t_sample add_2623 = (sah_2632 + ((int)50));
			t_sample wrap_2633 = wrap(plusequals_2635, ((int)0), add_2623);
			t_sample div_2620 = safediv(wrap_2633, add_2623);
			t_sample expr_2640 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2620))));
			t_sample noise_2638 = noise();
			t_sample abs_2637 = fabs(noise_2638);
			t_sample mul_2636 = (abs_2637 * mul_2728);
			t_sample sah_2639 = __m_sah_96(mul_2636, mul_2331, ((t_sample)0.5));
			t_sample add_2621 = (sah_2639 + wrap_2633);
			t_sample switch_2624 = (gte_2392 ? add_2621 : ((int)-1));
			int index_trunc_97 = fixnan(floor(switch_2624));
			bool index_ignore_98 = ((index_trunc_97 >= segments_dim) || (index_trunc_97 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2627 = (index_ignore_98 ? 0 : m_segments_34.read(index_trunc_97, 0));
			t_sample index_segments_2628 = switch_2624;
			t_sample mul_2618 = (sample_segments_2627 * expr_2640);
			int gt_2736 = (phasor_2739 > ((t_sample)0.5));
			int change_2735 = __m_change_99(gt_2736);
			int eq_2734 = (change_2735 == ((int)1));
			t_sample add_2366 = (m_history_2 + ((int)1));
			int gt_2365 = (m_history_2 > mstosamps_2368);
			int mul_2364 = (eq_2734 * gt_2365);
			int and_2362 = (gt_2365 && eq_2734);
			t_sample switch_2363 = (and_2362 ? ((int)0) : add_2366);
			t_sample history_2367_next_2370 = fixdenorm(switch_2363);
			int plusequals_2717 = __m_pluseq_100.post(((int)-1), mul_2364, 0);
			t_sample noise_2713 = noise();
			t_sample abs_2712 = fabs(noise_2713);
			t_sample sub_2708 = (clamp_2616 - ((int)50));
			t_sample mul_2711 = (abs_2712 * sub_2708);
			t_sample sah_2714 = __m_sah_101(mul_2711, mul_2364, ((t_sample)0.5));
			t_sample add_2705 = (sah_2714 + ((int)50));
			t_sample wrap_2715 = wrap(plusequals_2717, ((int)0), add_2705);
			t_sample div_2702 = safediv(wrap_2715, add_2705);
			t_sample expr_2722 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2702))));
			t_sample noise_2720 = noise();
			t_sample abs_2719 = fabs(noise_2720);
			t_sample mul_2718 = (abs_2719 * mul_2728);
			t_sample sah_2721 = __m_sah_102(mul_2718, mul_2364, ((t_sample)0.5));
			t_sample add_2703 = (sah_2721 + wrap_2715);
			t_sample switch_2706 = (gte_2395 ? add_2703 : ((int)-1));
			int index_trunc_103 = fixnan(floor(switch_2706));
			bool index_ignore_104 = ((index_trunc_103 >= segments_dim) || (index_trunc_103 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2709 = (index_ignore_104 ? 0 : m_segments_34.read(index_trunc_103, 0));
			t_sample index_segments_2710 = switch_2706;
			t_sample mul_2700 = (sample_segments_2709 * expr_2722);
			t_sample mul_2699 = ((((mul_2700 + mul_2618) + mul_2642) + mul_2666) * ((t_sample)0.7));
			t_sample mul_2398 = (((((mul_2610 + mul_2608) + mul_2612) + mul_2614) + mul_2699) * scale_2843);
			t_sample dcblock_2374 = __m_dcblock_105(mul_2398);
			t_sample mul_2377 = (sqrt_2375 * dcblock_2374);
			t_sample out1 = ((mul_2377 + mul_2378) + gate_2742);
			t_sample mul_2397 = (((((mul_2609 + mul_2607) + mul_2611) + mul_2613) + mul_2699) * scale_2843);
			t_sample dcblock_2373 = __m_dcblock_106(mul_2397);
			t_sample mul_2376 = (sqrt_2375 * dcblock_2373);
			t_sample out2 = ((mul_2376 + mul_2378) + gate_2742);
			t_sample history_2729_next_2785 = fixdenorm(eq_2730);
			m_history_26 = history_2206_next_2208;
			m_history_25 = history_1828_next_1830;
			m_history_23 = history_1824_next_1832;
			m_history_24 = history_1826_next_1831;
			m_history_22 = history_1828_next_2749;
			m_history_20 = history_1824_next_2752;
			m_history_21 = history_1826_next_2750;
			m_history_19 = history_1828_next_2760;
			m_history_17 = history_1824_next_2759;
			m_history_18 = history_1826_next_2764;
			m_delay_16.write(mul_2353);
			m_delay_15.write(mul_2364);
			m_delay_14.write(mul_2331);
			m_delay_13.write(mul_2342);
			m_delay_12.write(tap_2408);
			m_delay_11.write(tap_2410);
			m_delay_10.write(tap_2412);
			m_delay_9.write(tap_2414);
			m_history_8 = history_1828_next_2779;
			m_history_6 = history_1824_next_2778;
			m_history_7 = history_1826_next_2775;
			m_history_5 = history_2356_next_2359;
			m_history_4 = history_2345_next_2348;
			m_history_3 = history_2334_next_2337;
			m_history_2 = history_2367_next_2370;
			m_history_1 = history_2729_next_2785;
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
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_density(t_param _value) {
		m_knob6_density_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_rate(t_param _value) {
		m_knob3_rate_33 = (_value < 0.01 ? 0.01 : (_value > 16 ? 16 : _value));
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
		case 0: *value = self->m_knob1_wetdry_28; break;
		case 1: *value = self->m_knob3_rate_33; break;
		case 2: *value = self->m_knob4_buflen_31; break;
		case 3: *value = self->m_knob5_glitchlen_27; break;
		case 4: *value = self->m_knob6_density_32; break;
		
		case 6: *value = self->m_sw_30; break;
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
	// initialize parameter 0 ("m_knob1_wetdry_28")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_rate_33")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_rate_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_buflen_31")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_buflen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_buflen_31;
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
	// initialize parameter 4 ("m_knob6_density_32")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_density";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_density_32;
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
	// initialize parameter 6 ("m_sw_30")
	pi = self->__commonstate.params + 6;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_30;
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
