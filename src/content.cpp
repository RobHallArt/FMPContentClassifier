#include "content.h"

content::content(string _path) {
	importContent(_path);
	path = _path;
}

void content::importContent(string _path) {
	if (getExtFromPath(_path) == "jpg") {
		image.load(_path);
		dataAsXml.loadFile(ofSplitString(_path, ".")[0] + ".xml");
	}
	if (getExtFromPath(_path) == "png") {
		image.load(_path);
		dataAsXml.loadFile(ofSplitString(_path, ".")[0] + ".xml");
	}
}

void content::getContentType() {

}

void content::parseMeta() {
	
	social.x = dataAsXml.getValue("ECON:X", 0);
	social.y = dataAsXml.getValue("ECON:Y", 0);

	religeous = dataAsXml.getValue("RELIGEOUS", 0);
	confidence = dataAsXml.getValue("CONFIDENCE", 0);
}

void content::draw(int _x, int _y) {

	/*
	float imageHeight = ofGetHeight()*0.6;
	float imageRatio = (imageHeight / image.getHeight());
	float imageWidth = image.getWidth()*imageRatio;

	if (imageWidth > ofGetWidth()*0.8) {
		imageWidth = ofGetWidth()*0.8;
		imageRatio = (imageWidth / image.getWidth());
		imageHeight = image.getHeight()*imageRatio;
	}

	image.draw((ofGetWidth() -imageWidth)*0.5, ofGetHeight()*0.05, imageWidth, imageHeight);
	*/

	image.draw(_x, _y, ofGetWidth(), ofGetHeight());

}

string content::getExtFromPath(string _path) {
	if (ofSplitString(_path, ".").size()>0) {
		string ret = ofSplitString(_path, ".")[1];
		return ret;
		std::cout << ret << std::endl;
	}
	else {
		string ret = "png";
		return ret;
	}
}

void content::saveValuesToFile() {
	dataAsXml.setValue("ECON:X", social.x);
	dataAsXml.setValue("ECON:Y", social.y);

	dataAsXml.setValue("RELIGEOUS", religeous);
	dataAsXml.setValue("CONFIDENCE", confidence);

	//dataAsXml.saveFile(ofSplitString(path, ".")[0] + ".xml");
}