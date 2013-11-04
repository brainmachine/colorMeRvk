#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0,0,0);
    masterCounter = 0;
    direction = 1; //count up
    
    // Video piping
    pipe.open("fifo.ppm"); // <---- remember this for FFMPEG
    pipe.setFrameRate(20);
}

//--------------------------------------------------------------
void testApp::update(){
    pipe.update();
    masterCounter+=direction;
    if (masterCounter > 300) {
        direction = -1;
    }
    if (masterCounter < -300) {
        direction = 1; 
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    // Draw the live web feed
    pipe.draw(0,0);
    
    
    //normalize mouse
    float daMouseX = float(mouseX)/float(ofGetWidth());
    float daMouseY = float(mouseY)/ofGetHeight();
    ofLogNotice(ofToString(daMouseX));
    
    //Abstract line stuff
    for (int i = 0; i < ofGetWidth(); i++) {
        int r = daMouseX*255;
        int g = daMouseY*255;
        int b = daMouseX*daMouseY*255;
        //ofSetColor(r, g, b); //Replace this with pixel colors from feed
        ofLine(i, 0, i*sin(i)*300, i*cos(i)*/*mouseY*30*/masterCounter);
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
