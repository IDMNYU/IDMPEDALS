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
		"rect" : [ 495.0, 147.0, 658.0, 752.0 ],
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
					"fontsize" : 12.0,
					"id" : "obj-23",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 425.0, 375.0, 70.0, 22.0 ],
					"text" : "diffusion $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 425.0, 320.0, 41.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "diffusion",
							"parameter_mmax" : 2.0,
							"parameter_shortname" : "diffusion",
							"parameter_type" : 0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "live.dial[4]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 568.5, 337.0, 57.0, 20.0 ],
					"text" : "< univibe"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 538.0, 337.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 538.0, 375.0, 45.0, 22.0 ],
					"text" : "env $1"
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
					"patching_rect" : [ 10.0, 7.0, 386.0, 300.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-138",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 161.299999999999955, 582.0, 125.0, 20.0 ],
					"text" : "IDMPEDALS phaser2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"lastchannelcount" : 0,
					"maxclass" : "live.gain~",
					"numinlets" : 2,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "", "float", "list" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 81.0, 533.0, 48.0, 136.0 ],
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
					"id" : "obj-7",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 81.0, 697.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 12.0,
					"id" : "obj-1",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 336.0, 375.0, 35.0, 22.0 ],
					"text" : "fb $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 336.0, 320.0, 41.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "fb",
							"parameter_mmax" : 0.99,
							"parameter_shortname" : "fb",
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
					"fontsize" : 12.0,
					"id" : "obj-12",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 148.5, 375.0, 55.0, 22.0 ],
					"text" : "depth $1"
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
					"patching_rect" : [ 247.0, 375.0, 46.0, 22.0 ],
					"text" : "rate $1"
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
					"patching_rect" : [ 148.5, 320.0, 41.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "depth[1]",
							"parameter_mmax" : 1.0,
							"parameter_shortname" : "depth",
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
					"id" : "obj-28",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 247.0, 320.0, 41.0, 48.0 ],
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
					"varname" : "live.dial[1]"
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
 ]
					}
,
					"maxclass" : "newobj",
					"numinlets" : 1,
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
						"rect" : [ 34.0, 108.0, 632.0, 373.0 ],
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
						"title" : "IDM-Phaser2",
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 383.0, 255.0, 50.0, 23.0 ],
									"rnbo_classname" : "number",
									"rnbo_extra_attributes" : 									{
										"maximum" : "<none>",
										"minimum" : "<none>",
										"initialFormat" : "float",
										"preset" : 0,
										"order" : ""
									}
,
									"rnbo_serial" : 1,
									"rnbo_uniqueid" : "number_obj-10"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-11",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 383.0, 219.0, 183.0, 23.0 ],
									"rnbo_classname" : "param",
									"rnbo_extra_attributes" : 									{
										"tonormalized" : "",
										"meta" : "",
										"exponent" : 1.0,
										"displayname" : "",
										"maximum" : 1.0,
										"preset" : 1,
										"unit" : "",
										"sendinit" : 1,
										"fromnormalized" : "",
										"value" : 0.0,
										"order" : "0",
										"displayorder" : "-",
										"ctlin" : 0.0,
										"steps" : 0.0
									}
,
									"rnbo_serial" : 1,
									"rnbo_uniqueid" : "env",
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
									"text" : "param env @min 0 @enum off on",
									"varname" : "env"
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
									"patching_rect" : [ 313.0, 219.0, 50.0, 23.0 ],
									"rnbo_classname" : "number",
									"rnbo_extra_attributes" : 									{
										"maximum" : "<none>",
										"minimum" : "<none>",
										"initialFormat" : "float",
										"preset" : 0,
										"order" : ""
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
									"patching_rect" : [ 313.0, 183.0, 238.0, 23.0 ],
									"rnbo_classname" : "param",
									"rnbo_extra_attributes" : 									{
										"tonormalized" : "",
										"meta" : "",
										"exponent" : 1.0,
										"enum" : "",
										"displayname" : "",
										"preset" : 1,
										"unit" : "",
										"sendinit" : 1,
										"fromnormalized" : "",
										"order" : "0",
										"displayorder" : "-",
										"ctlin" : 0.0,
										"steps" : 0.0
									}
,
									"rnbo_serial" : 2,
									"rnbo_uniqueid" : "diffusion",
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
									"text" : "param diffusion @min 0. @max 2. @value 1.",
									"varname" : "diffusion"
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
									"patching_rect" : [ 244.0, 183.0, 50.0, 23.0 ],
									"rnbo_classname" : "number",
									"rnbo_extra_attributes" : 									{
										"maximum" : "<none>",
										"minimum" : "<none>",
										"initialFormat" : "float",
										"preset" : 0,
										"order" : ""
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
									"patching_rect" : [ 244.0, 147.0, 230.0, 23.0 ],
									"rnbo_classname" : "param",
									"rnbo_extra_attributes" : 									{
										"tonormalized" : "",
										"meta" : "",
										"exponent" : 1.0,
										"enum" : "",
										"displayname" : "",
										"preset" : 1,
										"unit" : "",
										"sendinit" : 1,
										"fromnormalized" : "",
										"order" : "0",
										"displayorder" : "-",
										"ctlin" : 0.0,
										"steps" : 0.0
									}
,
									"rnbo_serial" : 3,
									"rnbo_uniqueid" : "fb",
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
									"text" : "param fb @min 0.5 @max 0.99 @value 0.7",
									"varname" : "fb"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-14",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 175.0, 147.0, 50.0, 23.0 ],
									"rnbo_classname" : "number",
									"rnbo_extra_attributes" : 									{
										"maximum" : "<none>",
										"minimum" : "<none>",
										"initialFormat" : "float",
										"preset" : 0,
										"order" : ""
									}
,
									"rnbo_serial" : 4,
									"rnbo_uniqueid" : "number_obj-14"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-15",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 175.0, 111.0, 219.0, 23.0 ],
									"rnbo_classname" : "param",
									"rnbo_extra_attributes" : 									{
										"tonormalized" : "",
										"meta" : "",
										"exponent" : 1.0,
										"enum" : "",
										"displayname" : "",
										"preset" : 1,
										"unit" : "",
										"sendinit" : 1,
										"fromnormalized" : "",
										"order" : "0",
										"displayorder" : "-",
										"ctlin" : 0.0,
										"steps" : 0.0
									}
,
									"rnbo_serial" : 4,
									"rnbo_uniqueid" : "rate",
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
									"text" : "param rate @value 0.1 @min 0. @max 1.",
									"varname" : "rate"
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
									"patching_rect" : [ 108.0, 111.0, 50.0, 23.0 ],
									"rnbo_classname" : "number",
									"rnbo_extra_attributes" : 									{
										"maximum" : "<none>",
										"minimum" : "<none>",
										"initialFormat" : "float",
										"preset" : 0,
										"order" : ""
									}
,
									"rnbo_serial" : 5,
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
									"patching_rect" : [ 108.0, 75.0, 222.0, 23.0 ],
									"rnbo_classname" : "param",
									"rnbo_extra_attributes" : 									{
										"tonormalized" : "",
										"meta" : "",
										"exponent" : 1.0,
										"enum" : "",
										"displayname" : "",
										"preset" : 1,
										"unit" : "",
										"sendinit" : 1,
										"fromnormalized" : "",
										"order" : "0",
										"displayorder" : "-",
										"ctlin" : 0.0,
										"steps" : 0.0
									}
,
									"rnbo_serial" : 5,
									"rnbo_uniqueid" : "depth",
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
									"text" : "param depth @value 1. @min 0. @max 1.",
									"varname" : "depth"
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
										"meta" : "",
										"comment" : ""
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
										"meta" : "",
										"comment" : ""
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
										"meta" : "",
										"comment" : ""
									}
,
									"rnbo_serial" : 1,
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
											"rect" : [ 386.0, 87.0, 1064.0, 637.0 ],
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
														"text" : "quartic scaling",
														"id" : "obj-44",
														"patching_rect" : [ 386.0, 105.0, 85.0, 20.0 ],
														"numinlets" : 1,
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "50% wet/dry",
														"id" : "obj-37",
														"patching_rect" : [ 186.540039999999863, 482.0, 75.0, 20.0 ],
														"numinlets" : 1,
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "* 30.",
														"id" : "obj-26",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 691.5, 53.0, 33.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "abs",
														"id" : "obj-36",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 691.5, 22.0, 28.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"id" : "obj-31",
														"outlettype" : [ "" ],
														"patching_rect" : [ 96.290039999999863, 518.0, 22.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 2",
														"id" : "obj-30",
														"outlettype" : [ "" ],
														"patching_rect" : [ 149.290039999999863, 518.0, 22.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "expr 1.0-(sqrt(sqrt(sqrt(1.0-in1))))",
														"id" : "obj-29",
														"outlettype" : [ "" ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
														"patching_rect" : [ 192.729980000000012, 105.0, 185.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "IDMPEDALS phaser2",
														"id" : "obj-138",
														"patching_rect" : [ 24.0, 13.0, 125.0, 20.0 ],
														"numinlets" : 1,
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "*",
														"id" : "obj-28",
														"outlettype" : [ "" ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"patching_rect" : [ 430.419920000000275, 220.0, 203.540039999999863, 22.0 ],
														"numinlets" : 2,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "scale 0.5 0.99 0.25 0.1",
														"id" : "obj-90",
														"outlettype" : [ "" ],
														"color" : [ 0.000000062398612, 0.0, 0.501960754394531, 1.0 ],
														"patching_rect" : [ 158.25, 419.0, 130.0, 22.0 ],
														"numinlets" : 2,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "oopsy.ctrl.smooth3",
														"id" : "obj-89",
														"outlettype" : [ "" ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
														"patching_rect" : [ 192.729980000000012, 71.0, 108.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "100",
														"id" : "obj-85",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 707.959960000000137, 120.0, 29.0, 22.0 ],
														"numinlets" : 0,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "10",
														"id" : "obj-84",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 632.459960000000137, 120.0, 22.0, 22.0 ],
														"numinlets" : 0,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "mstosamps",
														"id" : "obj-83",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 707.959960000000137, 149.0, 70.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "mstosamps",
														"id" : "obj-82",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 632.459960000000137, 149.0, 70.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "1",
														"id" : "obj-79",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 735.459960000000137, 54.0, 19.0, 22.0 ],
														"numinlets" : 0,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "clip 0. 1.",
														"id" : "obj-68",
														"outlettype" : [ "" ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"patching_rect" : [ 430.419920000000275, 251.0, 53.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "?",
														"id" : "obj-67",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 614.959960000000137, 86.0, 172.080079999999725, 22.0 ],
														"numinlets" : 3,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "\"univibe\"",
														"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
														"id" : "obj-64",
														"patching_rect" : [ 758.959960000000137, 54.0, 55.0, 20.0 ],
														"numinlets" : 1,
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "slide",
														"id" : "obj-65",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 614.959960000000137, 179.0, 112.0, 22.0 ],
														"numinlets" : 3,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "in 6",
														"id" : "obj-58",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 614.959960000000137, 53.0, 28.0, 22.0 ],
														"numinlets" : 0,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "in 1",
														"id" : "obj-1",
														"outlettype" : [ "" ],
														"fontsize" : 12.0,
														"patching_rect" : [ 146.290039999999863, 105.0, 28.0, 22.0 ],
														"numinlets" : 0,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "history",
														"id" : "obj-54",
														"outlettype" : [ "" ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 254.0, 229.0, 44.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"id" : "obj-55",
														"outlettype" : [ "" ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 243.5, 305.0, 29.5, 22.0 ],
														"numinlets" : 2,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "*",
														"id" : "obj-57",
														"outlettype" : [ "" ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 254.0, 268.0, 65.0, 22.0 ],
														"numinlets" : 2,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "* 0.5",
														"id" : "obj-33",
														"outlettype" : [ "" ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 569.959960000000137, 415.0, 40.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "dcblock",
														"id" : "obj-34",
														"outlettype" : [ "" ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 569.959960000000137, 449.0, 49.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "feedback",
														"id" : "obj-27",
														"patching_rect" : [ 326.0, 204.5, 57.0, 20.0 ],
														"numinlets" : 1,
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "*",
														"id" : "obj-25",
														"outlettype" : [ "" ],
														"patching_rect" : [ 149.290039999999863, 482.0, 29.5, 22.0 ],
														"numinlets" : 2,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "gen @title LFO-allpass",
														"id" : "obj-20",
														"outlettype" : [ "" ],
														"fontsize" : 12.0,
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 570.0, 360.0, 131.0, 22.0 ],
														"numinlets" : 5,
														"numoutlets" : 1,
														"patcher" : 														{
															"fileversion" : 1,
															"appversion" : 															{
																"major" : 8,
																"minor" : 5,
																"revision" : 3,
																"architecture" : "x64",
																"modernui" : 1
															}
,
															"classnamespace" : "dsp.gen",
															"rect" : [ 907.0, 79.0, 635.0, 739.0 ],
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
															"boxes" : [ 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "gen @title allpass-coeffs",
																		"id" : "obj-54",
																		"outlettype" : [ "", "", "" ],
																		"patching_rect" : [ 307.729980000000012, 353.0, 178.729980000000012, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 3,
																		"patcher" : 																		{
																			"fileversion" : 1,
																			"appversion" : 																			{
																				"major" : 8,
																				"minor" : 5,
																				"revision" : 3,
																				"architecture" : "x64",
																				"modernui" : 1
																			}
,
																			"classnamespace" : "dsp.gen",
																			"rect" : [ 878.0, 247.0, 333.0, 464.0 ],
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
																			"boxes" : [ 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "slide 5 5",
																						"id" : "obj-2",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 151.729980000000069, 386.0, 53.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "slide 5 5",
																						"id" : "obj-1",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 386.0, 53.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "a2",
																						"id" : "obj-68",
																						"patching_rect" : [ 259.729979999999955, 345.0, 22.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "1.",
																						"id" : "obj-66",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 238.729979999999955, 345.0, 19.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "a0, b2",
																						"id" : "obj-65",
																						"patching_rect" : [ 183.729980000000069, 345.0, 42.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "*",
																						"id" : "obj-63",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 151.729980000000069, 345.0, 29.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "!- 1.",
																						"id" : "obj-62",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 102.729980000000069, 265.0, 29.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "b1, a1",
																						"id" : "obj-61",
																						"patching_rect" : [ 90.729980000000069, 345.0, 42.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "*",
																						"id" : "obj-59",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 345.0, 29.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "* -2.",
																						"id" : "obj-58",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 158.729980000000069, 265.0, 31.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "cs",
																						"id" : "obj-57",
																						"patching_rect" : [ 189.729980000000069, 162.0, 20.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "sn",
																						"id" : "obj-56",
																						"patching_rect" : [ 32.0, 162.0, 21.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "b0",
																						"id" : "obj-54",
																						"patching_rect" : [ 31.5, 297.0, 22.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "!/ 1.",
																						"id" : "obj-52",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 297.0, 29.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "+ 1.",
																						"id" : "obj-51",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 265.0, 29.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "alpha",
																						"id" : "obj-50",
																						"patching_rect" : [ 18.0, 228.0, 38.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "/",
																						"id" : "obj-48",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 228.0, 61.999999999999943, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "* 0.5",
																						"id" : "obj-47",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 197.0, 33.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "cos",
																						"id" : "obj-46",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 158.729980000000069, 162.0, 27.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "sin",
																						"id" : "obj-45",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 162.0, 24.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "omega",
																						"id" : "obj-44",
																						"patching_rect" : [ 112.729980000000069, 121.0, 45.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "*",
																						"id" : "obj-42",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 121.0, 49.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "/",
																						"id" : "obj-41",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 90.729980000000069, 77.0, 29.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "twopi",
																						"id" : "obj-40",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 90.729980000000069, 44.0, 37.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "samplerate",
																						"id" : "obj-39",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 135.729980000000069, 44.0, 68.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "in 1",
																						"id" : "obj-25",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 44.0, 28.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "in 2",
																						"id" : "obj-27",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 102.729980000000012, 197.0, 28.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "out 1",
																						"id" : "obj-34",
																						"patching_rect" : [ 59.729980000000012, 427.0, 35.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "out 2",
																						"id" : "obj-43",
																						"patching_rect" : [ 151.729980000000012, 427.0, 35.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "out 3",
																						"id" : "obj-53",
																						"patching_rect" : [ 238.729979999999955, 427.0, 35.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
 ],
																			"lines" : [ 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-66", 0 ],
																						"destination" : [ "obj-53", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-63", 0 ],
																						"destination" : [ "obj-2", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-62", 0 ],
																						"destination" : [ "obj-63", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-59", 0 ],
																						"destination" : [ "obj-1", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-58", 0 ],
																						"destination" : [ "obj-59", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-52", 0 ],
																						"destination" : [ "obj-63", 0 ],
																						"order" : 0
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-52", 0 ],
																						"destination" : [ "obj-59", 0 ],
																						"order" : 1
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-51", 0 ],
																						"destination" : [ "obj-52", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-48", 0 ],
																						"destination" : [ "obj-62", 0 ],
																						"order" : 0
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-48", 0 ],
																						"destination" : [ "obj-51", 0 ],
																						"order" : 1
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-47", 0 ],
																						"destination" : [ "obj-48", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-46", 0 ],
																						"destination" : [ "obj-58", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-45", 0 ],
																						"destination" : [ "obj-47", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-42", 0 ],
																						"destination" : [ "obj-46", 0 ],
																						"order" : 0
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-42", 0 ],
																						"destination" : [ "obj-45", 0 ],
																						"order" : 1
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-41", 0 ],
																						"destination" : [ "obj-42", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-40", 0 ],
																						"destination" : [ "obj-41", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-39", 0 ],
																						"destination" : [ "obj-41", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-27", 0 ],
																						"destination" : [ "obj-48", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-25", 0 ],
																						"destination" : [ "obj-42", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-2", 0 ],
																						"destination" : [ "obj-43", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-1", 0 ],
																						"destination" : [ "obj-34", 0 ]
																					}

																				}
 ]
																		}

																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "--- allpass ---",
																		"id" : "obj-49",
																		"patching_rect" : [ 360.229980000000069, 313.0, 76.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "--- lfo ---",
																		"id" : "obj-30",
																		"patching_rect" : [ 372.229980000000126, 194.0, 52.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "x(n)",
																		"id" : "obj-7",
																		"patching_rect" : [ 96.5, 557.0, 29.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "/ 2.",
																		"id" : "obj-32",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 194.0, 25.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "+ 1.",
																		"id" : "obj-33",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 161.0, 29.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-35",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 307.729980000000012, 234.0, 222.000000000000057, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "cycle @index phase",
																		"id" : "obj-38",
																		"outlettype" : [ "", "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 124.0, 116.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 2
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 3",
																		"id" : "obj-26",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 510.729980000000069, 194.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 5",
																		"id" : "obj-23",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 348.229980000000126, 19.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "+",
																		"id" : "obj-29",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 57.0, 59.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "% 1.",
																		"id" : "obj-28",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 91.0, 33.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "scale 0. 1. 20. 135.",
																		"id" : "obj-20",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 307.729980000000012, 276.0, 110.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "mtof",
																		"id" : "obj-17",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 307.729980000000012, 313.0, 32.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 1",
																		"id" : "obj-1",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 58.5, 353.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 4",
																		"id" : "obj-2",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 467.459960000000024, 313.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 2",
																		"id" : "obj-3",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 19.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "out 1",
																		"id" : "obj-4",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 56.0, 687.0, 35.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "---- biquad ----",
																		"id" : "obj-5",
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 96.5, 353.0, 83.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "x(n-2)",
																		"id" : "obj-12",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 321.5, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "x(n-1)",
																		"id" : "obj-24",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 216.0, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "y(n-2)",
																		"id" : "obj-9",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 536.0, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "y(n-1)",
																		"id" : "obj-8",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 430.5, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-18",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 494.5, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-19",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 494.5, 509.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-21",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 389.5, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-22",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 389.5, 471.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-15",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 281.0, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-16",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 281.0, 435.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-14",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 176.0, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-13",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 176.0, 400.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "-",
																		"id" : "obj-11",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 56.0, 630.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-10",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 56.0, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
 ],
															"lines" : [ 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 0 ],
																		"destination" : [ "obj-21", 1 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 1 ],
																		"destination" : [ "obj-18", 1 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 2 ],
																		"destination" : [ "obj-15", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 0 ],
																		"destination" : [ "obj-14", 1 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 1 ],
																		"destination" : [ "obj-10", 1 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-38", 0 ],
																		"destination" : [ "obj-33", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-35", 0 ],
																		"destination" : [ "obj-20", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-33", 0 ],
																		"destination" : [ "obj-32", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-32", 0 ],
																		"destination" : [ "obj-35", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-3", 0 ],
																		"destination" : [ "obj-29", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-29", 0 ],
																		"destination" : [ "obj-28", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-28", 0 ],
																		"destination" : [ "obj-38", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-26", 0 ],
																		"destination" : [ "obj-35", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-23", 0 ],
																		"destination" : [ "obj-29", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-22", 0 ],
																		"destination" : [ "obj-21", 0 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-22", 0 ],
																		"destination" : [ "obj-19", 0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-21", 0 ],
																		"destination" : [ "obj-11", 1 ],
																		"midpoints" : [ 399.0, 608.5, 79.5, 608.5 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-20", 0 ],
																		"destination" : [ "obj-17", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-2", 0 ],
																		"destination" : [ "obj-54", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-19", 0 ],
																		"destination" : [ "obj-18", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-18", 0 ],
																		"destination" : [ "obj-11", 1 ],
																		"midpoints" : [ 504.0, 607.0, 79.5, 607.0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-17", 0 ],
																		"destination" : [ "obj-54", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-16", 0 ],
																		"destination" : [ "obj-15", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-15", 0 ],
																		"destination" : [ "obj-11", 0 ],
																		"midpoints" : [ 290.5, 594.5, 65.5, 594.5 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-14", 0 ],
																		"destination" : [ "obj-11", 0 ],
																		"midpoints" : [ 185.5, 593.5, 65.5, 593.5 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-13", 0 ],
																		"destination" : [ "obj-16", 0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-13", 0 ],
																		"destination" : [ "obj-14", 0 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-11", 0 ],
																		"destination" : [ "obj-4", 0 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-11", 0 ],
																		"destination" : [ "obj-22", 0 ],
																		"midpoints" : [ 65.5, 667.0, 595.25, 667.0, 595.25, 452.0, 399.0, 452.0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-10", 0 ],
																		"destination" : [ "obj-11", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-1", 0 ],
																		"destination" : [ "obj-13", 0 ],
																		"midpoints" : [ 68.0, 389.0, 185.5, 389.0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-1", 0 ],
																		"destination" : [ "obj-10", 0 ],
																		"order" : 1
																	}

																}
 ]
														}

													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "gen @title LFO-allpass",
														"id" : "obj-24",
														"outlettype" : [ "" ],
														"fontsize" : 12.0,
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 435.0, 360.0, 131.0, 22.0 ],
														"numinlets" : 5,
														"numoutlets" : 1,
														"patcher" : 														{
															"fileversion" : 1,
															"appversion" : 															{
																"major" : 8,
																"minor" : 5,
																"revision" : 3,
																"architecture" : "x64",
																"modernui" : 1
															}
,
															"classnamespace" : "dsp.gen",
															"rect" : [ 907.0, 79.0, 635.0, 739.0 ],
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
															"boxes" : [ 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "gen @title allpass-coeffs",
																		"id" : "obj-54",
																		"outlettype" : [ "", "", "" ],
																		"patching_rect" : [ 307.729980000000012, 353.0, 178.729980000000012, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 3,
																		"patcher" : 																		{
																			"fileversion" : 1,
																			"appversion" : 																			{
																				"major" : 8,
																				"minor" : 5,
																				"revision" : 3,
																				"architecture" : "x64",
																				"modernui" : 1
																			}
,
																			"classnamespace" : "dsp.gen",
																			"rect" : [ 878.0, 247.0, 333.0, 464.0 ],
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
																			"boxes" : [ 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "slide 5 5",
																						"id" : "obj-2",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 151.729980000000069, 386.0, 53.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "slide 5 5",
																						"id" : "obj-1",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 386.0, 53.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "a2",
																						"id" : "obj-68",
																						"patching_rect" : [ 259.729979999999955, 345.0, 22.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "1.",
																						"id" : "obj-66",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 238.729979999999955, 345.0, 19.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "a0, b2",
																						"id" : "obj-65",
																						"patching_rect" : [ 183.729980000000069, 345.0, 42.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "*",
																						"id" : "obj-63",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 151.729980000000069, 345.0, 29.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "!- 1.",
																						"id" : "obj-62",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 102.729980000000069, 265.0, 29.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "b1, a1",
																						"id" : "obj-61",
																						"patching_rect" : [ 90.729980000000069, 345.0, 42.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "*",
																						"id" : "obj-59",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 345.0, 29.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "* -2.",
																						"id" : "obj-58",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 158.729980000000069, 265.0, 31.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "cs",
																						"id" : "obj-57",
																						"patching_rect" : [ 189.729980000000069, 162.0, 20.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "sn",
																						"id" : "obj-56",
																						"patching_rect" : [ 32.0, 162.0, 21.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "b0",
																						"id" : "obj-54",
																						"patching_rect" : [ 31.5, 297.0, 22.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "!/ 1.",
																						"id" : "obj-52",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 297.0, 29.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "+ 1.",
																						"id" : "obj-51",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 265.0, 29.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "alpha",
																						"id" : "obj-50",
																						"patching_rect" : [ 18.0, 228.0, 38.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "/",
																						"id" : "obj-48",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 228.0, 61.999999999999943, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "* 0.5",
																						"id" : "obj-47",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 197.0, 33.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "cos",
																						"id" : "obj-46",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 158.729980000000069, 162.0, 27.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "sin",
																						"id" : "obj-45",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 162.0, 24.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "omega",
																						"id" : "obj-44",
																						"patching_rect" : [ 112.729980000000069, 121.0, 45.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "*",
																						"id" : "obj-42",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 121.0, 49.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "/",
																						"id" : "obj-41",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 90.729980000000069, 77.0, 29.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "twopi",
																						"id" : "obj-40",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 90.729980000000069, 44.0, 37.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "samplerate",
																						"id" : "obj-39",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 135.729980000000069, 44.0, 68.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "in 1",
																						"id" : "obj-25",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 44.0, 28.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "in 2",
																						"id" : "obj-27",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 102.729980000000012, 197.0, 28.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "out 1",
																						"id" : "obj-34",
																						"patching_rect" : [ 59.729980000000012, 427.0, 35.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "out 2",
																						"id" : "obj-43",
																						"patching_rect" : [ 151.729980000000012, 427.0, 35.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "out 3",
																						"id" : "obj-53",
																						"patching_rect" : [ 238.729979999999955, 427.0, 35.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
 ],
																			"lines" : [ 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-66", 0 ],
																						"destination" : [ "obj-53", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-63", 0 ],
																						"destination" : [ "obj-2", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-62", 0 ],
																						"destination" : [ "obj-63", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-59", 0 ],
																						"destination" : [ "obj-1", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-58", 0 ],
																						"destination" : [ "obj-59", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-52", 0 ],
																						"destination" : [ "obj-63", 0 ],
																						"order" : 0
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-52", 0 ],
																						"destination" : [ "obj-59", 0 ],
																						"order" : 1
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-51", 0 ],
																						"destination" : [ "obj-52", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-48", 0 ],
																						"destination" : [ "obj-62", 0 ],
																						"order" : 0
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-48", 0 ],
																						"destination" : [ "obj-51", 0 ],
																						"order" : 1
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-47", 0 ],
																						"destination" : [ "obj-48", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-46", 0 ],
																						"destination" : [ "obj-58", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-45", 0 ],
																						"destination" : [ "obj-47", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-42", 0 ],
																						"destination" : [ "obj-46", 0 ],
																						"order" : 0
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-42", 0 ],
																						"destination" : [ "obj-45", 0 ],
																						"order" : 1
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-41", 0 ],
																						"destination" : [ "obj-42", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-40", 0 ],
																						"destination" : [ "obj-41", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-39", 0 ],
																						"destination" : [ "obj-41", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-27", 0 ],
																						"destination" : [ "obj-48", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-25", 0 ],
																						"destination" : [ "obj-42", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-2", 0 ],
																						"destination" : [ "obj-43", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-1", 0 ],
																						"destination" : [ "obj-34", 0 ]
																					}

																				}
 ]
																		}

																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "--- allpass ---",
																		"id" : "obj-49",
																		"patching_rect" : [ 360.229980000000069, 313.0, 76.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "--- lfo ---",
																		"id" : "obj-30",
																		"patching_rect" : [ 372.229980000000126, 194.0, 52.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "x(n)",
																		"id" : "obj-7",
																		"patching_rect" : [ 96.5, 557.0, 29.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "/ 2.",
																		"id" : "obj-32",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 194.0, 25.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "+ 1.",
																		"id" : "obj-33",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 161.0, 29.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-35",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 307.729980000000012, 234.0, 222.000000000000057, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "cycle @index phase",
																		"id" : "obj-38",
																		"outlettype" : [ "", "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 124.0, 116.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 2
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 3",
																		"id" : "obj-26",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 510.729980000000069, 194.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 5",
																		"id" : "obj-23",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 348.229980000000126, 19.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "+",
																		"id" : "obj-29",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 57.0, 59.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "% 1.",
																		"id" : "obj-28",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 91.0, 33.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "scale 0. 1. 20. 135.",
																		"id" : "obj-20",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 307.729980000000012, 276.0, 110.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "mtof",
																		"id" : "obj-17",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 307.729980000000012, 313.0, 32.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 1",
																		"id" : "obj-1",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 58.5, 353.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 4",
																		"id" : "obj-2",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 467.459960000000024, 313.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 2",
																		"id" : "obj-3",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 19.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "out 1",
																		"id" : "obj-4",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 56.0, 687.0, 35.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "---- biquad ----",
																		"id" : "obj-5",
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 96.5, 353.0, 83.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "x(n-2)",
																		"id" : "obj-12",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 321.5, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "x(n-1)",
																		"id" : "obj-24",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 216.0, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "y(n-2)",
																		"id" : "obj-9",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 536.0, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "y(n-1)",
																		"id" : "obj-8",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 430.5, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-18",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 494.5, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-19",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 494.5, 509.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-21",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 389.5, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-22",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 389.5, 471.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-15",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 281.0, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-16",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 281.0, 435.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-14",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 176.0, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-13",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 176.0, 400.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "-",
																		"id" : "obj-11",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 56.0, 630.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-10",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 56.0, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
 ],
															"lines" : [ 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 0 ],
																		"destination" : [ "obj-21", 1 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 1 ],
																		"destination" : [ "obj-18", 1 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 2 ],
																		"destination" : [ "obj-15", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 0 ],
																		"destination" : [ "obj-14", 1 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 1 ],
																		"destination" : [ "obj-10", 1 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-38", 0 ],
																		"destination" : [ "obj-33", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-35", 0 ],
																		"destination" : [ "obj-20", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-33", 0 ],
																		"destination" : [ "obj-32", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-32", 0 ],
																		"destination" : [ "obj-35", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-3", 0 ],
																		"destination" : [ "obj-29", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-29", 0 ],
																		"destination" : [ "obj-28", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-28", 0 ],
																		"destination" : [ "obj-38", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-26", 0 ],
																		"destination" : [ "obj-35", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-23", 0 ],
																		"destination" : [ "obj-29", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-22", 0 ],
																		"destination" : [ "obj-21", 0 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-22", 0 ],
																		"destination" : [ "obj-19", 0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-21", 0 ],
																		"destination" : [ "obj-11", 1 ],
																		"midpoints" : [ 399.0, 608.5, 79.5, 608.5 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-20", 0 ],
																		"destination" : [ "obj-17", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-2", 0 ],
																		"destination" : [ "obj-54", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-19", 0 ],
																		"destination" : [ "obj-18", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-18", 0 ],
																		"destination" : [ "obj-11", 1 ],
																		"midpoints" : [ 504.0, 607.0, 79.5, 607.0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-17", 0 ],
																		"destination" : [ "obj-54", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-16", 0 ],
																		"destination" : [ "obj-15", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-15", 0 ],
																		"destination" : [ "obj-11", 0 ],
																		"midpoints" : [ 290.5, 594.5, 65.5, 594.5 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-14", 0 ],
																		"destination" : [ "obj-11", 0 ],
																		"midpoints" : [ 185.5, 593.5, 65.5, 593.5 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-13", 0 ],
																		"destination" : [ "obj-16", 0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-13", 0 ],
																		"destination" : [ "obj-14", 0 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-11", 0 ],
																		"destination" : [ "obj-4", 0 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-11", 0 ],
																		"destination" : [ "obj-22", 0 ],
																		"midpoints" : [ 65.5, 667.0, 595.25, 667.0, 595.25, 452.0, 399.0, 452.0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-10", 0 ],
																		"destination" : [ "obj-11", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-1", 0 ],
																		"destination" : [ "obj-13", 0 ],
																		"midpoints" : [ 68.0, 389.0, 185.5, 389.0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-1", 0 ],
																		"destination" : [ "obj-10", 0 ],
																		"order" : 1
																	}

																}
 ]
														}

													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "* 0.5",
														"id" : "obj-19",
														"outlettype" : [ "" ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 513.459960000000137, 415.0, 33.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "gen @title LFO-allpass",
														"id" : "obj-14",
														"outlettype" : [ "" ],
														"fontsize" : 12.0,
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 300.0, 360.0, 131.0, 22.0 ],
														"numinlets" : 5,
														"numoutlets" : 1,
														"patcher" : 														{
															"fileversion" : 1,
															"appversion" : 															{
																"major" : 8,
																"minor" : 5,
																"revision" : 3,
																"architecture" : "x64",
																"modernui" : 1
															}
,
															"classnamespace" : "dsp.gen",
															"rect" : [ 907.0, 79.0, 635.0, 739.0 ],
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
															"boxes" : [ 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "gen @title allpass-coeffs",
																		"id" : "obj-54",
																		"outlettype" : [ "", "", "" ],
																		"patching_rect" : [ 307.729980000000012, 353.0, 178.729980000000012, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 3,
																		"patcher" : 																		{
																			"fileversion" : 1,
																			"appversion" : 																			{
																				"major" : 8,
																				"minor" : 5,
																				"revision" : 3,
																				"architecture" : "x64",
																				"modernui" : 1
																			}
,
																			"classnamespace" : "dsp.gen",
																			"rect" : [ 878.0, 247.0, 333.0, 464.0 ],
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
																			"boxes" : [ 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "slide 5 5",
																						"id" : "obj-2",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 151.729980000000069, 386.0, 53.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "slide 5 5",
																						"id" : "obj-1",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 386.0, 53.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "a2",
																						"id" : "obj-68",
																						"patching_rect" : [ 259.729979999999955, 345.0, 22.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "1.",
																						"id" : "obj-66",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 238.729979999999955, 345.0, 19.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "a0, b2",
																						"id" : "obj-65",
																						"patching_rect" : [ 183.729980000000069, 345.0, 42.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "*",
																						"id" : "obj-63",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 151.729980000000069, 345.0, 29.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "!- 1.",
																						"id" : "obj-62",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 102.729980000000069, 265.0, 29.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "b1, a1",
																						"id" : "obj-61",
																						"patching_rect" : [ 90.729980000000069, 345.0, 42.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "*",
																						"id" : "obj-59",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 345.0, 29.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "* -2.",
																						"id" : "obj-58",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 158.729980000000069, 265.0, 31.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "cs",
																						"id" : "obj-57",
																						"patching_rect" : [ 189.729980000000069, 162.0, 20.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "sn",
																						"id" : "obj-56",
																						"patching_rect" : [ 32.0, 162.0, 21.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "b0",
																						"id" : "obj-54",
																						"patching_rect" : [ 31.5, 297.0, 22.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "!/ 1.",
																						"id" : "obj-52",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 297.0, 29.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "+ 1.",
																						"id" : "obj-51",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 265.0, 29.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "alpha",
																						"id" : "obj-50",
																						"patching_rect" : [ 18.0, 228.0, 38.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "/",
																						"id" : "obj-48",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 228.0, 61.999999999999943, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "* 0.5",
																						"id" : "obj-47",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 197.0, 33.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "cos",
																						"id" : "obj-46",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 158.729980000000069, 162.0, 27.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "sin",
																						"id" : "obj-45",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 162.0, 24.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "omega",
																						"id" : "obj-44",
																						"patching_rect" : [ 112.729980000000069, 121.0, 45.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "*",
																						"id" : "obj-42",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 121.0, 49.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "/",
																						"id" : "obj-41",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 90.729980000000069, 77.0, 29.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "twopi",
																						"id" : "obj-40",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 90.729980000000069, 44.0, 37.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "samplerate",
																						"id" : "obj-39",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 135.729980000000069, 44.0, 68.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "in 1",
																						"id" : "obj-25",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 44.0, 28.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "in 2",
																						"id" : "obj-27",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 102.729980000000012, 197.0, 28.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "out 1",
																						"id" : "obj-34",
																						"patching_rect" : [ 59.729980000000012, 427.0, 35.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "out 2",
																						"id" : "obj-43",
																						"patching_rect" : [ 151.729980000000012, 427.0, 35.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "out 3",
																						"id" : "obj-53",
																						"patching_rect" : [ 238.729979999999955, 427.0, 35.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
 ],
																			"lines" : [ 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-66", 0 ],
																						"destination" : [ "obj-53", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-63", 0 ],
																						"destination" : [ "obj-2", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-62", 0 ],
																						"destination" : [ "obj-63", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-59", 0 ],
																						"destination" : [ "obj-1", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-58", 0 ],
																						"destination" : [ "obj-59", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-52", 0 ],
																						"destination" : [ "obj-63", 0 ],
																						"order" : 0
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-52", 0 ],
																						"destination" : [ "obj-59", 0 ],
																						"order" : 1
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-51", 0 ],
																						"destination" : [ "obj-52", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-48", 0 ],
																						"destination" : [ "obj-62", 0 ],
																						"order" : 0
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-48", 0 ],
																						"destination" : [ "obj-51", 0 ],
																						"order" : 1
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-47", 0 ],
																						"destination" : [ "obj-48", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-46", 0 ],
																						"destination" : [ "obj-58", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-45", 0 ],
																						"destination" : [ "obj-47", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-42", 0 ],
																						"destination" : [ "obj-46", 0 ],
																						"order" : 0
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-42", 0 ],
																						"destination" : [ "obj-45", 0 ],
																						"order" : 1
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-41", 0 ],
																						"destination" : [ "obj-42", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-40", 0 ],
																						"destination" : [ "obj-41", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-39", 0 ],
																						"destination" : [ "obj-41", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-27", 0 ],
																						"destination" : [ "obj-48", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-25", 0 ],
																						"destination" : [ "obj-42", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-2", 0 ],
																						"destination" : [ "obj-43", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-1", 0 ],
																						"destination" : [ "obj-34", 0 ]
																					}

																				}
 ]
																		}

																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "--- allpass ---",
																		"id" : "obj-49",
																		"patching_rect" : [ 360.229980000000069, 313.0, 76.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "--- lfo ---",
																		"id" : "obj-30",
																		"patching_rect" : [ 372.229980000000126, 194.0, 52.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "x(n)",
																		"id" : "obj-7",
																		"patching_rect" : [ 96.5, 557.0, 29.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "/ 2.",
																		"id" : "obj-32",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 194.0, 25.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "+ 1.",
																		"id" : "obj-33",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 161.0, 29.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-35",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 307.729980000000012, 234.0, 222.000000000000057, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "cycle @index phase",
																		"id" : "obj-38",
																		"outlettype" : [ "", "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 124.0, 116.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 2
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 3",
																		"id" : "obj-26",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 510.729980000000069, 194.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 5",
																		"id" : "obj-23",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 348.229980000000126, 19.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "+",
																		"id" : "obj-29",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 57.0, 59.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "% 1.",
																		"id" : "obj-28",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 91.0, 33.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "scale 0. 1. 20. 135.",
																		"id" : "obj-20",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 307.729980000000012, 276.0, 110.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "mtof",
																		"id" : "obj-17",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 307.729980000000012, 313.0, 32.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 1",
																		"id" : "obj-1",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 58.5, 353.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 4",
																		"id" : "obj-2",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 467.459960000000024, 313.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 2",
																		"id" : "obj-3",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 19.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "out 1",
																		"id" : "obj-4",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 56.0, 687.0, 35.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "---- biquad ----",
																		"id" : "obj-5",
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 96.5, 353.0, 83.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "x(n-2)",
																		"id" : "obj-12",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 321.5, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "x(n-1)",
																		"id" : "obj-24",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 216.0, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "y(n-2)",
																		"id" : "obj-9",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 536.0, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "y(n-1)",
																		"id" : "obj-8",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 430.5, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-18",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 494.5, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-19",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 494.5, 509.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-21",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 389.5, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-22",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 389.5, 471.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-15",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 281.0, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-16",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 281.0, 435.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-14",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 176.0, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-13",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 176.0, 400.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "-",
																		"id" : "obj-11",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 56.0, 630.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-10",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 56.0, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
 ],
															"lines" : [ 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 0 ],
																		"destination" : [ "obj-21", 1 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 1 ],
																		"destination" : [ "obj-18", 1 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 2 ],
																		"destination" : [ "obj-15", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 0 ],
																		"destination" : [ "obj-14", 1 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 1 ],
																		"destination" : [ "obj-10", 1 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-38", 0 ],
																		"destination" : [ "obj-33", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-35", 0 ],
																		"destination" : [ "obj-20", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-33", 0 ],
																		"destination" : [ "obj-32", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-32", 0 ],
																		"destination" : [ "obj-35", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-3", 0 ],
																		"destination" : [ "obj-29", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-29", 0 ],
																		"destination" : [ "obj-28", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-28", 0 ],
																		"destination" : [ "obj-38", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-26", 0 ],
																		"destination" : [ "obj-35", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-23", 0 ],
																		"destination" : [ "obj-29", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-22", 0 ],
																		"destination" : [ "obj-21", 0 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-22", 0 ],
																		"destination" : [ "obj-19", 0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-21", 0 ],
																		"destination" : [ "obj-11", 1 ],
																		"midpoints" : [ 399.0, 608.5, 79.5, 608.5 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-20", 0 ],
																		"destination" : [ "obj-17", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-2", 0 ],
																		"destination" : [ "obj-54", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-19", 0 ],
																		"destination" : [ "obj-18", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-18", 0 ],
																		"destination" : [ "obj-11", 1 ],
																		"midpoints" : [ 504.0, 607.0, 79.5, 607.0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-17", 0 ],
																		"destination" : [ "obj-54", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-16", 0 ],
																		"destination" : [ "obj-15", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-15", 0 ],
																		"destination" : [ "obj-11", 0 ],
																		"midpoints" : [ 290.5, 594.5, 65.5, 594.5 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-14", 0 ],
																		"destination" : [ "obj-11", 0 ],
																		"midpoints" : [ 185.5, 593.5, 65.5, 593.5 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-13", 0 ],
																		"destination" : [ "obj-16", 0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-13", 0 ],
																		"destination" : [ "obj-14", 0 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-11", 0 ],
																		"destination" : [ "obj-4", 0 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-11", 0 ],
																		"destination" : [ "obj-22", 0 ],
																		"midpoints" : [ 65.5, 667.0, 595.25, 667.0, 595.25, 452.0, 399.0, 452.0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-10", 0 ],
																		"destination" : [ "obj-11", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-1", 0 ],
																		"destination" : [ "obj-13", 0 ],
																		"midpoints" : [ 68.0, 389.0, 185.5, 389.0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-1", 0 ],
																		"destination" : [ "obj-10", 0 ],
																		"order" : 1
																	}

																}
 ]
														}

													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "diffusion",
														"id" : "obj-7",
														"patching_rect" : [ 863.459960000000137, 269.0, 53.0, 20.0 ],
														"numinlets" : 1,
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "Q",
														"id" : "obj-2",
														"patching_rect" : [ 682.0, 304.0, 19.0, 20.0 ],
														"numinlets" : 1,
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "*",
														"id" : "obj-3",
														"outlettype" : [ "" ],
														"patching_rect" : [ 96.290039999999863, 482.0, 29.5, 22.0 ],
														"numinlets" : 2,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "comment",
														"text" : "max LFO rate",
														"linecount" : 2,
														"id" : "obj-35",
														"patching_rect" : [ 221.540039999999863, 139.5, 57.0, 33.0 ],
														"numinlets" : 1,
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "in 3",
														"id" : "obj-32",
														"outlettype" : [ "" ],
														"fontsize" : 12.0,
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
														"patching_rect" : [ 192.729980000000012, 45.0, 28.0, 22.0 ],
														"numinlets" : 0,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "dcblock",
														"id" : "obj-6",
														"outlettype" : [ "" ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 513.459960000000137, 449.0, 49.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 8.",
														"id" : "obj-49",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 834.959960000000137, 304.0, 25.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 8.",
														"id" : "obj-50",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 804.959960000000137, 304.0, 25.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "* 3.",
														"id" : "obj-52",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 834.959960000000137, 269.0, 27.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "* 1.",
														"id" : "obj-53",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 804.959960000000137, 269.0, 27.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "history",
														"id" : "obj-16",
														"outlettype" : [ "" ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 174.0, 229.0, 44.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "+",
														"id" : "obj-15",
														"outlettype" : [ "" ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 163.5, 305.0, 29.5, 22.0 ],
														"numinlets" : 2,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "*",
														"id" : "obj-11",
														"outlettype" : [ "" ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 174.0, 268.0, 65.0, 22.0 ],
														"numinlets" : 2,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "in 4",
														"id" : "obj-8",
														"outlettype" : [ "" ],
														"color" : [ 0.000000062398612, 0.0, 0.501960754394531, 1.0 ],
														"patching_rect" : [ 300.0, 166.0, 28.0, 22.0 ],
														"numinlets" : 0,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 8.",
														"id" : "obj-43",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 772.959960000000137, 304.0, 25.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "/ 8.",
														"id" : "obj-42",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 742.959960000000137, 304.0, 25.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "* 2.",
														"id" : "obj-40",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 772.959960000000137, 269.0, 27.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "* 0.",
														"id" : "obj-39",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 742.959960000000137, 269.0, 27.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "in 5",
														"id" : "obj-38",
														"outlettype" : [ "" ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"patching_rect" : [ 742.959960000000137, 230.0, 28.0, 22.0 ],
														"numinlets" : 0,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "out 2",
														"id" : "obj-23",
														"fontsize" : 12.0,
														"fontname" : "Arial",
														"patching_rect" : [ 136.290039999999863, 583.0, 35.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 0
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "in 2",
														"id" : "obj-21",
														"outlettype" : [ "" ],
														"fontsize" : 12.0,
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"patching_rect" : [ 430.419920000000275, 166.0, 28.0, 22.0 ],
														"numinlets" : 0,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "phasor",
														"id" : "obj-4",
														"outlettype" : [ "" ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
														"patching_rect" : [ 192.729980000000012, 179.0, 45.0, 22.0 ],
														"numinlets" : 2,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "gen @title LFO-allpass",
														"id" : "obj-5",
														"outlettype" : [ "" ],
														"fontsize" : 12.0,
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"patching_rect" : [ 165.0, 360.0, 131.0, 22.0 ],
														"numinlets" : 5,
														"numoutlets" : 1,
														"patcher" : 														{
															"fileversion" : 1,
															"appversion" : 															{
																"major" : 8,
																"minor" : 5,
																"revision" : 3,
																"architecture" : "x64",
																"modernui" : 1
															}
,
															"classnamespace" : "dsp.gen",
															"rect" : [ 907.0, 79.0, 635.0, 739.0 ],
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
															"boxes" : [ 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "gen @title allpass-coeffs",
																		"id" : "obj-54",
																		"outlettype" : [ "", "", "" ],
																		"patching_rect" : [ 307.729980000000012, 353.0, 178.729980000000012, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 3,
																		"patcher" : 																		{
																			"fileversion" : 1,
																			"appversion" : 																			{
																				"major" : 8,
																				"minor" : 5,
																				"revision" : 3,
																				"architecture" : "x64",
																				"modernui" : 1
																			}
,
																			"classnamespace" : "dsp.gen",
																			"rect" : [ 878.0, 247.0, 333.0, 464.0 ],
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
																			"boxes" : [ 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "slide 5 5",
																						"id" : "obj-2",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 151.729980000000069, 386.0, 53.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "slide 5 5",
																						"id" : "obj-1",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 386.0, 53.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "a2",
																						"id" : "obj-68",
																						"patching_rect" : [ 259.729979999999955, 345.0, 22.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "1.",
																						"id" : "obj-66",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 238.729979999999955, 345.0, 19.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "a0, b2",
																						"id" : "obj-65",
																						"patching_rect" : [ 183.729980000000069, 345.0, 42.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "*",
																						"id" : "obj-63",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 151.729980000000069, 345.0, 29.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "!- 1.",
																						"id" : "obj-62",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 102.729980000000069, 265.0, 29.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "b1, a1",
																						"id" : "obj-61",
																						"patching_rect" : [ 90.729980000000069, 345.0, 42.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "*",
																						"id" : "obj-59",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 345.0, 29.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "* -2.",
																						"id" : "obj-58",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 158.729980000000069, 265.0, 31.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "cs",
																						"id" : "obj-57",
																						"patching_rect" : [ 189.729980000000069, 162.0, 20.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "sn",
																						"id" : "obj-56",
																						"patching_rect" : [ 32.0, 162.0, 21.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "b0",
																						"id" : "obj-54",
																						"patching_rect" : [ 31.5, 297.0, 22.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "!/ 1.",
																						"id" : "obj-52",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 297.0, 29.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "+ 1.",
																						"id" : "obj-51",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 265.0, 29.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "alpha",
																						"id" : "obj-50",
																						"patching_rect" : [ 18.0, 228.0, 38.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "/",
																						"id" : "obj-48",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 228.0, 61.999999999999943, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "* 0.5",
																						"id" : "obj-47",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 197.0, 33.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "cos",
																						"id" : "obj-46",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 158.729980000000069, 162.0, 27.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "sin",
																						"id" : "obj-45",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 162.0, 24.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "comment",
																						"text" : "omega",
																						"id" : "obj-44",
																						"patching_rect" : [ 112.729980000000069, 121.0, 45.0, 20.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "*",
																						"id" : "obj-42",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 121.0, 49.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "/",
																						"id" : "obj-41",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 90.729980000000069, 77.0, 29.5, 22.0 ],
																						"numinlets" : 2,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "twopi",
																						"id" : "obj-40",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 90.729980000000069, 44.0, 37.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "samplerate",
																						"id" : "obj-39",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 135.729980000000069, 44.0, 68.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "in 1",
																						"id" : "obj-25",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 59.729980000000069, 44.0, 28.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "in 2",
																						"id" : "obj-27",
																						"outlettype" : [ "" ],
																						"patching_rect" : [ 102.729980000000012, 197.0, 28.0, 22.0 ],
																						"numinlets" : 0,
																						"numoutlets" : 1
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "out 1",
																						"id" : "obj-34",
																						"patching_rect" : [ 59.729980000000012, 427.0, 35.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "out 2",
																						"id" : "obj-43",
																						"patching_rect" : [ 151.729980000000012, 427.0, 35.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
, 																				{
																					"box" : 																					{
																						"maxclass" : "newobj",
																						"text" : "out 3",
																						"id" : "obj-53",
																						"patching_rect" : [ 238.729979999999955, 427.0, 35.0, 22.0 ],
																						"numinlets" : 1,
																						"numoutlets" : 0
																					}

																				}
 ],
																			"lines" : [ 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-66", 0 ],
																						"destination" : [ "obj-53", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-63", 0 ],
																						"destination" : [ "obj-2", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-62", 0 ],
																						"destination" : [ "obj-63", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-59", 0 ],
																						"destination" : [ "obj-1", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-58", 0 ],
																						"destination" : [ "obj-59", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-52", 0 ],
																						"destination" : [ "obj-63", 0 ],
																						"order" : 0
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-52", 0 ],
																						"destination" : [ "obj-59", 0 ],
																						"order" : 1
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-51", 0 ],
																						"destination" : [ "obj-52", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-48", 0 ],
																						"destination" : [ "obj-62", 0 ],
																						"order" : 0
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-48", 0 ],
																						"destination" : [ "obj-51", 0 ],
																						"order" : 1
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-47", 0 ],
																						"destination" : [ "obj-48", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-46", 0 ],
																						"destination" : [ "obj-58", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-45", 0 ],
																						"destination" : [ "obj-47", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-42", 0 ],
																						"destination" : [ "obj-46", 0 ],
																						"order" : 0
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-42", 0 ],
																						"destination" : [ "obj-45", 0 ],
																						"order" : 1
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-41", 0 ],
																						"destination" : [ "obj-42", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-40", 0 ],
																						"destination" : [ "obj-41", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-39", 0 ],
																						"destination" : [ "obj-41", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-27", 0 ],
																						"destination" : [ "obj-48", 1 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-25", 0 ],
																						"destination" : [ "obj-42", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-2", 0 ],
																						"destination" : [ "obj-43", 0 ]
																					}

																				}
, 																				{
																					"patchline" : 																					{
																						"source" : [ "obj-1", 0 ],
																						"destination" : [ "obj-34", 0 ]
																					}

																				}
 ]
																		}

																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "--- allpass ---",
																		"id" : "obj-49",
																		"patching_rect" : [ 360.229980000000069, 313.0, 76.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "--- lfo ---",
																		"id" : "obj-30",
																		"patching_rect" : [ 372.229980000000126, 194.0, 52.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "x(n)",
																		"id" : "obj-7",
																		"patching_rect" : [ 96.5, 557.0, 29.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "/ 2.",
																		"id" : "obj-32",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 194.0, 25.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "+ 1.",
																		"id" : "obj-33",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 161.0, 29.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-35",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 307.729980000000012, 234.0, 222.000000000000057, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "cycle @index phase",
																		"id" : "obj-38",
																		"outlettype" : [ "", "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 124.0, 116.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 2
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 3",
																		"id" : "obj-26",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 510.729980000000069, 194.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 5",
																		"id" : "obj-23",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 348.229980000000126, 19.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "+",
																		"id" : "obj-29",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 57.0, 59.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "% 1.",
																		"id" : "obj-28",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 91.0, 33.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "scale 0. 1. 20. 135.",
																		"id" : "obj-20",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 307.729980000000012, 276.0, 110.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "mtof",
																		"id" : "obj-17",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 307.729980000000012, 313.0, 32.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 1",
																		"id" : "obj-1",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 58.5, 353.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 4",
																		"id" : "obj-2",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 467.459960000000024, 313.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "in 2",
																		"id" : "obj-3",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"patching_rect" : [ 308.229980000000126, 19.0, 28.0, 22.0 ],
																		"numinlets" : 0,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "out 1",
																		"id" : "obj-4",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 56.0, 687.0, 35.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "---- biquad ----",
																		"id" : "obj-5",
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 96.5, 353.0, 83.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "x(n-2)",
																		"id" : "obj-12",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 321.5, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "x(n-1)",
																		"id" : "obj-24",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 216.0, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "y(n-2)",
																		"id" : "obj-9",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 536.0, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "comment",
																		"text" : "y(n-1)",
																		"id" : "obj-8",
																		"fontsize" : 12.0,
																		"patching_rect" : [ 430.5, 557.0, 40.0, 20.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 0
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-18",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 494.5, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-19",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 494.5, 509.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-21",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 389.5, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-22",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 389.5, 471.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-15",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 281.0, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-16",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 281.0, 435.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-14",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 176.0, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "history",
																		"id" : "obj-13",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 176.0, 400.0, 49.0, 22.0 ],
																		"numinlets" : 1,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "-",
																		"id" : "obj-11",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 56.0, 630.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
, 																{
																	"box" : 																	{
																		"maxclass" : "newobj",
																		"text" : "*",
																		"id" : "obj-10",
																		"outlettype" : [ "" ],
																		"fontsize" : 12.0,
																		"fontname" : "Arial",
																		"patching_rect" : [ 56.0, 557.0, 33.0, 22.0 ],
																		"numinlets" : 2,
																		"numoutlets" : 1
																	}

																}
 ],
															"lines" : [ 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 0 ],
																		"destination" : [ "obj-21", 1 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 1 ],
																		"destination" : [ "obj-18", 1 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 2 ],
																		"destination" : [ "obj-15", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 0 ],
																		"destination" : [ "obj-14", 1 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-54", 1 ],
																		"destination" : [ "obj-10", 1 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-38", 0 ],
																		"destination" : [ "obj-33", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-35", 0 ],
																		"destination" : [ "obj-20", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-33", 0 ],
																		"destination" : [ "obj-32", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-32", 0 ],
																		"destination" : [ "obj-35", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-3", 0 ],
																		"destination" : [ "obj-29", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-29", 0 ],
																		"destination" : [ "obj-28", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-28", 0 ],
																		"destination" : [ "obj-38", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-26", 0 ],
																		"destination" : [ "obj-35", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-23", 0 ],
																		"destination" : [ "obj-29", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-22", 0 ],
																		"destination" : [ "obj-21", 0 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-22", 0 ],
																		"destination" : [ "obj-19", 0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-21", 0 ],
																		"destination" : [ "obj-11", 1 ],
																		"midpoints" : [ 399.0, 608.5, 79.5, 608.5 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-20", 0 ],
																		"destination" : [ "obj-17", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-2", 0 ],
																		"destination" : [ "obj-54", 1 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-19", 0 ],
																		"destination" : [ "obj-18", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-18", 0 ],
																		"destination" : [ "obj-11", 1 ],
																		"midpoints" : [ 504.0, 607.0, 79.5, 607.0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-17", 0 ],
																		"destination" : [ "obj-54", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-16", 0 ],
																		"destination" : [ "obj-15", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-15", 0 ],
																		"destination" : [ "obj-11", 0 ],
																		"midpoints" : [ 290.5, 594.5, 65.5, 594.5 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-14", 0 ],
																		"destination" : [ "obj-11", 0 ],
																		"midpoints" : [ 185.5, 593.5, 65.5, 593.5 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-13", 0 ],
																		"destination" : [ "obj-16", 0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-13", 0 ],
																		"destination" : [ "obj-14", 0 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-11", 0 ],
																		"destination" : [ "obj-4", 0 ],
																		"order" : 1
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-11", 0 ],
																		"destination" : [ "obj-22", 0 ],
																		"midpoints" : [ 65.5, 667.0, 595.25, 667.0, 595.25, 452.0, 399.0, 452.0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-10", 0 ],
																		"destination" : [ "obj-11", 0 ]
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-1", 0 ],
																		"destination" : [ "obj-13", 0 ],
																		"midpoints" : [ 68.0, 389.0, 185.5, 389.0 ],
																		"order" : 0
																	}

																}
, 																{
																	"patchline" : 																	{
																		"source" : [ "obj-1", 0 ],
																		"destination" : [ "obj-10", 0 ],
																		"order" : 1
																	}

																}
 ]
														}

													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "3",
														"id" : "obj-13",
														"outlettype" : [ "" ],
														"fontsize" : 12.0,
														"color" : [ 0.12775145471096, 0.999752759933472, 0.999038398265839, 1.0 ],
														"patching_rect" : [ 656.0, 304.0, 19.0, 22.0 ],
														"numinlets" : 0,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "* 5.",
														"id" : "obj-10",
														"outlettype" : [ "" ],
														"fontsize" : 12.0,
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
														"patching_rect" : [ 192.729980000000012, 145.0, 27.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 1
													}

												}
, 												{
													"box" : 													{
														"maxclass" : "newobj",
														"text" : "out 1",
														"id" : "obj-12",
														"fontsize" : 12.0,
														"fontname" : "Arial",
														"patching_rect" : [ 96.290039999999863, 583.0, 35.0, 22.0 ],
														"numinlets" : 1,
														"numoutlets" : 0
													}

												}
 ],
											"lines" : [ 												{
													"patchline" : 													{
														"source" : [ "obj-30", 0 ],
														"destination" : [ "obj-23", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-31", 0 ],
														"destination" : [ "obj-12", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-1", 0 ],
														"destination" : [ "obj-3", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 4
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-1", 0 ],
														"destination" : [ "obj-15", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 2
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-1", 0 ],
														"destination" : [ "obj-25", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 3
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-1", 0 ],
														"destination" : [ "obj-36", 0 ],
														"color" : [ 0.298039227724075, 0.298039257526398, 0.298039197921753, 1.0 ],
														"midpoints" : [ 155.790039999999863, 198.0, 178.0, 198.0, 178.0, 16.0, 701.0, 16.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-1", 0 ],
														"destination" : [ "obj-55", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-58", 0 ],
														"destination" : [ "obj-67", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-38", 0 ],
														"destination" : [ "obj-39", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"order" : 3
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-38", 0 ],
														"destination" : [ "obj-40", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"order" : 2
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-38", 0 ],
														"destination" : [ "obj-52", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-38", 0 ],
														"destination" : [ "obj-53", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-8", 0 ],
														"destination" : [ "obj-11", 1 ],
														"color" : [ 0.000000062398612, 0.0, 0.501960754394531, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-8", 0 ],
														"destination" : [ "obj-57", 1 ],
														"color" : [ 0.000000062398612, 0.0, 0.501960754394531, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-8", 0 ],
														"destination" : [ "obj-90", 0 ],
														"color" : [ 0.000000062398612, 0.0, 0.501960754394531, 1.0 ],
														"order" : 2
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-32", 0 ],
														"destination" : [ "obj-89", 0 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-21", 0 ],
														"destination" : [ "obj-28", 0 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-90", 0 ],
														"destination" : [ "obj-3", 1 ],
														"color" : [ 0.000000062398612, 0.0, 0.501960754394531, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-90", 0 ],
														"destination" : [ "obj-25", 1 ],
														"color" : [ 0.000000062398612, 0.0, 0.501960754394531, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-89", 0 ],
														"destination" : [ "obj-29", 0 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-85", 0 ],
														"destination" : [ "obj-83", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-84", 0 ],
														"destination" : [ "obj-82", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-83", 0 ],
														"destination" : [ "obj-65", 2 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-82", 0 ],
														"destination" : [ "obj-65", 1 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-79", 0 ],
														"destination" : [ "obj-67", 2 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-68", 0 ],
														"destination" : [ "obj-5", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 3
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-68", 0 ],
														"destination" : [ "obj-24", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-68", 0 ],
														"destination" : [ "obj-20", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-68", 0 ],
														"destination" : [ "obj-14", 2 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ],
														"order" : 2
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-67", 0 ],
														"destination" : [ "obj-65", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-65", 0 ],
														"destination" : [ "obj-28", 1 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-6", 0 ],
														"destination" : [ "obj-54", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-57", 0 ],
														"destination" : [ "obj-55", 1 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-55", 0 ],
														"destination" : [ "obj-24", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-55", 0 ],
														"destination" : [ "obj-20", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-54", 0 ],
														"destination" : [ "obj-57", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-53", 0 ],
														"destination" : [ "obj-50", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-52", 0 ],
														"destination" : [ "obj-49", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-50", 0 ],
														"destination" : [ "obj-24", 4 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-5", 0 ],
														"destination" : [ "obj-3", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-5", 0 ],
														"destination" : [ "obj-19", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-49", 0 ],
														"destination" : [ "obj-20", 4 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-43", 0 ],
														"destination" : [ "obj-14", 4 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-42", 0 ],
														"destination" : [ "obj-5", 4 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-40", 0 ],
														"destination" : [ "obj-43", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-4", 0 ],
														"destination" : [ "obj-5", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
														"order" : 3
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-4", 0 ],
														"destination" : [ "obj-24", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-4", 0 ],
														"destination" : [ "obj-20", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-4", 0 ],
														"destination" : [ "obj-14", 1 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ],
														"order" : 2
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-39", 0 ],
														"destination" : [ "obj-42", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-36", 0 ],
														"destination" : [ "obj-26", 0 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-34", 0 ],
														"destination" : [ "obj-16", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-33", 0 ],
														"destination" : [ "obj-34", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-3", 0 ],
														"destination" : [ "obj-31", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-29", 0 ],
														"destination" : [ "obj-10", 0 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-28", 0 ],
														"destination" : [ "obj-68", 0 ],
														"color" : [ 0.50195974111557, 0.0, 0.008130922913551, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-26", 0 ],
														"destination" : [ "obj-67", 1 ],
														"color" : [ 0.064120709896088, 0.501819789409637, 0.501972615718842, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-25", 0 ],
														"destination" : [ "obj-30", 0 ],
														"color" : [ 0.19999997317791, 0.199999943375587, 0.19999997317791, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-24", 0 ],
														"destination" : [ "obj-33", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-24", 0 ],
														"destination" : [ "obj-25", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-20", 0 ],
														"destination" : [ "obj-33", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-20", 0 ],
														"destination" : [ "obj-25", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-19", 0 ],
														"destination" : [ "obj-6", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-16", 0 ],
														"destination" : [ "obj-11", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-15", 0 ],
														"destination" : [ "obj-5", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-15", 0 ],
														"destination" : [ "obj-14", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-14", 0 ],
														"destination" : [ "obj-3", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-14", 0 ],
														"destination" : [ "obj-19", 0 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-13", 0 ],
														"destination" : [ "obj-5", 3 ],
														"color" : [ 0.12775145471096, 0.999752759933472, 0.999038398265839, 1.0 ],
														"order" : 3
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-13", 0 ],
														"destination" : [ "obj-24", 3 ],
														"color" : [ 0.12775145471096, 0.999752759933472, 0.999038398265839, 1.0 ],
														"order" : 1
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-13", 0 ],
														"destination" : [ "obj-20", 3 ],
														"color" : [ 0.12775145471096, 0.999752759933472, 0.999038398265839, 1.0 ],
														"order" : 0
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-13", 0 ],
														"destination" : [ "obj-14", 3 ],
														"color" : [ 0.12775145471096, 0.999752759933472, 0.999038398265839, 1.0 ],
														"order" : 2
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-11", 0 ],
														"destination" : [ "obj-15", 1 ],
														"color" : [ 0.501960813999176, 0.0, 0.501960813999176, 1.0 ]
													}

												}
, 												{
													"patchline" : 													{
														"source" : [ "obj-10", 0 ],
														"destination" : [ "obj-4", 0 ],
														"color" : [ 0.065929934382439, 0.501798808574677, 0.006832201499492, 1.0 ]
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
									"patching_rect" : [ 54.0, 217.0, 118.0, 23.0 ],
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
									"text" : "gen~ @title Phaser2",
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
									"destination" : [ "obj-22", 5 ],
									"source" : [ "obj-10", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-10", 0 ],
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-22", 2 ],
									"source" : [ "obj-14", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-14", 0 ],
									"source" : [ "obj-15", 0 ]
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
									"destination" : [ "obj-22", 1 ],
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
									"plugin_name" : "IDM-Phaser2-plugin",
									"openexportdirectory" : 1
								}

							}

						}

					}
,
					"patching_rect" : [ 81.0, 427.0, 148.0, 22.0 ],
					"rnboattrcache" : 					{
						"depth" : 						{
							"label" : "depth",
							"isEnum" : 0,
							"parsestring" : ""
						}
,
						"diffusion" : 						{
							"label" : "diffusion",
							"isEnum" : 0,
							"parsestring" : ""
						}
,
						"rate" : 						{
							"label" : "rate",
							"isEnum" : 0,
							"parsestring" : ""
						}
,
						"fb" : 						{
							"label" : "fb",
							"isEnum" : 0,
							"parsestring" : ""
						}
,
						"env" : 						{
							"label" : "env",
							"isEnum" : 1,
							"parsestring" : "\"off\" \"on\""
						}

					}
,
					"rnboversion" : "1.1.0",
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_invisible" : 1,
							"parameter_longname" : "rnbo~[1]",
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
							"env" : 							{
								"value" : 0.0
							}
,
							"fb" : 							{
								"value" : 0.7
							}
,
							"rate" : 							{
								"value" : 0.1
							}
,
							"depth" : 							{
								"value" : 1.0
							}
,
							"diffusion" : 							{
								"value" : 1.0
							}
,
							"__presetid" : "IDM-Phaser2"
						}
,
						"snapshotlist" : 						{
							"current_snapshot" : 0,
							"entries" : [ 								{
									"filetype" : "C74Snapshot",
									"version" : 2,
									"minorversion" : 0,
									"name" : "Lowpass",
									"origin" : "IDM-Phaser2",
									"type" : "rnbo",
									"subtype" : "",
									"embed" : 0,
									"snapshot" : 									{
										"env" : 										{
											"value" : 0.0
										}
,
										"fb" : 										{
											"value" : 0.7
										}
,
										"rate" : 										{
											"value" : 0.1
										}
,
										"depth" : 										{
											"value" : 1.0
										}
,
										"diffusion" : 										{
											"value" : 1.0
										}
,
										"__presetid" : "IDM-Phaser2"
									}
,
									"fileref" : 									{
										"name" : "Lowpass",
										"filename" : "Lowpass_20230222_5.maxsnap",
										"filepath" : "~/Documents/Max 8/Snapshots",
										"filepos" : -1,
										"snapshotfileid" : "47427f8f3db228b4c826135e8763a5e6"
									}

								}
 ]
						}

					}
,
					"text" : "rnbo~ @title IDM-Phaser2",
					"varname" : "Phaser2"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
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
					"destination" : [ "obj-13", 0 ],
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 1 ],
					"source" : [ "obj-22", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"source" : [ "obj-24", 0 ]
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
					"destination" : [ "obj-7", 1 ],
					"midpoints" : [ 97.75, 682.5, 116.5, 682.5 ],
					"source" : [ "obj-6", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"source" : [ "obj-6", 0 ]
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
			"obj-2" : [ "fb", "fb", 0 ],
			"obj-22" : [ "rnbo~[1]", "rnbo~", 0 ],
			"obj-24" : [ "diffusion", "diffusion", 0 ],
			"obj-28" : [ "rate", "rate", 0 ],
			"obj-30" : [ "depth[1]", "depth", 0 ],
			"obj-6" : [ "live.gain~", "live.gain~", 0 ],
			"parameterbanks" : 			{

			}
,
			"inherited_shortname" : 1
		}
,
		"dependency_cache" : [ 			{
				"name" : "Lowpass_20230222_5.maxsnap",
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
