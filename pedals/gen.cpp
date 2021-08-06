#include "gen.h"

namespace gen {

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
	int __exception;
	int vectorsize;
	t_sample m_slim_7;
	t_sample m_s_8;
	t_sample m_s_9;
	t_sample m_s_10;
	t_sample m_s_6;
	t_sample m_s_11;
	t_sample m_s_5;
	t_sample m_s_3;
	t_sample samplerate;
	t_sample m_s_4;
	t_sample m_rc_1;
	t_sample m_previn_2;
	t_sample m_fc_12;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_rc_1 = ((int)0);
		m_previn_2 = ((int)0);
		m_s_3 = ((int)0);
		m_s_4 = ((int)0);
		m_s_5 = ((int)0);
		m_s_6 = ((int)0);
		m_slim_7 = ((int)0);
		m_s_8 = ((int)0);
		m_s_9 = ((int)0);
		m_s_10 = ((int)0);
		m_s_11 = ((int)0);
		m_fc_12 = ((int)1);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		const t_sample * __in3 = __ins[2];
		t_sample * __out1 = __outs[0];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__in3 == 0) || (__out1 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample maxb_13 = safediv(((t_sample)12.5), samplerate);
		t_sample minb_14 = ((((t_sample)0.0001) < maxb_13) ? maxb_13 : ((t_sample)0.0001));
		t_sample expr_1079 = sqrt(((minb_14 < ((int)1)) ? minb_14 : ((int)1)));
		t_sample expr_1078 = (((int)-1) * log(expr_1079));
		int min_18 = (-1);
		int min_21 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			const t_sample in3 = (*(__in3++));
			t_sample expr_1104 = (m_fc_12 * m_fc_12);
			t_sample expr_1103 = (expr_1104 * (((int)1) - m_rc_1));
			t_sample expr_1102 = (expr_1104 + (expr_1103 * expr_1103));
			t_sample expr_1101 = ((((t_sample)1.25) + ((((t_sample)-0.74375) + (((t_sample)0.3) * expr_1102)) * expr_1102)) * expr_1102);
			t_sample expr_1100 = (m_rc_1 * (((t_sample)1.4) + ((((t_sample)0.108) + ((((t_sample)-0.164) - (((t_sample)0.069) * expr_1101)) * expr_1101)) * expr_1101)));
			t_sample expr_1099 = (((t_sample)0.18) + (((t_sample)0.25) * (expr_1100 * expr_1100)));
			t_sample rsub_480 = (((int)1) - expr_1101);
			t_sample minb_15 = ((((t_sample)1e-05) < in3) ? in3 : ((t_sample)1e-05));
			t_sample expr_1105 = (((((t_sample)1.05) * ((minb_15 < ((int)1)) ? minb_15 : ((int)1))) - m_rc_1) * ((t_sample)0.25));
			t_sample add_479 = (m_rc_1 + expr_1105);
			t_sample fixdenorm_440 = fixdenorm(m_previn_2);
			t_sample expr_1098 = ((fixdenorm_440 * expr_1099) - (expr_1100 * m_s_11));
			t_sample maxb_16 = (((((t_sample)0.062) * expr_1098) * expr_1098) + (((t_sample)0.993) * m_slim_7));
			t_sample minb_17 = ((((int)-1) < maxb_16) ? maxb_16 : ((int)-1));
			t_sample expr_1097 = ((minb_17 < ((int)1)) ? minb_17 : ((int)1));
			t_sample expr_1096 = (expr_1098 * ((((int)1) - expr_1097) + ((((t_sample)0.5) * expr_1097) * expr_1097)));
			t_sample expr_1095 = ((expr_1096 * expr_1101) + (rsub_480 * m_s_4));
			t_sample noise_531 = noise();
			t_sample expr_1090 = (in1 + (((t_sample)1e-11) * noise_531));
			t_sample mul_473 = (m_s_4 * ((t_sample)0.3));
			t_sample add_471 = (expr_1095 + mul_473);
			t_sample expr_1094 = ((add_471 * expr_1101) + (rsub_480 * m_s_5));
			t_sample mul_462 = (m_s_8 * ((t_sample)0.3));
			t_sample mul_465 = (m_s_6 * ((t_sample)0.3));
			t_sample mul_455 = (expr_1095 * ((t_sample)0.3));
			t_sample mul_452 = (expr_1094 * ((t_sample)0.3));
			t_sample mul_470 = (m_s_5 * ((t_sample)0.3));
			t_sample add_468 = (expr_1094 + mul_470);
			t_sample clamp_467 = ((add_468 <= min_18) ? min_18 : ((add_468 >= ((int)1)) ? ((int)1) : add_468));
			t_sample expr_1093 = (clamp_467 * (((int)1) - ((((t_sample)0.3333333) * clamp_467) * clamp_467)));
			t_sample expr_1092 = ((expr_1093 * expr_1101) + (rsub_480 * m_s_6));
			t_sample add_463 = (expr_1092 + mul_465);
			t_sample expr_1091 = ((add_463 * expr_1101) + (rsub_480 * m_s_8));
			t_sample add_460 = (expr_1091 + mul_462);
			t_sample expr_1089 = ((expr_1090 * expr_1099) - (expr_1100 * add_460));
			t_sample maxb_19 = (((((t_sample)0.062) * expr_1089) * expr_1089) + (((t_sample)0.993) * expr_1097));
			t_sample minb_20 = ((((int)-1) < maxb_19) ? maxb_19 : ((int)-1));
			t_sample expr_1088 = ((minb_20 < ((int)1)) ? minb_20 : ((int)1));
			t_sample expr_1087 = (expr_1089 * ((((int)1) - expr_1088) + ((((t_sample)0.5) * expr_1088) * expr_1088)));
			t_sample expr_1086 = ((expr_1087 * expr_1101) + (rsub_480 * expr_1095));
			t_sample add_453 = (expr_1086 + mul_455);
			t_sample expr_1085 = ((add_453 * expr_1101) + (rsub_480 * expr_1094));
			t_sample add_450 = (expr_1085 + mul_452);
			t_sample clamp_449 = ((add_450 <= min_21) ? min_21 : ((add_450 >= ((int)1)) ? ((int)1) : add_450));
			t_sample expr_1084 = (clamp_449 * (((int)1) - ((((t_sample)0.3333333) * clamp_449) * clamp_449)));
			t_sample expr_1083 = ((expr_1084 * expr_1101) + (rsub_480 * expr_1092));
			t_sample mul_444 = (expr_1091 * ((t_sample)0.3));
			t_sample mul_447 = (expr_1092 * ((t_sample)0.3));
			t_sample add_445 = (expr_1083 + mul_447);
			t_sample expr_1082 = ((add_445 * expr_1101) + (rsub_480 * expr_1091));
			t_sample add_442 = (expr_1082 + mul_444);
			t_sample expr_1081 = (((((t_sample)0.19) * (add_442 + m_s_3)) + (((t_sample)0.57) * (add_460 + m_s_9))) - (((t_sample)0.52) * m_s_10));
			t_sample out1 = expr_1081;
			t_sample mul_423 = (in2 * ((t_sample)0.90193));
			t_sample add_420 = (mul_423 + ((t_sample)7.29));
			t_sample div_419 = (add_420 * ((t_sample)0.0078740157480315));
			t_sample clamp_425 = ((div_419 <= ((int)0)) ? ((int)0) : ((div_419 >= ((t_sample)0.99)) ? ((t_sample)0.99) : div_419));
			t_sample mul_424 = (clamp_425 * expr_1078);
			t_sample expr_1080 = (((t_sample)0.99999636) + ((((t_sample)0.031261316) + ((((t_sample)0.00048274797) + (((t_sample)5.949053e-06) * mul_424)) * mul_424)) * mul_424));
			t_sample mul_432 = (expr_1080 * expr_1080);
			t_sample mul_431 = (mul_432 * mul_432);
			t_sample mul_430 = (mul_431 * mul_431);
			t_sample mul_429 = (mul_430 * mul_430);
			t_sample mul_428 = (mul_429 * mul_429);
			t_sample mul_422 = (mul_428 * expr_1079);
			t_sample sub_421 = (mul_422 - m_fc_12);
			t_sample div_418 = (sub_421 * ((t_sample)0.5));
			t_sample add_483 = (m_fc_12 + div_418);
			t_sample rc_next_1106 = fixdenorm(add_479);
			t_sample previn_next_1107 = fixdenorm(expr_1090);
			t_sample s8_next_1108 = fixdenorm(add_460);
			t_sample s1_next_1109 = fixdenorm(expr_1086);
			t_sample s2_next_1110 = fixdenorm(expr_1085);
			t_sample s3_next_1111 = fixdenorm(expr_1083);
			t_sample slim_next_1112 = fixdenorm(expr_1088);
			t_sample s4_next_1113 = fixdenorm(expr_1082);
			t_sample s7_next_1114 = fixdenorm(add_442);
			t_sample s6_next_1115 = fixdenorm(expr_1081);
			t_sample s5_next_1116 = fixdenorm(add_442);
			t_sample fc_next_1117 = fixdenorm(add_483);
			m_rc_1 = rc_next_1106;
			m_fc_12 = fc_next_1117;
			m_s_11 = s5_next_1116;
			m_s_10 = s6_next_1115;
			m_s_9 = s7_next_1114;
			m_s_8 = s4_next_1113;
			m_slim_7 = slim_next_1112;
			m_s_6 = s3_next_1111;
			m_s_5 = s2_next_1110;
			m_s_4 = s1_next_1109;
			m_s_3 = s8_next_1108;
			m_previn_2 = previn_next_1107;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			
		};
		return __exception;
		
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 3;
int gen_kernel_numouts = 1;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 0; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2", "in3" };
const char *gen_kernel_outnames[] = { "out1" };

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
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
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
	self->__commonstate.params = 0;
	self->__commonstate.numparams = 0;
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	
	delete self;
}


} // gen::
