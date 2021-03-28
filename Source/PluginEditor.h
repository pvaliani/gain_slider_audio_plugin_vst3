/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
//editor becomes a Slider:: Listener
class GainSliderPluginProjectAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                                    public juce::Slider::Listener
{
public:
    GainSliderPluginProjectAudioProcessorEditor (GainSliderPluginProjectAudioProcessor&);
    ~GainSliderPluginProjectAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    
//  Pure virtual function
    void sliderValueChanged (juce::Slider* slider) override;

private:
    juce::Slider mGainSlider;
//    no & here so it's not a reference object, its a new object
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GainSliderPluginProjectAudioProcessor& audioProcessor;
    
//    & in c++ is a reference so on line 33 we are refering to an existing mem location

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainSliderPluginProjectAudioProcessorEditor)
};
