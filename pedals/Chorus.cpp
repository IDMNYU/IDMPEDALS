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
	t_sample m_sw_20;
	t_sample m_knob4_rate_18;
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
		m_knob4_rate_18 = ((int)0);
		m_knob5_breadth_19 = 256;
		m_sw_20 = ((int)0);
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
		t_sample expr_38160 = (((int)1) - sqrt(sqrt((((int)1) - m_knob4_rate_18))));
		t_sample expr_38161 = (((int)1) - sqrt(sqrt((((int)1) - m_knob3_depth_15))));
		t_sample mul_38051 = (expr_38161 * ((int)1000));
		t_sample add_38050 = (mul_38051 + ((int)2));
		t_sample mul_38048 = (expr_38160 * ((int)10));
		t_sample add_38049 = (mul_38048 + ((t_sample)0.01));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_38154 = __m_sah_21(m_history_14, m_sw_17, ((int)0));
			t_sample gen_38156 = sah_38154;
			t_sample rsub_38152 = (((int)1) - sah_38154);
			t_sample history_38153_next_38155 = fixdenorm(rsub_38152);
			t_sample out3 = gen_38156;
			t_sample add_38157 = (gen_38156 + ((int)1));
			t_sample choice_22 = int(add_38157);
			t_sample gate_38149 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_38150 = ((choice_22 >= 2) ? in1 : 0);
			t_sample switch_38087 = (m_sw_20 ? ((int)0) : gate_38150);
			t_sample mix_38291 = (m_history_13 + (((t_sample)0.0019634941468452) * (m_knob6_taps_16 - m_history_13)));
			t_sample mix_38057 = mix_38291;
			t_sample mix_38292 = (m_history_12 + (((t_sample)0.0019634941468452) * (mix_38057 - m_history_12)));
			t_sample mix_38055 = mix_38292;
			t_sample mix_38293 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_38055 - m_history_11)));
			t_sample mix_38053 = mix_38293;
			t_sample gen_38085 = mix_38053;
			t_sample history_38059_next_38062 = fixdenorm(mix_38057);
			t_sample history_38056_next_38063 = fixdenorm(mix_38055);
			t_sample history_38054_next_38064 = fixdenorm(mix_38053);
			t_sample sub_38297 = (gen_38085 - ((int)0));
			t_sample scale_38294 = ((safepow((sub_38297 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.5)) + ((int)1));
			t_sample sub_38301 = (gen_38085 - ((int)0));
			t_sample scale_38298 = ((safepow((sub_38301 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-2));
			t_sample clamp_38071 = ((scale_38298 <= ((int)0)) ? ((int)0) : ((scale_38298 >= ((int)1)) ? ((int)1) : scale_38298));
			t_sample sub_38305 = (gen_38085 - ((int)0));
			t_sample scale_38302 = ((safepow((sub_38305 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-3));
			t_sample clamp_38069 = ((scale_38302 <= ((int)0)) ? ((int)0) : ((scale_38302 >= ((int)1)) ? ((int)1) : scale_38302));
			t_sample sub_38309 = (gen_38085 - ((int)0));
			t_sample scale_38306 = ((safepow((sub_38309 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-1));
			t_sample clamp_38073 = ((scale_38306 <= ((int)0)) ? ((int)0) : ((scale_38306 >= ((int)1)) ? ((int)1) : scale_38306));
			t_sample mix_38310 = (m_history_10 + (((t_sample)0.0019634941468452) * (m_knob5_breadth_19 - m_history_10)));
			t_sample mix_38173 = mix_38310;
			t_sample mix_38311 = (m_history_9 + (((t_sample)0.0019634941468452) * (mix_38173 - m_history_9)));
			t_sample mix_38171 = mix_38311;
			t_sample mix_38312 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_38171 - m_history_8)));
			t_sample mix_38166 = mix_38312;
			t_sample gen_38065 = mix_38166;
			t_sample history_38059_next_38164 = fixdenorm(mix_38173);
			t_sample history_38056_next_38169 = fixdenorm(mix_38171);
			t_sample history_38054_next_38168 = fixdenorm(mix_38166);
			t_sample mul_38052 = (gen_38065 * ((int)1));
			t_sample mul_38068 = (gen_38065 * ((int)2));
			t_sample mul_38067 = (gen_38065 * ((int)3));
			t_sample mul_38066 = (gen_38065 * ((int)4));
			t_sample mix_38313 = (m_history_7 + (((t_sample)0.0019634941468452) * (add_38050 - m_history_7)));
			t_sample mix_38186 = mix_38313;
			t_sample mix_38314 = (m_history_6 + (((t_sample)0.0019634941468452) * (mix_38186 - m_history_6)));
			t_sample mix_38185 = mix_38314;
			t_sample mix_38315 = (m_history_5 + (((t_sample)0.0019634941468452) * (mix_38185 - m_history_5)));
			t_sample mix_38184 = mix_38315;
			t_sample gen_38159 = mix_38184;
			t_sample history_38059_next_38178 = fixdenorm(mix_38186);
			t_sample history_38056_next_38182 = fixdenorm(mix_38185);
			t_sample history_38054_next_38179 = fixdenorm(mix_38184);
			t_sample mix_38316 = (m_history_4 + (((t_sample)0.0019634941468452) * (add_38049 - m_history_4)));
			t_sample mix_38197 = mix_38316;
			t_sample mix_38317 = (m_history_3 + (((t_sample)0.0019634941468452) * (mix_38197 - m_history_3)));
			t_sample mix_38193 = mix_38317;
			t_sample mix_38318 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_38193 - m_history_2)));
			t_sample mix_38194 = mix_38318;
			t_sample gen_38096 = mix_38194;
			t_sample history_38059_next_38198 = fixdenorm(mix_38197);
			t_sample history_38056_next_38202 = fixdenorm(mix_38193);
			t_sample history_38054_next_38196 = fixdenorm(mix_38194);
			t_sample mul_38100 = (gen_38096 * ((int)1));
			__m_cycle_23.freq(mul_38100);
			t_sample cycle_38138 = __m_cycle_23(__sinedata);
			t_sample cycleindex_38139 = __m_cycle_23.phase();
			t_sample mul_38136 = (cycle_38138 * gen_38159);
			t_sample add_38137 = (mul_38136 + mul_38052);
			t_sample mul_38131 = (gen_38096 * ((t_sample)1.51));
			__m_cycle_24.freq(mul_38131);
			t_sample cycle_38134 = __m_cycle_24(__sinedata);
			t_sample cycleindex_38135 = __m_cycle_24.phase();
			t_sample mul_38132 = (cycle_38134 * gen_38159);
			t_sample add_38133 = (mul_38132 + mul_38052);
			t_sample mul_38099 = (gen_38096 * ((t_sample)0.48));
			__m_cycle_25.freq(mul_38099);
			t_sample cycle_38128 = __m_cycle_25(__sinedata);
			t_sample cycleindex_38129 = __m_cycle_25.phase();
			t_sample mul_38126 = (cycle_38128 * gen_38159);
			t_sample add_38127 = (mul_38126 + mul_38068);
			t_sample mul_38121 = (gen_38096 * ((t_sample)0.73));
			__m_cycle_26.freq(mul_38121);
			t_sample cycle_38124 = __m_cycle_26(__sinedata);
			t_sample cycleindex_38125 = __m_cycle_26.phase();
			t_sample mul_38122 = (cycle_38124 * gen_38159);
			t_sample add_38123 = (mul_38122 + mul_38068);
			t_sample mul_38098 = (gen_38096 * ((t_sample)1.245));
			__m_cycle_27.freq(mul_38098);
			t_sample cycle_38117 = __m_cycle_27(__sinedata);
			t_sample cycleindex_38118 = __m_cycle_27.phase();
			t_sample mul_38115 = (cycle_38117 * gen_38159);
			t_sample add_38116 = (mul_38115 + mul_38067);
			t_sample mul_38110 = (gen_38096 * ((t_sample)0.81));
			__m_cycle_28.freq(mul_38110);
			t_sample cycle_38113 = __m_cycle_28(__sinedata);
			t_sample cycleindex_38114 = __m_cycle_28.phase();
			t_sample mul_38111 = (cycle_38113 * gen_38159);
			t_sample add_38112 = (mul_38111 + mul_38067);
			t_sample mul_38097 = (gen_38096 * ((t_sample)1.93));
			__m_cycle_29.freq(mul_38097);
			t_sample cycle_38108 = __m_cycle_29(__sinedata);
			t_sample cycleindex_38109 = __m_cycle_29.phase();
			t_sample mul_38106 = (cycle_38108 * gen_38159);
			t_sample add_38107 = (mul_38106 + mul_38066);
			t_sample mul_38101 = (gen_38096 * ((t_sample)2.11));
			__m_cycle_30.freq(mul_38101);
			t_sample cycle_38104 = __m_cycle_30(__sinedata);
			t_sample cycleindex_38105 = __m_cycle_30.phase();
			t_sample mul_38102 = (cycle_38104 * gen_38159);
			t_sample add_38103 = (mul_38102 + mul_38066);
			t_sample tap_38141 = m_delay_1.read_linear(add_38137);
			t_sample tap_38142 = m_delay_1.read_linear(add_38133);
			t_sample tap_38143 = m_delay_1.read_linear(add_38127);
			t_sample tap_38144 = m_delay_1.read_linear(add_38123);
			t_sample tap_38145 = m_delay_1.read_linear(add_38116);
			t_sample tap_38146 = m_delay_1.read_linear(add_38112);
			t_sample tap_38147 = m_delay_1.read_linear(add_38107);
			t_sample tap_38148 = m_delay_1.read_linear(add_38103);
			t_sample mul_38084 = (tap_38145 * clamp_38071);
			t_sample mul_38081 = (tap_38148 * clamp_38069);
			t_sample mul_38077 = (tap_38144 * clamp_38073);
			t_sample mul_38080 = (tap_38141 * ((int)1));
			t_sample mul_38120 = ((((mul_38080 + mul_38077) + mul_38081) + mul_38084) * scale_38294);
			t_sample add_38158 = (switch_38087 + mul_38120);
			t_sample out1 = (gate_38149 + add_38158);
			t_sample mul_38083 = (tap_38146 * clamp_38071);
			t_sample mul_38082 = (tap_38147 * clamp_38069);
			t_sample mul_38078 = (tap_38143 * clamp_38073);
			t_sample mul_38079 = (tap_38142 * ((int)1));
			t_sample mul_38119 = ((((mul_38079 + mul_38078) + mul_38082) + mul_38083) * scale_38294);
			t_sample add_38130 = (switch_38087 + mul_38119);
			t_sample out2 = (add_38130 + gate_38149);
			m_history_14 = history_38153_next_38155;
			m_history_13 = history_38059_next_38062;
			m_history_11 = history_38054_next_38064;
			m_history_12 = history_38056_next_38063;
			m_history_10 = history_38059_next_38164;
			m_history_8 = history_38054_next_38168;
			m_history_9 = history_38056_next_38169;
			m_history_7 = history_38059_next_38178;
			m_history_5 = history_38054_next_38179;
			m_history_6 = history_38056_next_38182;
			m_history_4 = history_38059_next_38198;
			m_history_2 = history_38054_next_38196;
			m_history_3 = history_38056_next_38202;
			m_delay_1.write(gate_38150);
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
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_breadth(t_param _value) {
		m_knob5_breadth_19 = (_value < 240 ? 240 : (_value > 2400 ? 2400 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 1: *value = self->m_knob4_rate_18; break;
		case 2: *value = self->m_knob5_breadth_19; break;
		case 3: *value = self->m_knob6_taps_16; break;
		case 4: *value = self->m_sw_17; break;
		case 5: *value = self->m_sw_20; break;
		
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
	// initialize parameter 5 ("m_sw_20")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_20;
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
