#include "Phaser.h"

namespace Phaser {

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
	DCBlock __m_dcblock_64;
	DCBlock __m_dcblock_49;
	Phasor __m_phasor_31;
	Sah __m_sah_29;
	SineCycle __m_cycle_57;
	SineCycle __m_cycle_50;
	SineCycle __m_cycle_42;
	SineCycle __m_cycle_35;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_4;
	t_sample m_history_8;
	t_sample m_history_3;
	t_sample __m_slide_32;
	t_sample m_history_5;
	t_sample samples_to_seconds;
	t_sample __m_slide_36;
	t_sample m_history_6;
	t_sample __m_slide_39;
	t_sample m_history_2;
	t_sample __m_slide_43;
	t_sample __m_slide_54;
	t_sample __m_slide_58;
	t_sample m_knob4_rate_28;
	t_sample __m_slide_51;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_slide_46;
	t_sample m_history_7;
	t_sample m_knob5_fb_27;
	t_sample m_sw_25;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_12;
	t_sample m_history_10;
	t_sample m_history_11;
	t_sample m_history_9;
	t_sample m_knob6_diffusion_26;
	t_sample m_history_16;
	t_sample m_history_18;
	t_sample m_knob3_depth_23;
	t_sample m_sw_24;
	t_sample m_history_17;
	t_sample __m_slide_61;
	t_sample m_history_20;
	t_sample m_history_21;
	t_sample m_history_19;
	t_sample m_history_22;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_knob3_depth_23 = 1;
		m_sw_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_knob6_diffusion_26 = 1;
		m_knob5_fb_27 = ((int)0);
		m_knob4_rate_28 = 0.1;
		__m_sah_29.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_31.reset(0);
		__m_slide_32 = 0;
		__m_cycle_35.reset(samplerate, 0);
		__m_slide_36 = 0;
		__m_slide_39 = 0;
		__m_cycle_42.reset(samplerate, 0);
		__m_slide_43 = 0;
		__m_slide_46 = 0;
		__m_dcblock_49.reset();
		__m_cycle_50.reset(samplerate, 0);
		__m_slide_51 = 0;
		__m_slide_54 = 0;
		__m_cycle_57.reset(samplerate, 0);
		__m_slide_58 = 0;
		__m_slide_61 = 0;
		__m_dcblock_64.reset();
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		t_sample * __out6 = __outs[5];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample sub_353 = (m_knob5_fb_27 - ((t_sample)0.5));
		t_sample scale_350 = ((safepow((sub_353 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		t_sample mul_175 = (m_knob6_diffusion_26 * ((int)3));
		t_sample div_173 = (mul_175 * ((t_sample)0.125));
		t_sample mul_176 = (m_knob6_diffusion_26 * ((int)1));
		t_sample div_174 = (mul_176 * ((t_sample)0.125));
		t_sample mul_182 = (m_knob6_diffusion_26 * ((int)2));
		t_sample div_180 = (mul_182 * ((t_sample)0.125));
		t_sample mul_183 = (m_knob6_diffusion_26 * ((int)0));
		t_sample div_181 = (mul_183 * ((t_sample)0.125));
		t_sample mstosamps_23 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_22 = (((int)100) * (samplerate * 0.001));
		t_sample iup_33 = (1 / maximum(1, abs(mstosamps_23)));
		t_sample idown_34 = (1 / maximum(1, abs(mstosamps_22)));
		t_sample div_56 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_37 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_38 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_40 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_41 = (1 / maximum(1, abs(((int)5))));
		t_sample div_98 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_44 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)5))));
		t_sample div_141 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_52 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)5))));
		t_sample div_199 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample mix_347 = (m_history_22 + (((t_sample)0.0042742627044161) * (m_knob4_rate_28 - m_history_22)));
			t_sample mix_13 = mix_347;
			t_sample mix_348 = (m_history_21 + (((t_sample)0.0042742627044161) * (mix_13 - m_history_21)));
			t_sample mix_11 = mix_348;
			t_sample mix_349 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_11 - m_history_20)));
			t_sample mix_9 = mix_349;
			t_sample gen_19 = mix_9;
			t_sample history_14_next_16 = fixdenorm(mix_13);
			t_sample history_12_next_17 = fixdenorm(mix_11);
			t_sample history_10_next_18 = fixdenorm(mix_9);
			t_sample expr_229 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_19)))));
			t_sample sah_32 = __m_sah_29(m_history_19, m_sw_25, ((int)0));
			t_sample gen_34 = sah_32;
			t_sample rsub_30 = (((int)1) - sah_32);
			t_sample history_31_next_33 = fixdenorm(rsub_30);
			t_sample out3 = gen_34;
			t_sample add_35 = (gen_34 + ((int)1));
			t_sample choice_30 = int(add_35);
			t_sample gate_28 = (((choice_30 >= 1) && (choice_30 < 2)) ? in1 : 0);
			t_sample gate_29 = ((choice_30 >= 2) ? in1 : 0);
			t_sample mul_38 = (m_history_1 * m_knob5_fb_27);
			t_sample add_37 = (gate_29 + mul_38);
			t_sample mul_228 = (expr_229 * ((t_sample)7.5));
			t_sample phasor_184 = __m_phasor_31(mul_228, samples_to_seconds);
			t_sample mul_179 = (m_history_2 * m_knob5_fb_27);
			t_sample add_178 = (gate_29 + mul_179);
			t_sample abs_2 = fabs(gate_29);
			t_sample mul_1 = (abs_2 * ((int)30));
			t_sample switch_26 = (m_sw_24 ? mul_1 : ((int)1));
			__m_slide_32 = fixdenorm((__m_slide_32 + (((switch_26 > __m_slide_32) ? iup_33 : idown_34) * (switch_26 - __m_slide_32))));
			t_sample slide_27 = __m_slide_32;
			t_sample mul_6 = (m_knob3_depth_23 * slide_27);
			t_sample clamp_25 = ((mul_6 <= ((int)0)) ? ((int)0) : ((mul_6 >= ((int)1)) ? ((int)1) : mul_6));
			t_sample out4 = clamp_25;
			t_sample add_65 = (phasor_184 + div_173);
			t_sample mod_66 = safemod(add_65, ((int)1));
			__m_cycle_35.phase(mod_66);
			t_sample cycle_63 = __m_cycle_35(__sinedata);
			t_sample cycleindex_64 = __m_cycle_35.phase();
			t_sample add_61 = (cycle_63 + ((int)1));
			t_sample div_60 = (add_61 * ((t_sample)0.5));
			t_sample mul_62 = (div_60 * clamp_25);
			t_sample sub_357 = (mul_62 - ((int)0));
			t_sample scale_354 = ((safepow((sub_357 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_67 = scale_354;
			t_sample mtof_68 = mtof(scale_67, ((int)440));
			t_sample mul_55 = (mtof_68 * div_56);
			t_sample cos_53 = cos(mul_55);
			t_sample mul_48 = (cos_53 * (-2));
			t_sample sin_54 = sin(mul_55);
			t_sample mul_52 = (sin_54 * ((t_sample)0.5));
			t_sample div_51 = (mul_52 * ((t_sample)0.33333333333333));
			t_sample rsub_46 = (((int)1) - div_51);
			t_sample add_50 = (div_51 + ((int)1));
			t_sample rdiv_49 = safediv(((int)1), add_50);
			t_sample mul_45 = (rdiv_49 * rsub_46);
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_45 > __m_slide_36) ? iup_37 : idown_38) * (mul_45 - __m_slide_36))));
			t_sample slide_42 = __m_slide_36;
			t_sample gen_58 = slide_42;
			t_sample mul_47 = (rdiv_49 * mul_48);
			__m_slide_39 = fixdenorm((__m_slide_39 + (((mul_47 > __m_slide_39) ? iup_40 : idown_41) * (mul_47 - __m_slide_39))));
			t_sample slide_43 = __m_slide_39;
			t_sample gen_57 = slide_43;
			t_sample mul_78 = (add_37 * gen_58);
			t_sample mul_75 = (m_history_16 * gen_57);
			t_sample mul_73 = (m_history_17 * ((int)1));
			t_sample mul_69 = (m_history_18 * gen_58);
			t_sample mul_71 = (m_history_15 * gen_57);
			t_sample sub_77 = (((mul_73 + mul_75) + mul_78) - (mul_71 + mul_69));
			t_sample gen_83 = sub_77;
			t_sample history_70_next_79 = fixdenorm(m_history_15);
			t_sample history_74_next_80 = fixdenorm(m_history_16);
			t_sample history_76_next_81 = fixdenorm(add_37);
			t_sample history_72_next_82 = fixdenorm(sub_77);
			t_sample add_107 = (phasor_184 + div_174);
			t_sample mod_108 = safemod(add_107, ((int)1));
			__m_cycle_42.phase(mod_108);
			t_sample cycle_105 = __m_cycle_42(__sinedata);
			t_sample cycleindex_106 = __m_cycle_42.phase();
			t_sample add_103 = (cycle_105 + ((int)1));
			t_sample div_102 = (add_103 * ((t_sample)0.5));
			t_sample mul_104 = (div_102 * clamp_25);
			t_sample sub_361 = (mul_104 - ((int)0));
			t_sample scale_358 = ((safepow((sub_361 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_109 = scale_358;
			t_sample mtof_110 = mtof(scale_109, ((int)440));
			t_sample mul_97 = (mtof_110 * div_98);
			t_sample cos_95 = cos(mul_97);
			t_sample mul_90 = (cos_95 * (-2));
			t_sample sin_96 = sin(mul_97);
			t_sample mul_94 = (sin_96 * ((t_sample)0.5));
			t_sample div_93 = (mul_94 * ((t_sample)0.33333333333333));
			t_sample rsub_88 = (((int)1) - div_93);
			t_sample add_92 = (div_93 + ((int)1));
			t_sample rdiv_91 = safediv(((int)1), add_92);
			t_sample mul_89 = (rdiv_91 * mul_90);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((mul_89 > __m_slide_43) ? iup_44 : idown_45) * (mul_89 - __m_slide_43))));
			t_sample slide_85 = __m_slide_43;
			t_sample gen_99 = slide_85;
			t_sample mul_87 = (rdiv_91 * rsub_88);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((mul_87 > __m_slide_46) ? iup_47 : idown_48) * (mul_87 - __m_slide_46))));
			t_sample slide_84 = __m_slide_46;
			t_sample gen_100 = slide_84;
			t_sample mul_120 = (add_37 * gen_100);
			t_sample mul_117 = (m_history_12 * gen_99);
			t_sample mul_115 = (m_history_14 * ((int)1));
			t_sample mul_111 = (m_history_13 * gen_100);
			t_sample mul_113 = (m_history_11 * gen_99);
			t_sample sub_119 = (((mul_115 + mul_117) + mul_120) - (mul_113 + mul_111));
			t_sample gen_125 = sub_119;
			t_sample history_116_next_121 = fixdenorm(m_history_12);
			t_sample history_112_next_122 = fixdenorm(m_history_11);
			t_sample history_118_next_123 = fixdenorm(add_37);
			t_sample history_114_next_124 = fixdenorm(sub_119);
			t_sample mul_39 = ((gen_125 + gen_83) * ((t_sample)0.5));
			t_sample dcblock_40 = __m_dcblock_49(mul_39);
			t_sample mul_41 = (((gate_29 + gen_125) + gen_83) * scale_350);
			t_sample div_4 = (mul_41 * ((t_sample)0.5));
			t_sample add_170 = (gate_28 + div_4);
			t_sample out2 = add_170;
			t_sample add_150 = (phasor_184 + div_180);
			t_sample mod_151 = safemod(add_150, ((int)1));
			__m_cycle_50.phase(mod_151);
			t_sample cycle_148 = __m_cycle_50(__sinedata);
			t_sample cycleindex_149 = __m_cycle_50.phase();
			t_sample add_146 = (cycle_148 + ((int)1));
			t_sample div_145 = (add_146 * ((t_sample)0.5));
			t_sample mul_147 = (div_145 * clamp_25);
			t_sample sub_365 = (mul_147 - ((int)0));
			t_sample scale_362 = ((safepow((sub_365 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_152 = scale_362;
			t_sample mtof_153 = mtof(scale_152, ((int)440));
			t_sample mul_140 = (mtof_153 * div_141);
			t_sample cos_138 = cos(mul_140);
			t_sample mul_133 = (cos_138 * (-2));
			t_sample sin_139 = sin(mul_140);
			t_sample mul_137 = (sin_139 * ((t_sample)0.5));
			t_sample div_136 = (mul_137 * ((t_sample)0.33333333333333));
			t_sample rsub_131 = (((int)1) - div_136);
			t_sample add_135 = (div_136 + ((int)1));
			t_sample rdiv_134 = safediv(((int)1), add_135);
			t_sample mul_132 = (rdiv_134 * mul_133);
			__m_slide_51 = fixdenorm((__m_slide_51 + (((mul_132 > __m_slide_51) ? iup_52 : idown_53) * (mul_132 - __m_slide_51))));
			t_sample slide_128 = __m_slide_51;
			t_sample gen_142 = slide_128;
			t_sample mul_130 = (rdiv_134 * rsub_131);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((mul_130 > __m_slide_54) ? iup_55 : idown_56) * (mul_130 - __m_slide_54))));
			t_sample slide_127 = __m_slide_54;
			t_sample gen_143 = slide_127;
			t_sample mul_163 = (add_178 * gen_143);
			t_sample mul_160 = (m_history_8 * gen_142);
			t_sample mul_158 = (m_history_9 * ((int)1));
			t_sample mul_154 = (m_history_10 * gen_143);
			t_sample mul_156 = (m_history_7 * gen_142);
			t_sample sub_162 = (((mul_158 + mul_160) + mul_163) - (mul_156 + mul_154));
			t_sample gen_168 = sub_162;
			t_sample history_155_next_164 = fixdenorm(m_history_7);
			t_sample history_159_next_165 = fixdenorm(m_history_8);
			t_sample history_161_next_166 = fixdenorm(add_178);
			t_sample history_157_next_167 = fixdenorm(sub_162);
			t_sample add_208 = (phasor_184 + div_181);
			t_sample mod_209 = safemod(add_208, ((int)1));
			__m_cycle_57.phase(mod_209);
			t_sample cycle_206 = __m_cycle_57(__sinedata);
			t_sample cycleindex_207 = __m_cycle_57.phase();
			t_sample add_204 = (cycle_206 + ((int)1));
			t_sample div_203 = (add_204 * ((t_sample)0.5));
			t_sample mul_205 = (div_203 * clamp_25);
			t_sample sub_369 = (mul_205 - ((int)0));
			t_sample scale_366 = ((safepow((sub_369 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_210 = scale_366;
			t_sample mtof_211 = mtof(scale_210, ((int)440));
			t_sample mul_198 = (mtof_211 * div_199);
			t_sample cos_196 = cos(mul_198);
			t_sample mul_191 = (cos_196 * (-2));
			t_sample sin_197 = sin(mul_198);
			t_sample mul_195 = (sin_197 * ((t_sample)0.5));
			t_sample div_194 = (mul_195 * ((t_sample)0.33333333333333));
			t_sample rsub_189 = (((int)1) - div_194);
			t_sample add_193 = (div_194 + ((int)1));
			t_sample rdiv_192 = safediv(((int)1), add_193);
			t_sample mul_188 = (rdiv_192 * rsub_189);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((mul_188 > __m_slide_58) ? iup_59 : idown_60) * (mul_188 - __m_slide_58))));
			t_sample slide_185 = __m_slide_58;
			t_sample gen_201 = slide_185;
			t_sample mul_190 = (rdiv_192 * mul_191);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((mul_190 > __m_slide_61) ? iup_62 : idown_63) * (mul_190 - __m_slide_61))));
			t_sample slide_186 = __m_slide_61;
			t_sample gen_200 = slide_186;
			t_sample mul_221 = (add_178 * gen_201);
			t_sample mul_218 = (m_history_4 * gen_200);
			t_sample mul_216 = (m_history_6 * ((int)1));
			t_sample mul_212 = (m_history_5 * gen_201);
			t_sample mul_214 = (m_history_3 * gen_200);
			t_sample sub_220 = (((mul_216 + mul_218) + mul_221) - (mul_214 + mul_212));
			t_sample gen_226 = sub_220;
			t_sample history_217_next_222 = fixdenorm(m_history_4);
			t_sample history_213_next_223 = fixdenorm(m_history_3);
			t_sample history_219_next_224 = fixdenorm(add_178);
			t_sample history_215_next_225 = fixdenorm(sub_220);
			t_sample mul_126 = ((gen_226 + gen_168) * ((t_sample)0.5));
			t_sample dcblock_171 = __m_dcblock_64(mul_126);
			t_sample mul_169 = (((gate_29 + gen_226) + gen_168) * scale_350);
			t_sample div_3 = (mul_169 * ((t_sample)0.5));
			t_sample add_172 = (gate_28 + div_3);
			t_sample out1 = add_172;
			t_sample history_177_next_230 = fixdenorm(dcblock_40);
			t_sample history_36_next_231 = fixdenorm(dcblock_171);
			m_history_22 = history_14_next_16;
			m_history_20 = history_10_next_18;
			m_history_21 = history_12_next_17;
			m_history_19 = history_31_next_33;
			m_history_18 = history_70_next_79;
			m_history_15 = history_72_next_82;
			m_history_16 = history_76_next_81;
			m_history_17 = history_74_next_80;
			m_history_14 = history_116_next_121;
			m_history_11 = history_114_next_124;
			m_history_12 = history_118_next_123;
			m_history_13 = history_112_next_122;
			m_history_10 = history_155_next_164;
			m_history_7 = history_157_next_167;
			m_history_8 = history_161_next_166;
			m_history_9 = history_159_next_165;
			m_history_6 = history_217_next_222;
			m_history_3 = history_215_next_225;
			m_history_4 = history_219_next_224;
			m_history_5 = history_213_next_223;
			m_history_2 = history_177_next_230;
			m_history_1 = history_36_next_231;
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
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_diffusion(t_param _value) {
		m_knob6_diffusion_26 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_27 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 1;
int gen_kernel_numouts = 6;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 6; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1" };
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
		case 0: self->set_knob3_depth(value); break;
		case 1: self->set_knob4_rate(value); break;
		case 2: self->set_knob5_fb(value); break;
		case 3: self->set_knob6_diffusion(value); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_depth_23; break;
		case 1: *value = self->m_knob4_rate_28; break;
		case 2: *value = self->m_knob5_fb_27; break;
		case 3: *value = self->m_knob6_diffusion_26; break;
		case 4: *value = self->m_sw_25; break;
		case 5: *value = self->m_sw_24; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(6 * sizeof(ParamInfo));
	self->__commonstate.numparams = 6;
	// initialize parameter 0 ("m_knob3_depth_23")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_28")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_fb_27")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_diffusion_26")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_diffusion";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_diffusion_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_25")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_24")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_24;
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


} // Phaser::
