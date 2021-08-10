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
	t_sample m_sw_134;
	t_sample m_y_14;
	t_sample __m_slide_141;
	t_sample __m_latch_144;
	t_sample m_y_123;
	t_sample m_knob4_gain_138;
	t_sample m_knob3_res_136;
	t_sample m_sw_137;
	t_sample m_knob5_noise_135;
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
		m_sw_134 = 0;
		m_knob5_noise_135 = 0;
		m_knob3_res_136 = 15;
		m_sw_137 = ((int)0);
		m_knob4_gain_138 = 5;
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
		t_sample rsub_44613 = (((int)1) - m_sw_134);
		t_sample mstosamps_45013 = (((int)2) * (samplerate * 0.001));
		t_sample mstosamps_45104 = (((int)20) * (samplerate * 0.001));
		t_sample twopi_over_sr = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44953 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_142 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_143 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45130 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44927 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_147 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_148 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45148 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44901 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_152 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_153 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45154 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44875 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_157 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_158 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45172 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44849 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_162 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_163 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45191 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44823 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_167 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_168 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45207 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44797 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_172 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_173 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45225 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44771 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_177 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_178 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45243 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44745 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_182 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_183 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45261 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44719 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_187 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_188 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45280 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44693 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_192 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_193 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45299 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44667 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_197 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_198 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45316 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44641 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_202 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_203 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45333 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_45075 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_207 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_208 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45351 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_45005 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_212 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_213 = (1 / maximum(1, abs(mstosamps_45104)));
		t_sample twopi_over_sr_45369 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_44979 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_217 = (1 / maximum(1, abs(mstosamps_45013)));
		t_sample idown_218 = (1 / maximum(1, abs(mstosamps_45104)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_45111 = __m_sah_139(m_history_133, m_sw_137, ((int)0));
			t_sample gen_45113 = sah_45111;
			t_sample rsub_45109 = (((int)1) - sah_45111);
			t_sample history_45110_next_45112 = fixdenorm(rsub_45109);
			t_sample out3 = gen_45113;
			t_sample add_45114 = (gen_45113 + ((int)1));
			t_sample choice_140 = int(add_45114);
			t_sample gate_45106 = (((choice_140 >= 1) && (choice_140 < 2)) ? in1 : 0);
			t_sample gate_45107 = ((choice_140 >= 2) ? in1 : 0);
			t_sample mix_45400 = (m_history_132 + (((t_sample)0.0019634941468452) * (m_knob3_res_136 - m_history_132)));
			t_sample mix_45094 = mix_45400;
			t_sample mix_45401 = (m_history_131 + (((t_sample)0.0019634941468452) * (mix_45094 - m_history_131)));
			t_sample mix_45092 = mix_45401;
			t_sample mix_45402 = (m_history_130 + (((t_sample)0.0019634941468452) * (mix_45092 - m_history_130)));
			t_sample mix_45090 = mix_45402;
			t_sample gen_45102 = mix_45090;
			t_sample history_45096_next_45099 = fixdenorm(mix_45094);
			t_sample history_45093_next_45100 = fixdenorm(mix_45092);
			t_sample history_45091_next_45101 = fixdenorm(mix_45090);
			t_sample noise_44620 = noise();
			t_sample mul_44614 = (noise_44620 * ((t_sample)0.5));
			t_sample add_44616 = (mul_44614 + m_history_1);
			t_sample mul_44615 = (add_44616 * ((t_sample)0.5));
			t_sample mul_44619 = (add_44616 * m_knob5_noise_135);
			t_sample add_44618 = (gate_45107 + mul_44619);
			t_sample x = add_44618;
			t_sample q = gen_45102;
			t_sample bw = safediv(((t_sample)284.5), q);
			t_sample r = exp(((-bw) * twopi_over_sr));
			t_sample c1 = ((((int)2) * r) * cos((((t_sample)284.5) * twopi_over_sr)));
			t_sample c2 = ((-r) * r);
			t_sample y = ((((((int)1) - r) * (x - (r * m_x_128))) + (c1 * m_y_127)) + (c2 * m_y_126));
			m_y_126 = m_y_127;
			m_y_127 = y;
			m_x_128 = m_x_129;
			m_x_129 = x;
			t_sample x_44950 = in2;
			t_sample q_44942 = gen_45102;
			t_sample bw_44951 = safediv(((t_sample)284.5), q_44942);
			t_sample r_44944 = exp(((-bw_44951) * twopi_over_sr_44953));
			t_sample c_44952 = ((((int)2) * r_44944) * cos((((t_sample)284.5) * twopi_over_sr_44953)));
			t_sample c_44955 = ((-r_44944) * r_44944);
			t_sample y_44954 = ((((((int)1) - r_44944) * (x_44950 - (r_44944 * m_x_124))) + (c_44952 * m_y_123)) + (c_44955 * m_y_122));
			m_y_122 = m_y_123;
			m_y_123 = y_44954;
			m_x_124 = m_x_125;
			m_x_125 = x_44950;
			t_sample abs_44941 = fabs(y_44954);
			__m_slide_141 = fixdenorm((__m_slide_141 + (((abs_44941 > __m_slide_141) ? iup_142 : idown_143) * (abs_44941 - __m_slide_141))));
			t_sample slide_44940 = __m_slide_141;
			__m_latch_144 = ((rsub_44613 != 0) ? slide_44940 : __m_latch_144);
			t_sample latch_44935 = __m_latch_144;
			t_sample mul_44937 = (y * latch_44935);
			t_sample dcblock_44936 = __m_dcblock_145(mul_44937);
			t_sample x_45123 = add_44618;
			t_sample q_45120 = gen_45102;
			t_sample bw_45124 = safediv(((t_sample)358.5), q_45120);
			t_sample r_45121 = exp(((-bw_45124) * twopi_over_sr_45130));
			t_sample c_45127 = ((((int)2) * r_45121) * cos((((t_sample)358.5) * twopi_over_sr_45130)));
			t_sample c_45119 = ((-r_45121) * r_45121);
			t_sample y_45122 = ((((((int)1) - r_45121) * (x_45123 - (r_45121 * m_x_120))) + (c_45127 * m_y_119)) + (c_45119 * m_y_118));
			m_y_118 = m_y_119;
			m_y_119 = y_45122;
			m_x_120 = m_x_121;
			m_x_121 = x_45123;
			t_sample x_44924 = in2;
			t_sample q_44916 = gen_45102;
			t_sample bw_44925 = safediv(((t_sample)358.5), q_44916);
			t_sample r_44918 = exp(((-bw_44925) * twopi_over_sr_44927));
			t_sample c_44926 = ((((int)2) * r_44918) * cos((((t_sample)358.5) * twopi_over_sr_44927)));
			t_sample c_44929 = ((-r_44918) * r_44918);
			t_sample y_44928 = ((((((int)1) - r_44918) * (x_44924 - (r_44918 * m_x_116))) + (c_44926 * m_y_115)) + (c_44929 * m_y_114));
			m_y_114 = m_y_115;
			m_y_115 = y_44928;
			m_x_116 = m_x_117;
			m_x_117 = x_44924;
			t_sample abs_44915 = fabs(y_44928);
			__m_slide_146 = fixdenorm((__m_slide_146 + (((abs_44915 > __m_slide_146) ? iup_147 : idown_148) * (abs_44915 - __m_slide_146))));
			t_sample slide_44914 = __m_slide_146;
			__m_latch_149 = ((rsub_44613 != 0) ? slide_44914 : __m_latch_149);
			t_sample latch_44909 = __m_latch_149;
			t_sample mul_44911 = (y_45122 * latch_44909);
			t_sample dcblock_44910 = __m_dcblock_150(mul_44911);
			t_sample x_45141 = add_44618;
			t_sample q_45138 = gen_45102;
			t_sample bw_45142 = safediv(((int)452), q_45138);
			t_sample r_45139 = exp(((-bw_45142) * twopi_over_sr_45148));
			t_sample c_45146 = ((((int)2) * r_45139) * cos((((int)452) * twopi_over_sr_45148)));
			t_sample c_45137 = ((-r_45139) * r_45139);
			t_sample y_45140 = ((((((int)1) - r_45139) * (x_45141 - (r_45139 * m_x_112))) + (c_45146 * m_y_111)) + (c_45137 * m_y_110));
			m_y_110 = m_y_111;
			m_y_111 = y_45140;
			m_x_112 = m_x_113;
			m_x_113 = x_45141;
			t_sample x_44898 = in2;
			t_sample q_44890 = gen_45102;
			t_sample bw_44899 = safediv(((int)452), q_44890);
			t_sample r_44892 = exp(((-bw_44899) * twopi_over_sr_44901));
			t_sample c_44900 = ((((int)2) * r_44892) * cos((((int)452) * twopi_over_sr_44901)));
			t_sample c_44903 = ((-r_44892) * r_44892);
			t_sample y_44902 = ((((((int)1) - r_44892) * (x_44898 - (r_44892 * m_x_108))) + (c_44900 * m_y_107)) + (c_44903 * m_y_106));
			m_y_106 = m_y_107;
			m_y_107 = y_44902;
			m_x_108 = m_x_109;
			m_x_109 = x_44898;
			t_sample abs_44889 = fabs(y_44902);
			__m_slide_151 = fixdenorm((__m_slide_151 + (((abs_44889 > __m_slide_151) ? iup_152 : idown_153) * (abs_44889 - __m_slide_151))));
			t_sample slide_44888 = __m_slide_151;
			__m_latch_154 = ((rsub_44613 != 0) ? slide_44888 : __m_latch_154);
			t_sample latch_44883 = __m_latch_154;
			t_sample mul_44885 = (y_45140 * latch_44883);
			t_sample dcblock_44884 = __m_dcblock_155(mul_44885);
			t_sample x_45159 = add_44618;
			t_sample q_45156 = gen_45102;
			t_sample bw_45160 = safediv(((t_sample)569.5), q_45156);
			t_sample r_45157 = exp(((-bw_45160) * twopi_over_sr_45154));
			t_sample c_45162 = ((((int)2) * r_45157) * cos((((t_sample)569.5) * twopi_over_sr_45154)));
			t_sample c_45153 = ((-r_45157) * r_45157);
			t_sample y_45158 = ((((((int)1) - r_45157) * (x_45159 - (r_45157 * m_x_104))) + (c_45162 * m_y_103)) + (c_45153 * m_y_102));
			m_y_102 = m_y_103;
			m_y_103 = y_45158;
			m_x_104 = m_x_105;
			m_x_105 = x_45159;
			t_sample x_44872 = in2;
			t_sample q_44864 = gen_45102;
			t_sample bw_44873 = safediv(((t_sample)569.5), q_44864);
			t_sample r_44866 = exp(((-bw_44873) * twopi_over_sr_44875));
			t_sample c_44874 = ((((int)2) * r_44866) * cos((((t_sample)569.5) * twopi_over_sr_44875)));
			t_sample c_44877 = ((-r_44866) * r_44866);
			t_sample y_44876 = ((((((int)1) - r_44866) * (x_44872 - (r_44866 * m_x_100))) + (c_44874 * m_y_99)) + (c_44877 * m_y_98));
			m_y_98 = m_y_99;
			m_y_99 = y_44876;
			m_x_100 = m_x_101;
			m_x_101 = x_44872;
			t_sample abs_44863 = fabs(y_44876);
			__m_slide_156 = fixdenorm((__m_slide_156 + (((abs_44863 > __m_slide_156) ? iup_157 : idown_158) * (abs_44863 - __m_slide_156))));
			t_sample slide_44862 = __m_slide_156;
			__m_latch_159 = ((rsub_44613 != 0) ? slide_44862 : __m_latch_159);
			t_sample latch_44857 = __m_latch_159;
			t_sample mul_44859 = (y_45158 * latch_44857);
			t_sample dcblock_44858 = __m_dcblock_160(mul_44859);
			t_sample x_45177 = add_44618;
			t_sample q_45174 = gen_45102;
			t_sample bw_45178 = safediv(((t_sample)717.5), q_45174);
			t_sample r_45175 = exp(((-bw_45178) * twopi_over_sr_45172));
			t_sample c_45180 = ((((int)2) * r_45175) * cos((((t_sample)717.5) * twopi_over_sr_45172)));
			t_sample c_45171 = ((-r_45175) * r_45175);
			t_sample y_45176 = ((((((int)1) - r_45175) * (x_45177 - (r_45175 * m_x_96))) + (c_45180 * m_y_95)) + (c_45171 * m_y_94));
			m_y_94 = m_y_95;
			m_y_95 = y_45176;
			m_x_96 = m_x_97;
			m_x_97 = x_45177;
			t_sample x_44846 = in2;
			t_sample q_44838 = gen_45102;
			t_sample bw_44847 = safediv(((t_sample)717.5), q_44838);
			t_sample r_44840 = exp(((-bw_44847) * twopi_over_sr_44849));
			t_sample c_44848 = ((((int)2) * r_44840) * cos((((t_sample)717.5) * twopi_over_sr_44849)));
			t_sample c_44851 = ((-r_44840) * r_44840);
			t_sample y_44850 = ((((((int)1) - r_44840) * (x_44846 - (r_44840 * m_x_92))) + (c_44848 * m_y_91)) + (c_44851 * m_y_90));
			m_y_90 = m_y_91;
			m_y_91 = y_44850;
			m_x_92 = m_x_93;
			m_x_93 = x_44846;
			t_sample abs_44837 = fabs(y_44850);
			__m_slide_161 = fixdenorm((__m_slide_161 + (((abs_44837 > __m_slide_161) ? iup_162 : idown_163) * (abs_44837 - __m_slide_161))));
			t_sample slide_44836 = __m_slide_161;
			__m_latch_164 = ((rsub_44613 != 0) ? slide_44836 : __m_latch_164);
			t_sample latch_44831 = __m_latch_164;
			t_sample mul_44833 = (y_45176 * latch_44831);
			t_sample dcblock_44832 = __m_dcblock_165(mul_44833);
			t_sample x_45196 = add_44618;
			t_sample q_45193 = gen_45102;
			t_sample bw_45197 = safediv(((int)904), q_45193);
			t_sample r_45194 = exp(((-bw_45197) * twopi_over_sr_45191));
			t_sample c_45198 = ((((int)2) * r_45194) * cos((((int)904) * twopi_over_sr_45191)));
			t_sample c_45189 = ((-r_45194) * r_45194);
			t_sample y_45195 = ((((((int)1) - r_45194) * (x_45196 - (r_45194 * m_x_88))) + (c_45198 * m_y_87)) + (c_45189 * m_y_86));
			m_y_86 = m_y_87;
			m_y_87 = y_45195;
			m_x_88 = m_x_89;
			m_x_89 = x_45196;
			t_sample x_44820 = in2;
			t_sample q_44812 = gen_45102;
			t_sample bw_44821 = safediv(((int)904), q_44812);
			t_sample r_44814 = exp(((-bw_44821) * twopi_over_sr_44823));
			t_sample c_44822 = ((((int)2) * r_44814) * cos((((int)904) * twopi_over_sr_44823)));
			t_sample c_44825 = ((-r_44814) * r_44814);
			t_sample y_44824 = ((((((int)1) - r_44814) * (x_44820 - (r_44814 * m_x_84))) + (c_44822 * m_y_83)) + (c_44825 * m_y_82));
			m_y_82 = m_y_83;
			m_y_83 = y_44824;
			m_x_84 = m_x_85;
			m_x_85 = x_44820;
			t_sample abs_44811 = fabs(y_44824);
			__m_slide_166 = fixdenorm((__m_slide_166 + (((abs_44811 > __m_slide_166) ? iup_167 : idown_168) * (abs_44811 - __m_slide_166))));
			t_sample slide_44810 = __m_slide_166;
			__m_latch_169 = ((rsub_44613 != 0) ? slide_44810 : __m_latch_169);
			t_sample latch_44805 = __m_latch_169;
			t_sample mul_44807 = (y_45195 * latch_44805);
			t_sample dcblock_44806 = __m_dcblock_170(mul_44807);
			t_sample x_45213 = add_44618;
			t_sample q_45210 = gen_45102;
			t_sample bw_45217 = safediv(((int)1139), q_45210);
			t_sample r_45211 = exp(((-bw_45217) * twopi_over_sr_45207));
			t_sample c_45214 = ((((int)2) * r_45211) * cos((((int)1139) * twopi_over_sr_45207)));
			t_sample c_45218 = ((-r_45211) * r_45211);
			t_sample y_45212 = ((((((int)1) - r_45211) * (x_45213 - (r_45211 * m_x_80))) + (c_45214 * m_y_79)) + (c_45218 * m_y_78));
			m_y_78 = m_y_79;
			m_y_79 = y_45212;
			m_x_80 = m_x_81;
			m_x_81 = x_45213;
			t_sample x_44794 = in2;
			t_sample q_44786 = gen_45102;
			t_sample bw_44795 = safediv(((int)1139), q_44786);
			t_sample r_44788 = exp(((-bw_44795) * twopi_over_sr_44797));
			t_sample c_44796 = ((((int)2) * r_44788) * cos((((int)1139) * twopi_over_sr_44797)));
			t_sample c_44799 = ((-r_44788) * r_44788);
			t_sample y_44798 = ((((((int)1) - r_44788) * (x_44794 - (r_44788 * m_x_76))) + (c_44796 * m_y_75)) + (c_44799 * m_y_74));
			m_y_74 = m_y_75;
			m_y_75 = y_44798;
			m_x_76 = m_x_77;
			m_x_77 = x_44794;
			t_sample abs_44785 = fabs(y_44798);
			__m_slide_171 = fixdenorm((__m_slide_171 + (((abs_44785 > __m_slide_171) ? iup_172 : idown_173) * (abs_44785 - __m_slide_171))));
			t_sample slide_44784 = __m_slide_171;
			__m_latch_174 = ((rsub_44613 != 0) ? slide_44784 : __m_latch_174);
			t_sample latch_44779 = __m_latch_174;
			t_sample mul_44781 = (y_45212 * latch_44779);
			t_sample dcblock_44780 = __m_dcblock_175(mul_44781);
			t_sample x_45230 = add_44618;
			t_sample q_45227 = gen_45102;
			t_sample bw_45234 = safediv(((int)1435), q_45227);
			t_sample r_45228 = exp(((-bw_45234) * twopi_over_sr_45225));
			t_sample c_45231 = ((((int)2) * r_45228) * cos((((int)1435) * twopi_over_sr_45225)));
			t_sample c_45235 = ((-r_45228) * r_45228);
			t_sample y_45229 = ((((((int)1) - r_45228) * (x_45230 - (r_45228 * m_x_72))) + (c_45231 * m_y_71)) + (c_45235 * m_y_70));
			m_y_70 = m_y_71;
			m_y_71 = y_45229;
			m_x_72 = m_x_73;
			m_x_73 = x_45230;
			t_sample x_44768 = in2;
			t_sample q_44760 = gen_45102;
			t_sample bw_44769 = safediv(((int)1435), q_44760);
			t_sample r_44762 = exp(((-bw_44769) * twopi_over_sr_44771));
			t_sample c_44770 = ((((int)2) * r_44762) * cos((((int)1435) * twopi_over_sr_44771)));
			t_sample c_44773 = ((-r_44762) * r_44762);
			t_sample y_44772 = ((((((int)1) - r_44762) * (x_44768 - (r_44762 * m_x_68))) + (c_44770 * m_y_67)) + (c_44773 * m_y_66));
			m_y_66 = m_y_67;
			m_y_67 = y_44772;
			m_x_68 = m_x_69;
			m_x_69 = x_44768;
			t_sample abs_44759 = fabs(y_44772);
			__m_slide_176 = fixdenorm((__m_slide_176 + (((abs_44759 > __m_slide_176) ? iup_177 : idown_178) * (abs_44759 - __m_slide_176))));
			t_sample slide_44758 = __m_slide_176;
			__m_latch_179 = ((rsub_44613 != 0) ? slide_44758 : __m_latch_179);
			t_sample latch_44753 = __m_latch_179;
			t_sample mul_44755 = (y_45229 * latch_44753);
			t_sample dcblock_44754 = __m_dcblock_180(mul_44755);
			t_sample x_45248 = add_44618;
			t_sample q_45245 = gen_45102;
			t_sample bw_45251 = safediv(((int)1808), q_45245);
			t_sample r_45246 = exp(((-bw_45251) * twopi_over_sr_45243));
			t_sample c_45255 = ((((int)2) * r_45246) * cos((((int)1808) * twopi_over_sr_45243)));
			t_sample c_45252 = ((-r_45246) * r_45246);
			t_sample y_45247 = ((((((int)1) - r_45246) * (x_45248 - (r_45246 * m_x_64))) + (c_45255 * m_y_63)) + (c_45252 * m_y_62));
			m_y_62 = m_y_63;
			m_y_63 = y_45247;
			m_x_64 = m_x_65;
			m_x_65 = x_45248;
			t_sample x_44742 = in2;
			t_sample q_44734 = gen_45102;
			t_sample bw_44743 = safediv(((int)1808), q_44734);
			t_sample r_44736 = exp(((-bw_44743) * twopi_over_sr_44745));
			t_sample c_44744 = ((((int)2) * r_44736) * cos((((int)1808) * twopi_over_sr_44745)));
			t_sample c_44747 = ((-r_44736) * r_44736);
			t_sample y_44746 = ((((((int)1) - r_44736) * (x_44742 - (r_44736 * m_x_60))) + (c_44744 * m_y_59)) + (c_44747 * m_y_58));
			m_y_58 = m_y_59;
			m_y_59 = y_44746;
			m_x_60 = m_x_61;
			m_x_61 = x_44742;
			t_sample abs_44733 = fabs(y_44746);
			__m_slide_181 = fixdenorm((__m_slide_181 + (((abs_44733 > __m_slide_181) ? iup_182 : idown_183) * (abs_44733 - __m_slide_181))));
			t_sample slide_44732 = __m_slide_181;
			__m_latch_184 = ((rsub_44613 != 0) ? slide_44732 : __m_latch_184);
			t_sample latch_44727 = __m_latch_184;
			t_sample mul_44729 = (y_45247 * latch_44727);
			t_sample dcblock_44728 = __m_dcblock_185(mul_44729);
			t_sample x_45267 = add_44618;
			t_sample q_45264 = gen_45102;
			t_sample bw_45270 = safediv(((int)2260), q_45264);
			t_sample r_45265 = exp(((-bw_45270) * twopi_over_sr_45261));
			t_sample c_45273 = ((((int)2) * r_45265) * cos((((int)2260) * twopi_over_sr_45261)));
			t_sample c_45272 = ((-r_45265) * r_45265);
			t_sample y_45266 = ((((((int)1) - r_45265) * (x_45267 - (r_45265 * m_x_56))) + (c_45273 * m_y_55)) + (c_45272 * m_y_54));
			m_y_54 = m_y_55;
			m_y_55 = y_45266;
			m_x_56 = m_x_57;
			m_x_57 = x_45267;
			t_sample x_44716 = in2;
			t_sample q_44708 = gen_45102;
			t_sample bw_44717 = safediv(((int)2260), q_44708);
			t_sample r_44710 = exp(((-bw_44717) * twopi_over_sr_44719));
			t_sample c_44718 = ((((int)2) * r_44710) * cos((((int)2260) * twopi_over_sr_44719)));
			t_sample c_44721 = ((-r_44710) * r_44710);
			t_sample y_44720 = ((((((int)1) - r_44710) * (x_44716 - (r_44710 * m_x_52))) + (c_44718 * m_y_51)) + (c_44721 * m_y_50));
			m_y_50 = m_y_51;
			m_y_51 = y_44720;
			m_x_52 = m_x_53;
			m_x_53 = x_44716;
			t_sample abs_44707 = fabs(y_44720);
			__m_slide_186 = fixdenorm((__m_slide_186 + (((abs_44707 > __m_slide_186) ? iup_187 : idown_188) * (abs_44707 - __m_slide_186))));
			t_sample slide_44706 = __m_slide_186;
			__m_latch_189 = ((rsub_44613 != 0) ? slide_44706 : __m_latch_189);
			t_sample latch_44701 = __m_latch_189;
			t_sample mul_44703 = (y_45266 * latch_44701);
			t_sample dcblock_44702 = __m_dcblock_190(mul_44703);
			t_sample x_45285 = add_44618;
			t_sample q_45282 = gen_45102;
			t_sample bw_45290 = safediv(((int)2852), q_45282);
			t_sample r_45283 = exp(((-bw_45290) * twopi_over_sr_45280));
			t_sample c_45286 = ((((int)2) * r_45283) * cos((((int)2852) * twopi_over_sr_45280)));
			t_sample c_45279 = ((-r_45283) * r_45283);
			t_sample y_45284 = ((((((int)1) - r_45283) * (x_45285 - (r_45283 * m_x_48))) + (c_45286 * m_y_47)) + (c_45279 * m_y_46));
			m_y_46 = m_y_47;
			m_y_47 = y_45284;
			m_x_48 = m_x_49;
			m_x_49 = x_45285;
			t_sample x_44690 = in2;
			t_sample q_44682 = gen_45102;
			t_sample bw_44691 = safediv(((int)2852), q_44682);
			t_sample r_44684 = exp(((-bw_44691) * twopi_over_sr_44693));
			t_sample c_44692 = ((((int)2) * r_44684) * cos((((int)2852) * twopi_over_sr_44693)));
			t_sample c_44695 = ((-r_44684) * r_44684);
			t_sample y_44694 = ((((((int)1) - r_44684) * (x_44690 - (r_44684 * m_x_44))) + (c_44692 * m_y_43)) + (c_44695 * m_y_42));
			m_y_42 = m_y_43;
			m_y_43 = y_44694;
			m_x_44 = m_x_45;
			m_x_45 = x_44690;
			t_sample abs_44681 = fabs(y_44694);
			__m_slide_191 = fixdenorm((__m_slide_191 + (((abs_44681 > __m_slide_191) ? iup_192 : idown_193) * (abs_44681 - __m_slide_191))));
			t_sample slide_44680 = __m_slide_191;
			__m_latch_194 = ((rsub_44613 != 0) ? slide_44680 : __m_latch_194);
			t_sample latch_44675 = __m_latch_194;
			t_sample mul_44677 = (y_45284 * latch_44675);
			t_sample dcblock_44676 = __m_dcblock_195(mul_44677);
			t_sample x_45305 = add_44618;
			t_sample q_45302 = gen_45102;
			t_sample bw_45308 = safediv(((int)3616), q_45302);
			t_sample r_45303 = exp(((-bw_45308) * twopi_over_sr_45299));
			t_sample c_45298 = ((((int)2) * r_45303) * cos((((int)3616) * twopi_over_sr_45299)));
			t_sample c_45297 = ((-r_45303) * r_45303);
			t_sample y_45304 = ((((((int)1) - r_45303) * (x_45305 - (r_45303 * m_x_40))) + (c_45298 * m_y_39)) + (c_45297 * m_y_38));
			m_y_38 = m_y_39;
			m_y_39 = y_45304;
			m_x_40 = m_x_41;
			m_x_41 = x_45305;
			t_sample x_44664 = in2;
			t_sample q_44656 = gen_45102;
			t_sample bw_44665 = safediv(((int)3616), q_44656);
			t_sample r_44658 = exp(((-bw_44665) * twopi_over_sr_44667));
			t_sample c_44666 = ((((int)2) * r_44658) * cos((((int)3616) * twopi_over_sr_44667)));
			t_sample c_44669 = ((-r_44658) * r_44658);
			t_sample y_44668 = ((((((int)1) - r_44658) * (x_44664 - (r_44658 * m_x_36))) + (c_44666 * m_y_35)) + (c_44669 * m_y_34));
			m_y_34 = m_y_35;
			m_y_35 = y_44668;
			m_x_36 = m_x_37;
			m_x_37 = x_44664;
			t_sample abs_44655 = fabs(y_44668);
			__m_slide_196 = fixdenorm((__m_slide_196 + (((abs_44655 > __m_slide_196) ? iup_197 : idown_198) * (abs_44655 - __m_slide_196))));
			t_sample slide_44654 = __m_slide_196;
			__m_latch_199 = ((rsub_44613 != 0) ? slide_44654 : __m_latch_199);
			t_sample latch_44649 = __m_latch_199;
			t_sample mul_44651 = (y_45304 * latch_44649);
			t_sample dcblock_44650 = __m_dcblock_200(mul_44651);
			t_sample x_45322 = add_44618;
			t_sample q_45319 = gen_45102;
			t_sample bw_45326 = safediv(((int)4556), q_45319);
			t_sample r_45320 = exp(((-bw_45326) * twopi_over_sr_45316));
			t_sample c_45323 = ((((int)2) * r_45320) * cos((((int)4556) * twopi_over_sr_45316)));
			t_sample c_45315 = ((-r_45320) * r_45320);
			t_sample y_45321 = ((((((int)1) - r_45320) * (x_45322 - (r_45320 * m_x_32))) + (c_45323 * m_y_31)) + (c_45315 * m_y_30));
			m_y_30 = m_y_31;
			m_y_31 = y_45321;
			m_x_32 = m_x_33;
			m_x_33 = x_45322;
			t_sample x_44638 = in2;
			t_sample q_44630 = gen_45102;
			t_sample bw_44639 = safediv(((int)4556), q_44630);
			t_sample r_44632 = exp(((-bw_44639) * twopi_over_sr_44641));
			t_sample c_44640 = ((((int)2) * r_44632) * cos((((int)4556) * twopi_over_sr_44641)));
			t_sample c_44643 = ((-r_44632) * r_44632);
			t_sample y_44642 = ((((((int)1) - r_44632) * (x_44638 - (r_44632 * m_x_28))) + (c_44640 * m_y_27)) + (c_44643 * m_y_26));
			m_y_26 = m_y_27;
			m_y_27 = y_44642;
			m_x_28 = m_x_29;
			m_x_29 = x_44638;
			t_sample abs_44629 = fabs(y_44642);
			__m_slide_201 = fixdenorm((__m_slide_201 + (((abs_44629 > __m_slide_201) ? iup_202 : idown_203) * (abs_44629 - __m_slide_201))));
			t_sample slide_44628 = __m_slide_201;
			__m_latch_204 = ((rsub_44613 != 0) ? slide_44628 : __m_latch_204);
			t_sample latch_44621 = __m_latch_204;
			t_sample mul_44623 = (y_45321 * latch_44621);
			t_sample dcblock_44622 = __m_dcblock_205(mul_44623);
			t_sample x_45337 = add_44618;
			t_sample q_45334 = gen_45102;
			t_sample bw_45343 = safediv(((t_sample)104.5), q_45334);
			t_sample r_45335 = exp(((-bw_45343) * twopi_over_sr_45333));
			t_sample c_45341 = ((((int)2) * r_45335) * cos((((t_sample)104.5) * twopi_over_sr_45333)));
			t_sample c_45344 = ((-r_45335) * r_45335);
			t_sample y_45336 = ((((((int)1) - r_45335) * (x_45337 - (r_45335 * m_x_24))) + (c_45341 * m_y_23)) + (c_45344 * m_y_22));
			m_y_22 = m_y_23;
			m_y_23 = y_45336;
			m_x_24 = m_x_25;
			m_x_25 = x_45337;
			t_sample x_45072 = in2;
			t_sample q_45064 = gen_45102;
			t_sample bw_45073 = safediv(((t_sample)104.5), q_45064);
			t_sample r_45066 = exp(((-bw_45073) * twopi_over_sr_45075));
			t_sample c_45074 = ((((int)2) * r_45066) * cos((((t_sample)104.5) * twopi_over_sr_45075)));
			t_sample c_45077 = ((-r_45066) * r_45066);
			t_sample y_45076 = ((((((int)1) - r_45066) * (x_45072 - (r_45066 * m_x_20))) + (c_45074 * m_y_19)) + (c_45077 * m_y_18));
			m_y_18 = m_y_19;
			m_y_19 = y_45076;
			m_x_20 = m_x_21;
			m_x_21 = x_45072;
			t_sample abs_45063 = fabs(y_45076);
			__m_slide_206 = fixdenorm((__m_slide_206 + (((abs_45063 > __m_slide_206) ? iup_207 : idown_208) * (abs_45063 - __m_slide_206))));
			t_sample slide_45062 = __m_slide_206;
			__m_latch_209 = ((rsub_44613 != 0) ? slide_45062 : __m_latch_209);
			t_sample latch_45057 = __m_latch_209;
			t_sample mul_45059 = (y_45336 * latch_45057);
			t_sample dcblock_45058 = __m_dcblock_210(mul_45059);
			t_sample x_45355 = add_44618;
			t_sample q_45352 = gen_45102;
			t_sample bw_45361 = safediv(((t_sample)179.5), q_45352);
			t_sample r_45353 = exp(((-bw_45361) * twopi_over_sr_45351));
			t_sample c_45358 = ((((int)2) * r_45353) * cos((((t_sample)179.5) * twopi_over_sr_45351)));
			t_sample c_45360 = ((-r_45353) * r_45353);
			t_sample y_45354 = ((((((int)1) - r_45353) * (x_45355 - (r_45353 * m_x_16))) + (c_45358 * m_y_15)) + (c_45360 * m_y_14));
			m_y_14 = m_y_15;
			m_y_15 = y_45354;
			m_x_16 = m_x_17;
			m_x_17 = x_45355;
			t_sample x_45002 = in2;
			t_sample q_44994 = gen_45102;
			t_sample bw_45003 = safediv(((t_sample)179.5), q_44994);
			t_sample r_44996 = exp(((-bw_45003) * twopi_over_sr_45005));
			t_sample c_45004 = ((((int)2) * r_44996) * cos((((t_sample)179.5) * twopi_over_sr_45005)));
			t_sample c_45007 = ((-r_44996) * r_44996);
			t_sample y_45006 = ((((((int)1) - r_44996) * (x_45002 - (r_44996 * m_x_12))) + (c_45004 * m_y_11)) + (c_45007 * m_y_10));
			m_y_10 = m_y_11;
			m_y_11 = y_45006;
			m_x_12 = m_x_13;
			m_x_13 = x_45002;
			t_sample abs_44993 = fabs(y_45006);
			__m_slide_211 = fixdenorm((__m_slide_211 + (((abs_44993 > __m_slide_211) ? iup_212 : idown_213) * (abs_44993 - __m_slide_211))));
			t_sample slide_44992 = __m_slide_211;
			__m_latch_214 = ((rsub_44613 != 0) ? slide_44992 : __m_latch_214);
			t_sample latch_44987 = __m_latch_214;
			t_sample mul_44989 = (y_45354 * latch_44987);
			t_sample dcblock_44988 = __m_dcblock_215(mul_44989);
			t_sample x_45373 = add_44618;
			t_sample q_45370 = gen_45102;
			t_sample bw_45382 = safediv(((int)226), q_45370);
			t_sample r_45371 = exp(((-bw_45382) * twopi_over_sr_45369));
			t_sample c_45378 = ((((int)2) * r_45371) * cos((((int)226) * twopi_over_sr_45369)));
			t_sample c_45381 = ((-r_45371) * r_45371);
			t_sample y_45372 = ((((((int)1) - r_45371) * (x_45373 - (r_45371 * m_x_8))) + (c_45378 * m_y_7)) + (c_45381 * m_y_6));
			m_y_6 = m_y_7;
			m_y_7 = y_45372;
			m_x_8 = m_x_9;
			m_x_9 = x_45373;
			t_sample x_44976 = in2;
			t_sample q_44968 = gen_45102;
			t_sample bw_44977 = safediv(((int)226), q_44968);
			t_sample r_44970 = exp(((-bw_44977) * twopi_over_sr_44979));
			t_sample c_44978 = ((((int)2) * r_44970) * cos((((int)226) * twopi_over_sr_44979)));
			t_sample c_44981 = ((-r_44970) * r_44970);
			t_sample y_44980 = ((((((int)1) - r_44970) * (x_44976 - (r_44970 * m_x_4))) + (c_44978 * m_y_3)) + (c_44981 * m_y_2));
			m_y_2 = m_y_3;
			m_y_3 = y_44980;
			m_x_4 = m_x_5;
			m_x_5 = x_44976;
			t_sample abs_44967 = fabs(y_44980);
			__m_slide_216 = fixdenorm((__m_slide_216 + (((abs_44967 > __m_slide_216) ? iup_217 : idown_218) * (abs_44967 - __m_slide_216))));
			t_sample slide_44966 = __m_slide_216;
			__m_latch_219 = ((rsub_44613 != 0) ? slide_44966 : __m_latch_219);
			t_sample latch_44961 = __m_latch_219;
			t_sample mul_44963 = (y_45372 * latch_44961);
			t_sample dcblock_44962 = __m_dcblock_220(mul_44963);
			t_sample mul_45103 = ((((((((((((((((dcblock_44962 + dcblock_44988) + dcblock_45058) + dcblock_44622) + dcblock_44650) + dcblock_44676) + dcblock_44702) + dcblock_44728) + dcblock_44754) + dcblock_44780) + dcblock_44806) + dcblock_44832) + dcblock_44858) + dcblock_44884) + dcblock_44910) + dcblock_44936) * m_knob4_gain_138);
			t_sample add_45115 = (mul_45103 + gate_45106);
			t_sample out2 = add_45115;
			t_sample add_45116 = (mul_45103 + gate_45106);
			t_sample out1 = add_45116;
			t_sample history_44617_next_45387 = fixdenorm(mul_44615);
			m_history_133 = history_45110_next_45112;
			m_history_132 = history_45096_next_45099;
			m_history_130 = history_45091_next_45101;
			m_history_131 = history_45093_next_45100;
			m_history_1 = history_44617_next_45387;
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
	inline void set_sw5(t_param _value) {
		m_sw_134 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_noise(t_param _value) {
		m_knob5_noise_135 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_res(t_param _value) {
		m_knob3_res_136 = (_value < 15 ? 15 : (_value > 50 ? 50 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_137 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_gain(t_param _value) {
		m_knob4_gain_138 = (_value < 1 ? 1 : (_value > 20 ? 20 : _value));
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
		case 0: *value = self->m_knob3_res_136; break;
		case 1: *value = self->m_knob4_gain_138; break;
		case 2: *value = self->m_knob5_noise_135; break;
		case 3: *value = self->m_sw_137; break;
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
	// initialize parameter 1 ("m_knob4_gain_138")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_gain";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_gain_138;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 20;
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
	// initialize parameter 3 ("m_sw_137")
	pi = self->__commonstate.params + 3;
	pi->name = "sw1";
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
	// initialize parameter 4 ("m_sw_134")
	pi = self->__commonstate.params + 4;
	pi->name = "sw5";
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
