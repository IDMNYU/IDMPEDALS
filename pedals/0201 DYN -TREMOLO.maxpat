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
		"rect" : [ 474.0, 213.0, 657.0, 723.0 ],
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
					"id" : "obj-4",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 584.5, 344.0, 39.0, 20.0 ],
					"text" : "< pan"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 555.5, 380.0, 47.0, 22.0 ],
					"text" : "sw6 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 555.5, 345.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 12.0,
					"id" : "obj-11",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 367.5, 380.0, 97.0, 22.0 ],
					"text" : "knob5_shape $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 367.5, 325.0, 41.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "shape",
							"parameter_mmax" : 10.0,
							"parameter_mmin" : 1.0,
							"parameter_shortname" : "shape",
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
					"id" : "obj-6",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 495.5, 344.0, 57.0, 20.0 ],
					"text" : "< univibe"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 466.5, 380.0, 47.0, 22.0 ],
					"text" : "sw5 $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 466.5, 345.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 128.0, 349.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 128.0, 379.0, 47.0, 22.0 ],
					"text" : "sw1 $1"
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
					"patching_rect" : [ 190.199999999999989, 478.0, 56.0, 22.0 ],
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
					"id" : "obj-9",
					"lockeddragscroll" : 0,
					"lockedsize" : 0,
					"maxclass" : "bpatcher",
					"name" : "testinput_bpatch.maxpat",
					"numinlets" : 0,
					"numoutlets" : 1,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 25.199999999999989, 15.0, 386.0, 300.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-138",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 188.5, 545.0, 169.0, 20.0 ],
					"text" : "IDMPEDALS tremolo / univibe"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"lastchannelcount" : 0,
					"maxclass" : "live.gain~",
					"numinlets" : 2,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "", "float", "list" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 108.199999999999989, 496.0, 48.0, 136.0 ],
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
					"patching_rect" : [ 108.199999999999989, 660.0, 45.0, 45.0 ]
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
					"patching_rect" : [ 417.0, 15.0, 58.0, 22.0 ],
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-2",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 417.0, 47.0, 172.0, 22.0 ],
					"text" : "target petal, samplerate 96kHz"
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
					"patching_rect" : [ 417.0, 81.0, 128.0, 128.0 ],
					"viewvisibility" : 1
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
					"patching_rect" : [ 179.5, 380.0, 95.0, 22.0 ],
					"text" : "knob3_depth $1"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 12.0,
					"id" : "obj-10",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 279.0, 380.0, 85.0, 22.0 ],
					"text" : "knob4_rate $1"
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
					"patching_rect" : [ 179.5, 325.0, 41.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "depth",
							"parameter_mmax" : 1.0,
							"parameter_shortname" : "depth",
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
					"id" : "obj-28",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 279.0, 325.0, 41.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "rate",
							"parameter_mmax" : 1.0,
							"parameter_shortname" : "rate",
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
					"numinlets" : 1,
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
						"rect" : [ 455.0, 259.0, 676.0, 690.0 ],
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
									"id" : "obj-31",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 259.0, 131.0, 77.0, 20.0 ],
									"text" : "log response"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-25",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 101.75, 659.0, 111.0, 20.0 ],
									"text" : "mono in, stereo out"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059509769082069, 0.501929938793182, 0.998454749584198, 1.0 ],
									"id" : "obj-28",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 315.749999999999943, 509.0, 29.0, 22.0 ],
									"text" : "!- 1."
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-26",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 193.499999999999886, 509.0, 52.0, 20.0 ],
									"text" : "autopan",
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059509769082069, 0.501929938793182, 0.998454749584198, 1.0 ],
									"id" : "obj-24",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 247.499999999999886, 509.0, 67.0, 22.0 ],
									"text" : "param sw6"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059509769082069, 0.501929938793182, 0.998454749584198, 1.0 ],
									"id" : "obj-20",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 247.499999999999886, 546.0, 155.500000000000114, 22.0 ],
									"text" : "?"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 125.729980000000012, 576.0, 29.5, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-16",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 452.875, 215.0, 33.0, 22.0 ],
									"text" : "* 30."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-18",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 452.875, 186.0, 28.0, 22.0 ],
									"text" : "abs"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-17",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 193.459960000000081, 333.0, 62.0, 20.0 ],
									"text" : "RM -> AM"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-125",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 462.0, 546.0, 129.0, 20.0 ],
									"text" : "hold petal lights 2-4 off"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-15",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 510.0, 587.0, 61.0, 22.0 ],
									"text" : "out 6 led4"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-27",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 438.0, 587.0, 61.0, 22.0 ],
									"text" : "out 5 led3"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-29",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 156.999999999999886, 441.0, 61.0, 22.0 ],
									"text" : "out 4 led2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-44",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 438.0, 546.0, 19.0, 22.0 ],
									"text" : "0"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"id" : "obj-14",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 126.459960000000081, 129.0, 129.0, 22.0 ],
									"text" : "expr 1.0-(sqrt(1.0-in1))"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-138",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 179.0, 22.0, 169.0, 20.0 ],
									"text" : "IDMPEDALS tremolo / univibe"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-85",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 593.0, 217.0, 29.0, 22.0 ],
									"text" : "100"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-84",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 517.0, 217.0, 22.0, 22.0 ],
									"text" : "10"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-83",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 593.0, 246.0, 70.0, 22.0 ],
									"text" : "mstosamps"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-82",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 517.0, 246.0, 70.0, 22.0 ],
									"text" : "mstosamps"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-81",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 415.0, 316.0, 53.0, 22.0 ],
									"text" : "clip 0. 1."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-79",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 491.75, 215.0, 19.0, 22.0 ],
									"text" : "1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-67",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 414.0, 253.0, 96.75, 22.0 ],
									"text" : "?"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-64",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 491.75, 186.0, 55.0, 20.0 ],
									"text" : "\"univibe\"",
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-65",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 415.0, 282.0, 223.0, 22.0 ],
									"text" : "slide"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-58",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 377.0, 215.0, 67.0, 22.0 ],
									"text" : "param sw5"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.059509769082069, 0.501929938793182, 0.998454749584198, 1.0 ],
									"fontsize" : 12.0,
									"id" : "obj-11",
									"linecount" : 3,
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 250.229980000000012, 217.5, 118.000000000000057, 49.0 ],
									"text" : "param knob5_shape @default 1. @min 1. @max 10."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
									"id" : "obj-9",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 125.729980000000012, 282.0, 143.5, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 125.729980000000012, 318.0, 57.0, 22.0 ],
									"text" : "clip -1. 1."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
									"id" : "obj-7",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 123.729980000000012, 441.0, 29.0, 22.0 ],
									"text" : "!- 1."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 124.729980000000012, 401.0, 95.0, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 125.729980000000012, 362.0, 94.0, 22.0 ],
									"text" : "scale -1. 1. 0. 1."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 125.729980000000012, 243.0, 116.0, 22.0 ],
									"text" : "cycle @index phase"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"id" : "obj-89",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 126.459960000000081, 97.0, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth3"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"id" : "obj-68",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 291.5, 362.0, 142.5, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-77",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 15.0, 146.0, 42.0, 22.0 ],
									"text" : "gate 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-73",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 47.0, 84.0, 61.0, 22.0 ],
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
									"patching_rect" : [ 16.0, 49.0, 56.0, 22.0 ],
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
									"patching_rect" : [ 16.0, 84.0, 26.0, 22.0 ],
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
									"patching_rect" : [ 16.0, 10.0, 67.0, 22.0 ],
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
									"patching_rect" : [ 38.0, 113.0, 28.0, 22.0 ],
									"text" : "in 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-3",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 74.729980000000012, 576.0, 29.5, 22.0 ],
									"text" : "*"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-35",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 163.459960000000137, 165.0, 82.0, 20.0 ],
									"text" : "max LFO rate",
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"fontsize" : 12.0,
									"id" : "obj-32",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 126.459960000000081, 65.0, 284.0, 22.0 ],
									"text" : "param knob4_rate @default 0.1 @min 0. @max 1."
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-22",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 60.0, 623.0, 29.5, 22.0 ],
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
									"patching_rect" : [ 15.0, 623.0, 29.5, 22.0 ],
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
									"patching_rect" : [ 60.0, 659.0, 35.0, 22.0 ],
									"text" : "out 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"fontsize" : 12.0,
									"id" : "obj-21",
									"linecount" : 3,
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 291.5, 289.0, 118.0, 49.0 ],
									"text" : "param knob3_depth @default 1. @min 0. @max 1."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 125.729980000000012, 209.0, 45.0, 22.0 ],
									"text" : "phasor"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"fontsize" : 12.0,
									"id" : "obj-10",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 126.459960000000081, 165.0, 33.0, 22.0 ],
									"text" : "* 12."
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
									"patching_rect" : [ 15.0, 659.0, 35.0, 22.0 ],
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
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 1 ],
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
									"destination" : [ "obj-22", 1 ],
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-10", 0 ],
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-67", 1 ],
									"source" : [ "obj-16", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-16", 0 ],
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-9", 0 ],
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059509769082069, 0.501929938793182, 0.998454749584198, 1.0 ],
									"destination" : [ "obj-13", 1 ],
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-68", 0 ],
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
									"color" : [ 0.059509769082069, 0.501929938793182, 0.998454749584198, 1.0 ],
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-24", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.059509769082069, 0.501929938793182, 0.998454749584198, 1.0 ],
									"destination" : [ "obj-20", 1 ],
									"source" : [ "obj-28", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
									"destination" : [ "obj-59", 1 ],
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-89", 0 ],
									"source" : [ "obj-32", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-2", 0 ],
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-15", 0 ],
									"order" : 0,
									"source" : [ "obj-44", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 0 ],
									"order" : 1,
									"source" : [ "obj-44", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-67", 0 ],
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
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-29", 0 ],
									"order" : 0,
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
									"destination" : [ "obj-7", 0 ],
									"order" : 1,
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-81", 0 ],
									"source" : [ "obj-65", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-65", 0 ],
									"source" : [ "obj-67", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-6", 1 ],
									"source" : [ "obj-68", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
									"destination" : [ "obj-20", 2 ],
									"midpoints" : [ 133.229980000000012, 495.0, 393.5, 495.0 ],
									"order" : 0,
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
									"destination" : [ "obj-28", 0 ],
									"midpoints" : [ 133.229980000000012, 495.0, 325.249999999999943, 495.0 ],
									"order" : 1,
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
									"destination" : [ "obj-3", 1 ],
									"order" : 2,
									"source" : [ "obj-7", 0 ]
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
									"color" : [ 0.298039227724075, 0.298039257526398, 0.298039197921753, 1.0 ],
									"destination" : [ "obj-13", 0 ],
									"order" : 1,
									"source" : [ "obj-77", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.298039227724075, 0.298039257526398, 0.298039197921753, 1.0 ],
									"destination" : [ "obj-18", 0 ],
									"midpoints" : [ 47.5, 195.0, 438.0, 195.0, 438.0, 180.0, 462.375, 180.0 ],
									"order" : 0,
									"source" : [ "obj-77", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-22", 0 ],
									"order" : 0,
									"source" : [ "obj-77", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.298039227724075, 0.298039257526398, 0.298039197921753, 1.0 ],
									"destination" : [ "obj-3", 0 ],
									"order" : 2,
									"source" : [ "obj-77", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-59", 0 ],
									"order" : 1,
									"source" : [ "obj-77", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-67", 2 ],
									"source" : [ "obj-79", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-8", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-68", 1 ],
									"source" : [ "obj-81", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-65", 1 ],
									"source" : [ "obj-82", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-65", 2 ],
									"source" : [ "obj-83", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-82", 0 ],
									"source" : [ "obj-84", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
									"destination" : [ "obj-83", 0 ],
									"source" : [ "obj-85", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
									"destination" : [ "obj-14", 0 ],
									"source" : [ "obj-89", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-9", 0 ]
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
					"patching_rect" : [ 113.0, 421.0, 116.0, 22.0 ],
					"saved_object_attributes" : 					{
						"exportfolder" : "Macintosh HD:/Users/lukedubois/Documents/TEACHING/nyu/idm/soundstudio/IDMPEDALS/pedals/",
						"exportname" : "Tremolo"
					}
,
					"text" : "gen~ @title Tremolo",
					"varname" : "Tremolo"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 1 ],
					"midpoints" : [ 124.949999999999989, 645.5, 143.699999999999989, 645.5 ],
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
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
					"destination" : [ "obj-22", 0 ],
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
					"destination" : [ "obj-15", 0 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"hidden" : 1,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-83", 0 ],
					"hidden" : 1,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 1 ],
					"source" : [ "obj-22", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
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
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-28", 0 ]
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
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-1" : [ "live.gain~", "live.gain~", 0 ],
			"obj-14" : [ "shape", "shape", 0 ],
			"obj-28" : [ "rate", "rate", 0 ],
			"obj-30" : [ "depth", "depth", 0 ],
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
