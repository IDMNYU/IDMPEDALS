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
		t_sample rsub_5821 = (((int)1) - m_sw_134);
		t_sample mstosamps_6221 = (((int)2) * (samplerate * 0.001));
		t_sample mstosamps_6312 = (((int)20) * (samplerate * 0.001));
		t_sample twopi_over_sr = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_6162 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_142 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_143 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_6899 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_6135 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_147 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_148 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_6917 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_6109 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_152 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_153 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_6924 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_6083 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_157 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_158 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_6941 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_6057 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_162 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_163 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_6961 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_6031 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_167 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_168 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_6989 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_6005 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_172 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_173 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_7006 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_5979 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_177 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_178 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_7025 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_5953 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_182 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_183 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_7043 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_5927 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_187 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_188 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_7061 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_5901 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_192 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_193 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_7066 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_5875 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_197 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_198 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_7084 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_5849 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_202 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_203 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_7113 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_6283 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_207 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_208 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_7131 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_6213 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_212 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_213 = (1 / maximum(1, abs(mstosamps_6312)));
		t_sample twopi_over_sr_7150 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample twopi_over_sr_6187 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_217 = (1 / maximum(1, abs(mstosamps_6221)));
		t_sample idown_218 = (1 / maximum(1, abs(mstosamps_6312)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_6319 = __m_sah_139(m_history_133, m_sw_137, ((int)0));
			t_sample gen_6321 = sah_6319;
			t_sample rsub_6317 = (((int)1) - sah_6319);
			t_sample history_6318_next_6320 = fixdenorm(rsub_6317);
			t_sample out3 = gen_6321;
			t_sample add_6322 = (gen_6321 + ((int)1));
			t_sample choice_140 = int(add_6322);
			t_sample gate_6314 = (((choice_140 >= 1) && (choice_140 < 2)) ? in1 : 0);
			t_sample gate_6315 = ((choice_140 >= 2) ? in1 : 0);
			t_sample noise_5828 = noise();
			t_sample mul_5822 = (noise_5828 * ((t_sample)0.5));
			t_sample add_5824 = (mul_5822 + m_history_1);
			t_sample mul_5823 = (add_5824 * ((t_sample)0.5));
			t_sample mix_7163 = (m_history_132 + (((t_sample)0.0019634941468452) * (m_knob3_res_136 - m_history_132)));
			t_sample mix_6302 = mix_7163;
			t_sample mix_7164 = (m_history_131 + (((t_sample)0.0019634941468452) * (mix_6302 - m_history_131)));
			t_sample mix_6300 = mix_7164;
			t_sample mix_7165 = (m_history_130 + (((t_sample)0.0019634941468452) * (mix_6300 - m_history_130)));
			t_sample mix_6298 = mix_7165;
			t_sample gen_6310 = mix_6298;
			t_sample history_6304_next_6307 = fixdenorm(mix_6302);
			t_sample history_6301_next_6308 = fixdenorm(mix_6300);
			t_sample history_6299_next_6309 = fixdenorm(mix_6298);
			t_sample mul_5827 = (add_5824 * m_knob5_noise_135);
			t_sample add_5826 = (gate_6315 + mul_5827);
			t_sample x = add_5826;
			t_sample q = gen_6310;
			t_sample bw = safediv(((t_sample)284.5), q);
			t_sample r = exp(((-bw) * twopi_over_sr));
			t_sample c1 = ((((int)2) * r) * cos((((t_sample)284.5) * twopi_over_sr)));
			t_sample c2 = ((-r) * r);
			t_sample y = ((((((int)1) - r) * (x - (r * m_x_128))) + (c1 * m_y_127)) + (c2 * m_y_126));
			m_y_126 = m_y_127;
			m_y_127 = y;
			m_x_128 = m_x_129;
			m_x_129 = x;
			t_sample x_6158 = in2;
			t_sample q_6150 = gen_6310;
			t_sample bw_6159 = safediv(((t_sample)284.5), q_6150);
			t_sample r_6152 = exp(((-bw_6159) * twopi_over_sr_6162));
			t_sample c_6161 = ((((int)2) * r_6152) * cos((((t_sample)284.5) * twopi_over_sr_6162)));
			t_sample c_6163 = ((-r_6152) * r_6152);
			t_sample y_6160 = ((((((int)1) - r_6152) * (x_6158 - (r_6152 * m_x_124))) + (c_6161 * m_y_123)) + (c_6163 * m_y_122));
			m_y_122 = m_y_123;
			m_y_123 = y_6160;
			m_x_124 = m_x_125;
			m_x_125 = x_6158;
			t_sample abs_6149 = fabs(y_6160);
			__m_slide_141 = fixdenorm((__m_slide_141 + (((abs_6149 > __m_slide_141) ? iup_142 : idown_143) * (abs_6149 - __m_slide_141))));
			t_sample slide_6148 = __m_slide_141;
			__m_latch_144 = ((rsub_5821 != 0) ? slide_6148 : __m_latch_144);
			t_sample latch_6143 = __m_latch_144;
			t_sample mul_6145 = (y * latch_6143);
			t_sample dcblock_6144 = __m_dcblock_145(mul_6145);
			t_sample x_6891 = add_5826;
			t_sample q_6889 = gen_6310;
			t_sample bw_6892 = safediv(((t_sample)358.5), q_6889);
			t_sample r_6890 = exp(((-bw_6892) * twopi_over_sr_6899));
			t_sample c_6898 = ((((int)2) * r_6890) * cos((((t_sample)358.5) * twopi_over_sr_6899)));
			t_sample c_6888 = ((-r_6890) * r_6890);
			t_sample y_6897 = ((((((int)1) - r_6890) * (x_6891 - (r_6890 * m_x_120))) + (c_6898 * m_y_119)) + (c_6888 * m_y_118));
			m_y_118 = m_y_119;
			m_y_119 = y_6897;
			m_x_120 = m_x_121;
			m_x_121 = x_6891;
			t_sample x_6132 = in2;
			t_sample q_6124 = gen_6310;
			t_sample bw_6133 = safediv(((t_sample)358.5), q_6124);
			t_sample r_6126 = exp(((-bw_6133) * twopi_over_sr_6135));
			t_sample c_6134 = ((((int)2) * r_6126) * cos((((t_sample)358.5) * twopi_over_sr_6135)));
			t_sample c_6137 = ((-r_6126) * r_6126);
			t_sample y_6136 = ((((((int)1) - r_6126) * (x_6132 - (r_6126 * m_x_116))) + (c_6134 * m_y_115)) + (c_6137 * m_y_114));
			m_y_114 = m_y_115;
			m_y_115 = y_6136;
			m_x_116 = m_x_117;
			m_x_117 = x_6132;
			t_sample abs_6123 = fabs(y_6136);
			__m_slide_146 = fixdenorm((__m_slide_146 + (((abs_6123 > __m_slide_146) ? iup_147 : idown_148) * (abs_6123 - __m_slide_146))));
			t_sample slide_6122 = __m_slide_146;
			__m_latch_149 = ((rsub_5821 != 0) ? slide_6122 : __m_latch_149);
			t_sample latch_6117 = __m_latch_149;
			t_sample mul_6119 = (y_6897 * latch_6117);
			t_sample dcblock_6118 = __m_dcblock_150(mul_6119);
			t_sample x_6912 = add_5826;
			t_sample q_6906 = gen_6310;
			t_sample bw_6908 = safediv(((int)452), q_6906);
			t_sample r_6907 = exp(((-bw_6908) * twopi_over_sr_6917));
			t_sample c_6913 = ((((int)2) * r_6907) * cos((((int)452) * twopi_over_sr_6917)));
			t_sample c_6905 = ((-r_6907) * r_6907);
			t_sample y_6911 = ((((((int)1) - r_6907) * (x_6912 - (r_6907 * m_x_112))) + (c_6913 * m_y_111)) + (c_6905 * m_y_110));
			m_y_110 = m_y_111;
			m_y_111 = y_6911;
			m_x_112 = m_x_113;
			m_x_113 = x_6912;
			t_sample x_6106 = in2;
			t_sample q_6098 = gen_6310;
			t_sample bw_6107 = safediv(((int)452), q_6098);
			t_sample r_6100 = exp(((-bw_6107) * twopi_over_sr_6109));
			t_sample c_6108 = ((((int)2) * r_6100) * cos((((int)452) * twopi_over_sr_6109)));
			t_sample c_6111 = ((-r_6100) * r_6100);
			t_sample y_6110 = ((((((int)1) - r_6100) * (x_6106 - (r_6100 * m_x_108))) + (c_6108 * m_y_107)) + (c_6111 * m_y_106));
			m_y_106 = m_y_107;
			m_y_107 = y_6110;
			m_x_108 = m_x_109;
			m_x_109 = x_6106;
			t_sample abs_6097 = fabs(y_6110);
			__m_slide_151 = fixdenorm((__m_slide_151 + (((abs_6097 > __m_slide_151) ? iup_152 : idown_153) * (abs_6097 - __m_slide_151))));
			t_sample slide_6096 = __m_slide_151;
			__m_latch_154 = ((rsub_5821 != 0) ? slide_6096 : __m_latch_154);
			t_sample latch_6091 = __m_latch_154;
			t_sample mul_6093 = (y_6911 * latch_6091);
			t_sample dcblock_6092 = __m_dcblock_155(mul_6093);
			t_sample x_6930 = add_5826;
			t_sample q_6927 = gen_6310;
			t_sample bw_6931 = safediv(((t_sample)569.5), q_6927);
			t_sample r_6928 = exp(((-bw_6931) * twopi_over_sr_6924));
			t_sample c_6933 = ((((int)2) * r_6928) * cos((((t_sample)569.5) * twopi_over_sr_6924)));
			t_sample c_6922 = ((-r_6928) * r_6928);
			t_sample y_6929 = ((((((int)1) - r_6928) * (x_6930 - (r_6928 * m_x_104))) + (c_6933 * m_y_103)) + (c_6922 * m_y_102));
			m_y_102 = m_y_103;
			m_y_103 = y_6929;
			m_x_104 = m_x_105;
			m_x_105 = x_6930;
			t_sample x_6080 = in2;
			t_sample q_6072 = gen_6310;
			t_sample bw_6081 = safediv(((t_sample)569.5), q_6072);
			t_sample r_6074 = exp(((-bw_6081) * twopi_over_sr_6083));
			t_sample c_6082 = ((((int)2) * r_6074) * cos((((t_sample)569.5) * twopi_over_sr_6083)));
			t_sample c_6085 = ((-r_6074) * r_6074);
			t_sample y_6084 = ((((((int)1) - r_6074) * (x_6080 - (r_6074 * m_x_100))) + (c_6082 * m_y_99)) + (c_6085 * m_y_98));
			m_y_98 = m_y_99;
			m_y_99 = y_6084;
			m_x_100 = m_x_101;
			m_x_101 = x_6080;
			t_sample abs_6071 = fabs(y_6084);
			__m_slide_156 = fixdenorm((__m_slide_156 + (((abs_6071 > __m_slide_156) ? iup_157 : idown_158) * (abs_6071 - __m_slide_156))));
			t_sample slide_6070 = __m_slide_156;
			__m_latch_159 = ((rsub_5821 != 0) ? slide_6070 : __m_latch_159);
			t_sample latch_6065 = __m_latch_159;
			t_sample mul_6067 = (y_6929 * latch_6065);
			t_sample dcblock_6066 = __m_dcblock_160(mul_6067);
			t_sample x_6946 = add_5826;
			t_sample q_6943 = gen_6310;
			t_sample bw_6947 = safediv(((t_sample)717.5), q_6943);
			t_sample r_6944 = exp(((-bw_6947) * twopi_over_sr_6941));
			t_sample c_6949 = ((((int)2) * r_6944) * cos((((t_sample)717.5) * twopi_over_sr_6941)));
			t_sample c_6940 = ((-r_6944) * r_6944);
			t_sample y_6945 = ((((((int)1) - r_6944) * (x_6946 - (r_6944 * m_x_96))) + (c_6949 * m_y_95)) + (c_6940 * m_y_94));
			m_y_94 = m_y_95;
			m_y_95 = y_6945;
			m_x_96 = m_x_97;
			m_x_97 = x_6946;
			t_sample x_6054 = in2;
			t_sample q_6046 = gen_6310;
			t_sample bw_6055 = safediv(((t_sample)717.5), q_6046);
			t_sample r_6048 = exp(((-bw_6055) * twopi_over_sr_6057));
			t_sample c_6056 = ((((int)2) * r_6048) * cos((((t_sample)717.5) * twopi_over_sr_6057)));
			t_sample c_6059 = ((-r_6048) * r_6048);
			t_sample y_6058 = ((((((int)1) - r_6048) * (x_6054 - (r_6048 * m_x_92))) + (c_6056 * m_y_91)) + (c_6059 * m_y_90));
			m_y_90 = m_y_91;
			m_y_91 = y_6058;
			m_x_92 = m_x_93;
			m_x_93 = x_6054;
			t_sample abs_6045 = fabs(y_6058);
			__m_slide_161 = fixdenorm((__m_slide_161 + (((abs_6045 > __m_slide_161) ? iup_162 : idown_163) * (abs_6045 - __m_slide_161))));
			t_sample slide_6044 = __m_slide_161;
			__m_latch_164 = ((rsub_5821 != 0) ? slide_6044 : __m_latch_164);
			t_sample latch_6039 = __m_latch_164;
			t_sample mul_6041 = (y_6945 * latch_6039);
			t_sample dcblock_6040 = __m_dcblock_165(mul_6041);
			t_sample x_6965 = add_5826;
			t_sample q_6962 = gen_6310;
			t_sample bw_6966 = safediv(((int)904), q_6962);
			t_sample r_6963 = exp(((-bw_6966) * twopi_over_sr_6961));
			t_sample c_6960 = ((((int)2) * r_6963) * cos((((int)904) * twopi_over_sr_6961)));
			t_sample c_6958 = ((-r_6963) * r_6963);
			t_sample y_6964 = ((((((int)1) - r_6963) * (x_6965 - (r_6963 * m_x_88))) + (c_6960 * m_y_87)) + (c_6958 * m_y_86));
			m_y_86 = m_y_87;
			m_y_87 = y_6964;
			m_x_88 = m_x_89;
			m_x_89 = x_6965;
			t_sample x_6028 = in2;
			t_sample q_6020 = gen_6310;
			t_sample bw_6029 = safediv(((int)904), q_6020);
			t_sample r_6022 = exp(((-bw_6029) * twopi_over_sr_6031));
			t_sample c_6030 = ((((int)2) * r_6022) * cos((((int)904) * twopi_over_sr_6031)));
			t_sample c_6033 = ((-r_6022) * r_6022);
			t_sample y_6032 = ((((((int)1) - r_6022) * (x_6028 - (r_6022 * m_x_84))) + (c_6030 * m_y_83)) + (c_6033 * m_y_82));
			m_y_82 = m_y_83;
			m_y_83 = y_6032;
			m_x_84 = m_x_85;
			m_x_85 = x_6028;
			t_sample abs_6019 = fabs(y_6032);
			__m_slide_166 = fixdenorm((__m_slide_166 + (((abs_6019 > __m_slide_166) ? iup_167 : idown_168) * (abs_6019 - __m_slide_166))));
			t_sample slide_6018 = __m_slide_166;
			__m_latch_169 = ((rsub_5821 != 0) ? slide_6018 : __m_latch_169);
			t_sample latch_6013 = __m_latch_169;
			t_sample mul_6015 = (y_6964 * latch_6013);
			t_sample dcblock_6014 = __m_dcblock_170(mul_6015);
			t_sample x_6981 = add_5826;
			t_sample q_6978 = gen_6310;
			t_sample bw_6986 = safediv(((int)1139), q_6978);
			t_sample r_6979 = exp(((-bw_6986) * twopi_over_sr_6989));
			t_sample c_6982 = ((((int)2) * r_6979) * cos((((int)1139) * twopi_over_sr_6989)));
			t_sample c_6988 = ((-r_6979) * r_6979);
			t_sample y_6980 = ((((((int)1) - r_6979) * (x_6981 - (r_6979 * m_x_80))) + (c_6982 * m_y_79)) + (c_6988 * m_y_78));
			m_y_78 = m_y_79;
			m_y_79 = y_6980;
			m_x_80 = m_x_81;
			m_x_81 = x_6981;
			t_sample x_6002 = in2;
			t_sample q_5994 = gen_6310;
			t_sample bw_6003 = safediv(((int)1139), q_5994);
			t_sample r_5996 = exp(((-bw_6003) * twopi_over_sr_6005));
			t_sample c_6004 = ((((int)2) * r_5996) * cos((((int)1139) * twopi_over_sr_6005)));
			t_sample c_6007 = ((-r_5996) * r_5996);
			t_sample y_6006 = ((((((int)1) - r_5996) * (x_6002 - (r_5996 * m_x_76))) + (c_6004 * m_y_75)) + (c_6007 * m_y_74));
			m_y_74 = m_y_75;
			m_y_75 = y_6006;
			m_x_76 = m_x_77;
			m_x_77 = x_6002;
			t_sample abs_5993 = fabs(y_6006);
			__m_slide_171 = fixdenorm((__m_slide_171 + (((abs_5993 > __m_slide_171) ? iup_172 : idown_173) * (abs_5993 - __m_slide_171))));
			t_sample slide_5992 = __m_slide_171;
			__m_latch_174 = ((rsub_5821 != 0) ? slide_5992 : __m_latch_174);
			t_sample latch_5987 = __m_latch_174;
			t_sample mul_5989 = (y_6980 * latch_5987);
			t_sample dcblock_5988 = __m_dcblock_175(mul_5989);
			t_sample x_6998 = add_5826;
			t_sample q_6995 = gen_6310;
			t_sample bw_7002 = safediv(((int)1435), q_6995);
			t_sample r_6996 = exp(((-bw_7002) * twopi_over_sr_7006));
			t_sample c_7005 = ((((int)2) * r_6996) * cos((((int)1435) * twopi_over_sr_7006)));
			t_sample c_7004 = ((-r_6996) * r_6996);
			t_sample y_6997 = ((((((int)1) - r_6996) * (x_6998 - (r_6996 * m_x_72))) + (c_7005 * m_y_71)) + (c_7004 * m_y_70));
			m_y_70 = m_y_71;
			m_y_71 = y_6997;
			m_x_72 = m_x_73;
			m_x_73 = x_6998;
			t_sample x_5976 = in2;
			t_sample q_5968 = gen_6310;
			t_sample bw_5977 = safediv(((int)1435), q_5968);
			t_sample r_5970 = exp(((-bw_5977) * twopi_over_sr_5979));
			t_sample c_5978 = ((((int)2) * r_5970) * cos((((int)1435) * twopi_over_sr_5979)));
			t_sample c_5981 = ((-r_5970) * r_5970);
			t_sample y_5980 = ((((((int)1) - r_5970) * (x_5976 - (r_5970 * m_x_68))) + (c_5978 * m_y_67)) + (c_5981 * m_y_66));
			m_y_66 = m_y_67;
			m_y_67 = y_5980;
			m_x_68 = m_x_69;
			m_x_69 = x_5976;
			t_sample abs_5967 = fabs(y_5980);
			__m_slide_176 = fixdenorm((__m_slide_176 + (((abs_5967 > __m_slide_176) ? iup_177 : idown_178) * (abs_5967 - __m_slide_176))));
			t_sample slide_5966 = __m_slide_176;
			__m_latch_179 = ((rsub_5821 != 0) ? slide_5966 : __m_latch_179);
			t_sample latch_5961 = __m_latch_179;
			t_sample mul_5963 = (y_6997 * latch_5961);
			t_sample dcblock_5962 = __m_dcblock_180(mul_5963);
			t_sample x_7017 = add_5826;
			t_sample q_7014 = gen_6310;
			t_sample bw_7022 = safediv(((int)1808), q_7014);
			t_sample r_7015 = exp(((-bw_7022) * twopi_over_sr_7025));
			t_sample c_7024 = ((((int)2) * r_7015) * cos((((int)1808) * twopi_over_sr_7025)));
			t_sample c_7021 = ((-r_7015) * r_7015);
			t_sample y_7016 = ((((((int)1) - r_7015) * (x_7017 - (r_7015 * m_x_64))) + (c_7024 * m_y_63)) + (c_7021 * m_y_62));
			m_y_62 = m_y_63;
			m_y_63 = y_7016;
			m_x_64 = m_x_65;
			m_x_65 = x_7017;
			t_sample x_5950 = in2;
			t_sample q_5942 = gen_6310;
			t_sample bw_5951 = safediv(((int)1808), q_5942);
			t_sample r_5944 = exp(((-bw_5951) * twopi_over_sr_5953));
			t_sample c_5952 = ((((int)2) * r_5944) * cos((((int)1808) * twopi_over_sr_5953)));
			t_sample c_5955 = ((-r_5944) * r_5944);
			t_sample y_5954 = ((((((int)1) - r_5944) * (x_5950 - (r_5944 * m_x_60))) + (c_5952 * m_y_59)) + (c_5955 * m_y_58));
			m_y_58 = m_y_59;
			m_y_59 = y_5954;
			m_x_60 = m_x_61;
			m_x_61 = x_5950;
			t_sample abs_5941 = fabs(y_5954);
			__m_slide_181 = fixdenorm((__m_slide_181 + (((abs_5941 > __m_slide_181) ? iup_182 : idown_183) * (abs_5941 - __m_slide_181))));
			t_sample slide_5940 = __m_slide_181;
			__m_latch_184 = ((rsub_5821 != 0) ? slide_5940 : __m_latch_184);
			t_sample latch_5935 = __m_latch_184;
			t_sample mul_5937 = (y_7016 * latch_5935);
			t_sample dcblock_5936 = __m_dcblock_185(mul_5937);
			t_sample x_7035 = add_5826;
			t_sample q_7032 = gen_6310;
			t_sample bw_7040 = safediv(((int)2260), q_7032);
			t_sample r_7033 = exp(((-bw_7040) * twopi_over_sr_7043));
			t_sample c_7036 = ((((int)2) * r_7033) * cos((((int)2260) * twopi_over_sr_7043)));
			t_sample c_7042 = ((-r_7033) * r_7033);
			t_sample y_7034 = ((((((int)1) - r_7033) * (x_7035 - (r_7033 * m_x_56))) + (c_7036 * m_y_55)) + (c_7042 * m_y_54));
			m_y_54 = m_y_55;
			m_y_55 = y_7034;
			m_x_56 = m_x_57;
			m_x_57 = x_7035;
			t_sample x_5924 = in2;
			t_sample q_5916 = gen_6310;
			t_sample bw_5925 = safediv(((int)2260), q_5916);
			t_sample r_5918 = exp(((-bw_5925) * twopi_over_sr_5927));
			t_sample c_5926 = ((((int)2) * r_5918) * cos((((int)2260) * twopi_over_sr_5927)));
			t_sample c_5929 = ((-r_5918) * r_5918);
			t_sample y_5928 = ((((((int)1) - r_5918) * (x_5924 - (r_5918 * m_x_52))) + (c_5926 * m_y_51)) + (c_5929 * m_y_50));
			m_y_50 = m_y_51;
			m_y_51 = y_5928;
			m_x_52 = m_x_53;
			m_x_53 = x_5924;
			t_sample abs_5915 = fabs(y_5928);
			__m_slide_186 = fixdenorm((__m_slide_186 + (((abs_5915 > __m_slide_186) ? iup_187 : idown_188) * (abs_5915 - __m_slide_186))));
			t_sample slide_5914 = __m_slide_186;
			__m_latch_189 = ((rsub_5821 != 0) ? slide_5914 : __m_latch_189);
			t_sample latch_5909 = __m_latch_189;
			t_sample mul_5911 = (y_7034 * latch_5909);
			t_sample dcblock_5910 = __m_dcblock_190(mul_5911);
			t_sample x_7052 = add_5826;
			t_sample q_7049 = gen_6310;
			t_sample bw_7059 = safediv(((int)2852), q_7049);
			t_sample r_7050 = exp(((-bw_7059) * twopi_over_sr_7061));
			t_sample c_7053 = ((((int)2) * r_7050) * cos((((int)2852) * twopi_over_sr_7061)));
			t_sample c_7058 = ((-r_7050) * r_7050);
			t_sample y_7051 = ((((((int)1) - r_7050) * (x_7052 - (r_7050 * m_x_48))) + (c_7053 * m_y_47)) + (c_7058 * m_y_46));
			m_y_46 = m_y_47;
			m_y_47 = y_7051;
			m_x_48 = m_x_49;
			m_x_49 = x_7052;
			t_sample x_5898 = in2;
			t_sample q_5890 = gen_6310;
			t_sample bw_5899 = safediv(((int)2852), q_5890);
			t_sample r_5892 = exp(((-bw_5899) * twopi_over_sr_5901));
			t_sample c_5900 = ((((int)2) * r_5892) * cos((((int)2852) * twopi_over_sr_5901)));
			t_sample c_5903 = ((-r_5892) * r_5892);
			t_sample y_5902 = ((((((int)1) - r_5892) * (x_5898 - (r_5892 * m_x_44))) + (c_5900 * m_y_43)) + (c_5903 * m_y_42));
			m_y_42 = m_y_43;
			m_y_43 = y_5902;
			m_x_44 = m_x_45;
			m_x_45 = x_5898;
			t_sample abs_5889 = fabs(y_5902);
			__m_slide_191 = fixdenorm((__m_slide_191 + (((abs_5889 > __m_slide_191) ? iup_192 : idown_193) * (abs_5889 - __m_slide_191))));
			t_sample slide_5888 = __m_slide_191;
			__m_latch_194 = ((rsub_5821 != 0) ? slide_5888 : __m_latch_194);
			t_sample latch_5883 = __m_latch_194;
			t_sample mul_5885 = (y_7051 * latch_5883);
			t_sample dcblock_5884 = __m_dcblock_195(mul_5885);
			t_sample x_7071 = add_5826;
			t_sample q_7068 = gen_6310;
			t_sample bw_7076 = safediv(((int)3616), q_7068);
			t_sample r_7069 = exp(((-bw_7076) * twopi_over_sr_7066));
			t_sample c_7072 = ((((int)2) * r_7069) * cos((((int)3616) * twopi_over_sr_7066)));
			t_sample c_7077 = ((-r_7069) * r_7069);
			t_sample y_7070 = ((((((int)1) - r_7069) * (x_7071 - (r_7069 * m_x_40))) + (c_7072 * m_y_39)) + (c_7077 * m_y_38));
			m_y_38 = m_y_39;
			m_y_39 = y_7070;
			m_x_40 = m_x_41;
			m_x_41 = x_7071;
			t_sample x_5872 = in2;
			t_sample q_5864 = gen_6310;
			t_sample bw_5873 = safediv(((int)3616), q_5864);
			t_sample r_5866 = exp(((-bw_5873) * twopi_over_sr_5875));
			t_sample c_5874 = ((((int)2) * r_5866) * cos((((int)3616) * twopi_over_sr_5875)));
			t_sample c_5877 = ((-r_5866) * r_5866);
			t_sample y_5876 = ((((((int)1) - r_5866) * (x_5872 - (r_5866 * m_x_36))) + (c_5874 * m_y_35)) + (c_5877 * m_y_34));
			m_y_34 = m_y_35;
			m_y_35 = y_5876;
			m_x_36 = m_x_37;
			m_x_37 = x_5872;
			t_sample abs_5863 = fabs(y_5876);
			__m_slide_196 = fixdenorm((__m_slide_196 + (((abs_5863 > __m_slide_196) ? iup_197 : idown_198) * (abs_5863 - __m_slide_196))));
			t_sample slide_5862 = __m_slide_196;
			__m_latch_199 = ((rsub_5821 != 0) ? slide_5862 : __m_latch_199);
			t_sample latch_5857 = __m_latch_199;
			t_sample mul_5859 = (y_7070 * latch_5857);
			t_sample dcblock_5858 = __m_dcblock_200(mul_5859);
			t_sample x_7089 = add_5826;
			t_sample q_7086 = gen_6310;
			t_sample bw_7094 = safediv(((int)4556), q_7086);
			t_sample r_7087 = exp(((-bw_7094) * twopi_over_sr_7084));
			t_sample c_7090 = ((((int)2) * r_7087) * cos((((int)4556) * twopi_over_sr_7084)));
			t_sample c_7093 = ((-r_7087) * r_7087);
			t_sample y_7088 = ((((((int)1) - r_7087) * (x_7089 - (r_7087 * m_x_32))) + (c_7090 * m_y_31)) + (c_7093 * m_y_30));
			m_y_30 = m_y_31;
			m_y_31 = y_7088;
			m_x_32 = m_x_33;
			m_x_33 = x_7089;
			t_sample x_5846 = in2;
			t_sample q_5838 = gen_6310;
			t_sample bw_5847 = safediv(((int)4556), q_5838);
			t_sample r_5840 = exp(((-bw_5847) * twopi_over_sr_5849));
			t_sample c_5848 = ((((int)2) * r_5840) * cos((((int)4556) * twopi_over_sr_5849)));
			t_sample c_5851 = ((-r_5840) * r_5840);
			t_sample y_5850 = ((((((int)1) - r_5840) * (x_5846 - (r_5840 * m_x_28))) + (c_5848 * m_y_27)) + (c_5851 * m_y_26));
			m_y_26 = m_y_27;
			m_y_27 = y_5850;
			m_x_28 = m_x_29;
			m_x_29 = x_5846;
			t_sample abs_5837 = fabs(y_5850);
			__m_slide_201 = fixdenorm((__m_slide_201 + (((abs_5837 > __m_slide_201) ? iup_202 : idown_203) * (abs_5837 - __m_slide_201))));
			t_sample slide_5836 = __m_slide_201;
			__m_latch_204 = ((rsub_5821 != 0) ? slide_5836 : __m_latch_204);
			t_sample latch_5829 = __m_latch_204;
			t_sample mul_5831 = (y_7088 * latch_5829);
			t_sample dcblock_5830 = __m_dcblock_205(mul_5831);
			t_sample x_7104 = add_5826;
			t_sample q_7114 = gen_6310;
			t_sample bw_7112 = safediv(((t_sample)104.5), q_7114);
			t_sample r_7102 = exp(((-bw_7112) * twopi_over_sr_7113));
			t_sample c_7111 = ((((int)2) * r_7102) * cos((((t_sample)104.5) * twopi_over_sr_7113)));
			t_sample c_7106 = ((-r_7102) * r_7102);
			t_sample y_7103 = ((((((int)1) - r_7102) * (x_7104 - (r_7102 * m_x_24))) + (c_7111 * m_y_23)) + (c_7106 * m_y_22));
			m_y_22 = m_y_23;
			m_y_23 = y_7103;
			m_x_24 = m_x_25;
			m_x_25 = x_7104;
			t_sample x_6280 = in2;
			t_sample q_6272 = gen_6310;
			t_sample bw_6281 = safediv(((t_sample)104.5), q_6272);
			t_sample r_6274 = exp(((-bw_6281) * twopi_over_sr_6283));
			t_sample c_6282 = ((((int)2) * r_6274) * cos((((t_sample)104.5) * twopi_over_sr_6283)));
			t_sample c_6285 = ((-r_6274) * r_6274);
			t_sample y_6284 = ((((((int)1) - r_6274) * (x_6280 - (r_6274 * m_x_20))) + (c_6282 * m_y_19)) + (c_6285 * m_y_18));
			m_y_18 = m_y_19;
			m_y_19 = y_6284;
			m_x_20 = m_x_21;
			m_x_21 = x_6280;
			t_sample abs_6271 = fabs(y_6284);
			__m_slide_206 = fixdenorm((__m_slide_206 + (((abs_6271 > __m_slide_206) ? iup_207 : idown_208) * (abs_6271 - __m_slide_206))));
			t_sample slide_6270 = __m_slide_206;
			__m_latch_209 = ((rsub_5821 != 0) ? slide_6270 : __m_latch_209);
			t_sample latch_6265 = __m_latch_209;
			t_sample mul_6267 = (y_7103 * latch_6265);
			t_sample dcblock_6266 = __m_dcblock_210(mul_6267);
			t_sample x_7122 = add_5826;
			t_sample q_7129 = gen_6310;
			t_sample bw_7130 = safediv(((t_sample)179.5), q_7129);
			t_sample r_7120 = exp(((-bw_7130) * twopi_over_sr_7131));
			t_sample c_7132 = ((((int)2) * r_7120) * cos((((t_sample)179.5) * twopi_over_sr_7131)));
			t_sample c_7124 = ((-r_7120) * r_7120);
			t_sample y_7121 = ((((((int)1) - r_7120) * (x_7122 - (r_7120 * m_x_16))) + (c_7132 * m_y_15)) + (c_7124 * m_y_14));
			m_y_14 = m_y_15;
			m_y_15 = y_7121;
			m_x_16 = m_x_17;
			m_x_17 = x_7122;
			t_sample x_6210 = in2;
			t_sample q_6202 = gen_6310;
			t_sample bw_6211 = safediv(((t_sample)179.5), q_6202);
			t_sample r_6204 = exp(((-bw_6211) * twopi_over_sr_6213));
			t_sample c_6212 = ((((int)2) * r_6204) * cos((((t_sample)179.5) * twopi_over_sr_6213)));
			t_sample c_6215 = ((-r_6204) * r_6204);
			t_sample y_6214 = ((((((int)1) - r_6204) * (x_6210 - (r_6204 * m_x_12))) + (c_6212 * m_y_11)) + (c_6215 * m_y_10));
			m_y_10 = m_y_11;
			m_y_11 = y_6214;
			m_x_12 = m_x_13;
			m_x_13 = x_6210;
			t_sample abs_6201 = fabs(y_6214);
			__m_slide_211 = fixdenorm((__m_slide_211 + (((abs_6201 > __m_slide_211) ? iup_212 : idown_213) * (abs_6201 - __m_slide_211))));
			t_sample slide_6200 = __m_slide_211;
			__m_latch_214 = ((rsub_5821 != 0) ? slide_6200 : __m_latch_214);
			t_sample latch_6195 = __m_latch_214;
			t_sample mul_6197 = (y_7121 * latch_6195);
			t_sample dcblock_6196 = __m_dcblock_215(mul_6197);
			t_sample x_7140 = add_5826;
			t_sample q_7151 = gen_6310;
			t_sample bw_7149 = safediv(((int)226), q_7151);
			t_sample r_7138 = exp(((-bw_7149) * twopi_over_sr_7150));
			t_sample c_7145 = ((((int)2) * r_7138) * cos((((int)226) * twopi_over_sr_7150)));
			t_sample c_7142 = ((-r_7138) * r_7138);
			t_sample y_7139 = ((((((int)1) - r_7138) * (x_7140 - (r_7138 * m_x_8))) + (c_7145 * m_y_7)) + (c_7142 * m_y_6));
			m_y_6 = m_y_7;
			m_y_7 = y_7139;
			m_x_8 = m_x_9;
			m_x_9 = x_7140;
			t_sample x_6184 = in2;
			t_sample q_6176 = gen_6310;
			t_sample bw_6185 = safediv(((int)226), q_6176);
			t_sample r_6178 = exp(((-bw_6185) * twopi_over_sr_6187));
			t_sample c_6186 = ((((int)2) * r_6178) * cos((((int)226) * twopi_over_sr_6187)));
			t_sample c_6189 = ((-r_6178) * r_6178);
			t_sample y_6188 = ((((((int)1) - r_6178) * (x_6184 - (r_6178 * m_x_4))) + (c_6186 * m_y_3)) + (c_6189 * m_y_2));
			m_y_2 = m_y_3;
			m_y_3 = y_6188;
			m_x_4 = m_x_5;
			m_x_5 = x_6184;
			t_sample abs_6175 = fabs(y_6188);
			__m_slide_216 = fixdenorm((__m_slide_216 + (((abs_6175 > __m_slide_216) ? iup_217 : idown_218) * (abs_6175 - __m_slide_216))));
			t_sample slide_6174 = __m_slide_216;
			__m_latch_219 = ((rsub_5821 != 0) ? slide_6174 : __m_latch_219);
			t_sample latch_6169 = __m_latch_219;
			t_sample mul_6171 = (y_7139 * latch_6169);
			t_sample dcblock_6170 = __m_dcblock_220(mul_6171);
			t_sample mul_6311 = ((((((((((((((((dcblock_6170 + dcblock_6196) + dcblock_6266) + dcblock_5830) + dcblock_5858) + dcblock_5884) + dcblock_5910) + dcblock_5936) + dcblock_5962) + dcblock_5988) + dcblock_6014) + dcblock_6040) + dcblock_6066) + dcblock_6092) + dcblock_6118) + dcblock_6144) * m_knob4_gain_138);
			t_sample add_6324 = (mul_6311 + gate_6314);
			t_sample out1 = add_6324;
			t_sample add_6323 = (mul_6311 + gate_6314);
			t_sample out2 = add_6323;
			t_sample history_5825_next_7156 = fixdenorm(mul_5823);
			m_history_133 = history_6318_next_6320;
			m_history_132 = history_6304_next_6307;
			m_history_130 = history_6299_next_6309;
			m_history_131 = history_6301_next_6308;
			m_history_1 = history_5825_next_7156;
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
