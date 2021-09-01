#include "Phaser.h"

namespace Phaser {

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
	DCBlock __m_dcblock_64;
	DCBlock __m_dcblock_49;
	Phasor __m_phasor_31;
	Sah __m_sah_29;
	SineCycle __m_cycle_57;
	SineCycle __m_cycle_50;
	SineCycle __m_cycle_42;
	SineCycle __m_cycle_35;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_4;
	t_sample m_history_8;
	t_sample m_history_3;
	t_sample __m_slide_32;
	t_sample m_history_5;
	t_sample samples_to_seconds;
	t_sample __m_slide_36;
	t_sample m_history_6;
	t_sample __m_slide_39;
	t_sample m_history_2;
	t_sample __m_slide_43;
	t_sample __m_slide_54;
	t_sample __m_slide_58;
	t_sample m_knob4_rate_28;
	t_sample __m_slide_51;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_slide_46;
	t_sample m_history_7;
	t_sample m_sw_27;
	t_sample m_knob3_depth_25;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_12;
	t_sample m_history_10;
	t_sample m_history_11;
	t_sample m_history_9;
	t_sample m_sw_26;
	t_sample m_history_16;
	t_sample m_history_18;
	t_sample m_knob5_fb_23;
	t_sample m_knob6_diffusion_24;
	t_sample m_history_17;
	t_sample __m_slide_61;
	t_sample m_history_20;
	t_sample m_history_21;
	t_sample m_history_19;
	t_sample m_history_22;
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
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_knob5_fb_23 = ((int)0);
		m_knob6_diffusion_24 = 1;
		m_knob3_depth_25 = 1;
		m_sw_26 = ((int)0);
		m_sw_27 = ((int)0);
		m_knob4_rate_28 = 0.1;
		__m_sah_29.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_31.reset(0);
		__m_slide_32 = 0;
		__m_cycle_35.reset(samplerate, 0);
		__m_slide_36 = 0;
		__m_slide_39 = 0;
		__m_cycle_42.reset(samplerate, 0);
		__m_slide_43 = 0;
		__m_slide_46 = 0;
		__m_dcblock_49.reset();
		__m_cycle_50.reset(samplerate, 0);
		__m_slide_51 = 0;
		__m_slide_54 = 0;
		__m_cycle_57.reset(samplerate, 0);
		__m_slide_58 = 0;
		__m_slide_61 = 0;
		__m_dcblock_64.reset();
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
		t_sample sub_2120 = (m_knob5_fb_23 - ((t_sample)0.5));
		t_sample scale_2117 = ((safepow((sub_2120 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		t_sample mul_2018 = (m_knob6_diffusion_24 * ((int)2));
		t_sample div_2016 = (mul_2018 * ((t_sample)0.125));
		t_sample mul_2019 = (m_knob6_diffusion_24 * ((int)0));
		t_sample div_2017 = (mul_2019 * ((t_sample)0.125));
		t_sample mul_2011 = (m_knob6_diffusion_24 * ((int)3));
		t_sample div_2009 = (mul_2011 * ((t_sample)0.125));
		t_sample mul_2012 = (m_knob6_diffusion_24 * ((int)1));
		t_sample div_2010 = (mul_2012 * ((t_sample)0.125));
		t_sample mstosamps_1859 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_1858 = (((int)100) * (samplerate * 0.001));
		t_sample iup_33 = (1 / maximum(1, abs(mstosamps_1859)));
		t_sample idown_34 = (1 / maximum(1, abs(mstosamps_1858)));
		t_sample div_1977 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_37 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_38 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_40 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_41 = (1 / maximum(1, abs(((int)5))));
		t_sample div_2035 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_44 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)5))));
		t_sample div_1892 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_52 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)5))));
		t_sample div_1934 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample mix_2114 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob4_rate_28 - m_history_22)));
			t_sample mix_1849 = mix_2114;
			t_sample mix_2115 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_1849 - m_history_21)));
			t_sample mix_1847 = mix_2115;
			t_sample mix_2116 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_1847 - m_history_20)));
			t_sample mix_1845 = mix_2116;
			t_sample gen_1855 = mix_1845;
			t_sample history_1850_next_1852 = fixdenorm(mix_1849);
			t_sample history_1848_next_1853 = fixdenorm(mix_1847);
			t_sample history_1846_next_1854 = fixdenorm(mix_1845);
			t_sample expr_2065 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_1855)))));
			t_sample sah_1868 = __m_sah_29(m_history_19, m_sw_27, ((int)0));
			t_sample gen_1870 = sah_1868;
			t_sample rsub_1866 = (((int)1) - sah_1868);
			t_sample history_1867_next_1869 = fixdenorm(rsub_1866);
			t_sample out3 = gen_1870;
			t_sample add_1871 = (gen_1870 + ((int)1));
			t_sample choice_30 = int(add_1871);
			t_sample gate_1864 = (((choice_30 >= 1) && (choice_30 < 2)) ? in1 : 0);
			t_sample gate_1865 = ((choice_30 >= 2) ? in1 : 0);
			t_sample mul_2015 = (m_history_1 * m_knob5_fb_23);
			t_sample add_2014 = (gate_1865 + mul_2015);
			t_sample mul_2064 = (expr_2065 * ((t_sample)7.5));
			t_sample phasor_2020 = __m_phasor_31(mul_2064, samples_to_seconds);
			t_sample mul_1874 = (m_history_2 * m_knob5_fb_23);
			t_sample add_1873 = (gate_1865 + mul_1874);
			t_sample abs_1838 = fabs(gate_1865);
			t_sample mul_1837 = (abs_1838 * ((int)30));
			t_sample switch_1862 = (m_sw_26 ? mul_1837 : ((int)1));
			__m_slide_32 = fixdenorm((__m_slide_32 + (((switch_1862 > __m_slide_32) ? iup_33 : idown_34) * (switch_1862 - __m_slide_32))));
			t_sample slide_1863 = __m_slide_32;
			t_sample mul_1842 = (m_knob3_depth_25 * slide_1863);
			t_sample clamp_1861 = ((mul_1842 <= ((int)0)) ? ((int)0) : ((mul_1842 >= ((int)1)) ? ((int)1) : mul_1842));
			t_sample out4 = clamp_1861;
			t_sample add_1986 = (phasor_2020 + div_2016);
			t_sample mod_1987 = safemod(add_1986, ((int)1));
			__m_cycle_35.phase(mod_1987);
			t_sample cycle_1984 = __m_cycle_35(__sinedata);
			t_sample cycleindex_1985 = __m_cycle_35.phase();
			t_sample add_1982 = (cycle_1984 + ((int)1));
			t_sample div_1981 = (add_1982 * ((t_sample)0.5));
			t_sample mul_1983 = (div_1981 * clamp_1861);
			t_sample sub_2124 = (mul_1983 - ((int)0));
			t_sample scale_2121 = ((safepow((sub_2124 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_1988 = scale_2121;
			t_sample mtof_1989 = mtof(scale_1988, ((int)440));
			t_sample mul_1976 = (mtof_1989 * div_1977);
			t_sample cos_1974 = cos(mul_1976);
			t_sample mul_1969 = (cos_1974 * (-2));
			t_sample sin_1975 = sin(mul_1976);
			t_sample mul_1973 = (sin_1975 * ((t_sample)0.5));
			t_sample div_1972 = (mul_1973 * ((t_sample)0.33333333333333));
			t_sample rsub_1967 = (((int)1) - div_1972);
			t_sample add_1971 = (div_1972 + ((int)1));
			t_sample rdiv_1970 = safediv(((int)1), add_1971);
			t_sample mul_1968 = (rdiv_1970 * mul_1969);
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_1968 > __m_slide_36) ? iup_37 : idown_38) * (mul_1968 - __m_slide_36))));
			t_sample slide_1964 = __m_slide_36;
			t_sample gen_1978 = slide_1964;
			t_sample mul_1966 = (rdiv_1970 * rsub_1967);
			__m_slide_39 = fixdenorm((__m_slide_39 + (((mul_1966 > __m_slide_39) ? iup_40 : idown_41) * (mul_1966 - __m_slide_39))));
			t_sample slide_1963 = __m_slide_39;
			t_sample gen_1979 = slide_1963;
			t_sample mul_1999 = (add_2014 * gen_1979);
			t_sample mul_1996 = (m_history_16 * gen_1978);
			t_sample mul_1994 = (m_history_17 * ((int)1));
			t_sample mul_1990 = (m_history_18 * gen_1979);
			t_sample mul_1992 = (m_history_15 * gen_1978);
			t_sample sub_1998 = (((mul_1994 + mul_1996) + mul_1999) - (mul_1992 + mul_1990));
			t_sample gen_2004 = sub_1998;
			t_sample history_1991_next_2000 = fixdenorm(m_history_15);
			t_sample history_1995_next_2001 = fixdenorm(m_history_16);
			t_sample history_1997_next_2002 = fixdenorm(add_2014);
			t_sample history_1993_next_2003 = fixdenorm(sub_1998);
			t_sample add_2044 = (phasor_2020 + div_2017);
			t_sample mod_2045 = safemod(add_2044, ((int)1));
			__m_cycle_42.phase(mod_2045);
			t_sample cycle_2042 = __m_cycle_42(__sinedata);
			t_sample cycleindex_2043 = __m_cycle_42.phase();
			t_sample add_2040 = (cycle_2042 + ((int)1));
			t_sample div_2039 = (add_2040 * ((t_sample)0.5));
			t_sample mul_2041 = (div_2039 * clamp_1861);
			t_sample sub_2128 = (mul_2041 - ((int)0));
			t_sample scale_2125 = ((safepow((sub_2128 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_2046 = scale_2125;
			t_sample mtof_2047 = mtof(scale_2046, ((int)440));
			t_sample mul_2034 = (mtof_2047 * div_2035);
			t_sample cos_2032 = cos(mul_2034);
			t_sample mul_2027 = (cos_2032 * (-2));
			t_sample sin_2033 = sin(mul_2034);
			t_sample mul_2031 = (sin_2033 * ((t_sample)0.5));
			t_sample div_2030 = (mul_2031 * ((t_sample)0.33333333333333));
			t_sample rsub_2025 = (((int)1) - div_2030);
			t_sample add_2029 = (div_2030 + ((int)1));
			t_sample rdiv_2028 = safediv(((int)1), add_2029);
			t_sample mul_2026 = (rdiv_2028 * mul_2027);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((mul_2026 > __m_slide_43) ? iup_44 : idown_45) * (mul_2026 - __m_slide_43))));
			t_sample slide_2022 = __m_slide_43;
			t_sample gen_2036 = slide_2022;
			t_sample mul_2024 = (rdiv_2028 * rsub_2025);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((mul_2024 > __m_slide_46) ? iup_47 : idown_48) * (mul_2024 - __m_slide_46))));
			t_sample slide_2021 = __m_slide_46;
			t_sample gen_2037 = slide_2021;
			t_sample mul_2057 = (add_2014 * gen_2037);
			t_sample mul_2054 = (m_history_12 * gen_2036);
			t_sample mul_2052 = (m_history_14 * ((int)1));
			t_sample mul_2048 = (m_history_13 * gen_2037);
			t_sample mul_2050 = (m_history_11 * gen_2036);
			t_sample sub_2056 = (((mul_2052 + mul_2054) + mul_2057) - (mul_2050 + mul_2048));
			t_sample gen_2062 = sub_2056;
			t_sample history_2053_next_2058 = fixdenorm(m_history_12);
			t_sample history_2049_next_2059 = fixdenorm(m_history_11);
			t_sample history_2055_next_2060 = fixdenorm(add_2014);
			t_sample history_2051_next_2061 = fixdenorm(sub_2056);
			t_sample mul_1962 = ((gen_2062 + gen_2004) * ((t_sample)0.5));
			t_sample dcblock_2007 = __m_dcblock_49(mul_1962);
			t_sample mul_2005 = (((gate_1865 + gen_2062) + gen_2004) * scale_2117);
			t_sample div_1839 = (mul_2005 * ((t_sample)0.5));
			t_sample add_2008 = (gate_1864 + div_1839);
			t_sample out1 = add_2008;
			t_sample add_1901 = (phasor_2020 + div_2009);
			t_sample mod_1902 = safemod(add_1901, ((int)1));
			__m_cycle_50.phase(mod_1902);
			t_sample cycle_1899 = __m_cycle_50(__sinedata);
			t_sample cycleindex_1900 = __m_cycle_50.phase();
			t_sample add_1897 = (cycle_1899 + ((int)1));
			t_sample div_1896 = (add_1897 * ((t_sample)0.5));
			t_sample mul_1898 = (div_1896 * clamp_1861);
			t_sample sub_2132 = (mul_1898 - ((int)0));
			t_sample scale_2129 = ((safepow((sub_2132 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_1903 = scale_2129;
			t_sample mtof_1904 = mtof(scale_1903, ((int)440));
			t_sample mul_1891 = (mtof_1904 * div_1892);
			t_sample cos_1889 = cos(mul_1891);
			t_sample mul_1884 = (cos_1889 * (-2));
			t_sample sin_1890 = sin(mul_1891);
			t_sample mul_1888 = (sin_1890 * ((t_sample)0.5));
			t_sample div_1887 = (mul_1888 * ((t_sample)0.33333333333333));
			t_sample rsub_1882 = (((int)1) - div_1887);
			t_sample add_1886 = (div_1887 + ((int)1));
			t_sample rdiv_1885 = safediv(((int)1), add_1886);
			t_sample mul_1883 = (rdiv_1885 * mul_1884);
			__m_slide_51 = fixdenorm((__m_slide_51 + (((mul_1883 > __m_slide_51) ? iup_52 : idown_53) * (mul_1883 - __m_slide_51))));
			t_sample slide_1879 = __m_slide_51;
			t_sample gen_1893 = slide_1879;
			t_sample mul_1881 = (rdiv_1885 * rsub_1882);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((mul_1881 > __m_slide_54) ? iup_55 : idown_56) * (mul_1881 - __m_slide_54))));
			t_sample slide_1878 = __m_slide_54;
			t_sample gen_1894 = slide_1878;
			t_sample mul_1914 = (add_1873 * gen_1894);
			t_sample mul_1911 = (m_history_8 * gen_1893);
			t_sample mul_1909 = (m_history_10 * ((int)1));
			t_sample mul_1905 = (m_history_9 * gen_1894);
			t_sample mul_1907 = (m_history_7 * gen_1893);
			t_sample sub_1913 = (((mul_1909 + mul_1911) + mul_1914) - (mul_1907 + mul_1905));
			t_sample gen_1919 = sub_1913;
			t_sample history_1910_next_1915 = fixdenorm(m_history_8);
			t_sample history_1906_next_1916 = fixdenorm(m_history_7);
			t_sample history_1912_next_1917 = fixdenorm(add_1873);
			t_sample history_1908_next_1918 = fixdenorm(sub_1913);
			t_sample add_1943 = (phasor_2020 + div_2010);
			t_sample mod_1944 = safemod(add_1943, ((int)1));
			__m_cycle_57.phase(mod_1944);
			t_sample cycle_1941 = __m_cycle_57(__sinedata);
			t_sample cycleindex_1942 = __m_cycle_57.phase();
			t_sample add_1939 = (cycle_1941 + ((int)1));
			t_sample div_1938 = (add_1939 * ((t_sample)0.5));
			t_sample mul_1940 = (div_1938 * clamp_1861);
			t_sample sub_2136 = (mul_1940 - ((int)0));
			t_sample scale_2133 = ((safepow((sub_2136 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_1945 = scale_2133;
			t_sample mtof_1946 = mtof(scale_1945, ((int)440));
			t_sample mul_1933 = (mtof_1946 * div_1934);
			t_sample cos_1931 = cos(mul_1933);
			t_sample mul_1926 = (cos_1931 * (-2));
			t_sample sin_1932 = sin(mul_1933);
			t_sample mul_1930 = (sin_1932 * ((t_sample)0.5));
			t_sample div_1929 = (mul_1930 * ((t_sample)0.33333333333333));
			t_sample rsub_1924 = (((int)1) - div_1929);
			t_sample add_1928 = (div_1929 + ((int)1));
			t_sample rdiv_1927 = safediv(((int)1), add_1928);
			t_sample mul_1925 = (rdiv_1927 * mul_1926);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((mul_1925 > __m_slide_58) ? iup_59 : idown_60) * (mul_1925 - __m_slide_58))));
			t_sample slide_1921 = __m_slide_58;
			t_sample gen_1935 = slide_1921;
			t_sample mul_1923 = (rdiv_1927 * rsub_1924);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((mul_1923 > __m_slide_61) ? iup_62 : idown_63) * (mul_1923 - __m_slide_61))));
			t_sample slide_1920 = __m_slide_61;
			t_sample gen_1936 = slide_1920;
			t_sample mul_1956 = (add_1873 * gen_1936);
			t_sample mul_1953 = (m_history_4 * gen_1935);
			t_sample mul_1951 = (m_history_5 * ((int)1));
			t_sample mul_1947 = (m_history_6 * gen_1936);
			t_sample mul_1949 = (m_history_3 * gen_1935);
			t_sample sub_1955 = (((mul_1951 + mul_1953) + mul_1956) - (mul_1949 + mul_1947));
			t_sample gen_1961 = sub_1955;
			t_sample history_1948_next_1957 = fixdenorm(m_history_3);
			t_sample history_1952_next_1958 = fixdenorm(m_history_4);
			t_sample history_1954_next_1959 = fixdenorm(add_1873);
			t_sample history_1950_next_1960 = fixdenorm(sub_1955);
			t_sample mul_1875 = ((gen_1961 + gen_1919) * ((t_sample)0.5));
			t_sample dcblock_1876 = __m_dcblock_64(mul_1875);
			t_sample mul_1877 = (((gate_1865 + gen_1961) + gen_1919) * scale_2117);
			t_sample div_1840 = (mul_1877 * ((t_sample)0.5));
			t_sample add_2006 = (gate_1864 + div_1840);
			t_sample out2 = add_2006;
			t_sample history_1872_next_2066 = fixdenorm(dcblock_2007);
			t_sample history_2013_next_2067 = fixdenorm(dcblock_1876);
			m_history_22 = history_1850_next_1852;
			m_history_20 = history_1846_next_1854;
			m_history_21 = history_1848_next_1853;
			m_history_19 = history_1867_next_1869;
			m_history_18 = history_1991_next_2000;
			m_history_15 = history_1993_next_2003;
			m_history_16 = history_1997_next_2002;
			m_history_17 = history_1995_next_2001;
			m_history_14 = history_2053_next_2058;
			m_history_11 = history_2051_next_2061;
			m_history_12 = history_2055_next_2060;
			m_history_13 = history_2049_next_2059;
			m_history_10 = history_1910_next_1915;
			m_history_7 = history_1908_next_1918;
			m_history_8 = history_1912_next_1917;
			m_history_9 = history_1906_next_1916;
			m_history_6 = history_1948_next_1957;
			m_history_3 = history_1950_next_1960;
			m_history_4 = history_1954_next_1959;
			m_history_5 = history_1952_next_1958;
			m_history_2 = history_1872_next_2066;
			m_history_1 = history_2013_next_2067;
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
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_23 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_knob6_diffusion(t_param _value) {
		m_knob6_diffusion_24 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 2: self->set_knob5_fb(value); break;
		case 3: self->set_knob6_diffusion(value); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_depth_25; break;
		case 1: *value = self->m_knob4_rate_28; break;
		case 2: *value = self->m_knob5_fb_23; break;
		case 3: *value = self->m_knob6_diffusion_24; break;
		case 4: *value = self->m_sw_27; break;
		case 5: *value = self->m_sw_26; break;
		
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
	// initialize parameter 0 ("m_knob3_depth_25")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_28")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_fb_23")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_diffusion_24")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_diffusion";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_diffusion_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_27")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_26")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_26;
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


} // Phaser::
