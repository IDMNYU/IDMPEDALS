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
	t_sample m_knob3_thresh_27;
	t_sample m_history_4;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_3;
	t_sample m_history_1;
	t_sample m_history_2;
	t_sample __m_slide_36;
	t_sample samplerate;
	t_sample m_knob6_density_28;
	t_sample m_history_16;
	t_sample m_history_18;
	t_sample m_knob5_glitchlen_24;
	t_sample m_sw_25;
	t_sample m_knob4_buflen_26;
	t_sample m_history_17;
	t_sample m_knob1_wetdry_23;
	t_sample m_history_21;
	t_sample m_history_22;
	t_sample m_history_19;
	t_sample m_sw_29;
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
		m_delay_5.reset("m_delay_5", ((int)2));
		m_delay_6.reset("m_delay_6", ((int)9));
		m_delay_7.reset("m_delay_7", ((int)3));
		m_delay_8.reset("m_delay_8", ((int)5));
		m_delay_9.reset("m_delay_9", ((int)5));
		m_delay_10.reset("m_delay_10", ((int)7));
		m_delay_11.reset("m_delay_11", ((int)3));
		m_delay_12.reset("m_delay_12", ((int)4));
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
		m_knob1_wetdry_23 = ((int)0);
		m_knob5_glitchlen_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_knob4_buflen_26 = ((int)0);
		m_knob3_thresh_27 = ((int)0);
		m_knob6_density_28 = ((int)0);
		m_sw_29 = ((int)0);
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
		t_sample mstosamps_1015 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_1013 = (((int)100) * (samplerate * 0.001));
		t_sample iup_37 = (1 / maximum(1, abs(mstosamps_1015)));
		t_sample idown_38 = (1 / maximum(1, abs(mstosamps_1013)));
		t_sample mul_961 = (m_knob3_thresh_27 * ((t_sample)0.95));
		t_sample mul_960 = (m_knob3_thresh_27 * ((t_sample)1.03));
		t_sample mul_959 = (m_knob3_thresh_27 * ((t_sample)0.98));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample mix_1164 = (m_history_22 + (((t_sample)0.0019634941468452) * (m_knob4_buflen_26 - m_history_22)));
			t_sample mix_641 = mix_1164;
			t_sample mix_1165 = (m_history_21 + (((t_sample)0.0019634941468452) * (mix_641 - m_history_21)));
			t_sample mix_639 = mix_1165;
			t_sample mix_1166 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_639 - m_history_20)));
			t_sample mix_637 = mix_1166;
			t_sample gen_999 = mix_637;
			t_sample history_642_next_644 = fixdenorm(mix_641);
			t_sample history_640_next_645 = fixdenorm(mix_639);
			t_sample history_638_next_646 = fixdenorm(mix_637);
			t_sample expr_1027 = (((int)1) - sqrt((((int)1) - gen_999)));
			t_sample sah_1021 = __m_sah_31(m_history_19, m_sw_29, ((int)0));
			t_sample gen_1023 = sah_1021;
			t_sample rsub_1019 = (((int)1) - sah_1021);
			t_sample history_1020_next_1022 = fixdenorm(rsub_1019);
			t_sample out3 = gen_1023;
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample add_1026 = (gen_1023 + ((int)1));
			t_sample choice_32 = int(add_1026);
			t_sample gate_1024 = (((choice_32 >= 1) && (choice_32 < 2)) ? in1 : 0);
			t_sample gate_1025 = ((choice_32 >= 2) ? in1 : 0);
			t_sample mix_1167 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_knob1_wetdry_23 - m_history_18)));
			t_sample mix_1035 = mix_1167;
			t_sample mix_1168 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_1035 - m_history_17)));
			t_sample mix_1036 = mix_1168;
			t_sample mix_1169 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_1036 - m_history_16)));
			t_sample mix_1034 = mix_1169;
			t_sample gen_647 = mix_1034;
			t_sample history_642_next_1037 = fixdenorm(mix_1035);
			t_sample history_640_next_1032 = fixdenorm(mix_1036);
			t_sample history_638_next_1029 = fixdenorm(mix_1034);
			t_sample sqrt_633 = sqrt(gen_647);
			t_sample rsub_649 = (((int)1) - gen_647);
			t_sample sqrt_648 = sqrt(rsub_649);
			t_sample mul_636 = (sqrt_648 * gate_1025);
			t_sample plusequals_1017 = __m_pluseq_33.post(((int)1), m_history_1, 0);
			t_sample switch_997 = (m_sw_25 ? ((int)-1) : plusequals_1017);
			int index_trunc_34 = fixnan(floor(switch_997));
			bool index_ignore_35 = ((index_trunc_34 >= segments_dim) || (index_trunc_34 < 0));
			if ((!index_ignore_35)) {
				m_segments_30.write(gate_1025, index_trunc_34, 0);
				
			};
			t_sample mul_1000 = (expr_1027 * ((int)480000));
			int gte_1003 = (plusequals_1017 >= mul_1000);
			int eq_1002 = (gte_1003 == ((int)1));
			t_sample abs_1018 = fabs(gate_1025);
			t_sample mul_651 = (abs_1018 * ((int)30));
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_651 > __m_slide_36) ? iup_37 : idown_38) * (mul_651 - __m_slide_36))));
			t_sample slide_1016 = __m_slide_36;
			t_sample clamp_1011 = ((slide_1016 <= ((int)0)) ? ((int)0) : ((slide_1016 >= ((int)1)) ? ((int)1) : slide_1016));
			t_sample out4 = clamp_1011;
			t_sample mix_1170 = (m_history_15 + (((t_sample)0.0019634941468452) * (m_knob6_density_28 - m_history_15)));
			t_sample mix_1043 = mix_1170;
			t_sample mix_1171 = (m_history_14 + (((t_sample)0.0019634941468452) * (mix_1043 - m_history_14)));
			t_sample mix_1044 = mix_1171;
			t_sample mix_1172 = (m_history_13 + (((t_sample)0.0019634941468452) * (mix_1044 - m_history_13)));
			t_sample mix_1049 = mix_1172;
			t_sample gen_884 = mix_1049;
			t_sample history_642_next_1047 = fixdenorm(mix_1043);
			t_sample history_640_next_1042 = fixdenorm(mix_1044);
			t_sample history_638_next_1041 = fixdenorm(mix_1049);
			t_sample sub_1176 = (gen_884 - ((int)0));
			t_sample scale_1173 = ((safepow((sub_1176 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_681 = m_delay_12.read_step(((int)8));
			t_sample tap_683 = m_delay_11.read_step(((int)8));
			t_sample tap_677 = m_delay_10.read_step(((int)8));
			t_sample tap_679 = m_delay_9.read_step(((int)8));
			t_sample tap_669 = m_delay_8.read_step(((int)8));
			t_sample tap_671 = m_delay_7.read_step(((int)8));
			t_sample tap_673 = m_delay_6.read_step(((int)9));
			t_sample tap_675 = m_delay_5.read_step(((int)8));
			t_sample mul_665 = (gen_884 * ((int)12));
			int gte_663 = (mul_665 >= ((int)1));
			int gte_662 = (mul_665 >= ((int)2));
			int gte_661 = (mul_665 >= ((int)3));
			int gte_664 = (mul_665 >= ((int)0));
			int gte_659 = (mul_665 >= ((int)5));
			int gte_660 = (mul_665 >= ((int)4));
			int gte_657 = (mul_665 >= ((int)7));
			int gte_658 = (mul_665 >= ((int)6));
			int gte_653 = (mul_665 >= ((int)11));
			int gte_654 = (mul_665 >= ((int)10));
			int gte_655 = (mul_665 >= ((int)9));
			int gte_656 = (mul_665 >= ((int)8));
			t_sample mix_1177 = (m_history_4 + (((t_sample)0.0019634941468452) * (m_knob5_glitchlen_24 - m_history_4)));
			t_sample mix_1058 = mix_1177;
			t_sample mix_1178 = (m_history_3 + (((t_sample)0.0019634941468452) * (mix_1058 - m_history_3)));
			t_sample mix_1055 = mix_1178;
			t_sample mix_1179 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_1055 - m_history_2)));
			t_sample mix_1063 = mix_1179;
			t_sample gen_886 = mix_1063;
			t_sample history_642_next_1062 = fixdenorm(mix_1058);
			t_sample history_640_next_1054 = fixdenorm(mix_1055);
			t_sample history_638_next_1061 = fixdenorm(mix_1063);
			t_sample mul_630 = (mul_1000 * gen_886);
			t_sample clamp_885 = ((mul_630 <= ((int)50)) ? ((int)50) : ((mul_630 >= ((int)480000)) ? ((int)480000) : mul_630));
			t_sample plusequals_845 = __m_pluseq_39.post(((int)1), tap_681, 0);
			t_sample noise_840 = noise();
			t_sample abs_839 = fabs(noise_840);
			t_sample sub_831 = (clamp_885 - ((int)50));
			t_sample mul_838 = (abs_839 * sub_831);
			t_sample sah_841 = __m_sah_40(mul_838, tap_681, ((t_sample)0.5));
			t_sample add_828 = (sah_841 + ((int)50));
			t_sample mod_837 = safemod(plusequals_845, add_828);
			t_sample div_834 = safediv(mod_837, add_828);
			t_sample expr_850 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_834))));
			t_sample noise_848 = noise();
			t_sample abs_847 = fabs(noise_848);
			t_sample mul_846 = (abs_847 * mul_1000);
			t_sample sah_849 = __m_sah_41(mul_846, tap_681, ((t_sample)0.5));
			t_sample add_843 = (sah_849 + mod_837);
			t_sample mod_842 = safemod(add_843, mul_1000);
			t_sample switch_829 = (gte_659 ? mod_842 : ((int)-1));
			int index_trunc_42 = fixnan(floor(switch_829));
			bool index_ignore_43 = ((index_trunc_42 >= segments_dim) || (index_trunc_42 < 0));
			// samples segments channel 1;
			t_sample sample_segments_835 = (index_ignore_43 ? 0 : m_segments_30.read(index_trunc_42, 0));
			t_sample index_segments_836 = switch_829;
			t_sample mul_832 = (sample_segments_835 * expr_850);
			t_sample plusequals_869 = __m_pluseq_44.post(((int)1), tap_683, 0);
			t_sample noise_864 = noise();
			t_sample abs_863 = fabs(noise_864);
			t_sample sub_855 = (clamp_885 - ((int)50));
			t_sample mul_862 = (abs_863 * sub_855);
			t_sample sah_865 = __m_sah_45(mul_862, tap_683, ((t_sample)0.5));
			t_sample add_852 = (sah_865 + ((int)50));
			t_sample mod_861 = safemod(plusequals_869, add_852);
			t_sample div_858 = safediv(mod_861, add_852);
			t_sample expr_874 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_858))));
			t_sample noise_872 = noise();
			t_sample abs_871 = fabs(noise_872);
			t_sample mul_870 = (abs_871 * mul_1000);
			t_sample sah_873 = __m_sah_46(mul_870, tap_683, ((t_sample)0.5));
			t_sample add_867 = (sah_873 + mod_861);
			t_sample mod_866 = safemod(add_867, mul_1000);
			t_sample switch_853 = (gte_660 ? mod_866 : ((int)-1));
			int index_trunc_47 = fixnan(floor(switch_853));
			bool index_ignore_48 = ((index_trunc_47 >= segments_dim) || (index_trunc_47 < 0));
			// samples segments channel 1;
			t_sample sample_segments_859 = (index_ignore_48 ? 0 : m_segments_30.read(index_trunc_47, 0));
			t_sample index_segments_860 = switch_853;
			t_sample mul_856 = (sample_segments_859 * expr_874);
			t_sample mul_882 = ((mul_856 + mul_832) * ((t_sample)0.4));
			t_sample mul_883 = ((mul_856 + mul_832) * ((t_sample)0.3));
			t_sample plusequals_797 = __m_pluseq_49.post(((int)1), tap_677, 0);
			t_sample noise_792 = noise();
			t_sample abs_791 = fabs(noise_792);
			t_sample sub_783 = (clamp_885 - ((int)50));
			t_sample mul_790 = (abs_791 * sub_783);
			t_sample sah_793 = __m_sah_50(mul_790, tap_677, ((t_sample)0.5));
			t_sample add_780 = (sah_793 + ((int)50));
			t_sample mod_789 = safemod(plusequals_797, add_780);
			t_sample div_786 = safediv(mod_789, add_780);
			t_sample expr_802 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_786))));
			t_sample noise_800 = noise();
			t_sample abs_799 = fabs(noise_800);
			t_sample mul_798 = (abs_799 * mul_1000);
			t_sample sah_801 = __m_sah_51(mul_798, tap_677, ((t_sample)0.5));
			t_sample add_795 = (sah_801 + mod_789);
			t_sample mod_794 = safemod(add_795, mul_1000);
			t_sample switch_781 = (gte_657 ? mod_794 : ((int)-1));
			int index_trunc_52 = fixnan(floor(switch_781));
			bool index_ignore_53 = ((index_trunc_52 >= segments_dim) || (index_trunc_52 < 0));
			// samples segments channel 1;
			t_sample sample_segments_787 = (index_ignore_53 ? 0 : m_segments_30.read(index_trunc_52, 0));
			t_sample index_segments_788 = switch_781;
			t_sample mul_784 = (sample_segments_787 * expr_802);
			t_sample plusequals_821 = __m_pluseq_54.post(((int)1), tap_679, 0);
			t_sample noise_816 = noise();
			t_sample abs_815 = fabs(noise_816);
			t_sample sub_807 = (clamp_885 - ((int)50));
			t_sample mul_814 = (abs_815 * sub_807);
			t_sample sah_817 = __m_sah_55(mul_814, tap_679, ((t_sample)0.5));
			t_sample add_804 = (sah_817 + ((int)50));
			t_sample mod_813 = safemod(plusequals_821, add_804);
			t_sample div_810 = safediv(mod_813, add_804);
			t_sample expr_826 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_810))));
			t_sample noise_824 = noise();
			t_sample abs_823 = fabs(noise_824);
			t_sample mul_822 = (abs_823 * mul_1000);
			t_sample sah_825 = __m_sah_56(mul_822, tap_679, ((t_sample)0.5));
			t_sample add_819 = (sah_825 + mod_813);
			t_sample mod_818 = safemod(add_819, mul_1000);
			t_sample switch_805 = (gte_658 ? mod_818 : ((int)-1));
			int index_trunc_57 = fixnan(floor(switch_805));
			bool index_ignore_58 = ((index_trunc_57 >= segments_dim) || (index_trunc_57 < 0));
			// samples segments channel 1;
			t_sample sample_segments_811 = (index_ignore_58 ? 0 : m_segments_30.read(index_trunc_57, 0));
			t_sample index_segments_812 = switch_805;
			t_sample mul_808 = (sample_segments_811 * expr_826);
			t_sample mul_880 = ((mul_808 + mul_784) * ((t_sample)0.3));
			t_sample mul_881 = ((mul_808 + mul_784) * ((t_sample)0.4));
			t_sample plusequals_701 = __m_pluseq_59.post(((int)1), tap_669, 0);
			t_sample noise_696 = noise();
			t_sample abs_695 = fabs(noise_696);
			t_sample sub_687 = (clamp_885 - ((int)50));
			t_sample mul_694 = (abs_695 * sub_687);
			t_sample sah_697 = __m_sah_60(mul_694, tap_669, ((t_sample)0.5));
			t_sample add_684 = (sah_697 + ((int)50));
			t_sample mod_693 = safemod(plusequals_701, add_684);
			t_sample div_690 = safediv(mod_693, add_684);
			t_sample expr_706 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_690))));
			t_sample noise_704 = noise();
			t_sample abs_703 = fabs(noise_704);
			t_sample mul_702 = (abs_703 * mul_1000);
			t_sample sah_705 = __m_sah_61(mul_702, tap_669, ((t_sample)0.5));
			t_sample add_699 = (sah_705 + mod_693);
			t_sample mod_698 = safemod(add_699, mul_1000);
			t_sample switch_685 = (gte_653 ? mod_698 : ((int)-1));
			int index_trunc_62 = fixnan(floor(switch_685));
			bool index_ignore_63 = ((index_trunc_62 >= segments_dim) || (index_trunc_62 < 0));
			// samples segments channel 1;
			t_sample sample_segments_691 = (index_ignore_63 ? 0 : m_segments_30.read(index_trunc_62, 0));
			t_sample index_segments_692 = switch_685;
			t_sample mul_688 = (sample_segments_691 * expr_706);
			t_sample plusequals_725 = __m_pluseq_64.post(((int)1), tap_671, 0);
			t_sample noise_720 = noise();
			t_sample abs_719 = fabs(noise_720);
			t_sample sub_711 = (clamp_885 - ((int)50));
			t_sample mul_718 = (abs_719 * sub_711);
			t_sample sah_721 = __m_sah_65(mul_718, tap_671, ((t_sample)0.5));
			t_sample add_708 = (sah_721 + ((int)50));
			t_sample mod_717 = safemod(plusequals_725, add_708);
			t_sample div_714 = safediv(mod_717, add_708);
			t_sample expr_730 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_714))));
			t_sample noise_728 = noise();
			t_sample abs_727 = fabs(noise_728);
			t_sample mul_726 = (abs_727 * mul_1000);
			t_sample sah_729 = __m_sah_66(mul_726, tap_671, ((t_sample)0.5));
			t_sample add_723 = (sah_729 + mod_717);
			t_sample mod_722 = safemod(add_723, mul_1000);
			t_sample switch_709 = (gte_654 ? mod_722 : ((int)-1));
			int index_trunc_67 = fixnan(floor(switch_709));
			bool index_ignore_68 = ((index_trunc_67 >= segments_dim) || (index_trunc_67 < 0));
			// samples segments channel 1;
			t_sample sample_segments_715 = (index_ignore_68 ? 0 : m_segments_30.read(index_trunc_67, 0));
			t_sample index_segments_716 = switch_709;
			t_sample mul_712 = (sample_segments_715 * expr_730);
			t_sample mul_876 = ((mul_712 + mul_688) * ((t_sample)0.2));
			t_sample mul_877 = ((mul_712 + mul_688) * ((t_sample)0.5));
			t_sample plusequals_749 = __m_pluseq_69.post(((int)1), tap_673, 0);
			t_sample noise_744 = noise();
			t_sample abs_743 = fabs(noise_744);
			t_sample sub_735 = (clamp_885 - ((int)50));
			t_sample mul_742 = (abs_743 * sub_735);
			t_sample sah_745 = __m_sah_70(mul_742, tap_673, ((t_sample)0.5));
			t_sample add_732 = (sah_745 + ((int)50));
			t_sample mod_741 = safemod(plusequals_749, add_732);
			t_sample div_738 = safediv(mod_741, add_732);
			t_sample expr_754 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_738))));
			t_sample noise_752 = noise();
			t_sample abs_751 = fabs(noise_752);
			t_sample mul_750 = (abs_751 * mul_1000);
			t_sample sah_753 = __m_sah_71(mul_750, tap_673, ((t_sample)0.5));
			t_sample add_747 = (sah_753 + mod_741);
			t_sample mod_746 = safemod(add_747, mul_1000);
			t_sample switch_733 = (gte_655 ? mod_746 : ((int)-1));
			int index_trunc_72 = fixnan(floor(switch_733));
			bool index_ignore_73 = ((index_trunc_72 >= segments_dim) || (index_trunc_72 < 0));
			// samples segments channel 1;
			t_sample sample_segments_739 = (index_ignore_73 ? 0 : m_segments_30.read(index_trunc_72, 0));
			t_sample index_segments_740 = switch_733;
			t_sample mul_736 = (sample_segments_739 * expr_754);
			t_sample plusequals_773 = __m_pluseq_74.post(((int)1), tap_675, 0);
			t_sample noise_768 = noise();
			t_sample abs_767 = fabs(noise_768);
			t_sample sub_759 = (clamp_885 - ((int)50));
			t_sample mul_766 = (abs_767 * sub_759);
			t_sample sah_769 = __m_sah_75(mul_766, tap_675, ((t_sample)0.5));
			t_sample add_756 = (sah_769 + ((int)50));
			t_sample mod_765 = safemod(plusequals_773, add_756);
			t_sample div_762 = safediv(mod_765, add_756);
			t_sample expr_778 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_762))));
			t_sample noise_776 = noise();
			t_sample abs_775 = fabs(noise_776);
			t_sample mul_774 = (abs_775 * mul_1000);
			t_sample sah_777 = __m_sah_76(mul_774, tap_675, ((t_sample)0.5));
			t_sample add_771 = (sah_777 + mod_765);
			t_sample mod_770 = safemod(add_771, mul_1000);
			t_sample switch_757 = (gte_656 ? mod_770 : ((int)-1));
			int index_trunc_77 = fixnan(floor(switch_757));
			bool index_ignore_78 = ((index_trunc_77 >= segments_dim) || (index_trunc_77 < 0));
			// samples segments channel 1;
			t_sample sample_segments_763 = (index_ignore_78 ? 0 : m_segments_30.read(index_trunc_77, 0));
			t_sample index_segments_764 = switch_757;
			t_sample mul_760 = (sample_segments_763 * expr_778);
			t_sample mul_878 = ((mul_760 + mul_736) * ((t_sample)0.5));
			t_sample mul_879 = ((mul_760 + mul_736) * ((t_sample)0.2));
			int gt_1008 = (clamp_1011 > m_knob3_thresh_27);
			int change_1007 = __m_change_79(gt_1008);
			int eq_1006 = (change_1007 == ((int)1));
			int plusequals_989 = __m_pluseq_80.post(((int)1), eq_1006, 0);
			t_sample noise_984 = noise();
			t_sample abs_983 = fabs(noise_984);
			t_sample sub_975 = (clamp_885 - ((int)50));
			t_sample mul_982 = (abs_983 * sub_975);
			t_sample sah_985 = __m_sah_81(mul_982, eq_1006, ((t_sample)0.5));
			t_sample add_972 = (sah_985 + ((int)50));
			t_sample mod_981 = safemod(plusequals_989, add_972);
			t_sample div_978 = safediv(mod_981, add_972);
			t_sample expr_994 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_978))));
			t_sample noise_992 = noise();
			t_sample abs_991 = fabs(noise_992);
			t_sample mul_990 = (abs_991 * mul_1000);
			t_sample sah_993 = __m_sah_82(mul_990, eq_1006, ((t_sample)0.5));
			t_sample add_987 = (sah_993 + mod_981);
			t_sample mod_986 = safemod(add_987, mul_1000);
			t_sample switch_973 = (gte_664 ? mod_986 : ((int)-1));
			int index_trunc_83 = fixnan(floor(switch_973));
			bool index_ignore_84 = ((index_trunc_83 >= segments_dim) || (index_trunc_83 < 0));
			// samples segments channel 1;
			t_sample sample_segments_979 = (index_ignore_84 ? 0 : m_segments_30.read(index_trunc_83, 0));
			t_sample index_segments_980 = switch_973;
			t_sample mul_976 = (sample_segments_979 * expr_994);
			int gt_970 = (clamp_1011 > mul_961);
			int change_969 = __m_change_85(gt_970);
			int eq_968 = (change_969 == ((int)1));
			int plusequals_952 = __m_pluseq_86.post(((int)1), eq_968, 0);
			t_sample noise_947 = noise();
			t_sample abs_946 = fabs(noise_947);
			t_sample sub_938 = (clamp_885 - ((int)50));
			t_sample mul_945 = (abs_946 * sub_938);
			t_sample sah_948 = __m_sah_87(mul_945, eq_968, ((t_sample)0.5));
			t_sample add_935 = (sah_948 + ((int)50));
			t_sample mod_944 = safemod(plusequals_952, add_935);
			t_sample div_941 = safediv(mod_944, add_935);
			t_sample expr_957 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_941))));
			t_sample noise_955 = noise();
			t_sample abs_954 = fabs(noise_955);
			t_sample mul_953 = (abs_954 * mul_1000);
			t_sample sah_956 = __m_sah_88(mul_953, eq_968, ((t_sample)0.5));
			t_sample add_950 = (sah_956 + mod_944);
			t_sample mod_949 = safemod(add_950, mul_1000);
			t_sample switch_936 = (gte_663 ? mod_949 : ((int)-1));
			int index_trunc_89 = fixnan(floor(switch_936));
			bool index_ignore_90 = ((index_trunc_89 >= segments_dim) || (index_trunc_89 < 0));
			// samples segments channel 1;
			t_sample sample_segments_942 = (index_ignore_90 ? 0 : m_segments_30.read(index_trunc_89, 0));
			t_sample index_segments_943 = switch_936;
			t_sample mul_939 = (sample_segments_942 * expr_957);
			int gt_967 = (clamp_1011 > mul_960);
			int change_966 = __m_change_91(gt_967);
			int eq_965 = (change_966 == ((int)1));
			int plusequals_928 = __m_pluseq_92.post(((int)1), eq_965, 0);
			t_sample noise_923 = noise();
			t_sample abs_922 = fabs(noise_923);
			t_sample sub_914 = (clamp_885 - ((int)50));
			t_sample mul_921 = (abs_922 * sub_914);
			t_sample sah_924 = __m_sah_93(mul_921, eq_965, ((t_sample)0.5));
			t_sample add_911 = (sah_924 + ((int)50));
			t_sample mod_920 = safemod(plusequals_928, add_911);
			t_sample div_917 = safediv(mod_920, add_911);
			t_sample expr_933 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_917))));
			t_sample noise_931 = noise();
			t_sample abs_930 = fabs(noise_931);
			t_sample mul_929 = (abs_930 * mul_1000);
			t_sample sah_932 = __m_sah_94(mul_929, eq_965, ((t_sample)0.5));
			t_sample add_926 = (sah_932 + mod_920);
			t_sample mod_925 = safemod(add_926, mul_1000);
			t_sample switch_912 = (gte_662 ? mod_925 : ((int)-1));
			int index_trunc_95 = fixnan(floor(switch_912));
			bool index_ignore_96 = ((index_trunc_95 >= segments_dim) || (index_trunc_95 < 0));
			// samples segments channel 1;
			t_sample sample_segments_918 = (index_ignore_96 ? 0 : m_segments_30.read(index_trunc_95, 0));
			t_sample index_segments_919 = switch_912;
			t_sample mul_915 = (sample_segments_918 * expr_933);
			int gt_964 = (clamp_1011 > mul_959);
			int change_963 = __m_change_97(gt_964);
			int eq_962 = (change_963 == ((int)1));
			int plusequals_904 = __m_pluseq_98.post(((int)1), eq_962, 0);
			t_sample noise_899 = noise();
			t_sample abs_898 = fabs(noise_899);
			t_sample sub_890 = (clamp_885 - ((int)50));
			t_sample mul_897 = (abs_898 * sub_890);
			t_sample sah_900 = __m_sah_99(mul_897, eq_962, ((t_sample)0.5));
			t_sample add_887 = (sah_900 + ((int)50));
			t_sample mod_896 = safemod(plusequals_904, add_887);
			t_sample div_893 = safediv(mod_896, add_887);
			t_sample expr_909 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_893))));
			t_sample noise_907 = noise();
			t_sample abs_906 = fabs(noise_907);
			t_sample mul_905 = (abs_906 * mul_1000);
			t_sample sah_908 = __m_sah_100(mul_905, eq_962, ((t_sample)0.5));
			t_sample add_902 = (sah_908 + mod_896);
			t_sample mod_901 = safemod(add_902, mul_1000);
			t_sample switch_888 = (gte_661 ? mod_901 : ((int)-1));
			int index_trunc_101 = fixnan(floor(switch_888));
			bool index_ignore_102 = ((index_trunc_101 >= segments_dim) || (index_trunc_101 < 0));
			// samples segments channel 1;
			t_sample sample_segments_894 = (index_ignore_102 ? 0 : m_segments_30.read(index_trunc_101, 0));
			t_sample index_segments_895 = switch_888;
			t_sample mul_891 = (sample_segments_894 * expr_909);
			t_sample mul_971 = ((((mul_976 + mul_891) + mul_915) + mul_939) * ((t_sample)0.7));
			t_sample mul_666 = (((((mul_878 + mul_876) + mul_880) + mul_882) + mul_971) * scale_1173);
			t_sample dcblock_631 = __m_dcblock_103(mul_666);
			t_sample mul_634 = (sqrt_633 * dcblock_631);
			t_sample out2 = ((mul_634 + mul_636) + gate_1024);
			t_sample mul_667 = (((((mul_879 + mul_877) + mul_881) + mul_883) + mul_971) * scale_1173);
			t_sample dcblock_632 = __m_dcblock_104(mul_667);
			t_sample mul_635 = (sqrt_633 * dcblock_632);
			t_sample out1 = ((mul_635 + mul_636) + gate_1024);
			t_sample history_1001_next_1067 = fixdenorm(eq_1002);
			m_history_22 = history_642_next_644;
			m_history_20 = history_638_next_646;
			m_history_21 = history_640_next_645;
			m_history_19 = history_1020_next_1022;
			m_history_18 = history_642_next_1037;
			m_history_16 = history_638_next_1029;
			m_history_17 = history_640_next_1032;
			m_history_15 = history_642_next_1047;
			m_history_13 = history_638_next_1041;
			m_history_14 = history_640_next_1042;
			m_delay_12.write(eq_968);
			m_delay_11.write(eq_1006);
			m_delay_10.write(eq_962);
			m_delay_9.write(eq_965);
			m_delay_8.write(tap_677);
			m_delay_7.write(tap_679);
			m_delay_6.write(tap_681);
			m_delay_5.write(tap_683);
			m_history_4 = history_642_next_1062;
			m_history_2 = history_638_next_1061;
			m_history_3 = history_640_next_1054;
			m_history_1 = history_1001_next_1067;
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
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_glitchlen(t_param _value) {
		m_knob5_glitchlen_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_thresh(t_param _value) {
		m_knob3_thresh_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_density(t_param _value) {
		m_knob6_density_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob1_wetdry_23; break;
		case 1: *value = self->m_knob3_thresh_27; break;
		case 2: *value = self->m_knob4_buflen_26; break;
		case 3: *value = self->m_knob5_glitchlen_24; break;
		case 4: *value = self->m_knob6_density_28; break;
		
		case 6: *value = self->m_sw_29; break;
		case 7: *value = self->m_sw_25; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_23")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_thresh_27")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_thresh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_thresh_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_buflen_26")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_buflen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_buflen_26;
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
	// initialize parameter 6 ("m_sw_29")
	pi = self->__commonstate.params + 6;
	pi->name = "sw1";
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
	// initialize parameter 7 ("m_sw_25")
	pi = self->__commonstate.params + 7;
	pi->name = "sw2";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Glitch::
