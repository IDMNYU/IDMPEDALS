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
	t_sample m_knob1_res_22;
	t_sample m_knob6_r_21;
	t_sample m_knob3_min_23;
	t_sample m_sw_24;
	t_sample m_sw_25;
	t_sample m_knob4_max_26;
	t_sample m_knob2_key_20;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample m_history_7;
	t_sample m_knob5_r_19;
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
		m_knob5_r_19 = ((int)0);
		m_knob2_key_20 = ((int)0);
		m_knob6_r_21 = ((int)0);
		m_knob1_res_22 = ((int)0);
		m_knob3_min_23 = ((int)0);
		m_sw_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_knob4_max_26 = ((int)0);
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
		t_sample sqrt_511 = sqrt(m_knob1_res_22);
		t_sample sqrt_520 = sqrt(sqrt_511);
		t_sample mul_523 = (sqrt_520 * ((t_sample)0.99));
		t_sample mul_357 = (m_knob2_key_20 * ((int)12));
		t_sample round_356 = round(mul_357);
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
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_514 = __m_sah_27(m_history_18, m_sw_24, ((int)0));
			t_sample gen_516 = sah_514;
			t_sample rsub_512 = (((int)1) - sah_514);
			t_sample history_513_next_515 = fixdenorm(rsub_512);
			t_sample out3 = gen_516;
			t_sample add_519 = (gen_516 + ((int)1));
			t_sample choice_28 = int(add_519);
			t_sample gate_517 = (((choice_28 >= 1) && (choice_28 < 2)) ? in1 : 0);
			t_sample gate_518 = ((choice_28 >= 2) ? in1 : 0);
			t_sample switch_345 = (m_sw_25 ? gate_518 : ((int)0));
			t_sample mix_752 = (m_history_17 + (((t_sample)0.0019634941468452) * (m_knob3_min_23 - m_history_17)));
			t_sample mix_472 = mix_752;
			t_sample mix_753 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_472 - m_history_16)));
			t_sample mix_470 = mix_753;
			t_sample mix_754 = (m_history_15 + (((t_sample)0.0019634941468452) * (mix_470 - m_history_15)));
			t_sample mix_468 = mix_754;
			t_sample gen_509 = mix_468;
			t_sample history_473_next_475 = fixdenorm(mix_472);
			t_sample history_471_next_476 = fixdenorm(mix_470);
			t_sample history_469_next_477 = fixdenorm(mix_468);
			t_sample sub_758 = (gen_509 - ((int)0));
			t_sample scale_755 = ((safepow((sub_758 * ((t_sample)1)), ((int)1)) * ((int)84)) + ((int)24));
			t_sample mix_759 = (m_history_14 + (((t_sample)0.0019634941468452) * (m_knob4_max_26 - m_history_14)));
			t_sample mix_530 = mix_759;
			t_sample mix_760 = (m_history_13 + (((t_sample)0.0019634941468452) * (mix_530 - m_history_13)));
			t_sample mix_533 = mix_760;
			t_sample mix_761 = (m_history_12 + (((t_sample)0.0019634941468452) * (mix_533 - m_history_12)));
			t_sample mix_532 = mix_761;
			t_sample gen_478 = mix_532;
			t_sample history_473_next_529 = fixdenorm(mix_530);
			t_sample history_471_next_528 = fixdenorm(mix_533);
			t_sample history_469_next_527 = fixdenorm(mix_532);
			t_sample sub_765 = (gen_478 - ((int)0));
			t_sample scale_762 = ((safepow((sub_765 * ((t_sample)1)), ((int)1)) * ((int)84)) + ((int)24));
			t_sample mix_766 = (m_history_11 + (((t_sample)0.0019634941468452) * (m_knob5_r_19 - m_history_11)));
			t_sample mix_544 = mix_766;
			t_sample mix_767 = (m_history_10 + (((t_sample)0.0019634941468452) * (mix_544 - m_history_10)));
			t_sample mix_543 = mix_767;
			t_sample mix_768 = (m_history_9 + (((t_sample)0.0019634941468452) * (mix_543 - m_history_9)));
			t_sample mix_542 = mix_768;
			t_sample gen_508 = mix_542;
			t_sample history_473_next_548 = fixdenorm(mix_544);
			t_sample history_471_next_546 = fixdenorm(mix_543);
			t_sample history_469_next_547 = fixdenorm(mix_542);
			t_sample mul_521 = (gen_508 * ((int)10));
			t_sample phasor_522 = __m_phasor_29(mul_521, samples_to_seconds);
			t_sample mix_769 = (m_history_8 + (((t_sample)0.0019634941468452) * (m_knob6_r_21 - m_history_8)));
			t_sample mix_557 = mix_769;
			t_sample mix_770 = (m_history_7 + (((t_sample)0.0019634941468452) * (mix_557 - m_history_7)));
			t_sample mix_556 = mix_770;
			t_sample mix_771 = (m_history_6 + (((t_sample)0.0019634941468452) * (mix_556 - m_history_6)));
			t_sample mix_555 = mix_771;
			t_sample gen_507 = mix_555;
			t_sample history_473_next_561 = fixdenorm(mix_557);
			t_sample history_471_next_560 = fixdenorm(mix_556);
			t_sample history_469_next_559 = fixdenorm(mix_555);
			t_sample mul_462 = (gen_507 * ((int)10));
			t_sample phasor_463 = __m_phasor_30(mul_462, samples_to_seconds);
			t_sample sah_464 = __m_sah_31(phasor_522, phasor_463, ((t_sample)0.5));
			t_sample add_359 = (sah_464 + ((t_sample)0.75));
			t_sample mod_358 = safemod(add_359, ((int)1));
			t_sample orange_774 = (scale_762 - scale_755);
			t_sample sub_775 = (mod_358 - ((int)0));
			t_sample scale_772 = ((safepow((sub_775 * ((t_sample)1)), ((int)1)) * orange_774) + scale_755);
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
			t_sample oct = floor((scale_772 * ((t_sample)0.083333333333333)));
			t_sample pc = floor(safemod((scale_772 + round_356), ((int)12)));
			int index_trunc_43 = fixnan(floor(pc));
			bool index_ignore_44 = ((index_trunc_43 >= ms_dim) || (index_trunc_43 < 0));
			// samples ms channel 1;
			t_sample pc_grid = (index_ignore_44 ? 0 : m_ms_5.read(index_trunc_43, 0));
			t_sample outpitch = ((pc_grid + (oct * ((int)12))) - round_356);
			t_sample mtof_367 = mtof(outpitch, ((int)440));
			t_sample rdiv_366 = safediv(((int)1000), mtof_367);
			t_sample mstosamps_365 = (rdiv_366 * (samplerate * 0.001));
			t_sample tap_395 = m_delay_4.read_linear(mstosamps_365);
			t_sample mul_393 = (tap_395 * mul_523);
			t_sample mul_348 = (mul_393 * ((t_sample)0.4));
			t_sample mul_349 = (mul_393 * ((t_sample)0.6));
			t_sample add_361 = (sah_464 + ((t_sample)0.5));
			t_sample mod_360 = safemod(add_361, ((int)1));
			t_sample orange_778 = (scale_762 - scale_755);
			t_sample sub_779 = (mod_360 - ((int)0));
			t_sample scale_776 = ((safepow((sub_779 * ((t_sample)1)), ((int)1)) * orange_778) + scale_755);
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
			t_sample oct_567 = floor((scale_776 * ((t_sample)0.083333333333333)));
			t_sample pc_566 = floor(safemod((scale_776 + round_356), ((int)12)));
			int index_trunc_56 = fixnan(floor(pc_566));
			bool index_ignore_57 = ((index_trunc_56 >= ms_dim) || (index_trunc_56 < 0));
			// samples ms channel 1;
			t_sample pc_grid_568 = (index_ignore_57 ? 0 : m_ms_5.read(index_trunc_56, 0));
			t_sample outpitch_569 = ((pc_grid_568 + (oct_567 * ((int)12))) - round_356);
			t_sample mtof_399 = mtof(outpitch_569, ((int)440));
			t_sample rdiv_398 = safediv(((int)1000), mtof_399);
			t_sample mstosamps_397 = (rdiv_398 * (samplerate * 0.001));
			t_sample tap_427 = m_delay_3.read_linear(mstosamps_397);
			t_sample mul_425 = (tap_427 * mul_523);
			t_sample mul_350 = (mul_425 * ((t_sample)0.1));
			t_sample mul_351 = (mul_425 * ((t_sample)0.9));
			t_sample add_461 = (sah_464 + ((int)0));
			t_sample mod_460 = safemod(add_461, ((int)1));
			t_sample orange_782 = (scale_762 - scale_755);
			t_sample sub_783 = (mod_460 - ((int)0));
			t_sample scale_780 = ((safepow((sub_783 * ((t_sample)1)), ((int)1)) * orange_782) + scale_755);
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
			t_sample oct_571 = floor((scale_780 * ((t_sample)0.083333333333333)));
			t_sample pc_570 = floor(safemod((scale_780 + round_356), ((int)12)));
			int index_trunc_69 = fixnan(floor(pc_570));
			bool index_ignore_70 = ((index_trunc_69 >= ms_dim) || (index_trunc_69 < 0));
			// samples ms channel 1;
			t_sample pc_grid_572 = (index_ignore_70 ? 0 : m_ms_5.read(index_trunc_69, 0));
			t_sample outpitch_573 = ((pc_grid_572 + (oct_571 * ((int)12))) - round_356);
			t_sample mtof_481 = mtof(outpitch_573, ((int)440));
			t_sample rdiv_480 = safediv(((int)1000), mtof_481);
			t_sample mstosamps_479 = (rdiv_480 * (samplerate * 0.001));
			t_sample tap_526 = m_delay_2.read_linear(mstosamps_479);
			t_sample mul_524 = (tap_526 * mul_523);
			t_sample mul_355 = (mul_524 * ((t_sample)0.9));
			t_sample mul_354 = (mul_524 * ((t_sample)0.1));
			t_sample add_363 = (sah_464 + ((t_sample)0.25));
			t_sample mod_362 = safemod(add_363, ((int)1));
			t_sample orange_786 = (scale_762 - scale_755);
			t_sample sub_787 = (mod_362 - ((int)0));
			t_sample scale_784 = ((safepow((sub_787 * ((t_sample)1)), ((int)1)) * orange_786) + scale_755);
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
			t_sample oct_575 = floor((scale_784 * ((t_sample)0.083333333333333)));
			t_sample pc_574 = floor(safemod((scale_784 + round_356), ((int)12)));
			int index_trunc_82 = fixnan(floor(pc_574));
			bool index_ignore_83 = ((index_trunc_82 >= ms_dim) || (index_trunc_82 < 0));
			// samples ms channel 1;
			t_sample pc_grid_576 = (index_ignore_83 ? 0 : m_ms_5.read(index_trunc_82, 0));
			t_sample outpitch_577 = ((pc_grid_576 + (oct_575 * ((int)12))) - round_356);
			t_sample mtof_431 = mtof(outpitch_577, ((int)440));
			t_sample rdiv_430 = safediv(((int)1000), mtof_431);
			t_sample mstosamps_429 = (rdiv_430 * (samplerate * 0.001));
			t_sample tap_459 = m_delay_1.read_linear(mstosamps_429);
			t_sample mul_457 = (tap_459 * mul_523);
			t_sample mul_353 = (mul_457 * ((t_sample)0.6));
			t_sample div_347 = (((((mul_353 + mul_355) + switch_345) + mul_350) + mul_348) * ((t_sample)0.25));
			t_sample out1 = (gate_517 + div_347);
			t_sample mul_352 = (mul_457 * ((t_sample)0.4));
			t_sample div_346 = (((((mul_352 + mul_354) + switch_345) + mul_351) + mul_349) * ((t_sample)0.25));
			t_sample out2 = (gate_517 + div_346);
			m_history_18 = history_513_next_515;
			m_history_17 = history_473_next_475;
			m_history_15 = history_469_next_477;
			m_history_16 = history_471_next_476;
			m_history_14 = history_473_next_529;
			m_history_12 = history_469_next_527;
			m_history_13 = history_471_next_528;
			m_history_11 = history_473_next_548;
			m_history_9 = history_469_next_547;
			m_history_10 = history_471_next_546;
			m_history_8 = history_473_next_561;
			m_history_6 = history_469_next_559;
			m_history_7 = history_471_next_560;
			m_delay_4.write((mul_393 + gate_518));
			m_delay_3.write((mul_425 + gate_518));
			m_delay_2.write((mul_524 + gate_518));
			m_delay_1.write((mul_457 + gate_518));
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
	inline void set_knob5_r1(t_param _value) {
		m_knob5_r_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2_key(t_param _value) {
		m_knob2_key_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_r2(t_param _value) {
		m_knob6_r_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_res(t_param _value) {
		m_knob1_res_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_min(t_param _value) {
		m_knob3_min_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_max(t_param _value) {
		m_knob4_max_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob1_res_22; break;
		case 1: *value = self->m_knob2_key_20; break;
		case 2: *value = self->m_knob3_min_23; break;
		case 3: *value = self->m_knob4_max_26; break;
		case 4: *value = self->m_knob5_r_19; break;
		case 5: *value = self->m_knob6_r_21; break;
		
		case 7: *value = self->m_sw_24; break;
		case 8: *value = self->m_sw_25; break;
		
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
	// initialize parameter 0 ("m_knob1_res_22")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_res_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob2_key_20")
	pi = self->__commonstate.params + 1;
	pi->name = "knob2_key";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_key_20;
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
	// initialize parameter 3 ("m_knob4_max_26")
	pi = self->__commonstate.params + 3;
	pi->name = "knob4_max";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_max_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob5_r_19")
	pi = self->__commonstate.params + 4;
	pi->name = "knob5_r1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_r_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob6_r_21")
	pi = self->__commonstate.params + 5;
	pi->name = "knob6_r2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_r_21;
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
	// initialize parameter 7 ("m_sw_24")
	pi = self->__commonstate.params + 7;
	pi->name = "sw1";
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
	// initialize parameter 8 ("m_sw_25")
	pi = self->__commonstate.params + 8;
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


} // SHComb2::
