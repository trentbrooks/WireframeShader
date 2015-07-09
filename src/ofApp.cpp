#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    sphere.setRadius( 250 );
    
    // load the wireframe shader
    useShader = true;
    wireframeLineWidth = 1.0;
    wireframeShader.setGeometryInputType(GL_TRIANGLES);
    wireframeShader.setGeometryOutputType(GL_TRIANGLES);
    wireframeShader.setGeometryOutputCount(3);
    wireframeShader.load("wireframe.vert","wireframe.frag","wireframe.geom");
}

//--------------------------------------------------------------
void ofApp::update(){

    int res = ofMap(ofGetMouseX(), 0, ofGetWidth(), 1, 100);
    sphere.setResolution(res);
}

//--------------------------------------------------------------
void ofApp::draw(){

    cam.begin();
    ofSetColor(0);
    
    if(useShader) {
        wireframeShader.begin();
        wireframeShader.setUniform2f("ViewportSize", float(ofGetWidth()), float(ofGetHeight()));
        wireframeShader.setUniform1f("LineWidth", wireframeLineWidth);
        
        sphere.draw(); // note we are drawing triangles, which get converted to lines in geom shader
        
        wireframeShader.end();
    } else {
        
        sphere.drawWireframe(); // regular wireframe drawing is slow
    }
    
    cam.end();
    
    stringstream out;
    out << "fps: " << ofToString(ofGetFrameRate(),0) << endl;
    out << "use wireframe shader (press space): " << useShader;
    ofDrawBitmapStringHighlight(out.str(),20,20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == ' ')
        useShader = !useShader;
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
