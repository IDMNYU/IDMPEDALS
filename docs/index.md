# NYU Integrated Design & Media
## IDM PEDALS
How to make effect pedals based on the [Electrosmith Daisy](https://www.electro-smith.com/daisy)!

NYU Tandon Undergraduate Summer Research Project, 2021-22

Last updated Fall, 2022.

- [Overview](#overview)
- [Oopsy Basics](#oopsy-basics)
- [Glossary](#glossary)
- [The Pedals](#pedals)
  - [EQ](#eq)
    - [Lowpass Filter](#eq-lowpass)
    - [Parametric EQ](#eq-parametric)
    - [Fixed Crossover Filter](#eq-xover)
    - [Variable Crossover Filter](#eq-xover2)
    - [Mu-Tron Wah](#eq-wah)
    - [LFO Auto-Wah](#eq-wah2)
    - [Formant Filter](#eq-formant)
    - [Vocoder](#eq-vocoder)
  - [Dynamics](#dynamics)
    - [Tremolo / Univibe](#dyn-tremolo)
    - [Compressor / Limiter](#dyn-compressor)
    - [Gate](#dyn-gate)
  - [Distortion](#distortion)
    - [Overdrive](#dist-overdrive)
    - [Fuzz](#dist-fuzz)
    - [Octave Fuzz](#dist-octavia)
    - [Amp Distortion](#dist-distortion) 
    - [Crunch Distortion](#dist-distortion2) 
    - [Clipping, Folding, Wrapping](#dist-waveshaper) 
    - [Parametric Waveshaping](#dist-waveshaper2) 
  - [Modulation](#modulation)
    - [Simple Chorus](#mod-chorus) 
    - [Chorus Ensemble](#mod-chorus2) 
    - [Flanger](#mod-flanger) 
    - [Simple Phaser](#mod-phaser) 
    - [Multi-stage Phaser](#mod-phaser2) 
    - [Harmonizer](#mod-harmonizer) 
    - [S&H Comb](#mod-shcomb) 
    - [Harmonic Filters](#mod-shcomb2) 
  - [Delay](#delay)
    - [Digital Delay](#del-digitaldelay) 
    - [Multi-tap Delay](#del-digitaldelay2) 
    - [Chowning Reverb](#del-reverb) 
    - [Freeverb](#del-reverb2) 
    - [Creepy Reverb](#del-reverb3) 
  - [Special FX](#special)
    - [Subharmonic Oscillator](#sfx-subharmonic) 
    - [Sample-and-Hold Sine](#sfx-shsine) 
    - [Ring Modulator](#sfx-ringmod) 
    - [Frequency Shifter](#sfx-freqshift) 
    - [FM Delay](#sfx-fmdelay) 
    - [Glitch Sampler](#sfx-glitch) 
    - [Reverse Sampler](#sfx-glitch2) 
    - [Yin Synthesizer](#sfx-yin) 



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

# Glossary

Effects pedals (and audio signal processing techniques in general) have a jargon. Before looking at the pedals themselves, here's a brief glossary of some terms commonly found in effect pedal documentation; many others will be introduced when talking about the pedals themselves:

- [**Analog Electronics**](https://en.wikipedia.org/wiki/Analogue_electronics) - refers to electronic circuits that work - at least primarily - with continuous (as opposed to discrete) signal levels. More broadly, an **analog** signal can be thought of as any representation of a phenemenon (e.g. a sound pressure wave) that is *analogous* to the phenomenon itself; this is in contrast to a **digital** signal, where the signal is quantized and encoded into numerical values that are represented in electronic systems through discrete (typically binary - on or off) signals.

- [**Analog to Digital Converter**]([https://en.wikipedia.org/wiki/CV/Gate](https://en.wikipedia.org/wiki/Analog-to-digital_converter)) (**ADC** or **A/D**) - circuitry that takes a continuous (*analog*) signal and converts it into a discrete, numerical *sample* encoded as a *digital* signal. The speed at which the conversion of the signal occurs is called the *sampling rate*; the resolution (range of values) of each sample is called the *bit depth*. Different media have different common techniques for analog-to-digital conversion, including [Pulse Code Modulation](https://en.wikipedia.org/wiki/Pulse-code_modulation) (PCM) and [Sigma-Delta](https://en.wikipedia.org/wiki/Delta-sigma_modulation) (Σ-Δ).

- [**Bit Depth**](https://en.wikipedia.org/wiki/Audio_bit_depth) - the number of bits allocated for each sample in a digital audio signal; in [PCM]((https://en.wikipedia.org/wiki/Pulse-code_modulation))-encoded audio, this value directly correlates to the resolution of how the signal's amplitude is recorded. Each additional bit of resolution doubles the range of possible values for the sample, giving approximately a 6dB boost to the signal-to-noise ratio. CD-quality audio has a 16-bit resolution (with sample values in the range of −32,768 to +32,767); modern professional-quality audio systems typically have a 24-bit resolution or higher.

- [**Bucket-Brigade Device**](https://en.wikipedia.org/wiki/Bucket-brigade_device) (**BBD**) - is a circuit that allows for the delay of analog signals using an array of capacitors where each capacitor discharges into the next in the array (the "bucket brigade"). In analog audio 

- [**Buffer**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Bypass**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Capacitor**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Clipping**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Delay**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Diode**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Distortion / Fuzz / Overdrive**](https://en.wikipedia.org/wiki/CV/Gate) (**DAC**) - words words words.

- [**Digital Signal Processing**](https://en.wikipedia.org/wiki/CV/Gate) (**DSP**) - words words words.

- [**Digital to Analog Converter**](https://en.wikipedia.org/wiki/CV/Gate) (**DAC**) - words words words.

- [**Dynamics Processing**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Equalization**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Envelope Follower**](https://en.wikipedia.org/wiki/CV/Gate) (**EQ**) - words words words.

- [**Expression Pedal**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Feedback**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Filter**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Gain**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Low Frequency Oscillator**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**MIDI**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Modulation**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Nyquist theorem**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Operational Amplifier**](https://en.wikipedia.org/wiki/CV/Gate) (**Op Amp**) - words words words.

- [**Pitch Tracker**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Potentiometer**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Resistor**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Sample**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Sample and Hold**](https://en.wikipedia.org/wiki/CV/Gate) (**S&H**) - words words words.

- [**Sampling Rate**](https://en.wikipedia.org/wiki/CV/Gate) (**SR**) - words words words.

- [**Signal-to-noise Ratio**](https://en.wikipedia.org/wiki/CV/Gate) (**SNR**) - words words words.

- [**Switch**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Transistor**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Waveshaping**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

- [**Vactrol**](https://en.wikipedia.org/wiki/CV/Gate) - words words words.

# Pedals

## EQ

### EQ Lowpass

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Lowpass.png" target="_new"><img src = "./img/Lowpass.png" title="Lowpass patcher" alt="Lowpass patcher"></a>

### EQ Parametric

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Parametric.png" target="_new"><img src = "./img/Parametric.png" title="Parametric patcher" alt="Parametric patcher"></a>

### EQ Xover

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Xover.png" target="_new"><img src = "./img/Xover.png" title="Xover patcher" alt="Xover patcher"></a>

### EQ Xover2

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Xover2.png" target="_new"><img src = "./img/Xover2.png" title="Xover2 patcher" alt="Xover2 patcher"></a>

### EQ Wah

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Wah.png" target="_new"><img src = "./img/Wah.png" title="Wah patcher" alt="Wah patcher"></a>

### EQ Wah2

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Wah2.png" target="_new"><img src = "./img/Wah2.png" title="Wah2 patcher" alt="Wah2 patcher"></a>

### EQ Formant

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Formant.png" target="_new"><img src = "./img/Formant.png" title="Formant patcher" alt="Formant patcher"></a>

### EQ Vocoder

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Vocoder.png" target="_new"><img src = "./img/Vocoder.png" title="Vocoder patcher" alt="Vocoder patcher"></a>

## Dynamics

### Dyn Tremolo

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Tremolo.png" target="_new"><img src = "./img/Tremolo.png" title="Tremolo patcher" alt="Tremolo patcher"></a>

### Dyn Compressor

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Compressor.png" target="_new"><img src = "./img/Compressor.png" title="Compressor patcher" alt="Compressor patcher"></a>

### Dyn Gate

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Gate.png" target="_new"><img src = "./img/Gate.png" title="Gate patcher" alt="Gate patcher"></a>

## Distortion

### Dist Overdrive

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Overdrive.png" target="_new"><img src = "./img/Overdrive.png" title="Overdrive patcher" alt="Overdrive patcher"></a>

### Dist Fuzz

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Fuzz.png" target="_new"><img src = "./img/Fuzz.png" title="Fuzz patcher" alt="Fuzz patcher"></a>

### Dist Octavia

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Octavia.png" target="_new"><img src = "./img/Octavia.png" title="Octavia patcher" alt="Octavia patcher"></a>

### Dist Distortion

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Distortion.png" target="_new"><img src = "./img/Distortion.png" title="Distortion patcher" alt="Distortion patcher"></a>

### Dist Distortion2

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Distortion2.png" target="_new"><img src = "./img/Distortion2.png" title="Distortion2 patcher" alt="Distortion2 patcher"></a>

### Dist Waveshaper

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Waveshaper.png" target="_new"><img src = "./img/Waveshaper.png" title="Waveshaper patcher" alt="Waveshaper patcher"></a>

### Dist Waveshaper2
    
<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Waveshaper2.png" target="_new"><img src = "./img/Waveshaper2.png" title="Waveshaper2 patcher" alt="Waveshaper2 patcher"></a>

## Modulation

### Mod Chorus

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Chorus.png" target="_new"><img src = "./img/Chorus.png" title="Chorus patcher" alt="Chorus patcher"></a>

### Mod Chorus2

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Chorus2.png" target="_new"><img src = "./img/Chorus2.png" title="Chorus2 patcher" alt="Chorus2 patcher"></a>

### Mod Flanger

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Flanger.png" target="_new"><img src = "./img/Flanger.png" title="Flanger patcher" alt="Flanger patcher"></a>

### Mod Phaser

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Phaser.png" target="_new"><img src = "./img/Phaser.png" title="Phaser patcher" alt="Phaser patcher"></a>

### Mod Phaser2

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Phaser2.png" target="_new"><img src = "./img/Phaser2.png" title="Phaser2 patcher" alt="Phaser2 patcher"></a>

### Mod Harmonizer

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Harmonizer.png" target="_new"><img src = "./img/Harmonizer.png" title="Harmonizer patcher" alt="Harmonizer patcher"></a>

### Mod Shcomb

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/SHComb.png" target="_new"><img src = "./img/SHComb.png" title="SHComb patcher" alt="SHComb patcher"></a>

### Mod Shcomb2

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/SHComb2.png" target="_new"><img src = "./img/SHComb2.png" title="SHComb2 patcher" alt="SHComb2 patcher"></a>

## Delay

### Del Digitaldelay

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/DigitalDelay.png" target="_new"><img src = "./img/DigitalDelay.png" title="DigitalDelay patcher" alt="DigitalDelay patcher"></a>

### Del Digitaldelay2

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/DigitalDelay2.png" target="_new"><img src = "./img/DigitalDelay2.png" title="DigitalDelay2 patcher" alt="DigitalDelay2 patcher"></a>

### Del Reverb

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Reverb.png" target="_new"><img src = "./img/Reverb.png" title="Reverb patcher" alt="Reverb patcher"></a>

### Del Reverb2

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Reverb2.png" target="_new"><img src = "./img/Reverb2.png" title="Reverb2 patcher" alt="Reverb2 patcher"></a>

### Del Reverb3
    
<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Reverb3.png" target="_new"><img src = "./img/Reverb3.png" title="Reverb3 patcher" alt="Reverb3 patcher"></a>

## Special

### Sfx Subharmonic

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Subharmonic.png" target="_new"><img src = "./img/Subharmonic.png" title="Subharmonic patcher" alt="Subharmonic patcher"></a>

### Sfx Shsine

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/SHSine.png" target="_new"><img src = "./img/SHSine.png" title="SHSine patcher" alt="SHSine patcher"></a>

### Sfx Ringmod

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Ringmod.png" target="_new"><img src = "./img/Ringmod.png" title="Ringmod patcher" alt="Ringmod patcher"></a>

### Sfx Freqshift

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/FreqShiftRingMod.png" target="_new"><img src = "./img/FreqShiftRingMod.png" title="FreqShiftRingMod patcher" alt="FreqShiftRingMod patcher"></a>

### Sfx Fmdelay

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/FMDelay.png" target="_new"><img src = "./img/FMDelay.png" title="FMDelay patcher" alt="FMDelay patcher"></a>

### Sfx Glitch

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Glitch.png" target="_new"><img src = "./img/Glitch.png" title="Glitch patcher" alt="Glitch patcher"></a>

### Sfx Glitch2 

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Glitch2.png" target="_new"><img src = "./img/Glitch2.png" title="Glitch2 patcher" alt="Glitch2 patcher"></a>

### Sfx Yin

<a href="https://raw.githubusercontent.com/IDMNYU/IDMPEDALS/main/docs/img/Yin.png" target="_new"><img src = "./img/Yin.png" title="Yin patcher" alt="Yin patcher"></a>
