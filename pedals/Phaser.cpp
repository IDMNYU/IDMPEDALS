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
	t_sample m_knob3_depth_28;
	t_sample __m_slide_51;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_slide_46;
	t_sample m_history_7;
	t_sample m_knob4_rate_27;
	t_sample m_knob6_diffusion_25;
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
		m_sw_23 = ((int)0);
		m_sw_24 = ((int)0);
		m_knob6_diffusion_25 = 1;
		m_knob5_fb_26 = ((int)0);
		m_knob4_rate_27 = 0.1;
		m_knob3_depth_28 = 1;
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
		t_sample sub_6376 = (m_knob5_fb_26 - ((t_sample)0.5));
		t_sample scale_6373 = ((safepow((sub_6376 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		t_sample mul_6267 = (m_knob6_diffusion_25 * ((int)3));
		t_sample div_6265 = (mul_6267 * ((t_sample)0.125));
		t_sample mul_6268 = (m_knob6_diffusion_25 * ((int)1));
		t_sample div_6266 = (mul_6268 * ((t_sample)0.125));
		t_sample mstosamps_6115 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_6114 = (((int)100) * (samplerate * 0.001));
		t_sample mul_6274 = (m_knob6_diffusion_25 * ((int)2));
		t_sample div_6272 = (mul_6274 * ((t_sample)0.125));
		t_sample mul_6275 = (m_knob6_diffusion_25 * ((int)0));
		t_sample div_6273 = (mul_6275 * ((t_sample)0.125));
		t_sample iup_33 = (1 / maximum(1, abs(mstosamps_6115)));
		t_sample idown_34 = (1 / maximum(1, abs(mstosamps_6114)));
		t_sample div_6148 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_37 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_38 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_40 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_41 = (1 / maximum(1, abs(((int)5))));
		t_sample div_6190 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_44 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)5))));
		t_sample div_6233 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_52 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)5))));
		t_sample div_6291 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_6124 = __m_sah_29(m_history_22, m_sw_23, ((int)0));
			t_sample gen_6126 = sah_6124;
			t_sample rsub_6122 = (((int)1) - sah_6124);
			t_sample history_6123_next_6125 = fixdenorm(rsub_6122);
			t_sample out3 = gen_6126;
			t_sample mix_6370 = (m_history_21 + (((t_sample)0.003926980723806) * (m_knob4_rate_27 - m_history_21)));
			t_sample mix_6105 = mix_6370;
			t_sample mix_6371 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_6105 - m_history_20)));
			t_sample mix_6103 = mix_6371;
			t_sample mix_6372 = (m_history_19 + (((t_sample)0.003926980723806) * (mix_6103 - m_history_19)));
			t_sample mix_6101 = mix_6372;
			t_sample gen_6111 = mix_6101;
			t_sample history_6106_next_6108 = fixdenorm(mix_6105);
			t_sample history_6104_next_6109 = fixdenorm(mix_6103);
			t_sample history_6102_next_6110 = fixdenorm(mix_6101);
			t_sample expr_6321 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_6111)))));
			t_sample add_6127 = (gen_6126 + ((int)1));
			t_sample choice_30 = int(add_6127);
			t_sample gate_6120 = (((choice_30 >= 1) && (choice_30 < 2)) ? in1 : 0);
			t_sample gate_6121 = ((choice_30 >= 2) ? in1 : 0);
			t_sample mul_6130 = (m_history_1 * m_knob5_fb_26);
			t_sample add_6129 = (gate_6121 + mul_6130);
			t_sample mul_6320 = (expr_6321 * ((t_sample)7.5));
			t_sample phasor_6276 = __m_phasor_31(mul_6320, samples_to_seconds);
			t_sample mul_6271 = (m_history_2 * m_knob5_fb_26);
			t_sample add_6270 = (gate_6121 + mul_6271);
			t_sample abs_6094 = fabs(gate_6121);
			t_sample mul_6093 = (abs_6094 * ((int)30));
			t_sample switch_6118 = (m_sw_24 ? mul_6093 : ((int)1));
			__m_slide_32 = fixdenorm((__m_slide_32 + (((switch_6118 > __m_slide_32) ? iup_33 : idown_34) * (switch_6118 - __m_slide_32))));
			t_sample slide_6119 = __m_slide_32;
			t_sample mul_6098 = (m_knob3_depth_28 * slide_6119);
			t_sample clamp_6117 = ((mul_6098 <= ((int)0)) ? ((int)0) : ((mul_6098 >= ((int)1)) ? ((int)1) : mul_6098));
			t_sample out4 = clamp_6117;
			t_sample add_6157 = (phasor_6276 + div_6265);
			t_sample mod_6158 = safemod(add_6157, ((int)1));
			__m_cycle_35.phase(mod_6158);
			t_sample cycle_6155 = __m_cycle_35(__sinedata);
			t_sample cycleindex_6156 = __m_cycle_35.phase();
			t_sample add_6153 = (cycle_6155 + ((int)1));
			t_sample div_6152 = (add_6153 * ((t_sample)0.5));
			t_sample mul_6154 = (div_6152 * clamp_6117);
			t_sample sub_6380 = (mul_6154 - ((int)0));
			t_sample scale_6377 = ((safepow((sub_6380 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_6159 = scale_6377;
			t_sample mtof_6160 = mtof(scale_6159, ((int)440));
			t_sample mul_6147 = (mtof_6160 * div_6148);
			t_sample cos_6145 = cos(mul_6147);
			t_sample mul_6140 = (cos_6145 * (-2));
			t_sample sin_6146 = sin(mul_6147);
			t_sample mul_6144 = (sin_6146 * ((t_sample)0.5));
			t_sample div_6143 = (mul_6144 * ((t_sample)0.33333333333333));
			t_sample rsub_6138 = (((int)1) - div_6143);
			t_sample add_6142 = (div_6143 + ((int)1));
			t_sample rdiv_6141 = safediv(((int)1), add_6142);
			t_sample mul_6137 = (rdiv_6141 * rsub_6138);
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_6137 > __m_slide_36) ? iup_37 : idown_38) * (mul_6137 - __m_slide_36))));
			t_sample slide_6134 = __m_slide_36;
			t_sample gen_6150 = slide_6134;
			t_sample mul_6139 = (rdiv_6141 * mul_6140);
			__m_slide_39 = fixdenorm((__m_slide_39 + (((mul_6139 > __m_slide_39) ? iup_40 : idown_41) * (mul_6139 - __m_slide_39))));
			t_sample slide_6135 = __m_slide_39;
			t_sample gen_6149 = slide_6135;
			t_sample mul_6170 = (add_6129 * gen_6150);
			t_sample mul_6167 = (m_history_16 * gen_6149);
			t_sample mul_6165 = (m_history_18 * ((int)1));
			t_sample mul_6161 = (m_history_17 * gen_6150);
			t_sample mul_6163 = (m_history_15 * gen_6149);
			t_sample sub_6169 = (((mul_6165 + mul_6167) + mul_6170) - (mul_6163 + mul_6161));
			t_sample gen_6175 = sub_6169;
			t_sample history_6166_next_6171 = fixdenorm(m_history_16);
			t_sample history_6162_next_6172 = fixdenorm(m_history_15);
			t_sample history_6168_next_6173 = fixdenorm(add_6129);
			t_sample history_6164_next_6174 = fixdenorm(sub_6169);
			t_sample add_6199 = (phasor_6276 + div_6266);
			t_sample mod_6200 = safemod(add_6199, ((int)1));
			__m_cycle_42.phase(mod_6200);
			t_sample cycle_6197 = __m_cycle_42(__sinedata);
			t_sample cycleindex_6198 = __m_cycle_42.phase();
			t_sample add_6195 = (cycle_6197 + ((int)1));
			t_sample div_6194 = (add_6195 * ((t_sample)0.5));
			t_sample mul_6196 = (div_6194 * clamp_6117);
			t_sample sub_6384 = (mul_6196 - ((int)0));
			t_sample scale_6381 = ((safepow((sub_6384 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_6201 = scale_6381;
			t_sample mtof_6202 = mtof(scale_6201, ((int)440));
			t_sample mul_6189 = (mtof_6202 * div_6190);
			t_sample cos_6187 = cos(mul_6189);
			t_sample mul_6182 = (cos_6187 * (-2));
			t_sample sin_6188 = sin(mul_6189);
			t_sample mul_6186 = (sin_6188 * ((t_sample)0.5));
			t_sample div_6185 = (mul_6186 * ((t_sample)0.33333333333333));
			t_sample rsub_6180 = (((int)1) - div_6185);
			t_sample add_6184 = (div_6185 + ((int)1));
			t_sample rdiv_6183 = safediv(((int)1), add_6184);
			t_sample mul_6179 = (rdiv_6183 * rsub_6180);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((mul_6179 > __m_slide_43) ? iup_44 : idown_45) * (mul_6179 - __m_slide_43))));
			t_sample slide_6176 = __m_slide_43;
			t_sample gen_6192 = slide_6176;
			t_sample mul_6181 = (rdiv_6183 * mul_6182);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((mul_6181 > __m_slide_46) ? iup_47 : idown_48) * (mul_6181 - __m_slide_46))));
			t_sample slide_6177 = __m_slide_46;
			t_sample gen_6191 = slide_6177;
			t_sample mul_6212 = (add_6129 * gen_6192);
			t_sample mul_6209 = (m_history_12 * gen_6191);
			t_sample mul_6207 = (m_history_14 * ((int)1));
			t_sample mul_6203 = (m_history_13 * gen_6192);
			t_sample mul_6205 = (m_history_11 * gen_6191);
			t_sample sub_6211 = (((mul_6207 + mul_6209) + mul_6212) - (mul_6205 + mul_6203));
			t_sample gen_6217 = sub_6211;
			t_sample history_6208_next_6213 = fixdenorm(m_history_12);
			t_sample history_6204_next_6214 = fixdenorm(m_history_11);
			t_sample history_6210_next_6215 = fixdenorm(add_6129);
			t_sample history_6206_next_6216 = fixdenorm(sub_6211);
			t_sample mul_6131 = ((gen_6217 + gen_6175) * ((t_sample)0.5));
			t_sample dcblock_6132 = __m_dcblock_49(mul_6131);
			t_sample mul_6133 = (((gate_6121 + gen_6217) + gen_6175) * scale_6373);
			t_sample div_6096 = (mul_6133 * ((t_sample)0.5));
			t_sample add_6262 = (gate_6120 + div_6096);
			t_sample out2 = add_6262;
			t_sample add_6242 = (phasor_6276 + div_6272);
			t_sample mod_6243 = safemod(add_6242, ((int)1));
			__m_cycle_50.phase(mod_6243);
			t_sample cycle_6240 = __m_cycle_50(__sinedata);
			t_sample cycleindex_6241 = __m_cycle_50.phase();
			t_sample add_6238 = (cycle_6240 + ((int)1));
			t_sample div_6237 = (add_6238 * ((t_sample)0.5));
			t_sample mul_6239 = (div_6237 * clamp_6117);
			t_sample sub_6388 = (mul_6239 - ((int)0));
			t_sample scale_6385 = ((safepow((sub_6388 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_6244 = scale_6385;
			t_sample mtof_6245 = mtof(scale_6244, ((int)440));
			t_sample mul_6232 = (mtof_6245 * div_6233);
			t_sample cos_6230 = cos(mul_6232);
			t_sample mul_6225 = (cos_6230 * (-2));
			t_sample sin_6231 = sin(mul_6232);
			t_sample mul_6229 = (sin_6231 * ((t_sample)0.5));
			t_sample div_6228 = (mul_6229 * ((t_sample)0.33333333333333));
			t_sample rsub_6223 = (((int)1) - div_6228);
			t_sample add_6227 = (div_6228 + ((int)1));
			t_sample rdiv_6226 = safediv(((int)1), add_6227);
			t_sample mul_6224 = (rdiv_6226 * mul_6225);
			__m_slide_51 = fixdenorm((__m_slide_51 + (((mul_6224 > __m_slide_51) ? iup_52 : idown_53) * (mul_6224 - __m_slide_51))));
			t_sample slide_6220 = __m_slide_51;
			t_sample gen_6234 = slide_6220;
			t_sample mul_6222 = (rdiv_6226 * rsub_6223);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((mul_6222 > __m_slide_54) ? iup_55 : idown_56) * (mul_6222 - __m_slide_54))));
			t_sample slide_6219 = __m_slide_54;
			t_sample gen_6235 = slide_6219;
			t_sample mul_6255 = (add_6270 * gen_6235);
			t_sample mul_6252 = (m_history_8 * gen_6234);
			t_sample mul_6250 = (m_history_10 * ((int)1));
			t_sample mul_6246 = (m_history_9 * gen_6235);
			t_sample mul_6248 = (m_history_7 * gen_6234);
			t_sample sub_6254 = (((mul_6250 + mul_6252) + mul_6255) - (mul_6248 + mul_6246));
			t_sample gen_6260 = sub_6254;
			t_sample history_6251_next_6256 = fixdenorm(m_history_8);
			t_sample history_6247_next_6257 = fixdenorm(m_history_7);
			t_sample history_6253_next_6258 = fixdenorm(add_6270);
			t_sample history_6249_next_6259 = fixdenorm(sub_6254);
			t_sample add_6300 = (phasor_6276 + div_6273);
			t_sample mod_6301 = safemod(add_6300, ((int)1));
			__m_cycle_57.phase(mod_6301);
			t_sample cycle_6298 = __m_cycle_57(__sinedata);
			t_sample cycleindex_6299 = __m_cycle_57.phase();
			t_sample add_6296 = (cycle_6298 + ((int)1));
			t_sample div_6295 = (add_6296 * ((t_sample)0.5));
			t_sample mul_6297 = (div_6295 * clamp_6117);
			t_sample sub_6392 = (mul_6297 - ((int)0));
			t_sample scale_6389 = ((safepow((sub_6392 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_6302 = scale_6389;
			t_sample mtof_6303 = mtof(scale_6302, ((int)440));
			t_sample mul_6290 = (mtof_6303 * div_6291);
			t_sample cos_6288 = cos(mul_6290);
			t_sample mul_6283 = (cos_6288 * (-2));
			t_sample sin_6289 = sin(mul_6290);
			t_sample mul_6287 = (sin_6289 * ((t_sample)0.5));
			t_sample div_6286 = (mul_6287 * ((t_sample)0.33333333333333));
			t_sample rsub_6281 = (((int)1) - div_6286);
			t_sample add_6285 = (div_6286 + ((int)1));
			t_sample rdiv_6284 = safediv(((int)1), add_6285);
			t_sample mul_6280 = (rdiv_6284 * rsub_6281);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((mul_6280 > __m_slide_58) ? iup_59 : idown_60) * (mul_6280 - __m_slide_58))));
			t_sample slide_6277 = __m_slide_58;
			t_sample gen_6293 = slide_6277;
			t_sample mul_6282 = (rdiv_6284 * mul_6283);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((mul_6282 > __m_slide_61) ? iup_62 : idown_63) * (mul_6282 - __m_slide_61))));
			t_sample slide_6278 = __m_slide_61;
			t_sample gen_6292 = slide_6278;
			t_sample mul_6313 = (add_6270 * gen_6293);
			t_sample mul_6310 = (m_history_4 * gen_6292);
			t_sample mul_6308 = (m_history_6 * ((int)1));
			t_sample mul_6304 = (m_history_5 * gen_6293);
			t_sample mul_6306 = (m_history_3 * gen_6292);
			t_sample sub_6312 = (((mul_6308 + mul_6310) + mul_6313) - (mul_6306 + mul_6304));
			t_sample gen_6318 = sub_6312;
			t_sample history_6309_next_6314 = fixdenorm(m_history_4);
			t_sample history_6305_next_6315 = fixdenorm(m_history_3);
			t_sample history_6311_next_6316 = fixdenorm(add_6270);
			t_sample history_6307_next_6317 = fixdenorm(sub_6312);
			t_sample mul_6218 = ((gen_6318 + gen_6260) * ((t_sample)0.5));
			t_sample dcblock_6263 = __m_dcblock_64(mul_6218);
			t_sample mul_6261 = (((gate_6121 + gen_6318) + gen_6260) * scale_6373);
			t_sample div_6095 = (mul_6261 * ((t_sample)0.5));
			t_sample add_6264 = (gate_6120 + div_6095);
			t_sample out1 = add_6264;
			t_sample history_6269_next_6322 = fixdenorm(dcblock_6132);
			t_sample history_6128_next_6323 = fixdenorm(dcblock_6263);
			m_history_22 = history_6123_next_6125;
			m_history_21 = history_6106_next_6108;
			m_history_19 = history_6102_next_6110;
			m_history_20 = history_6104_next_6109;
			m_history_18 = history_6166_next_6171;
			m_history_15 = history_6164_next_6174;
			m_history_16 = history_6168_next_6173;
			m_history_17 = history_6162_next_6172;
			m_history_14 = history_6208_next_6213;
			m_history_11 = history_6206_next_6216;
			m_history_12 = history_6210_next_6215;
			m_history_13 = history_6204_next_6214;
			m_history_10 = history_6251_next_6256;
			m_history_7 = history_6249_next_6259;
			m_history_8 = history_6253_next_6258;
			m_history_9 = history_6247_next_6257;
			m_history_6 = history_6309_next_6314;
			m_history_3 = history_6307_next_6317;
			m_history_4 = history_6311_next_6316;
			m_history_5 = history_6305_next_6315;
			m_history_2 = history_6269_next_6322;
			m_history_1 = history_6128_next_6323;
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
	inline void set_sw5(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_diffusion(t_param _value) {
		m_knob6_diffusion_25 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_26 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_depth_28; break;
		case 1: *value = self->m_knob4_rate_27; break;
		case 2: *value = self->m_knob5_fb_26; break;
		case 3: *value = self->m_knob6_diffusion_25; break;
		case 4: *value = self->m_sw_23; break;
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
	// initialize parameter 0 ("m_knob3_depth_28")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_28;
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
	// initialize parameter 3 ("m_knob6_diffusion_25")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_diffusion";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_diffusion_25;
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
