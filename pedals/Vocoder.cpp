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
	t_sample m_knob5_noise_133;
	t_sample m_knob4_gain_134;
	t_sample __m_slide_140;
	t_sample __m_slide_143;
	t_sample __m_latch_146;
	t_sample m_x_123;
	t_sample m_y_14;
	t_sample m_sw_136;
	t_sample m_sw_137;
	t_sample m_knob3_res_135;
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
		m_knob5_noise_133 = 0;
		m_knob4_gain_134 = 5;
		m_knob3_res_135 = 15;
		m_sw_136 = ((int)0);
		m_sw_137 = 0;
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
		t_sample rsub_4709 = (((int)1) - m_sw_137);
		t_sample mstosamps_5105 = (((int)2) * (samplerate * 0.001));
		t_sample mstosamps_5194 = (((int)20) * (samplerate * 0.001));
		t_sample iup_141 = (1 / maximum(1, abs(((int)10))));
		t_sample idown_142 = (1 / maximum(1, abs(((int)400))));
		t_sample twopi_over_sr = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_5045 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_144 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_145 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5219 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_5019 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_149 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_150 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5226 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_4993 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_154 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_155 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5244 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_4967 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_159 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_160 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5269 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_4941 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_164 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_165 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5279 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_4915 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_169 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_170 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5297 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_4889 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_174 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_175 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5315 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_4864 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_179 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_180 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5333 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_4837 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_184 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_185 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5351 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_4811 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_189 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_190 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5369 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_4785 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_194 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_195 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5387 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_4759 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_199 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_200 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5404 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_4733 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_204 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_205 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5422 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_5167 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_209 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_210 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5440 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_5098 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_214 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_215 = (1 / maximum(1, abs(mstosamps_5194)));
		t_sample twopi_over_sr_5458 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_5071 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_219 = (1 / maximum(1, abs(mstosamps_5105)));
		t_sample idown_220 = (1 / maximum(1, abs(mstosamps_5194)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_5200 = __m_sah_138(m_history_132, m_sw_136, ((int)0));
			t_sample gen_5202 = sah_5200;
			t_sample rsub_5198 = (((int)1) - sah_5200);
			t_sample history_5199_next_5201 = fixdenorm(rsub_5198);
			t_sample out3 = gen_5202;
			t_sample add_5203 = (gen_5202 + ((int)1));
			t_sample choice_139 = int(add_5203);
			t_sample gate_5196 = (((choice_139 >= 1) && (choice_139 < 2)) ? in1 : 0);
			t_sample gate_5197 = ((choice_139 >= 2) ? in1 : 0);
			t_sample mix_5523 = (m_history_131 + (((t_sample)0.003926980723806) * (m_knob3_res_135 - m_history_131)));
			t_sample mix_5186 = mix_5523;
			t_sample mix_5524 = (m_history_130 + (((t_sample)0.003926980723806) * (mix_5186 - m_history_130)));
			t_sample mix_5184 = mix_5524;
			t_sample mix_5525 = (m_history_129 + (((t_sample)0.003926980723806) * (mix_5184 - m_history_129)));
			t_sample mix_5182 = mix_5525;
			t_sample gen_5192 = mix_5182;
			t_sample history_5187_next_5189 = fixdenorm(mix_5186);
			t_sample history_5185_next_5190 = fixdenorm(mix_5184);
			t_sample history_5183_next_5191 = fixdenorm(mix_5182);
			t_sample mul_4707 = (gate_5197 * m_knob4_gain_134);
			t_sample abs_4705 = fabs(gate_5197);
			__m_slide_140 = fixdenorm((__m_slide_140 + (((abs_4705 > __m_slide_140) ? iup_141 : idown_142) * (abs_4705 - __m_slide_140))));
			t_sample slide_4704 = __m_slide_140;
			t_sample noise_4712 = noise();
			t_sample mul_4711 = (noise_4712 * m_knob5_noise_133);
			t_sample mul_4706 = (slide_4704 * mul_4711);
			t_sample add_4710 = (mul_4707 + mul_4706);
			t_sample x = add_4710;
			t_sample q = gen_5192;
			t_sample bw = safediv(((t_sample)284.5), q);
			t_sample r = exp(((-bw) * twopi_over_sr));
			t_sample c1 = ((((int)2) * r) * cos((((t_sample)284.5) * twopi_over_sr)));
			t_sample c2 = ((-r) * r);
			t_sample y = ((((((int)1) - r) * (x - (r * m_x_127))) + (c1 * m_y_126)) + (c2 * m_y_125));
			m_y_125 = m_y_126;
			m_y_126 = y;
			m_x_127 = m_x_128;
			m_x_128 = x;
			t_sample x_5041 = in2;
			t_sample q_5034 = gen_5192;
			t_sample bw_5042 = safediv(((t_sample)284.5), q_5034);
			t_sample r_5035 = exp(((-bw_5042) * twopi_over_sr_5045));
			t_sample c_5044 = ((((int)2) * r_5035) * cos((((t_sample)284.5) * twopi_over_sr_5045)));
			t_sample c_5047 = ((-r_5035) * r_5035);
			t_sample y_5046 = ((((((int)1) - r_5035) * (x_5041 - (r_5035 * m_x_123))) + (c_5044 * m_y_122)) + (c_5047 * m_y_121));
			m_y_121 = m_y_122;
			m_y_122 = y_5046;
			m_x_123 = m_x_124;
			m_x_124 = x_5041;
			t_sample abs_5033 = fabs(y_5046);
			__m_slide_143 = fixdenorm((__m_slide_143 + (((abs_5033 > __m_slide_143) ? iup_144 : idown_145) * (abs_5033 - __m_slide_143))));
			t_sample slide_5032 = __m_slide_143;
			__m_latch_146 = ((rsub_4709 != 0) ? slide_5032 : __m_latch_146);
			t_sample latch_5027 = __m_latch_146;
			t_sample mul_5029 = (y * latch_5027);
			t_sample dcblock_5028 = __m_dcblock_147(mul_5029);
			t_sample x_5213 = add_4710;
			t_sample q_5209 = gen_5192;
			t_sample bw_5210 = safediv(((t_sample)358.5), q_5209);
			t_sample r_5211 = exp(((-bw_5210) * twopi_over_sr_5219));
			t_sample c_5215 = ((((int)2) * r_5211) * cos((((t_sample)358.5) * twopi_over_sr_5219)));
			t_sample c_5208 = ((-r_5211) * r_5211);
			t_sample y_5212 = ((((((int)1) - r_5211) * (x_5213 - (r_5211 * m_x_119))) + (c_5215 * m_y_118)) + (c_5208 * m_y_117));
			m_y_117 = m_y_118;
			m_y_118 = y_5212;
			m_x_119 = m_x_120;
			m_x_120 = x_5213;
			t_sample x_5015 = in2;
			t_sample q_5008 = gen_5192;
			t_sample bw_5016 = safediv(((t_sample)358.5), q_5008);
			t_sample r_5009 = exp(((-bw_5016) * twopi_over_sr_5019));
			t_sample c_5018 = ((((int)2) * r_5009) * cos((((t_sample)358.5) * twopi_over_sr_5019)));
			t_sample c_5021 = ((-r_5009) * r_5009);
			t_sample y_5020 = ((((((int)1) - r_5009) * (x_5015 - (r_5009 * m_x_115))) + (c_5018 * m_y_114)) + (c_5021 * m_y_113));
			m_y_113 = m_y_114;
			m_y_114 = y_5020;
			m_x_115 = m_x_116;
			m_x_116 = x_5015;
			t_sample abs_5007 = fabs(y_5020);
			__m_slide_148 = fixdenorm((__m_slide_148 + (((abs_5007 > __m_slide_148) ? iup_149 : idown_150) * (abs_5007 - __m_slide_148))));
			t_sample slide_5006 = __m_slide_148;
			__m_latch_151 = ((rsub_4709 != 0) ? slide_5006 : __m_latch_151);
			t_sample latch_5001 = __m_latch_151;
			t_sample mul_5003 = (y_5212 * latch_5001);
			t_sample dcblock_5002 = __m_dcblock_152(mul_5003);
			t_sample x_5232 = add_4710;
			t_sample q_5229 = gen_5192;
			t_sample bw_5233 = safediv(((int)452), q_5229);
			t_sample r_5230 = exp(((-bw_5233) * twopi_over_sr_5226));
			t_sample c_5237 = ((((int)2) * r_5230) * cos((((int)452) * twopi_over_sr_5226)));
			t_sample c_5224 = ((-r_5230) * r_5230);
			t_sample y_5231 = ((((((int)1) - r_5230) * (x_5232 - (r_5230 * m_x_111))) + (c_5237 * m_y_110)) + (c_5224 * m_y_109));
			m_y_109 = m_y_110;
			m_y_110 = y_5231;
			m_x_111 = m_x_112;
			m_x_112 = x_5232;
			t_sample x_4989 = in2;
			t_sample q_4982 = gen_5192;
			t_sample bw_4990 = safediv(((int)452), q_4982);
			t_sample r_4983 = exp(((-bw_4990) * twopi_over_sr_4993));
			t_sample c_4992 = ((((int)2) * r_4983) * cos((((int)452) * twopi_over_sr_4993)));
			t_sample c_4995 = ((-r_4983) * r_4983);
			t_sample y_4994 = ((((((int)1) - r_4983) * (x_4989 - (r_4983 * m_x_107))) + (c_4992 * m_y_106)) + (c_4995 * m_y_105));
			m_y_105 = m_y_106;
			m_y_106 = y_4994;
			m_x_107 = m_x_108;
			m_x_108 = x_4989;
			t_sample abs_4981 = fabs(y_4994);
			__m_slide_153 = fixdenorm((__m_slide_153 + (((abs_4981 > __m_slide_153) ? iup_154 : idown_155) * (abs_4981 - __m_slide_153))));
			t_sample slide_4980 = __m_slide_153;
			__m_latch_156 = ((rsub_4709 != 0) ? slide_4980 : __m_latch_156);
			t_sample latch_4975 = __m_latch_156;
			t_sample mul_4977 = (y_5231 * latch_4975);
			t_sample dcblock_4976 = __m_dcblock_157(mul_4977);
			t_sample x_5250 = add_4710;
			t_sample q_5247 = gen_5192;
			t_sample bw_5252 = safediv(((t_sample)569.5), q_5247);
			t_sample r_5248 = exp(((-bw_5252) * twopi_over_sr_5244));
			t_sample c_5255 = ((((int)2) * r_5248) * cos((((t_sample)569.5) * twopi_over_sr_5244)));
			t_sample c_5242 = ((-r_5248) * r_5248);
			t_sample y_5249 = ((((((int)1) - r_5248) * (x_5250 - (r_5248 * m_x_103))) + (c_5255 * m_y_102)) + (c_5242 * m_y_101));
			m_y_101 = m_y_102;
			m_y_102 = y_5249;
			m_x_103 = m_x_104;
			m_x_104 = x_5250;
			t_sample x_4963 = in2;
			t_sample q_4956 = gen_5192;
			t_sample bw_4964 = safediv(((t_sample)569.5), q_4956);
			t_sample r_4957 = exp(((-bw_4964) * twopi_over_sr_4967));
			t_sample c_4966 = ((((int)2) * r_4957) * cos((((t_sample)569.5) * twopi_over_sr_4967)));
			t_sample c_4969 = ((-r_4957) * r_4957);
			t_sample y_4968 = ((((((int)1) - r_4957) * (x_4963 - (r_4957 * m_x_99))) + (c_4966 * m_y_98)) + (c_4969 * m_y_97));
			m_y_97 = m_y_98;
			m_y_98 = y_4968;
			m_x_99 = m_x_100;
			m_x_100 = x_4963;
			t_sample abs_4955 = fabs(y_4968);
			__m_slide_158 = fixdenorm((__m_slide_158 + (((abs_4955 > __m_slide_158) ? iup_159 : idown_160) * (abs_4955 - __m_slide_158))));
			t_sample slide_4954 = __m_slide_158;
			__m_latch_161 = ((rsub_4709 != 0) ? slide_4954 : __m_latch_161);
			t_sample latch_4949 = __m_latch_161;
			t_sample mul_4951 = (y_5249 * latch_4949);
			t_sample dcblock_4950 = __m_dcblock_162(mul_4951);
			t_sample x_5267 = add_4710;
			t_sample q_5264 = gen_5192;
			t_sample bw_5270 = safediv(((t_sample)717.5), q_5264);
			t_sample r_5265 = exp(((-bw_5270) * twopi_over_sr_5269));
			t_sample c_5271 = ((((int)2) * r_5265) * cos((((t_sample)717.5) * twopi_over_sr_5269)));
			t_sample c_5260 = ((-r_5265) * r_5265);
			t_sample y_5266 = ((((((int)1) - r_5265) * (x_5267 - (r_5265 * m_x_95))) + (c_5271 * m_y_94)) + (c_5260 * m_y_93));
			m_y_93 = m_y_94;
			m_y_94 = y_5266;
			m_x_95 = m_x_96;
			m_x_96 = x_5267;
			t_sample x_4937 = in2;
			t_sample q_4930 = gen_5192;
			t_sample bw_4938 = safediv(((t_sample)717.5), q_4930);
			t_sample r_4931 = exp(((-bw_4938) * twopi_over_sr_4941));
			t_sample c_4940 = ((((int)2) * r_4931) * cos((((t_sample)717.5) * twopi_over_sr_4941)));
			t_sample c_4943 = ((-r_4931) * r_4931);
			t_sample y_4942 = ((((((int)1) - r_4931) * (x_4937 - (r_4931 * m_x_91))) + (c_4940 * m_y_90)) + (c_4943 * m_y_89));
			m_y_89 = m_y_90;
			m_y_90 = y_4942;
			m_x_91 = m_x_92;
			m_x_92 = x_4937;
			t_sample abs_4929 = fabs(y_4942);
			__m_slide_163 = fixdenorm((__m_slide_163 + (((abs_4929 > __m_slide_163) ? iup_164 : idown_165) * (abs_4929 - __m_slide_163))));
			t_sample slide_4928 = __m_slide_163;
			__m_latch_166 = ((rsub_4709 != 0) ? slide_4928 : __m_latch_166);
			t_sample latch_4923 = __m_latch_166;
			t_sample mul_4925 = (y_5266 * latch_4923);
			t_sample dcblock_4924 = __m_dcblock_167(mul_4925);
			t_sample x_5285 = add_4710;
			t_sample q_5282 = gen_5192;
			t_sample bw_5290 = safediv(((int)904), q_5282);
			t_sample r_5283 = exp(((-bw_5290) * twopi_over_sr_5279));
			t_sample c_5286 = ((((int)2) * r_5283) * cos((((int)904) * twopi_over_sr_5279)));
			t_sample c_5278 = ((-r_5283) * r_5283);
			t_sample y_5284 = ((((((int)1) - r_5283) * (x_5285 - (r_5283 * m_x_87))) + (c_5286 * m_y_86)) + (c_5278 * m_y_85));
			m_y_85 = m_y_86;
			m_y_86 = y_5284;
			m_x_87 = m_x_88;
			m_x_88 = x_5285;
			t_sample x_4911 = in2;
			t_sample q_4904 = gen_5192;
			t_sample bw_4912 = safediv(((int)904), q_4904);
			t_sample r_4905 = exp(((-bw_4912) * twopi_over_sr_4915));
			t_sample c_4914 = ((((int)2) * r_4905) * cos((((int)904) * twopi_over_sr_4915)));
			t_sample c_4917 = ((-r_4905) * r_4905);
			t_sample y_4916 = ((((((int)1) - r_4905) * (x_4911 - (r_4905 * m_x_83))) + (c_4914 * m_y_82)) + (c_4917 * m_y_81));
			m_y_81 = m_y_82;
			m_y_82 = y_4916;
			m_x_83 = m_x_84;
			m_x_84 = x_4911;
			t_sample abs_4903 = fabs(y_4916);
			__m_slide_168 = fixdenorm((__m_slide_168 + (((abs_4903 > __m_slide_168) ? iup_169 : idown_170) * (abs_4903 - __m_slide_168))));
			t_sample slide_4902 = __m_slide_168;
			__m_latch_171 = ((rsub_4709 != 0) ? slide_4902 : __m_latch_171);
			t_sample latch_4897 = __m_latch_171;
			t_sample mul_4899 = (y_5284 * latch_4897);
			t_sample dcblock_4898 = __m_dcblock_172(mul_4899);
			t_sample x_5303 = add_4710;
			t_sample q_5300 = gen_5192;
			t_sample bw_5308 = safediv(((int)1139), q_5300);
			t_sample r_5301 = exp(((-bw_5308) * twopi_over_sr_5297));
			t_sample c_5304 = ((((int)2) * r_5301) * cos((((int)1139) * twopi_over_sr_5297)));
			t_sample c_5296 = ((-r_5301) * r_5301);
			t_sample y_5302 = ((((((int)1) - r_5301) * (x_5303 - (r_5301 * m_x_79))) + (c_5304 * m_y_78)) + (c_5296 * m_y_77));
			m_y_77 = m_y_78;
			m_y_78 = y_5302;
			m_x_79 = m_x_80;
			m_x_80 = x_5303;
			t_sample x_4885 = in2;
			t_sample q_4878 = gen_5192;
			t_sample bw_4886 = safediv(((int)1139), q_4878);
			t_sample r_4879 = exp(((-bw_4886) * twopi_over_sr_4889));
			t_sample c_4888 = ((((int)2) * r_4879) * cos((((int)1139) * twopi_over_sr_4889)));
			t_sample c_4891 = ((-r_4879) * r_4879);
			t_sample y_4890 = ((((((int)1) - r_4879) * (x_4885 - (r_4879 * m_x_75))) + (c_4888 * m_y_74)) + (c_4891 * m_y_73));
			m_y_73 = m_y_74;
			m_y_74 = y_4890;
			m_x_75 = m_x_76;
			m_x_76 = x_4885;
			t_sample abs_4877 = fabs(y_4890);
			__m_slide_173 = fixdenorm((__m_slide_173 + (((abs_4877 > __m_slide_173) ? iup_174 : idown_175) * (abs_4877 - __m_slide_173))));
			t_sample slide_4876 = __m_slide_173;
			__m_latch_176 = ((rsub_4709 != 0) ? slide_4876 : __m_latch_176);
			t_sample latch_4871 = __m_latch_176;
			t_sample mul_4873 = (y_5302 * latch_4871);
			t_sample dcblock_4872 = __m_dcblock_177(mul_4873);
			t_sample x_5321 = add_4710;
			t_sample q_5318 = gen_5192;
			t_sample bw_5325 = safediv(((int)1435), q_5318);
			t_sample r_5319 = exp(((-bw_5325) * twopi_over_sr_5315));
			t_sample c_5327 = ((((int)2) * r_5319) * cos((((int)1435) * twopi_over_sr_5315)));
			t_sample c_5314 = ((-r_5319) * r_5319);
			t_sample y_5320 = ((((((int)1) - r_5319) * (x_5321 - (r_5319 * m_x_71))) + (c_5327 * m_y_70)) + (c_5314 * m_y_69));
			m_y_69 = m_y_70;
			m_y_70 = y_5320;
			m_x_71 = m_x_72;
			m_x_72 = x_5321;
			t_sample x_4860 = in2;
			t_sample q_4852 = gen_5192;
			t_sample bw_4861 = safediv(((int)1435), q_4852);
			t_sample r_4854 = exp(((-bw_4861) * twopi_over_sr_4864));
			t_sample c_4863 = ((((int)2) * r_4854) * cos((((int)1435) * twopi_over_sr_4864)));
			t_sample c_4865 = ((-r_4854) * r_4854);
			t_sample y_4853 = ((((((int)1) - r_4854) * (x_4860 - (r_4854 * m_x_67))) + (c_4863 * m_y_66)) + (c_4865 * m_y_65));
			m_y_65 = m_y_66;
			m_y_66 = y_4853;
			m_x_67 = m_x_68;
			m_x_68 = x_4860;
			t_sample abs_4851 = fabs(y_4853);
			__m_slide_178 = fixdenorm((__m_slide_178 + (((abs_4851 > __m_slide_178) ? iup_179 : idown_180) * (abs_4851 - __m_slide_178))));
			t_sample slide_4850 = __m_slide_178;
			__m_latch_181 = ((rsub_4709 != 0) ? slide_4850 : __m_latch_181);
			t_sample latch_4845 = __m_latch_181;
			t_sample mul_4847 = (y_5320 * latch_4845);
			t_sample dcblock_4846 = __m_dcblock_182(mul_4847);
			t_sample x_5339 = add_4710;
			t_sample q_5336 = gen_5192;
			t_sample bw_5344 = safediv(((int)1808), q_5336);
			t_sample r_5337 = exp(((-bw_5344) * twopi_over_sr_5333));
			t_sample c_5343 = ((((int)2) * r_5337) * cos((((int)1808) * twopi_over_sr_5333)));
			t_sample c_5332 = ((-r_5337) * r_5337);
			t_sample y_5338 = ((((((int)1) - r_5337) * (x_5339 - (r_5337 * m_x_63))) + (c_5343 * m_y_62)) + (c_5332 * m_y_61));
			m_y_61 = m_y_62;
			m_y_62 = y_5338;
			m_x_63 = m_x_64;
			m_x_64 = x_5339;
			t_sample x_4833 = in2;
			t_sample q_4826 = gen_5192;
			t_sample bw_4834 = safediv(((int)1808), q_4826);
			t_sample r_4827 = exp(((-bw_4834) * twopi_over_sr_4837));
			t_sample c_4836 = ((((int)2) * r_4827) * cos((((int)1808) * twopi_over_sr_4837)));
			t_sample c_4839 = ((-r_4827) * r_4827);
			t_sample y_4838 = ((((((int)1) - r_4827) * (x_4833 - (r_4827 * m_x_59))) + (c_4836 * m_y_58)) + (c_4839 * m_y_57));
			m_y_57 = m_y_58;
			m_y_58 = y_4838;
			m_x_59 = m_x_60;
			m_x_60 = x_4833;
			t_sample abs_4825 = fabs(y_4838);
			__m_slide_183 = fixdenorm((__m_slide_183 + (((abs_4825 > __m_slide_183) ? iup_184 : idown_185) * (abs_4825 - __m_slide_183))));
			t_sample slide_4824 = __m_slide_183;
			__m_latch_186 = ((rsub_4709 != 0) ? slide_4824 : __m_latch_186);
			t_sample latch_4819 = __m_latch_186;
			t_sample mul_4821 = (y_5338 * latch_4819);
			t_sample dcblock_4820 = __m_dcblock_187(mul_4821);
			t_sample x_5357 = add_4710;
			t_sample q_5354 = gen_5192;
			t_sample bw_5361 = safediv(((int)2260), q_5354);
			t_sample r_5355 = exp(((-bw_5361) * twopi_over_sr_5351));
			t_sample c_5363 = ((((int)2) * r_5355) * cos((((int)2260) * twopi_over_sr_5351)));
			t_sample c_5350 = ((-r_5355) * r_5355);
			t_sample y_5356 = ((((((int)1) - r_5355) * (x_5357 - (r_5355 * m_x_55))) + (c_5363 * m_y_54)) + (c_5350 * m_y_53));
			m_y_53 = m_y_54;
			m_y_54 = y_5356;
			m_x_55 = m_x_56;
			m_x_56 = x_5357;
			t_sample x_4807 = in2;
			t_sample q_4800 = gen_5192;
			t_sample bw_4808 = safediv(((int)2260), q_4800);
			t_sample r_4801 = exp(((-bw_4808) * twopi_over_sr_4811));
			t_sample c_4810 = ((((int)2) * r_4801) * cos((((int)2260) * twopi_over_sr_4811)));
			t_sample c_4813 = ((-r_4801) * r_4801);
			t_sample y_4812 = ((((((int)1) - r_4801) * (x_4807 - (r_4801 * m_x_51))) + (c_4810 * m_y_50)) + (c_4813 * m_y_49));
			m_y_49 = m_y_50;
			m_y_50 = y_4812;
			m_x_51 = m_x_52;
			m_x_52 = x_4807;
			t_sample abs_4799 = fabs(y_4812);
			__m_slide_188 = fixdenorm((__m_slide_188 + (((abs_4799 > __m_slide_188) ? iup_189 : idown_190) * (abs_4799 - __m_slide_188))));
			t_sample slide_4798 = __m_slide_188;
			__m_latch_191 = ((rsub_4709 != 0) ? slide_4798 : __m_latch_191);
			t_sample latch_4793 = __m_latch_191;
			t_sample mul_4795 = (y_5356 * latch_4793);
			t_sample dcblock_4794 = __m_dcblock_192(mul_4795);
			t_sample x_5375 = add_4710;
			t_sample q_5372 = gen_5192;
			t_sample bw_5380 = safediv(((int)2852), q_5372);
			t_sample r_5373 = exp(((-bw_5380) * twopi_over_sr_5369));
			t_sample c_5381 = ((((int)2) * r_5373) * cos((((int)2852) * twopi_over_sr_5369)));
			t_sample c_5368 = ((-r_5373) * r_5373);
			t_sample y_5374 = ((((((int)1) - r_5373) * (x_5375 - (r_5373 * m_x_47))) + (c_5381 * m_y_46)) + (c_5368 * m_y_45));
			m_y_45 = m_y_46;
			m_y_46 = y_5374;
			m_x_47 = m_x_48;
			m_x_48 = x_5375;
			t_sample x_4781 = in2;
			t_sample q_4774 = gen_5192;
			t_sample bw_4782 = safediv(((int)2852), q_4774);
			t_sample r_4775 = exp(((-bw_4782) * twopi_over_sr_4785));
			t_sample c_4784 = ((((int)2) * r_4775) * cos((((int)2852) * twopi_over_sr_4785)));
			t_sample c_4787 = ((-r_4775) * r_4775);
			t_sample y_4786 = ((((((int)1) - r_4775) * (x_4781 - (r_4775 * m_x_43))) + (c_4784 * m_y_42)) + (c_4787 * m_y_41));
			m_y_41 = m_y_42;
			m_y_42 = y_4786;
			m_x_43 = m_x_44;
			m_x_44 = x_4781;
			t_sample abs_4773 = fabs(y_4786);
			__m_slide_193 = fixdenorm((__m_slide_193 + (((abs_4773 > __m_slide_193) ? iup_194 : idown_195) * (abs_4773 - __m_slide_193))));
			t_sample slide_4772 = __m_slide_193;
			__m_latch_196 = ((rsub_4709 != 0) ? slide_4772 : __m_latch_196);
			t_sample latch_4767 = __m_latch_196;
			t_sample mul_4769 = (y_5374 * latch_4767);
			t_sample dcblock_4768 = __m_dcblock_197(mul_4769);
			t_sample x_5393 = add_4710;
			t_sample q_5390 = gen_5192;
			t_sample bw_5398 = safediv(((int)3616), q_5390);
			t_sample r_5391 = exp(((-bw_5398) * twopi_over_sr_5387));
			t_sample c_5394 = ((((int)2) * r_5391) * cos((((int)3616) * twopi_over_sr_5387)));
			t_sample c_5386 = ((-r_5391) * r_5391);
			t_sample y_5392 = ((((((int)1) - r_5391) * (x_5393 - (r_5391 * m_x_39))) + (c_5394 * m_y_38)) + (c_5386 * m_y_37));
			m_y_37 = m_y_38;
			m_y_38 = y_5392;
			m_x_39 = m_x_40;
			m_x_40 = x_5393;
			t_sample x_4755 = in2;
			t_sample q_4748 = gen_5192;
			t_sample bw_4756 = safediv(((int)3616), q_4748);
			t_sample r_4749 = exp(((-bw_4756) * twopi_over_sr_4759));
			t_sample c_4758 = ((((int)2) * r_4749) * cos((((int)3616) * twopi_over_sr_4759)));
			t_sample c_4761 = ((-r_4749) * r_4749);
			t_sample y_4760 = ((((((int)1) - r_4749) * (x_4755 - (r_4749 * m_x_35))) + (c_4758 * m_y_34)) + (c_4761 * m_y_33));
			m_y_33 = m_y_34;
			m_y_34 = y_4760;
			m_x_35 = m_x_36;
			m_x_36 = x_4755;
			t_sample abs_4747 = fabs(y_4760);
			__m_slide_198 = fixdenorm((__m_slide_198 + (((abs_4747 > __m_slide_198) ? iup_199 : idown_200) * (abs_4747 - __m_slide_198))));
			t_sample slide_4746 = __m_slide_198;
			__m_latch_201 = ((rsub_4709 != 0) ? slide_4746 : __m_latch_201);
			t_sample latch_4741 = __m_latch_201;
			t_sample mul_4743 = (y_5392 * latch_4741);
			t_sample dcblock_4742 = __m_dcblock_202(mul_4743);
			t_sample x_5407 = add_4710;
			t_sample q_5405 = gen_5192;
			t_sample bw_5415 = safediv(((int)4556), q_5405);
			t_sample r_5417 = exp(((-bw_5415) * twopi_over_sr_5404));
			t_sample c_5414 = ((((int)2) * r_5417) * cos((((int)4556) * twopi_over_sr_5404)));
			t_sample c_5409 = ((-r_5417) * r_5417);
			t_sample y_5406 = ((((((int)1) - r_5417) * (x_5407 - (r_5417 * m_x_31))) + (c_5414 * m_y_30)) + (c_5409 * m_y_29));
			m_y_29 = m_y_30;
			m_y_30 = y_5406;
			m_x_31 = m_x_32;
			m_x_32 = x_5407;
			t_sample x_4729 = in2;
			t_sample q_4722 = gen_5192;
			t_sample bw_4730 = safediv(((int)4556), q_4722);
			t_sample r_4723 = exp(((-bw_4730) * twopi_over_sr_4733));
			t_sample c_4732 = ((((int)2) * r_4723) * cos((((int)4556) * twopi_over_sr_4733)));
			t_sample c_4735 = ((-r_4723) * r_4723);
			t_sample y_4734 = ((((((int)1) - r_4723) * (x_4729 - (r_4723 * m_x_27))) + (c_4732 * m_y_26)) + (c_4735 * m_y_25));
			m_y_25 = m_y_26;
			m_y_26 = y_4734;
			m_x_27 = m_x_28;
			m_x_28 = x_4729;
			t_sample abs_4721 = fabs(y_4734);
			__m_slide_203 = fixdenorm((__m_slide_203 + (((abs_4721 > __m_slide_203) ? iup_204 : idown_205) * (abs_4721 - __m_slide_203))));
			t_sample slide_4720 = __m_slide_203;
			__m_latch_206 = ((rsub_4709 != 0) ? slide_4720 : __m_latch_206);
			t_sample latch_4713 = __m_latch_206;
			t_sample mul_4715 = (y_5406 * latch_4713);
			t_sample dcblock_4714 = __m_dcblock_207(mul_4715);
			t_sample x_5425 = add_4710;
			t_sample q_5423 = gen_5192;
			t_sample bw_5434 = safediv(((t_sample)104.5), q_5423);
			t_sample r_5435 = exp(((-bw_5434) * twopi_over_sr_5422));
			t_sample c_5432 = ((((int)2) * r_5435) * cos((((t_sample)104.5) * twopi_over_sr_5422)));
			t_sample c_5427 = ((-r_5435) * r_5435);
			t_sample y_5424 = ((((((int)1) - r_5435) * (x_5425 - (r_5435 * m_x_23))) + (c_5432 * m_y_22)) + (c_5427 * m_y_21));
			m_y_21 = m_y_22;
			m_y_22 = y_5424;
			m_x_23 = m_x_24;
			m_x_24 = x_5425;
			t_sample x_5163 = in2;
			t_sample q_5156 = gen_5192;
			t_sample bw_5164 = safediv(((t_sample)104.5), q_5156);
			t_sample r_5157 = exp(((-bw_5164) * twopi_over_sr_5167));
			t_sample c_5166 = ((((int)2) * r_5157) * cos((((t_sample)104.5) * twopi_over_sr_5167)));
			t_sample c_5169 = ((-r_5157) * r_5157);
			t_sample y_5168 = ((((((int)1) - r_5157) * (x_5163 - (r_5157 * m_x_19))) + (c_5166 * m_y_18)) + (c_5169 * m_y_17));
			m_y_17 = m_y_18;
			m_y_18 = y_5168;
			m_x_19 = m_x_20;
			m_x_20 = x_5163;
			t_sample abs_5155 = fabs(y_5168);
			__m_slide_208 = fixdenorm((__m_slide_208 + (((abs_5155 > __m_slide_208) ? iup_209 : idown_210) * (abs_5155 - __m_slide_208))));
			t_sample slide_5154 = __m_slide_208;
			__m_latch_211 = ((rsub_4709 != 0) ? slide_5154 : __m_latch_211);
			t_sample latch_5149 = __m_latch_211;
			t_sample mul_5151 = (y_5424 * latch_5149);
			t_sample dcblock_5150 = __m_dcblock_212(mul_5151);
			t_sample x_5444 = add_4710;
			t_sample q_5441 = gen_5192;
			t_sample bw_5452 = safediv(((t_sample)179.5), q_5441);
			t_sample r_5442 = exp(((-bw_5452) * twopi_over_sr_5440));
			t_sample c_5448 = ((((int)2) * r_5442) * cos((((t_sample)179.5) * twopi_over_sr_5440)));
			t_sample c_5446 = ((-r_5442) * r_5442);
			t_sample y_5443 = ((((((int)1) - r_5442) * (x_5444 - (r_5442 * m_x_15))) + (c_5448 * m_y_14)) + (c_5446 * m_y_13));
			m_y_13 = m_y_14;
			m_y_14 = y_5443;
			m_x_15 = m_x_16;
			m_x_16 = x_5444;
			t_sample x_5094 = in2;
			t_sample q_5086 = gen_5192;
			t_sample bw_5095 = safediv(((t_sample)179.5), q_5086);
			t_sample r_5088 = exp(((-bw_5095) * twopi_over_sr_5098));
			t_sample c_5097 = ((((int)2) * r_5088) * cos((((t_sample)179.5) * twopi_over_sr_5098)));
			t_sample c_5099 = ((-r_5088) * r_5088);
			t_sample y_5087 = ((((((int)1) - r_5088) * (x_5094 - (r_5088 * m_x_11))) + (c_5097 * m_y_10)) + (c_5099 * m_y_9));
			m_y_9 = m_y_10;
			m_y_10 = y_5087;
			m_x_11 = m_x_12;
			m_x_12 = x_5094;
			t_sample abs_5085 = fabs(y_5087);
			__m_slide_213 = fixdenorm((__m_slide_213 + (((abs_5085 > __m_slide_213) ? iup_214 : idown_215) * (abs_5085 - __m_slide_213))));
			t_sample slide_5084 = __m_slide_213;
			__m_latch_216 = ((rsub_4709 != 0) ? slide_5084 : __m_latch_216);
			t_sample latch_5079 = __m_latch_216;
			t_sample mul_5081 = (y_5443 * latch_5079);
			t_sample dcblock_5080 = __m_dcblock_217(mul_5081);
			t_sample x_5461 = add_4710;
			t_sample q_5459 = gen_5192;
			t_sample bw_5470 = safediv(((int)226), q_5459);
			t_sample r_5471 = exp(((-bw_5470) * twopi_over_sr_5458));
			t_sample c_5465 = ((((int)2) * r_5471) * cos((((int)226) * twopi_over_sr_5458)));
			t_sample c_5463 = ((-r_5471) * r_5471);
			t_sample y_5460 = ((((((int)1) - r_5471) * (x_5461 - (r_5471 * m_x_7))) + (c_5465 * m_y_6)) + (c_5463 * m_y_5));
			m_y_5 = m_y_6;
			m_y_6 = y_5460;
			m_x_7 = m_x_8;
			m_x_8 = x_5461;
			t_sample x_5067 = in2;
			t_sample q_5060 = gen_5192;
			t_sample bw_5068 = safediv(((int)226), q_5060);
			t_sample r_5061 = exp(((-bw_5068) * twopi_over_sr_5071));
			t_sample c_5070 = ((((int)2) * r_5061) * cos((((int)226) * twopi_over_sr_5071)));
			t_sample c_5073 = ((-r_5061) * r_5061);
			t_sample y_5072 = ((((((int)1) - r_5061) * (x_5067 - (r_5061 * m_x_3))) + (c_5070 * m_y_2)) + (c_5073 * m_y_1));
			m_y_1 = m_y_2;
			m_y_2 = y_5072;
			m_x_3 = m_x_4;
			m_x_4 = x_5067;
			t_sample abs_5059 = fabs(y_5072);
			__m_slide_218 = fixdenorm((__m_slide_218 + (((abs_5059 > __m_slide_218) ? iup_219 : idown_220) * (abs_5059 - __m_slide_218))));
			t_sample slide_5058 = __m_slide_218;
			__m_latch_221 = ((rsub_4709 != 0) ? slide_5058 : __m_latch_221);
			t_sample latch_5053 = __m_latch_221;
			t_sample mul_5055 = (y_5460 * latch_5053);
			t_sample dcblock_5054 = __m_dcblock_222(mul_5055);
			t_sample pass_5193 = (((((((((((((((dcblock_5054 + dcblock_5080) + dcblock_5150) + dcblock_4714) + dcblock_4742) + dcblock_4768) + dcblock_4794) + dcblock_4820) + dcblock_4846) + dcblock_4872) + dcblock_4898) + dcblock_4924) + dcblock_4950) + dcblock_4976) + dcblock_5002) + dcblock_5028);
			t_sample add_5205 = (pass_5193 + gate_5196);
			t_sample out1 = add_5205;
			t_sample add_5204 = (pass_5193 + gate_5196);
			t_sample out2 = add_5204;
			m_history_132 = history_5199_next_5201;
			m_history_131 = history_5187_next_5189;
			m_history_129 = history_5183_next_5191;
			m_history_130 = history_5185_next_5190;
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
	inline void set_knob5_noise(t_param _value) {
		m_knob5_noise_133 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_gain(t_param _value) {
		m_knob4_gain_134 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
	};
	inline void set_knob3_res(t_param _value) {
		m_knob3_res_135 = (_value < 15 ? 15 : (_value > 50 ? 50 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_136 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_137 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_res_135; break;
		case 1: *value = self->m_knob4_gain_134; break;
		case 2: *value = self->m_knob5_noise_133; break;
		case 3: *value = self->m_sw_136; break;
		case 4: *value = self->m_sw_137; break;
		
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
	// initialize parameter 0 ("m_knob3_res_135")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_res_135;
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
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_noise_133")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_noise";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_noise_133;
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
	// initialize parameter 4 ("m_sw_137")
	pi = self->__commonstate.params + 4;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_137;
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
