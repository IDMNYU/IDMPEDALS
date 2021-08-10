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
	DCBlock __m_dcblock_220;
	DCBlock __m_dcblock_165;
	DCBlock __m_dcblock_170;
	DCBlock __m_dcblock_175;
	DCBlock __m_dcblock_160;
	DCBlock __m_dcblock_150;
	DCBlock __m_dcblock_155;
	DCBlock __m_dcblock_145;
	DCBlock __m_dcblock_180;
	DCBlock __m_dcblock_190;
	DCBlock __m_dcblock_210;
	DCBlock __m_dcblock_215;
	DCBlock __m_dcblock_185;
	DCBlock __m_dcblock_205;
	DCBlock __m_dcblock_195;
	DCBlock __m_dcblock_200;
	Sah __m_sah_139;
	int __exception;
	int vectorsize;
	t_sample m_x_129;
	t_sample m_x_128;
	t_sample m_x_16;
	t_sample m_history_130;
	t_sample m_history_131;
	t_sample m_y_127;
	t_sample m_x_125;
	t_sample m_y_126;
	t_sample m_x_124;
	t_sample m_history_132;
	t_sample m_history_133;
	t_sample m_knob4_gain_134;
	t_sample m_y_14;
	t_sample __m_slide_141;
	t_sample __m_latch_144;
	t_sample m_y_123;
	t_sample m_knob5_noise_138;
	t_sample m_sw_136;
	t_sample m_knob3_res_137;
	t_sample m_sw_135;
	t_sample m_x_13;
	t_sample m_y_122;
	t_sample m_x_120;
	t_sample m_y_107;
	t_sample m_x_108;
	t_sample m_x_109;
	t_sample m_y_110;
	t_sample m_y_106;
	t_sample m_x_104;
	t_sample m_x_105;
	t_sample m_y_103;
	t_sample m_x_121;
	t_sample m_y_111;
	t_sample m_x_113;
	t_sample m_y_118;
	t_sample m_y_119;
	t_sample m_x_112;
	t_sample m_x_117;
	t_sample m_y_115;
	t_sample m_x_116;
	t_sample m_y_114;
	t_sample __m_slide_146;
	t_sample __m_latch_149;
	t_sample m_x_12;
	t_sample __m_latch_194;
	t_sample m_y_3;
	t_sample __m_slide_196;
	t_sample __m_latch_199;
	t_sample __m_slide_191;
	t_sample __m_latch_189;
	t_sample m_x_4;
	t_sample __m_slide_186;
	t_sample m_x_5;
	t_sample m_y_2;
	t_sample __m_latch_204;
	t_sample __m_slide_211;
	t_sample __m_latch_214;
	t_sample __m_slide_216;
	t_sample __m_slide_201;
	t_sample samplerate;
	t_sample __m_slide_206;
	t_sample __m_latch_209;
	t_sample m_history_1;
	t_sample m_y_102;
	t_sample __m_latch_184;
	t_sample m_y_6;
	t_sample __m_latch_159;
	t_sample m_y_10;
	t_sample __m_slide_161;
	t_sample __m_latch_164;
	t_sample __m_slide_156;
	t_sample __m_latch_154;
	t_sample m_y_11;
	t_sample __m_slide_151;
	t_sample __m_slide_181;
	t_sample m_x_9;
	t_sample __m_latch_169;
	t_sample __m_slide_176;
	t_sample __m_latch_179;
	t_sample __m_slide_166;
	t_sample m_y_7;
	t_sample __m_slide_171;
	t_sample __m_latch_174;
	t_sample m_x_8;
	t_sample m_y_15;
	t_sample m_x_101;
	t_sample m_y_99;
	t_sample m_y_42;
	t_sample m_y_43;
	t_sample m_x_44;
	t_sample m_x_45;
	t_sample m_x_41;
	t_sample m_y_39;
	t_sample m_x_40;
	t_sample m_y_38;
	t_sample m_x_37;
	t_sample m_y_46;
	t_sample m_x_48;
	t_sample m_x_53;
	t_sample m_y_54;
	t_sample m_y_55;
	t_sample m_y_47;
	t_sample m_x_52;
	t_sample m_y_50;
	t_sample m_y_51;
	t_sample m_x_49;
	t_sample m_x_56;
	t_sample m_x_36;
	t_sample m_y_34;
	t_sample m_x_21;
	t_sample m_y_22;
	t_sample m_y_23;
	t_sample m_x_24;
	t_sample m_x_20;
	t_sample m_y_18;
	t_sample m_y_19;
	t_sample m_x_17;
	t_sample m_y_35;
	t_sample m_x_25;
	t_sample m_y_27;
	t_sample m_x_32;
	t_sample m_x_33;
	t_sample m_y_26;
	t_sample m_y_31;
	t_sample m_x_29;
	t_sample m_y_30;
	t_sample m_x_28;
	t_sample m_x_100;
	t_sample m_x_57;
	t_sample m_y_59;
	t_sample m_x_85;
	t_sample m_y_86;
	t_sample m_y_87;
	t_sample m_x_88;
	t_sample m_x_84;
	t_sample m_y_82;
	t_sample m_y_83;
	t_sample m_x_81;
	t_sample m_x_80;
	t_sample m_x_89;
	t_sample m_y_91;
	t_sample m_x_96;
	t_sample m_x_97;
	t_sample m_y_98;
	t_sample m_y_90;
	t_sample m_y_95;
	t_sample m_x_93;
	t_sample m_y_94;
	t_sample __m_latch_219;
	t_sample m_y_58;
	t_sample m_y_79;
	t_sample m_x_77;
	t_sample m_x_64;
	t_sample m_x_65;
	t_sample m_y_66;
	t_sample m_y_67;
	t_sample m_y_63;
	t_sample m_x_61;
	t_sample m_y_62;
	t_sample m_x_60;
	t_sample m_y_78;
	t_sample m_x_68;
	t_sample m_y_70;
	t_sample m_y_75;
	t_sample m_x_76;
	t_sample m_x_69;
	t_sample m_y_74;
	t_sample m_x_72;
	t_sample m_x_73;
	t_sample m_y_71;
	t_sample m_x_92;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_y_2 = ((int)0);
		m_y_3 = ((int)0);
		m_x_4 = ((int)0);
		m_x_5 = ((int)0);
		m_y_6 = ((int)0);
		m_y_7 = ((int)0);
		m_x_8 = ((int)0);
		m_x_9 = ((int)0);
		m_y_10 = ((int)0);
		m_y_11 = ((int)0);
		m_x_12 = ((int)0);
		m_x_13 = ((int)0);
		m_y_14 = ((int)0);
		m_y_15 = ((int)0);
		m_x_16 = ((int)0);
		m_x_17 = ((int)0);
		m_y_18 = ((int)0);
		m_y_19 = ((int)0);
		m_x_20 = ((int)0);
		m_x_21 = ((int)0);
		m_y_22 = ((int)0);
		m_y_23 = ((int)0);
		m_x_24 = ((int)0);
		m_x_25 = ((int)0);
		m_y_26 = ((int)0);
		m_y_27 = ((int)0);
		m_x_28 = ((int)0);
		m_x_29 = ((int)0);
		m_y_30 = ((int)0);
		m_y_31 = ((int)0);
		m_x_32 = ((int)0);
		m_x_33 = ((int)0);
		m_y_34 = ((int)0);
		m_y_35 = ((int)0);
		m_x_36 = ((int)0);
		m_x_37 = ((int)0);
		m_y_38 = ((int)0);
		m_y_39 = ((int)0);
		m_x_40 = ((int)0);
		m_x_41 = ((int)0);
		m_y_42 = ((int)0);
		m_y_43 = ((int)0);
		m_x_44 = ((int)0);
		m_x_45 = ((int)0);
		m_y_46 = ((int)0);
		m_y_47 = ((int)0);
		m_x_48 = ((int)0);
		m_x_49 = ((int)0);
		m_y_50 = ((int)0);
		m_y_51 = ((int)0);
		m_x_52 = ((int)0);
		m_x_53 = ((int)0);
		m_y_54 = ((int)0);
		m_y_55 = ((int)0);
		m_x_56 = ((int)0);
		m_x_57 = ((int)0);
		m_y_58 = ((int)0);
		m_y_59 = ((int)0);
		m_x_60 = ((int)0);
		m_x_61 = ((int)0);
		m_y_62 = ((int)0);
		m_y_63 = ((int)0);
		m_x_64 = ((int)0);
		m_x_65 = ((int)0);
		m_y_66 = ((int)0);
		m_y_67 = ((int)0);
		m_x_68 = ((int)0);
		m_x_69 = ((int)0);
		m_y_70 = ((int)0);
		m_y_71 = ((int)0);
		m_x_72 = ((int)0);
		m_x_73 = ((int)0);
		m_y_74 = ((int)0);
		m_y_75 = ((int)0);
		m_x_76 = ((int)0);
		m_x_77 = ((int)0);
		m_y_78 = ((int)0);
		m_y_79 = ((int)0);
		m_x_80 = ((int)0);
		m_x_81 = ((int)0);
		m_y_82 = ((int)0);
		m_y_83 = ((int)0);
		m_x_84 = ((int)0);
		m_x_85 = ((int)0);
		m_y_86 = ((int)0);
		m_y_87 = ((int)0);
		m_x_88 = ((int)0);
		m_x_89 = ((int)0);
		m_y_90 = ((int)0);
		m_y_91 = ((int)0);
		m_x_92 = ((int)0);
		m_x_93 = ((int)0);
		m_y_94 = ((int)0);
		m_y_95 = ((int)0);
		m_x_96 = ((int)0);
		m_x_97 = ((int)0);
		m_y_98 = ((int)0);
		m_y_99 = ((int)0);
		m_x_100 = ((int)0);
		m_x_101 = ((int)0);
		m_y_102 = ((int)0);
		m_y_103 = ((int)0);
		m_x_104 = ((int)0);
		m_x_105 = ((int)0);
		m_y_106 = ((int)0);
		m_y_107 = ((int)0);
		m_x_108 = ((int)0);
		m_x_109 = ((int)0);
		m_y_110 = ((int)0);
		m_y_111 = ((int)0);
		m_x_112 = ((int)0);
		m_x_113 = ((int)0);
		m_y_114 = ((int)0);
		m_y_115 = ((int)0);
		m_x_116 = ((int)0);
		m_x_117 = ((int)0);
		m_y_118 = ((int)0);
		m_y_119 = ((int)0);
		m_x_120 = ((int)0);
		m_x_121 = ((int)0);
		m_y_122 = ((int)0);
		m_y_123 = ((int)0);
		m_x_124 = ((int)0);
		m_x_125 = ((int)0);
		m_y_126 = ((int)0);
		m_y_127 = ((int)0);
		m_x_128 = ((int)0);
		m_x_129 = ((int)0);
		m_history_130 = ((int)0);
		m_history_131 = ((int)0);
		m_history_132 = ((int)0);
		m_history_133 = ((int)0);
		m_knob4_gain_134 = 5;
		m_sw_135 = 0;
		m_sw_136 = ((int)0);
		m_knob3_res_137 = 15;
		m_knob5_noise_138 = 0;
		__m_sah_139.reset(0);
		__m_slide_141 = 0;
		__m_latch_144 = 0;
		__m_dcblock_145.reset();
		__m_slide_146 = 0;
		__m_latch_149 = 0;
		__m_dcblock_150.reset();
		__m_slide_151 = 0;
		__m_latch_154 = 0;
		__m_dcblock_155.reset();
		__m_slide_156 = 0;
		__m_latch_159 = 0;
		__m_dcblock_160.reset();
		__m_slide_161 = 0;
		__m_latch_164 = 0;
		__m_dcblock_165.reset();
		__m_slide_166 = 0;
		__m_latch_169 = 0;
		__m_dcblock_170.reset();
		__m_slide_171 = 0;
		__m_latch_174 = 0;
		__m_dcblock_175.reset();
		__m_slide_176 = 0;
		__m_latch_179 = 0;
		__m_dcblock_180.reset();
		__m_slide_181 = 0;
		__m_latch_184 = 0;
		__m_dcblock_185.reset();
		__m_slide_186 = 0;
		__m_latch_189 = 0;
		__m_dcblock_190.reset();
		__m_slide_191 = 0;
		__m_latch_194 = 0;
		__m_dcblock_195.reset();
		__m_slide_196 = 0;
		__m_latch_199 = 0;
		__m_dcblock_200.reset();
		__m_slide_201 = 0;
		__m_latch_204 = 0;
		__m_dcblock_205.reset();
		__m_slide_206 = 0;
		__m_latch_209 = 0;
		__m_dcblock_210.reset();
		__m_slide_211 = 0;
		__m_latch_214 = 0;
		__m_dcblock_215.reset();
		__m_slide_216 = 0;
		__m_latch_219 = 0;
		__m_dcblock_220.reset();
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
		t_sample rsub_43491 = (((int)1) - m_sw_135);
		t_sample mstosamps_43891 = (((int)2) * (samplerate * 0.001));
		t_sample mstosamps_43982 = (((int)20) * (samplerate * 0.001));
		t_sample twopi_over_sr = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43831 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_142 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_143 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44008 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43805 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_147 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_148 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44026 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43779 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_152 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_153 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44032 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43753 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_157 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_158 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44050 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43727 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_162 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_163 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44068 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43701 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_167 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_168 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44085 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43675 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_172 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_173 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44103 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43649 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_177 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_178 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44122 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43623 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_182 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_183 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44139 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43597 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_187 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_188 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44158 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43572 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_192 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_193 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44176 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43546 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_197 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_198 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44194 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43519 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_202 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_203 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44211 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43954 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_207 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_208 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44229 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43883 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_212 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_213 = (1 / maximum(1, abs(mstosamps_43982)));
		t_sample twopi_over_sr_44247 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_43857 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_217 = (1 / maximum(1, abs(mstosamps_43891)));
		t_sample idown_218 = (1 / maximum(1, abs(mstosamps_43982)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_43989 = __m_sah_139(m_history_133, m_sw_136, ((int)0));
			t_sample gen_43991 = sah_43989;
			t_sample rsub_43987 = (((int)1) - sah_43989);
			t_sample history_43988_next_43990 = fixdenorm(rsub_43987);
			t_sample out3 = gen_43991;
			t_sample add_43992 = (gen_43991 + ((int)1));
			t_sample choice_140 = int(add_43992);
			t_sample gate_43984 = (((choice_140 >= 1) && (choice_140 < 2)) ? in1 : 0);
			t_sample gate_43985 = ((choice_140 >= 2) ? in1 : 0);
			t_sample noise_43498 = noise();
			t_sample mul_43492 = (noise_43498 * ((t_sample)0.5));
			t_sample add_43494 = (mul_43492 + m_history_1);
			t_sample mul_43493 = (add_43494 * ((t_sample)0.5));
			t_sample mix_44278 = (m_history_132 + (((t_sample)0.0019634941468452) * (m_knob3_res_137 - m_history_132)));
			t_sample mix_43972 = mix_44278;
			t_sample mix_44279 = (m_history_131 + (((t_sample)0.0019634941468452) * (mix_43972 - m_history_131)));
			t_sample mix_43970 = mix_44279;
			t_sample mix_44280 = (m_history_130 + (((t_sample)0.0019634941468452) * (mix_43970 - m_history_130)));
			t_sample mix_43968 = mix_44280;
			t_sample gen_43980 = mix_43968;
			t_sample history_43974_next_43977 = fixdenorm(mix_43972);
			t_sample history_43971_next_43978 = fixdenorm(mix_43970);
			t_sample history_43969_next_43979 = fixdenorm(mix_43968);
			t_sample mul_43497 = (add_43494 * m_knob5_noise_138);
			t_sample add_43496 = (gate_43985 + mul_43497);
			t_sample x = add_43496;
			t_sample q = gen_43980;
			t_sample bw = safediv(((t_sample)284.5), q);
			t_sample r = exp(((-bw) * twopi_over_sr));
			t_sample c1 = ((((int)2) * r) * cos((((t_sample)284.5) * twopi_over_sr)));
			t_sample c2 = ((-r) * r);
			t_sample y = ((((((int)1) - r) * (x - (r * m_x_128))) + (c1 * m_y_127)) + (c2 * m_y_126));
			m_y_126 = m_y_127;
			m_y_127 = y;
			m_x_128 = m_x_129;
			m_x_129 = x;
			t_sample x_43828 = in2;
			t_sample q_43820 = gen_43980;
			t_sample bw_43829 = safediv(((t_sample)284.5), q_43820);
			t_sample r_43822 = exp(((-bw_43829) * twopi_over_sr_43831));
			t_sample c_43830 = ((((int)2) * r_43822) * cos((((t_sample)284.5) * twopi_over_sr_43831)));
			t_sample c_43833 = ((-r_43822) * r_43822);
			t_sample y_43832 = ((((((int)1) - r_43822) * (x_43828 - (r_43822 * m_x_124))) + (c_43830 * m_y_123)) + (c_43833 * m_y_122));
			m_y_122 = m_y_123;
			m_y_123 = y_43832;
			m_x_124 = m_x_125;
			m_x_125 = x_43828;
			t_sample abs_43819 = fabs(y_43832);
			__m_slide_141 = fixdenorm((__m_slide_141 + (((abs_43819 > __m_slide_141) ? iup_142 : idown_143) * (abs_43819 - __m_slide_141))));
			t_sample slide_43818 = __m_slide_141;
			__m_latch_144 = ((rsub_43491 != 0) ? slide_43818 : __m_latch_144);
			t_sample latch_43813 = __m_latch_144;
			t_sample mul_43815 = (y * latch_43813);
			t_sample dcblock_43814 = __m_dcblock_145(mul_43815);
			t_sample x_44001 = add_43496;
			t_sample q_43998 = gen_43980;
			t_sample bw_44002 = safediv(((t_sample)358.5), q_43998);
			t_sample r_43999 = exp(((-bw_44002) * twopi_over_sr_44008));
			t_sample c_44004 = ((((int)2) * r_43999) * cos((((t_sample)358.5) * twopi_over_sr_44008)));
			t_sample c_43997 = ((-r_43999) * r_43999);
			t_sample y_44000 = ((((((int)1) - r_43999) * (x_44001 - (r_43999 * m_x_120))) + (c_44004 * m_y_119)) + (c_43997 * m_y_118));
			m_y_118 = m_y_119;
			m_y_119 = y_44000;
			m_x_120 = m_x_121;
			m_x_121 = x_44001;
			t_sample x_43802 = in2;
			t_sample q_43794 = gen_43980;
			t_sample bw_43803 = safediv(((t_sample)358.5), q_43794);
			t_sample r_43796 = exp(((-bw_43803) * twopi_over_sr_43805));
			t_sample c_43804 = ((((int)2) * r_43796) * cos((((t_sample)358.5) * twopi_over_sr_43805)));
			t_sample c_43807 = ((-r_43796) * r_43796);
			t_sample y_43806 = ((((((int)1) - r_43796) * (x_43802 - (r_43796 * m_x_116))) + (c_43804 * m_y_115)) + (c_43807 * m_y_114));
			m_y_114 = m_y_115;
			m_y_115 = y_43806;
			m_x_116 = m_x_117;
			m_x_117 = x_43802;
			t_sample abs_43793 = fabs(y_43806);
			__m_slide_146 = fixdenorm((__m_slide_146 + (((abs_43793 > __m_slide_146) ? iup_147 : idown_148) * (abs_43793 - __m_slide_146))));
			t_sample slide_43792 = __m_slide_146;
			__m_latch_149 = ((rsub_43491 != 0) ? slide_43792 : __m_latch_149);
			t_sample latch_43787 = __m_latch_149;
			t_sample mul_43789 = (y_44000 * latch_43787);
			t_sample dcblock_43788 = __m_dcblock_150(mul_43789);
			t_sample x_44018 = add_43496;
			t_sample q_44015 = gen_43980;
			t_sample bw_44025 = safediv(((int)452), q_44015);
			t_sample r_44016 = exp(((-bw_44025) * twopi_over_sr_44026));
			t_sample c_44020 = ((((int)2) * r_44016) * cos((((int)452) * twopi_over_sr_44026)));
			t_sample c_44021 = ((-r_44016) * r_44016);
			t_sample y_44017 = ((((((int)1) - r_44016) * (x_44018 - (r_44016 * m_x_112))) + (c_44020 * m_y_111)) + (c_44021 * m_y_110));
			m_y_110 = m_y_111;
			m_y_111 = y_44017;
			m_x_112 = m_x_113;
			m_x_113 = x_44018;
			t_sample x_43776 = in2;
			t_sample q_43768 = gen_43980;
			t_sample bw_43777 = safediv(((int)452), q_43768);
			t_sample r_43770 = exp(((-bw_43777) * twopi_over_sr_43779));
			t_sample c_43778 = ((((int)2) * r_43770) * cos((((int)452) * twopi_over_sr_43779)));
			t_sample c_43781 = ((-r_43770) * r_43770);
			t_sample y_43780 = ((((((int)1) - r_43770) * (x_43776 - (r_43770 * m_x_108))) + (c_43778 * m_y_107)) + (c_43781 * m_y_106));
			m_y_106 = m_y_107;
			m_y_107 = y_43780;
			m_x_108 = m_x_109;
			m_x_109 = x_43776;
			t_sample abs_43767 = fabs(y_43780);
			__m_slide_151 = fixdenorm((__m_slide_151 + (((abs_43767 > __m_slide_151) ? iup_152 : idown_153) * (abs_43767 - __m_slide_151))));
			t_sample slide_43766 = __m_slide_151;
			__m_latch_154 = ((rsub_43491 != 0) ? slide_43766 : __m_latch_154);
			t_sample latch_43761 = __m_latch_154;
			t_sample mul_43763 = (y_44017 * latch_43761);
			t_sample dcblock_43762 = __m_dcblock_155(mul_43763);
			t_sample x_44044 = add_43496;
			t_sample q_44040 = gen_43980;
			t_sample bw_44036 = safediv(((t_sample)569.5), q_44040);
			t_sample r_44035 = exp(((-bw_44036) * twopi_over_sr_44032));
			t_sample c_44038 = ((((int)2) * r_44035) * cos((((t_sample)569.5) * twopi_over_sr_44032)));
			t_sample c_44031 = ((-r_44035) * r_44035);
			t_sample y_44043 = ((((((int)1) - r_44035) * (x_44044 - (r_44035 * m_x_104))) + (c_44038 * m_y_103)) + (c_44031 * m_y_102));
			m_y_102 = m_y_103;
			m_y_103 = y_44043;
			m_x_104 = m_x_105;
			m_x_105 = x_44044;
			t_sample x_43750 = in2;
			t_sample q_43742 = gen_43980;
			t_sample bw_43751 = safediv(((t_sample)569.5), q_43742);
			t_sample r_43744 = exp(((-bw_43751) * twopi_over_sr_43753));
			t_sample c_43752 = ((((int)2) * r_43744) * cos((((t_sample)569.5) * twopi_over_sr_43753)));
			t_sample c_43755 = ((-r_43744) * r_43744);
			t_sample y_43754 = ((((((int)1) - r_43744) * (x_43750 - (r_43744 * m_x_100))) + (c_43752 * m_y_99)) + (c_43755 * m_y_98));
			m_y_98 = m_y_99;
			m_y_99 = y_43754;
			m_x_100 = m_x_101;
			m_x_101 = x_43750;
			t_sample abs_43741 = fabs(y_43754);
			__m_slide_156 = fixdenorm((__m_slide_156 + (((abs_43741 > __m_slide_156) ? iup_157 : idown_158) * (abs_43741 - __m_slide_156))));
			t_sample slide_43740 = __m_slide_156;
			__m_latch_159 = ((rsub_43491 != 0) ? slide_43740 : __m_latch_159);
			t_sample latch_43735 = __m_latch_159;
			t_sample mul_43737 = (y_44043 * latch_43735);
			t_sample dcblock_43736 = __m_dcblock_160(mul_43737);
			t_sample x_44061 = add_43496;
			t_sample q_44054 = gen_43980;
			t_sample bw_44056 = safediv(((t_sample)717.5), q_44054);
			t_sample r_44055 = exp(((-bw_44056) * twopi_over_sr_44050));
			t_sample c_44058 = ((((int)2) * r_44055) * cos((((t_sample)717.5) * twopi_over_sr_44050)));
			t_sample c_44049 = ((-r_44055) * r_44055);
			t_sample y_44051 = ((((((int)1) - r_44055) * (x_44061 - (r_44055 * m_x_96))) + (c_44058 * m_y_95)) + (c_44049 * m_y_94));
			m_y_94 = m_y_95;
			m_y_95 = y_44051;
			m_x_96 = m_x_97;
			m_x_97 = x_44061;
			t_sample x_43724 = in2;
			t_sample q_43716 = gen_43980;
			t_sample bw_43725 = safediv(((t_sample)717.5), q_43716);
			t_sample r_43718 = exp(((-bw_43725) * twopi_over_sr_43727));
			t_sample c_43726 = ((((int)2) * r_43718) * cos((((t_sample)717.5) * twopi_over_sr_43727)));
			t_sample c_43729 = ((-r_43718) * r_43718);
			t_sample y_43728 = ((((((int)1) - r_43718) * (x_43724 - (r_43718 * m_x_92))) + (c_43726 * m_y_91)) + (c_43729 * m_y_90));
			m_y_90 = m_y_91;
			m_y_91 = y_43728;
			m_x_92 = m_x_93;
			m_x_93 = x_43724;
			t_sample abs_43715 = fabs(y_43728);
			__m_slide_161 = fixdenorm((__m_slide_161 + (((abs_43715 > __m_slide_161) ? iup_162 : idown_163) * (abs_43715 - __m_slide_161))));
			t_sample slide_43714 = __m_slide_161;
			__m_latch_164 = ((rsub_43491 != 0) ? slide_43714 : __m_latch_164);
			t_sample latch_43709 = __m_latch_164;
			t_sample mul_43711 = (y_44051 * latch_43709);
			t_sample dcblock_43710 = __m_dcblock_165(mul_43711);
			t_sample x_44074 = add_43496;
			t_sample q_44071 = gen_43980;
			t_sample bw_44075 = safediv(((int)904), q_44071);
			t_sample r_44072 = exp(((-bw_44075) * twopi_over_sr_44068));
			t_sample c_44077 = ((((int)2) * r_44072) * cos((((int)904) * twopi_over_sr_44068)));
			t_sample c_44067 = ((-r_44072) * r_44072);
			t_sample y_44073 = ((((((int)1) - r_44072) * (x_44074 - (r_44072 * m_x_88))) + (c_44077 * m_y_87)) + (c_44067 * m_y_86));
			m_y_86 = m_y_87;
			m_y_87 = y_44073;
			m_x_88 = m_x_89;
			m_x_89 = x_44074;
			t_sample x_43698 = in2;
			t_sample q_43690 = gen_43980;
			t_sample bw_43699 = safediv(((int)904), q_43690);
			t_sample r_43692 = exp(((-bw_43699) * twopi_over_sr_43701));
			t_sample c_43700 = ((((int)2) * r_43692) * cos((((int)904) * twopi_over_sr_43701)));
			t_sample c_43703 = ((-r_43692) * r_43692);
			t_sample y_43702 = ((((((int)1) - r_43692) * (x_43698 - (r_43692 * m_x_84))) + (c_43700 * m_y_83)) + (c_43703 * m_y_82));
			m_y_82 = m_y_83;
			m_y_83 = y_43702;
			m_x_84 = m_x_85;
			m_x_85 = x_43698;
			t_sample abs_43689 = fabs(y_43702);
			__m_slide_166 = fixdenorm((__m_slide_166 + (((abs_43689 > __m_slide_166) ? iup_167 : idown_168) * (abs_43689 - __m_slide_166))));
			t_sample slide_43688 = __m_slide_166;
			__m_latch_169 = ((rsub_43491 != 0) ? slide_43688 : __m_latch_169);
			t_sample latch_43683 = __m_latch_169;
			t_sample mul_43685 = (y_44073 * latch_43683);
			t_sample dcblock_43684 = __m_dcblock_170(mul_43685);
			t_sample x_44090 = add_43496;
			t_sample q_44098 = gen_43980;
			t_sample bw_44094 = safediv(((int)1139), q_44098);
			t_sample r_44088 = exp(((-bw_44094) * twopi_over_sr_44085));
			t_sample c_44091 = ((((int)2) * r_44088) * cos((((int)1139) * twopi_over_sr_44085)));
			t_sample c_44096 = ((-r_44088) * r_44088);
			t_sample y_44089 = ((((((int)1) - r_44088) * (x_44090 - (r_44088 * m_x_80))) + (c_44091 * m_y_79)) + (c_44096 * m_y_78));
			m_y_78 = m_y_79;
			m_y_79 = y_44089;
			m_x_80 = m_x_81;
			m_x_81 = x_44090;
			t_sample x_43672 = in2;
			t_sample q_43664 = gen_43980;
			t_sample bw_43673 = safediv(((int)1139), q_43664);
			t_sample r_43666 = exp(((-bw_43673) * twopi_over_sr_43675));
			t_sample c_43674 = ((((int)2) * r_43666) * cos((((int)1139) * twopi_over_sr_43675)));
			t_sample c_43677 = ((-r_43666) * r_43666);
			t_sample y_43676 = ((((((int)1) - r_43666) * (x_43672 - (r_43666 * m_x_76))) + (c_43674 * m_y_75)) + (c_43677 * m_y_74));
			m_y_74 = m_y_75;
			m_y_75 = y_43676;
			m_x_76 = m_x_77;
			m_x_77 = x_43672;
			t_sample abs_43663 = fabs(y_43676);
			__m_slide_171 = fixdenorm((__m_slide_171 + (((abs_43663 > __m_slide_171) ? iup_172 : idown_173) * (abs_43663 - __m_slide_171))));
			t_sample slide_43662 = __m_slide_171;
			__m_latch_174 = ((rsub_43491 != 0) ? slide_43662 : __m_latch_174);
			t_sample latch_43657 = __m_latch_174;
			t_sample mul_43659 = (y_44089 * latch_43657);
			t_sample dcblock_43658 = __m_dcblock_175(mul_43659);
			t_sample x_44108 = add_43496;
			t_sample q_44115 = gen_43980;
			t_sample bw_44111 = safediv(((int)1435), q_44115);
			t_sample r_44106 = exp(((-bw_44111) * twopi_over_sr_44103));
			t_sample c_44109 = ((((int)2) * r_44106) * cos((((int)1435) * twopi_over_sr_44103)));
			t_sample c_44113 = ((-r_44106) * r_44106);
			t_sample y_44107 = ((((((int)1) - r_44106) * (x_44108 - (r_44106 * m_x_72))) + (c_44109 * m_y_71)) + (c_44113 * m_y_70));
			m_y_70 = m_y_71;
			m_y_71 = y_44107;
			m_x_72 = m_x_73;
			m_x_73 = x_44108;
			t_sample x_43646 = in2;
			t_sample q_43638 = gen_43980;
			t_sample bw_43647 = safediv(((int)1435), q_43638);
			t_sample r_43640 = exp(((-bw_43647) * twopi_over_sr_43649));
			t_sample c_43648 = ((((int)2) * r_43640) * cos((((int)1435) * twopi_over_sr_43649)));
			t_sample c_43651 = ((-r_43640) * r_43640);
			t_sample y_43650 = ((((((int)1) - r_43640) * (x_43646 - (r_43640 * m_x_68))) + (c_43648 * m_y_67)) + (c_43651 * m_y_66));
			m_y_66 = m_y_67;
			m_y_67 = y_43650;
			m_x_68 = m_x_69;
			m_x_69 = x_43646;
			t_sample abs_43637 = fabs(y_43650);
			__m_slide_176 = fixdenorm((__m_slide_176 + (((abs_43637 > __m_slide_176) ? iup_177 : idown_178) * (abs_43637 - __m_slide_176))));
			t_sample slide_43636 = __m_slide_176;
			__m_latch_179 = ((rsub_43491 != 0) ? slide_43636 : __m_latch_179);
			t_sample latch_43631 = __m_latch_179;
			t_sample mul_43633 = (y_44107 * latch_43631);
			t_sample dcblock_43632 = __m_dcblock_180(mul_43633);
			t_sample x_44128 = add_43496;
			t_sample q_44125 = gen_43980;
			t_sample bw_44132 = safediv(((int)1808), q_44125);
			t_sample r_44126 = exp(((-bw_44132) * twopi_over_sr_44122));
			t_sample c_44129 = ((((int)2) * r_44126) * cos((((int)1808) * twopi_over_sr_44122)));
			t_sample c_44121 = ((-r_44126) * r_44126);
			t_sample y_44127 = ((((((int)1) - r_44126) * (x_44128 - (r_44126 * m_x_64))) + (c_44129 * m_y_63)) + (c_44121 * m_y_62));
			m_y_62 = m_y_63;
			m_y_63 = y_44127;
			m_x_64 = m_x_65;
			m_x_65 = x_44128;
			t_sample x_43620 = in2;
			t_sample q_43612 = gen_43980;
			t_sample bw_43621 = safediv(((int)1808), q_43612);
			t_sample r_43614 = exp(((-bw_43621) * twopi_over_sr_43623));
			t_sample c_43622 = ((((int)2) * r_43614) * cos((((int)1808) * twopi_over_sr_43623)));
			t_sample c_43625 = ((-r_43614) * r_43614);
			t_sample y_43624 = ((((((int)1) - r_43614) * (x_43620 - (r_43614 * m_x_60))) + (c_43622 * m_y_59)) + (c_43625 * m_y_58));
			m_y_58 = m_y_59;
			m_y_59 = y_43624;
			m_x_60 = m_x_61;
			m_x_61 = x_43620;
			t_sample abs_43611 = fabs(y_43624);
			__m_slide_181 = fixdenorm((__m_slide_181 + (((abs_43611 > __m_slide_181) ? iup_182 : idown_183) * (abs_43611 - __m_slide_181))));
			t_sample slide_43610 = __m_slide_181;
			__m_latch_184 = ((rsub_43491 != 0) ? slide_43610 : __m_latch_184);
			t_sample latch_43605 = __m_latch_184;
			t_sample mul_43607 = (y_44127 * latch_43605);
			t_sample dcblock_43606 = __m_dcblock_185(mul_43607);
			t_sample x_44144 = add_43496;
			t_sample q_44152 = gen_43980;
			t_sample bw_44148 = safediv(((int)2260), q_44152);
			t_sample r_44142 = exp(((-bw_44148) * twopi_over_sr_44139));
			t_sample c_44145 = ((((int)2) * r_44142) * cos((((int)2260) * twopi_over_sr_44139)));
			t_sample c_44150 = ((-r_44142) * r_44142);
			t_sample y_44143 = ((((((int)1) - r_44142) * (x_44144 - (r_44142 * m_x_56))) + (c_44145 * m_y_55)) + (c_44150 * m_y_54));
			m_y_54 = m_y_55;
			m_y_55 = y_44143;
			m_x_56 = m_x_57;
			m_x_57 = x_44144;
			t_sample x_43594 = in2;
			t_sample q_43586 = gen_43980;
			t_sample bw_43595 = safediv(((int)2260), q_43586);
			t_sample r_43588 = exp(((-bw_43595) * twopi_over_sr_43597));
			t_sample c_43596 = ((((int)2) * r_43588) * cos((((int)2260) * twopi_over_sr_43597)));
			t_sample c_43599 = ((-r_43588) * r_43588);
			t_sample y_43598 = ((((((int)1) - r_43588) * (x_43594 - (r_43588 * m_x_52))) + (c_43596 * m_y_51)) + (c_43599 * m_y_50));
			m_y_50 = m_y_51;
			m_y_51 = y_43598;
			m_x_52 = m_x_53;
			m_x_53 = x_43594;
			t_sample abs_43585 = fabs(y_43598);
			__m_slide_186 = fixdenorm((__m_slide_186 + (((abs_43585 > __m_slide_186) ? iup_187 : idown_188) * (abs_43585 - __m_slide_186))));
			t_sample slide_43584 = __m_slide_186;
			__m_latch_189 = ((rsub_43491 != 0) ? slide_43584 : __m_latch_189);
			t_sample latch_43579 = __m_latch_189;
			t_sample mul_43581 = (y_44143 * latch_43579);
			t_sample dcblock_43580 = __m_dcblock_190(mul_43581);
			t_sample x_44163 = add_43496;
			t_sample q_44169 = gen_43980;
			t_sample bw_44167 = safediv(((int)2852), q_44169);
			t_sample r_44161 = exp(((-bw_44167) * twopi_over_sr_44158));
			t_sample c_44164 = ((((int)2) * r_44161) * cos((((int)2852) * twopi_over_sr_44158)));
			t_sample c_44157 = ((-r_44161) * r_44161);
			t_sample y_44162 = ((((((int)1) - r_44161) * (x_44163 - (r_44161 * m_x_48))) + (c_44164 * m_y_47)) + (c_44157 * m_y_46));
			m_y_46 = m_y_47;
			m_y_47 = y_44162;
			m_x_48 = m_x_49;
			m_x_49 = x_44163;
			t_sample x_43568 = in2;
			t_sample q_43560 = gen_43980;
			t_sample bw_43569 = safediv(((int)2852), q_43560);
			t_sample r_43562 = exp(((-bw_43569) * twopi_over_sr_43572));
			t_sample c_43571 = ((((int)2) * r_43562) * cos((((int)2852) * twopi_over_sr_43572)));
			t_sample c_43573 = ((-r_43562) * r_43562);
			t_sample y_43570 = ((((((int)1) - r_43562) * (x_43568 - (r_43562 * m_x_44))) + (c_43571 * m_y_43)) + (c_43573 * m_y_42));
			m_y_42 = m_y_43;
			m_y_43 = y_43570;
			m_x_44 = m_x_45;
			m_x_45 = x_43568;
			t_sample abs_43559 = fabs(y_43570);
			__m_slide_191 = fixdenorm((__m_slide_191 + (((abs_43559 > __m_slide_191) ? iup_192 : idown_193) * (abs_43559 - __m_slide_191))));
			t_sample slide_43558 = __m_slide_191;
			__m_latch_194 = ((rsub_43491 != 0) ? slide_43558 : __m_latch_194);
			t_sample latch_43553 = __m_latch_194;
			t_sample mul_43555 = (y_44162 * latch_43553);
			t_sample dcblock_43554 = __m_dcblock_195(mul_43555);
			t_sample x_44182 = add_43496;
			t_sample q_44179 = gen_43980;
			t_sample bw_44187 = safediv(((int)3616), q_44179);
			t_sample r_44180 = exp(((-bw_44187) * twopi_over_sr_44176));
			t_sample c_44183 = ((((int)2) * r_44180) * cos((((int)3616) * twopi_over_sr_44176)));
			t_sample c_44175 = ((-r_44180) * r_44180);
			t_sample y_44181 = ((((((int)1) - r_44180) * (x_44182 - (r_44180 * m_x_40))) + (c_44183 * m_y_39)) + (c_44175 * m_y_38));
			m_y_38 = m_y_39;
			m_y_39 = y_44181;
			m_x_40 = m_x_41;
			m_x_41 = x_44182;
			t_sample x_43542 = in2;
			t_sample q_43534 = gen_43980;
			t_sample bw_43543 = safediv(((int)3616), q_43534);
			t_sample r_43536 = exp(((-bw_43543) * twopi_over_sr_43546));
			t_sample c_43545 = ((((int)2) * r_43536) * cos((((int)3616) * twopi_over_sr_43546)));
			t_sample c_43547 = ((-r_43536) * r_43536);
			t_sample y_43544 = ((((((int)1) - r_43536) * (x_43542 - (r_43536 * m_x_36))) + (c_43545 * m_y_35)) + (c_43547 * m_y_34));
			m_y_34 = m_y_35;
			m_y_35 = y_43544;
			m_x_36 = m_x_37;
			m_x_37 = x_43542;
			t_sample abs_43533 = fabs(y_43544);
			__m_slide_196 = fixdenorm((__m_slide_196 + (((abs_43533 > __m_slide_196) ? iup_197 : idown_198) * (abs_43533 - __m_slide_196))));
			t_sample slide_43532 = __m_slide_196;
			__m_latch_199 = ((rsub_43491 != 0) ? slide_43532 : __m_latch_199);
			t_sample latch_43527 = __m_latch_199;
			t_sample mul_43529 = (y_44181 * latch_43527);
			t_sample dcblock_43528 = __m_dcblock_200(mul_43529);
			t_sample x_44200 = add_43496;
			t_sample q_44197 = gen_43980;
			t_sample bw_44204 = safediv(((int)4556), q_44197);
			t_sample r_44198 = exp(((-bw_44204) * twopi_over_sr_44194));
			t_sample c_44201 = ((((int)2) * r_44198) * cos((((int)4556) * twopi_over_sr_44194)));
			t_sample c_44193 = ((-r_44198) * r_44198);
			t_sample y_44199 = ((((((int)1) - r_44198) * (x_44200 - (r_44198 * m_x_32))) + (c_44201 * m_y_31)) + (c_44193 * m_y_30));
			m_y_30 = m_y_31;
			m_y_31 = y_44199;
			m_x_32 = m_x_33;
			m_x_33 = x_44200;
			t_sample x_43516 = in2;
			t_sample q_43508 = gen_43980;
			t_sample bw_43517 = safediv(((int)4556), q_43508);
			t_sample r_43510 = exp(((-bw_43517) * twopi_over_sr_43519));
			t_sample c_43518 = ((((int)2) * r_43510) * cos((((int)4556) * twopi_over_sr_43519)));
			t_sample c_43521 = ((-r_43510) * r_43510);
			t_sample y_43520 = ((((((int)1) - r_43510) * (x_43516 - (r_43510 * m_x_28))) + (c_43518 * m_y_27)) + (c_43521 * m_y_26));
			m_y_26 = m_y_27;
			m_y_27 = y_43520;
			m_x_28 = m_x_29;
			m_x_29 = x_43516;
			t_sample abs_43507 = fabs(y_43520);
			__m_slide_201 = fixdenorm((__m_slide_201 + (((abs_43507 > __m_slide_201) ? iup_202 : idown_203) * (abs_43507 - __m_slide_201))));
			t_sample slide_43506 = __m_slide_201;
			__m_latch_204 = ((rsub_43491 != 0) ? slide_43506 : __m_latch_204);
			t_sample latch_43499 = __m_latch_204;
			t_sample mul_43501 = (y_44199 * latch_43499);
			t_sample dcblock_43500 = __m_dcblock_205(mul_43501);
			t_sample x_44214 = add_43496;
			t_sample q_44221 = gen_43980;
			t_sample bw_44222 = safediv(((t_sample)104.5), q_44221);
			t_sample r_44212 = exp(((-bw_44222) * twopi_over_sr_44211));
			t_sample c_44218 = ((((int)2) * r_44212) * cos((((t_sample)104.5) * twopi_over_sr_44211)));
			t_sample c_44220 = ((-r_44212) * r_44212);
			t_sample y_44213 = ((((((int)1) - r_44212) * (x_44214 - (r_44212 * m_x_24))) + (c_44218 * m_y_23)) + (c_44220 * m_y_22));
			m_y_22 = m_y_23;
			m_y_23 = y_44213;
			m_x_24 = m_x_25;
			m_x_25 = x_44214;
			t_sample x_43950 = in2;
			t_sample q_43942 = gen_43980;
			t_sample bw_43951 = safediv(((t_sample)104.5), q_43942);
			t_sample r_43944 = exp(((-bw_43951) * twopi_over_sr_43954));
			t_sample c_43953 = ((((int)2) * r_43944) * cos((((t_sample)104.5) * twopi_over_sr_43954)));
			t_sample c_43955 = ((-r_43944) * r_43944);
			t_sample y_43952 = ((((((int)1) - r_43944) * (x_43950 - (r_43944 * m_x_20))) + (c_43953 * m_y_19)) + (c_43955 * m_y_18));
			m_y_18 = m_y_19;
			m_y_19 = y_43952;
			m_x_20 = m_x_21;
			m_x_21 = x_43950;
			t_sample abs_43941 = fabs(y_43952);
			__m_slide_206 = fixdenorm((__m_slide_206 + (((abs_43941 > __m_slide_206) ? iup_207 : idown_208) * (abs_43941 - __m_slide_206))));
			t_sample slide_43940 = __m_slide_206;
			__m_latch_209 = ((rsub_43491 != 0) ? slide_43940 : __m_latch_209);
			t_sample latch_43935 = __m_latch_209;
			t_sample mul_43937 = (y_44213 * latch_43935);
			t_sample dcblock_43936 = __m_dcblock_210(mul_43937);
			t_sample x_44232 = add_43496;
			t_sample q_44240 = gen_43980;
			t_sample bw_44239 = safediv(((t_sample)179.5), q_44240);
			t_sample r_44230 = exp(((-bw_44239) * twopi_over_sr_44229));
			t_sample c_44236 = ((((int)2) * r_44230) * cos((((t_sample)179.5) * twopi_over_sr_44229)));
			t_sample c_44238 = ((-r_44230) * r_44230);
			t_sample y_44231 = ((((((int)1) - r_44230) * (x_44232 - (r_44230 * m_x_16))) + (c_44236 * m_y_15)) + (c_44238 * m_y_14));
			m_y_14 = m_y_15;
			m_y_15 = y_44231;
			m_x_16 = m_x_17;
			m_x_17 = x_44232;
			t_sample x_43880 = in2;
			t_sample q_43872 = gen_43980;
			t_sample bw_43881 = safediv(((t_sample)179.5), q_43872);
			t_sample r_43874 = exp(((-bw_43881) * twopi_over_sr_43883));
			t_sample c_43882 = ((((int)2) * r_43874) * cos((((t_sample)179.5) * twopi_over_sr_43883)));
			t_sample c_43885 = ((-r_43874) * r_43874);
			t_sample y_43884 = ((((((int)1) - r_43874) * (x_43880 - (r_43874 * m_x_12))) + (c_43882 * m_y_11)) + (c_43885 * m_y_10));
			m_y_10 = m_y_11;
			m_y_11 = y_43884;
			m_x_12 = m_x_13;
			m_x_13 = x_43880;
			t_sample abs_43871 = fabs(y_43884);
			__m_slide_211 = fixdenorm((__m_slide_211 + (((abs_43871 > __m_slide_211) ? iup_212 : idown_213) * (abs_43871 - __m_slide_211))));
			t_sample slide_43870 = __m_slide_211;
			__m_latch_214 = ((rsub_43491 != 0) ? slide_43870 : __m_latch_214);
			t_sample latch_43865 = __m_latch_214;
			t_sample mul_43867 = (y_44231 * latch_43865);
			t_sample dcblock_43866 = __m_dcblock_215(mul_43867);
			t_sample x_44250 = add_43496;
			t_sample q_44259 = gen_43980;
			t_sample bw_44258 = safediv(((int)226), q_44259);
			t_sample r_44248 = exp(((-bw_44258) * twopi_over_sr_44247));
			t_sample c_44254 = ((((int)2) * r_44248) * cos((((int)226) * twopi_over_sr_44247)));
			t_sample c_44257 = ((-r_44248) * r_44248);
			t_sample y_44249 = ((((((int)1) - r_44248) * (x_44250 - (r_44248 * m_x_8))) + (c_44254 * m_y_7)) + (c_44257 * m_y_6));
			m_y_6 = m_y_7;
			m_y_7 = y_44249;
			m_x_8 = m_x_9;
			m_x_9 = x_44250;
			t_sample x_43854 = in2;
			t_sample q_43846 = gen_43980;
			t_sample bw_43855 = safediv(((int)226), q_43846);
			t_sample r_43848 = exp(((-bw_43855) * twopi_over_sr_43857));
			t_sample c_43856 = ((((int)2) * r_43848) * cos((((int)226) * twopi_over_sr_43857)));
			t_sample c_43859 = ((-r_43848) * r_43848);
			t_sample y_43858 = ((((((int)1) - r_43848) * (x_43854 - (r_43848 * m_x_4))) + (c_43856 * m_y_3)) + (c_43859 * m_y_2));
			m_y_2 = m_y_3;
			m_y_3 = y_43858;
			m_x_4 = m_x_5;
			m_x_5 = x_43854;
			t_sample abs_43845 = fabs(y_43858);
			__m_slide_216 = fixdenorm((__m_slide_216 + (((abs_43845 > __m_slide_216) ? iup_217 : idown_218) * (abs_43845 - __m_slide_216))));
			t_sample slide_43844 = __m_slide_216;
			__m_latch_219 = ((rsub_43491 != 0) ? slide_43844 : __m_latch_219);
			t_sample latch_43839 = __m_latch_219;
			t_sample mul_43841 = (y_44249 * latch_43839);
			t_sample dcblock_43840 = __m_dcblock_220(mul_43841);
			t_sample mul_43981 = ((((((((((((((((dcblock_43840 + dcblock_43866) + dcblock_43936) + dcblock_43500) + dcblock_43528) + dcblock_43554) + dcblock_43580) + dcblock_43606) + dcblock_43632) + dcblock_43658) + dcblock_43684) + dcblock_43710) + dcblock_43736) + dcblock_43762) + dcblock_43788) + dcblock_43814) * m_knob4_gain_134);
			t_sample add_43994 = (mul_43981 + gate_43984);
			t_sample out1 = add_43994;
			t_sample add_43993 = (mul_43981 + gate_43984);
			t_sample out2 = add_43993;
			t_sample history_43495_next_44265 = fixdenorm(mul_43493);
			m_history_133 = history_43988_next_43990;
			m_history_132 = history_43974_next_43977;
			m_history_130 = history_43969_next_43979;
			m_history_131 = history_43971_next_43978;
			m_history_1 = history_43495_next_44265;
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
	inline void set_knob4_gain(t_param _value) {
		m_knob4_gain_134 = (_value < 1 ? 1 : (_value > 20 ? 20 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_135 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_136 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_res(t_param _value) {
		m_knob3_res_137 = (_value < 15 ? 15 : (_value > 50 ? 50 : _value));
	};
	inline void set_knob5_noise(t_param _value) {
		m_knob5_noise_138 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 4: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_res_137; break;
		case 1: *value = self->m_knob4_gain_134; break;
		case 2: *value = self->m_knob5_noise_138; break;
		case 3: *value = self->m_sw_136; break;
		case 4: *value = self->m_sw_135; break;
		
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
	// initialize parameter 1 ("m_knob4_gain_134")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_gain";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_gain_134;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 20;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_noise_138")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_noise";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_noise_138;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_sw_136")
	pi = self->__commonstate.params + 3;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_136;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_135")
	pi = self->__commonstate.params + 4;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_135;
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
