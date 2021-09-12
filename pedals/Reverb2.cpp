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
	t_sample m_knob5_fb_3;
	t_sample m_history_11;
	t_sample m_sw_2;
	t_sample m_knob1_wetdry_1;
	t_sample samplerate;
	t_sample m_knob3_damp_4;
	t_sample m_history_13;
	t_sample m_knob4_fb_5;
	t_sample m_knob6_spread_6;
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
		m_knob1_wetdry_1 = ((int)0);
		m_sw_2 = ((int)0);
		m_knob5_fb_3 = ((t_sample)0.5);
		m_knob3_damp_4 = ((t_sample)0.5);
		m_knob4_fb_5 = ((t_sample)0.9);
		m_knob6_spread_6 = ((int)0);
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
		t_sample sqrt_22 = sqrt(m_knob1_wetdry_1);
		t_sample rsub_26 = (((int)1) - m_knob1_wetdry_1);
		t_sample sqrt_25 = sqrt(rsub_26);
		t_sample mul_76 = (m_knob5_fb_3 * ((t_sample)0.9));
		t_sample mul_21 = (m_knob5_fb_3 * ((t_sample)0.9));
		t_sample add_62 = (((int)450) + m_knob6_spread_6);
		t_sample add_16 = (((int)456) + m_knob6_spread_6);
		t_sample add_64 = (((int)682) + m_knob6_spread_6);
		t_sample add_18 = (((int)676) + m_knob6_spread_6);
		t_sample add_74 = (((int)882) + m_knob6_spread_6);
		t_sample add_20 = (((int)888) + m_knob6_spread_6);
		t_sample add_60 = (((int)1112) + m_knob6_spread_6);
		t_sample add_14 = (((int)1106) + m_knob6_spread_6);
		t_sample add_67 = (((int)3114) + m_knob6_spread_6);
		t_sample rsub_29 = (((int)1) - m_knob3_damp_4);
		t_sample add_66 = (((int)3234) + m_knob6_spread_6);
		t_sample rsub_93 = (((int)1) - m_knob3_damp_4);
		t_sample add_68 = (((int)2982) + m_knob6_spread_6);
		t_sample rsub_105 = (((int)1) - m_knob3_damp_4);
		t_sample add_69 = (((int)2844) + m_knob6_spread_6);
		t_sample rsub_117 = (((int)1) - m_knob3_damp_4);
		t_sample add_70 = (((int)2712) + m_knob6_spread_6);
		t_sample rsub_128 = (((int)1) - m_knob3_damp_4);
		t_sample add_71 = (((int)2554) + m_knob6_spread_6);
		t_sample rsub_142 = (((int)1) - m_knob3_damp_4);
		t_sample add_72 = (((int)2376) + m_knob6_spread_6);
		t_sample rsub_155 = (((int)1) - m_knob3_damp_4);
		t_sample add_73 = (((int)2232) + m_knob6_spread_6);
		t_sample rsub_163 = (((int)1) - m_knob3_damp_4);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample sah_81 = __m_sah_32(m_history_7, m_sw_2, ((int)0));
			t_sample gen_83 = sah_81;
			t_sample rsub_79 = (((int)1) - sah_81);
			t_sample history_80_next_82 = fixdenorm(rsub_79);
			t_sample out3 = gen_83;
			t_sample add_86 = (gen_83 + ((int)1));
			t_sample choice_33 = int(add_86);
			t_sample gate_84 = (((choice_33 >= 1) && (choice_33 < 2)) ? in1 : 0);
			t_sample gate_85 = ((choice_33 >= 2) ? in1 : 0);
			t_sample mul_24 = (gate_85 * sqrt_25);
			t_sample mul_78 = (gate_85 * ((t_sample)0.015));
			t_sample tap_36 = m_delay_8.read_linear(add_67);
			t_sample gen_58 = tap_36;
			t_sample mul_34 = (tap_36 * m_knob3_damp_4);
			t_sample mul_32 = (m_history_9 * rsub_29);
			t_sample add_33 = (mul_34 + mul_32);
			t_sample mul_30 = (add_33 * m_knob4_fb_5);
			t_sample add_37 = (mul_78 + mul_30);
			t_sample history_31_next_38 = fixdenorm(add_33);
			t_sample tap_89 = m_delay_10.read_linear(add_66);
			t_sample gen_77 = tap_89;
			t_sample mul_88 = (tap_89 * m_knob3_damp_4);
			t_sample mul_92 = (m_history_11 * rsub_93);
			t_sample add_95 = (mul_88 + mul_92);
			t_sample mul_91 = (add_95 * m_knob4_fb_5);
			t_sample add_87 = (mul_78 + mul_91);
			t_sample history_31_next_90 = fixdenorm(add_95);
			t_sample tap_102 = m_delay_12.read_linear(add_68);
			t_sample gen_57 = tap_102;
			t_sample mul_100 = (tap_102 * m_knob3_damp_4);
			t_sample mul_104 = (m_history_13 * rsub_105);
			t_sample add_107 = (mul_100 + mul_104);
			t_sample mul_103 = (add_107 * m_knob4_fb_5);
			t_sample add_99 = (mul_78 + mul_103);
			t_sample history_31_next_101 = fixdenorm(add_107);
			t_sample tap_112 = m_delay_14.read_linear(add_69);
			t_sample gen_56 = tap_112;
			t_sample mul_115 = (tap_112 * m_knob3_damp_4);
			t_sample mul_116 = (m_history_15 * rsub_117);
			t_sample add_118 = (mul_115 + mul_116);
			t_sample mul_113 = (add_118 * m_knob4_fb_5);
			t_sample add_111 = (mul_78 + mul_113);
			t_sample history_31_next_119 = fixdenorm(add_118);
			t_sample tap_124 = m_delay_16.read_linear(add_70);
			t_sample gen_55 = tap_124;
			t_sample mul_127 = (tap_124 * m_knob3_damp_4);
			t_sample mul_131 = (m_history_17 * rsub_128);
			t_sample add_129 = (mul_127 + mul_131);
			t_sample mul_125 = (add_129 * m_knob4_fb_5);
			t_sample add_123 = (mul_78 + mul_125);
			t_sample history_31_next_130 = fixdenorm(add_129);
			t_sample tap_136 = m_delay_18.read_linear(add_71);
			t_sample gen_54 = tap_136;
			t_sample mul_140 = (tap_136 * m_knob3_damp_4);
			t_sample mul_143 = (m_history_19 * rsub_142);
			t_sample add_141 = (mul_140 + mul_143);
			t_sample mul_137 = (add_141 * m_knob4_fb_5);
			t_sample add_135 = (mul_78 + mul_137);
			t_sample history_31_next_139 = fixdenorm(add_141);
			t_sample tap_148 = m_delay_20.read_linear(add_72);
			t_sample gen_53 = tap_148;
			t_sample mul_151 = (tap_148 * m_knob3_damp_4);
			t_sample mul_152 = (m_history_21 * rsub_155);
			t_sample add_153 = (mul_151 + mul_152);
			t_sample mul_149 = (add_153 * m_knob4_fb_5);
			t_sample add_147 = (mul_78 + mul_149);
			t_sample history_31_next_154 = fixdenorm(add_153);
			t_sample tap_159 = m_delay_22.read_linear(add_73);
			t_sample gen_52 = tap_159;
			t_sample mul_164 = (tap_159 * m_knob3_damp_4);
			t_sample mul_165 = (m_history_23 * rsub_163);
			t_sample add_167 = (mul_164 + mul_165);
			t_sample mul_160 = (add_167 * m_knob4_fb_5);
			t_sample add_162 = (mul_78 + mul_160);
			t_sample history_31_next_168 = fixdenorm(add_167);
			t_sample pass_75 = (((((((gen_52 + gen_53) + gen_54) + gen_55) + gen_56) + gen_57) + gen_77) + gen_58);
			t_sample tap_12 = m_delay_24.read_linear(add_60);
			t_sample sub_8 = (pass_75 - tap_12);
			t_sample mul_10 = (tap_12 * mul_76);
			t_sample add_9 = (pass_75 + mul_10);
			t_sample tap_171 = m_delay_25.read_linear(add_74);
			t_sample sub_175 = (sub_8 - tap_171);
			t_sample mul_173 = (tap_171 * mul_76);
			t_sample add_174 = (sub_8 + mul_173);
			t_sample tap_177 = m_delay_26.read_linear(add_64);
			t_sample sub_181 = (sub_175 - tap_177);
			t_sample mul_179 = (tap_177 * mul_76);
			t_sample add_180 = (sub_175 + mul_179);
			t_sample tap_183 = m_delay_27.read_linear(add_62);
			t_sample sub_187 = (sub_181 - tap_183);
			t_sample mul_185 = (tap_183 * mul_76);
			t_sample add_186 = (sub_181 + mul_185);
			t_sample mul_27 = (sub_187 * sqrt_22);
			t_sample add_23 = (mul_24 + mul_27);
			t_sample out1 = (gate_84 + add_23);
			t_sample tap_189 = m_delay_28.read_linear(add_14);
			t_sample sub_193 = (pass_75 - tap_189);
			t_sample mul_191 = (tap_189 * mul_21);
			t_sample add_192 = (pass_75 + mul_191);
			t_sample tap_195 = m_delay_29.read_linear(add_20);
			t_sample sub_199 = (sub_193 - tap_195);
			t_sample mul_197 = (tap_195 * mul_21);
			t_sample add_198 = (sub_193 + mul_197);
			t_sample tap_201 = m_delay_30.read_linear(add_18);
			t_sample sub_205 = (sub_199 - tap_201);
			t_sample mul_203 = (tap_201 * mul_21);
			t_sample add_204 = (sub_199 + mul_203);
			t_sample tap_207 = m_delay_31.read_linear(add_16);
			t_sample sub_211 = (sub_205 - tap_207);
			t_sample mul_209 = (tap_207 * mul_21);
			t_sample add_210 = (sub_205 + mul_209);
			t_sample mul_3 = (sub_211 * sqrt_22);
			t_sample add_2 = (mul_24 + mul_3);
			t_sample out2 = (add_2 + gate_84);
			m_history_7 = history_80_next_82;
			m_delay_31.write(add_210);
			m_delay_30.write(add_204);
			m_delay_29.write(add_198);
			m_delay_28.write(add_192);
			m_delay_27.write(add_186);
			m_delay_26.write(add_180);
			m_delay_25.write(add_174);
			m_delay_24.write(add_9);
			m_history_23 = history_31_next_168;
			m_delay_22.write(add_162);
			m_history_21 = history_31_next_154;
			m_delay_20.write(add_147);
			m_history_19 = history_31_next_139;
			m_delay_18.write(add_135);
			m_history_17 = history_31_next_130;
			m_delay_16.write(add_123);
			m_history_15 = history_31_next_119;
			m_delay_14.write(add_111);
			m_history_13 = history_31_next_101;
			m_delay_12.write(add_99);
			m_history_11 = history_31_next_90;
			m_delay_10.write(add_87);
			m_history_9 = history_31_next_38;
			m_delay_8.write(add_37);
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
	inline void set_knob1_wetdry(t_param _value) {
		m_knob1_wetdry_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb2(t_param _value) {
		m_knob5_fb_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_damp(t_param _value) {
		m_knob3_damp_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_fb1(t_param _value) {
		m_knob4_fb_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_spread(t_param _value) {
		m_knob6_spread_6 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
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
		case 0: *value = self->m_knob1_wetdry_1; break;
		case 1: *value = self->m_knob3_damp_4; break;
		case 2: *value = self->m_knob4_fb_5; break;
		case 3: *value = self->m_knob5_fb_3; break;
		case 4: *value = self->m_knob6_spread_6; break;
		case 5: *value = self->m_sw_2; break;
		
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
	// initialize parameter 0 ("m_knob1_wetdry_1")
	pi = self->__commonstate.params + 0;
	pi->name = "knob1_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_wetdry_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob3_damp_4")
	pi = self->__commonstate.params + 1;
	pi->name = "knob3_damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_damp_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob4_fb_5")
	pi = self->__commonstate.params + 2;
	pi->name = "knob4_fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_fb_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob5_fb_3")
	pi = self->__commonstate.params + 3;
	pi->name = "knob5_fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob6_spread_6")
	pi = self->__commonstate.params + 4;
	pi->name = "knob6_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_spread_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_2")
	pi = self->__commonstate.params + 5;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_2;
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
