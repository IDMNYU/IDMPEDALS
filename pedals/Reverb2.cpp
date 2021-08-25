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
	t_sample m_knob1_wetdry_2;
	t_sample m_knob6_spread_1;
	t_sample samplerate;
	t_sample m_knob4_fb_4;
	t_sample m_history_13;
	t_sample m_sw_5;
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
		m_knob6_spread_1 = ((int)0);
		m_knob1_wetdry_2 = ((int)0);
		m_knob5_fb_3 = ((t_sample)0.5);
		m_knob4_fb_4 = ((t_sample)0.9);
		m_sw_5 = ((int)0);
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
		t_sample sqrt_489 = sqrt(m_knob1_wetdry_2);
		t_sample rsub_493 = (((int)1) - m_knob1_wetdry_2);
		t_sample sqrt_492 = sqrt(rsub_493);
		t_sample mul_488 = (m_knob5_fb_3 * ((t_sample)0.9));
		t_sample mul_543 = (m_knob5_fb_3 * ((t_sample)0.9));
		t_sample add_483 = (((int)456) + m_knob6_spread_1);
		t_sample add_529 = (((int)450) + m_knob6_spread_1);
		t_sample add_485 = (((int)676) + m_knob6_spread_1);
		t_sample add_531 = (((int)682) + m_knob6_spread_1);
		t_sample add_487 = (((int)888) + m_knob6_spread_1);
		t_sample add_541 = (((int)882) + m_knob6_spread_1);
		t_sample add_481 = (((int)1106) + m_knob6_spread_1);
		t_sample add_527 = (((int)1112) + m_knob6_spread_1);
		t_sample add_534 = (((int)3114) + m_knob6_spread_1);
		t_sample rsub_496 = (((int)1) - m_knob3_damp_6);
		t_sample add_533 = (((int)3234) + m_knob6_spread_1);
		t_sample rsub_561 = (((int)1) - m_knob3_damp_6);
		t_sample add_535 = (((int)2982) + m_knob6_spread_1);
		t_sample rsub_568 = (((int)1) - m_knob3_damp_6);
		t_sample add_536 = (((int)2844) + m_knob6_spread_1);
		t_sample rsub_583 = (((int)1) - m_knob3_damp_6);
		t_sample add_537 = (((int)2712) + m_knob6_spread_1);
		t_sample rsub_595 = (((int)1) - m_knob3_damp_6);
		t_sample add_538 = (((int)2554) + m_knob6_spread_1);
		t_sample rsub_606 = (((int)1) - m_knob3_damp_6);
		t_sample add_539 = (((int)2376) + m_knob6_spread_1);
		t_sample rsub_618 = (((int)1) - m_knob3_damp_6);
		t_sample add_540 = (((int)2232) + m_knob6_spread_1);
		t_sample rsub_634 = (((int)1) - m_knob3_damp_6);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_548 = __m_sah_32(m_history_7, m_sw_5, ((int)0));
			t_sample gen_550 = sah_548;
			t_sample rsub_546 = (((int)1) - sah_548);
			t_sample history_547_next_549 = fixdenorm(rsub_546);
			t_sample out3 = gen_550;
			t_sample add_553 = (gen_550 + ((int)1));
			t_sample choice_33 = int(add_553);
			t_sample gate_551 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_552 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_491 = (gate_552 * sqrt_492);
			t_sample mul_545 = (gate_552 * ((t_sample)0.015));
			t_sample tap_503 = m_delay_8.read_linear(add_534);
			t_sample gen_525 = tap_503;
			t_sample mul_501 = (tap_503 * m_knob3_damp_6);
			t_sample mul_499 = (m_history_9 * rsub_496);
			t_sample add_500 = (mul_501 + mul_499);
			t_sample mul_497 = (add_500 * m_knob4_fb_4);
			t_sample add_504 = (mul_545 + mul_497);
			t_sample history_498_next_505 = fixdenorm(add_500);
			t_sample tap_562 = m_delay_10.read_linear(add_533);
			t_sample gen_544 = tap_562;
			t_sample mul_560 = (tap_562 * m_knob3_damp_6);
			t_sample mul_554 = (m_history_11 * rsub_561);
			t_sample add_555 = (mul_560 + mul_554);
			t_sample mul_557 = (add_555 * m_knob4_fb_4);
			t_sample add_556 = (mul_545 + mul_557);
			t_sample history_498_next_558 = fixdenorm(add_555);
			t_sample tap_575 = m_delay_12.read_linear(add_535);
			t_sample gen_524 = tap_575;
			t_sample mul_574 = (tap_575 * m_knob3_damp_6);
			t_sample mul_567 = (m_history_13 * rsub_568);
			t_sample add_566 = (mul_574 + mul_567);
			t_sample mul_571 = (add_566 * m_knob4_fb_4);
			t_sample add_569 = (mul_545 + mul_571);
			t_sample history_498_next_572 = fixdenorm(add_566);
			t_sample tap_581 = m_delay_14.read_linear(add_536);
			t_sample gen_523 = tap_581;
			t_sample mul_580 = (tap_581 * m_knob3_damp_6);
			t_sample mul_582 = (m_history_15 * rsub_583);
			t_sample add_586 = (mul_580 + mul_582);
			t_sample mul_585 = (add_586 * m_knob4_fb_4);
			t_sample add_584 = (mul_545 + mul_585);
			t_sample history_498_next_578 = fixdenorm(add_586);
			t_sample tap_593 = m_delay_16.read_linear(add_537);
			t_sample gen_522 = tap_593;
			t_sample mul_592 = (tap_593 * m_knob3_damp_6);
			t_sample mul_594 = (m_history_17 * rsub_595);
			t_sample add_598 = (mul_592 + mul_594);
			t_sample mul_597 = (add_598 * m_knob4_fb_4);
			t_sample add_596 = (mul_545 + mul_597);
			t_sample history_498_next_590 = fixdenorm(add_598);
			t_sample tap_604 = m_delay_18.read_linear(add_538);
			t_sample gen_521 = tap_604;
			t_sample mul_610 = (tap_604 * m_knob3_damp_6);
			t_sample mul_605 = (m_history_19 * rsub_606);
			t_sample add_609 = (mul_610 + mul_605);
			t_sample mul_608 = (add_609 * m_knob4_fb_4);
			t_sample add_607 = (mul_545 + mul_608);
			t_sample history_498_next_602 = fixdenorm(add_609);
			t_sample tap_616 = m_delay_20.read_linear(add_539);
			t_sample gen_520 = tap_616;
			t_sample mul_622 = (tap_616 * m_knob3_damp_6);
			t_sample mul_617 = (m_history_21 * rsub_618);
			t_sample add_619 = (mul_622 + mul_617);
			t_sample mul_621 = (add_619 * m_knob4_fb_4);
			t_sample add_620 = (mul_545 + mul_621);
			t_sample history_498_next_614 = fixdenorm(add_619);
			t_sample tap_628 = m_delay_22.read_linear(add_540);
			t_sample gen_519 = tap_628;
			t_sample mul_631 = (tap_628 * m_knob3_damp_6);
			t_sample mul_629 = (m_history_23 * rsub_634);
			t_sample add_627 = (mul_631 + mul_629);
			t_sample mul_626 = (add_627 * m_knob4_fb_4);
			t_sample add_632 = (mul_545 + mul_626);
			t_sample history_498_next_633 = fixdenorm(add_627);
			t_sample pass_542 = (((((((gen_519 + gen_520) + gen_521) + gen_522) + gen_523) + gen_524) + gen_544) + gen_525);
			t_sample tap_479 = m_delay_24.read_linear(add_481);
			t_sample sub_475 = (pass_542 - tap_479);
			t_sample mul_477 = (tap_479 * mul_488);
			t_sample add_476 = (pass_542 + mul_477);
			t_sample tap_642 = m_delay_25.read_linear(add_487);
			t_sample sub_638 = (sub_475 - tap_642);
			t_sample mul_640 = (tap_642 * mul_488);
			t_sample add_639 = (sub_475 + mul_640);
			t_sample tap_648 = m_delay_26.read_linear(add_485);
			t_sample sub_644 = (sub_638 - tap_648);
			t_sample mul_646 = (tap_648 * mul_488);
			t_sample add_645 = (sub_638 + mul_646);
			t_sample tap_654 = m_delay_27.read_linear(add_483);
			t_sample sub_650 = (sub_644 - tap_654);
			t_sample mul_652 = (tap_654 * mul_488);
			t_sample add_651 = (sub_644 + mul_652);
			t_sample mul_470 = (sub_650 * sqrt_489);
			t_sample add_469 = (mul_491 + mul_470);
			t_sample out2 = (add_469 + gate_551);
			t_sample tap_660 = m_delay_28.read_linear(add_527);
			t_sample sub_656 = (pass_542 - tap_660);
			t_sample mul_658 = (tap_660 * mul_543);
			t_sample add_657 = (pass_542 + mul_658);
			t_sample tap_666 = m_delay_29.read_linear(add_541);
			t_sample sub_662 = (sub_656 - tap_666);
			t_sample mul_664 = (tap_666 * mul_543);
			t_sample add_663 = (sub_656 + mul_664);
			t_sample tap_672 = m_delay_30.read_linear(add_531);
			t_sample sub_668 = (sub_662 - tap_672);
			t_sample mul_670 = (tap_672 * mul_543);
			t_sample add_669 = (sub_662 + mul_670);
			t_sample tap_678 = m_delay_31.read_linear(add_529);
			t_sample sub_674 = (sub_668 - tap_678);
			t_sample mul_676 = (tap_678 * mul_543);
			t_sample add_675 = (sub_668 + mul_676);
			t_sample mul_494 = (sub_674 * sqrt_489);
			t_sample add_490 = (mul_491 + mul_494);
			t_sample out1 = (gate_551 + add_490);
			m_history_7 = history_547_next_549;
			m_delay_31.write(add_675);
			m_delay_30.write(add_669);
			m_delay_29.write(add_663);
			m_delay_28.write(add_657);
			m_delay_27.write(add_651);
			m_delay_26.write(add_645);
			m_delay_25.write(add_639);
			m_delay_24.write(add_476);
			m_history_23 = history_498_next_633;
			m_delay_22.write(add_632);
			m_history_21 = history_498_next_614;
			m_delay_20.write(add_620);
			m_history_19 = history_498_next_602;
			m_delay_18.write(add_607);
			m_history_17 = history_498_next_590;
			m_delay_16.write(add_596);
			m_history_15 = history_498_next_578;
			m_delay_14.write(add_584);
			m_history_13 = history_498_next_572;
			m_delay_12.write(add_569);
			m_history_11 = history_498_next_558;
			m_delay_10.write(add_556);
			m_history_9 = history_498_next_505;
			m_delay_8.write(add_504);
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
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_1 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb2(t_param _value) {
		m_knob5_fb_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob1_wetdry_2; break;
		case 1: *value = self->m_knob3_damp_6; break;
		case 2: *value = self->m_knob4_fb_4; break;
		case 3: *value = self->m_knob5_fb_3; break;
		case 4: *value = self->m_knob6_spread_1; break;
		case 5: *value = self->m_sw_5; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_2")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_2;
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
	// initialize parameter 2 ("m_knob4_fb_4")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_4;
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
	// initialize parameter 4 ("m_knob6_spread_1")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_5")
	pi = self->__commonstate.params + 5;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_5;
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
