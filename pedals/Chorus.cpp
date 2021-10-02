#include "Chorus.h"

namespace Chorus {

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
	Delay m_delay_1;
	Sah __m_sah_21;
	SineCycle __m_cycle_24;
	SineCycle __m_cycle_23;
	SineCycle __m_cycle_30;
	SineCycle __m_cycle_25;
	SineCycle __m_cycle_27;
	SineCycle __m_cycle_26;
	SineCycle __m_cycle_29;
	SineCycle __m_cycle_28;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_10;
	t_sample m_history_5;
	t_sample m_history_6;
	t_sample m_history_4;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample m_history_7;
	t_sample samplerate;
	t_sample m_history_9;
	t_sample m_knob3_depth_20;
	t_sample m_knob4_rate_18;
	t_sample m_history_13;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_sw_19;
	t_sample m_history_8;
	t_sample m_knob6_taps_16;
	t_sample m_knob5_breadth_15;
	t_sample m_sw_17;
	t_sample m_history_14;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)20000));
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
		m_knob5_breadth_15 = 256;
		m_knob6_taps_16 = ((int)0);
		m_sw_17 = ((int)0);
		m_knob4_rate_18 = ((int)0);
		m_sw_19 = ((int)0);
		m_knob3_depth_20 = ((int)0);
		__m_sah_21.reset(0);
		__m_cycle_23.reset(samplerate, 0);
		__m_cycle_24.reset(samplerate, 0);
		__m_cycle_25.reset(samplerate, 0);
		__m_cycle_26.reset(samplerate, 0);
		__m_cycle_27.reset(samplerate, 0);
		__m_cycle_28.reset(samplerate, 0);
		__m_cycle_29.reset(samplerate, 0);
		__m_cycle_30.reset(samplerate, 0);
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
		t_sample expr_1686 = (((int)1) - sqrt(sqrt((((int)1) - m_knob4_rate_18))));
		t_sample expr_1687 = (((int)1) - sqrt(sqrt((((int)1) - m_knob3_depth_20))));
		t_sample div_1571 = (m_sw_17 * ((t_sample)0.5));
		t_sample add_1570 = (div_1571 + ((t_sample)0.5));
		t_sample mul_1579 = (expr_1687 * ((int)1000));
		t_sample add_1578 = (mul_1579 + ((int)2));
		t_sample mul_1576 = (expr_1686 * ((int)10));
		t_sample add_1577 = (mul_1576 + ((t_sample)0.01));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_1680 = __m_sah_21(m_history_14, m_sw_19, ((int)0));
			t_sample gen_1682 = sah_1680;
			t_sample rsub_1678 = (((int)1) - sah_1680);
			t_sample history_1679_next_1681 = fixdenorm(rsub_1678);
			t_sample out3 = gen_1682;
			t_sample add_1683 = (gen_1682 + ((int)1));
			t_sample choice_22 = int(add_1683);
			t_sample gate_1675 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_1676 = ((choice_22 >= 2) ? in1 : 0);
			t_sample switch_1613 = (m_sw_17 ? ((int)0) : gate_1676);
			t_sample mix_1783 = (m_history_13 + (((t_sample)0.003926980723806) * (m_knob6_taps_16 - m_history_13)));
			t_sample mix_1585 = mix_1783;
			t_sample mix_1784 = (m_history_12 + (((t_sample)0.003926980723806) * (mix_1585 - m_history_12)));
			t_sample mix_1583 = mix_1784;
			t_sample mix_1785 = (m_history_11 + (((t_sample)0.003926980723806) * (mix_1583 - m_history_11)));
			t_sample mix_1581 = mix_1785;
			t_sample gen_1611 = mix_1581;
			t_sample history_1586_next_1588 = fixdenorm(mix_1585);
			t_sample history_1584_next_1589 = fixdenorm(mix_1583);
			t_sample history_1582_next_1590 = fixdenorm(mix_1581);
			t_sample sub_1789 = (gen_1611 - ((int)0));
			t_sample scale_1786 = ((safepow((sub_1789 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.5)) + ((int)1));
			t_sample sub_1793 = (gen_1611 - ((int)0));
			t_sample scale_1790 = ((safepow((sub_1793 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-2));
			t_sample clamp_1597 = ((scale_1790 <= ((int)0)) ? ((int)0) : ((scale_1790 >= ((int)1)) ? ((int)1) : scale_1790));
			t_sample sub_1797 = (gen_1611 - ((int)0));
			t_sample scale_1794 = ((safepow((sub_1797 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-3));
			t_sample clamp_1595 = ((scale_1794 <= ((int)0)) ? ((int)0) : ((scale_1794 >= ((int)1)) ? ((int)1) : scale_1794));
			t_sample sub_1801 = (gen_1611 - ((int)0));
			t_sample scale_1798 = ((safepow((sub_1801 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-1));
			t_sample clamp_1599 = ((scale_1798 <= ((int)0)) ? ((int)0) : ((scale_1798 >= ((int)1)) ? ((int)1) : scale_1798));
			t_sample mix_1802 = (m_history_10 + (((t_sample)0.003926980723806) * (m_knob5_breadth_15 - m_history_10)));
			t_sample mix_1697 = mix_1802;
			t_sample mix_1803 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_1697 - m_history_9)));
			t_sample mix_1692 = mix_1803;
			t_sample mix_1804 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_1692 - m_history_8)));
			t_sample mix_1690 = mix_1804;
			t_sample gen_1591 = mix_1690;
			t_sample history_1586_next_1694 = fixdenorm(mix_1697);
			t_sample history_1584_next_1696 = fixdenorm(mix_1692);
			t_sample history_1582_next_1688 = fixdenorm(mix_1690);
			t_sample mul_1580 = (gen_1591 * ((int)1));
			t_sample mul_1594 = (gen_1591 * ((int)2));
			t_sample mul_1593 = (gen_1591 * ((int)3));
			t_sample mul_1592 = (gen_1591 * ((int)4));
			t_sample mix_1805 = (m_history_7 + (((t_sample)0.003926980723806) * (add_1578 - m_history_7)));
			t_sample mix_1710 = mix_1805;
			t_sample mix_1806 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_1710 - m_history_6)));
			t_sample mix_1705 = mix_1806;
			t_sample mix_1807 = (m_history_5 + (((t_sample)0.003926980723806) * (mix_1705 - m_history_5)));
			t_sample mix_1703 = mix_1807;
			t_sample gen_1685 = mix_1703;
			t_sample history_1586_next_1707 = fixdenorm(mix_1710);
			t_sample history_1584_next_1709 = fixdenorm(mix_1705);
			t_sample history_1582_next_1701 = fixdenorm(mix_1703);
			t_sample mix_1808 = (m_history_4 + (((t_sample)0.003926980723806) * (add_1577 - m_history_4)));
			t_sample mix_1718 = mix_1808;
			t_sample mix_1809 = (m_history_3 + (((t_sample)0.003926980723806) * (mix_1718 - m_history_3)));
			t_sample mix_1716 = mix_1809;
			t_sample mix_1810 = (m_history_2 + (((t_sample)0.003926980723806) * (mix_1716 - m_history_2)));
			t_sample mix_1714 = mix_1810;
			t_sample gen_1622 = mix_1714;
			t_sample history_1586_next_1717 = fixdenorm(mix_1718);
			t_sample history_1584_next_1720 = fixdenorm(mix_1716);
			t_sample history_1582_next_1719 = fixdenorm(mix_1714);
			t_sample mul_1626 = (gen_1622 * ((int)1));
			__m_cycle_23.freq(mul_1626);
			t_sample cycle_1664 = __m_cycle_23(__sinedata);
			t_sample cycleindex_1665 = __m_cycle_23.phase();
			t_sample mul_1662 = (cycle_1664 * gen_1685);
			t_sample add_1663 = (mul_1662 + mul_1580);
			t_sample mul_1657 = (gen_1622 * ((t_sample)1.51));
			__m_cycle_24.freq(mul_1657);
			t_sample cycle_1660 = __m_cycle_24(__sinedata);
			t_sample cycleindex_1661 = __m_cycle_24.phase();
			t_sample mul_1658 = (cycle_1660 * gen_1685);
			t_sample add_1659 = (mul_1658 + mul_1580);
			t_sample mul_1625 = (gen_1622 * ((t_sample)0.48));
			__m_cycle_25.freq(mul_1625);
			t_sample cycle_1654 = __m_cycle_25(__sinedata);
			t_sample cycleindex_1655 = __m_cycle_25.phase();
			t_sample mul_1652 = (cycle_1654 * gen_1685);
			t_sample add_1653 = (mul_1652 + mul_1594);
			t_sample mul_1647 = (gen_1622 * ((t_sample)0.73));
			__m_cycle_26.freq(mul_1647);
			t_sample cycle_1650 = __m_cycle_26(__sinedata);
			t_sample cycleindex_1651 = __m_cycle_26.phase();
			t_sample mul_1648 = (cycle_1650 * gen_1685);
			t_sample add_1649 = (mul_1648 + mul_1594);
			t_sample mul_1624 = (gen_1622 * ((t_sample)1.245));
			__m_cycle_27.freq(mul_1624);
			t_sample cycle_1643 = __m_cycle_27(__sinedata);
			t_sample cycleindex_1644 = __m_cycle_27.phase();
			t_sample mul_1641 = (cycle_1643 * gen_1685);
			t_sample add_1642 = (mul_1641 + mul_1593);
			t_sample mul_1636 = (gen_1622 * ((t_sample)0.81));
			__m_cycle_28.freq(mul_1636);
			t_sample cycle_1639 = __m_cycle_28(__sinedata);
			t_sample cycleindex_1640 = __m_cycle_28.phase();
			t_sample mul_1637 = (cycle_1639 * gen_1685);
			t_sample add_1638 = (mul_1637 + mul_1593);
			t_sample mul_1623 = (gen_1622 * ((t_sample)1.93));
			__m_cycle_29.freq(mul_1623);
			t_sample cycle_1634 = __m_cycle_29(__sinedata);
			t_sample cycleindex_1635 = __m_cycle_29.phase();
			t_sample mul_1632 = (cycle_1634 * gen_1685);
			t_sample add_1633 = (mul_1632 + mul_1592);
			t_sample mul_1627 = (gen_1622 * ((t_sample)2.11));
			__m_cycle_30.freq(mul_1627);
			t_sample cycle_1630 = __m_cycle_30(__sinedata);
			t_sample cycleindex_1631 = __m_cycle_30.phase();
			t_sample mul_1628 = (cycle_1630 * gen_1685);
			t_sample add_1629 = (mul_1628 + mul_1592);
			t_sample tap_1667 = m_delay_1.read_linear(add_1663);
			t_sample tap_1668 = m_delay_1.read_linear(add_1659);
			t_sample tap_1669 = m_delay_1.read_linear(add_1653);
			t_sample tap_1670 = m_delay_1.read_linear(add_1649);
			t_sample tap_1671 = m_delay_1.read_linear(add_1642);
			t_sample tap_1672 = m_delay_1.read_linear(add_1638);
			t_sample tap_1673 = m_delay_1.read_linear(add_1633);
			t_sample tap_1674 = m_delay_1.read_linear(add_1629);
			t_sample mul_1610 = (tap_1671 * clamp_1597);
			t_sample mul_1607 = (tap_1674 * clamp_1595);
			t_sample mul_1603 = (tap_1670 * clamp_1599);
			t_sample mul_1606 = (tap_1667 * ((int)1));
			t_sample mul_1646 = ((((mul_1606 + mul_1603) + mul_1607) + mul_1610) * scale_1786);
			t_sample add_1684 = (switch_1613 + mul_1646);
			t_sample mul_1573 = (add_1570 * add_1684);
			t_sample out1 = (gate_1675 + mul_1573);
			t_sample mul_1609 = (tap_1672 * clamp_1597);
			t_sample mul_1608 = (tap_1673 * clamp_1595);
			t_sample mul_1604 = (tap_1669 * clamp_1599);
			t_sample mul_1605 = (tap_1668 * ((int)1));
			t_sample mul_1645 = ((((mul_1605 + mul_1604) + mul_1608) + mul_1609) * scale_1786);
			t_sample add_1656 = (switch_1613 + mul_1645);
			t_sample mul_1572 = (add_1570 * add_1656);
			t_sample out2 = (gate_1675 + mul_1572);
			m_history_14 = history_1679_next_1681;
			m_history_13 = history_1586_next_1588;
			m_history_11 = history_1582_next_1590;
			m_history_12 = history_1584_next_1589;
			m_history_10 = history_1586_next_1694;
			m_history_8 = history_1582_next_1688;
			m_history_9 = history_1584_next_1696;
			m_history_7 = history_1586_next_1707;
			m_history_5 = history_1582_next_1701;
			m_history_6 = history_1584_next_1709;
			m_history_4 = history_1586_next_1717;
			m_history_2 = history_1582_next_1719;
			m_history_3 = history_1584_next_1720;
			m_delay_1.write(gate_1676);
			m_delay_1.step();
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
	inline void set_knob5_breadth(t_param _value) {
		m_knob5_breadth_15 = (_value < 240 ? 240 : (_value > 2400 ? 2400 : _value));
	};
	inline void set_knob6_taps(t_param _value) {
		m_knob6_taps_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 2: self->set_knob5_breadth(value); break;
		case 3: self->set_knob6_taps(value); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_depth_20; break;
		case 1: *value = self->m_knob4_rate_18; break;
		case 2: *value = self->m_knob5_breadth_15; break;
		case 3: *value = self->m_knob6_taps_16; break;
		case 4: *value = self->m_sw_19; break;
		case 5: *value = self->m_sw_17; break;
		
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
	// initialize parameter 0 ("m_knob3_depth_20")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_18")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_breadth_15")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_breadth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_breadth_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 240;
	pi->outputmax = 2400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_taps_16")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_taps";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_taps_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_19")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_17")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_17;
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


} // Chorus::
