# NYU Integrated Design & Media
## IDM PEDALS
How to make effect pedals based on the [Electrosmith Daisy](https://www.electro-smith.com/daisy)!

NYU Tandon Undergraduate Summer Research Project, 2021-22

Last updated Fall, 2022.

- [Overview](#overview)
- [Oopsy Basics](#oopsy-basics)
- [Glossary](./glossary.md)
- [The Pedals](./pedals.md)

# Overview

**IDM Pedals** is an open-source repository of audio signal processing algorithms designed, from a user experience standpoint, to be deployed as [effects pedals](https://en.wikipedia.org/wiki/Effects_unit). The repository contains software implementations of a wide variety of effects, ranging from canonical 1960s analog distortions to common digital effects from the 1980s to studies on more modern and esoteric effects. The repository consists of Max/MSP patches written in the [**gen~**](https://docs.cycling74.com/max8/vignettes/gen_overview) language and intended to be used with the [Electrosmith Daisy](https://www.electro-smith.com/) platform; the system used in this repository can be easily adapted to other architectures, however, including software-only (VST, Max4Live), or other embedded implementations (via the C++ code export or the [RNBO](https://rnbo.cycling74.com/) system). 

The project is intended to be a resource for people interested in learning about:
* Digital signal processing algorithms specifically designed for modifying an input audio signal ("audio effects")
* Historical analog and digital audio effects design
* Effects pedals
* The gen~ architecture of Max and the Electrosmith Daisy platform
* Any combination of the above

# Oopsy basics

The **IDM Pedals** project uses the [oopsy](https://github.com/electro-smith/oopsy) package to transmit gen~ patches in Max/MSP directly to an Electrosmith Daisy chip. The patches in this repository are designed for the [Daisy Petal](https://www.perfectcircuit.com/electrosmith-daisy-petal.html) prototyping board:

<img src = "./img/petal.jpg" width="100%" title="Daisy Petal" alt="Daisy Petal">

The patches contained in the repository consists of numbered and categorized Max/MSP patches that each contain a gen~ subpatch to be uploaded to the Daisy chip. *The gen~ patcher is the actual effect algorithm*; the host Max/MSP patch contains objects for previewing and working with the patch in Max.

The Max/MSP patches all rely on a **bpatcher** object called "testinput_bpatch.maxpat", as well as **toggle** and **live.dial** objects to simulate using the effect within Max, e.g.:

<img src = "./img/mainpatcher.png" width="50%" title="Example Host Patch" alt="Example Host Patch">

An oopsy **bpatcher** in each patch (seen in the upper-right of the example above) allows you to transmit the **gen~** code to the Daisy directly from Max. If you double-click the **gen~** object in the middle of the patch, you will see the actual effect algorithm that will be sent to the chip.

There are a number of utility abstractions used by the **gen~** code in this project, most notably:

<img src = "./img/swtoggle.gendsp.png" width="25%" title="Software toggle subpatch" alt="Software toggle subpatch">

This is a "software toggle" algorithm to allow the left-hand toggle switch on the Daisy Petal board to act as a bypass switch for the effect. If you want to use these algorithms in a different context, this is probably the first thing you would remove.

<img src = "./img/oopsy.ctrl.smooth3.gendsp.png" width="50%" title="Oopsy smoothing subpatch" alt="Oopsy smoothing subpatch">

This is a third-order smoothing filter that is applied to many (but not all) knob inputs in the algorithms in this project; this helps prevent any A/D jitter from the analog controls on the physical pedal from having a negative effect on the effect's behavior.

[back to top](#top)
