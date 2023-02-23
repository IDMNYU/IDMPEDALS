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
					"patching_rect" : [ 526.0, 371.0, 48.0, 22.0 ],
					"text" : "hold $1"
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
					"patching_rect" : [ 431.0, 371.0, 54.0, 22.0 ],
					"text" : "noise $1"
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
					"fontsize" : 12.0,
					"id" : "obj-42",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 255.0, 371.0, 42.0, 22.0 ],
					"text" : "res $1"
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
					"patching_rect" : [ 340.0, 371.0, 48.0, 22.0 ],
					"text" : "gain $1"
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
					"autosave" : 1,
					"id" : "obj-22",
					"inletInfo" : 					{
						"IOInfo" : [ 							{
								"type" : "signal",
								"index" : 1,
								"tag" : "in1",
								"comment" : ""
							}
, 							{
								"type" : "signal",
								"index" : 2,
								"tag" : "in2",
								"comment" : ""
							}
 ]
					}
,
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 3,
					"outletInfo" : 					{
						"IOInfo" : [ 							{
								"type" : "signal",
								"index" : 1,
								"tag" : "out1",
								"comment" : ""
							}
, 							{
								"type" : "signal",
								"index" : 2,
								"tag" : "out2",
								"comment" : ""
							}
 ]
					}
,
					"outlettype" : [ "signal", "signal", "list" ],
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
						"classnamespace" : "rnbo",
						"rect" : [ 59.0, 106.0, 686.0, 304.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Lato",
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
						"title" : "IDM-Vocoder",
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "signal" ],
									"patching_rect" : [ 101.0, 73.0, 35.0, 23.0 ],
									"rnbo_classname" : "in~",
									"rnbo_extra_attributes" : 									{
										"comment" : "",
										"meta" : ""
									}
,
									"rnbo_serial" : 1,
									"rnbo_uniqueid" : "in~_obj-12",
									"rnboinfo" : 									{
										"needsInstanceInfo" : 1,
										"argnames" : 										{
											"out1" : 											{
												"attrOrProp" : 1,
												"digest" : "signal from inlet with index 2",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 0,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"outlet" : 1,
												"type" : "signal"
											}
,
											"index" : 											{
												"attrOrProp" : 2,
												"digest" : "inlet number",
												"defaultarg" : 1,
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"mandatory" : 1
											}
,
											"comment" : 											{
												"attrOrProp" : 2,
												"digest" : "mouse over comment",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol"
											}
,
											"meta" : 											{
												"attrOrProp" : 2,
												"digest" : "A JSON formatted string containing metadata for use by the exported code",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Metadata",
												"displayorder" : 3
											}

										}
,
										"inputs" : [  ],
										"outputs" : [ 											{
												"name" : "out1",
												"type" : "signal",
												"digest" : "signal from inlet with index 2",
												"displayName" : "",
												"docked" : 0
											}
 ],
										"helpname" : "in~",
										"aliasOf" : "in~",
										"classname" : "in~",
										"operator" : 0,
										"versionId" : -176007711,
										"changesPatcherIO" : 1
									}
,
									"text" : "in~ 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 380.0, 180.0, 50.0, 23.0 ],
									"rnbo_classname" : "number",
									"rnbo_extra_attributes" : 									{
										"minimum" : "<none>",
										"maximum" : "<none>",
										"order" : "",
										"preset" : 0,
										"initialFormat" : "float"
									}
,
									"rnbo_serial" : 1,
									"rnbo_uniqueid" : "number_obj-13"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-14",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 380.0, 144.0, 196.0, 23.0 ],
									"rnbo_classname" : "param",
									"rnbo_extra_attributes" : 									{
										"order" : "0",
										"maximum" : 1.0,
										"fromnormalized" : "",
										"preset" : 1,
										"steps" : 0.0,
										"meta" : "",
										"ctlin" : 0.0,
										"tonormalized" : "",
										"displayorder" : "-",
										"unit" : "",
										"sendinit" : 1,
										"minimum" : 0.0,
										"displayname" : "",
										"exponent" : 1.0
									}
,
									"rnbo_serial" : 1,
									"rnbo_uniqueid" : "hold",
									"rnboinfo" : 									{
										"needsInstanceInfo" : 1,
										"argnames" : 										{
											"value" : 											{
												"attrOrProp" : 2,
												"digest" : "Set initial value",
												"defaultarg" : 2,
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Initial Value",
												"displayorder" : 3
											}
,
											"normalizedvalue" : 											{
												"attrOrProp" : 1,
												"digest" : "Set value normalized. ",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"inlet" : 1,
												"type" : "number"
											}
,
											"reset" : 											{
												"attrOrProp" : 1,
												"digest" : "Reset param to initial value",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 1,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bang"
											}
,
											"normalized" : 											{
												"attrOrProp" : 1,
												"digest" : "Normalized parameter value.",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"outlet" : 1,
												"type" : "number"
											}
,
											"name" : 											{
												"attrOrProp" : 2,
												"digest" : "Name of the parameter",
												"defaultarg" : 1,
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"label" : "Parameter Name",
												"mandatory" : 1
											}
,
											"enum" : 											{
												"attrOrProp" : 2,
												"digest" : "Use an enumerated output",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "list",
												"label" : "Enum Values",
												"displayorder" : 6
											}
,
											"minimum" : 											{
												"attrOrProp" : 2,
												"digest" : "Minimum value",
												"isalias" : 0,
												"aliases" : [ "min" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Minimum",
												"displayorder" : 1
											}
,
											"min" : 											{
												"attrOrProp" : 2,
												"digest" : "Minimum value",
												"isalias" : 1,
												"aliasOf" : "minimum",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Minimum",
												"displayorder" : 1
											}
,
											"maximum" : 											{
												"attrOrProp" : 2,
												"digest" : "Maximum value",
												"isalias" : 0,
												"aliases" : [ "max" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "1",
												"label" : "Maximum",
												"displayorder" : 2
											}
,
											"max" : 											{
												"attrOrProp" : 2,
												"digest" : "Maximum value",
												"isalias" : 1,
												"aliasOf" : "maximum",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "1",
												"label" : "Maximum",
												"displayorder" : 2
											}
,
											"exponent" : 											{
												"attrOrProp" : 2,
												"digest" : "Scale values exponentially",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "1",
												"label" : "Exponent",
												"displayorder" : 7
											}
,
											"steps" : 											{
												"attrOrProp" : 2,
												"digest" : "Divide the output into a number of discrete steps",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Steps",
												"displayorder" : 8
											}
,
											"displayname" : 											{
												"attrOrProp" : 2,
												"digest" : "A more readable name for the parameter in an external RNBO target",
												"isalias" : 0,
												"aliases" : [ "displayName" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Display Name",
												"displayorder" : 14
											}
,
											"displayName" : 											{
												"attrOrProp" : 2,
												"digest" : "A more readable name for the parameter in an external RNBO target",
												"isalias" : 1,
												"aliasOf" : "displayname",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Display Name",
												"displayorder" : 14
											}
,
											"unit" : 											{
												"attrOrProp" : 2,
												"digest" : "A symbol to describe the unit of the parameter in an external RNBO target",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Unit",
												"displayorder" : 15
											}
,
											"tonormalized" : 											{
												"attrOrProp" : 2,
												"digest" : "Converts a real parameter value to its normalized form.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"label" : "To Normalized Expression",
												"displayorder" : 10
											}
,
											"fromnormalized" : 											{
												"attrOrProp" : 2,
												"digest" : "Converts a normalized parameter into its actual parameter value.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"label" : "From Normalized Expression",
												"displayorder" : 9
											}
,
											"order" : 											{
												"attrOrProp" : 2,
												"digest" : "Order in which initial parameter values will be sent out on patcher load. The order can be numeric or symbolic ('first' and 'last')",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "0",
												"label" : "Restore Order",
												"displayorder" : 12
											}
,
											"displayorder" : 											{
												"attrOrProp" : 2,
												"digest" : "Order in which parameters will show up in a list of all parameters. The order can be numeric or symbolic ('first' and 'last')",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "-",
												"label" : "Display Order",
												"displayorder" : 13
											}
,
											"sendinit" : 											{
												"attrOrProp" : 2,
												"digest" : "Send initial value",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bool",
												"defaultValue" : "true",
												"label" : "Send Init",
												"displayorder" : 4
											}
,
											"ctlin" : 											{
												"attrOrProp" : 2,
												"digest" : "MIDI controller number to control this parameter.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"label" : "MIDI Controller Number.",
												"displayorder" : 16
											}
,
											"meta" : 											{
												"attrOrProp" : 2,
												"digest" : "A JSON formatted string containing metadata for use by the exported code",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Metadata",
												"displayorder" : 17
											}
,
											"nopreset" : 											{
												"attrOrProp" : 2,
												"digest" : "Do not add this value to the preset [DEPRECATED - USE @preset 0 instead].",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 1,
												"type" : "bool",
												"defaultValue" : "false"
											}
,
											"preset" : 											{
												"attrOrProp" : 2,
												"digest" : "Add this value to the preset.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bool",
												"defaultValue" : "true",
												"label" : "Include In Preset",
												"displayorder" : 11
											}

										}
,
										"inputs" : [ 											{
												"name" : "value",
												"type" : "number",
												"digest" : "Parameter value",
												"hot" : 1,
												"docked" : 0
											}
, 											{
												"name" : "normalizedvalue",
												"type" : "number",
												"digest" : "Set value normalized. ",
												"docked" : 0
											}
 ],
										"outputs" : [ 											{
												"name" : "value",
												"type" : "number",
												"digest" : "Parameter value",
												"hot" : 1,
												"docked" : 0
											}
, 											{
												"name" : "normalized",
												"type" : "number",
												"digest" : "Normalized parameter value.",
												"docked" : 0
											}
 ],
										"helpname" : "param",
										"aliasOf" : "param",
										"classname" : "param",
										"operator" : 0,
										"versionId" : -1445040964,
										"changesPatcherIO" : 0
									}
,
									"text" : "param hold @value 0 @enum off on",
									"varname" : "hold"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-8",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 318.0, 144.0, 50.0, 23.0 ],
									"rnbo_classname" : "number",
									"rnbo_extra_attributes" : 									{
										"minimum" : "<none>",
										"maximum" : "<none>",
										"order" : "",
										"preset" : 0,
										"initialFormat" : "float"
									}
,
									"rnbo_serial" : 2,
									"rnbo_uniqueid" : "number_obj-8"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-9",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 318.0, 108.0, 219.0, 23.0 ],
									"rnbo_classname" : "param",
									"rnbo_extra_attributes" : 									{
										"order" : "0",
										"fromnormalized" : "",
										"preset" : 1,
										"steps" : 0.0,
										"meta" : "",
										"ctlin" : 0.0,
										"tonormalized" : "",
										"displayorder" : "-",
										"unit" : "",
										"sendinit" : 1,
										"displayname" : "",
										"exponent" : 1.0,
										"enum" : ""
									}
,
									"rnbo_serial" : 6,
									"rnbo_uniqueid" : "noise",
									"rnboinfo" : 									{
										"needsInstanceInfo" : 1,
										"argnames" : 										{
											"value" : 											{
												"attrOrProp" : 2,
												"digest" : "Set initial value",
												"defaultarg" : 2,
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Initial Value",
												"displayorder" : 3
											}
,
											"normalizedvalue" : 											{
												"attrOrProp" : 1,
												"digest" : "Set value normalized. ",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"inlet" : 1,
												"type" : "number"
											}
,
											"reset" : 											{
												"attrOrProp" : 1,
												"digest" : "Reset param to initial value",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 1,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bang"
											}
,
											"normalized" : 											{
												"attrOrProp" : 1,
												"digest" : "Normalized parameter value.",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"outlet" : 1,
												"type" : "number"
											}
,
											"name" : 											{
												"attrOrProp" : 2,
												"digest" : "Name of the parameter",
												"defaultarg" : 1,
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"label" : "Parameter Name",
												"mandatory" : 1
											}
,
											"enum" : 											{
												"attrOrProp" : 2,
												"digest" : "Use an enumerated output",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "list",
												"label" : "Enum Values",
												"displayorder" : 6
											}
,
											"minimum" : 											{
												"attrOrProp" : 2,
												"digest" : "Minimum value",
												"isalias" : 0,
												"aliases" : [ "min" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Minimum",
												"displayorder" : 1
											}
,
											"min" : 											{
												"attrOrProp" : 2,
												"digest" : "Minimum value",
												"isalias" : 1,
												"aliasOf" : "minimum",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Minimum",
												"displayorder" : 1
											}
,
											"maximum" : 											{
												"attrOrProp" : 2,
												"digest" : "Maximum value",
												"isalias" : 0,
												"aliases" : [ "max" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "1",
												"label" : "Maximum",
												"displayorder" : 2
											}
,
											"max" : 											{
												"attrOrProp" : 2,
												"digest" : "Maximum value",
												"isalias" : 1,
												"aliasOf" : "maximum",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "1",
												"label" : "Maximum",
												"displayorder" : 2
											}
,
											"exponent" : 											{
												"attrOrProp" : 2,
												"digest" : "Scale values exponentially",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "1",
												"label" : "Exponent",
												"displayorder" : 7
											}
,
											"steps" : 											{
												"attrOrProp" : 2,
												"digest" : "Divide the output into a number of discrete steps",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Steps",
												"displayorder" : 8
											}
,
											"displayname" : 											{
												"attrOrProp" : 2,
												"digest" : "A more readable name for the parameter in an external RNBO target",
												"isalias" : 0,
												"aliases" : [ "displayName" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Display Name",
												"displayorder" : 14
											}
,
											"displayName" : 											{
												"attrOrProp" : 2,
												"digest" : "A more readable name for the parameter in an external RNBO target",
												"isalias" : 1,
												"aliasOf" : "displayname",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Display Name",
												"displayorder" : 14
											}
,
											"unit" : 											{
												"attrOrProp" : 2,
												"digest" : "A symbol to describe the unit of the parameter in an external RNBO target",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Unit",
												"displayorder" : 15
											}
,
											"tonormalized" : 											{
												"attrOrProp" : 2,
												"digest" : "Converts a real parameter value to its normalized form.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"label" : "To Normalized Expression",
												"displayorder" : 10
											}
,
											"fromnormalized" : 											{
												"attrOrProp" : 2,
												"digest" : "Converts a normalized parameter into its actual parameter value.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"label" : "From Normalized Expression",
												"displayorder" : 9
											}
,
											"order" : 											{
												"attrOrProp" : 2,
												"digest" : "Order in which initial parameter values will be sent out on patcher load. The order can be numeric or symbolic ('first' and 'last')",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "0",
												"label" : "Restore Order",
												"displayorder" : 12
											}
,
											"displayorder" : 											{
												"attrOrProp" : 2,
												"digest" : "Order in which parameters will show up in a list of all parameters. The order can be numeric or symbolic ('first' and 'last')",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "-",
												"label" : "Display Order",
												"displayorder" : 13
											}
,
											"sendinit" : 											{
												"attrOrProp" : 2,
												"digest" : "Send initial value",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bool",
												"defaultValue" : "true",
												"label" : "Send Init",
												"displayorder" : 4
											}
,
											"ctlin" : 											{
												"attrOrProp" : 2,
												"digest" : "MIDI controller number to control this parameter.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"label" : "MIDI Controller Number.",
												"displayorder" : 16
											}
,
											"meta" : 											{
												"attrOrProp" : 2,
												"digest" : "A JSON formatted string containing metadata for use by the exported code",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Metadata",
												"displayorder" : 17
											}
,
											"nopreset" : 											{
												"attrOrProp" : 2,
												"digest" : "Do not add this value to the preset [DEPRECATED - USE @preset 0 instead].",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 1,
												"type" : "bool",
												"defaultValue" : "false"
											}
,
											"preset" : 											{
												"attrOrProp" : 2,
												"digest" : "Add this value to the preset.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bool",
												"defaultValue" : "true",
												"label" : "Include In Preset",
												"displayorder" : 11
											}

										}
,
										"inputs" : [ 											{
												"name" : "value",
												"type" : "number",
												"digest" : "Parameter value",
												"hot" : 1,
												"docked" : 0
											}
, 											{
												"name" : "normalizedvalue",
												"type" : "number",
												"digest" : "Set value normalized. ",
												"docked" : 0
											}
 ],
										"outputs" : [ 											{
												"name" : "value",
												"type" : "number",
												"digest" : "Parameter value",
												"hot" : 1,
												"docked" : 0
											}
, 											{
												"name" : "normalized",
												"type" : "number",
												"digest" : "Normalized parameter value.",
												"docked" : 0
											}
 ],
										"helpname" : "param",
										"aliasOf" : "param",
										"classname" : "param",
										"operator" : 0,
										"versionId" : -1445040964,
										"changesPatcherIO" : 0
									}
,
									"text" : "param noise @value 0. @min 0. @max 1.",
									"varname" : "noise"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 239.0, 109.0, 50.0, 23.0 ],
									"rnbo_classname" : "number",
									"rnbo_extra_attributes" : 									{
										"minimum" : "<none>",
										"maximum" : "<none>",
										"order" : "",
										"preset" : 0,
										"initialFormat" : "float"
									}
,
									"rnbo_serial" : 3,
									"rnbo_uniqueid" : "number_obj-5"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-7",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 239.0, 73.0, 220.0, 23.0 ],
									"rnbo_classname" : "param",
									"rnbo_extra_attributes" : 									{
										"order" : "0",
										"fromnormalized" : "",
										"preset" : 1,
										"steps" : 0.0,
										"meta" : "",
										"ctlin" : 0.0,
										"tonormalized" : "",
										"displayorder" : "-",
										"unit" : "",
										"sendinit" : 1,
										"displayname" : "",
										"exponent" : 1.0,
										"enum" : ""
									}
,
									"rnbo_serial" : 3,
									"rnbo_uniqueid" : "gain",
									"rnboinfo" : 									{
										"needsInstanceInfo" : 1,
										"argnames" : 										{
											"value" : 											{
												"attrOrProp" : 2,
												"digest" : "Set initial value",
												"defaultarg" : 2,
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Initial Value",
												"displayorder" : 3
											}
,
											"normalizedvalue" : 											{
												"attrOrProp" : 1,
												"digest" : "Set value normalized. ",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"inlet" : 1,
												"type" : "number"
											}
,
											"reset" : 											{
												"attrOrProp" : 1,
												"digest" : "Reset param to initial value",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 1,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bang"
											}
,
											"normalized" : 											{
												"attrOrProp" : 1,
												"digest" : "Normalized parameter value.",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"outlet" : 1,
												"type" : "number"
											}
,
											"name" : 											{
												"attrOrProp" : 2,
												"digest" : "Name of the parameter",
												"defaultarg" : 1,
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"label" : "Parameter Name",
												"mandatory" : 1
											}
,
											"enum" : 											{
												"attrOrProp" : 2,
												"digest" : "Use an enumerated output",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "list",
												"label" : "Enum Values",
												"displayorder" : 6
											}
,
											"minimum" : 											{
												"attrOrProp" : 2,
												"digest" : "Minimum value",
												"isalias" : 0,
												"aliases" : [ "min" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Minimum",
												"displayorder" : 1
											}
,
											"min" : 											{
												"attrOrProp" : 2,
												"digest" : "Minimum value",
												"isalias" : 1,
												"aliasOf" : "minimum",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Minimum",
												"displayorder" : 1
											}
,
											"maximum" : 											{
												"attrOrProp" : 2,
												"digest" : "Maximum value",
												"isalias" : 0,
												"aliases" : [ "max" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "1",
												"label" : "Maximum",
												"displayorder" : 2
											}
,
											"max" : 											{
												"attrOrProp" : 2,
												"digest" : "Maximum value",
												"isalias" : 1,
												"aliasOf" : "maximum",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "1",
												"label" : "Maximum",
												"displayorder" : 2
											}
,
											"exponent" : 											{
												"attrOrProp" : 2,
												"digest" : "Scale values exponentially",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "1",
												"label" : "Exponent",
												"displayorder" : 7
											}
,
											"steps" : 											{
												"attrOrProp" : 2,
												"digest" : "Divide the output into a number of discrete steps",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Steps",
												"displayorder" : 8
											}
,
											"displayname" : 											{
												"attrOrProp" : 2,
												"digest" : "A more readable name for the parameter in an external RNBO target",
												"isalias" : 0,
												"aliases" : [ "displayName" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Display Name",
												"displayorder" : 14
											}
,
											"displayName" : 											{
												"attrOrProp" : 2,
												"digest" : "A more readable name for the parameter in an external RNBO target",
												"isalias" : 1,
												"aliasOf" : "displayname",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Display Name",
												"displayorder" : 14
											}
,
											"unit" : 											{
												"attrOrProp" : 2,
												"digest" : "A symbol to describe the unit of the parameter in an external RNBO target",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Unit",
												"displayorder" : 15
											}
,
											"tonormalized" : 											{
												"attrOrProp" : 2,
												"digest" : "Converts a real parameter value to its normalized form.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"label" : "To Normalized Expression",
												"displayorder" : 10
											}
,
											"fromnormalized" : 											{
												"attrOrProp" : 2,
												"digest" : "Converts a normalized parameter into its actual parameter value.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"label" : "From Normalized Expression",
												"displayorder" : 9
											}
,
											"order" : 											{
												"attrOrProp" : 2,
												"digest" : "Order in which initial parameter values will be sent out on patcher load. The order can be numeric or symbolic ('first' and 'last')",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "0",
												"label" : "Restore Order",
												"displayorder" : 12
											}
,
											"displayorder" : 											{
												"attrOrProp" : 2,
												"digest" : "Order in which parameters will show up in a list of all parameters. The order can be numeric or symbolic ('first' and 'last')",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "-",
												"label" : "Display Order",
												"displayorder" : 13
											}
,
											"sendinit" : 											{
												"attrOrProp" : 2,
												"digest" : "Send initial value",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bool",
												"defaultValue" : "true",
												"label" : "Send Init",
												"displayorder" : 4
											}
,
											"ctlin" : 											{
												"attrOrProp" : 2,
												"digest" : "MIDI controller number to control this parameter.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"label" : "MIDI Controller Number.",
												"displayorder" : 16
											}
,
											"meta" : 											{
												"attrOrProp" : 2,
												"digest" : "A JSON formatted string containing metadata for use by the exported code",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Metadata",
												"displayorder" : 17
											}
,
											"nopreset" : 											{
												"attrOrProp" : 2,
												"digest" : "Do not add this value to the preset [DEPRECATED - USE @preset 0 instead].",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 1,
												"type" : "bool",
												"defaultValue" : "false"
											}
,
											"preset" : 											{
												"attrOrProp" : 2,
												"digest" : "Add this value to the preset.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bool",
												"defaultValue" : "true",
												"label" : "Include In Preset",
												"displayorder" : 11
											}

										}
,
										"inputs" : [ 											{
												"name" : "value",
												"type" : "number",
												"digest" : "Parameter value",
												"hot" : 1,
												"docked" : 0
											}
, 											{
												"name" : "normalizedvalue",
												"type" : "number",
												"digest" : "Set value normalized. ",
												"docked" : 0
											}
 ],
										"outputs" : [ 											{
												"name" : "value",
												"type" : "number",
												"digest" : "Parameter value",
												"hot" : 1,
												"docked" : 0
											}
, 											{
												"name" : "normalized",
												"type" : "number",
												"digest" : "Normalized parameter value.",
												"docked" : 0
											}
 ],
										"helpname" : "param",
										"aliasOf" : "param",
										"classname" : "param",
										"operator" : 0,
										"versionId" : -1445040964,
										"changesPatcherIO" : 0
									}
,
									"text" : "param gain @value 5. @min 1. @max 50.",
									"varname" : "gain"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-6",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 155.0, 73.0, 50.0, 23.0 ],
									"rnbo_classname" : "number",
									"rnbo_extra_attributes" : 									{
										"minimum" : "<none>",
										"maximum" : "<none>",
										"order" : "",
										"preset" : 0,
										"initialFormat" : "float"
									}
,
									"rnbo_serial" : 4,
									"rnbo_uniqueid" : "number_obj-6"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 155.0, 37.0, 222.0, 23.0 ],
									"rnbo_classname" : "param",
									"rnbo_extra_attributes" : 									{
										"order" : "0",
										"fromnormalized" : "",
										"preset" : 1,
										"steps" : 0.0,
										"meta" : "",
										"ctlin" : 0.0,
										"tonormalized" : "",
										"displayorder" : "-",
										"unit" : "",
										"sendinit" : 1,
										"displayname" : "",
										"exponent" : 1.0,
										"enum" : ""
									}
,
									"rnbo_serial" : 5,
									"rnbo_uniqueid" : "res",
									"rnboinfo" : 									{
										"needsInstanceInfo" : 1,
										"argnames" : 										{
											"value" : 											{
												"attrOrProp" : 2,
												"digest" : "Set initial value",
												"defaultarg" : 2,
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Initial Value",
												"displayorder" : 3
											}
,
											"normalizedvalue" : 											{
												"attrOrProp" : 1,
												"digest" : "Set value normalized. ",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"inlet" : 1,
												"type" : "number"
											}
,
											"reset" : 											{
												"attrOrProp" : 1,
												"digest" : "Reset param to initial value",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 1,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bang"
											}
,
											"normalized" : 											{
												"attrOrProp" : 1,
												"digest" : "Normalized parameter value.",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"outlet" : 1,
												"type" : "number"
											}
,
											"name" : 											{
												"attrOrProp" : 2,
												"digest" : "Name of the parameter",
												"defaultarg" : 1,
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"label" : "Parameter Name",
												"mandatory" : 1
											}
,
											"enum" : 											{
												"attrOrProp" : 2,
												"digest" : "Use an enumerated output",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "list",
												"label" : "Enum Values",
												"displayorder" : 6
											}
,
											"minimum" : 											{
												"attrOrProp" : 2,
												"digest" : "Minimum value",
												"isalias" : 0,
												"aliases" : [ "min" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Minimum",
												"displayorder" : 1
											}
,
											"min" : 											{
												"attrOrProp" : 2,
												"digest" : "Minimum value",
												"isalias" : 1,
												"aliasOf" : "minimum",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Minimum",
												"displayorder" : 1
											}
,
											"maximum" : 											{
												"attrOrProp" : 2,
												"digest" : "Maximum value",
												"isalias" : 0,
												"aliases" : [ "max" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "1",
												"label" : "Maximum",
												"displayorder" : 2
											}
,
											"max" : 											{
												"attrOrProp" : 2,
												"digest" : "Maximum value",
												"isalias" : 1,
												"aliasOf" : "maximum",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "1",
												"label" : "Maximum",
												"displayorder" : 2
											}
,
											"exponent" : 											{
												"attrOrProp" : 2,
												"digest" : "Scale values exponentially",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "1",
												"label" : "Exponent",
												"displayorder" : 7
											}
,
											"steps" : 											{
												"attrOrProp" : 2,
												"digest" : "Divide the output into a number of discrete steps",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"defaultValue" : "0",
												"label" : "Steps",
												"displayorder" : 8
											}
,
											"displayname" : 											{
												"attrOrProp" : 2,
												"digest" : "A more readable name for the parameter in an external RNBO target",
												"isalias" : 0,
												"aliases" : [ "displayName" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Display Name",
												"displayorder" : 14
											}
,
											"displayName" : 											{
												"attrOrProp" : 2,
												"digest" : "A more readable name for the parameter in an external RNBO target",
												"isalias" : 1,
												"aliasOf" : "displayname",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Display Name",
												"displayorder" : 14
											}
,
											"unit" : 											{
												"attrOrProp" : 2,
												"digest" : "A symbol to describe the unit of the parameter in an external RNBO target",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Unit",
												"displayorder" : 15
											}
,
											"tonormalized" : 											{
												"attrOrProp" : 2,
												"digest" : "Converts a real parameter value to its normalized form.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"label" : "To Normalized Expression",
												"displayorder" : 10
											}
,
											"fromnormalized" : 											{
												"attrOrProp" : 2,
												"digest" : "Converts a normalized parameter into its actual parameter value.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"label" : "From Normalized Expression",
												"displayorder" : 9
											}
,
											"order" : 											{
												"attrOrProp" : 2,
												"digest" : "Order in which initial parameter values will be sent out on patcher load. The order can be numeric or symbolic ('first' and 'last')",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "0",
												"label" : "Restore Order",
												"displayorder" : 12
											}
,
											"displayorder" : 											{
												"attrOrProp" : 2,
												"digest" : "Order in which parameters will show up in a list of all parameters. The order can be numeric or symbolic ('first' and 'last')",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "-",
												"label" : "Display Order",
												"displayorder" : 13
											}
,
											"sendinit" : 											{
												"attrOrProp" : 2,
												"digest" : "Send initial value",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bool",
												"defaultValue" : "true",
												"label" : "Send Init",
												"displayorder" : 4
											}
,
											"ctlin" : 											{
												"attrOrProp" : 2,
												"digest" : "MIDI controller number to control this parameter.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"label" : "MIDI Controller Number.",
												"displayorder" : 16
											}
,
											"meta" : 											{
												"attrOrProp" : 2,
												"digest" : "A JSON formatted string containing metadata for use by the exported code",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Metadata",
												"displayorder" : 17
											}
,
											"nopreset" : 											{
												"attrOrProp" : 2,
												"digest" : "Do not add this value to the preset [DEPRECATED - USE @preset 0 instead].",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 1,
												"type" : "bool",
												"defaultValue" : "false"
											}
,
											"preset" : 											{
												"attrOrProp" : 2,
												"digest" : "Add this value to the preset.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bool",
												"defaultValue" : "true",
												"label" : "Include In Preset",
												"displayorder" : 11
											}

										}
,
										"inputs" : [ 											{
												"name" : "value",
												"type" : "number",
												"digest" : "Parameter value",
												"hot" : 1,
												"docked" : 0
											}
, 											{
												"name" : "normalizedvalue",
												"type" : "number",
												"digest" : "Set value normalized. ",
												"docked" : 0
											}
 ],
										"outputs" : [ 											{
												"name" : "value",
												"type" : "number",
												"digest" : "Parameter value",
												"hot" : 1,
												"docked" : 0
											}
, 											{
												"name" : "normalized",
												"type" : "number",
												"digest" : "Normalized parameter value.",
												"docked" : 0
											}
 ],
										"helpname" : "param",
										"aliasOf" : "param",
										"classname" : "param",
										"operator" : 0,
										"versionId" : -1445040964,
										"changesPatcherIO" : 0
									}
,
									"text" : "param res @value 15. @min 15 @max 50",
									"varname" : "res"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-3",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 101.0, 263.0, 43.0, 23.0 ],
									"rnbo_classname" : "out~",
									"rnbo_extra_attributes" : 									{
										"comment" : "",
										"meta" : ""
									}
,
									"rnbo_serial" : 1,
									"rnbo_uniqueid" : "out~_obj-3",
									"rnboinfo" : 									{
										"needsInstanceInfo" : 1,
										"argnames" : 										{
											"in1" : 											{
												"attrOrProp" : 1,
												"digest" : "signal sent to outlet with index 2",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 0,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"inlet" : 1,
												"type" : "signal"
											}
,
											"index" : 											{
												"attrOrProp" : 2,
												"digest" : "outlet number",
												"defaultarg" : 1,
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"mandatory" : 1
											}
,
											"comment" : 											{
												"attrOrProp" : 2,
												"digest" : "mouse over comment",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol"
											}
,
											"meta" : 											{
												"attrOrProp" : 2,
												"digest" : "A JSON formatted string containing metadata for use by the exported code",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Metadata",
												"displayorder" : 3
											}

										}
,
										"inputs" : [ 											{
												"name" : "in1",
												"type" : "signal",
												"digest" : "signal sent to outlet with index 2",
												"displayName" : "",
												"hot" : 1,
												"docked" : 0
											}
 ],
										"outputs" : [  ],
										"helpname" : "out~",
										"aliasOf" : "out~",
										"classname" : "out~",
										"operator" : 0,
										"versionId" : 374499139,
										"changesPatcherIO" : 1
									}
,
									"text" : "out~ 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 54.0, 263.0, 43.0, 23.0 ],
									"rnbo_classname" : "out~",
									"rnbo_extra_attributes" : 									{
										"comment" : "",
										"meta" : ""
									}
,
									"rnbo_serial" : 2,
									"rnbo_uniqueid" : "out~_obj-2",
									"rnboinfo" : 									{
										"needsInstanceInfo" : 1,
										"argnames" : 										{
											"in1" : 											{
												"attrOrProp" : 1,
												"digest" : "signal sent to outlet with index 1",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 0,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"inlet" : 1,
												"type" : "signal"
											}
,
											"index" : 											{
												"attrOrProp" : 2,
												"digest" : "outlet number",
												"defaultarg" : 1,
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"mandatory" : 1
											}
,
											"comment" : 											{
												"attrOrProp" : 2,
												"digest" : "mouse over comment",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol"
											}
,
											"meta" : 											{
												"attrOrProp" : 2,
												"digest" : "A JSON formatted string containing metadata for use by the exported code",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Metadata",
												"displayorder" : 3
											}

										}
,
										"inputs" : [ 											{
												"name" : "in1",
												"type" : "signal",
												"digest" : "signal sent to outlet with index 1",
												"displayName" : "",
												"hot" : 1,
												"docked" : 0
											}
 ],
										"outputs" : [  ],
										"helpname" : "out~",
										"aliasOf" : "out~",
										"classname" : "out~",
										"operator" : 0,
										"versionId" : 374499139,
										"changesPatcherIO" : 1
									}
,
									"text" : "out~ 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "signal" ],
									"patching_rect" : [ 54.0, 73.0, 35.0, 23.0 ],
									"rnbo_classname" : "in~",
									"rnbo_extra_attributes" : 									{
										"comment" : "",
										"meta" : ""
									}
,
									"rnbo_serial" : 2,
									"rnbo_uniqueid" : "in~_obj-1",
									"rnboinfo" : 									{
										"needsInstanceInfo" : 1,
										"argnames" : 										{
											"out1" : 											{
												"attrOrProp" : 1,
												"digest" : "signal from inlet with index 1",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 0,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"outlet" : 1,
												"type" : "signal"
											}
,
											"index" : 											{
												"attrOrProp" : 2,
												"digest" : "inlet number",
												"defaultarg" : 1,
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "number",
												"mandatory" : 1
											}
,
											"comment" : 											{
												"attrOrProp" : 2,
												"digest" : "mouse over comment",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol"
											}
,
											"meta" : 											{
												"attrOrProp" : 2,
												"digest" : "A JSON formatted string containing metadata for use by the exported code",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"defaultValue" : "",
												"label" : "Metadata",
												"displayorder" : 3
											}

										}
,
										"inputs" : [  ],
										"outputs" : [ 											{
												"name" : "out1",
												"type" : "signal",
												"digest" : "signal from inlet with index 1",
												"displayName" : "",
												"docked" : 0
											}
 ],
										"helpname" : "in~",
										"aliasOf" : "in~",
										"classname" : "in~",
										"operator" : 0,
										"versionId" : -176007711,
										"changesPatcherIO" : 1
									}
,
									"text" : "in~ 1"
								}

							}
, 							{
								"box" : 								{
									"genpatcher" : 									{
										"patcher" : 										{
											"fileversion" : 1,
											"appversion" : 											{
												"major" : 8,
												"minor" : 5,
												"revision" : 3,
												"architecture" : "x64",
												"modernui" : 1
											}
,
											"classnamespace" : "dsp.gen",
											"rect" : [ 261.0, 107.0, 1396.0, 859.0 ],
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
											"boxes" : [ 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "filter Q",
														"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
														"id" : "obj-67",
														"numinlets" : 1,
														"patching_rect" : [ 540.0, 42.0, 44.0, 20.0 ],
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "release",
														"id" : "obj-52",
														"numinlets" : 1,
														"patching_rect" : [ 833.0, 41.0, 48.0, 20.0 ],
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "attack",
														"id" : "obj-45",
														"numinlets" : 1,
														"patching_rect" : [ 755.0, 41.0, 41.0, 20.0 ],
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "envelope follower on noise",
														"linecount" : 3,
														"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
														"id" : "obj-41",
														"numinlets" : 1,
														"patching_rect" : [ 202.5, 227.0, 61.0, 47.0 ],
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "filter bands (from Moog, 1978)",
														"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
														"id" : "obj-65",
														"numinlets" : 1,
														"patching_rect" : [ 911.0, 163.0, 169.0, 20.0 ],
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "slide 10 400",
														"outlettype" : [ "" ],
														"id" : "obj-60",
														"numinlets" : 1,
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
														"patching_rect" : [ 197.5, 329.0, 73.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "abs",
														"outlettype" : [ "" ],
														"id" : "obj-61",
														"numinlets" : 1,
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
														"patching_rect" : [ 197.5, 295.0, 28.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "*",
														"outlettype" : [ "" ],
														"id" : "obj-57",
														"numinlets" : 2,
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
														"patching_rect" : [ 197.5, 367.0, 86.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "*",
														"outlettype" : [ "" ],
														"id" : "obj-55",
														"numinlets" : 2,
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"patching_rect" : [ 117.0, 209.0, 46.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "in 4",
														"outlettype" : [ "" ],
														"id" : "obj-53",
														"numinlets" : 0,
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"patching_rect" : [ 144.5, 127.0, 28.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "IDMPEDALS vocoder",
														"id" : "obj-138",
														"numinlets" : 1,
														"patching_rect" : [ 217.25, 27.0, 124.0, 20.0 ],
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "sample & hold",
														"id" : "obj-49",
														"numinlets" : 1,
														"patching_rect" : [ 953.0, 96.0, 85.0, 20.0 ],
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "!- 1",
														"outlettype" : [ "" ],
														"id" : "obj-47",
														"numinlets" : 1,
														"patching_rect" : [ 824.0, 124.0, 26.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "in 6",
														"outlettype" : [ "" ],
														"id" : "obj-46",
														"numinlets" : 0,
														"patching_rect" : [ 824.0, 96.0, 28.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-35",
														"numinlets" : 2,
														"patching_rect" : [ 119.5, 409.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "*",
														"outlettype" : [ "" ],
														"id" : "obj-33",
														"numinlets" : 2,
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
														"patching_rect" : [ 264.5, 296.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "noise",
														"outlettype" : [ "" ],
														"id" : "obj-5",
														"numinlets" : 0,
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
														"patching_rect" : [ 264.5, 245.0, 37.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "in 5",
														"outlettype" : [ "" ],
														"id" : "obj-3",
														"numinlets" : 0,
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
														"patching_rect" : [ 308.0, 232.0, 28.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-31",
														"numinlets" : 7,
														"patching_rect" : [ 546.333333333333371, 605.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-29",
														"numinlets" : 7,
														"patching_rect" : [ 441.0, 605.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-28",
														"numinlets" : 7,
														"patching_rect" : [ 328.0, 605.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-26",
														"numinlets" : 7,
														"patching_rect" : [ 208.5, 605.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-25",
														"numinlets" : 7,
														"patching_rect" : [ 519.5, 569.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-24",
														"numinlets" : 7,
														"patching_rect" : [ 408.0, 569.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-19",
														"numinlets" : 7,
														"patching_rect" : [ 296.0, 569.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-18",
														"numinlets" : 7,
														"patching_rect" : [ 173.5, 569.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-17",
														"numinlets" : 7,
														"patching_rect" : [ 473.0, 532.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-15",
														"numinlets" : 7,
														"patching_rect" : [ 359.0, 532.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-14",
														"numinlets" : 7,
														"patching_rect" : [ 252.0, 532.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-13",
														"numinlets" : 7,
														"patching_rect" : [ 145.0, 532.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-11",
														"numinlets" : 7,
														"patching_rect" : [ 448.0, 490.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-8",
														"numinlets" : 7,
														"patching_rect" : [ 336.0, 490.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-6",
														"numinlets" : 7,
														"patching_rect" : [ 230.0, 490.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "mstosamps",
														"outlettype" : [ "" ],
														"id" : "obj-115",
														"numinlets" : 1,
														"patching_rect" : [ 733.0, 67.0, 70.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "2",
														"outlettype" : [ "" ],
														"id" : "obj-116",
														"numinlets" : 0,
														"patching_rect" : [ 733.0, 41.0, 19.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-111",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1360.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-112",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1359.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-109",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1324.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-110",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1323.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-107",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1288.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-108",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1287.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-105",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1252.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-106",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1251.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-103",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1216.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-104",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1215.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-101",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1180.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-102",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1179.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-99",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1144.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-100",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1143.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-97",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1108.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-98",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1107.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-95",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1072.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-96",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1071.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-93",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1036.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-94",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1035.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-91",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1000.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-92",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 999.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-89",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 964.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-90",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 963.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-87",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 928.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-88",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 927.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-83",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 892.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-86",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 891.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-81",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 856.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-82",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 855.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"outlettype" : [ "" ],
														"id" : "obj-80",
														"numinlets" : 1,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 820.5, 264.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"outlettype" : [ "" ],
														"id" : "obj-79",
														"numinlets" : 2,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 819.5, 231.0, 29.5, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "5080",
														"outlettype" : [ "" ],
														"id" : "obj-78",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1354.0, 193.0, 35.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "4032",
														"outlettype" : [ "" ],
														"id" : "obj-62",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1318.0, 193.0, 35.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "3200",
														"outlettype" : [ "" ],
														"id" : "obj-64",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1281.0, 193.0, 35.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "2504",
														"outlettype" : [ "" ],
														"id" : "obj-66",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1244.0, 193.0, 35.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "2016",
														"outlettype" : [ "" ],
														"id" : "obj-68",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1207.0, 193.0, 35.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "635",
														"outlettype" : [ "" ],
														"id" : "obj-54",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1033.0, 193.0, 29.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "504",
														"outlettype" : [ "" ],
														"id" : "obj-56",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1002.0, 193.0, 29.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "400",
														"outlettype" : [ "" ],
														"id" : "obj-58",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 969.0, 193.0, 29.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "1600",
														"outlettype" : [ "" ],
														"id" : "obj-44",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1170.0, 193.0, 35.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "1270",
														"outlettype" : [ "" ],
														"id" : "obj-42",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1133.0, 193.0, 35.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "vocoderchannel",
														"outlettype" : [ "" ],
														"id" : "obj-39",
														"numinlets" : 7,
														"patching_rect" : [ 121.0, 490.0, 93.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "1008",
														"outlettype" : [ "" ],
														"id" : "obj-40",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1095.0, 193.0, 35.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "800",
														"outlettype" : [ "" ],
														"id" : "obj-38",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 1064.0, 193.0, 29.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "317",
														"outlettype" : [ "" ],
														"id" : "obj-36",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 938.0, 193.0, 29.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "252",
														"outlettype" : [ "" ],
														"id" : "obj-34",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 907.0, 193.0, 29.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "200",
														"outlettype" : [ "" ],
														"id" : "obj-32",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 876.0, 193.0, 29.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "159",
														"outlettype" : [ "" ],
														"id" : "obj-30",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 845.0, 193.0, 29.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "50",
														"outlettype" : [ "" ],
														"id" : "obj-21",
														"numinlets" : 0,
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"patching_rect" : [ 821.0, 193.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "oopsy.ctrl.smooth3",
														"outlettype" : [ "" ],
														"id" : "obj-10",
														"numinlets" : 1,
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"patching_rect" : [ 426.0, 42.0, 108.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "program (voice)",
														"id" : "obj-7",
														"numinlets" : 1,
														"patching_rect" : [ 750.0, 8.0, 101.0, 20.0 ],
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "carrier (synth)",
														"id" : "obj-4",
														"numinlets" : 1,
														"patching_rect" : [ 151.5, 89.0, 83.0, 20.0 ],
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "in 2",
														"outlettype" : [ "" ],
														"id" : "obj-2",
														"numinlets" : 0,
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"patching_rect" : [ 717.0, 8.0, 28.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "pass",
														"outlettype" : [ "" ],
														"id" : "obj-20",
														"numinlets" : 1,
														"patching_rect" : [ 126.5, 724.0, 34.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "mstosamps",
														"outlettype" : [ "" ],
														"id" : "obj-27",
														"numinlets" : 1,
														"patching_rect" : [ 809.0, 67.0, 70.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "in 3",
														"outlettype" : [ "" ],
														"id" : "obj-16",
														"numinlets" : 0,
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"patching_rect" : [ 426.0, 8.0, 28.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "20",
														"outlettype" : [ "" ],
														"id" : "obj-85",
														"numinlets" : 0,
														"patching_rect" : [ 809.0, 41.0, 22.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "in 1",
														"outlettype" : [ "" ],
														"id" : "obj-1",
														"fontsize" : 12.0,
														"numinlets" : 0,
														"patching_rect" : [ 117.0, 89.0, 28.0, 22.0 ],
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "out 2",
														"id" : "obj-23",
														"fontsize" : 12.0,
														"numinlets" : 1,
														"fontname" : "Arial",
														"patching_rect" : [ 179.0, 794.5, 35.0, 22.0 ],
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "out 1",
														"id" : "obj-12",
														"fontsize" : 12.0,
														"numinlets" : 1,
														"fontname" : "Arial",
														"patching_rect" : [ 126.5, 794.5, 35.0, 22.0 ],
														"numoutlets" : 0
													}

												}
 ],
											"lines" : [ 												{
													"patchline" : 													{
														"source" : [ "obj-99", 0 ],
														"destination" : [ "obj-19", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-98", 0 ],
														"destination" : [ "obj-97", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-97", 0 ],
														"destination" : [ "obj-18", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-96", 0 ],
														"destination" : [ "obj-95", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-95", 0 ],
														"destination" : [ "obj-17", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-94", 0 ],
														"destination" : [ "obj-93", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-93", 0 ],
														"destination" : [ "obj-15", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-92", 0 ],
														"destination" : [ "obj-91", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-91", 0 ],
														"destination" : [ "obj-14", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-90", 0 ],
														"destination" : [ "obj-89", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-89", 0 ],
														"destination" : [ "obj-13", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-88", 0 ],
														"destination" : [ "obj-87", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-87", 0 ],
														"destination" : [ "obj-11", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-86", 0 ],
														"destination" : [ "obj-83", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-85", 0 ],
														"destination" : [ "obj-27", 0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-83", 0 ],
														"destination" : [ "obj-8", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-82", 0 ],
														"destination" : [ "obj-81", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-81", 0 ],
														"destination" : [ "obj-6", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-80", 0 ],
														"destination" : [ "obj-39", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-8", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-79", 0 ],
														"destination" : [ "obj-80", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-78", 0 ],
														"destination" : [ "obj-112", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-68", 0 ],
														"destination" : [ "obj-106", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-68", 0 ],
														"destination" : [ "obj-104", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-66", 0 ],
														"destination" : [ "obj-108", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-66", 0 ],
														"destination" : [ "obj-106", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-64", 0 ],
														"destination" : [ "obj-110", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-64", 0 ],
														"destination" : [ "obj-108", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-62", 0 ],
														"destination" : [ "obj-112", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-62", 0 ],
														"destination" : [ "obj-110", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-61", 0 ],
														"destination" : [ "obj-60", 0 ],
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-60", 0 ],
														"destination" : [ "obj-57", 0 ],
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-6", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-58", 0 ],
														"destination" : [ "obj-92", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-58", 0 ],
														"destination" : [ "obj-90", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-57", 0 ],
														"destination" : [ "obj-35", 1 ],
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-56", 0 ],
														"destination" : [ "obj-94", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-56", 0 ],
														"destination" : [ "obj-92", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-55", 0 ],
														"destination" : [ "obj-61", 0 ],
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-55", 0 ],
														"destination" : [ "obj-35", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-54", 0 ],
														"destination" : [ "obj-96", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-54", 0 ],
														"destination" : [ "obj-94", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-5", 0 ],
														"destination" : [ "obj-33", 0 ],
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-8", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 7
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-6", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 11
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-39", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 15
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-31", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-29", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 4
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-28", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 8
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-26", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 12
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-25", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-24", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 5
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-19", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 9
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-18", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 13
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-17", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 2
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-15", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 6
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-14", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 10
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-13", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 14
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-47", 0 ],
														"destination" : [ "obj-11", 6 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 3
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-44", 0 ],
														"destination" : [ "obj-104", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-44", 0 ],
														"destination" : [ "obj-102", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-42", 0 ],
														"destination" : [ "obj-102", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-42", 0 ],
														"destination" : [ "obj-100", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-40", 0 ],
														"destination" : [ "obj-98", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-40", 0 ],
														"destination" : [ "obj-100", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-39", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-38", 0 ],
														"destination" : [ "obj-98", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-38", 0 ],
														"destination" : [ "obj-96", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-36", 0 ],
														"destination" : [ "obj-90", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-36", 0 ],
														"destination" : [ "obj-88", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-8", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 7
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-6", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 11
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-39", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 15
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-31", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-29", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 4
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-28", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 8
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-26", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 12
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-25", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-24", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 5
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-19", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 9
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-18", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 13
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-17", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 2
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-15", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 6
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-14", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 10
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-13", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 14
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-35", 0 ],
														"destination" : [ "obj-11", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 3
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-34", 0 ],
														"destination" : [ "obj-88", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-34", 0 ],
														"destination" : [ "obj-86", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-33", 0 ],
														"destination" : [ "obj-57", 1 ],
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-32", 0 ],
														"destination" : [ "obj-86", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-32", 0 ],
														"destination" : [ "obj-82", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-31", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-30", 0 ],
														"destination" : [ "obj-82", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-30", 0 ],
														"destination" : [ "obj-79", 1 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-29", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-28", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-8", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 7
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-6", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 11
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-39", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 15
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-31", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-29", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 4
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-28", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 8
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-26", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 12
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-25", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-24", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 5
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-19", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 9
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-18", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 13
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-17", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 2
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-15", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 6
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-14", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 10
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-13", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 14
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-27", 0 ],
														"destination" : [ "obj-11", 5 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 3
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-26", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-25", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-24", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-21", 0 ],
														"destination" : [ "obj-79", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-8", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 7
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-6", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 11
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-39", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 15
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-31", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-29", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 4
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-28", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 8
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-26", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 12
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-25", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-24", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 5
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-19", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 9
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-18", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 13
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-17", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 2
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-15", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 6
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-14", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 10
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-13", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 14
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-2", 0 ],
														"destination" : [ "obj-11", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 3
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-19", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-18", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-17", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-15", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-14", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-13", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-116", 0 ],
														"destination" : [ "obj-115", 0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-8", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 7
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-6", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 11
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-39", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 15
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-31", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-29", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 4
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-28", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 8
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-26", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 12
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-25", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-24", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 5
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-19", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 9
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-18", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 13
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-17", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 2
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-15", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 6
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-14", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 10
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-13", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 14
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-115", 0 ],
														"destination" : [ "obj-11", 4 ],
														"color" : [ 0.701960921287537, 0.701960802078247, 0.701960742473602, 1.0 ],
														"order" : 3
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-112", 0 ],
														"destination" : [ "obj-111", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-111", 0 ],
														"destination" : [ "obj-31", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-110", 0 ],
														"destination" : [ "obj-109", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-11", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-109", 0 ],
														"destination" : [ "obj-29", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-108", 0 ],
														"destination" : [ "obj-107", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-107", 0 ],
														"destination" : [ "obj-28", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-106", 0 ],
														"destination" : [ "obj-105", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-105", 0 ],
														"destination" : [ "obj-26", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-104", 0 ],
														"destination" : [ "obj-103", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-103", 0 ],
														"destination" : [ "obj-25", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-102", 0 ],
														"destination" : [ "obj-101", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-101", 0 ],
														"destination" : [ "obj-24", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-100", 0 ],
														"destination" : [ "obj-99", 0 ],
														"color" : [ 0.250978410243988, 0.501942276954651, 0.008960168808699, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-8", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 7
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-6", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 11
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-39", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 15
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-31", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-29", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 4
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-28", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 8
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-26", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 12
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-25", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-24", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 5
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-19", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 9
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-18", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 13
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-17", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 2
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-15", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 6
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-14", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 10
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-13", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 14
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-11", 3 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ],
														"order" : 3
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-16", 0 ],
														"destination" : [ "obj-10", 0 ],
														"color" : [ 0.50196647644043, 0.001480937004089, 0.998501121997833, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-53", 0 ],
														"destination" : [ "obj-55", 1 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-3", 0 ],
														"destination" : [ "obj-33", 1 ],
														"color" : [ 0.501959443092346, 0.250944197177887, 0.010033501312137, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-46", 0 ],
														"destination" : [ "obj-47", 0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-1", 0 ],
														"destination" : [ "obj-55", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-20", 0 ],
														"destination" : [ "obj-23", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-20", 0 ],
														"destination" : [ "obj-12", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 1
													}

												}
 ],
											"styles" : [ 												{
													"name" : "AudioStatus_Menu",
													"default" : 													{
														"bgfillcolor" : 														{
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
,
									"id" : "obj-22",
									"maxclass" : "newobj",
									"numinlets" : 6,
									"numoutlets" : 2,
									"outlettype" : [ "signal", "signal" ],
									"patching_rect" : [ 54.0, 217.0, 117.0, 23.0 ],
									"rnbo_classname" : "gen~",
									"rnbo_extra_attributes" : 									{
										"exposeparams" : 0
									}
,
									"rnbo_serial" : 1,
									"rnbo_uniqueid" : "Lowpass",
									"rnboinfo" : 									{
										"needsInstanceInfo" : 1,
										"argnames" : 										{
											"in1" : 											{
												"attrOrProp" : 1,
												"digest" : "in1",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"inlet" : 1,
												"type" : "number"
											}
,
											"reset" : 											{
												"attrOrProp" : 1,
												"digest" : "Reset all param and history objects to initial values",
												"isalias" : 0,
												"aliases" : [  ],
												"attachable" : 1,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bang"
											}
,
											"expr" : 											{
												"attrOrProp" : 2,
												"digest" : "a gen expression",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"doNotShowInMaxInspector" : 1
											}
,
											"file" : 											{
												"attrOrProp" : 2,
												"digest" : "gendsp file to load",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"doNotShowInMaxInspector" : 1
											}
,
											"title" : 											{
												"attrOrProp" : 2,
												"digest" : "a title",
												"defaultarg" : 1,
												"isalias" : 0,
												"aliases" : [ "t" ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol",
												"doNotShowInMaxInspector" : 1
											}
,
											"t" : 											{
												"attrOrProp" : 2,
												"digest" : "a title",
												"defaultarg" : 1,
												"isalias" : 1,
												"aliasOf" : "title",
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "symbol"
											}
,
											"exposeparams" : 											{
												"attrOrProp" : 2,
												"digest" : "Expose gen params as RNBO params.",
												"isalias" : 0,
												"aliases" : [  ],
												"settable" : 1,
												"attachable" : 0,
												"isparam" : 0,
												"deprecated" : 0,
												"type" : "bool",
												"defaultValue" : "false"
											}

										}
,
										"inputs" : [ 											{
												"name" : "in1",
												"type" : "auto",
												"digest" : "in1",
												"hot" : 1,
												"docked" : 0
											}
, 											{
												"name" : "in2",
												"type" : "auto"
											}
, 											{
												"name" : "in3",
												"type" : "auto"
											}
, 											{
												"name" : "in4",
												"type" : "auto"
											}
, 											{
												"name" : "in5",
												"type" : "auto"
											}
, 											{
												"name" : "in6",
												"type" : "auto"
											}
 ],
										"outputs" : [ 											{
												"name" : "out1",
												"type" : "signal"
											}
, 											{
												"name" : "out2",
												"type" : "signal"
											}
 ],
										"helpname" : "gen~",
										"aliasOf" : "gen~",
										"classname" : "gen~",
										"operator" : 0,
										"versionId" : 932019353,
										"changesPatcherIO" : 0
									}
,
									"text" : "gen~ @title Vocoder",
									"varname" : "Lowpass"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-22", 0 ],
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-22", 1 ],
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-22", 5 ],
									"source" : [ "obj-13", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-2", 0 ],
									"source" : [ "obj-22", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-22", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-22", 3 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-22", 2 ],
									"source" : [ "obj-6", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-7", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-22", 4 ],
									"source" : [ "obj-8", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-9", 0 ]
								}

							}
 ],
						"default_bgcolor" : [ 0.031372549019608, 0.125490196078431, 0.211764705882353, 1.0 ],
						"color" : [ 0.929412, 0.929412, 0.352941, 1.0 ],
						"elementcolor" : [ 0.357540726661682, 0.515565991401672, 0.861786782741547, 1.0 ],
						"accentcolor" : [ 0.343034118413925, 0.506230533123016, 0.86220508813858, 1.0 ],
						"stripecolor" : [ 0.258338063955307, 0.352425158023834, 0.511919498443604, 1.0 ],
						"bgfillcolor_type" : "color",
						"bgfillcolor_color" : [ 0.031372549019608, 0.125490196078431, 0.211764705882353, 1.0 ],
						"bgfillcolor_color1" : [ 0.031372549019608, 0.125490196078431, 0.211764705882353, 1.0 ],
						"bgfillcolor_color2" : [ 0.263682, 0.004541, 0.038797, 1.0 ],
						"bgfillcolor_angle" : 270.0,
						"bgfillcolor_proportion" : 0.39,
						"bgfillcolor_autogradient" : 0.0,
						"export_config" : 						{
							"vst-au-export" : 							{
								"vst-au-export-ins" : 								{
									"plugin_manufacturer_code" : "BxmC",
									"plugin_manufacturer_name" : "IDMNYU",
									"plugin_name" : "IDM-Vocoder-plugin",
									"openexportdirectory" : 1
								}

							}

						}

					}
,
					"patching_rect" : [ 200.0, 466.0, 147.0, 22.0 ],
					"rnboattrcache" : 					{
						"gain" : 						{
							"label" : "gain",
							"isEnum" : 0,
							"parsestring" : ""
						}
,
						"res" : 						{
							"label" : "res",
							"isEnum" : 0,
							"parsestring" : ""
						}
,
						"noise" : 						{
							"label" : "noise",
							"isEnum" : 0,
							"parsestring" : ""
						}
,
						"hold" : 						{
							"label" : "hold",
							"isEnum" : 1,
							"parsestring" : "\"off\" \"on\""
						}

					}
,
					"rnboversion" : "1.1.0",
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_invisible" : 1,
							"parameter_longname" : "rnbo~",
							"parameter_shortname" : "rnbo~",
							"parameter_type" : 3
						}

					}
,
					"saved_object_attributes" : 					{
						"optimization" : "O1",
						"parameter_enable" : 1,
						"uuid" : "69f771f5-b19c-11ed-b1f5-acde48001122"
					}
,
					"snapshot" : 					{
						"filetype" : "C74Snapshot",
						"version" : 2,
						"minorversion" : 0,
						"name" : "snapshotlist",
						"origin" : "rnbo~",
						"type" : "list",
						"subtype" : "Undefined",
						"embed" : 1,
						"snapshot" : 						{
							"noise" : 							{
								"value" : 0.220472440944882
							}
,
							"hold" : 							{
								"value" : 0.0
							}
,
							"gain" : 							{
								"value" : 21.448818897637793
							}
,
							"res" : 							{
								"value" : 19.685039370078744
							}
,
							"__presetid" : "IDM-Vocoder"
						}
,
						"snapshotlist" : 						{
							"current_snapshot" : 0,
							"entries" : [ 								{
									"filetype" : "C74Snapshot",
									"version" : 2,
									"minorversion" : 0,
									"name" : "Lowpass",
									"origin" : "IDM-Vocoder",
									"type" : "rnbo",
									"subtype" : "",
									"embed" : 0,
									"snapshot" : 									{
										"noise" : 										{
											"value" : 0.220472440944882
										}
,
										"hold" : 										{
											"value" : 0.0
										}
,
										"gain" : 										{
											"value" : 21.448818897637793
										}
,
										"res" : 										{
											"value" : 19.685039370078744
										}
,
										"__presetid" : "IDM-Vocoder"
									}
,
									"fileref" : 									{
										"name" : "Lowpass",
										"filename" : "Lowpass_20230221.maxsnap",
										"filepath" : "~/Documents/Max 8/Snapshots",
										"filepos" : -1,
										"snapshotfileid" : "789144f2723feb8d0fb4817fdea699e3"
									}

								}
 ]
						}

					}
,
					"text" : "rnbo~ @title IDM-Vocoder",
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
					"destination" : [ "obj-12", 0 ],
					"source" : [ "obj-30", 0 ]
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
 ],
		"parameters" : 		{
			"obj-2" : [ "live.gain~", "live.gain~", 0 ],
			"obj-22" : [ "rnbo~", "rnbo~", 0 ],
			"obj-30" : [ "gain", "gain", 0 ],
			"obj-43" : [ "res", "res", 0 ],
			"obj-7" : [ "noise", "noise", 0 ],
			"parameterbanks" : 			{

			}
,
			"inherited_shortname" : 1
		}
,
		"dependency_cache" : [ 			{
				"name" : "Lowpass_20230221.maxsnap",
				"bootpath" : "~/Documents/Max 8/Snapshots",
				"patcherrelativepath" : "../../../../../../../Max 8/Snapshots",
				"type" : "mx@s",
				"implicit" : 1
			}
, 			{
				"name" : "testinput_bpatch.maxpat",
				"bootpath" : "~/Documents/TEACHING/nyu/idm/soundstudio/IDMPEDALS/pedals/VST_patches",
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
