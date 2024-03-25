/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxRight, true, 50, 20);
    gainSlider.setRange(0.0f, 1.0f, 0.01f);
    gainSlider.setValue(1.0f);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);

    pitchSwitch.addListener(this);
    addAndMakeVisible(pitchSwitch);

    pitchLabel.setText("Pitch Shift", juce::dontSendNotification);
    pitchLabel.setFont(juce::Font(12.0f)); // Set font size
    pitchLabel.setJustificationType(juce::Justification::centred);
    pitchLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    addAndMakeVisible(pitchLabel);

    gainSlidertLabel.setText("Gain Slider", juce::dontSendNotification);
    gainSlidertLabel.setFont(juce::Font(12.0f)); // Set font size
    gainSlidertLabel.setJustificationType(juce::Justification::centred);
    gainSlidertLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    addAndMakeVisible(gainSlidertLabel);

    setSize (400, 300);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    //g.setColour (juce::Colours::white);
    //g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
    g.fillAll(juce::Colours::black);
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlidertLabel.setBounds(20, getHeight() / 2 - 75, getWidth() - 40, 30);
    gainSlider.setBounds(getWidth() / 2 - 80, getHeight() / 2 - 75, 200, 100);
    pitchSwitch.setBounds(getWidth() / 2 - 13, getHeight() / 2, 30, 50);
    pitchLabel.setBounds(20, getHeight() / 2 + 30, getWidth() - 40, 30);
}
