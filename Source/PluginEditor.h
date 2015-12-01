/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.0.2

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_7239B31E6DADC126__
#define __JUCE_HEADER_7239B31E6DADC126__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"

#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ImpleAudioProcessorEditor  : public AudioProcessorEditor,
                                   public Timer,
                                   public SliderListener,
                                   public ButtonListener
{
public:
    //==============================================================================
    ImpleAudioProcessorEditor (ImpleAudioProcessor& p);
    ~ImpleAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void timerCallback() override;
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	ImpleAudioProcessor& processor;
	const OwnedArray<AudioProcessorParameter>& processorParameters;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> gainSlider;
    ScopedPointer<ToggleButton> blockAlignToggle;
    ScopedPointer<TextButton> bangButton;
    ScopedPointer<ToggleButton> phaseInvertToggle;
    ScopedPointer<ToggleButton> holdToggle;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ImpleAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_7239B31E6DADC126__
