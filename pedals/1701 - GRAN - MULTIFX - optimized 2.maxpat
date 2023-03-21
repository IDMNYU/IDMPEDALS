{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 5,
			"revision" : 3,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 474.0, 87.0, 1081.0, 647.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-47",
					"maxclass" : "scope~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 276.0, 497.0, 130.0, 130.0 ]
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-56",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 504.0, 20.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-34",
					"maxclass" : "number~",
					"mode" : 2,
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "float" ],
					"patching_rect" : [ 470.0, 447.0, 56.0, 22.0 ],
					"sig" : 0.0
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-19",
					"maxclass" : "number~",
					"mode" : 2,
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "float" ],
					"patching_rect" : [ 394.5, 447.0, 56.0, 22.0 ],
					"sig" : 0.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-43",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 240.0, 63.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-60",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 514.0, 518.0, 80.0, 22.0 ],
					"text" : "loadmess 10."
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-59",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 514.0, 556.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-57",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 142.0, 367.5, 40.0, 22.0 ],
					"text" : "*~ 30."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-48",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 471.5, 487.5, 72.0, 47.0 ],
					"text" : "testing with instrument level"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-46",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 560.0, 335.0, 39.0, 22.0 ],
					"text" : "/~ 30."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-53",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 426.0, 280.0, 47.0, 22.0 ],
					"text" : "sw3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-54",
					"items" : [ "center", ",", "left", ",", "right" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 426.0, 217.0, 100.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-55",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 426.0, 250.0, 110.0, 22.0 ],
					"text" : "scale 0 2 0.25 0.75"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-50",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 314.5, 280.0, 47.0, 22.0 ],
					"text" : "sw2 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-51",
					"items" : [ "center", ",", "left", ",", "right" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 314.5, 217.0, 100.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-52",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 314.5, 250.0, 110.0, 22.0 ],
					"text" : "scale 0 2 0.25 0.75"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-49",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 203.0, 280.0, 47.0, 22.0 ],
					"text" : "sw1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-45",
					"items" : [ "center", ",", "left", ",", "right" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 203.0, 217.0, 100.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-44",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 203.0, 250.0, 110.0, 22.0 ],
					"text" : "scale 0 2 0.25 0.75"
				}

			}
, 			{
				"box" : 				{
					"floatoutput" : 1,
					"id" : "obj-6",
					"maxclass" : "dial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 538.0, 217.0, 40.0, 40.0 ],
					"size" : 1.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 538.0, 266.0, 83.0, 22.0 ],
					"text" : "expression $1"
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 1,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-31",
					"lockeddragscroll" : 0,
					"lockedsize" : 0,
					"maxclass" : "bpatcher",
					"name" : "testinput_bpatch.maxpat",
					"numinlets" : 0,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 632.0, 8.0, 386.0, 300.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-21",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 543.0, 46.0, 80.0, 22.0 ],
					"text" : "loadmess 0.5"
				}

			}
, 			{
				"box" : 				{
					"floatoutput" : 1,
					"id" : "obj-39",
					"maxclass" : "dial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 433.0, 110.0, 40.0, 40.0 ],
					"size" : 1.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-40",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 433.0, 161.0, 58.0, 22.0 ],
					"text" : "knob6 $1"
				}

			}
, 			{
				"box" : 				{
					"floatoutput" : 1,
					"id" : "obj-41",
					"maxclass" : "dial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 366.0, 110.0, 40.0, 40.0 ],
					"size" : 1.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-42",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 366.0, 161.0, 58.0, 22.0 ],
					"text" : "knob5 $1"
				}

			}
, 			{
				"box" : 				{
					"floatoutput" : 1,
					"id" : "obj-35",
					"maxclass" : "dial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 303.5, 110.0, 40.0, 40.0 ],
					"size" : 1.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 303.5, 161.0, 58.0, 22.0 ],
					"text" : "knob4 $1"
				}

			}
, 			{
				"box" : 				{
					"floatoutput" : 1,
					"id" : "obj-37",
					"maxclass" : "dial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 433.0, 18.0, 40.0, 40.0 ],
					"size" : 1.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 433.0, 69.0, 58.0, 22.0 ],
					"text" : "knob3 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 190.0, 18.0, 69.0, 20.0 ],
					"text" : "right switch"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-32",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 59.0, 17.0, 61.0, 20.0 ],
					"text" : "left switch"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 61.0, 86.0, 22.0, 22.0 ],
					"text" : "t 0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 61.0, 56.0, 41.0, 22.0 ],
					"text" : "del 10"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 32.0, 63.0, 22.0, 22.0 ],
					"text" : "t 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-29",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 30.0, 18.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 30.0, 111.0, 92.0, 22.0 ],
					"text" : "footswitch_1 $1"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-25",
					"maxclass" : "number~",
					"mode" : 2,
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "float" ],
					"patching_rect" : [ 471.5, 380.0, 56.0, 22.0 ],
					"sig" : 0.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 185.0, 86.0, 22.0, 22.0 ],
					"text" : "t 0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 185.0, 56.0, 41.0, 22.0 ],
					"text" : "del 10"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 156.0, 63.0, 22.0, 22.0 ],
					"text" : "t 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-20",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 154.0, 18.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 154.0, 111.0, 92.0, 22.0 ],
					"text" : "footswitch_2 $1"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-15",
					"maxclass" : "number~",
					"mode" : 2,
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "float" ],
					"patching_rect" : [ 337.5, 380.0, 56.0, 22.0 ],
					"sig" : 0.0
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-14",
					"maxclass" : "number~",
					"mode" : 2,
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "float" ],
					"patching_rect" : [ 274.5, 380.0, 56.0, 22.0 ],
					"sig" : 0.0
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-10",
					"maxclass" : "number~",
					"mode" : 2,
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "float" ],
					"patching_rect" : [ 211.5, 380.0, 56.0, 22.0 ],
					"sig" : 0.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 815.0, 462.0, 219.0, 20.0 ],
					"text" : "BOOT hold THEN RESET push/release"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-5",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 632.0, 326.0, 58.0, 22.0 ],
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 632.0, 360.0, 67.0, 22.0 ],
					"text" : "delay 2000"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-3",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 632.0, 392.0, 294.0, 22.0 ],
					"text" : "target petal_125b_sm, samplerate 96kHz, blocksize 8"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"lastchannelcount" : 0,
					"maxclass" : "live.gain~",
					"numinlets" : 2,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "", "float", "list" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 140.5, 428.0, 48.0, 136.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "live.gain~",
							"parameter_mmax" : 6.0,
							"parameter_mmin" : -70.0,
							"parameter_shortname" : "live.gain~",
							"parameter_type" : 0,
							"parameter_unitstyle" : 4
						}

					}
,
					"varname" : "live.gain~"
				}

			}
, 			{
				"box" : 				{
					"args" : [ "petal" ],
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-83",
					"lockeddragscroll" : 0,
					"lockedsize" : 0,
					"maxclass" : "bpatcher",
					"name" : "oopsy.maxpat",
					"numinlets" : 1,
					"numoutlets" : 0,
					"offset" : [ 0.0, 0.0 ],
					"patching_rect" : [ 632.0, 437.0, 173.0, 131.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 632.0, 579.0, 139.0, 20.0 ],
					"text" : "IDMPEDALS test tones"
				}

			}
, 			{
				"box" : 				{
					"floatoutput" : 1,
					"id" : "obj-12",
					"maxclass" : "dial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 370.5, 18.0, 40.0, 40.0 ],
					"size" : 1.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 370.5, 69.0, 58.0, 22.0 ],
					"text" : "knob2 $1"
				}

			}
, 			{
				"box" : 				{
					"floatoutput" : 1,
					"id" : "obj-11",
					"maxclass" : "dial",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 303.5, 18.0, 40.0, 40.0 ],
					"size" : 1.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 303.5, 69.0, 58.0, 22.0 ],
					"text" : "knob1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 142.0, 580.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 11,
					"outlettype" : [ "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 5,
							"revision" : 3,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "dsp.gen",
						"rect" : [ 251.0, 87.0, 1181.0, 898.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-181",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1271.557389736175537, 702.524590492248535, 100.0, 22.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-177",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1235.057389736175537, 733.524590492248535, 37.0, 22.0 ],
									"text" : "* 500"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-174",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1171.557389736175537, 763.0, 39.0, 22.0 ],
									"text" : "0.999"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-172",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1320.0, 837.0, 44.0, 22.0 ],
									"text" : "history"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 444.5, 1022.0, 23.0, 22.0 ],
									"text" : "* 1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-114",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 858.75, 848.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-121",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 720.75, 848.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-122",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 582.75, 848.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-131",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 444.75, 848.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-221",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 233.0, 743.0, 87.0, 22.0 ],
									"text" : "history ampvar"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-220",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 233.0, 708.0, 67.0, 22.0 ],
									"text" : "clamp 0. 1."
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-219",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 232.0, 673.0, 90.0, 22.0 ],
									"text" : "scale 0. 1. 1. 0."
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-218",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 265.057389736175537, 613.5, 57.0, 47.0 ],
									"text" : "variation (left of the dial)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-217",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 102.0, 638.5, 38.0, 22.0 ],
									"text" : "fold 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-215",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 102.0, 603.5, 23.0, 22.0 ],
									"text" : "* 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-208",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1635.0, 1335.0, 55.0, 22.0 ],
									"text" : "1920000"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-206",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1510.0, 1338.0, 96.0, 22.0 ],
									"text" : "history sampmin"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-189",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1438.057389736175537, 1105.524590492248535, 129.0, 22.0 ],
									"text" : "expr 1.0-(sqrt(1.0-in1))"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-84",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1520.557389736175537, 1229.524590492248535, 28.0, 22.0 ],
									"text" : "abs"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-85",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1586.057389736175537, 1092.524590492248535, 67.0, 22.0 ],
									"text" : "clamp 0. 1."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-87",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1586.057389736175537, 1059.524590492248535, 90.0, 22.0 ],
									"text" : "scale 0. 1. 1. 0."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-88",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1560.057389736175537, 1229.524590492248535, 29.5, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-89",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1483.557389736175537, 1027.524590492248535, 38.0, 22.0 ],
									"text" : "fold 1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-91",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1483.557389736175537, 983.524590492248535, 23.0, 22.0 ],
									"text" : "* 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-94",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1520.557389736175537, 1295.524590492248535, 56.0, 20.0 ],
									"text" : "dirty saw",
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-96",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1483.557389736175537, 1291.524590492248535, 29.5, 22.0 ],
									"text" : "-"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-97",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1520.557389736175537, 1198.524590492248535, 37.0, 22.0 ],
									"text" : "noise"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-98",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1520.557389736175537, 1261.524590492248535, 29.5, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-99",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1685.057389736175537, 1059.524590492248535, 57.0, 47.0 ],
									"text" : "variation (left of the dial)",
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-182",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1483.557389736175537, 1059.524590492248535, 29.0, 22.0 ],
									"text" : "!- 1."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-79",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1150.557389736175537, 798.524590492248535, 40.0, 22.0 ],
									"text" : "mix"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-63",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 861.0, 564.0, 37.0, 22.0 ],
									"text" : "s env"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-60",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1181.557389736175537, 994.524590492248535, 43.0, 20.0 ],
									"text" : "trigger"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-53",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1235.057389736175537, 702.524590492248535, 29.0, 22.0 ],
									"text" : "< 1."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-42",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1132.557389736175537, 703.524590492248535, 38.0, 22.0 ],
									"text" : "fold 1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-31",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1132.557389736175537, 663.524590492248535, 23.0, 22.0 ],
									"text" : "* 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-28",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1287.557389736175537, 1225.524590492248535, 84.0, 22.0 ],
									"text" : "out 11 debug2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-19",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1197.557389736175537, 1225.524590492248535, 79.0, 22.0 ],
									"text" : "out 10 debug"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-216",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1169.557389736175537, 864.524590492248535, 56.0, 20.0 ],
									"text" : "dirty saw"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-214",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1132.557389736175537, 860.524590492248535, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-212",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1287.557389736175537, 766.524590492248535, 37.0, 22.0 ],
									"text" : "noise"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-210",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1169.557389736175537, 830.524590492248535, 29.5, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-188",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1334.057389736175537, 702.524590492248535, 57.0, 47.0 ],
									"text" : "variation (left of the dial)"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-187",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 298.0, 1235.0, 40.0, 22.0 ],
									"text" : "* 1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-74",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1132.557389736175537, 959.524590492248535, 48.0, 22.0 ],
									"text" : "change"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-52",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1132.557389736175537, 993.524590492248535, 33.0, 22.0 ],
									"text" : "== 1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-41",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1132.557389736175537, 924.524590492248535, 36.0, 22.0 ],
									"text" : "> 0.5"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-38",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1132.557389736175537, 894.524590492248535, 45.0, 22.0 ],
									"text" : "phasor"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-33",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 171.5, 136.0, 91.0, 20.0 ],
									"text" : "twenty seconds"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-29",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1304.0, 467.0, 85.0, 20.0 ],
									"text" : "min grain size"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-27",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1280.0, 467.0, 19.0, 22.0 ],
									"text" : "5"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-21",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1280.0, 501.0, 70.0, 22.0 ],
									"text" : "mstosamps"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-14",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1280.0, 549.0, 96.0, 22.0 ],
									"text" : "history sampmin"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 531.416666666666629, 431.0, 80.0, 22.0 ],
									"text" : "history buflen"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-213",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1134.557389736175537, 604.524590492248535, 47.0, 20.0 ],
									"text" : "density"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-211",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1299.333333333333258, 941.524590492248535, 131.0, 20.0 ],
									"text" : "grain buffer max length",
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-209",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 887.5, 496.0, 58.0, 20.0 ],
									"text" : "threshold"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-207",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 160.0, 485.0, 81.0, 20.0 ],
									"text" : "amp / wet dry"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-205",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1299.333333333333258, 1099.524590492248535, 80.0, 22.0 ],
									"text" : "history buflen"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-204",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1467.557389736175537, 1403.524590492248535, 90.0, 22.0 ],
									"text" : "history grainlen"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-61",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 59.5, 1062.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-44",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1467.557389736175537, 1338.524590492248535, 29.5, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-48",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 293.5, 1277.0, 49.0, 22.0 ],
									"text" : "dcblock"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-59",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 160.0, 691.0, 29.0, 22.0 ],
									"text" : "sqrt"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-65",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 283.0, 1321.0, 29.5, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-66",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 44.0, 820.0, 29.5, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-67",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 160.0, 514.0, 29.0, 22.0 ],
									"text" : "r p4"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-68",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 102.0, 728.5, 29.0, 22.0 ],
									"text" : "sqrt"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-69",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 102.0, 686.5, 29.0, 22.0 ],
									"text" : "!- 1."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-32",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1132.557389736175537, 733.524590492248535, 97.0, 22.0 ],
									"text" : "scale 0. 1. 15. 1."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-70",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 763.5, 439.0, 33.0, 22.0 ],
									"text" : "* 30."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-159",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 401.5, 841.0, 23.0, 22.0 ],
									"text" : "* 1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-147",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 915.75, 789.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-102",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 777.75, 789.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-149",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 639.75, 789.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-105",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 501.75, 789.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-143",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 865.75, 728.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-144",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 727.75, 728.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-145",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 589.75, 728.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-146",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 451.75, 728.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"id" : "obj-132",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1132.557389736175537, 632.524590492248535, 29.0, 22.0 ],
									"text" : "r p1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-130",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1483.557389736175537, 919.524590492248535, 82.0, 20.0 ],
									"text" : "grain duration",
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-107",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1467.557389736175537, 1372.524590492248535, 222.0, 22.0 ],
									"text" : "clip"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-109",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1483.557389736175537, 941.524590492248535, 29.0, 22.0 ],
									"text" : "r p2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-111",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 815.75, 667.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-112",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 677.75, 667.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-113",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 539.75, 667.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-170",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1376.0, 1027.524590492248535, 41.0, 20.0 ],
									"text" : "length",
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"id" : "obj-173",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 401.75, 667.5, 70.0, 22.0 ],
									"text" : "grainvoice2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-175",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 386.166666666666629, 435.0, 19.0, 22.0 ],
									"text" : "-1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-176",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 368.166666666666629, 475.0, 40.0, 22.0 ],
									"text" : "?"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-178",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1299.333333333333258, 1000.524590492248535, 129.0, 22.0 ],
									"text" : "expr 1.0-(sqrt(1.0-in1))"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-179",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1299.333333333333258, 971.524590492248535, 29.0, 22.0 ],
									"text" : "r p6"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-180",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1299.333333333333258, 1046.524590492248535, 63.0, 22.0 ],
									"text" : "* 1920000"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-183",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 505.75, 538.0, 44.0, 22.0 ],
									"text" : "history"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-184",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 505.75, 505.0, 33.0, 22.0 ],
									"text" : "== 1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-185",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 505.75, 476.0, 29.5, 22.0 ],
									"text" : ">="
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059509769082069, 0.501929938793182, 0.998454749584198, 1.0 ],
									"id" : "obj-186",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 32.416666666666629, 136.0, 135.0, 22.0 ],
									"text" : "data capture 1920000 1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-190",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 419.5, 475.0, 19.0, 22.0 ],
									"text" : "0"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-191",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 414.416666666666629, 396.0, 19.0, 22.0 ],
									"text" : "1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-192",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 765.833333333333371, 523.0, 53.0, 22.0 ],
									"text" : "clip 0. 1."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-193",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 882.833333333333371, 403.0, 29.0, 22.0 ],
									"text" : "100"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-194",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 881.5, 444.0, 70.0, 22.0 ],
									"text" : "mstosamps"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-195",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 822.833333333333371, 404.0, 22.0, 22.0 ],
									"text" : "10"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-196",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 808.833333333333371, 444.0, 70.0, 22.0 ],
									"text" : "mstosamps"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-20",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 763.5, 481.0, 40.0, 22.0 ],
									"text" : "slide"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-197",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 452.416666666666629, 431.0, 77.0, 33.0 ],
									"text" : "segment size counter"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-198",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 414.416666666666629, 431.0, 34.0, 22.0 ],
									"text" : "+="
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-199",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 763.5, 399.0, 28.0, 22.0 ],
									"text" : "abs"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-200",
									"maxclass" : "newobj",
									"numinlets" : 4,
									"numoutlets" : 0,
									"patching_rect" : [ 342.499999999999943, 533.0, 96.0, 22.0 ],
									"text" : "poke capture"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-202",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 59.5, 1114.0, 35.0, 22.0 ],
									"text" : "out 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-203",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 102.0, 225.0, 28.0, 22.0 ],
									"text" : "in 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-90",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 366.166666666666629, 334.0, 42.0, 20.0 ],
									"text" : "freeze"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-86",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 368.166666666666629, 362.0, 113.0, 22.0 ],
									"text" : "param footswitch_2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-123",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1108.5, 162.0, 39.0, 22.0 ],
									"text" : "s sw2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059509769082069, 0.501929938793182, 0.998454749584198, 1.0 ],
									"id" : "obj-103",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1322.0, 127.0, 32.0, 22.0 ],
									"text" : "mtof"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059509769082069, 0.501929938793182, 0.998454749584198, 1.0 ],
									"id" : "obj-104",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1322.0, 87.0, 97.0, 22.0 ],
									"text" : "scale 0. 1. 65 97"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-75",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1322.0, 162.0, 76.0, 22.0 ],
									"text" : "s expression"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-9",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1156.5, 162.0, 39.0, 22.0 ],
									"text" : "s sw3"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.064094848930836, 0.501830697059631, 0.501977205276489, 1.0 ],
									"id" : "obj-51",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 594.0, 85.0, 31.0, 22.0 ],
									"text" : "s p6"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-50",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 480.0, 84.0, 31.0, 22.0 ],
									"text" : "s p5"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.0, 0.000011786818504, 0.501965880393982, 1.0 ],
									"id" : "obj-17",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 257.0, 85.0, 31.0, 22.0 ],
									"text" : "s p3"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962959766388, 0.000045776367188, 0.501965701580048, 1.0 ],
									"id" : "obj-15",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 366.0, 87.0, 31.0, 22.0 ],
									"text" : "s p4"
								}

							}
, 							{
								"box" : 								{
									"code" : "r = 0;\r\ng = 0;\r\nb = 0;\r\n\r\nif(in1==1) r, g, b = 1, 0, 0;\r\nelse if(in1==2) r, g, b = 1., 0.5, 0;\r\nelse if(in1==3) r, g, b = 0.5, 1, 0;\r\nelse if(in1==4) r, g, b = 0, 1, 0;\r\nelse if(in1==5) r, g, b = 0, 1, 0.5;\r\nelse if(in1==6) r, g, b = 1, 0.5, 1;\r\nelse if(in1==7) r, g, b = 0., 0., 1;\r\nelse if(in1==8) r, g, b = 0.5, 0, 1;\r\nelse if(in1==9) r, g, b = 1, 0, 1;\r\n\r\nout1, out2, out3 = r, g, b;",
									"fontface" : 0,
									"fontname" : "Menlo",
									"fontsize" : 12.0,
									"id" : "obj-40",
									"maxclass" : "codebox",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "" ],
									"patching_rect" : [ 1418.0, 274.0, 390.0, 200.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-39",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1418.0, 241.0, 39.0, 22.0 ],
									"text" : "r pgm"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-37",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1277.0, 391.0, 41.0, 22.0 ],
									"text" : "s pgm"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.065395027399063, 0.501824975013733, 0.251003384590149, 1.0 ],
									"id" : "obj-35",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 141.0, 86.100000000000023, 31.0, 22.0 ],
									"text" : "s p2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-30",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 28.0, 80.0, 31.0, 22.0 ],
									"text" : "s p1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1277.0, 354.0, 26.0, 22.0 ],
									"text" : "+ 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1277.0, 321.0, 92.0, 22.0 ],
									"text" : "accum @max 9"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-78",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 754.0, 93.5, 63.0, 20.0 ],
									"text" : "scale it up"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-76",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 839.0, 52.0, 52.0, 20.0 ],
									"text" : "lowpass"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-73",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1066.0, 279.0, 168.0, 20.0 ],
									"text" : "count 0 then 1 then 0 then 1..."
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-72",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1036.0, 245.600000000000023, 201.0, 20.0 ],
									"text" : "listen to the stomps not the releases"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-11",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1021.0, 201.0, 234.0, 33.0 ],
									"text" : "sends out a 1 when there's a rising switch and -1 when there's a falling switch"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-151",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1322.0, 49.0, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-150",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1322.0, 12.5, 104.0, 22.0 ],
									"text" : "param expression"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-148",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1277.0, 238.5, 48.0, 22.0 ],
									"text" : "change"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-142",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1277.0, 279.399999999999977, 61.0, 22.0 ],
									"text" : "clamp 0 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-124",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1206.5, 123.5, 70.0, 20.0 ],
									"text" : "gives  1 2 3"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-125",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1231.5, 13.0, 79.0, 20.0 ],
									"text" : "0.5 0.25 0.75"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-126",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1156.5, 123.5, 39.0, 22.0 ],
									"text" : "round"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-127",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1156.5, 93.5, 23.0, 22.0 ],
									"text" : "* 4"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-128",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1156.5, 52.0, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-129",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1156.5, 13.0, 67.0, 22.0 ],
									"text" : "param sw3"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-115",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1023.0, 123.5, 70.0, 20.0 ],
									"text" : "gives  1 2 3"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-116",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1048.0, 13.0, 79.0, 20.0 ],
									"text" : "0.5 0.25 0.75"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-117",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 973.0, 123.5, 39.0, 22.0 ],
									"text" : "round"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-118",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 973.0, 93.5, 23.0, 22.0 ],
									"text" : "* 4"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-119",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 973.0, 52.0, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-120",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 973.0, 13.0, 67.0, 22.0 ],
									"text" : "param sw2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-108",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 726.0, 161.5, 39.0, 22.0 ],
									"text" : "s sw1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-101",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 776.0, 123.5, 70.0, 20.0 ],
									"text" : "gives  1 2 3"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-95",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 805.0, 13.0, 79.0, 20.0 ],
									"text" : "0.5 0.25 0.75"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-93",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 726.0, 123.5, 39.0, 22.0 ],
									"text" : "round"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-92",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 726.0, 93.5, 23.0, 22.0 ],
									"text" : "* 4"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-80",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 726.0, 52.0, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-77",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 726.0, 13.0, 67.0, 22.0 ],
									"text" : "param sw1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 765.833333333333371, 565.0, 91.0, 22.0 ],
									"text" : "out 7 led3_blue"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-22",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1411.5, 195.0, 99.0, 22.0 ],
									"text" : "out 6 led3_green"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.064094848930836, 0.501830697059631, 0.501977205276489, 1.0 ],
									"id" : "obj-47",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 594.0, 49.0, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth3"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.064094848930836, 0.501830697059631, 0.501977205276489, 1.0 ],
									"id" : "obj-49",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 594.0, 16.0, 79.0, 22.0 ],
									"text" : "param knob6"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-54",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 480.0, 49.0, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth3"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"id" : "obj-56",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 480.0, 16.0, 79.0, 22.0 ],
									"text" : "param knob5"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-57",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1436.0, 127.0, 85.0, 22.0 ],
									"text" : "out 5 led3_red"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962959766388, 0.000045776367188, 0.501965701580048, 1.0 ],
									"id" : "obj-62",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 366.0, 49.0, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth3"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962959766388, 0.000045776367188, 0.501965701580048, 1.0 ],
									"id" : "obj-64",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 366.0, 16.0, 79.0, 22.0 ],
									"text" : "param knob4"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-7",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 972.0, 317.5, 26.0, 22.0 ],
									"text" : "!- 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1603.5, 490.0, 91.0, 22.0 ],
									"text" : "out 4 led1_blue"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1709.0, 490.0, 99.0, 22.0 ],
									"text" : "out 3 led1_green"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.0, 0.000011786818504, 0.501965880393982, 1.0 ],
									"id" : "obj-43",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 256.0, 49.0, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth3"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.0, 0.000011786818504, 0.501965880393982, 1.0 ],
									"id" : "obj-45",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 256.0, 16.0, 79.0, 22.0 ],
									"text" : "param knob3"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.065395027399063, 0.501824975013733, 0.251003384590149, 1.0 ],
									"id" : "obj-34",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 141.0, 49.0, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth3"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.065395027399063, 0.501824975013733, 0.251003384590149, 1.0 ],
									"id" : "obj-36",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 141.0, 16.0, 79.0, 22.0 ],
									"text" : "param knob2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-23",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1036.0, 348.5, 65.0, 22.0 ],
									"text" : "out 9 relay"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-24",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 972.0, 245.600000000000023, 61.0, 22.0 ],
									"text" : "clamp 0 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-25",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 972.0, 212.0, 48.0, 22.0 ],
									"text" : "change"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 972.0, 162.0, 113.0, 22.0 ],
									"text" : "param footswitch_1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-3",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 972.0, 279.0, 92.0, 22.0 ],
									"text" : "accum @max 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-26",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1418.0, 490.0, 85.0, 22.0 ],
									"text" : "out 2 led1_red"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-18",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 972.0, 348.5, 61.0, 22.0 ],
									"text" : "out 8 led2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-16",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 28.0, 49.0, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth3"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"id" : "obj-13",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 28.0, 16.0, 79.0, 22.0 ],
									"text" : "param knob1"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-187", 0 ],
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-37", 0 ],
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-147", 0 ],
									"source" : [ "obj-102", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-159", 0 ],
									"source" : [ "obj-102", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-75", 0 ],
									"source" : [ "obj-103", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059509769082069, 0.501929938793182, 0.998454749584198, 1.0 ],
									"destination" : [ "obj-103", 0 ],
									"source" : [ "obj-104", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-149", 0 ],
									"source" : [ "obj-105", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-159", 0 ],
									"source" : [ "obj-105", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-204", 0 ],
									"source" : [ "obj-107", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-91", 0 ],
									"source" : [ "obj-109", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-146", 0 ],
									"source" : [ "obj-111", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-159", 0 ],
									"source" : [ "obj-111", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-111", 0 ],
									"source" : [ "obj-112", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-159", 0 ],
									"source" : [ "obj-112", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-112", 0 ],
									"source" : [ "obj-113", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-159", 0 ],
									"source" : [ "obj-113", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-114", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-123", 0 ],
									"source" : [ "obj-117", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-117", 0 ],
									"source" : [ "obj-118", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-118", 0 ],
									"source" : [ "obj-119", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-119", 0 ],
									"source" : [ "obj-120", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-121", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-114", 0 ],
									"source" : [ "obj-121", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-122", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-121", 0 ],
									"source" : [ "obj-122", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"source" : [ "obj-126", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-126", 0 ],
									"source" : [ "obj-127", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-127", 0 ],
									"source" : [ "obj-128", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-128", 0 ],
									"source" : [ "obj-129", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-16", 0 ],
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-131", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-122", 0 ],
									"source" : [ "obj-131", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-31", 0 ],
									"source" : [ "obj-132", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-142", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-105", 0 ],
									"source" : [ "obj-143", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-159", 0 ],
									"source" : [ "obj-143", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-143", 0 ],
									"source" : [ "obj-144", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-159", 0 ],
									"source" : [ "obj-144", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-144", 0 ],
									"source" : [ "obj-145", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-159", 0 ],
									"source" : [ "obj-145", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-145", 0 ],
									"source" : [ "obj-146", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-159", 0 ],
									"source" : [ "obj-146", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-131", 0 ],
									"source" : [ "obj-147", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-159", 0 ],
									"source" : [ "obj-147", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-142", 0 ],
									"source" : [ "obj-148", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-102", 0 ],
									"source" : [ "obj-149", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-159", 0 ],
									"source" : [ "obj-149", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-151", 0 ],
									"source" : [ "obj-150", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-104", 0 ],
									"source" : [ "obj-151", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-187", 0 ],
									"source" : [ "obj-159", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-79", 1 ],
									"source" : [ "obj-172", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-113", 0 ],
									"source" : [ "obj-173", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-159", 0 ],
									"source" : [ "obj-173", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-79", 2 ],
									"source" : [ "obj-174", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-176", 1 ],
									"source" : [ "obj-175", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-200", 1 ],
									"source" : [ "obj-176", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-210", 1 ],
									"source" : [ "obj-177", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-180", 0 ],
									"source" : [ "obj-178", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-178", 0 ],
									"source" : [ "obj-179", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-205", 0 ],
									"order" : 1,
									"source" : [ "obj-180", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-44", 0 ],
									"order" : 0,
									"source" : [ "obj-180", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-189", 0 ],
									"source" : [ "obj-182", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-198", 1 ],
									"source" : [ "obj-183", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-183", 0 ],
									"source" : [ "obj-184", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-184", 0 ],
									"source" : [ "obj-185", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-48", 0 ],
									"source" : [ "obj-187", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-88", 0 ],
									"order" : 0,
									"source" : [ "obj-189", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-96", 0 ],
									"order" : 1,
									"source" : [ "obj-189", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-200", 3 ],
									"order" : 0,
									"source" : [ "obj-190", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-200", 2 ],
									"order" : 1,
									"source" : [ "obj-190", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-198", 0 ],
									"source" : [ "obj-191", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"order" : 1,
									"source" : [ "obj-192", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-63", 0 ],
									"order" : 0,
									"source" : [ "obj-192", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-194", 0 ],
									"source" : [ "obj-193", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-20", 2 ],
									"source" : [ "obj-194", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-196", 0 ],
									"source" : [ "obj-195", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-20", 1 ],
									"source" : [ "obj-196", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-176", 2 ],
									"order" : 1,
									"source" : [ "obj-198", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-185", 0 ],
									"order" : 0,
									"source" : [ "obj-198", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-70", 0 ],
									"source" : [ "obj-199", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-192", 0 ],
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
									"destination" : [ "obj-199", 0 ],
									"order" : 0,
									"source" : [ "obj-203", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
									"destination" : [ "obj-200", 0 ],
									"order" : 1,
									"source" : [ "obj-203", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
									"destination" : [ "obj-66", 1 ],
									"order" : 2,
									"source" : [ "obj-203", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-107", 1 ],
									"source" : [ "obj-206", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-107", 2 ],
									"source" : [ "obj-208", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-14", 0 ],
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-214", 1 ],
									"source" : [ "obj-210", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-79", 0 ],
									"source" : [ "obj-212", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-38", 0 ],
									"source" : [ "obj-214", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-217", 0 ],
									"order" : 1,
									"source" : [ "obj-215", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-219", 0 ],
									"order" : 0,
									"source" : [ "obj-215", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-59", 0 ],
									"order" : 0,
									"source" : [ "obj-217", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-69", 0 ],
									"order" : 1,
									"source" : [ "obj-217", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-220", 0 ],
									"source" : [ "obj-219", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-221", 0 ],
									"source" : [ "obj-220", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-24", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 0 ],
									"source" : [ "obj-25", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-21", 0 ],
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-23", 0 ],
									"order" : 0,
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"order" : 1,
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-42", 0 ],
									"order" : 1,
									"source" : [ "obj-31", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-53", 0 ],
									"order" : 0,
									"source" : [ "obj-31", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-214", 0 ],
									"source" : [ "obj-32", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065395027399063, 0.501824975013733, 0.251003384590149, 1.0 ],
									"destination" : [ "obj-35", 0 ],
									"source" : [ "obj-34", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065395027399063, 0.501824975013733, 0.251003384590149, 1.0 ],
									"destination" : [ "obj-34", 0 ],
									"source" : [ "obj-36", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-41", 0 ],
									"source" : [ "obj-38", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-40", 0 ],
									"source" : [ "obj-39", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-185", 1 ],
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 0 ],
									"source" : [ "obj-40", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-26", 0 ],
									"source" : [ "obj-40", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-40", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-74", 0 ],
									"source" : [ "obj-41", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-32", 0 ],
									"source" : [ "obj-42", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.0, 0.000011786818504, 0.501965880393982, 1.0 ],
									"destination" : [ "obj-17", 0 ],
									"source" : [ "obj-43", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-107", 0 ],
									"source" : [ "obj-44", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.0, 0.000011786818504, 0.501965880393982, 1.0 ],
									"destination" : [ "obj-43", 0 ],
									"source" : [ "obj-45", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.064094848930836, 0.501830697059631, 0.501977205276489, 1.0 ],
									"destination" : [ "obj-51", 0 ],
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059471700340509, 0.501942574977875, 0.998464584350586, 1.0 ],
									"destination" : [ "obj-65", 1 ],
									"source" : [ "obj-48", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.064094848930836, 0.501830697059631, 0.501977205276489, 1.0 ],
									"destination" : [ "obj-47", 0 ],
									"source" : [ "obj-49", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-173", 0 ],
									"midpoints" : [ 1142.057389736175537, 1017.0, 1099.0, 1017.0, 1099.0, 654.0, 411.25, 654.0 ],
									"source" : [ "obj-52", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-177", 0 ],
									"source" : [ "obj-53", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-50", 0 ],
									"source" : [ "obj-54", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-54", 0 ],
									"source" : [ "obj-56", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-65", 0 ],
									"source" : [ "obj-59", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
									"destination" : [ "obj-202", 0 ],
									"source" : [ "obj-61", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962959766388, 0.000045776367188, 0.501965701580048, 1.0 ],
									"destination" : [ "obj-15", 0 ],
									"source" : [ "obj-62", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962959766388, 0.000045776367188, 0.501965701580048, 1.0 ],
									"destination" : [ "obj-62", 0 ],
									"source" : [ "obj-64", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-61", 1 ],
									"source" : [ "obj-65", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-61", 0 ],
									"source" : [ "obj-66", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-215", 0 ],
									"source" : [ "obj-67", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-66", 0 ],
									"source" : [ "obj-68", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-68", 0 ],
									"source" : [ "obj-69", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-70", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-52", 0 ],
									"source" : [ "obj-74", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-80", 0 ],
									"source" : [ "obj-77", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-172", 0 ],
									"order" : 0,
									"source" : [ "obj-79", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.985541701316833, 0.009453415870667, 0.999180555343628, 1.0 ],
									"destination" : [ "obj-210", 0 ],
									"order" : 1,
									"source" : [ "obj-79", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-10", 0 ],
									"source" : [ "obj-8", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-92", 0 ],
									"source" : [ "obj-80", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-98", 0 ],
									"source" : [ "obj-84", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-88", 1 ],
									"source" : [ "obj-85", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501957535743713, 0.50194239616394, 0.014744119718671, 1.0 ],
									"destination" : [ "obj-176", 0 ],
									"source" : [ "obj-86", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-85", 0 ],
									"source" : [ "obj-87", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-98", 1 ],
									"source" : [ "obj-88", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-182", 0 ],
									"source" : [ "obj-89", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-87", 0 ],
									"order" : 0,
									"source" : [ "obj-91", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-89", 0 ],
									"order" : 1,
									"source" : [ "obj-91", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-93", 0 ],
									"source" : [ "obj-92", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-108", 0 ],
									"source" : [ "obj-93", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-44", 1 ],
									"source" : [ "obj-96", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-84", 0 ],
									"source" : [ "obj-97", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501962661743164, 0.0, 0.008127626031637, 1.0 ],
									"destination" : [ "obj-96", 1 ],
									"source" : [ "obj-98", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 140.5, 334.0, 397.285714285714334, 22.0 ],
					"saved_object_attributes" : 					{
						"exportfolder" : "Macintosh HD:/Users/lukedubois/Documents/TEACHING/nyu/idm/soundstudio/IDMPEDALS/pedals/",
						"exportname" : "Granular_Multifx"
					}
,
					"text" : "gen~ @title Granular_Multifx",
					"varname" : "Granular_Multifx"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"source" : [ "obj-1", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"source" : [ "obj-1", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"order" : 0,
					"source" : [ "obj-1", 9 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"source" : [ "obj-1", 7 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"source" : [ "obj-1", 10 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-47", 0 ],
					"order" : 1,
					"source" : [ "obj-1", 9 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-57", 0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"order" : 1,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 0 ],
					"order" : 0,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"hidden" : 1,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 1 ],
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"order" : 1,
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"order" : 0,
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"hidden" : 1,
					"order" : 5,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"hidden" : 1,
					"order" : 2,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"hidden" : 1,
					"order" : 4,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"hidden" : 1,
					"order" : 1,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"hidden" : 1,
					"order" : 0,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"hidden" : 1,
					"order" : 3,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"order" : 0,
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"order" : 1,
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-83", 0 ],
					"hidden" : 1,
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-46", 0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 0 ],
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"source" : [ "obj-41", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-49", 0 ],
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-44", 0 ],
					"source" : [ "obj-45", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-46", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-49", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"hidden" : 1,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-50", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-52", 0 ],
					"source" : [ "obj-51", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-50", 0 ],
					"source" : [ "obj-52", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-55", 0 ],
					"source" : [ "obj-54", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"source" : [ "obj-55", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 1 ],
					"order" : 0,
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"order" : 1,
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-46", 1 ],
					"order" : 0,
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-57", 1 ],
					"order" : 1,
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 0 ],
					"source" : [ "obj-60", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-8", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-2" : [ "live.gain~", "live.gain~", 0 ],
			"obj-83::obj-32" : [ "live.text[2]", "FILTER", 0 ],
			"obj-83::obj-33" : [ "live.text[1]", "FILTER", 0 ],
			"obj-83::obj-34" : [ "live.text[3]", "FILTER", 0 ],
			"parameterbanks" : 			{

			}
,
			"inherited_shortname" : 1
		}
,
		"dependency_cache" : [ 			{
				"name" : "grainvoice2.gendsp",
				"bootpath" : "~/Documents/TEACHING/nyu/idm/soundstudio/IDMPEDALS/pedals",
				"patcherrelativepath" : ".",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.ctrl.smooth2.gendsp",
				"bootpath" : "~/Documents/Max 8/Packages/oopsy/code",
				"patcherrelativepath" : "../../../../../../Max 8/Packages/oopsy/code",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.ctrl.smooth3.gendsp",
				"bootpath" : "~/Documents/Max 8/Packages/oopsy/code",
				"patcherrelativepath" : "../../../../../../Max 8/Packages/oopsy/code",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.maxpat",
				"bootpath" : "~/Documents/Max 8/Packages/oopsy/patchers",
				"patcherrelativepath" : "../../../../../../Max 8/Packages/oopsy/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.node4max.js",
				"bootpath" : "~/Documents/Max 8/Packages/oopsy/javascript",
				"patcherrelativepath" : "../../../../../../Max 8/Packages/oopsy/javascript",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.snoop.js",
				"bootpath" : "~/Documents/Max 8/Packages/oopsy/javascript",
				"patcherrelativepath" : "../../../../../../Max 8/Packages/oopsy/javascript",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "testinput_bpatch.maxpat",
				"bootpath" : "~/Documents/TEACHING/nyu/idm/soundstudio/IDMPEDALS/pedals",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
 ],
		"autosave" : 0,
		"styles" : [ 			{
				"name" : "AudioStatus_Menu",
				"default" : 				{
					"bgfillcolor" : 					{
						"angle" : 270.0,
						"autogradient" : 0,
						"color" : [ 0.294118, 0.313726, 0.337255, 1 ],
						"color1" : [ 0.454902, 0.462745, 0.482353, 0.0 ],
						"color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
						"proportion" : 0.39,
						"type" : "color"
					}

				}
,
				"parentstyle" : "",
				"multi" : 0
			}
 ]
	}

}
