#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowTitle("Colisiones");
  ofBackground(10, 10, 10);
  box2d.init();
  box2d.setGravity(0, 30);
  box2d.createGround();
  box2d.registerGrabbing();
  box2d.createBounds(ofRectangle(0, 0, ofGetWidth(), ofGetHeight()));
  
  circle.setPhysics(3.0, 0.5, 1.0);
  circle.setup(box2d.getWorld(), 300, 300, 32);
  ofSetColor(0, 143, 57);
  
  polygonShape.begin();
  polygonShape.addVertex(0, 0);
  polygonShape.addVertex(64, 0);
  polygonShape.addVertex(64, 64);
  polygonShape.end();
}

//--------------------------------------------------------------
void ofApp::update(){
  box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  circle.draw();
  
  for (auto circle:circles) {
    circle->draw();
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  if (button == 0){
    auto circle = make_shared<ofxBox2dCircle>();
    circle->setPhysics(3.0, 0.5, 1.0);
    circle->setup(box2d.getWorld(), mouseX, mouseY, 32);
    circles.push_back(circle);
  }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
