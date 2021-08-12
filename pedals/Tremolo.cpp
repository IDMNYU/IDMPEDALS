#include "Tremolo.h"

namespace Tremolo {

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
	Phasor __m_phasor_12;
	Sah __m_sah_10;
	SineCycle __m_cycle_13;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_sw_8;
	t_sample samples_to_seconds;
	t_sample m_history_9;
	t_sample m_knob4_rate_7;
	t_sample m_knob3_depth_6;
	t_sample m_knob5_shape_4;
	t_sample samplerate;
	t_sample m_sw_5;
	t_sample m_history_1;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample __m_slide_15;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_knob5_shape_4 = 1;
		m_sw_5 = ((int)0);
		m_knob3_depth_6 = 1;
		m_knob4_rate_7 = 0.1;
		m_sw_8 = ((int)0);
		m_history_9 = ((int)0);
		__m_sah_10.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_12.reset(0);
		__m_cycle_13.reset(samplerate, 0);
		__m_slide_15 = 0;
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
		t_sample mstosamps_1891 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_1890 = (((int)100) * (samplerate * 0.001));
		samples_to_seconds = (1 / samplerate);
		int min_14 = (-1);
		t_sample iup_16 = (1 / maximum(1, abs(mstosamps_1891)));
		t_sample idown_17 = (1 / maximum(1, abs(mstosamps_1890)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_1920 = __m_sah_10(m_history_9, m_sw_8, ((int)0));
			t_sample gen_1922 = sah_1920;
			t_sample rsub_1918 = (((int)1) - sah_1920);
			t_sample history_1919_next_1921 = fixdenorm(rsub_1918);
			t_sample out3 = gen_1922;
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample mix_1945 = (m_history_3 + (((t_sample)0.0019634941468452) * (m_knob4_rate_7 - m_history_3)));
			t_sample mix_1908 = mix_1945;
			t_sample mix_1946 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_1908 - m_history_2)));
			t_sample mix_1906 = mix_1946;
			t_sample mix_1947 = (m_history_1 + (((t_sample)0.0019634941468452) * (mix_1906 - m_history_1)));
			t_sample mix_1904 = mix_1947;
			t_sample gen_1914 = mix_1904;
			t_sample history_1909_next_1911 = fixdenorm(mix_1908);
			t_sample history_1907_next_1912 = fixdenorm(mix_1906);
			t_sample history_1905_next_1913 = fixdenorm(mix_1904);
			t_sample expr_1930 = (((int)1) - sqrt((((int)1) - gen_1914)));
			t_sample add_1923 = (gen_1922 + ((int)1));
			t_sample choice_11 = int(add_1923);
			t_sample gate_1916 = (((choice_11 >= 1) && (choice_11 < 2)) ? in1 : 0);
			t_sample gate_1917 = ((choice_11 >= 2) ? in1 : 0);
			t_sample mul_1929 = (expr_1930 * ((int)12));
			t_sample phasor_1928 = __m_phasor_12(mul_1929, samples_to_seconds);
			__m_cycle_13.phase(phasor_1928);
			t_sample cycle_1902 = __m_cycle_13(__sinedata);
			t_sample cycleindex_1903 = __m_cycle_13.phase();
			t_sample mul_1897 = (cycle_1902 * m_knob5_shape_4);
			t_sample clamp_1898 = ((mul_1897 <= min_14) ? min_14 : ((mul_1897 >= ((int)1)) ? ((int)1) : mul_1897));
			t_sample sub_1951 = (clamp_1898 - (-1));
			t_sample scale_1948 = ((safepow((sub_1951 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample switch_1894 = (m_sw_5 ? gate_1917 : ((int)1));
			t_sample abs_1896 = fabs(switch_1894);
			t_sample mul_1887 = (abs_1896 * ((int)100));
			__m_slide_15 = fixdenorm((__m_slide_15 + (((mul_1887 > __m_slide_15) ? iup_16 : idown_17) * (mul_1887 - __m_slide_15))));
			t_sample slide_1895 = __m_slide_15;
			t_sample clamp_1892 = ((slide_1895 <= ((int)0)) ? ((int)0) : ((slide_1895 >= ((int)1)) ? ((int)1) : slide_1895));
			t_sample mul_1915 = (m_knob3_depth_6 * clamp_1892);
			t_sample mul_1900 = (scale_1948 * mul_1915);
			t_sample rsub_1899 = (((int)1) - mul_1900);
			t_sample mul_1924 = (gate_1917 * rsub_1899);
			t_sample add_1926 = (gate_1916 + mul_1924);
			t_sample out2 = add_1926;
			t_sample mul_1925 = (gate_1917 * rsub_1899);
			t_sample add_1927 = (gate_1916 + mul_1925);
			t_sample out1 = add_1927;
			m_history_9 = history_1919_next_1921;
			m_history_3 = history_1909_next_1911;
			m_history_1 = history_1905_next_1913;
			m_history_2 = history_1907_next_1912;
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
	inline void set_knob5_shape(t_param _value) {
		m_knob5_shape_4 = (_value < 1 ? 1 : (_value > 10 ? 10 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_7 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_8 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 5; }

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
		case 2: self->set_knob5_shape(value); break;
		case 3: self->set_sw1(value); break;
		case 4: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_depth_6; break;
		case 1: *value = self->m_knob4_rate_7; break;
		case 2: *value = self->m_knob5_shape_4; break;
		case 3: *value = self->m_sw_8; break;
		case 4: *value = self->m_sw_5; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(5 * sizeof(ParamInfo));
	self->__commonstate.numparams = 5;
	// initialize parameter 0 ("m_knob3_depth_6")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_7")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_7;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_shape_4")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_shape";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_shape_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 10;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_sw_8")
	pi = self->__commonstate.params + 3;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_5")
	pi = self->__commonstate.params + 4;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_5;
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


} // Tremolo::
