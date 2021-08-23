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
	t_sample m_knob6_diffusion_28;
	t_sample __m_slide_51;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_slide_46;
	t_sample m_history_7;
	t_sample m_knob4_rate_27;
	t_sample m_knob3_depth_25;
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
	t_sample m_sw_23;
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
		m_sw_23 = ((int)0);
		m_sw_24 = ((int)0);
		m_knob3_depth_25 = 1;
		m_knob5_fb_26 = ((int)0);
		m_knob4_rate_27 = 0.1;
		m_knob6_diffusion_28 = 1;
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
		t_sample sub_828 = (m_knob5_fb_26 - ((t_sample)0.5));
		t_sample scale_825 = ((safepow((sub_828 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		t_sample mul_726 = (m_knob6_diffusion_28 * ((int)2));
		t_sample div_724 = (mul_726 * ((t_sample)0.125));
		t_sample mul_727 = (m_knob6_diffusion_28 * ((int)0));
		t_sample div_725 = (mul_727 * ((t_sample)0.125));
		t_sample mul_719 = (m_knob6_diffusion_28 * ((int)3));
		t_sample div_717 = (mul_719 * ((t_sample)0.125));
		t_sample mul_720 = (m_knob6_diffusion_28 * ((int)1));
		t_sample div_718 = (mul_720 * ((t_sample)0.125));
		t_sample mstosamps_567 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_566 = (((int)100) * (samplerate * 0.001));
		t_sample iup_33 = (1 / maximum(1, abs(mstosamps_567)));
		t_sample idown_34 = (1 / maximum(1, abs(mstosamps_566)));
		t_sample div_685 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_37 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_38 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_40 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_41 = (1 / maximum(1, abs(((int)5))));
		t_sample div_743 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_44 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)5))));
		t_sample div_600 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_52 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)5))));
		t_sample div_642 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_576 = __m_sah_29(m_history_22, m_sw_24, ((int)0));
			t_sample gen_578 = sah_576;
			t_sample rsub_574 = (((int)1) - sah_576);
			t_sample history_575_next_577 = fixdenorm(rsub_574);
			t_sample out3 = gen_578;
			t_sample mix_822 = (m_history_21 + (((t_sample)0.0019634941468452) * (m_knob4_rate_27 - m_history_21)));
			t_sample mix_557 = mix_822;
			t_sample mix_823 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_557 - m_history_20)));
			t_sample mix_555 = mix_823;
			t_sample mix_824 = (m_history_19 + (((t_sample)0.0019634941468452) * (mix_555 - m_history_19)));
			t_sample mix_553 = mix_824;
			t_sample gen_563 = mix_553;
			t_sample history_558_next_560 = fixdenorm(mix_557);
			t_sample history_556_next_561 = fixdenorm(mix_555);
			t_sample history_554_next_562 = fixdenorm(mix_553);
			t_sample expr_773 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_563)))));
			t_sample add_579 = (gen_578 + ((int)1));
			t_sample choice_30 = int(add_579);
			t_sample gate_572 = (((choice_30 >= 1) && (choice_30 < 2)) ? in1 : 0);
			t_sample gate_573 = ((choice_30 >= 2) ? in1 : 0);
			t_sample mul_723 = (m_history_1 * m_knob5_fb_26);
			t_sample add_722 = (gate_573 + mul_723);
			t_sample mul_772 = (expr_773 * ((t_sample)7.5));
			t_sample phasor_728 = __m_phasor_31(mul_772, samples_to_seconds);
			t_sample mul_582 = (m_history_2 * m_knob5_fb_26);
			t_sample add_581 = (gate_573 + mul_582);
			t_sample abs_546 = fabs(gate_573);
			t_sample mul_545 = (abs_546 * ((int)30));
			t_sample switch_570 = (m_sw_23 ? mul_545 : ((int)1));
			__m_slide_32 = fixdenorm((__m_slide_32 + (((switch_570 > __m_slide_32) ? iup_33 : idown_34) * (switch_570 - __m_slide_32))));
			t_sample slide_571 = __m_slide_32;
			t_sample mul_550 = (m_knob3_depth_25 * slide_571);
			t_sample clamp_569 = ((mul_550 <= ((int)0)) ? ((int)0) : ((mul_550 >= ((int)1)) ? ((int)1) : mul_550));
			t_sample add_694 = (phasor_728 + div_724);
			t_sample mod_695 = safemod(add_694, ((int)1));
			__m_cycle_35.phase(mod_695);
			t_sample cycle_692 = __m_cycle_35(__sinedata);
			t_sample cycleindex_693 = __m_cycle_35.phase();
			t_sample add_690 = (cycle_692 + ((int)1));
			t_sample div_689 = (add_690 * ((t_sample)0.5));
			t_sample mul_691 = (div_689 * clamp_569);
			t_sample sub_832 = (mul_691 - ((int)0));
			t_sample scale_829 = ((safepow((sub_832 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_696 = scale_829;
			t_sample mtof_697 = mtof(scale_696, ((int)440));
			t_sample mul_684 = (mtof_697 * div_685);
			t_sample cos_682 = cos(mul_684);
			t_sample mul_677 = (cos_682 * (-2));
			t_sample sin_683 = sin(mul_684);
			t_sample mul_681 = (sin_683 * ((t_sample)0.5));
			t_sample div_680 = (mul_681 * ((t_sample)0.33333333333333));
			t_sample rsub_675 = (((int)1) - div_680);
			t_sample add_679 = (div_680 + ((int)1));
			t_sample rdiv_678 = safediv(((int)1), add_679);
			t_sample mul_676 = (rdiv_678 * mul_677);
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_676 > __m_slide_36) ? iup_37 : idown_38) * (mul_676 - __m_slide_36))));
			t_sample slide_672 = __m_slide_36;
			t_sample gen_686 = slide_672;
			t_sample mul_674 = (rdiv_678 * rsub_675);
			__m_slide_39 = fixdenorm((__m_slide_39 + (((mul_674 > __m_slide_39) ? iup_40 : idown_41) * (mul_674 - __m_slide_39))));
			t_sample slide_671 = __m_slide_39;
			t_sample gen_687 = slide_671;
			t_sample mul_707 = (add_722 * gen_687);
			t_sample mul_704 = (m_history_16 * gen_686);
			t_sample mul_702 = (m_history_17 * ((int)1));
			t_sample mul_698 = (m_history_18 * gen_687);
			t_sample mul_700 = (m_history_15 * gen_686);
			t_sample sub_706 = (((mul_702 + mul_704) + mul_707) - (mul_700 + mul_698));
			t_sample gen_712 = sub_706;
			t_sample history_699_next_708 = fixdenorm(m_history_15);
			t_sample history_703_next_709 = fixdenorm(m_history_16);
			t_sample history_705_next_710 = fixdenorm(add_722);
			t_sample history_701_next_711 = fixdenorm(sub_706);
			t_sample add_752 = (phasor_728 + div_725);
			t_sample mod_753 = safemod(add_752, ((int)1));
			__m_cycle_42.phase(mod_753);
			t_sample cycle_750 = __m_cycle_42(__sinedata);
			t_sample cycleindex_751 = __m_cycle_42.phase();
			t_sample add_748 = (cycle_750 + ((int)1));
			t_sample div_747 = (add_748 * ((t_sample)0.5));
			t_sample mul_749 = (div_747 * clamp_569);
			t_sample sub_836 = (mul_749 - ((int)0));
			t_sample scale_833 = ((safepow((sub_836 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_754 = scale_833;
			t_sample mtof_755 = mtof(scale_754, ((int)440));
			t_sample mul_742 = (mtof_755 * div_743);
			t_sample cos_740 = cos(mul_742);
			t_sample mul_735 = (cos_740 * (-2));
			t_sample sin_741 = sin(mul_742);
			t_sample mul_739 = (sin_741 * ((t_sample)0.5));
			t_sample div_738 = (mul_739 * ((t_sample)0.33333333333333));
			t_sample rsub_733 = (((int)1) - div_738);
			t_sample add_737 = (div_738 + ((int)1));
			t_sample rdiv_736 = safediv(((int)1), add_737);
			t_sample mul_732 = (rdiv_736 * rsub_733);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((mul_732 > __m_slide_43) ? iup_44 : idown_45) * (mul_732 - __m_slide_43))));
			t_sample slide_729 = __m_slide_43;
			t_sample gen_745 = slide_729;
			t_sample mul_734 = (rdiv_736 * mul_735);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((mul_734 > __m_slide_46) ? iup_47 : idown_48) * (mul_734 - __m_slide_46))));
			t_sample slide_730 = __m_slide_46;
			t_sample gen_744 = slide_730;
			t_sample mul_765 = (add_722 * gen_745);
			t_sample mul_762 = (m_history_12 * gen_744);
			t_sample mul_760 = (m_history_13 * ((int)1));
			t_sample mul_756 = (m_history_14 * gen_745);
			t_sample mul_758 = (m_history_11 * gen_744);
			t_sample sub_764 = (((mul_760 + mul_762) + mul_765) - (mul_758 + mul_756));
			t_sample gen_770 = sub_764;
			t_sample history_757_next_766 = fixdenorm(m_history_11);
			t_sample history_761_next_767 = fixdenorm(m_history_12);
			t_sample history_763_next_768 = fixdenorm(add_722);
			t_sample history_759_next_769 = fixdenorm(sub_764);
			t_sample mul_670 = ((gen_770 + gen_712) * ((t_sample)0.5));
			t_sample dcblock_715 = __m_dcblock_49(mul_670);
			t_sample mul_713 = (((gate_573 + gen_770) + gen_712) * scale_825);
			t_sample div_547 = (mul_713 * ((t_sample)0.5));
			t_sample add_716 = (gate_572 + div_547);
			t_sample out1 = add_716;
			t_sample add_609 = (phasor_728 + div_717);
			t_sample mod_610 = safemod(add_609, ((int)1));
			__m_cycle_50.phase(mod_610);
			t_sample cycle_607 = __m_cycle_50(__sinedata);
			t_sample cycleindex_608 = __m_cycle_50.phase();
			t_sample add_605 = (cycle_607 + ((int)1));
			t_sample div_604 = (add_605 * ((t_sample)0.5));
			t_sample mul_606 = (div_604 * clamp_569);
			t_sample sub_840 = (mul_606 - ((int)0));
			t_sample scale_837 = ((safepow((sub_840 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_611 = scale_837;
			t_sample mtof_612 = mtof(scale_611, ((int)440));
			t_sample mul_599 = (mtof_612 * div_600);
			t_sample cos_597 = cos(mul_599);
			t_sample mul_592 = (cos_597 * (-2));
			t_sample sin_598 = sin(mul_599);
			t_sample mul_596 = (sin_598 * ((t_sample)0.5));
			t_sample div_595 = (mul_596 * ((t_sample)0.33333333333333));
			t_sample rsub_590 = (((int)1) - div_595);
			t_sample add_594 = (div_595 + ((int)1));
			t_sample rdiv_593 = safediv(((int)1), add_594);
			t_sample mul_591 = (rdiv_593 * mul_592);
			__m_slide_51 = fixdenorm((__m_slide_51 + (((mul_591 > __m_slide_51) ? iup_52 : idown_53) * (mul_591 - __m_slide_51))));
			t_sample slide_587 = __m_slide_51;
			t_sample gen_601 = slide_587;
			t_sample mul_589 = (rdiv_593 * rsub_590);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((mul_589 > __m_slide_54) ? iup_55 : idown_56) * (mul_589 - __m_slide_54))));
			t_sample slide_586 = __m_slide_54;
			t_sample gen_602 = slide_586;
			t_sample mul_622 = (add_581 * gen_602);
			t_sample mul_619 = (m_history_8 * gen_601);
			t_sample mul_617 = (m_history_9 * ((int)1));
			t_sample mul_613 = (m_history_10 * gen_602);
			t_sample mul_615 = (m_history_7 * gen_601);
			t_sample sub_621 = (((mul_617 + mul_619) + mul_622) - (mul_615 + mul_613));
			t_sample gen_627 = sub_621;
			t_sample history_614_next_623 = fixdenorm(m_history_7);
			t_sample history_618_next_624 = fixdenorm(m_history_8);
			t_sample history_620_next_625 = fixdenorm(add_581);
			t_sample history_616_next_626 = fixdenorm(sub_621);
			t_sample add_651 = (phasor_728 + div_718);
			t_sample mod_652 = safemod(add_651, ((int)1));
			__m_cycle_57.phase(mod_652);
			t_sample cycle_649 = __m_cycle_57(__sinedata);
			t_sample cycleindex_650 = __m_cycle_57.phase();
			t_sample add_647 = (cycle_649 + ((int)1));
			t_sample div_646 = (add_647 * ((t_sample)0.5));
			t_sample mul_648 = (div_646 * clamp_569);
			t_sample sub_844 = (mul_648 - ((int)0));
			t_sample scale_841 = ((safepow((sub_844 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_653 = scale_841;
			t_sample mtof_654 = mtof(scale_653, ((int)440));
			t_sample mul_641 = (mtof_654 * div_642);
			t_sample cos_639 = cos(mul_641);
			t_sample mul_634 = (cos_639 * (-2));
			t_sample sin_640 = sin(mul_641);
			t_sample mul_638 = (sin_640 * ((t_sample)0.5));
			t_sample div_637 = (mul_638 * ((t_sample)0.33333333333333));
			t_sample rsub_632 = (((int)1) - div_637);
			t_sample add_636 = (div_637 + ((int)1));
			t_sample rdiv_635 = safediv(((int)1), add_636);
			t_sample mul_633 = (rdiv_635 * mul_634);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((mul_633 > __m_slide_58) ? iup_59 : idown_60) * (mul_633 - __m_slide_58))));
			t_sample slide_629 = __m_slide_58;
			t_sample gen_643 = slide_629;
			t_sample mul_631 = (rdiv_635 * rsub_632);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((mul_631 > __m_slide_61) ? iup_62 : idown_63) * (mul_631 - __m_slide_61))));
			t_sample slide_628 = __m_slide_61;
			t_sample gen_644 = slide_628;
			t_sample mul_664 = (add_581 * gen_644);
			t_sample mul_661 = (m_history_4 * gen_643);
			t_sample mul_659 = (m_history_6 * ((int)1));
			t_sample mul_655 = (m_history_5 * gen_644);
			t_sample mul_657 = (m_history_3 * gen_643);
			t_sample sub_663 = (((mul_659 + mul_661) + mul_664) - (mul_657 + mul_655));
			t_sample gen_669 = sub_663;
			t_sample history_660_next_665 = fixdenorm(m_history_4);
			t_sample history_656_next_666 = fixdenorm(m_history_3);
			t_sample history_662_next_667 = fixdenorm(add_581);
			t_sample history_658_next_668 = fixdenorm(sub_663);
			t_sample mul_583 = ((gen_669 + gen_627) * ((t_sample)0.5));
			t_sample dcblock_584 = __m_dcblock_64(mul_583);
			t_sample mul_585 = (((gate_573 + gen_669) + gen_627) * scale_825);
			t_sample div_548 = (mul_585 * ((t_sample)0.5));
			t_sample add_714 = (gate_572 + div_548);
			t_sample out2 = add_714;
			t_sample history_580_next_774 = fixdenorm(dcblock_715);
			t_sample history_721_next_775 = fixdenorm(dcblock_584);
			m_history_22 = history_575_next_577;
			m_history_21 = history_558_next_560;
			m_history_19 = history_554_next_562;
			m_history_20 = history_556_next_561;
			m_history_18 = history_699_next_708;
			m_history_15 = history_701_next_711;
			m_history_16 = history_705_next_710;
			m_history_17 = history_703_next_709;
			m_history_14 = history_757_next_766;
			m_history_11 = history_759_next_769;
			m_history_12 = history_763_next_768;
			m_history_13 = history_761_next_767;
			m_history_10 = history_614_next_623;
			m_history_7 = history_616_next_626;
			m_history_8 = history_620_next_625;
			m_history_9 = history_618_next_624;
			m_history_6 = history_660_next_665;
			m_history_3 = history_658_next_668;
			m_history_4 = history_662_next_667;
			m_history_5 = history_656_next_666;
			m_history_2 = history_580_next_774;
			m_history_1 = history_721_next_775;
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
	inline void set_sw5(t_param _value) {
		m_sw_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_26 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_diffusion(t_param _value) {
		m_knob6_diffusion_28 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
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
		case 0: *value = self->m_knob3_depth_25; break;
		case 1: *value = self->m_knob4_rate_27; break;
		case 2: *value = self->m_knob5_fb_26; break;
		case 3: *value = self->m_knob6_diffusion_28; break;
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
	// initialize parameter 0 ("m_knob3_depth_25")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_25;
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
	// initialize parameter 3 ("m_knob6_diffusion_28")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_diffusion";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_diffusion_28;
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


} // Phaser::
