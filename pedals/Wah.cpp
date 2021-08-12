#include "Wah.h"

namespace Wah {

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
	t_sample m_knob5_rate_22;
	t_sample m_sw_20;
	t_sample m_history_19;
	t_sample m_knob4_depth_23;
	t_sample m_knob3_manual_24;
	t_sample m_knob6_res_25;
	t_sample samples_to_seconds;
	t_sample m_history_18;
	t_sample __m_slide_28;
	t_sample samplerate;
	t_sample m_s_2;
	t_sample m_history_17;
	t_sample m_history_15;
	t_sample m_slim_7;
	t_sample m_s_8;
	t_sample m_s_6;
	t_sample m_s_4;
	t_sample m_s_5;
	t_sample m_history_16;
	t_sample m_s_9;
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
		m_slim_7 = ((int)0);
		m_s_8 = ((int)0);
		m_s_9 = ((int)0);
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
		m_knob5_rate_22 = 0.1;
		m_knob4_depth_23 = 1;
		m_knob3_manual_24 = 0;
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
		t_sample add_2864 = (m_sw_21 + ((int)1));
		t_sample mstosamps_2862 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_2861 = (((int)100) * (samplerate * 0.001));
		t_sample iup_29 = (1 / maximum(1, abs(mstosamps_2862)));
		t_sample idown_30 = (1 / maximum(1, abs(mstosamps_2861)));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_33 = int(add_2864);
		t_sample minb_34 = ((((t_sample)1e-05) < m_knob6_res_25) ? m_knob6_res_25 : ((t_sample)1e-05));
		t_sample maxb_35 = safediv(((t_sample)12.5), samplerate);
		t_sample minb_36 = ((((t_sample)0.0001) < maxb_35) ? maxb_35 : ((t_sample)0.0001));
		t_sample expr_2767 = sqrt(((minb_36 < ((int)1)) ? minb_36 : ((int)1)));
		t_sample expr_2766 = (((int)-1) * log(expr_2767));
		int min_39 = (-1);
		int min_42 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_2872 = __m_sah_26(m_history_19, m_sw_20, ((int)0));
			t_sample gen_2874 = sah_2872;
			t_sample rsub_2870 = (((int)1) - sah_2872);
			t_sample history_2871_next_2873 = fixdenorm(rsub_2870);
			t_sample out3 = gen_2874;
			t_sample add_2875 = (gen_2874 + ((int)1));
			t_sample choice_27 = int(add_2875);
			t_sample gate_2868 = (((choice_27 >= 1) && (choice_27 < 2)) ? in1 : 0);
			t_sample gate_2869 = ((choice_27 >= 2) ? in1 : 0);
			t_sample mix_2924 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_knob3_manual_24 - m_history_18)));
			t_sample mix_2739 = mix_2924;
			t_sample mix_2925 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_2739 - m_history_17)));
			t_sample mix_2737 = mix_2925;
			t_sample mix_2926 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_2737 - m_history_16)));
			t_sample mix_2735 = mix_2926;
			t_sample gen_2745 = mix_2735;
			t_sample history_2740_next_2742 = fixdenorm(mix_2739);
			t_sample history_2738_next_2743 = fixdenorm(mix_2737);
			t_sample history_2736_next_2744 = fixdenorm(mix_2735);
			t_sample abs_2867 = fabs(gate_2869);
			__m_slide_28 = fixdenorm((__m_slide_28 + (((abs_2867 > __m_slide_28) ? iup_29 : idown_30) * (abs_2867 - __m_slide_28))));
			t_sample slide_2866 = __m_slide_28;
			t_sample mul_2863 = (slide_2866 * ((int)10));
			t_sample mix_2927 = (m_history_15 + (((t_sample)0.0019634941468452) * (m_knob5_rate_22 - m_history_15)));
			t_sample mix_2883 = mix_2927;
			t_sample mix_2928 = (m_history_14 + (((t_sample)0.0019634941468452) * (mix_2883 - m_history_14)));
			t_sample mix_2884 = mix_2928;
			t_sample mix_2929 = (m_history_13 + (((t_sample)0.0019634941468452) * (mix_2884 - m_history_13)));
			t_sample mix_2885 = mix_2929;
			t_sample gen_2858 = mix_2885;
			t_sample history_2740_next_2889 = fixdenorm(mix_2883);
			t_sample history_2738_next_2887 = fixdenorm(mix_2884);
			t_sample history_2736_next_2891 = fixdenorm(mix_2885);
			t_sample rsub_2878 = (((int)1) - gen_2858);
			t_sample sqrt_2877 = sqrt(rsub_2878);
			t_sample rsub_2876 = (((int)1) - sqrt_2877);
			t_sample mul_2882 = (rsub_2876 * ((int)10));
			t_sample phasor_2881 = __m_phasor_31(mul_2882, samples_to_seconds);
			__m_cycle_32.phase(phasor_2881);
			t_sample cycle_2856 = __m_cycle_32(__sinedata);
			t_sample cycleindex_2857 = __m_cycle_32.phase();
			t_sample sub_2933 = (cycle_2856 - (-1));
			t_sample scale_2930 = ((safepow((sub_2933 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_2734 = scale_2930;
			t_sample selector_2865 = ((choice_33 >= 2) ? mul_2863 : ((choice_33 >= 1) ? scale_2734 : 0));
			t_sample mul_2855 = (selector_2865 * m_knob4_depth_23);
			t_sample add_2747 = (mul_2855 + gen_2745);
			t_sample clamp_2746 = ((add_2747 <= ((int)0)) ? ((int)0) : ((add_2747 >= ((int)1)) ? ((int)1) : add_2747));
			t_sample sub_2937 = (clamp_2746 - ((int)0));
			t_sample scale_2934 = ((safepow((sub_2937 * ((t_sample)1)), ((int)1)) * ((int)120)) + ((int)15));
			t_sample scale_2748 = scale_2934;
			t_sample expr_2842 = (((((t_sample)1.05) * ((minb_34 < ((int)1)) ? minb_34 : ((int)1))) - m_rc_11) * ((t_sample)0.25));
			t_sample fixdenorm_2772 = fixdenorm(m_previn_10);
			t_sample add_2811 = (m_rc_11 + expr_2842);
			t_sample noise_2771 = noise();
			t_sample expr_2827 = (gate_2869 + (((t_sample)1e-11) * noise_2771));
			t_sample mul_2805 = (m_s_9 * ((t_sample)0.3));
			t_sample mul_2797 = (m_s_5 * ((t_sample)0.3));
			t_sample gen_2770 = m_fc_12;
			t_sample mul_2754 = (scale_2748 * ((t_sample)0.90193));
			t_sample add_2751 = (mul_2754 + ((t_sample)7.29));
			t_sample div_2750 = (add_2751 * ((t_sample)0.0078740157480315));
			t_sample clamp_2756 = ((div_2750 <= ((int)0)) ? ((int)0) : ((div_2750 >= ((t_sample)0.99)) ? ((t_sample)0.99) : div_2750));
			t_sample mul_2755 = (clamp_2756 * expr_2766);
			t_sample expr_2768 = (((t_sample)0.99999636) + ((((t_sample)0.031261316) + ((((t_sample)0.00048274797) + (((t_sample)5.949053e-06) * mul_2755)) * mul_2755)) * mul_2755));
			t_sample mul_2763 = (expr_2768 * expr_2768);
			t_sample mul_2762 = (mul_2763 * mul_2763);
			t_sample mul_2761 = (mul_2762 * mul_2762);
			t_sample mul_2760 = (mul_2761 * mul_2761);
			t_sample mul_2759 = (mul_2760 * mul_2760);
			t_sample mul_2753 = (mul_2759 * expr_2767);
			t_sample sub_2752 = (mul_2753 - m_fc_12);
			t_sample div_2749 = (sub_2752 * ((t_sample)0.5));
			t_sample add_2765 = (m_fc_12 + div_2749);
			t_sample fc_next_2769 = fixdenorm(add_2765);
			t_sample expr_2841 = (gen_2770 * gen_2770);
			t_sample expr_2840 = (expr_2841 * (((int)1) - m_rc_11));
			t_sample expr_2839 = (expr_2841 + (expr_2840 * expr_2840));
			t_sample expr_2838 = ((((t_sample)1.25) + ((((t_sample)-0.74375) + (((t_sample)0.3) * expr_2839)) * expr_2839)) * expr_2839);
			t_sample expr_2837 = (m_rc_11 * (((t_sample)1.4) + ((((t_sample)0.108) + ((((t_sample)-0.164) - (((t_sample)0.069) * expr_2838)) * expr_2838)) * expr_2838)));
			t_sample expr_2836 = (((t_sample)0.18) + (((t_sample)0.25) * (expr_2837 * expr_2837)));
			t_sample expr_2835 = ((fixdenorm_2772 * expr_2836) - (expr_2837 * m_s_2));
			t_sample maxb_37 = (((((t_sample)0.062) * expr_2835) * expr_2835) + (((t_sample)0.993) * m_slim_7));
			t_sample minb_38 = ((((int)-1) < maxb_37) ? maxb_37 : ((int)-1));
			t_sample expr_2834 = ((minb_38 < ((int)1)) ? minb_38 : ((int)1));
			t_sample expr_2833 = (expr_2835 * ((((int)1) - expr_2834) + ((((t_sample)0.5) * expr_2834) * expr_2834)));
			t_sample rsub_2812 = (((int)1) - expr_2838);
			t_sample expr_2832 = ((expr_2833 * expr_2838) + (rsub_2812 * m_s_9));
			t_sample add_2803 = (expr_2832 + mul_2805);
			t_sample expr_2831 = ((add_2803 * expr_2838) + (rsub_2812 * m_s_8));
			t_sample mul_2787 = (expr_2832 * ((t_sample)0.3));
			t_sample mul_2794 = (m_s_4 * ((t_sample)0.3));
			t_sample mul_2802 = (m_s_8 * ((t_sample)0.3));
			t_sample add_2800 = (expr_2831 + mul_2802);
			t_sample clamp_2799 = ((add_2800 <= min_39) ? min_39 : ((add_2800 >= ((int)1)) ? ((int)1) : add_2800));
			t_sample expr_2830 = (clamp_2799 * (((int)1) - ((((t_sample)0.3333333) * clamp_2799) * clamp_2799)));
			t_sample expr_2829 = ((expr_2830 * expr_2838) + (rsub_2812 * m_s_5));
			t_sample add_2795 = (expr_2829 + mul_2797);
			t_sample expr_2828 = ((add_2795 * expr_2838) + (rsub_2812 * m_s_4));
			t_sample add_2792 = (expr_2828 + mul_2794);
			t_sample expr_2826 = ((expr_2827 * expr_2836) - (expr_2837 * add_2792));
			t_sample maxb_40 = (((((t_sample)0.062) * expr_2826) * expr_2826) + (((t_sample)0.993) * expr_2834));
			t_sample minb_41 = ((((int)-1) < maxb_40) ? maxb_40 : ((int)-1));
			t_sample expr_2825 = ((minb_41 < ((int)1)) ? minb_41 : ((int)1));
			t_sample expr_2824 = (expr_2826 * ((((int)1) - expr_2825) + ((((t_sample)0.5) * expr_2825) * expr_2825)));
			t_sample expr_2823 = ((expr_2824 * expr_2838) + (rsub_2812 * expr_2832));
			t_sample add_2785 = (expr_2823 + mul_2787);
			t_sample expr_2822 = ((add_2785 * expr_2838) + (rsub_2812 * expr_2831));
			t_sample mul_2776 = (expr_2828 * ((t_sample)0.3));
			t_sample mul_2779 = (expr_2829 * ((t_sample)0.3));
			t_sample mul_2784 = (expr_2831 * ((t_sample)0.3));
			t_sample add_2782 = (expr_2822 + mul_2784);
			t_sample clamp_2781 = ((add_2782 <= min_42) ? min_42 : ((add_2782 >= ((int)1)) ? ((int)1) : add_2782));
			t_sample expr_2821 = (clamp_2781 * (((int)1) - ((((t_sample)0.3333333) * clamp_2781) * clamp_2781)));
			t_sample expr_2820 = ((expr_2821 * expr_2838) + (rsub_2812 * expr_2829));
			t_sample add_2777 = (expr_2820 + mul_2779);
			t_sample expr_2819 = ((add_2777 * expr_2838) + (rsub_2812 * expr_2828));
			t_sample add_2774 = (expr_2819 + mul_2776);
			t_sample expr_2818 = (((((t_sample)0.19) * (add_2774 + m_s_6)) + (((t_sample)0.57) * (add_2792 + m_s_1))) - (((t_sample)0.52) * m_s_3));
			t_sample gen_2854 = expr_2818;
			t_sample rc_next_2843 = fixdenorm(add_2811);
			t_sample previn_next_2844 = fixdenorm(expr_2827);
			t_sample s1_next_2845 = fixdenorm(expr_2823);
			t_sample s2_next_2846 = fixdenorm(expr_2822);
			t_sample slim_next_2847 = fixdenorm(expr_2825);
			t_sample s8_next_2848 = fixdenorm(add_2792);
			t_sample s3_next_2849 = fixdenorm(expr_2820);
			t_sample s4_next_2850 = fixdenorm(expr_2819);
			t_sample s6_next_2851 = fixdenorm(expr_2818);
			t_sample s5_next_2852 = fixdenorm(add_2774);
			t_sample s7_next_2853 = fixdenorm(add_2774);
			t_sample add_2879 = (gen_2854 + gate_2868);
			t_sample out2 = add_2879;
			t_sample add_2880 = (gen_2854 + gate_2868);
			t_sample out1 = add_2880;
			m_history_19 = history_2871_next_2873;
			m_history_18 = history_2740_next_2742;
			m_history_16 = history_2736_next_2744;
			m_history_17 = history_2738_next_2743;
			m_history_15 = history_2740_next_2889;
			m_history_13 = history_2736_next_2891;
			m_history_14 = history_2738_next_2887;
			m_fc_12 = fc_next_2769;
			m_s_1 = s7_next_2853;
			m_s_2 = s5_next_2852;
			m_s_3 = s6_next_2851;
			m_s_4 = s4_next_2850;
			m_s_5 = s3_next_2849;
			m_s_6 = s8_next_2848;
			m_slim_7 = slim_next_2847;
			m_s_8 = s2_next_2846;
			m_s_9 = s1_next_2845;
			m_previn_10 = previn_next_2844;
			m_rc_11 = rc_next_2843;
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
		m_sw_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_rate(t_param _value) {
		m_knob5_rate_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_depth(t_param _value) {
		m_knob4_depth_23 = (_value < -1 ? -1 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_manual(t_param _value) {
		m_knob3_manual_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_manual_24; break;
		case 1: *value = self->m_knob4_depth_23; break;
		case 2: *value = self->m_knob5_rate_22; break;
		case 3: *value = self->m_knob6_res_25; break;
		case 4: *value = self->m_sw_20; break;
		case 5: *value = self->m_sw_21; break;
		
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
	// initialize parameter 0 ("m_knob3_manual_24")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_manual";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_manual_24;
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
	// initialize parameter 2 ("m_knob5_rate_22")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_rate_22;
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
	// initialize parameter 4 ("m_sw_20")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
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
	// initialize parameter 5 ("m_sw_21")
	pi = self->__commonstate.params + 5;
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


} // Wah::
