#include "ofApp.h"

//--------------------------------------------------------------


/*
	Pseudocode for this bastard.
	-GUI, separate class:

		-position
		-size x/y
		-current Setting
		-mode (2d vs 1d)
		
		-constructor ( with and without current Setting )
		-draw
		-mousePressed ( change setting )
		
	Button Class :
		-position
		-size x/y
		-function to call when pressed
		
		-constructor
		-draw
		-mousePressed ( calls function to respond )

	ofApp extra functions
		load from text file into array
		load from array into UI
		save current UI values to array
		save current array values to text

	setup :
		create necessary buttons / other elements
		load everything into the array
		load first content into the ui

	draw : 
		draw function of GUI


	mousePressed :
		call check mouse pressed on all buttons and ui elements

*/


void ofApp::setup(){
	//some path, may be absolute or relative to bin/data
	string contentPath = "\content";
	ofDirectory contentDir(contentPath);



	//only show png files
	//dir.allowExt("png");
	//populate the directory object
	contentDir.listDir();



	//go through and print out all the paths
	for (int i = 0; i < contentDir.size(); i++) {
		std::cout << contentDir.getPath(i) << std::endl;
		contents.push_back(content(contentDir.getPath(i)));
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
		
		contents[currentContent].draw(0,0);

		socialGraph.draw(glm::vec2(ofGetWidth()*0.05, ofGetWidth()*0.05), glm::vec2(ofGetWidth()*0.4, ofGetWidth()*0.4));
		econGraph.draw(glm::vec2(ofGetWidth()*0.55, ofGetWidth()*0.05), glm::vec2(ofGetWidth()*0.4, ofGetWidth()*0.4));

		religeousSlider.draw( glm::vec2(ofGetWidth()*0.05, ofGetWidth()*0.50), glm::vec2(ofGetWidth()*0.4,ofGetWidth()*0.1) );
		confidenceSlider.draw( glm::vec2(ofGetWidth()*0.55, ofGetWidth()*0.50), glm::vec2(ofGetWidth()*0.4,ofGetWidth()*0.1) );

		backButton.draw(glm::vec2(ofGetWidth()*0.05, ofGetWidth()*0.65), glm::vec2(ofGetWidth()*0.1, ofGetWidth()*0.05));
		nextButton.draw(glm::vec2(ofGetWidth()*0.2, ofGetWidth()*0.65), glm::vec2(ofGetWidth()*0.1, ofGetWidth()*0.05));

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
	socialGraph.mousePressed(x, y);
	econGraph.mousePressed(x, y);

	religeousSlider.mousePressed(x, y);
	confidenceSlider.mousePressed(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	socialGraph.mousePressed(x, y);
	econGraph.mousePressed(x, y);

	religeousSlider.mousePressed(x, y);
	confidenceSlider.mousePressed(x, y);

	if (nextButton.mousePressed(x, y)) {
		contents[currentContent].saveValuesToFile();
		if (currentContent >= contents.size()-1) {
			currentContent = 0;
		}
		else {
			currentContent++;
		}
		/*
		contents[currentContent].parseMeta();
		socialGraph.vecValue = contents[currentContent].social;
		econGraph.vecValue = contents[currentContent].econ;
		religeousSlider.fltValue = contents[currentContent].religeous;
		confidenceSlider.fltValue = contents[currentContent].confidence;
		*/

	}
	
	if (backButton.mousePressed(x, y)) {
		contents[currentContent].saveValuesToFile();
		if (currentContent <= 0) {
			currentContent = contents.size()-1;
		}
		else {
			currentContent--;
		}
		contents[currentContent].parseMeta();
		socialGraph.vecValue = contents[currentContent].social;
		econGraph.vecValue = contents[currentContent].econ;
		religeousSlider.fltValue = contents[currentContent].religeous;
		confidenceSlider.fltValue = contents[currentContent].confidence;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	nextButton.mouseReleased(x, y);
	backButton.mouseReleased(x, y);
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
