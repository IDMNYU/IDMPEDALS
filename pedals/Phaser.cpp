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
	DCBlock __m_dcblock_63;
	DCBlock __m_dcblock_48;
	Phasor __m_phasor_33;
	Sah __m_sah_28;
	SineCycle __m_cycle_56;
	SineCycle __m_cycle_49;
	SineCycle __m_cycle_41;
	SineCycle __m_cycle_34;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_3;
	t_sample m_history_8;
	t_sample __m_slide_35;
	t_sample m_history_4;
	t_sample m_history_5;
	t_sample samples_to_seconds;
	t_sample __m_slide_38;
	t_sample __m_slide_30;
	t_sample m_history_6;
	t_sample m_history_2;
	t_sample __m_slide_45;
	t_sample __m_slide_53;
	t_sample __m_slide_57;
	t_sample __m_slide_42;
	t_sample __m_slide_50;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample m_history_7;
	t_sample m_sw_27;
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
	t_sample m_knob3_depth_23;
	t_sample m_knob5_fb_24;
	t_sample m_history_17;
	t_sample __m_slide_60;
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
		m_knob5_fb_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_knob4_rate_26 = 0.1;
		m_sw_27 = ((int)0);
		__m_sah_28.reset(0);
		__m_slide_30 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_33.reset(0);
		__m_cycle_34.reset(samplerate, 0);
		__m_slide_35 = 0;
		__m_slide_38 = 0;
		__m_cycle_41.reset(samplerate, 0);
		__m_slide_42 = 0;
		__m_slide_45 = 0;
		__m_dcblock_48.reset();
		__m_cycle_49.reset(samplerate, 0);
		__m_slide_50 = 0;
		__m_slide_53 = 0;
		__m_cycle_56.reset(samplerate, 0);
		__m_slide_57 = 0;
		__m_slide_60 = 0;
		__m_dcblock_63.reset();
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
		t_sample sub_4403 = (m_knob5_fb_24 - ((t_sample)0.5));
		t_sample scale_4400 = ((safepow((sub_4403 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		t_sample mstosamps_4115 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_4114 = (((int)100) * (samplerate * 0.001));
		t_sample iup_31 = (1 / maximum(1, abs(mstosamps_4115)));
		t_sample idown_32 = (1 / maximum(1, abs(mstosamps_4114)));
		samples_to_seconds = (1 / samplerate);
		t_sample div_4236 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_36 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_37 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_39 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_40 = (1 / maximum(1, abs(((int)5))));
		t_sample div_4299 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_43 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_44 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_46 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_47 = (1 / maximum(1, abs(((int)5))));
		t_sample div_4151 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_51 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_52 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_54 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_55 = (1 / maximum(1, abs(((int)5))));
		t_sample div_4193 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_58 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_59 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_61 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_62 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_4127 = __m_sah_28(m_history_22, m_sw_27, ((int)0));
			t_sample gen_4129 = sah_4127;
			t_sample rsub_4125 = (((int)1) - sah_4127);
			t_sample history_4126_next_4128 = fixdenorm(rsub_4125);
			t_sample out3 = gen_4129;
			t_sample add_4130 = (gen_4129 + ((int)1));
			t_sample choice_29 = int(add_4130);
			t_sample gate_4122 = (((choice_29 >= 1) && (choice_29 < 2)) ? in1 : 0);
			t_sample gate_4123 = ((choice_29 >= 2) ? in1 : 0);
			t_sample mul_4278 = (m_history_1 * m_knob5_fb_24);
			t_sample add_4277 = (gate_4123 + mul_4278);
			t_sample mul_4133 = (m_history_2 * m_knob5_fb_24);
			t_sample add_4132 = (gate_4123 + mul_4133);
			t_sample switch_4119 = (m_sw_25 ? gate_4123 : ((int)1));
			t_sample abs_4121 = fabs(switch_4119);
			t_sample mul_4096 = (abs_4121 * ((int)100));
			__m_slide_30 = fixdenorm((__m_slide_30 + (((mul_4096 > __m_slide_30) ? iup_31 : idown_32) * (mul_4096 - __m_slide_30))));
			t_sample slide_4120 = __m_slide_30;
			t_sample clamp_4116 = ((slide_4120 <= ((int)0)) ? ((int)0) : ((slide_4120 >= ((int)1)) ? ((int)1) : slide_4120));
			t_sample mul_4118 = (m_knob3_depth_23 * clamp_4116);
			t_sample mix_4404 = (m_history_21 + (((t_sample)0.003926980723806) * (m_knob4_rate_26 - m_history_21)));
			t_sample mix_4102 = mix_4404;
			t_sample mix_4405 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_4102 - m_history_20)));
			t_sample mix_4100 = mix_4405;
			t_sample mix_4406 = (m_history_19 + (((t_sample)0.003926980723806) * (mix_4100 - m_history_19)));
			t_sample mix_4098 = mix_4406;
			t_sample gen_4110 = mix_4098;
			t_sample history_4104_next_4107 = fixdenorm(mix_4102);
			t_sample history_4101_next_4108 = fixdenorm(mix_4100);
			t_sample history_4099_next_4109 = fixdenorm(mix_4098);
			t_sample rsub_4268 = (((int)1) - gen_4110);
			t_sample sqrt_4267 = sqrt(rsub_4268);
			t_sample sqrt_4266 = sqrt(sqrt_4267);
			t_sample sqrt_4111 = sqrt(sqrt_4266);
			t_sample rsub_4265 = (((int)1) - sqrt_4111);
			t_sample mul_4328 = (rsub_4265 * ((t_sample)7.5));
			t_sample phasor_4284 = __m_phasor_33(mul_4328, samples_to_seconds);
			t_sample add_4245 = (phasor_4284 + ((t_sample)0.25));
			t_sample mod_4246 = safemod(add_4245, ((int)1));
			__m_cycle_34.phase(mod_4246);
			t_sample cycle_4243 = __m_cycle_34(__sinedata);
			t_sample cycleindex_4244 = __m_cycle_34.phase();
			t_sample add_4241 = (cycle_4243 + ((int)1));
			t_sample div_4240 = (add_4241 * ((t_sample)0.5));
			t_sample mul_4242 = (div_4240 * mul_4118);
			t_sample sub_4410 = (mul_4242 - ((int)0));
			t_sample scale_4407 = ((safepow((sub_4410 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_4247 = scale_4407;
			t_sample mtof_4248 = mtof(scale_4247, ((int)440));
			t_sample mul_4235 = (mtof_4248 * div_4236);
			t_sample cos_4233 = cos(mul_4235);
			t_sample mul_4228 = (cos_4233 * (-2));
			t_sample sin_4234 = sin(mul_4235);
			t_sample mul_4232 = (sin_4234 * ((t_sample)0.5));
			t_sample div_4231 = (mul_4232 * ((t_sample)0.33333333333333));
			t_sample rsub_4226 = (((int)1) - div_4231);
			t_sample add_4230 = (div_4231 + ((int)1));
			t_sample rdiv_4229 = safediv(((int)1), add_4230);
			t_sample mul_4225 = (rdiv_4229 * rsub_4226);
			__m_slide_35 = fixdenorm((__m_slide_35 + (((mul_4225 > __m_slide_35) ? iup_36 : idown_37) * (mul_4225 - __m_slide_35))));
			t_sample slide_4222 = __m_slide_35;
			t_sample gen_4238 = slide_4222;
			t_sample mul_4227 = (rdiv_4229 * mul_4228);
			__m_slide_38 = fixdenorm((__m_slide_38 + (((mul_4227 > __m_slide_38) ? iup_39 : idown_40) * (mul_4227 - __m_slide_38))));
			t_sample slide_4223 = __m_slide_38;
			t_sample gen_4237 = slide_4223;
			t_sample mul_4258 = (add_4277 * gen_4238);
			t_sample mul_4255 = (m_history_16 * gen_4237);
			t_sample mul_4253 = (m_history_18 * ((int)1));
			t_sample mul_4249 = (m_history_17 * gen_4238);
			t_sample mul_4251 = (m_history_15 * gen_4237);
			t_sample sub_4257 = (((mul_4253 + mul_4255) + mul_4258) - (mul_4251 + mul_4249));
			t_sample gen_4263 = sub_4257;
			t_sample history_4254_next_4259 = fixdenorm(m_history_16);
			t_sample history_4250_next_4260 = fixdenorm(m_history_15);
			t_sample history_4256_next_4261 = fixdenorm(add_4277);
			t_sample history_4252_next_4262 = fixdenorm(sub_4257);
			t_sample add_4308 = (phasor_4284 + ((int)0));
			t_sample mod_4309 = safemod(add_4308, ((int)1));
			__m_cycle_41.phase(mod_4309);
			t_sample cycle_4306 = __m_cycle_41(__sinedata);
			t_sample cycleindex_4307 = __m_cycle_41.phase();
			t_sample add_4304 = (cycle_4306 + ((int)1));
			t_sample div_4303 = (add_4304 * ((t_sample)0.5));
			t_sample mul_4305 = (div_4303 * mul_4118);
			t_sample sub_4414 = (mul_4305 - ((int)0));
			t_sample scale_4411 = ((safepow((sub_4414 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_4310 = scale_4411;
			t_sample mtof_4311 = mtof(scale_4310, ((int)440));
			t_sample mul_4298 = (mtof_4311 * div_4299);
			t_sample cos_4296 = cos(mul_4298);
			t_sample mul_4291 = (cos_4296 * (-2));
			t_sample sin_4297 = sin(mul_4298);
			t_sample mul_4295 = (sin_4297 * ((t_sample)0.5));
			t_sample div_4294 = (mul_4295 * ((t_sample)0.33333333333333));
			t_sample rsub_4289 = (((int)1) - div_4294);
			t_sample add_4293 = (div_4294 + ((int)1));
			t_sample rdiv_4292 = safediv(((int)1), add_4293);
			t_sample mul_4290 = (rdiv_4292 * mul_4291);
			__m_slide_42 = fixdenorm((__m_slide_42 + (((mul_4290 > __m_slide_42) ? iup_43 : idown_44) * (mul_4290 - __m_slide_42))));
			t_sample slide_4286 = __m_slide_42;
			t_sample gen_4300 = slide_4286;
			t_sample mul_4288 = (rdiv_4292 * rsub_4289);
			__m_slide_45 = fixdenorm((__m_slide_45 + (((mul_4288 > __m_slide_45) ? iup_46 : idown_47) * (mul_4288 - __m_slide_45))));
			t_sample slide_4285 = __m_slide_45;
			t_sample gen_4301 = slide_4285;
			t_sample mul_4321 = (add_4277 * gen_4301);
			t_sample mul_4318 = (m_history_12 * gen_4300);
			t_sample mul_4316 = (m_history_13 * ((int)1));
			t_sample mul_4312 = (m_history_14 * gen_4301);
			t_sample mul_4314 = (m_history_11 * gen_4300);
			t_sample sub_4320 = (((mul_4316 + mul_4318) + mul_4321) - (mul_4314 + mul_4312));
			t_sample gen_4326 = sub_4320;
			t_sample history_4313_next_4322 = fixdenorm(m_history_11);
			t_sample history_4317_next_4323 = fixdenorm(m_history_12);
			t_sample history_4319_next_4324 = fixdenorm(add_4277);
			t_sample history_4315_next_4325 = fixdenorm(sub_4320);
			t_sample mul_4264 = (((gate_4123 + gen_4326) + gen_4263) * scale_4400);
			t_sample add_4271 = (mul_4264 + gate_4122);
			t_sample out1 = add_4271;
			t_sample mul_4221 = ((gen_4326 + gen_4263) * ((t_sample)0.5));
			t_sample dcblock_4270 = __m_dcblock_48(mul_4221);
			t_sample add_4160 = (phasor_4284 + ((t_sample)0.375));
			t_sample mod_4161 = safemod(add_4160, ((int)1));
			__m_cycle_49.phase(mod_4161);
			t_sample cycle_4158 = __m_cycle_49(__sinedata);
			t_sample cycleindex_4159 = __m_cycle_49.phase();
			t_sample add_4156 = (cycle_4158 + ((int)1));
			t_sample div_4155 = (add_4156 * ((t_sample)0.5));
			t_sample mul_4157 = (div_4155 * mul_4118);
			t_sample sub_4418 = (mul_4157 - ((int)0));
			t_sample scale_4415 = ((safepow((sub_4418 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_4162 = scale_4415;
			t_sample mtof_4163 = mtof(scale_4162, ((int)440));
			t_sample mul_4150 = (mtof_4163 * div_4151);
			t_sample cos_4148 = cos(mul_4150);
			t_sample mul_4143 = (cos_4148 * (-2));
			t_sample sin_4149 = sin(mul_4150);
			t_sample mul_4147 = (sin_4149 * ((t_sample)0.5));
			t_sample div_4146 = (mul_4147 * ((t_sample)0.33333333333333));
			t_sample rsub_4141 = (((int)1) - div_4146);
			t_sample add_4145 = (div_4146 + ((int)1));
			t_sample rdiv_4144 = safediv(((int)1), add_4145);
			t_sample mul_4140 = (rdiv_4144 * rsub_4141);
			__m_slide_50 = fixdenorm((__m_slide_50 + (((mul_4140 > __m_slide_50) ? iup_51 : idown_52) * (mul_4140 - __m_slide_50))));
			t_sample slide_4137 = __m_slide_50;
			t_sample gen_4153 = slide_4137;
			t_sample mul_4142 = (rdiv_4144 * mul_4143);
			__m_slide_53 = fixdenorm((__m_slide_53 + (((mul_4142 > __m_slide_53) ? iup_54 : idown_55) * (mul_4142 - __m_slide_53))));
			t_sample slide_4138 = __m_slide_53;
			t_sample gen_4152 = slide_4138;
			t_sample mul_4173 = (add_4132 * gen_4153);
			t_sample mul_4170 = (m_history_8 * gen_4152);
			t_sample mul_4168 = (m_history_9 * ((int)1));
			t_sample mul_4164 = (m_history_10 * gen_4153);
			t_sample mul_4166 = (m_history_7 * gen_4152);
			t_sample sub_4172 = (((mul_4168 + mul_4170) + mul_4173) - (mul_4166 + mul_4164));
			t_sample gen_4178 = sub_4172;
			t_sample history_4165_next_4174 = fixdenorm(m_history_7);
			t_sample history_4169_next_4175 = fixdenorm(m_history_8);
			t_sample history_4171_next_4176 = fixdenorm(add_4132);
			t_sample history_4167_next_4177 = fixdenorm(sub_4172);
			t_sample add_4202 = (phasor_4284 + ((t_sample)0.125));
			t_sample mod_4203 = safemod(add_4202, ((int)1));
			__m_cycle_56.phase(mod_4203);
			t_sample cycle_4200 = __m_cycle_56(__sinedata);
			t_sample cycleindex_4201 = __m_cycle_56.phase();
			t_sample add_4198 = (cycle_4200 + ((int)1));
			t_sample div_4197 = (add_4198 * ((t_sample)0.5));
			t_sample mul_4199 = (div_4197 * mul_4118);
			t_sample sub_4422 = (mul_4199 - ((int)0));
			t_sample scale_4419 = ((safepow((sub_4422 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_4204 = scale_4419;
			t_sample mtof_4205 = mtof(scale_4204, ((int)440));
			t_sample mul_4192 = (mtof_4205 * div_4193);
			t_sample cos_4190 = cos(mul_4192);
			t_sample mul_4185 = (cos_4190 * (-2));
			t_sample sin_4191 = sin(mul_4192);
			t_sample mul_4189 = (sin_4191 * ((t_sample)0.5));
			t_sample div_4188 = (mul_4189 * ((t_sample)0.33333333333333));
			t_sample rsub_4183 = (((int)1) - div_4188);
			t_sample add_4187 = (div_4188 + ((int)1));
			t_sample rdiv_4186 = safediv(((int)1), add_4187);
			t_sample mul_4182 = (rdiv_4186 * rsub_4183);
			__m_slide_57 = fixdenorm((__m_slide_57 + (((mul_4182 > __m_slide_57) ? iup_58 : idown_59) * (mul_4182 - __m_slide_57))));
			t_sample slide_4179 = __m_slide_57;
			t_sample gen_4195 = slide_4179;
			t_sample mul_4184 = (rdiv_4186 * mul_4185);
			__m_slide_60 = fixdenorm((__m_slide_60 + (((mul_4184 > __m_slide_60) ? iup_61 : idown_62) * (mul_4184 - __m_slide_60))));
			t_sample slide_4180 = __m_slide_60;
			t_sample gen_4194 = slide_4180;
			t_sample mul_4215 = (add_4132 * gen_4195);
			t_sample mul_4212 = (m_history_4 * gen_4194);
			t_sample mul_4210 = (m_history_5 * ((int)1));
			t_sample mul_4206 = (m_history_6 * gen_4195);
			t_sample mul_4208 = (m_history_3 * gen_4194);
			t_sample sub_4214 = (((mul_4210 + mul_4212) + mul_4215) - (mul_4208 + mul_4206));
			t_sample gen_4220 = sub_4214;
			t_sample history_4207_next_4216 = fixdenorm(m_history_3);
			t_sample history_4211_next_4217 = fixdenorm(m_history_4);
			t_sample history_4213_next_4218 = fixdenorm(add_4132);
			t_sample history_4209_next_4219 = fixdenorm(sub_4214);
			t_sample mul_4136 = (((gate_4123 + gen_4220) + gen_4178) * scale_4400);
			t_sample add_4269 = (mul_4136 + gate_4122);
			t_sample out2 = add_4269;
			t_sample mul_4134 = ((gen_4220 + gen_4178) * ((t_sample)0.5));
			t_sample dcblock_4135 = __m_dcblock_63(mul_4134);
			t_sample history_4131_next_4329 = fixdenorm(dcblock_4270);
			t_sample history_4276_next_4330 = fixdenorm(dcblock_4135);
			m_history_22 = history_4126_next_4128;
			m_history_21 = history_4104_next_4107;
			m_history_19 = history_4099_next_4109;
			m_history_20 = history_4101_next_4108;
			m_history_18 = history_4254_next_4259;
			m_history_15 = history_4252_next_4262;
			m_history_16 = history_4256_next_4261;
			m_history_17 = history_4250_next_4260;
			m_history_14 = history_4313_next_4322;
			m_history_11 = history_4315_next_4325;
			m_history_12 = history_4319_next_4324;
			m_history_13 = history_4317_next_4323;
			m_history_10 = history_4165_next_4174;
			m_history_7 = history_4167_next_4177;
			m_history_8 = history_4171_next_4176;
			m_history_9 = history_4169_next_4175;
			m_history_6 = history_4207_next_4216;
			m_history_3 = history_4209_next_4219;
			m_history_4 = history_4213_next_4218;
			m_history_5 = history_4211_next_4217;
			m_history_2 = history_4131_next_4329;
			m_history_1 = history_4276_next_4330;
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
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_24 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 5; }

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
		case 3: self->set_sw1(value); break;
		case 4: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_depth_23; break;
		case 1: *value = self->m_knob4_rate_26; break;
		case 2: *value = self->m_knob5_fb_24; break;
		case 3: *value = self->m_sw_27; break;
		case 4: *value = self->m_sw_25; break;
		
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
	// initialize parameter 3 ("m_sw_27")
	pi = self->__commonstate.params + 3;
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
	// initialize parameter 4 ("m_sw_25")
	pi = self->__commonstate.params + 4;
	pi->name = "sw5";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Phaser::
