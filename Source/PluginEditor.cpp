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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ImpleAudioProcessorEditor::ImpleAudioProcessorEditor (ImpleAudioProcessor& p)
    : AudioProcessorEditor(p), processor(p), processorParameters(processor.getParameters())
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (gainSlider = new Slider (String()));
    gainSlider->setRange (0, 1, 0.01);
    gainSlider->setSliderStyle (Slider::LinearHorizontal);
    gainSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    gainSlider->addListener (this);

    addAndMakeVisible (blockAlignToggle = new ToggleButton (String()));
    blockAlignToggle->setButtonText (TRANS("block align"));
    blockAlignToggle->addListener (this);
    blockAlignToggle->setToggleState (true, dontSendNotification);
    blockAlignToggle->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (bangButton = new TextButton (String()));
    bangButton->setButtonText (TRANS("bang"));
    bangButton->addListener (this);

    addAndMakeVisible (phaseInvertToggle = new ToggleButton (String()));
    phaseInvertToggle->setButtonText (TRANS("phase invert"));
    phaseInvertToggle->addListener (this);
    phaseInvertToggle->setToggleState (true, dontSendNotification);
    phaseInvertToggle->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (holdToggle = new ToggleButton (String()));
    holdToggle->setButtonText (TRANS("hold"));
    holdToggle->addListener (this);
    holdToggle->setToggleState (true, dontSendNotification);
    holdToggle->setColour (ToggleButton::textColourId, Colours::white);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 168);


    //[Constructor] You can add your own custom stuff here..
	blockAlignToggle->setToggleState(processorParameters[ImpleAudioProcessor::blockAlign]->getValue() > 0.0f ? true : false, dontSendNotification);
	phaseInvertToggle->setToggleState(processorParameters[ImpleAudioProcessor::phaseInvert]->getValue() > 0.0f ? true : false, dontSendNotification);
	holdToggle->setToggleState(processorParameters[ImpleAudioProcessor::hold]->getValue() > 0.0f ? true : false, dontSendNotification);
	gainSlider->setRange(0.0, 1.0, 0.01);
	gainSlider->setValue(processorParameters[ImpleAudioProcessor::gain]->getValue(), dontSendNotification);

	startTimer(20);
    //[/Constructor]
}

ImpleAudioProcessorEditor::~ImpleAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    gainSlider = nullptr;
    blockAlignToggle = nullptr;
    bangButton = nullptr;
    phaseInvertToggle = nullptr;
    holdToggle = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ImpleAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff4d2323));

    g.setColour (Colour (0x88190803));
    g.fillRoundedRectangle (120.0f, 8.0f, 72.0f, 88.0f, 10.000f);

    g.setColour (Colours::white);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("imple"),
                120, 16, 72, 72,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ImpleAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    gainSlider->setBounds (8, 104, 184, 24);
    blockAlignToggle->setBounds (8, 8, 104, 24);
    bangButton->setBounds (8, 136, 184, 24);
    phaseInvertToggle->setBounds (8, 40, 104, 24);
    holdToggle->setBounds (8, 72, 104, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ImpleAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == gainSlider)
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
		processorParameters[ImpleAudioProcessor::gain]->setValueNotifyingHost(static_cast<float>(gainSlider->getValue()));
        //[/UserSliderCode_gainSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void ImpleAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == blockAlignToggle)
    {
        //[UserButtonCode_blockAlignToggle] -- add your button handler code here..
		processorParameters[ImpleAudioProcessor::blockAlign]->setValueNotifyingHost(blockAlignToggle->getToggleState() ? 1.0f : 0.0f);
        //[/UserButtonCode_blockAlignToggle]
    }
    else if (buttonThatWasClicked == bangButton)
    {
        //[UserButtonCode_bangButton] -- add your button handler code here..
		processor.fire();
        //[/UserButtonCode_bangButton]
    }
    else if (buttonThatWasClicked == phaseInvertToggle)
    {
        //[UserButtonCode_phaseInvertToggle] -- add your button handler code here..
		processorParameters[ImpleAudioProcessor::phaseInvert]->setValueNotifyingHost(phaseInvertToggle->getToggleState() ? 1.0f : 0.0f);
        //[/UserButtonCode_phaseInvertToggle]
    }
    else if (buttonThatWasClicked == holdToggle)
    {
        //[UserButtonCode_holdToggle] -- add your button handler code here..
		processorParameters[ImpleAudioProcessor::hold]->setValueNotifyingHost(holdToggle->getToggleState() ? 1.0f : 0.0f);
        //[/UserButtonCode_holdToggle]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ImpleAudioProcessorEditor::timerCallback() {
	blockAlignToggle->setToggleState(processorParameters[ImpleAudioProcessor::blockAlign]->getValue() > 0.0f ? true : false, dontSendNotification);
	phaseInvertToggle->setToggleState(processorParameters[ImpleAudioProcessor::phaseInvert]->getValue() > 0.0f ? true : false, dontSendNotification);
	holdToggle->setToggleState(processorParameters[ImpleAudioProcessor::hold]->getValue() > 0.0f ? true : false, dontSendNotification);
	gainSlider->setValue(processorParameters[ImpleAudioProcessor::gain]->getValue(), dontSendNotification);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ImpleAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="ImpleAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(p), processor(p), processorParameters(processor.getParameters())"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="200" initialHeight="168">
  <BACKGROUND backgroundColour="ff4d2323">
    <ROUNDRECT pos="120 8 72 88" cornerSize="10" fill="solid: 88190803" hasStroke="0"/>
    <TEXT pos="120 16 72 72" fill="solid: ffffffff" hasStroke="0" text="imple"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="" id="25be4f7352ccc483" memberName="gainSlider" virtualName=""
          explicitFocusOrder="0" pos="8 104 184 24" min="0" max="1" int="0.010000000000000000208"
          style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="" id="49a349dfed5521ba" memberName="blockAlignToggle" virtualName=""
                explicitFocusOrder="0" pos="8 8 104 24" txtcol="ffffffff" buttonText="block align"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TEXTBUTTON name="" id="3eee566a234bcc3b" memberName="bangButton" virtualName=""
              explicitFocusOrder="0" pos="8 136 184 24" buttonText="bang" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="" id="84ae9d7d1a8b50df" memberName="phaseInvertToggle"
                virtualName="" explicitFocusOrder="0" pos="8 40 104 24" txtcol="ffffffff"
                buttonText="phase invert" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="" id="9b145f4ed4144949" memberName="holdToggle" virtualName=""
                explicitFocusOrder="0" pos="8 72 104 24" txtcol="ffffffff" buttonText="hold"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
