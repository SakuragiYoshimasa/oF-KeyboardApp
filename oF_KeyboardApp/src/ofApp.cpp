

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    ofBackground(255, 255, 255);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    // print input ports to console
    midiIn.listPorts();
    
    // open port by number
    midiIn.openPort(0);

    // don't ignore sysex, timing, & active sense messages,
    // these are ignored by default
    midiIn.ignoreTypes(false, false, false);
    
    // add ofApp as a listener
    midiIn.addListener(this);
    
    // print received messages to the console
    midiIn.setVerbose(true);
    
    
    //my keyboardset 48 ~ 108
    for(int i = 0; i < 60; i++){
        noteBars.push_back(noteBar(i));
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    
    noteBars[midiMessage.pitch - 48].up(midiMessage.velocity);
    midiMessage.velocity = 0;
    
    for(int i = 0; i < 60; i++){
        noteBars[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(0);
    
/*    // draw the last recieved message contents to the screen
    text << "Received: " << ofxMidiMessage::getStatusString(midiMessage.status);
    ofDrawBitmapString(text.str(), 20, 20);
    text.str(""); // clear
    
    text << "channel: " << midiMessage.channel;
    ofDrawBitmapString(text.str(), 20, 34);
    text.str(""); // clear
    
    text << "pitch: " << midiMessage.pitch;
    ofDrawBitmapString(text.str(), 20, 48);
    text.str(""); // clear
    ofRect(20, 58, ofMap(midiMessage.pitch, 0, 127, 0, ofGetWidth()-40), 20);
    
    text << "velocity: " << midiMessage.velocity;
    ofDrawBitmapString(text.str(), 20, 96);
    text.str(""); // clear
    ofRect(20, 105, ofMap(midiMessage.velocity, 0, 127, 0, ofGetWidth()-40), 20);
    
    text << "control: " << midiMessage.control;
    ofDrawBitmapString(text.str(), 20, 144);
    text.str(""); // clear
    ofRect(20, 154, ofMap(midiMessage.control, 0, 127, 0, ofGetWidth()-40), 20);
    
    text << "value: " << midiMessage.value;
    ofDrawBitmapString(text.str(), 20, 192);
    text.str(""); // clear
    if(midiMessage.status == MIDI_PITCH_BEND) {
        ofRect(20, 202, ofMap(midiMessage.value, 0, MIDI_MAX_BEND, 0, ofGetWidth()-40), 20);
    }
    else {
        ofRect(20, 202, ofMap(midiMessage.value, 0, 127, 0, ofGetWidth()-40), 20);
    }
    
    text << "delta: " << midiMessage.deltatime;
    ofDrawBitmapString(text.str(), 20, 240);
    text.str(""); // clear*/
    
    for(double i = 0; i <60; i++){
        ofRect(i * ofGetWidth() / 60 ,ofGetHeight() -  noteBars[(int)i].getHeight() , (double)ofGetWidth()/(double)60 , noteBars[(int)i].getHeight() );
    }
}

//--------------------------------------------------------------
void ofApp::exit() {
    
    midiIn.closePort();
    midiIn.removeListener(this);
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& msg) {
    
    // make a copy of the latest message
    midiMessage = msg;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    switch(key) {
        case 'l':
            midiIn.listPorts();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased() {
}
