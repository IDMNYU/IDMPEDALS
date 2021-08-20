#include "Wah2.h"

namespace Wah2 {

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
	Phasor __m_phasor_31;
	Sah __m_sah_26;
	SineCycle __m_cycle_32;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_sw_21;
	t_sample m_s_3;
	t_sample m_knob3_manual_22;
	t_sample m_sw_20;
	t_sample m_history_19;
	t_sample m_knob4_depth_23;
	t_sample m_knob5_rate_24;
	t_sample m_knob6_res_25;
	t_sample samples_to_seconds;
	t_sample m_history_18;
	t_sample __m_slide_28;
	t_sample samplerate;
	t_sample m_s_2;
	t_sample m_history_17;
	t_sample m_history_15;
	t_sample m_s_7;
	t_sample m_s_8;
	t_sample m_s_6;
	t_sample m_s_4;
	t_sample m_s_5;
	t_sample m_history_16;
	t_sample m_slim_9;
	t_sample m_rc_11;
	t_sample m_s_1;
	t_sample m_previn_10;
	t_sample m_history_13;
	t_sample m_fc_12;
	t_sample m_history_14;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_s_1 = ((int)0);
		m_s_2 = ((int)0);
		m_s_3 = ((int)0);
		m_s_4 = ((int)0);
		m_s_5 = ((int)0);
		m_s_6 = ((int)0);
		m_s_7 = ((int)0);
		m_s_8 = ((int)0);
		m_slim_9 = ((int)0);
		m_previn_10 = ((int)0);
		m_rc_11 = ((int)0);
		m_fc_12 = ((int)1);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_sw_20 = ((int)0);
		m_sw_21 = ((int)0);
		m_knob3_manual_22 = 0;
		m_knob4_depth_23 = 1;
		m_knob5_rate_24 = 0.1;
		m_knob6_res_25 = 0.5;
		__m_sah_26.reset(0);
		__m_slide_28 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_31.reset(0);
		__m_cycle_32.reset(samplerate, 0);
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
		t_sample add_4627 = (m_sw_20 + ((int)1));
		t_sample mstosamps_4625 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_4624 = (((int)100) * (samplerate * 0.001));
		t_sample iup_29 = (1 / maximum(1, abs(mstosamps_4625)));
		t_sample idown_30 = (1 / maximum(1, abs(mstosamps_4624)));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_33 = int(add_4627);
		t_sample minb_34 = ((((t_sample)1e-05) < m_knob6_res_25) ? m_knob6_res_25 : ((t_sample)1e-05));
		t_sample maxb_35 = safediv(((t_sample)12.5), samplerate);
		t_sample minb_36 = ((((t_sample)0.0001) < maxb_35) ? maxb_35 : ((t_sample)0.0001));
		t_sample expr_4530 = sqrt(((minb_36 < ((int)1)) ? minb_36 : ((int)1)));
		t_sample expr_4529 = (((int)-1) * log(expr_4530));
		int min_39 = (-1);
		int min_42 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_4635 = __m_sah_26(m_history_19, m_sw_21, ((int)0));
			t_sample gen_4637 = sah_4635;
			t_sample rsub_4633 = (((int)1) - sah_4635);
			t_sample history_4634_next_4636 = fixdenorm(rsub_4633);
			t_sample out3 = gen_4637;
			t_sample add_4638 = (gen_4637 + ((int)1));
			t_sample choice_27 = int(add_4638);
			t_sample gate_4631 = (((choice_27 >= 1) && (choice_27 < 2)) ? in1 : 0);
			t_sample gate_4632 = ((choice_27 >= 2) ? in1 : 0);
			t_sample mix_4687 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_knob3_manual_22 - m_history_18)));
			t_sample mix_4502 = mix_4687;
			t_sample mix_4688 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_4502 - m_history_17)));
			t_sample mix_4500 = mix_4688;
			t_sample mix_4689 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_4500 - m_history_16)));
			t_sample mix_4498 = mix_4689;
			t_sample gen_4508 = mix_4498;
			t_sample history_4503_next_4505 = fixdenorm(mix_4502);
			t_sample history_4501_next_4506 = fixdenorm(mix_4500);
			t_sample history_4499_next_4507 = fixdenorm(mix_4498);
			t_sample abs_4630 = fabs(gate_4632);
			__m_slide_28 = fixdenorm((__m_slide_28 + (((abs_4630 > __m_slide_28) ? iup_29 : idown_30) * (abs_4630 - __m_slide_28))));
			t_sample slide_4629 = __m_slide_28;
			t_sample mul_4626 = (slide_4629 * ((int)30));
			t_sample sqrt_4495 = sqrt(mul_4626);
			t_sample mix_4690 = (m_history_15 + (((t_sample)0.0019634941468452) * (m_knob5_rate_24 - m_history_15)));
			t_sample mix_4648 = mix_4690;
			t_sample mix_4691 = (m_history_14 + (((t_sample)0.0019634941468452) * (mix_4648 - m_history_14)));
			t_sample mix_4654 = mix_4691;
			t_sample mix_4692 = (m_history_13 + (((t_sample)0.0019634941468452) * (mix_4654 - m_history_13)));
			t_sample mix_4652 = mix_4692;
			t_sample gen_4621 = mix_4652;
			t_sample history_4503_next_4651 = fixdenorm(mix_4648);
			t_sample history_4501_next_4649 = fixdenorm(mix_4654);
			t_sample history_4499_next_4650 = fixdenorm(mix_4652);
			t_sample rsub_4641 = (((int)1) - gen_4621);
			t_sample sqrt_4640 = sqrt(rsub_4641);
			t_sample rsub_4639 = (((int)1) - sqrt_4640);
			t_sample mul_4645 = (rsub_4639 * ((int)10));
			t_sample phasor_4644 = __m_phasor_31(mul_4645, samples_to_seconds);
			__m_cycle_32.phase(phasor_4644);
			t_sample cycle_4619 = __m_cycle_32(__sinedata);
			t_sample cycleindex_4620 = __m_cycle_32.phase();
			t_sample sub_4696 = (cycle_4619 - (-1));
			t_sample scale_4693 = ((safepow((sub_4696 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_4497 = scale_4693;
			t_sample selector_4628 = ((choice_33 >= 2) ? sqrt_4495 : ((choice_33 >= 1) ? scale_4497 : 0));
			t_sample mul_4618 = (selector_4628 * m_knob4_depth_23);
			t_sample add_4510 = (mul_4618 + gen_4508);
			t_sample clamp_4509 = ((add_4510 <= ((int)0)) ? ((int)0) : ((add_4510 >= ((int)1)) ? ((int)1) : add_4510));
			t_sample sub_4700 = (clamp_4509 - ((int)0));
			t_sample scale_4697 = ((safepow((sub_4700 * ((t_sample)1)), ((int)1)) * ((int)120)) + ((int)15));
			t_sample scale_4511 = scale_4697;
			t_sample expr_4605 = (((((t_sample)1.05) * ((minb_34 < ((int)1)) ? minb_34 : ((int)1))) - m_rc_11) * ((t_sample)0.25));
			t_sample add_4574 = (m_rc_11 + expr_4605);
			t_sample fixdenorm_4535 = fixdenorm(m_previn_10);
			t_sample noise_4534 = noise();
			t_sample expr_4590 = (gate_4632 + (((t_sample)1e-11) * noise_4534));
			t_sample gen_4533 = m_fc_12;
			t_sample mul_4517 = (scale_4511 * ((t_sample)0.90193));
			t_sample add_4514 = (mul_4517 + ((t_sample)7.29));
			t_sample div_4513 = (add_4514 * ((t_sample)0.0078740157480315));
			t_sample clamp_4519 = ((div_4513 <= ((int)0)) ? ((int)0) : ((div_4513 >= ((t_sample)0.99)) ? ((t_sample)0.99) : div_4513));
			t_sample mul_4518 = (clamp_4519 * expr_4529);
			t_sample expr_4531 = (((t_sample)0.99999636) + ((((t_sample)0.031261316) + ((((t_sample)0.00048274797) + (((t_sample)5.949053e-06) * mul_4518)) * mul_4518)) * mul_4518));
			t_sample mul_4526 = (expr_4531 * expr_4531);
			t_sample mul_4525 = (mul_4526 * mul_4526);
			t_sample mul_4524 = (mul_4525 * mul_4525);
			t_sample mul_4523 = (mul_4524 * mul_4524);
			t_sample mul_4522 = (mul_4523 * mul_4523);
			t_sample mul_4516 = (mul_4522 * expr_4530);
			t_sample sub_4515 = (mul_4516 - m_fc_12);
			t_sample div_4512 = (sub_4515 * ((t_sample)0.5));
			t_sample add_4528 = (m_fc_12 + div_4512);
			t_sample fc_next_4532 = fixdenorm(add_4528);
			t_sample expr_4604 = (gen_4533 * gen_4533);
			t_sample expr_4603 = (expr_4604 * (((int)1) - m_rc_11));
			t_sample expr_4602 = (expr_4604 + (expr_4603 * expr_4603));
			t_sample expr_4601 = ((((t_sample)1.25) + ((((t_sample)-0.74375) + (((t_sample)0.3) * expr_4602)) * expr_4602)) * expr_4602);
			t_sample expr_4600 = (m_rc_11 * (((t_sample)1.4) + ((((t_sample)0.108) + ((((t_sample)-0.164) - (((t_sample)0.069) * expr_4601)) * expr_4601)) * expr_4601)));
			t_sample expr_4599 = (((t_sample)0.18) + (((t_sample)0.25) * (expr_4600 * expr_4600)));
			t_sample expr_4598 = ((fixdenorm_4535 * expr_4599) - (expr_4600 * m_s_2));
			t_sample maxb_37 = (((((t_sample)0.062) * expr_4598) * expr_4598) + (((t_sample)0.993) * m_slim_9));
			t_sample minb_38 = ((((int)-1) < maxb_37) ? maxb_37 : ((int)-1));
			t_sample expr_4597 = ((minb_38 < ((int)1)) ? minb_38 : ((int)1));
			t_sample expr_4596 = (expr_4598 * ((((int)1) - expr_4597) + ((((t_sample)0.5) * expr_4597) * expr_4597)));
			t_sample rsub_4575 = (((int)1) - expr_4601);
			t_sample expr_4595 = ((expr_4596 * expr_4601) + (rsub_4575 * m_s_8));
			t_sample mul_4550 = (expr_4595 * ((t_sample)0.3));
			t_sample mul_4568 = (m_s_8 * ((t_sample)0.3));
			t_sample add_4566 = (expr_4595 + mul_4568);
			t_sample expr_4594 = ((add_4566 * expr_4601) + (rsub_4575 * m_s_7));
			t_sample mul_4560 = (m_s_5 * ((t_sample)0.3));
			t_sample mul_4557 = (m_s_4 * ((t_sample)0.3));
			t_sample mul_4565 = (m_s_7 * ((t_sample)0.3));
			t_sample add_4563 = (expr_4594 + mul_4565);
			t_sample clamp_4562 = ((add_4563 <= min_39) ? min_39 : ((add_4563 >= ((int)1)) ? ((int)1) : add_4563));
			t_sample expr_4593 = (clamp_4562 * (((int)1) - ((((t_sample)0.3333333) * clamp_4562) * clamp_4562)));
			t_sample expr_4592 = ((expr_4593 * expr_4601) + (rsub_4575 * m_s_5));
			t_sample add_4558 = (expr_4592 + mul_4560);
			t_sample expr_4591 = ((add_4558 * expr_4601) + (rsub_4575 * m_s_4));
			t_sample add_4555 = (expr_4591 + mul_4557);
			t_sample expr_4589 = ((expr_4590 * expr_4599) - (expr_4600 * add_4555));
			t_sample maxb_40 = (((((t_sample)0.062) * expr_4589) * expr_4589) + (((t_sample)0.993) * expr_4597));
			t_sample minb_41 = ((((int)-1) < maxb_40) ? maxb_40 : ((int)-1));
			t_sample expr_4588 = ((minb_41 < ((int)1)) ? minb_41 : ((int)1));
			t_sample expr_4587 = (expr_4589 * ((((int)1) - expr_4588) + ((((t_sample)0.5) * expr_4588) * expr_4588)));
			t_sample expr_4586 = ((expr_4587 * expr_4601) + (rsub_4575 * expr_4595));
			t_sample add_4548 = (expr_4586 + mul_4550);
			t_sample expr_4585 = ((add_4548 * expr_4601) + (rsub_4575 * expr_4594));
			t_sample mul_4539 = (expr_4591 * ((t_sample)0.3));
			t_sample mul_4542 = (expr_4592 * ((t_sample)0.3));
			t_sample mul_4547 = (expr_4594 * ((t_sample)0.3));
			t_sample add_4545 = (expr_4585 + mul_4547);
			t_sample clamp_4544 = ((add_4545 <= min_42) ? min_42 : ((add_4545 >= ((int)1)) ? ((int)1) : add_4545));
			t_sample expr_4584 = (clamp_4544 * (((int)1) - ((((t_sample)0.3333333) * clamp_4544) * clamp_4544)));
			t_sample expr_4583 = ((expr_4584 * expr_4601) + (rsub_4575 * expr_4592));
			t_sample add_4540 = (expr_4583 + mul_4542);
			t_sample expr_4582 = ((add_4540 * expr_4601) + (rsub_4575 * expr_4591));
			t_sample add_4537 = (expr_4582 + mul_4539);
			t_sample expr_4581 = (((((t_sample)0.19) * (add_4537 + m_s_6)) + (((t_sample)0.57) * (add_4555 + m_s_3))) - (((t_sample)0.52) * m_s_1));
			t_sample gen_4617 = expr_4581;
			t_sample rc_next_4606 = fixdenorm(add_4574);
			t_sample previn_next_4607 = fixdenorm(expr_4590);
			t_sample slim_next_4608 = fixdenorm(expr_4588);
			t_sample s1_next_4609 = fixdenorm(expr_4586);
			t_sample s2_next_4610 = fixdenorm(expr_4585);
			t_sample s8_next_4611 = fixdenorm(add_4555);
			t_sample s3_next_4612 = fixdenorm(expr_4583);
			t_sample s4_next_4613 = fixdenorm(expr_4582);
			t_sample s7_next_4614 = fixdenorm(add_4537);
			t_sample s5_next_4615 = fixdenorm(add_4537);
			t_sample s6_next_4616 = fixdenorm(expr_4581);
			t_sample add_4642 = (gen_4617 + gate_4631);
			t_sample out2 = add_4642;
			t_sample add_4643 = (gen_4617 + gate_4631);
			t_sample out1 = add_4643;
			m_history_19 = history_4634_next_4636;
			m_history_18 = history_4503_next_4505;
			m_history_16 = history_4499_next_4507;
			m_history_17 = history_4501_next_4506;
			m_history_15 = history_4503_next_4651;
			m_history_13 = history_4499_next_4650;
			m_history_14 = history_4501_next_4649;
			m_fc_12 = fc_next_4532;
			m_s_1 = s6_next_4616;
			m_s_2 = s5_next_4615;
			m_s_3 = s7_next_4614;
			m_s_4 = s4_next_4613;
			m_s_5 = s3_next_4612;
			m_s_6 = s8_next_4611;
			m_s_7 = s2_next_4610;
			m_s_8 = s1_next_4609;
			m_slim_9 = slim_next_4608;
			m_previn_10 = previn_next_4607;
			m_rc_11 = rc_next_4606;
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
	inline void set_sw5(t_param _value) {
		m_sw_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_manual(t_param _value) {
		m_knob3_manual_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_depth(t_param _value) {
		m_knob4_depth_23 = (_value < -1 ? -1 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_rate(t_param _value) {
		m_knob5_rate_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_res(t_param _value) {
		m_knob6_res_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_knob3_manual(value); break;
		case 1: self->set_knob4_depth(value); break;
		case 2: self->set_knob5_rate(value); break;
		case 3: self->set_knob6_res(value); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_manual_22; break;
		case 1: *value = self->m_knob4_depth_23; break;
		case 2: *value = self->m_knob5_rate_24; break;
		case 3: *value = self->m_knob6_res_25; break;
		case 4: *value = self->m_sw_21; break;
		case 5: *value = self->m_sw_20; break;
		
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
	// initialize parameter 0 ("m_knob3_manual_22")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_manual";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_manual_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_depth_23")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_depth_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -1;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_rate_24")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_rate_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_res_25")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_res_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_21")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
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
	// initialize parameter 5 ("m_sw_20")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_20;
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


} // Wah2::
