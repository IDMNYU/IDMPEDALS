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
	t_sample m_sw_16;
	t_sample m_knob4_depth_15;
	t_sample m_sw_14;
	t_sample m_knob5_rate_17;
	t_sample m_knob6_res_19;
	t_sample m_knob3_manual_18;
	t_sample m_history_4;
	t_sample m_history_13;
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
		m_delay_1.reset("m_delay_1", ((int)3840));
		m_delay_2.reset("m_delay_2", ((int)3940));
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
		m_history_13 = ((int)0);
		m_sw_14 = ((int)0);
		m_knob4_depth_15 = ((int)0);
		m_sw_16 = ((int)0);
		m_knob5_rate_17 = ((int)0);
		m_knob3_manual_18 = ((int)0);
		m_knob6_res_19 = ((int)0);
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
		t_sample sqrt_1833 = sqrt(m_knob6_res_19);
		t_sample sqrt_1842 = sqrt(sqrt_1833);
		t_sample mul_1854 = (sqrt_1842 * ((t_sample)0.99));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample mix_1909 = (m_history_13 + (((t_sample)0.003926980723806) * (m_knob5_rate_17 - m_history_13)));
			t_sample mix_1815 = mix_1909;
			t_sample mix_1910 = (m_history_12 + (((t_sample)0.003926980723806) * (mix_1815 - m_history_12)));
			t_sample mix_1813 = mix_1910;
			t_sample mix_1911 = (m_history_11 + (((t_sample)0.003926980723806) * (mix_1813 - m_history_11)));
			t_sample mix_1811 = mix_1911;
			t_sample gen_1822 = mix_1811;
			t_sample history_1816_next_1818 = fixdenorm(mix_1815);
			t_sample history_1814_next_1819 = fixdenorm(mix_1813);
			t_sample history_1812_next_1820 = fixdenorm(mix_1811);
			t_sample expr_1860 = (((int)1) - sqrt(sqrt((((int)1) - gen_1822))));
			t_sample sah_1836 = __m_sah_20(m_history_10, m_sw_14, ((int)0));
			t_sample gen_1838 = sah_1836;
			t_sample rsub_1834 = (((int)1) - sah_1836);
			t_sample history_1835_next_1837 = fixdenorm(rsub_1834);
			t_sample out3 = gen_1838;
			t_sample mix_1912 = (m_history_9 + (((t_sample)0.003926980723806) * (m_knob3_manual_18 - m_history_9)));
			t_sample mix_1866 = mix_1912;
			t_sample mix_1913 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_1866 - m_history_8)));
			t_sample mix_1864 = mix_1913;
			t_sample mix_1914 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_1864 - m_history_7)));
			t_sample mix_1870 = mix_1914;
			t_sample gen_1823 = mix_1870;
			t_sample history_1816_next_1869 = fixdenorm(mix_1866);
			t_sample history_1814_next_1867 = fixdenorm(mix_1864);
			t_sample history_1812_next_1862 = fixdenorm(mix_1870);
			t_sample expr_1859 = (((int)1) - sqrt((((int)1) - gen_1823)));
			t_sample add_1841 = (gen_1838 + ((int)1));
			t_sample choice_21 = int(add_1841);
			t_sample gate_1839 = (((choice_21 >= 1) && (choice_21 < 2)) ? in1 : 0);
			t_sample gate_1840 = ((choice_21 >= 2) ? in1 : 0);
			t_sample mul_1856 = (expr_1859 * ((int)1920));
			t_sample tap_1832 = m_delay_6.read_linear(mul_1856);
			t_sample switch_1830 = (m_sw_16 ? tap_1832 : gate_1840);
			t_sample mul_1845 = (expr_1860 * ((int)10));
			__m_cycle_22.freq(mul_1845);
			t_sample cycle_1846 = __m_cycle_22(__sinedata);
			t_sample cycleindex_1847 = __m_cycle_22.phase();
			t_sample mix_1915 = (m_history_5 + (((t_sample)0.003926980723806) * (m_knob4_depth_15 - m_history_5)));
			t_sample mix_1883 = mix_1915;
			t_sample mix_1916 = (m_history_4 + (((t_sample)0.003926980723806) * (mix_1883 - m_history_4)));
			t_sample mix_1875 = mix_1916;
			t_sample mix_1917 = (m_history_3 + (((t_sample)0.003926980723806) * (mix_1875 - m_history_3)));
			t_sample mix_1878 = mix_1917;
			t_sample gen_1821 = mix_1878;
			t_sample history_1816_next_1877 = fixdenorm(mix_1883);
			t_sample history_1814_next_1879 = fixdenorm(mix_1875);
			t_sample history_1812_next_1874 = fixdenorm(mix_1878);
			t_sample mul_1850 = (gen_1821 * mul_1856);
			t_sample mul_1844 = (cycle_1846 * mul_1850);
			t_sample add_1848 = (mul_1856 + mul_1844);
			t_sample clamp_1849 = ((add_1848 <= ((int)0)) ? ((int)0) : ((add_1848 >= ((int)3940)) ? ((int)3940) : add_1848));
			t_sample tap_1853 = m_delay_2.read_linear(clamp_1849);
			t_sample add_1828 = (switch_1830 + tap_1853);
			t_sample div_1826 = (add_1828 * ((t_sample)0.5));
			t_sample out2 = (div_1826 + gate_1839);
			t_sample mul_1851 = (tap_1853 * mul_1854);
			t_sample tap_1858 = m_delay_1.read_linear(clamp_1849);
			t_sample add_1829 = (switch_1830 + tap_1858);
			t_sample div_1827 = (add_1829 * ((t_sample)0.5));
			t_sample out1 = (div_1827 + gate_1839);
			t_sample mul_1855 = (tap_1858 * mul_1854);
			m_history_13 = history_1816_next_1818;
			m_history_11 = history_1812_next_1820;
			m_history_12 = history_1814_next_1819;
			m_history_10 = history_1835_next_1837;
			m_history_9 = history_1816_next_1869;
			m_history_7 = history_1812_next_1862;
			m_history_8 = history_1814_next_1867;
			m_delay_6.write(gate_1840);
			m_history_5 = history_1816_next_1877;
			m_history_3 = history_1812_next_1874;
			m_history_4 = history_1814_next_1879;
			m_delay_2.write(mul_1855);
			m_delay_1.write((mul_1851 + gate_1840));
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
	inline void set_sw1(t_param _value) {
		m_sw_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_depth(t_param _value) {
		m_knob4_depth_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_rate(t_param _value) {
		m_knob5_rate_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_manual(t_param _value) {
		m_knob3_manual_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_res(t_param _value) {
		m_knob6_res_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_manual_18; break;
		case 1: *value = self->m_knob4_depth_15; break;
		case 2: *value = self->m_knob5_rate_17; break;
		case 3: *value = self->m_knob6_res_19; break;
		case 4: *value = self->m_sw_14; break;
		case 5: *value = self->m_sw_16; break;
		
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
	// initialize parameter 0 ("m_knob3_manual_18")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_manual";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_manual_18;
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
	// initialize parameter 2 ("m_knob5_rate_17")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_rate_17;
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
	// initialize parameter 4 ("m_sw_14")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_16")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_16;
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
