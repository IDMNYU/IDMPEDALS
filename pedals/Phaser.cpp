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
	t_sample m_knob5_fb_28;
	t_sample __m_slide_51;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_slide_46;
	t_sample m_history_7;
	t_sample m_knob3_depth_27;
	t_sample m_knob4_rate_25;
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
		m_knob4_rate_25 = 0.1;
		m_sw_26 = ((int)0);
		m_knob3_depth_27 = 1;
		m_knob5_fb_28 = ((int)0);
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
		t_sample sub_3613 = (m_knob5_fb_28 - ((t_sample)0.5));
		t_sample scale_3610 = ((safepow((sub_3613 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		t_sample mstosamps_3214 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_3213 = (((int)100) * (samplerate * 0.001));
		samples_to_seconds = (1 / samplerate);
		t_sample mul_3366 = (m_knob6_diffusion_24 * ((int)3));
		t_sample div_3364 = (mul_3366 * ((t_sample)0.125));
		t_sample mul_3367 = (m_knob6_diffusion_24 * ((int)1));
		t_sample div_3365 = (mul_3367 * ((t_sample)0.125));
		t_sample mul_3373 = (m_knob6_diffusion_24 * ((int)2));
		t_sample div_3371 = (mul_3373 * ((t_sample)0.125));
		t_sample mul_3374 = (m_knob6_diffusion_24 * ((int)0));
		t_sample div_3372 = (mul_3374 * ((t_sample)0.125));
		t_sample iup_33 = (1 / maximum(1, abs(mstosamps_3214)));
		t_sample idown_34 = (1 / maximum(1, abs(mstosamps_3213)));
		t_sample div_3247 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_37 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_38 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_40 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_41 = (1 / maximum(1, abs(((int)5))));
		t_sample div_3289 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_44 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)5))));
		t_sample div_3332 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_52 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)5))));
		t_sample div_3390 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample mix_3607 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob4_rate_25 - m_history_22)));
			t_sample mix_3204 = mix_3607;
			t_sample mix_3608 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_3204 - m_history_21)));
			t_sample mix_3202 = mix_3608;
			t_sample mix_3609 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_3202 - m_history_20)));
			t_sample mix_3200 = mix_3609;
			t_sample gen_3210 = mix_3200;
			t_sample history_3205_next_3207 = fixdenorm(mix_3204);
			t_sample history_3203_next_3208 = fixdenorm(mix_3202);
			t_sample history_3201_next_3209 = fixdenorm(mix_3200);
			t_sample expr_3420 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_3210)))));
			t_sample sah_3223 = __m_sah_29(m_history_19, m_sw_23, ((int)0));
			t_sample gen_3225 = sah_3223;
			t_sample rsub_3221 = (((int)1) - sah_3223);
			t_sample history_3222_next_3224 = fixdenorm(rsub_3221);
			t_sample out3 = gen_3225;
			t_sample add_3226 = (gen_3225 + ((int)1));
			t_sample choice_30 = int(add_3226);
			t_sample gate_3219 = (((choice_30 >= 1) && (choice_30 < 2)) ? in1 : 0);
			t_sample gate_3220 = ((choice_30 >= 2) ? in1 : 0);
			t_sample mul_3229 = (m_history_1 * m_knob5_fb_28);
			t_sample add_3228 = (gate_3220 + mul_3229);
			t_sample mul_3419 = (expr_3420 * ((t_sample)7.5));
			t_sample phasor_3375 = __m_phasor_31(mul_3419, samples_to_seconds);
			t_sample mul_3370 = (m_history_2 * m_knob5_fb_28);
			t_sample add_3369 = (gate_3220 + mul_3370);
			t_sample abs_3193 = fabs(gate_3220);
			t_sample mul_3192 = (abs_3193 * ((int)30));
			t_sample switch_3217 = (m_sw_26 ? mul_3192 : ((int)1));
			__m_slide_32 = fixdenorm((__m_slide_32 + (((switch_3217 > __m_slide_32) ? iup_33 : idown_34) * (switch_3217 - __m_slide_32))));
			t_sample slide_3218 = __m_slide_32;
			t_sample mul_3197 = (m_knob3_depth_27 * slide_3218);
			t_sample clamp_3216 = ((mul_3197 <= ((int)0)) ? ((int)0) : ((mul_3197 >= ((int)1)) ? ((int)1) : mul_3197));
			t_sample out4 = clamp_3216;
			t_sample add_3256 = (phasor_3375 + div_3364);
			t_sample mod_3257 = safemod(add_3256, ((int)1));
			__m_cycle_35.phase(mod_3257);
			t_sample cycle_3254 = __m_cycle_35(__sinedata);
			t_sample cycleindex_3255 = __m_cycle_35.phase();
			t_sample add_3252 = (cycle_3254 + ((int)1));
			t_sample div_3251 = (add_3252 * ((t_sample)0.5));
			t_sample mul_3253 = (div_3251 * clamp_3216);
			t_sample sub_3617 = (mul_3253 - ((int)0));
			t_sample scale_3614 = ((safepow((sub_3617 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_3258 = scale_3614;
			t_sample mtof_3259 = mtof(scale_3258, ((int)440));
			t_sample mul_3246 = (mtof_3259 * div_3247);
			t_sample cos_3244 = cos(mul_3246);
			t_sample mul_3239 = (cos_3244 * (-2));
			t_sample sin_3245 = sin(mul_3246);
			t_sample mul_3243 = (sin_3245 * ((t_sample)0.5));
			t_sample div_3242 = (mul_3243 * ((t_sample)0.33333333333333));
			t_sample rsub_3237 = (((int)1) - div_3242);
			t_sample add_3241 = (div_3242 + ((int)1));
			t_sample rdiv_3240 = safediv(((int)1), add_3241);
			t_sample mul_3236 = (rdiv_3240 * rsub_3237);
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_3236 > __m_slide_36) ? iup_37 : idown_38) * (mul_3236 - __m_slide_36))));
			t_sample slide_3233 = __m_slide_36;
			t_sample gen_3249 = slide_3233;
			t_sample mul_3238 = (rdiv_3240 * mul_3239);
			__m_slide_39 = fixdenorm((__m_slide_39 + (((mul_3238 > __m_slide_39) ? iup_40 : idown_41) * (mul_3238 - __m_slide_39))));
			t_sample slide_3234 = __m_slide_39;
			t_sample gen_3248 = slide_3234;
			t_sample mul_3269 = (add_3228 * gen_3249);
			t_sample mul_3266 = (m_history_16 * gen_3248);
			t_sample mul_3264 = (m_history_18 * ((int)1));
			t_sample mul_3260 = (m_history_17 * gen_3249);
			t_sample mul_3262 = (m_history_15 * gen_3248);
			t_sample sub_3268 = (((mul_3264 + mul_3266) + mul_3269) - (mul_3262 + mul_3260));
			t_sample gen_3274 = sub_3268;
			t_sample history_3265_next_3270 = fixdenorm(m_history_16);
			t_sample history_3261_next_3271 = fixdenorm(m_history_15);
			t_sample history_3267_next_3272 = fixdenorm(add_3228);
			t_sample history_3263_next_3273 = fixdenorm(sub_3268);
			t_sample add_3298 = (phasor_3375 + div_3365);
			t_sample mod_3299 = safemod(add_3298, ((int)1));
			__m_cycle_42.phase(mod_3299);
			t_sample cycle_3296 = __m_cycle_42(__sinedata);
			t_sample cycleindex_3297 = __m_cycle_42.phase();
			t_sample add_3294 = (cycle_3296 + ((int)1));
			t_sample div_3293 = (add_3294 * ((t_sample)0.5));
			t_sample mul_3295 = (div_3293 * clamp_3216);
			t_sample sub_3621 = (mul_3295 - ((int)0));
			t_sample scale_3618 = ((safepow((sub_3621 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_3300 = scale_3618;
			t_sample mtof_3301 = mtof(scale_3300, ((int)440));
			t_sample mul_3288 = (mtof_3301 * div_3289);
			t_sample cos_3286 = cos(mul_3288);
			t_sample mul_3281 = (cos_3286 * (-2));
			t_sample sin_3287 = sin(mul_3288);
			t_sample mul_3285 = (sin_3287 * ((t_sample)0.5));
			t_sample div_3284 = (mul_3285 * ((t_sample)0.33333333333333));
			t_sample rsub_3279 = (((int)1) - div_3284);
			t_sample add_3283 = (div_3284 + ((int)1));
			t_sample rdiv_3282 = safediv(((int)1), add_3283);
			t_sample mul_3280 = (rdiv_3282 * mul_3281);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((mul_3280 > __m_slide_43) ? iup_44 : idown_45) * (mul_3280 - __m_slide_43))));
			t_sample slide_3276 = __m_slide_43;
			t_sample gen_3290 = slide_3276;
			t_sample mul_3278 = (rdiv_3282 * rsub_3279);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((mul_3278 > __m_slide_46) ? iup_47 : idown_48) * (mul_3278 - __m_slide_46))));
			t_sample slide_3275 = __m_slide_46;
			t_sample gen_3291 = slide_3275;
			t_sample mul_3311 = (add_3228 * gen_3291);
			t_sample mul_3308 = (m_history_12 * gen_3290);
			t_sample mul_3306 = (m_history_14 * ((int)1));
			t_sample mul_3302 = (m_history_13 * gen_3291);
			t_sample mul_3304 = (m_history_11 * gen_3290);
			t_sample sub_3310 = (((mul_3306 + mul_3308) + mul_3311) - (mul_3304 + mul_3302));
			t_sample gen_3316 = sub_3310;
			t_sample history_3307_next_3312 = fixdenorm(m_history_12);
			t_sample history_3303_next_3313 = fixdenorm(m_history_11);
			t_sample history_3309_next_3314 = fixdenorm(add_3228);
			t_sample history_3305_next_3315 = fixdenorm(sub_3310);
			t_sample mul_3230 = ((gen_3316 + gen_3274) * ((t_sample)0.5));
			t_sample dcblock_3231 = __m_dcblock_49(mul_3230);
			t_sample mul_3232 = (((gate_3220 + gen_3316) + gen_3274) * scale_3610);
			t_sample div_3195 = (mul_3232 * ((t_sample)0.5));
			t_sample add_3361 = (gate_3219 + div_3195);
			t_sample out2 = add_3361;
			t_sample add_3341 = (phasor_3375 + div_3371);
			t_sample mod_3342 = safemod(add_3341, ((int)1));
			__m_cycle_50.phase(mod_3342);
			t_sample cycle_3339 = __m_cycle_50(__sinedata);
			t_sample cycleindex_3340 = __m_cycle_50.phase();
			t_sample add_3337 = (cycle_3339 + ((int)1));
			t_sample div_3336 = (add_3337 * ((t_sample)0.5));
			t_sample mul_3338 = (div_3336 * clamp_3216);
			t_sample sub_3625 = (mul_3338 - ((int)0));
			t_sample scale_3622 = ((safepow((sub_3625 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_3343 = scale_3622;
			t_sample mtof_3344 = mtof(scale_3343, ((int)440));
			t_sample mul_3331 = (mtof_3344 * div_3332);
			t_sample cos_3329 = cos(mul_3331);
			t_sample mul_3324 = (cos_3329 * (-2));
			t_sample sin_3330 = sin(mul_3331);
			t_sample mul_3328 = (sin_3330 * ((t_sample)0.5));
			t_sample div_3327 = (mul_3328 * ((t_sample)0.33333333333333));
			t_sample rsub_3322 = (((int)1) - div_3327);
			t_sample add_3326 = (div_3327 + ((int)1));
			t_sample rdiv_3325 = safediv(((int)1), add_3326);
			t_sample mul_3321 = (rdiv_3325 * rsub_3322);
			__m_slide_51 = fixdenorm((__m_slide_51 + (((mul_3321 > __m_slide_51) ? iup_52 : idown_53) * (mul_3321 - __m_slide_51))));
			t_sample slide_3318 = __m_slide_51;
			t_sample gen_3334 = slide_3318;
			t_sample mul_3323 = (rdiv_3325 * mul_3324);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((mul_3323 > __m_slide_54) ? iup_55 : idown_56) * (mul_3323 - __m_slide_54))));
			t_sample slide_3319 = __m_slide_54;
			t_sample gen_3333 = slide_3319;
			t_sample mul_3354 = (add_3369 * gen_3334);
			t_sample mul_3351 = (m_history_8 * gen_3333);
			t_sample mul_3349 = (m_history_9 * ((int)1));
			t_sample mul_3345 = (m_history_10 * gen_3334);
			t_sample mul_3347 = (m_history_7 * gen_3333);
			t_sample sub_3353 = (((mul_3349 + mul_3351) + mul_3354) - (mul_3347 + mul_3345));
			t_sample gen_3359 = sub_3353;
			t_sample history_3346_next_3355 = fixdenorm(m_history_7);
			t_sample history_3350_next_3356 = fixdenorm(m_history_8);
			t_sample history_3352_next_3357 = fixdenorm(add_3369);
			t_sample history_3348_next_3358 = fixdenorm(sub_3353);
			t_sample add_3399 = (phasor_3375 + div_3372);
			t_sample mod_3400 = safemod(add_3399, ((int)1));
			__m_cycle_57.phase(mod_3400);
			t_sample cycle_3397 = __m_cycle_57(__sinedata);
			t_sample cycleindex_3398 = __m_cycle_57.phase();
			t_sample add_3395 = (cycle_3397 + ((int)1));
			t_sample div_3394 = (add_3395 * ((t_sample)0.5));
			t_sample mul_3396 = (div_3394 * clamp_3216);
			t_sample sub_3629 = (mul_3396 - ((int)0));
			t_sample scale_3626 = ((safepow((sub_3629 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_3401 = scale_3626;
			t_sample mtof_3402 = mtof(scale_3401, ((int)440));
			t_sample mul_3389 = (mtof_3402 * div_3390);
			t_sample cos_3387 = cos(mul_3389);
			t_sample mul_3382 = (cos_3387 * (-2));
			t_sample sin_3388 = sin(mul_3389);
			t_sample mul_3386 = (sin_3388 * ((t_sample)0.5));
			t_sample div_3385 = (mul_3386 * ((t_sample)0.33333333333333));
			t_sample rsub_3380 = (((int)1) - div_3385);
			t_sample add_3384 = (div_3385 + ((int)1));
			t_sample rdiv_3383 = safediv(((int)1), add_3384);
			t_sample mul_3379 = (rdiv_3383 * rsub_3380);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((mul_3379 > __m_slide_58) ? iup_59 : idown_60) * (mul_3379 - __m_slide_58))));
			t_sample slide_3376 = __m_slide_58;
			t_sample gen_3392 = slide_3376;
			t_sample mul_3381 = (rdiv_3383 * mul_3382);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((mul_3381 > __m_slide_61) ? iup_62 : idown_63) * (mul_3381 - __m_slide_61))));
			t_sample slide_3377 = __m_slide_61;
			t_sample gen_3391 = slide_3377;
			t_sample mul_3412 = (add_3369 * gen_3392);
			t_sample mul_3409 = (m_history_4 * gen_3391);
			t_sample mul_3407 = (m_history_5 * ((int)1));
			t_sample mul_3403 = (m_history_6 * gen_3392);
			t_sample mul_3405 = (m_history_3 * gen_3391);
			t_sample sub_3411 = (((mul_3407 + mul_3409) + mul_3412) - (mul_3405 + mul_3403));
			t_sample gen_3417 = sub_3411;
			t_sample history_3404_next_3413 = fixdenorm(m_history_3);
			t_sample history_3408_next_3414 = fixdenorm(m_history_4);
			t_sample history_3410_next_3415 = fixdenorm(add_3369);
			t_sample history_3406_next_3416 = fixdenorm(sub_3411);
			t_sample mul_3317 = ((gen_3417 + gen_3359) * ((t_sample)0.5));
			t_sample dcblock_3362 = __m_dcblock_64(mul_3317);
			t_sample mul_3360 = (((gate_3220 + gen_3417) + gen_3359) * scale_3610);
			t_sample div_3194 = (mul_3360 * ((t_sample)0.5));
			t_sample add_3363 = (gate_3219 + div_3194);
			t_sample out1 = add_3363;
			t_sample history_3368_next_3421 = fixdenorm(dcblock_3231);
			t_sample history_3227_next_3422 = fixdenorm(dcblock_3362);
			m_history_22 = history_3205_next_3207;
			m_history_20 = history_3201_next_3209;
			m_history_21 = history_3203_next_3208;
			m_history_19 = history_3222_next_3224;
			m_history_18 = history_3265_next_3270;
			m_history_15 = history_3263_next_3273;
			m_history_16 = history_3267_next_3272;
			m_history_17 = history_3261_next_3271;
			m_history_14 = history_3307_next_3312;
			m_history_11 = history_3305_next_3315;
			m_history_12 = history_3309_next_3314;
			m_history_13 = history_3303_next_3313;
			m_history_10 = history_3346_next_3355;
			m_history_7 = history_3348_next_3358;
			m_history_8 = history_3352_next_3357;
			m_history_9 = history_3350_next_3356;
			m_history_6 = history_3404_next_3413;
			m_history_3 = history_3406_next_3416;
			m_history_4 = history_3410_next_3415;
			m_history_5 = history_3408_next_3414;
			m_history_2 = history_3368_next_3421;
			m_history_1 = history_3227_next_3422;
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
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_28 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
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
		case 0: *value = self->m_knob3_depth_27; break;
		case 1: *value = self->m_knob4_rate_25; break;
		case 2: *value = self->m_knob5_fb_28; break;
		case 3: *value = self->m_knob6_diffusion_24; break;
		case 4: *value = self->m_sw_23; break;
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
	// initialize parameter 0 ("m_knob3_depth_27")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_25")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_fb_28")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_28;
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
