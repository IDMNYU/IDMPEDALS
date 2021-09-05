#include "Glitch.h"

namespace Glitch {

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
	Change __m_change_89;
	Change __m_change_83;
	Change __m_change_95;
	Change __m_change_101;
	DCBlock __m_dcblock_107;
	DCBlock __m_dcblock_108;
	Data m_segments_34;
	Delay m_delay_11;
	Delay m_delay_13;
	Delay m_delay_12;
	Delay m_delay_15;
	Delay m_delay_16;
	Delay m_delay_10;
	Delay m_delay_14;
	Delay m_delay_9;
	PlusEquals __m_pluseq_53;
	PlusEquals __m_pluseq_58;
	PlusEquals __m_pluseq_48;
	PlusEquals __m_pluseq_102;
	PlusEquals __m_pluseq_37;
	PlusEquals __m_pluseq_63;
	PlusEquals __m_pluseq_96;
	PlusEquals __m_pluseq_73;
	PlusEquals __m_pluseq_68;
	PlusEquals __m_pluseq_90;
	PlusEquals __m_pluseq_78;
	PlusEquals __m_pluseq_84;
	PlusEquals __m_pluseq_43;
	Sah __m_sah_65;
	Sah __m_sah_49;
	Sah __m_sah_50;
	Sah __m_sah_75;
	Sah __m_sah_45;
	Sah __m_sah_44;
	Sah __m_sah_74;
	Sah __m_sah_55;
	Sah __m_sah_60;
	Sah __m_sah_54;
	Sah __m_sah_59;
	Sah __m_sah_70;
	Sah __m_sah_69;
	Sah __m_sah_79;
	Sah __m_sah_85;
	Sah __m_sah_98;
	Sah __m_sah_103;
	Sah __m_sah_104;
	Sah __m_sah_80;
	Sah __m_sah_97;
	Sah __m_sah_91;
	Sah __m_sah_35;
	Sah __m_sah_92;
	Sah __m_sah_86;
	Sah __m_sah_64;
	int vectorsize;
	int __exception;
	t_sample m_history_17;
	t_sample m_history_2;
	t_sample m_history_1;
	t_sample m_knob1_wetdry_32;
	t_sample m_sw_33;
	t_sample m_history_3;
	t_sample m_sw_31;
	t_sample samplerate;
	t_sample m_knob6_density_27;
	t_sample m_knob4_buflen_30;
	t_sample m_knob5_glitchlen_28;
	t_sample m_knob3_thresh_29;
	t_sample m_history_25;
	t_sample m_history_4;
	t_sample m_history_23;
	t_sample m_history_8;
	t_sample m_history_20;
	t_sample m_history_19;
	t_sample m_history_18;
	t_sample m_history_24;
	t_sample m_history_21;
	t_sample m_history_22;
	t_sample m_history_5;
	t_sample m_history_7;
	t_sample m_history_6;
	t_sample __m_slide_40;
	t_sample m_history_26;
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
		m_delay_9.reset("m_delay_9", ((int)2));
		m_delay_10.reset("m_delay_10", ((int)9));
		m_delay_11.reset("m_delay_11", ((int)3));
		m_delay_12.reset("m_delay_12", ((int)5));
		m_delay_13.reset("m_delay_13", ((int)5));
		m_delay_14.reset("m_delay_14", ((int)7));
		m_delay_15.reset("m_delay_15", ((int)3));
		m_delay_16.reset("m_delay_16", ((int)4));
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_history_23 = ((int)0);
		m_history_24 = ((int)0);
		m_history_25 = ((int)0);
		m_history_26 = ((int)0);
		m_knob6_density_27 = ((int)0);
		m_knob5_glitchlen_28 = ((int)0);
		m_knob3_thresh_29 = ((int)0);
		m_knob4_buflen_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_knob1_wetdry_32 = ((int)0);
		m_sw_33 = ((int)0);
		m_segments_34.reset("segments", ((int)480000), ((int)1));
		__m_sah_35.reset(0);
		__m_pluseq_37.reset(0);
		__m_slide_40 = 0;
		__m_pluseq_43.reset(0);
		__m_sah_44.reset(0);
		__m_sah_45.reset(0);
		__m_pluseq_48.reset(0);
		__m_sah_49.reset(0);
		__m_sah_50.reset(0);
		__m_pluseq_53.reset(0);
		__m_sah_54.reset(0);
		__m_sah_55.reset(0);
		__m_pluseq_58.reset(0);
		__m_sah_59.reset(0);
		__m_sah_60.reset(0);
		__m_pluseq_63.reset(0);
		__m_sah_64.reset(0);
		__m_sah_65.reset(0);
		__m_pluseq_68.reset(0);
		__m_sah_69.reset(0);
		__m_sah_70.reset(0);
		__m_pluseq_73.reset(0);
		__m_sah_74.reset(0);
		__m_sah_75.reset(0);
		__m_pluseq_78.reset(0);
		__m_sah_79.reset(0);
		__m_sah_80.reset(0);
		__m_change_83.reset(0);
		__m_pluseq_84.reset(0);
		__m_sah_85.reset(0);
		__m_sah_86.reset(0);
		__m_change_89.reset(0);
		__m_pluseq_90.reset(0);
		__m_sah_91.reset(0);
		__m_sah_92.reset(0);
		__m_change_95.reset(0);
		__m_pluseq_96.reset(0);
		__m_sah_97.reset(0);
		__m_sah_98.reset(0);
		__m_change_101.reset(0);
		__m_pluseq_102.reset(0);
		__m_sah_103.reset(0);
		__m_sah_104.reset(0);
		__m_dcblock_107.reset();
		__m_dcblock_108.reset();
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
		int segments_dim = m_segments_34.dim;
		int segments_channels = m_segments_34.channels;
		t_sample mstosamps_2201 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_2199 = (((int)100) * (samplerate * 0.001));
		t_sample iup_41 = (1 / maximum(1, abs(mstosamps_2201)));
		t_sample idown_42 = (1 / maximum(1, abs(mstosamps_2199)));
		t_sample mstosamps_1812 = (((int)1) * (samplerate * 0.001));
		t_sample mul_2147 = (m_knob3_thresh_29 * ((t_sample)0.95));
		t_sample mstosamps_1801 = (((int)1) * (samplerate * 0.001));
		t_sample mul_2146 = (m_knob3_thresh_29 * ((t_sample)1.03));
		t_sample mstosamps_1790 = (((int)1) * (samplerate * 0.001));
		t_sample mul_2145 = (m_knob3_thresh_29 * ((t_sample)0.98));
		t_sample mstosamps_1779 = (((int)1) * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample mix_2302 = (m_history_26 + (((t_sample)0.003926980723806) * (m_knob4_buflen_30 - m_history_26)));
			t_sample mix_1827 = mix_2302;
			t_sample mix_2303 = (m_history_25 + (((t_sample)0.003926980723806) * (mix_1827 - m_history_25)));
			t_sample mix_1825 = mix_2303;
			t_sample mix_2304 = (m_history_24 + (((t_sample)0.003926980723806) * (mix_1825 - m_history_24)));
			t_sample mix_1823 = mix_2304;
			t_sample gen_2185 = mix_1823;
			t_sample history_1828_next_1830 = fixdenorm(mix_1827);
			t_sample history_1826_next_1831 = fixdenorm(mix_1825);
			t_sample history_1824_next_1832 = fixdenorm(mix_1823);
			t_sample expr_2213 = (((int)1) - sqrt((((int)1) - gen_2185)));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_2207 = __m_sah_35(m_history_23, m_sw_33, ((int)0));
			t_sample gen_2209 = sah_2207;
			t_sample rsub_2205 = (((int)1) - sah_2207);
			t_sample history_2206_next_2208 = fixdenorm(rsub_2205);
			t_sample out3 = gen_2209;
			t_sample add_2212 = (gen_2209 + ((int)1));
			t_sample choice_36 = int(add_2212);
			t_sample gate_2210 = (((choice_36 >= 1) && (choice_36 < 2)) ? in1 : 0);
			t_sample gate_2211 = ((choice_36 >= 2) ? in1 : 0);
			t_sample mix_2305 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob1_wetdry_32 - m_history_22)));
			t_sample mix_2218 = mix_2305;
			t_sample mix_2306 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_2218 - m_history_21)));
			t_sample mix_2220 = mix_2306;
			t_sample mix_2307 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_2220 - m_history_20)));
			t_sample mix_2222 = mix_2307;
			t_sample gen_1833 = mix_2222;
			t_sample history_1828_next_2215 = fixdenorm(mix_2218);
			t_sample history_1826_next_2217 = fixdenorm(mix_2220);
			t_sample history_1824_next_2223 = fixdenorm(mix_2222);
			t_sample sqrt_1819 = sqrt(gen_1833);
			t_sample rsub_1835 = (((int)1) - gen_1833);
			t_sample sqrt_1834 = sqrt(rsub_1835);
			t_sample mul_1822 = (sqrt_1834 * gate_2211);
			t_sample plusequals_2203 = __m_pluseq_37.post(((int)1), m_history_1, 0);
			t_sample switch_2183 = (m_sw_31 ? ((int)-1) : plusequals_2203);
			int index_trunc_38 = fixnan(floor(switch_2183));
			bool index_ignore_39 = ((index_trunc_38 >= segments_dim) || (index_trunc_38 < 0));
			if ((!index_ignore_39)) {
				m_segments_34.write(gate_2211, index_trunc_38, 0);
				
			};
			t_sample mul_2186 = (expr_2213 * ((int)480000));
			int gte_2189 = (plusequals_2203 >= mul_2186);
			int eq_2188 = (gte_2189 == ((int)1));
			t_sample abs_2204 = fabs(gate_2211);
			t_sample mul_1837 = (abs_2204 * ((int)30));
			__m_slide_40 = fixdenorm((__m_slide_40 + (((mul_1837 > __m_slide_40) ? iup_41 : idown_42) * (mul_1837 - __m_slide_40))));
			t_sample slide_2202 = __m_slide_40;
			t_sample clamp_2197 = ((slide_2202 <= ((int)0)) ? ((int)0) : ((slide_2202 >= ((int)1)) ? ((int)1) : slide_2202));
			t_sample out4 = clamp_2197;
			t_sample mix_2308 = (m_history_19 + (((t_sample)0.003926980723806) * (m_knob6_density_27 - m_history_19)));
			t_sample mix_2233 = mix_2308;
			t_sample mix_2309 = (m_history_18 + (((t_sample)0.003926980723806) * (mix_2233 - m_history_18)));
			t_sample mix_2230 = mix_2309;
			t_sample mix_2310 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_2230 - m_history_17)));
			t_sample mix_2234 = mix_2310;
			t_sample gen_2070 = mix_2234;
			t_sample history_1828_next_2228 = fixdenorm(mix_2233);
			t_sample history_1826_next_2232 = fixdenorm(mix_2230);
			t_sample history_1824_next_2227 = fixdenorm(mix_2234);
			t_sample sub_2314 = (gen_2070 - ((int)0));
			t_sample scale_2311 = ((safepow((sub_2314 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_1867 = m_delay_16.read_step(((int)8));
			t_sample tap_1869 = m_delay_15.read_step(((int)8));
			t_sample tap_1863 = m_delay_14.read_step(((int)8));
			t_sample tap_1865 = m_delay_13.read_step(((int)8));
			t_sample tap_1855 = m_delay_12.read_step(((int)8));
			t_sample tap_1857 = m_delay_11.read_step(((int)8));
			t_sample tap_1859 = m_delay_10.read_step(((int)9));
			t_sample tap_1861 = m_delay_9.read_step(((int)8));
			t_sample mul_1851 = (gen_2070 * ((int)12));
			int gte_1849 = (mul_1851 >= ((int)1));
			int gte_1848 = (mul_1851 >= ((int)2));
			int gte_1847 = (mul_1851 >= ((int)3));
			int gte_1850 = (mul_1851 >= ((int)0));
			int gte_1845 = (mul_1851 >= ((int)5));
			int gte_1846 = (mul_1851 >= ((int)4));
			int gte_1843 = (mul_1851 >= ((int)7));
			int gte_1844 = (mul_1851 >= ((int)6));
			int gte_1839 = (mul_1851 >= ((int)11));
			int gte_1840 = (mul_1851 >= ((int)10));
			int gte_1841 = (mul_1851 >= ((int)9));
			int gte_1842 = (mul_1851 >= ((int)8));
			t_sample mix_2315 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob5_glitchlen_28 - m_history_8)));
			t_sample mix_2249 = mix_2315;
			t_sample mix_2316 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_2249 - m_history_7)));
			t_sample mix_2241 = mix_2316;
			t_sample mix_2317 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_2241 - m_history_6)));
			t_sample mix_2244 = mix_2317;
			t_sample gen_2072 = mix_2244;
			t_sample history_1828_next_2247 = fixdenorm(mix_2249);
			t_sample history_1826_next_2243 = fixdenorm(mix_2241);
			t_sample history_1824_next_2246 = fixdenorm(mix_2244);
			t_sample mul_1816 = (mul_2186 * gen_2072);
			t_sample clamp_2071 = ((mul_1816 <= ((int)50)) ? ((int)50) : ((mul_1816 >= ((int)480000)) ? ((int)480000) : mul_1816));
			t_sample plusequals_2031 = __m_pluseq_43.post(((int)1), tap_1867, 0);
			t_sample noise_2026 = noise();
			t_sample abs_2025 = fabs(noise_2026);
			t_sample sub_2017 = (clamp_2071 - ((int)50));
			t_sample mul_2024 = (abs_2025 * sub_2017);
			t_sample sah_2027 = __m_sah_44(mul_2024, tap_1867, ((t_sample)0.5));
			t_sample add_2014 = (sah_2027 + ((int)50));
			t_sample mod_2023 = safemod(plusequals_2031, add_2014);
			t_sample div_2020 = safediv(mod_2023, add_2014);
			t_sample expr_2036 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2020))));
			t_sample noise_2034 = noise();
			t_sample abs_2033 = fabs(noise_2034);
			t_sample mul_2032 = (abs_2033 * mul_2186);
			t_sample sah_2035 = __m_sah_45(mul_2032, tap_1867, ((t_sample)0.5));
			t_sample add_2029 = (sah_2035 + mod_2023);
			t_sample mod_2028 = safemod(add_2029, mul_2186);
			t_sample switch_2015 = (gte_1845 ? mod_2028 : ((int)-1));
			int index_trunc_46 = fixnan(floor(switch_2015));
			bool index_ignore_47 = ((index_trunc_46 >= segments_dim) || (index_trunc_46 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2021 = (index_ignore_47 ? 0 : m_segments_34.read(index_trunc_46, 0));
			t_sample index_segments_2022 = switch_2015;
			t_sample mul_2018 = (sample_segments_2021 * expr_2036);
			t_sample plusequals_2055 = __m_pluseq_48.post(((int)1), tap_1869, 0);
			t_sample noise_2050 = noise();
			t_sample abs_2049 = fabs(noise_2050);
			t_sample sub_2041 = (clamp_2071 - ((int)50));
			t_sample mul_2048 = (abs_2049 * sub_2041);
			t_sample sah_2051 = __m_sah_49(mul_2048, tap_1869, ((t_sample)0.5));
			t_sample add_2038 = (sah_2051 + ((int)50));
			t_sample mod_2047 = safemod(plusequals_2055, add_2038);
			t_sample div_2044 = safediv(mod_2047, add_2038);
			t_sample expr_2060 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2044))));
			t_sample noise_2058 = noise();
			t_sample abs_2057 = fabs(noise_2058);
			t_sample mul_2056 = (abs_2057 * mul_2186);
			t_sample sah_2059 = __m_sah_50(mul_2056, tap_1869, ((t_sample)0.5));
			t_sample add_2053 = (sah_2059 + mod_2047);
			t_sample mod_2052 = safemod(add_2053, mul_2186);
			t_sample switch_2039 = (gte_1846 ? mod_2052 : ((int)-1));
			int index_trunc_51 = fixnan(floor(switch_2039));
			bool index_ignore_52 = ((index_trunc_51 >= segments_dim) || (index_trunc_51 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2045 = (index_ignore_52 ? 0 : m_segments_34.read(index_trunc_51, 0));
			t_sample index_segments_2046 = switch_2039;
			t_sample mul_2042 = (sample_segments_2045 * expr_2060);
			t_sample mul_2069 = ((mul_2042 + mul_2018) * ((t_sample)0.3));
			t_sample mul_2068 = ((mul_2042 + mul_2018) * ((t_sample)0.4));
			t_sample plusequals_1983 = __m_pluseq_53.post(((int)1), tap_1863, 0);
			t_sample noise_1978 = noise();
			t_sample abs_1977 = fabs(noise_1978);
			t_sample sub_1969 = (clamp_2071 - ((int)50));
			t_sample mul_1976 = (abs_1977 * sub_1969);
			t_sample sah_1979 = __m_sah_54(mul_1976, tap_1863, ((t_sample)0.5));
			t_sample add_1966 = (sah_1979 + ((int)50));
			t_sample mod_1975 = safemod(plusequals_1983, add_1966);
			t_sample div_1972 = safediv(mod_1975, add_1966);
			t_sample expr_1988 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1972))));
			t_sample noise_1986 = noise();
			t_sample abs_1985 = fabs(noise_1986);
			t_sample mul_1984 = (abs_1985 * mul_2186);
			t_sample sah_1987 = __m_sah_55(mul_1984, tap_1863, ((t_sample)0.5));
			t_sample add_1981 = (sah_1987 + mod_1975);
			t_sample mod_1980 = safemod(add_1981, mul_2186);
			t_sample switch_1967 = (gte_1843 ? mod_1980 : ((int)-1));
			int index_trunc_56 = fixnan(floor(switch_1967));
			bool index_ignore_57 = ((index_trunc_56 >= segments_dim) || (index_trunc_56 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1973 = (index_ignore_57 ? 0 : m_segments_34.read(index_trunc_56, 0));
			t_sample index_segments_1974 = switch_1967;
			t_sample mul_1970 = (sample_segments_1973 * expr_1988);
			t_sample plusequals_2007 = __m_pluseq_58.post(((int)1), tap_1865, 0);
			t_sample noise_2002 = noise();
			t_sample abs_2001 = fabs(noise_2002);
			t_sample sub_1993 = (clamp_2071 - ((int)50));
			t_sample mul_2000 = (abs_2001 * sub_1993);
			t_sample sah_2003 = __m_sah_59(mul_2000, tap_1865, ((t_sample)0.5));
			t_sample add_1990 = (sah_2003 + ((int)50));
			t_sample mod_1999 = safemod(plusequals_2007, add_1990);
			t_sample div_1996 = safediv(mod_1999, add_1990);
			t_sample expr_2012 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1996))));
			t_sample noise_2010 = noise();
			t_sample abs_2009 = fabs(noise_2010);
			t_sample mul_2008 = (abs_2009 * mul_2186);
			t_sample sah_2011 = __m_sah_60(mul_2008, tap_1865, ((t_sample)0.5));
			t_sample add_2005 = (sah_2011 + mod_1999);
			t_sample mod_2004 = safemod(add_2005, mul_2186);
			t_sample switch_1991 = (gte_1844 ? mod_2004 : ((int)-1));
			int index_trunc_61 = fixnan(floor(switch_1991));
			bool index_ignore_62 = ((index_trunc_61 >= segments_dim) || (index_trunc_61 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1997 = (index_ignore_62 ? 0 : m_segments_34.read(index_trunc_61, 0));
			t_sample index_segments_1998 = switch_1991;
			t_sample mul_1994 = (sample_segments_1997 * expr_2012);
			t_sample mul_2067 = ((mul_1994 + mul_1970) * ((t_sample)0.4));
			t_sample mul_2066 = ((mul_1994 + mul_1970) * ((t_sample)0.3));
			t_sample plusequals_1887 = __m_pluseq_63.post(((int)1), tap_1855, 0);
			t_sample noise_1882 = noise();
			t_sample abs_1881 = fabs(noise_1882);
			t_sample sub_1873 = (clamp_2071 - ((int)50));
			t_sample mul_1880 = (abs_1881 * sub_1873);
			t_sample sah_1883 = __m_sah_64(mul_1880, tap_1855, ((t_sample)0.5));
			t_sample add_1870 = (sah_1883 + ((int)50));
			t_sample mod_1879 = safemod(plusequals_1887, add_1870);
			t_sample div_1876 = safediv(mod_1879, add_1870);
			t_sample expr_1892 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1876))));
			t_sample noise_1890 = noise();
			t_sample abs_1889 = fabs(noise_1890);
			t_sample mul_1888 = (abs_1889 * mul_2186);
			t_sample sah_1891 = __m_sah_65(mul_1888, tap_1855, ((t_sample)0.5));
			t_sample add_1885 = (sah_1891 + mod_1879);
			t_sample mod_1884 = safemod(add_1885, mul_2186);
			t_sample switch_1871 = (gte_1839 ? mod_1884 : ((int)-1));
			int index_trunc_66 = fixnan(floor(switch_1871));
			bool index_ignore_67 = ((index_trunc_66 >= segments_dim) || (index_trunc_66 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1877 = (index_ignore_67 ? 0 : m_segments_34.read(index_trunc_66, 0));
			t_sample index_segments_1878 = switch_1871;
			t_sample mul_1874 = (sample_segments_1877 * expr_1892);
			t_sample plusequals_1911 = __m_pluseq_68.post(((int)1), tap_1857, 0);
			t_sample noise_1906 = noise();
			t_sample abs_1905 = fabs(noise_1906);
			t_sample sub_1897 = (clamp_2071 - ((int)50));
			t_sample mul_1904 = (abs_1905 * sub_1897);
			t_sample sah_1907 = __m_sah_69(mul_1904, tap_1857, ((t_sample)0.5));
			t_sample add_1894 = (sah_1907 + ((int)50));
			t_sample mod_1903 = safemod(plusequals_1911, add_1894);
			t_sample div_1900 = safediv(mod_1903, add_1894);
			t_sample expr_1916 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1900))));
			t_sample noise_1914 = noise();
			t_sample abs_1913 = fabs(noise_1914);
			t_sample mul_1912 = (abs_1913 * mul_2186);
			t_sample sah_1915 = __m_sah_70(mul_1912, tap_1857, ((t_sample)0.5));
			t_sample add_1909 = (sah_1915 + mod_1903);
			t_sample mod_1908 = safemod(add_1909, mul_2186);
			t_sample switch_1895 = (gte_1840 ? mod_1908 : ((int)-1));
			int index_trunc_71 = fixnan(floor(switch_1895));
			bool index_ignore_72 = ((index_trunc_71 >= segments_dim) || (index_trunc_71 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1901 = (index_ignore_72 ? 0 : m_segments_34.read(index_trunc_71, 0));
			t_sample index_segments_1902 = switch_1895;
			t_sample mul_1898 = (sample_segments_1901 * expr_1916);
			t_sample mul_2063 = ((mul_1898 + mul_1874) * ((t_sample)0.5));
			t_sample mul_2062 = ((mul_1898 + mul_1874) * ((t_sample)0.2));
			t_sample plusequals_1935 = __m_pluseq_73.post(((int)1), tap_1859, 0);
			t_sample noise_1930 = noise();
			t_sample abs_1929 = fabs(noise_1930);
			t_sample sub_1921 = (clamp_2071 - ((int)50));
			t_sample mul_1928 = (abs_1929 * sub_1921);
			t_sample sah_1931 = __m_sah_74(mul_1928, tap_1859, ((t_sample)0.5));
			t_sample add_1918 = (sah_1931 + ((int)50));
			t_sample mod_1927 = safemod(plusequals_1935, add_1918);
			t_sample div_1924 = safediv(mod_1927, add_1918);
			t_sample expr_1940 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1924))));
			t_sample noise_1938 = noise();
			t_sample abs_1937 = fabs(noise_1938);
			t_sample mul_1936 = (abs_1937 * mul_2186);
			t_sample sah_1939 = __m_sah_75(mul_1936, tap_1859, ((t_sample)0.5));
			t_sample add_1933 = (sah_1939 + mod_1927);
			t_sample mod_1932 = safemod(add_1933, mul_2186);
			t_sample switch_1919 = (gte_1841 ? mod_1932 : ((int)-1));
			int index_trunc_76 = fixnan(floor(switch_1919));
			bool index_ignore_77 = ((index_trunc_76 >= segments_dim) || (index_trunc_76 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1925 = (index_ignore_77 ? 0 : m_segments_34.read(index_trunc_76, 0));
			t_sample index_segments_1926 = switch_1919;
			t_sample mul_1922 = (sample_segments_1925 * expr_1940);
			t_sample plusequals_1959 = __m_pluseq_78.post(((int)1), tap_1861, 0);
			t_sample noise_1954 = noise();
			t_sample abs_1953 = fabs(noise_1954);
			t_sample sub_1945 = (clamp_2071 - ((int)50));
			t_sample mul_1952 = (abs_1953 * sub_1945);
			t_sample sah_1955 = __m_sah_79(mul_1952, tap_1861, ((t_sample)0.5));
			t_sample add_1942 = (sah_1955 + ((int)50));
			t_sample mod_1951 = safemod(plusequals_1959, add_1942);
			t_sample div_1948 = safediv(mod_1951, add_1942);
			t_sample expr_1964 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1948))));
			t_sample noise_1962 = noise();
			t_sample abs_1961 = fabs(noise_1962);
			t_sample mul_1960 = (abs_1961 * mul_2186);
			t_sample sah_1963 = __m_sah_80(mul_1960, tap_1861, ((t_sample)0.5));
			t_sample add_1957 = (sah_1963 + mod_1951);
			t_sample mod_1956 = safemod(add_1957, mul_2186);
			t_sample switch_1943 = (gte_1842 ? mod_1956 : ((int)-1));
			int index_trunc_81 = fixnan(floor(switch_1943));
			bool index_ignore_82 = ((index_trunc_81 >= segments_dim) || (index_trunc_81 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1949 = (index_ignore_82 ? 0 : m_segments_34.read(index_trunc_81, 0));
			t_sample index_segments_1950 = switch_1943;
			t_sample mul_1946 = (sample_segments_1949 * expr_1964);
			t_sample mul_2065 = ((mul_1946 + mul_1922) * ((t_sample)0.2));
			t_sample mul_2064 = ((mul_1946 + mul_1922) * ((t_sample)0.5));
			int gt_2194 = (clamp_2197 > m_knob3_thresh_29);
			int change_2193 = __m_change_83(gt_2194);
			int eq_2192 = (change_2193 == ((int)1));
			t_sample add_1810 = (m_history_5 + ((int)1));
			int gt_1809 = (m_history_5 > mstosamps_1812);
			int mul_1808 = (eq_2192 * gt_1809);
			int and_1806 = (gt_1809 && eq_2192);
			t_sample switch_1807 = (and_1806 ? ((int)0) : add_1810);
			t_sample history_1811_next_1814 = fixdenorm(switch_1807);
			int plusequals_2175 = __m_pluseq_84.post(((int)1), mul_1808, 0);
			t_sample noise_2170 = noise();
			t_sample abs_2169 = fabs(noise_2170);
			t_sample sub_2161 = (clamp_2071 - ((int)50));
			t_sample mul_2168 = (abs_2169 * sub_2161);
			t_sample sah_2171 = __m_sah_85(mul_2168, mul_1808, ((t_sample)0.5));
			t_sample add_2158 = (sah_2171 + ((int)50));
			t_sample mod_2167 = safemod(plusequals_2175, add_2158);
			t_sample div_2164 = safediv(mod_2167, add_2158);
			t_sample expr_2180 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2164))));
			t_sample noise_2178 = noise();
			t_sample abs_2177 = fabs(noise_2178);
			t_sample mul_2176 = (abs_2177 * mul_2186);
			t_sample sah_2179 = __m_sah_86(mul_2176, mul_1808, ((t_sample)0.5));
			t_sample add_2173 = (sah_2179 + mod_2167);
			t_sample mod_2172 = safemod(add_2173, mul_2186);
			t_sample switch_2159 = (gte_1850 ? mod_2172 : ((int)-1));
			int index_trunc_87 = fixnan(floor(switch_2159));
			bool index_ignore_88 = ((index_trunc_87 >= segments_dim) || (index_trunc_87 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2165 = (index_ignore_88 ? 0 : m_segments_34.read(index_trunc_87, 0));
			t_sample index_segments_2166 = switch_2159;
			t_sample mul_2162 = (sample_segments_2165 * expr_2180);
			int gt_2156 = (clamp_2197 > mul_2147);
			int change_2155 = __m_change_89(gt_2156);
			int eq_2154 = (change_2155 == ((int)1));
			t_sample add_1799 = (m_history_4 + ((int)1));
			int gt_1798 = (m_history_4 > mstosamps_1801);
			int mul_1797 = (eq_2154 * gt_1798);
			int and_1795 = (gt_1798 && eq_2154);
			t_sample switch_1796 = (and_1795 ? ((int)0) : add_1799);
			t_sample history_1800_next_1803 = fixdenorm(switch_1796);
			int plusequals_2138 = __m_pluseq_90.post(((int)1), mul_1797, 0);
			t_sample noise_2133 = noise();
			t_sample abs_2132 = fabs(noise_2133);
			t_sample sub_2124 = (clamp_2071 - ((int)50));
			t_sample mul_2131 = (abs_2132 * sub_2124);
			t_sample sah_2134 = __m_sah_91(mul_2131, mul_1797, ((t_sample)0.5));
			t_sample add_2121 = (sah_2134 + ((int)50));
			t_sample mod_2130 = safemod(plusequals_2138, add_2121);
			t_sample div_2127 = safediv(mod_2130, add_2121);
			t_sample expr_2143 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2127))));
			t_sample noise_2141 = noise();
			t_sample abs_2140 = fabs(noise_2141);
			t_sample mul_2139 = (abs_2140 * mul_2186);
			t_sample sah_2142 = __m_sah_92(mul_2139, mul_1797, ((t_sample)0.5));
			t_sample add_2136 = (sah_2142 + mod_2130);
			t_sample mod_2135 = safemod(add_2136, mul_2186);
			t_sample switch_2122 = (gte_1849 ? mod_2135 : ((int)-1));
			int index_trunc_93 = fixnan(floor(switch_2122));
			bool index_ignore_94 = ((index_trunc_93 >= segments_dim) || (index_trunc_93 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2128 = (index_ignore_94 ? 0 : m_segments_34.read(index_trunc_93, 0));
			t_sample index_segments_2129 = switch_2122;
			t_sample mul_2125 = (sample_segments_2128 * expr_2143);
			int gt_2153 = (clamp_2197 > mul_2146);
			int change_2152 = __m_change_95(gt_2153);
			int eq_2151 = (change_2152 == ((int)1));
			t_sample add_1788 = (m_history_3 + ((int)1));
			int gt_1787 = (m_history_3 > mstosamps_1790);
			int mul_1786 = (eq_2151 * gt_1787);
			int and_1784 = (gt_1787 && eq_2151);
			t_sample switch_1785 = (and_1784 ? ((int)0) : add_1788);
			t_sample history_1789_next_1792 = fixdenorm(switch_1785);
			int plusequals_2114 = __m_pluseq_96.post(((int)1), mul_1786, 0);
			t_sample noise_2109 = noise();
			t_sample abs_2108 = fabs(noise_2109);
			t_sample sub_2100 = (clamp_2071 - ((int)50));
			t_sample mul_2107 = (abs_2108 * sub_2100);
			t_sample sah_2110 = __m_sah_97(mul_2107, mul_1786, ((t_sample)0.5));
			t_sample add_2097 = (sah_2110 + ((int)50));
			t_sample mod_2106 = safemod(plusequals_2114, add_2097);
			t_sample div_2103 = safediv(mod_2106, add_2097);
			t_sample expr_2119 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2103))));
			t_sample noise_2117 = noise();
			t_sample abs_2116 = fabs(noise_2117);
			t_sample mul_2115 = (abs_2116 * mul_2186);
			t_sample sah_2118 = __m_sah_98(mul_2115, mul_1786, ((t_sample)0.5));
			t_sample add_2112 = (sah_2118 + mod_2106);
			t_sample mod_2111 = safemod(add_2112, mul_2186);
			t_sample switch_2098 = (gte_1848 ? mod_2111 : ((int)-1));
			int index_trunc_99 = fixnan(floor(switch_2098));
			bool index_ignore_100 = ((index_trunc_99 >= segments_dim) || (index_trunc_99 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2104 = (index_ignore_100 ? 0 : m_segments_34.read(index_trunc_99, 0));
			t_sample index_segments_2105 = switch_2098;
			t_sample mul_2101 = (sample_segments_2104 * expr_2119);
			int gt_2150 = (clamp_2197 > mul_2145);
			int change_2149 = __m_change_101(gt_2150);
			int eq_2148 = (change_2149 == ((int)1));
			t_sample add_1777 = (m_history_2 + ((int)1));
			int gt_1776 = (m_history_2 > mstosamps_1779);
			int mul_1775 = (eq_2148 * gt_1776);
			int and_1773 = (gt_1776 && eq_2148);
			t_sample switch_1774 = (and_1773 ? ((int)0) : add_1777);
			t_sample history_1778_next_1781 = fixdenorm(switch_1774);
			int plusequals_2090 = __m_pluseq_102.post(((int)1), mul_1775, 0);
			t_sample noise_2085 = noise();
			t_sample abs_2084 = fabs(noise_2085);
			t_sample sub_2076 = (clamp_2071 - ((int)50));
			t_sample mul_2083 = (abs_2084 * sub_2076);
			t_sample sah_2086 = __m_sah_103(mul_2083, mul_1775, ((t_sample)0.5));
			t_sample add_2073 = (sah_2086 + ((int)50));
			t_sample mod_2082 = safemod(plusequals_2090, add_2073);
			t_sample div_2079 = safediv(mod_2082, add_2073);
			t_sample expr_2095 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2079))));
			t_sample noise_2093 = noise();
			t_sample abs_2092 = fabs(noise_2093);
			t_sample mul_2091 = (abs_2092 * mul_2186);
			t_sample sah_2094 = __m_sah_104(mul_2091, mul_1775, ((t_sample)0.5));
			t_sample add_2088 = (sah_2094 + mod_2082);
			t_sample mod_2087 = safemod(add_2088, mul_2186);
			t_sample switch_2074 = (gte_1847 ? mod_2087 : ((int)-1));
			int index_trunc_105 = fixnan(floor(switch_2074));
			bool index_ignore_106 = ((index_trunc_105 >= segments_dim) || (index_trunc_105 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2080 = (index_ignore_106 ? 0 : m_segments_34.read(index_trunc_105, 0));
			t_sample index_segments_2081 = switch_2074;
			t_sample mul_2077 = (sample_segments_2080 * expr_2095);
			t_sample mul_2157 = ((((mul_2162 + mul_2077) + mul_2101) + mul_2125) * ((t_sample)0.7));
			t_sample mul_1853 = (((((mul_2065 + mul_2063) + mul_2067) + mul_2069) + mul_2157) * scale_2311);
			t_sample dcblock_1818 = __m_dcblock_107(mul_1853);
			t_sample mul_1821 = (sqrt_1819 * dcblock_1818);
			t_sample out1 = ((mul_1821 + mul_1822) + gate_2210);
			t_sample mul_1852 = (((((mul_2064 + mul_2062) + mul_2066) + mul_2068) + mul_2157) * scale_2311);
			t_sample dcblock_1817 = __m_dcblock_108(mul_1852);
			t_sample mul_1820 = (sqrt_1819 * dcblock_1817);
			t_sample out2 = ((mul_1820 + mul_1822) + gate_2210);
			t_sample history_2187_next_2253 = fixdenorm(eq_2188);
			m_history_26 = history_1828_next_1830;
			m_history_24 = history_1824_next_1832;
			m_history_25 = history_1826_next_1831;
			m_history_23 = history_2206_next_2208;
			m_history_22 = history_1828_next_2215;
			m_history_20 = history_1824_next_2223;
			m_history_21 = history_1826_next_2217;
			m_history_19 = history_1828_next_2228;
			m_history_17 = history_1824_next_2227;
			m_history_18 = history_1826_next_2232;
			m_delay_16.write(mul_1797);
			m_delay_15.write(mul_1808);
			m_delay_14.write(mul_1775);
			m_delay_13.write(mul_1786);
			m_delay_12.write(tap_1863);
			m_delay_11.write(tap_1865);
			m_delay_10.write(tap_1867);
			m_delay_9.write(tap_1869);
			m_history_8 = history_1828_next_2247;
			m_history_6 = history_1824_next_2246;
			m_history_7 = history_1826_next_2243;
			m_history_5 = history_1811_next_1814;
			m_history_4 = history_1800_next_1803;
			m_history_3 = history_1789_next_1792;
			m_history_2 = history_1778_next_1781;
			m_history_1 = history_2187_next_2253;
			m_delay_9.step();
			m_delay_10.step();
			m_delay_11.step();
			m_delay_12.step();
			m_delay_13.step();
			m_delay_14.step();
			m_delay_15.step();
			m_delay_16.step();
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
	inline void set_knob6_density(t_param _value) {
		m_knob6_density_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_glitchlen(t_param _value) {
		m_knob5_glitchlen_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_thresh(t_param _value) {
		m_knob3_thresh_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_segments(void * _value) {
		m_segments_34.setbuffer(_value);
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
int num_params() { return 8; }

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
		case 1: self->set_knob3_thresh(value); break;
		case 2: self->set_knob4_buflen(value); break;
		case 3: self->set_knob5_glitchlen(value); break;
		case 4: self->set_knob6_density(value); break;
		case 5: self->set_segments(ref); break;
		case 6: self->set_sw1(value); break;
		case 7: self->set_sw2(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_wetdry_32; break;
		case 1: *value = self->m_knob3_thresh_29; break;
		case 2: *value = self->m_knob4_buflen_30; break;
		case 3: *value = self->m_knob5_glitchlen_28; break;
		case 4: *value = self->m_knob6_density_27; break;
		
		case 6: *value = self->m_sw_33; break;
		case 7: *value = self->m_sw_31; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(8 * sizeof(ParamInfo));
	self->__commonstate.numparams = 8;
	// initialize parameter 0 ("m_knob1_wetdry_32")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_thresh_29")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_thresh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_thresh_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_buflen_30")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_buflen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_buflen_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_glitchlen_28")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_glitchlen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_glitchlen_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_density_27")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_density";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_density_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_segments_34")
	pi = self->__commonstate.params + 5;
	pi->name = "segments";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_sw_33")
	pi = self->__commonstate.params + 6;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_sw_31")
	pi = self->__commonstate.params + 7;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_31;
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


} // Glitch::
