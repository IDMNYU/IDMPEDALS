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
	t_sample m_knob5_fb_25;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_12;
	t_sample m_history_10;
	t_sample m_history_11;
	t_sample m_history_9;
	t_sample m_sw_26;
	t_sample m_history_16;
	t_sample m_history_18;
	t_sample m_knob3_depth_23;
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
		m_knob3_depth_23 = 1;
		m_knob6_diffusion_24 = 1;
		m_knob5_fb_25 = ((int)0);
		m_sw_26 = ((int)0);
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
		t_sample sub_3360 = (m_knob5_fb_25 - ((t_sample)0.5));
		t_sample scale_3357 = ((safepow((sub_3360 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		t_sample mstosamps_3099 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_3098 = (((int)100) * (samplerate * 0.001));
		samples_to_seconds = (1 / samplerate);
		t_sample mul_3251 = (m_knob6_diffusion_24 * ((int)3));
		t_sample div_3249 = (mul_3251 * ((t_sample)0.125));
		t_sample mul_3252 = (m_knob6_diffusion_24 * ((int)1));
		t_sample div_3250 = (mul_3252 * ((t_sample)0.125));
		t_sample mul_3258 = (m_knob6_diffusion_24 * ((int)2));
		t_sample div_3256 = (mul_3258 * ((t_sample)0.125));
		t_sample mul_3259 = (m_knob6_diffusion_24 * ((int)0));
		t_sample div_3257 = (mul_3259 * ((t_sample)0.125));
		t_sample iup_33 = (1 / maximum(1, abs(mstosamps_3099)));
		t_sample idown_34 = (1 / maximum(1, abs(mstosamps_3098)));
		t_sample div_3132 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_37 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_38 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_40 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_41 = (1 / maximum(1, abs(((int)5))));
		t_sample div_3174 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_44 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)5))));
		t_sample div_3217 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_52 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)5))));
		t_sample div_3275 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample mix_3354 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob4_rate_27 - m_history_22)));
			t_sample mix_3089 = mix_3354;
			t_sample mix_3355 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_3089 - m_history_21)));
			t_sample mix_3087 = mix_3355;
			t_sample mix_3356 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_3087 - m_history_20)));
			t_sample mix_3085 = mix_3356;
			t_sample gen_3095 = mix_3085;
			t_sample history_3090_next_3092 = fixdenorm(mix_3089);
			t_sample history_3088_next_3093 = fixdenorm(mix_3087);
			t_sample history_3086_next_3094 = fixdenorm(mix_3085);
			t_sample expr_3305 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_3095)))));
			t_sample sah_3108 = __m_sah_29(m_history_19, m_sw_28, ((int)0));
			t_sample gen_3110 = sah_3108;
			t_sample rsub_3106 = (((int)1) - sah_3108);
			t_sample history_3107_next_3109 = fixdenorm(rsub_3106);
			t_sample out3 = gen_3110;
			t_sample add_3111 = (gen_3110 + ((int)1));
			t_sample choice_30 = int(add_3111);
			t_sample gate_3104 = (((choice_30 >= 1) && (choice_30 < 2)) ? in1 : 0);
			t_sample gate_3105 = ((choice_30 >= 2) ? in1 : 0);
			t_sample mul_3114 = (m_history_1 * m_knob5_fb_25);
			t_sample add_3113 = (gate_3105 + mul_3114);
			t_sample mul_3304 = (expr_3305 * ((t_sample)7.5));
			t_sample phasor_3260 = __m_phasor_31(mul_3304, samples_to_seconds);
			t_sample mul_3255 = (m_history_2 * m_knob5_fb_25);
			t_sample add_3254 = (gate_3105 + mul_3255);
			t_sample abs_3078 = fabs(gate_3105);
			t_sample mul_3077 = (abs_3078 * ((int)30));
			t_sample switch_3102 = (m_sw_26 ? mul_3077 : ((int)1));
			__m_slide_32 = fixdenorm((__m_slide_32 + (((switch_3102 > __m_slide_32) ? iup_33 : idown_34) * (switch_3102 - __m_slide_32))));
			t_sample slide_3103 = __m_slide_32;
			t_sample mul_3082 = (m_knob3_depth_23 * slide_3103);
			t_sample clamp_3101 = ((mul_3082 <= ((int)0)) ? ((int)0) : ((mul_3082 >= ((int)1)) ? ((int)1) : mul_3082));
			t_sample out4 = clamp_3101;
			t_sample add_3141 = (phasor_3260 + div_3249);
			t_sample mod_3142 = safemod(add_3141, ((int)1));
			__m_cycle_35.phase(mod_3142);
			t_sample cycle_3139 = __m_cycle_35(__sinedata);
			t_sample cycleindex_3140 = __m_cycle_35.phase();
			t_sample add_3137 = (cycle_3139 + ((int)1));
			t_sample div_3136 = (add_3137 * ((t_sample)0.5));
			t_sample mul_3138 = (div_3136 * clamp_3101);
			t_sample sub_3364 = (mul_3138 - ((int)0));
			t_sample scale_3361 = ((safepow((sub_3364 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_3143 = scale_3361;
			t_sample mtof_3144 = mtof(scale_3143, ((int)440));
			t_sample mul_3131 = (mtof_3144 * div_3132);
			t_sample cos_3129 = cos(mul_3131);
			t_sample mul_3124 = (cos_3129 * (-2));
			t_sample sin_3130 = sin(mul_3131);
			t_sample mul_3128 = (sin_3130 * ((t_sample)0.5));
			t_sample div_3127 = (mul_3128 * ((t_sample)0.33333333333333));
			t_sample rsub_3122 = (((int)1) - div_3127);
			t_sample add_3126 = (div_3127 + ((int)1));
			t_sample rdiv_3125 = safediv(((int)1), add_3126);
			t_sample mul_3121 = (rdiv_3125 * rsub_3122);
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_3121 > __m_slide_36) ? iup_37 : idown_38) * (mul_3121 - __m_slide_36))));
			t_sample slide_3118 = __m_slide_36;
			t_sample gen_3134 = slide_3118;
			t_sample mul_3123 = (rdiv_3125 * mul_3124);
			__m_slide_39 = fixdenorm((__m_slide_39 + (((mul_3123 > __m_slide_39) ? iup_40 : idown_41) * (mul_3123 - __m_slide_39))));
			t_sample slide_3119 = __m_slide_39;
			t_sample gen_3133 = slide_3119;
			t_sample mul_3154 = (add_3113 * gen_3134);
			t_sample mul_3151 = (m_history_16 * gen_3133);
			t_sample mul_3149 = (m_history_18 * ((int)1));
			t_sample mul_3145 = (m_history_17 * gen_3134);
			t_sample mul_3147 = (m_history_15 * gen_3133);
			t_sample sub_3153 = (((mul_3149 + mul_3151) + mul_3154) - (mul_3147 + mul_3145));
			t_sample gen_3159 = sub_3153;
			t_sample history_3150_next_3155 = fixdenorm(m_history_16);
			t_sample history_3146_next_3156 = fixdenorm(m_history_15);
			t_sample history_3152_next_3157 = fixdenorm(add_3113);
			t_sample history_3148_next_3158 = fixdenorm(sub_3153);
			t_sample add_3183 = (phasor_3260 + div_3250);
			t_sample mod_3184 = safemod(add_3183, ((int)1));
			__m_cycle_42.phase(mod_3184);
			t_sample cycle_3181 = __m_cycle_42(__sinedata);
			t_sample cycleindex_3182 = __m_cycle_42.phase();
			t_sample add_3179 = (cycle_3181 + ((int)1));
			t_sample div_3178 = (add_3179 * ((t_sample)0.5));
			t_sample mul_3180 = (div_3178 * clamp_3101);
			t_sample sub_3368 = (mul_3180 - ((int)0));
			t_sample scale_3365 = ((safepow((sub_3368 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_3185 = scale_3365;
			t_sample mtof_3186 = mtof(scale_3185, ((int)440));
			t_sample mul_3173 = (mtof_3186 * div_3174);
			t_sample cos_3171 = cos(mul_3173);
			t_sample mul_3166 = (cos_3171 * (-2));
			t_sample sin_3172 = sin(mul_3173);
			t_sample mul_3170 = (sin_3172 * ((t_sample)0.5));
			t_sample div_3169 = (mul_3170 * ((t_sample)0.33333333333333));
			t_sample rsub_3164 = (((int)1) - div_3169);
			t_sample add_3168 = (div_3169 + ((int)1));
			t_sample rdiv_3167 = safediv(((int)1), add_3168);
			t_sample mul_3163 = (rdiv_3167 * rsub_3164);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((mul_3163 > __m_slide_43) ? iup_44 : idown_45) * (mul_3163 - __m_slide_43))));
			t_sample slide_3160 = __m_slide_43;
			t_sample gen_3176 = slide_3160;
			t_sample mul_3165 = (rdiv_3167 * mul_3166);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((mul_3165 > __m_slide_46) ? iup_47 : idown_48) * (mul_3165 - __m_slide_46))));
			t_sample slide_3161 = __m_slide_46;
			t_sample gen_3175 = slide_3161;
			t_sample mul_3196 = (add_3113 * gen_3176);
			t_sample mul_3193 = (m_history_12 * gen_3175);
			t_sample mul_3191 = (m_history_14 * ((int)1));
			t_sample mul_3187 = (m_history_13 * gen_3176);
			t_sample mul_3189 = (m_history_11 * gen_3175);
			t_sample sub_3195 = (((mul_3191 + mul_3193) + mul_3196) - (mul_3189 + mul_3187));
			t_sample gen_3201 = sub_3195;
			t_sample history_3192_next_3197 = fixdenorm(m_history_12);
			t_sample history_3188_next_3198 = fixdenorm(m_history_11);
			t_sample history_3194_next_3199 = fixdenorm(add_3113);
			t_sample history_3190_next_3200 = fixdenorm(sub_3195);
			t_sample mul_3115 = ((gen_3201 + gen_3159) * ((t_sample)0.5));
			t_sample dcblock_3116 = __m_dcblock_49(mul_3115);
			t_sample mul_3117 = (((gate_3105 + gen_3201) + gen_3159) * scale_3357);
			t_sample div_3080 = (mul_3117 * ((t_sample)0.5));
			t_sample add_3246 = (gate_3104 + div_3080);
			t_sample out2 = add_3246;
			t_sample add_3226 = (phasor_3260 + div_3256);
			t_sample mod_3227 = safemod(add_3226, ((int)1));
			__m_cycle_50.phase(mod_3227);
			t_sample cycle_3224 = __m_cycle_50(__sinedata);
			t_sample cycleindex_3225 = __m_cycle_50.phase();
			t_sample add_3222 = (cycle_3224 + ((int)1));
			t_sample div_3221 = (add_3222 * ((t_sample)0.5));
			t_sample mul_3223 = (div_3221 * clamp_3101);
			t_sample sub_3372 = (mul_3223 - ((int)0));
			t_sample scale_3369 = ((safepow((sub_3372 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_3228 = scale_3369;
			t_sample mtof_3229 = mtof(scale_3228, ((int)440));
			t_sample mul_3216 = (mtof_3229 * div_3217);
			t_sample cos_3214 = cos(mul_3216);
			t_sample mul_3209 = (cos_3214 * (-2));
			t_sample sin_3215 = sin(mul_3216);
			t_sample mul_3213 = (sin_3215 * ((t_sample)0.5));
			t_sample div_3212 = (mul_3213 * ((t_sample)0.33333333333333));
			t_sample rsub_3207 = (((int)1) - div_3212);
			t_sample add_3211 = (div_3212 + ((int)1));
			t_sample rdiv_3210 = safediv(((int)1), add_3211);
			t_sample mul_3208 = (rdiv_3210 * mul_3209);
			__m_slide_51 = fixdenorm((__m_slide_51 + (((mul_3208 > __m_slide_51) ? iup_52 : idown_53) * (mul_3208 - __m_slide_51))));
			t_sample slide_3204 = __m_slide_51;
			t_sample gen_3218 = slide_3204;
			t_sample mul_3206 = (rdiv_3210 * rsub_3207);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((mul_3206 > __m_slide_54) ? iup_55 : idown_56) * (mul_3206 - __m_slide_54))));
			t_sample slide_3203 = __m_slide_54;
			t_sample gen_3219 = slide_3203;
			t_sample mul_3239 = (add_3254 * gen_3219);
			t_sample mul_3236 = (m_history_8 * gen_3218);
			t_sample mul_3234 = (m_history_9 * ((int)1));
			t_sample mul_3230 = (m_history_10 * gen_3219);
			t_sample mul_3232 = (m_history_7 * gen_3218);
			t_sample sub_3238 = (((mul_3234 + mul_3236) + mul_3239) - (mul_3232 + mul_3230));
			t_sample gen_3244 = sub_3238;
			t_sample history_3231_next_3240 = fixdenorm(m_history_7);
			t_sample history_3235_next_3241 = fixdenorm(m_history_8);
			t_sample history_3237_next_3242 = fixdenorm(add_3254);
			t_sample history_3233_next_3243 = fixdenorm(sub_3238);
			t_sample add_3284 = (phasor_3260 + div_3257);
			t_sample mod_3285 = safemod(add_3284, ((int)1));
			__m_cycle_57.phase(mod_3285);
			t_sample cycle_3282 = __m_cycle_57(__sinedata);
			t_sample cycleindex_3283 = __m_cycle_57.phase();
			t_sample add_3280 = (cycle_3282 + ((int)1));
			t_sample div_3279 = (add_3280 * ((t_sample)0.5));
			t_sample mul_3281 = (div_3279 * clamp_3101);
			t_sample sub_3376 = (mul_3281 - ((int)0));
			t_sample scale_3373 = ((safepow((sub_3376 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_3286 = scale_3373;
			t_sample mtof_3287 = mtof(scale_3286, ((int)440));
			t_sample mul_3274 = (mtof_3287 * div_3275);
			t_sample cos_3272 = cos(mul_3274);
			t_sample mul_3267 = (cos_3272 * (-2));
			t_sample sin_3273 = sin(mul_3274);
			t_sample mul_3271 = (sin_3273 * ((t_sample)0.5));
			t_sample div_3270 = (mul_3271 * ((t_sample)0.33333333333333));
			t_sample rsub_3265 = (((int)1) - div_3270);
			t_sample add_3269 = (div_3270 + ((int)1));
			t_sample rdiv_3268 = safediv(((int)1), add_3269);
			t_sample mul_3264 = (rdiv_3268 * rsub_3265);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((mul_3264 > __m_slide_58) ? iup_59 : idown_60) * (mul_3264 - __m_slide_58))));
			t_sample slide_3261 = __m_slide_58;
			t_sample gen_3277 = slide_3261;
			t_sample mul_3266 = (rdiv_3268 * mul_3267);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((mul_3266 > __m_slide_61) ? iup_62 : idown_63) * (mul_3266 - __m_slide_61))));
			t_sample slide_3262 = __m_slide_61;
			t_sample gen_3276 = slide_3262;
			t_sample mul_3297 = (add_3254 * gen_3277);
			t_sample mul_3294 = (m_history_4 * gen_3276);
			t_sample mul_3292 = (m_history_6 * ((int)1));
			t_sample mul_3288 = (m_history_5 * gen_3277);
			t_sample mul_3290 = (m_history_3 * gen_3276);
			t_sample sub_3296 = (((mul_3292 + mul_3294) + mul_3297) - (mul_3290 + mul_3288));
			t_sample gen_3302 = sub_3296;
			t_sample history_3293_next_3298 = fixdenorm(m_history_4);
			t_sample history_3289_next_3299 = fixdenorm(m_history_3);
			t_sample history_3295_next_3300 = fixdenorm(add_3254);
			t_sample history_3291_next_3301 = fixdenorm(sub_3296);
			t_sample mul_3202 = ((gen_3302 + gen_3244) * ((t_sample)0.5));
			t_sample dcblock_3247 = __m_dcblock_64(mul_3202);
			t_sample mul_3245 = (((gate_3105 + gen_3302) + gen_3244) * scale_3357);
			t_sample div_3079 = (mul_3245 * ((t_sample)0.5));
			t_sample add_3248 = (gate_3104 + div_3079);
			t_sample out1 = add_3248;
			t_sample history_3253_next_3306 = fixdenorm(dcblock_3116);
			t_sample history_3112_next_3307 = fixdenorm(dcblock_3247);
			m_history_22 = history_3090_next_3092;
			m_history_20 = history_3086_next_3094;
			m_history_21 = history_3088_next_3093;
			m_history_19 = history_3107_next_3109;
			m_history_18 = history_3150_next_3155;
			m_history_15 = history_3148_next_3158;
			m_history_16 = history_3152_next_3157;
			m_history_17 = history_3146_next_3156;
			m_history_14 = history_3192_next_3197;
			m_history_11 = history_3190_next_3200;
			m_history_12 = history_3194_next_3199;
			m_history_13 = history_3188_next_3198;
			m_history_10 = history_3231_next_3240;
			m_history_7 = history_3233_next_3243;
			m_history_8 = history_3237_next_3242;
			m_history_9 = history_3235_next_3241;
			m_history_6 = history_3293_next_3298;
			m_history_3 = history_3291_next_3301;
			m_history_4 = history_3295_next_3300;
			m_history_5 = history_3289_next_3299;
			m_history_2 = history_3253_next_3306;
			m_history_1 = history_3112_next_3307;
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
	inline void set_knob6_diffusion(t_param _value) {
		m_knob6_diffusion_24 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_25 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
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
		case 0: *value = self->m_knob3_depth_23; break;
		case 1: *value = self->m_knob4_rate_27; break;
		case 2: *value = self->m_knob5_fb_25; break;
		case 3: *value = self->m_knob6_diffusion_24; break;
		case 4: *value = self->m_sw_28; break;
		case 5: *value = self->m_sw_26; break;
		
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
	// initialize parameter 2 ("m_knob5_fb_25")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_25;
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
	// initialize parameter 4 ("m_sw_28")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
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
	// initialize parameter 5 ("m_sw_26")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_26;
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
