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
	t_sample m_knob3_thresh_32;
	t_sample m_sw_33;
	t_sample m_history_3;
	t_sample m_sw_31;
	t_sample samplerate;
	t_sample m_knob6_density_27;
	t_sample m_knob1_wetdry_30;
	t_sample m_knob4_buflen_28;
	t_sample m_knob5_glitchlen_29;
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
		m_knob4_buflen_28 = ((int)0);
		m_knob5_glitchlen_29 = ((int)0);
		m_knob1_wetdry_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_knob3_thresh_32 = ((int)0);
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
		t_sample mstosamps_1748 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_1746 = (((int)100) * (samplerate * 0.001));
		t_sample iup_41 = (1 / maximum(1, abs(mstosamps_1748)));
		t_sample idown_42 = (1 / maximum(1, abs(mstosamps_1746)));
		t_sample mstosamps_2086 = (((int)1) * (samplerate * 0.001));
		t_sample mul_1694 = (m_knob3_thresh_32 * ((t_sample)0.95));
		t_sample mstosamps_2293 = (((int)1) * (samplerate * 0.001));
		t_sample mul_1693 = (m_knob3_thresh_32 * ((t_sample)1.03));
		t_sample mstosamps_2401 = (((int)1) * (samplerate * 0.001));
		t_sample mul_1692 = (m_knob3_thresh_32 * ((t_sample)0.98));
		t_sample mstosamps_2509 = (((int)1) * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_1754 = __m_sah_35(m_history_26, m_sw_31, ((int)0));
			t_sample gen_1756 = sah_1754;
			t_sample rsub_1752 = (((int)1) - sah_1754);
			t_sample history_1753_next_1755 = fixdenorm(rsub_1752);
			t_sample out3 = gen_1756;
			t_sample mix_3950 = (m_history_25 + (((t_sample)0.0019634941468452) * (m_knob4_buflen_28 - m_history_25)));
			t_sample mix_1374 = mix_3950;
			t_sample mix_3951 = (m_history_24 + (((t_sample)0.0019634941468452) * (mix_1374 - m_history_24)));
			t_sample mix_1372 = mix_3951;
			t_sample mix_3952 = (m_history_23 + (((t_sample)0.0019634941468452) * (mix_1372 - m_history_23)));
			t_sample mix_1370 = mix_3952;
			t_sample gen_1732 = mix_1370;
			t_sample history_1375_next_1377 = fixdenorm(mix_1374);
			t_sample history_1373_next_1378 = fixdenorm(mix_1372);
			t_sample history_1371_next_1379 = fixdenorm(mix_1370);
			t_sample expr_3733 = (((int)1) - sqrt((((int)1) - gen_1732)));
			t_sample add_1759 = (gen_1756 + ((int)1));
			t_sample choice_36 = int(add_1759);
			t_sample gate_1757 = (((choice_36 >= 1) && (choice_36 < 2)) ? in1 : 0);
			t_sample gate_1758 = ((choice_36 >= 2) ? in1 : 0);
			t_sample mix_3953 = (m_history_22 + (((t_sample)0.0019634941468452) * (m_knob1_wetdry_30 - m_history_22)));
			t_sample mix_3738 = mix_3953;
			t_sample mix_3954 = (m_history_21 + (((t_sample)0.0019634941468452) * (mix_3738 - m_history_21)));
			t_sample mix_3739 = mix_3954;
			t_sample mix_3955 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_3739 - m_history_20)));
			t_sample mix_3742 = mix_3955;
			t_sample gen_1380 = mix_3742;
			t_sample history_1375_next_3741 = fixdenorm(mix_3738);
			t_sample history_1373_next_3740 = fixdenorm(mix_3739);
			t_sample history_1371_next_3734 = fixdenorm(mix_3742);
			t_sample sqrt_1366 = sqrt(gen_1380);
			t_sample rsub_1382 = (((int)1) - gen_1380);
			t_sample sqrt_1381 = sqrt(rsub_1382);
			t_sample mul_1369 = (sqrt_1381 * gate_1758);
			t_sample plusequals_1750 = __m_pluseq_37.post(((int)1), m_history_1, 0);
			t_sample switch_1730 = (m_sw_33 ? ((int)-1) : plusequals_1750);
			int index_trunc_38 = fixnan(floor(switch_1730));
			bool index_ignore_39 = ((index_trunc_38 >= segments_dim) || (index_trunc_38 < 0));
			if ((!index_ignore_39)) {
				m_segments_34.write(gate_1758, index_trunc_38, 0);
				
			};
			t_sample mul_1733 = (expr_3733 * ((int)480000));
			int gte_1736 = (plusequals_1750 >= mul_1733);
			int eq_1735 = (gte_1736 == ((int)1));
			t_sample abs_1751 = fabs(gate_1758);
			t_sample mul_1384 = (abs_1751 * ((int)30));
			__m_slide_40 = fixdenorm((__m_slide_40 + (((mul_1384 > __m_slide_40) ? iup_41 : idown_42) * (mul_1384 - __m_slide_40))));
			t_sample slide_1749 = __m_slide_40;
			t_sample clamp_1744 = ((slide_1749 <= ((int)0)) ? ((int)0) : ((slide_1749 >= ((int)1)) ? ((int)1) : slide_1749));
			t_sample out4 = clamp_1744;
			t_sample mix_3956 = (m_history_19 + (((t_sample)0.0019634941468452) * (m_knob6_density_27 - m_history_19)));
			t_sample mix_3749 = mix_3956;
			t_sample mix_3957 = (m_history_18 + (((t_sample)0.0019634941468452) * (mix_3749 - m_history_18)));
			t_sample mix_3750 = mix_3957;
			t_sample mix_3958 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_3750 - m_history_17)));
			t_sample mix_3755 = mix_3958;
			t_sample gen_1617 = mix_3755;
			t_sample history_1375_next_3747 = fixdenorm(mix_3749);
			t_sample history_1373_next_3753 = fixdenorm(mix_3750);
			t_sample history_1371_next_3751 = fixdenorm(mix_3755);
			t_sample sub_3962 = (gen_1617 - ((int)0));
			t_sample scale_3959 = ((safepow((sub_3962 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.3)) + ((int)1));
			t_sample tap_1414 = m_delay_16.read_step(((int)8));
			t_sample tap_1416 = m_delay_15.read_step(((int)8));
			t_sample tap_1410 = m_delay_14.read_step(((int)8));
			t_sample tap_1412 = m_delay_13.read_step(((int)8));
			t_sample tap_1402 = m_delay_12.read_step(((int)8));
			t_sample tap_1404 = m_delay_11.read_step(((int)8));
			t_sample tap_1406 = m_delay_10.read_step(((int)9));
			t_sample tap_1408 = m_delay_9.read_step(((int)8));
			t_sample mul_1398 = (gen_1617 * ((int)12));
			int gte_1396 = (mul_1398 >= ((int)1));
			int gte_1395 = (mul_1398 >= ((int)2));
			int gte_1394 = (mul_1398 >= ((int)3));
			int gte_1397 = (mul_1398 >= ((int)0));
			int gte_1392 = (mul_1398 >= ((int)5));
			int gte_1393 = (mul_1398 >= ((int)4));
			int gte_1390 = (mul_1398 >= ((int)7));
			int gte_1391 = (mul_1398 >= ((int)6));
			int gte_1386 = (mul_1398 >= ((int)11));
			int gte_1387 = (mul_1398 >= ((int)10));
			int gte_1388 = (mul_1398 >= ((int)9));
			int gte_1389 = (mul_1398 >= ((int)8));
			t_sample mix_3963 = (m_history_8 + (((t_sample)0.0019634941468452) * (m_knob5_glitchlen_29 - m_history_8)));
			t_sample mix_3771 = mix_3963;
			t_sample mix_3964 = (m_history_7 + (((t_sample)0.0019634941468452) * (mix_3771 - m_history_7)));
			t_sample mix_3772 = mix_3964;
			t_sample mix_3965 = (m_history_6 + (((t_sample)0.0019634941468452) * (mix_3772 - m_history_6)));
			t_sample mix_3776 = mix_3965;
			t_sample gen_1619 = mix_3776;
			t_sample history_1375_next_3774 = fixdenorm(mix_3771);
			t_sample history_1373_next_3769 = fixdenorm(mix_3772);
			t_sample history_1371_next_3773 = fixdenorm(mix_3776);
			t_sample mul_1363 = (mul_1733 * gen_1619);
			t_sample clamp_1618 = ((mul_1363 <= ((int)50)) ? ((int)50) : ((mul_1363 >= ((int)480000)) ? ((int)480000) : mul_1363));
			t_sample plusequals_1578 = __m_pluseq_43.post(((int)1), tap_1414, 0);
			t_sample noise_1573 = noise();
			t_sample abs_1572 = fabs(noise_1573);
			t_sample sub_1564 = (clamp_1618 - ((int)50));
			t_sample mul_1571 = (abs_1572 * sub_1564);
			t_sample sah_1574 = __m_sah_44(mul_1571, tap_1414, ((t_sample)0.5));
			t_sample add_1561 = (sah_1574 + ((int)50));
			t_sample mod_1570 = safemod(plusequals_1578, add_1561);
			t_sample div_1567 = safediv(mod_1570, add_1561);
			t_sample expr_1583 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1567))));
			t_sample noise_1581 = noise();
			t_sample abs_1580 = fabs(noise_1581);
			t_sample mul_1579 = (abs_1580 * mul_1733);
			t_sample sah_1582 = __m_sah_45(mul_1579, tap_1414, ((t_sample)0.5));
			t_sample add_1576 = (sah_1582 + mod_1570);
			t_sample mod_1575 = safemod(add_1576, mul_1733);
			t_sample switch_1562 = (gte_1392 ? mod_1575 : ((int)-1));
			int index_trunc_46 = fixnan(floor(switch_1562));
			bool index_ignore_47 = ((index_trunc_46 >= segments_dim) || (index_trunc_46 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1568 = (index_ignore_47 ? 0 : m_segments_34.read(index_trunc_46, 0));
			t_sample index_segments_1569 = switch_1562;
			t_sample mul_1565 = (sample_segments_1568 * expr_1583);
			t_sample plusequals_1602 = __m_pluseq_48.post(((int)1), tap_1416, 0);
			t_sample noise_1597 = noise();
			t_sample abs_1596 = fabs(noise_1597);
			t_sample sub_1588 = (clamp_1618 - ((int)50));
			t_sample mul_1595 = (abs_1596 * sub_1588);
			t_sample sah_1598 = __m_sah_49(mul_1595, tap_1416, ((t_sample)0.5));
			t_sample add_1585 = (sah_1598 + ((int)50));
			t_sample mod_1594 = safemod(plusequals_1602, add_1585);
			t_sample div_1591 = safediv(mod_1594, add_1585);
			t_sample expr_1607 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1591))));
			t_sample noise_1605 = noise();
			t_sample abs_1604 = fabs(noise_1605);
			t_sample mul_1603 = (abs_1604 * mul_1733);
			t_sample sah_1606 = __m_sah_50(mul_1603, tap_1416, ((t_sample)0.5));
			t_sample add_1600 = (sah_1606 + mod_1594);
			t_sample mod_1599 = safemod(add_1600, mul_1733);
			t_sample switch_1586 = (gte_1393 ? mod_1599 : ((int)-1));
			int index_trunc_51 = fixnan(floor(switch_1586));
			bool index_ignore_52 = ((index_trunc_51 >= segments_dim) || (index_trunc_51 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1592 = (index_ignore_52 ? 0 : m_segments_34.read(index_trunc_51, 0));
			t_sample index_segments_1593 = switch_1586;
			t_sample mul_1589 = (sample_segments_1592 * expr_1607);
			t_sample mul_1616 = ((mul_1589 + mul_1565) * ((t_sample)0.3));
			t_sample mul_1615 = ((mul_1589 + mul_1565) * ((t_sample)0.4));
			t_sample plusequals_1530 = __m_pluseq_53.post(((int)1), tap_1410, 0);
			t_sample noise_1525 = noise();
			t_sample abs_1524 = fabs(noise_1525);
			t_sample sub_1516 = (clamp_1618 - ((int)50));
			t_sample mul_1523 = (abs_1524 * sub_1516);
			t_sample sah_1526 = __m_sah_54(mul_1523, tap_1410, ((t_sample)0.5));
			t_sample add_1513 = (sah_1526 + ((int)50));
			t_sample mod_1522 = safemod(plusequals_1530, add_1513);
			t_sample div_1519 = safediv(mod_1522, add_1513);
			t_sample expr_1535 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1519))));
			t_sample noise_1533 = noise();
			t_sample abs_1532 = fabs(noise_1533);
			t_sample mul_1531 = (abs_1532 * mul_1733);
			t_sample sah_1534 = __m_sah_55(mul_1531, tap_1410, ((t_sample)0.5));
			t_sample add_1528 = (sah_1534 + mod_1522);
			t_sample mod_1527 = safemod(add_1528, mul_1733);
			t_sample switch_1514 = (gte_1390 ? mod_1527 : ((int)-1));
			int index_trunc_56 = fixnan(floor(switch_1514));
			bool index_ignore_57 = ((index_trunc_56 >= segments_dim) || (index_trunc_56 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1520 = (index_ignore_57 ? 0 : m_segments_34.read(index_trunc_56, 0));
			t_sample index_segments_1521 = switch_1514;
			t_sample mul_1517 = (sample_segments_1520 * expr_1535);
			t_sample plusequals_1554 = __m_pluseq_58.post(((int)1), tap_1412, 0);
			t_sample noise_1549 = noise();
			t_sample abs_1548 = fabs(noise_1549);
			t_sample sub_1540 = (clamp_1618 - ((int)50));
			t_sample mul_1547 = (abs_1548 * sub_1540);
			t_sample sah_1550 = __m_sah_59(mul_1547, tap_1412, ((t_sample)0.5));
			t_sample add_1537 = (sah_1550 + ((int)50));
			t_sample mod_1546 = safemod(plusequals_1554, add_1537);
			t_sample div_1543 = safediv(mod_1546, add_1537);
			t_sample expr_1559 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1543))));
			t_sample noise_1557 = noise();
			t_sample abs_1556 = fabs(noise_1557);
			t_sample mul_1555 = (abs_1556 * mul_1733);
			t_sample sah_1558 = __m_sah_60(mul_1555, tap_1412, ((t_sample)0.5));
			t_sample add_1552 = (sah_1558 + mod_1546);
			t_sample mod_1551 = safemod(add_1552, mul_1733);
			t_sample switch_1538 = (gte_1391 ? mod_1551 : ((int)-1));
			int index_trunc_61 = fixnan(floor(switch_1538));
			bool index_ignore_62 = ((index_trunc_61 >= segments_dim) || (index_trunc_61 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1544 = (index_ignore_62 ? 0 : m_segments_34.read(index_trunc_61, 0));
			t_sample index_segments_1545 = switch_1538;
			t_sample mul_1541 = (sample_segments_1544 * expr_1559);
			t_sample mul_1614 = ((mul_1541 + mul_1517) * ((t_sample)0.4));
			t_sample mul_1613 = ((mul_1541 + mul_1517) * ((t_sample)0.3));
			t_sample plusequals_1434 = __m_pluseq_63.post(((int)1), tap_1402, 0);
			t_sample noise_1429 = noise();
			t_sample abs_1428 = fabs(noise_1429);
			t_sample sub_1420 = (clamp_1618 - ((int)50));
			t_sample mul_1427 = (abs_1428 * sub_1420);
			t_sample sah_1430 = __m_sah_64(mul_1427, tap_1402, ((t_sample)0.5));
			t_sample add_1417 = (sah_1430 + ((int)50));
			t_sample mod_1426 = safemod(plusequals_1434, add_1417);
			t_sample div_1423 = safediv(mod_1426, add_1417);
			t_sample expr_1439 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1423))));
			t_sample noise_1437 = noise();
			t_sample abs_1436 = fabs(noise_1437);
			t_sample mul_1435 = (abs_1436 * mul_1733);
			t_sample sah_1438 = __m_sah_65(mul_1435, tap_1402, ((t_sample)0.5));
			t_sample add_1432 = (sah_1438 + mod_1426);
			t_sample mod_1431 = safemod(add_1432, mul_1733);
			t_sample switch_1418 = (gte_1386 ? mod_1431 : ((int)-1));
			int index_trunc_66 = fixnan(floor(switch_1418));
			bool index_ignore_67 = ((index_trunc_66 >= segments_dim) || (index_trunc_66 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1424 = (index_ignore_67 ? 0 : m_segments_34.read(index_trunc_66, 0));
			t_sample index_segments_1425 = switch_1418;
			t_sample mul_1421 = (sample_segments_1424 * expr_1439);
			t_sample plusequals_1458 = __m_pluseq_68.post(((int)1), tap_1404, 0);
			t_sample noise_1453 = noise();
			t_sample abs_1452 = fabs(noise_1453);
			t_sample sub_1444 = (clamp_1618 - ((int)50));
			t_sample mul_1451 = (abs_1452 * sub_1444);
			t_sample sah_1454 = __m_sah_69(mul_1451, tap_1404, ((t_sample)0.5));
			t_sample add_1441 = (sah_1454 + ((int)50));
			t_sample mod_1450 = safemod(plusequals_1458, add_1441);
			t_sample div_1447 = safediv(mod_1450, add_1441);
			t_sample expr_1463 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1447))));
			t_sample noise_1461 = noise();
			t_sample abs_1460 = fabs(noise_1461);
			t_sample mul_1459 = (abs_1460 * mul_1733);
			t_sample sah_1462 = __m_sah_70(mul_1459, tap_1404, ((t_sample)0.5));
			t_sample add_1456 = (sah_1462 + mod_1450);
			t_sample mod_1455 = safemod(add_1456, mul_1733);
			t_sample switch_1442 = (gte_1387 ? mod_1455 : ((int)-1));
			int index_trunc_71 = fixnan(floor(switch_1442));
			bool index_ignore_72 = ((index_trunc_71 >= segments_dim) || (index_trunc_71 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1448 = (index_ignore_72 ? 0 : m_segments_34.read(index_trunc_71, 0));
			t_sample index_segments_1449 = switch_1442;
			t_sample mul_1445 = (sample_segments_1448 * expr_1463);
			t_sample mul_1610 = ((mul_1445 + mul_1421) * ((t_sample)0.5));
			t_sample mul_1609 = ((mul_1445 + mul_1421) * ((t_sample)0.2));
			t_sample plusequals_1482 = __m_pluseq_73.post(((int)1), tap_1406, 0);
			t_sample noise_1477 = noise();
			t_sample abs_1476 = fabs(noise_1477);
			t_sample sub_1468 = (clamp_1618 - ((int)50));
			t_sample mul_1475 = (abs_1476 * sub_1468);
			t_sample sah_1478 = __m_sah_74(mul_1475, tap_1406, ((t_sample)0.5));
			t_sample add_1465 = (sah_1478 + ((int)50));
			t_sample mod_1474 = safemod(plusequals_1482, add_1465);
			t_sample div_1471 = safediv(mod_1474, add_1465);
			t_sample expr_1487 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1471))));
			t_sample noise_1485 = noise();
			t_sample abs_1484 = fabs(noise_1485);
			t_sample mul_1483 = (abs_1484 * mul_1733);
			t_sample sah_1486 = __m_sah_75(mul_1483, tap_1406, ((t_sample)0.5));
			t_sample add_1480 = (sah_1486 + mod_1474);
			t_sample mod_1479 = safemod(add_1480, mul_1733);
			t_sample switch_1466 = (gte_1388 ? mod_1479 : ((int)-1));
			int index_trunc_76 = fixnan(floor(switch_1466));
			bool index_ignore_77 = ((index_trunc_76 >= segments_dim) || (index_trunc_76 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1472 = (index_ignore_77 ? 0 : m_segments_34.read(index_trunc_76, 0));
			t_sample index_segments_1473 = switch_1466;
			t_sample mul_1469 = (sample_segments_1472 * expr_1487);
			t_sample plusequals_1506 = __m_pluseq_78.post(((int)1), tap_1408, 0);
			t_sample noise_1501 = noise();
			t_sample abs_1500 = fabs(noise_1501);
			t_sample sub_1492 = (clamp_1618 - ((int)50));
			t_sample mul_1499 = (abs_1500 * sub_1492);
			t_sample sah_1502 = __m_sah_79(mul_1499, tap_1408, ((t_sample)0.5));
			t_sample add_1489 = (sah_1502 + ((int)50));
			t_sample mod_1498 = safemod(plusequals_1506, add_1489);
			t_sample div_1495 = safediv(mod_1498, add_1489);
			t_sample expr_1511 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1495))));
			t_sample noise_1509 = noise();
			t_sample abs_1508 = fabs(noise_1509);
			t_sample mul_1507 = (abs_1508 * mul_1733);
			t_sample sah_1510 = __m_sah_80(mul_1507, tap_1408, ((t_sample)0.5));
			t_sample add_1504 = (sah_1510 + mod_1498);
			t_sample mod_1503 = safemod(add_1504, mul_1733);
			t_sample switch_1490 = (gte_1389 ? mod_1503 : ((int)-1));
			int index_trunc_81 = fixnan(floor(switch_1490));
			bool index_ignore_82 = ((index_trunc_81 >= segments_dim) || (index_trunc_81 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1496 = (index_ignore_82 ? 0 : m_segments_34.read(index_trunc_81, 0));
			t_sample index_segments_1497 = switch_1490;
			t_sample mul_1493 = (sample_segments_1496 * expr_1511);
			t_sample mul_1612 = ((mul_1493 + mul_1469) * ((t_sample)0.2));
			t_sample mul_1611 = ((mul_1493 + mul_1469) * ((t_sample)0.5));
			int gt_1741 = (clamp_1744 > m_knob3_thresh_32);
			int change_1740 = __m_change_83(gt_1741);
			int eq_1739 = (change_1740 == ((int)1));
			t_sample add_2084 = (m_history_5 + ((int)1));
			int gt_2083 = (m_history_5 > mstosamps_2086);
			int mul_2082 = (eq_1739 * gt_2083);
			int and_2080 = (gt_2083 && eq_1739);
			t_sample switch_2081 = (and_2080 ? ((int)0) : add_2084);
			t_sample history_2085_next_2187 = fixdenorm(switch_2081);
			int plusequals_1722 = __m_pluseq_84.post(((int)1), mul_2082, 0);
			t_sample noise_1717 = noise();
			t_sample abs_1716 = fabs(noise_1717);
			t_sample sub_1708 = (clamp_1618 - ((int)50));
			t_sample mul_1715 = (abs_1716 * sub_1708);
			t_sample sah_1718 = __m_sah_85(mul_1715, mul_2082, ((t_sample)0.5));
			t_sample add_1705 = (sah_1718 + ((int)50));
			t_sample mod_1714 = safemod(plusequals_1722, add_1705);
			t_sample div_1711 = safediv(mod_1714, add_1705);
			t_sample expr_1727 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1711))));
			t_sample noise_1725 = noise();
			t_sample abs_1724 = fabs(noise_1725);
			t_sample mul_1723 = (abs_1724 * mul_1733);
			t_sample sah_1726 = __m_sah_86(mul_1723, mul_2082, ((t_sample)0.5));
			t_sample add_1720 = (sah_1726 + mod_1714);
			t_sample mod_1719 = safemod(add_1720, mul_1733);
			t_sample switch_1706 = (gte_1397 ? mod_1719 : ((int)-1));
			int index_trunc_87 = fixnan(floor(switch_1706));
			bool index_ignore_88 = ((index_trunc_87 >= segments_dim) || (index_trunc_87 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1712 = (index_ignore_88 ? 0 : m_segments_34.read(index_trunc_87, 0));
			t_sample index_segments_1713 = switch_1706;
			t_sample mul_1709 = (sample_segments_1712 * expr_1727);
			int gt_1703 = (clamp_1744 > mul_1694);
			int change_1702 = __m_change_89(gt_1703);
			int eq_1701 = (change_1702 == ((int)1));
			t_sample add_2291 = (m_history_4 + ((int)1));
			int gt_2290 = (m_history_4 > mstosamps_2293);
			int mul_2289 = (eq_1701 * gt_2290);
			int and_2287 = (gt_2290 && eq_1701);
			t_sample switch_2288 = (and_2287 ? ((int)0) : add_2291);
			t_sample history_2292_next_2295 = fixdenorm(switch_2288);
			int plusequals_1685 = __m_pluseq_90.post(((int)1), mul_2289, 0);
			t_sample noise_1680 = noise();
			t_sample abs_1679 = fabs(noise_1680);
			t_sample sub_1671 = (clamp_1618 - ((int)50));
			t_sample mul_1678 = (abs_1679 * sub_1671);
			t_sample sah_1681 = __m_sah_91(mul_1678, mul_2289, ((t_sample)0.5));
			t_sample add_1668 = (sah_1681 + ((int)50));
			t_sample mod_1677 = safemod(plusequals_1685, add_1668);
			t_sample div_1674 = safediv(mod_1677, add_1668);
			t_sample expr_1690 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1674))));
			t_sample noise_1688 = noise();
			t_sample abs_1687 = fabs(noise_1688);
			t_sample mul_1686 = (abs_1687 * mul_1733);
			t_sample sah_1689 = __m_sah_92(mul_1686, mul_2289, ((t_sample)0.5));
			t_sample add_1683 = (sah_1689 + mod_1677);
			t_sample mod_1682 = safemod(add_1683, mul_1733);
			t_sample switch_1669 = (gte_1396 ? mod_1682 : ((int)-1));
			int index_trunc_93 = fixnan(floor(switch_1669));
			bool index_ignore_94 = ((index_trunc_93 >= segments_dim) || (index_trunc_93 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1675 = (index_ignore_94 ? 0 : m_segments_34.read(index_trunc_93, 0));
			t_sample index_segments_1676 = switch_1669;
			t_sample mul_1672 = (sample_segments_1675 * expr_1690);
			int gt_1700 = (clamp_1744 > mul_1693);
			int change_1699 = __m_change_95(gt_1700);
			int eq_1698 = (change_1699 == ((int)1));
			t_sample add_2399 = (m_history_3 + ((int)1));
			int gt_2398 = (m_history_3 > mstosamps_2401);
			int mul_2397 = (eq_1698 * gt_2398);
			int and_2395 = (gt_2398 && eq_1698);
			t_sample switch_2396 = (and_2395 ? ((int)0) : add_2399);
			t_sample history_2400_next_2403 = fixdenorm(switch_2396);
			int plusequals_1661 = __m_pluseq_96.post(((int)1), mul_2397, 0);
			t_sample noise_1656 = noise();
			t_sample abs_1655 = fabs(noise_1656);
			t_sample sub_1647 = (clamp_1618 - ((int)50));
			t_sample mul_1654 = (abs_1655 * sub_1647);
			t_sample sah_1657 = __m_sah_97(mul_1654, mul_2397, ((t_sample)0.5));
			t_sample add_1644 = (sah_1657 + ((int)50));
			t_sample mod_1653 = safemod(plusequals_1661, add_1644);
			t_sample div_1650 = safediv(mod_1653, add_1644);
			t_sample expr_1666 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1650))));
			t_sample noise_1664 = noise();
			t_sample abs_1663 = fabs(noise_1664);
			t_sample mul_1662 = (abs_1663 * mul_1733);
			t_sample sah_1665 = __m_sah_98(mul_1662, mul_2397, ((t_sample)0.5));
			t_sample add_1659 = (sah_1665 + mod_1653);
			t_sample mod_1658 = safemod(add_1659, mul_1733);
			t_sample switch_1645 = (gte_1395 ? mod_1658 : ((int)-1));
			int index_trunc_99 = fixnan(floor(switch_1645));
			bool index_ignore_100 = ((index_trunc_99 >= segments_dim) || (index_trunc_99 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1651 = (index_ignore_100 ? 0 : m_segments_34.read(index_trunc_99, 0));
			t_sample index_segments_1652 = switch_1645;
			t_sample mul_1648 = (sample_segments_1651 * expr_1666);
			int gt_1697 = (clamp_1744 > mul_1692);
			int change_1696 = __m_change_101(gt_1697);
			int eq_1695 = (change_1696 == ((int)1));
			t_sample add_2507 = (m_history_2 + ((int)1));
			int gt_2506 = (m_history_2 > mstosamps_2509);
			int mul_2505 = (eq_1695 * gt_2506);
			int and_2503 = (gt_2506 && eq_1695);
			t_sample switch_2504 = (and_2503 ? ((int)0) : add_2507);
			t_sample history_2508_next_2511 = fixdenorm(switch_2504);
			int plusequals_1637 = __m_pluseq_102.post(((int)1), mul_2505, 0);
			t_sample noise_1632 = noise();
			t_sample abs_1631 = fabs(noise_1632);
			t_sample sub_1623 = (clamp_1618 - ((int)50));
			t_sample mul_1630 = (abs_1631 * sub_1623);
			t_sample sah_1633 = __m_sah_103(mul_1630, mul_2505, ((t_sample)0.5));
			t_sample add_1620 = (sah_1633 + ((int)50));
			t_sample mod_1629 = safemod(plusequals_1637, add_1620);
			t_sample div_1626 = safediv(mod_1629, add_1620);
			t_sample expr_1642 = (((t_sample)0.54) - (((t_sample)0.48) * cos((((t_sample)6.2831853071796) * div_1626))));
			t_sample noise_1640 = noise();
			t_sample abs_1639 = fabs(noise_1640);
			t_sample mul_1638 = (abs_1639 * mul_1733);
			t_sample sah_1641 = __m_sah_104(mul_1638, mul_2505, ((t_sample)0.5));
			t_sample add_1635 = (sah_1641 + mod_1629);
			t_sample mod_1634 = safemod(add_1635, mul_1733);
			t_sample switch_1621 = (gte_1394 ? mod_1634 : ((int)-1));
			int index_trunc_105 = fixnan(floor(switch_1621));
			bool index_ignore_106 = ((index_trunc_105 >= segments_dim) || (index_trunc_105 < 0));
			// samples segments channel 1;
			t_sample sample_segments_1627 = (index_ignore_106 ? 0 : m_segments_34.read(index_trunc_105, 0));
			t_sample index_segments_1628 = switch_1621;
			t_sample mul_1624 = (sample_segments_1627 * expr_1642);
			t_sample mul_1704 = ((((mul_1709 + mul_1624) + mul_1648) + mul_1672) * ((t_sample)0.7));
			t_sample mul_1400 = (((((mul_1612 + mul_1610) + mul_1614) + mul_1616) + mul_1704) * scale_3959);
			t_sample dcblock_1365 = __m_dcblock_107(mul_1400);
			t_sample mul_1368 = (sqrt_1366 * dcblock_1365);
			t_sample out1 = ((mul_1368 + mul_1369) + gate_1757);
			t_sample mul_1399 = (((((mul_1611 + mul_1609) + mul_1613) + mul_1615) + mul_1704) * scale_3959);
			t_sample dcblock_1364 = __m_dcblock_108(mul_1399);
			t_sample mul_1367 = (sqrt_1366 * dcblock_1364);
			t_sample out2 = ((mul_1367 + mul_1369) + gate_1757);
			t_sample history_1734_next_3781 = fixdenorm(eq_1735);
			m_history_26 = history_1753_next_1755;
			m_history_25 = history_1375_next_1377;
			m_history_23 = history_1371_next_1379;
			m_history_24 = history_1373_next_1378;
			m_history_22 = history_1375_next_3741;
			m_history_20 = history_1371_next_3734;
			m_history_21 = history_1373_next_3740;
			m_history_19 = history_1375_next_3747;
			m_history_17 = history_1371_next_3751;
			m_history_18 = history_1373_next_3753;
			m_delay_16.write(mul_2289);
			m_delay_15.write(mul_2082);
			m_delay_14.write(mul_2505);
			m_delay_13.write(mul_2397);
			m_delay_12.write(tap_1410);
			m_delay_11.write(tap_1412);
			m_delay_10.write(tap_1414);
			m_delay_9.write(tap_1416);
			m_history_8 = history_1375_next_3774;
			m_history_6 = history_1371_next_3773;
			m_history_7 = history_1373_next_3769;
			m_history_5 = history_2085_next_2187;
			m_history_4 = history_2292_next_2295;
			m_history_3 = history_2400_next_2403;
			m_history_2 = history_2508_next_2511;
			m_history_1 = history_1734_next_3781;
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
	inline void set_knob4_buflen(t_param _value) {
		m_knob4_buflen_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_glitchlen(t_param _value) {
		m_knob5_glitchlen_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_thresh(t_param _value) {
		m_knob3_thresh_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
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
		case 0: *value = self->m_knob1_wetdry_30; break;
		case 1: *value = self->m_knob3_thresh_32; break;
		case 2: *value = self->m_knob4_buflen_28; break;
		case 3: *value = self->m_knob5_glitchlen_29; break;
		case 4: *value = self->m_knob6_density_27; break;
		
		case 6: *value = self->m_sw_31; break;
		case 7: *value = self->m_sw_33; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_30")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_thresh_32")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_thresh";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_thresh_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_buflen_28")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_buflen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_buflen_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_glitchlen_29")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_glitchlen";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_glitchlen_29;
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
	// initialize parameter 7 ("m_sw_33")
	pi = self->__commonstate.params + 7;
	pi->name = "sw2";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Glitch::
