#include "Glitch2.h"

namespace Glitch2 {

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
	Change __m_change_87;
	Change __m_change_81;
	Change __m_change_93;
	Change __m_change_99;
	DCBlock __m_dcblock_105;
	DCBlock __m_dcblock_106;
	Data m_segments_34;
	Delay m_delay_11;
	Delay m_delay_13;
	Delay m_delay_12;
	Delay m_delay_14;
	Delay m_delay_16;
	Delay m_delay_10;
	Delay m_delay_15;
	Delay m_delay_9;
	Phasor __m_phasor_37;
	PlusEquals __m_pluseq_100;
	PlusEquals __m_pluseq_38;
	PlusEquals __m_pluseq_51;
	PlusEquals __m_pluseq_56;
	PlusEquals __m_pluseq_46;
	PlusEquals __m_pluseq_61;
	PlusEquals __m_pluseq_94;
	PlusEquals __m_pluseq_71;
	PlusEquals __m_pluseq_66;
	PlusEquals __m_pluseq_76;
	PlusEquals __m_pluseq_88;
	PlusEquals __m_pluseq_82;
	PlusEquals __m_pluseq_41;
	Sah __m_sah_63;
	Sah __m_sah_47;
	Sah __m_sah_48;
	Sah __m_sah_73;
	Sah __m_sah_43;
	Sah __m_sah_42;
	Sah __m_sah_72;
	Sah __m_sah_53;
	Sah __m_sah_58;
	Sah __m_sah_52;
	Sah __m_sah_57;
	Sah __m_sah_68;
	Sah __m_sah_67;
	Sah __m_sah_77;
	Sah __m_sah_83;
	Sah __m_sah_96;
	Sah __m_sah_101;
	Sah __m_sah_102;
	Sah __m_sah_78;
	Sah __m_sah_95;
	Sah __m_sah_89;
	Sah __m_sah_84;
	Sah __m_sah_90;
	Sah __m_sah_35;
	Sah __m_sah_62;
	int vectorsize;
	int __exception;
	t_sample m_history_17;
	t_sample m_history_2;
	t_sample m_history_1;
	t_sample m_knob1_wetdry_33;
	t_sample m_history_25;
	t_sample m_history_3;
	t_sample m_sw_32;
	t_sample samplerate;
	t_sample m_knob5_glitchlen_28;
	t_sample m_knob4_buflen_31;
	t_sample m_knob6_density_29;
	t_sample m_knob3_rate_30;
	t_sample m_history_26;
	t_sample m_history_4;
	t_sample m_history_24;
	t_sample m_history_8;
	t_sample m_history_20;
	t_sample m_history_19;
	t_sample m_history_18;
	t_sample samples_to_seconds;
	t_sample m_history_21;
	t_sample m_history_22;
	t_sample m_history_5;
	t_sample m_history_7;
	t_sample m_history_6;
	t_sample m_history_23;
	t_sample m_sw_27;
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
		m_sw_27 = ((int)0);
		m_knob5_glitchlen_28 = ((int)0);
		m_knob6_density_29 = ((int)0);
		m_knob3_rate_30 = ((int)0);
		m_knob4_buflen_31 = ((int)0);
		m_sw_32 = ((int)0);
		m_knob1_wetdry_33 = ((int)0);
		m_segments_34.reset("segments", ((int)480000), ((int)1));
		__m_sah_35.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_37.reset(0);
		__m_pluseq_38.reset(0);
		__m_pluseq_41.reset(0);
		__m_sah_42.reset(0);
		__m_sah_43.reset(0);
		__m_pluseq_46.reset(0);
		__m_sah_47.reset(0);
		__m_sah_48.reset(0);
		__m_pluseq_51.reset(0);
		__m_sah_52.reset(0);
		__m_sah_53.reset(0);
		__m_pluseq_56.reset(0);
		__m_sah_57.reset(0);
		__m_sah_58.reset(0);
		__m_pluseq_61.reset(0);
		__m_sah_62.reset(0);
		__m_sah_63.reset(0);
		__m_pluseq_66.reset(0);
		__m_sah_67.reset(0);
		__m_sah_68.reset(0);
		__m_pluseq_71.reset(0);
		__m_sah_72.reset(0);
		__m_sah_73.reset(0);
		__m_pluseq_76.reset(0);
		__m_sah_77.reset(0);
		__m_sah_78.reset(0);
		__m_change_81.reset(0);
		__m_pluseq_82.reset(0);
		__m_sah_83.reset(0);
		__m_sah_84.reset(0);
		__m_change_87.reset(0);
		__m_pluseq_88.reset(0);
		__m_sah_89.reset(0);
		__m_sah_90.reset(0);
		__m_change_93.reset(0);
		__m_pluseq_94.reset(0);
		__m_sah_95.reset(0);
		__m_sah_96.reset(0);
		__m_change_99.reset(0);
		__m_pluseq_100.reset(0);
		__m_sah_101.reset(0);
		__m_sah_102.reset(0);
		__m_dcblock_105.reset();
		__m_dcblock_106.reset();
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
		samples_to_seconds = (1 / samplerate);
		int segments_dim = m_segments_34.dim;
		int segments_channels = m_segments_34.channels;
		t_sample mstosamps_1798 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_1787 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_1776 = (((int)1) * (samplerate * 0.001));
		t_sample mstosamps_1809 = (((int)1) * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_2194 = __m_sah_35(m_history_26, m_sw_32, ((int)0));
			t_sample gen_2196 = sah_2194;
			t_sample rsub_2192 = (((int)1) - sah_2194);
			t_sample history_2193_next_2195 = fixdenorm(rsub_2192);
			t_sample out3 = gen_2196;
			t_sample mix_2289 = (m_history_25 + (((t_sample)0.003926980723806) * (m_knob4_buflen_31 - m_history_25)));
			t_sample mix_1824 = mix_2289;
			t_sample mix_2290 = (m_history_24 + (((t_sample)0.003926980723806) * (mix_1824 - m_history_24)));
			t_sample mix_1822 = mix_2290;
			t_sample mix_2291 = (m_history_23 + (((t_sample)0.003926980723806) * (mix_1822 - m_history_23)));
			t_sample mix_1820 = mix_2291;
			t_sample gen_2178 = mix_1820;
			t_sample history_1825_next_1827 = fixdenorm(mix_1824);
			t_sample history_1823_next_1828 = fixdenorm(mix_1822);
			t_sample history_1821_next_1829 = fixdenorm(mix_1820);
			t_sample expr_2200 = (((int)1) - sqrt((((int)1) - gen_2178)));
			t_sample add_2199 = (gen_2196 + ((int)1));
			t_sample choice_36 = int(add_2199);
			t_sample gate_2197 = (((choice_36 >= 1) && (choice_36 < 2)) ? in1 : 0);
			t_sample gate_2198 = ((choice_36 >= 2) ? in1 : 0);
			t_sample switch_1768 = (gen_2196 ? m_knob3_rate_30 : ((int)0));
			t_sample phasor_2190 = __m_phasor_37(switch_1768, samples_to_seconds);
			t_sample out4 = phasor_2190;
			t_sample mix_2292 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob1_wetdry_33 - m_history_22)));
			t_sample mix_2204 = mix_2292;
			t_sample mix_2293 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_2204 - m_history_21)));
			t_sample mix_2210 = mix_2293;
			t_sample mix_2294 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_2210 - m_history_20)));
			t_sample mix_2202 = mix_2294;
			t_sample gen_1830 = mix_2202;
			t_sample history_1825_next_2206 = fixdenorm(mix_2204);
			t_sample history_1823_next_2207 = fixdenorm(mix_2210);
			t_sample history_1821_next_2203 = fixdenorm(mix_2202);
			t_sample sqrt_1816 = sqrt(gen_1830);
			t_sample rsub_1832 = (((int)1) - gen_1830);
			t_sample sqrt_1831 = sqrt(rsub_1832);
			t_sample mul_1819 = (sqrt_1831 * gate_2198);
			t_sample plusequals_2191 = __m_pluseq_38.post(((int)1), m_history_1, 0);
			t_sample switch_2176 = (m_sw_27 ? ((int)-1) : plusequals_2191);
			int index_trunc_39 = fixnan(floor(switch_2176));
			bool index_ignore_40 = ((index_trunc_39 >= segments_dim) || (index_trunc_39 < 0));
			if ((!index_ignore_40)) {
				m_segments_34.write(gate_2198, index_trunc_39, 0);
				
			};
			t_sample mul_2179 = (expr_2200 * ((int)480000));
			int gte_2182 = (plusequals_2191 >= mul_2179);
			int eq_2181 = (gte_2182 == ((int)1));
			t_sample mix_2295 = (m_history_19 + (((t_sample)0.003926980723806) * (m_knob6_density_29 - m_history_19)));
			t_sample mix_2220 = mix_2295;
			t_sample mix_2296 = (m_history_18 + (((t_sample)0.003926980723806) * (mix_2220 - m_history_18)));
			t_sample mix_2218 = mix_2296;
			t_sample mix_2297 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_2218 - m_history_17)));
			t_sample mix_2219 = mix_2297;
			t_sample gen_2066 = mix_2219;
			t_sample history_1825_next_2217 = fixdenorm(mix_2220);
			t_sample history_1823_next_2221 = fixdenorm(mix_2218);
			t_sample history_1821_next_2215 = fixdenorm(mix_2219);
			t_sample sub_2301 = (gen_2066 - ((int)0));
			t_sample scale_2298 = ((safepow((sub_2301 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_1863 = m_delay_16.read_step(((int)8));
			t_sample tap_1865 = m_delay_15.read_step(((int)8));
			t_sample tap_1859 = m_delay_14.read_step(((int)8));
			t_sample tap_1861 = m_delay_13.read_step(((int)8));
			t_sample tap_1851 = m_delay_12.read_step(((int)8));
			t_sample tap_1853 = m_delay_11.read_step(((int)8));
			t_sample tap_1855 = m_delay_10.read_step(((int)9));
			t_sample tap_1857 = m_delay_9.read_step(((int)8));
			t_sample mul_1847 = (gen_2066 * ((int)12));
			int gte_1845 = (mul_1847 >= ((int)1));
			int gte_1844 = (mul_1847 >= ((int)2));
			int gte_1843 = (mul_1847 >= ((int)3));
			int gte_1846 = (mul_1847 >= ((int)0));
			int gte_1841 = (mul_1847 >= ((int)5));
			int gte_1842 = (mul_1847 >= ((int)4));
			int gte_1839 = (mul_1847 >= ((int)7));
			int gte_1840 = (mul_1847 >= ((int)6));
			int gte_1835 = (mul_1847 >= ((int)11));
			int gte_1836 = (mul_1847 >= ((int)10));
			int gte_1837 = (mul_1847 >= ((int)9));
			int gte_1838 = (mul_1847 >= ((int)8));
			t_sample mix_2302 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob5_glitchlen_28 - m_history_8)));
			t_sample mix_2232 = mix_2302;
			t_sample mix_2303 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_2232 - m_history_7)));
			t_sample mix_2228 = mix_2303;
			t_sample mix_2304 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_2228 - m_history_6)));
			t_sample mix_2229 = mix_2304;
			t_sample gen_2068 = mix_2229;
			t_sample history_1825_next_2231 = fixdenorm(mix_2232);
			t_sample history_1823_next_2234 = fixdenorm(mix_2228);
			t_sample history_1821_next_2227 = fixdenorm(mix_2229);
			t_sample mul_1813 = (mul_2179 * gen_2068);
			t_sample clamp_2067 = ((mul_1813 <= ((int)50)) ? ((int)50) : ((mul_1813 >= ((int)480000)) ? ((int)480000) : mul_1813));
			t_sample plusequals_2027 = __m_pluseq_41.post(((int)-1), tap_1863, 0);
			t_sample noise_2023 = noise();
			t_sample abs_2022 = fabs(noise_2023);
			t_sample sub_2018 = (clamp_2067 - ((int)50));
			t_sample mul_2021 = (abs_2022 * sub_2018);
			t_sample sah_2024 = __m_sah_42(mul_2021, tap_1863, ((t_sample)0.5));
			t_sample add_2015 = (sah_2024 + ((int)50));
			t_sample wrap_2025 = wrap(plusequals_2027, ((int)0), add_2015);
			t_sample div_2012 = safediv(wrap_2025, add_2015);
			t_sample expr_2032 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2012))));
			t_sample noise_2030 = noise();
			t_sample abs_2029 = fabs(noise_2030);
			t_sample mul_2028 = (abs_2029 * mul_2179);
			t_sample sah_2031 = __m_sah_43(mul_2028, tap_1863, ((t_sample)0.5));
			t_sample add_2013 = (sah_2031 + wrap_2025);
			t_sample switch_2016 = (gte_1841 ? add_2013 : ((int)-1));
			int index_trunc_44 = fixnan(floor(switch_2016));
			bool index_ignore_45 = ((index_trunc_44 >= segments_dim) || (index_trunc_44 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2019 = (index_ignore_45 ? 0 : m_segments_34.read(index_trunc_44, 0));
			t_sample index_segments_2020 = switch_2016;
			t_sample mul_2010 = (sample_segments_2019 * expr_2032);
			t_sample plusequals_2051 = __m_pluseq_46.post(((int)-1), tap_1865, 0);
			t_sample noise_2047 = noise();
			t_sample abs_2046 = fabs(noise_2047);
			t_sample sub_2042 = (clamp_2067 - ((int)50));
			t_sample mul_2045 = (abs_2046 * sub_2042);
			t_sample sah_2048 = __m_sah_47(mul_2045, tap_1865, ((t_sample)0.5));
			t_sample add_2039 = (sah_2048 + ((int)50));
			t_sample wrap_2049 = wrap(plusequals_2051, ((int)0), add_2039);
			t_sample div_2036 = safediv(wrap_2049, add_2039);
			t_sample expr_2056 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2036))));
			t_sample noise_2054 = noise();
			t_sample abs_2053 = fabs(noise_2054);
			t_sample mul_2052 = (abs_2053 * mul_2179);
			t_sample sah_2055 = __m_sah_48(mul_2052, tap_1865, ((t_sample)0.5));
			t_sample add_2037 = (sah_2055 + wrap_2049);
			t_sample switch_2040 = (gte_1842 ? add_2037 : ((int)-1));
			int index_trunc_49 = fixnan(floor(switch_2040));
			bool index_ignore_50 = ((index_trunc_49 >= segments_dim) || (index_trunc_49 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2043 = (index_ignore_50 ? 0 : m_segments_34.read(index_trunc_49, 0));
			t_sample index_segments_2044 = switch_2040;
			t_sample mul_2034 = (sample_segments_2043 * expr_2056);
			t_sample mul_2064 = ((mul_2034 + mul_2010) * ((t_sample)0.4));
			t_sample mul_2065 = ((mul_2034 + mul_2010) * ((t_sample)0.3));
			t_sample plusequals_1979 = __m_pluseq_51.post(((int)-1), tap_1859, 0);
			t_sample noise_1975 = noise();
			t_sample abs_1974 = fabs(noise_1975);
			t_sample sub_1970 = (clamp_2067 - ((int)50));
			t_sample mul_1973 = (abs_1974 * sub_1970);
			t_sample sah_1976 = __m_sah_52(mul_1973, tap_1859, ((t_sample)0.5));
			t_sample add_1967 = (sah_1976 + ((int)50));
			t_sample wrap_1977 = wrap(plusequals_1979, ((int)0), add_1967);
			t_sample div_1964 = safediv(wrap_1977, add_1967);
			t_sample expr_1984 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1964))));
			t_sample noise_1982 = noise();
			t_sample abs_1981 = fabs(noise_1982);
			t_sample mul_1980 = (abs_1981 * mul_2179);
			t_sample sah_1983 = __m_sah_53(mul_1980, tap_1859, ((t_sample)0.5));
			t_sample add_1965 = (sah_1983 + wrap_1977);
			t_sample switch_1968 = (gte_1839 ? add_1965 : ((int)-1));
			int index_trunc_54 = fixnan(floor(switch_1968));
			bool index_ignore_55 = ((index_trunc_54 >= segments_dim) || (index_trunc_54 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1971 = (index_ignore_55 ? 0 : m_segments_34.read(index_trunc_54, 0));
			t_sample index_segments_1972 = switch_1968;
			t_sample mul_1962 = (sample_segments_1971 * expr_1984);
			t_sample plusequals_2003 = __m_pluseq_56.post(((int)-1), tap_1861, 0);
			t_sample noise_1999 = noise();
			t_sample abs_1998 = fabs(noise_1999);
			t_sample sub_1994 = (clamp_2067 - ((int)50));
			t_sample mul_1997 = (abs_1998 * sub_1994);
			t_sample sah_2000 = __m_sah_57(mul_1997, tap_1861, ((t_sample)0.5));
			t_sample add_1991 = (sah_2000 + ((int)50));
			t_sample wrap_2001 = wrap(plusequals_2003, ((int)0), add_1991);
			t_sample div_1988 = safediv(wrap_2001, add_1991);
			t_sample expr_2008 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1988))));
			t_sample noise_2006 = noise();
			t_sample abs_2005 = fabs(noise_2006);
			t_sample mul_2004 = (abs_2005 * mul_2179);
			t_sample sah_2007 = __m_sah_58(mul_2004, tap_1861, ((t_sample)0.5));
			t_sample add_1989 = (sah_2007 + wrap_2001);
			t_sample switch_1992 = (gte_1840 ? add_1989 : ((int)-1));
			int index_trunc_59 = fixnan(floor(switch_1992));
			bool index_ignore_60 = ((index_trunc_59 >= segments_dim) || (index_trunc_59 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1995 = (index_ignore_60 ? 0 : m_segments_34.read(index_trunc_59, 0));
			t_sample index_segments_1996 = switch_1992;
			t_sample mul_1986 = (sample_segments_1995 * expr_2008);
			t_sample mul_2062 = ((mul_1986 + mul_1962) * ((t_sample)0.3));
			t_sample mul_2063 = ((mul_1986 + mul_1962) * ((t_sample)0.4));
			t_sample plusequals_1883 = __m_pluseq_61.post(((int)-1), tap_1851, 0);
			t_sample noise_1879 = noise();
			t_sample abs_1878 = fabs(noise_1879);
			t_sample sub_1874 = (clamp_2067 - ((int)50));
			t_sample mul_1877 = (abs_1878 * sub_1874);
			t_sample sah_1880 = __m_sah_62(mul_1877, tap_1851, ((t_sample)0.5));
			t_sample add_1871 = (sah_1880 + ((int)50));
			t_sample wrap_1881 = wrap(plusequals_1883, ((int)0), add_1871);
			t_sample div_1868 = safediv(wrap_1881, add_1871);
			t_sample expr_1888 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1868))));
			t_sample noise_1886 = noise();
			t_sample abs_1885 = fabs(noise_1886);
			t_sample mul_1884 = (abs_1885 * mul_2179);
			t_sample sah_1887 = __m_sah_63(mul_1884, tap_1851, ((t_sample)0.5));
			t_sample add_1869 = (sah_1887 + wrap_1881);
			t_sample switch_1872 = (gte_1835 ? add_1869 : ((int)-1));
			int index_trunc_64 = fixnan(floor(switch_1872));
			bool index_ignore_65 = ((index_trunc_64 >= segments_dim) || (index_trunc_64 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1875 = (index_ignore_65 ? 0 : m_segments_34.read(index_trunc_64, 0));
			t_sample index_segments_1876 = switch_1872;
			t_sample mul_1866 = (sample_segments_1875 * expr_1888);
			t_sample plusequals_1907 = __m_pluseq_66.post(((int)-1), tap_1853, 0);
			t_sample noise_1903 = noise();
			t_sample abs_1902 = fabs(noise_1903);
			t_sample sub_1898 = (clamp_2067 - ((int)50));
			t_sample mul_1901 = (abs_1902 * sub_1898);
			t_sample sah_1904 = __m_sah_67(mul_1901, tap_1853, ((t_sample)0.5));
			t_sample add_1895 = (sah_1904 + ((int)50));
			t_sample wrap_1905 = wrap(plusequals_1907, ((int)0), add_1895);
			t_sample div_1892 = safediv(wrap_1905, add_1895);
			t_sample expr_1912 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1892))));
			t_sample noise_1910 = noise();
			t_sample abs_1909 = fabs(noise_1910);
			t_sample mul_1908 = (abs_1909 * mul_2179);
			t_sample sah_1911 = __m_sah_68(mul_1908, tap_1853, ((t_sample)0.5));
			t_sample add_1893 = (sah_1911 + wrap_1905);
			t_sample switch_1896 = (gte_1836 ? add_1893 : ((int)-1));
			int index_trunc_69 = fixnan(floor(switch_1896));
			bool index_ignore_70 = ((index_trunc_69 >= segments_dim) || (index_trunc_69 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1899 = (index_ignore_70 ? 0 : m_segments_34.read(index_trunc_69, 0));
			t_sample index_segments_1900 = switch_1896;
			t_sample mul_1890 = (sample_segments_1899 * expr_1912);
			t_sample mul_2058 = ((mul_1890 + mul_1866) * ((t_sample)0.2));
			t_sample mul_2059 = ((mul_1890 + mul_1866) * ((t_sample)0.5));
			t_sample plusequals_1931 = __m_pluseq_71.post(((int)-1), tap_1855, 0);
			t_sample noise_1927 = noise();
			t_sample abs_1926 = fabs(noise_1927);
			t_sample sub_1922 = (clamp_2067 - ((int)50));
			t_sample mul_1925 = (abs_1926 * sub_1922);
			t_sample sah_1928 = __m_sah_72(mul_1925, tap_1855, ((t_sample)0.5));
			t_sample add_1919 = (sah_1928 + ((int)50));
			t_sample wrap_1929 = wrap(plusequals_1931, ((int)0), add_1919);
			t_sample div_1916 = safediv(wrap_1929, add_1919);
			t_sample expr_1936 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1916))));
			t_sample noise_1934 = noise();
			t_sample abs_1933 = fabs(noise_1934);
			t_sample mul_1932 = (abs_1933 * mul_2179);
			t_sample sah_1935 = __m_sah_73(mul_1932, tap_1855, ((t_sample)0.5));
			t_sample add_1917 = (sah_1935 + wrap_1929);
			t_sample switch_1920 = (gte_1837 ? add_1917 : ((int)-1));
			int index_trunc_74 = fixnan(floor(switch_1920));
			bool index_ignore_75 = ((index_trunc_74 >= segments_dim) || (index_trunc_74 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1923 = (index_ignore_75 ? 0 : m_segments_34.read(index_trunc_74, 0));
			t_sample index_segments_1924 = switch_1920;
			t_sample mul_1914 = (sample_segments_1923 * expr_1936);
			t_sample plusequals_1955 = __m_pluseq_76.post(((int)-1), tap_1857, 0);
			t_sample noise_1951 = noise();
			t_sample abs_1950 = fabs(noise_1951);
			t_sample sub_1946 = (clamp_2067 - ((int)50));
			t_sample mul_1949 = (abs_1950 * sub_1946);
			t_sample sah_1952 = __m_sah_77(mul_1949, tap_1857, ((t_sample)0.5));
			t_sample add_1943 = (sah_1952 + ((int)50));
			t_sample wrap_1953 = wrap(plusequals_1955, ((int)0), add_1943);
			t_sample div_1940 = safediv(wrap_1953, add_1943);
			t_sample expr_1960 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1940))));
			t_sample noise_1958 = noise();
			t_sample abs_1957 = fabs(noise_1958);
			t_sample mul_1956 = (abs_1957 * mul_2179);
			t_sample sah_1959 = __m_sah_78(mul_1956, tap_1857, ((t_sample)0.5));
			t_sample add_1941 = (sah_1959 + wrap_1953);
			t_sample switch_1944 = (gte_1838 ? add_1941 : ((int)-1));
			int index_trunc_79 = fixnan(floor(switch_1944));
			bool index_ignore_80 = ((index_trunc_79 >= segments_dim) || (index_trunc_79 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1947 = (index_ignore_80 ? 0 : m_segments_34.read(index_trunc_79, 0));
			t_sample index_segments_1948 = switch_1944;
			t_sample mul_1938 = (sample_segments_1947 * expr_1960);
			t_sample mul_2060 = ((mul_1938 + mul_1914) * ((t_sample)0.5));
			t_sample mul_2061 = ((mul_1938 + mul_1914) * ((t_sample)0.2));
			int gt_2149 = (phasor_2190 > ((t_sample)0.49));
			int change_2148 = __m_change_81(gt_2149);
			int eq_2147 = (change_2148 == ((int)1));
			t_sample add_1796 = (m_history_5 + ((int)1));
			int gt_1795 = (m_history_5 > mstosamps_1798);
			int mul_1794 = (eq_2147 * gt_1795);
			int and_1792 = (gt_1795 && eq_2147);
			t_sample switch_1793 = (and_1792 ? ((int)0) : add_1796);
			t_sample history_1797_next_1800 = fixdenorm(switch_1793);
			int plusequals_2134 = __m_pluseq_82.post(((int)-1), mul_1794, 0);
			t_sample noise_2130 = noise();
			t_sample abs_2129 = fabs(noise_2130);
			t_sample sub_2125 = (clamp_2067 - ((int)50));
			t_sample mul_2128 = (abs_2129 * sub_2125);
			t_sample sah_2131 = __m_sah_83(mul_2128, mul_1794, ((t_sample)0.5));
			t_sample add_2122 = (sah_2131 + ((int)50));
			t_sample wrap_2132 = wrap(plusequals_2134, ((int)0), add_2122);
			t_sample div_2119 = safediv(wrap_2132, add_2122);
			t_sample expr_2139 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2119))));
			t_sample noise_2137 = noise();
			t_sample abs_2136 = fabs(noise_2137);
			t_sample mul_2135 = (abs_2136 * mul_2179);
			t_sample sah_2138 = __m_sah_84(mul_2135, mul_1794, ((t_sample)0.5));
			t_sample add_2120 = (sah_2138 + wrap_2132);
			t_sample switch_2123 = (gte_1845 ? add_2120 : ((int)-1));
			int index_trunc_85 = fixnan(floor(switch_2123));
			bool index_ignore_86 = ((index_trunc_85 >= segments_dim) || (index_trunc_85 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2126 = (index_ignore_86 ? 0 : m_segments_34.read(index_trunc_85, 0));
			t_sample index_segments_2127 = switch_2123;
			t_sample mul_2117 = (sample_segments_2126 * expr_2139);
			int gt_2146 = (phasor_2190 > ((t_sample)0.51));
			int change_2145 = __m_change_87(gt_2146);
			int eq_2144 = (change_2145 == ((int)1));
			t_sample add_1785 = (m_history_4 + ((int)1));
			int gt_1784 = (m_history_4 > mstosamps_1787);
			int mul_1783 = (eq_2144 * gt_1784);
			int and_1781 = (gt_1784 && eq_2144);
			t_sample switch_1782 = (and_1781 ? ((int)0) : add_1785);
			t_sample history_1786_next_1789 = fixdenorm(switch_1782);
			int plusequals_2110 = __m_pluseq_88.post(((int)-1), mul_1783, 0);
			t_sample noise_2106 = noise();
			t_sample abs_2105 = fabs(noise_2106);
			t_sample sub_2101 = (clamp_2067 - ((int)50));
			t_sample mul_2104 = (abs_2105 * sub_2101);
			t_sample sah_2107 = __m_sah_89(mul_2104, mul_1783, ((t_sample)0.5));
			t_sample add_2098 = (sah_2107 + ((int)50));
			t_sample wrap_2108 = wrap(plusequals_2110, ((int)0), add_2098);
			t_sample div_2095 = safediv(wrap_2108, add_2098);
			t_sample expr_2115 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2095))));
			t_sample noise_2113 = noise();
			t_sample abs_2112 = fabs(noise_2113);
			t_sample mul_2111 = (abs_2112 * mul_2179);
			t_sample sah_2114 = __m_sah_90(mul_2111, mul_1783, ((t_sample)0.5));
			t_sample add_2096 = (sah_2114 + wrap_2108);
			t_sample switch_2099 = (gte_1844 ? add_2096 : ((int)-1));
			int index_trunc_91 = fixnan(floor(switch_2099));
			bool index_ignore_92 = ((index_trunc_91 >= segments_dim) || (index_trunc_91 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2102 = (index_ignore_92 ? 0 : m_segments_34.read(index_trunc_91, 0));
			t_sample index_segments_2103 = switch_2099;
			t_sample mul_2093 = (sample_segments_2102 * expr_2115);
			int gt_2143 = (phasor_2190 > ((t_sample)0.48));
			int change_2142 = __m_change_93(gt_2143);
			int eq_2141 = (change_2142 == ((int)1));
			t_sample add_1774 = (m_history_3 + ((int)1));
			int gt_1773 = (m_history_3 > mstosamps_1776);
			int mul_1772 = (eq_2141 * gt_1773);
			int and_1770 = (gt_1773 && eq_2141);
			t_sample switch_1771 = (and_1770 ? ((int)0) : add_1774);
			t_sample history_1775_next_1778 = fixdenorm(switch_1771);
			int plusequals_2086 = __m_pluseq_94.post(((int)-1), mul_1772, 0);
			t_sample noise_2082 = noise();
			t_sample abs_2081 = fabs(noise_2082);
			t_sample sub_2077 = (clamp_2067 - ((int)50));
			t_sample mul_2080 = (abs_2081 * sub_2077);
			t_sample sah_2083 = __m_sah_95(mul_2080, mul_1772, ((t_sample)0.5));
			t_sample add_2074 = (sah_2083 + ((int)50));
			t_sample wrap_2084 = wrap(plusequals_2086, ((int)0), add_2074);
			t_sample div_2071 = safediv(wrap_2084, add_2074);
			t_sample expr_2091 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2071))));
			t_sample noise_2089 = noise();
			t_sample abs_2088 = fabs(noise_2089);
			t_sample mul_2087 = (abs_2088 * mul_2179);
			t_sample sah_2090 = __m_sah_96(mul_2087, mul_1772, ((t_sample)0.5));
			t_sample add_2072 = (sah_2090 + wrap_2084);
			t_sample switch_2075 = (gte_1843 ? add_2072 : ((int)-1));
			int index_trunc_97 = fixnan(floor(switch_2075));
			bool index_ignore_98 = ((index_trunc_97 >= segments_dim) || (index_trunc_97 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2078 = (index_ignore_98 ? 0 : m_segments_34.read(index_trunc_97, 0));
			t_sample index_segments_2079 = switch_2075;
			t_sample mul_2069 = (sample_segments_2078 * expr_2091);
			int gt_2187 = (phasor_2190 > ((t_sample)0.5));
			int change_2186 = __m_change_99(gt_2187);
			int eq_2185 = (change_2186 == ((int)1));
			t_sample add_1807 = (m_history_2 + ((int)1));
			int gt_1806 = (m_history_2 > mstosamps_1809);
			int mul_1805 = (eq_2185 * gt_1806);
			int and_1803 = (gt_1806 && eq_2185);
			t_sample switch_1804 = (and_1803 ? ((int)0) : add_1807);
			t_sample history_1808_next_1811 = fixdenorm(switch_1804);
			int plusequals_2168 = __m_pluseq_100.post(((int)-1), mul_1805, 0);
			t_sample noise_2164 = noise();
			t_sample abs_2163 = fabs(noise_2164);
			t_sample sub_2159 = (clamp_2067 - ((int)50));
			t_sample mul_2162 = (abs_2163 * sub_2159);
			t_sample sah_2165 = __m_sah_101(mul_2162, mul_1805, ((t_sample)0.5));
			t_sample add_2156 = (sah_2165 + ((int)50));
			t_sample wrap_2166 = wrap(plusequals_2168, ((int)0), add_2156);
			t_sample div_2153 = safediv(wrap_2166, add_2156);
			t_sample expr_2173 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2153))));
			t_sample noise_2171 = noise();
			t_sample abs_2170 = fabs(noise_2171);
			t_sample mul_2169 = (abs_2170 * mul_2179);
			t_sample sah_2172 = __m_sah_102(mul_2169, mul_1805, ((t_sample)0.5));
			t_sample add_2154 = (sah_2172 + wrap_2166);
			t_sample switch_2157 = (gte_1846 ? add_2154 : ((int)-1));
			int index_trunc_103 = fixnan(floor(switch_2157));
			bool index_ignore_104 = ((index_trunc_103 >= segments_dim) || (index_trunc_103 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2160 = (index_ignore_104 ? 0 : m_segments_34.read(index_trunc_103, 0));
			t_sample index_segments_2161 = switch_2157;
			t_sample mul_2151 = (sample_segments_2160 * expr_2173);
			t_sample mul_2150 = ((((mul_2151 + mul_2069) + mul_2093) + mul_2117) * ((t_sample)0.7));
			t_sample mul_1848 = (((((mul_2060 + mul_2058) + mul_2062) + mul_2064) + mul_2150) * scale_2298);
			t_sample dcblock_1814 = __m_dcblock_105(mul_1848);
			t_sample mul_1817 = (sqrt_1816 * dcblock_1814);
			t_sample out2 = ((mul_1817 + mul_1819) + gate_2197);
			t_sample mul_1849 = (((((mul_2061 + mul_2059) + mul_2063) + mul_2065) + mul_2150) * scale_2298);
			t_sample dcblock_1815 = __m_dcblock_106(mul_1849);
			t_sample mul_1818 = (sqrt_1816 * dcblock_1815);
			t_sample out1 = ((mul_1818 + mul_1819) + gate_2197);
			t_sample history_2180_next_2240 = fixdenorm(eq_2181);
			m_history_26 = history_2193_next_2195;
			m_history_25 = history_1825_next_1827;
			m_history_23 = history_1821_next_1829;
			m_history_24 = history_1823_next_1828;
			m_history_22 = history_1825_next_2206;
			m_history_20 = history_1821_next_2203;
			m_history_21 = history_1823_next_2207;
			m_history_19 = history_1825_next_2217;
			m_history_17 = history_1821_next_2215;
			m_history_18 = history_1823_next_2221;
			m_delay_16.write(mul_1794);
			m_delay_15.write(mul_1805);
			m_delay_14.write(mul_1772);
			m_delay_13.write(mul_1783);
			m_delay_12.write(tap_1859);
			m_delay_11.write(tap_1861);
			m_delay_10.write(tap_1863);
			m_delay_9.write(tap_1865);
			m_history_8 = history_1825_next_2231;
			m_history_6 = history_1821_next_2227;
			m_history_7 = history_1823_next_2234;
			m_history_5 = history_1797_next_1800;
			m_history_4 = history_1786_next_1789;
			m_history_3 = history_1775_next_1778;
			m_history_2 = history_1808_next_1811;
			m_history_1 = history_2180_next_2240;
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
	inline void set_sw2(t_param _value) {
		m_sw_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_glitchlen(t_param _value) {
		m_knob5_glitchlen_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_density(t_param _value) {
		m_knob6_density_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_rate(t_param _value) {
		m_knob3_rate_30 = (_value < 0.01 ? 0.01 : (_value > 16 ? 16 : _value));
	};
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 1: self->set_knob3_rate(value); break;
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
		case 0: *value = self->m_knob1_wetdry_33; break;
		case 1: *value = self->m_knob3_rate_30; break;
		case 2: *value = self->m_knob4_buflen_31; break;
		case 3: *value = self->m_knob5_glitchlen_28; break;
		case 4: *value = self->m_knob6_density_29; break;
		
		case 6: *value = self->m_sw_32; break;
		case 7: *value = self->m_sw_27; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_33")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_rate_30")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_rate_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_buflen_31")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_buflen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_buflen_31;
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
	// initialize parameter 4 ("m_knob6_density_29")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_density";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_density_29;
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
	// initialize parameter 6 ("m_sw_32")
	pi = self->__commonstate.params + 6;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_sw_27")
	pi = self->__commonstate.params + 7;
	pi->name = "sw2";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Glitch2::
