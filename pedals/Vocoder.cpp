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
	t_sample m_knob4_gain_133;
	t_sample m_knob3_res_134;
	t_sample __m_slide_140;
	t_sample __m_slide_143;
	t_sample __m_latch_146;
	t_sample m_x_123;
	t_sample m_y_14;
	t_sample m_sw_136;
	t_sample m_sw_137;
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
		m_history_132 = ((int)0);
		m_knob4_gain_133 = 5;
		m_knob3_res_134 = 15;
		m_knob5_noise_135 = 0;
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
		t_sample rsub_10690 = (((int)1) - m_sw_137);
		t_sample mstosamps_11086 = (((int)2) * (samplerate * 0.001));
		t_sample mstosamps_11177 = (((int)20) * (samplerate * 0.001));
		t_sample iup_141 = (1 / maximum(1, abs(((int)10))));
		t_sample idown_142 = (1 / maximum(1, abs(((int)400))));
		t_sample twopi_over_sr = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_11027 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_144 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_145 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11481 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_11000 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_149 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_150 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11500 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_10974 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_154 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_155 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11518 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_10948 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_159 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_160 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11536 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_10922 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_164 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_165 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11544 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_10896 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_169 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_170 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11562 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_10871 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_174 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_175 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11580 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_10844 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_179 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_180 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11598 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_10818 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_184 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_185 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11616 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_10792 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_189 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_190 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11634 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_10766 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_194 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_195 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11652 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_10740 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_199 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_200 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11669 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_10714 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_204 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_205 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11687 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_11148 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_209 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_210 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11705 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_11078 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_214 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_215 = (1 / maximum(1, abs(mstosamps_11177)));
		t_sample twopi_over_sr_11723 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_11052 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_219 = (1 / maximum(1, abs(mstosamps_11086)));
		t_sample idown_220 = (1 / maximum(1, abs(mstosamps_11177)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_11183 = __m_sah_138(m_history_132, m_sw_136, ((int)0));
			t_sample gen_11185 = sah_11183;
			t_sample rsub_11181 = (((int)1) - sah_11183);
			t_sample history_11182_next_11184 = fixdenorm(rsub_11181);
			t_sample out3 = gen_11185;
			t_sample add_11186 = (gen_11185 + ((int)1));
			t_sample choice_139 = int(add_11186);
			t_sample gate_11179 = (((choice_139 >= 1) && (choice_139 < 2)) ? in1 : 0);
			t_sample gate_11180 = ((choice_139 >= 2) ? in1 : 0);
			t_sample mix_11747 = (m_history_131 + (((t_sample)0.0019634941468452) * (m_knob3_res_134 - m_history_131)));
			t_sample mix_11167 = mix_11747;
			t_sample mix_11748 = (m_history_130 + (((t_sample)0.0019634941468452) * (mix_11167 - m_history_130)));
			t_sample mix_11165 = mix_11748;
			t_sample mix_11749 = (m_history_129 + (((t_sample)0.0019634941468452) * (mix_11165 - m_history_129)));
			t_sample mix_11163 = mix_11749;
			t_sample gen_11175 = mix_11163;
			t_sample history_11169_next_11172 = fixdenorm(mix_11167);
			t_sample history_11166_next_11173 = fixdenorm(mix_11165);
			t_sample history_11164_next_11174 = fixdenorm(mix_11163);
			t_sample mul_10688 = (gate_11180 * m_knob4_gain_133);
			t_sample abs_10686 = fabs(gate_11180);
			__m_slide_140 = fixdenorm((__m_slide_140 + (((abs_10686 > __m_slide_140) ? iup_141 : idown_142) * (abs_10686 - __m_slide_140))));
			t_sample slide_10685 = __m_slide_140;
			t_sample noise_10693 = noise();
			t_sample mul_10692 = (noise_10693 * m_knob5_noise_135);
			t_sample mul_10687 = (slide_10685 * mul_10692);
			t_sample add_10691 = (mul_10688 + mul_10687);
			t_sample x = add_10691;
			t_sample q = gen_11175;
			t_sample bw = safediv(((t_sample)284.5), q);
			t_sample r = exp(((-bw) * twopi_over_sr));
			t_sample c1 = ((((int)2) * r) * cos((((t_sample)284.5) * twopi_over_sr)));
			t_sample c2 = ((-r) * r);
			t_sample y = ((((((int)1) - r) * (x - (r * m_x_127))) + (c1 * m_y_126)) + (c2 * m_y_125));
			m_y_125 = m_y_126;
			m_y_126 = y;
			m_x_127 = m_x_128;
			m_x_128 = x;
			t_sample x_11023 = in2;
			t_sample q_11015 = gen_11175;
			t_sample bw_11024 = safediv(((t_sample)284.5), q_11015);
			t_sample r_11017 = exp(((-bw_11024) * twopi_over_sr_11027));
			t_sample c_11026 = ((((int)2) * r_11017) * cos((((t_sample)284.5) * twopi_over_sr_11027)));
			t_sample c_11028 = ((-r_11017) * r_11017);
			t_sample y_11016 = ((((((int)1) - r_11017) * (x_11023 - (r_11017 * m_x_123))) + (c_11026 * m_y_122)) + (c_11028 * m_y_121));
			m_y_121 = m_y_122;
			m_y_122 = y_11016;
			m_x_123 = m_x_124;
			m_x_124 = x_11023;
			t_sample abs_11014 = fabs(y_11016);
			__m_slide_143 = fixdenorm((__m_slide_143 + (((abs_11014 > __m_slide_143) ? iup_144 : idown_145) * (abs_11014 - __m_slide_143))));
			t_sample slide_11013 = __m_slide_143;
			__m_latch_146 = ((rsub_10690 != 0) ? slide_11013 : __m_latch_146);
			t_sample latch_11008 = __m_latch_146;
			t_sample mul_11010 = (y * latch_11008);
			t_sample dcblock_11009 = __m_dcblock_147(mul_11010);
			t_sample x_11477 = add_10691;
			t_sample q_11475 = gen_11175;
			t_sample bw_11480 = safediv(((t_sample)358.5), q_11475);
			t_sample r_11476 = exp(((-bw_11480) * twopi_over_sr_11481));
			t_sample c_11479 = ((((int)2) * r_11476) * cos((((t_sample)358.5) * twopi_over_sr_11481)));
			t_sample c_11474 = ((-r_11476) * r_11476);
			t_sample y_11478 = ((((((int)1) - r_11476) * (x_11477 - (r_11476 * m_x_119))) + (c_11479 * m_y_118)) + (c_11474 * m_y_117));
			m_y_117 = m_y_118;
			m_y_118 = y_11478;
			m_x_119 = m_x_120;
			m_x_120 = x_11477;
			t_sample x_10996 = in2;
			t_sample q_10989 = gen_11175;
			t_sample bw_10997 = safediv(((t_sample)358.5), q_10989);
			t_sample r_10990 = exp(((-bw_10997) * twopi_over_sr_11000));
			t_sample c_10999 = ((((int)2) * r_10990) * cos((((t_sample)358.5) * twopi_over_sr_11000)));
			t_sample c_11002 = ((-r_10990) * r_10990);
			t_sample y_11001 = ((((((int)1) - r_10990) * (x_10996 - (r_10990 * m_x_115))) + (c_10999 * m_y_114)) + (c_11002 * m_y_113));
			m_y_113 = m_y_114;
			m_y_114 = y_11001;
			m_x_115 = m_x_116;
			m_x_116 = x_10996;
			t_sample abs_10988 = fabs(y_11001);
			__m_slide_148 = fixdenorm((__m_slide_148 + (((abs_10988 > __m_slide_148) ? iup_149 : idown_150) * (abs_10988 - __m_slide_148))));
			t_sample slide_10987 = __m_slide_148;
			__m_latch_151 = ((rsub_10690 != 0) ? slide_10987 : __m_latch_151);
			t_sample latch_10982 = __m_latch_151;
			t_sample mul_10984 = (y_11478 * latch_10982);
			t_sample dcblock_10983 = __m_dcblock_152(mul_10984);
			t_sample x_11496 = add_10691;
			t_sample q_11493 = gen_11175;
			t_sample bw_11499 = safediv(((int)452), q_11493);
			t_sample r_11494 = exp(((-bw_11499) * twopi_over_sr_11500));
			t_sample c_11498 = ((((int)2) * r_11494) * cos((((int)452) * twopi_over_sr_11500)));
			t_sample c_11490 = ((-r_11494) * r_11494);
			t_sample y_11495 = ((((((int)1) - r_11494) * (x_11496 - (r_11494 * m_x_111))) + (c_11498 * m_y_110)) + (c_11490 * m_y_109));
			m_y_109 = m_y_110;
			m_y_110 = y_11495;
			m_x_111 = m_x_112;
			m_x_112 = x_11496;
			t_sample x_10970 = in2;
			t_sample q_10963 = gen_11175;
			t_sample bw_10971 = safediv(((int)452), q_10963);
			t_sample r_10964 = exp(((-bw_10971) * twopi_over_sr_10974));
			t_sample c_10973 = ((((int)2) * r_10964) * cos((((int)452) * twopi_over_sr_10974)));
			t_sample c_10976 = ((-r_10964) * r_10964);
			t_sample y_10975 = ((((((int)1) - r_10964) * (x_10970 - (r_10964 * m_x_107))) + (c_10973 * m_y_106)) + (c_10976 * m_y_105));
			m_y_105 = m_y_106;
			m_y_106 = y_10975;
			m_x_107 = m_x_108;
			m_x_108 = x_10970;
			t_sample abs_10962 = fabs(y_10975);
			__m_slide_153 = fixdenorm((__m_slide_153 + (((abs_10962 > __m_slide_153) ? iup_154 : idown_155) * (abs_10962 - __m_slide_153))));
			t_sample slide_10961 = __m_slide_153;
			__m_latch_156 = ((rsub_10690 != 0) ? slide_10961 : __m_latch_156);
			t_sample latch_10956 = __m_latch_156;
			t_sample mul_10958 = (y_11495 * latch_10956);
			t_sample dcblock_10957 = __m_dcblock_157(mul_10958);
			t_sample x_11513 = add_10691;
			t_sample q_11511 = gen_11175;
			t_sample bw_11516 = safediv(((t_sample)569.5), q_11511);
			t_sample r_11512 = exp(((-bw_11516) * twopi_over_sr_11518));
			t_sample c_11515 = ((((int)2) * r_11512) * cos((((t_sample)569.5) * twopi_over_sr_11518)));
			t_sample c_11508 = ((-r_11512) * r_11512);
			t_sample y_11517 = ((((((int)1) - r_11512) * (x_11513 - (r_11512 * m_x_103))) + (c_11515 * m_y_102)) + (c_11508 * m_y_101));
			m_y_101 = m_y_102;
			m_y_102 = y_11517;
			m_x_103 = m_x_104;
			m_x_104 = x_11513;
			t_sample x_10945 = in2;
			t_sample q_10937 = gen_11175;
			t_sample bw_10946 = safediv(((t_sample)569.5), q_10937);
			t_sample r_10939 = exp(((-bw_10946) * twopi_over_sr_10948));
			t_sample c_10947 = ((((int)2) * r_10939) * cos((((t_sample)569.5) * twopi_over_sr_10948)));
			t_sample c_10950 = ((-r_10939) * r_10939);
			t_sample y_10949 = ((((((int)1) - r_10939) * (x_10945 - (r_10939 * m_x_99))) + (c_10947 * m_y_98)) + (c_10950 * m_y_97));
			m_y_97 = m_y_98;
			m_y_98 = y_10949;
			m_x_99 = m_x_100;
			m_x_100 = x_10945;
			t_sample abs_10936 = fabs(y_10949);
			__m_slide_158 = fixdenorm((__m_slide_158 + (((abs_10936 > __m_slide_158) ? iup_159 : idown_160) * (abs_10936 - __m_slide_158))));
			t_sample slide_10935 = __m_slide_158;
			__m_latch_161 = ((rsub_10690 != 0) ? slide_10935 : __m_latch_161);
			t_sample latch_10930 = __m_latch_161;
			t_sample mul_10932 = (y_11517 * latch_10930);
			t_sample dcblock_10931 = __m_dcblock_162(mul_10932);
			t_sample x_11530 = add_10691;
			t_sample q_11528 = gen_11175;
			t_sample bw_11535 = safediv(((t_sample)717.5), q_11528);
			t_sample r_11529 = exp(((-bw_11535) * twopi_over_sr_11536));
			t_sample c_11532 = ((((int)2) * r_11529) * cos((((t_sample)717.5) * twopi_over_sr_11536)));
			t_sample c_11525 = ((-r_11529) * r_11529);
			t_sample y_11534 = ((((((int)1) - r_11529) * (x_11530 - (r_11529 * m_x_95))) + (c_11532 * m_y_94)) + (c_11525 * m_y_93));
			m_y_93 = m_y_94;
			m_y_94 = y_11534;
			m_x_95 = m_x_96;
			m_x_96 = x_11530;
			t_sample x_10919 = in2;
			t_sample q_10911 = gen_11175;
			t_sample bw_10920 = safediv(((t_sample)717.5), q_10911);
			t_sample r_10913 = exp(((-bw_10920) * twopi_over_sr_10922));
			t_sample c_10921 = ((((int)2) * r_10913) * cos((((t_sample)717.5) * twopi_over_sr_10922)));
			t_sample c_10924 = ((-r_10913) * r_10913);
			t_sample y_10923 = ((((((int)1) - r_10913) * (x_10919 - (r_10913 * m_x_91))) + (c_10921 * m_y_90)) + (c_10924 * m_y_89));
			m_y_89 = m_y_90;
			m_y_90 = y_10923;
			m_x_91 = m_x_92;
			m_x_92 = x_10919;
			t_sample abs_10910 = fabs(y_10923);
			__m_slide_163 = fixdenorm((__m_slide_163 + (((abs_10910 > __m_slide_163) ? iup_164 : idown_165) * (abs_10910 - __m_slide_163))));
			t_sample slide_10909 = __m_slide_163;
			__m_latch_166 = ((rsub_10690 != 0) ? slide_10909 : __m_latch_166);
			t_sample latch_10904 = __m_latch_166;
			t_sample mul_10906 = (y_11534 * latch_10904);
			t_sample dcblock_10905 = __m_dcblock_167(mul_10906);
			t_sample x_11550 = add_10691;
			t_sample q_11547 = gen_11175;
			t_sample bw_11556 = safediv(((int)904), q_11547);
			t_sample r_11548 = exp(((-bw_11556) * twopi_over_sr_11544));
			t_sample c_11551 = ((((int)2) * r_11548) * cos((((int)904) * twopi_over_sr_11544)));
			t_sample c_11543 = ((-r_11548) * r_11548);
			t_sample y_11549 = ((((((int)1) - r_11548) * (x_11550 - (r_11548 * m_x_87))) + (c_11551 * m_y_86)) + (c_11543 * m_y_85));
			m_y_85 = m_y_86;
			m_y_86 = y_11549;
			m_x_87 = m_x_88;
			m_x_88 = x_11550;
			t_sample x_10892 = in2;
			t_sample q_10885 = gen_11175;
			t_sample bw_10893 = safediv(((int)904), q_10885);
			t_sample r_10886 = exp(((-bw_10893) * twopi_over_sr_10896));
			t_sample c_10895 = ((((int)2) * r_10886) * cos((((int)904) * twopi_over_sr_10896)));
			t_sample c_10898 = ((-r_10886) * r_10886);
			t_sample y_10897 = ((((((int)1) - r_10886) * (x_10892 - (r_10886 * m_x_83))) + (c_10895 * m_y_82)) + (c_10898 * m_y_81));
			m_y_81 = m_y_82;
			m_y_82 = y_10897;
			m_x_83 = m_x_84;
			m_x_84 = x_10892;
			t_sample abs_10884 = fabs(y_10897);
			__m_slide_168 = fixdenorm((__m_slide_168 + (((abs_10884 > __m_slide_168) ? iup_169 : idown_170) * (abs_10884 - __m_slide_168))));
			t_sample slide_10883 = __m_slide_168;
			__m_latch_171 = ((rsub_10690 != 0) ? slide_10883 : __m_latch_171);
			t_sample latch_10878 = __m_latch_171;
			t_sample mul_10880 = (y_11549 * latch_10878);
			t_sample dcblock_10879 = __m_dcblock_172(mul_10880);
			t_sample x_11568 = add_10691;
			t_sample q_11565 = gen_11175;
			t_sample bw_11574 = safediv(((int)1139), q_11565);
			t_sample r_11566 = exp(((-bw_11574) * twopi_over_sr_11562));
			t_sample c_11569 = ((((int)2) * r_11566) * cos((((int)1139) * twopi_over_sr_11562)));
			t_sample c_11561 = ((-r_11566) * r_11566);
			t_sample y_11567 = ((((((int)1) - r_11566) * (x_11568 - (r_11566 * m_x_79))) + (c_11569 * m_y_78)) + (c_11561 * m_y_77));
			m_y_77 = m_y_78;
			m_y_78 = y_11567;
			m_x_79 = m_x_80;
			m_x_80 = x_11568;
			t_sample x_10867 = in2;
			t_sample q_10859 = gen_11175;
			t_sample bw_10868 = safediv(((int)1139), q_10859);
			t_sample r_10861 = exp(((-bw_10868) * twopi_over_sr_10871));
			t_sample c_10870 = ((((int)2) * r_10861) * cos((((int)1139) * twopi_over_sr_10871)));
			t_sample c_10872 = ((-r_10861) * r_10861);
			t_sample y_10860 = ((((((int)1) - r_10861) * (x_10867 - (r_10861 * m_x_75))) + (c_10870 * m_y_74)) + (c_10872 * m_y_73));
			m_y_73 = m_y_74;
			m_y_74 = y_10860;
			m_x_75 = m_x_76;
			m_x_76 = x_10867;
			t_sample abs_10858 = fabs(y_10860);
			__m_slide_173 = fixdenorm((__m_slide_173 + (((abs_10858 > __m_slide_173) ? iup_174 : idown_175) * (abs_10858 - __m_slide_173))));
			t_sample slide_10857 = __m_slide_173;
			__m_latch_176 = ((rsub_10690 != 0) ? slide_10857 : __m_latch_176);
			t_sample latch_10852 = __m_latch_176;
			t_sample mul_10854 = (y_11567 * latch_10852);
			t_sample dcblock_10853 = __m_dcblock_177(mul_10854);
			t_sample x_11586 = add_10691;
			t_sample q_11583 = gen_11175;
			t_sample bw_11592 = safediv(((int)1435), q_11583);
			t_sample r_11584 = exp(((-bw_11592) * twopi_over_sr_11580));
			t_sample c_11587 = ((((int)2) * r_11584) * cos((((int)1435) * twopi_over_sr_11580)));
			t_sample c_11579 = ((-r_11584) * r_11584);
			t_sample y_11585 = ((((((int)1) - r_11584) * (x_11586 - (r_11584 * m_x_71))) + (c_11587 * m_y_70)) + (c_11579 * m_y_69));
			m_y_69 = m_y_70;
			m_y_70 = y_11585;
			m_x_71 = m_x_72;
			m_x_72 = x_11586;
			t_sample x_10840 = in2;
			t_sample q_10833 = gen_11175;
			t_sample bw_10841 = safediv(((int)1435), q_10833);
			t_sample r_10834 = exp(((-bw_10841) * twopi_over_sr_10844));
			t_sample c_10843 = ((((int)2) * r_10834) * cos((((int)1435) * twopi_over_sr_10844)));
			t_sample c_10846 = ((-r_10834) * r_10834);
			t_sample y_10845 = ((((((int)1) - r_10834) * (x_10840 - (r_10834 * m_x_67))) + (c_10843 * m_y_66)) + (c_10846 * m_y_65));
			m_y_65 = m_y_66;
			m_y_66 = y_10845;
			m_x_67 = m_x_68;
			m_x_68 = x_10840;
			t_sample abs_10832 = fabs(y_10845);
			__m_slide_178 = fixdenorm((__m_slide_178 + (((abs_10832 > __m_slide_178) ? iup_179 : idown_180) * (abs_10832 - __m_slide_178))));
			t_sample slide_10831 = __m_slide_178;
			__m_latch_181 = ((rsub_10690 != 0) ? slide_10831 : __m_latch_181);
			t_sample latch_10826 = __m_latch_181;
			t_sample mul_10828 = (y_11585 * latch_10826);
			t_sample dcblock_10827 = __m_dcblock_182(mul_10828);
			t_sample x_11604 = add_10691;
			t_sample q_11601 = gen_11175;
			t_sample bw_11609 = safediv(((int)1808), q_11601);
			t_sample r_11602 = exp(((-bw_11609) * twopi_over_sr_11598));
			t_sample c_11605 = ((((int)2) * r_11602) * cos((((int)1808) * twopi_over_sr_11598)));
			t_sample c_11597 = ((-r_11602) * r_11602);
			t_sample y_11603 = ((((((int)1) - r_11602) * (x_11604 - (r_11602 * m_x_63))) + (c_11605 * m_y_62)) + (c_11597 * m_y_61));
			m_y_61 = m_y_62;
			m_y_62 = y_11603;
			m_x_63 = m_x_64;
			m_x_64 = x_11604;
			t_sample x_10814 = in2;
			t_sample q_10807 = gen_11175;
			t_sample bw_10815 = safediv(((int)1808), q_10807);
			t_sample r_10808 = exp(((-bw_10815) * twopi_over_sr_10818));
			t_sample c_10817 = ((((int)2) * r_10808) * cos((((int)1808) * twopi_over_sr_10818)));
			t_sample c_10820 = ((-r_10808) * r_10808);
			t_sample y_10819 = ((((((int)1) - r_10808) * (x_10814 - (r_10808 * m_x_59))) + (c_10817 * m_y_58)) + (c_10820 * m_y_57));
			m_y_57 = m_y_58;
			m_y_58 = y_10819;
			m_x_59 = m_x_60;
			m_x_60 = x_10814;
			t_sample abs_10806 = fabs(y_10819);
			__m_slide_183 = fixdenorm((__m_slide_183 + (((abs_10806 > __m_slide_183) ? iup_184 : idown_185) * (abs_10806 - __m_slide_183))));
			t_sample slide_10805 = __m_slide_183;
			__m_latch_186 = ((rsub_10690 != 0) ? slide_10805 : __m_latch_186);
			t_sample latch_10800 = __m_latch_186;
			t_sample mul_10802 = (y_11603 * latch_10800);
			t_sample dcblock_10801 = __m_dcblock_187(mul_10802);
			t_sample x_11622 = add_10691;
			t_sample q_11619 = gen_11175;
			t_sample bw_11627 = safediv(((int)2260), q_11619);
			t_sample r_11620 = exp(((-bw_11627) * twopi_over_sr_11616));
			t_sample c_11623 = ((((int)2) * r_11620) * cos((((int)2260) * twopi_over_sr_11616)));
			t_sample c_11615 = ((-r_11620) * r_11620);
			t_sample y_11621 = ((((((int)1) - r_11620) * (x_11622 - (r_11620 * m_x_55))) + (c_11623 * m_y_54)) + (c_11615 * m_y_53));
			m_y_53 = m_y_54;
			m_y_54 = y_11621;
			m_x_55 = m_x_56;
			m_x_56 = x_11622;
			t_sample x_10788 = in2;
			t_sample q_10781 = gen_11175;
			t_sample bw_10789 = safediv(((int)2260), q_10781);
			t_sample r_10782 = exp(((-bw_10789) * twopi_over_sr_10792));
			t_sample c_10791 = ((((int)2) * r_10782) * cos((((int)2260) * twopi_over_sr_10792)));
			t_sample c_10794 = ((-r_10782) * r_10782);
			t_sample y_10793 = ((((((int)1) - r_10782) * (x_10788 - (r_10782 * m_x_51))) + (c_10791 * m_y_50)) + (c_10794 * m_y_49));
			m_y_49 = m_y_50;
			m_y_50 = y_10793;
			m_x_51 = m_x_52;
			m_x_52 = x_10788;
			t_sample abs_10780 = fabs(y_10793);
			__m_slide_188 = fixdenorm((__m_slide_188 + (((abs_10780 > __m_slide_188) ? iup_189 : idown_190) * (abs_10780 - __m_slide_188))));
			t_sample slide_10779 = __m_slide_188;
			__m_latch_191 = ((rsub_10690 != 0) ? slide_10779 : __m_latch_191);
			t_sample latch_10774 = __m_latch_191;
			t_sample mul_10776 = (y_11621 * latch_10774);
			t_sample dcblock_10775 = __m_dcblock_192(mul_10776);
			t_sample x_11639 = add_10691;
			t_sample q_11636 = gen_11175;
			t_sample bw_11644 = safediv(((int)2852), q_11636);
			t_sample r_11637 = exp(((-bw_11644) * twopi_over_sr_11634));
			t_sample c_11640 = ((((int)2) * r_11637) * cos((((int)2852) * twopi_over_sr_11634)));
			t_sample c_11633 = ((-r_11637) * r_11637);
			t_sample y_11638 = ((((((int)1) - r_11637) * (x_11639 - (r_11637 * m_x_47))) + (c_11640 * m_y_46)) + (c_11633 * m_y_45));
			m_y_45 = m_y_46;
			m_y_46 = y_11638;
			m_x_47 = m_x_48;
			m_x_48 = x_11639;
			t_sample x_10762 = in2;
			t_sample q_10755 = gen_11175;
			t_sample bw_10763 = safediv(((int)2852), q_10755);
			t_sample r_10756 = exp(((-bw_10763) * twopi_over_sr_10766));
			t_sample c_10765 = ((((int)2) * r_10756) * cos((((int)2852) * twopi_over_sr_10766)));
			t_sample c_10768 = ((-r_10756) * r_10756);
			t_sample y_10767 = ((((((int)1) - r_10756) * (x_10762 - (r_10756 * m_x_43))) + (c_10765 * m_y_42)) + (c_10768 * m_y_41));
			m_y_41 = m_y_42;
			m_y_42 = y_10767;
			m_x_43 = m_x_44;
			m_x_44 = x_10762;
			t_sample abs_10754 = fabs(y_10767);
			__m_slide_193 = fixdenorm((__m_slide_193 + (((abs_10754 > __m_slide_193) ? iup_194 : idown_195) * (abs_10754 - __m_slide_193))));
			t_sample slide_10753 = __m_slide_193;
			__m_latch_196 = ((rsub_10690 != 0) ? slide_10753 : __m_latch_196);
			t_sample latch_10748 = __m_latch_196;
			t_sample mul_10750 = (y_11638 * latch_10748);
			t_sample dcblock_10749 = __m_dcblock_197(mul_10750);
			t_sample x_11657 = add_10691;
			t_sample q_11654 = gen_11175;
			t_sample bw_11663 = safediv(((int)3616), q_11654);
			t_sample r_11655 = exp(((-bw_11663) * twopi_over_sr_11652));
			t_sample c_11658 = ((((int)2) * r_11655) * cos((((int)3616) * twopi_over_sr_11652)));
			t_sample c_11651 = ((-r_11655) * r_11655);
			t_sample y_11656 = ((((((int)1) - r_11655) * (x_11657 - (r_11655 * m_x_39))) + (c_11658 * m_y_38)) + (c_11651 * m_y_37));
			m_y_37 = m_y_38;
			m_y_38 = y_11656;
			m_x_39 = m_x_40;
			m_x_40 = x_11657;
			t_sample x_10736 = in2;
			t_sample q_10729 = gen_11175;
			t_sample bw_10737 = safediv(((int)3616), q_10729);
			t_sample r_10730 = exp(((-bw_10737) * twopi_over_sr_10740));
			t_sample c_10739 = ((((int)2) * r_10730) * cos((((int)3616) * twopi_over_sr_10740)));
			t_sample c_10742 = ((-r_10730) * r_10730);
			t_sample y_10741 = ((((((int)1) - r_10730) * (x_10736 - (r_10730 * m_x_35))) + (c_10739 * m_y_34)) + (c_10742 * m_y_33));
			m_y_33 = m_y_34;
			m_y_34 = y_10741;
			m_x_35 = m_x_36;
			m_x_36 = x_10736;
			t_sample abs_10728 = fabs(y_10741);
			__m_slide_198 = fixdenorm((__m_slide_198 + (((abs_10728 > __m_slide_198) ? iup_199 : idown_200) * (abs_10728 - __m_slide_198))));
			t_sample slide_10727 = __m_slide_198;
			__m_latch_201 = ((rsub_10690 != 0) ? slide_10727 : __m_latch_201);
			t_sample latch_10722 = __m_latch_201;
			t_sample mul_10724 = (y_11656 * latch_10722);
			t_sample dcblock_10723 = __m_dcblock_202(mul_10724);
			t_sample x_11673 = add_10691;
			t_sample q_11670 = gen_11175;
			t_sample bw_11679 = safediv(((int)4556), q_11670);
			t_sample r_11671 = exp(((-bw_11679) * twopi_over_sr_11669));
			t_sample c_11677 = ((((int)2) * r_11671) * cos((((int)4556) * twopi_over_sr_11669)));
			t_sample c_11674 = ((-r_11671) * r_11671);
			t_sample y_11672 = ((((((int)1) - r_11671) * (x_11673 - (r_11671 * m_x_31))) + (c_11677 * m_y_30)) + (c_11674 * m_y_29));
			m_y_29 = m_y_30;
			m_y_30 = y_11672;
			m_x_31 = m_x_32;
			m_x_32 = x_11673;
			t_sample x_10710 = in2;
			t_sample q_10703 = gen_11175;
			t_sample bw_10711 = safediv(((int)4556), q_10703);
			t_sample r_10704 = exp(((-bw_10711) * twopi_over_sr_10714));
			t_sample c_10713 = ((((int)2) * r_10704) * cos((((int)4556) * twopi_over_sr_10714)));
			t_sample c_10716 = ((-r_10704) * r_10704);
			t_sample y_10715 = ((((((int)1) - r_10704) * (x_10710 - (r_10704 * m_x_27))) + (c_10713 * m_y_26)) + (c_10716 * m_y_25));
			m_y_25 = m_y_26;
			m_y_26 = y_10715;
			m_x_27 = m_x_28;
			m_x_28 = x_10710;
			t_sample abs_10702 = fabs(y_10715);
			__m_slide_203 = fixdenorm((__m_slide_203 + (((abs_10702 > __m_slide_203) ? iup_204 : idown_205) * (abs_10702 - __m_slide_203))));
			t_sample slide_10701 = __m_slide_203;
			__m_latch_206 = ((rsub_10690 != 0) ? slide_10701 : __m_latch_206);
			t_sample latch_10694 = __m_latch_206;
			t_sample mul_10696 = (y_11672 * latch_10694);
			t_sample dcblock_10695 = __m_dcblock_207(mul_10696);
			t_sample x_11691 = add_10691;
			t_sample q_11688 = gen_11175;
			t_sample bw_11699 = safediv(((t_sample)104.5), q_11688);
			t_sample r_11689 = exp(((-bw_11699) * twopi_over_sr_11687));
			t_sample c_11695 = ((((int)2) * r_11689) * cos((((t_sample)104.5) * twopi_over_sr_11687)));
			t_sample c_11692 = ((-r_11689) * r_11689);
			t_sample y_11690 = ((((((int)1) - r_11689) * (x_11691 - (r_11689 * m_x_23))) + (c_11695 * m_y_22)) + (c_11692 * m_y_21));
			m_y_21 = m_y_22;
			m_y_22 = y_11690;
			m_x_23 = m_x_24;
			m_x_24 = x_11691;
			t_sample x_11144 = in2;
			t_sample q_11137 = gen_11175;
			t_sample bw_11145 = safediv(((t_sample)104.5), q_11137);
			t_sample r_11138 = exp(((-bw_11145) * twopi_over_sr_11148));
			t_sample c_11147 = ((((int)2) * r_11138) * cos((((t_sample)104.5) * twopi_over_sr_11148)));
			t_sample c_11150 = ((-r_11138) * r_11138);
			t_sample y_11149 = ((((((int)1) - r_11138) * (x_11144 - (r_11138 * m_x_19))) + (c_11147 * m_y_18)) + (c_11150 * m_y_17));
			m_y_17 = m_y_18;
			m_y_18 = y_11149;
			m_x_19 = m_x_20;
			m_x_20 = x_11144;
			t_sample abs_11136 = fabs(y_11149);
			__m_slide_208 = fixdenorm((__m_slide_208 + (((abs_11136 > __m_slide_208) ? iup_209 : idown_210) * (abs_11136 - __m_slide_208))));
			t_sample slide_11135 = __m_slide_208;
			__m_latch_211 = ((rsub_10690 != 0) ? slide_11135 : __m_latch_211);
			t_sample latch_11130 = __m_latch_211;
			t_sample mul_11132 = (y_11690 * latch_11130);
			t_sample dcblock_11131 = __m_dcblock_212(mul_11132);
			t_sample x_11708 = add_10691;
			t_sample q_11706 = gen_11175;
			t_sample bw_11718 = safediv(((t_sample)179.5), q_11706);
			t_sample r_11717 = exp(((-bw_11718) * twopi_over_sr_11705));
			t_sample c_11713 = ((((int)2) * r_11717) * cos((((t_sample)179.5) * twopi_over_sr_11705)));
			t_sample c_11710 = ((-r_11717) * r_11717);
			t_sample y_11707 = ((((((int)1) - r_11717) * (x_11708 - (r_11717 * m_x_15))) + (c_11713 * m_y_14)) + (c_11710 * m_y_13));
			m_y_13 = m_y_14;
			m_y_14 = y_11707;
			m_x_15 = m_x_16;
			m_x_16 = x_11708;
			t_sample x_11074 = in2;
			t_sample q_11067 = gen_11175;
			t_sample bw_11075 = safediv(((t_sample)179.5), q_11067);
			t_sample r_11068 = exp(((-bw_11075) * twopi_over_sr_11078));
			t_sample c_11077 = ((((int)2) * r_11068) * cos((((t_sample)179.5) * twopi_over_sr_11078)));
			t_sample c_11080 = ((-r_11068) * r_11068);
			t_sample y_11079 = ((((((int)1) - r_11068) * (x_11074 - (r_11068 * m_x_11))) + (c_11077 * m_y_10)) + (c_11080 * m_y_9));
			m_y_9 = m_y_10;
			m_y_10 = y_11079;
			m_x_11 = m_x_12;
			m_x_12 = x_11074;
			t_sample abs_11066 = fabs(y_11079);
			__m_slide_213 = fixdenorm((__m_slide_213 + (((abs_11066 > __m_slide_213) ? iup_214 : idown_215) * (abs_11066 - __m_slide_213))));
			t_sample slide_11065 = __m_slide_213;
			__m_latch_216 = ((rsub_10690 != 0) ? slide_11065 : __m_latch_216);
			t_sample latch_11060 = __m_latch_216;
			t_sample mul_11062 = (y_11707 * latch_11060);
			t_sample dcblock_11061 = __m_dcblock_217(mul_11062);
			t_sample x_11727 = add_10691;
			t_sample q_11724 = gen_11175;
			t_sample bw_11734 = safediv(((int)226), q_11724);
			t_sample r_11725 = exp(((-bw_11734) * twopi_over_sr_11723));
			t_sample c_11731 = ((((int)2) * r_11725) * cos((((int)226) * twopi_over_sr_11723)));
			t_sample c_11728 = ((-r_11725) * r_11725);
			t_sample y_11726 = ((((((int)1) - r_11725) * (x_11727 - (r_11725 * m_x_7))) + (c_11731 * m_y_6)) + (c_11728 * m_y_5));
			m_y_5 = m_y_6;
			m_y_6 = y_11726;
			m_x_7 = m_x_8;
			m_x_8 = x_11727;
			t_sample x_11048 = in2;
			t_sample q_11041 = gen_11175;
			t_sample bw_11049 = safediv(((int)226), q_11041);
			t_sample r_11042 = exp(((-bw_11049) * twopi_over_sr_11052));
			t_sample c_11051 = ((((int)2) * r_11042) * cos((((int)226) * twopi_over_sr_11052)));
			t_sample c_11054 = ((-r_11042) * r_11042);
			t_sample y_11053 = ((((((int)1) - r_11042) * (x_11048 - (r_11042 * m_x_3))) + (c_11051 * m_y_2)) + (c_11054 * m_y_1));
			m_y_1 = m_y_2;
			m_y_2 = y_11053;
			m_x_3 = m_x_4;
			m_x_4 = x_11048;
			t_sample abs_11040 = fabs(y_11053);
			__m_slide_218 = fixdenorm((__m_slide_218 + (((abs_11040 > __m_slide_218) ? iup_219 : idown_220) * (abs_11040 - __m_slide_218))));
			t_sample slide_11039 = __m_slide_218;
			__m_latch_221 = ((rsub_10690 != 0) ? slide_11039 : __m_latch_221);
			t_sample latch_11034 = __m_latch_221;
			t_sample mul_11036 = (y_11726 * latch_11034);
			t_sample dcblock_11035 = __m_dcblock_222(mul_11036);
			t_sample pass_11176 = (((((((((((((((dcblock_11035 + dcblock_11061) + dcblock_11131) + dcblock_10695) + dcblock_10723) + dcblock_10749) + dcblock_10775) + dcblock_10801) + dcblock_10827) + dcblock_10853) + dcblock_10879) + dcblock_10905) + dcblock_10931) + dcblock_10957) + dcblock_10983) + dcblock_11009);
			t_sample add_11187 = (pass_11176 + gate_11179);
			t_sample out2 = add_11187;
			t_sample add_11188 = (pass_11176 + gate_11179);
			t_sample out1 = add_11188;
			m_history_132 = history_11182_next_11184;
			m_history_131 = history_11169_next_11172;
			m_history_129 = history_11164_next_11174;
			m_history_130 = history_11166_next_11173;
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
		m_knob4_gain_133 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
	};
	inline void set_knob3_res(t_param _value) {
		m_knob3_res_134 = (_value < 15 ? 15 : (_value > 50 ? 50 : _value));
	};
	inline void set_knob5_noise(t_param _value) {
		m_knob5_noise_135 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_res_134; break;
		case 1: *value = self->m_knob4_gain_133; break;
		case 2: *value = self->m_knob5_noise_135; break;
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
	// initialize parameter 0 ("m_knob3_res_134")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_res_134;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 15;
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_gain_133")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_gain";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_gain_133;
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
