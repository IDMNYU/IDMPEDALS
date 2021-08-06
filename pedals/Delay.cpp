#include "Delay.h"

namespace Delay {

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
	Delay m_delay_5;
	Delay m_delay_6;
	Sah __m_sah_18;
	int __exception;
	int vectorsize;
	t_sample m_knob3_level_13;
	t_sample m_sw_12;
	t_sample m_sw_11;
	t_sample m_history_2;
	t_sample m_knob4_fb_15;
	t_sample m_knob5_time_14;
	t_sample m_knob6_lowpass_16;
	t_sample m_y_1;
	t_sample m_history_10;
	t_sample m_sw_17;
	t_sample m_history_3;
	t_sample m_history_9;
	t_sample m_history_4;
	t_sample m_history_7;
	t_sample samplerate;
	t_sample m_history_8;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_y_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_delay_5.reset("m_delay_5", ((int)48000));
		m_delay_6.reset("m_delay_6", ((int)48000));
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_sw_11 = ((int)0);
		m_sw_12 = ((int)0);
		m_knob3_level_13 = ((int)0);
		m_knob5_time_14 = ((int)0);
		m_knob4_fb_15 = ((int)0);
		m_knob6_lowpass_16 = ((int)0);
		m_sw_17 = ((int)0);
		__m_sah_18.reset(0);
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
		t_sample add_880 = (m_sw_12 + ((int)1));
		t_sample mul_896 = (m_knob4_fb_15 * ((t_sample)0.99));
		t_sample choice_20 = int(add_880);
		t_sample choice_21 = int(add_880);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_886 = __m_sah_18(m_history_10, m_sw_17, ((int)0));
			t_sample gen_888 = sah_886;
			t_sample rsub_884 = (((int)1) - sah_886);
			t_sample history_885_next_887 = fixdenorm(rsub_884);
			t_sample out3 = gen_888;
			t_sample add_889 = (gen_888 + ((int)1));
			t_sample choice_19 = int(add_889);
			t_sample gate_881 = (((choice_19 >= 1) && (choice_19 < 2)) ? in1 : 0);
			t_sample gate_882 = ((choice_19 >= 2) ? in1 : 0);
			t_sample mul_902 = (gate_882 * ((int)1));
			t_sample mix_992 = (m_history_9 + (((t_sample)0.003926980723806) * (m_knob5_time_14 - m_history_9)));
			t_sample mix_862 = mix_992;
			t_sample mix_993 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_862 - m_history_8)));
			t_sample mix_860 = mix_993;
			t_sample mix_994 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_860 - m_history_7)));
			t_sample mix_858 = mix_994;
			t_sample gen_890 = mix_858;
			t_sample history_864_next_867 = fixdenorm(mix_862);
			t_sample history_861_next_868 = fixdenorm(mix_860);
			t_sample history_859_next_869 = fixdenorm(mix_858);
			t_sample sub_998 = (gen_890 - ((int)0));
			t_sample scale_995 = ((safepow((sub_998 * ((t_sample)1)), ((int)1)) * ((int)36000)) + ((int)12000));
			t_sample scale_855 = scale_995;
			t_sample sub_1002 = (gen_890 - ((int)0));
			t_sample scale_999 = ((safepow((sub_1002 * ((t_sample)1)), ((int)1)) * ((int)12000)) + ((int)0));
			t_sample scale_856 = scale_999;
			t_sample switch_857 = (m_sw_11 ? scale_855 : scale_856);
			t_sample tap_901 = m_delay_6.read_cubic(switch_857);
			t_sample mul_899 = (tap_901 * mul_896);
			t_sample mul_898 = (tap_901 * m_knob3_level_13);
			t_sample gate_878 = (((choice_20 >= 1) && (choice_20 < 2)) ? mul_898 : 0);
			t_sample gate_879 = ((choice_20 >= 2) ? mul_898 : 0);
			t_sample tap_895 = m_delay_5.read_cubic(switch_857);
			t_sample mul_893 = (tap_895 * mul_896);
			t_sample mul_892 = (tap_895 * m_knob3_level_13);
			t_sample gate_876 = (((choice_21 >= 1) && (choice_21 < 2)) ? mul_892 : 0);
			t_sample gate_877 = ((choice_21 >= 2) ? mul_892 : 0);
			t_sample add_891 = ((gate_881 + mul_902) + ((gate_876 + gate_877) + gate_878));
			t_sample out2 = add_891;
			t_sample add_897 = ((gate_881 + mul_902) + ((gate_876 + gate_878) + gate_879));
			t_sample out1 = add_897;
			t_sample mix_1003 = (m_history_4 + (((t_sample)0.003926980723806) * (m_knob6_lowpass_16 - m_history_4)));
			t_sample mix_905 = mix_1003;
			t_sample mix_1004 = (m_history_3 + (((t_sample)0.003926980723806) * (mix_905 - m_history_3)));
			t_sample mix_909 = mix_1004;
			t_sample mix_1005 = (m_history_2 + (((t_sample)0.003926980723806) * (mix_909 - m_history_2)));
			t_sample mix_911 = mix_1005;
			t_sample gen_870 = mix_911;
			t_sample history_864_next_914 = fixdenorm(mix_905);
			t_sample history_861_next_910 = fixdenorm(mix_909);
			t_sample history_859_next_913 = fixdenorm(mix_911);
			t_sample mtof_871 = mtof(gen_870, ((int)440));
			t_sample mul_873 = (mtof_871 * safediv((2 * 3.1415926535898), samplerate));
			t_sample sin_874 = sin(mul_873);
			t_sample clamp_875 = ((sin_874 <= ((int)0)) ? ((int)0) : ((sin_874 >= ((int)1)) ? ((int)1) : sin_874));
			t_sample mix_1006 = (m_y_1 + (clamp_875 * (mul_899 - m_y_1)));
			t_sample mix_854 = mix_1006;
			t_sample add_1008 = (mul_893 + mul_902);
			t_sample mix_1007 = (m_y_1 + (clamp_875 * (add_1008 - m_y_1)));
			t_sample mix_872 = mix_1007;
			t_sample y0_next_918 = fixdenorm(mix_854);
			t_sample y0_next_919 = fixdenorm(mix_872);
			m_history_10 = history_885_next_887;
			m_history_9 = history_864_next_867;
			m_history_7 = history_859_next_869;
			m_history_8 = history_861_next_868;
			m_delay_6.write(mix_872);
			m_delay_5.write(mix_854);
			m_history_4 = history_864_next_914;
			m_history_2 = history_859_next_913;
			m_history_3 = history_861_next_910;
			m_y_1 = y0_next_918;
			m_y_1 = y0_next_919;
			m_delay_5.step();
			m_delay_6.step();
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
		m_sw_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_level(t_param _value) {
		m_knob3_level_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_time(t_param _value) {
		m_knob5_time_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_fb(t_param _value) {
		m_knob4_fb_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_lowpass(t_param _value) {
		m_knob6_lowpass_16 = (_value < 30 ? 30 : (_value > 138 ? 138 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 7; }

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
		case 0: self->set_knob3_level(value); break;
		case 1: self->set_knob4_fb(value); break;
		case 2: self->set_knob5_time(value); break;
		case 3: self->set_knob6_lowpass(value); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw5(value); break;
		case 6: self->set_sw6(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_level_13; break;
		case 1: *value = self->m_knob4_fb_15; break;
		case 2: *value = self->m_knob5_time_14; break;
		case 3: *value = self->m_knob6_lowpass_16; break;
		case 4: *value = self->m_sw_17; break;
		case 5: *value = self->m_sw_11; break;
		case 6: *value = self->m_sw_12; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(7 * sizeof(ParamInfo));
	self->__commonstate.numparams = 7;
	// initialize parameter 0 ("m_knob3_level_13")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_level";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_level_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_fb_15")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_time_14")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_time";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_time_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_lowpass_16")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_lowpass";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_lowpass_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 30;
	pi->outputmax = 138;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_17")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_11")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_11;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_sw_12")
	pi = self->__commonstate.params + 6;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_12;
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


} // Delay::
