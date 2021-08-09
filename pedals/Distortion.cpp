#include "Distortion.h"

namespace Distortion {

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
	Sah __m_sah_9;
	int vectorsize;
	int __exception;
	t_sample m_d_1;
	t_sample m_knob4_squish_6;
	t_sample m_knob6_output_7;
	t_sample samplerate;
	t_sample m_sw_5;
	t_sample m_knob5_tone_8;
	t_sample m_knob3_drive_4;
	t_sample m_d_2;
	t_sample m_history_3;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_d_1 = ((int)0);
		m_d_2 = ((int)0);
		m_history_3 = ((int)0);
		m_knob3_drive_4 = ((int)0);
		m_sw_5 = ((int)0);
		m_knob4_squish_6 = ((int)0);
		m_knob6_output_7 = ((int)0);
		m_knob5_tone_8 = ((int)0);
		__m_sah_9.reset(0);
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
		t_sample mtof_2934 = mtof(m_knob5_tone_8, ((int)440));
		t_sample dbtoa_2962 = dbtoa(m_knob6_output_7);
		t_sample freq = mtof_2934;
		t_sample f1 = sin(safediv((((t_sample)6.2831853071796) * freq), samplerate));
		t_sample sub_2996 = (m_knob3_drive_4 - ((int)0));
		t_sample scale_2993 = ((safepow((sub_2996 * ((t_sample)1)), ((int)1)) * ((int)6)) + ((int)1));
		t_sample sub_3000 = (m_knob3_drive_4 - ((int)0));
		t_sample scale_2997 = ((safepow((sub_3000 * ((t_sample)1)), ((int)1)) * ((int)-76)) + ((int)6));
		t_sample rdiv_2943 = safediv(((int)1), m_knob4_squish_6);
		t_sample rsub_2942 = (((int)1) - rdiv_2943);
		t_sample rdiv_2927 = safediv(((int)1), m_knob4_squish_6);
		t_sample rsub_2926 = (((int)1) - rdiv_2927);
		t_sample rdiv_2912 = safediv(((int)1), m_knob4_squish_6);
		t_sample rsub_2911 = (((int)1) - rdiv_2912);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_2956 = __m_sah_9(m_history_3, m_sw_5, ((int)0));
			t_sample gen_2958 = sah_2956;
			t_sample rsub_2954 = (((int)1) - sah_2956);
			t_sample history_2955_next_2957 = fixdenorm(rsub_2954);
			t_sample out3 = gen_2958;
			t_sample add_2961 = (gen_2958 + ((int)1));
			t_sample choice_10 = int(add_2961);
			t_sample gate_2959 = (((choice_10 >= 1) && (choice_10 < 2)) ? in1 : 0);
			t_sample gate_2960 = ((choice_10 >= 2) ? in1 : 0);
			t_sample L = (m_d_1 + (f1 * m_d_2));
			t_sample H = ((gate_2960 - L) - (((t_sample)0.2) * m_d_2));
			t_sample B = ((f1 * H) + m_d_2);
			m_d_2 = B;
			m_d_1 = L;
			t_sample abs_2947 = fabs(L);
			t_sample atodb_2946 = atodb(abs_2947);
			int gt_2944 = (atodb_2946 > scale_2997);
			t_sample sub_2945 = (scale_2997 - atodb_2946);
			t_sample mul_2941 = (sub_2945 * rsub_2942);
			t_sample dbtoa_2940 = dbtoa(mul_2941);
			t_sample rsub_2939 = (((int)1) - dbtoa_2940);
			t_sample mul_2938 = (rsub_2939 * (-1));
			t_sample mul_2937 = (gt_2944 * mul_2938);
			t_sample add_2936 = (mul_2937 + ((int)1));
			t_sample clamp_2935 = ((add_2936 <= ((int)0)) ? ((int)0) : ((add_2936 >= ((int)1)) ? ((int)1) : add_2936));
			t_sample mul_2948 = (L * clamp_2935);
			t_sample abs_2931 = fabs(H);
			t_sample atodb_2930 = atodb(abs_2931);
			int gt_2928 = (atodb_2930 > scale_2997);
			t_sample sub_2929 = (scale_2997 - atodb_2930);
			t_sample mul_2925 = (sub_2929 * rsub_2926);
			t_sample dbtoa_2924 = dbtoa(mul_2925);
			t_sample rsub_2923 = (((int)1) - dbtoa_2924);
			t_sample mul_2922 = (rsub_2923 * (-1));
			t_sample mul_2921 = (gt_2928 * mul_2922);
			t_sample add_2920 = (mul_2921 + ((int)1));
			t_sample clamp_2919 = ((add_2920 <= ((int)0)) ? ((int)0) : ((add_2920 >= ((int)1)) ? ((int)1) : add_2920));
			t_sample mul_2932 = (H * clamp_2919);
			t_sample abs_2916 = fabs(B);
			t_sample atodb_2915 = atodb(abs_2916);
			int gt_2913 = (atodb_2915 > scale_2997);
			t_sample sub_2914 = (scale_2997 - atodb_2915);
			t_sample mul_2910 = (sub_2914 * rsub_2911);
			t_sample dbtoa_2909 = dbtoa(mul_2910);
			t_sample rsub_2908 = (((int)1) - dbtoa_2909);
			t_sample mul_2907 = (rsub_2908 * (-1));
			t_sample mul_2906 = (gt_2913 * mul_2907);
			t_sample add_2905 = (mul_2906 + ((int)1));
			t_sample clamp_2904 = ((add_2905 <= ((int)0)) ? ((int)0) : ((add_2905 >= ((int)1)) ? ((int)1) : add_2905));
			t_sample mul_2917 = (B * clamp_2904);
			t_sample mul_2902 = (((mul_2917 + mul_2932) + mul_2948) * scale_2993);
			t_sample mul_2963 = (mul_2902 * dbtoa_2962);
			t_sample out2 = (gate_2959 + mul_2963);
			t_sample out1 = (gate_2959 + mul_2963);
			m_history_3 = history_2955_next_2957;
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
	inline void set_knob3_drive(t_param _value) {
		m_knob3_drive_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_squish(t_param _value) {
		m_knob4_squish_6 = (_value < 1 ? 1 : (_value > 5 ? 5 : _value));
	};
	inline void set_knob6_output(t_param _value) {
		m_knob6_output_7 = (_value < -70 ? -70 : (_value > 15 ? 15 : _value));
	};
	inline void set_knob5_tone(t_param _value) {
		m_knob5_tone_8 = (_value < 20 ? 20 : (_value > 80 ? 80 : _value));
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
		case 0: self->set_knob3_drive(value); break;
		case 1: self->set_knob4_squish(value); break;
		case 2: self->set_knob5_tone(value); break;
		case 3: self->set_knob6_output(value); break;
		case 4: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_drive_4; break;
		case 1: *value = self->m_knob4_squish_6; break;
		case 2: *value = self->m_knob5_tone_8; break;
		case 3: *value = self->m_knob6_output_7; break;
		case 4: *value = self->m_sw_5; break;
		
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
	// initialize parameter 0 ("m_knob3_drive_4")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_drive";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_drive_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_squish_6")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_squish";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_squish_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_tone_8")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_tone";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_tone_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 80;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_output_7")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_output";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_output_7;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -70;
	pi->outputmax = 15;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_5")
	pi = self->__commonstate.params + 4;
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // Distortion::
