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
	t_sample m_knob4_fb_2;
	t_sample m_knob3_damp_1;
	t_sample samplerate;
	t_sample m_sw_4;
	t_sample m_history_13;
	t_sample m_knob1_wetdry_5;
	t_sample m_knob6_spread_6;
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
		m_knob3_damp_1 = ((t_sample)0.5);
		m_knob4_fb_2 = ((t_sample)0.9);
		m_knob5_fb_3 = ((t_sample)0.5);
		m_sw_4 = ((int)0);
		m_knob1_wetdry_5 = ((int)0);
		m_knob6_spread_6 = ((int)0);
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
		t_sample sqrt_3567 = sqrt(m_knob1_wetdry_5);
		t_sample rsub_3571 = (((int)1) - m_knob1_wetdry_5);
		t_sample sqrt_3570 = sqrt(rsub_3571);
		t_sample mul_3566 = (m_knob5_fb_3 * ((t_sample)0.9));
		t_sample mul_3621 = (m_knob5_fb_3 * ((t_sample)0.9));
		t_sample add_3561 = (((int)456) + m_knob6_spread_6);
		t_sample add_3607 = (((int)450) + m_knob6_spread_6);
		t_sample add_3563 = (((int)676) + m_knob6_spread_6);
		t_sample add_3609 = (((int)682) + m_knob6_spread_6);
		t_sample add_3565 = (((int)888) + m_knob6_spread_6);
		t_sample add_3619 = (((int)882) + m_knob6_spread_6);
		t_sample add_3559 = (((int)1106) + m_knob6_spread_6);
		t_sample add_3605 = (((int)1112) + m_knob6_spread_6);
		t_sample add_3612 = (((int)3114) + m_knob6_spread_6);
		t_sample rsub_3574 = (((int)1) - m_knob3_damp_1);
		t_sample add_3611 = (((int)3234) + m_knob6_spread_6);
		t_sample rsub_3640 = (((int)1) - m_knob3_damp_1);
		t_sample add_3613 = (((int)2982) + m_knob6_spread_6);
		t_sample rsub_3652 = (((int)1) - m_knob3_damp_1);
		t_sample add_3614 = (((int)2844) + m_knob6_spread_6);
		t_sample rsub_3665 = (((int)1) - m_knob3_damp_1);
		t_sample add_3615 = (((int)2712) + m_knob6_spread_6);
		t_sample rsub_3677 = (((int)1) - m_knob3_damp_1);
		t_sample add_3616 = (((int)2554) + m_knob6_spread_6);
		t_sample rsub_3689 = (((int)1) - m_knob3_damp_1);
		t_sample add_3617 = (((int)2376) + m_knob6_spread_6);
		t_sample rsub_3701 = (((int)1) - m_knob3_damp_1);
		t_sample add_3618 = (((int)2232) + m_knob6_spread_6);
		t_sample rsub_3713 = (((int)1) - m_knob3_damp_1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_3626 = __m_sah_32(m_history_7, m_sw_4, ((int)0));
			t_sample gen_3628 = sah_3626;
			t_sample rsub_3624 = (((int)1) - sah_3626);
			t_sample history_3625_next_3627 = fixdenorm(rsub_3624);
			t_sample out3 = gen_3628;
			t_sample add_3631 = (gen_3628 + ((int)1));
			t_sample choice_33 = int(add_3631);
			t_sample gate_3629 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_3630 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_3569 = (gate_3630 * sqrt_3570);
			t_sample mul_3623 = (gate_3630 * ((t_sample)0.015));
			t_sample tap_3581 = m_delay_8.read_linear(add_3612);
			t_sample gen_3603 = tap_3581;
			t_sample mul_3579 = (tap_3581 * m_knob3_damp_1);
			t_sample mul_3577 = (m_history_9 * rsub_3574);
			t_sample add_3578 = (mul_3579 + mul_3577);
			t_sample mul_3575 = (add_3578 * m_knob4_fb_2);
			t_sample add_3582 = (mul_3623 + mul_3575);
			t_sample history_3576_next_3583 = fixdenorm(add_3578);
			t_sample tap_3635 = m_delay_10.read_linear(add_3611);
			t_sample gen_3622 = tap_3635;
			t_sample mul_3634 = (tap_3635 * m_knob3_damp_1);
			t_sample mul_3639 = (m_history_11 * rsub_3640);
			t_sample add_3638 = (mul_3634 + mul_3639);
			t_sample mul_3641 = (add_3638 * m_knob4_fb_2);
			t_sample add_3637 = (mul_3623 + mul_3641);
			t_sample history_3576_next_3636 = fixdenorm(add_3638);
			t_sample tap_3648 = m_delay_12.read_linear(add_3613);
			t_sample gen_3602 = tap_3648;
			t_sample mul_3647 = (tap_3648 * m_knob3_damp_1);
			t_sample mul_3651 = (m_history_13 * rsub_3652);
			t_sample add_3650 = (mul_3647 + mul_3651);
			t_sample mul_3653 = (add_3650 * m_knob4_fb_2);
			t_sample add_3645 = (mul_3623 + mul_3653);
			t_sample history_3576_next_3649 = fixdenorm(add_3650);
			t_sample tap_3662 = m_delay_14.read_linear(add_3614);
			t_sample gen_3601 = tap_3662;
			t_sample mul_3661 = (tap_3662 * m_knob3_damp_1);
			t_sample mul_3657 = (m_history_15 * rsub_3665);
			t_sample add_3663 = (mul_3661 + mul_3657);
			t_sample mul_3660 = (add_3663 * m_knob4_fb_2);
			t_sample add_3664 = (mul_3623 + mul_3660);
			t_sample history_3576_next_3659 = fixdenorm(add_3663);
			t_sample tap_3674 = m_delay_16.read_linear(add_3615);
			t_sample gen_3600 = tap_3674;
			t_sample mul_3673 = (tap_3674 * m_knob3_damp_1);
			t_sample mul_3669 = (m_history_17 * rsub_3677);
			t_sample add_3676 = (mul_3673 + mul_3669);
			t_sample mul_3672 = (add_3676 * m_knob4_fb_2);
			t_sample add_3675 = (mul_3623 + mul_3672);
			t_sample history_3576_next_3671 = fixdenorm(add_3676);
			t_sample tap_3686 = m_delay_18.read_linear(add_3616);
			t_sample gen_3599 = tap_3686;
			t_sample mul_3685 = (tap_3686 * m_knob3_damp_1);
			t_sample mul_3681 = (m_history_19 * rsub_3689);
			t_sample add_3688 = (mul_3685 + mul_3681);
			t_sample mul_3684 = (add_3688 * m_knob4_fb_2);
			t_sample add_3687 = (mul_3623 + mul_3684);
			t_sample history_3576_next_3683 = fixdenorm(add_3688);
			t_sample tap_3698 = m_delay_20.read_linear(add_3617);
			t_sample gen_3598 = tap_3698;
			t_sample mul_3697 = (tap_3698 * m_knob3_damp_1);
			t_sample mul_3693 = (m_history_21 * rsub_3701);
			t_sample add_3700 = (mul_3697 + mul_3693);
			t_sample mul_3696 = (add_3700 * m_knob4_fb_2);
			t_sample add_3699 = (mul_3623 + mul_3696);
			t_sample history_3576_next_3695 = fixdenorm(add_3700);
			t_sample tap_3707 = m_delay_22.read_linear(add_3618);
			t_sample gen_3597 = tap_3707;
			t_sample mul_3711 = (tap_3707 * m_knob3_damp_1);
			t_sample mul_3708 = (m_history_23 * rsub_3713);
			t_sample add_3710 = (mul_3711 + mul_3708);
			t_sample mul_3706 = (add_3710 * m_knob4_fb_2);
			t_sample add_3712 = (mul_3623 + mul_3706);
			t_sample history_3576_next_3705 = fixdenorm(add_3710);
			t_sample pass_3620 = (((((((gen_3597 + gen_3598) + gen_3599) + gen_3600) + gen_3601) + gen_3602) + gen_3622) + gen_3603);
			t_sample tap_3557 = m_delay_24.read_linear(add_3559);
			t_sample sub_3553 = (pass_3620 - tap_3557);
			t_sample mul_3555 = (tap_3557 * mul_3566);
			t_sample add_3554 = (pass_3620 + mul_3555);
			t_sample tap_3720 = m_delay_25.read_linear(add_3565);
			t_sample sub_3716 = (sub_3553 - tap_3720);
			t_sample mul_3718 = (tap_3720 * mul_3566);
			t_sample add_3717 = (sub_3553 + mul_3718);
			t_sample tap_3726 = m_delay_26.read_linear(add_3563);
			t_sample sub_3722 = (sub_3716 - tap_3726);
			t_sample mul_3724 = (tap_3726 * mul_3566);
			t_sample add_3723 = (sub_3716 + mul_3724);
			t_sample tap_3732 = m_delay_27.read_linear(add_3561);
			t_sample sub_3728 = (sub_3722 - tap_3732);
			t_sample mul_3730 = (tap_3732 * mul_3566);
			t_sample add_3729 = (sub_3722 + mul_3730);
			t_sample mul_3548 = (sub_3728 * sqrt_3567);
			t_sample add_3547 = (mul_3569 + mul_3548);
			t_sample out2 = (add_3547 + gate_3629);
			t_sample tap_3738 = m_delay_28.read_linear(add_3605);
			t_sample sub_3734 = (pass_3620 - tap_3738);
			t_sample mul_3736 = (tap_3738 * mul_3621);
			t_sample add_3735 = (pass_3620 + mul_3736);
			t_sample tap_3744 = m_delay_29.read_linear(add_3619);
			t_sample sub_3741 = (sub_3734 - tap_3744);
			t_sample mul_3742 = (tap_3744 * mul_3621);
			t_sample add_3740 = (sub_3734 + mul_3742);
			t_sample tap_3750 = m_delay_30.read_linear(add_3609);
			t_sample sub_3747 = (sub_3741 - tap_3750);
			t_sample mul_3748 = (tap_3750 * mul_3621);
			t_sample add_3746 = (sub_3741 + mul_3748);
			t_sample tap_3756 = m_delay_31.read_linear(add_3607);
			t_sample sub_3753 = (sub_3747 - tap_3756);
			t_sample mul_3752 = (tap_3756 * mul_3621);
			t_sample add_3754 = (sub_3747 + mul_3752);
			t_sample mul_3572 = (sub_3753 * sqrt_3567);
			t_sample add_3568 = (mul_3569 + mul_3572);
			t_sample out1 = (gate_3629 + add_3568);
			m_history_7 = history_3625_next_3627;
			m_delay_31.write(add_3754);
			m_delay_30.write(add_3746);
			m_delay_29.write(add_3740);
			m_delay_28.write(add_3735);
			m_delay_27.write(add_3729);
			m_delay_26.write(add_3723);
			m_delay_25.write(add_3717);
			m_delay_24.write(add_3554);
			m_history_23 = history_3576_next_3705;
			m_delay_22.write(add_3712);
			m_history_21 = history_3576_next_3695;
			m_delay_20.write(add_3699);
			m_history_19 = history_3576_next_3683;
			m_delay_18.write(add_3687);
			m_history_17 = history_3576_next_3671;
			m_delay_16.write(add_3675);
			m_history_15 = history_3576_next_3659;
			m_delay_14.write(add_3664);
			m_history_13 = history_3576_next_3649;
			m_delay_12.write(add_3645);
			m_history_11 = history_3576_next_3636;
			m_delay_10.write(add_3637);
			m_history_9 = history_3576_next_3583;
			m_delay_8.write(add_3582);
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
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_6 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
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
		case 1: *value = self->m_knob3_damp_1; break;
		case 2: *value = self->m_knob4_fb_2; break;
		case 3: *value = self->m_knob5_fb_3; break;
		case 4: *value = self->m_knob6_spread_6; break;
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
	// initialize parameter 1 ("m_knob3_damp_1")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_fb_2")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_2;
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
	// initialize parameter 4 ("m_knob6_spread_6")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_6;
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
