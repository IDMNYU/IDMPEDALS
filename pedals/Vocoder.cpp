#include "Vocoder.h"

namespace Vocoder {

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
	DCBlock __m_dcblock_201;
	DCBlock __m_dcblock_157;
	DCBlock __m_dcblock_161;
	DCBlock __m_dcblock_165;
	DCBlock __m_dcblock_153;
	DCBlock __m_dcblock_145;
	DCBlock __m_dcblock_149;
	DCBlock __m_dcblock_141;
	DCBlock __m_dcblock_169;
	DCBlock __m_dcblock_177;
	DCBlock __m_dcblock_193;
	DCBlock __m_dcblock_197;
	DCBlock __m_dcblock_173;
	DCBlock __m_dcblock_189;
	DCBlock __m_dcblock_181;
	DCBlock __m_dcblock_185;
	Sah __m_sah_136;
	int __exception;
	int vectorsize;
	t_sample m_x_16;
	t_sample m_y_117;
	t_sample m_y_118;
	t_sample m_x_116;
	t_sample m_x_115;
	t_sample m_y_114;
	t_sample m_x_119;
	t_sample m_y_113;
	t_sample m_x_112;
	t_sample m_x_120;
	t_sample m_y_122;
	t_sample m_y_126;
	t_sample m_x_127;
	t_sample m_y_121;
	t_sample m_y_125;
	t_sample m_x_123;
	t_sample m_x_124;
	t_sample m_x_111;
	t_sample m_y_110;
	t_sample m_y_109;
	t_sample m_y_98;
	t_sample m_x_99;
	t_sample m_x_100;
	t_sample m_y_97;
	t_sample m_x_95;
	t_sample m_x_96;
	t_sample m_y_94;
	t_sample m_x_128;
	t_sample m_y_101;
	t_sample m_x_103;
	t_sample m_x_107;
	t_sample m_x_108;
	t_sample m_y_102;
	t_sample m_y_106;
	t_sample m_x_104;
	t_sample m_y_105;
	t_sample m_history_129;
	t_sample m_history_130;
	t_sample m_history_131;
	t_sample __m_slide_174;
	t_sample m_x_4;
	t_sample __m_slide_178;
	t_sample m_y_5;
	t_sample m_y_6;
	t_sample __m_slide_170;
	t_sample __m_slide_166;
	t_sample m_x_7;
	t_sample m_x_3;
	t_sample m_y_2;
	t_sample samplerate;
	t_sample __m_slide_194;
	t_sample __m_slide_182;
	t_sample __m_slide_190;
	t_sample __m_slide_186;
	t_sample m_y_1;
	t_sample m_y_93;
	t_sample __m_slide_162;
	t_sample __m_slide_158;
	t_sample m_y_14;
	t_sample __m_slide_138;
	t_sample m_y_13;
	t_sample m_knob4_gain_135;
	t_sample m_knob3_res_133;
	t_sample m_sw_134;
	t_sample m_history_132;
	t_sample m_x_8;
	t_sample __m_slide_142;
	t_sample __m_slide_146;
	t_sample __m_slide_154;
	t_sample m_y_9;
	t_sample m_x_12;
	t_sample m_y_10;
	t_sample m_x_11;
	t_sample __m_slide_150;
	t_sample m_x_15;
	t_sample m_x_92;
	t_sample m_y_90;
	t_sample m_x_40;
	t_sample m_y_41;
	t_sample m_y_42;
	t_sample m_x_39;
	t_sample m_y_37;
	t_sample m_y_38;
	t_sample m_x_36;
	t_sample m_x_35;
	t_sample m_x_43;
	t_sample m_y_45;
	t_sample m_y_50;
	t_sample m_x_51;
	t_sample m_x_44;
	t_sample m_y_49;
	t_sample m_x_47;
	t_sample m_x_48;
	t_sample m_y_46;
	t_sample m_x_52;
	t_sample m_y_34;
	t_sample m_x_32;
	t_sample m_y_21;
	t_sample m_y_22;
	t_sample m_x_23;
	t_sample m_x_20;
	t_sample m_y_18;
	t_sample m_x_19;
	t_sample m_y_17;
	t_sample m_y_33;
	t_sample m_x_24;
	t_sample m_y_26;
	t_sample m_y_30;
	t_sample m_x_31;
	t_sample m_y_25;
	t_sample m_y_29;
	t_sample m_x_27;
	t_sample m_x_28;
	t_sample m_x_91;
	t_sample m_y_53;
	t_sample m_x_55;
	t_sample m_x_79;
	t_sample m_x_80;
	t_sample m_y_81;
	t_sample m_y_78;
	t_sample m_x_76;
	t_sample m_y_77;
	t_sample m_x_75;
	t_sample m_y_74;
	t_sample m_y_82;
	t_sample m_x_84;
	t_sample m_x_88;
	t_sample m_y_89;
	t_sample __m_slide_198;
	t_sample m_x_87;
	t_sample m_y_85;
	t_sample m_y_86;
	t_sample m_y_54;
	t_sample m_y_73;
	t_sample m_x_71;
	t_sample m_x_60;
	t_sample m_y_61;
	t_sample m_y_62;
	t_sample m_x_59;
	t_sample m_y_57;
	t_sample m_y_58;
	t_sample m_x_56;
	t_sample m_x_72;
	t_sample m_x_63;
	t_sample m_y_65;
	t_sample m_y_69;
	t_sample m_y_70;
	t_sample m_x_64;
	t_sample m_x_68;
	t_sample m_y_66;
	t_sample m_x_67;
	t_sample m_x_83;
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
		m_y_13 = ((int)0);
		m_y_14 = ((int)0);
		m_x_15 = ((int)0);
		m_x_16 = ((int)0);
		m_y_17 = ((int)0);
		m_y_18 = ((int)0);
		m_x_19 = ((int)0);
		m_x_20 = ((int)0);
		m_y_21 = ((int)0);
		m_y_22 = ((int)0);
		m_x_23 = ((int)0);
		m_x_24 = ((int)0);
		m_y_25 = ((int)0);
		m_y_26 = ((int)0);
		m_x_27 = ((int)0);
		m_x_28 = ((int)0);
		m_y_29 = ((int)0);
		m_y_30 = ((int)0);
		m_x_31 = ((int)0);
		m_x_32 = ((int)0);
		m_y_33 = ((int)0);
		m_y_34 = ((int)0);
		m_x_35 = ((int)0);
		m_x_36 = ((int)0);
		m_y_37 = ((int)0);
		m_y_38 = ((int)0);
		m_x_39 = ((int)0);
		m_x_40 = ((int)0);
		m_y_41 = ((int)0);
		m_y_42 = ((int)0);
		m_x_43 = ((int)0);
		m_x_44 = ((int)0);
		m_y_45 = ((int)0);
		m_y_46 = ((int)0);
		m_x_47 = ((int)0);
		m_x_48 = ((int)0);
		m_y_49 = ((int)0);
		m_y_50 = ((int)0);
		m_x_51 = ((int)0);
		m_x_52 = ((int)0);
		m_y_53 = ((int)0);
		m_y_54 = ((int)0);
		m_x_55 = ((int)0);
		m_x_56 = ((int)0);
		m_y_57 = ((int)0);
		m_y_58 = ((int)0);
		m_x_59 = ((int)0);
		m_x_60 = ((int)0);
		m_y_61 = ((int)0);
		m_y_62 = ((int)0);
		m_x_63 = ((int)0);
		m_x_64 = ((int)0);
		m_y_65 = ((int)0);
		m_y_66 = ((int)0);
		m_x_67 = ((int)0);
		m_x_68 = ((int)0);
		m_y_69 = ((int)0);
		m_y_70 = ((int)0);
		m_x_71 = ((int)0);
		m_x_72 = ((int)0);
		m_y_73 = ((int)0);
		m_y_74 = ((int)0);
		m_x_75 = ((int)0);
		m_x_76 = ((int)0);
		m_y_77 = ((int)0);
		m_y_78 = ((int)0);
		m_x_79 = ((int)0);
		m_x_80 = ((int)0);
		m_y_81 = ((int)0);
		m_y_82 = ((int)0);
		m_x_83 = ((int)0);
		m_x_84 = ((int)0);
		m_y_85 = ((int)0);
		m_y_86 = ((int)0);
		m_x_87 = ((int)0);
		m_x_88 = ((int)0);
		m_y_89 = ((int)0);
		m_y_90 = ((int)0);
		m_x_91 = ((int)0);
		m_x_92 = ((int)0);
		m_y_93 = ((int)0);
		m_y_94 = ((int)0);
		m_x_95 = ((int)0);
		m_x_96 = ((int)0);
		m_y_97 = ((int)0);
		m_y_98 = ((int)0);
		m_x_99 = ((int)0);
		m_x_100 = ((int)0);
		m_y_101 = ((int)0);
		m_y_102 = ((int)0);
		m_x_103 = ((int)0);
		m_x_104 = ((int)0);
		m_y_105 = ((int)0);
		m_y_106 = ((int)0);
		m_x_107 = ((int)0);
		m_x_108 = ((int)0);
		m_y_109 = ((int)0);
		m_y_110 = ((int)0);
		m_x_111 = ((int)0);
		m_x_112 = ((int)0);
		m_y_113 = ((int)0);
		m_y_114 = ((int)0);
		m_x_115 = ((int)0);
		m_x_116 = ((int)0);
		m_y_117 = ((int)0);
		m_y_118 = ((int)0);
		m_x_119 = ((int)0);
		m_x_120 = ((int)0);
		m_y_121 = ((int)0);
		m_y_122 = ((int)0);
		m_x_123 = ((int)0);
		m_x_124 = ((int)0);
		m_y_125 = ((int)0);
		m_y_126 = ((int)0);
		m_x_127 = ((int)0);
		m_x_128 = ((int)0);
		m_history_129 = ((int)0);
		m_history_130 = ((int)0);
		m_history_131 = ((int)0);
		m_history_132 = ((int)0);
		m_knob3_res_133 = 15;
		m_sw_134 = ((int)0);
		m_knob4_gain_135 = 5;
		__m_sah_136.reset(0);
		__m_slide_138 = 0;
		__m_dcblock_141.reset();
		__m_slide_142 = 0;
		__m_dcblock_145.reset();
		__m_slide_146 = 0;
		__m_dcblock_149.reset();
		__m_slide_150 = 0;
		__m_dcblock_153.reset();
		__m_slide_154 = 0;
		__m_dcblock_157.reset();
		__m_slide_158 = 0;
		__m_dcblock_161.reset();
		__m_slide_162 = 0;
		__m_dcblock_165.reset();
		__m_slide_166 = 0;
		__m_dcblock_169.reset();
		__m_slide_170 = 0;
		__m_dcblock_173.reset();
		__m_slide_174 = 0;
		__m_dcblock_177.reset();
		__m_slide_178 = 0;
		__m_dcblock_181.reset();
		__m_slide_182 = 0;
		__m_dcblock_185.reset();
		__m_slide_186 = 0;
		__m_dcblock_189.reset();
		__m_slide_190 = 0;
		__m_dcblock_193.reset();
		__m_slide_194 = 0;
		__m_dcblock_197.reset();
		__m_slide_198 = 0;
		__m_dcblock_201.reset();
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		t_sample * __out6 = __outs[5];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample mstosamps_3391 = (((int)2) * (samplerate * 0.001));
		t_sample mstosamps_3481 = (((int)20) * (samplerate * 0.001));
		t_sample twopi_over_sr = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3333 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_139 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_140 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3507 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3308 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_143 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_144 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3525 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3283 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_147 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_148 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3532 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3258 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_151 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_152 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3550 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3233 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_155 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_156 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3568 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3208 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_159 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_160 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3595 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3183 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_163 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_164 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3615 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3158 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_167 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_168 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3632 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3133 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_171 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_172 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3639 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3108 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_175 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_176 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3657 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3083 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_179 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_180 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3675 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3059 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_183 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_184 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3703 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3033 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_187 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_188 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3710 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3452 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_191 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_192 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3736 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3383 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_195 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_196 = (1 / maximum(1, abs(mstosamps_3481)));
		t_sample twopi_over_sr_3753 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3358 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_199 = (1 / maximum(1, abs(mstosamps_3391)));
		t_sample idown_200 = (1 / maximum(1, abs(mstosamps_3481)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_3488 = __m_sah_136(m_history_132, m_sw_134, ((int)0));
			t_sample gen_3490 = sah_3488;
			t_sample rsub_3486 = (((int)1) - sah_3488);
			t_sample history_3487_next_3489 = fixdenorm(rsub_3486);
			t_sample out3 = gen_3490;
			t_sample add_3491 = (gen_3490 + ((int)1));
			t_sample choice_137 = int(add_3491);
			t_sample gate_3483 = (((choice_137 >= 1) && (choice_137 < 2)) ? in1 : 0);
			t_sample gate_3484 = ((choice_137 >= 2) ? in1 : 0);
			t_sample mix_3776 = (m_history_131 + (((t_sample)0.003926980723806) * (m_knob3_res_133 - m_history_131)));
			t_sample mix_3471 = mix_3776;
			t_sample mix_3777 = (m_history_130 + (((t_sample)0.003926980723806) * (mix_3471 - m_history_130)));
			t_sample mix_3469 = mix_3777;
			t_sample mix_3778 = (m_history_129 + (((t_sample)0.003926980723806) * (mix_3469 - m_history_129)));
			t_sample mix_3467 = mix_3778;
			t_sample gen_3479 = mix_3467;
			t_sample history_3473_next_3476 = fixdenorm(mix_3471);
			t_sample history_3470_next_3477 = fixdenorm(mix_3469);
			t_sample history_3468_next_3478 = fixdenorm(mix_3467);
			t_sample x = gate_3484;
			t_sample q = gen_3479;
			t_sample bw = safediv(((t_sample)284.5), q);
			t_sample r = exp(((-bw) * twopi_over_sr));
			t_sample c1 = ((((int)2) * r) * cos((((t_sample)284.5) * twopi_over_sr)));
			t_sample c2 = ((-r) * r);
			t_sample y = ((((((int)1) - r) * (x - (r * m_x_127))) + (c1 * m_y_126)) + (c2 * m_y_125));
			m_y_125 = m_y_126;
			m_y_126 = y;
			m_x_127 = m_x_128;
			m_x_128 = x;
			t_sample x_3329 = in2;
			t_sample q_3322 = gen_3479;
			t_sample bw_3330 = safediv(((t_sample)284.5), q_3322);
			t_sample r_3323 = exp(((-bw_3330) * twopi_over_sr_3333));
			t_sample c_3332 = ((((int)2) * r_3323) * cos((((t_sample)284.5) * twopi_over_sr_3333)));
			t_sample c_3335 = ((-r_3323) * r_3323);
			t_sample y_3334 = ((((((int)1) - r_3323) * (x_3329 - (r_3323 * m_x_123))) + (c_3332 * m_y_122)) + (c_3335 * m_y_121));
			m_y_121 = m_y_122;
			m_y_122 = y_3334;
			m_x_123 = m_x_124;
			m_x_124 = x_3329;
			t_sample abs_3321 = fabs(y_3334);
			__m_slide_138 = fixdenorm((__m_slide_138 + (((abs_3321 > __m_slide_138) ? iup_139 : idown_140) * (abs_3321 - __m_slide_138))));
			t_sample slide_3320 = __m_slide_138;
			t_sample mul_3317 = (y * slide_3320);
			t_sample dcblock_3316 = __m_dcblock_141(mul_3317);
			t_sample x_3504 = gate_3484;
			t_sample q_3496 = gen_3479;
			t_sample bw_3499 = safediv(((t_sample)358.5), q_3496);
			t_sample r_3506 = exp(((-bw_3499) * twopi_over_sr_3507));
			t_sample c_3501 = ((((int)2) * r_3506) * cos((((t_sample)358.5) * twopi_over_sr_3507)));
			t_sample c_3495 = ((-r_3506) * r_3506);
			t_sample y_3497 = ((((((int)1) - r_3506) * (x_3504 - (r_3506 * m_x_119))) + (c_3501 * m_y_118)) + (c_3495 * m_y_117));
			m_y_117 = m_y_118;
			m_y_118 = y_3497;
			m_x_119 = m_x_120;
			m_x_120 = x_3504;
			t_sample x_3304 = in2;
			t_sample q_3297 = gen_3479;
			t_sample bw_3305 = safediv(((t_sample)358.5), q_3297);
			t_sample r_3298 = exp(((-bw_3305) * twopi_over_sr_3308));
			t_sample c_3307 = ((((int)2) * r_3298) * cos((((t_sample)358.5) * twopi_over_sr_3308)));
			t_sample c_3310 = ((-r_3298) * r_3298);
			t_sample y_3309 = ((((((int)1) - r_3298) * (x_3304 - (r_3298 * m_x_115))) + (c_3307 * m_y_114)) + (c_3310 * m_y_113));
			m_y_113 = m_y_114;
			m_y_114 = y_3309;
			m_x_115 = m_x_116;
			m_x_116 = x_3304;
			t_sample abs_3296 = fabs(y_3309);
			__m_slide_142 = fixdenorm((__m_slide_142 + (((abs_3296 > __m_slide_142) ? iup_143 : idown_144) * (abs_3296 - __m_slide_142))));
			t_sample slide_3295 = __m_slide_142;
			t_sample mul_3292 = (y_3497 * slide_3295);
			t_sample dcblock_3291 = __m_dcblock_145(mul_3292);
			t_sample x_3517 = gate_3484;
			t_sample q_3515 = gen_3479;
			t_sample bw_3518 = safediv(((int)452), q_3515);
			t_sample r_3516 = exp(((-bw_3518) * twopi_over_sr_3525));
			t_sample c_3520 = ((((int)2) * r_3516) * cos((((int)452) * twopi_over_sr_3525)));
			t_sample c_3514 = ((-r_3516) * r_3516);
			t_sample y_3521 = ((((((int)1) - r_3516) * (x_3517 - (r_3516 * m_x_111))) + (c_3520 * m_y_110)) + (c_3514 * m_y_109));
			m_y_109 = m_y_110;
			m_y_110 = y_3521;
			m_x_111 = m_x_112;
			m_x_112 = x_3517;
			t_sample x_3279 = in2;
			t_sample q_3272 = gen_3479;
			t_sample bw_3280 = safediv(((int)452), q_3272);
			t_sample r_3273 = exp(((-bw_3280) * twopi_over_sr_3283));
			t_sample c_3282 = ((((int)2) * r_3273) * cos((((int)452) * twopi_over_sr_3283)));
			t_sample c_3285 = ((-r_3273) * r_3273);
			t_sample y_3284 = ((((((int)1) - r_3273) * (x_3279 - (r_3273 * m_x_107))) + (c_3282 * m_y_106)) + (c_3285 * m_y_105));
			m_y_105 = m_y_106;
			m_y_106 = y_3284;
			m_x_107 = m_x_108;
			m_x_108 = x_3279;
			t_sample abs_3271 = fabs(y_3284);
			__m_slide_146 = fixdenorm((__m_slide_146 + (((abs_3271 > __m_slide_146) ? iup_147 : idown_148) * (abs_3271 - __m_slide_146))));
			t_sample slide_3270 = __m_slide_146;
			t_sample mul_3267 = (y_3521 * slide_3270);
			t_sample dcblock_3266 = __m_dcblock_149(mul_3267);
			t_sample x_3538 = gate_3484;
			t_sample q_3535 = gen_3479;
			t_sample bw_3539 = safediv(((t_sample)569.5), q_3535);
			t_sample r_3536 = exp(((-bw_3539) * twopi_over_sr_3532));
			t_sample c_3541 = ((((int)2) * r_3536) * cos((((t_sample)569.5) * twopi_over_sr_3532)));
			t_sample c_3530 = ((-r_3536) * r_3536);
			t_sample y_3537 = ((((((int)1) - r_3536) * (x_3538 - (r_3536 * m_x_103))) + (c_3541 * m_y_102)) + (c_3530 * m_y_101));
			m_y_101 = m_y_102;
			m_y_102 = y_3537;
			m_x_103 = m_x_104;
			m_x_104 = x_3538;
			t_sample x_3254 = in2;
			t_sample q_3247 = gen_3479;
			t_sample bw_3255 = safediv(((t_sample)569.5), q_3247);
			t_sample r_3248 = exp(((-bw_3255) * twopi_over_sr_3258));
			t_sample c_3257 = ((((int)2) * r_3248) * cos((((t_sample)569.5) * twopi_over_sr_3258)));
			t_sample c_3260 = ((-r_3248) * r_3248);
			t_sample y_3259 = ((((((int)1) - r_3248) * (x_3254 - (r_3248 * m_x_99))) + (c_3257 * m_y_98)) + (c_3260 * m_y_97));
			m_y_97 = m_y_98;
			m_y_98 = y_3259;
			m_x_99 = m_x_100;
			m_x_100 = x_3254;
			t_sample abs_3246 = fabs(y_3259);
			__m_slide_150 = fixdenorm((__m_slide_150 + (((abs_3246 > __m_slide_150) ? iup_151 : idown_152) * (abs_3246 - __m_slide_150))));
			t_sample slide_3245 = __m_slide_150;
			t_sample mul_3242 = (y_3537 * slide_3245);
			t_sample dcblock_3241 = __m_dcblock_153(mul_3242);
			t_sample x_3555 = gate_3484;
			t_sample q_3553 = gen_3479;
			t_sample bw_3556 = safediv(((t_sample)717.5), q_3553);
			t_sample r_3554 = exp(((-bw_3556) * twopi_over_sr_3550));
			t_sample c_3558 = ((((int)2) * r_3554) * cos((((t_sample)717.5) * twopi_over_sr_3550)));
			t_sample c_3548 = ((-r_3554) * r_3554);
			t_sample y_3559 = ((((((int)1) - r_3554) * (x_3555 - (r_3554 * m_x_95))) + (c_3558 * m_y_94)) + (c_3548 * m_y_93));
			m_y_93 = m_y_94;
			m_y_94 = y_3559;
			m_x_95 = m_x_96;
			m_x_96 = x_3555;
			t_sample x_3229 = in2;
			t_sample q_3222 = gen_3479;
			t_sample bw_3230 = safediv(((t_sample)717.5), q_3222);
			t_sample r_3223 = exp(((-bw_3230) * twopi_over_sr_3233));
			t_sample c_3232 = ((((int)2) * r_3223) * cos((((t_sample)717.5) * twopi_over_sr_3233)));
			t_sample c_3235 = ((-r_3223) * r_3223);
			t_sample y_3234 = ((((((int)1) - r_3223) * (x_3229 - (r_3223 * m_x_91))) + (c_3232 * m_y_90)) + (c_3235 * m_y_89));
			m_y_89 = m_y_90;
			m_y_90 = y_3234;
			m_x_91 = m_x_92;
			m_x_92 = x_3229;
			t_sample abs_3221 = fabs(y_3234);
			__m_slide_154 = fixdenorm((__m_slide_154 + (((abs_3221 > __m_slide_154) ? iup_155 : idown_156) * (abs_3221 - __m_slide_154))));
			t_sample slide_3220 = __m_slide_154;
			t_sample mul_3217 = (y_3559 * slide_3220);
			t_sample dcblock_3216 = __m_dcblock_157(mul_3217);
			t_sample x_3573 = gate_3484;
			t_sample q_3571 = gen_3479;
			t_sample bw_3574 = safediv(((int)904), q_3571);
			t_sample r_3579 = exp(((-bw_3574) * twopi_over_sr_3568));
			t_sample c_3576 = ((((int)2) * r_3579) * cos((((int)904) * twopi_over_sr_3568)));
			t_sample c_3566 = ((-r_3579) * r_3579);
			t_sample y_3572 = ((((((int)1) - r_3579) * (x_3573 - (r_3579 * m_x_87))) + (c_3576 * m_y_86)) + (c_3566 * m_y_85));
			m_y_85 = m_y_86;
			m_y_86 = y_3572;
			m_x_87 = m_x_88;
			m_x_88 = x_3573;
			t_sample x_3204 = in2;
			t_sample q_3197 = gen_3479;
			t_sample bw_3205 = safediv(((int)904), q_3197);
			t_sample r_3198 = exp(((-bw_3205) * twopi_over_sr_3208));
			t_sample c_3207 = ((((int)2) * r_3198) * cos((((int)904) * twopi_over_sr_3208)));
			t_sample c_3210 = ((-r_3198) * r_3198);
			t_sample y_3209 = ((((((int)1) - r_3198) * (x_3204 - (r_3198 * m_x_83))) + (c_3207 * m_y_82)) + (c_3210 * m_y_81));
			m_y_81 = m_y_82;
			m_y_82 = y_3209;
			m_x_83 = m_x_84;
			m_x_84 = x_3204;
			t_sample abs_3196 = fabs(y_3209);
			__m_slide_158 = fixdenorm((__m_slide_158 + (((abs_3196 > __m_slide_158) ? iup_159 : idown_160) * (abs_3196 - __m_slide_158))));
			t_sample slide_3195 = __m_slide_158;
			t_sample mul_3192 = (y_3572 * slide_3195);
			t_sample dcblock_3191 = __m_dcblock_161(mul_3192);
			t_sample x_3588 = gate_3484;
			t_sample q_3587 = gen_3479;
			t_sample bw_3591 = safediv(((int)1139), q_3587);
			t_sample r_3593 = exp(((-bw_3591) * twopi_over_sr_3595));
			t_sample c_3589 = ((((int)2) * r_3593) * cos((((int)1139) * twopi_over_sr_3595)));
			t_sample c_3584 = ((-r_3593) * r_3593);
			t_sample y_3597 = ((((((int)1) - r_3593) * (x_3588 - (r_3593 * m_x_79))) + (c_3589 * m_y_78)) + (c_3584 * m_y_77));
			m_y_77 = m_y_78;
			m_y_78 = y_3597;
			m_x_79 = m_x_80;
			m_x_80 = x_3588;
			t_sample x_3179 = in2;
			t_sample q_3172 = gen_3479;
			t_sample bw_3180 = safediv(((int)1139), q_3172);
			t_sample r_3173 = exp(((-bw_3180) * twopi_over_sr_3183));
			t_sample c_3182 = ((((int)2) * r_3173) * cos((((int)1139) * twopi_over_sr_3183)));
			t_sample c_3185 = ((-r_3173) * r_3173);
			t_sample y_3184 = ((((((int)1) - r_3173) * (x_3179 - (r_3173 * m_x_75))) + (c_3182 * m_y_74)) + (c_3185 * m_y_73));
			m_y_73 = m_y_74;
			m_y_74 = y_3184;
			m_x_75 = m_x_76;
			m_x_76 = x_3179;
			t_sample abs_3171 = fabs(y_3184);
			__m_slide_162 = fixdenorm((__m_slide_162 + (((abs_3171 > __m_slide_162) ? iup_163 : idown_164) * (abs_3171 - __m_slide_162))));
			t_sample slide_3170 = __m_slide_162;
			t_sample mul_3167 = (y_3597 * slide_3170);
			t_sample dcblock_3166 = __m_dcblock_165(mul_3167);
			t_sample x_3607 = gate_3484;
			t_sample q_3611 = gen_3479;
			t_sample bw_3610 = safediv(((int)1435), q_3611);
			t_sample r_3605 = exp(((-bw_3610) * twopi_over_sr_3615));
			t_sample c_3608 = ((((int)2) * r_3605) * cos((((int)1435) * twopi_over_sr_3615)));
			t_sample c_3602 = ((-r_3605) * r_3605);
			t_sample y_3606 = ((((((int)1) - r_3605) * (x_3607 - (r_3605 * m_x_71))) + (c_3608 * m_y_70)) + (c_3602 * m_y_69));
			m_y_69 = m_y_70;
			m_y_70 = y_3606;
			m_x_71 = m_x_72;
			m_x_72 = x_3607;
			t_sample x_3154 = in2;
			t_sample q_3147 = gen_3479;
			t_sample bw_3155 = safediv(((int)1435), q_3147);
			t_sample r_3148 = exp(((-bw_3155) * twopi_over_sr_3158));
			t_sample c_3157 = ((((int)2) * r_3148) * cos((((int)1435) * twopi_over_sr_3158)));
			t_sample c_3160 = ((-r_3148) * r_3148);
			t_sample y_3159 = ((((((int)1) - r_3148) * (x_3154 - (r_3148 * m_x_67))) + (c_3157 * m_y_66)) + (c_3160 * m_y_65));
			m_y_65 = m_y_66;
			m_y_66 = y_3159;
			m_x_67 = m_x_68;
			m_x_68 = x_3154;
			t_sample abs_3146 = fabs(y_3159);
			__m_slide_166 = fixdenorm((__m_slide_166 + (((abs_3146 > __m_slide_166) ? iup_167 : idown_168) * (abs_3146 - __m_slide_166))));
			t_sample slide_3145 = __m_slide_166;
			t_sample mul_3142 = (y_3606 * slide_3145);
			t_sample dcblock_3141 = __m_dcblock_169(mul_3142);
			t_sample x_3625 = gate_3484;
			t_sample q_3633 = gen_3479;
			t_sample bw_3629 = safediv(((int)1808), q_3633);
			t_sample r_3623 = exp(((-bw_3629) * twopi_over_sr_3632));
			t_sample c_3626 = ((((int)2) * r_3623) * cos((((int)1808) * twopi_over_sr_3632)));
			t_sample c_3620 = ((-r_3623) * r_3623);
			t_sample y_3624 = ((((((int)1) - r_3623) * (x_3625 - (r_3623 * m_x_63))) + (c_3626 * m_y_62)) + (c_3620 * m_y_61));
			m_y_61 = m_y_62;
			m_y_62 = y_3624;
			m_x_63 = m_x_64;
			m_x_64 = x_3625;
			t_sample x_3129 = in2;
			t_sample q_3122 = gen_3479;
			t_sample bw_3130 = safediv(((int)1808), q_3122);
			t_sample r_3123 = exp(((-bw_3130) * twopi_over_sr_3133));
			t_sample c_3132 = ((((int)2) * r_3123) * cos((((int)1808) * twopi_over_sr_3133)));
			t_sample c_3135 = ((-r_3123) * r_3123);
			t_sample y_3134 = ((((((int)1) - r_3123) * (x_3129 - (r_3123 * m_x_59))) + (c_3132 * m_y_58)) + (c_3135 * m_y_57));
			m_y_57 = m_y_58;
			m_y_58 = y_3134;
			m_x_59 = m_x_60;
			m_x_60 = x_3129;
			t_sample abs_3121 = fabs(y_3134);
			__m_slide_170 = fixdenorm((__m_slide_170 + (((abs_3121 > __m_slide_170) ? iup_171 : idown_172) * (abs_3121 - __m_slide_170))));
			t_sample slide_3120 = __m_slide_170;
			t_sample mul_3117 = (y_3624 * slide_3120);
			t_sample dcblock_3116 = __m_dcblock_173(mul_3117);
			t_sample x_3644 = gate_3484;
			t_sample q_3651 = gen_3479;
			t_sample bw_3648 = safediv(((int)2260), q_3651);
			t_sample r_3642 = exp(((-bw_3648) * twopi_over_sr_3639));
			t_sample c_3645 = ((((int)2) * r_3642) * cos((((int)2260) * twopi_over_sr_3639)));
			t_sample c_3638 = ((-r_3642) * r_3642);
			t_sample y_3643 = ((((((int)1) - r_3642) * (x_3644 - (r_3642 * m_x_55))) + (c_3645 * m_y_54)) + (c_3638 * m_y_53));
			m_y_53 = m_y_54;
			m_y_54 = y_3643;
			m_x_55 = m_x_56;
			m_x_56 = x_3644;
			t_sample x_3104 = in2;
			t_sample q_3097 = gen_3479;
			t_sample bw_3105 = safediv(((int)2260), q_3097);
			t_sample r_3098 = exp(((-bw_3105) * twopi_over_sr_3108));
			t_sample c_3107 = ((((int)2) * r_3098) * cos((((int)2260) * twopi_over_sr_3108)));
			t_sample c_3110 = ((-r_3098) * r_3098);
			t_sample y_3109 = ((((((int)1) - r_3098) * (x_3104 - (r_3098 * m_x_51))) + (c_3107 * m_y_50)) + (c_3110 * m_y_49));
			m_y_49 = m_y_50;
			m_y_50 = y_3109;
			m_x_51 = m_x_52;
			m_x_52 = x_3104;
			t_sample abs_3096 = fabs(y_3109);
			__m_slide_174 = fixdenorm((__m_slide_174 + (((abs_3096 > __m_slide_174) ? iup_175 : idown_176) * (abs_3096 - __m_slide_174))));
			t_sample slide_3095 = __m_slide_174;
			t_sample mul_3092 = (y_3643 * slide_3095);
			t_sample dcblock_3091 = __m_dcblock_177(mul_3092);
			t_sample x_3662 = gate_3484;
			t_sample q_3659 = gen_3479;
			t_sample bw_3668 = safediv(((int)2852), q_3659);
			t_sample r_3660 = exp(((-bw_3668) * twopi_over_sr_3657));
			t_sample c_3663 = ((((int)2) * r_3660) * cos((((int)2852) * twopi_over_sr_3657)));
			t_sample c_3656 = ((-r_3660) * r_3660);
			t_sample y_3661 = ((((((int)1) - r_3660) * (x_3662 - (r_3660 * m_x_47))) + (c_3663 * m_y_46)) + (c_3656 * m_y_45));
			m_y_45 = m_y_46;
			m_y_46 = y_3661;
			m_x_47 = m_x_48;
			m_x_48 = x_3662;
			t_sample x_3079 = in2;
			t_sample q_3072 = gen_3479;
			t_sample bw_3080 = safediv(((int)2852), q_3072);
			t_sample r_3073 = exp(((-bw_3080) * twopi_over_sr_3083));
			t_sample c_3082 = ((((int)2) * r_3073) * cos((((int)2852) * twopi_over_sr_3083)));
			t_sample c_3085 = ((-r_3073) * r_3073);
			t_sample y_3084 = ((((((int)1) - r_3073) * (x_3079 - (r_3073 * m_x_43))) + (c_3082 * m_y_42)) + (c_3085 * m_y_41));
			m_y_41 = m_y_42;
			m_y_42 = y_3084;
			m_x_43 = m_x_44;
			m_x_44 = x_3079;
			t_sample abs_3071 = fabs(y_3084);
			__m_slide_178 = fixdenorm((__m_slide_178 + (((abs_3071 > __m_slide_178) ? iup_179 : idown_180) * (abs_3071 - __m_slide_178))));
			t_sample slide_3070 = __m_slide_178;
			t_sample mul_3067 = (y_3661 * slide_3070);
			t_sample dcblock_3066 = __m_dcblock_181(mul_3067);
			t_sample x_3680 = gate_3484;
			t_sample q_3677 = gen_3479;
			t_sample bw_3686 = safediv(((int)3616), q_3677);
			t_sample r_3678 = exp(((-bw_3686) * twopi_over_sr_3675));
			t_sample c_3682 = ((((int)2) * r_3678) * cos((((int)3616) * twopi_over_sr_3675)));
			t_sample c_3674 = ((-r_3678) * r_3678);
			t_sample y_3679 = ((((((int)1) - r_3678) * (x_3680 - (r_3678 * m_x_39))) + (c_3682 * m_y_38)) + (c_3674 * m_y_37));
			m_y_37 = m_y_38;
			m_y_38 = y_3679;
			m_x_39 = m_x_40;
			m_x_40 = x_3680;
			t_sample x_3055 = in2;
			t_sample q_3047 = gen_3479;
			t_sample bw_3056 = safediv(((int)3616), q_3047);
			t_sample r_3049 = exp(((-bw_3056) * twopi_over_sr_3059));
			t_sample c_3058 = ((((int)2) * r_3049) * cos((((int)3616) * twopi_over_sr_3059)));
			t_sample c_3060 = ((-r_3049) * r_3049);
			t_sample y_3048 = ((((((int)1) - r_3049) * (x_3055 - (r_3049 * m_x_35))) + (c_3058 * m_y_34)) + (c_3060 * m_y_33));
			m_y_33 = m_y_34;
			m_y_34 = y_3048;
			m_x_35 = m_x_36;
			m_x_36 = x_3055;
			t_sample abs_3046 = fabs(y_3048);
			__m_slide_182 = fixdenorm((__m_slide_182 + (((abs_3046 > __m_slide_182) ? iup_183 : idown_184) * (abs_3046 - __m_slide_182))));
			t_sample slide_3045 = __m_slide_182;
			t_sample mul_3042 = (y_3679 * slide_3045);
			t_sample dcblock_3041 = __m_dcblock_185(mul_3042);
			t_sample x_3698 = gate_3484;
			t_sample q_3695 = gen_3479;
			t_sample bw_3701 = safediv(((int)4556), q_3695);
			t_sample r_3696 = exp(((-bw_3701) * twopi_over_sr_3703));
			t_sample c_3699 = ((((int)2) * r_3696) * cos((((int)4556) * twopi_over_sr_3703)));
			t_sample c_3692 = ((-r_3696) * r_3696);
			t_sample y_3697 = ((((((int)1) - r_3696) * (x_3698 - (r_3696 * m_x_31))) + (c_3699 * m_y_30)) + (c_3692 * m_y_29));
			m_y_29 = m_y_30;
			m_y_30 = y_3697;
			m_x_31 = m_x_32;
			m_x_32 = x_3698;
			t_sample x_3030 = in2;
			t_sample q_3022 = gen_3479;
			t_sample bw_3031 = safediv(((int)4556), q_3022);
			t_sample r_3024 = exp(((-bw_3031) * twopi_over_sr_3033));
			t_sample c_3032 = ((((int)2) * r_3024) * cos((((int)4556) * twopi_over_sr_3033)));
			t_sample c_3035 = ((-r_3024) * r_3024);
			t_sample y_3034 = ((((((int)1) - r_3024) * (x_3030 - (r_3024 * m_x_27))) + (c_3032 * m_y_26)) + (c_3035 * m_y_25));
			m_y_25 = m_y_26;
			m_y_26 = y_3034;
			m_x_27 = m_x_28;
			m_x_28 = x_3030;
			t_sample abs_3021 = fabs(y_3034);
			__m_slide_186 = fixdenorm((__m_slide_186 + (((abs_3021 > __m_slide_186) ? iup_187 : idown_188) * (abs_3021 - __m_slide_186))));
			t_sample slide_3020 = __m_slide_186;
			t_sample mul_3015 = (y_3697 * slide_3020);
			t_sample dcblock_3014 = __m_dcblock_189(mul_3015);
			t_sample x_3721 = gate_3484;
			t_sample q_3717 = gen_3479;
			t_sample bw_3719 = safediv(((t_sample)104.5), q_3717);
			t_sample r_3718 = exp(((-bw_3719) * twopi_over_sr_3710));
			t_sample c_3722 = ((((int)2) * r_3718) * cos((((t_sample)104.5) * twopi_over_sr_3710)));
			t_sample c_3712 = ((-r_3718) * r_3718);
			t_sample y_3720 = ((((((int)1) - r_3718) * (x_3721 - (r_3718 * m_x_23))) + (c_3722 * m_y_22)) + (c_3712 * m_y_21));
			m_y_21 = m_y_22;
			m_y_22 = y_3720;
			m_x_23 = m_x_24;
			m_x_24 = x_3721;
			t_sample x_3448 = in2;
			t_sample q_3441 = gen_3479;
			t_sample bw_3449 = safediv(((t_sample)104.5), q_3441);
			t_sample r_3442 = exp(((-bw_3449) * twopi_over_sr_3452));
			t_sample c_3451 = ((((int)2) * r_3442) * cos((((t_sample)104.5) * twopi_over_sr_3452)));
			t_sample c_3454 = ((-r_3442) * r_3442);
			t_sample y_3453 = ((((((int)1) - r_3442) * (x_3448 - (r_3442 * m_x_19))) + (c_3451 * m_y_18)) + (c_3454 * m_y_17));
			m_y_17 = m_y_18;
			m_y_18 = y_3453;
			m_x_19 = m_x_20;
			m_x_20 = x_3448;
			t_sample abs_3440 = fabs(y_3453);
			__m_slide_190 = fixdenorm((__m_slide_190 + (((abs_3440 > __m_slide_190) ? iup_191 : idown_192) * (abs_3440 - __m_slide_190))));
			t_sample slide_3439 = __m_slide_190;
			t_sample mul_3436 = (y_3720 * slide_3439);
			t_sample dcblock_3435 = __m_dcblock_193(mul_3436);
			t_sample x_3735 = gate_3484;
			t_sample q_3737 = gen_3479;
			t_sample bw_3739 = safediv(((t_sample)179.5), q_3737);
			t_sample r_3728 = exp(((-bw_3739) * twopi_over_sr_3736));
			t_sample c_3740 = ((((int)2) * r_3728) * cos((((t_sample)179.5) * twopi_over_sr_3736)));
			t_sample c_3730 = ((-r_3728) * r_3728);
			t_sample y_3738 = ((((((int)1) - r_3728) * (x_3735 - (r_3728 * m_x_15))) + (c_3740 * m_y_14)) + (c_3730 * m_y_13));
			m_y_13 = m_y_14;
			m_y_14 = y_3738;
			m_x_15 = m_x_16;
			m_x_16 = x_3735;
			t_sample x_3380 = in2;
			t_sample q_3372 = gen_3479;
			t_sample bw_3381 = safediv(((t_sample)179.5), q_3372);
			t_sample r_3374 = exp(((-bw_3381) * twopi_over_sr_3383));
			t_sample c_3382 = ((((int)2) * r_3374) * cos((((t_sample)179.5) * twopi_over_sr_3383)));
			t_sample c_3385 = ((-r_3374) * r_3374);
			t_sample y_3384 = ((((((int)1) - r_3374) * (x_3380 - (r_3374 * m_x_11))) + (c_3382 * m_y_10)) + (c_3385 * m_y_9));
			m_y_9 = m_y_10;
			m_y_10 = y_3384;
			m_x_11 = m_x_12;
			m_x_12 = x_3380;
			t_sample abs_3371 = fabs(y_3384);
			__m_slide_194 = fixdenorm((__m_slide_194 + (((abs_3371 > __m_slide_194) ? iup_195 : idown_196) * (abs_3371 - __m_slide_194))));
			t_sample slide_3370 = __m_slide_194;
			t_sample mul_3367 = (y_3738 * slide_3370);
			t_sample dcblock_3366 = __m_dcblock_197(mul_3367);
			t_sample x_3756 = gate_3484;
			t_sample q_3754 = gen_3479;
			t_sample bw_3757 = safediv(((int)226), q_3754);
			t_sample r_3746 = exp(((-bw_3757) * twopi_over_sr_3753));
			t_sample c_3758 = ((((int)2) * r_3746) * cos((((int)226) * twopi_over_sr_3753)));
			t_sample c_3748 = ((-r_3746) * r_3746);
			t_sample y_3755 = ((((((int)1) - r_3746) * (x_3756 - (r_3746 * m_x_7))) + (c_3758 * m_y_6)) + (c_3748 * m_y_5));
			m_y_5 = m_y_6;
			m_y_6 = y_3755;
			m_x_7 = m_x_8;
			m_x_8 = x_3756;
			t_sample x_3354 = in2;
			t_sample q_3347 = gen_3479;
			t_sample bw_3355 = safediv(((int)226), q_3347);
			t_sample r_3348 = exp(((-bw_3355) * twopi_over_sr_3358));
			t_sample c_3357 = ((((int)2) * r_3348) * cos((((int)226) * twopi_over_sr_3358)));
			t_sample c_3360 = ((-r_3348) * r_3348);
			t_sample y_3359 = ((((((int)1) - r_3348) * (x_3354 - (r_3348 * m_x_3))) + (c_3357 * m_y_2)) + (c_3360 * m_y_1));
			m_y_1 = m_y_2;
			m_y_2 = y_3359;
			m_x_3 = m_x_4;
			m_x_4 = x_3354;
			t_sample abs_3346 = fabs(y_3359);
			__m_slide_198 = fixdenorm((__m_slide_198 + (((abs_3346 > __m_slide_198) ? iup_199 : idown_200) * (abs_3346 - __m_slide_198))));
			t_sample slide_3345 = __m_slide_198;
			t_sample mul_3342 = (y_3755 * slide_3345);
			t_sample dcblock_3341 = __m_dcblock_201(mul_3342);
			t_sample mul_3480 = ((((((((((((((((dcblock_3341 + dcblock_3366) + dcblock_3435) + dcblock_3014) + dcblock_3041) + dcblock_3066) + dcblock_3091) + dcblock_3116) + dcblock_3141) + dcblock_3166) + dcblock_3191) + dcblock_3216) + dcblock_3241) + dcblock_3266) + dcblock_3291) + dcblock_3316) * m_knob4_gain_135);
			t_sample add_3493 = (mul_3480 + gate_3483);
			t_sample out1 = add_3493;
			t_sample add_3492 = (mul_3480 + gate_3483);
			t_sample out2 = add_3492;
			m_history_132 = history_3487_next_3489;
			m_history_131 = history_3473_next_3476;
			m_history_129 = history_3468_next_3478;
			m_history_130 = history_3470_next_3477;
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
	inline void set_knob3_res(t_param _value) {
		m_knob3_res_133 = (_value < 15 ? 15 : (_value > 50 ? 50 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_134 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_gain(t_param _value) {
		m_knob4_gain_135 = (_value < 1 ? 1 : (_value > 20 ? 20 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 6;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 3; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
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
		case 0: self->set_knob3_res(value); break;
		case 1: self->set_knob4_gain(value); break;
		case 2: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_res_133; break;
		case 1: *value = self->m_knob4_gain_135; break;
		case 2: *value = self->m_sw_134; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(3 * sizeof(ParamInfo));
	self->__commonstate.numparams = 3;
	// initialize parameter 0 ("m_knob3_res_133")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_res_133;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 15;
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_gain_135")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_gain";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_gain_135;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 20;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_sw_134")
	pi = self->__commonstate.params + 2;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_134;
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


} // Vocoder::
