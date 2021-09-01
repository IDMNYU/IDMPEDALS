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
	DCBlock __m_dcblock_222;
	DCBlock __m_dcblock_167;
	DCBlock __m_dcblock_172;
	DCBlock __m_dcblock_177;
	DCBlock __m_dcblock_162;
	DCBlock __m_dcblock_152;
	DCBlock __m_dcblock_157;
	DCBlock __m_dcblock_147;
	DCBlock __m_dcblock_182;
	DCBlock __m_dcblock_192;
	DCBlock __m_dcblock_212;
	DCBlock __m_dcblock_217;
	DCBlock __m_dcblock_187;
	DCBlock __m_dcblock_207;
	DCBlock __m_dcblock_197;
	DCBlock __m_dcblock_202;
	Sah __m_sah_138;
	int __exception;
	int vectorsize;
	t_sample m_history_129;
	t_sample m_x_128;
	t_sample m_x_16;
	t_sample m_history_130;
	t_sample m_history_131;
	t_sample m_x_127;
	t_sample m_y_125;
	t_sample m_y_126;
	t_sample m_x_124;
	t_sample m_history_132;
	t_sample m_sw_133;
	t_sample m_sw_134;
	t_sample __m_slide_140;
	t_sample __m_slide_143;
	t_sample __m_latch_146;
	t_sample m_x_123;
	t_sample m_y_14;
	t_sample m_knob5_noise_136;
	t_sample m_knob3_res_137;
	t_sample m_knob4_gain_135;
	t_sample m_y_13;
	t_sample m_y_122;
	t_sample m_x_120;
	t_sample m_x_107;
	t_sample m_x_108;
	t_sample m_y_109;
	t_sample m_y_110;
	t_sample m_y_106;
	t_sample m_x_104;
	t_sample m_y_105;
	t_sample m_x_103;
	t_sample m_y_121;
	t_sample m_x_111;
	t_sample m_y_113;
	t_sample m_y_118;
	t_sample m_x_119;
	t_sample m_x_112;
	t_sample m_y_117;
	t_sample m_x_115;
	t_sample m_x_116;
	t_sample m_y_114;
	t_sample __m_slide_148;
	t_sample __m_latch_151;
	t_sample m_x_12;
	t_sample __m_latch_196;
	t_sample m_x_3;
	t_sample __m_slide_198;
	t_sample __m_latch_201;
	t_sample __m_slide_193;
	t_sample __m_latch_191;
	t_sample m_x_4;
	t_sample __m_slide_188;
	t_sample m_y_5;
	t_sample m_y_2;
	t_sample __m_latch_206;
	t_sample __m_slide_213;
	t_sample __m_latch_216;
	t_sample __m_slide_218;
	t_sample __m_slide_203;
	t_sample samplerate;
	t_sample __m_slide_208;
	t_sample __m_latch_211;
	t_sample m_y_1;
	t_sample m_y_102;
	t_sample __m_latch_186;
	t_sample m_y_6;
	t_sample __m_latch_161;
	t_sample m_y_10;
	t_sample __m_slide_163;
	t_sample __m_latch_166;
	t_sample __m_slide_158;
	t_sample __m_latch_156;
	t_sample m_x_11;
	t_sample __m_slide_153;
	t_sample __m_slide_183;
	t_sample m_y_9;
	t_sample __m_latch_171;
	t_sample __m_slide_178;
	t_sample __m_latch_181;
	t_sample __m_slide_168;
	t_sample m_x_7;
	t_sample __m_slide_173;
	t_sample __m_latch_176;
	t_sample m_x_8;
	t_sample m_x_15;
	t_sample m_y_101;
	t_sample m_x_99;
	t_sample m_y_42;
	t_sample m_x_43;
	t_sample m_x_44;
	t_sample m_y_45;
	t_sample m_y_41;
	t_sample m_x_39;
	t_sample m_x_40;
	t_sample m_y_38;
	t_sample m_y_37;
	t_sample m_y_46;
	t_sample m_x_48;
	t_sample m_y_53;
	t_sample m_y_54;
	t_sample m_x_55;
	t_sample m_x_47;
	t_sample m_x_52;
	t_sample m_y_50;
	t_sample m_x_51;
	t_sample m_y_49;
	t_sample m_x_56;
	t_sample m_x_36;
	t_sample m_y_34;
	t_sample m_y_21;
	t_sample m_y_22;
	t_sample m_x_23;
	t_sample m_x_24;
	t_sample m_x_20;
	t_sample m_y_18;
	t_sample m_x_19;
	t_sample m_y_17;
	t_sample m_x_35;
	t_sample m_y_25;
	t_sample m_x_27;
	t_sample m_x_32;
	t_sample m_y_33;
	t_sample m_y_26;
	t_sample m_x_31;
	t_sample m_y_29;
	t_sample m_y_30;
	t_sample m_x_28;
	t_sample m_x_100;
	t_sample m_y_57;
	t_sample m_x_59;
	t_sample m_y_85;
	t_sample m_y_86;
	t_sample m_x_87;
	t_sample m_x_88;
	t_sample m_x_84;
	t_sample m_y_82;
	t_sample m_x_83;
	t_sample m_y_81;
	t_sample m_x_80;
	t_sample m_y_89;
	t_sample m_x_91;
	t_sample m_x_96;
	t_sample m_y_97;
	t_sample m_y_98;
	t_sample m_y_90;
	t_sample m_x_95;
	t_sample m_y_93;
	t_sample m_y_94;
	t_sample __m_latch_221;
	t_sample m_y_58;
	t_sample m_x_79;
	t_sample m_y_77;
	t_sample m_x_64;
	t_sample m_y_65;
	t_sample m_y_66;
	t_sample m_x_67;
	t_sample m_x_63;
	t_sample m_y_61;
	t_sample m_y_62;
	t_sample m_x_60;
	t_sample m_y_78;
	t_sample m_x_68;
	t_sample m_y_70;
	t_sample m_x_75;
	t_sample m_x_76;
	t_sample m_y_69;
	t_sample m_y_74;
	t_sample m_x_72;
	t_sample m_y_73;
	t_sample m_x_71;
	t_sample m_x_92;
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
		m_sw_133 = ((int)0);
		m_sw_134 = 0;
		m_knob4_gain_135 = 5;
		m_knob5_noise_136 = 0;
		m_knob3_res_137 = 15;
		__m_sah_138.reset(0);
		__m_slide_140 = 0;
		__m_slide_143 = 0;
		__m_latch_146 = 0;
		__m_dcblock_147.reset();
		__m_slide_148 = 0;
		__m_latch_151 = 0;
		__m_dcblock_152.reset();
		__m_slide_153 = 0;
		__m_latch_156 = 0;
		__m_dcblock_157.reset();
		__m_slide_158 = 0;
		__m_latch_161 = 0;
		__m_dcblock_162.reset();
		__m_slide_163 = 0;
		__m_latch_166 = 0;
		__m_dcblock_167.reset();
		__m_slide_168 = 0;
		__m_latch_171 = 0;
		__m_dcblock_172.reset();
		__m_slide_173 = 0;
		__m_latch_176 = 0;
		__m_dcblock_177.reset();
		__m_slide_178 = 0;
		__m_latch_181 = 0;
		__m_dcblock_182.reset();
		__m_slide_183 = 0;
		__m_latch_186 = 0;
		__m_dcblock_187.reset();
		__m_slide_188 = 0;
		__m_latch_191 = 0;
		__m_dcblock_192.reset();
		__m_slide_193 = 0;
		__m_latch_196 = 0;
		__m_dcblock_197.reset();
		__m_slide_198 = 0;
		__m_latch_201 = 0;
		__m_dcblock_202.reset();
		__m_slide_203 = 0;
		__m_latch_206 = 0;
		__m_dcblock_207.reset();
		__m_slide_208 = 0;
		__m_latch_211 = 0;
		__m_dcblock_212.reset();
		__m_slide_213 = 0;
		__m_latch_216 = 0;
		__m_dcblock_217.reset();
		__m_slide_218 = 0;
		__m_latch_221 = 0;
		__m_dcblock_222.reset();
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
		t_sample rsub_3233 = (((int)1) - m_sw_134);
		t_sample mstosamps_3629 = (((int)2) * (samplerate * 0.001));
		t_sample mstosamps_3718 = (((int)20) * (samplerate * 0.001));
		t_sample iup_141 = (1 / maximum(1, abs(((int)10))));
		t_sample idown_142 = (1 / maximum(1, abs(((int)400))));
		t_sample twopi_over_sr = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3569 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_144 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_145 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3735 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3543 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_149 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_150 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3760 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3517 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_154 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_155 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3779 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3491 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_159 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_160 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3791 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3465 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_164 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_165 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3803 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3439 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_169 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_170 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3821 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3413 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_174 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_175 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3839 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3387 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_179 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_180 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3857 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3361 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_184 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_185 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3875 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3335 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_189 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_190 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3893 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3309 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_194 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_195 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3911 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3283 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_199 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_200 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3928 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3257 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_204 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_205 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3946 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3691 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_209 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_210 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3964 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3621 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_214 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_215 = (1 / maximum(1, abs(mstosamps_3718)));
		t_sample twopi_over_sr_3982 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_3595 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_219 = (1 / maximum(1, abs(mstosamps_3629)));
		t_sample idown_220 = (1 / maximum(1, abs(mstosamps_3718)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_3724 = __m_sah_138(m_history_132, m_sw_133, ((int)0));
			t_sample gen_3726 = sah_3724;
			t_sample rsub_3722 = (((int)1) - sah_3724);
			t_sample history_3723_next_3725 = fixdenorm(rsub_3722);
			t_sample out3 = gen_3726;
			t_sample add_3727 = (gen_3726 + ((int)1));
			t_sample choice_139 = int(add_3727);
			t_sample gate_3720 = (((choice_139 >= 1) && (choice_139 < 2)) ? in1 : 0);
			t_sample gate_3721 = ((choice_139 >= 2) ? in1 : 0);
			t_sample mix_4006 = (m_history_131 + (((t_sample)0.003926980723806) * (m_knob3_res_137 - m_history_131)));
			t_sample mix_3710 = mix_4006;
			t_sample mix_4007 = (m_history_130 + (((t_sample)0.003926980723806) * (mix_3710 - m_history_130)));
			t_sample mix_3708 = mix_4007;
			t_sample mix_4008 = (m_history_129 + (((t_sample)0.003926980723806) * (mix_3708 - m_history_129)));
			t_sample mix_3706 = mix_4008;
			t_sample gen_3716 = mix_3706;
			t_sample history_3711_next_3713 = fixdenorm(mix_3710);
			t_sample history_3709_next_3714 = fixdenorm(mix_3708);
			t_sample history_3707_next_3715 = fixdenorm(mix_3706);
			t_sample mul_3231 = (gate_3721 * m_knob4_gain_135);
			t_sample abs_3229 = fabs(gate_3721);
			__m_slide_140 = fixdenorm((__m_slide_140 + (((abs_3229 > __m_slide_140) ? iup_141 : idown_142) * (abs_3229 - __m_slide_140))));
			t_sample slide_3228 = __m_slide_140;
			t_sample noise_3236 = noise();
			t_sample mul_3235 = (noise_3236 * m_knob5_noise_136);
			t_sample mul_3230 = (slide_3228 * mul_3235);
			t_sample add_3234 = (mul_3231 + mul_3230);
			t_sample x = add_3234;
			t_sample q = gen_3716;
			t_sample bw = safediv(((t_sample)284.5), q);
			t_sample r = exp(((-bw) * twopi_over_sr));
			t_sample c1 = ((((int)2) * r) * cos((((t_sample)284.5) * twopi_over_sr)));
			t_sample c2 = ((-r) * r);
			t_sample y = ((((((int)1) - r) * (x - (r * m_x_127))) + (c1 * m_y_126)) + (c2 * m_y_125));
			m_y_125 = m_y_126;
			m_y_126 = y;
			m_x_127 = m_x_128;
			m_x_128 = x;
			t_sample x_3565 = in2;
			t_sample q_3558 = gen_3716;
			t_sample bw_3566 = safediv(((t_sample)284.5), q_3558);
			t_sample r_3559 = exp(((-bw_3566) * twopi_over_sr_3569));
			t_sample c_3568 = ((((int)2) * r_3559) * cos((((t_sample)284.5) * twopi_over_sr_3569)));
			t_sample c_3571 = ((-r_3559) * r_3559);
			t_sample y_3570 = ((((((int)1) - r_3559) * (x_3565 - (r_3559 * m_x_123))) + (c_3568 * m_y_122)) + (c_3571 * m_y_121));
			m_y_121 = m_y_122;
			m_y_122 = y_3570;
			m_x_123 = m_x_124;
			m_x_124 = x_3565;
			t_sample abs_3557 = fabs(y_3570);
			__m_slide_143 = fixdenorm((__m_slide_143 + (((abs_3557 > __m_slide_143) ? iup_144 : idown_145) * (abs_3557 - __m_slide_143))));
			t_sample slide_3556 = __m_slide_143;
			__m_latch_146 = ((rsub_3233 != 0) ? slide_3556 : __m_latch_146);
			t_sample latch_3551 = __m_latch_146;
			t_sample mul_3553 = (y * latch_3551);
			t_sample dcblock_3552 = __m_dcblock_147(mul_3553);
			t_sample x_3733 = add_3234;
			t_sample q_3731 = gen_3716;
			t_sample bw_3734 = safediv(((t_sample)358.5), q_3731);
			t_sample r_3732 = exp(((-bw_3734) * twopi_over_sr_3735));
			t_sample c_3740 = ((((int)2) * r_3732) * cos((((t_sample)358.5) * twopi_over_sr_3735)));
			t_sample c_3739 = ((-r_3732) * r_3732);
			t_sample y_3738 = ((((((int)1) - r_3732) * (x_3733 - (r_3732 * m_x_119))) + (c_3740 * m_y_118)) + (c_3739 * m_y_117));
			m_y_117 = m_y_118;
			m_y_118 = y_3738;
			m_x_119 = m_x_120;
			m_x_120 = x_3733;
			t_sample x_3539 = in2;
			t_sample q_3532 = gen_3716;
			t_sample bw_3540 = safediv(((t_sample)358.5), q_3532);
			t_sample r_3533 = exp(((-bw_3540) * twopi_over_sr_3543));
			t_sample c_3542 = ((((int)2) * r_3533) * cos((((t_sample)358.5) * twopi_over_sr_3543)));
			t_sample c_3545 = ((-r_3533) * r_3533);
			t_sample y_3544 = ((((((int)1) - r_3533) * (x_3539 - (r_3533 * m_x_115))) + (c_3542 * m_y_114)) + (c_3545 * m_y_113));
			m_y_113 = m_y_114;
			m_y_114 = y_3544;
			m_x_115 = m_x_116;
			m_x_116 = x_3539;
			t_sample abs_3531 = fabs(y_3544);
			__m_slide_148 = fixdenorm((__m_slide_148 + (((abs_3531 > __m_slide_148) ? iup_149 : idown_150) * (abs_3531 - __m_slide_148))));
			t_sample slide_3530 = __m_slide_148;
			__m_latch_151 = ((rsub_3233 != 0) ? slide_3530 : __m_latch_151);
			t_sample latch_3525 = __m_latch_151;
			t_sample mul_3527 = (y_3738 * latch_3525);
			t_sample dcblock_3526 = __m_dcblock_152(mul_3527);
			t_sample x_3754 = add_3234;
			t_sample q_3751 = gen_3716;
			t_sample bw_3759 = safediv(((int)452), q_3751);
			t_sample r_3752 = exp(((-bw_3759) * twopi_over_sr_3760));
			t_sample c_3757 = ((((int)2) * r_3752) * cos((((int)452) * twopi_over_sr_3760)));
			t_sample c_3748 = ((-r_3752) * r_3752);
			t_sample y_3753 = ((((((int)1) - r_3752) * (x_3754 - (r_3752 * m_x_111))) + (c_3757 * m_y_110)) + (c_3748 * m_y_109));
			m_y_109 = m_y_110;
			m_y_110 = y_3753;
			m_x_111 = m_x_112;
			m_x_112 = x_3754;
			t_sample x_3513 = in2;
			t_sample q_3506 = gen_3716;
			t_sample bw_3514 = safediv(((int)452), q_3506);
			t_sample r_3507 = exp(((-bw_3514) * twopi_over_sr_3517));
			t_sample c_3516 = ((((int)2) * r_3507) * cos((((int)452) * twopi_over_sr_3517)));
			t_sample c_3519 = ((-r_3507) * r_3507);
			t_sample y_3518 = ((((((int)1) - r_3507) * (x_3513 - (r_3507 * m_x_107))) + (c_3516 * m_y_106)) + (c_3519 * m_y_105));
			m_y_105 = m_y_106;
			m_y_106 = y_3518;
			m_x_107 = m_x_108;
			m_x_108 = x_3513;
			t_sample abs_3505 = fabs(y_3518);
			__m_slide_153 = fixdenorm((__m_slide_153 + (((abs_3505 > __m_slide_153) ? iup_154 : idown_155) * (abs_3505 - __m_slide_153))));
			t_sample slide_3504 = __m_slide_153;
			__m_latch_156 = ((rsub_3233 != 0) ? slide_3504 : __m_latch_156);
			t_sample latch_3499 = __m_latch_156;
			t_sample mul_3501 = (y_3753 * latch_3499);
			t_sample dcblock_3500 = __m_dcblock_157(mul_3501);
			t_sample x_3771 = add_3234;
			t_sample q_3769 = gen_3716;
			t_sample bw_3772 = safediv(((t_sample)569.5), q_3769);
			t_sample r_3770 = exp(((-bw_3772) * twopi_over_sr_3779));
			t_sample c_3775 = ((((int)2) * r_3770) * cos((((t_sample)569.5) * twopi_over_sr_3779)));
			t_sample c_3766 = ((-r_3770) * r_3770);
			t_sample y_3778 = ((((((int)1) - r_3770) * (x_3771 - (r_3770 * m_x_103))) + (c_3775 * m_y_102)) + (c_3766 * m_y_101));
			m_y_101 = m_y_102;
			m_y_102 = y_3778;
			m_x_103 = m_x_104;
			m_x_104 = x_3771;
			t_sample x_3487 = in2;
			t_sample q_3480 = gen_3716;
			t_sample bw_3488 = safediv(((t_sample)569.5), q_3480);
			t_sample r_3481 = exp(((-bw_3488) * twopi_over_sr_3491));
			t_sample c_3490 = ((((int)2) * r_3481) * cos((((t_sample)569.5) * twopi_over_sr_3491)));
			t_sample c_3493 = ((-r_3481) * r_3481);
			t_sample y_3492 = ((((((int)1) - r_3481) * (x_3487 - (r_3481 * m_x_99))) + (c_3490 * m_y_98)) + (c_3493 * m_y_97));
			m_y_97 = m_y_98;
			m_y_98 = y_3492;
			m_x_99 = m_x_100;
			m_x_100 = x_3487;
			t_sample abs_3479 = fabs(y_3492);
			__m_slide_158 = fixdenorm((__m_slide_158 + (((abs_3479 > __m_slide_158) ? iup_159 : idown_160) * (abs_3479 - __m_slide_158))));
			t_sample slide_3478 = __m_slide_158;
			__m_latch_161 = ((rsub_3233 != 0) ? slide_3478 : __m_latch_161);
			t_sample latch_3473 = __m_latch_161;
			t_sample mul_3475 = (y_3778 * latch_3473);
			t_sample dcblock_3474 = __m_dcblock_162(mul_3475);
			t_sample x_3789 = add_3234;
			t_sample q_3787 = gen_3716;
			t_sample bw_3790 = safediv(((t_sample)717.5), q_3787);
			t_sample r_3788 = exp(((-bw_3790) * twopi_over_sr_3791));
			t_sample c_3794 = ((((int)2) * r_3788) * cos((((t_sample)717.5) * twopi_over_sr_3791)));
			t_sample c_3795 = ((-r_3788) * r_3788);
			t_sample y_3784 = ((((((int)1) - r_3788) * (x_3789 - (r_3788 * m_x_95))) + (c_3794 * m_y_94)) + (c_3795 * m_y_93));
			m_y_93 = m_y_94;
			m_y_94 = y_3784;
			m_x_95 = m_x_96;
			m_x_96 = x_3789;
			t_sample x_3461 = in2;
			t_sample q_3454 = gen_3716;
			t_sample bw_3462 = safediv(((t_sample)717.5), q_3454);
			t_sample r_3455 = exp(((-bw_3462) * twopi_over_sr_3465));
			t_sample c_3464 = ((((int)2) * r_3455) * cos((((t_sample)717.5) * twopi_over_sr_3465)));
			t_sample c_3467 = ((-r_3455) * r_3455);
			t_sample y_3466 = ((((((int)1) - r_3455) * (x_3461 - (r_3455 * m_x_91))) + (c_3464 * m_y_90)) + (c_3467 * m_y_89));
			m_y_89 = m_y_90;
			m_y_90 = y_3466;
			m_x_91 = m_x_92;
			m_x_92 = x_3461;
			t_sample abs_3453 = fabs(y_3466);
			__m_slide_163 = fixdenorm((__m_slide_163 + (((abs_3453 > __m_slide_163) ? iup_164 : idown_165) * (abs_3453 - __m_slide_163))));
			t_sample slide_3452 = __m_slide_163;
			__m_latch_166 = ((rsub_3233 != 0) ? slide_3452 : __m_latch_166);
			t_sample latch_3447 = __m_latch_166;
			t_sample mul_3449 = (y_3784 * latch_3447);
			t_sample dcblock_3448 = __m_dcblock_167(mul_3449);
			t_sample x_3807 = add_3234;
			t_sample q_3804 = gen_3716;
			t_sample bw_3815 = safediv(((int)904), q_3804);
			t_sample r_3805 = exp(((-bw_3815) * twopi_over_sr_3803));
			t_sample c_3808 = ((((int)2) * r_3805) * cos((((int)904) * twopi_over_sr_3803)));
			t_sample c_3802 = ((-r_3805) * r_3805);
			t_sample y_3806 = ((((((int)1) - r_3805) * (x_3807 - (r_3805 * m_x_87))) + (c_3808 * m_y_86)) + (c_3802 * m_y_85));
			m_y_85 = m_y_86;
			m_y_86 = y_3806;
			m_x_87 = m_x_88;
			m_x_88 = x_3807;
			t_sample x_3435 = in2;
			t_sample q_3428 = gen_3716;
			t_sample bw_3436 = safediv(((int)904), q_3428);
			t_sample r_3429 = exp(((-bw_3436) * twopi_over_sr_3439));
			t_sample c_3438 = ((((int)2) * r_3429) * cos((((int)904) * twopi_over_sr_3439)));
			t_sample c_3441 = ((-r_3429) * r_3429);
			t_sample y_3440 = ((((((int)1) - r_3429) * (x_3435 - (r_3429 * m_x_83))) + (c_3438 * m_y_82)) + (c_3441 * m_y_81));
			m_y_81 = m_y_82;
			m_y_82 = y_3440;
			m_x_83 = m_x_84;
			m_x_84 = x_3435;
			t_sample abs_3427 = fabs(y_3440);
			__m_slide_168 = fixdenorm((__m_slide_168 + (((abs_3427 > __m_slide_168) ? iup_169 : idown_170) * (abs_3427 - __m_slide_168))));
			t_sample slide_3426 = __m_slide_168;
			__m_latch_171 = ((rsub_3233 != 0) ? slide_3426 : __m_latch_171);
			t_sample latch_3421 = __m_latch_171;
			t_sample mul_3423 = (y_3806 * latch_3421);
			t_sample dcblock_3422 = __m_dcblock_172(mul_3423);
			t_sample x_3825 = add_3234;
			t_sample q_3822 = gen_3716;
			t_sample bw_3829 = safediv(((int)1139), q_3822);
			t_sample r_3823 = exp(((-bw_3829) * twopi_over_sr_3821));
			t_sample c_3826 = ((((int)2) * r_3823) * cos((((int)1139) * twopi_over_sr_3821)));
			t_sample c_3820 = ((-r_3823) * r_3823);
			t_sample y_3824 = ((((((int)1) - r_3823) * (x_3825 - (r_3823 * m_x_79))) + (c_3826 * m_y_78)) + (c_3820 * m_y_77));
			m_y_77 = m_y_78;
			m_y_78 = y_3824;
			m_x_79 = m_x_80;
			m_x_80 = x_3825;
			t_sample x_3409 = in2;
			t_sample q_3402 = gen_3716;
			t_sample bw_3410 = safediv(((int)1139), q_3402);
			t_sample r_3403 = exp(((-bw_3410) * twopi_over_sr_3413));
			t_sample c_3412 = ((((int)2) * r_3403) * cos((((int)1139) * twopi_over_sr_3413)));
			t_sample c_3415 = ((-r_3403) * r_3403);
			t_sample y_3414 = ((((((int)1) - r_3403) * (x_3409 - (r_3403 * m_x_75))) + (c_3412 * m_y_74)) + (c_3415 * m_y_73));
			m_y_73 = m_y_74;
			m_y_74 = y_3414;
			m_x_75 = m_x_76;
			m_x_76 = x_3409;
			t_sample abs_3401 = fabs(y_3414);
			__m_slide_173 = fixdenorm((__m_slide_173 + (((abs_3401 > __m_slide_173) ? iup_174 : idown_175) * (abs_3401 - __m_slide_173))));
			t_sample slide_3400 = __m_slide_173;
			__m_latch_176 = ((rsub_3233 != 0) ? slide_3400 : __m_latch_176);
			t_sample latch_3395 = __m_latch_176;
			t_sample mul_3397 = (y_3824 * latch_3395);
			t_sample dcblock_3396 = __m_dcblock_177(mul_3397);
			t_sample x_3843 = add_3234;
			t_sample q_3840 = gen_3716;
			t_sample bw_3851 = safediv(((int)1435), q_3840);
			t_sample r_3841 = exp(((-bw_3851) * twopi_over_sr_3839));
			t_sample c_3844 = ((((int)2) * r_3841) * cos((((int)1435) * twopi_over_sr_3839)));
			t_sample c_3838 = ((-r_3841) * r_3841);
			t_sample y_3842 = ((((((int)1) - r_3841) * (x_3843 - (r_3841 * m_x_71))) + (c_3844 * m_y_70)) + (c_3838 * m_y_69));
			m_y_69 = m_y_70;
			m_y_70 = y_3842;
			m_x_71 = m_x_72;
			m_x_72 = x_3843;
			t_sample x_3383 = in2;
			t_sample q_3376 = gen_3716;
			t_sample bw_3384 = safediv(((int)1435), q_3376);
			t_sample r_3377 = exp(((-bw_3384) * twopi_over_sr_3387));
			t_sample c_3386 = ((((int)2) * r_3377) * cos((((int)1435) * twopi_over_sr_3387)));
			t_sample c_3389 = ((-r_3377) * r_3377);
			t_sample y_3388 = ((((((int)1) - r_3377) * (x_3383 - (r_3377 * m_x_67))) + (c_3386 * m_y_66)) + (c_3389 * m_y_65));
			m_y_65 = m_y_66;
			m_y_66 = y_3388;
			m_x_67 = m_x_68;
			m_x_68 = x_3383;
			t_sample abs_3375 = fabs(y_3388);
			__m_slide_178 = fixdenorm((__m_slide_178 + (((abs_3375 > __m_slide_178) ? iup_179 : idown_180) * (abs_3375 - __m_slide_178))));
			t_sample slide_3374 = __m_slide_178;
			__m_latch_181 = ((rsub_3233 != 0) ? slide_3374 : __m_latch_181);
			t_sample latch_3369 = __m_latch_181;
			t_sample mul_3371 = (y_3842 * latch_3369);
			t_sample dcblock_3370 = __m_dcblock_182(mul_3371);
			t_sample x_3861 = add_3234;
			t_sample q_3858 = gen_3716;
			t_sample bw_3865 = safediv(((int)1808), q_3858);
			t_sample r_3859 = exp(((-bw_3865) * twopi_over_sr_3857));
			t_sample c_3862 = ((((int)2) * r_3859) * cos((((int)1808) * twopi_over_sr_3857)));
			t_sample c_3856 = ((-r_3859) * r_3859);
			t_sample y_3860 = ((((((int)1) - r_3859) * (x_3861 - (r_3859 * m_x_63))) + (c_3862 * m_y_62)) + (c_3856 * m_y_61));
			m_y_61 = m_y_62;
			m_y_62 = y_3860;
			m_x_63 = m_x_64;
			m_x_64 = x_3861;
			t_sample x_3357 = in2;
			t_sample q_3350 = gen_3716;
			t_sample bw_3358 = safediv(((int)1808), q_3350);
			t_sample r_3351 = exp(((-bw_3358) * twopi_over_sr_3361));
			t_sample c_3360 = ((((int)2) * r_3351) * cos((((int)1808) * twopi_over_sr_3361)));
			t_sample c_3363 = ((-r_3351) * r_3351);
			t_sample y_3362 = ((((((int)1) - r_3351) * (x_3357 - (r_3351 * m_x_59))) + (c_3360 * m_y_58)) + (c_3363 * m_y_57));
			m_y_57 = m_y_58;
			m_y_58 = y_3362;
			m_x_59 = m_x_60;
			m_x_60 = x_3357;
			t_sample abs_3349 = fabs(y_3362);
			__m_slide_183 = fixdenorm((__m_slide_183 + (((abs_3349 > __m_slide_183) ? iup_184 : idown_185) * (abs_3349 - __m_slide_183))));
			t_sample slide_3348 = __m_slide_183;
			__m_latch_186 = ((rsub_3233 != 0) ? slide_3348 : __m_latch_186);
			t_sample latch_3343 = __m_latch_186;
			t_sample mul_3345 = (y_3860 * latch_3343);
			t_sample dcblock_3344 = __m_dcblock_187(mul_3345);
			t_sample x_3879 = add_3234;
			t_sample q_3876 = gen_3716;
			t_sample bw_3887 = safediv(((int)2260), q_3876);
			t_sample r_3877 = exp(((-bw_3887) * twopi_over_sr_3875));
			t_sample c_3880 = ((((int)2) * r_3877) * cos((((int)2260) * twopi_over_sr_3875)));
			t_sample c_3874 = ((-r_3877) * r_3877);
			t_sample y_3878 = ((((((int)1) - r_3877) * (x_3879 - (r_3877 * m_x_55))) + (c_3880 * m_y_54)) + (c_3874 * m_y_53));
			m_y_53 = m_y_54;
			m_y_54 = y_3878;
			m_x_55 = m_x_56;
			m_x_56 = x_3879;
			t_sample x_3331 = in2;
			t_sample q_3324 = gen_3716;
			t_sample bw_3332 = safediv(((int)2260), q_3324);
			t_sample r_3325 = exp(((-bw_3332) * twopi_over_sr_3335));
			t_sample c_3334 = ((((int)2) * r_3325) * cos((((int)2260) * twopi_over_sr_3335)));
			t_sample c_3337 = ((-r_3325) * r_3325);
			t_sample y_3336 = ((((((int)1) - r_3325) * (x_3331 - (r_3325 * m_x_51))) + (c_3334 * m_y_50)) + (c_3337 * m_y_49));
			m_y_49 = m_y_50;
			m_y_50 = y_3336;
			m_x_51 = m_x_52;
			m_x_52 = x_3331;
			t_sample abs_3323 = fabs(y_3336);
			__m_slide_188 = fixdenorm((__m_slide_188 + (((abs_3323 > __m_slide_188) ? iup_189 : idown_190) * (abs_3323 - __m_slide_188))));
			t_sample slide_3322 = __m_slide_188;
			__m_latch_191 = ((rsub_3233 != 0) ? slide_3322 : __m_latch_191);
			t_sample latch_3317 = __m_latch_191;
			t_sample mul_3319 = (y_3878 * latch_3317);
			t_sample dcblock_3318 = __m_dcblock_192(mul_3319);
			t_sample x_3898 = add_3234;
			t_sample q_3895 = gen_3716;
			t_sample bw_3904 = safediv(((int)2852), q_3895);
			t_sample r_3896 = exp(((-bw_3904) * twopi_over_sr_3893));
			t_sample c_3902 = ((((int)2) * r_3896) * cos((((int)2852) * twopi_over_sr_3893)));
			t_sample c_3892 = ((-r_3896) * r_3896);
			t_sample y_3897 = ((((((int)1) - r_3896) * (x_3898 - (r_3896 * m_x_47))) + (c_3902 * m_y_46)) + (c_3892 * m_y_45));
			m_y_45 = m_y_46;
			m_y_46 = y_3897;
			m_x_47 = m_x_48;
			m_x_48 = x_3898;
			t_sample x_3305 = in2;
			t_sample q_3298 = gen_3716;
			t_sample bw_3306 = safediv(((int)2852), q_3298);
			t_sample r_3299 = exp(((-bw_3306) * twopi_over_sr_3309));
			t_sample c_3308 = ((((int)2) * r_3299) * cos((((int)2852) * twopi_over_sr_3309)));
			t_sample c_3311 = ((-r_3299) * r_3299);
			t_sample y_3310 = ((((((int)1) - r_3299) * (x_3305 - (r_3299 * m_x_43))) + (c_3308 * m_y_42)) + (c_3311 * m_y_41));
			m_y_41 = m_y_42;
			m_y_42 = y_3310;
			m_x_43 = m_x_44;
			m_x_44 = x_3305;
			t_sample abs_3297 = fabs(y_3310);
			__m_slide_193 = fixdenorm((__m_slide_193 + (((abs_3297 > __m_slide_193) ? iup_194 : idown_195) * (abs_3297 - __m_slide_193))));
			t_sample slide_3296 = __m_slide_193;
			__m_latch_196 = ((rsub_3233 != 0) ? slide_3296 : __m_latch_196);
			t_sample latch_3291 = __m_latch_196;
			t_sample mul_3293 = (y_3897 * latch_3291);
			t_sample dcblock_3292 = __m_dcblock_197(mul_3293);
			t_sample x_3913 = add_3234;
			t_sample q_3916 = gen_3716;
			t_sample bw_3917 = safediv(((int)3616), q_3916);
			t_sample r_3912 = exp(((-bw_3917) * twopi_over_sr_3911));
			t_sample c_3923 = ((((int)2) * r_3912) * cos((((int)3616) * twopi_over_sr_3911)));
			t_sample c_3910 = ((-r_3912) * r_3912);
			t_sample y_3920 = ((((((int)1) - r_3912) * (x_3913 - (r_3912 * m_x_39))) + (c_3923 * m_y_38)) + (c_3910 * m_y_37));
			m_y_37 = m_y_38;
			m_y_38 = y_3920;
			m_x_39 = m_x_40;
			m_x_40 = x_3913;
			t_sample x_3279 = in2;
			t_sample q_3272 = gen_3716;
			t_sample bw_3280 = safediv(((int)3616), q_3272);
			t_sample r_3273 = exp(((-bw_3280) * twopi_over_sr_3283));
			t_sample c_3282 = ((((int)2) * r_3273) * cos((((int)3616) * twopi_over_sr_3283)));
			t_sample c_3285 = ((-r_3273) * r_3273);
			t_sample y_3284 = ((((((int)1) - r_3273) * (x_3279 - (r_3273 * m_x_35))) + (c_3282 * m_y_34)) + (c_3285 * m_y_33));
			m_y_33 = m_y_34;
			m_y_34 = y_3284;
			m_x_35 = m_x_36;
			m_x_36 = x_3279;
			t_sample abs_3271 = fabs(y_3284);
			__m_slide_198 = fixdenorm((__m_slide_198 + (((abs_3271 > __m_slide_198) ? iup_199 : idown_200) * (abs_3271 - __m_slide_198))));
			t_sample slide_3270 = __m_slide_198;
			__m_latch_201 = ((rsub_3233 != 0) ? slide_3270 : __m_latch_201);
			t_sample latch_3265 = __m_latch_201;
			t_sample mul_3267 = (y_3920 * latch_3265);
			t_sample dcblock_3266 = __m_dcblock_202(mul_3267);
			t_sample x_3931 = add_3234;
			t_sample q_3939 = gen_3716;
			t_sample bw_3938 = safediv(((int)4556), q_3939);
			t_sample r_3929 = exp(((-bw_3938) * twopi_over_sr_3928));
			t_sample c_3935 = ((((int)2) * r_3929) * cos((((int)4556) * twopi_over_sr_3928)));
			t_sample c_3933 = ((-r_3929) * r_3929);
			t_sample y_3930 = ((((((int)1) - r_3929) * (x_3931 - (r_3929 * m_x_31))) + (c_3935 * m_y_30)) + (c_3933 * m_y_29));
			m_y_29 = m_y_30;
			m_y_30 = y_3930;
			m_x_31 = m_x_32;
			m_x_32 = x_3931;
			t_sample x_3253 = in2;
			t_sample q_3246 = gen_3716;
			t_sample bw_3254 = safediv(((int)4556), q_3246);
			t_sample r_3247 = exp(((-bw_3254) * twopi_over_sr_3257));
			t_sample c_3256 = ((((int)2) * r_3247) * cos((((int)4556) * twopi_over_sr_3257)));
			t_sample c_3259 = ((-r_3247) * r_3247);
			t_sample y_3258 = ((((((int)1) - r_3247) * (x_3253 - (r_3247 * m_x_27))) + (c_3256 * m_y_26)) + (c_3259 * m_y_25));
			m_y_25 = m_y_26;
			m_y_26 = y_3258;
			m_x_27 = m_x_28;
			m_x_28 = x_3253;
			t_sample abs_3245 = fabs(y_3258);
			__m_slide_203 = fixdenorm((__m_slide_203 + (((abs_3245 > __m_slide_203) ? iup_204 : idown_205) * (abs_3245 - __m_slide_203))));
			t_sample slide_3244 = __m_slide_203;
			__m_latch_206 = ((rsub_3233 != 0) ? slide_3244 : __m_latch_206);
			t_sample latch_3237 = __m_latch_206;
			t_sample mul_3239 = (y_3930 * latch_3237);
			t_sample dcblock_3238 = __m_dcblock_207(mul_3239);
			t_sample x_3959 = add_3234;
			t_sample q_3947 = gen_3716;
			t_sample bw_3958 = safediv(((t_sample)104.5), q_3947);
			t_sample r_3948 = exp(((-bw_3958) * twopi_over_sr_3946));
			t_sample c_3954 = ((((int)2) * r_3948) * cos((((t_sample)104.5) * twopi_over_sr_3946)));
			t_sample c_3951 = ((-r_3948) * r_3948);
			t_sample y_3949 = ((((((int)1) - r_3948) * (x_3959 - (r_3948 * m_x_23))) + (c_3954 * m_y_22)) + (c_3951 * m_y_21));
			m_y_21 = m_y_22;
			m_y_22 = y_3949;
			m_x_23 = m_x_24;
			m_x_24 = x_3959;
			t_sample x_3687 = in2;
			t_sample q_3680 = gen_3716;
			t_sample bw_3688 = safediv(((t_sample)104.5), q_3680);
			t_sample r_3681 = exp(((-bw_3688) * twopi_over_sr_3691));
			t_sample c_3690 = ((((int)2) * r_3681) * cos((((t_sample)104.5) * twopi_over_sr_3691)));
			t_sample c_3693 = ((-r_3681) * r_3681);
			t_sample y_3692 = ((((((int)1) - r_3681) * (x_3687 - (r_3681 * m_x_19))) + (c_3690 * m_y_18)) + (c_3693 * m_y_17));
			m_y_17 = m_y_18;
			m_y_18 = y_3692;
			m_x_19 = m_x_20;
			m_x_20 = x_3687;
			t_sample abs_3679 = fabs(y_3692);
			__m_slide_208 = fixdenorm((__m_slide_208 + (((abs_3679 > __m_slide_208) ? iup_209 : idown_210) * (abs_3679 - __m_slide_208))));
			t_sample slide_3678 = __m_slide_208;
			__m_latch_211 = ((rsub_3233 != 0) ? slide_3678 : __m_latch_211);
			t_sample latch_3673 = __m_latch_211;
			t_sample mul_3675 = (y_3949 * latch_3673);
			t_sample dcblock_3674 = __m_dcblock_212(mul_3675);
			t_sample x_3976 = add_3234;
			t_sample q_3977 = gen_3716;
			t_sample bw_3973 = safediv(((t_sample)179.5), q_3977);
			t_sample r_3965 = exp(((-bw_3973) * twopi_over_sr_3964));
			t_sample c_3970 = ((((int)2) * r_3965) * cos((((t_sample)179.5) * twopi_over_sr_3964)));
			t_sample c_3968 = ((-r_3965) * r_3965);
			t_sample y_3966 = ((((((int)1) - r_3965) * (x_3976 - (r_3965 * m_x_15))) + (c_3970 * m_y_14)) + (c_3968 * m_y_13));
			m_y_13 = m_y_14;
			m_y_14 = y_3966;
			m_x_15 = m_x_16;
			m_x_16 = x_3976;
			t_sample x_3617 = in2;
			t_sample q_3610 = gen_3716;
			t_sample bw_3618 = safediv(((t_sample)179.5), q_3610);
			t_sample r_3611 = exp(((-bw_3618) * twopi_over_sr_3621));
			t_sample c_3620 = ((((int)2) * r_3611) * cos((((t_sample)179.5) * twopi_over_sr_3621)));
			t_sample c_3623 = ((-r_3611) * r_3611);
			t_sample y_3622 = ((((((int)1) - r_3611) * (x_3617 - (r_3611 * m_x_11))) + (c_3620 * m_y_10)) + (c_3623 * m_y_9));
			m_y_9 = m_y_10;
			m_y_10 = y_3622;
			m_x_11 = m_x_12;
			m_x_12 = x_3617;
			t_sample abs_3609 = fabs(y_3622);
			__m_slide_213 = fixdenorm((__m_slide_213 + (((abs_3609 > __m_slide_213) ? iup_214 : idown_215) * (abs_3609 - __m_slide_213))));
			t_sample slide_3608 = __m_slide_213;
			__m_latch_216 = ((rsub_3233 != 0) ? slide_3608 : __m_latch_216);
			t_sample latch_3603 = __m_latch_216;
			t_sample mul_3605 = (y_3966 * latch_3603);
			t_sample dcblock_3604 = __m_dcblock_217(mul_3605);
			t_sample x_3993 = add_3234;
			t_sample q_3983 = gen_3716;
			t_sample bw_3991 = safediv(((int)226), q_3983);
			t_sample r_3984 = exp(((-bw_3991) * twopi_over_sr_3982));
			t_sample c_3995 = ((((int)2) * r_3984) * cos((((int)226) * twopi_over_sr_3982)));
			t_sample c_3987 = ((-r_3984) * r_3984);
			t_sample y_3985 = ((((((int)1) - r_3984) * (x_3993 - (r_3984 * m_x_7))) + (c_3995 * m_y_6)) + (c_3987 * m_y_5));
			m_y_5 = m_y_6;
			m_y_6 = y_3985;
			m_x_7 = m_x_8;
			m_x_8 = x_3993;
			t_sample x_3592 = in2;
			t_sample q_3584 = gen_3716;
			t_sample bw_3593 = safediv(((int)226), q_3584);
			t_sample r_3586 = exp(((-bw_3593) * twopi_over_sr_3595));
			t_sample c_3594 = ((((int)2) * r_3586) * cos((((int)226) * twopi_over_sr_3595)));
			t_sample c_3597 = ((-r_3586) * r_3586);
			t_sample y_3596 = ((((((int)1) - r_3586) * (x_3592 - (r_3586 * m_x_3))) + (c_3594 * m_y_2)) + (c_3597 * m_y_1));
			m_y_1 = m_y_2;
			m_y_2 = y_3596;
			m_x_3 = m_x_4;
			m_x_4 = x_3592;
			t_sample abs_3583 = fabs(y_3596);
			__m_slide_218 = fixdenorm((__m_slide_218 + (((abs_3583 > __m_slide_218) ? iup_219 : idown_220) * (abs_3583 - __m_slide_218))));
			t_sample slide_3582 = __m_slide_218;
			__m_latch_221 = ((rsub_3233 != 0) ? slide_3582 : __m_latch_221);
			t_sample latch_3577 = __m_latch_221;
			t_sample mul_3579 = (y_3985 * latch_3577);
			t_sample dcblock_3578 = __m_dcblock_222(mul_3579);
			t_sample pass_3717 = (((((((((((((((dcblock_3578 + dcblock_3604) + dcblock_3674) + dcblock_3238) + dcblock_3266) + dcblock_3292) + dcblock_3318) + dcblock_3344) + dcblock_3370) + dcblock_3396) + dcblock_3422) + dcblock_3448) + dcblock_3474) + dcblock_3500) + dcblock_3526) + dcblock_3552);
			t_sample add_3728 = (pass_3717 + gate_3720);
			t_sample out2 = add_3728;
			t_sample add_3729 = (pass_3717 + gate_3720);
			t_sample out1 = add_3729;
			m_history_132 = history_3723_next_3725;
			m_history_131 = history_3711_next_3713;
			m_history_129 = history_3707_next_3715;
			m_history_130 = history_3709_next_3714;
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
		m_sw_133 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_134 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_gain(t_param _value) {
		m_knob4_gain_135 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
	};
	inline void set_knob5_noise(t_param _value) {
		m_knob5_noise_136 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_res(t_param _value) {
		m_knob3_res_137 = (_value < 15 ? 15 : (_value > 50 ? 50 : _value));
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
int num_params() { return 5; }

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
		case 2: self->set_knob5_noise(value); break;
		case 3: self->set_sw1(value); break;
		case 4: self->set_sw2(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_res_137; break;
		case 1: *value = self->m_knob4_gain_135; break;
		case 2: *value = self->m_knob5_noise_136; break;
		case 3: *value = self->m_sw_133; break;
		case 4: *value = self->m_sw_134; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(5 * sizeof(ParamInfo));
	self->__commonstate.numparams = 5;
	// initialize parameter 0 ("m_knob3_res_137")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_res_137;
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
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_noise_136")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_noise";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_noise_136;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_sw_133")
	pi = self->__commonstate.params + 3;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_133;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_134")
	pi = self->__commonstate.params + 4;
	pi->name = "sw2";
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
