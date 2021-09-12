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
	t_sample m_knob1_wetdry_32;
	t_sample m_knob5_glitchlen_33;
	t_sample m_history_3;
	t_sample m_knob6_density_31;
	t_sample samplerate;
	t_sample m_sw_27;
	t_sample m_sw_30;
	t_sample m_knob4_buflen_28;
	t_sample m_knob3_thresh_29;
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
		m_sw_27 = ((int)0);
		m_knob4_buflen_28 = ((int)0);
		m_knob3_thresh_29 = ((int)0);
		m_sw_30 = ((int)0);
		m_knob6_density_31 = ((int)0);
		m_knob1_wetdry_32 = ((int)0);
		m_knob5_glitchlen_33 = ((int)0);
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
		t_sample mstosamps_1004 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_1002 = (((int)100) * (samplerate * 0.001));
		t_sample iup_41 = (1 / maximum(1, abs(mstosamps_1004)));
		t_sample idown_42 = (1 / maximum(1, abs(mstosamps_1002)));
		t_sample mstosamps_615 = (((int)1) * (samplerate * 0.001));
		t_sample mul_950 = (m_knob3_thresh_29 * ((t_sample)0.95));
		t_sample mstosamps_604 = (((int)1) * (samplerate * 0.001));
		t_sample mul_949 = (m_knob3_thresh_29 * ((t_sample)1.03));
		t_sample mstosamps_593 = (((int)1) * (samplerate * 0.001));
		t_sample mul_948 = (m_knob3_thresh_29 * ((t_sample)0.98));
		t_sample mstosamps_582 = (((int)1) * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_1010 = __m_sah_35(m_history_26, m_sw_27, ((int)0));
			t_sample gen_1012 = sah_1010;
			t_sample rsub_1008 = (((int)1) - sah_1010);
			t_sample history_1009_next_1011 = fixdenorm(rsub_1008);
			t_sample out3 = gen_1012;
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample mix_1105 = (m_history_25 + (((t_sample)0.003926980723806) * (m_knob4_buflen_28 - m_history_25)));
			t_sample mix_630 = mix_1105;
			t_sample mix_1106 = (m_history_24 + (((t_sample)0.003926980723806) * (mix_630 - m_history_24)));
			t_sample mix_628 = mix_1106;
			t_sample mix_1107 = (m_history_23 + (((t_sample)0.003926980723806) * (mix_628 - m_history_23)));
			t_sample mix_626 = mix_1107;
			t_sample gen_988 = mix_626;
			t_sample history_631_next_633 = fixdenorm(mix_630);
			t_sample history_629_next_634 = fixdenorm(mix_628);
			t_sample history_627_next_635 = fixdenorm(mix_626);
			t_sample expr_1016 = (((int)1) - sqrt((((int)1) - gen_988)));
			t_sample add_1015 = (gen_1012 + ((int)1));
			t_sample choice_36 = int(add_1015);
			t_sample gate_1013 = (((choice_36 >= 1) && (choice_36 < 2)) ? in1 : 0);
			t_sample gate_1014 = ((choice_36 >= 2) ? in1 : 0);
			t_sample mix_1108 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob1_wetdry_32 - m_history_22)));
			t_sample mix_1025 = mix_1108;
			t_sample mix_1109 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_1025 - m_history_21)));
			t_sample mix_1018 = mix_1109;
			t_sample mix_1110 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_1018 - m_history_20)));
			t_sample mix_1022 = mix_1110;
			t_sample gen_636 = mix_1022;
			t_sample history_631_next_1019 = fixdenorm(mix_1025);
			t_sample history_629_next_1020 = fixdenorm(mix_1018);
			t_sample history_627_next_1021 = fixdenorm(mix_1022);
			t_sample sqrt_622 = sqrt(gen_636);
			t_sample rsub_638 = (((int)1) - gen_636);
			t_sample sqrt_637 = sqrt(rsub_638);
			t_sample mul_625 = (sqrt_637 * gate_1014);
			t_sample mul_989 = (expr_1016 * ((int)480000));
			t_sample plusequals_1006 = __m_pluseq_37.post(((int)1), m_history_1, 0);
			t_sample switch_986 = (m_sw_30 ? ((int)-1) : plusequals_1006);
			int index_trunc_38 = fixnan(floor(switch_986));
			bool index_ignore_39 = ((index_trunc_38 >= segments_dim) || (index_trunc_38 < 0));
			if ((!index_ignore_39)) {
				m_segments_34.write(gate_1014, index_trunc_38, 0);
				
			};
			int gte_992 = (plusequals_1006 >= mul_989);
			int eq_991 = (gte_992 == ((int)1));
			t_sample abs_1007 = fabs(gate_1014);
			t_sample mul_640 = (abs_1007 * ((int)30));
			__m_slide_40 = fixdenorm((__m_slide_40 + (((mul_640 > __m_slide_40) ? iup_41 : idown_42) * (mul_640 - __m_slide_40))));
			t_sample slide_1005 = __m_slide_40;
			t_sample clamp_1000 = ((slide_1005 <= ((int)0)) ? ((int)0) : ((slide_1005 >= ((int)1)) ? ((int)1) : slide_1005));
			t_sample out4 = clamp_1000;
			t_sample mix_1111 = (m_history_19 + (((t_sample)0.003926980723806) * (m_knob6_density_31 - m_history_19)));
			t_sample mix_1039 = mix_1111;
			t_sample mix_1112 = (m_history_18 + (((t_sample)0.003926980723806) * (mix_1039 - m_history_18)));
			t_sample mix_1033 = mix_1112;
			t_sample mix_1113 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_1033 - m_history_17)));
			t_sample mix_1031 = mix_1113;
			t_sample gen_873 = mix_1031;
			t_sample history_631_next_1038 = fixdenorm(mix_1039);
			t_sample history_629_next_1030 = fixdenorm(mix_1033);
			t_sample history_627_next_1036 = fixdenorm(mix_1031);
			t_sample sub_1117 = (gen_873 - ((int)0));
			t_sample scale_1114 = ((safepow((sub_1117 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_670 = m_delay_16.read_step(((int)8));
			t_sample tap_672 = m_delay_15.read_step(((int)8));
			t_sample tap_666 = m_delay_14.read_step(((int)8));
			t_sample tap_668 = m_delay_13.read_step(((int)8));
			t_sample tap_658 = m_delay_12.read_step(((int)8));
			t_sample tap_660 = m_delay_11.read_step(((int)8));
			t_sample tap_662 = m_delay_10.read_step(((int)9));
			t_sample tap_664 = m_delay_9.read_step(((int)8));
			t_sample mul_654 = (gen_873 * ((int)12));
			int gte_652 = (mul_654 >= ((int)1));
			int gte_651 = (mul_654 >= ((int)2));
			int gte_650 = (mul_654 >= ((int)3));
			int gte_653 = (mul_654 >= ((int)0));
			int gte_648 = (mul_654 >= ((int)5));
			int gte_649 = (mul_654 >= ((int)4));
			int gte_646 = (mul_654 >= ((int)7));
			int gte_647 = (mul_654 >= ((int)6));
			int gte_642 = (mul_654 >= ((int)11));
			int gte_643 = (mul_654 >= ((int)10));
			int gte_644 = (mul_654 >= ((int)9));
			int gte_645 = (mul_654 >= ((int)8));
			t_sample mix_1118 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob5_glitchlen_33 - m_history_8)));
			t_sample mix_1052 = mix_1118;
			t_sample mix_1119 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_1052 - m_history_7)));
			t_sample mix_1045 = mix_1119;
			t_sample mix_1120 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_1045 - m_history_6)));
			t_sample mix_1044 = mix_1120;
			t_sample gen_875 = mix_1044;
			t_sample history_631_next_1049 = fixdenorm(mix_1052);
			t_sample history_629_next_1043 = fixdenorm(mix_1045);
			t_sample history_627_next_1051 = fixdenorm(mix_1044);
			t_sample mul_619 = (mul_989 * gen_875);
			t_sample clamp_874 = ((mul_619 <= ((int)50)) ? ((int)50) : ((mul_619 >= ((int)480000)) ? ((int)480000) : mul_619));
			t_sample plusequals_834 = __m_pluseq_43.post(((int)1), tap_670, 0);
			t_sample noise_829 = noise();
			t_sample abs_828 = fabs(noise_829);
			t_sample sub_820 = (clamp_874 - ((int)50));
			t_sample mul_827 = (abs_828 * sub_820);
			t_sample sah_830 = __m_sah_44(mul_827, tap_670, ((t_sample)0.5));
			t_sample add_817 = (sah_830 + ((int)50));
			t_sample mod_826 = safemod(plusequals_834, add_817);
			t_sample div_823 = safediv(mod_826, add_817);
			t_sample expr_839 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_823))));
			t_sample noise_837 = noise();
			t_sample abs_836 = fabs(noise_837);
			t_sample mul_835 = (abs_836 * mul_989);
			t_sample sah_838 = __m_sah_45(mul_835, tap_670, ((t_sample)0.5));
			t_sample add_832 = (sah_838 + mod_826);
			t_sample mod_831 = safemod(add_832, mul_989);
			t_sample switch_818 = (gte_648 ? mod_831 : ((int)-1));
			int index_trunc_46 = fixnan(floor(switch_818));
			bool index_ignore_47 = ((index_trunc_46 >= segments_dim) || (index_trunc_46 < 0));
			// samples segments channel 1;
			t_sample sample_segments_824 = (index_ignore_47 ? 0 : m_segments_34.read(index_trunc_46, 0));
			t_sample index_segments_825 = switch_818;
			t_sample mul_821 = (sample_segments_824 * expr_839);
			t_sample plusequals_858 = __m_pluseq_48.post(((int)1), tap_672, 0);
			t_sample noise_853 = noise();
			t_sample abs_852 = fabs(noise_853);
			t_sample sub_844 = (clamp_874 - ((int)50));
			t_sample mul_851 = (abs_852 * sub_844);
			t_sample sah_854 = __m_sah_49(mul_851, tap_672, ((t_sample)0.5));
			t_sample add_841 = (sah_854 + ((int)50));
			t_sample mod_850 = safemod(plusequals_858, add_841);
			t_sample div_847 = safediv(mod_850, add_841);
			t_sample expr_863 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_847))));
			t_sample noise_861 = noise();
			t_sample abs_860 = fabs(noise_861);
			t_sample mul_859 = (abs_860 * mul_989);
			t_sample sah_862 = __m_sah_50(mul_859, tap_672, ((t_sample)0.5));
			t_sample add_856 = (sah_862 + mod_850);
			t_sample mod_855 = safemod(add_856, mul_989);
			t_sample switch_842 = (gte_649 ? mod_855 : ((int)-1));
			int index_trunc_51 = fixnan(floor(switch_842));
			bool index_ignore_52 = ((index_trunc_51 >= segments_dim) || (index_trunc_51 < 0));
			// samples segments channel 1;
			t_sample sample_segments_848 = (index_ignore_52 ? 0 : m_segments_34.read(index_trunc_51, 0));
			t_sample index_segments_849 = switch_842;
			t_sample mul_845 = (sample_segments_848 * expr_863);
			t_sample mul_872 = ((mul_845 + mul_821) * ((t_sample)0.3));
			t_sample mul_871 = ((mul_845 + mul_821) * ((t_sample)0.4));
			t_sample plusequals_786 = __m_pluseq_53.post(((int)1), tap_666, 0);
			t_sample noise_781 = noise();
			t_sample abs_780 = fabs(noise_781);
			t_sample sub_772 = (clamp_874 - ((int)50));
			t_sample mul_779 = (abs_780 * sub_772);
			t_sample sah_782 = __m_sah_54(mul_779, tap_666, ((t_sample)0.5));
			t_sample add_769 = (sah_782 + ((int)50));
			t_sample mod_778 = safemod(plusequals_786, add_769);
			t_sample div_775 = safediv(mod_778, add_769);
			t_sample expr_791 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_775))));
			t_sample noise_789 = noise();
			t_sample abs_788 = fabs(noise_789);
			t_sample mul_787 = (abs_788 * mul_989);
			t_sample sah_790 = __m_sah_55(mul_787, tap_666, ((t_sample)0.5));
			t_sample add_784 = (sah_790 + mod_778);
			t_sample mod_783 = safemod(add_784, mul_989);
			t_sample switch_770 = (gte_646 ? mod_783 : ((int)-1));
			int index_trunc_56 = fixnan(floor(switch_770));
			bool index_ignore_57 = ((index_trunc_56 >= segments_dim) || (index_trunc_56 < 0));
			// samples segments channel 1;
			t_sample sample_segments_776 = (index_ignore_57 ? 0 : m_segments_34.read(index_trunc_56, 0));
			t_sample index_segments_777 = switch_770;
			t_sample mul_773 = (sample_segments_776 * expr_791);
			t_sample plusequals_810 = __m_pluseq_58.post(((int)1), tap_668, 0);
			t_sample noise_805 = noise();
			t_sample abs_804 = fabs(noise_805);
			t_sample sub_796 = (clamp_874 - ((int)50));
			t_sample mul_803 = (abs_804 * sub_796);
			t_sample sah_806 = __m_sah_59(mul_803, tap_668, ((t_sample)0.5));
			t_sample add_793 = (sah_806 + ((int)50));
			t_sample mod_802 = safemod(plusequals_810, add_793);
			t_sample div_799 = safediv(mod_802, add_793);
			t_sample expr_815 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_799))));
			t_sample noise_813 = noise();
			t_sample abs_812 = fabs(noise_813);
			t_sample mul_811 = (abs_812 * mul_989);
			t_sample sah_814 = __m_sah_60(mul_811, tap_668, ((t_sample)0.5));
			t_sample add_808 = (sah_814 + mod_802);
			t_sample mod_807 = safemod(add_808, mul_989);
			t_sample switch_794 = (gte_647 ? mod_807 : ((int)-1));
			int index_trunc_61 = fixnan(floor(switch_794));
			bool index_ignore_62 = ((index_trunc_61 >= segments_dim) || (index_trunc_61 < 0));
			// samples segments channel 1;
			t_sample sample_segments_800 = (index_ignore_62 ? 0 : m_segments_34.read(index_trunc_61, 0));
			t_sample index_segments_801 = switch_794;
			t_sample mul_797 = (sample_segments_800 * expr_815);
			t_sample mul_870 = ((mul_797 + mul_773) * ((t_sample)0.4));
			t_sample mul_869 = ((mul_797 + mul_773) * ((t_sample)0.3));
			t_sample plusequals_690 = __m_pluseq_63.post(((int)1), tap_658, 0);
			t_sample noise_685 = noise();
			t_sample abs_684 = fabs(noise_685);
			t_sample sub_676 = (clamp_874 - ((int)50));
			t_sample mul_683 = (abs_684 * sub_676);
			t_sample sah_686 = __m_sah_64(mul_683, tap_658, ((t_sample)0.5));
			t_sample add_673 = (sah_686 + ((int)50));
			t_sample mod_682 = safemod(plusequals_690, add_673);
			t_sample div_679 = safediv(mod_682, add_673);
			t_sample expr_695 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_679))));
			t_sample noise_693 = noise();
			t_sample abs_692 = fabs(noise_693);
			t_sample mul_691 = (abs_692 * mul_989);
			t_sample sah_694 = __m_sah_65(mul_691, tap_658, ((t_sample)0.5));
			t_sample add_688 = (sah_694 + mod_682);
			t_sample mod_687 = safemod(add_688, mul_989);
			t_sample switch_674 = (gte_642 ? mod_687 : ((int)-1));
			int index_trunc_66 = fixnan(floor(switch_674));
			bool index_ignore_67 = ((index_trunc_66 >= segments_dim) || (index_trunc_66 < 0));
			// samples segments channel 1;
			t_sample sample_segments_680 = (index_ignore_67 ? 0 : m_segments_34.read(index_trunc_66, 0));
			t_sample index_segments_681 = switch_674;
			t_sample mul_677 = (sample_segments_680 * expr_695);
			t_sample plusequals_714 = __m_pluseq_68.post(((int)1), tap_660, 0);
			t_sample noise_709 = noise();
			t_sample abs_708 = fabs(noise_709);
			t_sample sub_700 = (clamp_874 - ((int)50));
			t_sample mul_707 = (abs_708 * sub_700);
			t_sample sah_710 = __m_sah_69(mul_707, tap_660, ((t_sample)0.5));
			t_sample add_697 = (sah_710 + ((int)50));
			t_sample mod_706 = safemod(plusequals_714, add_697);
			t_sample div_703 = safediv(mod_706, add_697);
			t_sample expr_719 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_703))));
			t_sample noise_717 = noise();
			t_sample abs_716 = fabs(noise_717);
			t_sample mul_715 = (abs_716 * mul_989);
			t_sample sah_718 = __m_sah_70(mul_715, tap_660, ((t_sample)0.5));
			t_sample add_712 = (sah_718 + mod_706);
			t_sample mod_711 = safemod(add_712, mul_989);
			t_sample switch_698 = (gte_643 ? mod_711 : ((int)-1));
			int index_trunc_71 = fixnan(floor(switch_698));
			bool index_ignore_72 = ((index_trunc_71 >= segments_dim) || (index_trunc_71 < 0));
			// samples segments channel 1;
			t_sample sample_segments_704 = (index_ignore_72 ? 0 : m_segments_34.read(index_trunc_71, 0));
			t_sample index_segments_705 = switch_698;
			t_sample mul_701 = (sample_segments_704 * expr_719);
			t_sample mul_866 = ((mul_701 + mul_677) * ((t_sample)0.5));
			t_sample mul_865 = ((mul_701 + mul_677) * ((t_sample)0.2));
			t_sample plusequals_738 = __m_pluseq_73.post(((int)1), tap_662, 0);
			t_sample noise_733 = noise();
			t_sample abs_732 = fabs(noise_733);
			t_sample sub_724 = (clamp_874 - ((int)50));
			t_sample mul_731 = (abs_732 * sub_724);
			t_sample sah_734 = __m_sah_74(mul_731, tap_662, ((t_sample)0.5));
			t_sample add_721 = (sah_734 + ((int)50));
			t_sample mod_730 = safemod(plusequals_738, add_721);
			t_sample div_727 = safediv(mod_730, add_721);
			t_sample expr_743 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_727))));
			t_sample noise_741 = noise();
			t_sample abs_740 = fabs(noise_741);
			t_sample mul_739 = (abs_740 * mul_989);
			t_sample sah_742 = __m_sah_75(mul_739, tap_662, ((t_sample)0.5));
			t_sample add_736 = (sah_742 + mod_730);
			t_sample mod_735 = safemod(add_736, mul_989);
			t_sample switch_722 = (gte_644 ? mod_735 : ((int)-1));
			int index_trunc_76 = fixnan(floor(switch_722));
			bool index_ignore_77 = ((index_trunc_76 >= segments_dim) || (index_trunc_76 < 0));
			// samples segments channel 1;
			t_sample sample_segments_728 = (index_ignore_77 ? 0 : m_segments_34.read(index_trunc_76, 0));
			t_sample index_segments_729 = switch_722;
			t_sample mul_725 = (sample_segments_728 * expr_743);
			t_sample plusequals_762 = __m_pluseq_78.post(((int)1), tap_664, 0);
			t_sample noise_757 = noise();
			t_sample abs_756 = fabs(noise_757);
			t_sample sub_748 = (clamp_874 - ((int)50));
			t_sample mul_755 = (abs_756 * sub_748);
			t_sample sah_758 = __m_sah_79(mul_755, tap_664, ((t_sample)0.5));
			t_sample add_745 = (sah_758 + ((int)50));
			t_sample mod_754 = safemod(plusequals_762, add_745);
			t_sample div_751 = safediv(mod_754, add_745);
			t_sample expr_767 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_751))));
			t_sample noise_765 = noise();
			t_sample abs_764 = fabs(noise_765);
			t_sample mul_763 = (abs_764 * mul_989);
			t_sample sah_766 = __m_sah_80(mul_763, tap_664, ((t_sample)0.5));
			t_sample add_760 = (sah_766 + mod_754);
			t_sample mod_759 = safemod(add_760, mul_989);
			t_sample switch_746 = (gte_645 ? mod_759 : ((int)-1));
			int index_trunc_81 = fixnan(floor(switch_746));
			bool index_ignore_82 = ((index_trunc_81 >= segments_dim) || (index_trunc_81 < 0));
			// samples segments channel 1;
			t_sample sample_segments_752 = (index_ignore_82 ? 0 : m_segments_34.read(index_trunc_81, 0));
			t_sample index_segments_753 = switch_746;
			t_sample mul_749 = (sample_segments_752 * expr_767);
			t_sample mul_868 = ((mul_749 + mul_725) * ((t_sample)0.2));
			t_sample mul_867 = ((mul_749 + mul_725) * ((t_sample)0.5));
			int gt_997 = (clamp_1000 > m_knob3_thresh_29);
			int change_996 = __m_change_83(gt_997);
			int eq_995 = (change_996 == ((int)1));
			t_sample add_613 = (m_history_5 + ((int)1));
			int gt_612 = (m_history_5 > mstosamps_615);
			int mul_611 = (eq_995 * gt_612);
			int and_609 = (gt_612 && eq_995);
			t_sample switch_610 = (and_609 ? ((int)0) : add_613);
			t_sample history_614_next_617 = fixdenorm(switch_610);
			int plusequals_978 = __m_pluseq_84.post(((int)1), mul_611, 0);
			t_sample noise_973 = noise();
			t_sample abs_972 = fabs(noise_973);
			t_sample sub_964 = (clamp_874 - ((int)50));
			t_sample mul_971 = (abs_972 * sub_964);
			t_sample sah_974 = __m_sah_85(mul_971, mul_611, ((t_sample)0.5));
			t_sample add_961 = (sah_974 + ((int)50));
			t_sample mod_970 = safemod(plusequals_978, add_961);
			t_sample div_967 = safediv(mod_970, add_961);
			t_sample expr_983 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_967))));
			t_sample noise_981 = noise();
			t_sample abs_980 = fabs(noise_981);
			t_sample mul_979 = (abs_980 * mul_989);
			t_sample sah_982 = __m_sah_86(mul_979, mul_611, ((t_sample)0.5));
			t_sample add_976 = (sah_982 + mod_970);
			t_sample mod_975 = safemod(add_976, mul_989);
			t_sample switch_962 = (gte_653 ? mod_975 : ((int)-1));
			int index_trunc_87 = fixnan(floor(switch_962));
			bool index_ignore_88 = ((index_trunc_87 >= segments_dim) || (index_trunc_87 < 0));
			// samples segments channel 1;
			t_sample sample_segments_968 = (index_ignore_88 ? 0 : m_segments_34.read(index_trunc_87, 0));
			t_sample index_segments_969 = switch_962;
			t_sample mul_965 = (sample_segments_968 * expr_983);
			int gt_959 = (clamp_1000 > mul_950);
			int change_958 = __m_change_89(gt_959);
			int eq_957 = (change_958 == ((int)1));
			t_sample add_602 = (m_history_4 + ((int)1));
			int gt_601 = (m_history_4 > mstosamps_604);
			int mul_600 = (eq_957 * gt_601);
			int and_598 = (gt_601 && eq_957);
			t_sample switch_599 = (and_598 ? ((int)0) : add_602);
			t_sample history_603_next_606 = fixdenorm(switch_599);
			int plusequals_941 = __m_pluseq_90.post(((int)1), mul_600, 0);
			t_sample noise_936 = noise();
			t_sample abs_935 = fabs(noise_936);
			t_sample sub_927 = (clamp_874 - ((int)50));
			t_sample mul_934 = (abs_935 * sub_927);
			t_sample sah_937 = __m_sah_91(mul_934, mul_600, ((t_sample)0.5));
			t_sample add_924 = (sah_937 + ((int)50));
			t_sample mod_933 = safemod(plusequals_941, add_924);
			t_sample div_930 = safediv(mod_933, add_924);
			t_sample expr_946 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_930))));
			t_sample noise_944 = noise();
			t_sample abs_943 = fabs(noise_944);
			t_sample mul_942 = (abs_943 * mul_989);
			t_sample sah_945 = __m_sah_92(mul_942, mul_600, ((t_sample)0.5));
			t_sample add_939 = (sah_945 + mod_933);
			t_sample mod_938 = safemod(add_939, mul_989);
			t_sample switch_925 = (gte_652 ? mod_938 : ((int)-1));
			int index_trunc_93 = fixnan(floor(switch_925));
			bool index_ignore_94 = ((index_trunc_93 >= segments_dim) || (index_trunc_93 < 0));
			// samples segments channel 1;
			t_sample sample_segments_931 = (index_ignore_94 ? 0 : m_segments_34.read(index_trunc_93, 0));
			t_sample index_segments_932 = switch_925;
			t_sample mul_928 = (sample_segments_931 * expr_946);
			int gt_956 = (clamp_1000 > mul_949);
			int change_955 = __m_change_95(gt_956);
			int eq_954 = (change_955 == ((int)1));
			t_sample add_591 = (m_history_3 + ((int)1));
			int gt_590 = (m_history_3 > mstosamps_593);
			int mul_589 = (eq_954 * gt_590);
			int and_587 = (gt_590 && eq_954);
			t_sample switch_588 = (and_587 ? ((int)0) : add_591);
			t_sample history_592_next_595 = fixdenorm(switch_588);
			int plusequals_917 = __m_pluseq_96.post(((int)1), mul_589, 0);
			t_sample noise_912 = noise();
			t_sample abs_911 = fabs(noise_912);
			t_sample sub_903 = (clamp_874 - ((int)50));
			t_sample mul_910 = (abs_911 * sub_903);
			t_sample sah_913 = __m_sah_97(mul_910, mul_589, ((t_sample)0.5));
			t_sample add_900 = (sah_913 + ((int)50));
			t_sample mod_909 = safemod(plusequals_917, add_900);
			t_sample div_906 = safediv(mod_909, add_900);
			t_sample expr_922 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_906))));
			t_sample noise_920 = noise();
			t_sample abs_919 = fabs(noise_920);
			t_sample mul_918 = (abs_919 * mul_989);
			t_sample sah_921 = __m_sah_98(mul_918, mul_589, ((t_sample)0.5));
			t_sample add_915 = (sah_921 + mod_909);
			t_sample mod_914 = safemod(add_915, mul_989);
			t_sample switch_901 = (gte_651 ? mod_914 : ((int)-1));
			int index_trunc_99 = fixnan(floor(switch_901));
			bool index_ignore_100 = ((index_trunc_99 >= segments_dim) || (index_trunc_99 < 0));
			// samples segments channel 1;
			t_sample sample_segments_907 = (index_ignore_100 ? 0 : m_segments_34.read(index_trunc_99, 0));
			t_sample index_segments_908 = switch_901;
			t_sample mul_904 = (sample_segments_907 * expr_922);
			int gt_953 = (clamp_1000 > mul_948);
			int change_952 = __m_change_101(gt_953);
			int eq_951 = (change_952 == ((int)1));
			t_sample add_580 = (m_history_2 + ((int)1));
			int gt_579 = (m_history_2 > mstosamps_582);
			int mul_578 = (eq_951 * gt_579);
			int and_576 = (gt_579 && eq_951);
			t_sample switch_577 = (and_576 ? ((int)0) : add_580);
			t_sample history_581_next_584 = fixdenorm(switch_577);
			int plusequals_893 = __m_pluseq_102.post(((int)1), mul_578, 0);
			t_sample noise_888 = noise();
			t_sample abs_887 = fabs(noise_888);
			t_sample sub_879 = (clamp_874 - ((int)50));
			t_sample mul_886 = (abs_887 * sub_879);
			t_sample sah_889 = __m_sah_103(mul_886, mul_578, ((t_sample)0.5));
			t_sample add_876 = (sah_889 + ((int)50));
			t_sample mod_885 = safemod(plusequals_893, add_876);
			t_sample div_882 = safediv(mod_885, add_876);
			t_sample expr_898 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_882))));
			t_sample noise_896 = noise();
			t_sample abs_895 = fabs(noise_896);
			t_sample mul_894 = (abs_895 * mul_989);
			t_sample sah_897 = __m_sah_104(mul_894, mul_578, ((t_sample)0.5));
			t_sample add_891 = (sah_897 + mod_885);
			t_sample mod_890 = safemod(add_891, mul_989);
			t_sample switch_877 = (gte_650 ? mod_890 : ((int)-1));
			int index_trunc_105 = fixnan(floor(switch_877));
			bool index_ignore_106 = ((index_trunc_105 >= segments_dim) || (index_trunc_105 < 0));
			// samples segments channel 1;
			t_sample sample_segments_883 = (index_ignore_106 ? 0 : m_segments_34.read(index_trunc_105, 0));
			t_sample index_segments_884 = switch_877;
			t_sample mul_880 = (sample_segments_883 * expr_898);
			t_sample mul_960 = ((((mul_965 + mul_880) + mul_904) + mul_928) * ((t_sample)0.7));
			t_sample mul_656 = (((((mul_868 + mul_866) + mul_870) + mul_872) + mul_960) * scale_1114);
			t_sample dcblock_621 = __m_dcblock_107(mul_656);
			t_sample mul_624 = (sqrt_622 * dcblock_621);
			t_sample out1 = ((mul_624 + mul_625) + gate_1013);
			t_sample mul_655 = (((((mul_867 + mul_865) + mul_869) + mul_871) + mul_960) * scale_1114);
			t_sample dcblock_620 = __m_dcblock_108(mul_655);
			t_sample mul_623 = (sqrt_622 * dcblock_620);
			t_sample out2 = ((mul_623 + mul_625) + gate_1013);
			t_sample history_990_next_1056 = fixdenorm(eq_991);
			m_history_26 = history_1009_next_1011;
			m_history_25 = history_631_next_633;
			m_history_23 = history_627_next_635;
			m_history_24 = history_629_next_634;
			m_history_22 = history_631_next_1019;
			m_history_20 = history_627_next_1021;
			m_history_21 = history_629_next_1020;
			m_history_19 = history_631_next_1038;
			m_history_17 = history_627_next_1036;
			m_history_18 = history_629_next_1030;
			m_delay_16.write(mul_600);
			m_delay_15.write(mul_611);
			m_delay_14.write(mul_578);
			m_delay_13.write(mul_589);
			m_delay_12.write(tap_666);
			m_delay_11.write(tap_668);
			m_delay_10.write(tap_670);
			m_delay_9.write(tap_672);
			m_history_8 = history_631_next_1049;
			m_history_6 = history_627_next_1051;
			m_history_7 = history_629_next_1043;
			m_history_5 = history_614_next_617;
			m_history_4 = history_603_next_606;
			m_history_3 = history_592_next_595;
			m_history_2 = history_581_next_584;
			m_history_1 = history_990_next_1056;
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
	inline void set_sw1(t_param _value) {
		m_sw_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_thresh(t_param _value) {
		m_knob3_thresh_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_density(t_param _value) {
		m_knob6_density_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob1_wetdry_32; break;
		case 1: *value = self->m_knob3_thresh_29; break;
		case 2: *value = self->m_knob4_buflen_28; break;
		case 3: *value = self->m_knob5_glitchlen_33; break;
		case 4: *value = self->m_knob6_density_31; break;
		
		case 6: *value = self->m_sw_27; break;
		case 7: *value = self->m_sw_30; break;
		
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
	// initialize parameter 1 ("m_knob3_thresh_29")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_thresh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_thresh_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_buflen_28")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_buflen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_buflen_28;
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
	// initialize parameter 7 ("m_sw_30")
	pi = self->__commonstate.params + 7;
	pi->name = "sw2";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Glitch::
