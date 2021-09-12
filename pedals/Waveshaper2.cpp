#include "Waveshaper2.h"

namespace Waveshaper2 {

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
	DCBlock __m_dcblock_28;
	DCBlock __m_dcblock_25;
	Sah __m_sah_23;
	SineCycle __m_cycle_27;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_4;
	t_sample m_sw_18;
	t_sample m_knob5_xthresh_17;
	t_sample m_knob4_xthresh_19;
	t_sample m_knob3_xthresh_20;
	t_sample m_knob6_smooth_21;
	t_sample m_sw_22;
	t_sample m_knob2_output_16;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_history_3;
	t_sample m_knob1_input_15;
	t_sample m_history_13;
	t_sample m_history_7;
	t_sample m_history_6;
	t_sample m_history_5;
	t_sample m_history_14;
	t_sample m_history_8;
	t_sample m_history_10;
	t_sample m_history_9;
	t_sample m_history_2;
	t_sample m_history_11;
	t_sample m_history_12;
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
		m_knob1_input_15 = ((int)0);
		m_knob2_output_16 = ((int)0);
		m_knob5_xthresh_17 = ((int)0);
		m_sw_18 = ((int)0);
		m_knob4_xthresh_19 = ((int)0);
		m_knob3_xthresh_20 = ((int)0);
		m_knob6_smooth_21 = ((int)0);
		m_sw_22 = ((int)0);
		__m_sah_23.reset(0);
		__m_dcblock_25.reset();
		__m_cycle_27.reset(samplerate, 0);
		__m_dcblock_28.reset();
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
		t_sample dbtoa_2933 = dbtoa(m_knob2_output_16);
		t_sample add_4281 = (m_sw_18 + ((int)1));
		t_sample dbtoa_36 = dbtoa(m_knob1_input_15);
		t_sample div_2310 = (m_knob4_xthresh_19 * ((t_sample)0.033333333333333));
		t_sample div_3204 = (m_knob5_xthresh_17 * ((t_sample)0.033333333333333));
		t_sample div_2264 = (m_knob3_xthresh_20 * ((t_sample)0.033333333333333));
		t_sample choice_26 = int(add_4281);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_30 = __m_sah_23(m_history_14, m_sw_22, ((int)0));
			t_sample gen_32 = sah_30;
			t_sample rsub_28 = (((int)1) - sah_30);
			t_sample history_29_next_31 = fixdenorm(rsub_28);
			t_sample out3 = gen_32;
			t_sample add_35 = (gen_32 + ((int)1));
			t_sample choice_24 = int(add_35);
			t_sample gate_33 = (((choice_24 >= 1) && (choice_24 < 2)) ? in1 : 0);
			t_sample gate_34 = ((choice_24 >= 2) ? in1 : 0);
			t_sample mix_6028 = (m_history_13 + (((t_sample)0.0042742627044161) * (m_knob6_smooth_21 - m_history_13)));
			t_sample mix_5 = mix_6028;
			t_sample mix_6029 = (m_history_12 + (((t_sample)0.0042742627044161) * (mix_5 - m_history_12)));
			t_sample mix_3 = mix_6029;
			t_sample mix_6030 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_3 - m_history_11)));
			t_sample mix_1 = mix_6030;
			t_sample gen_11 = mix_1;
			t_sample history_6_next_8 = fixdenorm(mix_5);
			t_sample history_4_next_9 = fixdenorm(mix_3);
			t_sample history_2_next_10 = fixdenorm(mix_1);
			t_sample mul_1485 = (m_history_1 * gen_11);
			t_sample rsub_1353 = (((int)1) - gen_11);
			t_sample mul_26 = (gate_34 * dbtoa_36);
			t_sample dcblock_168 = __m_dcblock_25(mul_26);
			t_sample abs_325 = fabs(dcblock_168);
			t_sample mix_6031 = (m_history_10 + (((t_sample)0.0042742627044161) * (div_2310 - m_history_10)));
			t_sample mix_5865 = mix_6031;
			t_sample mix_6032 = (m_history_9 + (((t_sample)0.0042742627044161) * (mix_5865 - m_history_9)));
			t_sample mix_5863 = mix_6032;
			t_sample mix_6033 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_5863 - m_history_8)));
			t_sample mix_5857 = mix_6033;
			t_sample gen_12 = mix_5857;
			t_sample history_6_next_5859 = fixdenorm(mix_5865);
			t_sample history_4_next_5858 = fixdenorm(mix_5863);
			t_sample history_2_next_5862 = fixdenorm(mix_5857);
			t_sample mix_6034 = (m_history_7 + (((t_sample)0.0042742627044161) * (div_3204 - m_history_7)));
			t_sample mix_5878 = mix_6034;
			t_sample mix_6035 = (m_history_6 + (((t_sample)0.0042742627044161) * (mix_5878 - m_history_6)));
			t_sample mix_5877 = mix_6035;
			t_sample mix_6036 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_5877 - m_history_5)));
			t_sample mix_5870 = mix_6036;
			t_sample gen_3205 = mix_5870;
			t_sample history_6_next_5872 = fixdenorm(mix_5878);
			t_sample history_4_next_5871 = fixdenorm(mix_5877);
			t_sample history_2_next_5875 = fixdenorm(mix_5870);
			t_sample mul_3642 = (gen_3205 * (-1));
			int lt_3797 = (mul_3642 < ((int)0));
			int switch_3389 = (lt_3797 ? ((int)-1) : ((int)1));
			t_sample mix_6037 = (m_history_4 + (((t_sample)0.0042742627044161) * (div_2264 - m_history_4)));
			t_sample mix_5886 = mix_6037;
			t_sample mix_6038 = (m_history_3 + (((t_sample)0.0042742627044161) * (mix_5886 - m_history_3)));
			t_sample mix_5891 = mix_6038;
			t_sample mix_6039 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_5891 - m_history_2)));
			t_sample mix_5884 = mix_6039;
			t_sample gen_13 = mix_5884;
			t_sample history_6_next_5883 = fixdenorm(mix_5886);
			t_sample history_4_next_5885 = fixdenorm(mix_5891);
			t_sample history_2_next_5890 = fixdenorm(mix_5884);
			int gt_430 = (abs_325 > gen_13);
			int switch_587 = (gt_430 ? ((int)-1) : ((int)1));
			t_sample mul_902 = (dcblock_168 * switch_587);
			int gt_1115 = (mul_902 > gen_12);
			int switch_1114 = (gt_1115 ? ((int)-1) : ((int)1));
			t_sample mul_1111 = (mul_902 * switch_1114);
			t_sample mul_3386 = (mul_1111 * switch_3389);
			t_sample gate_4215 = (((choice_26 >= 1) && (choice_26 < 2)) ? mul_3386 : 0);
			t_sample gate_4216 = ((choice_26 >= 2) ? mul_3386 : 0);
			__m_cycle_27.phase(gate_4216);
			t_sample cycle_4666 = __m_cycle_27(__sinedata);
			t_sample cycleindex_4667 = __m_cycle_27.phase();
			t_sample mul_1406 = ((gate_4215 + cycle_4666) * rsub_1353);
			t_sample add_1564 = (mul_1406 + mul_1485);
			t_sample mul_2752 = (add_1564 * dbtoa_2933);
			t_sample dcblock_37 = __m_dcblock_28(mul_2752);
			t_sample out2 = (gate_33 + dcblock_37);
			t_sample out1 = (gate_33 + dcblock_37);
			t_sample history_1325_next_5895 = fixdenorm(add_1564);
			m_history_14 = history_29_next_31;
			m_history_13 = history_6_next_8;
			m_history_11 = history_2_next_10;
			m_history_12 = history_4_next_9;
			m_history_10 = history_6_next_5859;
			m_history_8 = history_2_next_5862;
			m_history_9 = history_4_next_5858;
			m_history_7 = history_6_next_5872;
			m_history_5 = history_2_next_5875;
			m_history_6 = history_4_next_5871;
			m_history_4 = history_6_next_5883;
			m_history_2 = history_2_next_5890;
			m_history_3 = history_4_next_5885;
			m_history_1 = history_1325_next_5895;
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
	inline void set_knob1_input(t_param _value) {
		m_knob1_input_15 = (_value < -6 ? -6 : (_value > 15 ? 15 : _value));
	};
	inline void set_knob2_output(t_param _value) {
		m_knob2_output_16 = (_value < -70 ? -70 : (_value > 15 ? 15 : _value));
	};
	inline void set_knob5_xthresh3(t_param _value) {
		m_knob5_xthresh_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_xthresh2(t_param _value) {
		m_knob4_xthresh_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_xthresh1(t_param _value) {
		m_knob3_xthresh_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_smooth(t_param _value) {
		m_knob6_smooth_21 = (_value < 0 ? 0 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_knob1_input(value); break;
		case 1: self->set_knob2_output(value); break;
		case 2: self->set_knob3_xthresh1(value); break;
		case 3: self->set_knob4_xthresh2(value); break;
		case 4: self->set_knob5_xthresh3(value); break;
		case 5: self->set_knob6_smooth(value); break;
		case 6: self->set_sw1(value); break;
		case 7: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_input_15; break;
		case 1: *value = self->m_knob2_output_16; break;
		case 2: *value = self->m_knob3_xthresh_20; break;
		case 3: *value = self->m_knob4_xthresh_19; break;
		case 4: *value = self->m_knob5_xthresh_17; break;
		case 5: *value = self->m_knob6_smooth_21; break;
		case 6: *value = self->m_sw_22; break;
		case 7: *value = self->m_sw_18; break;
		
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
	// initialize parameter 0 ("m_knob1_input_15")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_input";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_input_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -6;
	pi->outputmax = 15;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob2_output_16")
	pi = self->__commonstate.params + 1;
	pi->name = "knob2_output";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_output_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -70;
	pi->outputmax = 15;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob3_xthresh_20")
	pi = self->__commonstate.params + 2;
	pi->name = "knob3_xthresh1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_xthresh_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob4_xthresh_19")
	pi = self->__commonstate.params + 3;
	pi->name = "knob4_xthresh2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_xthresh_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob5_xthresh_17")
	pi = self->__commonstate.params + 4;
	pi->name = "knob5_xthresh3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_xthresh_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob6_smooth_21")
	pi = self->__commonstate.params + 5;
	pi->name = "knob6_smooth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_smooth_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_sw_22")
	pi = self->__commonstate.params + 6;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_sw_18")
	pi = self->__commonstate.params + 7;
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


} // Waveshaper2::
