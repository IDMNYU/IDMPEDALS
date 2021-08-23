#include "Reverb.h"

namespace Reverb {

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
	Delay m_delay_7;
	Delay m_delay_6;
	Delay m_delay_8;
	Delay m_delay_10;
	Delay m_delay_9;
	Delay m_delay_11;
	Sah __m_sah_12;
	int __exception;
	int vectorsize;
	t_sample m_history_4;
	t_sample samplerate;
	t_sample m_knob4_wetdry_2;
	t_sample m_sw_1;
	t_sample m_knob3_size_3;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_sw_1 = ((int)0);
		m_knob4_wetdry_2 = ((int)0);
		m_knob3_size_3 = ((int)0);
		m_history_4 = ((int)0);
		m_delay_5.reset("m_delay_5", samplerate);
		m_delay_6.reset("m_delay_6", samplerate);
		m_delay_7.reset("m_delay_7", samplerate);
		m_delay_8.reset("m_delay_8", ((int)3374));
		m_delay_9.reset("m_delay_9", ((int)3202));
		m_delay_10.reset("m_delay_10", ((int)4106));
		m_delay_11.reset("m_delay_11", ((int)4502));
		__m_sah_12.reset(0);
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
		t_sample sqrt_846 = sqrt(m_knob4_wetdry_2);
		t_sample rsub_851 = (((int)1) - m_knob4_wetdry_2);
		t_sample sqrt_850 = sqrt(rsub_851);
		t_sample mul_909 = (m_knob3_size_3 * ((int)347));
		t_sample mul_902 = (m_knob3_size_3 * ((int)113));
		t_sample mul_895 = (m_knob3_size_3 * ((int)37));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_857 = __m_sah_12(m_history_4, m_sw_1, ((int)0));
			t_sample gen_859 = sah_857;
			t_sample rsub_855 = (((int)1) - sah_857);
			t_sample history_856_next_858 = fixdenorm(rsub_855);
			t_sample out3 = gen_859;
			t_sample add_862 = (gen_859 + ((int)1));
			t_sample choice_13 = int(add_862);
			t_sample gate_860 = (((choice_13 >= 1) && (choice_13 < 2)) ? in1 : 0);
			t_sample gate_861 = ((choice_13 >= 2) ? in1 : 0);
			t_sample mul_849 = (gate_861 * sqrt_850);
			t_sample tap_914 = m_delay_5.read_linear(mul_909);
			t_sample mul_912 = (tap_914 * (-1));
			t_sample add_911 = (gate_861 + mul_912);
			t_sample mul_910 = (add_911 * ((t_sample)0.7));
			t_sample gen_915 = (mul_910 + tap_914);
			t_sample tap_907 = m_delay_6.read_linear(mul_902);
			t_sample mul_905 = (tap_907 * (-1));
			t_sample add_904 = (gen_915 + mul_905);
			t_sample mul_903 = (add_904 * ((t_sample)0.7));
			t_sample gen_908 = (mul_903 + tap_907);
			t_sample tap_900 = m_delay_7.read_linear(mul_895);
			t_sample mul_898 = (tap_900 * (-1));
			t_sample add_897 = (gen_908 + mul_898);
			t_sample mul_896 = (add_897 * ((t_sample)0.7));
			t_sample gen_901 = (mul_896 + tap_900);
			t_sample tap_892 = m_delay_8.read_step(((int)3374));
			t_sample mul_890 = (tap_892 * (-1));
			t_sample add_893 = (gen_901 + mul_890);
			t_sample mul_889 = (add_893 * ((t_sample)0.773));
			t_sample tap_886 = m_delay_9.read_step(((int)3202));
			t_sample mul_884 = (tap_886 * (-1));
			t_sample add_887 = (gen_901 + mul_884);
			t_sample mul_883 = (add_887 * ((t_sample)0.802));
			t_sample tap_880 = m_delay_10.read_step(((int)4106));
			t_sample mul_878 = (tap_880 * (-1));
			t_sample add_881 = (gen_901 + mul_878);
			t_sample mul_877 = (add_881 * ((t_sample)0.753));
			t_sample tap_874 = m_delay_11.read_step(((int)4502));
			t_sample mul_872 = (tap_874 * (-1));
			t_sample add_875 = (gen_901 + mul_872);
			t_sample mul_871 = (add_875 * ((t_sample)0.733));
			t_sample add_865 = (mul_883 + mul_871);
			t_sample mul_863 = (add_865 * (-1));
			t_sample add_866 = (mul_889 + mul_877);
			t_sample mul_864 = (add_866 * (-1));
			t_sample mul_853 = ((add_866 + mul_863) * sqrt_846);
			t_sample add_848 = (mul_849 + mul_853);
			t_sample out1 = (gate_860 + add_848);
			t_sample mul_852 = ((mul_864 + add_865) * sqrt_846);
			t_sample add_847 = (mul_849 + mul_852);
			t_sample out2 = (gate_860 + add_847);
			m_history_4 = history_856_next_858;
			m_delay_11.write(mul_871);
			m_delay_10.write(mul_877);
			m_delay_9.write(mul_883);
			m_delay_8.write(mul_889);
			m_delay_7.write(mul_896);
			m_delay_6.write(mul_903);
			m_delay_5.write(mul_910);
			m_delay_5.step();
			m_delay_6.step();
			m_delay_7.step();
			m_delay_8.step();
			m_delay_9.step();
			m_delay_10.step();
			m_delay_11.step();
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
		m_sw_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_wetdry(t_param _value) {
		m_knob4_wetdry_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_size(t_param _value) {
		m_knob3_size_3 = (_value < 1 ? 1 : (_value > 100 ? 100 : _value));
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
int num_params() { return 3; }

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
		case 0: self->set_knob3_size(value); break;
		case 1: self->set_knob4_wetdry(value); break;
		case 2: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_size_3; break;
		case 1: *value = self->m_knob4_wetdry_2; break;
		case 2: *value = self->m_sw_1; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(3 * sizeof(ParamInfo));
	self->__commonstate.numparams = 3;
	// initialize parameter 0 ("m_knob3_size_3")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_size";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_size_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_wetdry_2")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_wetdry_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_sw_1")
	pi = self->__commonstate.params + 2;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_1;
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


} // Reverb::
