#include "Reverb2.h"

namespace Reverb2 {

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
	Delay m_delay_14;
	Delay m_delay_18;
	Delay m_delay_8;
	Delay m_delay_20;
	Delay m_delay_10;
	Delay m_delay_12;
	Delay m_delay_16;
	Delay m_delay_31;
	Delay m_delay_22;
	Delay m_delay_25;
	Delay m_delay_29;
	Delay m_delay_30;
	Delay m_delay_24;
	Delay m_delay_28;
	Delay m_delay_26;
	Delay m_delay_27;
	Sah __m_sah_32;
	int __exception;
	int vectorsize;
	t_sample m_knob5_fb_3;
	t_sample m_history_11;
	t_sample m_knob6_spread_2;
	t_sample m_knob4_fb_1;
	t_sample samplerate;
	t_sample m_sw_4;
	t_sample m_history_13;
	t_sample m_knob1_wetdry_5;
	t_sample m_knob3_damp_6;
	t_sample m_history_9;
	t_sample m_history_17;
	t_sample m_history_23;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample m_history_7;
	t_sample m_history_15;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_knob4_fb_1 = ((t_sample)0.9);
		m_knob6_spread_2 = ((int)0);
		m_knob5_fb_3 = ((t_sample)0.5);
		m_sw_4 = ((int)0);
		m_knob1_wetdry_5 = ((int)0);
		m_knob3_damp_6 = ((t_sample)0.5);
		m_history_7 = ((int)0);
		m_delay_8.reset("m_delay_8", ((int)4000));
		m_history_9 = ((int)0);
		m_delay_10.reset("m_delay_10", ((int)4000));
		m_history_11 = ((int)0);
		m_delay_12.reset("m_delay_12", ((int)4000));
		m_history_13 = ((int)0);
		m_delay_14.reset("m_delay_14", ((int)4000));
		m_history_15 = ((int)0);
		m_delay_16.reset("m_delay_16", ((int)4000));
		m_history_17 = ((int)0);
		m_delay_18.reset("m_delay_18", ((int)4000));
		m_history_19 = ((int)0);
		m_delay_20.reset("m_delay_20", ((int)4000));
		m_history_21 = ((int)0);
		m_delay_22.reset("m_delay_22", ((int)4000));
		m_history_23 = ((int)0);
		m_delay_24.reset("m_delay_24", ((int)4000));
		m_delay_25.reset("m_delay_25", ((int)4000));
		m_delay_26.reset("m_delay_26", ((int)4000));
		m_delay_27.reset("m_delay_27", ((int)4000));
		m_delay_28.reset("m_delay_28", ((int)4000));
		m_delay_29.reset("m_delay_29", ((int)4000));
		m_delay_30.reset("m_delay_30", ((int)4000));
		m_delay_31.reset("m_delay_31", ((int)4000));
		__m_sah_32.reset(0);
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
		t_sample sqrt_433 = sqrt(m_knob1_wetdry_5);
		t_sample rsub_437 = (((int)1) - m_knob1_wetdry_5);
		t_sample sqrt_436 = sqrt(rsub_437);
		t_sample mul_432 = (m_knob5_fb_3 * ((t_sample)0.5));
		t_sample mul_487 = (m_knob5_fb_3 * ((t_sample)0.5));
		t_sample add_427 = (((int)456) + m_knob6_spread_2);
		t_sample add_473 = (((int)450) + m_knob6_spread_2);
		t_sample add_429 = (((int)676) + m_knob6_spread_2);
		t_sample add_475 = (((int)682) + m_knob6_spread_2);
		t_sample add_431 = (((int)888) + m_knob6_spread_2);
		t_sample add_485 = (((int)882) + m_knob6_spread_2);
		t_sample add_425 = (((int)1106) + m_knob6_spread_2);
		t_sample add_471 = (((int)1112) + m_knob6_spread_2);
		t_sample add_478 = (((int)3114) + m_knob6_spread_2);
		t_sample rsub_440 = (((int)1) - m_knob3_damp_6);
		t_sample add_477 = (((int)3234) + m_knob6_spread_2);
		t_sample rsub_503 = (((int)1) - m_knob3_damp_6);
		t_sample add_479 = (((int)2982) + m_knob6_spread_2);
		t_sample rsub_517 = (((int)1) - m_knob3_damp_6);
		t_sample add_480 = (((int)2844) + m_knob6_spread_2);
		t_sample rsub_530 = (((int)1) - m_knob3_damp_6);
		t_sample add_481 = (((int)2712) + m_knob6_spread_2);
		t_sample rsub_542 = (((int)1) - m_knob3_damp_6);
		t_sample add_482 = (((int)2554) + m_knob6_spread_2);
		t_sample rsub_554 = (((int)1) - m_knob3_damp_6);
		t_sample add_483 = (((int)2376) + m_knob6_spread_2);
		t_sample rsub_566 = (((int)1) - m_knob3_damp_6);
		t_sample add_484 = (((int)2232) + m_knob6_spread_2);
		t_sample rsub_579 = (((int)1) - m_knob3_damp_6);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_492 = __m_sah_32(m_history_7, m_sw_4, ((int)0));
			t_sample gen_494 = sah_492;
			t_sample rsub_490 = (((int)1) - sah_492);
			t_sample history_491_next_493 = fixdenorm(rsub_490);
			t_sample out3 = gen_494;
			t_sample add_497 = (gen_494 + ((int)1));
			t_sample choice_33 = int(add_497);
			t_sample gate_495 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_496 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_435 = (gate_496 * sqrt_436);
			t_sample mul_489 = (gate_496 * ((t_sample)0.015));
			t_sample tap_447 = m_delay_8.read_linear(add_478);
			t_sample gen_469 = tap_447;
			t_sample mul_445 = (tap_447 * m_knob3_damp_6);
			t_sample mul_443 = (m_history_9 * rsub_440);
			t_sample add_444 = (mul_445 + mul_443);
			t_sample mul_441 = (add_444 * m_knob4_fb_1);
			t_sample add_448 = (mul_489 + mul_441);
			t_sample history_442_next_449 = fixdenorm(add_444);
			t_sample tap_499 = m_delay_10.read_linear(add_477);
			t_sample gen_488 = tap_499;
			t_sample mul_506 = (tap_499 * m_knob3_damp_6);
			t_sample mul_507 = (m_history_11 * rsub_503);
			t_sample add_498 = (mul_506 + mul_507);
			t_sample mul_504 = (add_498 * m_knob4_fb_1);
			t_sample add_505 = (mul_489 + mul_504);
			t_sample history_442_next_502 = fixdenorm(add_498);
			t_sample tap_512 = m_delay_12.read_linear(add_479);
			t_sample gen_468 = tap_512;
			t_sample mul_511 = (tap_512 * m_knob3_damp_6);
			t_sample mul_519 = (m_history_13 * rsub_517);
			t_sample add_510 = (mul_511 + mul_519);
			t_sample mul_516 = (add_510 * m_knob4_fb_1);
			t_sample add_518 = (mul_489 + mul_516);
			t_sample history_442_next_515 = fixdenorm(add_510);
			t_sample tap_523 = m_delay_14.read_linear(add_480);
			t_sample gen_467 = tap_523;
			t_sample mul_522 = (tap_523 * m_knob3_damp_6);
			t_sample mul_531 = (m_history_15 * rsub_530);
			t_sample add_525 = (mul_522 + mul_531);
			t_sample mul_529 = (add_525 * m_knob4_fb_1);
			t_sample add_526 = (mul_489 + mul_529);
			t_sample history_442_next_528 = fixdenorm(add_525);
			t_sample tap_537 = m_delay_16.read_linear(add_481);
			t_sample gen_466 = tap_537;
			t_sample mul_534 = (tap_537 * m_knob3_damp_6);
			t_sample mul_543 = (m_history_17 * rsub_542);
			t_sample add_536 = (mul_534 + mul_543);
			t_sample mul_541 = (add_536 * m_knob4_fb_1);
			t_sample add_539 = (mul_489 + mul_541);
			t_sample history_442_next_540 = fixdenorm(add_536);
			t_sample tap_549 = m_delay_18.read_linear(add_482);
			t_sample gen_465 = tap_549;
			t_sample mul_546 = (tap_549 * m_knob3_damp_6);
			t_sample mul_555 = (m_history_19 * rsub_554);
			t_sample add_548 = (mul_546 + mul_555);
			t_sample mul_551 = (add_548 * m_knob4_fb_1);
			t_sample add_552 = (mul_489 + mul_551);
			t_sample history_442_next_553 = fixdenorm(add_548);
			t_sample tap_563 = m_delay_20.read_linear(add_483);
			t_sample gen_464 = tap_563;
			t_sample mul_558 = (tap_563 * m_knob3_damp_6);
			t_sample mul_567 = (m_history_21 * rsub_566);
			t_sample add_562 = (mul_558 + mul_567);
			t_sample mul_560 = (add_562 * m_knob4_fb_1);
			t_sample add_565 = (mul_489 + mul_560);
			t_sample history_442_next_561 = fixdenorm(add_562);
			t_sample tap_570 = m_delay_22.read_linear(add_484);
			t_sample gen_463 = tap_570;
			t_sample mul_575 = (tap_570 * m_knob3_damp_6);
			t_sample mul_573 = (m_history_23 * rsub_579);
			t_sample add_577 = (mul_575 + mul_573);
			t_sample mul_572 = (add_577 * m_knob4_fb_1);
			t_sample add_578 = (mul_489 + mul_572);
			t_sample history_442_next_576 = fixdenorm(add_577);
			t_sample pass_486 = (((((((gen_463 + gen_464) + gen_465) + gen_466) + gen_467) + gen_468) + gen_488) + gen_469);
			t_sample tap_423 = m_delay_24.read_linear(add_425);
			t_sample sub_419 = (pass_486 - tap_423);
			t_sample mul_421 = (tap_423 * mul_432);
			t_sample add_420 = (pass_486 + mul_421);
			t_sample tap_586 = m_delay_25.read_linear(add_431);
			t_sample sub_585 = (sub_419 - tap_586);
			t_sample mul_582 = (tap_586 * mul_432);
			t_sample add_584 = (sub_419 + mul_582);
			t_sample tap_592 = m_delay_26.read_linear(add_429);
			t_sample sub_591 = (sub_585 - tap_592);
			t_sample mul_588 = (tap_592 * mul_432);
			t_sample add_590 = (sub_585 + mul_588);
			t_sample tap_598 = m_delay_27.read_linear(add_427);
			t_sample sub_597 = (sub_591 - tap_598);
			t_sample mul_594 = (tap_598 * mul_432);
			t_sample add_596 = (sub_591 + mul_594);
			t_sample mul_414 = (sub_597 * sqrt_433);
			t_sample add_413 = (mul_435 + mul_414);
			t_sample out2 = (add_413 + gate_495);
			t_sample tap_604 = m_delay_28.read_linear(add_471);
			t_sample sub_603 = (pass_486 - tap_604);
			t_sample mul_600 = (tap_604 * mul_487);
			t_sample add_602 = (pass_486 + mul_600);
			t_sample tap_610 = m_delay_29.read_linear(add_485);
			t_sample sub_609 = (sub_603 - tap_610);
			t_sample mul_606 = (tap_610 * mul_487);
			t_sample add_608 = (sub_603 + mul_606);
			t_sample tap_616 = m_delay_30.read_linear(add_475);
			t_sample sub_615 = (sub_609 - tap_616);
			t_sample mul_612 = (tap_616 * mul_487);
			t_sample add_614 = (sub_609 + mul_612);
			t_sample tap_622 = m_delay_31.read_linear(add_473);
			t_sample sub_621 = (sub_615 - tap_622);
			t_sample mul_618 = (tap_622 * mul_487);
			t_sample add_620 = (sub_615 + mul_618);
			t_sample mul_438 = (sub_621 * sqrt_433);
			t_sample add_434 = (mul_435 + mul_438);
			t_sample out1 = (gate_495 + add_434);
			m_history_7 = history_491_next_493;
			m_delay_31.write(add_620);
			m_delay_30.write(add_614);
			m_delay_29.write(add_608);
			m_delay_28.write(add_602);
			m_delay_27.write(add_596);
			m_delay_26.write(add_590);
			m_delay_25.write(add_584);
			m_delay_24.write(add_420);
			m_history_23 = history_442_next_576;
			m_delay_22.write(add_578);
			m_history_21 = history_442_next_561;
			m_delay_20.write(add_565);
			m_history_19 = history_442_next_553;
			m_delay_18.write(add_552);
			m_history_17 = history_442_next_540;
			m_delay_16.write(add_539);
			m_history_15 = history_442_next_528;
			m_delay_14.write(add_526);
			m_history_13 = history_442_next_515;
			m_delay_12.write(add_518);
			m_history_11 = history_442_next_502;
			m_delay_10.write(add_505);
			m_history_9 = history_442_next_449;
			m_delay_8.write(add_448);
			m_delay_8.step();
			m_delay_10.step();
			m_delay_12.step();
			m_delay_14.step();
			m_delay_16.step();
			m_delay_18.step();
			m_delay_20.step();
			m_delay_22.step();
			m_delay_24.step();
			m_delay_25.step();
			m_delay_26.step();
			m_delay_27.step();
			m_delay_28.step();
			m_delay_29.step();
			m_delay_30.step();
			m_delay_31.step();
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
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_2 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
	};
	inline void set_knob5_fb2(t_param _value) {
		m_knob5_fb_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 2: self->set_knob4_fb1(value); break;
		case 3: self->set_knob5_fb2(value); break;
		case 4: self->set_knob6_spread(value); break;
		case 5: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_wetdry_5; break;
		case 1: *value = self->m_knob3_damp_6; break;
		case 2: *value = self->m_knob4_fb_1; break;
		case 3: *value = self->m_knob5_fb_3; break;
		case 4: *value = self->m_knob6_spread_2; break;
		case 5: *value = self->m_sw_4; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_5")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_damp_6")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_fb_1")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_fb_3")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_spread_2")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_4")
	pi = self->__commonstate.params + 5;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_4;
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


} // Reverb2::
