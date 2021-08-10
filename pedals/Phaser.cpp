#include "Phaser.h"

namespace Phaser {

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
	DCBlock __m_dcblock_64;
	DCBlock __m_dcblock_49;
	Phasor __m_phasor_31;
	Sah __m_sah_29;
	SineCycle __m_cycle_57;
	SineCycle __m_cycle_50;
	SineCycle __m_cycle_42;
	SineCycle __m_cycle_35;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_4;
	t_sample m_history_8;
	t_sample m_history_3;
	t_sample __m_slide_32;
	t_sample m_history_5;
	t_sample samples_to_seconds;
	t_sample __m_slide_36;
	t_sample m_history_6;
	t_sample __m_slide_39;
	t_sample m_history_2;
	t_sample __m_slide_43;
	t_sample __m_slide_54;
	t_sample __m_slide_58;
	t_sample m_sw_28;
	t_sample __m_slide_51;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_slide_46;
	t_sample m_history_7;
	t_sample m_knob4_rate_27;
	t_sample m_knob6_diffusion_25;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_12;
	t_sample m_history_10;
	t_sample m_history_11;
	t_sample m_history_9;
	t_sample m_knob5_fb_26;
	t_sample m_history_16;
	t_sample m_history_18;
	t_sample m_knob3_depth_23;
	t_sample m_sw_24;
	t_sample m_history_17;
	t_sample __m_slide_61;
	t_sample m_history_20;
	t_sample m_history_21;
	t_sample m_history_19;
	t_sample m_history_22;
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
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_knob3_depth_23 = 1;
		m_sw_24 = ((int)0);
		m_knob6_diffusion_25 = 1;
		m_knob5_fb_26 = ((int)0);
		m_knob4_rate_27 = 0.1;
		m_sw_28 = ((int)0);
		__m_sah_29.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_31.reset(0);
		__m_slide_32 = 0;
		__m_cycle_35.reset(samplerate, 0);
		__m_slide_36 = 0;
		__m_slide_39 = 0;
		__m_cycle_42.reset(samplerate, 0);
		__m_slide_43 = 0;
		__m_slide_46 = 0;
		__m_dcblock_49.reset();
		__m_cycle_50.reset(samplerate, 0);
		__m_slide_51 = 0;
		__m_slide_54 = 0;
		__m_cycle_57.reset(samplerate, 0);
		__m_slide_58 = 0;
		__m_slide_61 = 0;
		__m_dcblock_64.reset();
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
		t_sample sub_2728 = (m_knob5_fb_26 - ((t_sample)0.5));
		t_sample scale_2725 = ((safepow((sub_2728 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		t_sample mul_2603 = (m_knob6_diffusion_25 * ((int)2));
		t_sample div_2601 = (mul_2603 * ((t_sample)0.125));
		t_sample mul_2604 = (m_knob6_diffusion_25 * ((int)0));
		t_sample div_2602 = (mul_2604 * ((t_sample)0.125));
		t_sample mul_2596 = (m_knob6_diffusion_25 * ((int)3));
		t_sample div_2594 = (mul_2596 * ((t_sample)0.125));
		t_sample mul_2597 = (m_knob6_diffusion_25 * ((int)1));
		t_sample div_2595 = (mul_2597 * ((t_sample)0.125));
		t_sample mstosamps_2447 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_2446 = (((int)100) * (samplerate * 0.001));
		t_sample iup_33 = (1 / maximum(1, abs(mstosamps_2447)));
		t_sample idown_34 = (1 / maximum(1, abs(mstosamps_2446)));
		t_sample div_2562 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_37 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_38 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_40 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_41 = (1 / maximum(1, abs(((int)5))));
		t_sample div_2620 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_44 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)5))));
		t_sample div_2477 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_52 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)5))));
		t_sample div_2519 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_2323 = __m_sah_29(m_history_22, m_sw_24, ((int)0));
			t_sample gen_2455 = sah_2323;
			t_sample rsub_2321 = (((int)1) - sah_2323);
			t_sample history_2322_next_2324 = fixdenorm(rsub_2321);
			t_sample out3 = gen_2455;
			t_sample mix_2722 = (m_history_21 + (((t_sample)0.0019634941468452) * (m_knob4_rate_27 - m_history_21)));
			t_sample mix_2435 = mix_2722;
			t_sample mix_2723 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_2435 - m_history_20)));
			t_sample mix_2433 = mix_2723;
			t_sample mix_2724 = (m_history_19 + (((t_sample)0.0019634941468452) * (mix_2433 - m_history_19)));
			t_sample mix_2431 = mix_2724;
			t_sample gen_2443 = mix_2431;
			t_sample history_2437_next_2440 = fixdenorm(mix_2435);
			t_sample history_2434_next_2441 = fixdenorm(mix_2433);
			t_sample history_2432_next_2442 = fixdenorm(mix_2431);
			t_sample expr_2650 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_2443)))));
			t_sample add_2456 = (gen_2455 + ((int)1));
			t_sample choice_30 = int(add_2456);
			t_sample gate_2453 = (((choice_30 >= 1) && (choice_30 < 2)) ? in1 : 0);
			t_sample gate_2454 = ((choice_30 >= 2) ? in1 : 0);
			t_sample mul_2600 = (m_history_1 * m_knob5_fb_26);
			t_sample add_2599 = (gate_2454 + mul_2600);
			t_sample mul_2649 = (expr_2650 * ((t_sample)7.5));
			t_sample phasor_2605 = __m_phasor_31(mul_2649, samples_to_seconds);
			t_sample mul_2459 = (m_history_2 * m_knob5_fb_26);
			t_sample add_2458 = (gate_2454 + mul_2459);
			t_sample switch_2450 = (m_sw_28 ? gate_2454 : ((int)1));
			t_sample abs_2452 = fabs(switch_2450);
			t_sample mul_2429 = (abs_2452 * ((int)100));
			__m_slide_32 = fixdenorm((__m_slide_32 + (((mul_2429 > __m_slide_32) ? iup_33 : idown_34) * (mul_2429 - __m_slide_32))));
			t_sample slide_2451 = __m_slide_32;
			t_sample mul_2427 = (m_knob3_depth_23 * slide_2451);
			t_sample clamp_2449 = ((mul_2427 <= ((int)0)) ? ((int)0) : ((mul_2427 >= ((int)1)) ? ((int)1) : mul_2427));
			t_sample add_2571 = (phasor_2605 + div_2601);
			t_sample mod_2572 = safemod(add_2571, ((int)1));
			__m_cycle_35.phase(mod_2572);
			t_sample cycle_2569 = __m_cycle_35(__sinedata);
			t_sample cycleindex_2570 = __m_cycle_35.phase();
			t_sample add_2567 = (cycle_2569 + ((int)1));
			t_sample div_2566 = (add_2567 * ((t_sample)0.5));
			t_sample mul_2568 = (div_2566 * clamp_2449);
			t_sample sub_2732 = (mul_2568 - ((int)0));
			t_sample scale_2729 = ((safepow((sub_2732 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_2573 = scale_2729;
			t_sample mtof_2574 = mtof(scale_2573, ((int)440));
			t_sample mul_2561 = (mtof_2574 * div_2562);
			t_sample cos_2559 = cos(mul_2561);
			t_sample mul_2554 = (cos_2559 * (-2));
			t_sample sin_2560 = sin(mul_2561);
			t_sample mul_2558 = (sin_2560 * ((t_sample)0.5));
			t_sample div_2557 = (mul_2558 * ((t_sample)0.33333333333333));
			t_sample rsub_2552 = (((int)1) - div_2557);
			t_sample add_2556 = (div_2557 + ((int)1));
			t_sample rdiv_2555 = safediv(((int)1), add_2556);
			t_sample mul_2551 = (rdiv_2555 * rsub_2552);
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_2551 > __m_slide_36) ? iup_37 : idown_38) * (mul_2551 - __m_slide_36))));
			t_sample slide_2548 = __m_slide_36;
			t_sample gen_2564 = slide_2548;
			t_sample mul_2553 = (rdiv_2555 * mul_2554);
			__m_slide_39 = fixdenorm((__m_slide_39 + (((mul_2553 > __m_slide_39) ? iup_40 : idown_41) * (mul_2553 - __m_slide_39))));
			t_sample slide_2549 = __m_slide_39;
			t_sample gen_2563 = slide_2549;
			t_sample mul_2584 = (add_2599 * gen_2564);
			t_sample mul_2581 = (m_history_16 * gen_2563);
			t_sample mul_2579 = (m_history_18 * ((int)1));
			t_sample mul_2575 = (m_history_17 * gen_2564);
			t_sample mul_2577 = (m_history_15 * gen_2563);
			t_sample sub_2583 = (((mul_2579 + mul_2581) + mul_2584) - (mul_2577 + mul_2575));
			t_sample gen_2589 = sub_2583;
			t_sample history_2580_next_2585 = fixdenorm(m_history_16);
			t_sample history_2576_next_2586 = fixdenorm(m_history_15);
			t_sample history_2582_next_2587 = fixdenorm(add_2599);
			t_sample history_2578_next_2588 = fixdenorm(sub_2583);
			t_sample add_2629 = (phasor_2605 + div_2602);
			t_sample mod_2630 = safemod(add_2629, ((int)1));
			__m_cycle_42.phase(mod_2630);
			t_sample cycle_2627 = __m_cycle_42(__sinedata);
			t_sample cycleindex_2628 = __m_cycle_42.phase();
			t_sample add_2625 = (cycle_2627 + ((int)1));
			t_sample div_2624 = (add_2625 * ((t_sample)0.5));
			t_sample mul_2626 = (div_2624 * clamp_2449);
			t_sample sub_2736 = (mul_2626 - ((int)0));
			t_sample scale_2733 = ((safepow((sub_2736 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_2631 = scale_2733;
			t_sample mtof_2632 = mtof(scale_2631, ((int)440));
			t_sample mul_2619 = (mtof_2632 * div_2620);
			t_sample cos_2617 = cos(mul_2619);
			t_sample mul_2612 = (cos_2617 * (-2));
			t_sample sin_2618 = sin(mul_2619);
			t_sample mul_2616 = (sin_2618 * ((t_sample)0.5));
			t_sample div_2615 = (mul_2616 * ((t_sample)0.33333333333333));
			t_sample rsub_2610 = (((int)1) - div_2615);
			t_sample add_2614 = (div_2615 + ((int)1));
			t_sample rdiv_2613 = safediv(((int)1), add_2614);
			t_sample mul_2611 = (rdiv_2613 * mul_2612);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((mul_2611 > __m_slide_43) ? iup_44 : idown_45) * (mul_2611 - __m_slide_43))));
			t_sample slide_2607 = __m_slide_43;
			t_sample gen_2621 = slide_2607;
			t_sample mul_2609 = (rdiv_2613 * rsub_2610);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((mul_2609 > __m_slide_46) ? iup_47 : idown_48) * (mul_2609 - __m_slide_46))));
			t_sample slide_2606 = __m_slide_46;
			t_sample gen_2622 = slide_2606;
			t_sample mul_2642 = (add_2599 * gen_2622);
			t_sample mul_2639 = (m_history_12 * gen_2621);
			t_sample mul_2637 = (m_history_14 * ((int)1));
			t_sample mul_2633 = (m_history_13 * gen_2622);
			t_sample mul_2635 = (m_history_11 * gen_2621);
			t_sample sub_2641 = (((mul_2637 + mul_2639) + mul_2642) - (mul_2635 + mul_2633));
			t_sample gen_2647 = sub_2641;
			t_sample history_2638_next_2643 = fixdenorm(m_history_12);
			t_sample history_2634_next_2644 = fixdenorm(m_history_11);
			t_sample history_2640_next_2645 = fixdenorm(add_2599);
			t_sample history_2636_next_2646 = fixdenorm(sub_2641);
			t_sample mul_2547 = ((gen_2647 + gen_2589) * ((t_sample)0.5));
			t_sample dcblock_2592 = __m_dcblock_49(mul_2547);
			t_sample mul_2590 = (((gate_2454 + gen_2647) + gen_2589) * scale_2725);
			t_sample div_2424 = (mul_2590 * ((t_sample)0.5));
			t_sample add_2593 = (gate_2453 + div_2424);
			t_sample out1 = add_2593;
			t_sample add_2486 = (phasor_2605 + div_2594);
			t_sample mod_2487 = safemod(add_2486, ((int)1));
			__m_cycle_50.phase(mod_2487);
			t_sample cycle_2484 = __m_cycle_50(__sinedata);
			t_sample cycleindex_2485 = __m_cycle_50.phase();
			t_sample add_2482 = (cycle_2484 + ((int)1));
			t_sample div_2481 = (add_2482 * ((t_sample)0.5));
			t_sample mul_2483 = (div_2481 * clamp_2449);
			t_sample sub_2740 = (mul_2483 - ((int)0));
			t_sample scale_2737 = ((safepow((sub_2740 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_2488 = scale_2737;
			t_sample mtof_2489 = mtof(scale_2488, ((int)440));
			t_sample mul_2476 = (mtof_2489 * div_2477);
			t_sample cos_2474 = cos(mul_2476);
			t_sample mul_2469 = (cos_2474 * (-2));
			t_sample sin_2475 = sin(mul_2476);
			t_sample mul_2473 = (sin_2475 * ((t_sample)0.5));
			t_sample div_2472 = (mul_2473 * ((t_sample)0.33333333333333));
			t_sample rsub_2467 = (((int)1) - div_2472);
			t_sample add_2471 = (div_2472 + ((int)1));
			t_sample rdiv_2470 = safediv(((int)1), add_2471);
			t_sample mul_2468 = (rdiv_2470 * mul_2469);
			__m_slide_51 = fixdenorm((__m_slide_51 + (((mul_2468 > __m_slide_51) ? iup_52 : idown_53) * (mul_2468 - __m_slide_51))));
			t_sample slide_2464 = __m_slide_51;
			t_sample gen_2478 = slide_2464;
			t_sample mul_2466 = (rdiv_2470 * rsub_2467);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((mul_2466 > __m_slide_54) ? iup_55 : idown_56) * (mul_2466 - __m_slide_54))));
			t_sample slide_2463 = __m_slide_54;
			t_sample gen_2479 = slide_2463;
			t_sample mul_2499 = (add_2458 * gen_2479);
			t_sample mul_2496 = (m_history_8 * gen_2478);
			t_sample mul_2494 = (m_history_10 * ((int)1));
			t_sample mul_2490 = (m_history_9 * gen_2479);
			t_sample mul_2492 = (m_history_7 * gen_2478);
			t_sample sub_2498 = (((mul_2494 + mul_2496) + mul_2499) - (mul_2492 + mul_2490));
			t_sample gen_2504 = sub_2498;
			t_sample history_2495_next_2500 = fixdenorm(m_history_8);
			t_sample history_2491_next_2501 = fixdenorm(m_history_7);
			t_sample history_2497_next_2502 = fixdenorm(add_2458);
			t_sample history_2493_next_2503 = fixdenorm(sub_2498);
			t_sample add_2528 = (phasor_2605 + div_2595);
			t_sample mod_2529 = safemod(add_2528, ((int)1));
			__m_cycle_57.phase(mod_2529);
			t_sample cycle_2526 = __m_cycle_57(__sinedata);
			t_sample cycleindex_2527 = __m_cycle_57.phase();
			t_sample add_2524 = (cycle_2526 + ((int)1));
			t_sample div_2523 = (add_2524 * ((t_sample)0.5));
			t_sample mul_2525 = (div_2523 * clamp_2449);
			t_sample sub_2744 = (mul_2525 - ((int)0));
			t_sample scale_2741 = ((safepow((sub_2744 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_2530 = scale_2741;
			t_sample mtof_2531 = mtof(scale_2530, ((int)440));
			t_sample mul_2518 = (mtof_2531 * div_2519);
			t_sample cos_2516 = cos(mul_2518);
			t_sample mul_2511 = (cos_2516 * (-2));
			t_sample sin_2517 = sin(mul_2518);
			t_sample mul_2515 = (sin_2517 * ((t_sample)0.5));
			t_sample div_2514 = (mul_2515 * ((t_sample)0.33333333333333));
			t_sample rsub_2509 = (((int)1) - div_2514);
			t_sample add_2513 = (div_2514 + ((int)1));
			t_sample rdiv_2512 = safediv(((int)1), add_2513);
			t_sample mul_2508 = (rdiv_2512 * rsub_2509);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((mul_2508 > __m_slide_58) ? iup_59 : idown_60) * (mul_2508 - __m_slide_58))));
			t_sample slide_2505 = __m_slide_58;
			t_sample gen_2521 = slide_2505;
			t_sample mul_2510 = (rdiv_2512 * mul_2511);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((mul_2510 > __m_slide_61) ? iup_62 : idown_63) * (mul_2510 - __m_slide_61))));
			t_sample slide_2506 = __m_slide_61;
			t_sample gen_2520 = slide_2506;
			t_sample mul_2541 = (add_2458 * gen_2521);
			t_sample mul_2538 = (m_history_4 * gen_2520);
			t_sample mul_2536 = (m_history_5 * ((int)1));
			t_sample mul_2532 = (m_history_6 * gen_2521);
			t_sample mul_2534 = (m_history_3 * gen_2520);
			t_sample sub_2540 = (((mul_2536 + mul_2538) + mul_2541) - (mul_2534 + mul_2532));
			t_sample gen_2546 = sub_2540;
			t_sample history_2533_next_2542 = fixdenorm(m_history_3);
			t_sample history_2537_next_2543 = fixdenorm(m_history_4);
			t_sample history_2539_next_2544 = fixdenorm(add_2458);
			t_sample history_2535_next_2545 = fixdenorm(sub_2540);
			t_sample mul_2460 = ((gen_2546 + gen_2504) * ((t_sample)0.5));
			t_sample dcblock_2461 = __m_dcblock_64(mul_2460);
			t_sample mul_2462 = (((gate_2454 + gen_2546) + gen_2504) * scale_2725);
			t_sample div_2425 = (mul_2462 * ((t_sample)0.5));
			t_sample add_2591 = (gate_2453 + div_2425);
			t_sample out2 = add_2591;
			t_sample history_2457_next_2651 = fixdenorm(dcblock_2592);
			t_sample history_2598_next_2652 = fixdenorm(dcblock_2461);
			m_history_22 = history_2322_next_2324;
			m_history_21 = history_2437_next_2440;
			m_history_19 = history_2432_next_2442;
			m_history_20 = history_2434_next_2441;
			m_history_18 = history_2580_next_2585;
			m_history_15 = history_2578_next_2588;
			m_history_16 = history_2582_next_2587;
			m_history_17 = history_2576_next_2586;
			m_history_14 = history_2638_next_2643;
			m_history_11 = history_2636_next_2646;
			m_history_12 = history_2640_next_2645;
			m_history_13 = history_2634_next_2644;
			m_history_10 = history_2495_next_2500;
			m_history_7 = history_2493_next_2503;
			m_history_8 = history_2497_next_2502;
			m_history_9 = history_2491_next_2501;
			m_history_6 = history_2533_next_2542;
			m_history_3 = history_2535_next_2545;
			m_history_4 = history_2539_next_2544;
			m_history_5 = history_2537_next_2543;
			m_history_2 = history_2457_next_2651;
			m_history_1 = history_2598_next_2652;
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
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_diffusion(t_param _value) {
		m_knob6_diffusion_25 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_26 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_knob3_depth(value); break;
		case 1: self->set_knob4_rate(value); break;
		case 2: self->set_knob5_fb(value); break;
		case 3: self->set_knob6_diffusion(value); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_depth_23; break;
		case 1: *value = self->m_knob4_rate_27; break;
		case 2: *value = self->m_knob5_fb_26; break;
		case 3: *value = self->m_knob6_diffusion_25; break;
		case 4: *value = self->m_sw_24; break;
		case 5: *value = self->m_sw_28; break;
		
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
	// initialize parameter 0 ("m_knob3_depth_23")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_27")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_fb_26")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_diffusion_25")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_diffusion";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_diffusion_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
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
	// initialize parameter 5 ("m_sw_28")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
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


} // Phaser::
