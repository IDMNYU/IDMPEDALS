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
	t_sample m_knob6_taps_19;
	t_sample m_history_8;
	t_sample m_sw_16;
	t_sample m_sw_15;
	t_sample m_knob5_breadth_17;
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
		m_sw_15 = ((int)0);
		m_sw_16 = ((int)0);
		m_knob5_breadth_17 = 256;
		m_knob4_rate_18 = ((int)0);
		m_knob6_taps_19 = ((int)0);
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
		t_sample expr_1534 = (((int)1) - sqrt(sqrt((((int)1) - m_knob4_rate_18))));
		t_sample expr_1535 = (((int)1) - sqrt(sqrt((((int)1) - m_knob3_depth_20))));
		t_sample div_1419 = (m_sw_16 * ((t_sample)0.5));
		t_sample add_1418 = (div_1419 + ((t_sample)0.5));
		t_sample mul_1427 = (expr_1535 * ((int)1000));
		t_sample add_1426 = (mul_1427 + ((int)2));
		t_sample mul_1424 = (expr_1534 * ((int)10));
		t_sample add_1425 = (mul_1424 + ((t_sample)0.01));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_1528 = __m_sah_21(m_history_14, m_sw_15, ((int)0));
			t_sample gen_1530 = sah_1528;
			t_sample rsub_1526 = (((int)1) - sah_1528);
			t_sample history_1527_next_1529 = fixdenorm(rsub_1526);
			t_sample out3 = gen_1530;
			t_sample add_1531 = (gen_1530 + ((int)1));
			t_sample choice_22 = int(add_1531);
			t_sample gate_1523 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_1524 = ((choice_22 >= 2) ? in1 : 0);
			t_sample switch_1461 = (m_sw_16 ? ((int)0) : gate_1524);
			t_sample mix_1631 = (m_history_13 + (((t_sample)0.003926980723806) * (m_knob6_taps_19 - m_history_13)));
			t_sample mix_1433 = mix_1631;
			t_sample mix_1632 = (m_history_12 + (((t_sample)0.003926980723806) * (mix_1433 - m_history_12)));
			t_sample mix_1431 = mix_1632;
			t_sample mix_1633 = (m_history_11 + (((t_sample)0.003926980723806) * (mix_1431 - m_history_11)));
			t_sample mix_1429 = mix_1633;
			t_sample gen_1459 = mix_1429;
			t_sample history_1434_next_1436 = fixdenorm(mix_1433);
			t_sample history_1432_next_1437 = fixdenorm(mix_1431);
			t_sample history_1430_next_1438 = fixdenorm(mix_1429);
			t_sample sub_1637 = (gen_1459 - ((int)0));
			t_sample scale_1634 = ((safepow((sub_1637 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.5)) + ((int)1));
			t_sample sub_1641 = (gen_1459 - ((int)0));
			t_sample scale_1638 = ((safepow((sub_1641 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-2));
			t_sample clamp_1445 = ((scale_1638 <= ((int)0)) ? ((int)0) : ((scale_1638 >= ((int)1)) ? ((int)1) : scale_1638));
			t_sample sub_1645 = (gen_1459 - ((int)0));
			t_sample scale_1642 = ((safepow((sub_1645 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-3));
			t_sample clamp_1443 = ((scale_1642 <= ((int)0)) ? ((int)0) : ((scale_1642 >= ((int)1)) ? ((int)1) : scale_1642));
			t_sample sub_1649 = (gen_1459 - ((int)0));
			t_sample scale_1646 = ((safepow((sub_1649 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-1));
			t_sample clamp_1447 = ((scale_1646 <= ((int)0)) ? ((int)0) : ((scale_1646 >= ((int)1)) ? ((int)1) : scale_1646));
			t_sample mix_1650 = (m_history_10 + (((t_sample)0.003926980723806) * (m_knob5_breadth_17 - m_history_10)));
			t_sample mix_1538 = mix_1650;
			t_sample mix_1651 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_1538 - m_history_9)));
			t_sample mix_1542 = mix_1651;
			t_sample mix_1652 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_1542 - m_history_8)));
			t_sample mix_1545 = mix_1652;
			t_sample gen_1439 = mix_1545;
			t_sample history_1434_next_1536 = fixdenorm(mix_1538);
			t_sample history_1432_next_1543 = fixdenorm(mix_1542);
			t_sample history_1430_next_1544 = fixdenorm(mix_1545);
			t_sample mul_1428 = (gen_1439 * ((int)1));
			t_sample mul_1442 = (gen_1439 * ((int)2));
			t_sample mul_1441 = (gen_1439 * ((int)3));
			t_sample mul_1440 = (gen_1439 * ((int)4));
			t_sample mix_1653 = (m_history_7 + (((t_sample)0.003926980723806) * (add_1426 - m_history_7)));
			t_sample mix_1551 = mix_1653;
			t_sample mix_1654 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_1551 - m_history_6)));
			t_sample mix_1555 = mix_1654;
			t_sample mix_1655 = (m_history_5 + (((t_sample)0.003926980723806) * (mix_1555 - m_history_5)));
			t_sample mix_1558 = mix_1655;
			t_sample gen_1533 = mix_1558;
			t_sample history_1434_next_1549 = fixdenorm(mix_1551);
			t_sample history_1432_next_1556 = fixdenorm(mix_1555);
			t_sample history_1430_next_1557 = fixdenorm(mix_1558);
			t_sample mix_1656 = (m_history_4 + (((t_sample)0.003926980723806) * (add_1425 - m_history_4)));
			t_sample mix_1567 = mix_1656;
			t_sample mix_1657 = (m_history_3 + (((t_sample)0.003926980723806) * (mix_1567 - m_history_3)));
			t_sample mix_1569 = mix_1657;
			t_sample mix_1658 = (m_history_2 + (((t_sample)0.003926980723806) * (mix_1569 - m_history_2)));
			t_sample mix_1571 = mix_1658;
			t_sample gen_1470 = mix_1571;
			t_sample history_1434_next_1565 = fixdenorm(mix_1567);
			t_sample history_1432_next_1568 = fixdenorm(mix_1569);
			t_sample history_1430_next_1570 = fixdenorm(mix_1571);
			t_sample mul_1474 = (gen_1470 * ((int)1));
			__m_cycle_23.freq(mul_1474);
			t_sample cycle_1512 = __m_cycle_23(__sinedata);
			t_sample cycleindex_1513 = __m_cycle_23.phase();
			t_sample mul_1510 = (cycle_1512 * gen_1533);
			t_sample add_1511 = (mul_1510 + mul_1428);
			t_sample mul_1505 = (gen_1470 * ((t_sample)1.51));
			__m_cycle_24.freq(mul_1505);
			t_sample cycle_1508 = __m_cycle_24(__sinedata);
			t_sample cycleindex_1509 = __m_cycle_24.phase();
			t_sample mul_1506 = (cycle_1508 * gen_1533);
			t_sample add_1507 = (mul_1506 + mul_1428);
			t_sample mul_1473 = (gen_1470 * ((t_sample)0.48));
			__m_cycle_25.freq(mul_1473);
			t_sample cycle_1502 = __m_cycle_25(__sinedata);
			t_sample cycleindex_1503 = __m_cycle_25.phase();
			t_sample mul_1500 = (cycle_1502 * gen_1533);
			t_sample add_1501 = (mul_1500 + mul_1442);
			t_sample mul_1495 = (gen_1470 * ((t_sample)0.73));
			__m_cycle_26.freq(mul_1495);
			t_sample cycle_1498 = __m_cycle_26(__sinedata);
			t_sample cycleindex_1499 = __m_cycle_26.phase();
			t_sample mul_1496 = (cycle_1498 * gen_1533);
			t_sample add_1497 = (mul_1496 + mul_1442);
			t_sample mul_1472 = (gen_1470 * ((t_sample)1.245));
			__m_cycle_27.freq(mul_1472);
			t_sample cycle_1491 = __m_cycle_27(__sinedata);
			t_sample cycleindex_1492 = __m_cycle_27.phase();
			t_sample mul_1489 = (cycle_1491 * gen_1533);
			t_sample add_1490 = (mul_1489 + mul_1441);
			t_sample mul_1484 = (gen_1470 * ((t_sample)0.81));
			__m_cycle_28.freq(mul_1484);
			t_sample cycle_1487 = __m_cycle_28(__sinedata);
			t_sample cycleindex_1488 = __m_cycle_28.phase();
			t_sample mul_1485 = (cycle_1487 * gen_1533);
			t_sample add_1486 = (mul_1485 + mul_1441);
			t_sample mul_1471 = (gen_1470 * ((t_sample)1.93));
			__m_cycle_29.freq(mul_1471);
			t_sample cycle_1482 = __m_cycle_29(__sinedata);
			t_sample cycleindex_1483 = __m_cycle_29.phase();
			t_sample mul_1480 = (cycle_1482 * gen_1533);
			t_sample add_1481 = (mul_1480 + mul_1440);
			t_sample mul_1475 = (gen_1470 * ((t_sample)2.11));
			__m_cycle_30.freq(mul_1475);
			t_sample cycle_1478 = __m_cycle_30(__sinedata);
			t_sample cycleindex_1479 = __m_cycle_30.phase();
			t_sample mul_1476 = (cycle_1478 * gen_1533);
			t_sample add_1477 = (mul_1476 + mul_1440);
			t_sample tap_1515 = m_delay_1.read_linear(add_1511);
			t_sample tap_1516 = m_delay_1.read_linear(add_1507);
			t_sample tap_1517 = m_delay_1.read_linear(add_1501);
			t_sample tap_1518 = m_delay_1.read_linear(add_1497);
			t_sample tap_1519 = m_delay_1.read_linear(add_1490);
			t_sample tap_1520 = m_delay_1.read_linear(add_1486);
			t_sample tap_1521 = m_delay_1.read_linear(add_1481);
			t_sample tap_1522 = m_delay_1.read_linear(add_1477);
			t_sample mul_1458 = (tap_1519 * clamp_1445);
			t_sample mul_1455 = (tap_1522 * clamp_1443);
			t_sample mul_1451 = (tap_1518 * clamp_1447);
			t_sample mul_1454 = (tap_1515 * ((int)1));
			t_sample mul_1494 = ((((mul_1454 + mul_1451) + mul_1455) + mul_1458) * scale_1634);
			t_sample add_1532 = (switch_1461 + mul_1494);
			t_sample mul_1421 = (add_1418 * add_1532);
			t_sample out1 = (gate_1523 + mul_1421);
			t_sample mul_1457 = (tap_1520 * clamp_1445);
			t_sample mul_1456 = (tap_1521 * clamp_1443);
			t_sample mul_1452 = (tap_1517 * clamp_1447);
			t_sample mul_1453 = (tap_1516 * ((int)1));
			t_sample mul_1493 = ((((mul_1453 + mul_1452) + mul_1456) + mul_1457) * scale_1634);
			t_sample add_1504 = (switch_1461 + mul_1493);
			t_sample mul_1420 = (add_1418 * add_1504);
			t_sample out2 = (gate_1523 + mul_1420);
			m_history_14 = history_1527_next_1529;
			m_history_13 = history_1434_next_1436;
			m_history_11 = history_1430_next_1438;
			m_history_12 = history_1432_next_1437;
			m_history_10 = history_1434_next_1536;
			m_history_8 = history_1430_next_1544;
			m_history_9 = history_1432_next_1543;
			m_history_7 = history_1434_next_1549;
			m_history_5 = history_1430_next_1557;
			m_history_6 = history_1432_next_1556;
			m_history_4 = history_1434_next_1565;
			m_history_2 = history_1430_next_1570;
			m_history_3 = history_1432_next_1568;
			m_delay_1.write(gate_1524);
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
	inline void set_sw1(t_param _value) {
		m_sw_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_breadth(t_param _value) {
		m_knob5_breadth_17 = (_value < 240 ? 240 : (_value > 2400 ? 2400 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_taps(t_param _value) {
		m_knob6_taps_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 2: *value = self->m_knob5_breadth_17; break;
		case 3: *value = self->m_knob6_taps_19; break;
		case 4: *value = self->m_sw_15; break;
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
	// initialize parameter 2 ("m_knob5_breadth_17")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_breadth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_breadth_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 240;
	pi->outputmax = 2400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_taps_19")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_taps";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_taps_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_15")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_15;
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


} // Chorus::
