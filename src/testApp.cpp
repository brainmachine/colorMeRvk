#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0,0,0);
    
    // Video piping
    pipe.open("fifo.ppm"); // <---- remember this for FFMPEG
    pipe.setFrameRate(20);
}

//--------------------------------------------------------------
void testApp::update(){
    pipe.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    // Draw the live web feed
    pipe.draw(0,0);
    
    //Abstract line stuff
    for (int i = 0; i < ofGetWidth(); i++) {
        ofSetColor(i/4, i/3, i/2); //Replace this with pixel colors from feed
        ofLine(i, 0, i*sin(i)*mouseX, i*mouseY);
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
