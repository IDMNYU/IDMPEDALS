#include "Subharmonic.h"

namespace Subharmonic {

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
	Sah __m_sah_29;
	Sah __m_sah_15;
	Sah __m_sah_17;
	Sah __m_sah_18;
	Sah __m_sah_28;
	int __exception;
	int vectorsize;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_knob5_oct_14;
	t_sample m_history_4;
	t_sample __m_slide_22;
	t_sample __m_slide_19;
	t_sample __m_slide_25;
	t_sample m_history_3;
	t_sample m_sw_13;
	t_sample m_knob3_dry_11;
	t_sample m_history_6;
	t_sample m_history_5;
	t_sample m_knob4_oct_12;
	t_sample m_history_7;
	t_sample m_history_9;
	t_sample m_history_8;
	t_sample m_history_2;
	t_sample m_knob6_smooth_10;
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
		m_knob6_smooth_10 = ((int)0);
		m_knob3_dry_11 = ((int)0);
		m_knob4_oct_12 = ((int)0);
		m_sw_13 = ((int)0);
		m_knob5_oct_14 = ((int)0);
		__m_sah_15.reset(0);
		__m_sah_17.reset(1);
		__m_sah_18.reset(1);
		__m_slide_19 = 0;
		__m_slide_22 = 0;
		__m_slide_25 = 0;
		__m_sah_28.reset(0);
		__m_sah_29.reset(0);
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
		t_sample expr_1637 = (((int)1) - sqrt((((int)1) - m_knob6_smooth_10)));
		t_sample iup_20 = (1 / maximum(1, abs(((int)10))));
		t_sample idown_21 = (1 / maximum(1, abs(((int)400))));
		t_sample mul_1602 = (expr_1637 * ((int)200));
		t_sample iup_23 = (1 / maximum(1, abs(mul_1602)));
		t_sample idown_24 = (1 / maximum(1, abs(mul_1602)));
		t_sample iup_26 = (1 / maximum(1, abs(mul_1602)));
		t_sample idown_27 = (1 / maximum(1, abs(mul_1602)));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_1607 = __m_sah_15(m_history_9, m_sw_13, ((int)0));
			t_sample gen_1609 = sah_1607;
			t_sample rsub_1605 = (((int)1) - sah_1607);
			t_sample history_1606_next_1608 = fixdenorm(rsub_1605);
			t_sample out3 = gen_1609;
			t_sample add_1610 = (gen_1609 + ((int)1));
			t_sample choice_16 = int(add_1610);
			t_sample gate_1603 = (((choice_16 >= 1) && (choice_16 < 2)) ? in1 : 0);
			t_sample gate_1604 = ((choice_16 >= 2) ? in1 : 0);
			t_sample mul_1622 = (gate_1604 * m_knob3_dry_11);
			t_sample mul_1629 = (m_history_7 * (-1));
			t_sample mul_1615 = (m_history_8 * (-1));
			t_sample add_1619 = (m_history_2 + ((int)1));
			t_sample mod_1618 = safemod(add_1619, ((int)4));
			int eq_1617 = (mod_1618 == ((int)0));
			t_sample sah_1616 = __m_sah_17(mul_1615, eq_1617, ((int)0));
			t_sample add_1633 = (m_history_1 + ((int)1));
			t_sample mod_1632 = safemod(add_1633, ((int)2));
			int eq_1631 = (mod_1632 == ((int)0));
			t_sample sah_1630 = __m_sah_18(mul_1629, eq_1631, ((int)0));
			t_sample abs_1626 = fabs(gate_1604);
			__m_slide_19 = fixdenorm((__m_slide_19 + (((abs_1626 > __m_slide_19) ? iup_20 : idown_21) * (abs_1626 - __m_slide_19))));
			t_sample slide_1625 = __m_slide_19;
			__m_slide_22 = fixdenorm((__m_slide_22 + (((sah_1630 > __m_slide_22) ? iup_23 : idown_24) * (sah_1630 - __m_slide_22))));
			t_sample slide_1627 = __m_slide_22;
			t_sample mul_1624 = (slide_1625 * slide_1627);
			t_sample mul_1623 = (m_knob4_oct_12 * mul_1624);
			__m_slide_25 = fixdenorm((__m_slide_25 + (((sah_1616 > __m_slide_25) ? iup_26 : idown_27) * (sah_1616 - __m_slide_25))));
			t_sample slide_1613 = __m_slide_25;
			t_sample mul_1612 = (slide_1625 * slide_1613);
			t_sample mul_1611 = (m_knob5_oct_14 * mul_1612);
			t_sample out1 = (((gate_1603 + mul_1611) + mul_1622) + mul_1623);
			t_sample out2 = (((gate_1603 + mul_1611) + mul_1622) + mul_1623);
			t_sample mix_1654 = (m_history_6 + (((t_sample)0.065403129230143) * (gate_1604 - m_history_6)));
			t_sample mix_1595 = mix_1654;
			t_sample mix_1655 = (m_history_5 + (((t_sample)0.065403129230143) * (mix_1595 - m_history_5)));
			t_sample mix_1592 = mix_1655;
			t_sample mix_1656 = (m_history_4 + (((t_sample)0.065403129230143) * (mix_1592 - m_history_4)));
			t_sample mix_1590 = mix_1656;
			t_sample mix_1657 = (m_history_3 + (((t_sample)0.065403129230143) * (mix_1590 - m_history_3)));
			t_sample mix_1588 = mix_1657;
			int gt_1636 = (mix_1588 > ((int)0));
			t_sample sah_1621 = __m_sah_28(mod_1618, gt_1636, ((int)0));
			t_sample sah_1635 = __m_sah_29(mod_1632, gt_1636, ((int)0));
			t_sample history_1614_next_1638 = fixdenorm(sah_1616);
			t_sample history_1628_next_1639 = fixdenorm(sah_1630);
			t_sample history_1597_next_1640 = fixdenorm(mix_1595);
			t_sample history_1593_next_1641 = fixdenorm(mix_1592);
			t_sample history_1591_next_1642 = fixdenorm(mix_1590);
			t_sample history_1589_next_1643 = fixdenorm(mix_1588);
			t_sample history_1620_next_1644 = fixdenorm(sah_1621);
			t_sample history_1634_next_1645 = fixdenorm(sah_1635);
			m_history_9 = history_1606_next_1608;
			m_history_8 = history_1614_next_1638;
			m_history_7 = history_1628_next_1639;
			m_history_6 = history_1597_next_1640;
			m_history_5 = history_1593_next_1641;
			m_history_4 = history_1591_next_1642;
			m_history_3 = history_1589_next_1643;
			m_history_2 = history_1620_next_1644;
			m_history_1 = history_1634_next_1645;
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
	inline void set_knob6_smooth(t_param _value) {
		m_knob6_smooth_10 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_dry(t_param _value) {
		m_knob3_dry_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_oct1(t_param _value) {
		m_knob4_oct_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_oct2(t_param _value) {
		m_knob5_oct_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_knob3_dry(value); break;
		case 1: self->set_knob4_oct1(value); break;
		case 2: self->set_knob5_oct2(value); break;
		case 3: self->set_knob6_smooth(value); break;
		case 4: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_dry_11; break;
		case 1: *value = self->m_knob4_oct_12; break;
		case 2: *value = self->m_knob5_oct_14; break;
		case 3: *value = self->m_knob6_smooth_10; break;
		case 4: *value = self->m_sw_13; break;
		
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
	// initialize parameter 0 ("m_knob3_dry_11")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_dry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_dry_11;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_oct_12")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_oct1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_oct_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_oct_14")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_oct2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_oct_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_smooth_10")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_smooth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_smooth_10;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_13")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_13;
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


} // Subharmonic::
