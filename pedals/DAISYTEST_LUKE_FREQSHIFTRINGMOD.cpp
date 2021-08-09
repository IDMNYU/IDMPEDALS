#include "DAISYTEST_LUKE_FREQSHIFTRINGMOD.h"

namespace DAISYTEST_LUKE_FREQSHIFTRINGMOD {

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
	Phasor __m_phasor_43;
	int vectorsize;
	int __exception;
	t_sample m_mode_1;
	t_sample m_x_28;
	t_sample m_x_29;
	t_sample m_x_26;
	t_sample m_x_23;
	t_sample m_x_25;
	t_sample m_x_22;
	t_sample m_x_31;
	t_sample m_x_34;
	t_sample m_x_38;
	t_sample m_x_32;
	t_sample m_x_37;
	t_sample m_x_35;
	t_sample samplerate;
	t_sample m_x_20;
	t_sample m_x_17;
	t_sample m_x_5;
	t_sample m_x_6;
	t_sample m_x_3;
	t_sample m_x_2;
	t_sample samples_to_seconds;
	t_sample m_x_8;
	t_sample m_x_11;
	t_sample m_x_16;
	t_sample m_x_9;
	t_sample m_x_15;
	t_sample m_x_12;
	t_sample m_x_19;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_mode_1 = ((int)0);
		m_x_2 = ((int)0);
		m_x_3 = ((int)0);
		m_x_5 = ((int)0);
		m_x_6 = ((int)0);
		m_x_8 = ((int)0);
		m_x_9 = ((int)0);
		m_x_11 = ((int)0);
		m_x_12 = ((int)0);
		m_x_15 = ((int)0);
		m_x_16 = ((int)0);
		m_x_17 = ((int)0);
		m_x_19 = ((int)0);
		m_x_20 = ((int)0);
		m_x_22 = ((int)0);
		m_x_23 = ((int)0);
		m_x_25 = ((int)0);
		m_x_26 = ((int)0);
		m_x_28 = ((int)0);
		m_x_29 = ((int)0);
		m_x_31 = ((int)0);
		m_x_32 = ((int)0);
		m_x_34 = ((int)0);
		m_x_35 = ((int)0);
		m_x_37 = ((int)0);
		m_x_38 = ((int)0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_43.reset(0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int md = int(m_mode_1);
		samples_to_seconds = (1 / samplerate);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample return_13;
			t_sample return_14;
			hilbertBiquad_d(in1, return_13, return_14);
			t_sample r = return_13;
			t_sample i = return_14;
			if ((md == ((int)1))) {
				t_sample return_39;
				t_sample return_40;
				polyphaseIIR_d(in1, return_39, return_40);
				r = return_39;
				i = return_40;
				
			} else {
				t_sample return_41;
				t_sample return_42;
				hilbertBiquad_d(in1, return_41, return_42);
				r = return_41;
				i = return_42;
				
			};
			t_sample return_44;
			t_sample return_45;
			t_sample return_46;
			complexSine_d(in2, return_44, return_45, return_46);
			t_sample rm = return_44;
			t_sample ri = return_45;
			t_sample sync = return_46;
			t_sample return_47;
			t_sample return_48;
			complexRing_d_d_d_d(r, i, rm, ri, return_47, return_48);
			t_sample expr_4468 = return_47;
			t_sample expr_4469 = return_48;
			t_sample out2 = expr_4469;
			t_sample out3 = sync;
			t_sample out1 = expr_4468;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			
		};
		return __exception;
		
	};
	inline void set_mode(t_param _value) {
		m_mode_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void hilbertBiquad_d(t_sample x0, t_sample& out1, t_sample& out2) {
		t_sample x1 = biquadTdf2_d_d_d_i_d_d(x0, ((t_sample)0.94657), (-((t_sample)1.94632)), ((int)1), (-((t_sample)1.94632)), ((t_sample)0.94657));
		t_sample x2 = biquadTdf2_d_d_d_i_d_d_4(x1, ((t_sample)0.06338), (-((t_sample)0.83774)), ((int)1), (-((t_sample)0.83774)), ((t_sample)0.06338));
		t_sample y1 = biquadTdf2_d_d_d_i_d_d_7(x0, (-((t_sample)0.260502)), ((t_sample)0.02569), ((int)1), ((t_sample)0.02569), (-((t_sample)0.260502)));
		t_sample y2 = biquadTdf2_d_d_d_i_d_d_10(y1, ((t_sample)0.870686), (-((t_sample)1.8685)), ((int)1), (-((t_sample)1.8685)), ((t_sample)0.870686));
		out1 = x2;
		out2 = y2;
		
	};
	inline t_sample biquadTdf2_d_d_d_i_d_d(t_sample x, t_sample a0, t_sample a1, int a2, t_sample b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_3);
		m_x_3 = (((x * a1) - (y * b1)) + m_x_2);
		m_x_2 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_d_i_d_d_4(t_sample x, t_sample a0, t_sample a1, int a2, t_sample b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_6);
		m_x_6 = (((x * a1) - (y * b1)) + m_x_5);
		m_x_5 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_d_i_d_d_7(t_sample x, t_sample a0, t_sample a1, int a2, t_sample b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_9);
		m_x_9 = (((x * a1) - (y * b1)) + m_x_8);
		m_x_8 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_d_i_d_d_10(t_sample x, t_sample a0, t_sample a1, int a2, t_sample b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_12);
		m_x_12 = (((x * a1) - (y * b1)) + m_x_11);
		m_x_11 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline void polyphaseIIR_d(t_sample y0, t_sample& out1, t_sample& out2) {
		t_sample x1 = biquadTdf2_d_d_i_i_i_d(m_x_15, ((t_sample)0.479401), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.479401)));
		t_sample x2 = biquadTdf2_d_d_i_i_i_d_18(x1, ((t_sample)0.876218), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.876218)));
		t_sample x3 = biquadTdf2_d_d_i_i_i_d_21(x2, ((t_sample)0.976599), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.976599)));
		t_sample x4 = biquadTdf2_d_d_i_i_i_d_24(x3, ((t_sample)0.9975), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.9975)));
		t_sample y1 = biquadTdf2_d_d_i_i_i_d_27(y0, ((t_sample)0.161758), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.161758)));
		t_sample y2 = biquadTdf2_d_d_i_i_i_d_30(y1, ((t_sample)0.733029), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.733029)));
		t_sample y3 = biquadTdf2_d_d_i_i_i_d_33(y2, ((t_sample)0.94535), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.94535)));
		t_sample y4 = biquadTdf2_d_d_i_i_i_d_36(y3, ((t_sample)0.990598), ((int)0), (-((int)1)), ((int)0), (-((t_sample)0.990598)));
		m_x_15 = y0;
		out1 = x4;
		out2 = y4;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_17);
		m_x_17 = (((x * a1) - (y * b1)) + m_x_16);
		m_x_16 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_18(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_20);
		m_x_20 = (((x * a1) - (y * b1)) + m_x_19);
		m_x_19 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_21(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_23);
		m_x_23 = (((x * a1) - (y * b1)) + m_x_22);
		m_x_22 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_24(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_26);
		m_x_26 = (((x * a1) - (y * b1)) + m_x_25);
		m_x_25 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_27(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_29);
		m_x_29 = (((x * a1) - (y * b1)) + m_x_28);
		m_x_28 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_30(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_32);
		m_x_32 = (((x * a1) - (y * b1)) + m_x_31);
		m_x_31 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_33(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_35);
		m_x_35 = (((x * a1) - (y * b1)) + m_x_34);
		m_x_34 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline t_sample biquadTdf2_d_d_i_i_i_d_36(t_sample x, t_sample a0, int a1, int a2, int b1, t_sample b2) {
		t_sample y = ((x * a0) + m_x_38);
		m_x_38 = (((x * a1) - (y * b1)) + m_x_37);
		m_x_37 = ((x * a2) - (y * b2));
		return y;
		
	};
	inline void complexSine_d(t_sample hz, t_sample& out1, t_sample& out2, t_sample& out3) {
		t_sample p = __m_phasor_43(hz, samples_to_seconds);
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

int gen_kernel_numins = 2;
int gen_kernel_numouts = 3;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 1; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "input", "modulation (Hz)" };
const char *gen_kernel_outnames[] = { "upper sideband", "lower sideband", "sync" };

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
		case 0: self->set_mode(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_mode_1; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(1 * sizeof(ParamInfo));
	self->__commonstate.numparams = 1;
	// initialize parameter 0 ("m_mode_1")
	pi = self->__commonstate.params + 0;
	pi->name = "mode";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_mode_1;
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


} // DAISYTEST_LUKE_FREQSHIFTRINGMOD::
