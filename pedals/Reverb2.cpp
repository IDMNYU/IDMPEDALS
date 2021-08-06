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
	t_sample m_knob1_wetdry_3;
	t_sample m_history_11;
	t_sample m_knob4_fb_2;
	t_sample m_sw_1;
	t_sample samplerate;
	t_sample m_knob3_damp_4;
	t_sample m_history_13;
	t_sample m_knob6_spread_5;
	t_sample m_knob5_fb_6;
	t_sample m_history_9;
	t_sample m_history_17;
	t_sample m_history_23;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample m_history_7;
	t_sample m_history_15;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_sw_1 = ((int)0);
		m_knob4_fb_2 = ((t_sample)0.9);
		m_knob1_wetdry_3 = ((int)0);
		m_knob3_damp_4 = ((t_sample)0.5);
		m_knob6_spread_5 = ((int)0);
		m_knob5_fb_6 = ((t_sample)0.5);
		m_history_7 = ((int)0);
		m_delay_8.reset("m_delay_8", ((int)2000));
		m_history_9 = ((int)0);
		m_delay_10.reset("m_delay_10", ((int)2000));
		m_history_11 = ((int)0);
		m_delay_12.reset("m_delay_12", ((int)2000));
		m_history_13 = ((int)0);
		m_delay_14.reset("m_delay_14", ((int)2000));
		m_history_15 = ((int)0);
		m_delay_16.reset("m_delay_16", ((int)2000));
		m_history_17 = ((int)0);
		m_delay_18.reset("m_delay_18", ((int)2000));
		m_history_19 = ((int)0);
		m_delay_20.reset("m_delay_20", ((int)2000));
		m_history_21 = ((int)0);
		m_delay_22.reset("m_delay_22", ((int)2000));
		m_history_23 = ((int)0);
		m_delay_24.reset("m_delay_24", ((int)2000));
		m_delay_25.reset("m_delay_25", ((int)2000));
		m_delay_26.reset("m_delay_26", ((int)2000));
		m_delay_27.reset("m_delay_27", ((int)2000));
		m_delay_28.reset("m_delay_28", ((int)2000));
		m_delay_29.reset("m_delay_29", ((int)2000));
		m_delay_30.reset("m_delay_30", ((int)2000));
		m_delay_31.reset("m_delay_31", ((int)2000));
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
		t_sample sqrt_1845 = sqrt(m_knob1_wetdry_3);
		t_sample rsub_1849 = (((int)1) - m_knob1_wetdry_3);
		t_sample sqrt_1848 = sqrt(rsub_1849);
		t_sample mul_1844 = (m_knob5_fb_6 * ((t_sample)0.5));
		t_sample mul_1899 = (m_knob5_fb_6 * ((t_sample)0.5));
		t_sample add_1839 = (((int)228) + m_knob6_spread_5);
		t_sample add_1885 = (((int)225) + m_knob6_spread_5);
		t_sample add_1841 = (((int)338) + m_knob6_spread_5);
		t_sample add_1887 = (((int)341) + m_knob6_spread_5);
		t_sample add_1843 = (((int)444) + m_knob6_spread_5);
		t_sample add_1897 = (((int)441) + m_knob6_spread_5);
		t_sample add_1837 = (((int)553) + m_knob6_spread_5);
		t_sample add_1883 = (((int)556) + m_knob6_spread_5);
		t_sample add_1890 = (((int)1557) + m_knob6_spread_5);
		t_sample rsub_1852 = (((int)1) - m_knob3_damp_4);
		t_sample add_1889 = (((int)1617) + m_knob6_spread_5);
		t_sample rsub_1919 = (((int)1) - m_knob3_damp_4);
		t_sample add_1891 = (((int)1491) + m_knob6_spread_5);
		t_sample rsub_1927 = (((int)1) - m_knob3_damp_4);
		t_sample add_1892 = (((int)1422) + m_knob6_spread_5);
		t_sample rsub_1945 = (((int)1) - m_knob3_damp_4);
		t_sample add_1893 = (((int)1356) + m_knob6_spread_5);
		t_sample rsub_1951 = (((int)1) - m_knob3_damp_4);
		t_sample add_1894 = (((int)1277) + m_knob6_spread_5);
		t_sample rsub_1969 = (((int)1) - m_knob3_damp_4);
		t_sample add_1895 = (((int)1188) + m_knob6_spread_5);
		t_sample rsub_1977 = (((int)1) - m_knob3_damp_4);
		t_sample add_1896 = (((int)1116) + m_knob6_spread_5);
		t_sample rsub_1993 = (((int)1) - m_knob3_damp_4);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_1906 = __m_sah_32(m_history_7, m_sw_1, ((int)0));
			t_sample gen_1908 = sah_1906;
			t_sample rsub_1904 = (((int)1) - sah_1906);
			t_sample history_1905_next_1907 = fixdenorm(rsub_1904);
			t_sample out3 = gen_1908;
			t_sample add_1911 = (gen_1908 + ((int)1));
			t_sample choice_33 = int(add_1911);
			t_sample gate_1909 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_1910 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_1847 = (gate_1910 * sqrt_1848);
			t_sample mul_1901 = (gate_1910 * ((t_sample)0.015));
			t_sample tap_1859 = m_delay_8.read_linear(add_1890);
			t_sample gen_1881 = tap_1859;
			t_sample mul_1857 = (tap_1859 * m_knob3_damp_4);
			t_sample mul_1855 = (m_history_9 * rsub_1852);
			t_sample add_1856 = (mul_1857 + mul_1855);
			t_sample mul_1853 = (add_1856 * m_knob4_fb_2);
			t_sample add_1860 = (mul_1901 + mul_1853);
			t_sample history_1854_next_1861 = fixdenorm(add_1856);
			t_sample tap_1921 = m_delay_10.read_linear(add_1889);
			t_sample gen_1900 = tap_1921;
			t_sample mul_1914 = (tap_1921 * m_knob3_damp_4);
			t_sample mul_1920 = (m_history_11 * rsub_1919);
			t_sample add_1918 = (mul_1914 + mul_1920);
			t_sample mul_1917 = (add_1918 * m_knob4_fb_2);
			t_sample add_1916 = (mul_1901 + mul_1917);
			t_sample history_1854_next_1915 = fixdenorm(add_1918);
			t_sample tap_1930 = m_delay_12.read_linear(add_1891);
			t_sample gen_1880 = tap_1930;
			t_sample mul_1926 = (tap_1930 * m_knob3_damp_4);
			t_sample mul_1928 = (m_history_13 * rsub_1927);
			t_sample add_1933 = (mul_1926 + mul_1928);
			t_sample mul_1925 = (add_1933 * m_knob4_fb_2);
			t_sample add_1932 = (mul_1901 + mul_1925);
			t_sample history_1854_next_1931 = fixdenorm(add_1933);
			t_sample tap_1940 = m_delay_14.read_linear(add_1892);
			t_sample gen_1879 = tap_1940;
			t_sample mul_1938 = (tap_1940 * m_knob3_damp_4);
			t_sample mul_1939 = (m_history_15 * rsub_1945);
			t_sample add_1944 = (mul_1938 + mul_1939);
			t_sample mul_1937 = (add_1944 * m_knob4_fb_2);
			t_sample add_1943 = (mul_1901 + mul_1937);
			t_sample history_1854_next_1942 = fixdenorm(add_1944);
			t_sample tap_1956 = m_delay_16.read_linear(add_1893);
			t_sample gen_1878 = tap_1956;
			t_sample mul_1950 = (tap_1956 * m_knob3_damp_4);
			t_sample mul_1953 = (m_history_17 * rsub_1951);
			t_sample add_1957 = (mul_1950 + mul_1953);
			t_sample mul_1949 = (add_1957 * m_knob4_fb_2);
			t_sample add_1952 = (mul_1901 + mul_1949);
			t_sample history_1854_next_1955 = fixdenorm(add_1957);
			t_sample tap_1967 = m_delay_18.read_linear(add_1894);
			t_sample gen_1877 = tap_1967;
			t_sample mul_1962 = (tap_1967 * m_knob3_damp_4);
			t_sample mul_1966 = (m_history_19 * rsub_1969);
			t_sample add_1968 = (mul_1962 + mul_1966);
			t_sample mul_1961 = (add_1968 * m_knob4_fb_2);
			t_sample add_1964 = (mul_1901 + mul_1961);
			t_sample history_1854_next_1965 = fixdenorm(add_1968);
			t_sample tap_1981 = m_delay_20.read_linear(add_1895);
			t_sample gen_1876 = tap_1981;
			t_sample mul_1976 = (tap_1981 * m_knob3_damp_4);
			t_sample mul_1980 = (m_history_21 * rsub_1977);
			t_sample add_1975 = (mul_1976 + mul_1980);
			t_sample mul_1974 = (add_1975 * m_knob4_fb_2);
			t_sample add_1979 = (mul_1901 + mul_1974);
			t_sample history_1854_next_1978 = fixdenorm(add_1975);
			t_sample tap_1992 = m_delay_22.read_linear(add_1896);
			t_sample gen_1875 = tap_1992;
			t_sample mul_1987 = (tap_1992 * m_knob3_damp_4);
			t_sample mul_1991 = (m_history_23 * rsub_1993);
			t_sample add_1986 = (mul_1987 + mul_1991);
			t_sample mul_1990 = (add_1986 * m_knob4_fb_2);
			t_sample add_1984 = (mul_1901 + mul_1990);
			t_sample history_1854_next_1988 = fixdenorm(add_1986);
			t_sample pass_1898 = (((((((gen_1875 + gen_1876) + gen_1877) + gen_1878) + gen_1879) + gen_1880) + gen_1900) + gen_1881);
			t_sample tap_1835 = m_delay_24.read_linear(add_1837);
			t_sample sub_1831 = (pass_1898 - tap_1835);
			t_sample mul_1833 = (tap_1835 * mul_1844);
			t_sample add_1832 = (pass_1898 + mul_1833);
			t_sample tap_1997 = m_delay_25.read_linear(add_1843);
			t_sample sub_1998 = (sub_1831 - tap_1997);
			t_sample mul_1999 = (tap_1997 * mul_1844);
			t_sample add_2000 = (sub_1831 + mul_1999);
			t_sample tap_2003 = m_delay_26.read_linear(add_1841);
			t_sample sub_2004 = (sub_1998 - tap_2003);
			t_sample mul_2005 = (tap_2003 * mul_1844);
			t_sample add_2006 = (sub_1998 + mul_2005);
			t_sample tap_2009 = m_delay_27.read_linear(add_1839);
			t_sample sub_2010 = (sub_2004 - tap_2009);
			t_sample mul_2011 = (tap_2009 * mul_1844);
			t_sample add_2012 = (sub_2004 + mul_2011);
			t_sample mul_1826 = (sub_2010 * sqrt_1845);
			t_sample add_1825 = (mul_1847 + mul_1826);
			t_sample out2 = (add_1825 + gate_1909);
			t_sample tap_2015 = m_delay_28.read_linear(add_1883);
			t_sample sub_2016 = (pass_1898 - tap_2015);
			t_sample mul_2017 = (tap_2015 * mul_1899);
			t_sample add_2018 = (pass_1898 + mul_2017);
			t_sample tap_2021 = m_delay_29.read_linear(add_1897);
			t_sample sub_2022 = (sub_2016 - tap_2021);
			t_sample mul_2023 = (tap_2021 * mul_1899);
			t_sample add_2024 = (sub_2016 + mul_2023);
			t_sample tap_2027 = m_delay_30.read_linear(add_1887);
			t_sample sub_2028 = (sub_2022 - tap_2027);
			t_sample mul_2029 = (tap_2027 * mul_1899);
			t_sample add_2030 = (sub_2022 + mul_2029);
			t_sample tap_2033 = m_delay_31.read_linear(add_1885);
			t_sample sub_2034 = (sub_2028 - tap_2033);
			t_sample mul_2035 = (tap_2033 * mul_1899);
			t_sample add_2036 = (sub_2028 + mul_2035);
			t_sample mul_1850 = (sub_2034 * sqrt_1845);
			t_sample add_1846 = (mul_1847 + mul_1850);
			t_sample out1 = (gate_1909 + add_1846);
			m_history_7 = history_1905_next_1907;
			m_delay_31.write(add_2036);
			m_delay_30.write(add_2030);
			m_delay_29.write(add_2024);
			m_delay_28.write(add_2018);
			m_delay_27.write(add_2012);
			m_delay_26.write(add_2006);
			m_delay_25.write(add_2000);
			m_delay_24.write(add_1832);
			m_history_23 = history_1854_next_1988;
			m_delay_22.write(add_1984);
			m_history_21 = history_1854_next_1978;
			m_delay_20.write(add_1979);
			m_history_19 = history_1854_next_1965;
			m_delay_18.write(add_1964);
			m_history_17 = history_1854_next_1955;
			m_delay_16.write(add_1952);
			m_history_15 = history_1854_next_1942;
			m_delay_14.write(add_1943);
			m_history_13 = history_1854_next_1931;
			m_delay_12.write(add_1932);
			m_history_11 = history_1854_next_1915;
			m_delay_10.write(add_1916);
			m_history_9 = history_1854_next_1861;
			m_delay_8.write(add_1860);
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
	inline void set_sw1(t_param _value) {
		m_sw_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_5 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
	};
	inline void set_knob5_fb2(t_param _value) {
		m_knob5_fb_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob1_wetdry_3; break;
		case 1: *value = self->m_knob3_damp_4; break;
		case 2: *value = self->m_knob4_fb_2; break;
		case 3: *value = self->m_knob5_fb_6; break;
		case 4: *value = self->m_knob6_spread_5; break;
		case 5: *value = self->m_sw_1; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_3")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_damp_4")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_fb_2")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_fb_6")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_spread_5")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_1")
	pi = self->__commonstate.params + 5;
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


} // Reverb2::
