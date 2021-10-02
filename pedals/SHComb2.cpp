#include "SHComb2.h"

namespace SHComb2 {

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
	Data m_ms_5;
	Delay m_delay_1;
	Delay m_delay_3;
	Delay m_delay_4;
	Delay m_delay_2;
	Phasor __m_phasor_30;
	Phasor __m_phasor_29;
	Sah __m_sah_27;
	Sah __m_sah_31;
	int __exception;
	int vectorsize;
	t_sample m_history_8;
	t_sample m_knob1_res_22;
	t_sample m_knob4_max_21;
	t_sample m_knob3_min_23;
	t_sample m_sw_24;
	t_sample m_sw_25;
	t_sample m_history_26;
	t_sample m_knob5_r_20;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample m_history_7;
	t_sample m_knob2_key_19;
	t_sample m_history_17;
	t_sample m_history_11;
	t_sample m_history_10;
	t_sample m_history_9;
	t_sample m_knob6_r_18;
	t_sample m_history_12;
	t_sample m_history_6;
	t_sample m_history_13;
	t_sample m_history_16;
	t_sample m_history_15;
	t_sample m_history_14;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)6000));
		m_delay_2.reset("m_delay_2", ((int)6000));
		m_delay_3.reset("m_delay_3", ((int)6000));
		m_delay_4.reset("m_delay_4", ((int)6000));
		m_ms_5.reset("ms", ((int)12), ((int)1));
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
		m_knob6_r_18 = ((int)0);
		m_knob2_key_19 = ((int)0);
		m_knob5_r_20 = ((int)0);
		m_knob4_max_21 = ((int)0);
		m_knob1_res_22 = ((int)0);
		m_knob3_min_23 = ((int)0);
		m_sw_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_history_26 = ((int)0);
		__m_sah_27.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_29.reset(0);
		__m_phasor_30.reset(0);
		__m_sah_31.reset(0);
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
		t_sample sqrt_749 = sqrt(m_knob1_res_22);
		t_sample sqrt_758 = sqrt(sqrt_749);
		t_sample mul_761 = (sqrt_758 * ((t_sample)0.99));
		t_sample mul_595 = (m_knob2_key_19 * ((int)12));
		t_sample round_594 = round(mul_595);
		samples_to_seconds = (1 / samplerate);
		int ms_dim = m_ms_5.dim;
		int ms_channels = m_ms_5.channels;
		bool index_ignore_32 = (((int)1) >= ms_dim);
		bool index_ignore_33 = (((int)2) >= ms_dim);
		bool index_ignore_34 = (((int)3) >= ms_dim);
		bool index_ignore_35 = (((int)4) >= ms_dim);
		bool index_ignore_36 = (((int)5) >= ms_dim);
		bool index_ignore_37 = (((int)6) >= ms_dim);
		bool index_ignore_38 = (((int)7) >= ms_dim);
		bool index_ignore_39 = (((int)8) >= ms_dim);
		bool index_ignore_40 = (((int)9) >= ms_dim);
		bool index_ignore_41 = (((int)10) >= ms_dim);
		bool index_ignore_42 = (((int)11) >= ms_dim);
		bool index_ignore_45 = (((int)1) >= ms_dim);
		bool index_ignore_46 = (((int)2) >= ms_dim);
		bool index_ignore_47 = (((int)3) >= ms_dim);
		bool index_ignore_48 = (((int)4) >= ms_dim);
		bool index_ignore_49 = (((int)5) >= ms_dim);
		bool index_ignore_50 = (((int)6) >= ms_dim);
		bool index_ignore_51 = (((int)7) >= ms_dim);
		bool index_ignore_52 = (((int)8) >= ms_dim);
		bool index_ignore_53 = (((int)9) >= ms_dim);
		bool index_ignore_54 = (((int)10) >= ms_dim);
		bool index_ignore_55 = (((int)11) >= ms_dim);
		bool index_ignore_58 = (((int)1) >= ms_dim);
		bool index_ignore_59 = (((int)2) >= ms_dim);
		bool index_ignore_60 = (((int)3) >= ms_dim);
		bool index_ignore_61 = (((int)4) >= ms_dim);
		bool index_ignore_62 = (((int)5) >= ms_dim);
		bool index_ignore_63 = (((int)6) >= ms_dim);
		bool index_ignore_64 = (((int)7) >= ms_dim);
		bool index_ignore_65 = (((int)8) >= ms_dim);
		bool index_ignore_66 = (((int)9) >= ms_dim);
		bool index_ignore_67 = (((int)10) >= ms_dim);
		bool index_ignore_68 = (((int)11) >= ms_dim);
		bool index_ignore_71 = (((int)1) >= ms_dim);
		bool index_ignore_72 = (((int)2) >= ms_dim);
		bool index_ignore_73 = (((int)3) >= ms_dim);
		bool index_ignore_74 = (((int)4) >= ms_dim);
		bool index_ignore_75 = (((int)5) >= ms_dim);
		bool index_ignore_76 = (((int)6) >= ms_dim);
		bool index_ignore_77 = (((int)7) >= ms_dim);
		bool index_ignore_78 = (((int)8) >= ms_dim);
		bool index_ignore_79 = (((int)9) >= ms_dim);
		bool index_ignore_80 = (((int)10) >= ms_dim);
		bool index_ignore_81 = (((int)11) >= ms_dim);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_752 = __m_sah_27(m_history_26, m_sw_24, ((int)0));
			t_sample gen_754 = sah_752;
			t_sample rsub_750 = (((int)1) - sah_752);
			t_sample history_751_next_753 = fixdenorm(rsub_750);
			t_sample out3 = gen_754;
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample add_757 = (gen_754 + ((int)1));
			t_sample choice_28 = int(add_757);
			t_sample gate_755 = (((choice_28 >= 1) && (choice_28 < 2)) ? in1 : 0);
			t_sample gate_756 = ((choice_28 >= 2) ? in1 : 0);
			t_sample switch_583 = (m_sw_25 ? gate_756 : ((int)0));
			t_sample mix_990 = (m_history_17 + (((t_sample)0.003926980723806) * (m_knob3_min_23 - m_history_17)));
			t_sample mix_710 = mix_990;
			t_sample mix_991 = (m_history_16 + (((t_sample)0.003926980723806) * (mix_710 - m_history_16)));
			t_sample mix_708 = mix_991;
			t_sample mix_992 = (m_history_15 + (((t_sample)0.003926980723806) * (mix_708 - m_history_15)));
			t_sample mix_706 = mix_992;
			t_sample gen_747 = mix_706;
			t_sample history_711_next_713 = fixdenorm(mix_710);
			t_sample history_709_next_714 = fixdenorm(mix_708);
			t_sample history_707_next_715 = fixdenorm(mix_706);
			t_sample sub_996 = (gen_747 - ((int)0));
			t_sample scale_993 = ((safepow((sub_996 * ((t_sample)1)), ((int)1)) * ((int)84)) + ((int)24));
			t_sample mix_997 = (m_history_14 + (((t_sample)0.003926980723806) * (m_knob4_max_21 - m_history_14)));
			t_sample mix_767 = mix_997;
			t_sample mix_998 = (m_history_13 + (((t_sample)0.003926980723806) * (mix_767 - m_history_13)));
			t_sample mix_769 = mix_998;
			t_sample mix_999 = (m_history_12 + (((t_sample)0.003926980723806) * (mix_769 - m_history_12)));
			t_sample mix_765 = mix_999;
			t_sample gen_716 = mix_765;
			t_sample history_711_next_766 = fixdenorm(mix_767);
			t_sample history_709_next_768 = fixdenorm(mix_769);
			t_sample history_707_next_771 = fixdenorm(mix_765);
			t_sample sub_1003 = (gen_716 - ((int)0));
			t_sample scale_1000 = ((safepow((sub_1003 * ((t_sample)1)), ((int)1)) * ((int)84)) + ((int)24));
			t_sample mix_1004 = (m_history_11 + (((t_sample)0.003926980723806) * (m_knob5_r_20 - m_history_11)));
			t_sample mix_779 = mix_1004;
			t_sample mix_1005 = (m_history_10 + (((t_sample)0.003926980723806) * (mix_779 - m_history_10)));
			t_sample mix_784 = mix_1005;
			t_sample mix_1006 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_784 - m_history_9)));
			t_sample mix_778 = mix_1006;
			t_sample gen_746 = mix_778;
			t_sample history_711_next_782 = fixdenorm(mix_779);
			t_sample history_709_next_780 = fixdenorm(mix_784);
			t_sample history_707_next_786 = fixdenorm(mix_778);
			t_sample mul_759 = (gen_746 * ((int)10));
			t_sample phasor_760 = __m_phasor_29(mul_759, samples_to_seconds);
			t_sample mix_1007 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob6_r_18 - m_history_8)));
			t_sample mix_792 = mix_1007;
			t_sample mix_1008 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_792 - m_history_7)));
			t_sample mix_797 = mix_1008;
			t_sample mix_1009 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_797 - m_history_6)));
			t_sample mix_791 = mix_1009;
			t_sample gen_745 = mix_791;
			t_sample history_711_next_795 = fixdenorm(mix_792);
			t_sample history_709_next_793 = fixdenorm(mix_797);
			t_sample history_707_next_799 = fixdenorm(mix_791);
			t_sample mul_700 = (gen_745 * ((int)10));
			t_sample phasor_701 = __m_phasor_30(mul_700, samples_to_seconds);
			t_sample sah_702 = __m_sah_31(phasor_760, phasor_701, ((t_sample)0.5));
			t_sample add_597 = (sah_702 + ((t_sample)0.75));
			t_sample mod_596 = safemod(add_597, ((int)1));
			t_sample orange_1012 = (scale_1000 - scale_993);
			t_sample sub_1013 = (mod_596 - ((int)0));
			t_sample scale_1010 = ((safepow((sub_1013 * ((t_sample)1)), ((int)1)) * orange_1012) + scale_993);
			m_ms_5.write(((int)0), 0, 0);
			if ((!index_ignore_32)) {
				m_ms_5.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_33)) {
				m_ms_5.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_34)) {
				m_ms_5.write(((int)4), ((int)3), 0);
				
			};
			if ((!index_ignore_35)) {
				m_ms_5.write(((int)4), ((int)4), 0);
				
			};
			if ((!index_ignore_36)) {
				m_ms_5.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_37)) {
				m_ms_5.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_38)) {
				m_ms_5.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_39)) {
				m_ms_5.write(((int)9), ((int)8), 0);
				
			};
			if ((!index_ignore_40)) {
				m_ms_5.write(((int)9), ((int)9), 0);
				
			};
			if ((!index_ignore_41)) {
				m_ms_5.write(((int)11), ((int)10), 0);
				
			};
			if ((!index_ignore_42)) {
				m_ms_5.write(((int)11), ((int)11), 0);
				
			};
			t_sample oct = floor((scale_1010 * ((t_sample)0.083333333333333)));
			t_sample pc = floor(safemod((scale_1010 + round_594), ((int)12)));
			int index_trunc_43 = fixnan(floor(pc));
			bool index_ignore_44 = ((index_trunc_43 >= ms_dim) || (index_trunc_43 < 0));
			// samples ms channel 1;
			t_sample pc_grid = (index_ignore_44 ? 0 : m_ms_5.read(index_trunc_43, 0));
			t_sample outpitch = ((pc_grid + (oct * ((int)12))) - round_594);
			t_sample mtof_605 = mtof(outpitch, ((int)440));
			t_sample rdiv_604 = safediv(((int)1000), mtof_605);
			t_sample mstosamps_603 = (rdiv_604 * (samplerate * 0.001));
			t_sample tap_633 = m_delay_4.read_linear(mstosamps_603);
			t_sample mul_631 = (tap_633 * mul_761);
			t_sample mul_587 = (mul_631 * ((t_sample)0.6));
			t_sample mul_586 = (mul_631 * ((t_sample)0.4));
			t_sample add_599 = (sah_702 + ((t_sample)0.5));
			t_sample mod_598 = safemod(add_599, ((int)1));
			t_sample orange_1016 = (scale_1000 - scale_993);
			t_sample sub_1017 = (mod_598 - ((int)0));
			t_sample scale_1014 = ((safepow((sub_1017 * ((t_sample)1)), ((int)1)) * orange_1016) + scale_993);
			m_ms_5.write(((int)0), 0, 0);
			if ((!index_ignore_45)) {
				m_ms_5.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_46)) {
				m_ms_5.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_47)) {
				m_ms_5.write(((int)4), ((int)3), 0);
				
			};
			if ((!index_ignore_48)) {
				m_ms_5.write(((int)4), ((int)4), 0);
				
			};
			if ((!index_ignore_49)) {
				m_ms_5.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_50)) {
				m_ms_5.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_51)) {
				m_ms_5.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_52)) {
				m_ms_5.write(((int)9), ((int)8), 0);
				
			};
			if ((!index_ignore_53)) {
				m_ms_5.write(((int)9), ((int)9), 0);
				
			};
			if ((!index_ignore_54)) {
				m_ms_5.write(((int)11), ((int)10), 0);
				
			};
			if ((!index_ignore_55)) {
				m_ms_5.write(((int)11), ((int)11), 0);
				
			};
			t_sample oct_805 = floor((scale_1014 * ((t_sample)0.083333333333333)));
			t_sample pc_804 = floor(safemod((scale_1014 + round_594), ((int)12)));
			int index_trunc_56 = fixnan(floor(pc_804));
			bool index_ignore_57 = ((index_trunc_56 >= ms_dim) || (index_trunc_56 < 0));
			// samples ms channel 1;
			t_sample pc_grid_806 = (index_ignore_57 ? 0 : m_ms_5.read(index_trunc_56, 0));
			t_sample outpitch_807 = ((pc_grid_806 + (oct_805 * ((int)12))) - round_594);
			t_sample mtof_637 = mtof(outpitch_807, ((int)440));
			t_sample rdiv_636 = safediv(((int)1000), mtof_637);
			t_sample mstosamps_635 = (rdiv_636 * (samplerate * 0.001));
			t_sample tap_665 = m_delay_3.read_linear(mstosamps_635);
			t_sample mul_663 = (tap_665 * mul_761);
			t_sample mul_589 = (mul_663 * ((t_sample)0.9));
			t_sample mul_588 = (mul_663 * ((t_sample)0.1));
			t_sample add_699 = (sah_702 + ((int)0));
			t_sample mod_698 = safemod(add_699, ((int)1));
			t_sample orange_1020 = (scale_1000 - scale_993);
			t_sample sub_1021 = (mod_698 - ((int)0));
			t_sample scale_1018 = ((safepow((sub_1021 * ((t_sample)1)), ((int)1)) * orange_1020) + scale_993);
			m_ms_5.write(((int)0), 0, 0);
			if ((!index_ignore_58)) {
				m_ms_5.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_59)) {
				m_ms_5.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_60)) {
				m_ms_5.write(((int)4), ((int)3), 0);
				
			};
			if ((!index_ignore_61)) {
				m_ms_5.write(((int)4), ((int)4), 0);
				
			};
			if ((!index_ignore_62)) {
				m_ms_5.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_63)) {
				m_ms_5.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_64)) {
				m_ms_5.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_65)) {
				m_ms_5.write(((int)9), ((int)8), 0);
				
			};
			if ((!index_ignore_66)) {
				m_ms_5.write(((int)9), ((int)9), 0);
				
			};
			if ((!index_ignore_67)) {
				m_ms_5.write(((int)11), ((int)10), 0);
				
			};
			if ((!index_ignore_68)) {
				m_ms_5.write(((int)11), ((int)11), 0);
				
			};
			t_sample oct_809 = floor((scale_1018 * ((t_sample)0.083333333333333)));
			t_sample pc_808 = floor(safemod((scale_1018 + round_594), ((int)12)));
			int index_trunc_69 = fixnan(floor(pc_808));
			bool index_ignore_70 = ((index_trunc_69 >= ms_dim) || (index_trunc_69 < 0));
			// samples ms channel 1;
			t_sample pc_grid_810 = (index_ignore_70 ? 0 : m_ms_5.read(index_trunc_69, 0));
			t_sample outpitch_811 = ((pc_grid_810 + (oct_809 * ((int)12))) - round_594);
			t_sample mtof_719 = mtof(outpitch_811, ((int)440));
			t_sample rdiv_718 = safediv(((int)1000), mtof_719);
			t_sample mstosamps_717 = (rdiv_718 * (samplerate * 0.001));
			t_sample tap_764 = m_delay_2.read_linear(mstosamps_717);
			t_sample mul_762 = (tap_764 * mul_761);
			t_sample mul_592 = (mul_762 * ((t_sample)0.1));
			t_sample mul_593 = (mul_762 * ((t_sample)0.9));
			t_sample add_601 = (sah_702 + ((t_sample)0.25));
			t_sample mod_600 = safemod(add_601, ((int)1));
			t_sample orange_1024 = (scale_1000 - scale_993);
			t_sample sub_1025 = (mod_600 - ((int)0));
			t_sample scale_1022 = ((safepow((sub_1025 * ((t_sample)1)), ((int)1)) * orange_1024) + scale_993);
			m_ms_5.write(((int)0), 0, 0);
			if ((!index_ignore_71)) {
				m_ms_5.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_72)) {
				m_ms_5.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_73)) {
				m_ms_5.write(((int)4), ((int)3), 0);
				
			};
			if ((!index_ignore_74)) {
				m_ms_5.write(((int)4), ((int)4), 0);
				
			};
			if ((!index_ignore_75)) {
				m_ms_5.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_76)) {
				m_ms_5.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_77)) {
				m_ms_5.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_78)) {
				m_ms_5.write(((int)9), ((int)8), 0);
				
			};
			if ((!index_ignore_79)) {
				m_ms_5.write(((int)9), ((int)9), 0);
				
			};
			if ((!index_ignore_80)) {
				m_ms_5.write(((int)11), ((int)10), 0);
				
			};
			if ((!index_ignore_81)) {
				m_ms_5.write(((int)11), ((int)11), 0);
				
			};
			t_sample oct_813 = floor((scale_1022 * ((t_sample)0.083333333333333)));
			t_sample pc_812 = floor(safemod((scale_1022 + round_594), ((int)12)));
			int index_trunc_82 = fixnan(floor(pc_812));
			bool index_ignore_83 = ((index_trunc_82 >= ms_dim) || (index_trunc_82 < 0));
			// samples ms channel 1;
			t_sample pc_grid_814 = (index_ignore_83 ? 0 : m_ms_5.read(index_trunc_82, 0));
			t_sample outpitch_815 = ((pc_grid_814 + (oct_813 * ((int)12))) - round_594);
			t_sample mtof_669 = mtof(outpitch_815, ((int)440));
			t_sample rdiv_668 = safediv(((int)1000), mtof_669);
			t_sample mstosamps_667 = (rdiv_668 * (samplerate * 0.001));
			t_sample tap_697 = m_delay_1.read_linear(mstosamps_667);
			t_sample mul_695 = (tap_697 * mul_761);
			t_sample mul_590 = (mul_695 * ((t_sample)0.4));
			t_sample div_584 = (((((mul_590 + mul_592) + switch_583) + mul_589) + mul_587) * ((t_sample)0.25));
			t_sample out2 = (gate_755 + div_584);
			t_sample mul_591 = (mul_695 * ((t_sample)0.6));
			t_sample div_585 = (((((mul_591 + mul_593) + switch_583) + mul_588) + mul_586) * ((t_sample)0.25));
			t_sample out1 = (gate_755 + div_585);
			m_history_26 = history_751_next_753;
			m_history_17 = history_711_next_713;
			m_history_15 = history_707_next_715;
			m_history_16 = history_709_next_714;
			m_history_14 = history_711_next_766;
			m_history_12 = history_707_next_771;
			m_history_13 = history_709_next_768;
			m_history_11 = history_711_next_782;
			m_history_9 = history_707_next_786;
			m_history_10 = history_709_next_780;
			m_history_8 = history_711_next_795;
			m_history_6 = history_707_next_799;
			m_history_7 = history_709_next_793;
			m_delay_4.write((mul_631 + gate_756));
			m_delay_3.write((mul_663 + gate_756));
			m_delay_2.write((mul_762 + gate_756));
			m_delay_1.write((mul_695 + gate_756));
			m_delay_1.step();
			m_delay_2.step();
			m_delay_3.step();
			m_delay_4.step();
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
	inline void set_ms(void * _value) {
		m_ms_5.setbuffer(_value);
	};
	inline void set_knob6_r2(t_param _value) {
		m_knob6_r_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2_key(t_param _value) {
		m_knob2_key_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_r1(t_param _value) {
		m_knob5_r_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_max(t_param _value) {
		m_knob4_max_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_res(t_param _value) {
		m_knob1_res_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_min(t_param _value) {
		m_knob3_min_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 9; }

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
		case 0: self->set_knob1_res(value); break;
		case 1: self->set_knob2_key(value); break;
		case 2: self->set_knob3_min(value); break;
		case 3: self->set_knob4_max(value); break;
		case 4: self->set_knob5_r1(value); break;
		case 5: self->set_knob6_r2(value); break;
		case 6: self->set_ms(ref); break;
		case 7: self->set_sw1(value); break;
		case 8: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_res_22; break;
		case 1: *value = self->m_knob2_key_19; break;
		case 2: *value = self->m_knob3_min_23; break;
		case 3: *value = self->m_knob4_max_21; break;
		case 4: *value = self->m_knob5_r_20; break;
		case 5: *value = self->m_knob6_r_18; break;
		
		case 7: *value = self->m_sw_24; break;
		case 8: *value = self->m_sw_25; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(9 * sizeof(ParamInfo));
	self->__commonstate.numparams = 9;
	// initialize parameter 0 ("m_knob1_res_22")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_res_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob2_key_19")
	pi = self->__commonstate.params + 1;
	pi->name = "knob2_key";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_key_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob3_min_23")
	pi = self->__commonstate.params + 2;
	pi->name = "knob3_min";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_min_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob4_max_21")
	pi = self->__commonstate.params + 3;
	pi->name = "knob4_max";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_max_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob5_r_20")
	pi = self->__commonstate.params + 4;
	pi->name = "knob5_r1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_r_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob6_r_18")
	pi = self->__commonstate.params + 5;
	pi->name = "knob6_r2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_r_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_ms_5")
	pi = self->__commonstate.params + 6;
	pi->name = "ms";
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
	// initialize parameter 7 ("m_sw_24")
	pi = self->__commonstate.params + 7;
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
	// initialize parameter 8 ("m_sw_25")
	pi = self->__commonstate.params + 8;
	pi->name = "sw5";
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


} // SHComb2::
