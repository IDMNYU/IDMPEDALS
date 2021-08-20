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
	t_sample m_history_28;
	t_sample __m_slide_51;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_slide_46;
	t_sample m_history_7;
	t_sample m_history_27;
	t_sample m_sw_25;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_12;
	t_sample m_history_10;
	t_sample m_history_11;
	t_sample m_history_9;
	t_sample m_history_26;
	t_sample m_history_16;
	t_sample m_history_18;
	t_sample m_knob6_diffusion_23;
	t_sample m_knob4_rate_24;
	t_sample m_history_17;
	t_sample __m_slide_61;
	t_sample m_knob3_depth_20;
	t_sample m_knob5_fb_21;
	t_sample m_history_19;
	t_sample m_sw_22;
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
		m_knob3_depth_20 = 1;
		m_knob5_fb_21 = ((int)0);
		m_sw_22 = ((int)0);
		m_knob6_diffusion_23 = 1;
		m_knob4_rate_24 = 0.1;
		m_sw_25 = ((int)0);
		m_history_26 = ((int)0);
		m_history_27 = ((int)0);
		m_history_28 = ((int)0);
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
		t_sample sub_1337 = (m_knob5_fb_21 - ((t_sample)0.5));
		t_sample scale_1334 = ((safepow((sub_1337 * ((t_sample)2.0408163265306)), ((int)1)) * ((t_sample)-0.15)) + ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		t_sample mul_496 = (m_knob6_diffusion_23 * ((int)3));
		t_sample div_494 = (mul_496 * ((t_sample)0.125));
		t_sample mul_497 = (m_knob6_diffusion_23 * ((int)1));
		t_sample div_495 = (mul_497 * ((t_sample)0.125));
		t_sample mul_503 = (m_knob6_diffusion_23 * ((int)2));
		t_sample div_501 = (mul_503 * ((t_sample)0.125));
		t_sample mul_504 = (m_knob6_diffusion_23 * ((int)0));
		t_sample div_502 = (mul_504 * ((t_sample)0.125));
		t_sample mstosamps_343 = (((int)10) * (samplerate * 0.001));
		t_sample mstosamps_342 = (((int)100) * (samplerate * 0.001));
		t_sample iup_33 = (1 / maximum(1, abs(mstosamps_343)));
		t_sample idown_34 = (1 / maximum(1, abs(mstosamps_342)));
		t_sample div_377 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_37 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_38 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_40 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_41 = (1 / maximum(1, abs(((int)5))));
		t_sample div_419 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_44 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_47 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)5))));
		t_sample div_462 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_52 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_53 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_55 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_56 = (1 / maximum(1, abs(((int)5))));
		t_sample div_520 = safediv(((t_sample)6.2831853071796), samplerate);
		t_sample iup_59 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)5))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)5))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)5))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample mix_1331 = (m_history_28 + (((t_sample)0.0019634941468452) * (m_knob4_rate_24 - m_history_28)));
			t_sample mix_333 = mix_1331;
			t_sample mix_1332 = (m_history_27 + (((t_sample)0.0019634941468452) * (mix_333 - m_history_27)));
			t_sample mix_331 = mix_1332;
			t_sample mix_1333 = (m_history_26 + (((t_sample)0.0019634941468452) * (mix_331 - m_history_26)));
			t_sample mix_329 = mix_1333;
			t_sample gen_339 = mix_329;
			t_sample history_334_next_336 = fixdenorm(mix_333);
			t_sample history_332_next_337 = fixdenorm(mix_331);
			t_sample history_330_next_338 = fixdenorm(mix_329);
			t_sample expr_1259 = (((int)1) - sqrt(sqrt(sqrt((((int)1) - gen_339)))));
			t_sample out5 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample sah_353 = __m_sah_29(m_history_19, m_sw_25, ((int)0));
			t_sample gen_355 = sah_353;
			t_sample rsub_351 = (((int)1) - sah_353);
			t_sample history_352_next_354 = fixdenorm(rsub_351);
			t_sample out3 = gen_355;
			t_sample add_356 = (gen_355 + ((int)1));
			t_sample choice_30 = int(add_356);
			t_sample gate_349 = (((choice_30 >= 1) && (choice_30 < 2)) ? in1 : 0);
			t_sample gate_350 = ((choice_30 >= 2) ? in1 : 0);
			t_sample mul_359 = (m_history_1 * m_knob5_fb_21);
			t_sample add_358 = (gate_350 + mul_359);
			t_sample mul_549 = (expr_1259 * ((t_sample)7.5));
			t_sample phasor_505 = __m_phasor_31(mul_549, samples_to_seconds);
			t_sample mul_500 = (m_history_2 * m_knob5_fb_21);
			t_sample add_499 = (gate_350 + mul_500);
			t_sample abs_669 = fabs(gate_350);
			t_sample mul_1258 = (abs_669 * ((int)30));
			t_sample switch_346 = (m_sw_22 ? mul_1258 : ((int)1));
			__m_slide_32 = fixdenorm((__m_slide_32 + (((switch_346 > __m_slide_32) ? iup_33 : idown_34) * (switch_346 - __m_slide_32))));
			t_sample slide_347 = __m_slide_32;
			t_sample mul_325 = (m_knob3_depth_20 * slide_347);
			t_sample clamp_345 = ((mul_325 <= ((int)0)) ? ((int)0) : ((mul_325 >= ((int)1)) ? ((int)1) : mul_325));
			t_sample add_386 = (phasor_505 + div_494);
			t_sample mod_387 = safemod(add_386, ((int)1));
			__m_cycle_35.phase(mod_387);
			t_sample cycle_384 = __m_cycle_35(__sinedata);
			t_sample cycleindex_385 = __m_cycle_35.phase();
			t_sample add_382 = (cycle_384 + ((int)1));
			t_sample div_381 = (add_382 * ((t_sample)0.5));
			t_sample mul_383 = (div_381 * clamp_345);
			t_sample sub_1341 = (mul_383 - ((int)0));
			t_sample scale_1338 = ((safepow((sub_1341 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_388 = scale_1338;
			t_sample mtof_389 = mtof(scale_388, ((int)440));
			t_sample mul_376 = (mtof_389 * div_377);
			t_sample cos_374 = cos(mul_376);
			t_sample mul_369 = (cos_374 * (-2));
			t_sample sin_375 = sin(mul_376);
			t_sample mul_373 = (sin_375 * ((t_sample)0.5));
			t_sample div_372 = (mul_373 * ((t_sample)0.33333333333333));
			t_sample rsub_367 = (((int)1) - div_372);
			t_sample add_371 = (div_372 + ((int)1));
			t_sample rdiv_370 = safediv(((int)1), add_371);
			t_sample mul_366 = (rdiv_370 * rsub_367);
			__m_slide_36 = fixdenorm((__m_slide_36 + (((mul_366 > __m_slide_36) ? iup_37 : idown_38) * (mul_366 - __m_slide_36))));
			t_sample slide_363 = __m_slide_36;
			t_sample gen_379 = slide_363;
			t_sample mul_368 = (rdiv_370 * mul_369);
			__m_slide_39 = fixdenorm((__m_slide_39 + (((mul_368 > __m_slide_39) ? iup_40 : idown_41) * (mul_368 - __m_slide_39))));
			t_sample slide_364 = __m_slide_39;
			t_sample gen_378 = slide_364;
			t_sample mul_399 = (add_358 * gen_379);
			t_sample mul_396 = (m_history_16 * gen_378);
			t_sample mul_394 = (m_history_18 * ((int)1));
			t_sample mul_390 = (m_history_17 * gen_379);
			t_sample mul_392 = (m_history_15 * gen_378);
			t_sample sub_398 = (((mul_394 + mul_396) + mul_399) - (mul_392 + mul_390));
			t_sample gen_404 = sub_398;
			t_sample history_395_next_400 = fixdenorm(m_history_16);
			t_sample history_391_next_401 = fixdenorm(m_history_15);
			t_sample history_397_next_402 = fixdenorm(add_358);
			t_sample history_393_next_403 = fixdenorm(sub_398);
			t_sample add_428 = (phasor_505 + div_495);
			t_sample mod_429 = safemod(add_428, ((int)1));
			__m_cycle_42.phase(mod_429);
			t_sample cycle_426 = __m_cycle_42(__sinedata);
			t_sample cycleindex_427 = __m_cycle_42.phase();
			t_sample add_424 = (cycle_426 + ((int)1));
			t_sample div_423 = (add_424 * ((t_sample)0.5));
			t_sample mul_425 = (div_423 * clamp_345);
			t_sample sub_1345 = (mul_425 - ((int)0));
			t_sample scale_1342 = ((safepow((sub_1345 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_430 = scale_1342;
			t_sample mtof_431 = mtof(scale_430, ((int)440));
			t_sample mul_418 = (mtof_431 * div_419);
			t_sample cos_416 = cos(mul_418);
			t_sample mul_411 = (cos_416 * (-2));
			t_sample sin_417 = sin(mul_418);
			t_sample mul_415 = (sin_417 * ((t_sample)0.5));
			t_sample div_414 = (mul_415 * ((t_sample)0.33333333333333));
			t_sample rsub_409 = (((int)1) - div_414);
			t_sample add_413 = (div_414 + ((int)1));
			t_sample rdiv_412 = safediv(((int)1), add_413);
			t_sample mul_408 = (rdiv_412 * rsub_409);
			__m_slide_43 = fixdenorm((__m_slide_43 + (((mul_408 > __m_slide_43) ? iup_44 : idown_45) * (mul_408 - __m_slide_43))));
			t_sample slide_405 = __m_slide_43;
			t_sample gen_421 = slide_405;
			t_sample mul_410 = (rdiv_412 * mul_411);
			__m_slide_46 = fixdenorm((__m_slide_46 + (((mul_410 > __m_slide_46) ? iup_47 : idown_48) * (mul_410 - __m_slide_46))));
			t_sample slide_406 = __m_slide_46;
			t_sample gen_420 = slide_406;
			t_sample mul_441 = (add_358 * gen_421);
			t_sample mul_438 = (m_history_12 * gen_420);
			t_sample mul_436 = (m_history_14 * ((int)1));
			t_sample mul_432 = (m_history_13 * gen_421);
			t_sample mul_434 = (m_history_11 * gen_420);
			t_sample sub_440 = (((mul_436 + mul_438) + mul_441) - (mul_434 + mul_432));
			t_sample gen_446 = sub_440;
			t_sample history_437_next_442 = fixdenorm(m_history_12);
			t_sample history_433_next_443 = fixdenorm(m_history_11);
			t_sample history_439_next_444 = fixdenorm(add_358);
			t_sample history_435_next_445 = fixdenorm(sub_440);
			t_sample mul_360 = ((gen_446 + gen_404) * ((t_sample)0.5));
			t_sample dcblock_361 = __m_dcblock_49(mul_360);
			t_sample mul_362 = (((gate_350 + gen_446) + gen_404) * scale_1334);
			t_sample div_323 = (mul_362 * ((t_sample)0.5));
			t_sample add_491 = (gate_349 + div_323);
			t_sample out2 = add_491;
			t_sample add_471 = (phasor_505 + div_501);
			t_sample mod_472 = safemod(add_471, ((int)1));
			__m_cycle_50.phase(mod_472);
			t_sample cycle_469 = __m_cycle_50(__sinedata);
			t_sample cycleindex_470 = __m_cycle_50.phase();
			t_sample add_467 = (cycle_469 + ((int)1));
			t_sample div_466 = (add_467 * ((t_sample)0.5));
			t_sample mul_468 = (div_466 * clamp_345);
			t_sample sub_1349 = (mul_468 - ((int)0));
			t_sample scale_1346 = ((safepow((sub_1349 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_473 = scale_1346;
			t_sample mtof_474 = mtof(scale_473, ((int)440));
			t_sample mul_461 = (mtof_474 * div_462);
			t_sample cos_459 = cos(mul_461);
			t_sample mul_454 = (cos_459 * (-2));
			t_sample sin_460 = sin(mul_461);
			t_sample mul_458 = (sin_460 * ((t_sample)0.5));
			t_sample div_457 = (mul_458 * ((t_sample)0.33333333333333));
			t_sample rsub_452 = (((int)1) - div_457);
			t_sample add_456 = (div_457 + ((int)1));
			t_sample rdiv_455 = safediv(((int)1), add_456);
			t_sample mul_451 = (rdiv_455 * rsub_452);
			__m_slide_51 = fixdenorm((__m_slide_51 + (((mul_451 > __m_slide_51) ? iup_52 : idown_53) * (mul_451 - __m_slide_51))));
			t_sample slide_448 = __m_slide_51;
			t_sample gen_464 = slide_448;
			t_sample mul_453 = (rdiv_455 * mul_454);
			__m_slide_54 = fixdenorm((__m_slide_54 + (((mul_453 > __m_slide_54) ? iup_55 : idown_56) * (mul_453 - __m_slide_54))));
			t_sample slide_449 = __m_slide_54;
			t_sample gen_463 = slide_449;
			t_sample mul_484 = (add_499 * gen_464);
			t_sample mul_481 = (m_history_8 * gen_463);
			t_sample mul_479 = (m_history_10 * ((int)1));
			t_sample mul_475 = (m_history_9 * gen_464);
			t_sample mul_477 = (m_history_7 * gen_463);
			t_sample sub_483 = (((mul_479 + mul_481) + mul_484) - (mul_477 + mul_475));
			t_sample gen_489 = sub_483;
			t_sample history_480_next_485 = fixdenorm(m_history_8);
			t_sample history_476_next_486 = fixdenorm(m_history_7);
			t_sample history_482_next_487 = fixdenorm(add_499);
			t_sample history_478_next_488 = fixdenorm(sub_483);
			t_sample add_529 = (phasor_505 + div_502);
			t_sample mod_530 = safemod(add_529, ((int)1));
			__m_cycle_57.phase(mod_530);
			t_sample cycle_527 = __m_cycle_57(__sinedata);
			t_sample cycleindex_528 = __m_cycle_57.phase();
			t_sample add_525 = (cycle_527 + ((int)1));
			t_sample div_524 = (add_525 * ((t_sample)0.5));
			t_sample mul_526 = (div_524 * clamp_345);
			t_sample sub_1353 = (mul_526 - ((int)0));
			t_sample scale_1350 = ((safepow((sub_1353 * ((t_sample)1)), ((int)1)) * ((int)115)) + ((int)20));
			t_sample scale_531 = scale_1350;
			t_sample mtof_532 = mtof(scale_531, ((int)440));
			t_sample mul_519 = (mtof_532 * div_520);
			t_sample cos_517 = cos(mul_519);
			t_sample mul_512 = (cos_517 * (-2));
			t_sample sin_518 = sin(mul_519);
			t_sample mul_516 = (sin_518 * ((t_sample)0.5));
			t_sample div_515 = (mul_516 * ((t_sample)0.33333333333333));
			t_sample rsub_510 = (((int)1) - div_515);
			t_sample add_514 = (div_515 + ((int)1));
			t_sample rdiv_513 = safediv(((int)1), add_514);
			t_sample mul_509 = (rdiv_513 * rsub_510);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((mul_509 > __m_slide_58) ? iup_59 : idown_60) * (mul_509 - __m_slide_58))));
			t_sample slide_506 = __m_slide_58;
			t_sample gen_522 = slide_506;
			t_sample mul_511 = (rdiv_513 * mul_512);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((mul_511 > __m_slide_61) ? iup_62 : idown_63) * (mul_511 - __m_slide_61))));
			t_sample slide_507 = __m_slide_61;
			t_sample gen_521 = slide_507;
			t_sample mul_542 = (add_499 * gen_522);
			t_sample mul_539 = (m_history_4 * gen_521);
			t_sample mul_537 = (m_history_6 * ((int)1));
			t_sample mul_533 = (m_history_5 * gen_522);
			t_sample mul_535 = (m_history_3 * gen_521);
			t_sample sub_541 = (((mul_537 + mul_539) + mul_542) - (mul_535 + mul_533));
			t_sample gen_547 = sub_541;
			t_sample history_538_next_543 = fixdenorm(m_history_4);
			t_sample history_534_next_544 = fixdenorm(m_history_3);
			t_sample history_540_next_545 = fixdenorm(add_499);
			t_sample history_536_next_546 = fixdenorm(sub_541);
			t_sample mul_447 = ((gen_547 + gen_489) * ((t_sample)0.5));
			t_sample dcblock_492 = __m_dcblock_64(mul_447);
			t_sample mul_490 = (((gate_350 + gen_547) + gen_489) * scale_1334);
			t_sample div_322 = (mul_490 * ((t_sample)0.5));
			t_sample add_493 = (gate_349 + div_322);
			t_sample out1 = add_493;
			t_sample history_498_next_1260 = fixdenorm(dcblock_361);
			t_sample history_357_next_1261 = fixdenorm(dcblock_492);
			m_history_28 = history_334_next_336;
			m_history_26 = history_330_next_338;
			m_history_27 = history_332_next_337;
			m_history_19 = history_352_next_354;
			m_history_18 = history_395_next_400;
			m_history_15 = history_393_next_403;
			m_history_16 = history_397_next_402;
			m_history_17 = history_391_next_401;
			m_history_14 = history_437_next_442;
			m_history_11 = history_435_next_445;
			m_history_12 = history_439_next_444;
			m_history_13 = history_433_next_443;
			m_history_10 = history_480_next_485;
			m_history_7 = history_478_next_488;
			m_history_8 = history_482_next_487;
			m_history_9 = history_476_next_486;
			m_history_6 = history_538_next_543;
			m_history_3 = history_536_next_546;
			m_history_4 = history_540_next_545;
			m_history_5 = history_534_next_544;
			m_history_2 = history_498_next_1260;
			m_history_1 = history_357_next_1261;
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
		m_knob3_depth_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_fb(t_param _value) {
		m_knob5_fb_21 = (_value < 0.5 ? 0.5 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_diffusion(t_param _value) {
		m_knob6_diffusion_23 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_knob4_rate(t_param _value) {
		m_knob4_rate_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_knob3_depth_20; break;
		case 1: *value = self->m_knob4_rate_24; break;
		case 2: *value = self->m_knob5_fb_21; break;
		case 3: *value = self->m_knob6_diffusion_23; break;
		case 4: *value = self->m_sw_25; break;
		case 5: *value = self->m_sw_22; break;
		
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
	// initialize parameter 0 ("m_knob3_depth_20")
	pi = self->__commonstate.params + 0;
	pi->name = "knob3_depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_depth_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_knob4_rate_24")
	pi = self->__commonstate.params + 1;
	pi->name = "knob4_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_rate_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob5_fb_21")
	pi = self->__commonstate.params + 2;
	pi->name = "knob5_fb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_fb_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.5;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob6_diffusion_23")
	pi = self->__commonstate.params + 3;
	pi->name = "knob6_diffusion";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_diffusion_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_25")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_22")
	pi = self->__commonstate.params + 5;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_22;
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
