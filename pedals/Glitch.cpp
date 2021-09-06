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
	t_sample m_knob4_buflen_32;
	t_sample m_knob1_wetdry_33;
	t_sample m_history_3;
	t_sample m_sw_31;
	t_sample samplerate;
	t_sample m_knob6_density_27;
	t_sample m_knob3_thresh_30;
	t_sample m_knob5_glitchlen_28;
	t_sample m_sw_29;
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
		m_sw_29 = ((int)0);
		m_knob3_thresh_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_knob4_buflen_32 = ((int)0);
		m_knob1_wetdry_33 = ((int)0);
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
		t_sample mstosamps_2087 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_2085 = (((int)100) * (samplerate * 0.001));
		t_sample iup_41 = (1 / maximum(1, abs(mstosamps_2087)));
		t_sample idown_42 = (1 / maximum(1, abs(mstosamps_2085)));
		t_sample mstosamps_1698 = (((int)1) * (samplerate * 0.001));
		t_sample mul_2033 = (m_knob3_thresh_30 * ((t_sample)0.95));
		t_sample mstosamps_1687 = (((int)1) * (samplerate * 0.001));
		t_sample mul_2032 = (m_knob3_thresh_30 * ((t_sample)1.03));
		t_sample mstosamps_1676 = (((int)1) * (samplerate * 0.001));
		t_sample mul_2031 = (m_knob3_thresh_30 * ((t_sample)0.98));
		t_sample mstosamps_1665 = (((int)1) * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_2093 = __m_sah_35(m_history_26, m_sw_31, ((int)0));
			t_sample gen_2095 = sah_2093;
			t_sample rsub_2091 = (((int)1) - sah_2093);
			t_sample history_2092_next_2094 = fixdenorm(rsub_2091);
			t_sample out3 = gen_2095;
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample mix_2261 = (m_history_25 + (((t_sample)0.003926980723806) * (m_knob4_buflen_32 - m_history_25)));
			t_sample mix_1713 = mix_2261;
			t_sample mix_2262 = (m_history_24 + (((t_sample)0.003926980723806) * (mix_1713 - m_history_24)));
			t_sample mix_1711 = mix_2262;
			t_sample mix_2263 = (m_history_23 + (((t_sample)0.003926980723806) * (mix_1711 - m_history_23)));
			t_sample mix_1709 = mix_2263;
			t_sample gen_2071 = mix_1709;
			t_sample history_1714_next_1716 = fixdenorm(mix_1713);
			t_sample history_1712_next_1717 = fixdenorm(mix_1711);
			t_sample history_1710_next_1718 = fixdenorm(mix_1709);
			t_sample expr_2099 = (((int)1) - sqrt((((int)1) - gen_2071)));
			t_sample add_2098 = (gen_2095 + ((int)1));
			t_sample choice_36 = int(add_2098);
			t_sample gate_2096 = (((choice_36 >= 1) && (choice_36 < 2)) ? in1 : 0);
			t_sample gate_2097 = ((choice_36 >= 2) ? in1 : 0);
			t_sample mix_2264 = (m_history_22 + (((t_sample)0.003926980723806) * (m_knob1_wetdry_33 - m_history_22)));
			t_sample mix_2105 = mix_2264;
			t_sample mix_2265 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_2105 - m_history_21)));
			t_sample mix_2109 = mix_2265;
			t_sample mix_2266 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_2109 - m_history_20)));
			t_sample mix_2102 = mix_2266;
			t_sample gen_1719 = mix_2102;
			t_sample history_1714_next_2104 = fixdenorm(mix_2105);
			t_sample history_1712_next_2107 = fixdenorm(mix_2109);
			t_sample history_1710_next_2106 = fixdenorm(mix_2102);
			t_sample sqrt_1705 = sqrt(gen_1719);
			t_sample rsub_1721 = (((int)1) - gen_1719);
			t_sample sqrt_1720 = sqrt(rsub_1721);
			t_sample mul_1708 = (sqrt_1720 * gate_2097);
			t_sample mul_2072 = (expr_2099 * ((int)480000));
			t_sample plusequals_2089 = __m_pluseq_37.post(((int)1), m_history_1, 0);
			t_sample switch_2069 = (m_sw_29 ? ((int)-1) : plusequals_2089);
			int index_trunc_38 = fixnan(floor(switch_2069));
			bool index_ignore_39 = ((index_trunc_38 >= segments_dim) || (index_trunc_38 < 0));
			if ((!index_ignore_39)) {
				m_segments_34.write(gate_2097, index_trunc_38, 0);
				
			};
			int gte_2075 = (plusequals_2089 >= mul_2072);
			int eq_2074 = (gte_2075 == ((int)1));
			t_sample abs_2090 = fabs(gate_2097);
			t_sample mul_1723 = (abs_2090 * ((int)30));
			__m_slide_40 = fixdenorm((__m_slide_40 + (((mul_1723 > __m_slide_40) ? iup_41 : idown_42) * (mul_1723 - __m_slide_40))));
			t_sample slide_2088 = __m_slide_40;
			t_sample clamp_2083 = ((slide_2088 <= ((int)0)) ? ((int)0) : ((slide_2088 >= ((int)1)) ? ((int)1) : slide_2088));
			t_sample out4 = clamp_2083;
			t_sample mix_2267 = (m_history_19 + (((t_sample)0.003926980723806) * (m_knob6_density_27 - m_history_19)));
			t_sample mix_2117 = mix_2267;
			t_sample mix_2268 = (m_history_18 + (((t_sample)0.003926980723806) * (mix_2117 - m_history_18)));
			t_sample mix_2119 = mix_2268;
			t_sample mix_2269 = (m_history_17 + (((t_sample)0.003926980723806) * (mix_2119 - m_history_17)));
			t_sample mix_2115 = mix_2269;
			t_sample gen_1956 = mix_2115;
			t_sample history_1714_next_2120 = fixdenorm(mix_2117);
			t_sample history_1712_next_2122 = fixdenorm(mix_2119);
			t_sample history_1710_next_2121 = fixdenorm(mix_2115);
			t_sample sub_2273 = (gen_1956 - ((int)0));
			t_sample scale_2270 = ((safepow((sub_2273 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_1753 = m_delay_16.read_step(((int)8));
			t_sample tap_1755 = m_delay_15.read_step(((int)8));
			t_sample tap_1749 = m_delay_14.read_step(((int)8));
			t_sample tap_1751 = m_delay_13.read_step(((int)8));
			t_sample tap_1741 = m_delay_12.read_step(((int)8));
			t_sample tap_1743 = m_delay_11.read_step(((int)8));
			t_sample tap_1745 = m_delay_10.read_step(((int)9));
			t_sample tap_1747 = m_delay_9.read_step(((int)8));
			t_sample mul_1737 = (gen_1956 * ((int)12));
			int gte_1735 = (mul_1737 >= ((int)1));
			int gte_1734 = (mul_1737 >= ((int)2));
			int gte_1733 = (mul_1737 >= ((int)3));
			int gte_1736 = (mul_1737 >= ((int)0));
			int gte_1731 = (mul_1737 >= ((int)5));
			int gte_1732 = (mul_1737 >= ((int)4));
			int gte_1729 = (mul_1737 >= ((int)7));
			int gte_1730 = (mul_1737 >= ((int)6));
			int gte_1725 = (mul_1737 >= ((int)11));
			int gte_1726 = (mul_1737 >= ((int)10));
			int gte_1727 = (mul_1737 >= ((int)9));
			int gte_1728 = (mul_1737 >= ((int)8));
			t_sample mix_2274 = (m_history_8 + (((t_sample)0.003926980723806) * (m_knob5_glitchlen_28 - m_history_8)));
			t_sample mix_2129 = mix_2274;
			t_sample mix_2275 = (m_history_7 + (((t_sample)0.003926980723806) * (mix_2129 - m_history_7)));
			t_sample mix_2132 = mix_2275;
			t_sample mix_2276 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_2132 - m_history_6)));
			t_sample mix_2135 = mix_2276;
			t_sample gen_1958 = mix_2135;
			t_sample history_1714_next_2133 = fixdenorm(mix_2129);
			t_sample history_1712_next_2130 = fixdenorm(mix_2132);
			t_sample history_1710_next_2134 = fixdenorm(mix_2135);
			t_sample mul_1702 = (mul_2072 * gen_1958);
			t_sample clamp_1957 = ((mul_1702 <= ((int)50)) ? ((int)50) : ((mul_1702 >= ((int)480000)) ? ((int)480000) : mul_1702));
			t_sample plusequals_1917 = __m_pluseq_43.post(((int)1), tap_1753, 0);
			t_sample noise_1912 = noise();
			t_sample abs_1911 = fabs(noise_1912);
			t_sample sub_1903 = (clamp_1957 - ((int)50));
			t_sample mul_1910 = (abs_1911 * sub_1903);
			t_sample sah_1913 = __m_sah_44(mul_1910, tap_1753, ((t_sample)0.5));
			t_sample add_1900 = (sah_1913 + ((int)50));
			t_sample mod_1909 = safemod(plusequals_1917, add_1900);
			t_sample div_1906 = safediv(mod_1909, add_1900);
			t_sample expr_1922 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1906))));
			t_sample noise_1920 = noise();
			t_sample abs_1919 = fabs(noise_1920);
			t_sample mul_1918 = (abs_1919 * mul_2072);
			t_sample sah_1921 = __m_sah_45(mul_1918, tap_1753, ((t_sample)0.5));
			t_sample add_1915 = (sah_1921 + mod_1909);
			t_sample mod_1914 = safemod(add_1915, mul_2072);
			t_sample switch_1901 = (gte_1731 ? mod_1914 : ((int)-1));
			int index_trunc_46 = fixnan(floor(switch_1901));
			bool index_ignore_47 = ((index_trunc_46 >= segments_dim) || (index_trunc_46 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1907 = (index_ignore_47 ? 0 : m_segments_34.read(index_trunc_46, 0));
			t_sample index_segments_1908 = switch_1901;
			t_sample mul_1904 = (sample_segments_1907 * expr_1922);
			t_sample plusequals_1941 = __m_pluseq_48.post(((int)1), tap_1755, 0);
			t_sample noise_1936 = noise();
			t_sample abs_1935 = fabs(noise_1936);
			t_sample sub_1927 = (clamp_1957 - ((int)50));
			t_sample mul_1934 = (abs_1935 * sub_1927);
			t_sample sah_1937 = __m_sah_49(mul_1934, tap_1755, ((t_sample)0.5));
			t_sample add_1924 = (sah_1937 + ((int)50));
			t_sample mod_1933 = safemod(plusequals_1941, add_1924);
			t_sample div_1930 = safediv(mod_1933, add_1924);
			t_sample expr_1946 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1930))));
			t_sample noise_1944 = noise();
			t_sample abs_1943 = fabs(noise_1944);
			t_sample mul_1942 = (abs_1943 * mul_2072);
			t_sample sah_1945 = __m_sah_50(mul_1942, tap_1755, ((t_sample)0.5));
			t_sample add_1939 = (sah_1945 + mod_1933);
			t_sample mod_1938 = safemod(add_1939, mul_2072);
			t_sample switch_1925 = (gte_1732 ? mod_1938 : ((int)-1));
			int index_trunc_51 = fixnan(floor(switch_1925));
			bool index_ignore_52 = ((index_trunc_51 >= segments_dim) || (index_trunc_51 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1931 = (index_ignore_52 ? 0 : m_segments_34.read(index_trunc_51, 0));
			t_sample index_segments_1932 = switch_1925;
			t_sample mul_1928 = (sample_segments_1931 * expr_1946);
			t_sample mul_1955 = ((mul_1928 + mul_1904) * ((t_sample)0.3));
			t_sample mul_1954 = ((mul_1928 + mul_1904) * ((t_sample)0.4));
			t_sample plusequals_1869 = __m_pluseq_53.post(((int)1), tap_1749, 0);
			t_sample noise_1864 = noise();
			t_sample abs_1863 = fabs(noise_1864);
			t_sample sub_1855 = (clamp_1957 - ((int)50));
			t_sample mul_1862 = (abs_1863 * sub_1855);
			t_sample sah_1865 = __m_sah_54(mul_1862, tap_1749, ((t_sample)0.5));
			t_sample add_1852 = (sah_1865 + ((int)50));
			t_sample mod_1861 = safemod(plusequals_1869, add_1852);
			t_sample div_1858 = safediv(mod_1861, add_1852);
			t_sample expr_1874 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1858))));
			t_sample noise_1872 = noise();
			t_sample abs_1871 = fabs(noise_1872);
			t_sample mul_1870 = (abs_1871 * mul_2072);
			t_sample sah_1873 = __m_sah_55(mul_1870, tap_1749, ((t_sample)0.5));
			t_sample add_1867 = (sah_1873 + mod_1861);
			t_sample mod_1866 = safemod(add_1867, mul_2072);
			t_sample switch_1853 = (gte_1729 ? mod_1866 : ((int)-1));
			int index_trunc_56 = fixnan(floor(switch_1853));
			bool index_ignore_57 = ((index_trunc_56 >= segments_dim) || (index_trunc_56 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1859 = (index_ignore_57 ? 0 : m_segments_34.read(index_trunc_56, 0));
			t_sample index_segments_1860 = switch_1853;
			t_sample mul_1856 = (sample_segments_1859 * expr_1874);
			t_sample plusequals_1893 = __m_pluseq_58.post(((int)1), tap_1751, 0);
			t_sample noise_1888 = noise();
			t_sample abs_1887 = fabs(noise_1888);
			t_sample sub_1879 = (clamp_1957 - ((int)50));
			t_sample mul_1886 = (abs_1887 * sub_1879);
			t_sample sah_1889 = __m_sah_59(mul_1886, tap_1751, ((t_sample)0.5));
			t_sample add_1876 = (sah_1889 + ((int)50));
			t_sample mod_1885 = safemod(plusequals_1893, add_1876);
			t_sample div_1882 = safediv(mod_1885, add_1876);
			t_sample expr_1898 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1882))));
			t_sample noise_1896 = noise();
			t_sample abs_1895 = fabs(noise_1896);
			t_sample mul_1894 = (abs_1895 * mul_2072);
			t_sample sah_1897 = __m_sah_60(mul_1894, tap_1751, ((t_sample)0.5));
			t_sample add_1891 = (sah_1897 + mod_1885);
			t_sample mod_1890 = safemod(add_1891, mul_2072);
			t_sample switch_1877 = (gte_1730 ? mod_1890 : ((int)-1));
			int index_trunc_61 = fixnan(floor(switch_1877));
			bool index_ignore_62 = ((index_trunc_61 >= segments_dim) || (index_trunc_61 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1883 = (index_ignore_62 ? 0 : m_segments_34.read(index_trunc_61, 0));
			t_sample index_segments_1884 = switch_1877;
			t_sample mul_1880 = (sample_segments_1883 * expr_1898);
			t_sample mul_1953 = ((mul_1880 + mul_1856) * ((t_sample)0.4));
			t_sample mul_1952 = ((mul_1880 + mul_1856) * ((t_sample)0.3));
			t_sample plusequals_1773 = __m_pluseq_63.post(((int)1), tap_1741, 0);
			t_sample noise_1768 = noise();
			t_sample abs_1767 = fabs(noise_1768);
			t_sample sub_1759 = (clamp_1957 - ((int)50));
			t_sample mul_1766 = (abs_1767 * sub_1759);
			t_sample sah_1769 = __m_sah_64(mul_1766, tap_1741, ((t_sample)0.5));
			t_sample add_1756 = (sah_1769 + ((int)50));
			t_sample mod_1765 = safemod(plusequals_1773, add_1756);
			t_sample div_1762 = safediv(mod_1765, add_1756);
			t_sample expr_1778 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1762))));
			t_sample noise_1776 = noise();
			t_sample abs_1775 = fabs(noise_1776);
			t_sample mul_1774 = (abs_1775 * mul_2072);
			t_sample sah_1777 = __m_sah_65(mul_1774, tap_1741, ((t_sample)0.5));
			t_sample add_1771 = (sah_1777 + mod_1765);
			t_sample mod_1770 = safemod(add_1771, mul_2072);
			t_sample switch_1757 = (gte_1725 ? mod_1770 : ((int)-1));
			int index_trunc_66 = fixnan(floor(switch_1757));
			bool index_ignore_67 = ((index_trunc_66 >= segments_dim) || (index_trunc_66 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1763 = (index_ignore_67 ? 0 : m_segments_34.read(index_trunc_66, 0));
			t_sample index_segments_1764 = switch_1757;
			t_sample mul_1760 = (sample_segments_1763 * expr_1778);
			t_sample plusequals_1797 = __m_pluseq_68.post(((int)1), tap_1743, 0);
			t_sample noise_1792 = noise();
			t_sample abs_1791 = fabs(noise_1792);
			t_sample sub_1783 = (clamp_1957 - ((int)50));
			t_sample mul_1790 = (abs_1791 * sub_1783);
			t_sample sah_1793 = __m_sah_69(mul_1790, tap_1743, ((t_sample)0.5));
			t_sample add_1780 = (sah_1793 + ((int)50));
			t_sample mod_1789 = safemod(plusequals_1797, add_1780);
			t_sample div_1786 = safediv(mod_1789, add_1780);
			t_sample expr_1802 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1786))));
			t_sample noise_1800 = noise();
			t_sample abs_1799 = fabs(noise_1800);
			t_sample mul_1798 = (abs_1799 * mul_2072);
			t_sample sah_1801 = __m_sah_70(mul_1798, tap_1743, ((t_sample)0.5));
			t_sample add_1795 = (sah_1801 + mod_1789);
			t_sample mod_1794 = safemod(add_1795, mul_2072);
			t_sample switch_1781 = (gte_1726 ? mod_1794 : ((int)-1));
			int index_trunc_71 = fixnan(floor(switch_1781));
			bool index_ignore_72 = ((index_trunc_71 >= segments_dim) || (index_trunc_71 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1787 = (index_ignore_72 ? 0 : m_segments_34.read(index_trunc_71, 0));
			t_sample index_segments_1788 = switch_1781;
			t_sample mul_1784 = (sample_segments_1787 * expr_1802);
			t_sample mul_1949 = ((mul_1784 + mul_1760) * ((t_sample)0.5));
			t_sample mul_1948 = ((mul_1784 + mul_1760) * ((t_sample)0.2));
			t_sample plusequals_1821 = __m_pluseq_73.post(((int)1), tap_1745, 0);
			t_sample noise_1816 = noise();
			t_sample abs_1815 = fabs(noise_1816);
			t_sample sub_1807 = (clamp_1957 - ((int)50));
			t_sample mul_1814 = (abs_1815 * sub_1807);
			t_sample sah_1817 = __m_sah_74(mul_1814, tap_1745, ((t_sample)0.5));
			t_sample add_1804 = (sah_1817 + ((int)50));
			t_sample mod_1813 = safemod(plusequals_1821, add_1804);
			t_sample div_1810 = safediv(mod_1813, add_1804);
			t_sample expr_1826 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1810))));
			t_sample noise_1824 = noise();
			t_sample abs_1823 = fabs(noise_1824);
			t_sample mul_1822 = (abs_1823 * mul_2072);
			t_sample sah_1825 = __m_sah_75(mul_1822, tap_1745, ((t_sample)0.5));
			t_sample add_1819 = (sah_1825 + mod_1813);
			t_sample mod_1818 = safemod(add_1819, mul_2072);
			t_sample switch_1805 = (gte_1727 ? mod_1818 : ((int)-1));
			int index_trunc_76 = fixnan(floor(switch_1805));
			bool index_ignore_77 = ((index_trunc_76 >= segments_dim) || (index_trunc_76 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1811 = (index_ignore_77 ? 0 : m_segments_34.read(index_trunc_76, 0));
			t_sample index_segments_1812 = switch_1805;
			t_sample mul_1808 = (sample_segments_1811 * expr_1826);
			t_sample plusequals_1845 = __m_pluseq_78.post(((int)1), tap_1747, 0);
			t_sample noise_1840 = noise();
			t_sample abs_1839 = fabs(noise_1840);
			t_sample sub_1831 = (clamp_1957 - ((int)50));
			t_sample mul_1838 = (abs_1839 * sub_1831);
			t_sample sah_1841 = __m_sah_79(mul_1838, tap_1747, ((t_sample)0.5));
			t_sample add_1828 = (sah_1841 + ((int)50));
			t_sample mod_1837 = safemod(plusequals_1845, add_1828);
			t_sample div_1834 = safediv(mod_1837, add_1828);
			t_sample expr_1850 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1834))));
			t_sample noise_1848 = noise();
			t_sample abs_1847 = fabs(noise_1848);
			t_sample mul_1846 = (abs_1847 * mul_2072);
			t_sample sah_1849 = __m_sah_80(mul_1846, tap_1747, ((t_sample)0.5));
			t_sample add_1843 = (sah_1849 + mod_1837);
			t_sample mod_1842 = safemod(add_1843, mul_2072);
			t_sample switch_1829 = (gte_1728 ? mod_1842 : ((int)-1));
			int index_trunc_81 = fixnan(floor(switch_1829));
			bool index_ignore_82 = ((index_trunc_81 >= segments_dim) || (index_trunc_81 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1835 = (index_ignore_82 ? 0 : m_segments_34.read(index_trunc_81, 0));
			t_sample index_segments_1836 = switch_1829;
			t_sample mul_1832 = (sample_segments_1835 * expr_1850);
			t_sample mul_1951 = ((mul_1832 + mul_1808) * ((t_sample)0.2));
			t_sample mul_1950 = ((mul_1832 + mul_1808) * ((t_sample)0.5));
			int gt_2080 = (clamp_2083 > m_knob3_thresh_30);
			int change_2079 = __m_change_83(gt_2080);
			int eq_2078 = (change_2079 == ((int)1));
			t_sample add_1696 = (m_history_5 + ((int)1));
			int gt_1695 = (m_history_5 > mstosamps_1698);
			int mul_1694 = (eq_2078 * gt_1695);
			int and_1692 = (gt_1695 && eq_2078);
			t_sample switch_1693 = (and_1692 ? ((int)0) : add_1696);
			t_sample history_1697_next_1700 = fixdenorm(switch_1693);
			int plusequals_2061 = __m_pluseq_84.post(((int)1), mul_1694, 0);
			t_sample noise_2056 = noise();
			t_sample abs_2055 = fabs(noise_2056);
			t_sample sub_2047 = (clamp_1957 - ((int)50));
			t_sample mul_2054 = (abs_2055 * sub_2047);
			t_sample sah_2057 = __m_sah_85(mul_2054, mul_1694, ((t_sample)0.5));
			t_sample add_2044 = (sah_2057 + ((int)50));
			t_sample mod_2053 = safemod(plusequals_2061, add_2044);
			t_sample div_2050 = safediv(mod_2053, add_2044);
			t_sample expr_2066 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2050))));
			t_sample noise_2064 = noise();
			t_sample abs_2063 = fabs(noise_2064);
			t_sample mul_2062 = (abs_2063 * mul_2072);
			t_sample sah_2065 = __m_sah_86(mul_2062, mul_1694, ((t_sample)0.5));
			t_sample add_2059 = (sah_2065 + mod_2053);
			t_sample mod_2058 = safemod(add_2059, mul_2072);
			t_sample switch_2045 = (gte_1736 ? mod_2058 : ((int)-1));
			int index_trunc_87 = fixnan(floor(switch_2045));
			bool index_ignore_88 = ((index_trunc_87 >= segments_dim) || (index_trunc_87 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2051 = (index_ignore_88 ? 0 : m_segments_34.read(index_trunc_87, 0));
			t_sample index_segments_2052 = switch_2045;
			t_sample mul_2048 = (sample_segments_2051 * expr_2066);
			int gt_2042 = (clamp_2083 > mul_2033);
			int change_2041 = __m_change_89(gt_2042);
			int eq_2040 = (change_2041 == ((int)1));
			t_sample add_1685 = (m_history_4 + ((int)1));
			int gt_1684 = (m_history_4 > mstosamps_1687);
			int mul_1683 = (eq_2040 * gt_1684);
			int and_1681 = (gt_1684 && eq_2040);
			t_sample switch_1682 = (and_1681 ? ((int)0) : add_1685);
			t_sample history_1686_next_1689 = fixdenorm(switch_1682);
			int plusequals_2024 = __m_pluseq_90.post(((int)1), mul_1683, 0);
			t_sample noise_2019 = noise();
			t_sample abs_2018 = fabs(noise_2019);
			t_sample sub_2010 = (clamp_1957 - ((int)50));
			t_sample mul_2017 = (abs_2018 * sub_2010);
			t_sample sah_2020 = __m_sah_91(mul_2017, mul_1683, ((t_sample)0.5));
			t_sample add_2007 = (sah_2020 + ((int)50));
			t_sample mod_2016 = safemod(plusequals_2024, add_2007);
			t_sample div_2013 = safediv(mod_2016, add_2007);
			t_sample expr_2029 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_2013))));
			t_sample noise_2027 = noise();
			t_sample abs_2026 = fabs(noise_2027);
			t_sample mul_2025 = (abs_2026 * mul_2072);
			t_sample sah_2028 = __m_sah_92(mul_2025, mul_1683, ((t_sample)0.5));
			t_sample add_2022 = (sah_2028 + mod_2016);
			t_sample mod_2021 = safemod(add_2022, mul_2072);
			t_sample switch_2008 = (gte_1735 ? mod_2021 : ((int)-1));
			int index_trunc_93 = fixnan(floor(switch_2008));
			bool index_ignore_94 = ((index_trunc_93 >= segments_dim) || (index_trunc_93 < 0));
			// samples segments channel 1;
			t_sample sample_segments_2014 = (index_ignore_94 ? 0 : m_segments_34.read(index_trunc_93, 0));
			t_sample index_segments_2015 = switch_2008;
			t_sample mul_2011 = (sample_segments_2014 * expr_2029);
			int gt_2039 = (clamp_2083 > mul_2032);
			int change_2038 = __m_change_95(gt_2039);
			int eq_2037 = (change_2038 == ((int)1));
			t_sample add_1674 = (m_history_3 + ((int)1));
			int gt_1673 = (m_history_3 > mstosamps_1676);
			int mul_1672 = (eq_2037 * gt_1673);
			int and_1670 = (gt_1673 && eq_2037);
			t_sample switch_1671 = (and_1670 ? ((int)0) : add_1674);
			t_sample history_1675_next_1678 = fixdenorm(switch_1671);
			int plusequals_2000 = __m_pluseq_96.post(((int)1), mul_1672, 0);
			t_sample noise_1995 = noise();
			t_sample abs_1994 = fabs(noise_1995);
			t_sample sub_1986 = (clamp_1957 - ((int)50));
			t_sample mul_1993 = (abs_1994 * sub_1986);
			t_sample sah_1996 = __m_sah_97(mul_1993, mul_1672, ((t_sample)0.5));
			t_sample add_1983 = (sah_1996 + ((int)50));
			t_sample mod_1992 = safemod(plusequals_2000, add_1983);
			t_sample div_1989 = safediv(mod_1992, add_1983);
			t_sample expr_2005 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1989))));
			t_sample noise_2003 = noise();
			t_sample abs_2002 = fabs(noise_2003);
			t_sample mul_2001 = (abs_2002 * mul_2072);
			t_sample sah_2004 = __m_sah_98(mul_2001, mul_1672, ((t_sample)0.5));
			t_sample add_1998 = (sah_2004 + mod_1992);
			t_sample mod_1997 = safemod(add_1998, mul_2072);
			t_sample switch_1984 = (gte_1734 ? mod_1997 : ((int)-1));
			int index_trunc_99 = fixnan(floor(switch_1984));
			bool index_ignore_100 = ((index_trunc_99 >= segments_dim) || (index_trunc_99 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1990 = (index_ignore_100 ? 0 : m_segments_34.read(index_trunc_99, 0));
			t_sample index_segments_1991 = switch_1984;
			t_sample mul_1987 = (sample_segments_1990 * expr_2005);
			int gt_2036 = (clamp_2083 > mul_2031);
			int change_2035 = __m_change_101(gt_2036);
			int eq_2034 = (change_2035 == ((int)1));
			t_sample add_1663 = (m_history_2 + ((int)1));
			int gt_1662 = (m_history_2 > mstosamps_1665);
			int mul_1661 = (eq_2034 * gt_1662);
			int and_1659 = (gt_1662 && eq_2034);
			t_sample switch_1660 = (and_1659 ? ((int)0) : add_1663);
			t_sample history_1664_next_1667 = fixdenorm(switch_1660);
			int plusequals_1976 = __m_pluseq_102.post(((int)1), mul_1661, 0);
			t_sample noise_1971 = noise();
			t_sample abs_1970 = fabs(noise_1971);
			t_sample sub_1962 = (clamp_1957 - ((int)50));
			t_sample mul_1969 = (abs_1970 * sub_1962);
			t_sample sah_1972 = __m_sah_103(mul_1969, mul_1661, ((t_sample)0.5));
			t_sample add_1959 = (sah_1972 + ((int)50));
			t_sample mod_1968 = safemod(plusequals_1976, add_1959);
			t_sample div_1965 = safediv(mod_1968, add_1959);
			t_sample expr_1981 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1965))));
			t_sample noise_1979 = noise();
			t_sample abs_1978 = fabs(noise_1979);
			t_sample mul_1977 = (abs_1978 * mul_2072);
			t_sample sah_1980 = __m_sah_104(mul_1977, mul_1661, ((t_sample)0.5));
			t_sample add_1974 = (sah_1980 + mod_1968);
			t_sample mod_1973 = safemod(add_1974, mul_2072);
			t_sample switch_1960 = (gte_1733 ? mod_1973 : ((int)-1));
			int index_trunc_105 = fixnan(floor(switch_1960));
			bool index_ignore_106 = ((index_trunc_105 >= segments_dim) || (index_trunc_105 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1966 = (index_ignore_106 ? 0 : m_segments_34.read(index_trunc_105, 0));
			t_sample index_segments_1967 = switch_1960;
			t_sample mul_1963 = (sample_segments_1966 * expr_1981);
			t_sample mul_2043 = ((((mul_2048 + mul_1963) + mul_1987) + mul_2011) * ((t_sample)0.7));
			t_sample mul_1739 = (((((mul_1951 + mul_1949) + mul_1953) + mul_1955) + mul_2043) * scale_2270);
			t_sample dcblock_1704 = __m_dcblock_107(mul_1739);
			t_sample mul_1707 = (sqrt_1705 * dcblock_1704);
			t_sample out1 = ((mul_1707 + mul_1708) + gate_2096);
			t_sample mul_1738 = (((((mul_1950 + mul_1948) + mul_1952) + mul_1954) + mul_2043) * scale_2270);
			t_sample dcblock_1703 = __m_dcblock_108(mul_1738);
			t_sample mul_1706 = (sqrt_1705 * dcblock_1703);
			t_sample out2 = ((mul_1706 + mul_1708) + gate_2096);
			t_sample history_2073_next_2139 = fixdenorm(eq_2074);
			m_history_26 = history_2092_next_2094;
			m_history_25 = history_1714_next_1716;
			m_history_23 = history_1710_next_1718;
			m_history_24 = history_1712_next_1717;
			m_history_22 = history_1714_next_2104;
			m_history_20 = history_1710_next_2106;
			m_history_21 = history_1712_next_2107;
			m_history_19 = history_1714_next_2120;
			m_history_17 = history_1710_next_2121;
			m_history_18 = history_1712_next_2122;
			m_delay_16.write(mul_1683);
			m_delay_15.write(mul_1694);
			m_delay_14.write(mul_1661);
			m_delay_13.write(mul_1672);
			m_delay_12.write(tap_1749);
			m_delay_11.write(tap_1751);
			m_delay_10.write(tap_1753);
			m_delay_9.write(tap_1755);
			m_history_8 = history_1714_next_2133;
			m_history_6 = history_1710_next_2134;
			m_history_7 = history_1712_next_2130;
			m_history_5 = history_1697_next_1700;
			m_history_4 = history_1686_next_1689;
			m_history_3 = history_1675_next_1678;
			m_history_2 = history_1664_next_1667;
			m_history_1 = history_2073_next_2139;
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
	inline void set_sw2(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_thresh(t_param _value) {
		m_knob3_thresh_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob1_wetdry_33; break;
		case 1: *value = self->m_knob3_thresh_30; break;
		case 2: *value = self->m_knob4_buflen_32; break;
		case 3: *value = self->m_knob5_glitchlen_28; break;
		case 4: *value = self->m_knob6_density_27; break;
		
		case 6: *value = self->m_sw_31; break;
		case 7: *value = self->m_sw_29; break;
		
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
	// initialize parameter 1 ("m_knob3_thresh_30")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_thresh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_thresh_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_buflen_32")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_buflen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_buflen_32;
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
	// initialize parameter 6 ("m_sw_31")
	pi = self->__commonstate.params + 6;
	pi->name = "sw1";
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
	// initialize parameter 7 ("m_sw_29")
	pi = self->__commonstate.params + 7;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_29;
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
