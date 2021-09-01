#include "Chorus.h"

namespace Chorus {

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
	Delay m_delay_1;
	Sah __m_sah_21;
	SineCycle __m_cycle_24;
	SineCycle __m_cycle_23;
	SineCycle __m_cycle_30;
	SineCycle __m_cycle_25;
	SineCycle __m_cycle_27;
	SineCycle __m_cycle_26;
	SineCycle __m_cycle_29;
	SineCycle __m_cycle_28;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_10;
	t_sample m_history_5;
	t_sample m_history_6;
	t_sample m_history_4;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample m_history_7;
	t_sample samplerate;
	t_sample m_history_9;
	t_sample m_sw_20;
	t_sample m_knob4_rate_18;
	t_sample m_history_13;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_knob6_taps_19;
	t_sample m_history_8;
	t_sample m_knob3_depth_16;
	t_sample m_sw_15;
	t_sample m_knob5_breadth_17;
	t_sample m_history_14;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)20000));
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_sw_15 = ((int)0);
		m_knob3_depth_16 = ((int)0);
		m_knob5_breadth_17 = 256;
		m_knob4_rate_18 = ((int)0);
		m_knob6_taps_19 = ((int)0);
		m_sw_20 = ((int)0);
		__m_sah_21.reset(0);
		__m_cycle_23.reset(samplerate, 0);
		__m_cycle_24.reset(samplerate, 0);
		__m_cycle_25.reset(samplerate, 0);
		__m_cycle_26.reset(samplerate, 0);
		__m_cycle_27.reset(samplerate, 0);
		__m_cycle_28.reset(samplerate, 0);
		__m_cycle_29.reset(samplerate, 0);
		__m_cycle_30.reset(samplerate, 0);
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
		t_sample expr_904 = (((int)1) - sqrt(sqrt((((int)1) - m_knob4_rate_18))));
		t_sample expr_905 = (((int)1) - sqrt(sqrt((((int)1) - m_knob3_depth_16))));
		t_sample div_789 = (m_sw_20 * ((t_sample)0.5));
		t_sample add_788 = (div_789 + ((t_sample)0.5));
		t_sample mul_797 = (expr_905 * ((int)1000));
		t_sample add_796 = (mul_797 + ((int)2));
		t_sample mul_794 = (expr_904 * ((int)10));
		t_sample add_795 = (mul_794 + ((t_sample)0.01));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_898 = __m_sah_21(m_history_14, m_sw_15, ((int)0));
			t_sample gen_900 = sah_898;
			t_sample rsub_896 = (((int)1) - sah_898);
			t_sample history_897_next_899 = fixdenorm(rsub_896);
			t_sample out3 = gen_900;
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample add_901 = (gen_900 + ((int)1));
			t_sample choice_22 = int(add_901);
			t_sample gate_893 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_894 = ((choice_22 >= 2) ? in1 : 0);
			t_sample switch_831 = (m_sw_20 ? ((int)0) : gate_894);
			t_sample mix_1001 = (m_history_13 + (((t_sample)0.003926980723806) * (m_knob6_taps_19 - m_history_13)));
			t_sample mix_803 = mix_1001;
			t_sample mix_1002 = (m_history_12 + (((t_sample)0.003926980723806) * (mix_803 - m_history_12)));
			t_sample mix_801 = mix_1002;
			t_sample mix_1003 = (m_history_11 + (((t_sample)0.003926980723806) * (mix_801 - m_history_11)));
			t_sample mix_799 = mix_1003;
			t_sample gen_829 = mix_799;
			t_sample history_804_next_806 = fixdenorm(mix_803);
			t_sample history_802_next_807 = fixdenorm(mix_801);
			t_sample history_800_next_808 = fixdenorm(mix_799);
			t_sample sub_1007 = (gen_829 - ((int)0));
			t_sample scale_1004 = ((safepow((sub_1007 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.5)) + ((int)1));
			t_sample sub_1011 = (gen_829 - ((int)0));
			t_sample scale_1008 = ((safepow((sub_1011 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-2));
			t_sample clamp_815 = ((scale_1008 <= ((int)0)) ? ((int)0) : ((scale_1008 >= ((int)1)) ? ((int)1) : scale_1008));
			t_sample sub_1015 = (gen_829 - ((int)0));
			t_sample scale_1012 = ((safepow((sub_1015 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-3));
			t_sample clamp_813 = ((scale_1012 <= ((int)0)) ? ((int)0) : ((scale_1012 >= ((int)1)) ? ((int)1) : scale_1012));
			t_sample sub_1019 = (gen_829 - ((int)0));
			t_sample scale_1016 = ((safepow((sub_1019 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-1));
			t_sample clamp_817 = ((scale_1016 <= ((int)0)) ? ((int)0) : ((scale_1016 >= ((int)1)) ? ((int)1) : scale_1016));
			t_sample mix_1020 = (m_history_10 + (((t_sample)0.003926980723806) * (m_knob5_breadth_17 - m_history_10)));
			t_sample mix_906 = mix_1020;
			t_sample mix_1021 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_906 - m_history_9)));
			t_sample mix_909 = mix_1021;
			t_sample mix_1022 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_909 - m_history_8)));
			t_sample mix_912 = mix_1022;
			t_sample gen_809 = mix_912;
			t_sample history_804_next_908 = fixdenorm(mix_906);
			t_sample history_802_next_910 = fixdenorm(mix_909);
			t_sample history_800_next_914 = fixdenorm(mix_912);
			t_sample mul_798 = (gen_809 * ((int)1));
			t_sample mul_812 = (gen_809 * ((int)2));
			t_sample mul_811 = (gen_809 * ((int)3));
			t_sample mul_810 = (gen_809 * ((int)4));
			t_sample mix_1023 = (m_history_7 + (((t_sample)0.003926980723806) * (add_796 - m_history_7)));
			t_sample mix_919 = mix_1023;
			t_sample mix_1024 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_919 - m_history_6)));
			t_sample mix_922 = mix_1024;
			t_sample mix_1025 = (m_history_5 + (((t_sample)0.003926980723806) * (mix_922 - m_history_5)));
			t_sample mix_923 = mix_1025;
			t_sample gen_903 = mix_923;
			t_sample history_804_next_921 = fixdenorm(mix_919);
			t_sample history_802_next_926 = fixdenorm(mix_922);
			t_sample history_800_next_925 = fixdenorm(mix_923);
			t_sample mix_1026 = (m_history_4 + (((t_sample)0.003926980723806) * (add_795 - m_history_4)));
			t_sample mix_940 = mix_1026;
			t_sample mix_1027 = (m_history_3 + (((t_sample)0.003926980723806) * (mix_940 - m_history_3)));
			t_sample mix_932 = mix_1027;
			t_sample mix_1028 = (m_history_2 + (((t_sample)0.003926980723806) * (mix_932 - m_history_2)));
			t_sample mix_934 = mix_1028;
			t_sample gen_840 = mix_934;
			t_sample history_804_next_938 = fixdenorm(mix_940);
			t_sample history_802_next_939 = fixdenorm(mix_932);
			t_sample history_800_next_936 = fixdenorm(mix_934);
			t_sample mul_844 = (gen_840 * ((int)1));
			__m_cycle_23.freq(mul_844);
			t_sample cycle_882 = __m_cycle_23(__sinedata);
			t_sample cycleindex_883 = __m_cycle_23.phase();
			t_sample mul_880 = (cycle_882 * gen_903);
			t_sample add_881 = (mul_880 + mul_798);
			t_sample mul_875 = (gen_840 * ((t_sample)1.51));
			__m_cycle_24.freq(mul_875);
			t_sample cycle_878 = __m_cycle_24(__sinedata);
			t_sample cycleindex_879 = __m_cycle_24.phase();
			t_sample mul_876 = (cycle_878 * gen_903);
			t_sample add_877 = (mul_876 + mul_798);
			t_sample mul_843 = (gen_840 * ((t_sample)0.48));
			__m_cycle_25.freq(mul_843);
			t_sample cycle_872 = __m_cycle_25(__sinedata);
			t_sample cycleindex_873 = __m_cycle_25.phase();
			t_sample mul_870 = (cycle_872 * gen_903);
			t_sample add_871 = (mul_870 + mul_812);
			t_sample mul_865 = (gen_840 * ((t_sample)0.73));
			__m_cycle_26.freq(mul_865);
			t_sample cycle_868 = __m_cycle_26(__sinedata);
			t_sample cycleindex_869 = __m_cycle_26.phase();
			t_sample mul_866 = (cycle_868 * gen_903);
			t_sample add_867 = (mul_866 + mul_812);
			t_sample mul_842 = (gen_840 * ((t_sample)1.245));
			__m_cycle_27.freq(mul_842);
			t_sample cycle_861 = __m_cycle_27(__sinedata);
			t_sample cycleindex_862 = __m_cycle_27.phase();
			t_sample mul_859 = (cycle_861 * gen_903);
			t_sample add_860 = (mul_859 + mul_811);
			t_sample mul_854 = (gen_840 * ((t_sample)0.81));
			__m_cycle_28.freq(mul_854);
			t_sample cycle_857 = __m_cycle_28(__sinedata);
			t_sample cycleindex_858 = __m_cycle_28.phase();
			t_sample mul_855 = (cycle_857 * gen_903);
			t_sample add_856 = (mul_855 + mul_811);
			t_sample mul_841 = (gen_840 * ((t_sample)1.93));
			__m_cycle_29.freq(mul_841);
			t_sample cycle_852 = __m_cycle_29(__sinedata);
			t_sample cycleindex_853 = __m_cycle_29.phase();
			t_sample mul_850 = (cycle_852 * gen_903);
			t_sample add_851 = (mul_850 + mul_810);
			t_sample mul_845 = (gen_840 * ((t_sample)2.11));
			__m_cycle_30.freq(mul_845);
			t_sample cycle_848 = __m_cycle_30(__sinedata);
			t_sample cycleindex_849 = __m_cycle_30.phase();
			t_sample mul_846 = (cycle_848 * gen_903);
			t_sample add_847 = (mul_846 + mul_810);
			t_sample tap_885 = m_delay_1.read_linear(add_881);
			t_sample tap_886 = m_delay_1.read_linear(add_877);
			t_sample tap_887 = m_delay_1.read_linear(add_871);
			t_sample tap_888 = m_delay_1.read_linear(add_867);
			t_sample tap_889 = m_delay_1.read_linear(add_860);
			t_sample tap_890 = m_delay_1.read_linear(add_856);
			t_sample tap_891 = m_delay_1.read_linear(add_851);
			t_sample tap_892 = m_delay_1.read_linear(add_847);
			t_sample mul_827 = (tap_890 * clamp_815);
			t_sample mul_826 = (tap_891 * clamp_813);
			t_sample mul_822 = (tap_887 * clamp_817);
			t_sample mul_823 = (tap_886 * ((int)1));
			t_sample mul_863 = ((((mul_823 + mul_822) + mul_826) + mul_827) * scale_1004);
			t_sample add_874 = (switch_831 + mul_863);
			t_sample mul_790 = (add_788 * add_874);
			t_sample out2 = (gate_893 + mul_790);
			t_sample mul_828 = (tap_889 * clamp_815);
			t_sample mul_825 = (tap_892 * clamp_813);
			t_sample mul_821 = (tap_888 * clamp_817);
			t_sample mul_824 = (tap_885 * ((int)1));
			t_sample mul_864 = ((((mul_824 + mul_821) + mul_825) + mul_828) * scale_1004);
			t_sample add_902 = (switch_831 + mul_864);
			t_sample mul_791 = (add_788 * add_902);
			t_sample out1 = (gate_893 + mul_791);
			m_history_14 = history_897_next_899;
			m_history_13 = history_804_next_806;
			m_history_11 = history_800_next_808;
			m_history_12 = history_802_next_807;
			m_history_10 = history_804_next_908;
			m_history_8 = history_800_next_914;
			m_history_9 = history_802_next_910;
			m_history_7 = history_804_next_921;
			m_history_5 = history_800_next_925;
			m_history_6 = history_802_next_926;
			m_history_4 = history_804_next_938;
			m_history_2 = history_800_next_936;
			m_history_3 = history_802_next_939;
			m_delay_1.write(gate_894);
			m_delay_1.step();
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
		m_sw_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_breadth(t_param _value) {
		m_knob5_breadth_17 = (_value < 240 ? 240 : (_value > 2400 ? 2400 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_taps(t_param _value) {
		m_knob6_taps_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_knob3_depth(value); break;
		case 1: self->set_knob4_rate(value); break;
		case 2: self->set_knob5_breadth(value); break;
		case 3: self->set_knob6_taps(value); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_depth_16; break;
		case 1: *value = self->m_knob4_rate_18; break;
		case 2: *value = self->m_knob5_breadth_17; break;
		case 3: *value = self->m_knob6_taps_19; break;
		case 4: *value = self->m_sw_15; break;
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
	// initialize parameter 0 ("m_knob3_depth_16")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_18")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_breadth_17")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_breadth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_breadth_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 240;
	pi->outputmax = 2400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_taps_19")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_taps";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_taps_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_15")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_15;
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


} // Chorus::
