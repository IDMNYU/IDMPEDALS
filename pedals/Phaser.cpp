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
	t_sample m_sw_28;
	t_sample __m_slide_51;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_slide_46;
	t_sample m_history_7;
	t_sample m_knob4_rate_27;
	t_sample m_knob3_depth_25;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_12;
	t_sample m_history_10;
	t_sample m_history_11;
	t_sample m_history_9;
	t_sample m_knob5_fb_26;
	t_sample m_history_16;
	t_sample m_history_18;
	t_sample m_sw_23;
	t_sample m_knob6_diffusion_24;
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
		m_sw_23 = ((int)0);
		m_knob6_diffusion_24 = 1;
		m_knob3_depth_25 = 1;
		m_knob5_fb_26 = ((int)0);
		m_knob4_rate_27 = 0.1;
		m_sw_28 = ((int)0);
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
		t_sample sub_313 = (m_knob5_fb_26 - ((t_sample)0.5));
		t_sample scale_310 = ((safepow((sub_313 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		t_sample mul_211 = (m_knob6_diffusion_24 * ((int)2));
		t_sample div_209 = (mul_211 * ((t_sample)0.125));
		t_sample mul_212 = (m_knob6_diffusion_24 * ((int)0));
		t_sample div_210 = (mul_212 * ((t_sample)0.125));
		t_sample mul_204 = (m_knob6_diffusion_24 * ((int)3));
		t_sample div_202 = (mul_204 * ((t_sample)0.125));
		t_sample mul_205 = (m_knob6_diffusion_24 * ((int)1));
		t_sample div_203 = (mul_205 * ((t_sample)0.125));
		t_sample mstosamps_51 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_50 = (((int)100) * (samplerate * 0.001));
		t_sample iup_33 = (1 / maximum(1, abs(mstosamps_51)));
		t_sample idown_34 = (1 / maximum(1, abs(mstosamps_50)));
		t_sample div_170 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_37 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_38 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_40 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_41 = (1 / maximum(1, abs(((int)5))));
		t_sample div_228 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_44 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)5))));
		t_sample div_85 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_52 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)5))));
		t_sample div_127 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample mix_307 = (m_history_22 + (((t_sample)0.0019634941468452) * (m_knob4_rate_27 - m_history_22)));
			t_sample mix_41 = mix_307;
			t_sample mix_308 = (m_history_21 + (((t_sample)0.0019634941468452) * (mix_41 - m_history_21)));
			t_sample mix_39 = mix_308;
			t_sample mix_309 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_39 - m_history_20)));
			t_sample mix_37 = mix_309;
			t_sample gen_47 = mix_37;
			t_sample history_42_next_44 = fixdenorm(mix_41);
			t_sample history_40_next_45 = fixdenorm(mix_39);
			t_sample history_38_next_46 = fixdenorm(mix_37);
			t_sample expr_258 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_47)))));
			t_sample sah_61 = __m_sah_29(m_history_19, m_sw_23, ((int)0));
			t_sample gen_63 = sah_61;
			t_sample rsub_59 = (((int)1) - sah_61);
			t_sample history_60_next_62 = fixdenorm(rsub_59);
			t_sample out3 = gen_63;
			t_sample add_64 = (gen_63 + ((int)1));
			t_sample choice_30 = int(add_64);
			t_sample gate_57 = (((choice_30 >= 1) && (choice_30 < 2)) ? in1 : 0);
			t_sample gate_58 = ((choice_30 >= 2) ? in1 : 0);
			t_sample mul_208 = (m_history_1 * m_knob5_fb_26);
			t_sample add_207 = (gate_58 + mul_208);
			t_sample mul_257 = (expr_258 * ((t_sample)7.5));
			t_sample phasor_213 = __m_phasor_31(mul_257, samples_to_seconds);
			t_sample mul_67 = (m_history_2 * m_knob5_fb_26);
			t_sample add_66 = (gate_58 + mul_67);
			t_sample switch_54 = (m_sw_28 ? gate_58 : ((int)1));
			t_sample abs_56 = fabs(switch_54);
			t_sample mul_35 = (abs_56 * ((int)100));
			__m_slide_32 = fixdenorm((__m_slide_32 + (((mul_35 > __m_slide_32) ? iup_33 : idown_34) * (mul_35 - __m_slide_32))));
			t_sample slide_55 = __m_slide_32;
			t_sample mul_33 = (m_knob3_depth_25 * slide_55);
			t_sample clamp_53 = ((mul_33 <= ((int)0)) ? ((int)0) : ((mul_33 >= ((int)1)) ? ((int)1) : mul_33));
			t_sample add_179 = (phasor_213 + div_209);
			t_sample mod_180 = safemod(add_179, ((int)1));
			__m_cycle_35.phase(mod_180);
			t_sample cycle_177 = __m_cycle_35(__sinedata);
			t_sample cycleindex_178 = __m_cycle_35.phase();
			t_sample add_175 = (cycle_177 + ((int)1));
			t_sample div_174 = (add_175 * ((t_sample)0.5));
			t_sample mul_176 = (div_174 * clamp_53);
			t_sample sub_317 = (mul_176 - ((int)0));
			t_sample scale_314 = ((safepow((sub_317 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_181 = scale_314;
			t_sample mtof_182 = mtof(scale_181, ((int)440));
			t_sample mul_169 = (mtof_182 * div_170);
			t_sample cos_167 = cos(mul_169);
			t_sample mul_162 = (cos_167 * (-2));
			t_sample sin_168 = sin(mul_169);
			t_sample mul_166 = (sin_168 * ((t_sample)0.5));
			t_sample div_165 = (mul_166 * ((t_sample)0.33333333333333));
			t_sample rsub_160 = (((int)1) - div_165);
			t_sample add_164 = (div_165 + ((int)1));
			t_sample rdiv_163 = safediv(((int)1), add_164);
			t_sample mul_161 = (rdiv_163 * mul_162);
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_161 > __m_slide_36) ? iup_37 : idown_38) * (mul_161 - __m_slide_36))));
			t_sample slide_157 = __m_slide_36;
			t_sample gen_171 = slide_157;
			t_sample mul_159 = (rdiv_163 * rsub_160);
			__m_slide_39 = fixdenorm((__m_slide_39 + (((mul_159 > __m_slide_39) ? iup_40 : idown_41) * (mul_159 - __m_slide_39))));
			t_sample slide_156 = __m_slide_39;
			t_sample gen_172 = slide_156;
			t_sample mul_192 = (add_207 * gen_172);
			t_sample mul_189 = (m_history_16 * gen_171);
			t_sample mul_187 = (m_history_18 * ((int)1));
			t_sample mul_183 = (m_history_17 * gen_172);
			t_sample mul_185 = (m_history_15 * gen_171);
			t_sample sub_191 = (((mul_187 + mul_189) + mul_192) - (mul_185 + mul_183));
			t_sample gen_197 = sub_191;
			t_sample history_188_next_193 = fixdenorm(m_history_16);
			t_sample history_184_next_194 = fixdenorm(m_history_15);
			t_sample history_190_next_195 = fixdenorm(add_207);
			t_sample history_186_next_196 = fixdenorm(sub_191);
			t_sample add_237 = (phasor_213 + div_210);
			t_sample mod_238 = safemod(add_237, ((int)1));
			__m_cycle_42.phase(mod_238);
			t_sample cycle_235 = __m_cycle_42(__sinedata);
			t_sample cycleindex_236 = __m_cycle_42.phase();
			t_sample add_233 = (cycle_235 + ((int)1));
			t_sample div_232 = (add_233 * ((t_sample)0.5));
			t_sample mul_234 = (div_232 * clamp_53);
			t_sample sub_321 = (mul_234 - ((int)0));
			t_sample scale_318 = ((safepow((sub_321 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_239 = scale_318;
			t_sample mtof_240 = mtof(scale_239, ((int)440));
			t_sample mul_227 = (mtof_240 * div_228);
			t_sample cos_225 = cos(mul_227);
			t_sample mul_220 = (cos_225 * (-2));
			t_sample sin_226 = sin(mul_227);
			t_sample mul_224 = (sin_226 * ((t_sample)0.5));
			t_sample div_223 = (mul_224 * ((t_sample)0.33333333333333));
			t_sample rsub_218 = (((int)1) - div_223);
			t_sample add_222 = (div_223 + ((int)1));
			t_sample rdiv_221 = safediv(((int)1), add_222);
			t_sample mul_219 = (rdiv_221 * mul_220);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((mul_219 > __m_slide_43) ? iup_44 : idown_45) * (mul_219 - __m_slide_43))));
			t_sample slide_215 = __m_slide_43;
			t_sample gen_229 = slide_215;
			t_sample mul_217 = (rdiv_221 * rsub_218);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((mul_217 > __m_slide_46) ? iup_47 : idown_48) * (mul_217 - __m_slide_46))));
			t_sample slide_214 = __m_slide_46;
			t_sample gen_230 = slide_214;
			t_sample mul_250 = (add_207 * gen_230);
			t_sample mul_247 = (m_history_12 * gen_229);
			t_sample mul_245 = (m_history_14 * ((int)1));
			t_sample mul_241 = (m_history_13 * gen_230);
			t_sample mul_243 = (m_history_11 * gen_229);
			t_sample sub_249 = (((mul_245 + mul_247) + mul_250) - (mul_243 + mul_241));
			t_sample gen_255 = sub_249;
			t_sample history_246_next_251 = fixdenorm(m_history_12);
			t_sample history_242_next_252 = fixdenorm(m_history_11);
			t_sample history_248_next_253 = fixdenorm(add_207);
			t_sample history_244_next_254 = fixdenorm(sub_249);
			t_sample mul_155 = ((gen_255 + gen_197) * ((t_sample)0.5));
			t_sample dcblock_200 = __m_dcblock_49(mul_155);
			t_sample mul_198 = (((gate_58 + gen_255) + gen_197) * scale_310);
			t_sample div_30 = (mul_198 * ((t_sample)0.5));
			t_sample add_201 = (gate_57 + div_30);
			t_sample out1 = add_201;
			t_sample add_94 = (phasor_213 + div_202);
			t_sample mod_95 = safemod(add_94, ((int)1));
			__m_cycle_50.phase(mod_95);
			t_sample cycle_92 = __m_cycle_50(__sinedata);
			t_sample cycleindex_93 = __m_cycle_50.phase();
			t_sample add_90 = (cycle_92 + ((int)1));
			t_sample div_89 = (add_90 * ((t_sample)0.5));
			t_sample mul_91 = (div_89 * clamp_53);
			t_sample sub_325 = (mul_91 - ((int)0));
			t_sample scale_322 = ((safepow((sub_325 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_96 = scale_322;
			t_sample mtof_97 = mtof(scale_96, ((int)440));
			t_sample mul_84 = (mtof_97 * div_85);
			t_sample cos_82 = cos(mul_84);
			t_sample mul_77 = (cos_82 * (-2));
			t_sample sin_83 = sin(mul_84);
			t_sample mul_81 = (sin_83 * ((t_sample)0.5));
			t_sample div_80 = (mul_81 * ((t_sample)0.33333333333333));
			t_sample rsub_75 = (((int)1) - div_80);
			t_sample add_79 = (div_80 + ((int)1));
			t_sample rdiv_78 = safediv(((int)1), add_79);
			t_sample mul_76 = (rdiv_78 * mul_77);
			__m_slide_51 = fixdenorm((__m_slide_51 + (((mul_76 > __m_slide_51) ? iup_52 : idown_53) * (mul_76 - __m_slide_51))));
			t_sample slide_72 = __m_slide_51;
			t_sample gen_86 = slide_72;
			t_sample mul_74 = (rdiv_78 * rsub_75);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((mul_74 > __m_slide_54) ? iup_55 : idown_56) * (mul_74 - __m_slide_54))));
			t_sample slide_71 = __m_slide_54;
			t_sample gen_87 = slide_71;
			t_sample mul_107 = (add_66 * gen_87);
			t_sample mul_104 = (m_history_8 * gen_86);
			t_sample mul_102 = (m_history_9 * ((int)1));
			t_sample mul_98 = (m_history_10 * gen_87);
			t_sample mul_100 = (m_history_7 * gen_86);
			t_sample sub_106 = (((mul_102 + mul_104) + mul_107) - (mul_100 + mul_98));
			t_sample gen_112 = sub_106;
			t_sample history_99_next_108 = fixdenorm(m_history_7);
			t_sample history_103_next_109 = fixdenorm(m_history_8);
			t_sample history_105_next_110 = fixdenorm(add_66);
			t_sample history_101_next_111 = fixdenorm(sub_106);
			t_sample add_136 = (phasor_213 + div_203);
			t_sample mod_137 = safemod(add_136, ((int)1));
			__m_cycle_57.phase(mod_137);
			t_sample cycle_134 = __m_cycle_57(__sinedata);
			t_sample cycleindex_135 = __m_cycle_57.phase();
			t_sample add_132 = (cycle_134 + ((int)1));
			t_sample div_131 = (add_132 * ((t_sample)0.5));
			t_sample mul_133 = (div_131 * clamp_53);
			t_sample sub_329 = (mul_133 - ((int)0));
			t_sample scale_326 = ((safepow((sub_329 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_138 = scale_326;
			t_sample mtof_139 = mtof(scale_138, ((int)440));
			t_sample mul_126 = (mtof_139 * div_127);
			t_sample cos_124 = cos(mul_126);
			t_sample mul_119 = (cos_124 * (-2));
			t_sample sin_125 = sin(mul_126);
			t_sample mul_123 = (sin_125 * ((t_sample)0.5));
			t_sample div_122 = (mul_123 * ((t_sample)0.33333333333333));
			t_sample rsub_117 = (((int)1) - div_122);
			t_sample add_121 = (div_122 + ((int)1));
			t_sample rdiv_120 = safediv(((int)1), add_121);
			t_sample mul_118 = (rdiv_120 * mul_119);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((mul_118 > __m_slide_58) ? iup_59 : idown_60) * (mul_118 - __m_slide_58))));
			t_sample slide_114 = __m_slide_58;
			t_sample gen_128 = slide_114;
			t_sample mul_116 = (rdiv_120 * rsub_117);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((mul_116 > __m_slide_61) ? iup_62 : idown_63) * (mul_116 - __m_slide_61))));
			t_sample slide_113 = __m_slide_61;
			t_sample gen_129 = slide_113;
			t_sample mul_149 = (add_66 * gen_129);
			t_sample mul_146 = (m_history_4 * gen_128);
			t_sample mul_144 = (m_history_6 * ((int)1));
			t_sample mul_140 = (m_history_5 * gen_129);
			t_sample mul_142 = (m_history_3 * gen_128);
			t_sample sub_148 = (((mul_144 + mul_146) + mul_149) - (mul_142 + mul_140));
			t_sample gen_154 = sub_148;
			t_sample history_145_next_150 = fixdenorm(m_history_4);
			t_sample history_141_next_151 = fixdenorm(m_history_3);
			t_sample history_147_next_152 = fixdenorm(add_66);
			t_sample history_143_next_153 = fixdenorm(sub_148);
			t_sample mul_68 = ((gen_154 + gen_112) * ((t_sample)0.5));
			t_sample dcblock_69 = __m_dcblock_64(mul_68);
			t_sample mul_70 = (((gate_58 + gen_154) + gen_112) * scale_310);
			t_sample div_31 = (mul_70 * ((t_sample)0.5));
			t_sample add_199 = (gate_57 + div_31);
			t_sample out2 = add_199;
			t_sample history_65_next_259 = fixdenorm(dcblock_200);
			t_sample history_206_next_260 = fixdenorm(dcblock_69);
			m_history_22 = history_42_next_44;
			m_history_20 = history_38_next_46;
			m_history_21 = history_40_next_45;
			m_history_19 = history_60_next_62;
			m_history_18 = history_188_next_193;
			m_history_15 = history_186_next_196;
			m_history_16 = history_190_next_195;
			m_history_17 = history_184_next_194;
			m_history_14 = history_246_next_251;
			m_history_11 = history_244_next_254;
			m_history_12 = history_248_next_253;
			m_history_13 = history_242_next_252;
			m_history_10 = history_99_next_108;
			m_history_7 = history_101_next_111;
			m_history_8 = history_105_next_110;
			m_history_9 = history_103_next_109;
			m_history_6 = history_145_next_150;
			m_history_3 = history_143_next_153;
			m_history_4 = history_147_next_152;
			m_history_5 = history_141_next_151;
			m_history_2 = history_65_next_259;
			m_history_1 = history_206_next_260;
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
	inline void set_sw1(t_param _value) {
		m_sw_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_diffusion(t_param _value) {
		m_knob6_diffusion_24 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_26 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_depth_25; break;
		case 1: *value = self->m_knob4_rate_27; break;
		case 2: *value = self->m_knob5_fb_26; break;
		case 3: *value = self->m_knob6_diffusion_24; break;
		case 4: *value = self->m_sw_23; break;
		case 5: *value = self->m_sw_28; break;
		
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
	// initialize parameter 0 ("m_knob3_depth_25")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_27")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_fb_26")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_diffusion_24")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_diffusion";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_diffusion_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_23")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
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
	// initialize parameter 5 ("m_sw_28")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_28;
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
