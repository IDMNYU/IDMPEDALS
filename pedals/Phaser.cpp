#include "Phaser.h"

namespace Phaser {

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
	DCBlock __m_dcblock_64;
	DCBlock __m_dcblock_49;
	Phasor __m_phasor_31;
	Sah __m_sah_29;
	SineCycle __m_cycle_57;
	SineCycle __m_cycle_50;
	SineCycle __m_cycle_42;
	SineCycle __m_cycle_35;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_4;
	t_sample m_history_8;
	t_sample m_history_3;
	t_sample __m_slide_32;
	t_sample m_history_5;
	t_sample samples_to_seconds;
	t_sample __m_slide_36;
	t_sample m_history_6;
	t_sample __m_slide_39;
	t_sample m_history_2;
	t_sample __m_slide_43;
	t_sample __m_slide_54;
	t_sample __m_slide_58;
	t_sample m_knob3_depth_28;
	t_sample __m_slide_51;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_slide_46;
	t_sample m_history_7;
	t_sample m_knob4_rate_27;
	t_sample m_knob6_diffusion_25;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_12;
	t_sample m_history_10;
	t_sample m_history_11;
	t_sample m_history_9;
	t_sample m_knob5_fb_26;
	t_sample m_history_16;
	t_sample m_history_18;
	t_sample m_sw_23;
	t_sample m_sw_24;
	t_sample m_history_17;
	t_sample __m_slide_61;
	t_sample m_history_20;
	t_sample m_history_21;
	t_sample m_history_19;
	t_sample m_history_22;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
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
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_sw_23 = ((int)0);
		m_sw_24 = ((int)0);
		m_knob6_diffusion_25 = 1;
		m_knob5_fb_26 = ((int)0);
		m_knob4_rate_27 = 0.1;
		m_knob3_depth_28 = 1;
		__m_sah_29.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_31.reset(0);
		__m_slide_32 = 0;
		__m_cycle_35.reset(samplerate, 0);
		__m_slide_36 = 0;
		__m_slide_39 = 0;
		__m_cycle_42.reset(samplerate, 0);
		__m_slide_43 = 0;
		__m_slide_46 = 0;
		__m_dcblock_49.reset();
		__m_cycle_50.reset(samplerate, 0);
		__m_slide_51 = 0;
		__m_slide_54 = 0;
		__m_cycle_57.reset(samplerate, 0);
		__m_slide_58 = 0;
		__m_slide_61 = 0;
		__m_dcblock_64.reset();
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
		t_sample sub_1440 = (m_knob5_fb_26 - ((t_sample)0.5));
		t_sample scale_1437 = ((safepow((sub_1440 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		t_sample mul_1331 = (m_knob6_diffusion_25 * ((int)3));
		t_sample div_1329 = (mul_1331 * ((t_sample)0.125));
		t_sample mul_1332 = (m_knob6_diffusion_25 * ((int)1));
		t_sample div_1330 = (mul_1332 * ((t_sample)0.125));
		t_sample mul_1338 = (m_knob6_diffusion_25 * ((int)2));
		t_sample div_1336 = (mul_1338 * ((t_sample)0.125));
		t_sample mul_1339 = (m_knob6_diffusion_25 * ((int)0));
		t_sample div_1337 = (mul_1339 * ((t_sample)0.125));
		t_sample mstosamps_1178 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_1177 = (((int)100) * (samplerate * 0.001));
		t_sample iup_33 = (1 / maximum(1, abs(mstosamps_1178)));
		t_sample idown_34 = (1 / maximum(1, abs(mstosamps_1177)));
		t_sample div_1212 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_37 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_38 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_40 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_41 = (1 / maximum(1, abs(((int)5))));
		t_sample div_1254 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_44 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)5))));
		t_sample div_1297 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_52 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)5))));
		t_sample div_1355 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample mix_1434 = (m_history_22 + (((t_sample)0.0019634941468452) * (m_knob4_rate_27 - m_history_22)));
			t_sample mix_1168 = mix_1434;
			t_sample mix_1435 = (m_history_21 + (((t_sample)0.0019634941468452) * (mix_1168 - m_history_21)));
			t_sample mix_1166 = mix_1435;
			t_sample mix_1436 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_1166 - m_history_20)));
			t_sample mix_1164 = mix_1436;
			t_sample gen_1174 = mix_1164;
			t_sample history_1169_next_1171 = fixdenorm(mix_1168);
			t_sample history_1167_next_1172 = fixdenorm(mix_1166);
			t_sample history_1165_next_1173 = fixdenorm(mix_1164);
			t_sample expr_1385 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_1174)))));
			t_sample sah_1188 = __m_sah_29(m_history_19, m_sw_23, ((int)0));
			t_sample gen_1190 = sah_1188;
			t_sample rsub_1186 = (((int)1) - sah_1188);
			t_sample history_1187_next_1189 = fixdenorm(rsub_1186);
			t_sample out3 = gen_1190;
			t_sample add_1191 = (gen_1190 + ((int)1));
			t_sample choice_30 = int(add_1191);
			t_sample gate_1184 = (((choice_30 >= 1) && (choice_30 < 2)) ? in1 : 0);
			t_sample gate_1185 = ((choice_30 >= 2) ? in1 : 0);
			t_sample mul_1194 = (m_history_1 * m_knob5_fb_26);
			t_sample add_1193 = (gate_1185 + mul_1194);
			t_sample mul_1384 = (expr_1385 * ((t_sample)7.5));
			t_sample phasor_1340 = __m_phasor_31(mul_1384, samples_to_seconds);
			t_sample mul_1335 = (m_history_2 * m_knob5_fb_26);
			t_sample add_1334 = (gate_1185 + mul_1335);
			t_sample switch_1181 = (m_sw_24 ? gate_1185 : ((int)1));
			t_sample abs_1183 = fabs(switch_1181);
			t_sample mul_1162 = (abs_1183 * ((int)100));
			__m_slide_32 = fixdenorm((__m_slide_32 + (((mul_1162 > __m_slide_32) ? iup_33 : idown_34) * (mul_1162 - __m_slide_32))));
			t_sample slide_1182 = __m_slide_32;
			t_sample mul_1160 = (m_knob3_depth_28 * slide_1182);
			t_sample clamp_1180 = ((mul_1160 <= ((int)0)) ? ((int)0) : ((mul_1160 >= ((int)1)) ? ((int)1) : mul_1160));
			t_sample add_1221 = (phasor_1340 + div_1329);
			t_sample mod_1222 = safemod(add_1221, ((int)1));
			__m_cycle_35.phase(mod_1222);
			t_sample cycle_1219 = __m_cycle_35(__sinedata);
			t_sample cycleindex_1220 = __m_cycle_35.phase();
			t_sample add_1217 = (cycle_1219 + ((int)1));
			t_sample div_1216 = (add_1217 * ((t_sample)0.5));
			t_sample mul_1218 = (div_1216 * clamp_1180);
			t_sample sub_1444 = (mul_1218 - ((int)0));
			t_sample scale_1441 = ((safepow((sub_1444 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_1223 = scale_1441;
			t_sample mtof_1224 = mtof(scale_1223, ((int)440));
			t_sample mul_1211 = (mtof_1224 * div_1212);
			t_sample cos_1209 = cos(mul_1211);
			t_sample mul_1204 = (cos_1209 * (-2));
			t_sample sin_1210 = sin(mul_1211);
			t_sample mul_1208 = (sin_1210 * ((t_sample)0.5));
			t_sample div_1207 = (mul_1208 * ((t_sample)0.33333333333333));
			t_sample rsub_1202 = (((int)1) - div_1207);
			t_sample add_1206 = (div_1207 + ((int)1));
			t_sample rdiv_1205 = safediv(((int)1), add_1206);
			t_sample mul_1201 = (rdiv_1205 * rsub_1202);
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_1201 > __m_slide_36) ? iup_37 : idown_38) * (mul_1201 - __m_slide_36))));
			t_sample slide_1198 = __m_slide_36;
			t_sample gen_1214 = slide_1198;
			t_sample mul_1203 = (rdiv_1205 * mul_1204);
			__m_slide_39 = fixdenorm((__m_slide_39 + (((mul_1203 > __m_slide_39) ? iup_40 : idown_41) * (mul_1203 - __m_slide_39))));
			t_sample slide_1199 = __m_slide_39;
			t_sample gen_1213 = slide_1199;
			t_sample mul_1234 = (add_1193 * gen_1214);
			t_sample mul_1231 = (m_history_16 * gen_1213);
			t_sample mul_1229 = (m_history_18 * ((int)1));
			t_sample mul_1225 = (m_history_17 * gen_1214);
			t_sample mul_1227 = (m_history_15 * gen_1213);
			t_sample sub_1233 = (((mul_1229 + mul_1231) + mul_1234) - (mul_1227 + mul_1225));
			t_sample gen_1239 = sub_1233;
			t_sample history_1230_next_1235 = fixdenorm(m_history_16);
			t_sample history_1226_next_1236 = fixdenorm(m_history_15);
			t_sample history_1232_next_1237 = fixdenorm(add_1193);
			t_sample history_1228_next_1238 = fixdenorm(sub_1233);
			t_sample add_1263 = (phasor_1340 + div_1330);
			t_sample mod_1264 = safemod(add_1263, ((int)1));
			__m_cycle_42.phase(mod_1264);
			t_sample cycle_1261 = __m_cycle_42(__sinedata);
			t_sample cycleindex_1262 = __m_cycle_42.phase();
			t_sample add_1259 = (cycle_1261 + ((int)1));
			t_sample div_1258 = (add_1259 * ((t_sample)0.5));
			t_sample mul_1260 = (div_1258 * clamp_1180);
			t_sample sub_1448 = (mul_1260 - ((int)0));
			t_sample scale_1445 = ((safepow((sub_1448 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_1265 = scale_1445;
			t_sample mtof_1266 = mtof(scale_1265, ((int)440));
			t_sample mul_1253 = (mtof_1266 * div_1254);
			t_sample cos_1251 = cos(mul_1253);
			t_sample mul_1246 = (cos_1251 * (-2));
			t_sample sin_1252 = sin(mul_1253);
			t_sample mul_1250 = (sin_1252 * ((t_sample)0.5));
			t_sample div_1249 = (mul_1250 * ((t_sample)0.33333333333333));
			t_sample rsub_1244 = (((int)1) - div_1249);
			t_sample add_1248 = (div_1249 + ((int)1));
			t_sample rdiv_1247 = safediv(((int)1), add_1248);
			t_sample mul_1243 = (rdiv_1247 * rsub_1244);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((mul_1243 > __m_slide_43) ? iup_44 : idown_45) * (mul_1243 - __m_slide_43))));
			t_sample slide_1240 = __m_slide_43;
			t_sample gen_1256 = slide_1240;
			t_sample mul_1245 = (rdiv_1247 * mul_1246);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((mul_1245 > __m_slide_46) ? iup_47 : idown_48) * (mul_1245 - __m_slide_46))));
			t_sample slide_1241 = __m_slide_46;
			t_sample gen_1255 = slide_1241;
			t_sample mul_1276 = (add_1193 * gen_1256);
			t_sample mul_1273 = (m_history_12 * gen_1255);
			t_sample mul_1271 = (m_history_14 * ((int)1));
			t_sample mul_1267 = (m_history_13 * gen_1256);
			t_sample mul_1269 = (m_history_11 * gen_1255);
			t_sample sub_1275 = (((mul_1271 + mul_1273) + mul_1276) - (mul_1269 + mul_1267));
			t_sample gen_1281 = sub_1275;
			t_sample history_1272_next_1277 = fixdenorm(m_history_12);
			t_sample history_1268_next_1278 = fixdenorm(m_history_11);
			t_sample history_1274_next_1279 = fixdenorm(add_1193);
			t_sample history_1270_next_1280 = fixdenorm(sub_1275);
			t_sample mul_1195 = ((gen_1281 + gen_1239) * ((t_sample)0.5));
			t_sample dcblock_1196 = __m_dcblock_49(mul_1195);
			t_sample mul_1197 = (((gate_1185 + gen_1281) + gen_1239) * scale_1437);
			t_sample div_1158 = (mul_1197 * ((t_sample)0.5));
			t_sample add_1326 = (gate_1184 + div_1158);
			t_sample out2 = add_1326;
			t_sample add_1306 = (phasor_1340 + div_1336);
			t_sample mod_1307 = safemod(add_1306, ((int)1));
			__m_cycle_50.phase(mod_1307);
			t_sample cycle_1304 = __m_cycle_50(__sinedata);
			t_sample cycleindex_1305 = __m_cycle_50.phase();
			t_sample add_1302 = (cycle_1304 + ((int)1));
			t_sample div_1301 = (add_1302 * ((t_sample)0.5));
			t_sample mul_1303 = (div_1301 * clamp_1180);
			t_sample sub_1452 = (mul_1303 - ((int)0));
			t_sample scale_1449 = ((safepow((sub_1452 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_1308 = scale_1449;
			t_sample mtof_1309 = mtof(scale_1308, ((int)440));
			t_sample mul_1296 = (mtof_1309 * div_1297);
			t_sample cos_1294 = cos(mul_1296);
			t_sample mul_1289 = (cos_1294 * (-2));
			t_sample sin_1295 = sin(mul_1296);
			t_sample mul_1293 = (sin_1295 * ((t_sample)0.5));
			t_sample div_1292 = (mul_1293 * ((t_sample)0.33333333333333));
			t_sample rsub_1287 = (((int)1) - div_1292);
			t_sample add_1291 = (div_1292 + ((int)1));
			t_sample rdiv_1290 = safediv(((int)1), add_1291);
			t_sample mul_1288 = (rdiv_1290 * mul_1289);
			__m_slide_51 = fixdenorm((__m_slide_51 + (((mul_1288 > __m_slide_51) ? iup_52 : idown_53) * (mul_1288 - __m_slide_51))));
			t_sample slide_1284 = __m_slide_51;
			t_sample gen_1298 = slide_1284;
			t_sample mul_1286 = (rdiv_1290 * rsub_1287);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((mul_1286 > __m_slide_54) ? iup_55 : idown_56) * (mul_1286 - __m_slide_54))));
			t_sample slide_1283 = __m_slide_54;
			t_sample gen_1299 = slide_1283;
			t_sample mul_1319 = (add_1334 * gen_1299);
			t_sample mul_1316 = (m_history_8 * gen_1298);
			t_sample mul_1314 = (m_history_10 * ((int)1));
			t_sample mul_1310 = (m_history_9 * gen_1299);
			t_sample mul_1312 = (m_history_7 * gen_1298);
			t_sample sub_1318 = (((mul_1314 + mul_1316) + mul_1319) - (mul_1312 + mul_1310));
			t_sample gen_1324 = sub_1318;
			t_sample history_1315_next_1320 = fixdenorm(m_history_8);
			t_sample history_1311_next_1321 = fixdenorm(m_history_7);
			t_sample history_1317_next_1322 = fixdenorm(add_1334);
			t_sample history_1313_next_1323 = fixdenorm(sub_1318);
			t_sample add_1364 = (phasor_1340 + div_1337);
			t_sample mod_1365 = safemod(add_1364, ((int)1));
			__m_cycle_57.phase(mod_1365);
			t_sample cycle_1362 = __m_cycle_57(__sinedata);
			t_sample cycleindex_1363 = __m_cycle_57.phase();
			t_sample add_1360 = (cycle_1362 + ((int)1));
			t_sample div_1359 = (add_1360 * ((t_sample)0.5));
			t_sample mul_1361 = (div_1359 * clamp_1180);
			t_sample sub_1456 = (mul_1361 - ((int)0));
			t_sample scale_1453 = ((safepow((sub_1456 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_1366 = scale_1453;
			t_sample mtof_1367 = mtof(scale_1366, ((int)440));
			t_sample mul_1354 = (mtof_1367 * div_1355);
			t_sample cos_1352 = cos(mul_1354);
			t_sample mul_1347 = (cos_1352 * (-2));
			t_sample sin_1353 = sin(mul_1354);
			t_sample mul_1351 = (sin_1353 * ((t_sample)0.5));
			t_sample div_1350 = (mul_1351 * ((t_sample)0.33333333333333));
			t_sample rsub_1345 = (((int)1) - div_1350);
			t_sample add_1349 = (div_1350 + ((int)1));
			t_sample rdiv_1348 = safediv(((int)1), add_1349);
			t_sample mul_1346 = (rdiv_1348 * mul_1347);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((mul_1346 > __m_slide_58) ? iup_59 : idown_60) * (mul_1346 - __m_slide_58))));
			t_sample slide_1342 = __m_slide_58;
			t_sample gen_1356 = slide_1342;
			t_sample mul_1344 = (rdiv_1348 * rsub_1345);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((mul_1344 > __m_slide_61) ? iup_62 : idown_63) * (mul_1344 - __m_slide_61))));
			t_sample slide_1341 = __m_slide_61;
			t_sample gen_1357 = slide_1341;
			t_sample mul_1377 = (add_1334 * gen_1357);
			t_sample mul_1374 = (m_history_4 * gen_1356);
			t_sample mul_1372 = (m_history_6 * ((int)1));
			t_sample mul_1368 = (m_history_5 * gen_1357);
			t_sample mul_1370 = (m_history_3 * gen_1356);
			t_sample sub_1376 = (((mul_1372 + mul_1374) + mul_1377) - (mul_1370 + mul_1368));
			t_sample gen_1382 = sub_1376;
			t_sample history_1373_next_1378 = fixdenorm(m_history_4);
			t_sample history_1369_next_1379 = fixdenorm(m_history_3);
			t_sample history_1375_next_1380 = fixdenorm(add_1334);
			t_sample history_1371_next_1381 = fixdenorm(sub_1376);
			t_sample mul_1282 = ((gen_1382 + gen_1324) * ((t_sample)0.5));
			t_sample dcblock_1327 = __m_dcblock_64(mul_1282);
			t_sample mul_1325 = (((gate_1185 + gen_1382) + gen_1324) * scale_1437);
			t_sample div_1157 = (mul_1325 * ((t_sample)0.5));
			t_sample add_1328 = (gate_1184 + div_1157);
			t_sample out1 = add_1328;
			t_sample history_1333_next_1386 = fixdenorm(dcblock_1196);
			t_sample history_1192_next_1387 = fixdenorm(dcblock_1327);
			m_history_22 = history_1169_next_1171;
			m_history_20 = history_1165_next_1173;
			m_history_21 = history_1167_next_1172;
			m_history_19 = history_1187_next_1189;
			m_history_18 = history_1230_next_1235;
			m_history_15 = history_1228_next_1238;
			m_history_16 = history_1232_next_1237;
			m_history_17 = history_1226_next_1236;
			m_history_14 = history_1272_next_1277;
			m_history_11 = history_1270_next_1280;
			m_history_12 = history_1274_next_1279;
			m_history_13 = history_1268_next_1278;
			m_history_10 = history_1315_next_1320;
			m_history_7 = history_1313_next_1323;
			m_history_8 = history_1317_next_1322;
			m_history_9 = history_1311_next_1321;
			m_history_6 = history_1373_next_1378;
			m_history_3 = history_1371_next_1381;
			m_history_4 = history_1375_next_1380;
			m_history_5 = history_1369_next_1379;
			m_history_2 = history_1333_next_1386;
			m_history_1 = history_1192_next_1387;
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
	inline void set_sw1(t_param _value) {
		m_sw_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_diffusion(t_param _value) {
		m_knob6_diffusion_25 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_26 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_depth(t_param _value) {
		m_knob3_depth_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 2: self->set_knob5_fb(value); break;
		case 3: self->set_knob6_diffusion(value); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw5(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_knob3_depth_28; break;
		case 1: *value = self->m_knob4_rate_27; break;
		case 2: *value = self->m_knob5_fb_26; break;
		case 3: *value = self->m_knob6_diffusion_25; break;
		case 4: *value = self->m_sw_23; break;
		case 5: *value = self->m_sw_24; break;
		
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
	// initialize parameter 0 ("m_knob3_depth_28")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_27")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_fb_26")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_diffusion_25")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_diffusion";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_diffusion_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_23")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_24")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_24;
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


} // Phaser::
