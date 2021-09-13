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
	t_sample m_sw_132;
	t_sample m_sw_133;
	t_sample m_knob4_gain_134;
	t_sample __m_slide_140;
	t_sample __m_slide_143;
	t_sample __m_latch_146;
	t_sample m_x_123;
	t_sample m_y_14;
	t_sample m_knob3_res_136;
	t_sample m_history_137;
	t_sample m_knob5_noise_135;
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
		m_sw_132 = 0;
		m_sw_133 = ((int)0);
		m_knob4_gain_134 = 5;
		m_knob5_noise_135 = 0;
		m_knob3_res_136 = 15;
		m_history_137 = ((int)0);
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
		t_sample rsub_35 = (((int)1) - m_sw_132);
		t_sample mstosamps_431 = (((int)2) * (samplerate * 0.001));
		t_sample mstosamps_510 = (((int)20) * (samplerate * 0.001));
		t_sample iup_141 = (1 / maximum(1, abs(((int)10))));
		t_sample idown_142 = (1 / maximum(1, abs(((int)400))));
		t_sample twopi_over_sr = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_372 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_144 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_145 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_528 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_345 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_149 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_150 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_547 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_319 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_154 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_155 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_565 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_293 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_159 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_160 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_575 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_267 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_164 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_165 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_590 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_241 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_169 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_170 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_609 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_215 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_174 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_175 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_627 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_189 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_179 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_180 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_645 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_163 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_184 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_185 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_663 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_137 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_189 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_190 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_681 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_111 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_194 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_195 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_699 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_85 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_199 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_200 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_716 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_59 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_204 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_205 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_734 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_493 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_209 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_210 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_752 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_423 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_214 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_215 = (1 / maximum(1, abs(mstosamps_510)));
		t_sample twopi_over_sr_770 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_397 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_219 = (1 / maximum(1, abs(mstosamps_431)));
		t_sample idown_220 = (1 / maximum(1, abs(mstosamps_510)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample sah_24 = __m_sah_138(m_history_137, m_sw_133, ((int)0));
			t_sample gen_514 = sah_24;
			t_sample rsub_22 = (((int)1) - sah_24);
			t_sample history_23_next_25 = fixdenorm(rsub_22);
			t_sample out3 = gen_514;
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample add_515 = (gen_514 + ((int)1));
			t_sample choice_139 = int(add_515);
			t_sample gate_512 = (((choice_139 >= 1) && (choice_139 < 2)) ? in1 : 0);
			t_sample gate_513 = ((choice_139 >= 2) ? in1 : 0);
			t_sample mix_818 = (m_history_131 + (((t_sample)0.0042742627044161) * (m_knob3_res_136 - m_history_131)));
			t_sample mix_13 = mix_818;
			t_sample mix_819 = (m_history_130 + (((t_sample)0.0042742627044161) * (mix_13 - m_history_130)));
			t_sample mix_11 = mix_819;
			t_sample mix_820 = (m_history_129 + (((t_sample)0.0042742627044161) * (mix_11 - m_history_129)));
			t_sample mix_9 = mix_820;
			t_sample gen_508 = mix_9;
			t_sample history_14_next_16 = fixdenorm(mix_13);
			t_sample history_12_next_17 = fixdenorm(mix_11);
			t_sample history_10_next_18 = fixdenorm(mix_9);
			t_sample mul_33 = (gate_513 * m_knob4_gain_134);
			t_sample abs_31 = fabs(mul_33);
			__m_slide_140 = fixdenorm((__m_slide_140 + (((abs_31 > __m_slide_140) ? iup_141 : idown_142) * (abs_31 - __m_slide_140))));
			t_sample slide_30 = __m_slide_140;
			t_sample noise_38 = noise();
			t_sample mul_37 = (noise_38 * m_knob5_noise_135);
			t_sample mul_32 = (slide_30 * mul_37);
			t_sample add_36 = (mul_33 + mul_32);
			t_sample x = add_36;
			t_sample q = gen_508;
			t_sample bw = safediv(((t_sample)284.5), q);
			t_sample r = exp(((-bw) * twopi_over_sr));
			t_sample c1 = ((((int)2) * r) * cos((((t_sample)284.5) * twopi_over_sr)));
			t_sample c2 = ((-r) * r);
			t_sample y = ((((((int)1) - r) * (x - (r * m_x_127))) + (c1 * m_y_126)) + (c2 * m_y_125));
			m_y_125 = m_y_126;
			m_y_126 = y;
			m_x_127 = m_x_128;
			m_x_128 = x;
			t_sample x_368 = in2;
			t_sample q_360 = gen_508;
			t_sample bw_369 = safediv(((t_sample)284.5), q_360);
			t_sample r_362 = exp(((-bw_369) * twopi_over_sr_372));
			t_sample c_371 = ((((int)2) * r_362) * cos((((t_sample)284.5) * twopi_over_sr_372)));
			t_sample c_373 = ((-r_362) * r_362);
			t_sample y_370 = ((((((int)1) - r_362) * (x_368 - (r_362 * m_x_123))) + (c_371 * m_y_122)) + (c_373 * m_y_121));
			m_y_121 = m_y_122;
			m_y_122 = y_370;
			m_x_123 = m_x_124;
			m_x_124 = x_368;
			t_sample abs_359 = fabs(y_370);
			__m_slide_143 = fixdenorm((__m_slide_143 + (((abs_359 > __m_slide_143) ? iup_144 : idown_145) * (abs_359 - __m_slide_143))));
			t_sample slide_358 = __m_slide_143;
			__m_latch_146 = ((rsub_35 != 0) ? slide_358 : __m_latch_146);
			t_sample latch_353 = __m_latch_146;
			t_sample mul_355 = (y * latch_353);
			t_sample dcblock_354 = __m_dcblock_147(mul_355);
			t_sample x_524 = add_36;
			t_sample q_529 = gen_508;
			t_sample bw_522 = safediv(((t_sample)358.5), q_529);
			t_sample r_521 = exp(((-bw_522) * twopi_over_sr_528));
			t_sample c_527 = ((((int)2) * r_521) * cos((((t_sample)358.5) * twopi_over_sr_528)));
			t_sample c_520 = ((-r_521) * r_521);
			t_sample y_526 = ((((((int)1) - r_521) * (x_524 - (r_521 * m_x_119))) + (c_527 * m_y_118)) + (c_520 * m_y_117));
			m_y_117 = m_y_118;
			m_y_118 = y_526;
			m_x_119 = m_x_120;
			m_x_120 = x_524;
			t_sample x_342 = in2;
			t_sample q_334 = gen_508;
			t_sample bw_343 = safediv(((t_sample)358.5), q_334);
			t_sample r_336 = exp(((-bw_343) * twopi_over_sr_345));
			t_sample c_344 = ((((int)2) * r_336) * cos((((t_sample)358.5) * twopi_over_sr_345)));
			t_sample c_347 = ((-r_336) * r_336);
			t_sample y_346 = ((((((int)1) - r_336) * (x_342 - (r_336 * m_x_115))) + (c_344 * m_y_114)) + (c_347 * m_y_113));
			m_y_113 = m_y_114;
			m_y_114 = y_346;
			m_x_115 = m_x_116;
			m_x_116 = x_342;
			t_sample abs_333 = fabs(y_346);
			__m_slide_148 = fixdenorm((__m_slide_148 + (((abs_333 > __m_slide_148) ? iup_149 : idown_150) * (abs_333 - __m_slide_148))));
			t_sample slide_332 = __m_slide_148;
			__m_latch_151 = ((rsub_35 != 0) ? slide_332 : __m_latch_151);
			t_sample latch_327 = __m_latch_151;
			t_sample mul_329 = (y_526 * latch_327);
			t_sample dcblock_328 = __m_dcblock_152(mul_329);
			t_sample x_543 = add_36;
			t_sample q_540 = gen_508;
			t_sample bw_544 = safediv(((int)452), q_540);
			t_sample r_541 = exp(((-bw_544) * twopi_over_sr_547));
			t_sample c_546 = ((((int)2) * r_541) * cos((((int)452) * twopi_over_sr_547)));
			t_sample c_536 = ((-r_541) * r_541);
			t_sample y_542 = ((((((int)1) - r_541) * (x_543 - (r_541 * m_x_111))) + (c_546 * m_y_110)) + (c_536 * m_y_109));
			m_y_109 = m_y_110;
			m_y_110 = y_542;
			m_x_111 = m_x_112;
			m_x_112 = x_543;
			t_sample x_316 = in2;
			t_sample q_308 = gen_508;
			t_sample bw_317 = safediv(((int)452), q_308);
			t_sample r_310 = exp(((-bw_317) * twopi_over_sr_319));
			t_sample c_318 = ((((int)2) * r_310) * cos((((int)452) * twopi_over_sr_319)));
			t_sample c_321 = ((-r_310) * r_310);
			t_sample y_320 = ((((((int)1) - r_310) * (x_316 - (r_310 * m_x_107))) + (c_318 * m_y_106)) + (c_321 * m_y_105));
			m_y_105 = m_y_106;
			m_y_106 = y_320;
			m_x_107 = m_x_108;
			m_x_108 = x_316;
			t_sample abs_307 = fabs(y_320);
			__m_slide_153 = fixdenorm((__m_slide_153 + (((abs_307 > __m_slide_153) ? iup_154 : idown_155) * (abs_307 - __m_slide_153))));
			t_sample slide_306 = __m_slide_153;
			__m_latch_156 = ((rsub_35 != 0) ? slide_306 : __m_latch_156);
			t_sample latch_301 = __m_latch_156;
			t_sample mul_303 = (y_542 * latch_301);
			t_sample dcblock_302 = __m_dcblock_157(mul_303);
			t_sample x_561 = add_36;
			t_sample q_558 = gen_508;
			t_sample bw_562 = safediv(((t_sample)569.5), q_558);
			t_sample r_559 = exp(((-bw_562) * twopi_over_sr_565));
			t_sample c_564 = ((((int)2) * r_559) * cos((((t_sample)569.5) * twopi_over_sr_565)));
			t_sample c_554 = ((-r_559) * r_559);
			t_sample y_560 = ((((((int)1) - r_559) * (x_561 - (r_559 * m_x_103))) + (c_564 * m_y_102)) + (c_554 * m_y_101));
			m_y_101 = m_y_102;
			m_y_102 = y_560;
			m_x_103 = m_x_104;
			m_x_104 = x_561;
			t_sample x_290 = in2;
			t_sample q_282 = gen_508;
			t_sample bw_291 = safediv(((t_sample)569.5), q_282);
			t_sample r_284 = exp(((-bw_291) * twopi_over_sr_293));
			t_sample c_292 = ((((int)2) * r_284) * cos((((t_sample)569.5) * twopi_over_sr_293)));
			t_sample c_295 = ((-r_284) * r_284);
			t_sample y_294 = ((((((int)1) - r_284) * (x_290 - (r_284 * m_x_99))) + (c_292 * m_y_98)) + (c_295 * m_y_97));
			m_y_97 = m_y_98;
			m_y_98 = y_294;
			m_x_99 = m_x_100;
			m_x_100 = x_290;
			t_sample abs_281 = fabs(y_294);
			__m_slide_158 = fixdenorm((__m_slide_158 + (((abs_281 > __m_slide_158) ? iup_159 : idown_160) * (abs_281 - __m_slide_158))));
			t_sample slide_280 = __m_slide_158;
			__m_latch_161 = ((rsub_35 != 0) ? slide_280 : __m_latch_161);
			t_sample latch_275 = __m_latch_161;
			t_sample mul_277 = (y_560 * latch_275);
			t_sample dcblock_276 = __m_dcblock_162(mul_277);
			t_sample x_579 = add_36;
			t_sample q_576 = gen_508;
			t_sample bw_580 = safediv(((t_sample)717.5), q_576);
			t_sample r_577 = exp(((-bw_580) * twopi_over_sr_575));
			t_sample c_582 = ((((int)2) * r_577) * cos((((t_sample)717.5) * twopi_over_sr_575)));
			t_sample c_572 = ((-r_577) * r_577);
			t_sample y_578 = ((((((int)1) - r_577) * (x_579 - (r_577 * m_x_95))) + (c_582 * m_y_94)) + (c_572 * m_y_93));
			m_y_93 = m_y_94;
			m_y_94 = y_578;
			m_x_95 = m_x_96;
			m_x_96 = x_579;
			t_sample x_264 = in2;
			t_sample q_256 = gen_508;
			t_sample bw_265 = safediv(((t_sample)717.5), q_256);
			t_sample r_258 = exp(((-bw_265) * twopi_over_sr_267));
			t_sample c_266 = ((((int)2) * r_258) * cos((((t_sample)717.5) * twopi_over_sr_267)));
			t_sample c_269 = ((-r_258) * r_258);
			t_sample y_268 = ((((((int)1) - r_258) * (x_264 - (r_258 * m_x_91))) + (c_266 * m_y_90)) + (c_269 * m_y_89));
			m_y_89 = m_y_90;
			m_y_90 = y_268;
			m_x_91 = m_x_92;
			m_x_92 = x_264;
			t_sample abs_255 = fabs(y_268);
			__m_slide_163 = fixdenorm((__m_slide_163 + (((abs_255 > __m_slide_163) ? iup_164 : idown_165) * (abs_255 - __m_slide_163))));
			t_sample slide_254 = __m_slide_163;
			__m_latch_166 = ((rsub_35 != 0) ? slide_254 : __m_latch_166);
			t_sample latch_249 = __m_latch_166;
			t_sample mul_251 = (y_578 * latch_249);
			t_sample dcblock_250 = __m_dcblock_167(mul_251);
			t_sample x_595 = add_36;
			t_sample q_592 = gen_508;
			t_sample bw_600 = safediv(((int)904), q_592);
			t_sample r_593 = exp(((-bw_600) * twopi_over_sr_590));
			t_sample c_596 = ((((int)2) * r_593) * cos((((int)904) * twopi_over_sr_590)));
			t_sample c_602 = ((-r_593) * r_593);
			t_sample y_594 = ((((((int)1) - r_593) * (x_595 - (r_593 * m_x_87))) + (c_596 * m_y_86)) + (c_602 * m_y_85));
			m_y_85 = m_y_86;
			m_y_86 = y_594;
			m_x_87 = m_x_88;
			m_x_88 = x_595;
			t_sample x_238 = in2;
			t_sample q_230 = gen_508;
			t_sample bw_239 = safediv(((int)904), q_230);
			t_sample r_232 = exp(((-bw_239) * twopi_over_sr_241));
			t_sample c_240 = ((((int)2) * r_232) * cos((((int)904) * twopi_over_sr_241)));
			t_sample c_243 = ((-r_232) * r_232);
			t_sample y_242 = ((((((int)1) - r_232) * (x_238 - (r_232 * m_x_83))) + (c_240 * m_y_82)) + (c_243 * m_y_81));
			m_y_81 = m_y_82;
			m_y_82 = y_242;
			m_x_83 = m_x_84;
			m_x_84 = x_238;
			t_sample abs_229 = fabs(y_242);
			__m_slide_168 = fixdenorm((__m_slide_168 + (((abs_229 > __m_slide_168) ? iup_169 : idown_170) * (abs_229 - __m_slide_168))));
			t_sample slide_228 = __m_slide_168;
			__m_latch_171 = ((rsub_35 != 0) ? slide_228 : __m_latch_171);
			t_sample latch_223 = __m_latch_171;
			t_sample mul_225 = (y_594 * latch_223);
			t_sample dcblock_224 = __m_dcblock_172(mul_225);
			t_sample x_614 = add_36;
			t_sample q_611 = gen_508;
			t_sample bw_618 = safediv(((int)1139), q_611);
			t_sample r_612 = exp(((-bw_618) * twopi_over_sr_609));
			t_sample c_615 = ((((int)2) * r_612) * cos((((int)1139) * twopi_over_sr_609)));
			t_sample c_608 = ((-r_612) * r_612);
			t_sample y_613 = ((((((int)1) - r_612) * (x_614 - (r_612 * m_x_79))) + (c_615 * m_y_78)) + (c_608 * m_y_77));
			m_y_77 = m_y_78;
			m_y_78 = y_613;
			m_x_79 = m_x_80;
			m_x_80 = x_614;
			t_sample x_212 = in2;
			t_sample q_204 = gen_508;
			t_sample bw_213 = safediv(((int)1139), q_204);
			t_sample r_206 = exp(((-bw_213) * twopi_over_sr_215));
			t_sample c_214 = ((((int)2) * r_206) * cos((((int)1139) * twopi_over_sr_215)));
			t_sample c_217 = ((-r_206) * r_206);
			t_sample y_216 = ((((((int)1) - r_206) * (x_212 - (r_206 * m_x_75))) + (c_214 * m_y_74)) + (c_217 * m_y_73));
			m_y_73 = m_y_74;
			m_y_74 = y_216;
			m_x_75 = m_x_76;
			m_x_76 = x_212;
			t_sample abs_203 = fabs(y_216);
			__m_slide_173 = fixdenorm((__m_slide_173 + (((abs_203 > __m_slide_173) ? iup_174 : idown_175) * (abs_203 - __m_slide_173))));
			t_sample slide_202 = __m_slide_173;
			__m_latch_176 = ((rsub_35 != 0) ? slide_202 : __m_latch_176);
			t_sample latch_197 = __m_latch_176;
			t_sample mul_199 = (y_613 * latch_197);
			t_sample dcblock_198 = __m_dcblock_177(mul_199);
			t_sample x_632 = add_36;
			t_sample q_629 = gen_508;
			t_sample bw_635 = safediv(((int)1435), q_629);
			t_sample r_630 = exp(((-bw_635) * twopi_over_sr_627));
			t_sample c_633 = ((((int)2) * r_630) * cos((((int)1435) * twopi_over_sr_627)));
			t_sample c_626 = ((-r_630) * r_630);
			t_sample y_631 = ((((((int)1) - r_630) * (x_632 - (r_630 * m_x_71))) + (c_633 * m_y_70)) + (c_626 * m_y_69));
			m_y_69 = m_y_70;
			m_y_70 = y_631;
			m_x_71 = m_x_72;
			m_x_72 = x_632;
			t_sample x_186 = in2;
			t_sample q_178 = gen_508;
			t_sample bw_187 = safediv(((int)1435), q_178);
			t_sample r_180 = exp(((-bw_187) * twopi_over_sr_189));
			t_sample c_188 = ((((int)2) * r_180) * cos((((int)1435) * twopi_over_sr_189)));
			t_sample c_191 = ((-r_180) * r_180);
			t_sample y_190 = ((((((int)1) - r_180) * (x_186 - (r_180 * m_x_67))) + (c_188 * m_y_66)) + (c_191 * m_y_65));
			m_y_65 = m_y_66;
			m_y_66 = y_190;
			m_x_67 = m_x_68;
			m_x_68 = x_186;
			t_sample abs_177 = fabs(y_190);
			__m_slide_178 = fixdenorm((__m_slide_178 + (((abs_177 > __m_slide_178) ? iup_179 : idown_180) * (abs_177 - __m_slide_178))));
			t_sample slide_176 = __m_slide_178;
			__m_latch_181 = ((rsub_35 != 0) ? slide_176 : __m_latch_181);
			t_sample latch_171 = __m_latch_181;
			t_sample mul_173 = (y_631 * latch_171);
			t_sample dcblock_172 = __m_dcblock_182(mul_173);
			t_sample x_650 = add_36;
			t_sample q_647 = gen_508;
			t_sample bw_654 = safediv(((int)1808), q_647);
			t_sample r_648 = exp(((-bw_654) * twopi_over_sr_645));
			t_sample c_651 = ((((int)2) * r_648) * cos((((int)1808) * twopi_over_sr_645)));
			t_sample c_644 = ((-r_648) * r_648);
			t_sample y_649 = ((((((int)1) - r_648) * (x_650 - (r_648 * m_x_63))) + (c_651 * m_y_62)) + (c_644 * m_y_61));
			m_y_61 = m_y_62;
			m_y_62 = y_649;
			m_x_63 = m_x_64;
			m_x_64 = x_650;
			t_sample x_160 = in2;
			t_sample q_152 = gen_508;
			t_sample bw_161 = safediv(((int)1808), q_152);
			t_sample r_154 = exp(((-bw_161) * twopi_over_sr_163));
			t_sample c_162 = ((((int)2) * r_154) * cos((((int)1808) * twopi_over_sr_163)));
			t_sample c_165 = ((-r_154) * r_154);
			t_sample y_164 = ((((((int)1) - r_154) * (x_160 - (r_154 * m_x_59))) + (c_162 * m_y_58)) + (c_165 * m_y_57));
			m_y_57 = m_y_58;
			m_y_58 = y_164;
			m_x_59 = m_x_60;
			m_x_60 = x_160;
			t_sample abs_151 = fabs(y_164);
			__m_slide_183 = fixdenorm((__m_slide_183 + (((abs_151 > __m_slide_183) ? iup_184 : idown_185) * (abs_151 - __m_slide_183))));
			t_sample slide_150 = __m_slide_183;
			__m_latch_186 = ((rsub_35 != 0) ? slide_150 : __m_latch_186);
			t_sample latch_145 = __m_latch_186;
			t_sample mul_147 = (y_649 * latch_145);
			t_sample dcblock_146 = __m_dcblock_187(mul_147);
			t_sample x_669 = add_36;
			t_sample q_666 = gen_508;
			t_sample bw_673 = safediv(((int)2260), q_666);
			t_sample r_667 = exp(((-bw_673) * twopi_over_sr_663));
			t_sample c_670 = ((((int)2) * r_667) * cos((((int)2260) * twopi_over_sr_663)));
			t_sample c_662 = ((-r_667) * r_667);
			t_sample y_668 = ((((((int)1) - r_667) * (x_669 - (r_667 * m_x_55))) + (c_670 * m_y_54)) + (c_662 * m_y_53));
			m_y_53 = m_y_54;
			m_y_54 = y_668;
			m_x_55 = m_x_56;
			m_x_56 = x_669;
			t_sample x_134 = in2;
			t_sample q_126 = gen_508;
			t_sample bw_135 = safediv(((int)2260), q_126);
			t_sample r_128 = exp(((-bw_135) * twopi_over_sr_137));
			t_sample c_136 = ((((int)2) * r_128) * cos((((int)2260) * twopi_over_sr_137)));
			t_sample c_139 = ((-r_128) * r_128);
			t_sample y_138 = ((((((int)1) - r_128) * (x_134 - (r_128 * m_x_51))) + (c_136 * m_y_50)) + (c_139 * m_y_49));
			m_y_49 = m_y_50;
			m_y_50 = y_138;
			m_x_51 = m_x_52;
			m_x_52 = x_134;
			t_sample abs_125 = fabs(y_138);
			__m_slide_188 = fixdenorm((__m_slide_188 + (((abs_125 > __m_slide_188) ? iup_189 : idown_190) * (abs_125 - __m_slide_188))));
			t_sample slide_124 = __m_slide_188;
			__m_latch_191 = ((rsub_35 != 0) ? slide_124 : __m_latch_191);
			t_sample latch_119 = __m_latch_191;
			t_sample mul_121 = (y_668 * latch_119);
			t_sample dcblock_120 = __m_dcblock_192(mul_121);
			t_sample x_687 = add_36;
			t_sample q_684 = gen_508;
			t_sample bw_690 = safediv(((int)2852), q_684);
			t_sample r_685 = exp(((-bw_690) * twopi_over_sr_681));
			t_sample c_688 = ((((int)2) * r_685) * cos((((int)2852) * twopi_over_sr_681)));
			t_sample c_680 = ((-r_685) * r_685);
			t_sample y_686 = ((((((int)1) - r_685) * (x_687 - (r_685 * m_x_47))) + (c_688 * m_y_46)) + (c_680 * m_y_45));
			m_y_45 = m_y_46;
			m_y_46 = y_686;
			m_x_47 = m_x_48;
			m_x_48 = x_687;
			t_sample x_108 = in2;
			t_sample q_100 = gen_508;
			t_sample bw_109 = safediv(((int)2852), q_100);
			t_sample r_102 = exp(((-bw_109) * twopi_over_sr_111));
			t_sample c_110 = ((((int)2) * r_102) * cos((((int)2852) * twopi_over_sr_111)));
			t_sample c_113 = ((-r_102) * r_102);
			t_sample y_112 = ((((((int)1) - r_102) * (x_108 - (r_102 * m_x_43))) + (c_110 * m_y_42)) + (c_113 * m_y_41));
			m_y_41 = m_y_42;
			m_y_42 = y_112;
			m_x_43 = m_x_44;
			m_x_44 = x_108;
			t_sample abs_99 = fabs(y_112);
			__m_slide_193 = fixdenorm((__m_slide_193 + (((abs_99 > __m_slide_193) ? iup_194 : idown_195) * (abs_99 - __m_slide_193))));
			t_sample slide_98 = __m_slide_193;
			__m_latch_196 = ((rsub_35 != 0) ? slide_98 : __m_latch_196);
			t_sample latch_93 = __m_latch_196;
			t_sample mul_95 = (y_686 * latch_93);
			t_sample dcblock_94 = __m_dcblock_197(mul_95);
			t_sample x_705 = add_36;
			t_sample q_702 = gen_508;
			t_sample bw_708 = safediv(((int)3616), q_702);
			t_sample r_703 = exp(((-bw_708) * twopi_over_sr_699));
			t_sample c_706 = ((((int)2) * r_703) * cos((((int)3616) * twopi_over_sr_699)));
			t_sample c_698 = ((-r_703) * r_703);
			t_sample y_704 = ((((((int)1) - r_703) * (x_705 - (r_703 * m_x_39))) + (c_706 * m_y_38)) + (c_698 * m_y_37));
			m_y_37 = m_y_38;
			m_y_38 = y_704;
			m_x_39 = m_x_40;
			m_x_40 = x_705;
			t_sample x_82 = in2;
			t_sample q_74 = gen_508;
			t_sample bw_83 = safediv(((int)3616), q_74);
			t_sample r_76 = exp(((-bw_83) * twopi_over_sr_85));
			t_sample c_84 = ((((int)2) * r_76) * cos((((int)3616) * twopi_over_sr_85)));
			t_sample c_87 = ((-r_76) * r_76);
			t_sample y_86 = ((((((int)1) - r_76) * (x_82 - (r_76 * m_x_35))) + (c_84 * m_y_34)) + (c_87 * m_y_33));
			m_y_33 = m_y_34;
			m_y_34 = y_86;
			m_x_35 = m_x_36;
			m_x_36 = x_82;
			t_sample abs_73 = fabs(y_86);
			__m_slide_198 = fixdenorm((__m_slide_198 + (((abs_73 > __m_slide_198) ? iup_199 : idown_200) * (abs_73 - __m_slide_198))));
			t_sample slide_72 = __m_slide_198;
			__m_latch_201 = ((rsub_35 != 0) ? slide_72 : __m_latch_201);
			t_sample latch_67 = __m_latch_201;
			t_sample mul_69 = (y_704 * latch_67);
			t_sample dcblock_68 = __m_dcblock_202(mul_69);
			t_sample x_720 = add_36;
			t_sample q_717 = gen_508;
			t_sample bw_726 = safediv(((int)4556), q_717);
			t_sample r_718 = exp(((-bw_726) * twopi_over_sr_716));
			t_sample c_729 = ((((int)2) * r_718) * cos((((int)4556) * twopi_over_sr_716)));
			t_sample c_725 = ((-r_718) * r_718);
			t_sample y_719 = ((((((int)1) - r_718) * (x_720 - (r_718 * m_x_31))) + (c_729 * m_y_30)) + (c_725 * m_y_29));
			m_y_29 = m_y_30;
			m_y_30 = y_719;
			m_x_31 = m_x_32;
			m_x_32 = x_720;
			t_sample x_56 = in2;
			t_sample q_48 = gen_508;
			t_sample bw_57 = safediv(((int)4556), q_48);
			t_sample r_50 = exp(((-bw_57) * twopi_over_sr_59));
			t_sample c_58 = ((((int)2) * r_50) * cos((((int)4556) * twopi_over_sr_59)));
			t_sample c_61 = ((-r_50) * r_50);
			t_sample y_60 = ((((((int)1) - r_50) * (x_56 - (r_50 * m_x_27))) + (c_58 * m_y_26)) + (c_61 * m_y_25));
			m_y_25 = m_y_26;
			m_y_26 = y_60;
			m_x_27 = m_x_28;
			m_x_28 = x_56;
			t_sample abs_47 = fabs(y_60);
			__m_slide_203 = fixdenorm((__m_slide_203 + (((abs_47 > __m_slide_203) ? iup_204 : idown_205) * (abs_47 - __m_slide_203))));
			t_sample slide_46 = __m_slide_203;
			__m_latch_206 = ((rsub_35 != 0) ? slide_46 : __m_latch_206);
			t_sample latch_39 = __m_latch_206;
			t_sample mul_41 = (y_719 * latch_39);
			t_sample dcblock_40 = __m_dcblock_207(mul_41);
			t_sample x_738 = add_36;
			t_sample q_735 = gen_508;
			t_sample bw_744 = safediv(((t_sample)104.5), q_735);
			t_sample r_736 = exp(((-bw_744) * twopi_over_sr_734));
			t_sample c_740 = ((((int)2) * r_736) * cos((((t_sample)104.5) * twopi_over_sr_734)));
			t_sample c_743 = ((-r_736) * r_736);
			t_sample y_737 = ((((((int)1) - r_736) * (x_738 - (r_736 * m_x_23))) + (c_740 * m_y_22)) + (c_743 * m_y_21));
			m_y_21 = m_y_22;
			m_y_22 = y_737;
			m_x_23 = m_x_24;
			m_x_24 = x_738;
			t_sample x_490 = in2;
			t_sample q_482 = gen_508;
			t_sample bw_491 = safediv(((t_sample)104.5), q_482);
			t_sample r_484 = exp(((-bw_491) * twopi_over_sr_493));
			t_sample c_492 = ((((int)2) * r_484) * cos((((t_sample)104.5) * twopi_over_sr_493)));
			t_sample c_495 = ((-r_484) * r_484);
			t_sample y_494 = ((((((int)1) - r_484) * (x_490 - (r_484 * m_x_19))) + (c_492 * m_y_18)) + (c_495 * m_y_17));
			m_y_17 = m_y_18;
			m_y_18 = y_494;
			m_x_19 = m_x_20;
			m_x_20 = x_490;
			t_sample abs_481 = fabs(y_494);
			__m_slide_208 = fixdenorm((__m_slide_208 + (((abs_481 > __m_slide_208) ? iup_209 : idown_210) * (abs_481 - __m_slide_208))));
			t_sample slide_480 = __m_slide_208;
			__m_latch_211 = ((rsub_35 != 0) ? slide_480 : __m_latch_211);
			t_sample latch_475 = __m_latch_211;
			t_sample mul_477 = (y_737 * latch_475);
			t_sample dcblock_476 = __m_dcblock_212(mul_477);
			t_sample x_756 = add_36;
			t_sample q_753 = gen_508;
			t_sample bw_763 = safediv(((t_sample)179.5), q_753);
			t_sample r_754 = exp(((-bw_763) * twopi_over_sr_752));
			t_sample c_758 = ((((int)2) * r_754) * cos((((t_sample)179.5) * twopi_over_sr_752)));
			t_sample c_762 = ((-r_754) * r_754);
			t_sample y_755 = ((((((int)1) - r_754) * (x_756 - (r_754 * m_x_15))) + (c_758 * m_y_14)) + (c_762 * m_y_13));
			m_y_13 = m_y_14;
			m_y_14 = y_755;
			m_x_15 = m_x_16;
			m_x_16 = x_756;
			t_sample x_420 = in2;
			t_sample q_412 = gen_508;
			t_sample bw_421 = safediv(((t_sample)179.5), q_412);
			t_sample r_414 = exp(((-bw_421) * twopi_over_sr_423));
			t_sample c_422 = ((((int)2) * r_414) * cos((((t_sample)179.5) * twopi_over_sr_423)));
			t_sample c_425 = ((-r_414) * r_414);
			t_sample y_424 = ((((((int)1) - r_414) * (x_420 - (r_414 * m_x_11))) + (c_422 * m_y_10)) + (c_425 * m_y_9));
			m_y_9 = m_y_10;
			m_y_10 = y_424;
			m_x_11 = m_x_12;
			m_x_12 = x_420;
			t_sample abs_411 = fabs(y_424);
			__m_slide_213 = fixdenorm((__m_slide_213 + (((abs_411 > __m_slide_213) ? iup_214 : idown_215) * (abs_411 - __m_slide_213))));
			t_sample slide_410 = __m_slide_213;
			__m_latch_216 = ((rsub_35 != 0) ? slide_410 : __m_latch_216);
			t_sample latch_405 = __m_latch_216;
			t_sample mul_407 = (y_755 * latch_405);
			t_sample dcblock_406 = __m_dcblock_217(mul_407);
			t_sample x_774 = add_36;
			t_sample q_771 = gen_508;
			t_sample bw_782 = safediv(((int)226), q_771);
			t_sample r_772 = exp(((-bw_782) * twopi_over_sr_770));
			t_sample c_776 = ((((int)2) * r_772) * cos((((int)226) * twopi_over_sr_770)));
			t_sample c_780 = ((-r_772) * r_772);
			t_sample y_773 = ((((((int)1) - r_772) * (x_774 - (r_772 * m_x_7))) + (c_776 * m_y_6)) + (c_780 * m_y_5));
			m_y_5 = m_y_6;
			m_y_6 = y_773;
			m_x_7 = m_x_8;
			m_x_8 = x_774;
			t_sample x_394 = in2;
			t_sample q_386 = gen_508;
			t_sample bw_395 = safediv(((int)226), q_386);
			t_sample r_388 = exp(((-bw_395) * twopi_over_sr_397));
			t_sample c_396 = ((((int)2) * r_388) * cos((((int)226) * twopi_over_sr_397)));
			t_sample c_399 = ((-r_388) * r_388);
			t_sample y_398 = ((((((int)1) - r_388) * (x_394 - (r_388 * m_x_3))) + (c_396 * m_y_2)) + (c_399 * m_y_1));
			m_y_1 = m_y_2;
			m_y_2 = y_398;
			m_x_3 = m_x_4;
			m_x_4 = x_394;
			t_sample abs_385 = fabs(y_398);
			__m_slide_218 = fixdenorm((__m_slide_218 + (((abs_385 > __m_slide_218) ? iup_219 : idown_220) * (abs_385 - __m_slide_218))));
			t_sample slide_384 = __m_slide_218;
			__m_latch_221 = ((rsub_35 != 0) ? slide_384 : __m_latch_221);
			t_sample latch_379 = __m_latch_221;
			t_sample mul_381 = (y_773 * latch_379);
			t_sample dcblock_380 = __m_dcblock_222(mul_381);
			t_sample pass_509 = (((((((((((((((dcblock_380 + dcblock_406) + dcblock_476) + dcblock_40) + dcblock_68) + dcblock_94) + dcblock_120) + dcblock_146) + dcblock_172) + dcblock_198) + dcblock_224) + dcblock_250) + dcblock_276) + dcblock_302) + dcblock_328) + dcblock_354);
			t_sample add_517 = (pass_509 + gate_512);
			t_sample out1 = add_517;
			t_sample add_516 = (pass_509 + gate_512);
			t_sample out2 = add_516;
			m_history_137 = history_23_next_25;
			m_history_131 = history_14_next_16;
			m_history_129 = history_10_next_18;
			m_history_130 = history_12_next_17;
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
	inline void set_sw2(t_param _value) {
		m_sw_132 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_133 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_gain(t_param _value) {
		m_knob4_gain_134 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
	};
	inline void set_knob5_noise(t_param _value) {
		m_knob5_noise_135 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_res(t_param _value) {
		m_knob3_res_136 = (_value < 15 ? 15 : (_value > 50 ? 50 : _value));
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
		case 0: *value = self->m_knob3_res_136; break;
		case 1: *value = self->m_knob4_gain_134; break;
		case 2: *value = self->m_knob5_noise_135; break;
		case 3: *value = self->m_sw_133; break;
		case 4: *value = self->m_sw_132; break;
		
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
	// initialize parameter 0 ("m_knob3_res_136")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_res_136;
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
	// initialize parameter 2 ("m_knob5_noise_135")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_noise";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_noise_135;
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
	// initialize parameter 4 ("m_sw_132")
	pi = self->__commonstate.params + 4;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_132;
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
