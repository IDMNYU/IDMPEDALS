#include "Glitch.h"

namespace Glitch {

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
	Change __m_change_89;
	Change __m_change_83;
	Change __m_change_95;
	Change __m_change_101;
	DCBlock __m_dcblock_107;
	DCBlock __m_dcblock_108;
	Data m_segments_34;
	Delay m_delay_11;
	Delay m_delay_13;
	Delay m_delay_12;
	Delay m_delay_15;
	Delay m_delay_16;
	Delay m_delay_10;
	Delay m_delay_14;
	Delay m_delay_9;
	PlusEquals __m_pluseq_53;
	PlusEquals __m_pluseq_58;
	PlusEquals __m_pluseq_48;
	PlusEquals __m_pluseq_102;
	PlusEquals __m_pluseq_37;
	PlusEquals __m_pluseq_63;
	PlusEquals __m_pluseq_96;
	PlusEquals __m_pluseq_73;
	PlusEquals __m_pluseq_68;
	PlusEquals __m_pluseq_90;
	PlusEquals __m_pluseq_78;
	PlusEquals __m_pluseq_84;
	PlusEquals __m_pluseq_43;
	Sah __m_sah_65;
	Sah __m_sah_49;
	Sah __m_sah_50;
	Sah __m_sah_75;
	Sah __m_sah_45;
	Sah __m_sah_44;
	Sah __m_sah_74;
	Sah __m_sah_55;
	Sah __m_sah_60;
	Sah __m_sah_54;
	Sah __m_sah_59;
	Sah __m_sah_70;
	Sah __m_sah_69;
	Sah __m_sah_79;
	Sah __m_sah_85;
	Sah __m_sah_98;
	Sah __m_sah_103;
	Sah __m_sah_104;
	Sah __m_sah_80;
	Sah __m_sah_97;
	Sah __m_sah_91;
	Sah __m_sah_35;
	Sah __m_sah_92;
	Sah __m_sah_86;
	Sah __m_sah_64;
	int vectorsize;
	int __exception;
	t_sample m_history_17;
	t_sample m_history_2;
	t_sample m_history_1;
	t_sample m_knob4_buflen_32;
	t_sample m_knob5_glitchlen_33;
	t_sample m_history_3;
	t_sample m_sw_31;
	t_sample samplerate;
	t_sample m_sw_27;
	t_sample m_knob6_density_30;
	t_sample m_knob3_thresh_28;
	t_sample m_knob1_wetdry_29;
	t_sample m_history_25;
	t_sample m_history_4;
	t_sample m_history_23;
	t_sample m_history_8;
	t_sample m_history_20;
	t_sample m_history_19;
	t_sample m_history_18;
	t_sample m_history_24;
	t_sample m_history_21;
	t_sample m_history_22;
	t_sample m_history_5;
	t_sample m_history_7;
	t_sample m_history_6;
	t_sample __m_slide_40;
	t_sample m_history_26;
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
		m_delay_9.reset("m_delay_9", ((int)2));
		m_delay_10.reset("m_delay_10", ((int)9));
		m_delay_11.reset("m_delay_11", ((int)3));
		m_delay_12.reset("m_delay_12", ((int)5));
		m_delay_13.reset("m_delay_13", ((int)5));
		m_delay_14.reset("m_delay_14", ((int)7));
		m_delay_15.reset("m_delay_15", ((int)3));
		m_delay_16.reset("m_delay_16", ((int)4));
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_history_23 = ((int)0);
		m_history_24 = ((int)0);
		m_history_25 = ((int)0);
		m_history_26 = ((int)0);
		m_sw_27 = ((int)0);
		m_knob3_thresh_28 = ((int)0);
		m_knob1_wetdry_29 = ((int)0);
		m_knob6_density_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_knob4_buflen_32 = ((int)0);
		m_knob5_glitchlen_33 = ((int)0);
		m_segments_34.reset("segments", ((int)480000), ((int)1));
		__m_sah_35.reset(0);
		__m_pluseq_37.reset(0);
		__m_slide_40 = 0;
		__m_pluseq_43.reset(0);
		__m_sah_44.reset(0);
		__m_sah_45.reset(0);
		__m_pluseq_48.reset(0);
		__m_sah_49.reset(0);
		__m_sah_50.reset(0);
		__m_pluseq_53.reset(0);
		__m_sah_54.reset(0);
		__m_sah_55.reset(0);
		__m_pluseq_58.reset(0);
		__m_sah_59.reset(0);
		__m_sah_60.reset(0);
		__m_pluseq_63.reset(0);
		__m_sah_64.reset(0);
		__m_sah_65.reset(0);
		__m_pluseq_68.reset(0);
		__m_sah_69.reset(0);
		__m_sah_70.reset(0);
		__m_pluseq_73.reset(0);
		__m_sah_74.reset(0);
		__m_sah_75.reset(0);
		__m_pluseq_78.reset(0);
		__m_sah_79.reset(0);
		__m_sah_80.reset(0);
		__m_change_83.reset(0);
		__m_pluseq_84.reset(0);
		__m_sah_85.reset(0);
		__m_sah_86.reset(0);
		__m_change_89.reset(0);
		__m_pluseq_90.reset(0);
		__m_sah_91.reset(0);
		__m_sah_92.reset(0);
		__m_change_95.reset(0);
		__m_pluseq_96.reset(0);
		__m_sah_97.reset(0);
		__m_sah_98.reset(0);
		__m_change_101.reset(0);
		__m_pluseq_102.reset(0);
		__m_sah_103.reset(0);
		__m_sah_104.reset(0);
		__m_dcblock_107.reset();
		__m_dcblock_108.reset();
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
		int segments_dim = m_segments_34.dim;
		int segments_channels = m_segments_34.channels;
		t_sample mstosamps_3263 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_3261 = (((int)100) * (samplerate * 0.001));
		t_sample iup_41 = (1 / maximum(1, abs(mstosamps_3263)));
		t_sample idown_42 = (1 / maximum(1, abs(mstosamps_3261)));
		t_sample mstosamps_2874 = (((int)1) * (samplerate * 0.001));
		t_sample mul_3209 = (m_knob3_thresh_28 * ((t_sample)0.95));
		t_sample mstosamps_2863 = (((int)1) * (samplerate * 0.001));
		t_sample mul_3208 = (m_knob3_thresh_28 * ((t_sample)1.03));
		t_sample mstosamps_2852 = (((int)1) * (samplerate * 0.001));
		t_sample mul_3207 = (m_knob3_thresh_28 * ((t_sample)0.98));
		t_sample mstosamps_2841 = (((int)1) * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_3269 = __m_sah_35(m_history_26, m_sw_27, ((int)0));
			t_sample gen_3271 = sah_3269;
			t_sample rsub_3267 = (((int)1) - sah_3269);
			t_sample history_3268_next_3270 = fixdenorm(rsub_3267);
			t_sample out3 = gen_3271;
			t_sample mix_3364 = (m_history_25 + (((t_sample)0.003926980723806) * (m_knob4_buflen_32 - m_history_25)));
			t_sample mix_2889 = mix_3364;
			t_sample mix_3365 = (m_history_24 + (((t_sample)0.003926980723806) * (mix_2889 - m_history_24)));
			t_sample mix_2887 = mix_3365;
			t_sample mix_3366 = (m_history_23 + (((t_sample)0.003926980723806) * (mix_2887 - m_history_23)));
			t_sample mix_2885 = mix_3366;
			t_sample gen_3247 = mix_2885;
			t_sample history_2890_next_2892 = fixdenorm(mix_2889);
			t_sample history_2888_next_2893 = fixdenorm(mix_2887);
			t_sample history_2886_next_2894 = fixdenorm(mix_2885);
			t_sample expr_3275 = (((int)1) - sqrt((((int)1) - gen_3247)));
			t_sample add_3274 = (gen_3271 + ((int)1));
			t_sample choice_36 = int(add_3274);
			t_sample gate_3272 = (((choice_36 >= 1) && (choice_36 < 2)) ? in1 : 0);
			t_sample gate_3273 = ((choice_36 >= 2) ? in1 : 0);
			t_sample mix_3367 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob1_wetdry_29 - m_history_22)));
			t_sample mix_3285 = mix_3367;
			t_sample mix_3368 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_3285 - m_history_21)));
			t_sample mix_3283 = mix_3368;
			t_sample mix_3369 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_3283 - m_history_20)));
			t_sample mix_3282 = mix_3369;
			t_sample gen_2895 = mix_3282;
			t_sample history_2890_next_3281 = fixdenorm(mix_3285);
			t_sample history_2888_next_3278 = fixdenorm(mix_3283);
			t_sample history_2886_next_3276 = fixdenorm(mix_3282);
			t_sample sqrt_2881 = sqrt(gen_2895);
			t_sample rsub_2897 = (((int)1) - gen_2895);
			t_sample sqrt_2896 = sqrt(rsub_2897);
			t_sample mul_2884 = (sqrt_2896 * gate_3273);
			t_sample plusequals_3265 = __m_pluseq_37.post(((int)1), m_history_1, 0);
			t_sample switch_3245 = (m_sw_31 ? ((int)-1) : plusequals_3265);
			int index_trunc_38 = fixnan(floor(switch_3245));
			bool index_ignore_39 = ((index_trunc_38 >= segments_dim) || (index_trunc_38 < 0));
			if ((!index_ignore_39)) {
				m_segments_34.write(gate_3273, index_trunc_38, 0);
				
			};
			t_sample mul_3248 = (expr_3275 * ((int)480000));
			int gte_3251 = (plusequals_3265 >= mul_3248);
			int eq_3250 = (gte_3251 == ((int)1));
			t_sample abs_3266 = fabs(gate_3273);
			t_sample mul_2899 = (abs_3266 * ((int)30));
			__m_slide_40 = fixdenorm((__m_slide_40 + (((mul_2899 > __m_slide_40) ? iup_41 : idown_42) * (mul_2899 - __m_slide_40))));
			t_sample slide_3264 = __m_slide_40;
			t_sample clamp_3259 = ((slide_3264 <= ((int)0)) ? ((int)0) : ((slide_3264 >= ((int)1)) ? ((int)1) : slide_3264));
			t_sample out4 = clamp_3259;
			t_sample mix_3370 = (m_history_19 + (((t_sample)0.003926980723806) * (m_knob6_density_30 - m_history_19)));
			t_sample mix_3298 = mix_3370;
			t_sample mix_3371 = (m_history_18 + (((t_sample)0.003926980723806) * (mix_3298 - m_history_18)));
			t_sample mix_3292 = mix_3371;
			t_sample mix_3372 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_3292 - m_history_17)));
			t_sample mix_3297 = mix_3372;
			t_sample gen_3132 = mix_3297;
			t_sample history_2890_next_3295 = fixdenorm(mix_3298);
			t_sample history_2888_next_3293 = fixdenorm(mix_3292);
			t_sample history_2886_next_3289 = fixdenorm(mix_3297);
			t_sample sub_3376 = (gen_3132 - ((int)0));
			t_sample scale_3373 = ((safepow((sub_3376 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_2929 = m_delay_16.read_step(((int)8));
			t_sample tap_2931 = m_delay_15.read_step(((int)8));
			t_sample tap_2925 = m_delay_14.read_step(((int)8));
			t_sample tap_2927 = m_delay_13.read_step(((int)8));
			t_sample tap_2917 = m_delay_12.read_step(((int)8));
			t_sample tap_2919 = m_delay_11.read_step(((int)8));
			t_sample tap_2921 = m_delay_10.read_step(((int)9));
			t_sample tap_2923 = m_delay_9.read_step(((int)8));
			t_sample mul_2913 = (gen_3132 * ((int)12));
			int gte_2911 = (mul_2913 >= ((int)1));
			int gte_2910 = (mul_2913 >= ((int)2));
			int gte_2909 = (mul_2913 >= ((int)3));
			int gte_2912 = (mul_2913 >= ((int)0));
			int gte_2907 = (mul_2913 >= ((int)5));
			int gte_2908 = (mul_2913 >= ((int)4));
			int gte_2905 = (mul_2913 >= ((int)7));
			int gte_2906 = (mul_2913 >= ((int)6));
			int gte_2901 = (mul_2913 >= ((int)11));
			int gte_2902 = (mul_2913 >= ((int)10));
			int gte_2903 = (mul_2913 >= ((int)9));
			int gte_2904 = (mul_2913 >= ((int)8));
			t_sample mix_3377 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob5_glitchlen_33 - m_history_8)));
			t_sample mix_3311 = mix_3377;
			t_sample mix_3378 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_3311 - m_history_7)));
			t_sample mix_3303 = mix_3378;
			t_sample mix_3379 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_3303 - m_history_6)));
			t_sample mix_3307 = mix_3379;
			t_sample gen_3134 = mix_3307;
			t_sample history_2890_next_3302 = fixdenorm(mix_3311);
			t_sample history_2888_next_3308 = fixdenorm(mix_3303);
			t_sample history_2886_next_3305 = fixdenorm(mix_3307);
			t_sample mul_2878 = (mul_3248 * gen_3134);
			t_sample clamp_3133 = ((mul_2878 <= ((int)50)) ? ((int)50) : ((mul_2878 >= ((int)480000)) ? ((int)480000) : mul_2878));
			t_sample plusequals_3093 = __m_pluseq_43.post(((int)1), tap_2929, 0);
			t_sample noise_3088 = noise();
			t_sample abs_3087 = fabs(noise_3088);
			t_sample sub_3079 = (clamp_3133 - ((int)50));
			t_sample mul_3086 = (abs_3087 * sub_3079);
			t_sample sah_3089 = __m_sah_44(mul_3086, tap_2929, ((t_sample)0.5));
			t_sample add_3076 = (sah_3089 + ((int)50));
			t_sample mod_3085 = safemod(plusequals_3093, add_3076);
			t_sample div_3082 = safediv(mod_3085, add_3076);
			t_sample expr_3098 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_3082))));
			t_sample noise_3096 = noise();
			t_sample abs_3095 = fabs(noise_3096);
			t_sample mul_3094 = (abs_3095 * mul_3248);
			t_sample sah_3097 = __m_sah_45(mul_3094, tap_2929, ((t_sample)0.5));
			t_sample add_3091 = (sah_3097 + mod_3085);
			t_sample mod_3090 = safemod(add_3091, mul_3248);
			t_sample switch_3077 = (gte_2907 ? mod_3090 : ((int)-1));
			int index_trunc_46 = fixnan(floor(switch_3077));
			bool index_ignore_47 = ((index_trunc_46 >= segments_dim) || (index_trunc_46 < 0));
			// samples segments channel 1;
			t_sample sample_segments_3083 = (index_ignore_47 ? 0 : m_segments_34.read(index_trunc_46, 0));
			t_sample index_segments_3084 = switch_3077;
			t_sample mul_3080 = (sample_segments_3083 * expr_3098);
			t_sample plusequals_3117 = __m_pluseq_48.post(((int)1), tap_2931, 0);
			t_sample noise_3112 = noise();
			t_sample abs_3111 = fabs(noise_3112);
			t_sample sub_3103 = (clamp_3133 - ((int)50));
			t_sample mul_3110 = (abs_3111 * sub_3103);
			t_sample sah_3113 = __m_sah_49(mul_3110, tap_2931, ((t_sample)0.5));
			t_sample add_3100 = (sah_3113 + ((int)50));
			t_sample mod_3109 = safemod(plusequals_3117, add_3100);
			t_sample div_3106 = safediv(mod_3109, add_3100);
			t_sample expr_3122 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_3106))));
			t_sample noise_3120 = noise();
			t_sample abs_3119 = fabs(noise_3120);
			t_sample mul_3118 = (abs_3119 * mul_3248);
			t_sample sah_3121 = __m_sah_50(mul_3118, tap_2931, ((t_sample)0.5));
			t_sample add_3115 = (sah_3121 + mod_3109);
			t_sample mod_3114 = safemod(add_3115, mul_3248);
			t_sample switch_3101 = (gte_2908 ? mod_3114 : ((int)-1));
			int index_trunc_51 = fixnan(floor(switch_3101));
			bool index_ignore_52 = ((index_trunc_51 >= segments_dim) || (index_trunc_51 < 0));
			// samples segments channel 1;
			t_sample sample_segments_3107 = (index_ignore_52 ? 0 : m_segments_34.read(index_trunc_51, 0));
			t_sample index_segments_3108 = switch_3101;
			t_sample mul_3104 = (sample_segments_3107 * expr_3122);
			t_sample mul_3131 = ((mul_3104 + mul_3080) * ((t_sample)0.3));
			t_sample mul_3130 = ((mul_3104 + mul_3080) * ((t_sample)0.4));
			t_sample plusequals_3045 = __m_pluseq_53.post(((int)1), tap_2925, 0);
			t_sample noise_3040 = noise();
			t_sample abs_3039 = fabs(noise_3040);
			t_sample sub_3031 = (clamp_3133 - ((int)50));
			t_sample mul_3038 = (abs_3039 * sub_3031);
			t_sample sah_3041 = __m_sah_54(mul_3038, tap_2925, ((t_sample)0.5));
			t_sample add_3028 = (sah_3041 + ((int)50));
			t_sample mod_3037 = safemod(plusequals_3045, add_3028);
			t_sample div_3034 = safediv(mod_3037, add_3028);
			t_sample expr_3050 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_3034))));
			t_sample noise_3048 = noise();
			t_sample abs_3047 = fabs(noise_3048);
			t_sample mul_3046 = (abs_3047 * mul_3248);
			t_sample sah_3049 = __m_sah_55(mul_3046, tap_2925, ((t_sample)0.5));
			t_sample add_3043 = (sah_3049 + mod_3037);
			t_sample mod_3042 = safemod(add_3043, mul_3248);
			t_sample switch_3029 = (gte_2905 ? mod_3042 : ((int)-1));
			int index_trunc_56 = fixnan(floor(switch_3029));
			bool index_ignore_57 = ((index_trunc_56 >= segments_dim) || (index_trunc_56 < 0));
			// samples segments channel 1;
			t_sample sample_segments_3035 = (index_ignore_57 ? 0 : m_segments_34.read(index_trunc_56, 0));
			t_sample index_segments_3036 = switch_3029;
			t_sample mul_3032 = (sample_segments_3035 * expr_3050);
			t_sample plusequals_3069 = __m_pluseq_58.post(((int)1), tap_2927, 0);
			t_sample noise_3064 = noise();
			t_sample abs_3063 = fabs(noise_3064);
			t_sample sub_3055 = (clamp_3133 - ((int)50));
			t_sample mul_3062 = (abs_3063 * sub_3055);
			t_sample sah_3065 = __m_sah_59(mul_3062, tap_2927, ((t_sample)0.5));
			t_sample add_3052 = (sah_3065 + ((int)50));
			t_sample mod_3061 = safemod(plusequals_3069, add_3052);
			t_sample div_3058 = safediv(mod_3061, add_3052);
			t_sample expr_3074 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_3058))));
			t_sample noise_3072 = noise();
			t_sample abs_3071 = fabs(noise_3072);
			t_sample mul_3070 = (abs_3071 * mul_3248);
			t_sample sah_3073 = __m_sah_60(mul_3070, tap_2927, ((t_sample)0.5));
			t_sample add_3067 = (sah_3073 + mod_3061);
			t_sample mod_3066 = safemod(add_3067, mul_3248);
			t_sample switch_3053 = (gte_2906 ? mod_3066 : ((int)-1));
			int index_trunc_61 = fixnan(floor(switch_3053));
			bool index_ignore_62 = ((index_trunc_61 >= segments_dim) || (index_trunc_61 < 0));
			// samples segments channel 1;
			t_sample sample_segments_3059 = (index_ignore_62 ? 0 : m_segments_34.read(index_trunc_61, 0));
			t_sample index_segments_3060 = switch_3053;
			t_sample mul_3056 = (sample_segments_3059 * expr_3074);
			t_sample mul_3129 = ((mul_3056 + mul_3032) * ((t_sample)0.4));
			t_sample mul_3128 = ((mul_3056 + mul_3032) * ((t_sample)0.3));
			t_sample plusequals_2949 = __m_pluseq_63.post(((int)1), tap_2917, 0);
			t_sample noise_2944 = noise();
			t_sample abs_2943 = fabs(noise_2944);
			t_sample sub_2935 = (clamp_3133 - ((int)50));
			t_sample mul_2942 = (abs_2943 * sub_2935);
			t_sample sah_2945 = __m_sah_64(mul_2942, tap_2917, ((t_sample)0.5));
			t_sample add_2932 = (sah_2945 + ((int)50));
			t_sample mod_2941 = safemod(plusequals_2949, add_2932);
			t_sample div_2938 = safediv(mod_2941, add_2932);
			t_sample expr_2954 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2938))));
			t_sample noise_2952 = noise();
			t_sample abs_2951 = fabs(noise_2952);
			t_sample mul_2950 = (abs_2951 * mul_3248);
			t_sample sah_2953 = __m_sah_65(mul_2950, tap_2917, ((t_sample)0.5));
			t_sample add_2947 = (sah_2953 + mod_2941);
			t_sample mod_2946 = safemod(add_2947, mul_3248);
			t_sample switch_2933 = (gte_2901 ? mod_2946 : ((int)-1));
			int index_trunc_66 = fixnan(floor(switch_2933));
			bool index_ignore_67 = ((index_trunc_66 >= segments_dim) || (index_trunc_66 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2939 = (index_ignore_67 ? 0 : m_segments_34.read(index_trunc_66, 0));
			t_sample index_segments_2940 = switch_2933;
			t_sample mul_2936 = (sample_segments_2939 * expr_2954);
			t_sample plusequals_2973 = __m_pluseq_68.post(((int)1), tap_2919, 0);
			t_sample noise_2968 = noise();
			t_sample abs_2967 = fabs(noise_2968);
			t_sample sub_2959 = (clamp_3133 - ((int)50));
			t_sample mul_2966 = (abs_2967 * sub_2959);
			t_sample sah_2969 = __m_sah_69(mul_2966, tap_2919, ((t_sample)0.5));
			t_sample add_2956 = (sah_2969 + ((int)50));
			t_sample mod_2965 = safemod(plusequals_2973, add_2956);
			t_sample div_2962 = safediv(mod_2965, add_2956);
			t_sample expr_2978 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2962))));
			t_sample noise_2976 = noise();
			t_sample abs_2975 = fabs(noise_2976);
			t_sample mul_2974 = (abs_2975 * mul_3248);
			t_sample sah_2977 = __m_sah_70(mul_2974, tap_2919, ((t_sample)0.5));
			t_sample add_2971 = (sah_2977 + mod_2965);
			t_sample mod_2970 = safemod(add_2971, mul_3248);
			t_sample switch_2957 = (gte_2902 ? mod_2970 : ((int)-1));
			int index_trunc_71 = fixnan(floor(switch_2957));
			bool index_ignore_72 = ((index_trunc_71 >= segments_dim) || (index_trunc_71 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2963 = (index_ignore_72 ? 0 : m_segments_34.read(index_trunc_71, 0));
			t_sample index_segments_2964 = switch_2957;
			t_sample mul_2960 = (sample_segments_2963 * expr_2978);
			t_sample mul_3125 = ((mul_2960 + mul_2936) * ((t_sample)0.5));
			t_sample mul_3124 = ((mul_2960 + mul_2936) * ((t_sample)0.2));
			t_sample plusequals_2997 = __m_pluseq_73.post(((int)1), tap_2921, 0);
			t_sample noise_2992 = noise();
			t_sample abs_2991 = fabs(noise_2992);
			t_sample sub_2983 = (clamp_3133 - ((int)50));
			t_sample mul_2990 = (abs_2991 * sub_2983);
			t_sample sah_2993 = __m_sah_74(mul_2990, tap_2921, ((t_sample)0.5));
			t_sample add_2980 = (sah_2993 + ((int)50));
			t_sample mod_2989 = safemod(plusequals_2997, add_2980);
			t_sample div_2986 = safediv(mod_2989, add_2980);
			t_sample expr_3002 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2986))));
			t_sample noise_3000 = noise();
			t_sample abs_2999 = fabs(noise_3000);
			t_sample mul_2998 = (abs_2999 * mul_3248);
			t_sample sah_3001 = __m_sah_75(mul_2998, tap_2921, ((t_sample)0.5));
			t_sample add_2995 = (sah_3001 + mod_2989);
			t_sample mod_2994 = safemod(add_2995, mul_3248);
			t_sample switch_2981 = (gte_2903 ? mod_2994 : ((int)-1));
			int index_trunc_76 = fixnan(floor(switch_2981));
			bool index_ignore_77 = ((index_trunc_76 >= segments_dim) || (index_trunc_76 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2987 = (index_ignore_77 ? 0 : m_segments_34.read(index_trunc_76, 0));
			t_sample index_segments_2988 = switch_2981;
			t_sample mul_2984 = (sample_segments_2987 * expr_3002);
			t_sample plusequals_3021 = __m_pluseq_78.post(((int)1), tap_2923, 0);
			t_sample noise_3016 = noise();
			t_sample abs_3015 = fabs(noise_3016);
			t_sample sub_3007 = (clamp_3133 - ((int)50));
			t_sample mul_3014 = (abs_3015 * sub_3007);
			t_sample sah_3017 = __m_sah_79(mul_3014, tap_2923, ((t_sample)0.5));
			t_sample add_3004 = (sah_3017 + ((int)50));
			t_sample mod_3013 = safemod(plusequals_3021, add_3004);
			t_sample div_3010 = safediv(mod_3013, add_3004);
			t_sample expr_3026 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_3010))));
			t_sample noise_3024 = noise();
			t_sample abs_3023 = fabs(noise_3024);
			t_sample mul_3022 = (abs_3023 * mul_3248);
			t_sample sah_3025 = __m_sah_80(mul_3022, tap_2923, ((t_sample)0.5));
			t_sample add_3019 = (sah_3025 + mod_3013);
			t_sample mod_3018 = safemod(add_3019, mul_3248);
			t_sample switch_3005 = (gte_2904 ? mod_3018 : ((int)-1));
			int index_trunc_81 = fixnan(floor(switch_3005));
			bool index_ignore_82 = ((index_trunc_81 >= segments_dim) || (index_trunc_81 < 0));
			// samples segments channel 1;
			t_sample sample_segments_3011 = (index_ignore_82 ? 0 : m_segments_34.read(index_trunc_81, 0));
			t_sample index_segments_3012 = switch_3005;
			t_sample mul_3008 = (sample_segments_3011 * expr_3026);
			t_sample mul_3127 = ((mul_3008 + mul_2984) * ((t_sample)0.2));
			t_sample mul_3126 = ((mul_3008 + mul_2984) * ((t_sample)0.5));
			int gt_3256 = (clamp_3259 > m_knob3_thresh_28);
			int change_3255 = __m_change_83(gt_3256);
			int eq_3254 = (change_3255 == ((int)1));
			t_sample add_2872 = (m_history_5 + ((int)1));
			int gt_2871 = (m_history_5 > mstosamps_2874);
			int mul_2870 = (eq_3254 * gt_2871);
			int and_2868 = (gt_2871 && eq_3254);
			t_sample switch_2869 = (and_2868 ? ((int)0) : add_2872);
			t_sample history_2873_next_2876 = fixdenorm(switch_2869);
			int plusequals_3237 = __m_pluseq_84.post(((int)1), mul_2870, 0);
			t_sample noise_3232 = noise();
			t_sample abs_3231 = fabs(noise_3232);
			t_sample sub_3223 = (clamp_3133 - ((int)50));
			t_sample mul_3230 = (abs_3231 * sub_3223);
			t_sample sah_3233 = __m_sah_85(mul_3230, mul_2870, ((t_sample)0.5));
			t_sample add_3220 = (sah_3233 + ((int)50));
			t_sample mod_3229 = safemod(plusequals_3237, add_3220);
			t_sample div_3226 = safediv(mod_3229, add_3220);
			t_sample expr_3242 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_3226))));
			t_sample noise_3240 = noise();
			t_sample abs_3239 = fabs(noise_3240);
			t_sample mul_3238 = (abs_3239 * mul_3248);
			t_sample sah_3241 = __m_sah_86(mul_3238, mul_2870, ((t_sample)0.5));
			t_sample add_3235 = (sah_3241 + mod_3229);
			t_sample mod_3234 = safemod(add_3235, mul_3248);
			t_sample switch_3221 = (gte_2912 ? mod_3234 : ((int)-1));
			int index_trunc_87 = fixnan(floor(switch_3221));
			bool index_ignore_88 = ((index_trunc_87 >= segments_dim) || (index_trunc_87 < 0));
			// samples segments channel 1;
			t_sample sample_segments_3227 = (index_ignore_88 ? 0 : m_segments_34.read(index_trunc_87, 0));
			t_sample index_segments_3228 = switch_3221;
			t_sample mul_3224 = (sample_segments_3227 * expr_3242);
			int gt_3218 = (clamp_3259 > mul_3209);
			int change_3217 = __m_change_89(gt_3218);
			int eq_3216 = (change_3217 == ((int)1));
			t_sample add_2861 = (m_history_4 + ((int)1));
			int gt_2860 = (m_history_4 > mstosamps_2863);
			int mul_2859 = (eq_3216 * gt_2860);
			int and_2857 = (gt_2860 && eq_3216);
			t_sample switch_2858 = (and_2857 ? ((int)0) : add_2861);
			t_sample history_2862_next_2865 = fixdenorm(switch_2858);
			int plusequals_3200 = __m_pluseq_90.post(((int)1), mul_2859, 0);
			t_sample noise_3195 = noise();
			t_sample abs_3194 = fabs(noise_3195);
			t_sample sub_3186 = (clamp_3133 - ((int)50));
			t_sample mul_3193 = (abs_3194 * sub_3186);
			t_sample sah_3196 = __m_sah_91(mul_3193, mul_2859, ((t_sample)0.5));
			t_sample add_3183 = (sah_3196 + ((int)50));
			t_sample mod_3192 = safemod(plusequals_3200, add_3183);
			t_sample div_3189 = safediv(mod_3192, add_3183);
			t_sample expr_3205 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_3189))));
			t_sample noise_3203 = noise();
			t_sample abs_3202 = fabs(noise_3203);
			t_sample mul_3201 = (abs_3202 * mul_3248);
			t_sample sah_3204 = __m_sah_92(mul_3201, mul_2859, ((t_sample)0.5));
			t_sample add_3198 = (sah_3204 + mod_3192);
			t_sample mod_3197 = safemod(add_3198, mul_3248);
			t_sample switch_3184 = (gte_2911 ? mod_3197 : ((int)-1));
			int index_trunc_93 = fixnan(floor(switch_3184));
			bool index_ignore_94 = ((index_trunc_93 >= segments_dim) || (index_trunc_93 < 0));
			// samples segments channel 1;
			t_sample sample_segments_3190 = (index_ignore_94 ? 0 : m_segments_34.read(index_trunc_93, 0));
			t_sample index_segments_3191 = switch_3184;
			t_sample mul_3187 = (sample_segments_3190 * expr_3205);
			int gt_3215 = (clamp_3259 > mul_3208);
			int change_3214 = __m_change_95(gt_3215);
			int eq_3213 = (change_3214 == ((int)1));
			t_sample add_2850 = (m_history_3 + ((int)1));
			int gt_2849 = (m_history_3 > mstosamps_2852);
			int mul_2848 = (eq_3213 * gt_2849);
			int and_2846 = (gt_2849 && eq_3213);
			t_sample switch_2847 = (and_2846 ? ((int)0) : add_2850);
			t_sample history_2851_next_2854 = fixdenorm(switch_2847);
			int plusequals_3176 = __m_pluseq_96.post(((int)1), mul_2848, 0);
			t_sample noise_3171 = noise();
			t_sample abs_3170 = fabs(noise_3171);
			t_sample sub_3162 = (clamp_3133 - ((int)50));
			t_sample mul_3169 = (abs_3170 * sub_3162);
			t_sample sah_3172 = __m_sah_97(mul_3169, mul_2848, ((t_sample)0.5));
			t_sample add_3159 = (sah_3172 + ((int)50));
			t_sample mod_3168 = safemod(plusequals_3176, add_3159);
			t_sample div_3165 = safediv(mod_3168, add_3159);
			t_sample expr_3181 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_3165))));
			t_sample noise_3179 = noise();
			t_sample abs_3178 = fabs(noise_3179);
			t_sample mul_3177 = (abs_3178 * mul_3248);
			t_sample sah_3180 = __m_sah_98(mul_3177, mul_2848, ((t_sample)0.5));
			t_sample add_3174 = (sah_3180 + mod_3168);
			t_sample mod_3173 = safemod(add_3174, mul_3248);
			t_sample switch_3160 = (gte_2910 ? mod_3173 : ((int)-1));
			int index_trunc_99 = fixnan(floor(switch_3160));
			bool index_ignore_100 = ((index_trunc_99 >= segments_dim) || (index_trunc_99 < 0));
			// samples segments channel 1;
			t_sample sample_segments_3166 = (index_ignore_100 ? 0 : m_segments_34.read(index_trunc_99, 0));
			t_sample index_segments_3167 = switch_3160;
			t_sample mul_3163 = (sample_segments_3166 * expr_3181);
			int gt_3212 = (clamp_3259 > mul_3207);
			int change_3211 = __m_change_101(gt_3212);
			int eq_3210 = (change_3211 == ((int)1));
			t_sample add_2839 = (m_history_2 + ((int)1));
			int gt_2838 = (m_history_2 > mstosamps_2841);
			int mul_2837 = (eq_3210 * gt_2838);
			int and_2835 = (gt_2838 && eq_3210);
			t_sample switch_2836 = (and_2835 ? ((int)0) : add_2839);
			t_sample history_2840_next_2843 = fixdenorm(switch_2836);
			int plusequals_3152 = __m_pluseq_102.post(((int)1), mul_2837, 0);
			t_sample noise_3147 = noise();
			t_sample abs_3146 = fabs(noise_3147);
			t_sample sub_3138 = (clamp_3133 - ((int)50));
			t_sample mul_3145 = (abs_3146 * sub_3138);
			t_sample sah_3148 = __m_sah_103(mul_3145, mul_2837, ((t_sample)0.5));
			t_sample add_3135 = (sah_3148 + ((int)50));
			t_sample mod_3144 = safemod(plusequals_3152, add_3135);
			t_sample div_3141 = safediv(mod_3144, add_3135);
			t_sample expr_3157 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_3141))));
			t_sample noise_3155 = noise();
			t_sample abs_3154 = fabs(noise_3155);
			t_sample mul_3153 = (abs_3154 * mul_3248);
			t_sample sah_3156 = __m_sah_104(mul_3153, mul_2837, ((t_sample)0.5));
			t_sample add_3150 = (sah_3156 + mod_3144);
			t_sample mod_3149 = safemod(add_3150, mul_3248);
			t_sample switch_3136 = (gte_2909 ? mod_3149 : ((int)-1));
			int index_trunc_105 = fixnan(floor(switch_3136));
			bool index_ignore_106 = ((index_trunc_105 >= segments_dim) || (index_trunc_105 < 0));
			// samples segments channel 1;
			t_sample sample_segments_3142 = (index_ignore_106 ? 0 : m_segments_34.read(index_trunc_105, 0));
			t_sample index_segments_3143 = switch_3136;
			t_sample mul_3139 = (sample_segments_3142 * expr_3157);
			t_sample mul_3219 = ((((mul_3224 + mul_3139) + mul_3163) + mul_3187) * ((t_sample)0.7));
			t_sample mul_2915 = (((((mul_3127 + mul_3125) + mul_3129) + mul_3131) + mul_3219) * scale_3373);
			t_sample dcblock_2880 = __m_dcblock_107(mul_2915);
			t_sample mul_2883 = (sqrt_2881 * dcblock_2880);
			t_sample out1 = ((mul_2883 + mul_2884) + gate_3272);
			t_sample mul_2914 = (((((mul_3126 + mul_3124) + mul_3128) + mul_3130) + mul_3219) * scale_3373);
			t_sample dcblock_2879 = __m_dcblock_108(mul_2914);
			t_sample mul_2882 = (sqrt_2881 * dcblock_2879);
			t_sample out2 = ((mul_2882 + mul_2884) + gate_3272);
			t_sample history_3249_next_3315 = fixdenorm(eq_3250);
			m_history_26 = history_3268_next_3270;
			m_history_25 = history_2890_next_2892;
			m_history_23 = history_2886_next_2894;
			m_history_24 = history_2888_next_2893;
			m_history_22 = history_2890_next_3281;
			m_history_20 = history_2886_next_3276;
			m_history_21 = history_2888_next_3278;
			m_history_19 = history_2890_next_3295;
			m_history_17 = history_2886_next_3289;
			m_history_18 = history_2888_next_3293;
			m_delay_16.write(mul_2859);
			m_delay_15.write(mul_2870);
			m_delay_14.write(mul_2837);
			m_delay_13.write(mul_2848);
			m_delay_12.write(tap_2925);
			m_delay_11.write(tap_2927);
			m_delay_10.write(tap_2929);
			m_delay_9.write(tap_2931);
			m_history_8 = history_2890_next_3302;
			m_history_6 = history_2886_next_3305;
			m_history_7 = history_2888_next_3308;
			m_history_5 = history_2873_next_2876;
			m_history_4 = history_2862_next_2865;
			m_history_3 = history_2851_next_2854;
			m_history_2 = history_2840_next_2843;
			m_history_1 = history_3249_next_3315;
			m_delay_9.step();
			m_delay_10.step();
			m_delay_11.step();
			m_delay_12.step();
			m_delay_13.step();
			m_delay_14.step();
			m_delay_15.step();
			m_delay_16.step();
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
		m_sw_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_thresh(t_param _value) {
		m_knob3_thresh_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_density(t_param _value) {
		m_knob6_density_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_glitchlen(t_param _value) {
		m_knob5_glitchlen_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_segments(void * _value) {
		m_segments_34.setbuffer(_value);
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
int num_params() { return 8; }

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
		case 0: self->set_knob1_wetdry(value); break;
		case 1: self->set_knob3_thresh(value); break;
		case 2: self->set_knob4_buflen(value); break;
		case 3: self->set_knob5_glitchlen(value); break;
		case 4: self->set_knob6_density(value); break;
		case 5: self->set_segments(ref); break;
		case 6: self->set_sw1(value); break;
		case 7: self->set_sw2(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_wetdry_29; break;
		case 1: *value = self->m_knob3_thresh_28; break;
		case 2: *value = self->m_knob4_buflen_32; break;
		case 3: *value = self->m_knob5_glitchlen_33; break;
		case 4: *value = self->m_knob6_density_30; break;
		
		case 6: *value = self->m_sw_27; break;
		case 7: *value = self->m_sw_31; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(8 * sizeof(ParamInfo));
	self->__commonstate.numparams = 8;
	// initialize parameter 0 ("m_knob1_wetdry_29")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_thresh_28")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_thresh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_thresh_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_buflen_32")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_buflen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_buflen_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_glitchlen_33")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_glitchlen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_glitchlen_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_density_30")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_density";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_density_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_segments_34")
	pi = self->__commonstate.params + 5;
	pi->name = "segments";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_sw_27")
	pi = self->__commonstate.params + 6;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_sw_31")
	pi = self->__commonstate.params + 7;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_31;
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


} // Glitch::
