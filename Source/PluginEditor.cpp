/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainSliderPluginProjectAudioProcessorEditor::GainSliderPluginProjectAudioProcessorEditor (GainSliderPluginProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
//    code added
    mGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setRange(-60.0f, 0.0f, 0.01f);
    mGainSlider.setValue(-20.0f);
    mGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
//  gain slider is made a child component of the editor - the visual front end
    mGainSlider.addListener(this);
    addAndMakeVisible(mGainSlider);
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 300);
}

GainSliderPluginProjectAudioProcessorEditor::~GainSliderPluginProjectAudioProcessorEditor()
{
}

//==============================================================================
void GainSliderPluginProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
}

void GainSliderPluginProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    mGainSlider.setBounds(getWidth() / 2 - 50 , getHeight() / 2 - 75, 100, 150);
}

// Want the listener to listen to changes on the slider and affect the processor

void GainSliderPluginProjectAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if (slider == &mGainSlider){
        audioProcessor.mGain = mGainSlider.getValue();
    }
}
