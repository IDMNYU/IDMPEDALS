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
	t_sample m_knob4_rate_20;
	t_sample m_sw_18;
	t_sample m_history_13;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_knob5_breadth_19;
	t_sample m_history_8;
	t_sample m_knob6_taps_16;
	t_sample m_knob3_depth_15;
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
		m_knob3_depth_15 = ((int)0);
		m_knob6_taps_16 = ((int)0);
		m_sw_17 = ((int)0);
		m_sw_18 = ((int)0);
		m_knob5_breadth_19 = 256;
		m_knob4_rate_20 = ((int)0);
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
		t_sample expr_48509 = (((int)1) - sqrt(sqrt((((int)1) - m_knob4_rate_20))));
		t_sample expr_48510 = (((int)1) - sqrt(sqrt((((int)1) - m_knob3_depth_15))));
		t_sample div_48091 = (m_sw_18 * ((t_sample)0.5));
		t_sample add_48196 = (div_48091 + ((t_sample)0.5));
		t_sample mul_46659 = (expr_48510 * ((int)1000));
		t_sample add_46658 = (mul_46659 + ((int)2));
		t_sample mul_46656 = (expr_48509 * ((int)10));
		t_sample add_46657 = (mul_46656 + ((t_sample)0.01));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_46762 = __m_sah_21(m_history_14, m_sw_17, ((int)0));
			t_sample gen_46764 = sah_46762;
			t_sample rsub_46760 = (((int)1) - sah_46762);
			t_sample history_46761_next_46763 = fixdenorm(rsub_46760);
			t_sample out3 = gen_46764;
			t_sample add_46765 = (gen_46764 + ((int)1));
			t_sample choice_22 = int(add_46765);
			t_sample gate_46757 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_46758 = ((choice_22 >= 2) ? in1 : 0);
			t_sample switch_46695 = (m_sw_18 ? ((int)0) : gate_46758);
			t_sample mix_48613 = (m_history_13 + (((t_sample)0.0019634941468452) * (m_knob6_taps_16 - m_history_13)));
			t_sample mix_46665 = mix_48613;
			t_sample mix_48614 = (m_history_12 + (((t_sample)0.0019634941468452) * (mix_46665 - m_history_12)));
			t_sample mix_46663 = mix_48614;
			t_sample mix_48615 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_46663 - m_history_11)));
			t_sample mix_46661 = mix_48615;
			t_sample gen_46693 = mix_46661;
			t_sample history_46667_next_46670 = fixdenorm(mix_46665);
			t_sample history_46664_next_46671 = fixdenorm(mix_46663);
			t_sample history_46662_next_46672 = fixdenorm(mix_46661);
			t_sample sub_48619 = (gen_46693 - ((int)0));
			t_sample scale_48616 = ((safepow((sub_48619 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.5)) + ((int)1));
			t_sample sub_48623 = (gen_46693 - ((int)0));
			t_sample scale_48620 = ((safepow((sub_48623 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-2));
			t_sample clamp_46679 = ((scale_48620 <= ((int)0)) ? ((int)0) : ((scale_48620 >= ((int)1)) ? ((int)1) : scale_48620));
			t_sample sub_48627 = (gen_46693 - ((int)0));
			t_sample scale_48624 = ((safepow((sub_48627 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-3));
			t_sample clamp_46677 = ((scale_48624 <= ((int)0)) ? ((int)0) : ((scale_48624 >= ((int)1)) ? ((int)1) : scale_48624));
			t_sample sub_48631 = (gen_46693 - ((int)0));
			t_sample scale_48628 = ((safepow((sub_48631 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-1));
			t_sample clamp_46681 = ((scale_48628 <= ((int)0)) ? ((int)0) : ((scale_48628 >= ((int)1)) ? ((int)1) : scale_48628));
			t_sample mix_48632 = (m_history_10 + (((t_sample)0.0019634941468452) * (m_knob5_breadth_19 - m_history_10)));
			t_sample mix_48522 = mix_48632;
			t_sample mix_48633 = (m_history_9 + (((t_sample)0.0019634941468452) * (mix_48522 - m_history_9)));
			t_sample mix_48521 = mix_48633;
			t_sample mix_48634 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_48521 - m_history_8)));
			t_sample mix_48514 = mix_48634;
			t_sample gen_46673 = mix_48514;
			t_sample history_46667_next_48518 = fixdenorm(mix_48522);
			t_sample history_46664_next_48512 = fixdenorm(mix_48521);
			t_sample history_46662_next_48519 = fixdenorm(mix_48514);
			t_sample mul_46660 = (gen_46673 * ((int)1));
			t_sample mul_46676 = (gen_46673 * ((int)2));
			t_sample mul_46675 = (gen_46673 * ((int)3));
			t_sample mul_46674 = (gen_46673 * ((int)4));
			t_sample mix_48635 = (m_history_7 + (((t_sample)0.0019634941468452) * (add_46658 - m_history_7)));
			t_sample mix_48536 = mix_48635;
			t_sample mix_48636 = (m_history_6 + (((t_sample)0.0019634941468452) * (mix_48536 - m_history_6)));
			t_sample mix_48527 = mix_48636;
			t_sample mix_48637 = (m_history_5 + (((t_sample)0.0019634941468452) * (mix_48527 - m_history_5)));
			t_sample mix_48530 = mix_48637;
			t_sample gen_46767 = mix_48530;
			t_sample history_46667_next_48534 = fixdenorm(mix_48536);
			t_sample history_46664_next_48528 = fixdenorm(mix_48527);
			t_sample history_46662_next_48535 = fixdenorm(mix_48530);
			t_sample mix_48638 = (m_history_4 + (((t_sample)0.0019634941468452) * (add_46657 - m_history_4)));
			t_sample mix_48548 = mix_48638;
			t_sample mix_48639 = (m_history_3 + (((t_sample)0.0019634941468452) * (mix_48548 - m_history_3)));
			t_sample mix_48542 = mix_48639;
			t_sample mix_48640 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_48542 - m_history_2)));
			t_sample mix_48551 = mix_48640;
			t_sample gen_46704 = mix_48551;
			t_sample history_46667_next_48550 = fixdenorm(mix_48548);
			t_sample history_46664_next_48549 = fixdenorm(mix_48542);
			t_sample history_46662_next_48544 = fixdenorm(mix_48551);
			t_sample mul_46708 = (gen_46704 * ((int)1));
			__m_cycle_23.freq(mul_46708);
			t_sample cycle_46746 = __m_cycle_23(__sinedata);
			t_sample cycleindex_46747 = __m_cycle_23.phase();
			t_sample mul_46744 = (cycle_46746 * gen_46767);
			t_sample add_46745 = (mul_46744 + mul_46660);
			t_sample mul_46739 = (gen_46704 * ((t_sample)1.51));
			__m_cycle_24.freq(mul_46739);
			t_sample cycle_46742 = __m_cycle_24(__sinedata);
			t_sample cycleindex_46743 = __m_cycle_24.phase();
			t_sample mul_46740 = (cycle_46742 * gen_46767);
			t_sample add_46741 = (mul_46740 + mul_46660);
			t_sample mul_46707 = (gen_46704 * ((t_sample)0.48));
			__m_cycle_25.freq(mul_46707);
			t_sample cycle_46736 = __m_cycle_25(__sinedata);
			t_sample cycleindex_46737 = __m_cycle_25.phase();
			t_sample mul_46734 = (cycle_46736 * gen_46767);
			t_sample add_46735 = (mul_46734 + mul_46676);
			t_sample mul_46729 = (gen_46704 * ((t_sample)0.73));
			__m_cycle_26.freq(mul_46729);
			t_sample cycle_46732 = __m_cycle_26(__sinedata);
			t_sample cycleindex_46733 = __m_cycle_26.phase();
			t_sample mul_46730 = (cycle_46732 * gen_46767);
			t_sample add_46731 = (mul_46730 + mul_46676);
			t_sample mul_46706 = (gen_46704 * ((t_sample)1.245));
			__m_cycle_27.freq(mul_46706);
			t_sample cycle_46725 = __m_cycle_27(__sinedata);
			t_sample cycleindex_46726 = __m_cycle_27.phase();
			t_sample mul_46723 = (cycle_46725 * gen_46767);
			t_sample add_46724 = (mul_46723 + mul_46675);
			t_sample mul_46718 = (gen_46704 * ((t_sample)0.81));
			__m_cycle_28.freq(mul_46718);
			t_sample cycle_46721 = __m_cycle_28(__sinedata);
			t_sample cycleindex_46722 = __m_cycle_28.phase();
			t_sample mul_46719 = (cycle_46721 * gen_46767);
			t_sample add_46720 = (mul_46719 + mul_46675);
			t_sample mul_46705 = (gen_46704 * ((t_sample)1.93));
			__m_cycle_29.freq(mul_46705);
			t_sample cycle_46716 = __m_cycle_29(__sinedata);
			t_sample cycleindex_46717 = __m_cycle_29.phase();
			t_sample mul_46714 = (cycle_46716 * gen_46767);
			t_sample add_46715 = (mul_46714 + mul_46674);
			t_sample mul_46709 = (gen_46704 * ((t_sample)2.11));
			__m_cycle_30.freq(mul_46709);
			t_sample cycle_46712 = __m_cycle_30(__sinedata);
			t_sample cycleindex_46713 = __m_cycle_30.phase();
			t_sample mul_46710 = (cycle_46712 * gen_46767);
			t_sample add_46711 = (mul_46710 + mul_46674);
			t_sample tap_46749 = m_delay_1.read_linear(add_46745);
			t_sample tap_46750 = m_delay_1.read_linear(add_46741);
			t_sample tap_46751 = m_delay_1.read_linear(add_46735);
			t_sample tap_46752 = m_delay_1.read_linear(add_46731);
			t_sample tap_46753 = m_delay_1.read_linear(add_46724);
			t_sample tap_46754 = m_delay_1.read_linear(add_46720);
			t_sample tap_46755 = m_delay_1.read_linear(add_46715);
			t_sample tap_46756 = m_delay_1.read_linear(add_46711);
			t_sample mul_46692 = (tap_46753 * clamp_46679);
			t_sample mul_46689 = (tap_46756 * clamp_46677);
			t_sample mul_46685 = (tap_46752 * clamp_46681);
			t_sample mul_46688 = (tap_46749 * ((int)1));
			t_sample mul_46728 = ((((mul_46688 + mul_46685) + mul_46689) + mul_46692) * scale_48616);
			t_sample add_46766 = (switch_46695 + mul_46728);
			t_sample mul_47345 = (add_48196 * add_46766);
			t_sample out1 = (mul_47345 + gate_46757);
			t_sample mul_46691 = (tap_46754 * clamp_46679);
			t_sample mul_46690 = (tap_46755 * clamp_46677);
			t_sample mul_46686 = (tap_46751 * clamp_46681);
			t_sample mul_46687 = (tap_46750 * ((int)1));
			t_sample mul_46727 = ((((mul_46687 + mul_46686) + mul_46690) + mul_46691) * scale_48616);
			t_sample add_46738 = (switch_46695 + mul_46727);
			t_sample mul_47450 = (add_48196 * add_46738);
			t_sample out2 = (mul_47450 + gate_46757);
			m_history_14 = history_46761_next_46763;
			m_history_13 = history_46667_next_46670;
			m_history_11 = history_46662_next_46672;
			m_history_12 = history_46664_next_46671;
			m_history_10 = history_46667_next_48518;
			m_history_8 = history_46662_next_48519;
			m_history_9 = history_46664_next_48512;
			m_history_7 = history_46667_next_48534;
			m_history_5 = history_46662_next_48535;
			m_history_6 = history_46664_next_48528;
			m_history_4 = history_46667_next_48550;
			m_history_2 = history_46662_next_48544;
			m_history_3 = history_46664_next_48549;
			m_delay_1.write(gate_46758);
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
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_taps(t_param _value) {
		m_knob6_taps_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_breadth(t_param _value) {
		m_knob5_breadth_19 = (_value < 240 ? 240 : (_value > 2400 ? 2400 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_depth_15; break;
		case 1: *value = self->m_knob4_rate_20; break;
		case 2: *value = self->m_knob5_breadth_19; break;
		case 3: *value = self->m_knob6_taps_16; break;
		case 4: *value = self->m_sw_17; break;
		case 5: *value = self->m_sw_18; break;
		
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
	// initialize parameter 0 ("m_knob3_depth_15")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_20")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_breadth_19")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_breadth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_breadth_19;
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
	// initialize parameter 4 ("m_sw_17")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
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
	// initialize parameter 5 ("m_sw_18")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_18;
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
