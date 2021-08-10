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
	t_sample m_knob5_fb_28;
	t_sample __m_slide_51;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_slide_46;
	t_sample m_history_7;
	t_sample m_knob6_diffusion_27;
	t_sample m_sw_25;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_12;
	t_sample m_history_10;
	t_sample m_history_11;
	t_sample m_history_9;
	t_sample m_knob4_rate_26;
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
		m_sw_25 = ((int)0);
		m_knob4_rate_26 = 0.1;
		m_knob6_diffusion_27 = 1;
		m_knob5_fb_28 = ((int)0);
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
		t_sample sub_42840 = (m_knob5_fb_28 - ((t_sample)0.5));
		t_sample scale_42837 = ((safepow((sub_42840 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		t_sample mul_42696 = (m_knob6_diffusion_27 * ((int)2));
		t_sample div_42694 = (mul_42696 * ((t_sample)0.125));
		t_sample mul_42697 = (m_knob6_diffusion_27 * ((int)0));
		t_sample div_42695 = (mul_42697 * ((t_sample)0.125));
		t_sample mul_42689 = (m_knob6_diffusion_27 * ((int)3));
		t_sample div_42687 = (mul_42689 * ((t_sample)0.125));
		t_sample mul_42690 = (m_knob6_diffusion_27 * ((int)1));
		t_sample div_42688 = (mul_42690 * ((t_sample)0.125));
		t_sample mstosamps_42532 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_42531 = (((int)100) * (samplerate * 0.001));
		samples_to_seconds = (1 / samplerate);
		t_sample iup_33 = (1 / maximum(1, abs(mstosamps_42532)));
		t_sample idown_34 = (1 / maximum(1, abs(mstosamps_42531)));
		t_sample div_42651 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_37 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_38 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_40 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_41 = (1 / maximum(1, abs(((int)5))));
		t_sample div_42713 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_44 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)5))));
		t_sample div_42566 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_52 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)5))));
		t_sample div_42608 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_42542 = __m_sah_29(m_history_22, m_sw_25, ((int)0));
			t_sample gen_42544 = sah_42542;
			t_sample rsub_42540 = (((int)1) - sah_42542);
			t_sample history_42541_next_42543 = fixdenorm(rsub_42540);
			t_sample out3 = gen_42544;
			t_sample add_42545 = (gen_42544 + ((int)1));
			t_sample choice_30 = int(add_42545);
			t_sample gate_42538 = (((choice_30 >= 1) && (choice_30 < 2)) ? in1 : 0);
			t_sample gate_42539 = ((choice_30 >= 2) ? in1 : 0);
			t_sample mul_42693 = (m_history_1 * m_knob5_fb_28);
			t_sample add_42692 = (gate_42539 + mul_42693);
			t_sample mul_42548 = (m_history_2 * m_knob5_fb_28);
			t_sample add_42547 = (gate_42539 + mul_42548);
			t_sample mix_42841 = (m_history_21 + (((t_sample)0.0019634941468452) * (m_knob4_rate_26 - m_history_21)));
			t_sample mix_42519 = mix_42841;
			t_sample mix_42842 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_42519 - m_history_20)));
			t_sample mix_42517 = mix_42842;
			t_sample mix_42843 = (m_history_19 + (((t_sample)0.0019634941468452) * (mix_42517 - m_history_19)));
			t_sample mix_42515 = mix_42843;
			t_sample gen_42527 = mix_42515;
			t_sample history_42521_next_42524 = fixdenorm(mix_42519);
			t_sample history_42518_next_42525 = fixdenorm(mix_42517);
			t_sample history_42516_next_42526 = fixdenorm(mix_42515);
			t_sample rsub_42683 = (((int)1) - gen_42527);
			t_sample sqrt_42682 = sqrt(rsub_42683);
			t_sample sqrt_42681 = sqrt(sqrt_42682);
			t_sample sqrt_42528 = sqrt(sqrt_42681);
			t_sample rsub_42680 = (((int)1) - sqrt_42528);
			t_sample mul_42742 = (rsub_42680 * ((t_sample)7.5));
			t_sample phasor_42698 = __m_phasor_31(mul_42742, samples_to_seconds);
			t_sample switch_42535 = (m_sw_24 ? gate_42539 : ((int)1));
			t_sample abs_42537 = fabs(switch_42535);
			t_sample mul_42513 = (abs_42537 * ((int)100));
			__m_slide_32 = fixdenorm((__m_slide_32 + (((mul_42513 > __m_slide_32) ? iup_33 : idown_34) * (mul_42513 - __m_slide_32))));
			t_sample slide_42536 = __m_slide_32;
			t_sample clamp_42511 = ((slide_42536 <= ((int)0)) ? ((int)0) : ((slide_42536 >= ((int)1)) ? ((int)1) : slide_42536));
			t_sample mul_42510 = (m_knob3_depth_23 * clamp_42511);
			t_sample clamp_42534 = ((mul_42510 <= ((int)0)) ? ((int)0) : ((mul_42510 >= ((int)1)) ? ((int)1) : mul_42510));
			t_sample add_42660 = (phasor_42698 + div_42694);
			t_sample mod_42661 = safemod(add_42660, ((int)1));
			__m_cycle_35.phase(mod_42661);
			t_sample cycle_42658 = __m_cycle_35(__sinedata);
			t_sample cycleindex_42659 = __m_cycle_35.phase();
			t_sample add_42656 = (cycle_42658 + ((int)1));
			t_sample div_42655 = (add_42656 * ((t_sample)0.5));
			t_sample mul_42657 = (div_42655 * clamp_42534);
			t_sample sub_42847 = (mul_42657 - ((int)0));
			t_sample scale_42844 = ((safepow((sub_42847 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_42662 = scale_42844;
			t_sample mtof_42663 = mtof(scale_42662, ((int)440));
			t_sample mul_42650 = (mtof_42663 * div_42651);
			t_sample cos_42648 = cos(mul_42650);
			t_sample mul_42643 = (cos_42648 * (-2));
			t_sample sin_42649 = sin(mul_42650);
			t_sample mul_42647 = (sin_42649 * ((t_sample)0.5));
			t_sample div_42646 = (mul_42647 * ((t_sample)0.33333333333333));
			t_sample rsub_42641 = (((int)1) - div_42646);
			t_sample add_42645 = (div_42646 + ((int)1));
			t_sample rdiv_42644 = safediv(((int)1), add_42645);
			t_sample mul_42642 = (rdiv_42644 * mul_42643);
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_42642 > __m_slide_36) ? iup_37 : idown_38) * (mul_42642 - __m_slide_36))));
			t_sample slide_42638 = __m_slide_36;
			t_sample gen_42652 = slide_42638;
			t_sample mul_42640 = (rdiv_42644 * rsub_42641);
			__m_slide_39 = fixdenorm((__m_slide_39 + (((mul_42640 > __m_slide_39) ? iup_40 : idown_41) * (mul_42640 - __m_slide_39))));
			t_sample slide_42637 = __m_slide_39;
			t_sample gen_42653 = slide_42637;
			t_sample mul_42673 = (add_42692 * gen_42653);
			t_sample mul_42670 = (m_history_16 * gen_42652);
			t_sample mul_42668 = (m_history_18 * ((int)1));
			t_sample mul_42664 = (m_history_17 * gen_42653);
			t_sample mul_42666 = (m_history_15 * gen_42652);
			t_sample sub_42672 = (((mul_42668 + mul_42670) + mul_42673) - (mul_42666 + mul_42664));
			t_sample gen_42678 = sub_42672;
			t_sample history_42669_next_42674 = fixdenorm(m_history_16);
			t_sample history_42665_next_42675 = fixdenorm(m_history_15);
			t_sample history_42671_next_42676 = fixdenorm(add_42692);
			t_sample history_42667_next_42677 = fixdenorm(sub_42672);
			t_sample add_42722 = (phasor_42698 + div_42695);
			t_sample mod_42723 = safemod(add_42722, ((int)1));
			__m_cycle_42.phase(mod_42723);
			t_sample cycle_42720 = __m_cycle_42(__sinedata);
			t_sample cycleindex_42721 = __m_cycle_42.phase();
			t_sample add_42718 = (cycle_42720 + ((int)1));
			t_sample div_42717 = (add_42718 * ((t_sample)0.5));
			t_sample mul_42719 = (div_42717 * clamp_42534);
			t_sample sub_42851 = (mul_42719 - ((int)0));
			t_sample scale_42848 = ((safepow((sub_42851 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_42724 = scale_42848;
			t_sample mtof_42725 = mtof(scale_42724, ((int)440));
			t_sample mul_42712 = (mtof_42725 * div_42713);
			t_sample cos_42710 = cos(mul_42712);
			t_sample mul_42705 = (cos_42710 * (-2));
			t_sample sin_42711 = sin(mul_42712);
			t_sample mul_42709 = (sin_42711 * ((t_sample)0.5));
			t_sample div_42708 = (mul_42709 * ((t_sample)0.33333333333333));
			t_sample rsub_42703 = (((int)1) - div_42708);
			t_sample add_42707 = (div_42708 + ((int)1));
			t_sample rdiv_42706 = safediv(((int)1), add_42707);
			t_sample mul_42704 = (rdiv_42706 * mul_42705);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((mul_42704 > __m_slide_43) ? iup_44 : idown_45) * (mul_42704 - __m_slide_43))));
			t_sample slide_42700 = __m_slide_43;
			t_sample gen_42714 = slide_42700;
			t_sample mul_42702 = (rdiv_42706 * rsub_42703);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((mul_42702 > __m_slide_46) ? iup_47 : idown_48) * (mul_42702 - __m_slide_46))));
			t_sample slide_42699 = __m_slide_46;
			t_sample gen_42715 = slide_42699;
			t_sample mul_42735 = (add_42692 * gen_42715);
			t_sample mul_42732 = (m_history_12 * gen_42714);
			t_sample mul_42730 = (m_history_14 * ((int)1));
			t_sample mul_42726 = (m_history_13 * gen_42715);
			t_sample mul_42728 = (m_history_11 * gen_42714);
			t_sample sub_42734 = (((mul_42730 + mul_42732) + mul_42735) - (mul_42728 + mul_42726));
			t_sample gen_42740 = sub_42734;
			t_sample history_42731_next_42736 = fixdenorm(m_history_12);
			t_sample history_42727_next_42737 = fixdenorm(m_history_11);
			t_sample history_42733_next_42738 = fixdenorm(add_42692);
			t_sample history_42729_next_42739 = fixdenorm(sub_42734);
			t_sample mul_42636 = ((gen_42740 + gen_42678) * ((t_sample)0.5));
			t_sample dcblock_42685 = __m_dcblock_49(mul_42636);
			t_sample mul_42679 = (((gate_42539 + gen_42740) + gen_42678) * scale_42837);
			t_sample add_42686 = (mul_42679 + gate_42538);
			t_sample out1 = add_42686;
			t_sample add_42575 = (phasor_42698 + div_42687);
			t_sample mod_42576 = safemod(add_42575, ((int)1));
			__m_cycle_50.phase(mod_42576);
			t_sample cycle_42573 = __m_cycle_50(__sinedata);
			t_sample cycleindex_42574 = __m_cycle_50.phase();
			t_sample add_42571 = (cycle_42573 + ((int)1));
			t_sample div_42570 = (add_42571 * ((t_sample)0.5));
			t_sample mul_42572 = (div_42570 * clamp_42534);
			t_sample sub_42855 = (mul_42572 - ((int)0));
			t_sample scale_42852 = ((safepow((sub_42855 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_42577 = scale_42852;
			t_sample mtof_42578 = mtof(scale_42577, ((int)440));
			t_sample mul_42565 = (mtof_42578 * div_42566);
			t_sample cos_42563 = cos(mul_42565);
			t_sample mul_42558 = (cos_42563 * (-2));
			t_sample sin_42564 = sin(mul_42565);
			t_sample mul_42562 = (sin_42564 * ((t_sample)0.5));
			t_sample div_42561 = (mul_42562 * ((t_sample)0.33333333333333));
			t_sample rsub_42556 = (((int)1) - div_42561);
			t_sample add_42560 = (div_42561 + ((int)1));
			t_sample rdiv_42559 = safediv(((int)1), add_42560);
			t_sample mul_42555 = (rdiv_42559 * rsub_42556);
			__m_slide_51 = fixdenorm((__m_slide_51 + (((mul_42555 > __m_slide_51) ? iup_52 : idown_53) * (mul_42555 - __m_slide_51))));
			t_sample slide_42552 = __m_slide_51;
			t_sample gen_42568 = slide_42552;
			t_sample mul_42557 = (rdiv_42559 * mul_42558);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((mul_42557 > __m_slide_54) ? iup_55 : idown_56) * (mul_42557 - __m_slide_54))));
			t_sample slide_42553 = __m_slide_54;
			t_sample gen_42567 = slide_42553;
			t_sample mul_42588 = (add_42547 * gen_42568);
			t_sample mul_42585 = (m_history_8 * gen_42567);
			t_sample mul_42583 = (m_history_9 * ((int)1));
			t_sample mul_42579 = (m_history_10 * gen_42568);
			t_sample mul_42581 = (m_history_7 * gen_42567);
			t_sample sub_42587 = (((mul_42583 + mul_42585) + mul_42588) - (mul_42581 + mul_42579));
			t_sample gen_42593 = sub_42587;
			t_sample history_42580_next_42589 = fixdenorm(m_history_7);
			t_sample history_42584_next_42590 = fixdenorm(m_history_8);
			t_sample history_42586_next_42591 = fixdenorm(add_42547);
			t_sample history_42582_next_42592 = fixdenorm(sub_42587);
			t_sample add_42617 = (phasor_42698 + div_42688);
			t_sample mod_42618 = safemod(add_42617, ((int)1));
			__m_cycle_57.phase(mod_42618);
			t_sample cycle_42615 = __m_cycle_57(__sinedata);
			t_sample cycleindex_42616 = __m_cycle_57.phase();
			t_sample add_42613 = (cycle_42615 + ((int)1));
			t_sample div_42612 = (add_42613 * ((t_sample)0.5));
			t_sample mul_42614 = (div_42612 * clamp_42534);
			t_sample sub_42859 = (mul_42614 - ((int)0));
			t_sample scale_42856 = ((safepow((sub_42859 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_42619 = scale_42856;
			t_sample mtof_42620 = mtof(scale_42619, ((int)440));
			t_sample mul_42607 = (mtof_42620 * div_42608);
			t_sample cos_42605 = cos(mul_42607);
			t_sample mul_42600 = (cos_42605 * (-2));
			t_sample sin_42606 = sin(mul_42607);
			t_sample mul_42604 = (sin_42606 * ((t_sample)0.5));
			t_sample div_42603 = (mul_42604 * ((t_sample)0.33333333333333));
			t_sample rsub_42598 = (((int)1) - div_42603);
			t_sample add_42602 = (div_42603 + ((int)1));
			t_sample rdiv_42601 = safediv(((int)1), add_42602);
			t_sample mul_42599 = (rdiv_42601 * mul_42600);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((mul_42599 > __m_slide_58) ? iup_59 : idown_60) * (mul_42599 - __m_slide_58))));
			t_sample slide_42595 = __m_slide_58;
			t_sample gen_42609 = slide_42595;
			t_sample mul_42597 = (rdiv_42601 * rsub_42598);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((mul_42597 > __m_slide_61) ? iup_62 : idown_63) * (mul_42597 - __m_slide_61))));
			t_sample slide_42594 = __m_slide_61;
			t_sample gen_42610 = slide_42594;
			t_sample mul_42630 = (add_42547 * gen_42610);
			t_sample mul_42627 = (m_history_4 * gen_42609);
			t_sample mul_42625 = (m_history_5 * ((int)1));
			t_sample mul_42621 = (m_history_6 * gen_42610);
			t_sample mul_42623 = (m_history_3 * gen_42609);
			t_sample sub_42629 = (((mul_42625 + mul_42627) + mul_42630) - (mul_42623 + mul_42621));
			t_sample gen_42635 = sub_42629;
			t_sample history_42622_next_42631 = fixdenorm(m_history_3);
			t_sample history_42626_next_42632 = fixdenorm(m_history_4);
			t_sample history_42628_next_42633 = fixdenorm(add_42547);
			t_sample history_42624_next_42634 = fixdenorm(sub_42629);
			t_sample mul_42549 = ((gen_42635 + gen_42593) * ((t_sample)0.5));
			t_sample dcblock_42550 = __m_dcblock_64(mul_42549);
			t_sample mul_42551 = (((gate_42539 + gen_42635) + gen_42593) * scale_42837);
			t_sample add_42684 = (mul_42551 + gate_42538);
			t_sample out2 = add_42684;
			t_sample history_42546_next_42743 = fixdenorm(dcblock_42685);
			t_sample history_42691_next_42744 = fixdenorm(dcblock_42550);
			m_history_22 = history_42541_next_42543;
			m_history_21 = history_42521_next_42524;
			m_history_19 = history_42516_next_42526;
			m_history_20 = history_42518_next_42525;
			m_history_18 = history_42669_next_42674;
			m_history_15 = history_42667_next_42677;
			m_history_16 = history_42671_next_42676;
			m_history_17 = history_42665_next_42675;
			m_history_14 = history_42731_next_42736;
			m_history_11 = history_42729_next_42739;
			m_history_12 = history_42733_next_42738;
			m_history_13 = history_42727_next_42737;
			m_history_10 = history_42580_next_42589;
			m_history_7 = history_42582_next_42592;
			m_history_8 = history_42586_next_42591;
			m_history_9 = history_42584_next_42590;
			m_history_6 = history_42622_next_42631;
			m_history_3 = history_42624_next_42634;
			m_history_4 = history_42628_next_42633;
			m_history_5 = history_42626_next_42632;
			m_history_2 = history_42546_next_42743;
			m_history_1 = history_42691_next_42744;
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
	inline void set_sw5(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_diffusion(t_param _value) {
		m_knob6_diffusion_27 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_28 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
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
		case 1: *value = self->m_knob4_rate_26; break;
		case 2: *value = self->m_knob5_fb_28; break;
		case 3: *value = self->m_knob6_diffusion_27; break;
		case 4: *value = self->m_sw_25; break;
		case 5: *value = self->m_sw_24; break;
		
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
	// initialize parameter 1 ("m_knob4_rate_26")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_fb_28")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_diffusion_27")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_diffusion";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_diffusion_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_25")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_24")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Phaser::
