#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255, 255, 255);

  /*
   * Uncomment to use GUI to adjust influential values
  gui.setup();

  gui.add(mZoom.setup("mZoom", 0.00255, 0, 0.01));
  gui.add(mOffset.setup("mOffset", 53, 1, 150));
  gui.add(mScale.setup("mScale", 306, 100, 500));

  gui.add(nZoom.setup("nZoom", 0.0275, 0, 0.1));
  gui.add(nOffset.setup("nOffset", 327, 250, 350));
  gui.add(nScale.setup("nScale", 11.5, 1, 50));
  */
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  int H_NUM_STRIPES = 56;
  int V_NUM_STRIPES = 3 * H_NUM_STRIPES; // Width is x3 longer than height
  int LINE_WIDTH = 2;

  ofSetLineWidth(LINE_WIDTH);

  // Horizontal stripes
  for (int y = 0; y <= HEIGHT; y++) {
    // Map the vertical coordinate to a horizontal stripe number
    int hStripeNumber = ofMap(y, 0, HEIGHT, 1, H_NUM_STRIPES);

    // If stripe is odd, stripe will be colored
    // Else stripe is white
    if (hStripeNumber % 2 == 1) {
      ofSetColor(0, 51, 102);
    } else {
      ofSetColor(255, 255, 255);
    }

    // Draw the line across the canvas
    ofDrawLine(0, y, WIDTH, y);

  }

  // Vertical stripes
  for (int x = 0; x <= WIDTH; x++) {
    // Map the horizontal coordinate to a vertical stripe number
    int vStripeNumber = ofMap(x, 0, WIDTH, 1, V_NUM_STRIPES);

    // If stripe is odd, stripe will be colored
    // Else stripe is white
    if (vStripeNumber % 2 == 1) {
      ofSetColor(0, 51, 102);
    } else {
      ofSetColor(255, 255, 255);
    }

    // Random variation with two noises
    ofSeedRandom(1);

    // Major curve values:
    float mZoom = 0.00255;
    float mOffset = 53;
    float mScale = 306;
    float majorNoise = mScale * ofSignedNoise(x * mZoom + mOffset);

    // Minor curve values:
    float nZoom = 0.0275;
    float nOffset = 327;
    float nScale = 11.5;
    float minorNoise = nScale * ofSignedNoise(x * nZoom + nOffset);

    ofDrawLine(x, HEIGHT, x, (HEIGHT / 2 + majorNoise + minorNoise));
  }

  /*
   * Uncomment to display GUI controls

   gui.draw();
  */

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
