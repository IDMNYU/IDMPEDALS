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
	t_sample m_knob4_rate_20;
	t_sample m_sw_18;
	t_sample m_history_13;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_sw_19;
	t_sample m_history_8;
	t_sample m_knob5_breadth_16;
	t_sample m_knob6_taps_15;
	t_sample m_knob3_depth_17;
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
		m_knob6_taps_15 = ((int)0);
		m_knob5_breadth_16 = 256;
		m_knob3_depth_17 = ((int)0);
		m_sw_18 = ((int)0);
		m_sw_19 = ((int)0);
		m_knob4_rate_20 = ((int)0);
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
		t_sample expr_118 = (((int)1) - sqrt(sqrt((((int)1) - m_knob3_depth_17))));
		t_sample expr_117 = (((int)1) - sqrt(sqrt((((int)1) - m_knob4_rate_20))));
		t_sample div_2 = (m_sw_18 * ((t_sample)0.5));
		t_sample add_1 = (div_2 + ((t_sample)0.5));
		t_sample mul_10 = (expr_118 * ((int)1000));
		t_sample add_9 = (mul_10 + ((int)2));
		t_sample mul_7 = (expr_117 * ((int)10));
		t_sample add_8 = (mul_7 + ((t_sample)0.01));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample sah_111 = __m_sah_21(m_history_14, m_sw_19, ((int)0));
			t_sample gen_113 = sah_111;
			t_sample rsub_109 = (((int)1) - sah_111);
			t_sample history_110_next_112 = fixdenorm(rsub_109);
			t_sample out3 = gen_113;
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample add_114 = (gen_113 + ((int)1));
			t_sample choice_22 = int(add_114);
			t_sample gate_106 = (((choice_22 >= 1) && (choice_22 < 2)) ? in1 : 0);
			t_sample gate_107 = ((choice_22 >= 2) ? in1 : 0);
			t_sample switch_44 = (m_sw_18 ? ((int)0) : gate_107);
			t_sample mix_242 = (m_history_13 + (((t_sample)0.0042742627044161) * (m_knob6_taps_15 - m_history_13)));
			t_sample mix_16 = mix_242;
			t_sample mix_243 = (m_history_12 + (((t_sample)0.0042742627044161) * (mix_16 - m_history_12)));
			t_sample mix_14 = mix_243;
			t_sample mix_244 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_14 - m_history_11)));
			t_sample mix_12 = mix_244;
			t_sample gen_42 = mix_12;
			t_sample history_17_next_19 = fixdenorm(mix_16);
			t_sample history_15_next_20 = fixdenorm(mix_14);
			t_sample history_13_next_21 = fixdenorm(mix_12);
			t_sample sub_248 = (gen_42 - ((int)0));
			t_sample scale_245 = ((safepow((sub_248 * ((t_sample)1)), ((int)1)) * ((t_sample)-0.5)) + ((int)1));
			t_sample sub_252 = (gen_42 - ((int)0));
			t_sample scale_249 = ((safepow((sub_252 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-2));
			t_sample clamp_28 = ((scale_249 <= ((int)0)) ? ((int)0) : ((scale_249 >= ((int)1)) ? ((int)1) : scale_249));
			t_sample sub_256 = (gen_42 - ((int)0));
			t_sample scale_253 = ((safepow((sub_256 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-3));
			t_sample clamp_26 = ((scale_253 <= ((int)0)) ? ((int)0) : ((scale_253 >= ((int)1)) ? ((int)1) : scale_253));
			t_sample sub_260 = (gen_42 - ((int)0));
			t_sample scale_257 = ((safepow((sub_260 * ((t_sample)1)), ((int)1)) * ((int)4)) + (-1));
			t_sample clamp_30 = ((scale_257 <= ((int)0)) ? ((int)0) : ((scale_257 >= ((int)1)) ? ((int)1) : scale_257));
			t_sample mix_261 = (m_history_10 + (((t_sample)0.0042742627044161) * (m_knob5_breadth_16 - m_history_10)));
			t_sample mix_128 = mix_261;
			t_sample mix_262 = (m_history_9 + (((t_sample)0.0042742627044161) * (mix_128 - m_history_9)));
			t_sample mix_127 = mix_262;
			t_sample mix_263 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_127 - m_history_8)));
			t_sample mix_126 = mix_263;
			t_sample gen_22 = mix_126;
			t_sample history_17_next_123 = fixdenorm(mix_128);
			t_sample history_15_next_122 = fixdenorm(mix_127);
			t_sample history_13_next_125 = fixdenorm(mix_126);
			t_sample mul_11 = (gen_22 * ((int)1));
			t_sample mul_25 = (gen_22 * ((int)2));
			t_sample mul_24 = (gen_22 * ((int)3));
			t_sample mul_23 = (gen_22 * ((int)4));
			t_sample mix_264 = (m_history_7 + (((t_sample)0.0042742627044161) * (add_9 - m_history_7)));
			t_sample mix_141 = mix_264;
			t_sample mix_265 = (m_history_6 + (((t_sample)0.0042742627044161) * (mix_141 - m_history_6)));
			t_sample mix_135 = mix_265;
			t_sample mix_266 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_135 - m_history_5)));
			t_sample mix_140 = mix_266;
			t_sample gen_116 = mix_140;
			t_sample history_17_next_137 = fixdenorm(mix_141);
			t_sample history_15_next_136 = fixdenorm(mix_135);
			t_sample history_13_next_139 = fixdenorm(mix_140);
			t_sample mix_267 = (m_history_4 + (((t_sample)0.0042742627044161) * (add_8 - m_history_4)));
			t_sample mix_148 = mix_267;
			t_sample mix_268 = (m_history_3 + (((t_sample)0.0042742627044161) * (mix_148 - m_history_3)));
			t_sample mix_152 = mix_268;
			t_sample mix_269 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_152 - m_history_2)));
			t_sample mix_145 = mix_269;
			t_sample gen_53 = mix_145;
			t_sample history_17_next_153 = fixdenorm(mix_148);
			t_sample history_15_next_146 = fixdenorm(mix_152);
			t_sample history_13_next_154 = fixdenorm(mix_145);
			t_sample mul_57 = (gen_53 * ((int)1));
			__m_cycle_23.freq(mul_57);
			t_sample cycle_95 = __m_cycle_23(__sinedata);
			t_sample cycleindex_96 = __m_cycle_23.phase();
			t_sample mul_93 = (cycle_95 * gen_116);
			t_sample add_94 = (mul_93 + mul_11);
			t_sample mul_88 = (gen_53 * ((t_sample)1.51));
			__m_cycle_24.freq(mul_88);
			t_sample cycle_91 = __m_cycle_24(__sinedata);
			t_sample cycleindex_92 = __m_cycle_24.phase();
			t_sample mul_89 = (cycle_91 * gen_116);
			t_sample add_90 = (mul_89 + mul_11);
			t_sample mul_56 = (gen_53 * ((t_sample)0.48));
			__m_cycle_25.freq(mul_56);
			t_sample cycle_85 = __m_cycle_25(__sinedata);
			t_sample cycleindex_86 = __m_cycle_25.phase();
			t_sample mul_83 = (cycle_85 * gen_116);
			t_sample add_84 = (mul_83 + mul_25);
			t_sample mul_78 = (gen_53 * ((t_sample)0.73));
			__m_cycle_26.freq(mul_78);
			t_sample cycle_81 = __m_cycle_26(__sinedata);
			t_sample cycleindex_82 = __m_cycle_26.phase();
			t_sample mul_79 = (cycle_81 * gen_116);
			t_sample add_80 = (mul_79 + mul_25);
			t_sample mul_55 = (gen_53 * ((t_sample)1.245));
			__m_cycle_27.freq(mul_55);
			t_sample cycle_74 = __m_cycle_27(__sinedata);
			t_sample cycleindex_75 = __m_cycle_27.phase();
			t_sample mul_72 = (cycle_74 * gen_116);
			t_sample add_73 = (mul_72 + mul_24);
			t_sample mul_67 = (gen_53 * ((t_sample)0.81));
			__m_cycle_28.freq(mul_67);
			t_sample cycle_70 = __m_cycle_28(__sinedata);
			t_sample cycleindex_71 = __m_cycle_28.phase();
			t_sample mul_68 = (cycle_70 * gen_116);
			t_sample add_69 = (mul_68 + mul_24);
			t_sample mul_54 = (gen_53 * ((t_sample)1.93));
			__m_cycle_29.freq(mul_54);
			t_sample cycle_65 = __m_cycle_29(__sinedata);
			t_sample cycleindex_66 = __m_cycle_29.phase();
			t_sample mul_63 = (cycle_65 * gen_116);
			t_sample add_64 = (mul_63 + mul_23);
			t_sample mul_58 = (gen_53 * ((t_sample)2.11));
			__m_cycle_30.freq(mul_58);
			t_sample cycle_61 = __m_cycle_30(__sinedata);
			t_sample cycleindex_62 = __m_cycle_30.phase();
			t_sample mul_59 = (cycle_61 * gen_116);
			t_sample add_60 = (mul_59 + mul_23);
			t_sample tap_98 = m_delay_1.read_linear(add_94);
			t_sample tap_99 = m_delay_1.read_linear(add_90);
			t_sample tap_100 = m_delay_1.read_linear(add_84);
			t_sample tap_101 = m_delay_1.read_linear(add_80);
			t_sample tap_102 = m_delay_1.read_linear(add_73);
			t_sample tap_103 = m_delay_1.read_linear(add_69);
			t_sample tap_104 = m_delay_1.read_linear(add_64);
			t_sample tap_105 = m_delay_1.read_linear(add_60);
			t_sample mul_41 = (tap_102 * clamp_28);
			t_sample mul_38 = (tap_105 * clamp_26);
			t_sample mul_34 = (tap_101 * clamp_30);
			t_sample mul_37 = (tap_98 * ((int)1));
			t_sample mul_77 = ((((mul_37 + mul_34) + mul_38) + mul_41) * scale_245);
			t_sample add_115 = (switch_44 + mul_77);
			t_sample mul_4 = (add_1 * add_115);
			t_sample out1 = (gate_106 + mul_4);
			t_sample mul_40 = (tap_103 * clamp_28);
			t_sample mul_39 = (tap_104 * clamp_26);
			t_sample mul_35 = (tap_100 * clamp_30);
			t_sample mul_36 = (tap_99 * ((int)1));
			t_sample mul_76 = ((((mul_36 + mul_35) + mul_39) + mul_40) * scale_245);
			t_sample add_87 = (switch_44 + mul_76);
			t_sample mul_3 = (add_1 * add_87);
			t_sample out2 = (gate_106 + mul_3);
			m_history_14 = history_110_next_112;
			m_history_13 = history_17_next_19;
			m_history_11 = history_13_next_21;
			m_history_12 = history_15_next_20;
			m_history_10 = history_17_next_123;
			m_history_8 = history_13_next_125;
			m_history_9 = history_15_next_122;
			m_history_7 = history_17_next_137;
			m_history_5 = history_13_next_139;
			m_history_6 = history_15_next_136;
			m_history_4 = history_17_next_153;
			m_history_2 = history_13_next_154;
			m_history_3 = history_15_next_146;
			m_delay_1.write(gate_107);
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
	inline void set_knob6_taps(t_param _value) {
		m_knob6_taps_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_breadth(t_param _value) {
		m_knob5_breadth_16 = (_value < 240 ? 240 : (_value > 2400 ? 2400 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_depth_17; break;
		case 1: *value = self->m_knob4_rate_20; break;
		case 2: *value = self->m_knob5_breadth_16; break;
		case 3: *value = self->m_knob6_taps_15; break;
		case 4: *value = self->m_sw_19; break;
		case 5: *value = self->m_sw_18; break;
		
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
	// initialize parameter 0 ("m_knob3_depth_17")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_20")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_breadth_16")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_breadth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_breadth_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 240;
	pi->outputmax = 2400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_taps_15")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_taps";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_taps_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_19")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
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
	// initialize parameter 5 ("m_sw_18")
	pi = self->__commonstate.params + 5;
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


} // Chorus::
