#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"

class content {
	public :

		string title;
		string desc;
		ofImage image;
		ofVideoPlayer video;
		vector<ofImage> slideshow;

		string path;

		ofxXmlSettings dataAsXml;

		glm::vec2 social;
		glm::vec2 econ;
		
		float religeous;
		float confidence;

		content(string _path);

		void importContent(string _path);			// Will have internal string to capture imported metadata for processing.

		void getContentType();

		void parseMeta();

		void saveValuesToFile();

		void draw(int _x, int _y);

		string getExtFromPath(string _path);
		
		
};