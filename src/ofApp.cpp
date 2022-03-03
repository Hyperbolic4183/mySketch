#include "ofApp.h"

const float radius = 30.0f;

//--------------------------------------------------------------
void ofApp::setup(){
    position = vec2{ radius };
    velocity = vec2 { 300.0f, 200.0f };
}

//--------------------------------------------------------------
void ofApp::update(){
    //直前のフレームの時間感覚を記録しておく
    const float dt = ofGetLastFrameTime();
    //現在の円の位置を記録しておく
    const vec2 p = position;
    //円の位置を更新する
    position += velocity * dt;
    //w-rを計算する
    const float wr = ofGetWidth() - 1.0f - radius;
    //もし円がウィンドウからはみ出たら
    if (position.x >= wr) {
        //壁と衝突した時刻を求める
        const float t = (wr - p.x) / velocity.x;
        //衝突した位置を求める
        const vec2 q = vec2{wr, p.y + velocity.y * t};
        //衝突後の速度を変更する
        velocity = vec2{-velocity.x, velocity.y};
        //円の位置を変更すr
        position = q + velocity * (dt - t);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(position, radius);
    
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
