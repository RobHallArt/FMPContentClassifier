#include "content.h"

// Class for storing content with relevant data.

// Constructor class
content::content(string _path) {
	importContent(_path);
	path = _path;
}

// Import function loads image and data.
void content::importContent(string _path) {

		image.load(_path);
		std::cout << _path << std::endl;

		// Path for data is the same path as the image with the extension changed.
		datPath = ofSplitString(_path, ".")[0] + ".txt";

		// If there is a file at the path then import it.
		if (file.open(ofToDataPath(ofSplitString(_path, ".")[0] + ".txt"), ofFile::ReadWrite, false)) {
			
				std::cout << ofSplitString(_path, ".")[0] + ".txt" << std::endl;
				importSuccess = true;
		
		}
		else {
			std::cout << "Didn't Work" << std::endl;
			importSuccess = false;
		}
	// Parse the contents of the imported file.
	parseMeta();

}

// Function to parse the imported file.
void content::parseMeta() {

	if (importSuccess) {
		// Load file into buffer.
		ofBuffer buf = file.readToBuffer();
		std::cout << buf.getText() << std::endl;
		string str = buf.getText();
		// Split buffer into variables.
		graph.x = ofToFloat(ofSplitString(str, ",")[0]);
		graph.y = ofToFloat(ofSplitString(str, ",")[1]);

		religeous = ofToFloat(ofSplitString(str, ",")[2]);
		confidence = ofToFloat(ofSplitString(str, ",")[3]);
		
	}
	
}

// Draw Content
void content::draw(int _x, int _y) {

	image.draw(_x, _y, ofGetWidth(), ofGetHeight());

}

// Save changed values back to file.
void content::saveValuesToFile() {

	// Create string for values
	string save;

	// Add values to string
	save = ofToString(graph.x);
	save += "," + ofToString(graph.y);

	save += "," + ofToString(religeous);
	save += "," + ofToString(confidence);

	// Create output buffer.
	ofBuffer out;
	// Save to file.
	out.set(save.c_str(),save.size());
	std::cout << save << std::endl;

	// Notif if save failed.
	if (ofBufferToFile(datPath, out, false)) {
		std::cout << save << std::endl;
	}
	else {
		std::cout << "WriteFailed" << std::endl;
	}

}