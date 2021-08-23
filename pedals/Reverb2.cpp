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
	t_sample m_knob6_spread_3;
	t_sample m_history_11;
	t_sample m_knob1_wetdry_2;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample m_knob4_fb_4;
	t_sample m_history_13;
	t_sample m_knob5_fb_5;
	t_sample m_sw_6;
	t_sample m_history_9;
	t_sample m_history_17;
	t_sample m_history_23;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample m_knob3_damp_7;
	t_sample m_history_15;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_knob1_wetdry_2 = ((int)0);
		m_knob6_spread_3 = ((int)0);
		m_knob4_fb_4 = ((t_sample)0.9);
		m_knob5_fb_5 = ((t_sample)0.5);
		m_sw_6 = ((int)0);
		m_knob3_damp_7 = ((t_sample)0.5);
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
		t_sample sqrt_860 = sqrt(m_knob1_wetdry_2);
		t_sample rsub_864 = (((int)1) - m_knob1_wetdry_2);
		t_sample sqrt_863 = sqrt(rsub_864);
		t_sample mul_914 = (m_knob5_fb_5 * ((t_sample)0.9));
		t_sample mul_859 = (m_knob5_fb_5 * ((t_sample)0.9));
		t_sample add_900 = (((int)450) + m_knob6_spread_3);
		t_sample add_854 = (((int)456) + m_knob6_spread_3);
		t_sample add_902 = (((int)682) + m_knob6_spread_3);
		t_sample add_856 = (((int)676) + m_knob6_spread_3);
		t_sample add_912 = (((int)882) + m_knob6_spread_3);
		t_sample add_858 = (((int)888) + m_knob6_spread_3);
		t_sample add_898 = (((int)1112) + m_knob6_spread_3);
		t_sample add_852 = (((int)1106) + m_knob6_spread_3);
		t_sample add_905 = (((int)3114) + m_knob6_spread_3);
		t_sample rsub_867 = (((int)1) - m_knob3_damp_7);
		t_sample add_904 = (((int)3234) + m_knob6_spread_3);
		t_sample rsub_930 = (((int)1) - m_knob3_damp_7);
		t_sample add_906 = (((int)2982) + m_knob6_spread_3);
		t_sample rsub_937 = (((int)1) - m_knob3_damp_7);
		t_sample add_907 = (((int)2844) + m_knob6_spread_3);
		t_sample rsub_958 = (((int)1) - m_knob3_damp_7);
		t_sample add_908 = (((int)2712) + m_knob6_spread_3);
		t_sample rsub_969 = (((int)1) - m_knob3_damp_7);
		t_sample add_909 = (((int)2554) + m_knob6_spread_3);
		t_sample rsub_980 = (((int)1) - m_knob3_damp_7);
		t_sample add_910 = (((int)2376) + m_knob6_spread_3);
		t_sample rsub_994 = (((int)1) - m_knob3_damp_7);
		t_sample add_911 = (((int)2232) + m_knob6_spread_3);
		t_sample rsub_1000 = (((int)1) - m_knob3_damp_7);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_919 = __m_sah_32(m_history_1, m_sw_6, ((int)0));
			t_sample gen_921 = sah_919;
			t_sample rsub_917 = (((int)1) - sah_919);
			t_sample history_918_next_920 = fixdenorm(rsub_917);
			t_sample out3 = gen_921;
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample add_924 = (gen_921 + ((int)1));
			t_sample choice_33 = int(add_924);
			t_sample gate_922 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_923 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_862 = (gate_923 * sqrt_863);
			t_sample mul_916 = (gate_923 * ((t_sample)0.015));
			t_sample tap_874 = m_delay_8.read_linear(add_905);
			t_sample gen_896 = tap_874;
			t_sample mul_872 = (tap_874 * m_knob3_damp_7);
			t_sample mul_870 = (m_history_9 * rsub_867);
			t_sample add_871 = (mul_872 + mul_870);
			t_sample mul_868 = (add_871 * m_knob4_fb_4);
			t_sample add_875 = (mul_916 + mul_868);
			t_sample history_869_next_876 = fixdenorm(add_871);
			t_sample tap_932 = m_delay_10.read_linear(add_904);
			t_sample gen_915 = tap_932;
			t_sample mul_931 = (tap_932 * m_knob3_damp_7);
			t_sample mul_929 = (m_history_11 * rsub_930);
			t_sample add_928 = (mul_931 + mul_929);
			t_sample mul_927 = (add_928 * m_knob4_fb_4);
			t_sample add_925 = (mul_916 + mul_927);
			t_sample history_869_next_926 = fixdenorm(add_928);
			t_sample tap_944 = m_delay_12.read_linear(add_906);
			t_sample gen_895 = tap_944;
			t_sample mul_943 = (tap_944 * m_knob3_damp_7);
			t_sample mul_942 = (m_history_13 * rsub_937);
			t_sample add_941 = (mul_943 + mul_942);
			t_sample mul_940 = (add_941 * m_knob4_fb_4);
			t_sample add_938 = (mul_916 + mul_940);
			t_sample history_869_next_939 = fixdenorm(add_941);
			t_sample tap_955 = m_delay_14.read_linear(add_907);
			t_sample gen_894 = tap_955;
			t_sample mul_954 = (tap_955 * m_knob3_damp_7);
			t_sample mul_951 = (m_history_15 * rsub_958);
			t_sample add_949 = (mul_954 + mul_951);
			t_sample mul_956 = (add_949 * m_knob4_fb_4);
			t_sample add_952 = (mul_916 + mul_956);
			t_sample history_869_next_957 = fixdenorm(add_949);
			t_sample tap_970 = m_delay_16.read_linear(add_908);
			t_sample gen_893 = tap_970;
			t_sample mul_965 = (tap_970 * m_knob3_damp_7);
			t_sample mul_963 = (m_history_17 * rsub_969);
			t_sample add_961 = (mul_965 + mul_963);
			t_sample mul_968 = (add_961 * m_knob4_fb_4);
			t_sample add_964 = (mul_916 + mul_968);
			t_sample history_869_next_967 = fixdenorm(add_961);
			t_sample tap_982 = m_delay_18.read_linear(add_909);
			t_sample gen_892 = tap_982;
			t_sample mul_981 = (tap_982 * m_knob3_damp_7);
			t_sample mul_978 = (m_history_19 * rsub_980);
			t_sample add_973 = (mul_981 + mul_978);
			t_sample mul_975 = (add_973 * m_knob4_fb_4);
			t_sample add_979 = (mul_916 + mul_975);
			t_sample history_869_next_976 = fixdenorm(add_973);
			t_sample tap_991 = m_delay_20.read_linear(add_910);
			t_sample gen_891 = tap_991;
			t_sample mul_986 = (tap_991 * m_knob3_damp_7);
			t_sample mul_989 = (m_history_21 * rsub_994);
			t_sample add_985 = (mul_986 + mul_989);
			t_sample mul_992 = (add_985 * m_knob4_fb_4);
			t_sample add_990 = (mul_916 + mul_992);
			t_sample history_869_next_993 = fixdenorm(add_985);
			t_sample tap_999 = m_delay_22.read_linear(add_911);
			t_sample gen_890 = tap_999;
			t_sample mul_1005 = (tap_999 * m_knob3_damp_7);
			t_sample mul_1003 = (m_history_23 * rsub_1000);
			t_sample add_1001 = (mul_1005 + mul_1003);
			t_sample mul_1006 = (add_1001 * m_knob4_fb_4);
			t_sample add_1004 = (mul_916 + mul_1006);
			t_sample history_869_next_997 = fixdenorm(add_1001);
			t_sample pass_913 = (((((((gen_890 + gen_891) + gen_892) + gen_893) + gen_894) + gen_895) + gen_915) + gen_896);
			t_sample tap_850 = m_delay_24.read_linear(add_898);
			t_sample sub_846 = (pass_913 - tap_850);
			t_sample mul_848 = (tap_850 * mul_914);
			t_sample add_847 = (pass_913 + mul_848);
			t_sample tap_1012 = m_delay_25.read_linear(add_912);
			t_sample sub_1013 = (sub_846 - tap_1012);
			t_sample mul_1009 = (tap_1012 * mul_914);
			t_sample add_1011 = (sub_846 + mul_1009);
			t_sample tap_1018 = m_delay_26.read_linear(add_902);
			t_sample sub_1019 = (sub_1013 - tap_1018);
			t_sample mul_1015 = (tap_1018 * mul_914);
			t_sample add_1017 = (sub_1013 + mul_1015);
			t_sample tap_1023 = m_delay_27.read_linear(add_900);
			t_sample sub_1025 = (sub_1019 - tap_1023);
			t_sample mul_1021 = (tap_1023 * mul_914);
			t_sample add_1022 = (sub_1019 + mul_1021);
			t_sample mul_865 = (sub_1025 * sqrt_860);
			t_sample add_861 = (mul_862 + mul_865);
			t_sample out1 = (gate_922 + add_861);
			t_sample tap_1029 = m_delay_28.read_linear(add_852);
			t_sample sub_1031 = (pass_913 - tap_1029);
			t_sample mul_1027 = (tap_1029 * mul_859);
			t_sample add_1028 = (pass_913 + mul_1027);
			t_sample tap_1035 = m_delay_29.read_linear(add_858);
			t_sample sub_1037 = (sub_1031 - tap_1035);
			t_sample mul_1033 = (tap_1035 * mul_859);
			t_sample add_1034 = (sub_1031 + mul_1033);
			t_sample tap_1041 = m_delay_30.read_linear(add_856);
			t_sample sub_1043 = (sub_1037 - tap_1041);
			t_sample mul_1039 = (tap_1041 * mul_859);
			t_sample add_1040 = (sub_1037 + mul_1039);
			t_sample tap_1047 = m_delay_31.read_linear(add_854);
			t_sample sub_1049 = (sub_1043 - tap_1047);
			t_sample mul_1045 = (tap_1047 * mul_859);
			t_sample add_1046 = (sub_1043 + mul_1045);
			t_sample mul_841 = (sub_1049 * sqrt_860);
			t_sample add_840 = (mul_862 + mul_841);
			t_sample out2 = (add_840 + gate_922);
			m_history_1 = history_918_next_920;
			m_delay_31.write(add_1046);
			m_delay_30.write(add_1040);
			m_delay_29.write(add_1034);
			m_delay_28.write(add_1028);
			m_delay_27.write(add_1022);
			m_delay_26.write(add_1017);
			m_delay_25.write(add_1011);
			m_delay_24.write(add_847);
			m_history_23 = history_869_next_997;
			m_delay_22.write(add_1004);
			m_history_21 = history_869_next_993;
			m_delay_20.write(add_990);
			m_history_19 = history_869_next_976;
			m_delay_18.write(add_979);
			m_history_17 = history_869_next_967;
			m_delay_16.write(add_964);
			m_history_15 = history_869_next_957;
			m_delay_14.write(add_952);
			m_history_13 = history_869_next_939;
			m_delay_12.write(add_938);
			m_history_11 = history_869_next_926;
			m_delay_10.write(add_925);
			m_history_9 = history_869_next_876;
			m_delay_8.write(add_875);
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
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_3 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
	};
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb2(t_param _value) {
		m_knob5_fb_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_7 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 1: *value = self->m_knob3_damp_7; break;
		case 2: *value = self->m_knob4_fb_4; break;
		case 3: *value = self->m_knob5_fb_5; break;
		case 4: *value = self->m_knob6_spread_3; break;
		case 5: *value = self->m_sw_6; break;
		
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
	// initialize parameter 1 ("m_knob3_damp_7")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_7;
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
	// initialize parameter 3 ("m_knob5_fb_5")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_spread_3")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_6")
	pi = self->__commonstate.params + 5;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_6;
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
