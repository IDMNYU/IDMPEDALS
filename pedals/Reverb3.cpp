#include "Reverb3.h"

namespace Reverb3 {

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
	DCBlock __m_dcblock_37;
	DCBlock __m_dcblock_36;
	DCBlock __m_dcblock_35;
	DCBlock __m_dcblock_34;
	Delay m_delay_7;
	Delay m_delay_8;
	Delay m_delay_13;
	Delay m_delay_9;
	Delay m_delay_6;
	Delay m_delay_10;
	Delay m_delay_12;
	Delay m_delay_11;
	Phasor __m_phasor_29;
	Phasor __m_phasor_28;
	Sah __m_sah_26;
	int __exception;
	int vectorsize;
	t_sample __m_latch_38;
	t_sample __m_latch_43;
	t_sample samples_to_seconds;
	t_sample m_knob6_fluctuate_25;
	t_sample __m_latch_42;
	t_sample __m_latch_40;
	t_sample __m_latch_41;
	t_sample __m_latch_39;
	t_sample m_sw_24;
	t_sample m_history_19;
	t_sample m_knob4_decay_22;
	t_sample m_history_3;
	t_sample m_history_4;
	t_sample m_history_5;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_knob1_wetdry_23;
	t_sample m_history_14;
	t_sample m_history_16;
	t_sample m_knob5_rotate_20;
	t_sample m_knob3_damp_21;
	t_sample m_history_15;
	t_sample __m_latch_44;
	t_sample m_history_17;
	t_sample m_history_18;
	t_sample __m_latch_45;
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
		m_delay_6.reset("m_delay_6", ((int)100));
		m_delay_7.reset("m_delay_7", ((int)100));
		m_delay_8.reset("m_delay_8", ((int)100));
		m_delay_9.reset("m_delay_9", ((int)100));
		m_delay_10.reset("m_delay_10", ((int)3000));
		m_delay_11.reset("m_delay_11", ((int)3000));
		m_delay_12.reset("m_delay_12", ((int)3000));
		m_delay_13.reset("m_delay_13", ((int)3000));
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_knob5_rotate_20 = ((t_sample)0.25);
		m_knob3_damp_21 = ((t_sample)0.5);
		m_knob4_decay_22 = ((int)100);
		m_knob1_wetdry_23 = ((int)0);
		m_sw_24 = ((int)0);
		m_knob6_fluctuate_25 = ((t_sample)0.1);
		__m_sah_26.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_28.reset(0);
		__m_phasor_29.reset(0);
		__m_dcblock_34.reset();
		__m_dcblock_35.reset();
		__m_dcblock_36.reset();
		__m_dcblock_37.reset();
		__m_latch_38 = 0;
		__m_latch_39 = 0;
		__m_latch_40 = 0;
		__m_latch_41 = 0;
		__m_latch_42 = 0;
		__m_latch_43 = 0;
		__m_latch_44 = 0;
		__m_latch_45 = 0;
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
		t_sample t_496 = exp(safediv(-6.9077552789821, m_knob4_decay_22));
		t_sample sqrt_1184 = sqrt(m_knob1_wetdry_23);
		t_sample rsub_1188 = (((int)1) - m_knob1_wetdry_23);
		t_sample sqrt_1187 = sqrt(rsub_1188);
		samples_to_seconds = (1 / samplerate);
		t_sample mul_554 = (m_knob5_rotate_20 * ((t_sample)3.1415926535898));
		t_sample div_510 = (m_knob6_fluctuate_25 * ((t_sample)0.00033333333333333));
		t_sample history_507_next_541 = fixdenorm(((int)1));
		t_sample history_610_next_620 = fixdenorm(((int)1));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_325 = __m_sah_26(m_history_19, m_sw_24, ((int)0));
			t_sample gen_327 = sah_325;
			t_sample rsub_323 = (((int)1) - sah_325);
			t_sample history_324_next_326 = fixdenorm(rsub_323);
			t_sample out3 = gen_327;
			t_sample add_330 = (gen_327 + ((int)1));
			t_sample choice_27 = int(add_330);
			t_sample gate_328 = (((choice_27 >= 1) && (choice_27 < 2)) ? in1 : 0);
			t_sample gate_329 = ((choice_27 >= 2) ? in1 : 0);
			t_sample mul_1186 = (gate_329 * sqrt_1187);
			t_sample phasor_564 = __m_phasor_28(m_knob5_rotate_20, samples_to_seconds);
			t_sample mul_563 = (phasor_564 * ((t_sample)6.2831853071796));
			t_sample cos_562 = cos(mul_563);
			t_sample gen_565 = cos_562;
			t_sample mul_560 = (cos_562 * (-1));
			t_sample gen_568 = mul_560;
			t_sample sin_561 = sin(mul_563);
			t_sample gen_566 = sin_561;
			t_sample gen_567 = sin_561;
			t_sample phasor_555 = __m_phasor_29(mul_554, samples_to_seconds);
			t_sample mul_559 = (phasor_555 * ((t_sample)6.2831853071796));
			t_sample sin_557 = sin(mul_559);
			t_sample gen_570 = sin_557;
			t_sample gen_571 = sin_557;
			t_sample cos_558 = cos(mul_559);
			t_sample gen_569 = cos_558;
			t_sample mul_556 = (cos_558 * (-1));
			t_sample gen_572 = mul_556;
			t_sample add_505 = (m_history_18 + ((int)1));
			t_sample noise_523 = noise();
			t_sample noise_516 = noise();
			t_sample noise_539 = noise();
			t_sample noise_532 = noise();
			int sign_522 = ((noise_523 > 0) ? 1 : ((noise_523 < 0) ? -1 : 0));
			int sign_515 = ((noise_516 > 0) ? 1 : ((noise_516 < 0) ? -1 : 0));
			int sign_538 = ((noise_539 > 0) ? 1 : ((noise_539 < 0) ? -1 : 0));
			int sign_531 = ((noise_532 > 0) ? 1 : ((noise_532 < 0) ? -1 : 0));
			t_sample mul_508 = (sign_522 * div_510);
			t_sample add_519 = (m_history_17 + mul_508);
			t_sample clamp_518 = ((add_519 <= ((int)0)) ? ((int)0) : ((add_519 >= ((int)1)) ? ((int)1) : add_519));
			t_sample choice_30 = int(add_505);
			t_sample selector_521 = ((choice_30 >= 2) ? clamp_518 : ((choice_30 >= 1) ? noise_523 : 0));
			t_sample mul_502 = (clamp_518 * ((int)3000));
			t_sample gen_550 = mul_502;
			t_sample rsub_524 = (((int)3000) - mul_502);
			t_sample gen_551 = rsub_524;
			t_sample mul_509 = (sign_515 * div_510);
			t_sample add_512 = (m_history_16 + mul_509);
			t_sample clamp_511 = ((add_512 <= ((int)0)) ? ((int)0) : ((add_512 >= ((int)1)) ? ((int)1) : add_512));
			t_sample mul_501 = (clamp_511 * ((int)3000));
			t_sample gen_552 = mul_501;
			t_sample rsub_517 = (((int)3000) - mul_501);
			t_sample gen_553 = rsub_517;
			t_sample choice_31 = int(add_505);
			t_sample selector_514 = ((choice_31 >= 2) ? clamp_511 : ((choice_31 >= 1) ? noise_516 : 0));
			t_sample mul_525 = (sign_538 * div_510);
			t_sample add_535 = (m_history_15 + mul_525);
			t_sample clamp_534 = ((add_535 <= ((int)0)) ? ((int)0) : ((add_535 >= ((int)1)) ? ((int)1) : add_535));
			t_sample choice_32 = int(add_505);
			t_sample selector_537 = ((choice_32 >= 2) ? clamp_534 : ((choice_32 >= 1) ? noise_539 : 0));
			t_sample mul_504 = (clamp_534 * ((int)3000));
			t_sample gen_546 = mul_504;
			t_sample rsub_540 = (((int)3000) - mul_504);
			t_sample gen_547 = rsub_540;
			t_sample mul_526 = (sign_531 * div_510);
			t_sample add_528 = (m_history_14 + mul_526);
			t_sample clamp_527 = ((add_528 <= ((int)0)) ? ((int)0) : ((add_528 >= ((int)1)) ? ((int)1) : add_528));
			t_sample choice_33 = int(add_505);
			t_sample selector_530 = ((choice_33 >= 2) ? clamp_527 : ((choice_33 >= 1) ? noise_532 : 0));
			t_sample mul_503 = (clamp_527 * ((int)3000));
			t_sample gen_548 = mul_503;
			t_sample rsub_533 = (((int)3000) - mul_503);
			t_sample gen_549 = rsub_533;
			t_sample history_520_next_542 = fixdenorm(selector_521);
			t_sample history_513_next_543 = fixdenorm(selector_514);
			t_sample history_536_next_544 = fixdenorm(selector_537);
			t_sample history_529_next_545 = fixdenorm(selector_530);
			t_sample tap_650 = m_delay_13.read_step(gen_546);
			t_sample tap_651 = m_delay_13.read_step(gen_547);
			t_sample mul_648 = (tap_651 * gen_566);
			t_sample mul_647 = (tap_650 * gen_565);
			t_sample tap_641 = m_delay_12.read_step(gen_548);
			t_sample tap_642 = m_delay_12.read_step(gen_549);
			t_sample mul_643 = (tap_642 * gen_568);
			t_sample add_645 = (mul_648 + mul_643);
			t_sample mul_499 = (add_645 * t_496);
			t_sample mix_1937 = (mul_499 + (m_knob3_damp_21 * (m_history_4 - mul_499)));
			t_sample mix_489 = mix_1937;
			t_sample mul_644 = (tap_641 * gen_567);
			t_sample add_646 = (mul_647 + mul_644);
			t_sample mul_500 = (add_646 * t_496);
			t_sample mix_1938 = (mul_500 + (m_knob3_damp_21 * (m_history_3 - mul_500)));
			t_sample mix_487 = mix_1938;
			t_sample tap_638 = m_delay_11.read_step(gen_550);
			t_sample tap_639 = m_delay_11.read_step(gen_551);
			t_sample mul_635 = (tap_638 * gen_569);
			t_sample mul_636 = (tap_639 * gen_570);
			t_sample tap_629 = m_delay_10.read_step(gen_552);
			t_sample tap_630 = m_delay_10.read_step(gen_553);
			t_sample mul_632 = (tap_629 * gen_571);
			t_sample add_634 = (mul_635 + mul_632);
			t_sample mul_498 = (add_634 * t_496);
			t_sample mix_1939 = (mul_498 + (m_knob3_damp_21 * (m_history_2 - mul_498)));
			t_sample mix_491 = mix_1939;
			t_sample mul_631 = (tap_630 * gen_572);
			t_sample add_633 = (mul_636 + mul_631);
			t_sample mul_497 = (add_633 * t_496);
			t_sample mix_1940 = (mul_497 + (m_knob3_damp_21 * (m_history_1 - mul_497)));
			t_sample mix_485 = mix_1940;
			t_sample dcblock_492 = __m_dcblock_34(mix_485);
			t_sample mul_479 = (dcblock_492 * safediv(1, sqrt(2)));
			t_sample dcblock_493 = __m_dcblock_35(mix_491);
			t_sample mul_478 = (dcblock_493 * safediv(1, sqrt(2)));
			t_sample add_472 = (mul_479 + mul_478);
			t_sample add_480 = (add_472 + ((int)0));
			t_sample sub_473 = (mul_479 - mul_478);
			t_sample add_481 = (sub_473 + ((int)0));
			t_sample dcblock_495 = __m_dcblock_36(mix_487);
			t_sample mul_476 = (dcblock_495 * safediv(1, sqrt(2)));
			t_sample dcblock_494 = __m_dcblock_37(mix_489);
			t_sample mul_477 = (dcblock_494 * safediv(1, sqrt(2)));
			t_sample sub_474 = (mul_476 - mul_477);
			t_sample add_482 = (sub_474 + ((int)0));
			t_sample mul_1189 = ((add_482 + add_480) * sqrt_1184);
			t_sample add_1185 = (mul_1186 + mul_1189);
			t_sample out1 = (add_1185 + gate_328);
			t_sample add_475 = (mul_476 + mul_477);
			t_sample add_483 = (add_475 + ((int)0));
			t_sample mul_1183 = ((add_483 + add_481) * sqrt_1184);
			t_sample add_1182 = (mul_1186 + mul_1183);
			t_sample out2 = (add_1182 + gate_328);
			t_sample add_652 = (add_480 + gate_329);
			t_sample add_627 = (add_481 + gate_329);
			t_sample add_626 = (add_482 + gate_329);
			t_sample add_625 = (add_483 + gate_329);
			t_sample noise_612 = noise();
			int not_608 = (!m_history_5);
			__m_latch_38 = ((not_608 != 0) ? noise_612 : __m_latch_38);
			t_sample latch_611 = __m_latch_38;
			t_sample mul_619 = (add_652 * latch_611);
			t_sample noise_576 = noise();
			__m_latch_39 = ((not_608 != 0) ? noise_576 : __m_latch_39);
			t_sample latch_575 = __m_latch_39;
			t_sample mul_583 = (add_625 * latch_575);
			t_sample noise_598 = noise();
			__m_latch_40 = ((not_608 != 0) ? noise_598 : __m_latch_40);
			t_sample latch_597 = __m_latch_40;
			t_sample mul_605 = (add_627 * latch_597);
			t_sample noise_587 = noise();
			__m_latch_41 = ((not_608 != 0) ? noise_587 : __m_latch_41);
			t_sample latch_586 = __m_latch_41;
			t_sample mul_594 = (add_626 * latch_586);
			t_sample noise_607 = noise();
			__m_latch_42 = ((not_608 != 0) ? noise_607 : __m_latch_42);
			t_sample latch_606 = __m_latch_42;
			t_sample mul_613 = (latch_606 * ((int)100));
			t_sample tap_617 = m_delay_9.read_step(mul_613);
			t_sample sub_618 = (tap_617 - mul_619);
			t_sample mul_614 = (sub_618 * latch_611);
			t_sample add_615 = (mul_614 + add_652);
			t_sample noise_574 = noise();
			__m_latch_43 = ((not_608 != 0) ? noise_574 : __m_latch_43);
			t_sample latch_573 = __m_latch_43;
			t_sample mul_577 = (latch_573 * ((int)100));
			t_sample tap_581 = m_delay_8.read_step(mul_577);
			t_sample sub_582 = (tap_581 - mul_583);
			t_sample mul_578 = (sub_582 * latch_575);
			t_sample add_579 = (mul_578 + add_625);
			t_sample noise_596 = noise();
			__m_latch_44 = ((not_608 != 0) ? noise_596 : __m_latch_44);
			t_sample latch_595 = __m_latch_44;
			t_sample mul_599 = (latch_595 * ((int)100));
			t_sample tap_603 = m_delay_7.read_step(mul_599);
			t_sample sub_604 = (tap_603 - mul_605);
			t_sample mul_600 = (sub_604 * latch_597);
			t_sample add_601 = (mul_600 + add_627);
			t_sample noise_585 = noise();
			__m_latch_45 = ((not_608 != 0) ? noise_585 : __m_latch_45);
			t_sample latch_584 = __m_latch_45;
			t_sample mul_588 = (latch_584 * ((int)100));
			t_sample tap_592 = m_delay_6.read_step(mul_588);
			t_sample sub_593 = (tap_592 - mul_594);
			t_sample mul_589 = (sub_593 * latch_586);
			t_sample add_590 = (mul_589 + add_626);
			t_sample history_488_next_1900 = fixdenorm(mix_489);
			t_sample history_486_next_1901 = fixdenorm(mix_487);
			t_sample history_490_next_1902 = fixdenorm(mix_491);
			t_sample history_484_next_1903 = fixdenorm(mix_485);
			m_history_19 = history_324_next_326;
			m_history_18 = history_507_next_541;
			m_history_14 = history_529_next_545;
			m_history_15 = history_536_next_544;
			m_history_16 = history_513_next_543;
			m_history_17 = history_520_next_542;
			m_delay_13.write(sub_618);
			m_delay_12.write(sub_604);
			m_delay_11.write(sub_593);
			m_delay_10.write(sub_582);
			m_delay_9.write(add_615);
			m_history_5 = history_610_next_620;
			m_delay_6.write(add_590);
			m_delay_7.write(add_601);
			m_delay_8.write(add_579);
			m_history_4 = history_488_next_1900;
			m_history_3 = history_486_next_1901;
			m_history_2 = history_490_next_1902;
			m_history_1 = history_484_next_1903;
			m_delay_6.step();
			m_delay_7.step();
			m_delay_8.step();
			m_delay_9.step();
			m_delay_10.step();
			m_delay_11.step();
			m_delay_12.step();
			m_delay_13.step();
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
	inline void set_knob5_rotate(t_param _value) {
		m_knob5_rotate_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_decay(t_param _value) {
		m_knob4_decay_22 = (_value < 0 ? 0 : (_value > 200 ? 200 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_fluctuate(t_param _value) {
		m_knob6_fluctuate_25 = (_value < 0 ? 0 : (_value > 0.5 ? 0.5 : _value));
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
		case 0: self->set_knob1_wetdry(value); break;
		case 1: self->set_knob3_damp(value); break;
		case 2: self->set_knob4_decay(value); break;
		case 3: self->set_knob5_rotate(value); break;
		case 4: self->set_knob6_fluctuate(value); break;
		case 5: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_wetdry_23; break;
		case 1: *value = self->m_knob3_damp_21; break;
		case 2: *value = self->m_knob4_decay_22; break;
		case 3: *value = self->m_knob5_rotate_20; break;
		case 4: *value = self->m_knob6_fluctuate_25; break;
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
	// initialize parameter 0 ("m_knob1_wetdry_23")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_damp_21")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_decay_22")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_decay";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_decay_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 200;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_rotate_20")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_rotate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_rotate_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_fluctuate_25")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_fluctuate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_fluctuate_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_24")
	pi = self->__commonstate.params + 5;
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Reverb3::
