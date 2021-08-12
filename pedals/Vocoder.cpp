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
	t_sample m_sw_134;
	t_sample __m_slide_140;
	t_sample __m_slide_143;
	t_sample __m_latch_146;
	t_sample m_x_123;
	t_sample m_y_14;
	t_sample m_knob5_noise_136;
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
		m_knob4_gain_133 = 5;
		m_sw_134 = ((int)0);
		m_knob3_res_135 = 15;
		m_knob5_noise_136 = 0;
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
		t_sample rsub_1957 = (((int)1) - m_sw_137);
		t_sample mstosamps_2353 = (((int)2) * (samplerate * 0.001));
		t_sample mstosamps_2442 = (((int)20) * (samplerate * 0.001));
		t_sample iup_141 = (1 / maximum(1, abs(((int)10))));
		t_sample idown_142 = (1 / maximum(1, abs(((int)400))));
		t_sample twopi_over_sr = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2293 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_144 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_145 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2464 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2267 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_149 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_150 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2482 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2241 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_154 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_155 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2499 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2215 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_159 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_160 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2519 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2189 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_164 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_165 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2527 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2163 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_169 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_170 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2557 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2137 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_174 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_175 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2563 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2111 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_179 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_180 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2593 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2085 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_184 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_185 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2608 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2059 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_189 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_190 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2628 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2033 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_194 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_195 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2647 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2007 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_199 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_200 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2665 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_1981 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_204 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_205 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2670 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2415 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_209 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_210 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2688 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2345 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_214 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_215 = (1 / maximum(1, abs(mstosamps_2442)));
		t_sample twopi_over_sr_2718 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2319 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_219 = (1 / maximum(1, abs(mstosamps_2353)));
		t_sample idown_220 = (1 / maximum(1, abs(mstosamps_2442)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_2448 = __m_sah_138(m_history_132, m_sw_134, ((int)0));
			t_sample gen_2450 = sah_2448;
			t_sample rsub_2446 = (((int)1) - sah_2448);
			t_sample history_2447_next_2449 = fixdenorm(rsub_2446);
			t_sample out3 = gen_2450;
			t_sample add_2451 = (gen_2450 + ((int)1));
			t_sample choice_139 = int(add_2451);
			t_sample gate_2444 = (((choice_139 >= 1) && (choice_139 < 2)) ? in1 : 0);
			t_sample gate_2445 = ((choice_139 >= 2) ? in1 : 0);
			t_sample mix_2730 = (m_history_131 + (((t_sample)0.0019634941468452) * (m_knob3_res_135 - m_history_131)));
			t_sample mix_2434 = mix_2730;
			t_sample mix_2731 = (m_history_130 + (((t_sample)0.0019634941468452) * (mix_2434 - m_history_130)));
			t_sample mix_2432 = mix_2731;
			t_sample mix_2732 = (m_history_129 + (((t_sample)0.0019634941468452) * (mix_2432 - m_history_129)));
			t_sample mix_2430 = mix_2732;
			t_sample gen_2440 = mix_2430;
			t_sample history_2435_next_2437 = fixdenorm(mix_2434);
			t_sample history_2433_next_2438 = fixdenorm(mix_2432);
			t_sample history_2431_next_2439 = fixdenorm(mix_2430);
			t_sample mul_1955 = (gate_2445 * m_knob4_gain_133);
			t_sample abs_1953 = fabs(gate_2445);
			__m_slide_140 = fixdenorm((__m_slide_140 + (((abs_1953 > __m_slide_140) ? iup_141 : idown_142) * (abs_1953 - __m_slide_140))));
			t_sample slide_1952 = __m_slide_140;
			t_sample noise_1960 = noise();
			t_sample mul_1959 = (noise_1960 * m_knob5_noise_136);
			t_sample mul_1954 = (slide_1952 * mul_1959);
			t_sample add_1958 = (mul_1955 + mul_1954);
			t_sample x = add_1958;
			t_sample q = gen_2440;
			t_sample bw = safediv(((t_sample)284.5), q);
			t_sample r = exp(((-bw) * twopi_over_sr));
			t_sample c1 = ((((int)2) * r) * cos((((t_sample)284.5) * twopi_over_sr)));
			t_sample c2 = ((-r) * r);
			t_sample y = ((((((int)1) - r) * (x - (r * m_x_127))) + (c1 * m_y_126)) + (c2 * m_y_125));
			m_y_125 = m_y_126;
			m_y_126 = y;
			m_x_127 = m_x_128;
			m_x_128 = x;
			t_sample x_2289 = in2;
			t_sample q_2282 = gen_2440;
			t_sample bw_2290 = safediv(((t_sample)284.5), q_2282);
			t_sample r_2283 = exp(((-bw_2290) * twopi_over_sr_2293));
			t_sample c_2292 = ((((int)2) * r_2283) * cos((((t_sample)284.5) * twopi_over_sr_2293)));
			t_sample c_2295 = ((-r_2283) * r_2283);
			t_sample y_2294 = ((((((int)1) - r_2283) * (x_2289 - (r_2283 * m_x_123))) + (c_2292 * m_y_122)) + (c_2295 * m_y_121));
			m_y_121 = m_y_122;
			m_y_122 = y_2294;
			m_x_123 = m_x_124;
			m_x_124 = x_2289;
			t_sample abs_2281 = fabs(y_2294);
			__m_slide_143 = fixdenorm((__m_slide_143 + (((abs_2281 > __m_slide_143) ? iup_144 : idown_145) * (abs_2281 - __m_slide_143))));
			t_sample slide_2280 = __m_slide_143;
			__m_latch_146 = ((rsub_1957 != 0) ? slide_2280 : __m_latch_146);
			t_sample latch_2275 = __m_latch_146;
			t_sample mul_2277 = (y * latch_2275);
			t_sample dcblock_2276 = __m_dcblock_147(mul_2277);
			t_sample x_2465 = add_1958;
			t_sample q_2457 = gen_2440;
			t_sample bw_2463 = safediv(((t_sample)358.5), q_2457);
			t_sample r_2462 = exp(((-bw_2463) * twopi_over_sr_2464));
			t_sample c_2459 = ((((int)2) * r_2462) * cos((((t_sample)358.5) * twopi_over_sr_2464)));
			t_sample c_2456 = ((-r_2462) * r_2462);
			t_sample y_2461 = ((((((int)1) - r_2462) * (x_2465 - (r_2462 * m_x_119))) + (c_2459 * m_y_118)) + (c_2456 * m_y_117));
			m_y_117 = m_y_118;
			m_y_118 = y_2461;
			m_x_119 = m_x_120;
			m_x_120 = x_2465;
			t_sample x_2263 = in2;
			t_sample q_2256 = gen_2440;
			t_sample bw_2264 = safediv(((t_sample)358.5), q_2256);
			t_sample r_2257 = exp(((-bw_2264) * twopi_over_sr_2267));
			t_sample c_2266 = ((((int)2) * r_2257) * cos((((t_sample)358.5) * twopi_over_sr_2267)));
			t_sample c_2269 = ((-r_2257) * r_2257);
			t_sample y_2268 = ((((((int)1) - r_2257) * (x_2263 - (r_2257 * m_x_115))) + (c_2266 * m_y_114)) + (c_2269 * m_y_113));
			m_y_113 = m_y_114;
			m_y_114 = y_2268;
			m_x_115 = m_x_116;
			m_x_116 = x_2263;
			t_sample abs_2255 = fabs(y_2268);
			__m_slide_148 = fixdenorm((__m_slide_148 + (((abs_2255 > __m_slide_148) ? iup_149 : idown_150) * (abs_2255 - __m_slide_148))));
			t_sample slide_2254 = __m_slide_148;
			__m_latch_151 = ((rsub_1957 != 0) ? slide_2254 : __m_latch_151);
			t_sample latch_2249 = __m_latch_151;
			t_sample mul_2251 = (y_2461 * latch_2249);
			t_sample dcblock_2250 = __m_dcblock_152(mul_2251);
			t_sample x_2477 = add_1958;
			t_sample q_2474 = gen_2440;
			t_sample bw_2478 = safediv(((int)452), q_2474);
			t_sample r_2475 = exp(((-bw_2478) * twopi_over_sr_2482));
			t_sample c_2480 = ((((int)2) * r_2475) * cos((((int)452) * twopi_over_sr_2482)));
			t_sample c_2472 = ((-r_2475) * r_2475);
			t_sample y_2476 = ((((((int)1) - r_2475) * (x_2477 - (r_2475 * m_x_111))) + (c_2480 * m_y_110)) + (c_2472 * m_y_109));
			m_y_109 = m_y_110;
			m_y_110 = y_2476;
			m_x_111 = m_x_112;
			m_x_112 = x_2477;
			t_sample x_2237 = in2;
			t_sample q_2230 = gen_2440;
			t_sample bw_2238 = safediv(((int)452), q_2230);
			t_sample r_2231 = exp(((-bw_2238) * twopi_over_sr_2241));
			t_sample c_2240 = ((((int)2) * r_2231) * cos((((int)452) * twopi_over_sr_2241)));
			t_sample c_2243 = ((-r_2231) * r_2231);
			t_sample y_2242 = ((((((int)1) - r_2231) * (x_2237 - (r_2231 * m_x_107))) + (c_2240 * m_y_106)) + (c_2243 * m_y_105));
			m_y_105 = m_y_106;
			m_y_106 = y_2242;
			m_x_107 = m_x_108;
			m_x_108 = x_2237;
			t_sample abs_2229 = fabs(y_2242);
			__m_slide_153 = fixdenorm((__m_slide_153 + (((abs_2229 > __m_slide_153) ? iup_154 : idown_155) * (abs_2229 - __m_slide_153))));
			t_sample slide_2228 = __m_slide_153;
			__m_latch_156 = ((rsub_1957 != 0) ? slide_2228 : __m_latch_156);
			t_sample latch_2223 = __m_latch_156;
			t_sample mul_2225 = (y_2476 * latch_2223);
			t_sample dcblock_2224 = __m_dcblock_157(mul_2225);
			t_sample x_2495 = add_1958;
			t_sample q_2493 = gen_2440;
			t_sample bw_2496 = safediv(((t_sample)569.5), q_2493);
			t_sample r_2494 = exp(((-bw_2496) * twopi_over_sr_2499));
			t_sample c_2498 = ((((int)2) * r_2494) * cos((((t_sample)569.5) * twopi_over_sr_2499)));
			t_sample c_2490 = ((-r_2494) * r_2494);
			t_sample y_2501 = ((((((int)1) - r_2494) * (x_2495 - (r_2494 * m_x_103))) + (c_2498 * m_y_102)) + (c_2490 * m_y_101));
			m_y_101 = m_y_102;
			m_y_102 = y_2501;
			m_x_103 = m_x_104;
			m_x_104 = x_2495;
			t_sample x_2212 = in2;
			t_sample q_2204 = gen_2440;
			t_sample bw_2213 = safediv(((t_sample)569.5), q_2204);
			t_sample r_2206 = exp(((-bw_2213) * twopi_over_sr_2215));
			t_sample c_2214 = ((((int)2) * r_2206) * cos((((t_sample)569.5) * twopi_over_sr_2215)));
			t_sample c_2217 = ((-r_2206) * r_2206);
			t_sample y_2216 = ((((((int)1) - r_2206) * (x_2212 - (r_2206 * m_x_99))) + (c_2214 * m_y_98)) + (c_2217 * m_y_97));
			m_y_97 = m_y_98;
			m_y_98 = y_2216;
			m_x_99 = m_x_100;
			m_x_100 = x_2212;
			t_sample abs_2203 = fabs(y_2216);
			__m_slide_158 = fixdenorm((__m_slide_158 + (((abs_2203 > __m_slide_158) ? iup_159 : idown_160) * (abs_2203 - __m_slide_158))));
			t_sample slide_2202 = __m_slide_158;
			__m_latch_161 = ((rsub_1957 != 0) ? slide_2202 : __m_latch_161);
			t_sample latch_2197 = __m_latch_161;
			t_sample mul_2199 = (y_2501 * latch_2197);
			t_sample dcblock_2198 = __m_dcblock_162(mul_2199);
			t_sample x_2512 = add_1958;
			t_sample q_2510 = gen_2440;
			t_sample bw_2518 = safediv(((t_sample)717.5), q_2510);
			t_sample r_2511 = exp(((-bw_2518) * twopi_over_sr_2519));
			t_sample c_2514 = ((((int)2) * r_2511) * cos((((t_sample)717.5) * twopi_over_sr_2519)));
			t_sample c_2508 = ((-r_2511) * r_2511);
			t_sample y_2516 = ((((((int)1) - r_2511) * (x_2512 - (r_2511 * m_x_95))) + (c_2514 * m_y_94)) + (c_2508 * m_y_93));
			m_y_93 = m_y_94;
			m_y_94 = y_2516;
			m_x_95 = m_x_96;
			m_x_96 = x_2512;
			t_sample x_2185 = in2;
			t_sample q_2178 = gen_2440;
			t_sample bw_2186 = safediv(((t_sample)717.5), q_2178);
			t_sample r_2179 = exp(((-bw_2186) * twopi_over_sr_2189));
			t_sample c_2188 = ((((int)2) * r_2179) * cos((((t_sample)717.5) * twopi_over_sr_2189)));
			t_sample c_2191 = ((-r_2179) * r_2179);
			t_sample y_2190 = ((((((int)1) - r_2179) * (x_2185 - (r_2179 * m_x_91))) + (c_2188 * m_y_90)) + (c_2191 * m_y_89));
			m_y_89 = m_y_90;
			m_y_90 = y_2190;
			m_x_91 = m_x_92;
			m_x_92 = x_2185;
			t_sample abs_2177 = fabs(y_2190);
			__m_slide_163 = fixdenorm((__m_slide_163 + (((abs_2177 > __m_slide_163) ? iup_164 : idown_165) * (abs_2177 - __m_slide_163))));
			t_sample slide_2176 = __m_slide_163;
			__m_latch_166 = ((rsub_1957 != 0) ? slide_2176 : __m_latch_166);
			t_sample latch_2171 = __m_latch_166;
			t_sample mul_2173 = (y_2516 * latch_2171);
			t_sample dcblock_2172 = __m_dcblock_167(mul_2173);
			t_sample x_2532 = add_1958;
			t_sample q_2530 = gen_2440;
			t_sample bw_2538 = safediv(((int)904), q_2530);
			t_sample r_2531 = exp(((-bw_2538) * twopi_over_sr_2527));
			t_sample c_2533 = ((((int)2) * r_2531) * cos((((int)904) * twopi_over_sr_2527)));
			t_sample c_2526 = ((-r_2531) * r_2531);
			t_sample y_2539 = ((((((int)1) - r_2531) * (x_2532 - (r_2531 * m_x_87))) + (c_2533 * m_y_86)) + (c_2526 * m_y_85));
			m_y_85 = m_y_86;
			m_y_86 = y_2539;
			m_x_87 = m_x_88;
			m_x_88 = x_2532;
			t_sample x_2159 = in2;
			t_sample q_2152 = gen_2440;
			t_sample bw_2160 = safediv(((int)904), q_2152);
			t_sample r_2153 = exp(((-bw_2160) * twopi_over_sr_2163));
			t_sample c_2162 = ((((int)2) * r_2153) * cos((((int)904) * twopi_over_sr_2163)));
			t_sample c_2165 = ((-r_2153) * r_2153);
			t_sample y_2164 = ((((((int)1) - r_2153) * (x_2159 - (r_2153 * m_x_83))) + (c_2162 * m_y_82)) + (c_2165 * m_y_81));
			m_y_81 = m_y_82;
			m_y_82 = y_2164;
			m_x_83 = m_x_84;
			m_x_84 = x_2159;
			t_sample abs_2151 = fabs(y_2164);
			__m_slide_168 = fixdenorm((__m_slide_168 + (((abs_2151 > __m_slide_168) ? iup_169 : idown_170) * (abs_2151 - __m_slide_168))));
			t_sample slide_2150 = __m_slide_168;
			__m_latch_171 = ((rsub_1957 != 0) ? slide_2150 : __m_latch_171);
			t_sample latch_2145 = __m_latch_171;
			t_sample mul_2147 = (y_2539 * latch_2145);
			t_sample dcblock_2146 = __m_dcblock_172(mul_2147);
			t_sample x_2550 = add_1958;
			t_sample q_2547 = gen_2440;
			t_sample bw_2555 = safediv(((int)1139), q_2547);
			t_sample r_2548 = exp(((-bw_2555) * twopi_over_sr_2557));
			t_sample c_2551 = ((((int)2) * r_2548) * cos((((int)1139) * twopi_over_sr_2557)));
			t_sample c_2544 = ((-r_2548) * r_2548);
			t_sample y_2549 = ((((((int)1) - r_2548) * (x_2550 - (r_2548 * m_x_79))) + (c_2551 * m_y_78)) + (c_2544 * m_y_77));
			m_y_77 = m_y_78;
			m_y_78 = y_2549;
			m_x_79 = m_x_80;
			m_x_80 = x_2550;
			t_sample x_2133 = in2;
			t_sample q_2126 = gen_2440;
			t_sample bw_2134 = safediv(((int)1139), q_2126);
			t_sample r_2127 = exp(((-bw_2134) * twopi_over_sr_2137));
			t_sample c_2136 = ((((int)2) * r_2127) * cos((((int)1139) * twopi_over_sr_2137)));
			t_sample c_2139 = ((-r_2127) * r_2127);
			t_sample y_2138 = ((((((int)1) - r_2127) * (x_2133 - (r_2127 * m_x_75))) + (c_2136 * m_y_74)) + (c_2139 * m_y_73));
			m_y_73 = m_y_74;
			m_y_74 = y_2138;
			m_x_75 = m_x_76;
			m_x_76 = x_2133;
			t_sample abs_2125 = fabs(y_2138);
			__m_slide_173 = fixdenorm((__m_slide_173 + (((abs_2125 > __m_slide_173) ? iup_174 : idown_175) * (abs_2125 - __m_slide_173))));
			t_sample slide_2124 = __m_slide_173;
			__m_latch_176 = ((rsub_1957 != 0) ? slide_2124 : __m_latch_176);
			t_sample latch_2119 = __m_latch_176;
			t_sample mul_2121 = (y_2549 * latch_2119);
			t_sample dcblock_2120 = __m_dcblock_177(mul_2121);
			t_sample x_2568 = add_1958;
			t_sample q_2565 = gen_2440;
			t_sample bw_2573 = safediv(((int)1435), q_2565);
			t_sample r_2566 = exp(((-bw_2573) * twopi_over_sr_2563));
			t_sample c_2569 = ((((int)2) * r_2566) * cos((((int)1435) * twopi_over_sr_2563)));
			t_sample c_2562 = ((-r_2566) * r_2566);
			t_sample y_2567 = ((((((int)1) - r_2566) * (x_2568 - (r_2566 * m_x_71))) + (c_2569 * m_y_70)) + (c_2562 * m_y_69));
			m_y_69 = m_y_70;
			m_y_70 = y_2567;
			m_x_71 = m_x_72;
			m_x_72 = x_2568;
			t_sample x_2107 = in2;
			t_sample q_2100 = gen_2440;
			t_sample bw_2108 = safediv(((int)1435), q_2100);
			t_sample r_2101 = exp(((-bw_2108) * twopi_over_sr_2111));
			t_sample c_2110 = ((((int)2) * r_2101) * cos((((int)1435) * twopi_over_sr_2111)));
			t_sample c_2113 = ((-r_2101) * r_2101);
			t_sample y_2112 = ((((((int)1) - r_2101) * (x_2107 - (r_2101 * m_x_67))) + (c_2110 * m_y_66)) + (c_2113 * m_y_65));
			m_y_65 = m_y_66;
			m_y_66 = y_2112;
			m_x_67 = m_x_68;
			m_x_68 = x_2107;
			t_sample abs_2099 = fabs(y_2112);
			__m_slide_178 = fixdenorm((__m_slide_178 + (((abs_2099 > __m_slide_178) ? iup_179 : idown_180) * (abs_2099 - __m_slide_178))));
			t_sample slide_2098 = __m_slide_178;
			__m_latch_181 = ((rsub_1957 != 0) ? slide_2098 : __m_latch_181);
			t_sample latch_2093 = __m_latch_181;
			t_sample mul_2095 = (y_2567 * latch_2093);
			t_sample dcblock_2094 = __m_dcblock_182(mul_2095);
			t_sample x_2585 = add_1958;
			t_sample q_2582 = gen_2440;
			t_sample bw_2590 = safediv(((int)1808), q_2582);
			t_sample r_2583 = exp(((-bw_2590) * twopi_over_sr_2593));
			t_sample c_2586 = ((((int)2) * r_2583) * cos((((int)1808) * twopi_over_sr_2593)));
			t_sample c_2580 = ((-r_2583) * r_2583);
			t_sample y_2584 = ((((((int)1) - r_2583) * (x_2585 - (r_2583 * m_x_63))) + (c_2586 * m_y_62)) + (c_2580 * m_y_61));
			m_y_61 = m_y_62;
			m_y_62 = y_2584;
			m_x_63 = m_x_64;
			m_x_64 = x_2585;
			t_sample x_2081 = in2;
			t_sample q_2074 = gen_2440;
			t_sample bw_2082 = safediv(((int)1808), q_2074);
			t_sample r_2075 = exp(((-bw_2082) * twopi_over_sr_2085));
			t_sample c_2084 = ((((int)2) * r_2075) * cos((((int)1808) * twopi_over_sr_2085)));
			t_sample c_2087 = ((-r_2075) * r_2075);
			t_sample y_2086 = ((((((int)1) - r_2075) * (x_2081 - (r_2075 * m_x_59))) + (c_2084 * m_y_58)) + (c_2087 * m_y_57));
			m_y_57 = m_y_58;
			m_y_58 = y_2086;
			m_x_59 = m_x_60;
			m_x_60 = x_2081;
			t_sample abs_2073 = fabs(y_2086);
			__m_slide_183 = fixdenorm((__m_slide_183 + (((abs_2073 > __m_slide_183) ? iup_184 : idown_185) * (abs_2073 - __m_slide_183))));
			t_sample slide_2072 = __m_slide_183;
			__m_latch_186 = ((rsub_1957 != 0) ? slide_2072 : __m_latch_186);
			t_sample latch_2067 = __m_latch_186;
			t_sample mul_2069 = (y_2584 * latch_2067);
			t_sample dcblock_2068 = __m_dcblock_187(mul_2069);
			t_sample x_2603 = add_1958;
			t_sample q_2600 = gen_2440;
			t_sample bw_2611 = safediv(((int)2260), q_2600);
			t_sample r_2601 = exp(((-bw_2611) * twopi_over_sr_2608));
			t_sample c_2604 = ((((int)2) * r_2601) * cos((((int)2260) * twopi_over_sr_2608)));
			t_sample c_2598 = ((-r_2601) * r_2601);
			t_sample y_2602 = ((((((int)1) - r_2601) * (x_2603 - (r_2601 * m_x_55))) + (c_2604 * m_y_54)) + (c_2598 * m_y_53));
			m_y_53 = m_y_54;
			m_y_54 = y_2602;
			m_x_55 = m_x_56;
			m_x_56 = x_2603;
			t_sample x_2055 = in2;
			t_sample q_2048 = gen_2440;
			t_sample bw_2056 = safediv(((int)2260), q_2048);
			t_sample r_2049 = exp(((-bw_2056) * twopi_over_sr_2059));
			t_sample c_2058 = ((((int)2) * r_2049) * cos((((int)2260) * twopi_over_sr_2059)));
			t_sample c_2061 = ((-r_2049) * r_2049);
			t_sample y_2060 = ((((((int)1) - r_2049) * (x_2055 - (r_2049 * m_x_51))) + (c_2058 * m_y_50)) + (c_2061 * m_y_49));
			m_y_49 = m_y_50;
			m_y_50 = y_2060;
			m_x_51 = m_x_52;
			m_x_52 = x_2055;
			t_sample abs_2047 = fabs(y_2060);
			__m_slide_188 = fixdenorm((__m_slide_188 + (((abs_2047 > __m_slide_188) ? iup_189 : idown_190) * (abs_2047 - __m_slide_188))));
			t_sample slide_2046 = __m_slide_188;
			__m_latch_191 = ((rsub_1957 != 0) ? slide_2046 : __m_latch_191);
			t_sample latch_2041 = __m_latch_191;
			t_sample mul_2043 = (y_2602 * latch_2041);
			t_sample dcblock_2042 = __m_dcblock_192(mul_2043);
			t_sample x_2620 = add_1958;
			t_sample q_2618 = gen_2440;
			t_sample bw_2626 = safediv(((int)2852), q_2618);
			t_sample r_2619 = exp(((-bw_2626) * twopi_over_sr_2628));
			t_sample c_2621 = ((((int)2) * r_2619) * cos((((int)2852) * twopi_over_sr_2628)));
			t_sample c_2616 = ((-r_2619) * r_2619);
			t_sample y_2625 = ((((((int)1) - r_2619) * (x_2620 - (r_2619 * m_x_47))) + (c_2621 * m_y_46)) + (c_2616 * m_y_45));
			m_y_45 = m_y_46;
			m_y_46 = y_2625;
			m_x_47 = m_x_48;
			m_x_48 = x_2620;
			t_sample x_2029 = in2;
			t_sample q_2022 = gen_2440;
			t_sample bw_2030 = safediv(((int)2852), q_2022);
			t_sample r_2023 = exp(((-bw_2030) * twopi_over_sr_2033));
			t_sample c_2032 = ((((int)2) * r_2023) * cos((((int)2852) * twopi_over_sr_2033)));
			t_sample c_2035 = ((-r_2023) * r_2023);
			t_sample y_2034 = ((((((int)1) - r_2023) * (x_2029 - (r_2023 * m_x_43))) + (c_2032 * m_y_42)) + (c_2035 * m_y_41));
			m_y_41 = m_y_42;
			m_y_42 = y_2034;
			m_x_43 = m_x_44;
			m_x_44 = x_2029;
			t_sample abs_2021 = fabs(y_2034);
			__m_slide_193 = fixdenorm((__m_slide_193 + (((abs_2021 > __m_slide_193) ? iup_194 : idown_195) * (abs_2021 - __m_slide_193))));
			t_sample slide_2020 = __m_slide_193;
			__m_latch_196 = ((rsub_1957 != 0) ? slide_2020 : __m_latch_196);
			t_sample latch_2015 = __m_latch_196;
			t_sample mul_2017 = (y_2625 * latch_2015);
			t_sample dcblock_2016 = __m_dcblock_197(mul_2017);
			t_sample x_2639 = add_1958;
			t_sample q_2637 = gen_2440;
			t_sample bw_2644 = safediv(((int)3616), q_2637);
			t_sample r_2638 = exp(((-bw_2644) * twopi_over_sr_2647));
			t_sample c_2640 = ((((int)2) * r_2638) * cos((((int)3616) * twopi_over_sr_2647)));
			t_sample c_2634 = ((-r_2638) * r_2638);
			t_sample y_2635 = ((((((int)1) - r_2638) * (x_2639 - (r_2638 * m_x_39))) + (c_2640 * m_y_38)) + (c_2634 * m_y_37));
			m_y_37 = m_y_38;
			m_y_38 = y_2635;
			m_x_39 = m_x_40;
			m_x_40 = x_2639;
			t_sample x_2004 = in2;
			t_sample q_1996 = gen_2440;
			t_sample bw_2005 = safediv(((int)3616), q_1996);
			t_sample r_1998 = exp(((-bw_2005) * twopi_over_sr_2007));
			t_sample c_2006 = ((((int)2) * r_1998) * cos((((int)3616) * twopi_over_sr_2007)));
			t_sample c_2009 = ((-r_1998) * r_1998);
			t_sample y_2008 = ((((((int)1) - r_1998) * (x_2004 - (r_1998 * m_x_35))) + (c_2006 * m_y_34)) + (c_2009 * m_y_33));
			m_y_33 = m_y_34;
			m_y_34 = y_2008;
			m_x_35 = m_x_36;
			m_x_36 = x_2004;
			t_sample abs_1995 = fabs(y_2008);
			__m_slide_198 = fixdenorm((__m_slide_198 + (((abs_1995 > __m_slide_198) ? iup_199 : idown_200) * (abs_1995 - __m_slide_198))));
			t_sample slide_1994 = __m_slide_198;
			__m_latch_201 = ((rsub_1957 != 0) ? slide_1994 : __m_latch_201);
			t_sample latch_1989 = __m_latch_201;
			t_sample mul_1991 = (y_2635 * latch_1989);
			t_sample dcblock_1990 = __m_dcblock_202(mul_1991);
			t_sample x_2662 = add_1958;
			t_sample q_2652 = gen_2440;
			t_sample bw_2661 = safediv(((int)4556), q_2652);
			t_sample r_2653 = exp(((-bw_2661) * twopi_over_sr_2665));
			t_sample c_2658 = ((((int)2) * r_2653) * cos((((int)4556) * twopi_over_sr_2665)));
			t_sample c_2660 = ((-r_2653) * r_2653);
			t_sample y_2654 = ((((((int)1) - r_2653) * (x_2662 - (r_2653 * m_x_31))) + (c_2658 * m_y_30)) + (c_2660 * m_y_29));
			m_y_29 = m_y_30;
			m_y_30 = y_2654;
			m_x_31 = m_x_32;
			m_x_32 = x_2662;
			t_sample x_1977 = in2;
			t_sample q_1970 = gen_2440;
			t_sample bw_1978 = safediv(((int)4556), q_1970);
			t_sample r_1971 = exp(((-bw_1978) * twopi_over_sr_1981));
			t_sample c_1980 = ((((int)2) * r_1971) * cos((((int)4556) * twopi_over_sr_1981)));
			t_sample c_1983 = ((-r_1971) * r_1971);
			t_sample y_1982 = ((((((int)1) - r_1971) * (x_1977 - (r_1971 * m_x_27))) + (c_1980 * m_y_26)) + (c_1983 * m_y_25));
			m_y_25 = m_y_26;
			m_y_26 = y_1982;
			m_x_27 = m_x_28;
			m_x_28 = x_1977;
			t_sample abs_1969 = fabs(y_1982);
			__m_slide_203 = fixdenorm((__m_slide_203 + (((abs_1969 > __m_slide_203) ? iup_204 : idown_205) * (abs_1969 - __m_slide_203))));
			t_sample slide_1968 = __m_slide_203;
			__m_latch_206 = ((rsub_1957 != 0) ? slide_1968 : __m_latch_206);
			t_sample latch_1961 = __m_latch_206;
			t_sample mul_1963 = (y_2654 * latch_1961);
			t_sample dcblock_1962 = __m_dcblock_207(mul_1963);
			t_sample x_2682 = add_1958;
			t_sample q_2671 = gen_2440;
			t_sample bw_2681 = safediv(((t_sample)104.5), q_2671);
			t_sample r_2672 = exp(((-bw_2681) * twopi_over_sr_2670));
			t_sample c_2677 = ((((int)2) * r_2672) * cos((((t_sample)104.5) * twopi_over_sr_2670)));
			t_sample c_2680 = ((-r_2672) * r_2672);
			t_sample y_2673 = ((((((int)1) - r_2672) * (x_2682 - (r_2672 * m_x_23))) + (c_2677 * m_y_22)) + (c_2680 * m_y_21));
			m_y_21 = m_y_22;
			m_y_22 = y_2673;
			m_x_23 = m_x_24;
			m_x_24 = x_2682;
			t_sample x_2411 = in2;
			t_sample q_2404 = gen_2440;
			t_sample bw_2412 = safediv(((t_sample)104.5), q_2404);
			t_sample r_2405 = exp(((-bw_2412) * twopi_over_sr_2415));
			t_sample c_2414 = ((((int)2) * r_2405) * cos((((t_sample)104.5) * twopi_over_sr_2415)));
			t_sample c_2417 = ((-r_2405) * r_2405);
			t_sample y_2416 = ((((((int)1) - r_2405) * (x_2411 - (r_2405 * m_x_19))) + (c_2414 * m_y_18)) + (c_2417 * m_y_17));
			m_y_17 = m_y_18;
			m_y_18 = y_2416;
			m_x_19 = m_x_20;
			m_x_20 = x_2411;
			t_sample abs_2403 = fabs(y_2416);
			__m_slide_208 = fixdenorm((__m_slide_208 + (((abs_2403 > __m_slide_208) ? iup_209 : idown_210) * (abs_2403 - __m_slide_208))));
			t_sample slide_2402 = __m_slide_208;
			__m_latch_211 = ((rsub_1957 != 0) ? slide_2402 : __m_latch_211);
			t_sample latch_2397 = __m_latch_211;
			t_sample mul_2399 = (y_2673 * latch_2397);
			t_sample dcblock_2398 = __m_dcblock_212(mul_2399);
			t_sample x_2700 = add_1958;
			t_sample q_2689 = gen_2440;
			t_sample bw_2699 = safediv(((t_sample)179.5), q_2689);
			t_sample r_2690 = exp(((-bw_2699) * twopi_over_sr_2688));
			t_sample c_2694 = ((((int)2) * r_2690) * cos((((t_sample)179.5) * twopi_over_sr_2688)));
			t_sample c_2698 = ((-r_2690) * r_2690);
			t_sample y_2697 = ((((((int)1) - r_2690) * (x_2700 - (r_2690 * m_x_15))) + (c_2694 * m_y_14)) + (c_2698 * m_y_13));
			m_y_13 = m_y_14;
			m_y_14 = y_2697;
			m_x_15 = m_x_16;
			m_x_16 = x_2700;
			t_sample x_2341 = in2;
			t_sample q_2334 = gen_2440;
			t_sample bw_2342 = safediv(((t_sample)179.5), q_2334);
			t_sample r_2335 = exp(((-bw_2342) * twopi_over_sr_2345));
			t_sample c_2344 = ((((int)2) * r_2335) * cos((((t_sample)179.5) * twopi_over_sr_2345)));
			t_sample c_2347 = ((-r_2335) * r_2335);
			t_sample y_2346 = ((((((int)1) - r_2335) * (x_2341 - (r_2335 * m_x_11))) + (c_2344 * m_y_10)) + (c_2347 * m_y_9));
			m_y_9 = m_y_10;
			m_y_10 = y_2346;
			m_x_11 = m_x_12;
			m_x_12 = x_2341;
			t_sample abs_2333 = fabs(y_2346);
			__m_slide_213 = fixdenorm((__m_slide_213 + (((abs_2333 > __m_slide_213) ? iup_214 : idown_215) * (abs_2333 - __m_slide_213))));
			t_sample slide_2332 = __m_slide_213;
			__m_latch_216 = ((rsub_1957 != 0) ? slide_2332 : __m_latch_216);
			t_sample latch_2327 = __m_latch_216;
			t_sample mul_2329 = (y_2697 * latch_2327);
			t_sample dcblock_2328 = __m_dcblock_217(mul_2329);
			t_sample x_2709 = add_1958;
			t_sample q_2706 = gen_2440;
			t_sample bw_2717 = safediv(((int)226), q_2706);
			t_sample r_2707 = exp(((-bw_2717) * twopi_over_sr_2718));
			t_sample c_2713 = ((((int)2) * r_2707) * cos((((int)226) * twopi_over_sr_2718)));
			t_sample c_2716 = ((-r_2707) * r_2707);
			t_sample y_2708 = ((((((int)1) - r_2707) * (x_2709 - (r_2707 * m_x_7))) + (c_2713 * m_y_6)) + (c_2716 * m_y_5));
			m_y_5 = m_y_6;
			m_y_6 = y_2708;
			m_x_7 = m_x_8;
			m_x_8 = x_2709;
			t_sample x_2315 = in2;
			t_sample q_2308 = gen_2440;
			t_sample bw_2316 = safediv(((int)226), q_2308);
			t_sample r_2309 = exp(((-bw_2316) * twopi_over_sr_2319));
			t_sample c_2318 = ((((int)2) * r_2309) * cos((((int)226) * twopi_over_sr_2319)));
			t_sample c_2321 = ((-r_2309) * r_2309);
			t_sample y_2320 = ((((((int)1) - r_2309) * (x_2315 - (r_2309 * m_x_3))) + (c_2318 * m_y_2)) + (c_2321 * m_y_1));
			m_y_1 = m_y_2;
			m_y_2 = y_2320;
			m_x_3 = m_x_4;
			m_x_4 = x_2315;
			t_sample abs_2307 = fabs(y_2320);
			__m_slide_218 = fixdenorm((__m_slide_218 + (((abs_2307 > __m_slide_218) ? iup_219 : idown_220) * (abs_2307 - __m_slide_218))));
			t_sample slide_2306 = __m_slide_218;
			__m_latch_221 = ((rsub_1957 != 0) ? slide_2306 : __m_latch_221);
			t_sample latch_2301 = __m_latch_221;
			t_sample mul_2303 = (y_2708 * latch_2301);
			t_sample dcblock_2302 = __m_dcblock_222(mul_2303);
			t_sample pass_2441 = (((((((((((((((dcblock_2302 + dcblock_2328) + dcblock_2398) + dcblock_1962) + dcblock_1990) + dcblock_2016) + dcblock_2042) + dcblock_2068) + dcblock_2094) + dcblock_2120) + dcblock_2146) + dcblock_2172) + dcblock_2198) + dcblock_2224) + dcblock_2250) + dcblock_2276);
			t_sample add_2452 = (pass_2441 + gate_2444);
			t_sample out2 = add_2452;
			t_sample add_2453 = (pass_2441 + gate_2444);
			t_sample out1 = add_2453;
			m_history_132 = history_2447_next_2449;
			m_history_131 = history_2435_next_2437;
			m_history_129 = history_2431_next_2439;
			m_history_130 = history_2433_next_2438;
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
	inline void set_sw1(t_param _value) {
		m_sw_134 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_res(t_param _value) {
		m_knob3_res_135 = (_value < 15 ? 15 : (_value > 50 ? 50 : _value));
	};
	inline void set_knob5_noise(t_param _value) {
		m_knob5_noise_136 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 1: *value = self->m_knob4_gain_133; break;
		case 2: *value = self->m_knob5_noise_136; break;
		case 3: *value = self->m_sw_134; break;
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
	// initialize parameter 3 ("m_sw_134")
	pi = self->__commonstate.params + 3;
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
