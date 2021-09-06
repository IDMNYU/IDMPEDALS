#include "SHComb2.h"

namespace SHComb2 {

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
	Data m_ms_5;
	Delay m_delay_1;
	Delay m_delay_3;
	Delay m_delay_4;
	Delay m_delay_2;
	Phasor __m_phasor_30;
	Phasor __m_phasor_29;
	Sah __m_sah_27;
	Sah __m_sah_31;
	int __exception;
	int vectorsize;
	t_sample m_history_8;
	t_sample m_knob4_max_22;
	t_sample m_sw_21;
	t_sample m_knob3_min_23;
	t_sample m_knob5_r_24;
	t_sample m_knob2_key_25;
	t_sample m_knob6_r_26;
	t_sample m_knob1_res_20;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample m_history_7;
	t_sample m_sw_19;
	t_sample m_history_17;
	t_sample m_history_11;
	t_sample m_history_10;
	t_sample m_history_9;
	t_sample m_history_18;
	t_sample m_history_12;
	t_sample m_history_6;
	t_sample m_history_13;
	t_sample m_history_16;
	t_sample m_history_15;
	t_sample m_history_14;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)6000));
		m_delay_2.reset("m_delay_2", ((int)6000));
		m_delay_3.reset("m_delay_3", ((int)6000));
		m_delay_4.reset("m_delay_4", ((int)6000));
		m_ms_5.reset("ms", ((int)12), ((int)1));
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
		m_sw_19 = ((int)0);
		m_knob1_res_20 = ((int)0);
		m_sw_21 = ((int)0);
		m_knob4_max_22 = ((int)0);
		m_knob3_min_23 = ((int)0);
		m_knob5_r_24 = ((int)0);
		m_knob2_key_25 = ((int)0);
		m_knob6_r_26 = ((int)0);
		__m_sah_27.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_29.reset(0);
		__m_phasor_30.reset(0);
		__m_sah_31.reset(0);
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
		t_sample sqrt_4237 = sqrt(m_knob1_res_20);
		t_sample sqrt_4246 = sqrt(sqrt_4237);
		t_sample mul_4249 = (sqrt_4246 * ((t_sample)0.99));
		t_sample mul_4083 = (m_knob2_key_25 * ((int)12));
		t_sample round_4082 = round(mul_4083);
		samples_to_seconds = (1 / samplerate);
		int ms_dim = m_ms_5.dim;
		int ms_channels = m_ms_5.channels;
		bool index_ignore_32 = (((int)1) >= ms_dim);
		bool index_ignore_33 = (((int)2) >= ms_dim);
		bool index_ignore_34 = (((int)3) >= ms_dim);
		bool index_ignore_35 = (((int)4) >= ms_dim);
		bool index_ignore_36 = (((int)5) >= ms_dim);
		bool index_ignore_37 = (((int)6) >= ms_dim);
		bool index_ignore_38 = (((int)7) >= ms_dim);
		bool index_ignore_39 = (((int)8) >= ms_dim);
		bool index_ignore_40 = (((int)9) >= ms_dim);
		bool index_ignore_41 = (((int)10) >= ms_dim);
		bool index_ignore_42 = (((int)11) >= ms_dim);
		bool index_ignore_45 = (((int)1) >= ms_dim);
		bool index_ignore_46 = (((int)2) >= ms_dim);
		bool index_ignore_47 = (((int)3) >= ms_dim);
		bool index_ignore_48 = (((int)4) >= ms_dim);
		bool index_ignore_49 = (((int)5) >= ms_dim);
		bool index_ignore_50 = (((int)6) >= ms_dim);
		bool index_ignore_51 = (((int)7) >= ms_dim);
		bool index_ignore_52 = (((int)8) >= ms_dim);
		bool index_ignore_53 = (((int)9) >= ms_dim);
		bool index_ignore_54 = (((int)10) >= ms_dim);
		bool index_ignore_55 = (((int)11) >= ms_dim);
		bool index_ignore_58 = (((int)1) >= ms_dim);
		bool index_ignore_59 = (((int)2) >= ms_dim);
		bool index_ignore_60 = (((int)3) >= ms_dim);
		bool index_ignore_61 = (((int)4) >= ms_dim);
		bool index_ignore_62 = (((int)5) >= ms_dim);
		bool index_ignore_63 = (((int)6) >= ms_dim);
		bool index_ignore_64 = (((int)7) >= ms_dim);
		bool index_ignore_65 = (((int)8) >= ms_dim);
		bool index_ignore_66 = (((int)9) >= ms_dim);
		bool index_ignore_67 = (((int)10) >= ms_dim);
		bool index_ignore_68 = (((int)11) >= ms_dim);
		bool index_ignore_71 = (((int)1) >= ms_dim);
		bool index_ignore_72 = (((int)2) >= ms_dim);
		bool index_ignore_73 = (((int)3) >= ms_dim);
		bool index_ignore_74 = (((int)4) >= ms_dim);
		bool index_ignore_75 = (((int)5) >= ms_dim);
		bool index_ignore_76 = (((int)6) >= ms_dim);
		bool index_ignore_77 = (((int)7) >= ms_dim);
		bool index_ignore_78 = (((int)8) >= ms_dim);
		bool index_ignore_79 = (((int)9) >= ms_dim);
		bool index_ignore_80 = (((int)10) >= ms_dim);
		bool index_ignore_81 = (((int)11) >= ms_dim);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_4240 = __m_sah_27(m_history_18, m_sw_19, ((int)0));
			t_sample gen_4242 = sah_4240;
			t_sample rsub_4238 = (((int)1) - sah_4240);
			t_sample history_4239_next_4241 = fixdenorm(rsub_4238);
			t_sample out3 = gen_4242;
			t_sample add_4245 = (gen_4242 + ((int)1));
			t_sample choice_28 = int(add_4245);
			t_sample gate_4243 = (((choice_28 >= 1) && (choice_28 < 2)) ? in1 : 0);
			t_sample gate_4244 = ((choice_28 >= 2) ? in1 : 0);
			t_sample switch_4071 = (m_sw_21 ? gate_4244 : ((int)0));
			t_sample mix_4478 = (m_history_17 + (((t_sample)0.003926980723806) * (m_knob3_min_23 - m_history_17)));
			t_sample mix_4198 = mix_4478;
			t_sample mix_4479 = (m_history_16 + (((t_sample)0.003926980723806) * (mix_4198 - m_history_16)));
			t_sample mix_4196 = mix_4479;
			t_sample mix_4480 = (m_history_15 + (((t_sample)0.003926980723806) * (mix_4196 - m_history_15)));
			t_sample mix_4194 = mix_4480;
			t_sample gen_4235 = mix_4194;
			t_sample history_4199_next_4201 = fixdenorm(mix_4198);
			t_sample history_4197_next_4202 = fixdenorm(mix_4196);
			t_sample history_4195_next_4203 = fixdenorm(mix_4194);
			t_sample sub_4484 = (gen_4235 - ((int)0));
			t_sample scale_4481 = ((safepow((sub_4484 * ((t_sample)1)), ((int)1)) * ((int)84)) + ((int)24));
			t_sample mix_4485 = (m_history_14 + (((t_sample)0.003926980723806) * (m_knob4_max_22 - m_history_14)));
			t_sample mix_4259 = mix_4485;
			t_sample mix_4486 = (m_history_13 + (((t_sample)0.003926980723806) * (mix_4259 - m_history_13)));
			t_sample mix_4258 = mix_4486;
			t_sample mix_4487 = (m_history_12 + (((t_sample)0.003926980723806) * (mix_4258 - m_history_12)));
			t_sample mix_4262 = mix_4487;
			t_sample gen_4204 = mix_4262;
			t_sample history_4199_next_4257 = fixdenorm(mix_4259);
			t_sample history_4197_next_4254 = fixdenorm(mix_4258);
			t_sample history_4195_next_4253 = fixdenorm(mix_4262);
			t_sample sub_4491 = (gen_4204 - ((int)0));
			t_sample scale_4488 = ((safepow((sub_4491 * ((t_sample)1)), ((int)1)) * ((int)84)) + ((int)24));
			t_sample mix_4492 = (m_history_11 + (((t_sample)0.003926980723806) * (m_knob5_r_24 - m_history_11)));
			t_sample mix_4271 = mix_4492;
			t_sample mix_4493 = (m_history_10 + (((t_sample)0.003926980723806) * (mix_4271 - m_history_10)));
			t_sample mix_4267 = mix_4493;
			t_sample mix_4494 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_4267 - m_history_9)));
			t_sample mix_4275 = mix_4494;
			t_sample gen_4234 = mix_4275;
			t_sample history_4199_next_4268 = fixdenorm(mix_4271);
			t_sample history_4197_next_4272 = fixdenorm(mix_4267);
			t_sample history_4195_next_4266 = fixdenorm(mix_4275);
			t_sample mul_4247 = (gen_4234 * ((int)10));
			t_sample phasor_4248 = __m_phasor_29(mul_4247, samples_to_seconds);
			t_sample mix_4495 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob6_r_26 - m_history_8)));
			t_sample mix_4284 = mix_4495;
			t_sample mix_4496 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_4284 - m_history_7)));
			t_sample mix_4280 = mix_4496;
			t_sample mix_4497 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_4280 - m_history_6)));
			t_sample mix_4288 = mix_4497;
			t_sample gen_4233 = mix_4288;
			t_sample history_4199_next_4281 = fixdenorm(mix_4284);
			t_sample history_4197_next_4285 = fixdenorm(mix_4280);
			t_sample history_4195_next_4279 = fixdenorm(mix_4288);
			t_sample mul_4188 = (gen_4233 * ((int)10));
			t_sample phasor_4189 = __m_phasor_30(mul_4188, samples_to_seconds);
			t_sample sah_4190 = __m_sah_31(phasor_4248, phasor_4189, ((t_sample)0.5));
			t_sample add_4085 = (sah_4190 + ((t_sample)0.75));
			t_sample mod_4084 = safemod(add_4085, ((int)1));
			t_sample orange_4500 = (scale_4488 - scale_4481);
			t_sample sub_4501 = (mod_4084 - ((int)0));
			t_sample scale_4498 = ((safepow((sub_4501 * ((t_sample)1)), ((int)1)) * orange_4500) + scale_4481);
			m_ms_5.write(((int)0), 0, 0);
			if ((!index_ignore_32)) {
				m_ms_5.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_33)) {
				m_ms_5.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_34)) {
				m_ms_5.write(((int)4), ((int)3), 0);
				
			};
			if ((!index_ignore_35)) {
				m_ms_5.write(((int)4), ((int)4), 0);
				
			};
			if ((!index_ignore_36)) {
				m_ms_5.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_37)) {
				m_ms_5.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_38)) {
				m_ms_5.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_39)) {
				m_ms_5.write(((int)9), ((int)8), 0);
				
			};
			if ((!index_ignore_40)) {
				m_ms_5.write(((int)9), ((int)9), 0);
				
			};
			if ((!index_ignore_41)) {
				m_ms_5.write(((int)11), ((int)10), 0);
				
			};
			if ((!index_ignore_42)) {
				m_ms_5.write(((int)11), ((int)11), 0);
				
			};
			t_sample oct = floor((scale_4498 * ((t_sample)0.083333333333333)));
			t_sample pc = floor(safemod((scale_4498 + round_4082), ((int)12)));
			int index_trunc_43 = fixnan(floor(pc));
			bool index_ignore_44 = ((index_trunc_43 >= ms_dim) || (index_trunc_43 < 0));
			// samples ms channel 1;
			t_sample pc_grid = (index_ignore_44 ? 0 : m_ms_5.read(index_trunc_43, 0));
			t_sample outpitch = ((pc_grid + (oct * ((int)12))) - round_4082);
			t_sample mtof_4093 = mtof(outpitch, ((int)440));
			t_sample rdiv_4092 = safediv(((int)1000), mtof_4093);
			t_sample mstosamps_4091 = (rdiv_4092 * (samplerate * 0.001));
			t_sample tap_4121 = m_delay_4.read_linear(mstosamps_4091);
			t_sample mul_4119 = (tap_4121 * mul_4249);
			t_sample mul_4074 = (mul_4119 * ((t_sample)0.4));
			t_sample mul_4075 = (mul_4119 * ((t_sample)0.6));
			t_sample add_4087 = (sah_4190 + ((t_sample)0.5));
			t_sample mod_4086 = safemod(add_4087, ((int)1));
			t_sample orange_4504 = (scale_4488 - scale_4481);
			t_sample sub_4505 = (mod_4086 - ((int)0));
			t_sample scale_4502 = ((safepow((sub_4505 * ((t_sample)1)), ((int)1)) * orange_4504) + scale_4481);
			m_ms_5.write(((int)0), 0, 0);
			if ((!index_ignore_45)) {
				m_ms_5.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_46)) {
				m_ms_5.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_47)) {
				m_ms_5.write(((int)4), ((int)3), 0);
				
			};
			if ((!index_ignore_48)) {
				m_ms_5.write(((int)4), ((int)4), 0);
				
			};
			if ((!index_ignore_49)) {
				m_ms_5.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_50)) {
				m_ms_5.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_51)) {
				m_ms_5.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_52)) {
				m_ms_5.write(((int)9), ((int)8), 0);
				
			};
			if ((!index_ignore_53)) {
				m_ms_5.write(((int)9), ((int)9), 0);
				
			};
			if ((!index_ignore_54)) {
				m_ms_5.write(((int)11), ((int)10), 0);
				
			};
			if ((!index_ignore_55)) {
				m_ms_5.write(((int)11), ((int)11), 0);
				
			};
			t_sample oct_4292 = floor((scale_4502 * ((t_sample)0.083333333333333)));
			t_sample pc_4293 = floor(safemod((scale_4502 + round_4082), ((int)12)));
			int index_trunc_56 = fixnan(floor(pc_4293));
			bool index_ignore_57 = ((index_trunc_56 >= ms_dim) || (index_trunc_56 < 0));
			// samples ms channel 1;
			t_sample pc_grid_4295 = (index_ignore_57 ? 0 : m_ms_5.read(index_trunc_56, 0));
			t_sample outpitch_4294 = ((pc_grid_4295 + (oct_4292 * ((int)12))) - round_4082);
			t_sample mtof_4125 = mtof(outpitch_4294, ((int)440));
			t_sample rdiv_4124 = safediv(((int)1000), mtof_4125);
			t_sample mstosamps_4123 = (rdiv_4124 * (samplerate * 0.001));
			t_sample tap_4153 = m_delay_3.read_linear(mstosamps_4123);
			t_sample mul_4151 = (tap_4153 * mul_4249);
			t_sample mul_4076 = (mul_4151 * ((t_sample)0.1));
			t_sample mul_4077 = (mul_4151 * ((t_sample)0.9));
			t_sample add_4187 = (sah_4190 + ((int)0));
			t_sample mod_4186 = safemod(add_4187, ((int)1));
			t_sample orange_4508 = (scale_4488 - scale_4481);
			t_sample sub_4509 = (mod_4186 - ((int)0));
			t_sample scale_4506 = ((safepow((sub_4509 * ((t_sample)1)), ((int)1)) * orange_4508) + scale_4481);
			m_ms_5.write(((int)0), 0, 0);
			if ((!index_ignore_58)) {
				m_ms_5.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_59)) {
				m_ms_5.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_60)) {
				m_ms_5.write(((int)4), ((int)3), 0);
				
			};
			if ((!index_ignore_61)) {
				m_ms_5.write(((int)4), ((int)4), 0);
				
			};
			if ((!index_ignore_62)) {
				m_ms_5.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_63)) {
				m_ms_5.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_64)) {
				m_ms_5.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_65)) {
				m_ms_5.write(((int)9), ((int)8), 0);
				
			};
			if ((!index_ignore_66)) {
				m_ms_5.write(((int)9), ((int)9), 0);
				
			};
			if ((!index_ignore_67)) {
				m_ms_5.write(((int)11), ((int)10), 0);
				
			};
			if ((!index_ignore_68)) {
				m_ms_5.write(((int)11), ((int)11), 0);
				
			};
			t_sample oct_4296 = floor((scale_4506 * ((t_sample)0.083333333333333)));
			t_sample pc_4297 = floor(safemod((scale_4506 + round_4082), ((int)12)));
			int index_trunc_69 = fixnan(floor(pc_4297));
			bool index_ignore_70 = ((index_trunc_69 >= ms_dim) || (index_trunc_69 < 0));
			// samples ms channel 1;
			t_sample pc_grid_4299 = (index_ignore_70 ? 0 : m_ms_5.read(index_trunc_69, 0));
			t_sample outpitch_4298 = ((pc_grid_4299 + (oct_4296 * ((int)12))) - round_4082);
			t_sample mtof_4207 = mtof(outpitch_4298, ((int)440));
			t_sample rdiv_4206 = safediv(((int)1000), mtof_4207);
			t_sample mstosamps_4205 = (rdiv_4206 * (samplerate * 0.001));
			t_sample tap_4252 = m_delay_2.read_linear(mstosamps_4205);
			t_sample mul_4250 = (tap_4252 * mul_4249);
			t_sample mul_4081 = (mul_4250 * ((t_sample)0.9));
			t_sample mul_4080 = (mul_4250 * ((t_sample)0.1));
			t_sample add_4089 = (sah_4190 + ((t_sample)0.25));
			t_sample mod_4088 = safemod(add_4089, ((int)1));
			t_sample orange_4512 = (scale_4488 - scale_4481);
			t_sample sub_4513 = (mod_4088 - ((int)0));
			t_sample scale_4510 = ((safepow((sub_4513 * ((t_sample)1)), ((int)1)) * orange_4512) + scale_4481);
			m_ms_5.write(((int)0), 0, 0);
			if ((!index_ignore_71)) {
				m_ms_5.write(((int)0), ((int)1), 0);
				
			};
			if ((!index_ignore_72)) {
				m_ms_5.write(((int)2), ((int)2), 0);
				
			};
			if ((!index_ignore_73)) {
				m_ms_5.write(((int)4), ((int)3), 0);
				
			};
			if ((!index_ignore_74)) {
				m_ms_5.write(((int)4), ((int)4), 0);
				
			};
			if ((!index_ignore_75)) {
				m_ms_5.write(((int)5), ((int)5), 0);
				
			};
			if ((!index_ignore_76)) {
				m_ms_5.write(((int)7), ((int)6), 0);
				
			};
			if ((!index_ignore_77)) {
				m_ms_5.write(((int)7), ((int)7), 0);
				
			};
			if ((!index_ignore_78)) {
				m_ms_5.write(((int)9), ((int)8), 0);
				
			};
			if ((!index_ignore_79)) {
				m_ms_5.write(((int)9), ((int)9), 0);
				
			};
			if ((!index_ignore_80)) {
				m_ms_5.write(((int)11), ((int)10), 0);
				
			};
			if ((!index_ignore_81)) {
				m_ms_5.write(((int)11), ((int)11), 0);
				
			};
			t_sample oct_4300 = floor((scale_4510 * ((t_sample)0.083333333333333)));
			t_sample pc_4301 = floor(safemod((scale_4510 + round_4082), ((int)12)));
			int index_trunc_82 = fixnan(floor(pc_4301));
			bool index_ignore_83 = ((index_trunc_82 >= ms_dim) || (index_trunc_82 < 0));
			// samples ms channel 1;
			t_sample pc_grid_4303 = (index_ignore_83 ? 0 : m_ms_5.read(index_trunc_82, 0));
			t_sample outpitch_4302 = ((pc_grid_4303 + (oct_4300 * ((int)12))) - round_4082);
			t_sample mtof_4157 = mtof(outpitch_4302, ((int)440));
			t_sample rdiv_4156 = safediv(((int)1000), mtof_4157);
			t_sample mstosamps_4155 = (rdiv_4156 * (samplerate * 0.001));
			t_sample tap_4185 = m_delay_1.read_linear(mstosamps_4155);
			t_sample mul_4183 = (tap_4185 * mul_4249);
			t_sample mul_4079 = (mul_4183 * ((t_sample)0.6));
			t_sample div_4073 = (((((mul_4079 + mul_4081) + switch_4071) + mul_4076) + mul_4074) * ((t_sample)0.25));
			t_sample out1 = (gate_4243 + div_4073);
			t_sample mul_4078 = (mul_4183 * ((t_sample)0.4));
			t_sample div_4072 = (((((mul_4078 + mul_4080) + switch_4071) + mul_4077) + mul_4075) * ((t_sample)0.25));
			t_sample out2 = (gate_4243 + div_4072);
			m_history_18 = history_4239_next_4241;
			m_history_17 = history_4199_next_4201;
			m_history_15 = history_4195_next_4203;
			m_history_16 = history_4197_next_4202;
			m_history_14 = history_4199_next_4257;
			m_history_12 = history_4195_next_4253;
			m_history_13 = history_4197_next_4254;
			m_history_11 = history_4199_next_4268;
			m_history_9 = history_4195_next_4266;
			m_history_10 = history_4197_next_4272;
			m_history_8 = history_4199_next_4281;
			m_history_6 = history_4195_next_4279;
			m_history_7 = history_4197_next_4285;
			m_delay_4.write((mul_4119 + gate_4244));
			m_delay_3.write((mul_4151 + gate_4244));
			m_delay_2.write((mul_4250 + gate_4244));
			m_delay_1.write((mul_4183 + gate_4244));
			m_delay_1.step();
			m_delay_2.step();
			m_delay_3.step();
			m_delay_4.step();
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
	inline void set_ms(void * _value) {
		m_ms_5.setbuffer(_value);
	};
	inline void set_sw1(t_param _value) {
		m_sw_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_res(t_param _value) {
		m_knob1_res_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_max(t_param _value) {
		m_knob4_max_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_min(t_param _value) {
		m_knob3_min_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_r1(t_param _value) {
		m_knob5_r_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2_key(t_param _value) {
		m_knob2_key_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_r2(t_param _value) {
		m_knob6_r_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 9; }

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
		case 0: self->set_knob1_res(value); break;
		case 1: self->set_knob2_key(value); break;
		case 2: self->set_knob3_min(value); break;
		case 3: self->set_knob4_max(value); break;
		case 4: self->set_knob5_r1(value); break;
		case 5: self->set_knob6_r2(value); break;
		case 6: self->set_ms(ref); break;
		case 7: self->set_sw1(value); break;
		case 8: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_res_20; break;
		case 1: *value = self->m_knob2_key_25; break;
		case 2: *value = self->m_knob3_min_23; break;
		case 3: *value = self->m_knob4_max_22; break;
		case 4: *value = self->m_knob5_r_24; break;
		case 5: *value = self->m_knob6_r_26; break;
		
		case 7: *value = self->m_sw_19; break;
		case 8: *value = self->m_sw_21; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(9 * sizeof(ParamInfo));
	self->__commonstate.numparams = 9;
	// initialize parameter 0 ("m_knob1_res_20")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_res_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob2_key_25")
	pi = self->__commonstate.params + 1;
	pi->name = "knob2_key";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_key_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob3_min_23")
	pi = self->__commonstate.params + 2;
	pi->name = "knob3_min";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_min_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob4_max_22")
	pi = self->__commonstate.params + 3;
	pi->name = "knob4_max";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_max_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob5_r_24")
	pi = self->__commonstate.params + 4;
	pi->name = "knob5_r1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_r_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob6_r_26")
	pi = self->__commonstate.params + 5;
	pi->name = "knob6_r2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_r_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_ms_5")
	pi = self->__commonstate.params + 6;
	pi->name = "ms";
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
	// initialize parameter 7 ("m_sw_19")
	pi = self->__commonstate.params + 7;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_sw_21")
	pi = self->__commonstate.params + 8;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_21;
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


} // SHComb2::
