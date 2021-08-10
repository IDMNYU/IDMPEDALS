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
	t_sample m_history_28;
	t_sample __m_slide_51;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_slide_46;
	t_sample m_history_7;
	t_sample m_knob6_diffusion_27;
	t_sample m_sw_25;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_12;
	t_sample m_history_10;
	t_sample m_history_11;
	t_sample m_history_9;
	t_sample m_knob4_rate_26;
	t_sample m_history_16;
	t_sample m_history_18;
	t_sample m_sw_23;
	t_sample m_knob5_fb_24;
	t_sample m_history_17;
	t_sample __m_slide_61;
	t_sample m_history_20;
	t_sample m_history_21;
	t_sample m_history_19;
	t_sample m_knob3_depth_22;
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
		m_knob3_depth_22 = 1;
		m_sw_23 = ((int)0);
		m_knob5_fb_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_knob4_rate_26 = 0.1;
		m_knob6_diffusion_27 = 1;
		m_history_28 = ((int)0);
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
		t_sample sub_332 = (m_knob5_fb_24 - ((t_sample)0.5));
		t_sample scale_329 = ((safepow((sub_332 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		t_sample mul_177 = (m_knob6_diffusion_27 * ((int)3));
		t_sample div_175 = (mul_177 * ((t_sample)0.125));
		t_sample mul_178 = (m_knob6_diffusion_27 * ((int)1));
		t_sample div_176 = (mul_178 * ((t_sample)0.125));
		t_sample mul_184 = (m_knob6_diffusion_27 * ((int)2));
		t_sample div_182 = (mul_184 * ((t_sample)0.125));
		t_sample mul_185 = (m_knob6_diffusion_27 * ((int)0));
		t_sample div_183 = (mul_185 * ((t_sample)0.125));
		t_sample mstosamps_24 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_23 = (((int)100) * (samplerate * 0.001));
		t_sample iup_33 = (1 / maximum(1, abs(mstosamps_24)));
		t_sample idown_34 = (1 / maximum(1, abs(mstosamps_23)));
		t_sample div_58 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_37 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_38 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_40 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_41 = (1 / maximum(1, abs(((int)5))));
		t_sample div_100 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_44 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)5))));
		t_sample div_143 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_52 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)5))));
		t_sample div_201 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_34 = __m_sah_29(m_history_28, m_sw_25, ((int)0));
			t_sample gen_36 = sah_34;
			t_sample rsub_32 = (((int)1) - sah_34);
			t_sample history_33_next_35 = fixdenorm(rsub_32);
			t_sample out3 = gen_36;
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample mix_326 = (m_history_21 + (((t_sample)0.0042742627044161) * (m_knob4_rate_26 - m_history_21)));
			t_sample mix_12 = mix_326;
			t_sample mix_327 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_12 - m_history_20)));
			t_sample mix_10 = mix_327;
			t_sample mix_328 = (m_history_19 + (((t_sample)0.0042742627044161) * (mix_10 - m_history_19)));
			t_sample mix_8 = mix_328;
			t_sample gen_20 = mix_8;
			t_sample history_14_next_17 = fixdenorm(mix_12);
			t_sample history_11_next_18 = fixdenorm(mix_10);
			t_sample history_9_next_19 = fixdenorm(mix_8);
			t_sample expr_231 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_20)))));
			t_sample add_37 = (gen_36 + ((int)1));
			t_sample choice_30 = int(add_37);
			t_sample gate_30 = (((choice_30 >= 1) && (choice_30 < 2)) ? in1 : 0);
			t_sample gate_31 = ((choice_30 >= 2) ? in1 : 0);
			t_sample mul_40 = (m_history_1 * m_knob5_fb_24);
			t_sample add_39 = (gate_31 + mul_40);
			t_sample mul_230 = (expr_231 * ((t_sample)7.5));
			t_sample phasor_186 = __m_phasor_31(mul_230, samples_to_seconds);
			t_sample mul_181 = (m_history_2 * m_knob5_fb_24);
			t_sample add_180 = (gate_31 + mul_181);
			t_sample switch_27 = (m_sw_23 ? gate_31 : ((int)1));
			t_sample abs_29 = fabs(switch_27);
			t_sample mul_6 = (abs_29 * ((int)100));
			__m_slide_32 = fixdenorm((__m_slide_32 + (((mul_6 > __m_slide_32) ? iup_33 : idown_34) * (mul_6 - __m_slide_32))));
			t_sample slide_28 = __m_slide_32;
			t_sample mul_4 = (m_knob3_depth_22 * slide_28);
			t_sample clamp_26 = ((mul_4 <= ((int)0)) ? ((int)0) : ((mul_4 >= ((int)1)) ? ((int)1) : mul_4));
			t_sample add_67 = (phasor_186 + div_175);
			t_sample mod_68 = safemod(add_67, ((int)1));
			__m_cycle_35.phase(mod_68);
			t_sample cycle_65 = __m_cycle_35(__sinedata);
			t_sample cycleindex_66 = __m_cycle_35.phase();
			t_sample add_63 = (cycle_65 + ((int)1));
			t_sample div_62 = (add_63 * ((t_sample)0.5));
			t_sample mul_64 = (div_62 * clamp_26);
			t_sample sub_336 = (mul_64 - ((int)0));
			t_sample scale_333 = ((safepow((sub_336 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_69 = scale_333;
			t_sample mtof_70 = mtof(scale_69, ((int)440));
			t_sample mul_57 = (mtof_70 * div_58);
			t_sample cos_55 = cos(mul_57);
			t_sample mul_50 = (cos_55 * (-2));
			t_sample sin_56 = sin(mul_57);
			t_sample mul_54 = (sin_56 * ((t_sample)0.5));
			t_sample div_53 = (mul_54 * ((t_sample)0.33333333333333));
			t_sample rsub_48 = (((int)1) - div_53);
			t_sample add_52 = (div_53 + ((int)1));
			t_sample rdiv_51 = safediv(((int)1), add_52);
			t_sample mul_47 = (rdiv_51 * rsub_48);
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_47 > __m_slide_36) ? iup_37 : idown_38) * (mul_47 - __m_slide_36))));
			t_sample slide_44 = __m_slide_36;
			t_sample gen_60 = slide_44;
			t_sample mul_49 = (rdiv_51 * mul_50);
			__m_slide_39 = fixdenorm((__m_slide_39 + (((mul_49 > __m_slide_39) ? iup_40 : idown_41) * (mul_49 - __m_slide_39))));
			t_sample slide_45 = __m_slide_39;
			t_sample gen_59 = slide_45;
			t_sample mul_80 = (add_39 * gen_60);
			t_sample mul_77 = (m_history_16 * gen_59);
			t_sample mul_75 = (m_history_18 * ((int)1));
			t_sample mul_71 = (m_history_17 * gen_60);
			t_sample mul_73 = (m_history_15 * gen_59);
			t_sample sub_79 = (((mul_75 + mul_77) + mul_80) - (mul_73 + mul_71));
			t_sample gen_85 = sub_79;
			t_sample history_76_next_81 = fixdenorm(m_history_16);
			t_sample history_72_next_82 = fixdenorm(m_history_15);
			t_sample history_78_next_83 = fixdenorm(add_39);
			t_sample history_74_next_84 = fixdenorm(sub_79);
			t_sample add_109 = (phasor_186 + div_176);
			t_sample mod_110 = safemod(add_109, ((int)1));
			__m_cycle_42.phase(mod_110);
			t_sample cycle_107 = __m_cycle_42(__sinedata);
			t_sample cycleindex_108 = __m_cycle_42.phase();
			t_sample add_105 = (cycle_107 + ((int)1));
			t_sample div_104 = (add_105 * ((t_sample)0.5));
			t_sample mul_106 = (div_104 * clamp_26);
			t_sample sub_340 = (mul_106 - ((int)0));
			t_sample scale_337 = ((safepow((sub_340 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_111 = scale_337;
			t_sample mtof_112 = mtof(scale_111, ((int)440));
			t_sample mul_99 = (mtof_112 * div_100);
			t_sample cos_97 = cos(mul_99);
			t_sample mul_92 = (cos_97 * (-2));
			t_sample sin_98 = sin(mul_99);
			t_sample mul_96 = (sin_98 * ((t_sample)0.5));
			t_sample div_95 = (mul_96 * ((t_sample)0.33333333333333));
			t_sample rsub_90 = (((int)1) - div_95);
			t_sample add_94 = (div_95 + ((int)1));
			t_sample rdiv_93 = safediv(((int)1), add_94);
			t_sample mul_89 = (rdiv_93 * rsub_90);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((mul_89 > __m_slide_43) ? iup_44 : idown_45) * (mul_89 - __m_slide_43))));
			t_sample slide_86 = __m_slide_43;
			t_sample gen_102 = slide_86;
			t_sample mul_91 = (rdiv_93 * mul_92);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((mul_91 > __m_slide_46) ? iup_47 : idown_48) * (mul_91 - __m_slide_46))));
			t_sample slide_87 = __m_slide_46;
			t_sample gen_101 = slide_87;
			t_sample mul_122 = (add_39 * gen_102);
			t_sample mul_119 = (m_history_12 * gen_101);
			t_sample mul_117 = (m_history_13 * ((int)1));
			t_sample mul_113 = (m_history_14 * gen_102);
			t_sample mul_115 = (m_history_11 * gen_101);
			t_sample sub_121 = (((mul_117 + mul_119) + mul_122) - (mul_115 + mul_113));
			t_sample gen_127 = sub_121;
			t_sample history_114_next_123 = fixdenorm(m_history_11);
			t_sample history_118_next_124 = fixdenorm(m_history_12);
			t_sample history_120_next_125 = fixdenorm(add_39);
			t_sample history_116_next_126 = fixdenorm(sub_121);
			t_sample mul_41 = ((gen_127 + gen_85) * ((t_sample)0.5));
			t_sample dcblock_42 = __m_dcblock_49(mul_41);
			t_sample mul_43 = (((gate_31 + gen_127) + gen_85) * scale_329);
			t_sample div_2 = (mul_43 * ((t_sample)0.5));
			t_sample add_172 = (gate_30 + div_2);
			t_sample out2 = add_172;
			t_sample add_152 = (phasor_186 + div_182);
			t_sample mod_153 = safemod(add_152, ((int)1));
			__m_cycle_50.phase(mod_153);
			t_sample cycle_150 = __m_cycle_50(__sinedata);
			t_sample cycleindex_151 = __m_cycle_50.phase();
			t_sample add_148 = (cycle_150 + ((int)1));
			t_sample div_147 = (add_148 * ((t_sample)0.5));
			t_sample mul_149 = (div_147 * clamp_26);
			t_sample sub_344 = (mul_149 - ((int)0));
			t_sample scale_341 = ((safepow((sub_344 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_154 = scale_341;
			t_sample mtof_155 = mtof(scale_154, ((int)440));
			t_sample mul_142 = (mtof_155 * div_143);
			t_sample cos_140 = cos(mul_142);
			t_sample mul_135 = (cos_140 * (-2));
			t_sample sin_141 = sin(mul_142);
			t_sample mul_139 = (sin_141 * ((t_sample)0.5));
			t_sample div_138 = (mul_139 * ((t_sample)0.33333333333333));
			t_sample rsub_133 = (((int)1) - div_138);
			t_sample add_137 = (div_138 + ((int)1));
			t_sample rdiv_136 = safediv(((int)1), add_137);
			t_sample mul_132 = (rdiv_136 * rsub_133);
			__m_slide_51 = fixdenorm((__m_slide_51 + (((mul_132 > __m_slide_51) ? iup_52 : idown_53) * (mul_132 - __m_slide_51))));
			t_sample slide_129 = __m_slide_51;
			t_sample gen_145 = slide_129;
			t_sample mul_134 = (rdiv_136 * mul_135);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((mul_134 > __m_slide_54) ? iup_55 : idown_56) * (mul_134 - __m_slide_54))));
			t_sample slide_130 = __m_slide_54;
			t_sample gen_144 = slide_130;
			t_sample mul_165 = (add_180 * gen_145);
			t_sample mul_162 = (m_history_8 * gen_144);
			t_sample mul_160 = (m_history_9 * ((int)1));
			t_sample mul_156 = (m_history_10 * gen_145);
			t_sample mul_158 = (m_history_7 * gen_144);
			t_sample sub_164 = (((mul_160 + mul_162) + mul_165) - (mul_158 + mul_156));
			t_sample gen_170 = sub_164;
			t_sample history_157_next_166 = fixdenorm(m_history_7);
			t_sample history_161_next_167 = fixdenorm(m_history_8);
			t_sample history_163_next_168 = fixdenorm(add_180);
			t_sample history_159_next_169 = fixdenorm(sub_164);
			t_sample add_210 = (phasor_186 + div_183);
			t_sample mod_211 = safemod(add_210, ((int)1));
			__m_cycle_57.phase(mod_211);
			t_sample cycle_208 = __m_cycle_57(__sinedata);
			t_sample cycleindex_209 = __m_cycle_57.phase();
			t_sample add_206 = (cycle_208 + ((int)1));
			t_sample div_205 = (add_206 * ((t_sample)0.5));
			t_sample mul_207 = (div_205 * clamp_26);
			t_sample sub_348 = (mul_207 - ((int)0));
			t_sample scale_345 = ((safepow((sub_348 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_212 = scale_345;
			t_sample mtof_213 = mtof(scale_212, ((int)440));
			t_sample mul_200 = (mtof_213 * div_201);
			t_sample cos_198 = cos(mul_200);
			t_sample mul_193 = (cos_198 * (-2));
			t_sample sin_199 = sin(mul_200);
			t_sample mul_197 = (sin_199 * ((t_sample)0.5));
			t_sample div_196 = (mul_197 * ((t_sample)0.33333333333333));
			t_sample rsub_191 = (((int)1) - div_196);
			t_sample add_195 = (div_196 + ((int)1));
			t_sample rdiv_194 = safediv(((int)1), add_195);
			t_sample mul_190 = (rdiv_194 * rsub_191);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((mul_190 > __m_slide_58) ? iup_59 : idown_60) * (mul_190 - __m_slide_58))));
			t_sample slide_187 = __m_slide_58;
			t_sample gen_203 = slide_187;
			t_sample mul_192 = (rdiv_194 * mul_193);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((mul_192 > __m_slide_61) ? iup_62 : idown_63) * (mul_192 - __m_slide_61))));
			t_sample slide_188 = __m_slide_61;
			t_sample gen_202 = slide_188;
			t_sample mul_223 = (add_180 * gen_203);
			t_sample mul_220 = (m_history_4 * gen_202);
			t_sample mul_218 = (m_history_5 * ((int)1));
			t_sample mul_214 = (m_history_6 * gen_203);
			t_sample mul_216 = (m_history_3 * gen_202);
			t_sample sub_222 = (((mul_218 + mul_220) + mul_223) - (mul_216 + mul_214));
			t_sample gen_228 = sub_222;
			t_sample history_215_next_224 = fixdenorm(m_history_3);
			t_sample history_219_next_225 = fixdenorm(m_history_4);
			t_sample history_221_next_226 = fixdenorm(add_180);
			t_sample history_217_next_227 = fixdenorm(sub_222);
			t_sample mul_128 = ((gen_228 + gen_170) * ((t_sample)0.5));
			t_sample dcblock_173 = __m_dcblock_64(mul_128);
			t_sample mul_171 = (((gate_31 + gen_228) + gen_170) * scale_329);
			t_sample div_1 = (mul_171 * ((t_sample)0.5));
			t_sample add_174 = (gate_30 + div_1);
			t_sample out1 = add_174;
			t_sample history_179_next_232 = fixdenorm(dcblock_42);
			t_sample history_38_next_233 = fixdenorm(dcblock_173);
			m_history_28 = history_33_next_35;
			m_history_21 = history_14_next_17;
			m_history_19 = history_9_next_19;
			m_history_20 = history_11_next_18;
			m_history_18 = history_76_next_81;
			m_history_15 = history_74_next_84;
			m_history_16 = history_78_next_83;
			m_history_17 = history_72_next_82;
			m_history_14 = history_114_next_123;
			m_history_11 = history_116_next_126;
			m_history_12 = history_120_next_125;
			m_history_13 = history_118_next_124;
			m_history_10 = history_157_next_166;
			m_history_7 = history_159_next_169;
			m_history_8 = history_163_next_168;
			m_history_9 = history_161_next_167;
			m_history_6 = history_215_next_224;
			m_history_3 = history_217_next_227;
			m_history_4 = history_221_next_226;
			m_history_5 = history_219_next_225;
			m_history_2 = history_179_next_232;
			m_history_1 = history_38_next_233;
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
		m_knob3_depth_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_24 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_diffusion(t_param _value) {
		m_knob6_diffusion_27 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
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
		case 0: *value = self->m_knob3_depth_22; break;
		case 1: *value = self->m_knob4_rate_26; break;
		case 2: *value = self->m_knob5_fb_24; break;
		case 3: *value = self->m_knob6_diffusion_27; break;
		case 4: *value = self->m_sw_25; break;
		case 5: *value = self->m_sw_23; break;
		
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
	// initialize parameter 0 ("m_knob3_depth_22")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_26")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_fb_24")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_diffusion_27")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_diffusion";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_diffusion_27;
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
	// initialize parameter 5 ("m_sw_23")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_23;
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
