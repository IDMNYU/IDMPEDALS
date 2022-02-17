{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 2,
			"revision" : 2,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 300.0, 223.0, 1073.0, 791.0 ],
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
		"subpatcher_template" : "newtemplate",
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 831.0, 221.0, 197.0, 20.0 ],
					"text" : "vocoder runs at 48kHz on the daisy"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 684.0, 725.0, 94.0, 20.0 ],
					"text" : "for pedal testing"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 628.200000000000045, 726.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 1,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-14",
					"lockeddragscroll" : 0,
					"lockedsize" : 0,
					"maxclass" : "bpatcher",
					"name" : "testinput_bpatch.maxpat",
					"numinlets" : 0,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 628.200000000000045, 414.0, 386.0, 300.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 552.0, 339.0, 42.0, 20.0 ],
					"text" : "< hold"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 526.0, 371.0, 47.0, 22.0 ],
					"text" : "sw5 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 526.0, 337.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 12.0,
					"id" : "obj-6",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 431.0, 371.0, 93.0, 22.0 ],
					"text" : "knob5_noise $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 431.0, 318.0, 41.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "noise",
							"parameter_mmax" : 1.0,
							"parameter_shortname" : "noise",
							"parameter_type" : 0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "live.dial[3]"
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 1,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-5",
					"lockeddragscroll" : 0,
					"lockedsize" : 0,
					"maxclass" : "bpatcher",
					"name" : "testinput_bpatch.maxpat",
					"numinlets" : 0,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 39.199999999999989, 9.0, 386.0, 300.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-3",
					"maxclass" : "number~",
					"mode" : 2,
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "float" ],
					"patching_rect" : [ 279.199999999999989, 521.0, 56.0, 22.0 ],
					"sig" : 0.0
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 1,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-1",
					"lockeddragscroll" : 0,
					"lockedsize" : 0,
					"maxclass" : "bpatcher",
					"name" : "testinput_bpatch.maxpat",
					"numinlets" : 0,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 427.199999999999989, 9.0, 386.0, 300.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-138",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 277.5, 588.0, 124.0, 20.0 ],
					"text" : "IDMPEDALS vocoder"
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
					"patching_rect" : [ 197.199999999999989, 539.0, 48.0, 136.0 ],
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
					"id" : "obj-8",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 197.199999999999989, 703.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 819.0, 9.0, 58.0, 22.0 ],
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-4",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 819.0, 41.0, 172.0, 22.0 ],
					"text" : "target petal, samplerate 48kHz"
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
					"patching_rect" : [ 819.0, 75.0, 128.0, 128.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 206.0, 371.0, 47.0, 22.0 ],
					"text" : "sw1 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 206.0, 338.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 12.0,
					"id" : "obj-42",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 255.0, 371.0, 81.0, 22.0 ],
					"text" : "knob3_res $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-43",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 255.0, 318.0, 41.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "res",
							"parameter_mmax" : 50.0,
							"parameter_mmin" : 15.0,
							"parameter_shortname" : "res",
							"parameter_type" : 0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "live.dial[1]"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 12.0,
					"id" : "obj-12",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 340.0, 371.0, 87.0, 22.0 ],
					"text" : "knob4_gain $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 340.0, 318.0, 41.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "gain",
							"parameter_mmax" : 50.0,
							"parameter_mmin" : 1.0,
							"parameter_shortname" : "gain",
							"parameter_type" : 0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "live.dial[2]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 6,
					"outlettype" : [ "signal", "signal", "signal", "signal", "signal", "signal" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 2,
							"revision" : 2,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "dsp.gen",
						"rect" : [ 104.0, 87.0, 1564.0, 884.0 ],
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
						"subpatcher_template" : "newtemplate",
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-67",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 540.0, 42.0, 44.0, 20.0 ],
									"text" : "filter Q",
									"textcolor" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-52",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 877.0, 14.0, 48.0, 20.0 ],
									"text" : "release"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-45",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 799.0, 14.0, 41.0, 20.0 ],
									"text" : "attack"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-41",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 296.0, 323.5, 105.0, 33.0 ],
									"text" : "envelope follower on noise",
									"textcolor" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-65",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1060.0, 152.0, 169.0, 20.0 ],
									"text" : "filter bands (from Moog, 1978)",
									"textcolor" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"id" : "obj-60",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 197.5, 329.0, 73.0, 22.0 ],
									"text" : "slide 10 400"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"id" : "obj-61",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 197.5, 295.0, 28.0, 22.0 ],
									"text" : "abs"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"id" : "obj-57",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 197.5, 367.0, 86.0, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
									"id" : "obj-55",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 71.5, 259.0, 29.5, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
									"id" : "obj-53",
									"linecount" : 3,
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 82.0, 182.0, 122.0, 49.0 ],
									"text" : "param knob4_gain @default 5. @min 1. @max 50."
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-125",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 279.0, 792.5, 129.0, 20.0 ],
									"text" : "hold petal lights 2-4 off"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-9",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 396.0, 832.5, 61.0, 22.0 ],
									"text" : "out 6 led4"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-48",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 324.0, 832.5, 61.0, 22.0 ],
									"text" : "out 5 led3"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-50",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 255.0, 832.5, 61.0, 22.0 ],
									"text" : "out 4 led2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-51",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 255.0, 792.5, 19.0, 22.0 ],
									"text" : "0"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-138",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 487.0, 769.0, 124.0, 20.0 ],
									"text" : "IDMPEDALS vocoder"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-49",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1074.0, 14.0, 85.0, 20.0 ],
									"text" : "sample & hold"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-47",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 945.0, 42.0, 26.0, 22.0 ],
									"text" : "!- 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-46",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 945.0, 14.0, 129.0, 22.0 ],
									"text" : "param sw2 @default 0"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-35",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 157.5, 414.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"id" : "obj-33",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 264.5, 296.0, 29.5, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 264.5, 245.0, 37.0, 22.0 ],
									"text" : "noise"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"id" : "obj-3",
									"linecount" : 3,
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 308.0, 232.0, 122.0, 49.0 ],
									"text" : "param knob5_noise @default 0. @min 0. @max 1."
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-31",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 848.0, 661.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-29",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 695.0, 661.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-28",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 542.0, 661.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-26",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 389.0, 661.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-25",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 794.0, 599.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-24",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 641.0, 599.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-19",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 488.0, 599.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-18",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 335.0, 599.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-17",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 674.0, 537.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-15",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 521.0, 537.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-14",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 368.0, 537.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 215.0, 537.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-11",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 618.0, 480.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 465.0, 480.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 312.0, 480.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-115",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 777.0, 40.0, 70.0, 22.0 ],
									"text" : "mstosamps"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-116",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 777.0, 14.0, 19.0, 22.0 ],
									"text" : "2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-111",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1519.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-112",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1518.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-109",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1483.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-110",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1482.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-107",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1447.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-108",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1446.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-105",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1411.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-106",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1410.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-103",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1375.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-104",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1374.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-101",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1339.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-102",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1338.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-99",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1303.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-100",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1302.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-97",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1267.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-98",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1266.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-95",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1231.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-96",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1230.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-93",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1195.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-94",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1194.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-91",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1159.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-92",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1158.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-89",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1123.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-90",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1122.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-87",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1087.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-88",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1086.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-83",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1051.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-86",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1050.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-81",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1015.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-82",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1014.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-80",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 979.0, 259.0, 22.0, 22.0 ],
									"text" : "/ 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-79",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 978.0, 226.0, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-78",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1503.0, 182.0, 35.0, 22.0 ],
									"text" : "5080"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-62",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1467.0, 182.0, 35.0, 22.0 ],
									"text" : "4032"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-64",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1430.0, 182.0, 35.0, 22.0 ],
									"text" : "3200"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-66",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1393.0, 182.0, 35.0, 22.0 ],
									"text" : "2504"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-68",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1356.0, 182.0, 35.0, 22.0 ],
									"text" : "2016"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-54",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1182.0, 182.0, 29.0, 22.0 ],
									"text" : "635"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-56",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1151.0, 182.0, 29.0, 22.0 ],
									"text" : "504"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-58",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1118.0, 182.0, 29.0, 22.0 ],
									"text" : "400"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-44",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1319.0, 182.0, 35.0, 22.0 ],
									"text" : "1600"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-42",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1282.0, 182.0, 35.0, 22.0 ],
									"text" : "1270"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-39",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 159.0, 480.0, 93.0, 22.0 ],
									"text" : "vocoderchannel"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-40",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1244.0, 182.0, 35.0, 22.0 ],
									"text" : "1008"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-38",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1213.0, 182.0, 29.0, 22.0 ],
									"text" : "800"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-36",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1087.0, 182.0, 29.0, 22.0 ],
									"text" : "317"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-34",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1056.0, 182.0, 29.0, 22.0 ],
									"text" : "252"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-32",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1025.0, 182.0, 29.0, 22.0 ],
									"text" : "200"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-30",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 994.0, 182.0, 29.0, 22.0 ],
									"text" : "159"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"id" : "obj-21",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 970.0, 182.0, 22.0, 22.0 ],
									"text" : "50"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"id" : "obj-10",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 426.0, 42.0, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth3"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-7",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 604.0, 103.0, 101.0, 20.0 ],
									"text" : "program (voice)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 29.5, 69.0, 83.0, 20.0 ],
									"text" : "carrier (synth)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 571.0, 103.0, 28.0, 22.0 ],
									"text" : "in 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-20",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 164.5, 729.0, 34.0, 22.0 ],
									"text" : "pass"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-27",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 853.0, 40.0, 70.0, 22.0 ],
									"text" : "mstosamps"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"id" : "obj-16",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 426.0, 8.0, 280.0, 22.0 ],
									"text" : "param knob3_res @default 15. @min 15 @max 50"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-85",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 853.0, 14.0, 22.0, 22.0 ],
									"text" : "20"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-77",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 14.0, 182.0, 42.0, 22.0 ],
									"text" : "gate 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-73",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 151.0, 97.0, 61.0, 22.0 ],
									"text" : "out 3 led1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-74",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 120.0, 62.0, 56.0, 22.0 ],
									"text" : "swtoggle"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-75",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 120.0, 97.0, 26.0, 22.0 ],
									"text" : "+ 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-76",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 120.0, 17.0, 67.0, 22.0 ],
									"text" : "param sw1"
								}

							}
, 							{
								"box" : 								{
									"fontsize" : 12.0,
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 37.0, 97.0, 28.0, 22.0 ],
									"text" : "in 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-22",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 82.0, 781.5, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-59",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 29.5, 781.5, 29.5, 22.0 ],
									"text" : "+"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-23",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 82.0, 832.5, 35.0, 22.0 ],
									"text" : "out 2"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 29.5, 832.5, 35.0, 22.0 ],
									"text" : "out 1"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-77", 1 ],
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-11", 3 ],
									"order" : 5,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-13", 3 ],
									"order" : 14,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-14", 3 ],
									"order" : 11,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-15", 3 ],
									"order" : 7,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-17", 3 ],
									"order" : 3,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-18", 3 ],
									"order" : 12,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-19", 3 ],
									"order" : 8,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-24", 3 ],
									"order" : 4,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-25", 3 ],
									"order" : 1,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-26", 3 ],
									"order" : 10,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-28", 3 ],
									"order" : 6,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-29", 3 ],
									"order" : 2,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-31", 3 ],
									"order" : 0,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-39", 3 ],
									"order" : 15,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-6", 3 ],
									"order" : 13,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-8", 3 ],
									"order" : 9,
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-99", 0 ],
									"source" : [ "obj-100", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-24", 1 ],
									"source" : [ "obj-101", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-101", 0 ],
									"source" : [ "obj-102", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-25", 1 ],
									"source" : [ "obj-103", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-103", 0 ],
									"source" : [ "obj-104", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-26", 1 ],
									"source" : [ "obj-105", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-105", 0 ],
									"source" : [ "obj-106", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-28", 1 ],
									"source" : [ "obj-107", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-107", 0 ],
									"source" : [ "obj-108", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-29", 1 ],
									"source" : [ "obj-109", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-109", 0 ],
									"source" : [ "obj-110", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-31", 1 ],
									"source" : [ "obj-111", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-111", 0 ],
									"source" : [ "obj-112", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-11", 4 ],
									"order" : 5,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-13", 4 ],
									"order" : 14,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-14", 4 ],
									"order" : 11,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-15", 4 ],
									"order" : 7,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-17", 4 ],
									"order" : 3,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-18", 4 ],
									"order" : 12,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-19", 4 ],
									"order" : 8,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-24", 4 ],
									"order" : 4,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-25", 4 ],
									"order" : 1,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-26", 4 ],
									"order" : 10,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-28", 4 ],
									"order" : 6,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-29", 4 ],
									"order" : 2,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-31", 4 ],
									"order" : 0,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-39", 4 ],
									"order" : 15,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-6", 4 ],
									"order" : 13,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-8", 4 ],
									"order" : 9,
									"source" : [ "obj-115", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-115", 0 ],
									"source" : [ "obj-116", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-15", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
									"destination" : [ "obj-10", 0 ],
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-17", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-11", 2 ],
									"order" : 5,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-13", 2 ],
									"order" : 14,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-14", 2 ],
									"order" : 11,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-15", 2 ],
									"order" : 7,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-17", 2 ],
									"order" : 3,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-18", 2 ],
									"order" : 12,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-19", 2 ],
									"order" : 8,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-24", 2 ],
									"order" : 4,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-25", 2 ],
									"order" : 1,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-26", 2 ],
									"order" : 10,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-28", 2 ],
									"order" : 6,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-29", 2 ],
									"order" : 2,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-31", 2 ],
									"order" : 0,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-39", 2 ],
									"order" : 15,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-6", 2 ],
									"order" : 13,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-8", 2 ],
									"order" : 9,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-22", 0 ],
									"order" : 0,
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-59", 0 ],
									"order" : 1,
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-79", 0 ],
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-23", 0 ],
									"source" : [ "obj-22", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-24", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-25", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-26", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-11", 5 ],
									"order" : 5,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-13", 5 ],
									"order" : 14,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-14", 5 ],
									"order" : 11,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-15", 5 ],
									"order" : 7,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-17", 5 ],
									"order" : 3,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-18", 5 ],
									"order" : 12,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-19", 5 ],
									"order" : 8,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-24", 5 ],
									"order" : 4,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-25", 5 ],
									"order" : 1,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-26", 5 ],
									"order" : 10,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-28", 5 ],
									"order" : 6,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-29", 5 ],
									"order" : 2,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-31", 5 ],
									"order" : 0,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-39", 5 ],
									"order" : 15,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-6", 5 ],
									"order" : 13,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-8", 5 ],
									"order" : 9,
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-28", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-29", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"destination" : [ "obj-33", 1 ],
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-79", 1 ],
									"order" : 1,
									"source" : [ "obj-30", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-82", 0 ],
									"order" : 0,
									"source" : [ "obj-30", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-31", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-82", 1 ],
									"order" : 1,
									"source" : [ "obj-32", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-86", 0 ],
									"order" : 0,
									"source" : [ "obj-32", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"destination" : [ "obj-57", 1 ],
									"source" : [ "obj-33", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-86", 1 ],
									"order" : 1,
									"source" : [ "obj-34", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-88", 0 ],
									"order" : 0,
									"source" : [ "obj-34", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-11", 0 ],
									"order" : 5,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-13", 0 ],
									"order" : 14,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-14", 0 ],
									"order" : 11,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-15", 0 ],
									"order" : 7,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-17", 0 ],
									"order" : 3,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-18", 0 ],
									"order" : 12,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-19", 0 ],
									"order" : 8,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-24", 0 ],
									"order" : 4,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-25", 0 ],
									"order" : 1,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-26", 0 ],
									"order" : 10,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-28", 0 ],
									"order" : 6,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-29", 0 ],
									"order" : 2,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-31", 0 ],
									"order" : 0,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-39", 0 ],
									"order" : 15,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-6", 0 ],
									"order" : 13,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.000110864639282, 0.001760244369507, 0.998218417167664, 1.0 ],
									"destination" : [ "obj-8", 0 ],
									"order" : 9,
									"source" : [ "obj-35", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-88", 1 ],
									"order" : 1,
									"source" : [ "obj-36", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-90", 0 ],
									"order" : 0,
									"source" : [ "obj-36", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-96", 1 ],
									"order" : 1,
									"source" : [ "obj-38", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-98", 0 ],
									"order" : 0,
									"source" : [ "obj-38", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-39", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-100", 0 ],
									"order" : 0,
									"source" : [ "obj-40", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-98", 1 ],
									"order" : 1,
									"source" : [ "obj-40", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-100", 1 ],
									"order" : 1,
									"source" : [ "obj-42", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-102", 0 ],
									"order" : 0,
									"source" : [ "obj-42", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-102", 1 ],
									"order" : 1,
									"source" : [ "obj-44", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-104", 0 ],
									"order" : 0,
									"source" : [ "obj-44", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-47", 0 ],
									"source" : [ "obj-46", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-11", 6 ],
									"order" : 5,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-13", 6 ],
									"order" : 14,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-14", 6 ],
									"order" : 11,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-15", 6 ],
									"order" : 7,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-17", 6 ],
									"order" : 3,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-18", 6 ],
									"order" : 12,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-19", 6 ],
									"order" : 8,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-24", 6 ],
									"order" : 4,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-25", 6 ],
									"order" : 1,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-26", 6 ],
									"order" : 10,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-28", 6 ],
									"order" : 6,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-29", 6 ],
									"order" : 2,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-31", 6 ],
									"order" : 0,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-39", 6 ],
									"order" : 15,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-6", 6 ],
									"order" : 13,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.901960849761963, 0.901960849761963, 0.901960730552673, 1.0 ],
									"destination" : [ "obj-8", 6 ],
									"order" : 9,
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"destination" : [ "obj-33", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-48", 0 ],
									"order" : 1,
									"source" : [ "obj-51", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-50", 0 ],
									"order" : 2,
									"source" : [ "obj-51", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"order" : 0,
									"source" : [ "obj-51", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
									"destination" : [ "obj-55", 1 ],
									"source" : [ "obj-53", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-94", 1 ],
									"order" : 1,
									"source" : [ "obj-54", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-96", 0 ],
									"order" : 0,
									"source" : [ "obj-54", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
									"destination" : [ "obj-35", 0 ],
									"order" : 1,
									"source" : [ "obj-55", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"destination" : [ "obj-61", 0 ],
									"order" : 0,
									"source" : [ "obj-55", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-92", 1 ],
									"order" : 1,
									"source" : [ "obj-56", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-94", 0 ],
									"order" : 0,
									"source" : [ "obj-56", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"destination" : [ "obj-35", 1 ],
									"source" : [ "obj-57", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-90", 1 ],
									"order" : 1,
									"source" : [ "obj-58", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-92", 0 ],
									"order" : 0,
									"source" : [ "obj-58", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"source" : [ "obj-59", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"destination" : [ "obj-57", 0 ],
									"source" : [ "obj-60", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
									"destination" : [ "obj-60", 0 ],
									"source" : [ "obj-61", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-110", 1 ],
									"order" : 1,
									"source" : [ "obj-62", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-112", 0 ],
									"order" : 0,
									"source" : [ "obj-62", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-108", 1 ],
									"order" : 1,
									"source" : [ "obj-64", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-110", 0 ],
									"order" : 0,
									"source" : [ "obj-64", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-106", 1 ],
									"order" : 1,
									"source" : [ "obj-66", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-108", 0 ],
									"order" : 0,
									"source" : [ "obj-66", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-104", 1 ],
									"order" : 1,
									"source" : [ "obj-68", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-106", 0 ],
									"order" : 0,
									"source" : [ "obj-68", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-73", 0 ],
									"order" : 0,
									"source" : [ "obj-74", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-75", 0 ],
									"order" : 1,
									"source" : [ "obj-74", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-77", 0 ],
									"source" : [ "obj-75", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-74", 0 ],
									"source" : [ "obj-76", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-22", 1 ],
									"order" : 0,
									"source" : [ "obj-77", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
									"destination" : [ "obj-55", 0 ],
									"source" : [ "obj-77", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-59", 1 ],
									"order" : 1,
									"source" : [ "obj-77", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-112", 1 ],
									"source" : [ "obj-78", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-80", 0 ],
									"source" : [ "obj-79", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-8", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-39", 1 ],
									"source" : [ "obj-80", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-6", 1 ],
									"source" : [ "obj-81", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-81", 0 ],
									"source" : [ "obj-82", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-8", 1 ],
									"source" : [ "obj-83", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 0 ],
									"source" : [ "obj-85", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-83", 0 ],
									"source" : [ "obj-86", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-11", 1 ],
									"source" : [ "obj-87", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-87", 0 ],
									"source" : [ "obj-88", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-13", 1 ],
									"source" : [ "obj-89", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-89", 0 ],
									"source" : [ "obj-90", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-14", 1 ],
									"source" : [ "obj-91", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-91", 0 ],
									"source" : [ "obj-92", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-15", 1 ],
									"source" : [ "obj-93", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-93", 0 ],
									"source" : [ "obj-94", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-17", 1 ],
									"source" : [ "obj-95", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-95", 0 ],
									"source" : [ "obj-96", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-18", 1 ],
									"source" : [ "obj-97", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
									"destination" : [ "obj-97", 0 ],
									"source" : [ "obj-98", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-19", 1 ],
									"source" : [ "obj-99", 0 ]
								}

							}
 ],
						"styles" : [ 							{
								"name" : "AudioStatus_Menu",
								"default" : 								{
									"bgfillcolor" : 									{
										"type" : "color",
										"color" : [ 0.294118, 0.313726, 0.337255, 1 ],
										"color1" : [ 0.454902, 0.462745, 0.482353, 0.0 ],
										"color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
										"angle" : 270.0,
										"proportion" : 0.39,
										"autogradient" : 0
									}

								}
,
								"parentstyle" : "",
								"multi" : 0
							}
 ]
					}
,
					"patching_rect" : [ 200.0, 466.0, 117.0, 22.0 ],
					"saved_object_attributes" : 					{
						"exportfolder" : "Macintosh HD:/Users/lukedubois/Documents/TEACHING/nyu/idm/soundstudio/IDMPEDALS/pedals/",
						"exportname" : "Vocoder"
					}
,
					"text" : "gen~ @title Vocoder",
					"varname" : "Vocoder"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 1 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 1 ],
					"order" : 0,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"order" : 1,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"hidden" : 1,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 1 ],
					"midpoints" : [ 213.949999999999989, 688.5, 232.699999999999989, 688.5 ],
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 1 ],
					"source" : [ "obj-22", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"source" : [ "obj-22", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-83", 0 ],
					"hidden" : 1,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-2" : [ "live.gain~", "live.gain~", 0 ],
			"obj-30" : [ "gain", "gain", 0 ],
			"obj-43" : [ "res", "res", 0 ],
			"obj-7" : [ "noise", "noise", 0 ],
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
				"name" : "genreson.gendsp",
				"bootpath" : "~/Documents/TEACHING/nyu/idm/soundstudio/IDMPEDALS/pedals",
				"patcherrelativepath" : ".",
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
				"name" : "swtoggle.gendsp",
				"bootpath" : "~/Documents/TEACHING/nyu/idm/soundstudio/IDMPEDALS/pedals",
				"patcherrelativepath" : ".",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "testinput_bpatch.maxpat",
				"bootpath" : "~/Documents/TEACHING/nyu/idm/soundstudio/IDMPEDALS/pedals",
				"patcherrelativepath" : ".",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "vocoderchannel.gendsp",
				"bootpath" : "~/Documents/TEACHING/nyu/idm/soundstudio/IDMPEDALS/pedals",
				"patcherrelativepath" : ".",
				"type" : "gDSP",
				"implicit" : 1
			}
 ],
		"autosave" : 0,
		"styles" : [ 			{
				"name" : "AudioStatus_Menu",
				"default" : 				{
					"bgfillcolor" : 					{
						"type" : "color",
						"color" : [ 0.294118, 0.313726, 0.337255, 1 ],
						"color1" : [ 0.454902, 0.462745, 0.482353, 0.0 ],
						"color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
						"angle" : 270.0,
						"proportion" : 0.39,
						"autogradient" : 0
					}

				}
,
				"parentstyle" : "",
				"multi" : 0
			}
 ]
	}

}
