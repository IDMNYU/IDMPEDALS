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
	t_sample m_sw_3;
	t_sample m_history_11;
	t_sample m_knob3_damp_2;
	t_sample m_knob4_fb_1;
	t_sample samplerate;
	t_sample m_knob1_wetdry_4;
	t_sample m_history_13;
	t_sample m_knob5_fb_5;
	t_sample m_knob6_spread_6;
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
		m_knob4_fb_1 = ((t_sample)0.9);
		m_knob3_damp_2 = ((t_sample)0.5);
		m_sw_3 = ((int)0);
		m_knob1_wetdry_4 = ((int)0);
		m_knob5_fb_5 = ((t_sample)0.5);
		m_knob6_spread_6 = ((int)0);
		m_history_7 = ((int)0);
		m_delay_8.reset("m_delay_8", ((int)4000));
		m_history_9 = ((int)0);
		m_delay_10.reset("m_delay_10", ((int)4000));
		m_history_11 = ((int)0);
		m_delay_12.reset("m_delay_12", ((int)4000));
		m_history_13 = ((int)0);
		m_delay_14.reset("m_delay_14", ((int)4000));
		m_history_15 = ((int)0);
		m_delay_16.reset("m_delay_16", ((int)4000));
		m_history_17 = ((int)0);
		m_delay_18.reset("m_delay_18", ((int)4000));
		m_history_19 = ((int)0);
		m_delay_20.reset("m_delay_20", ((int)4000));
		m_history_21 = ((int)0);
		m_delay_22.reset("m_delay_22", ((int)4000));
		m_history_23 = ((int)0);
		m_delay_24.reset("m_delay_24", ((int)4000));
		m_delay_25.reset("m_delay_25", ((int)4000));
		m_delay_26.reset("m_delay_26", ((int)4000));
		m_delay_27.reset("m_delay_27", ((int)4000));
		m_delay_28.reset("m_delay_28", ((int)4000));
		m_delay_29.reset("m_delay_29", ((int)4000));
		m_delay_30.reset("m_delay_30", ((int)4000));
		m_delay_31.reset("m_delay_31", ((int)4000));
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
		t_sample sqrt_1579 = sqrt(m_knob1_wetdry_4);
		t_sample rsub_1583 = (((int)1) - m_knob1_wetdry_4);
		t_sample sqrt_1582 = sqrt(rsub_1583);
		t_sample mul_1633 = (m_knob5_fb_5 * ((t_sample)0.9));
		t_sample mul_1578 = (m_knob5_fb_5 * ((t_sample)0.9));
		t_sample add_1619 = (((int)450) + m_knob6_spread_6);
		t_sample add_1573 = (((int)456) + m_knob6_spread_6);
		t_sample add_1621 = (((int)682) + m_knob6_spread_6);
		t_sample add_1575 = (((int)676) + m_knob6_spread_6);
		t_sample add_1631 = (((int)882) + m_knob6_spread_6);
		t_sample add_1577 = (((int)888) + m_knob6_spread_6);
		t_sample add_1617 = (((int)1112) + m_knob6_spread_6);
		t_sample add_1571 = (((int)1106) + m_knob6_spread_6);
		t_sample add_1624 = (((int)3114) + m_knob6_spread_6);
		t_sample rsub_1586 = (((int)1) - m_knob3_damp_2);
		t_sample add_1623 = (((int)3234) + m_knob6_spread_6);
		t_sample rsub_1651 = (((int)1) - m_knob3_damp_2);
		t_sample add_1625 = (((int)2982) + m_knob6_spread_6);
		t_sample rsub_1663 = (((int)1) - m_knob3_damp_2);
		t_sample add_1626 = (((int)2844) + m_knob6_spread_6);
		t_sample rsub_1675 = (((int)1) - m_knob3_damp_2);
		t_sample add_1627 = (((int)2712) + m_knob6_spread_6);
		t_sample rsub_1687 = (((int)1) - m_knob3_damp_2);
		t_sample add_1628 = (((int)2554) + m_knob6_spread_6);
		t_sample rsub_1699 = (((int)1) - m_knob3_damp_2);
		t_sample add_1629 = (((int)2376) + m_knob6_spread_6);
		t_sample rsub_1711 = (((int)1) - m_knob3_damp_2);
		t_sample add_1630 = (((int)2232) + m_knob6_spread_6);
		t_sample rsub_1725 = (((int)1) - m_knob3_damp_2);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_1638 = __m_sah_32(m_history_7, m_sw_3, ((int)0));
			t_sample gen_1640 = sah_1638;
			t_sample rsub_1636 = (((int)1) - sah_1638);
			t_sample history_1637_next_1639 = fixdenorm(rsub_1636);
			t_sample out3 = gen_1640;
			t_sample add_1643 = (gen_1640 + ((int)1));
			t_sample choice_33 = int(add_1643);
			t_sample gate_1641 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_1642 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_1581 = (gate_1642 * sqrt_1582);
			t_sample mul_1635 = (gate_1642 * ((t_sample)0.015));
			t_sample tap_1593 = m_delay_8.read_linear(add_1624);
			t_sample gen_1615 = tap_1593;
			t_sample mul_1591 = (tap_1593 * m_knob3_damp_2);
			t_sample mul_1589 = (m_history_9 * rsub_1586);
			t_sample add_1590 = (mul_1591 + mul_1589);
			t_sample mul_1587 = (add_1590 * m_knob4_fb_1);
			t_sample add_1594 = (mul_1635 + mul_1587);
			t_sample history_1588_next_1595 = fixdenorm(add_1590);
			t_sample tap_1645 = m_delay_10.read_linear(add_1623);
			t_sample gen_1634 = tap_1645;
			t_sample mul_1653 = (tap_1645 * m_knob3_damp_2);
			t_sample mul_1650 = (m_history_11 * rsub_1651);
			t_sample add_1647 = (mul_1653 + mul_1650);
			t_sample mul_1646 = (add_1647 * m_knob4_fb_1);
			t_sample add_1649 = (mul_1635 + mul_1646);
			t_sample history_1588_next_1648 = fixdenorm(add_1647);
			t_sample tap_1657 = m_delay_12.read_linear(add_1625);
			t_sample gen_1614 = tap_1657;
			t_sample mul_1664 = (tap_1657 * m_knob3_damp_2);
			t_sample mul_1662 = (m_history_13 * rsub_1663);
			t_sample add_1659 = (mul_1664 + mul_1662);
			t_sample mul_1658 = (add_1659 * m_knob4_fb_1);
			t_sample add_1660 = (mul_1635 + mul_1658);
			t_sample history_1588_next_1661 = fixdenorm(add_1659);
			t_sample tap_1677 = m_delay_14.read_linear(add_1626);
			t_sample gen_1613 = tap_1677;
			t_sample mul_1672 = (tap_1677 * m_knob3_damp_2);
			t_sample mul_1668 = (m_history_15 * rsub_1675);
			t_sample add_1671 = (mul_1672 + mul_1668);
			t_sample mul_1670 = (add_1671 * m_knob4_fb_1);
			t_sample add_1669 = (mul_1635 + mul_1670);
			t_sample history_1588_next_1676 = fixdenorm(add_1671);
			t_sample tap_1688 = m_delay_16.read_linear(add_1627);
			t_sample gen_1612 = tap_1688;
			t_sample mul_1684 = (tap_1688 * m_knob3_damp_2);
			t_sample mul_1680 = (m_history_17 * rsub_1687);
			t_sample add_1683 = (mul_1684 + mul_1680);
			t_sample mul_1682 = (add_1683 * m_knob4_fb_1);
			t_sample add_1681 = (mul_1635 + mul_1682);
			t_sample history_1588_next_1689 = fixdenorm(add_1683);
			t_sample tap_1701 = m_delay_18.read_linear(add_1628);
			t_sample gen_1611 = tap_1701;
			t_sample mul_1696 = (tap_1701 * m_knob3_damp_2);
			t_sample mul_1692 = (m_history_19 * rsub_1699);
			t_sample add_1695 = (mul_1696 + mul_1692);
			t_sample mul_1694 = (add_1695 * m_knob4_fb_1);
			t_sample add_1693 = (mul_1635 + mul_1694);
			t_sample history_1588_next_1700 = fixdenorm(add_1695);
			t_sample tap_1713 = m_delay_20.read_linear(add_1629);
			t_sample gen_1610 = tap_1713;
			t_sample mul_1708 = (tap_1713 * m_knob3_damp_2);
			t_sample mul_1704 = (m_history_21 * rsub_1711);
			t_sample add_1707 = (mul_1708 + mul_1704);
			t_sample mul_1706 = (add_1707 * m_knob4_fb_1);
			t_sample add_1705 = (mul_1635 + mul_1706);
			t_sample history_1588_next_1712 = fixdenorm(add_1707);
			t_sample tap_1724 = m_delay_22.read_linear(add_1630);
			t_sample gen_1609 = tap_1724;
			t_sample mul_1722 = (tap_1724 * m_knob3_damp_2);
			t_sample mul_1716 = (m_history_23 * rsub_1725);
			t_sample add_1721 = (mul_1722 + mul_1716);
			t_sample mul_1718 = (add_1721 * m_knob4_fb_1);
			t_sample add_1717 = (mul_1635 + mul_1718);
			t_sample history_1588_next_1720 = fixdenorm(add_1721);
			t_sample pass_1632 = (((((((gen_1609 + gen_1610) + gen_1611) + gen_1612) + gen_1613) + gen_1614) + gen_1634) + gen_1615);
			t_sample tap_1569 = m_delay_24.read_linear(add_1617);
			t_sample sub_1565 = (pass_1632 - tap_1569);
			t_sample mul_1567 = (tap_1569 * mul_1633);
			t_sample add_1566 = (pass_1632 + mul_1567);
			t_sample tap_1732 = m_delay_25.read_linear(add_1631);
			t_sample sub_1731 = (sub_1565 - tap_1732);
			t_sample mul_1730 = (tap_1732 * mul_1633);
			t_sample add_1728 = (sub_1565 + mul_1730);
			t_sample tap_1738 = m_delay_26.read_linear(add_1621);
			t_sample sub_1737 = (sub_1731 - tap_1738);
			t_sample mul_1736 = (tap_1738 * mul_1633);
			t_sample add_1734 = (sub_1731 + mul_1736);
			t_sample tap_1744 = m_delay_27.read_linear(add_1619);
			t_sample sub_1743 = (sub_1737 - tap_1744);
			t_sample mul_1742 = (tap_1744 * mul_1633);
			t_sample add_1740 = (sub_1737 + mul_1742);
			t_sample mul_1584 = (sub_1743 * sqrt_1579);
			t_sample add_1580 = (mul_1581 + mul_1584);
			t_sample out1 = (gate_1641 + add_1580);
			t_sample tap_1750 = m_delay_28.read_linear(add_1571);
			t_sample sub_1749 = (pass_1632 - tap_1750);
			t_sample mul_1748 = (tap_1750 * mul_1578);
			t_sample add_1746 = (pass_1632 + mul_1748);
			t_sample tap_1756 = m_delay_29.read_linear(add_1577);
			t_sample sub_1755 = (sub_1749 - tap_1756);
			t_sample mul_1754 = (tap_1756 * mul_1578);
			t_sample add_1752 = (sub_1749 + mul_1754);
			t_sample tap_1762 = m_delay_30.read_linear(add_1575);
			t_sample sub_1761 = (sub_1755 - tap_1762);
			t_sample mul_1760 = (tap_1762 * mul_1578);
			t_sample add_1758 = (sub_1755 + mul_1760);
			t_sample tap_1768 = m_delay_31.read_linear(add_1573);
			t_sample sub_1767 = (sub_1761 - tap_1768);
			t_sample mul_1766 = (tap_1768 * mul_1578);
			t_sample add_1764 = (sub_1761 + mul_1766);
			t_sample mul_1560 = (sub_1767 * sqrt_1579);
			t_sample add_1559 = (mul_1581 + mul_1560);
			t_sample out2 = (add_1559 + gate_1641);
			m_history_7 = history_1637_next_1639;
			m_delay_31.write(add_1764);
			m_delay_30.write(add_1758);
			m_delay_29.write(add_1752);
			m_delay_28.write(add_1746);
			m_delay_27.write(add_1740);
			m_delay_26.write(add_1734);
			m_delay_25.write(add_1728);
			m_delay_24.write(add_1566);
			m_history_23 = history_1588_next_1720;
			m_delay_22.write(add_1717);
			m_history_21 = history_1588_next_1712;
			m_delay_20.write(add_1705);
			m_history_19 = history_1588_next_1700;
			m_delay_18.write(add_1693);
			m_history_17 = history_1588_next_1689;
			m_delay_16.write(add_1681);
			m_history_15 = history_1588_next_1676;
			m_delay_14.write(add_1669);
			m_history_13 = history_1588_next_1661;
			m_delay_12.write(add_1660);
			m_history_11 = history_1588_next_1648;
			m_delay_10.write(add_1649);
			m_history_9 = history_1588_next_1595;
			m_delay_8.write(add_1594);
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
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb2(t_param _value) {
		m_knob5_fb_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_6 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
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
		case 0: *value = self->m_knob1_wetdry_4; break;
		case 1: *value = self->m_knob3_damp_2; break;
		case 2: *value = self->m_knob4_fb_1; break;
		case 3: *value = self->m_knob5_fb_5; break;
		case 4: *value = self->m_knob6_spread_6; break;
		case 5: *value = self->m_sw_3; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_4")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_damp_2")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_fb_1")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_fb_5")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_spread_6")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_3")
	pi = self->__commonstate.params + 5;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_3;
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
