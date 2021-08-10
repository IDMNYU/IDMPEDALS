#include "Reverb2.h"

namespace Reverb2 {

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
	Delay m_delay_14;
	Delay m_delay_18;
	Delay m_delay_8;
	Delay m_delay_20;
	Delay m_delay_10;
	Delay m_delay_12;
	Delay m_delay_16;
	Delay m_delay_31;
	Delay m_delay_22;
	Delay m_delay_25;
	Delay m_delay_29;
	Delay m_delay_30;
	Delay m_delay_24;
	Delay m_delay_28;
	Delay m_delay_26;
	Delay m_delay_27;
	Sah __m_sah_32;
	int __exception;
	int vectorsize;
	t_sample m_sw_3;
	t_sample m_history_11;
	t_sample m_knob4_fb_2;
	t_sample m_knob6_spread_1;
	t_sample samplerate;
	t_sample m_knob1_wetdry_4;
	t_sample m_history_13;
	t_sample m_knob3_damp_5;
	t_sample m_knob5_fb_6;
	t_sample m_history_9;
	t_sample m_history_17;
	t_sample m_history_23;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample m_history_7;
	t_sample m_history_15;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_knob6_spread_1 = ((int)0);
		m_knob4_fb_2 = ((t_sample)0.9);
		m_sw_3 = ((int)0);
		m_knob1_wetdry_4 = ((int)0);
		m_knob3_damp_5 = ((t_sample)0.5);
		m_knob5_fb_6 = ((t_sample)0.5);
		m_history_7 = ((int)0);
		m_delay_8.reset("m_delay_8", ((int)4000));
		m_history_9 = ((int)0);
		m_delay_10.reset("m_delay_10", ((int)4000));
		m_history_11 = ((int)0);
		m_delay_12.reset("m_delay_12", ((int)4000));
		m_history_13 = ((int)0);
		m_delay_14.reset("m_delay_14", ((int)4000));
		m_history_15 = ((int)0);
		m_delay_16.reset("m_delay_16", ((int)4000));
		m_history_17 = ((int)0);
		m_delay_18.reset("m_delay_18", ((int)4000));
		m_history_19 = ((int)0);
		m_delay_20.reset("m_delay_20", ((int)4000));
		m_history_21 = ((int)0);
		m_delay_22.reset("m_delay_22", ((int)4000));
		m_history_23 = ((int)0);
		m_delay_24.reset("m_delay_24", ((int)4000));
		m_delay_25.reset("m_delay_25", ((int)4000));
		m_delay_26.reset("m_delay_26", ((int)4000));
		m_delay_27.reset("m_delay_27", ((int)4000));
		m_delay_28.reset("m_delay_28", ((int)4000));
		m_delay_29.reset("m_delay_29", ((int)4000));
		m_delay_30.reset("m_delay_30", ((int)4000));
		m_delay_31.reset("m_delay_31", ((int)4000));
		__m_sah_32.reset(0);
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
		t_sample sqrt_43076 = sqrt(m_knob1_wetdry_4);
		t_sample rsub_43080 = (((int)1) - m_knob1_wetdry_4);
		t_sample sqrt_43079 = sqrt(rsub_43080);
		t_sample mul_43130 = (m_knob5_fb_6 * ((t_sample)0.5));
		t_sample mul_43075 = (m_knob5_fb_6 * ((t_sample)0.5));
		t_sample add_43116 = (((int)450) + m_knob6_spread_1);
		t_sample add_43070 = (((int)456) + m_knob6_spread_1);
		t_sample add_43118 = (((int)682) + m_knob6_spread_1);
		t_sample add_43072 = (((int)676) + m_knob6_spread_1);
		t_sample add_43128 = (((int)882) + m_knob6_spread_1);
		t_sample add_43074 = (((int)888) + m_knob6_spread_1);
		t_sample add_43114 = (((int)1112) + m_knob6_spread_1);
		t_sample add_43068 = (((int)1106) + m_knob6_spread_1);
		t_sample add_43121 = (((int)3114) + m_knob6_spread_1);
		t_sample rsub_43083 = (((int)1) - m_knob3_damp_5);
		t_sample add_43120 = (((int)3234) + m_knob6_spread_1);
		t_sample rsub_43145 = (((int)1) - m_knob3_damp_5);
		t_sample add_43122 = (((int)2982) + m_knob6_spread_1);
		t_sample rsub_43157 = (((int)1) - m_knob3_damp_5);
		t_sample add_43123 = (((int)2844) + m_knob6_spread_1);
		t_sample rsub_43168 = (((int)1) - m_knob3_damp_5);
		t_sample add_43124 = (((int)2712) + m_knob6_spread_1);
		t_sample rsub_43180 = (((int)1) - m_knob3_damp_5);
		t_sample add_43125 = (((int)2554) + m_knob6_spread_1);
		t_sample rsub_43193 = (((int)1) - m_knob3_damp_5);
		t_sample add_43126 = (((int)2376) + m_knob6_spread_1);
		t_sample rsub_43204 = (((int)1) - m_knob3_damp_5);
		t_sample add_43127 = (((int)2232) + m_knob6_spread_1);
		t_sample rsub_43216 = (((int)1) - m_knob3_damp_5);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_43137 = __m_sah_32(m_history_7, m_sw_3, ((int)0));
			t_sample gen_43139 = sah_43137;
			t_sample rsub_43135 = (((int)1) - sah_43137);
			t_sample history_43136_next_43138 = fixdenorm(rsub_43135);
			t_sample out3 = gen_43139;
			t_sample add_43142 = (gen_43139 + ((int)1));
			t_sample choice_33 = int(add_43142);
			t_sample gate_43140 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_43141 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_43078 = (gate_43141 * sqrt_43079);
			t_sample mul_43132 = (gate_43141 * ((t_sample)0.015));
			t_sample tap_43090 = m_delay_8.read_linear(add_43121);
			t_sample gen_43112 = tap_43090;
			t_sample mul_43088 = (tap_43090 * m_knob3_damp_5);
			t_sample mul_43086 = (m_history_9 * rsub_43083);
			t_sample add_43087 = (mul_43088 + mul_43086);
			t_sample mul_43084 = (add_43087 * m_knob4_fb_2);
			t_sample add_43091 = (mul_43132 + mul_43084);
			t_sample history_43085_next_43092 = fixdenorm(add_43087);
			t_sample tap_43150 = m_delay_10.read_linear(add_43120);
			t_sample gen_43131 = tap_43150;
			t_sample mul_43149 = (tap_43150 * m_knob3_damp_5);
			t_sample mul_43152 = (m_history_11 * rsub_43145);
			t_sample add_43143 = (mul_43149 + mul_43152);
			t_sample mul_43148 = (add_43143 * m_knob4_fb_2);
			t_sample add_43147 = (mul_43132 + mul_43148);
			t_sample history_43085_next_43146 = fixdenorm(add_43143);
			t_sample tap_43162 = m_delay_12.read_linear(add_43122);
			t_sample gen_43111 = tap_43162;
			t_sample mul_43163 = (tap_43162 * m_knob3_damp_5);
			t_sample mul_43164 = (m_history_13 * rsub_43157);
			t_sample add_43160 = (mul_43163 + mul_43164);
			t_sample mul_43155 = (add_43160 * m_knob4_fb_2);
			t_sample add_43161 = (mul_43132 + mul_43155);
			t_sample history_43085_next_43158 = fixdenorm(add_43160);
			t_sample tap_43176 = m_delay_14.read_linear(add_43123);
			t_sample gen_43110 = tap_43176;
			t_sample mul_43173 = (tap_43176 * m_knob3_damp_5);
			t_sample mul_43175 = (m_history_15 * rsub_43168);
			t_sample add_43171 = (mul_43173 + mul_43175);
			t_sample mul_43167 = (add_43171 * m_knob4_fb_2);
			t_sample add_43172 = (mul_43132 + mul_43167);
			t_sample history_43085_next_43169 = fixdenorm(add_43171);
			t_sample tap_43188 = m_delay_16.read_linear(add_43124);
			t_sample gen_43109 = tap_43188;
			t_sample mul_43185 = (tap_43188 * m_knob3_damp_5);
			t_sample mul_43187 = (m_history_17 * rsub_43180);
			t_sample add_43183 = (mul_43185 + mul_43187);
			t_sample mul_43179 = (add_43183 * m_knob4_fb_2);
			t_sample add_43184 = (mul_43132 + mul_43179);
			t_sample history_43085_next_43181 = fixdenorm(add_43183);
			t_sample tap_43200 = m_delay_18.read_linear(add_43125);
			t_sample gen_43108 = tap_43200;
			t_sample mul_43198 = (tap_43200 * m_knob3_damp_5);
			t_sample mul_43199 = (m_history_19 * rsub_43193);
			t_sample add_43196 = (mul_43198 + mul_43199);
			t_sample mul_43191 = (add_43196 * m_knob4_fb_2);
			t_sample add_43197 = (mul_43132 + mul_43191);
			t_sample history_43085_next_43194 = fixdenorm(add_43196);
			t_sample tap_43209 = m_delay_20.read_linear(add_43126);
			t_sample gen_43107 = tap_43209;
			t_sample mul_43211 = (tap_43209 * m_knob3_damp_5);
			t_sample mul_43212 = (m_history_21 * rsub_43204);
			t_sample add_43208 = (mul_43211 + mul_43212);
			t_sample mul_43206 = (add_43208 * m_knob4_fb_2);
			t_sample add_43210 = (mul_43132 + mul_43206);
			t_sample history_43085_next_43205 = fixdenorm(add_43208);
			t_sample tap_43217 = m_delay_22.read_linear(add_43127);
			t_sample gen_43106 = tap_43217;
			t_sample mul_43219 = (tap_43217 * m_knob3_damp_5);
			t_sample mul_43220 = (m_history_23 * rsub_43216);
			t_sample add_43218 = (mul_43219 + mul_43220);
			t_sample mul_43224 = (add_43218 * m_knob4_fb_2);
			t_sample add_43223 = (mul_43132 + mul_43224);
			t_sample history_43085_next_43221 = fixdenorm(add_43218);
			t_sample pass_43129 = (((((((gen_43106 + gen_43107) + gen_43108) + gen_43109) + gen_43110) + gen_43111) + gen_43131) + gen_43112);
			t_sample tap_43066 = m_delay_24.read_linear(add_43114);
			t_sample sub_43062 = (pass_43129 - tap_43066);
			t_sample mul_43064 = (tap_43066 * mul_43130);
			t_sample add_43063 = (pass_43129 + mul_43064);
			t_sample tap_43230 = m_delay_25.read_linear(add_43128);
			t_sample sub_43231 = (sub_43062 - tap_43230);
			t_sample mul_43227 = (tap_43230 * mul_43130);
			t_sample add_43229 = (sub_43062 + mul_43227);
			t_sample tap_43236 = m_delay_26.read_linear(add_43118);
			t_sample sub_43237 = (sub_43231 - tap_43236);
			t_sample mul_43233 = (tap_43236 * mul_43130);
			t_sample add_43235 = (sub_43231 + mul_43233);
			t_sample tap_43242 = m_delay_27.read_linear(add_43116);
			t_sample sub_43243 = (sub_43237 - tap_43242);
			t_sample mul_43239 = (tap_43242 * mul_43130);
			t_sample add_43241 = (sub_43237 + mul_43239);
			t_sample mul_43081 = (sub_43243 * sqrt_43076);
			t_sample add_43077 = (mul_43078 + mul_43081);
			t_sample out1 = (gate_43140 + add_43077);
			t_sample tap_43248 = m_delay_28.read_linear(add_43068);
			t_sample sub_43249 = (pass_43129 - tap_43248);
			t_sample mul_43245 = (tap_43248 * mul_43075);
			t_sample add_43247 = (pass_43129 + mul_43245);
			t_sample tap_43252 = m_delay_29.read_linear(add_43074);
			t_sample sub_43255 = (sub_43249 - tap_43252);
			t_sample mul_43251 = (tap_43252 * mul_43075);
			t_sample add_43254 = (sub_43249 + mul_43251);
			t_sample tap_43260 = m_delay_30.read_linear(add_43072);
			t_sample sub_43261 = (sub_43255 - tap_43260);
			t_sample mul_43257 = (tap_43260 * mul_43075);
			t_sample add_43259 = (sub_43255 + mul_43257);
			t_sample tap_43266 = m_delay_31.read_linear(add_43070);
			t_sample sub_43267 = (sub_43261 - tap_43266);
			t_sample mul_43263 = (tap_43266 * mul_43075);
			t_sample add_43265 = (sub_43261 + mul_43263);
			t_sample mul_43057 = (sub_43267 * sqrt_43076);
			t_sample add_43056 = (mul_43078 + mul_43057);
			t_sample out2 = (add_43056 + gate_43140);
			m_history_7 = history_43136_next_43138;
			m_delay_31.write(add_43265);
			m_delay_30.write(add_43259);
			m_delay_29.write(add_43254);
			m_delay_28.write(add_43247);
			m_delay_27.write(add_43241);
			m_delay_26.write(add_43235);
			m_delay_25.write(add_43229);
			m_delay_24.write(add_43063);
			m_history_23 = history_43085_next_43221;
			m_delay_22.write(add_43223);
			m_history_21 = history_43085_next_43205;
			m_delay_20.write(add_43210);
			m_history_19 = history_43085_next_43194;
			m_delay_18.write(add_43197);
			m_history_17 = history_43085_next_43181;
			m_delay_16.write(add_43184);
			m_history_15 = history_43085_next_43169;
			m_delay_14.write(add_43172);
			m_history_13 = history_43085_next_43158;
			m_delay_12.write(add_43161);
			m_history_11 = history_43085_next_43146;
			m_delay_10.write(add_43147);
			m_history_9 = history_43085_next_43092;
			m_delay_8.write(add_43091);
			m_delay_8.step();
			m_delay_10.step();
			m_delay_12.step();
			m_delay_14.step();
			m_delay_16.step();
			m_delay_18.step();
			m_delay_20.step();
			m_delay_22.step();
			m_delay_24.step();
			m_delay_25.step();
			m_delay_26.step();
			m_delay_27.step();
			m_delay_28.step();
			m_delay_29.step();
			m_delay_30.step();
			m_delay_31.step();
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
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_1 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
	};
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb2(t_param _value) {
		m_knob5_fb_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_knob1_wetdry(value); break;
		case 1: self->set_knob3_damp(value); break;
		case 2: self->set_knob4_fb1(value); break;
		case 3: self->set_knob5_fb2(value); break;
		case 4: self->set_knob6_spread(value); break;
		case 5: self->set_sw1(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob1_wetdry_4; break;
		case 1: *value = self->m_knob3_damp_5; break;
		case 2: *value = self->m_knob4_fb_2; break;
		case 3: *value = self->m_knob5_fb_6; break;
		case 4: *value = self->m_knob6_spread_1; break;
		case 5: *value = self->m_sw_3; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_4")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_damp_5")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_fb_2")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_fb_6")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_spread_1")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_3")
	pi = self->__commonstate.params + 5;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_3;
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


} // Reverb2::
