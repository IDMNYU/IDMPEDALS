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
	t_sample m_knob4_depth_21;
	t_sample m_s_3;
	t_sample m_sw_22;
	t_sample m_sw_20;
	t_sample m_history_19;
	t_sample m_knob5_rate_23;
	t_sample m_knob6_res_24;
	t_sample m_knob3_manual_25;
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
	t_sample m_slim_5;
	t_sample m_history_16;
	t_sample m_s_9;
	t_sample m_previn_11;
	t_sample m_s_1;
	t_sample m_rc_10;
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
		m_slim_5 = ((int)0);
		m_s_6 = ((int)0);
		m_s_7 = ((int)0);
		m_s_8 = ((int)0);
		m_s_9 = ((int)0);
		m_rc_10 = ((int)0);
		m_previn_11 = ((int)0);
		m_fc_12 = ((int)1);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_sw_20 = ((int)0);
		m_knob4_depth_21 = 1;
		m_sw_22 = ((int)0);
		m_knob5_rate_23 = 0.1;
		m_knob6_res_24 = 0.5;
		m_knob3_manual_25 = 0;
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
		t_sample add_5776 = (m_sw_20 + ((int)1));
		t_sample mstosamps_5774 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_5773 = (((int)100) * (samplerate * 0.001));
		t_sample iup_29 = (1 / maximum(1, abs(mstosamps_5774)));
		t_sample idown_30 = (1 / maximum(1, abs(mstosamps_5773)));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_33 = int(add_5776);
		t_sample minb_34 = ((((t_sample)1e-05) < m_knob6_res_24) ? m_knob6_res_24 : ((t_sample)1e-05));
		t_sample maxb_35 = safediv(((t_sample)12.5), samplerate);
		t_sample minb_36 = ((((t_sample)0.0001) < maxb_35) ? maxb_35 : ((t_sample)0.0001));
		t_sample expr_5679 = sqrt(((minb_36 < ((int)1)) ? minb_36 : ((int)1)));
		t_sample expr_5678 = (((int)-1) * log(expr_5679));
		int min_39 = (-1);
		int min_42 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_5784 = __m_sah_26(m_history_19, m_sw_22, ((int)0));
			t_sample gen_5786 = sah_5784;
			t_sample rsub_5782 = (((int)1) - sah_5784);
			t_sample history_5783_next_5785 = fixdenorm(rsub_5782);
			t_sample out3 = gen_5786;
			t_sample add_5787 = (gen_5786 + ((int)1));
			t_sample choice_27 = int(add_5787);
			t_sample gate_5780 = (((choice_27 >= 1) && (choice_27 < 2)) ? in1 : 0);
			t_sample gate_5781 = ((choice_27 >= 2) ? in1 : 0);
			t_sample mix_5836 = (m_history_18 + (((t_sample)0.003926980723806) * (m_knob3_manual_25 - m_history_18)));
			t_sample mix_5651 = mix_5836;
			t_sample mix_5837 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_5651 - m_history_17)));
			t_sample mix_5649 = mix_5837;
			t_sample mix_5838 = (m_history_16 + (((t_sample)0.003926980723806) * (mix_5649 - m_history_16)));
			t_sample mix_5647 = mix_5838;
			t_sample gen_5657 = mix_5647;
			t_sample history_5652_next_5654 = fixdenorm(mix_5651);
			t_sample history_5650_next_5655 = fixdenorm(mix_5649);
			t_sample history_5648_next_5656 = fixdenorm(mix_5647);
			t_sample abs_5779 = fabs(gate_5781);
			__m_slide_28 = fixdenorm((__m_slide_28 + (((abs_5779 > __m_slide_28) ? iup_29 : idown_30) * (abs_5779 - __m_slide_28))));
			t_sample slide_5778 = __m_slide_28;
			t_sample mul_5775 = (slide_5778 * ((int)30));
			t_sample sqrt_5644 = sqrt(mul_5775);
			t_sample mix_5839 = (m_history_15 + (((t_sample)0.003926980723806) * (m_knob5_rate_23 - m_history_15)));
			t_sample mix_5799 = mix_5839;
			t_sample mix_5840 = (m_history_14 + (((t_sample)0.003926980723806) * (mix_5799 - m_history_14)));
			t_sample mix_5797 = mix_5840;
			t_sample mix_5841 = (m_history_13 + (((t_sample)0.003926980723806) * (mix_5797 - m_history_13)));
			t_sample mix_5801 = mix_5841;
			t_sample gen_5770 = mix_5801;
			t_sample history_5652_next_5798 = fixdenorm(mix_5799);
			t_sample history_5650_next_5802 = fixdenorm(mix_5797);
			t_sample history_5648_next_5800 = fixdenorm(mix_5801);
			t_sample rsub_5790 = (((int)1) - gen_5770);
			t_sample sqrt_5789 = sqrt(rsub_5790);
			t_sample rsub_5788 = (((int)1) - sqrt_5789);
			t_sample mul_5794 = (rsub_5788 * ((int)10));
			t_sample phasor_5793 = __m_phasor_31(mul_5794, samples_to_seconds);
			__m_cycle_32.phase(phasor_5793);
			t_sample cycle_5768 = __m_cycle_32(__sinedata);
			t_sample cycleindex_5769 = __m_cycle_32.phase();
			t_sample sub_5845 = (cycle_5768 - (-1));
			t_sample scale_5842 = ((safepow((sub_5845 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_5646 = scale_5842;
			t_sample selector_5777 = ((choice_33 >= 2) ? sqrt_5644 : ((choice_33 >= 1) ? scale_5646 : 0));
			t_sample mul_5767 = (selector_5777 * m_knob4_depth_21);
			t_sample add_5659 = (mul_5767 + gen_5657);
			t_sample clamp_5658 = ((add_5659 <= ((int)0)) ? ((int)0) : ((add_5659 >= ((int)1)) ? ((int)1) : add_5659));
			t_sample sub_5849 = (clamp_5658 - ((int)0));
			t_sample scale_5846 = ((safepow((sub_5849 * ((t_sample)1)), ((int)1)) * ((int)120)) + ((int)15));
			t_sample scale_5660 = scale_5846;
			t_sample expr_5754 = (((((t_sample)1.05) * ((minb_34 < ((int)1)) ? minb_34 : ((int)1))) - m_rc_10) * ((t_sample)0.25));
			t_sample noise_5683 = noise();
			t_sample expr_5739 = (gate_5781 + (((t_sample)1e-11) * noise_5683));
			t_sample fixdenorm_5684 = fixdenorm(m_previn_11);
			t_sample add_5723 = (m_rc_10 + expr_5754);
			t_sample gen_5682 = m_fc_12;
			t_sample mul_5666 = (scale_5660 * ((t_sample)0.90193));
			t_sample add_5663 = (mul_5666 + ((t_sample)7.29));
			t_sample div_5662 = (add_5663 * ((t_sample)0.0078740157480315));
			t_sample clamp_5668 = ((div_5662 <= ((int)0)) ? ((int)0) : ((div_5662 >= ((t_sample)0.99)) ? ((t_sample)0.99) : div_5662));
			t_sample mul_5667 = (clamp_5668 * expr_5678);
			t_sample expr_5680 = (((t_sample)0.99999636) + ((((t_sample)0.031261316) + ((((t_sample)0.00048274797) + (((t_sample)5.949053e-06) * mul_5667)) * mul_5667)) * mul_5667));
			t_sample mul_5675 = (expr_5680 * expr_5680);
			t_sample mul_5674 = (mul_5675 * mul_5675);
			t_sample mul_5673 = (mul_5674 * mul_5674);
			t_sample mul_5672 = (mul_5673 * mul_5673);
			t_sample mul_5671 = (mul_5672 * mul_5672);
			t_sample mul_5665 = (mul_5671 * expr_5679);
			t_sample sub_5664 = (mul_5665 - m_fc_12);
			t_sample div_5661 = (sub_5664 * ((t_sample)0.5));
			t_sample add_5677 = (m_fc_12 + div_5661);
			t_sample fc_next_5681 = fixdenorm(add_5677);
			t_sample expr_5753 = (gen_5682 * gen_5682);
			t_sample expr_5752 = (expr_5753 * (((int)1) - m_rc_10));
			t_sample expr_5751 = (expr_5753 + (expr_5752 * expr_5752));
			t_sample expr_5750 = ((((t_sample)1.25) + ((((t_sample)-0.74375) + (((t_sample)0.3) * expr_5751)) * expr_5751)) * expr_5751);
			t_sample expr_5749 = (m_rc_10 * (((t_sample)1.4) + ((((t_sample)0.108) + ((((t_sample)-0.164) - (((t_sample)0.069) * expr_5750)) * expr_5750)) * expr_5750)));
			t_sample expr_5748 = (((t_sample)0.18) + (((t_sample)0.25) * (expr_5749 * expr_5749)));
			t_sample expr_5747 = ((fixdenorm_5684 * expr_5748) - (expr_5749 * m_s_2));
			t_sample maxb_37 = (((((t_sample)0.062) * expr_5747) * expr_5747) + (((t_sample)0.993) * m_slim_5));
			t_sample minb_38 = ((((int)-1) < maxb_37) ? maxb_37 : ((int)-1));
			t_sample expr_5746 = ((minb_38 < ((int)1)) ? minb_38 : ((int)1));
			t_sample expr_5745 = (expr_5747 * ((((int)1) - expr_5746) + ((((t_sample)0.5) * expr_5746) * expr_5746)));
			t_sample rsub_5724 = (((int)1) - expr_5750);
			t_sample expr_5744 = ((expr_5745 * expr_5750) + (rsub_5724 * m_s_8));
			t_sample mul_5699 = (expr_5744 * ((t_sample)0.3));
			t_sample mul_5717 = (m_s_8 * ((t_sample)0.3));
			t_sample add_5715 = (expr_5744 + mul_5717);
			t_sample expr_5743 = ((add_5715 * expr_5750) + (rsub_5724 * m_s_7));
			t_sample mul_5706 = (m_s_4 * ((t_sample)0.3));
			t_sample mul_5709 = (m_s_6 * ((t_sample)0.3));
			t_sample mul_5696 = (expr_5743 * ((t_sample)0.3));
			t_sample mul_5714 = (m_s_7 * ((t_sample)0.3));
			t_sample add_5712 = (expr_5743 + mul_5714);
			t_sample clamp_5711 = ((add_5712 <= min_39) ? min_39 : ((add_5712 >= ((int)1)) ? ((int)1) : add_5712));
			t_sample expr_5742 = (clamp_5711 * (((int)1) - ((((t_sample)0.3333333) * clamp_5711) * clamp_5711)));
			t_sample expr_5741 = ((expr_5742 * expr_5750) + (rsub_5724 * m_s_6));
			t_sample add_5707 = (expr_5741 + mul_5709);
			t_sample expr_5740 = ((add_5707 * expr_5750) + (rsub_5724 * m_s_4));
			t_sample add_5704 = (expr_5740 + mul_5706);
			t_sample expr_5738 = ((expr_5739 * expr_5748) - (expr_5749 * add_5704));
			t_sample maxb_40 = (((((t_sample)0.062) * expr_5738) * expr_5738) + (((t_sample)0.993) * expr_5746));
			t_sample minb_41 = ((((int)-1) < maxb_40) ? maxb_40 : ((int)-1));
			t_sample expr_5737 = ((minb_41 < ((int)1)) ? minb_41 : ((int)1));
			t_sample expr_5736 = (expr_5738 * ((((int)1) - expr_5737) + ((((t_sample)0.5) * expr_5737) * expr_5737)));
			t_sample expr_5735 = ((expr_5736 * expr_5750) + (rsub_5724 * expr_5744));
			t_sample add_5697 = (expr_5735 + mul_5699);
			t_sample expr_5734 = ((add_5697 * expr_5750) + (rsub_5724 * expr_5743));
			t_sample add_5694 = (expr_5734 + mul_5696);
			t_sample clamp_5693 = ((add_5694 <= min_42) ? min_42 : ((add_5694 >= ((int)1)) ? ((int)1) : add_5694));
			t_sample expr_5733 = (clamp_5693 * (((int)1) - ((((t_sample)0.3333333) * clamp_5693) * clamp_5693)));
			t_sample expr_5732 = ((expr_5733 * expr_5750) + (rsub_5724 * expr_5741));
			t_sample mul_5688 = (expr_5740 * ((t_sample)0.3));
			t_sample mul_5691 = (expr_5741 * ((t_sample)0.3));
			t_sample add_5689 = (expr_5732 + mul_5691);
			t_sample expr_5731 = ((add_5689 * expr_5750) + (rsub_5724 * expr_5740));
			t_sample add_5686 = (expr_5731 + mul_5688);
			t_sample expr_5730 = (((((t_sample)0.19) * (add_5686 + m_s_9)) + (((t_sample)0.57) * (add_5704 + m_s_3))) - (((t_sample)0.52) * m_s_1));
			t_sample gen_5766 = expr_5730;
			t_sample previn_next_5755 = fixdenorm(expr_5739);
			t_sample rc_next_5756 = fixdenorm(add_5723);
			t_sample s8_next_5757 = fixdenorm(add_5704);
			t_sample s1_next_5758 = fixdenorm(expr_5735);
			t_sample s2_next_5759 = fixdenorm(expr_5734);
			t_sample s3_next_5760 = fixdenorm(expr_5732);
			t_sample slim_next_5761 = fixdenorm(expr_5737);
			t_sample s4_next_5762 = fixdenorm(expr_5731);
			t_sample s7_next_5763 = fixdenorm(add_5686);
			t_sample s5_next_5764 = fixdenorm(add_5686);
			t_sample s6_next_5765 = fixdenorm(expr_5730);
			t_sample add_5792 = (gen_5766 + gate_5780);
			t_sample out1 = add_5792;
			t_sample add_5791 = (gen_5766 + gate_5780);
			t_sample out2 = add_5791;
			m_history_19 = history_5783_next_5785;
			m_history_18 = history_5652_next_5654;
			m_history_16 = history_5648_next_5656;
			m_history_17 = history_5650_next_5655;
			m_history_15 = history_5652_next_5798;
			m_history_13 = history_5648_next_5800;
			m_history_14 = history_5650_next_5802;
			m_fc_12 = fc_next_5681;
			m_s_1 = s6_next_5765;
			m_s_2 = s5_next_5764;
			m_s_3 = s7_next_5763;
			m_s_4 = s4_next_5762;
			m_slim_5 = slim_next_5761;
			m_s_6 = s3_next_5760;
			m_s_7 = s2_next_5759;
			m_s_8 = s1_next_5758;
			m_s_9 = s8_next_5757;
			m_rc_10 = rc_next_5756;
			m_previn_11 = previn_next_5755;
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
	inline void set_knob4_depth(t_param _value) {
		m_knob4_depth_21 = (_value < -1 ? -1 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_rate(t_param _value) {
		m_knob5_rate_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_res(t_param _value) {
		m_knob6_res_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_manual(t_param _value) {
		m_knob3_manual_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_manual_25; break;
		case 1: *value = self->m_knob4_depth_21; break;
		case 2: *value = self->m_knob5_rate_23; break;
		case 3: *value = self->m_knob6_res_24; break;
		case 4: *value = self->m_sw_22; break;
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
	// initialize parameter 0 ("m_knob3_manual_25")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_manual";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_manual_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_depth_21")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_depth_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -1;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_rate_23")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_rate_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_res_24")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_res_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_22")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_22;
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
