#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofEnableDepthTest();
	ofSetWindowTitle("Insta");

	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
	ofNoFill();

	this->noise_source_r = ofRandom(10);
	this->noise_source_g = ofRandom(10);
	this->noise_source_b = ofRandom(10);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	float tmp_r = this->noise_source_r;
	float tmp_g = this->noise_source_g;
	float tmp_b = this->noise_source_b;

	float noise_step = 0.025;
	float rect_step = 50;

	cam.begin();

	for (int i = ofGetWidth(); i > rect_step; i -= rect_step) {
		ofPushMatrix();

		float noise_r = ofNoise(tmp_r += noise_step);
		float noise_g = ofNoise(tmp_g += noise_step);
		float noise_b = ofNoise(tmp_b += noise_step);

		ofRotateX(360 * noise_r);
		ofRotateY(360 * noise_g);
		ofRotateZ(360 * noise_b);

		ofColor c;
		c.setHsb(ofMap(noise_r + noise_g + noise_b, 1, 2, 0, 255), 255, 255);
		ofSetColor(c);

		ofBox(i);

		ofPopMatrix();
	}

	this->noise_source_r += noise_step;
	this->noise_source_g += noise_step;
	this->noise_source_b += noise_step;

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}