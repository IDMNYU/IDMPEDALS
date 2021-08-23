#include "DigitalDelay.h"

namespace DigitalDelay {

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
	Delay m_delay_5;
	Delay m_delay_6;
	Sah __m_sah_21;
	int __exception;
	int vectorsize;
	t_sample m_knob4_fb_16;
	t_sample m_sw_15;
	t_sample m_knob5_time_14;
	t_sample m_history_13;
	t_sample m_history_2;
	t_sample m_sw_18;
	t_sample m_knob3_level_17;
	t_sample m_sw_19;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_history_10;
	t_sample m_history_4;
	t_sample m_history_3;
	t_sample m_y_1;
	t_sample samplerate;
	t_sample m_history_8;
	t_sample m_history_7;
	t_sample m_knob6_lowpass_20;
	t_sample m_history_9;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_y_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_delay_5.reset("m_delay_5", ((int)96000));
		m_delay_6.reset("m_delay_6", ((int)96000));
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_knob5_time_14 = ((int)0);
		m_sw_15 = ((int)0);
		m_knob4_fb_16 = ((int)0);
		m_knob3_level_17 = ((int)0);
		m_sw_18 = ((int)0);
		m_sw_19 = ((int)0);
		m_knob6_lowpass_20 = ((int)0);
		__m_sah_21.reset(0);
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
		t_sample add_1121 = (m_sw_15 + ((int)1));
		t_sample choice_23 = int(add_1121);
		t_sample choice_24 = int(add_1121);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample sah_1126 = __m_sah_21(m_history_13, m_sw_18, ((int)0));
			t_sample gen_1128 = sah_1126;
			t_sample rsub_1124 = (((int)1) - sah_1126);
			t_sample history_1125_next_1127 = fixdenorm(rsub_1124);
			t_sample out3 = gen_1128;
			t_sample add_1129 = (gen_1128 + ((int)1));
			t_sample choice_22 = int(add_1129);
			t_sample gate_1122 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_1123 = ((choice_22 >= 2) ? in1 : 0);
			t_sample pass_1142 = gate_1123;
			t_sample mix_1213 = (m_history_12 + (((t_sample)0.0019634941468452) * (m_knob4_fb_16 - m_history_12)));
			t_sample mix_1105 = mix_1213;
			t_sample mix_1214 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_1105 - m_history_11)));
			t_sample mix_1103 = mix_1214;
			t_sample mix_1215 = (m_history_10 + (((t_sample)0.0019634941468452) * (mix_1103 - m_history_10)));
			t_sample mix_1101 = mix_1215;
			t_sample gen_1138 = mix_1101;
			t_sample history_1106_next_1108 = fixdenorm(mix_1105);
			t_sample history_1104_next_1109 = fixdenorm(mix_1103);
			t_sample history_1102_next_1110 = fixdenorm(mix_1101);
			t_sample mix_1216 = (m_history_9 + (((t_sample)0.0019634941468452) * (m_knob5_time_14 - m_history_9)));
			t_sample mix_1151 = mix_1216;
			t_sample mix_1217 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_1151 - m_history_8)));
			t_sample mix_1145 = mix_1217;
			t_sample mix_1218 = (m_history_7 + (((t_sample)0.0019634941468452) * (mix_1145 - m_history_7)));
			t_sample mix_1150 = mix_1218;
			t_sample gen_1130 = mix_1150;
			t_sample history_1106_next_1144 = fixdenorm(mix_1151);
			t_sample history_1104_next_1148 = fixdenorm(mix_1145);
			t_sample history_1102_next_1149 = fixdenorm(mix_1150);
			t_sample sub_1222 = (gen_1130 - ((int)0));
			t_sample scale_1219 = ((safepow((sub_1222 * ((t_sample)1)), ((int)1)) * ((int)72000)) + ((int)24000));
			t_sample scale_1098 = scale_1219;
			t_sample sub_1226 = (gen_1130 - ((int)0));
			t_sample scale_1223 = ((safepow((sub_1226 * ((t_sample)1)), ((int)1)) * ((int)24000)) + ((int)0));
			t_sample scale_1099 = scale_1223;
			t_sample switch_1100 = (m_sw_19 ? scale_1098 : scale_1099);
			t_sample tap_1141 = m_delay_6.read_cubic(switch_1100);
			t_sample mul_1139 = (tap_1141 * gen_1138);
			t_sample mul_1137 = (tap_1141 * m_knob3_level_17);
			t_sample gate_1119 = (((choice_23 >= 1) && (choice_23 < 2)) ? mul_1137 : 0);
			t_sample gate_1120 = ((choice_23 >= 2) ? mul_1137 : 0);
			t_sample tap_1135 = m_delay_5.read_cubic(switch_1100);
			t_sample mul_1133 = (tap_1135 * gen_1138);
			t_sample mul_1132 = (tap_1135 * m_knob3_level_17);
			t_sample gate_1117 = (((choice_24 >= 1) && (choice_24 < 2)) ? mul_1132 : 0);
			t_sample gate_1118 = ((choice_24 >= 2) ? mul_1132 : 0);
			t_sample add_1136 = ((gate_1122 + pass_1142) + ((gate_1117 + gate_1119) + gate_1120));
			t_sample out1 = add_1136;
			t_sample add_1131 = ((gate_1122 + pass_1142) + ((gate_1117 + gate_1118) + gate_1119));
			t_sample out2 = add_1131;
			t_sample mix_1227 = (m_history_4 + (((t_sample)0.0019634941468452) * (m_knob6_lowpass_20 - m_history_4)));
			t_sample mix_1165 = mix_1227;
			t_sample mix_1228 = (m_history_3 + (((t_sample)0.0019634941468452) * (mix_1165 - m_history_3)));
			t_sample mix_1156 = mix_1228;
			t_sample mix_1229 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_1156 - m_history_2)));
			t_sample mix_1158 = mix_1229;
			t_sample gen_1111 = mix_1158;
			t_sample history_1106_next_1161 = fixdenorm(mix_1165);
			t_sample history_1104_next_1164 = fixdenorm(mix_1156);
			t_sample history_1102_next_1159 = fixdenorm(mix_1158);
			t_sample mtof_1112 = mtof(gen_1111, ((int)440));
			t_sample mul_1114 = (mtof_1112 * safediv((2 * 3.1415926535898), samplerate));
			t_sample sin_1115 = sin(mul_1114);
			t_sample clamp_1116 = ((sin_1115 <= ((int)0)) ? ((int)0) : ((sin_1115 >= ((int)1)) ? ((int)1) : sin_1115));
			t_sample mix_1230 = (m_y_1 + (clamp_1116 * (mul_1139 - m_y_1)));
			t_sample mix_1097 = mix_1230;
			t_sample add_1232 = (mul_1133 + pass_1142);
			t_sample mix_1231 = (m_y_1 + (clamp_1116 * (add_1232 - m_y_1)));
			t_sample mix_1113 = mix_1231;
			t_sample y0_next_1169 = fixdenorm(mix_1097);
			t_sample y0_next_1170 = fixdenorm(mix_1113);
			m_history_13 = history_1125_next_1127;
			m_history_12 = history_1106_next_1108;
			m_history_10 = history_1102_next_1110;
			m_history_11 = history_1104_next_1109;
			m_history_9 = history_1106_next_1144;
			m_history_7 = history_1102_next_1149;
			m_history_8 = history_1104_next_1148;
			m_delay_6.write(mix_1113);
			m_delay_5.write(mix_1097);
			m_history_4 = history_1106_next_1161;
			m_history_2 = history_1102_next_1159;
			m_history_3 = history_1104_next_1164;
			m_y_1 = y0_next_1169;
			m_y_1 = y0_next_1170;
			m_delay_5.step();
			m_delay_6.step();
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
	inline void set_knob5_time(t_param _value) {
		m_knob5_time_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_fb(t_param _value) {
		m_knob4_fb_16 = (_value < 0 ? 0 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_knob3_level(t_param _value) {
		m_knob3_level_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_lowpass(t_param _value) {
		m_knob6_lowpass_20 = (_value < 54 ? 54 : (_value > 138 ? 138 : _value));
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
		case 0: self->set_knob3_level(value); break;
		case 1: self->set_knob4_fb(value); break;
		case 2: self->set_knob5_time(value); break;
		case 3: self->set_knob6_lowpass(value); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw5(value); break;
		case 6: self->set_sw6(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_level_17; break;
		case 1: *value = self->m_knob4_fb_16; break;
		case 2: *value = self->m_knob5_time_14; break;
		case 3: *value = self->m_knob6_lowpass_20; break;
		case 4: *value = self->m_sw_18; break;
		case 5: *value = self->m_sw_19; break;
		case 6: *value = self->m_sw_15; break;
		
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
	// initialize parameter 0 ("m_knob3_level_17")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_level";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_level_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_fb_16")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_time_14")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_time";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_time_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_lowpass_20")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_lowpass";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_lowpass_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 54;
	pi->outputmax = 138;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_18")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
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
	// initialize parameter 5 ("m_sw_19")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_sw_15")
	pi = self->__commonstate.params + 6;
	pi->name = "sw6";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // DigitalDelay::
