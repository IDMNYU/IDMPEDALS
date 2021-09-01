#include "FreqShiftRingMod.h"

namespace FreqShiftRingMod {

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
	Phasor __m_phasor_48;
	Sah __m_sah_7;
	int __exception;
	int vectorsize;
	t_sample m_x_33;
	t_sample m_sw_1;
	t_sample m_x_35;
	t_sample m_x_32;
	t_sample m_x_29;
	t_sample m_x_30;
	t_sample m_x_27;
	t_sample m_x_26;
	t_sample m_x_36;
	t_sample m_x_39;
	t_sample m_x_45;
	t_sample m_x_38;
	t_sample m_x_44;
	t_sample m_x_41;
	t_sample m_x_42;
	t_sample m_x_24;
	t_sample m_x_23;
	t_sample samples_to_seconds;
	t_sample m_sw_5;
	t_sample m_knob4_fine_6;
	t_sample m_x_9;
	t_sample m_knob3_freq_4;
	t_sample m_history_2;
	t_sample m_knob5_mix_3;
	t_sample samplerate;
	t_sample m_x_10;
	t_sample m_x_13;
	t_sample m_x_19;
	t_sample m_x_12;
	t_sample m_x_18;
	t_sample m_x_15;
	t_sample m_x_16;
	t_sample m_x_22;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_sw_1 = ((int)0);
		m_history_2 = ((int)0);
		m_knob5_mix_3 = ((int)0);
		m_knob3_freq_4 = ((int)0);
		m_sw_5 = ((int)0);
		m_knob4_fine_6 = ((int)0);
		__m_sah_7.reset(0);
		m_x_9 = ((int)0);
		m_x_10 = ((int)0);
		m_x_12 = ((int)0);
		m_x_13 = ((int)0);
		m_x_15 = ((int)0);
		m_x_16 = ((int)0);
		m_x_18 = ((int)0);
		m_x_19 = ((int)0);
		m_x_22 = ((int)0);
		m_x_23 = ((int)0);
		m_x_24 = ((int)0);
		m_x_26 = ((int)0);
		m_x_27 = ((int)0);
		m_x_29 = ((int)0);
		m_x_30 = ((int)0);
		m_x_32 = ((int)0);
		m_x_33 = ((int)0);
		m_x_35 = ((int)0);
		m_x_36 = ((int)0);
		m_x_38 = ((int)0);
		m_x_39 = ((int)0);
		m_x_41 = ((int)0);
		m_x_42 = ((int)0);
		m_x_44 = ((int)0);
		m_x_45 = ((int)0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_48.reset(0);
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
		t_sample add_1610 = (m_knob3_freq_4 + m_knob4_fine_6);
		int md = int(m_sw_1);
		samples_to_seconds = (1 / samplerate);
		t_sample rsub_1609 = (((int)1) - m_knob5_mix_3);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_1619 = __m_sah_7(m_history_2, m_sw_5, ((int)0));
			t_sample gen_1621 = sah_1619;
			t_sample rsub_1617 = (((int)1) - sah_1619);
			t_sample history_1618_next_1620 = fixdenorm(rsub_1617);
			t_sample out3 = gen_1621;
			t_sample add_1622 = (gen_1621 + ((int)1));
			t_sample choice_8 = int(add_1622);
			t_sample gate_1615 = (((choice_8 >= 1) && (choice_8 < 2)) ? in1 : 0);
			t_sample gate_1616 = ((choice_8 >= 2) ? in1 : 0);
			t_sample return_20;
			t_sample return_21;
			hilbertBiquad_d(gate_1616, return_20, return_21);
			t_sample r = return_20;
			t_sample i = return_21;
			if ((md == ((int)1))) {
				t_sample return_46;
				t_sample return_47;
				polyphaseIIR_d(gate_1616, return_46, return_47);
				r = return_46;
				i = return_47;
				
			};
			t_sample return_49;
			t_sample return_50;
			t_sample return_51;
			complexSine_d(add_1610, return_49, return_50, return_51);
			t_sample rm = return_49;
			t_sample ri = return_50;
			t_sample sync = return_51;
			t_sample return_52;
			t_sample return_53;
			complexRing_d_d_d_d(r, i, rm, ri, return_52, return_53);
			t_sample expr_1625 = return_52;
			t_sample expr_1626 = return_53;
			t_sample mix_1630 = (expr_1625 + (rsub_1609 * (expr_1626 - expr_1625)));
			t_sample add_1624 = (gate_1615 + mix_1630);
			t_sample out1 = add_1624;
			t_sample add_1614 = (gate_1615 + mix_1630);
			t_sample out2 = add_1614;
			m_history_2 = history_1618_next_1620;
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
	inline void set_sw5(t_param _value) {
		m_sw_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_mix(t_param _value) {
		m_knob5_mix_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_freq(t_param _value) {
		m_knob3_freq_4 = (_value < 0.1 ? 0.1 : (_value > 5000 ? 5000 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_fine(t_param _value) {
		m_knob4_fine_6 = (_value < -50 ? -50 : (_value > 50 ? 50 : _value));
	};
	inline void hilbertBiquad_d(t_sample x0, t_sample& out1, t_sample& out2) {
		t_sample x1 = biquadTdf2_d_d_d_i_d_d(x0, ((t_sample)0.94657), (-((t_sample)1.94632)), ((int)1), (-((t_sample)1.94632)), ((t_sample)0.94657));
		t_sample x2 = biquadTdf2_d_d_d_i_d_d_11(x1, ((t_sample)0.06338), (-((t_sample)0.83774)), ((int)1), (-((t_sample)0.83774)), ((t_sample)0.06338));
		t_sample y1 = biquadTdf2_d_d_d_i_d_d_14(x0, (-((t_sample)0.260502)), ((t_sample)0.02569), ((int)1), ((t_sample)0.02569), (-((t_sample)0.260502)));
		t_sample y2 = biquadTdf2_d_d_d_i_d_d_17(y1, ((t_sample)0.870686), (-((t_sample)1.8685)), ((int)1), (-((t_sample)1.8685)), ((t_sample)0.870686));
		out1 = x2;
		out2 = y2;
		
	};
	inline t_sample biquadTdf2_d_d_d_i_d_d(t_sample x, t_sample a0, t_sample a1, int a2, t_sample b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_9);
		m_x_9 = (((x * a1) - (y * b1)) + m_x_10);
		m_x_10 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_d_i_d_d_11(t_sample x, t_sample a0, t_sample a1, int a2, t_sample b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_12);
		m_x_12 = (((x * a1) - (y * b1)) + m_x_13);
		m_x_13 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_d_i_d_d_14(t_sample x, t_sample a0, t_sample a1, int a2, t_sample b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_15);
		m_x_15 = (((x * a1) - (y * b1)) + m_x_16);
		m_x_16 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_d_i_d_d_17(t_sample x, t_sample a0, t_sample a1, int a2, t_sample b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_18);
		m_x_18 = (((x * a1) - (y * b1)) + m_x_19);
		m_x_19 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline void polyphaseIIR_d(t_sample y0, t_sample& out1, t_sample& out2) {
		t_sample x1 = biquadTdf2_d_d_i_i_i_d(m_x_22, ((t_sample)0.479401), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.479401)));
		t_sample x2 = biquadTdf2_d_d_i_i_i_d_25(x1, ((t_sample)0.876218), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.876218)));
		t_sample x3 = biquadTdf2_d_d_i_i_i_d_28(x2, ((t_sample)0.976599), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.976599)));
		t_sample x4 = biquadTdf2_d_d_i_i_i_d_31(x3, ((t_sample)0.9975), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.9975)));
		t_sample y1 = biquadTdf2_d_d_i_i_i_d_34(y0, ((t_sample)0.161758), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.161758)));
		t_sample y2 = biquadTdf2_d_d_i_i_i_d_37(y1, ((t_sample)0.733029), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.733029)));
		t_sample y3 = biquadTdf2_d_d_i_i_i_d_40(y2, ((t_sample)0.94535), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.94535)));
		t_sample y4 = biquadTdf2_d_d_i_i_i_d_43(y3, ((t_sample)0.990598), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.990598)));
		m_x_22 = y0;
		out1 = x4;
		out2 = y4;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_23);
		m_x_23 = (((x * a1) - (y * b1)) + m_x_24);
		m_x_24 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_25(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_26);
		m_x_26 = (((x * a1) - (y * b1)) + m_x_27);
		m_x_27 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_28(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_29);
		m_x_29 = (((x * a1) - (y * b1)) + m_x_30);
		m_x_30 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_31(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_32);
		m_x_32 = (((x * a1) - (y * b1)) + m_x_33);
		m_x_33 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_34(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_35);
		m_x_35 = (((x * a1) - (y * b1)) + m_x_36);
		m_x_36 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_37(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_38);
		m_x_38 = (((x * a1) - (y * b1)) + m_x_39);
		m_x_39 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_40(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_41);
		m_x_41 = (((x * a1) - (y * b1)) + m_x_42);
		m_x_42 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_43(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_44);
		m_x_44 = (((x * a1) - (y * b1)) + m_x_45);
		m_x_45 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline void complexSine_d(t_sample hz, t_sample& out1, t_sample& out2, t_sample& out3) {
		t_sample p = __m_phasor_48(hz, samples_to_seconds);
		t_sample real = cos(phasewrap((p * ((t_sample)6.2831853071796))));
		t_sample imaginary = cos(phasewrap(((p + (-((t_sample)0.25))) * ((t_sample)6.2831853071796))));
		out1 = real;
		out2 = imaginary;
		out3 = p;
		
	};
	inline void complexRing_d_d_d_d(t_sample r, t_sample i, t_sample rmod, t_sample imod, t_sample& out1, t_sample& out2) {
		t_sample cosp = (r * rmod);
		t_sample sinp = (i * imod);
		t_sample uppersideband = (cosp + sinp);
		t_sample lowersideband = (cosp - sinp);
		out1 = uppersideband;
		out2 = lowersideband;
		
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
		case 0: self->set_knob3_freq(value); break;
		case 1: self->set_knob4_fine(value); break;
		case 2: self->set_knob5_mix(value); break;
		case 3: self->set_sw1(value); break;
		case 4: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_freq_4; break;
		case 1: *value = self->m_knob4_fine_6; break;
		case 2: *value = self->m_knob5_mix_3; break;
		case 3: *value = self->m_sw_5; break;
		case 4: *value = self->m_sw_1; break;
		
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
	// initialize parameter 0 ("m_knob3_freq_4")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_freq";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_freq_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.1;
	pi->outputmax = 5000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_fine_6")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_fine";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fine_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -50;
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_mix_3")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_mix";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_mix_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_sw_5")
	pi = self->__commonstate.params + 3;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_1")
	pi = self->__commonstate.params + 4;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_1;
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


} // FreqShiftRingMod::
