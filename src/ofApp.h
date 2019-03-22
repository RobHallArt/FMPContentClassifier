#pragma once

#include "ofMain.h"
#include "content.h"
#include "graphInput.h"
#include "button.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int currentContent;

		vector<content> contents;

		graphInput socialGraph{ glm::vec2(ofGetWidth()*0.05, ofGetWidth()*0.05), glm::vec2(ofGetWidth()*0.4,ofGetWidth()*0.4), glm::vec2(0,0), "Social Graph" };
		graphInput econGraph{ glm::vec2(ofGetWidth()*0.55, ofGetWidth()*0.05), glm::vec2(ofGetWidth()*0.4,ofGetWidth()*0.4), glm::vec2(0,0), "Econ Graph" };
		graphInput religeousSlider{ glm::vec2(ofGetWidth()*0.05, ofGetWidth()*0.55), glm::vec2(ofGetWidth()*0.4,ofGetWidth()*0.1), 0, "Religeous Slider" };
		graphInput confidenceSlider{ glm::vec2(ofGetWidth()*0.55, ofGetWidth()*0.55), glm::vec2(ofGetWidth()*0.4,ofGetWidth()*0.1), 0, "Confidence Slider" };
		button backButton{ glm::vec2(ofGetWidth()*0.05, ofGetWidth()*0.65), glm::vec2(ofGetWidth()*0.1, ofGetWidth()*0.05), "Back" };
		button nextButton{ glm::vec2(ofGetWidth()*0.2, ofGetWidth()*0.65), glm::vec2(ofGetWidth()*0.1, ofGetWidth()*0.05), "Next" };
		
};
