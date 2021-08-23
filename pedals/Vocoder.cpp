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
	t_sample m_sw_134;
	t_sample __m_slide_140;
	t_sample __m_slide_143;
	t_sample __m_latch_146;
	t_sample m_x_123;
	t_sample m_y_14;
	t_sample m_sw_136;
	t_sample m_knob4_gain_137;
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
		m_sw_134 = ((int)0);
		m_knob3_res_135 = 15;
		m_sw_136 = 0;
		m_knob4_gain_137 = 5;
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
		t_sample rsub_1732 = (((int)1) - m_sw_136);
		t_sample mstosamps_2128 = (((int)2) * (samplerate * 0.001));
		t_sample mstosamps_2217 = (((int)20) * (samplerate * 0.001));
		t_sample iup_141 = (1 / maximum(1, abs(((int)10))));
		t_sample idown_142 = (1 / maximum(1, abs(((int)400))));
		t_sample twopi_over_sr = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2068 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_144 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_145 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2235 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2042 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_149 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_150 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2249 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2016 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_154 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_155 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2267 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_1990 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_159 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_160 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2285 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_1964 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_164 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_165 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2314 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_1938 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_169 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_170 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2332 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_1912 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_174 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_175 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2350 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_1886 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_179 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_180 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2366 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_1861 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_184 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_185 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2375 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_1834 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_189 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_190 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2401 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_1808 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_194 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_195 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2411 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_1783 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_199 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_200 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2428 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_1756 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_204 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_205 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2456 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2190 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_209 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_210 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2475 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2120 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_214 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_215 = (1 / maximum(1, abs(mstosamps_2217)));
		t_sample twopi_over_sr_2482 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_2094 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_219 = (1 / maximum(1, abs(mstosamps_2128)));
		t_sample idown_220 = (1 / maximum(1, abs(mstosamps_2217)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_2223 = __m_sah_138(m_history_132, m_sw_134, ((int)0));
			t_sample gen_2225 = sah_2223;
			t_sample rsub_2221 = (((int)1) - sah_2223);
			t_sample history_2222_next_2224 = fixdenorm(rsub_2221);
			t_sample out3 = gen_2225;
			t_sample add_2226 = (gen_2225 + ((int)1));
			t_sample choice_139 = int(add_2226);
			t_sample gate_2219 = (((choice_139 >= 1) && (choice_139 < 2)) ? in1 : 0);
			t_sample gate_2220 = ((choice_139 >= 2) ? in1 : 0);
			t_sample mix_2505 = (m_history_131 + (((t_sample)0.0019634941468452) * (m_knob3_res_135 - m_history_131)));
			t_sample mix_2209 = mix_2505;
			t_sample mix_2506 = (m_history_130 + (((t_sample)0.0019634941468452) * (mix_2209 - m_history_130)));
			t_sample mix_2207 = mix_2506;
			t_sample mix_2507 = (m_history_129 + (((t_sample)0.0019634941468452) * (mix_2207 - m_history_129)));
			t_sample mix_2205 = mix_2507;
			t_sample gen_2215 = mix_2205;
			t_sample history_2210_next_2212 = fixdenorm(mix_2209);
			t_sample history_2208_next_2213 = fixdenorm(mix_2207);
			t_sample history_2206_next_2214 = fixdenorm(mix_2205);
			t_sample mul_1730 = (gate_2220 * m_knob4_gain_137);
			t_sample abs_1728 = fabs(gate_2220);
			__m_slide_140 = fixdenorm((__m_slide_140 + (((abs_1728 > __m_slide_140) ? iup_141 : idown_142) * (abs_1728 - __m_slide_140))));
			t_sample slide_1727 = __m_slide_140;
			t_sample noise_1735 = noise();
			t_sample mul_1734 = (noise_1735 * m_knob5_noise_133);
			t_sample mul_1729 = (slide_1727 * mul_1734);
			t_sample add_1733 = (mul_1730 + mul_1729);
			t_sample x = add_1733;
			t_sample q = gen_2215;
			t_sample bw = safediv(((t_sample)284.5), q);
			t_sample r = exp(((-bw) * twopi_over_sr));
			t_sample c1 = ((((int)2) * r) * cos((((t_sample)284.5) * twopi_over_sr)));
			t_sample c2 = ((-r) * r);
			t_sample y = ((((((int)1) - r) * (x - (r * m_x_127))) + (c1 * m_y_126)) + (c2 * m_y_125));
			m_y_125 = m_y_126;
			m_y_126 = y;
			m_x_127 = m_x_128;
			m_x_128 = x;
			t_sample x_2064 = in2;
			t_sample q_2057 = gen_2215;
			t_sample bw_2065 = safediv(((t_sample)284.5), q_2057);
			t_sample r_2058 = exp(((-bw_2065) * twopi_over_sr_2068));
			t_sample c_2067 = ((((int)2) * r_2058) * cos((((t_sample)284.5) * twopi_over_sr_2068)));
			t_sample c_2070 = ((-r_2058) * r_2058);
			t_sample y_2069 = ((((((int)1) - r_2058) * (x_2064 - (r_2058 * m_x_123))) + (c_2067 * m_y_122)) + (c_2070 * m_y_121));
			m_y_121 = m_y_122;
			m_y_122 = y_2069;
			m_x_123 = m_x_124;
			m_x_124 = x_2064;
			t_sample abs_2056 = fabs(y_2069);
			__m_slide_143 = fixdenorm((__m_slide_143 + (((abs_2056 > __m_slide_143) ? iup_144 : idown_145) * (abs_2056 - __m_slide_143))));
			t_sample slide_2055 = __m_slide_143;
			__m_latch_146 = ((rsub_1732 != 0) ? slide_2055 : __m_latch_146);
			t_sample latch_2050 = __m_latch_146;
			t_sample mul_2052 = (y * latch_2050);
			t_sample dcblock_2051 = __m_dcblock_147(mul_2052);
			t_sample x_2233 = add_1733;
			t_sample q_2239 = gen_2215;
			t_sample bw_2238 = safediv(((t_sample)358.5), q_2239);
			t_sample r_2231 = exp(((-bw_2238) * twopi_over_sr_2235));
			t_sample c_2237 = ((((int)2) * r_2231) * cos((((t_sample)358.5) * twopi_over_sr_2235)));
			t_sample c_2236 = ((-r_2231) * r_2231);
			t_sample y_2232 = ((((((int)1) - r_2231) * (x_2233 - (r_2231 * m_x_119))) + (c_2237 * m_y_118)) + (c_2236 * m_y_117));
			m_y_117 = m_y_118;
			m_y_118 = y_2232;
			m_x_119 = m_x_120;
			m_x_120 = x_2233;
			t_sample x_2038 = in2;
			t_sample q_2031 = gen_2215;
			t_sample bw_2039 = safediv(((t_sample)358.5), q_2031);
			t_sample r_2032 = exp(((-bw_2039) * twopi_over_sr_2042));
			t_sample c_2041 = ((((int)2) * r_2032) * cos((((t_sample)358.5) * twopi_over_sr_2042)));
			t_sample c_2044 = ((-r_2032) * r_2032);
			t_sample y_2043 = ((((((int)1) - r_2032) * (x_2038 - (r_2032 * m_x_115))) + (c_2041 * m_y_114)) + (c_2044 * m_y_113));
			m_y_113 = m_y_114;
			m_y_114 = y_2043;
			m_x_115 = m_x_116;
			m_x_116 = x_2038;
			t_sample abs_2030 = fabs(y_2043);
			__m_slide_148 = fixdenorm((__m_slide_148 + (((abs_2030 > __m_slide_148) ? iup_149 : idown_150) * (abs_2030 - __m_slide_148))));
			t_sample slide_2029 = __m_slide_148;
			__m_latch_151 = ((rsub_1732 != 0) ? slide_2029 : __m_latch_151);
			t_sample latch_2024 = __m_latch_151;
			t_sample mul_2026 = (y_2232 * latch_2024);
			t_sample dcblock_2025 = __m_dcblock_152(mul_2026);
			t_sample x_2254 = add_1733;
			t_sample q_2252 = gen_2215;
			t_sample bw_2255 = safediv(((int)452), q_2252);
			t_sample r_2258 = exp(((-bw_2255) * twopi_over_sr_2249));
			t_sample c_2257 = ((((int)2) * r_2258) * cos((((int)452) * twopi_over_sr_2249)));
			t_sample c_2247 = ((-r_2258) * r_2258);
			t_sample y_2253 = ((((((int)1) - r_2258) * (x_2254 - (r_2258 * m_x_111))) + (c_2257 * m_y_110)) + (c_2247 * m_y_109));
			m_y_109 = m_y_110;
			m_y_110 = y_2253;
			m_x_111 = m_x_112;
			m_x_112 = x_2254;
			t_sample x_2012 = in2;
			t_sample q_2005 = gen_2215;
			t_sample bw_2013 = safediv(((int)452), q_2005);
			t_sample r_2006 = exp(((-bw_2013) * twopi_over_sr_2016));
			t_sample c_2015 = ((((int)2) * r_2006) * cos((((int)452) * twopi_over_sr_2016)));
			t_sample c_2018 = ((-r_2006) * r_2006);
			t_sample y_2017 = ((((((int)1) - r_2006) * (x_2012 - (r_2006 * m_x_107))) + (c_2015 * m_y_106)) + (c_2018 * m_y_105));
			m_y_105 = m_y_106;
			m_y_106 = y_2017;
			m_x_107 = m_x_108;
			m_x_108 = x_2012;
			t_sample abs_2004 = fabs(y_2017);
			__m_slide_153 = fixdenorm((__m_slide_153 + (((abs_2004 > __m_slide_153) ? iup_154 : idown_155) * (abs_2004 - __m_slide_153))));
			t_sample slide_2003 = __m_slide_153;
			__m_latch_156 = ((rsub_1732 != 0) ? slide_2003 : __m_latch_156);
			t_sample latch_1998 = __m_latch_156;
			t_sample mul_2000 = (y_2253 * latch_1998);
			t_sample dcblock_1999 = __m_dcblock_157(mul_2000);
			t_sample x_2273 = add_1733;
			t_sample q_2270 = gen_2215;
			t_sample bw_2274 = safediv(((t_sample)569.5), q_2270);
			t_sample r_2271 = exp(((-bw_2274) * twopi_over_sr_2267));
			t_sample c_2276 = ((((int)2) * r_2271) * cos((((t_sample)569.5) * twopi_over_sr_2267)));
			t_sample c_2265 = ((-r_2271) * r_2271);
			t_sample y_2272 = ((((((int)1) - r_2271) * (x_2273 - (r_2271 * m_x_103))) + (c_2276 * m_y_102)) + (c_2265 * m_y_101));
			m_y_101 = m_y_102;
			m_y_102 = y_2272;
			m_x_103 = m_x_104;
			m_x_104 = x_2273;
			t_sample x_1986 = in2;
			t_sample q_1979 = gen_2215;
			t_sample bw_1987 = safediv(((t_sample)569.5), q_1979);
			t_sample r_1980 = exp(((-bw_1987) * twopi_over_sr_1990));
			t_sample c_1989 = ((((int)2) * r_1980) * cos((((t_sample)569.5) * twopi_over_sr_1990)));
			t_sample c_1992 = ((-r_1980) * r_1980);
			t_sample y_1991 = ((((((int)1) - r_1980) * (x_1986 - (r_1980 * m_x_99))) + (c_1989 * m_y_98)) + (c_1992 * m_y_97));
			m_y_97 = m_y_98;
			m_y_98 = y_1991;
			m_x_99 = m_x_100;
			m_x_100 = x_1986;
			t_sample abs_1978 = fabs(y_1991);
			__m_slide_158 = fixdenorm((__m_slide_158 + (((abs_1978 > __m_slide_158) ? iup_159 : idown_160) * (abs_1978 - __m_slide_158))));
			t_sample slide_1977 = __m_slide_158;
			__m_latch_161 = ((rsub_1732 != 0) ? slide_1977 : __m_latch_161);
			t_sample latch_1972 = __m_latch_161;
			t_sample mul_1974 = (y_2272 * latch_1972);
			t_sample dcblock_1973 = __m_dcblock_162(mul_1974);
			t_sample x_2291 = add_1733;
			t_sample q_2288 = gen_2215;
			t_sample bw_2292 = safediv(((t_sample)717.5), q_2288);
			t_sample r_2289 = exp(((-bw_2292) * twopi_over_sr_2285));
			t_sample c_2294 = ((((int)2) * r_2289) * cos((((t_sample)717.5) * twopi_over_sr_2285)));
			t_sample c_2283 = ((-r_2289) * r_2289);
			t_sample y_2290 = ((((((int)1) - r_2289) * (x_2291 - (r_2289 * m_x_95))) + (c_2294 * m_y_94)) + (c_2283 * m_y_93));
			m_y_93 = m_y_94;
			m_y_94 = y_2290;
			m_x_95 = m_x_96;
			m_x_96 = x_2291;
			t_sample x_1960 = in2;
			t_sample q_1953 = gen_2215;
			t_sample bw_1961 = safediv(((t_sample)717.5), q_1953);
			t_sample r_1954 = exp(((-bw_1961) * twopi_over_sr_1964));
			t_sample c_1963 = ((((int)2) * r_1954) * cos((((t_sample)717.5) * twopi_over_sr_1964)));
			t_sample c_1966 = ((-r_1954) * r_1954);
			t_sample y_1965 = ((((((int)1) - r_1954) * (x_1960 - (r_1954 * m_x_91))) + (c_1963 * m_y_90)) + (c_1966 * m_y_89));
			m_y_89 = m_y_90;
			m_y_90 = y_1965;
			m_x_91 = m_x_92;
			m_x_92 = x_1960;
			t_sample abs_1952 = fabs(y_1965);
			__m_slide_163 = fixdenorm((__m_slide_163 + (((abs_1952 > __m_slide_163) ? iup_164 : idown_165) * (abs_1952 - __m_slide_163))));
			t_sample slide_1951 = __m_slide_163;
			__m_latch_166 = ((rsub_1732 != 0) ? slide_1951 : __m_latch_166);
			t_sample latch_1946 = __m_latch_166;
			t_sample mul_1948 = (y_2290 * latch_1946);
			t_sample dcblock_1947 = __m_dcblock_167(mul_1948);
			t_sample x_2308 = add_1733;
			t_sample q_2305 = gen_2215;
			t_sample bw_2312 = safediv(((int)904), q_2305);
			t_sample r_2306 = exp(((-bw_2312) * twopi_over_sr_2314));
			t_sample c_2309 = ((((int)2) * r_2306) * cos((((int)904) * twopi_over_sr_2314)));
			t_sample c_2301 = ((-r_2306) * r_2306);
			t_sample y_2307 = ((((((int)1) - r_2306) * (x_2308 - (r_2306 * m_x_87))) + (c_2309 * m_y_86)) + (c_2301 * m_y_85));
			m_y_85 = m_y_86;
			m_y_86 = y_2307;
			m_x_87 = m_x_88;
			m_x_88 = x_2308;
			t_sample x_1934 = in2;
			t_sample q_1927 = gen_2215;
			t_sample bw_1935 = safediv(((int)904), q_1927);
			t_sample r_1928 = exp(((-bw_1935) * twopi_over_sr_1938));
			t_sample c_1937 = ((((int)2) * r_1928) * cos((((int)904) * twopi_over_sr_1938)));
			t_sample c_1940 = ((-r_1928) * r_1928);
			t_sample y_1939 = ((((((int)1) - r_1928) * (x_1934 - (r_1928 * m_x_83))) + (c_1937 * m_y_82)) + (c_1940 * m_y_81));
			m_y_81 = m_y_82;
			m_y_82 = y_1939;
			m_x_83 = m_x_84;
			m_x_84 = x_1934;
			t_sample abs_1926 = fabs(y_1939);
			__m_slide_168 = fixdenorm((__m_slide_168 + (((abs_1926 > __m_slide_168) ? iup_169 : idown_170) * (abs_1926 - __m_slide_168))));
			t_sample slide_1925 = __m_slide_168;
			__m_latch_171 = ((rsub_1732 != 0) ? slide_1925 : __m_latch_171);
			t_sample latch_1920 = __m_latch_171;
			t_sample mul_1922 = (y_2307 * latch_1920);
			t_sample dcblock_1921 = __m_dcblock_172(mul_1922);
			t_sample x_2326 = add_1733;
			t_sample q_2323 = gen_2215;
			t_sample bw_2329 = safediv(((int)1139), q_2323);
			t_sample r_2324 = exp(((-bw_2329) * twopi_over_sr_2332));
			t_sample c_2331 = ((((int)2) * r_2324) * cos((((int)1139) * twopi_over_sr_2332)));
			t_sample c_2319 = ((-r_2324) * r_2324);
			t_sample y_2325 = ((((((int)1) - r_2324) * (x_2326 - (r_2324 * m_x_79))) + (c_2331 * m_y_78)) + (c_2319 * m_y_77));
			m_y_77 = m_y_78;
			m_y_78 = y_2325;
			m_x_79 = m_x_80;
			m_x_80 = x_2326;
			t_sample x_1908 = in2;
			t_sample q_1901 = gen_2215;
			t_sample bw_1909 = safediv(((int)1139), q_1901);
			t_sample r_1902 = exp(((-bw_1909) * twopi_over_sr_1912));
			t_sample c_1911 = ((((int)2) * r_1902) * cos((((int)1139) * twopi_over_sr_1912)));
			t_sample c_1914 = ((-r_1902) * r_1902);
			t_sample y_1913 = ((((((int)1) - r_1902) * (x_1908 - (r_1902 * m_x_75))) + (c_1911 * m_y_74)) + (c_1914 * m_y_73));
			m_y_73 = m_y_74;
			m_y_74 = y_1913;
			m_x_75 = m_x_76;
			m_x_76 = x_1908;
			t_sample abs_1900 = fabs(y_1913);
			__m_slide_173 = fixdenorm((__m_slide_173 + (((abs_1900 > __m_slide_173) ? iup_174 : idown_175) * (abs_1900 - __m_slide_173))));
			t_sample slide_1899 = __m_slide_173;
			__m_latch_176 = ((rsub_1732 != 0) ? slide_1899 : __m_latch_176);
			t_sample latch_1894 = __m_latch_176;
			t_sample mul_1896 = (y_2325 * latch_1894);
			t_sample dcblock_1895 = __m_dcblock_177(mul_1896);
			t_sample x_2344 = add_1733;
			t_sample q_2341 = gen_2215;
			t_sample bw_2348 = safediv(((int)1435), q_2341);
			t_sample r_2342 = exp(((-bw_2348) * twopi_over_sr_2350));
			t_sample c_2345 = ((((int)2) * r_2342) * cos((((int)1435) * twopi_over_sr_2350)));
			t_sample c_2337 = ((-r_2342) * r_2342);
			t_sample y_2343 = ((((((int)1) - r_2342) * (x_2344 - (r_2342 * m_x_71))) + (c_2345 * m_y_70)) + (c_2337 * m_y_69));
			m_y_69 = m_y_70;
			m_y_70 = y_2343;
			m_x_71 = m_x_72;
			m_x_72 = x_2344;
			t_sample x_1882 = in2;
			t_sample q_1875 = gen_2215;
			t_sample bw_1883 = safediv(((int)1435), q_1875);
			t_sample r_1876 = exp(((-bw_1883) * twopi_over_sr_1886));
			t_sample c_1885 = ((((int)2) * r_1876) * cos((((int)1435) * twopi_over_sr_1886)));
			t_sample c_1888 = ((-r_1876) * r_1876);
			t_sample y_1887 = ((((((int)1) - r_1876) * (x_1882 - (r_1876 * m_x_67))) + (c_1885 * m_y_66)) + (c_1888 * m_y_65));
			m_y_65 = m_y_66;
			m_y_66 = y_1887;
			m_x_67 = m_x_68;
			m_x_68 = x_1882;
			t_sample abs_1874 = fabs(y_1887);
			__m_slide_178 = fixdenorm((__m_slide_178 + (((abs_1874 > __m_slide_178) ? iup_179 : idown_180) * (abs_1874 - __m_slide_178))));
			t_sample slide_1873 = __m_slide_178;
			__m_latch_181 = ((rsub_1732 != 0) ? slide_1873 : __m_latch_181);
			t_sample latch_1868 = __m_latch_181;
			t_sample mul_1870 = (y_2343 * latch_1868);
			t_sample dcblock_1869 = __m_dcblock_182(mul_1870);
			t_sample x_2362 = add_1733;
			t_sample q_2359 = gen_2215;
			t_sample bw_2367 = safediv(((int)1808), q_2359);
			t_sample r_2360 = exp(((-bw_2367) * twopi_over_sr_2366));
			t_sample c_2363 = ((((int)2) * r_2360) * cos((((int)1808) * twopi_over_sr_2366)));
			t_sample c_2355 = ((-r_2360) * r_2360);
			t_sample y_2361 = ((((((int)1) - r_2360) * (x_2362 - (r_2360 * m_x_63))) + (c_2363 * m_y_62)) + (c_2355 * m_y_61));
			m_y_61 = m_y_62;
			m_y_62 = y_2361;
			m_x_63 = m_x_64;
			m_x_64 = x_2362;
			t_sample x_1857 = in2;
			t_sample q_1849 = gen_2215;
			t_sample bw_1858 = safediv(((int)1808), q_1849);
			t_sample r_1851 = exp(((-bw_1858) * twopi_over_sr_1861));
			t_sample c_1860 = ((((int)2) * r_1851) * cos((((int)1808) * twopi_over_sr_1861)));
			t_sample c_1862 = ((-r_1851) * r_1851);
			t_sample y_1850 = ((((((int)1) - r_1851) * (x_1857 - (r_1851 * m_x_59))) + (c_1860 * m_y_58)) + (c_1862 * m_y_57));
			m_y_57 = m_y_58;
			m_y_58 = y_1850;
			m_x_59 = m_x_60;
			m_x_60 = x_1857;
			t_sample abs_1848 = fabs(y_1850);
			__m_slide_183 = fixdenorm((__m_slide_183 + (((abs_1848 > __m_slide_183) ? iup_184 : idown_185) * (abs_1848 - __m_slide_183))));
			t_sample slide_1847 = __m_slide_183;
			__m_latch_186 = ((rsub_1732 != 0) ? slide_1847 : __m_latch_186);
			t_sample latch_1842 = __m_latch_186;
			t_sample mul_1844 = (y_2361 * latch_1842);
			t_sample dcblock_1843 = __m_dcblock_187(mul_1844);
			t_sample x_2381 = add_1733;
			t_sample q_2378 = gen_2215;
			t_sample bw_2385 = safediv(((int)2260), q_2378);
			t_sample r_2379 = exp(((-bw_2385) * twopi_over_sr_2375));
			t_sample c_2382 = ((((int)2) * r_2379) * cos((((int)2260) * twopi_over_sr_2375)));
			t_sample c_2373 = ((-r_2379) * r_2379);
			t_sample y_2380 = ((((((int)1) - r_2379) * (x_2381 - (r_2379 * m_x_55))) + (c_2382 * m_y_54)) + (c_2373 * m_y_53));
			m_y_53 = m_y_54;
			m_y_54 = y_2380;
			m_x_55 = m_x_56;
			m_x_56 = x_2381;
			t_sample x_1830 = in2;
			t_sample q_1823 = gen_2215;
			t_sample bw_1831 = safediv(((int)2260), q_1823);
			t_sample r_1824 = exp(((-bw_1831) * twopi_over_sr_1834));
			t_sample c_1833 = ((((int)2) * r_1824) * cos((((int)2260) * twopi_over_sr_1834)));
			t_sample c_1836 = ((-r_1824) * r_1824);
			t_sample y_1835 = ((((((int)1) - r_1824) * (x_1830 - (r_1824 * m_x_51))) + (c_1833 * m_y_50)) + (c_1836 * m_y_49));
			m_y_49 = m_y_50;
			m_y_50 = y_1835;
			m_x_51 = m_x_52;
			m_x_52 = x_1830;
			t_sample abs_1822 = fabs(y_1835);
			__m_slide_188 = fixdenorm((__m_slide_188 + (((abs_1822 > __m_slide_188) ? iup_189 : idown_190) * (abs_1822 - __m_slide_188))));
			t_sample slide_1821 = __m_slide_188;
			__m_latch_191 = ((rsub_1732 != 0) ? slide_1821 : __m_latch_191);
			t_sample latch_1816 = __m_latch_191;
			t_sample mul_1818 = (y_2380 * latch_1816);
			t_sample dcblock_1817 = __m_dcblock_192(mul_1818);
			t_sample x_2398 = add_1733;
			t_sample q_2395 = gen_2215;
			t_sample bw_2402 = safediv(((int)2852), q_2395);
			t_sample r_2396 = exp(((-bw_2402) * twopi_over_sr_2401));
			t_sample c_2404 = ((((int)2) * r_2396) * cos((((int)2852) * twopi_over_sr_2401)));
			t_sample c_2391 = ((-r_2396) * r_2396);
			t_sample y_2397 = ((((((int)1) - r_2396) * (x_2398 - (r_2396 * m_x_47))) + (c_2404 * m_y_46)) + (c_2391 * m_y_45));
			m_y_45 = m_y_46;
			m_y_46 = y_2397;
			m_x_47 = m_x_48;
			m_x_48 = x_2398;
			t_sample x_1804 = in2;
			t_sample q_1797 = gen_2215;
			t_sample bw_1805 = safediv(((int)2852), q_1797);
			t_sample r_1798 = exp(((-bw_1805) * twopi_over_sr_1808));
			t_sample c_1807 = ((((int)2) * r_1798) * cos((((int)2852) * twopi_over_sr_1808)));
			t_sample c_1810 = ((-r_1798) * r_1798);
			t_sample y_1809 = ((((((int)1) - r_1798) * (x_1804 - (r_1798 * m_x_43))) + (c_1807 * m_y_42)) + (c_1810 * m_y_41));
			m_y_41 = m_y_42;
			m_y_42 = y_1809;
			m_x_43 = m_x_44;
			m_x_44 = x_1804;
			t_sample abs_1796 = fabs(y_1809);
			__m_slide_193 = fixdenorm((__m_slide_193 + (((abs_1796 > __m_slide_193) ? iup_194 : idown_195) * (abs_1796 - __m_slide_193))));
			t_sample slide_1795 = __m_slide_193;
			__m_latch_196 = ((rsub_1732 != 0) ? slide_1795 : __m_latch_196);
			t_sample latch_1790 = __m_latch_196;
			t_sample mul_1792 = (y_2397 * latch_1790);
			t_sample dcblock_1791 = __m_dcblock_197(mul_1792);
			t_sample x_2417 = add_1733;
			t_sample q_2414 = gen_2215;
			t_sample bw_2420 = safediv(((int)3616), q_2414);
			t_sample r_2415 = exp(((-bw_2420) * twopi_over_sr_2411));
			t_sample c_2422 = ((((int)2) * r_2415) * cos((((int)3616) * twopi_over_sr_2411)));
			t_sample c_2409 = ((-r_2415) * r_2415);
			t_sample y_2416 = ((((((int)1) - r_2415) * (x_2417 - (r_2415 * m_x_39))) + (c_2422 * m_y_38)) + (c_2409 * m_y_37));
			m_y_37 = m_y_38;
			m_y_38 = y_2416;
			m_x_39 = m_x_40;
			m_x_40 = x_2417;
			t_sample x_1779 = in2;
			t_sample q_1771 = gen_2215;
			t_sample bw_1780 = safediv(((int)3616), q_1771);
			t_sample r_1773 = exp(((-bw_1780) * twopi_over_sr_1783));
			t_sample c_1782 = ((((int)2) * r_1773) * cos((((int)3616) * twopi_over_sr_1783)));
			t_sample c_1784 = ((-r_1773) * r_1773);
			t_sample y_1772 = ((((((int)1) - r_1773) * (x_1779 - (r_1773 * m_x_35))) + (c_1782 * m_y_34)) + (c_1784 * m_y_33));
			m_y_33 = m_y_34;
			m_y_34 = y_1772;
			m_x_35 = m_x_36;
			m_x_36 = x_1779;
			t_sample abs_1770 = fabs(y_1772);
			__m_slide_198 = fixdenorm((__m_slide_198 + (((abs_1770 > __m_slide_198) ? iup_199 : idown_200) * (abs_1770 - __m_slide_198))));
			t_sample slide_1769 = __m_slide_198;
			__m_latch_201 = ((rsub_1732 != 0) ? slide_1769 : __m_latch_201);
			t_sample latch_1764 = __m_latch_201;
			t_sample mul_1766 = (y_2416 * latch_1764);
			t_sample dcblock_1765 = __m_dcblock_202(mul_1766);
			t_sample x_2432 = add_1733;
			t_sample q_2429 = gen_2215;
			t_sample bw_2440 = safediv(((int)4556), q_2429);
			t_sample r_2430 = exp(((-bw_2440) * twopi_over_sr_2428));
			t_sample c_2437 = ((((int)2) * r_2430) * cos((((int)4556) * twopi_over_sr_2428)));
			t_sample c_2434 = ((-r_2430) * r_2430);
			t_sample y_2431 = ((((((int)1) - r_2430) * (x_2432 - (r_2430 * m_x_31))) + (c_2437 * m_y_30)) + (c_2434 * m_y_29));
			m_y_29 = m_y_30;
			m_y_30 = y_2431;
			m_x_31 = m_x_32;
			m_x_32 = x_2432;
			t_sample x_1752 = in2;
			t_sample q_1745 = gen_2215;
			t_sample bw_1753 = safediv(((int)4556), q_1745);
			t_sample r_1746 = exp(((-bw_1753) * twopi_over_sr_1756));
			t_sample c_1755 = ((((int)2) * r_1746) * cos((((int)4556) * twopi_over_sr_1756)));
			t_sample c_1758 = ((-r_1746) * r_1746);
			t_sample y_1757 = ((((((int)1) - r_1746) * (x_1752 - (r_1746 * m_x_27))) + (c_1755 * m_y_26)) + (c_1758 * m_y_25));
			m_y_25 = m_y_26;
			m_y_26 = y_1757;
			m_x_27 = m_x_28;
			m_x_28 = x_1752;
			t_sample abs_1744 = fabs(y_1757);
			__m_slide_203 = fixdenorm((__m_slide_203 + (((abs_1744 > __m_slide_203) ? iup_204 : idown_205) * (abs_1744 - __m_slide_203))));
			t_sample slide_1743 = __m_slide_203;
			__m_latch_206 = ((rsub_1732 != 0) ? slide_1743 : __m_latch_206);
			t_sample latch_1736 = __m_latch_206;
			t_sample mul_1738 = (y_2431 * latch_1736);
			t_sample dcblock_1737 = __m_dcblock_207(mul_1738);
			t_sample x_2449 = add_1733;
			t_sample q_2446 = gen_2215;
			t_sample bw_2458 = safediv(((t_sample)104.5), q_2446);
			t_sample r_2447 = exp(((-bw_2458) * twopi_over_sr_2456));
			t_sample c_2457 = ((((int)2) * r_2447) * cos((((t_sample)104.5) * twopi_over_sr_2456)));
			t_sample c_2451 = ((-r_2447) * r_2447);
			t_sample y_2448 = ((((((int)1) - r_2447) * (x_2449 - (r_2447 * m_x_23))) + (c_2457 * m_y_22)) + (c_2451 * m_y_21));
			m_y_21 = m_y_22;
			m_y_22 = y_2448;
			m_x_23 = m_x_24;
			m_x_24 = x_2449;
			t_sample x_2186 = in2;
			t_sample q_2179 = gen_2215;
			t_sample bw_2187 = safediv(((t_sample)104.5), q_2179);
			t_sample r_2180 = exp(((-bw_2187) * twopi_over_sr_2190));
			t_sample c_2189 = ((((int)2) * r_2180) * cos((((t_sample)104.5) * twopi_over_sr_2190)));
			t_sample c_2192 = ((-r_2180) * r_2180);
			t_sample y_2191 = ((((((int)1) - r_2180) * (x_2186 - (r_2180 * m_x_19))) + (c_2189 * m_y_18)) + (c_2192 * m_y_17));
			m_y_17 = m_y_18;
			m_y_18 = y_2191;
			m_x_19 = m_x_20;
			m_x_20 = x_2186;
			t_sample abs_2178 = fabs(y_2191);
			__m_slide_208 = fixdenorm((__m_slide_208 + (((abs_2178 > __m_slide_208) ? iup_209 : idown_210) * (abs_2178 - __m_slide_208))));
			t_sample slide_2177 = __m_slide_208;
			__m_latch_211 = ((rsub_1732 != 0) ? slide_2177 : __m_latch_211);
			t_sample latch_2172 = __m_latch_211;
			t_sample mul_2174 = (y_2448 * latch_2172);
			t_sample dcblock_2173 = __m_dcblock_212(mul_2174);
			t_sample x_2467 = add_1733;
			t_sample q_2464 = gen_2215;
			t_sample bw_2476 = safediv(((t_sample)179.5), q_2464);
			t_sample r_2465 = exp(((-bw_2476) * twopi_over_sr_2475));
			t_sample c_2472 = ((((int)2) * r_2465) * cos((((t_sample)179.5) * twopi_over_sr_2475)));
			t_sample c_2469 = ((-r_2465) * r_2465);
			t_sample y_2466 = ((((((int)1) - r_2465) * (x_2467 - (r_2465 * m_x_15))) + (c_2472 * m_y_14)) + (c_2469 * m_y_13));
			m_y_13 = m_y_14;
			m_y_14 = y_2466;
			m_x_15 = m_x_16;
			m_x_16 = x_2467;
			t_sample x_2116 = in2;
			t_sample q_2109 = gen_2215;
			t_sample bw_2117 = safediv(((t_sample)179.5), q_2109);
			t_sample r_2110 = exp(((-bw_2117) * twopi_over_sr_2120));
			t_sample c_2119 = ((((int)2) * r_2110) * cos((((t_sample)179.5) * twopi_over_sr_2120)));
			t_sample c_2122 = ((-r_2110) * r_2110);
			t_sample y_2121 = ((((((int)1) - r_2110) * (x_2116 - (r_2110 * m_x_11))) + (c_2119 * m_y_10)) + (c_2122 * m_y_9));
			m_y_9 = m_y_10;
			m_y_10 = y_2121;
			m_x_11 = m_x_12;
			m_x_12 = x_2116;
			t_sample abs_2108 = fabs(y_2121);
			__m_slide_213 = fixdenorm((__m_slide_213 + (((abs_2108 > __m_slide_213) ? iup_214 : idown_215) * (abs_2108 - __m_slide_213))));
			t_sample slide_2107 = __m_slide_213;
			__m_latch_216 = ((rsub_1732 != 0) ? slide_2107 : __m_latch_216);
			t_sample latch_2102 = __m_latch_216;
			t_sample mul_2104 = (y_2466 * latch_2102);
			t_sample dcblock_2103 = __m_dcblock_217(mul_2104);
			t_sample x_2486 = add_1733;
			t_sample q_2483 = gen_2215;
			t_sample bw_2494 = safediv(((int)226), q_2483);
			t_sample r_2484 = exp(((-bw_2494) * twopi_over_sr_2482));
			t_sample c_2491 = ((((int)2) * r_2484) * cos((((int)226) * twopi_over_sr_2482)));
			t_sample c_2488 = ((-r_2484) * r_2484);
			t_sample y_2485 = ((((((int)1) - r_2484) * (x_2486 - (r_2484 * m_x_7))) + (c_2491 * m_y_6)) + (c_2488 * m_y_5));
			m_y_5 = m_y_6;
			m_y_6 = y_2485;
			m_x_7 = m_x_8;
			m_x_8 = x_2486;
			t_sample x_2090 = in2;
			t_sample q_2083 = gen_2215;
			t_sample bw_2091 = safediv(((int)226), q_2083);
			t_sample r_2084 = exp(((-bw_2091) * twopi_over_sr_2094));
			t_sample c_2093 = ((((int)2) * r_2084) * cos((((int)226) * twopi_over_sr_2094)));
			t_sample c_2096 = ((-r_2084) * r_2084);
			t_sample y_2095 = ((((((int)1) - r_2084) * (x_2090 - (r_2084 * m_x_3))) + (c_2093 * m_y_2)) + (c_2096 * m_y_1));
			m_y_1 = m_y_2;
			m_y_2 = y_2095;
			m_x_3 = m_x_4;
			m_x_4 = x_2090;
			t_sample abs_2082 = fabs(y_2095);
			__m_slide_218 = fixdenorm((__m_slide_218 + (((abs_2082 > __m_slide_218) ? iup_219 : idown_220) * (abs_2082 - __m_slide_218))));
			t_sample slide_2081 = __m_slide_218;
			__m_latch_221 = ((rsub_1732 != 0) ? slide_2081 : __m_latch_221);
			t_sample latch_2076 = __m_latch_221;
			t_sample mul_2078 = (y_2485 * latch_2076);
			t_sample dcblock_2077 = __m_dcblock_222(mul_2078);
			t_sample pass_2216 = (((((((((((((((dcblock_2077 + dcblock_2103) + dcblock_2173) + dcblock_1737) + dcblock_1765) + dcblock_1791) + dcblock_1817) + dcblock_1843) + dcblock_1869) + dcblock_1895) + dcblock_1921) + dcblock_1947) + dcblock_1973) + dcblock_1999) + dcblock_2025) + dcblock_2051);
			t_sample add_2228 = (pass_2216 + gate_2219);
			t_sample out1 = add_2228;
			t_sample add_2227 = (pass_2216 + gate_2219);
			t_sample out2 = add_2227;
			m_history_132 = history_2222_next_2224;
			m_history_131 = history_2210_next_2212;
			m_history_129 = history_2206_next_2214;
			m_history_130 = history_2208_next_2213;
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
	inline void set_sw1(t_param _value) {
		m_sw_134 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_res(t_param _value) {
		m_knob3_res_135 = (_value < 15 ? 15 : (_value > 50 ? 50 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_136 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_gain(t_param _value) {
		m_knob4_gain_137 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
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
		case 1: *value = self->m_knob4_gain_137; break;
		case 2: *value = self->m_knob5_noise_133; break;
		case 3: *value = self->m_sw_134; break;
		case 4: *value = self->m_sw_136; break;
		
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
	// initialize parameter 1 ("m_knob4_gain_137")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_gain";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_gain_137;
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
	// initialize parameter 4 ("m_sw_136")
	pi = self->__commonstate.params + 4;
	pi->name = "sw2";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Vocoder::
