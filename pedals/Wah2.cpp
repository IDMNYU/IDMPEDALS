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
	t_sample m_knob5_rate_20;
	t_sample m_knob6_res_19;
	t_sample m_sw_23;
	t_sample m_knob3_manual_24;
	t_sample m_history_25;
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
		m_s_5 = ((int)0);
		m_s_6 = ((int)0);
		m_s_7 = ((int)0);
		m_s_8 = ((int)0);
		m_slim_9 = ((int)0);
		m_rc_10 = ((int)0);
		m_previn_11 = ((int)0);
		m_fc_12 = ((int)1);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_knob6_res_19 = 0.5;
		m_knob5_rate_20 = 0.1;
		m_knob4_depth_21 = 1;
		m_sw_22 = ((int)0);
		m_sw_23 = ((int)0);
		m_knob3_manual_24 = 0;
		m_history_25 = ((int)0);
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
		t_sample add_5988 = (m_sw_23 + ((int)1));
		t_sample mstosamps_5986 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_5985 = (((int)100) * (samplerate * 0.001));
		t_sample iup_29 = (1 / maximum(1, abs(mstosamps_5986)));
		t_sample idown_30 = (1 / maximum(1, abs(mstosamps_5985)));
		samples_to_seconds = (1 / samplerate);
		t_sample choice_33 = int(add_5988);
		t_sample minb_34 = ((((t_sample)1e-05) < m_knob6_res_19) ? m_knob6_res_19 : ((t_sample)1e-05));
		t_sample maxb_35 = safediv(((t_sample)12.5), samplerate);
		t_sample minb_36 = ((((t_sample)0.0001) < maxb_35) ? maxb_35 : ((t_sample)0.0001));
		t_sample expr_5891 = sqrt(((minb_36 < ((int)1)) ? minb_36 : ((int)1)));
		t_sample expr_5890 = (((int)-1) * log(expr_5891));
		int min_39 = (-1);
		int min_42 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_5996 = __m_sah_26(m_history_25, m_sw_22, ((int)0));
			t_sample gen_5998 = sah_5996;
			t_sample rsub_5994 = (((int)1) - sah_5996);
			t_sample history_5995_next_5997 = fixdenorm(rsub_5994);
			t_sample out3 = gen_5998;
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample add_5999 = (gen_5998 + ((int)1));
			t_sample choice_27 = int(add_5999);
			t_sample gate_5992 = (((choice_27 >= 1) && (choice_27 < 2)) ? in1 : 0);
			t_sample gate_5993 = ((choice_27 >= 2) ? in1 : 0);
			t_sample mix_6168 = (m_history_18 + (((t_sample)0.003926980723806) * (m_knob3_manual_24 - m_history_18)));
			t_sample mix_5863 = mix_6168;
			t_sample mix_6169 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_5863 - m_history_17)));
			t_sample mix_5861 = mix_6169;
			t_sample mix_6170 = (m_history_16 + (((t_sample)0.003926980723806) * (mix_5861 - m_history_16)));
			t_sample mix_5859 = mix_6170;
			t_sample gen_5869 = mix_5859;
			t_sample history_5864_next_5866 = fixdenorm(mix_5863);
			t_sample history_5862_next_5867 = fixdenorm(mix_5861);
			t_sample history_5860_next_5868 = fixdenorm(mix_5859);
			t_sample abs_5991 = fabs(gate_5993);
			__m_slide_28 = fixdenorm((__m_slide_28 + (((abs_5991 > __m_slide_28) ? iup_29 : idown_30) * (abs_5991 - __m_slide_28))));
			t_sample slide_5990 = __m_slide_28;
			t_sample mul_5987 = (slide_5990 * ((int)30));
			t_sample sqrt_5856 = sqrt(mul_5987);
			t_sample mix_6171 = (m_history_15 + (((t_sample)0.003926980723806) * (m_knob5_rate_20 - m_history_15)));
			t_sample mix_6012 = mix_6171;
			t_sample mix_6172 = (m_history_14 + (((t_sample)0.003926980723806) * (mix_6012 - m_history_14)));
			t_sample mix_6008 = mix_6172;
			t_sample mix_6173 = (m_history_13 + (((t_sample)0.003926980723806) * (mix_6008 - m_history_13)));
			t_sample mix_6011 = mix_6173;
			t_sample gen_5982 = mix_6011;
			t_sample history_5864_next_6014 = fixdenorm(mix_6012);
			t_sample history_5862_next_6015 = fixdenorm(mix_6008);
			t_sample history_5860_next_6007 = fixdenorm(mix_6011);
			t_sample rsub_6002 = (((int)1) - gen_5982);
			t_sample sqrt_6001 = sqrt(rsub_6002);
			t_sample rsub_6000 = (((int)1) - sqrt_6001);
			t_sample mul_6006 = (rsub_6000 * ((int)10));
			t_sample phasor_6005 = __m_phasor_31(mul_6006, samples_to_seconds);
			__m_cycle_32.phase(phasor_6005);
			t_sample cycle_5980 = __m_cycle_32(__sinedata);
			t_sample cycleindex_5981 = __m_cycle_32.phase();
			t_sample sub_6177 = (cycle_5980 - (-1));
			t_sample scale_6174 = ((safepow((sub_6177 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_5858 = scale_6174;
			t_sample selector_5989 = ((choice_33 >= 2) ? sqrt_5856 : ((choice_33 >= 1) ? scale_5858 : 0));
			t_sample mul_5979 = (selector_5989 * m_knob4_depth_21);
			t_sample add_5871 = (mul_5979 + gen_5869);
			t_sample clamp_5870 = ((add_5871 <= ((int)0)) ? ((int)0) : ((add_5871 >= ((int)1)) ? ((int)1) : add_5871));
			t_sample sub_6181 = (clamp_5870 - ((int)0));
			t_sample scale_6178 = ((safepow((sub_6181 * ((t_sample)1)), ((int)1)) * ((int)120)) + ((int)15));
			t_sample scale_5872 = scale_6178;
			t_sample expr_5966 = (((((t_sample)1.05) * ((minb_34 < ((int)1)) ? minb_34 : ((int)1))) - m_rc_10) * ((t_sample)0.25));
			t_sample fixdenorm_5896 = fixdenorm(m_previn_11);
			t_sample noise_5895 = noise();
			t_sample expr_5951 = (gate_5993 + (((t_sample)1e-11) * noise_5895));
			t_sample add_5935 = (m_rc_10 + expr_5966);
			t_sample gen_5894 = m_fc_12;
			t_sample mul_5878 = (scale_5872 * ((t_sample)0.90193));
			t_sample add_5875 = (mul_5878 + ((t_sample)7.29));
			t_sample div_5874 = (add_5875 * ((t_sample)0.0078740157480315));
			t_sample clamp_5880 = ((div_5874 <= ((int)0)) ? ((int)0) : ((div_5874 >= ((t_sample)0.99)) ? ((t_sample)0.99) : div_5874));
			t_sample mul_5879 = (clamp_5880 * expr_5890);
			t_sample expr_5892 = (((t_sample)0.99999636) + ((((t_sample)0.031261316) + ((((t_sample)0.00048274797) + (((t_sample)5.949053e-06) * mul_5879)) * mul_5879)) * mul_5879));
			t_sample mul_5887 = (expr_5892 * expr_5892);
			t_sample mul_5886 = (mul_5887 * mul_5887);
			t_sample mul_5885 = (mul_5886 * mul_5886);
			t_sample mul_5884 = (mul_5885 * mul_5885);
			t_sample mul_5883 = (mul_5884 * mul_5884);
			t_sample mul_5877 = (mul_5883 * expr_5891);
			t_sample sub_5876 = (mul_5877 - m_fc_12);
			t_sample div_5873 = (sub_5876 * ((t_sample)0.5));
			t_sample add_5889 = (m_fc_12 + div_5873);
			t_sample fc_next_5893 = fixdenorm(add_5889);
			t_sample expr_5965 = (gen_5894 * gen_5894);
			t_sample expr_5964 = (expr_5965 * (((int)1) - m_rc_10));
			t_sample expr_5963 = (expr_5965 + (expr_5964 * expr_5964));
			t_sample expr_5962 = ((((t_sample)1.25) + ((((t_sample)-0.74375) + (((t_sample)0.3) * expr_5963)) * expr_5963)) * expr_5963);
			t_sample expr_5961 = (m_rc_10 * (((t_sample)1.4) + ((((t_sample)0.108) + ((((t_sample)-0.164) - (((t_sample)0.069) * expr_5962)) * expr_5962)) * expr_5962)));
			t_sample expr_5960 = (((t_sample)0.18) + (((t_sample)0.25) * (expr_5961 * expr_5961)));
			t_sample expr_5959 = ((fixdenorm_5896 * expr_5960) - (expr_5961 * m_s_2));
			t_sample maxb_37 = (((((t_sample)0.062) * expr_5959) * expr_5959) + (((t_sample)0.993) * m_slim_9));
			t_sample minb_38 = ((((int)-1) < maxb_37) ? maxb_37 : ((int)-1));
			t_sample expr_5958 = ((minb_38 < ((int)1)) ? minb_38 : ((int)1));
			t_sample expr_5957 = (expr_5959 * ((((int)1) - expr_5958) + ((((t_sample)0.5) * expr_5958) * expr_5958)));
			t_sample rsub_5936 = (((int)1) - expr_5962);
			t_sample expr_5956 = ((expr_5957 * expr_5962) + (rsub_5936 * m_s_8));
			t_sample mul_5929 = (m_s_8 * ((t_sample)0.3));
			t_sample add_5927 = (expr_5956 + mul_5929);
			t_sample expr_5955 = ((add_5927 * expr_5962) + (rsub_5936 * m_s_7));
			t_sample mul_5921 = (m_s_6 * ((t_sample)0.3));
			t_sample mul_5918 = (m_s_4 * ((t_sample)0.3));
			t_sample mul_5911 = (expr_5956 * ((t_sample)0.3));
			t_sample mul_5908 = (expr_5955 * ((t_sample)0.3));
			t_sample mul_5926 = (m_s_7 * ((t_sample)0.3));
			t_sample add_5924 = (expr_5955 + mul_5926);
			t_sample clamp_5923 = ((add_5924 <= min_39) ? min_39 : ((add_5924 >= ((int)1)) ? ((int)1) : add_5924));
			t_sample expr_5954 = (clamp_5923 * (((int)1) - ((((t_sample)0.3333333) * clamp_5923) * clamp_5923)));
			t_sample expr_5953 = ((expr_5954 * expr_5962) + (rsub_5936 * m_s_6));
			t_sample add_5919 = (expr_5953 + mul_5921);
			t_sample expr_5952 = ((add_5919 * expr_5962) + (rsub_5936 * m_s_4));
			t_sample add_5916 = (expr_5952 + mul_5918);
			t_sample expr_5950 = ((expr_5951 * expr_5960) - (expr_5961 * add_5916));
			t_sample maxb_40 = (((((t_sample)0.062) * expr_5950) * expr_5950) + (((t_sample)0.993) * expr_5958));
			t_sample minb_41 = ((((int)-1) < maxb_40) ? maxb_40 : ((int)-1));
			t_sample expr_5949 = ((minb_41 < ((int)1)) ? minb_41 : ((int)1));
			t_sample expr_5948 = (expr_5950 * ((((int)1) - expr_5949) + ((((t_sample)0.5) * expr_5949) * expr_5949)));
			t_sample expr_5947 = ((expr_5948 * expr_5962) + (rsub_5936 * expr_5956));
			t_sample add_5909 = (expr_5947 + mul_5911);
			t_sample expr_5946 = ((add_5909 * expr_5962) + (rsub_5936 * expr_5955));
			t_sample add_5906 = (expr_5946 + mul_5908);
			t_sample clamp_5905 = ((add_5906 <= min_42) ? min_42 : ((add_5906 >= ((int)1)) ? ((int)1) : add_5906));
			t_sample expr_5945 = (clamp_5905 * (((int)1) - ((((t_sample)0.3333333) * clamp_5905) * clamp_5905)));
			t_sample expr_5944 = ((expr_5945 * expr_5962) + (rsub_5936 * expr_5953));
			t_sample mul_5900 = (expr_5952 * ((t_sample)0.3));
			t_sample mul_5903 = (expr_5953 * ((t_sample)0.3));
			t_sample add_5901 = (expr_5944 + mul_5903);
			t_sample expr_5943 = ((add_5901 * expr_5962) + (rsub_5936 * expr_5952));
			t_sample add_5898 = (expr_5943 + mul_5900);
			t_sample expr_5942 = (((((t_sample)0.19) * (add_5898 + m_s_5)) + (((t_sample)0.57) * (add_5916 + m_s_3))) - (((t_sample)0.52) * m_s_1));
			t_sample gen_5978 = expr_5942;
			t_sample previn_next_5967 = fixdenorm(expr_5951);
			t_sample rc_next_5968 = fixdenorm(add_5935);
			t_sample slim_next_5969 = fixdenorm(expr_5949);
			t_sample s1_next_5970 = fixdenorm(expr_5947);
			t_sample s2_next_5971 = fixdenorm(expr_5946);
			t_sample s3_next_5972 = fixdenorm(expr_5944);
			t_sample s8_next_5973 = fixdenorm(add_5916);
			t_sample s4_next_5974 = fixdenorm(expr_5943);
			t_sample s7_next_5975 = fixdenorm(add_5898);
			t_sample s5_next_5976 = fixdenorm(add_5898);
			t_sample s6_next_5977 = fixdenorm(expr_5942);
			t_sample add_6004 = (gen_5978 + gate_5992);
			t_sample out1 = add_6004;
			t_sample add_6003 = (gen_5978 + gate_5992);
			t_sample out2 = add_6003;
			m_history_25 = history_5995_next_5997;
			m_history_18 = history_5864_next_5866;
			m_history_16 = history_5860_next_5868;
			m_history_17 = history_5862_next_5867;
			m_history_15 = history_5864_next_6014;
			m_history_13 = history_5860_next_6007;
			m_history_14 = history_5862_next_6015;
			m_fc_12 = fc_next_5893;
			m_s_1 = s6_next_5977;
			m_s_2 = s5_next_5976;
			m_s_3 = s7_next_5975;
			m_s_4 = s4_next_5974;
			m_s_5 = s8_next_5973;
			m_s_6 = s3_next_5972;
			m_s_7 = s2_next_5971;
			m_s_8 = s1_next_5970;
			m_slim_9 = slim_next_5969;
			m_rc_10 = rc_next_5968;
			m_previn_11 = previn_next_5967;
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
	inline void set_knob6_res(t_param _value) {
		m_knob6_res_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_rate(t_param _value) {
		m_knob5_rate_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_depth(t_param _value) {
		m_knob4_depth_21 = (_value < -1 ? -1 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_manual(t_param _value) {
		m_knob3_manual_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 1: *value = self->m_knob4_depth_21; break;
		case 2: *value = self->m_knob5_rate_20; break;
		case 3: *value = self->m_knob6_res_19; break;
		case 4: *value = self->m_sw_22; break;
		case 5: *value = self->m_sw_23; break;
		
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
	// initialize parameter 2 ("m_knob5_rate_20")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_rate_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_res_19")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_res_19;
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
	// initialize parameter 5 ("m_sw_23")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_23;
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
