#include "SHComb.h"

namespace SHComb {

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
	Phasor __m_phasor_24;
	Phasor __m_phasor_25;
	Sah __m_sah_22;
	Sah __m_sah_26;
	int __exception;
	int vectorsize;
	t_sample m_history_4;
	t_sample m_knob4_max_18;
	t_sample m_sw_17;
	t_sample m_history_19;
	t_sample m_knob5_r_16;
	t_sample m_history_20;
	t_sample samplerate;
	t_sample m_history_21;
	t_sample samples_to_seconds;
	t_sample m_history_3;
	t_sample m_knob6_r_15;
	t_sample m_knob1_res_13;
	t_sample m_history_7;
	t_sample m_history_6;
	t_sample m_history_5;
	t_sample m_knob3_min_14;
	t_sample m_history_8;
	t_sample m_history_10;
	t_sample m_history_9;
	t_sample m_history_2;
	t_sample m_history_11;
	t_sample m_sw_12;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_delay_1.reset("m_delay_1", ((int)6000));
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
		m_sw_12 = ((int)0);
		m_knob1_res_13 = ((int)0);
		m_knob3_min_14 = ((int)0);
		m_knob6_r_15 = ((int)0);
		m_knob5_r_16 = ((int)0);
		m_sw_17 = ((int)0);
		m_knob4_max_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		__m_sah_22.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_24.reset(0);
		__m_phasor_25.reset(0);
		__m_sah_26.reset(0);
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
		t_sample sqrt_4039 = sqrt(m_knob1_res_13);
		t_sample sqrt_4048 = sqrt(sqrt_4039);
		t_sample mul_4052 = (sqrt_4048 * ((t_sample)0.99));
		samples_to_seconds = (1 / samplerate);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample mix_4145 = (m_history_21 + (((t_sample)0.003926980723806) * (m_knob6_r_15 - m_history_21)));
			t_sample mix_4022 = mix_4145;
			t_sample mix_4146 = (m_history_20 + (((t_sample)0.003926980723806) * (mix_4022 - m_history_20)));
			t_sample mix_4020 = mix_4146;
			t_sample mix_4147 = (m_history_19 + (((t_sample)0.003926980723806) * (mix_4020 - m_history_19)));
			t_sample mix_4018 = mix_4147;
			t_sample gen_4033 = mix_4018;
			t_sample history_4023_next_4025 = fixdenorm(mix_4022);
			t_sample history_4021_next_4026 = fixdenorm(mix_4020);
			t_sample history_4019_next_4027 = fixdenorm(mix_4018);
			t_sample expr_4056 = (((int)1) - sqrt((((int)1) - gen_4033)));
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_4042 = __m_sah_22(m_history_11, m_sw_17, ((int)0));
			t_sample gen_4044 = sah_4042;
			t_sample rsub_4040 = (((int)1) - sah_4042);
			t_sample history_4041_next_4043 = fixdenorm(rsub_4040);
			t_sample out3 = gen_4044;
			t_sample mix_4148 = (m_history_10 + (((t_sample)0.003926980723806) * (m_knob5_r_16 - m_history_10)));
			t_sample mix_4061 = mix_4148;
			t_sample mix_4149 = (m_history_9 + (((t_sample)0.003926980723806) * (mix_4061 - m_history_9)));
			t_sample mix_4065 = mix_4149;
			t_sample mix_4150 = (m_history_8 + (((t_sample)0.003926980723806) * (mix_4065 - m_history_8)));
			t_sample mix_4067 = mix_4150;
			t_sample gen_4034 = mix_4067;
			t_sample history_4023_next_4063 = fixdenorm(mix_4061);
			t_sample history_4021_next_4060 = fixdenorm(mix_4065);
			t_sample history_4019_next_4062 = fixdenorm(mix_4067);
			t_sample expr_4057 = (((int)1) - sqrt((((int)1) - gen_4034)));
			t_sample add_4047 = (gen_4044 + ((int)1));
			t_sample choice_23 = int(add_4047);
			t_sample gate_4045 = (((choice_23 >= 1) && (choice_23 < 2)) ? in1 : 0);
			t_sample gate_4046 = ((choice_23 >= 2) ? in1 : 0);
			t_sample mix_4151 = (m_history_7 + (((t_sample)0.003926980723806) * (m_knob3_min_14 - m_history_7)));
			t_sample mix_4076 = mix_4151;
			t_sample mix_4152 = (m_history_6 + (((t_sample)0.003926980723806) * (mix_4076 - m_history_6)));
			t_sample mix_4079 = mix_4152;
			t_sample mix_4153 = (m_history_5 + (((t_sample)0.003926980723806) * (mix_4079 - m_history_5)));
			t_sample mix_4073 = mix_4153;
			t_sample gen_4035 = mix_4073;
			t_sample history_4023_next_4072 = fixdenorm(mix_4076);
			t_sample history_4021_next_4075 = fixdenorm(mix_4079);
			t_sample history_4019_next_4077 = fixdenorm(mix_4073);
			t_sample sub_4157 = (gen_4035 - ((int)0));
			t_sample scale_4154 = ((safepow((sub_4157 * ((t_sample)1)), ((int)1)) * ((int)84)) + ((int)24));
			t_sample mix_4158 = (m_history_4 + (((t_sample)0.003926980723806) * (m_knob4_max_18 - m_history_4)));
			t_sample mix_4089 = mix_4158;
			t_sample mix_4159 = (m_history_3 + (((t_sample)0.003926980723806) * (mix_4089 - m_history_3)));
			t_sample mix_4092 = mix_4159;
			t_sample mix_4160 = (m_history_2 + (((t_sample)0.003926980723806) * (mix_4092 - m_history_2)));
			t_sample mix_4086 = mix_4160;
			t_sample gen_4028 = mix_4086;
			t_sample history_4023_next_4085 = fixdenorm(mix_4089);
			t_sample history_4021_next_4088 = fixdenorm(mix_4092);
			t_sample history_4019_next_4090 = fixdenorm(mix_4086);
			t_sample sub_4164 = (gen_4028 - ((int)0));
			t_sample scale_4161 = ((safepow((sub_4164 * ((t_sample)1)), ((int)1)) * ((int)84)) + ((int)24));
			t_sample mul_4050 = (expr_4057 * ((int)10));
			t_sample phasor_4051 = __m_phasor_24(mul_4050, samples_to_seconds);
			t_sample mul_4012 = (expr_4056 * ((int)10));
			t_sample phasor_4013 = __m_phasor_25(mul_4012, samples_to_seconds);
			t_sample sah_4014 = __m_sah_26(phasor_4051, phasor_4013, ((t_sample)0.5));
			t_sample orange_4167 = (scale_4161 - scale_4154);
			t_sample sub_4168 = (sah_4014 - ((int)0));
			t_sample scale_4165 = ((safepow((sub_4168 * ((t_sample)1)), ((int)1)) * orange_4167) + scale_4154);
			t_sample round_4032 = round(scale_4165);
			t_sample switch_4010 = (m_sw_12 ? round_4032 : scale_4165);
			t_sample mtof_4031 = mtof(switch_4010, ((int)440));
			t_sample rdiv_4030 = safediv(((int)1000), mtof_4031);
			t_sample mstosamps_4029 = (rdiv_4030 * (samplerate * 0.001));
			t_sample tap_4055 = m_delay_1.read_linear(mstosamps_4029);
			t_sample add_4038 = (gate_4046 + tap_4055);
			t_sample div_4037 = (add_4038 * ((t_sample)0.5));
			t_sample out2 = (div_4037 + gate_4045);
			t_sample out1 = (div_4037 + gate_4045);
			t_sample mul_4053 = (tap_4055 * mul_4052);
			m_history_21 = history_4023_next_4025;
			m_history_19 = history_4019_next_4027;
			m_history_20 = history_4021_next_4026;
			m_history_11 = history_4041_next_4043;
			m_history_10 = history_4023_next_4063;
			m_history_8 = history_4019_next_4062;
			m_history_9 = history_4021_next_4060;
			m_history_7 = history_4023_next_4072;
			m_history_5 = history_4019_next_4077;
			m_history_6 = history_4021_next_4075;
			m_history_4 = history_4023_next_4085;
			m_history_2 = history_4019_next_4090;
			m_history_3 = history_4021_next_4088;
			m_delay_1.write((mul_4053 + gate_4046));
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
	inline void set_sw5(t_param _value) {
		m_sw_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_res(t_param _value) {
		m_knob1_res_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_min(t_param _value) {
		m_knob3_min_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_r2(t_param _value) {
		m_knob6_r_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_r1(t_param _value) {
		m_knob5_r_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_max(t_param _value) {
		m_knob4_max_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 7; }

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
		case 0: self->set_knob1_res(value); break;
		case 1: self->set_knob3_min(value); break;
		case 2: self->set_knob4_max(value); break;
		case 3: self->set_knob5_r1(value); break;
		case 4: self->set_knob6_r2(value); break;
		case 5: self->set_sw1(value); break;
		case 6: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_res_13; break;
		case 1: *value = self->m_knob3_min_14; break;
		case 2: *value = self->m_knob4_max_18; break;
		case 3: *value = self->m_knob5_r_16; break;
		case 4: *value = self->m_knob6_r_15; break;
		case 5: *value = self->m_sw_17; break;
		case 6: *value = self->m_sw_12; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(7 * sizeof(ParamInfo));
	self->__commonstate.numparams = 7;
	// initialize parameter 0 ("m_knob1_res_13")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_res";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_res_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_min_14")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_min";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_min_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_max_18")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_max";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_max_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_r_16")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_r1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_r_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_r_15")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_r2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_r_15;
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
	// initialize parameter 6 ("m_sw_12")
	pi = self->__commonstate.params + 6;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_12;
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


} // SHComb::
