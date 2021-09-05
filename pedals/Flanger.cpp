#include "Flanger.h"

namespace Flanger {

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
	Delay m_delay_6;
	Delay m_delay_2;
	Delay m_delay_1;
	Sah __m_sah_20;
	SineCycle __m_cycle_22;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_5;
	t_sample m_knob6_res_16;
	t_sample m_knob4_depth_15;
	t_sample m_knob5_rate_14;
	t_sample m_sw_17;
	t_sample m_history_19;
	t_sample m_sw_18;
	t_sample m_history_4;
	t_sample m_knob3_manual_13;
	t_sample m_history_11;
	t_sample m_history_7;
	t_sample m_history_3;
	t_sample m_history_12;
	t_sample m_history_8;
	t_sample samplerate;
	t_sample m_history_9;
	t_sample m_history_10;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)3940));
		m_delay_2.reset("m_delay_2", ((int)3840));
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_delay_6.reset("m_delay_6", ((int)3840));
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_knob3_manual_13 = ((int)0);
		m_knob5_rate_14 = ((int)0);
		m_knob4_depth_15 = ((int)0);
		m_knob6_res_16 = ((int)0);
		m_sw_17 = ((int)0);
		m_sw_18 = ((int)0);
		m_history_19 = ((int)0);
		__m_sah_20.reset(0);
		__m_cycle_22.reset(samplerate, 0);
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
		t_sample sqrt_855 = sqrt(m_knob6_res_16);
		t_sample sqrt_864 = sqrt(sqrt_855);
		t_sample mul_876 = (sqrt_864 * ((t_sample)0.99));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_858 = __m_sah_20(m_history_19, m_sw_17, ((int)0));
			t_sample gen_860 = sah_858;
			t_sample rsub_856 = (((int)1) - sah_858);
			t_sample history_857_next_859 = fixdenorm(rsub_856);
			t_sample out3 = gen_860;
			t_sample mix_997 = (m_history_12 + (((t_sample)0.003926980723806) * (m_knob3_manual_13 - m_history_12)));
			t_sample mix_837 = mix_997;
			t_sample mix_998 = (m_history_11 + (((t_sample)0.003926980723806) * (mix_837 - m_history_11)));
			t_sample mix_835 = mix_998;
			t_sample mix_999 = (m_history_10 + (((t_sample)0.003926980723806) * (mix_835 - m_history_10)));
			t_sample mix_833 = mix_999;
			t_sample gen_845 = mix_833;
			t_sample history_838_next_840 = fixdenorm(mix_837);
			t_sample history_836_next_841 = fixdenorm(mix_835);
			t_sample history_834_next_842 = fixdenorm(mix_833);
			t_sample expr_881 = (((int)1) - sqrt((((int)1) - gen_845)));
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample mix_1000 = (m_history_9 + (((t_sample)0.003926980723806) * (m_knob5_rate_14 - m_history_9)));
			t_sample mix_886 = mix_1000;
			t_sample mix_1001 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_886 - m_history_8)));
			t_sample mix_887 = mix_1001;
			t_sample mix_1002 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_887 - m_history_7)));
			t_sample mix_888 = mix_1002;
			t_sample gen_844 = mix_888;
			t_sample history_838_next_884 = fixdenorm(mix_886);
			t_sample history_836_next_892 = fixdenorm(mix_887);
			t_sample history_834_next_885 = fixdenorm(mix_888);
			t_sample expr_882 = (((int)1) - sqrt(sqrt((((int)1) - gen_844))));
			t_sample add_863 = (gen_860 + ((int)1));
			t_sample choice_21 = int(add_863);
			t_sample gate_861 = (((choice_21 >= 1) && (choice_21 < 2)) ? in1 : 0);
			t_sample gate_862 = ((choice_21 >= 2) ? in1 : 0);
			t_sample mul_878 = (expr_881 * ((int)1920));
			t_sample tap_854 = m_delay_6.read_linear(mul_878);
			t_sample switch_852 = (m_sw_18 ? tap_854 : gate_862);
			t_sample mul_867 = (expr_882 * ((int)10));
			__m_cycle_22.freq(mul_867);
			t_sample cycle_868 = __m_cycle_22(__sinedata);
			t_sample cycleindex_869 = __m_cycle_22.phase();
			t_sample mix_1003 = (m_history_5 + (((t_sample)0.003926980723806) * (m_knob4_depth_15 - m_history_5)));
			t_sample mix_896 = mix_1003;
			t_sample mix_1004 = (m_history_4 + (((t_sample)0.003926980723806) * (mix_896 - m_history_4)));
			t_sample mix_903 = mix_1004;
			t_sample mix_1005 = (m_history_3 + (((t_sample)0.003926980723806) * (mix_903 - m_history_3)));
			t_sample mix_897 = mix_1005;
			t_sample gen_843 = mix_897;
			t_sample history_838_next_901 = fixdenorm(mix_896);
			t_sample history_836_next_899 = fixdenorm(mix_903);
			t_sample history_834_next_902 = fixdenorm(mix_897);
			t_sample mul_872 = (gen_843 * mul_878);
			t_sample mul_866 = (cycle_868 * mul_872);
			t_sample add_870 = (mul_878 + mul_866);
			t_sample clamp_871 = ((add_870 <= ((int)0)) ? ((int)0) : ((add_870 >= ((int)3940)) ? ((int)3940) : add_870));
			t_sample tap_880 = m_delay_2.read_linear(clamp_871);
			t_sample add_851 = (switch_852 + tap_880);
			t_sample div_849 = (add_851 * ((t_sample)0.5));
			t_sample out1 = (div_849 + gate_861);
			t_sample mul_877 = (tap_880 * mul_876);
			t_sample tap_875 = m_delay_1.read_linear(clamp_871);
			t_sample add_850 = (switch_852 + tap_875);
			t_sample div_848 = (add_850 * ((t_sample)0.5));
			t_sample out2 = (div_848 + gate_861);
			t_sample mul_873 = (tap_875 * mul_876);
			m_history_19 = history_857_next_859;
			m_history_12 = history_838_next_840;
			m_history_10 = history_834_next_842;
			m_history_11 = history_836_next_841;
			m_history_9 = history_838_next_884;
			m_history_7 = history_834_next_885;
			m_history_8 = history_836_next_892;
			m_delay_6.write(gate_862);
			m_history_5 = history_838_next_901;
			m_history_3 = history_834_next_902;
			m_history_4 = history_836_next_899;
			m_delay_2.write((mul_873 + gate_862));
			m_delay_1.write(mul_877);
			m_delay_1.step();
			m_delay_2.step();
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
	inline void set_knob3_manual(t_param _value) {
		m_knob3_manual_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_rate(t_param _value) {
		m_knob5_rate_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_depth(t_param _value) {
		m_knob4_depth_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_res(t_param _value) {
		m_knob6_res_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_manual_13; break;
		case 1: *value = self->m_knob4_depth_15; break;
		case 2: *value = self->m_knob5_rate_14; break;
		case 3: *value = self->m_knob6_res_16; break;
		case 4: *value = self->m_sw_17; break;
		case 5: *value = self->m_sw_18; break;
		
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
	// initialize parameter 0 ("m_knob3_manual_13")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_manual";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_manual_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_depth_15")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_depth_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_rate_14")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_rate_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_res_16")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_res_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
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
	// initialize parameter 5 ("m_sw_18")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_18;
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


} // Flanger::
