#include "Parametric.h"

namespace Parametric {

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
	Sah __m_sah_19;
	int vectorsize;
	int __exception;
	t_sample m_history_1;
	t_sample m_history_13;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_history_14;
	t_sample m_knob5_Q_16;
	t_sample m_sw_15;
	t_sample m_knob3_pitch_17;
	t_sample samplerate;
	t_sample m_history_10;
	t_sample m_knob4_gain_18;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample m_history_9;
	t_sample m_history_4;
	t_sample m_history_6;
	t_sample m_history_5;
	t_sample m_history_7;
	t_sample m_history_8;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
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
		m_knob5_Q_16 = ((int)0);
		m_knob3_pitch_17 = 23;
		m_knob4_gain_18 = 0.5;
		__m_sah_19.reset(0);
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
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_1974 = __m_sah_19(m_history_14, m_sw_15, ((int)0));
			t_sample gen_1976 = sah_1974;
			t_sample rsub_1972 = (((int)1) - sah_1974);
			t_sample history_1973_next_1975 = fixdenorm(rsub_1972);
			t_sample out3 = gen_1976;
			t_sample mix_2058 = (m_history_13 + (((t_sample)0.003926980723806) * (m_knob5_Q_16 - m_history_13)));
			t_sample mix_1930 = mix_2058;
			t_sample mix_2059 = (m_history_12 + (((t_sample)0.003926980723806) * (mix_1930 - m_history_12)));
			t_sample mix_1928 = mix_2059;
			t_sample mix_2060 = (m_history_11 + (((t_sample)0.003926980723806) * (mix_1928 - m_history_11)));
			t_sample mix_1926 = mix_2060;
			t_sample gen_1937 = mix_1926;
			t_sample history_1931_next_1933 = fixdenorm(mix_1930);
			t_sample history_1929_next_1934 = fixdenorm(mix_1928);
			t_sample history_1927_next_1935 = fixdenorm(mix_1926);
			t_sample expr_1979 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_1937)))));
			t_sample add_1977 = (gen_1976 + ((int)1));
			t_sample choice_20 = int(add_1977);
			t_sample gate_1970 = (((choice_20 >= 1) && (choice_20 < 2)) ? in1 : 0);
			t_sample gate_1971 = ((choice_20 >= 2) ? in1 : 0);
			t_sample mul_1924 = (expr_1979 * ((int)30));
			t_sample mix_2061 = (m_history_10 + (((t_sample)0.003926980723806) * (m_knob3_pitch_17 - m_history_10)));
			t_sample mix_1984 = mix_2061;
			t_sample mix_2062 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_1984 - m_history_9)));
			t_sample mix_1989 = mix_2062;
			t_sample mix_2063 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_1989 - m_history_8)));
			t_sample mix_1981 = mix_2063;
			t_sample gen_1969 = mix_1981;
			t_sample history_1931_next_1983 = fixdenorm(mix_1984);
			t_sample history_1929_next_1985 = fixdenorm(mix_1989);
			t_sample history_1927_next_1987 = fixdenorm(mix_1981);
			t_sample mtof_1968 = mtof(gen_1969, ((int)440));
			t_sample mix_2064 = (m_history_7 + (((t_sample)0.003926980723806) * (m_knob4_gain_18 - m_history_7)));
			t_sample mix_1994 = mix_2064;
			t_sample mix_2065 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_1994 - m_history_6)));
			t_sample mix_2001 = mix_2065;
			t_sample mix_2066 = (m_history_5 + (((t_sample)0.003926980723806) * (mix_2001 - m_history_5)));
			t_sample mix_1993 = mix_2066;
			t_sample gen_1936 = mix_1993;
			t_sample history_1931_next_2000 = fixdenorm(mix_1994);
			t_sample history_1929_next_1995 = fixdenorm(mix_2001);
			t_sample history_1927_next_1998 = fixdenorm(mix_1993);
			int gt_1923 = (gen_1936 > ((t_sample)0.5));
			t_sample sub_2070 = (gen_1936 - ((t_sample)0.5));
			t_sample scale_2067 = ((safepow((sub_2070 * ((t_sample)2)), ((int)1)) * ((int)19)) + ((int)1));
			t_sample scale_1920 = scale_2067;
			t_sample mul_1921 = (gen_1936 * ((int)2));
			t_sample switch_1922 = (gt_1923 ? scale_1920 : mul_1921);
			t_sample min_1946 = ((mtof_1968 < ((int)0)) ? ((int)0) : mtof_1968);
			t_sample min_1945 = ((switch_1922 < ((int)0)) ? ((int)0) : switch_1922);
			t_sample min_1944 = ((mul_1924 < ((t_sample)1e-06)) ? ((t_sample)1e-06) : mul_1924);
			t_sample omega = safediv((min_1946 * ((t_sample)6.2831853071796)), samplerate);
			t_sample sn = sin(omega);
			t_sample cs = cos(omega);
			t_sample alpha = safediv((sn * ((t_sample)0.5)), min_1944);
			t_sample A = sqrt(min_1945);
			t_sample one_over_A = safediv(((int)1), A);
			t_sample b0 = safediv(((int)1), (((int)1) + (alpha * one_over_A)));
			t_sample a0 = ((((int)1) + (alpha * A)) * b0);
			t_sample b1 = ((((int)-2) * cs) * b0);
			t_sample a2 = ((((int)1) - (alpha * A)) * b0);
			t_sample b2 = ((((int)1) - (alpha * one_over_A)) * b0);
			t_sample expr_1962 = a0;
			t_sample expr_1963 = b1;
			t_sample expr_1964 = a2;
			t_sample expr_1965 = b1;
			t_sample expr_1966 = b2;
			t_sample mul_1956 = (gate_1971 * expr_1962);
			t_sample mul_1953 = (m_history_2 * expr_1963);
			t_sample mul_1951 = (m_history_3 * expr_1964);
			t_sample mul_1947 = (m_history_4 * expr_1966);
			t_sample mul_1949 = (m_history_1 * expr_1965);
			t_sample sub_1955 = (((mul_1951 + mul_1953) + mul_1956) - (mul_1949 + mul_1947));
			t_sample gen_1961 = sub_1955;
			t_sample history_1948_next_1957 = fixdenorm(m_history_1);
			t_sample history_1952_next_1958 = fixdenorm(m_history_2);
			t_sample history_1954_next_1959 = fixdenorm(gate_1971);
			t_sample history_1950_next_1960 = fixdenorm(sub_1955);
			t_sample add_1978 = (gate_1970 + gen_1961);
			t_sample out1 = add_1978;
			t_sample out2 = add_1978;
			m_history_14 = history_1973_next_1975;
			m_history_13 = history_1931_next_1933;
			m_history_11 = history_1927_next_1935;
			m_history_12 = history_1929_next_1934;
			m_history_10 = history_1931_next_1983;
			m_history_8 = history_1927_next_1987;
			m_history_9 = history_1929_next_1985;
			m_history_7 = history_1931_next_2000;
			m_history_5 = history_1927_next_1998;
			m_history_6 = history_1929_next_1995;
			m_history_4 = history_1948_next_1957;
			m_history_3 = history_1952_next_1958;
			m_history_2 = history_1954_next_1959;
			m_history_1 = history_1950_next_1960;
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
	inline void set_knob5_Q(t_param _value) {
		m_knob5_Q_16 = (_value < 0.001 ? 0.001 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_pitch(t_param _value) {
		m_knob3_pitch_17 = (_value < 60 ? 60 : (_value > 127 ? 127 : _value));
	};
	inline void set_knob4_gain(t_param _value) {
		m_knob4_gain_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 4; }

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
		case 0: self->set_knob3_pitch(value); break;
		case 1: self->set_knob4_gain(value); break;
		case 2: self->set_knob5_Q(value); break;
		case 3: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_pitch_17; break;
		case 1: *value = self->m_knob4_gain_18; break;
		case 2: *value = self->m_knob5_Q_16; break;
		case 3: *value = self->m_sw_15; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(4 * sizeof(ParamInfo));
	self->__commonstate.numparams = 4;
	// initialize parameter 0 ("m_knob3_pitch_17")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_pitch";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_pitch_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 60;
	pi->outputmax = 127;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_gain_18")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_gain";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_gain_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_Q_16")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_Q";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_Q_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.001;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_sw_15")
	pi = self->__commonstate.params + 3;
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Parametric::
