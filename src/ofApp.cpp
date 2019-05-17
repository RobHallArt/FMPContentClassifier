#include "ofApp.h"

void ofApp::setup(){

	// Set up the directory to look in for content.
	string contentPath = "\content";
	ofDirectory contentDir(contentPath);
	contentDir.listDir();



	// Loop through content and add it to content array.
	for (int i = 0; i < contentDir.size(); i++) {
		// Check if content is an image.
		if (getExtFromPath(contentDir.getPath(i)) == "jpg" || getExtFromPath(contentDir.getPath(i)) == "png") {
			// Push content into array.
			contents.push_back(content(contentDir.getPath(i)));
		}
	}

	// Set graphs to first content.
	graph.vecValue = contents[currentContent].graph;
	religeousSlider.fltValue = contents[currentContent].religeous;
	confidenceSlider.fltValue = contents[currentContent].confidence;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
		// Draw content
		contents[currentContent].draw(0,0);

		// Draw Graph
		graph.draw(glm::vec2(ofGetWidth()*0.05, ofGetWidth()*0.05), glm::vec2(ofGetWidth()*0.4, ofGetWidth()*0.4));
		
		// Draw Sliders
		religeousSlider.draw( glm::vec2(ofGetWidth()*0.05, ofGetWidth()*0.50), glm::vec2(ofGetWidth()*0.4,ofGetWidth()*0.1) );
		confidenceSlider.draw( glm::vec2(ofGetWidth()*0.55, ofGetWidth()*0.50), glm::vec2(ofGetWidth()*0.4,ofGetWidth()*0.1) );

		// Draw Buttons
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

	// Make mouse on sliders works when dragging
	graph.mousePressed(x, y);

	religeousSlider.mousePressed(x, y);
	confidenceSlider.mousePressed(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	// Check mouseClicked on sliders
	graph.mousePressed(x, y);

	religeousSlider.mousePressed(x, y);
	confidenceSlider.mousePressed(x, y);

	// On next Button Pressed
	if (nextButton.mousePressed(x, y)) {

		// Set contents of graphs back to content
		contents[currentContent].graph = graph.vecValue;
		contents[currentContent].religeous = religeousSlider.fltValue;
		contents[currentContent].confidence = confidenceSlider.fltValue;
		// Save to file
		contents[currentContent].saveValuesToFile();

		// If at the end loop back around
		if (currentContent >= contents.size()-1) {
			currentContent = 0;
		}
		else {
			currentContent++;
		}
		


		// Update graphs for new content
		graph.vecValue = contents[currentContent].graph;
		religeousSlider.fltValue = contents[currentContent].religeous;
		confidenceSlider.fltValue = contents[currentContent].confidence;
		

	}
	
	if (backButton.mousePressed(x, y)) {
		// Set contents of graphs back to content
		contents[currentContent].graph = graph.vecValue;
		contents[currentContent].religeous = religeousSlider.fltValue;
		contents[currentContent].confidence = confidenceSlider.fltValue;
		// Save to file
		contents[currentContent].saveValuesToFile();

		// If at the end loop back around
		if (currentContent <= 0) {
			currentContent = contents.size() - 1;
		}
		else {
			currentContent--;
		}

		// Update graphs for new content
		graph.vecValue = contents[currentContent].graph;
		religeousSlider.fltValue = contents[currentContent].religeous;
		confidenceSlider.fltValue = contents[currentContent].confidence;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	// Reset Buttons when mouse is released
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

string ofApp::getExtFromPath(string _path) {
	if (ofSplitString(_path, ".").size() > 0) {
		string ret = ofSplitString(_path, ".")[1];
		return ret;
		std::cout << ret << std::endl;
	}
	else {
		return ".NaN";
	}
}