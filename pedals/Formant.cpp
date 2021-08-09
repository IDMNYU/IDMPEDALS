#include "Formant.h"

namespace Formant {

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
	Data m_formants_26;
	Phasor __m_phasor_80;
	Sah __m_sah_79;
	Sah __m_sah_74;
	SineCycle __m_cycle_81;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_knob3_manual_23;
	t_sample m_y_5;
	t_sample m_sw_24;
	t_sample m_knob4_depth_22;
	t_sample m_knob5_ratethresh_21;
	t_sample m_sw_25;
	t_sample m_y_2;
	t_sample m_y_1;
	t_sample samples_to_seconds;
	t_sample m_knob6_res_20;
	t_sample samplerate;
	t_sample __m_slide_76;
	t_sample m_x_4;
	t_sample m_history_19;
	t_sample m_history_17;
	t_sample m_y_9;
	t_sample m_y_10;
	t_sample m_x_8;
	t_sample m_y_6;
	t_sample m_x_7;
	t_sample m_history_18;
	t_sample m_x_11;
	t_sample m_history_13;
	t_sample m_history_16;
	t_sample m_x_12;
	t_sample m_x_3;
	t_sample m_history_14;
	t_sample m_history_15;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_y_1 = ((int)0);
		m_y_2 = ((int)0);
		m_x_3 = ((int)0);
		m_x_4 = ((int)0);
		m_y_5 = ((int)0);
		m_y_6 = ((int)0);
		m_x_7 = ((int)0);
		m_x_8 = ((int)0);
		m_y_9 = ((int)0);
		m_y_10 = ((int)0);
		m_x_11 = ((int)0);
		m_x_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_knob6_res_20 = 3;
		m_knob5_ratethresh_21 = 0.1;
		m_knob4_depth_22 = 1;
		m_knob3_manual_23 = 0;
		m_sw_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_formants_26.reset("formants", ((int)10), ((int)3));
		__m_sah_74.reset(0);
		__m_slide_76 = 0;
		__m_sah_79.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_80.reset(0);
		__m_cycle_81.reset(samplerate, 0);
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
		int formants_dim = m_formants_26.dim;
		int formants_channels = m_formants_26.channels;
		bool chan_ignore_27 = ((((int)1) < 0) || (((int)1) >= formants_channels));
		bool chan_ignore_28 = ((((int)2) < 0) || (((int)2) >= formants_channels));
		bool index_ignore_29 = (((int)1) >= formants_dim);
		bool chan_ignore_30 = ((((int)1) < 0) || (((int)1) >= formants_channels));
		bool index_ignore_31 = (((int)1) >= formants_dim);
		bool chan_ignore_32 = ((((int)2) < 0) || (((int)2) >= formants_channels));
		bool index_ignore_33 = (((int)1) >= formants_dim);
		bool index_ignore_34 = (((int)2) >= formants_dim);
		bool chan_ignore_35 = ((((int)1) < 0) || (((int)1) >= formants_channels));
		bool index_ignore_36 = (((int)2) >= formants_dim);
		bool chan_ignore_37 = ((((int)2) < 0) || (((int)2) >= formants_channels));
		bool index_ignore_38 = (((int)2) >= formants_dim);
		bool index_ignore_39 = (((int)3) >= formants_dim);
		bool chan_ignore_40 = ((((int)1) < 0) || (((int)1) >= formants_channels));
		bool index_ignore_41 = (((int)3) >= formants_dim);
		bool chan_ignore_42 = ((((int)2) < 0) || (((int)2) >= formants_channels));
		bool index_ignore_43 = (((int)3) >= formants_dim);
		bool index_ignore_44 = (((int)4) >= formants_dim);
		bool chan_ignore_45 = ((((int)1) < 0) || (((int)1) >= formants_channels));
		bool index_ignore_46 = (((int)4) >= formants_dim);
		bool chan_ignore_47 = ((((int)2) < 0) || (((int)2) >= formants_channels));
		bool index_ignore_48 = (((int)4) >= formants_dim);
		bool index_ignore_49 = (((int)5) >= formants_dim);
		bool chan_ignore_50 = ((((int)1) < 0) || (((int)1) >= formants_channels));
		bool index_ignore_51 = (((int)5) >= formants_dim);
		bool chan_ignore_52 = ((((int)2) < 0) || (((int)2) >= formants_channels));
		bool index_ignore_53 = (((int)5) >= formants_dim);
		bool index_ignore_54 = (((int)6) >= formants_dim);
		bool chan_ignore_55 = ((((int)1) < 0) || (((int)1) >= formants_channels));
		bool index_ignore_56 = (((int)6) >= formants_dim);
		bool chan_ignore_57 = ((((int)2) < 0) || (((int)2) >= formants_channels));
		bool index_ignore_58 = (((int)6) >= formants_dim);
		bool index_ignore_59 = (((int)7) >= formants_dim);
		bool chan_ignore_60 = ((((int)1) < 0) || (((int)1) >= formants_channels));
		bool index_ignore_61 = (((int)7) >= formants_dim);
		bool chan_ignore_62 = ((((int)2) < 0) || (((int)2) >= formants_channels));
		bool index_ignore_63 = (((int)7) >= formants_dim);
		bool index_ignore_64 = (((int)8) >= formants_dim);
		bool chan_ignore_65 = ((((int)1) < 0) || (((int)1) >= formants_channels));
		bool index_ignore_66 = (((int)8) >= formants_dim);
		bool chan_ignore_67 = ((((int)2) < 0) || (((int)2) >= formants_channels));
		bool index_ignore_68 = (((int)8) >= formants_dim);
		bool index_ignore_69 = (((int)9) >= formants_dim);
		bool chan_ignore_70 = ((((int)1) < 0) || (((int)1) >= formants_channels));
		bool index_ignore_71 = (((int)9) >= formants_dim);
		bool chan_ignore_72 = ((((int)2) < 0) || (((int)2) >= formants_channels));
		bool index_ignore_73 = (((int)9) >= formants_dim);
		t_sample add_3815 = (m_sw_24 + ((int)1));
		t_sample mstosamps_3747 = (((int)20) * (samplerate * 0.001));
		t_sample iup_77 = (1 / maximum(1, abs(((int)1))));
		t_sample idown_78 = (1 / maximum(1, abs(mstosamps_3747)));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_82 = int(add_3815);
		bool chan_ignore_92 = ((1 < 0) || (1 >= formants_channels));
		bool chan_ignore_96 = ((2 < 0) || (2 >= formants_channels));
		t_sample q = m_knob6_res_20;
		t_sample twopi_over_sr = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample q_3890 = m_knob6_res_20;
		t_sample twopi_over_sr_3891 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample q_3908 = m_knob6_res_20;
		t_sample twopi_over_sr_3909 = safediv(((t_sample)6.2831853071796), samplerate);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			m_formants_26.write(((int)270), 0, 0);
			if ((!chan_ignore_27)) {
				m_formants_26.write(((int)2290), 0, ((int)1));
				
			};
			if ((!chan_ignore_28)) {
				m_formants_26.write(((int)3010), 0, ((int)2));
				
			};
			if ((!index_ignore_29)) {
				m_formants_26.write(((int)390), ((int)1), 0);
				
			};
			if ((!(chan_ignore_30 || index_ignore_31))) {
				m_formants_26.write(((int)1990), ((int)1), ((int)1));
				
			};
			if ((!(chan_ignore_32 || index_ignore_33))) {
				m_formants_26.write(((int)2550), ((int)1), ((int)2));
				
			};
			if ((!index_ignore_34)) {
				m_formants_26.write(((int)530), ((int)2), 0);
				
			};
			if ((!(chan_ignore_35 || index_ignore_36))) {
				m_formants_26.write(((int)1840), ((int)2), ((int)1));
				
			};
			if ((!(chan_ignore_37 || index_ignore_38))) {
				m_formants_26.write(((int)2480), ((int)2), ((int)2));
				
			};
			if ((!index_ignore_39)) {
				m_formants_26.write(((int)660), ((int)3), 0);
				
			};
			if ((!(chan_ignore_40 || index_ignore_41))) {
				m_formants_26.write(((int)1720), ((int)3), ((int)1));
				
			};
			if ((!(chan_ignore_42 || index_ignore_43))) {
				m_formants_26.write(((int)2410), ((int)3), ((int)2));
				
			};
			if ((!index_ignore_44)) {
				m_formants_26.write(((int)520), ((int)4), 0);
				
			};
			if ((!(chan_ignore_45 || index_ignore_46))) {
				m_formants_26.write(((int)1190), ((int)4), ((int)1));
				
			};
			if ((!(chan_ignore_47 || index_ignore_48))) {
				m_formants_26.write(((int)2390), ((int)4), ((int)2));
				
			};
			if ((!index_ignore_49)) {
				m_formants_26.write(((int)730), ((int)5), 0);
				
			};
			if ((!(chan_ignore_50 || index_ignore_51))) {
				m_formants_26.write(((int)1090), ((int)5), ((int)1));
				
			};
			if ((!(chan_ignore_52 || index_ignore_53))) {
				m_formants_26.write(((int)2440), ((int)5), ((int)2));
				
			};
			if ((!index_ignore_54)) {
				m_formants_26.write(((int)570), ((int)6), 0);
				
			};
			if ((!(chan_ignore_55 || index_ignore_56))) {
				m_formants_26.write(((int)840), ((int)6), ((int)1));
				
			};
			if ((!(chan_ignore_57 || index_ignore_58))) {
				m_formants_26.write(((int)2410), ((int)6), ((int)2));
				
			};
			if ((!index_ignore_59)) {
				m_formants_26.write(((int)440), ((int)7), 0);
				
			};
			if ((!(chan_ignore_60 || index_ignore_61))) {
				m_formants_26.write(((int)1020), ((int)7), ((int)1));
				
			};
			if ((!(chan_ignore_62 || index_ignore_63))) {
				m_formants_26.write(((int)2240), ((int)7), ((int)2));
				
			};
			if ((!index_ignore_64)) {
				m_formants_26.write(((int)300), ((int)8), 0);
				
			};
			if ((!(chan_ignore_65 || index_ignore_66))) {
				m_formants_26.write(((int)870), ((int)8), ((int)1));
				
			};
			if ((!(chan_ignore_67 || index_ignore_68))) {
				m_formants_26.write(((int)2240), ((int)8), ((int)2));
				
			};
			if ((!index_ignore_69)) {
				m_formants_26.write(((int)490), ((int)9), 0);
				
			};
			if ((!(chan_ignore_70 || index_ignore_71))) {
				m_formants_26.write(((int)1350), ((int)9), ((int)1));
				
			};
			if ((!(chan_ignore_72 || index_ignore_73))) {
				m_formants_26.write(((int)1690), ((int)9), ((int)2));
				
			};
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_3824 = __m_sah_74(m_history_19, m_sw_25, ((int)0));
			t_sample gen_3826 = sah_3824;
			t_sample rsub_3822 = (((int)1) - sah_3824);
			t_sample history_3823_next_3825 = fixdenorm(rsub_3822);
			t_sample out3 = gen_3826;
			t_sample add_3827 = (gen_3826 + ((int)1));
			t_sample choice_75 = int(add_3827);
			t_sample gate_3819 = (((choice_75 >= 1) && (choice_75 < 2)) ? in1 : 0);
			t_sample gate_3820 = ((choice_75 >= 2) ? in1 : 0);
			t_sample mix_4426 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_knob3_manual_23 - m_history_18)));
			t_sample mix_3800 = mix_4426;
			t_sample mix_4427 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_3800 - m_history_17)));
			t_sample mix_3798 = mix_4427;
			t_sample mix_4428 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_3798 - m_history_16)));
			t_sample mix_3796 = mix_4428;
			t_sample gen_3808 = mix_3796;
			t_sample history_3802_next_3805 = fixdenorm(mix_3800);
			t_sample history_3799_next_3806 = fixdenorm(mix_3798);
			t_sample history_3797_next_3807 = fixdenorm(mix_3796);
			t_sample noise_3750 = noise();
			t_sample abs_3748 = fabs(noise_3750);
			t_sample abs_3818 = fabs(gate_3820);
			t_sample mix_4429 = (m_history_15 + (((t_sample)0.0019634941468452) * (m_knob5_ratethresh_21 - m_history_15)));
			t_sample mix_3870 = mix_4429;
			t_sample mix_4430 = (m_history_14 + (((t_sample)0.0019634941468452) * (mix_3870 - m_history_14)));
			t_sample mix_3867 = mix_4430;
			t_sample mix_4431 = (m_history_13 + (((t_sample)0.0019634941468452) * (mix_3867 - m_history_13)));
			t_sample mix_3866 = mix_4431;
			t_sample gen_3812 = mix_3866;
			t_sample history_3802_next_3873 = fixdenorm(mix_3870);
			t_sample history_3799_next_3874 = fixdenorm(mix_3867);
			t_sample history_3797_next_3871 = fixdenorm(mix_3866);
			t_sample mul_3745 = (gen_3812 * ((t_sample)0.3));
			int gt_3749 = (abs_3818 > mul_3745);
			__m_slide_76 = fixdenorm((__m_slide_76 + (((gt_3749 > __m_slide_76) ? iup_77 : idown_78) * (gt_3749 - __m_slide_76))));
			t_sample slide_3817 = __m_slide_76;
			t_sample sah_3795 = __m_sah_79(abs_3748, slide_3817, ((t_sample)0.01));
			t_sample rsub_3830 = (((int)1) - gen_3812);
			t_sample sqrt_3829 = sqrt(rsub_3830);
			t_sample rsub_3828 = (((int)1) - sqrt_3829);
			t_sample mul_3834 = (rsub_3828 * ((int)5));
			t_sample phasor_3833 = __m_phasor_80(mul_3834, samples_to_seconds);
			__m_cycle_81.phase(phasor_3833);
			t_sample cycle_3810 = __m_cycle_81(__sinedata);
			t_sample cycleindex_3811 = __m_cycle_81.phase();
			t_sample sub_4435 = (cycle_3810 - (-1));
			t_sample scale_4432 = ((safepow((sub_4435 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_3794 = scale_4432;
			t_sample selector_3816 = ((choice_82 >= 2) ? sah_3795 : ((choice_82 >= 1) ? scale_3794 : 0));
			t_sample mul_3809 = (selector_3816 * m_knob4_depth_22);
			t_sample add_3752 = (mul_3809 + gen_3808);
			t_sample mod_3753 = safemod(add_3752, ((int)1));
			t_sample clamp_3751 = ((mod_3753 <= ((int)0)) ? ((int)0) : ((mod_3753 >= ((int)1)) ? ((int)1) : mod_3753));
			double sample_index_83 = (clamp_3751 * (formants_dim - 1));
			int index_trunc_84 = fixnan(floor(sample_index_83));
			double index_fract_85 = (sample_index_83 - index_trunc_84);
			int index_trunc_86 = (index_trunc_84 + 1);
			bool index_ignore_87 = ((index_trunc_84 >= formants_dim) || (index_trunc_84 < 0));
			bool index_ignore_88 = ((index_trunc_86 >= formants_dim) || (index_trunc_86 < 0));
			// phase formants channel 1;
			double read_formants_89 = (index_ignore_87 ? 0 : m_formants_26.read(index_trunc_84, 0));
			double read_formants_90 = (index_ignore_88 ? 0 : m_formants_26.read(index_trunc_86, 0));
			double readinterp_91 = linear_interp(index_fract_85, read_formants_89, read_formants_90);
			// phase formants channel 2;
			double read_formants_93 = ((chan_ignore_92 || index_ignore_87) ? 0 : m_formants_26.read(index_trunc_84, 1));
			double read_formants_94 = ((chan_ignore_92 || index_ignore_88) ? 0 : m_formants_26.read(index_trunc_86, 1));
			double readinterp_95 = linear_interp(index_fract_85, read_formants_93, read_formants_94);
			// phase formants channel 3;
			double read_formants_97 = ((chan_ignore_96 || index_ignore_87) ? 0 : m_formants_26.read(index_trunc_84, 2));
			double read_formants_98 = ((chan_ignore_96 || index_ignore_88) ? 0 : m_formants_26.read(index_trunc_86, 2));
			double readinterp_99 = linear_interp(index_fract_85, read_formants_97, read_formants_98);
			t_sample sample_formants_3758 = readinterp_91;
			t_sample sample_formants_3759 = readinterp_95;
			t_sample sample_formants_3760 = readinterp_99;
			t_sample index_formants_3761 = sample_index_83;
			t_sample x = gate_3820;
			t_sample cf = sample_formants_3759;
			t_sample bw = safediv(cf, q);
			t_sample r = exp(((-bw) * twopi_over_sr));
			t_sample c1 = ((((int)2) * r) * cos((cf * twopi_over_sr)));
			t_sample c2 = ((-r) * r);
			t_sample y = ((((((int)1) - r) * (x - (r * m_x_11))) + (c1 * m_y_10)) + (c2 * m_y_9));
			m_y_9 = m_y_10;
			m_y_10 = y;
			m_x_11 = m_x_12;
			m_x_12 = x;
			t_sample x_3882 = gate_3820;
			t_sample cf_3884 = sample_formants_3760;
			t_sample bw_3883 = safediv(cf_3884, q_3890);
			t_sample r_3888 = exp(((-bw_3883) * twopi_over_sr_3891));
			t_sample c_3885 = ((((int)2) * r_3888) * cos((cf_3884 * twopi_over_sr_3891)));
			t_sample c_3887 = ((-r_3888) * r_3888);
			t_sample y_3881 = ((((((int)1) - r_3888) * (x_3882 - (r_3888 * m_x_7))) + (c_3885 * m_y_6)) + (c_3887 * m_y_5));
			m_y_5 = m_y_6;
			m_y_6 = y_3881;
			m_x_7 = m_x_8;
			m_x_8 = x_3882;
			t_sample x_3900 = gate_3820;
			t_sample cf_3902 = sample_formants_3758;
			t_sample bw_3901 = safediv(cf_3902, q_3908);
			t_sample r_3904 = exp(((-bw_3901) * twopi_over_sr_3909));
			t_sample c_3903 = ((((int)2) * r_3904) * cos((cf_3902 * twopi_over_sr_3909)));
			t_sample c_3906 = ((-r_3904) * r_3904);
			t_sample y_3899 = ((((((int)1) - r_3904) * (x_3900 - (r_3904 * m_x_3))) + (c_3903 * m_y_2)) + (c_3906 * m_y_1));
			m_y_1 = m_y_2;
			m_y_2 = y_3899;
			m_x_3 = m_x_4;
			m_x_4 = x_3900;
			t_sample mul_3746 = (((y_3899 + y_3881) + y) * ((int)3));
			t_sample add_3832 = (mul_3746 + gate_3819);
			t_sample out1 = add_3832;
			t_sample add_3831 = (mul_3746 + gate_3819);
			t_sample out2 = add_3831;
			m_history_19 = history_3823_next_3825;
			m_history_18 = history_3802_next_3805;
			m_history_16 = history_3797_next_3807;
			m_history_17 = history_3799_next_3806;
			m_history_15 = history_3802_next_3873;
			m_history_13 = history_3797_next_3871;
			m_history_14 = history_3799_next_3874;
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
	inline void set_knob6_res(t_param _value) {
		m_knob6_res_20 = (_value < 1 ? 1 : (_value > 100 ? 100 : _value));
	};
	inline void set_knob5_ratethresh(t_param _value) {
		m_knob5_ratethresh_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_depth(t_param _value) {
		m_knob4_depth_22 = (_value < -1 ? -1 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_manual(t_param _value) {
		m_knob3_manual_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_formants(void * _value) {
		m_formants_26.setbuffer(_value);
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
int num_params() { return 7; }

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
		case 0: self->set_formants(ref); break;
		case 1: self->set_knob3_manual(value); break;
		case 2: self->set_knob4_depth(value); break;
		case 3: self->set_knob5_ratethresh(value); break;
		case 4: self->set_knob6_res(value); break;
		case 5: self->set_sw1(value); break;
		case 6: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
		case 1: *value = self->m_knob3_manual_23; break;
		case 2: *value = self->m_knob4_depth_22; break;
		case 3: *value = self->m_knob5_ratethresh_21; break;
		case 4: *value = self->m_knob6_res_20; break;
		case 5: *value = self->m_sw_25; break;
		case 6: *value = self->m_sw_24; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(7 * sizeof(ParamInfo));
	self->__commonstate.numparams = 7;
	// initialize parameter 0 ("m_formants_26")
	pi = self->__commonstate.params + 0;
	pi->name = "formants";
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
	// initialize parameter 1 ("m_knob3_manual_23")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_manual";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_manual_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_depth_22")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_depth_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -1;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_ratethresh_21")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_ratethresh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_ratethresh_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_res_20")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_res_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_25")
	pi = self->__commonstate.params + 5;
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
	// initialize parameter 6 ("m_sw_24")
	pi = self->__commonstate.params + 6;
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


} // Formant::
