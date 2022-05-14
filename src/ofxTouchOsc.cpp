#include "ofxTouchOsc.h"


//---------
ofxTouchOscLabel* ofxTouchOscPage::addLabel(string name, float x, float y, float w, float h) {
    ofxTouchOscLabel *widget = new ofxTouchOscLabel(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscTime* ofxTouchOscPage::addTime(string name, float x, float y, float w, float h) {
    ofxTouchOscTime *widget = new ofxTouchOscTime(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscBattery* ofxTouchOscPage::addBattery(string name, float x, float y, float w, float h) {
    ofxTouchOscBattery *widget = new ofxTouchOscBattery(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscFader* ofxTouchOscPage::addFader(string name, float x, float y, float w, float h) {
    ofxTouchOscFader *widget = new ofxTouchOscFader(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscRotary* ofxTouchOscPage::addRotary(string name, float x, float y, float w, float h) {
    ofxTouchOscRotary *widget = new ofxTouchOscRotary(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscLed* ofxTouchOscPage::addLed(string name, float x, float y, float w, float h) {
    ofxTouchOscLed *widget = new ofxTouchOscLed(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscButton* ofxTouchOscPage::addButton(string name, float x, float y, float w, float h) {
    ofxTouchOscButton *widget = new ofxTouchOscButton(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscToggle* ofxTouchOscPage::addToggle(string name, float x, float y, float w, float h) {
    ofxTouchOscToggle *widget = new ofxTouchOscToggle(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscEncoder* ofxTouchOscPage::addEncoder(string name, float x, float y, float w, float h) {
    ofxTouchOscEncoder *widget = new ofxTouchOscEncoder(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscXy* ofxTouchOscPage::addXy(string name, float x, float y, float w, float h) {
    ofxTouchOscXy *widget = new ofxTouchOscXy(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscMultiPush* ofxTouchOscPage::addMultiPush(string name, float x, float y, float w, float h) {
    ofxTouchOscMultiPush *widget = new ofxTouchOscMultiPush(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscMultiToggle* ofxTouchOscPage::addMultiToggle(string name, float x, float y, float w, float h) {
    ofxTouchOscMultiToggle *widget = new ofxTouchOscMultiToggle(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscMultiFader* ofxTouchOscPage::addMultiFader(string name, float x, float y, float w, float h) {
    ofxTouchOscMultiFader *widget = new ofxTouchOscMultiFader(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}
ofxTouchOscMultiXy* ofxTouchOscPage::addMultiXy(string name, float x, float y, float w, float h) {
    ofxTouchOscMultiXy *widget = new ofxTouchOscMultiXy(name, x, y, w, h, defaultColor);
    widgets.push_back(widget);
    return widget;
}

//---------
ofxTouchOscPage::ofxTouchOscPage(string name, TouchOscColor color) {
    this->name = name;
    this->defaultColor = color;
}

//---------
void ofxTouchOscPage::setScale(float scaleX, float scaleY) {
    this->scaleX = scaleX;
    this->scaleY = scaleY;
}

//---------
void ofxTouchOscPage::setDefaultWidgetColor(TouchOscColor color) {
    this->defaultColor = color;
}

//---------
string ofxTouchOscPage::getXml() {
    string b64name = base64_encode(reinterpret_cast<const unsigned char*>(name.c_str()), name.length());
    
    string xml;
    xml += "<tabpage name=\""+b64name+"\" scalef=\"0.0\" scalet=\"1.0\" >\n";
    for (int i=0; i<widgets.size(); i++) {
        widgets[i]->setScale(scaleX, scaleY);
        xml += widgets[i]->getXmlInner();
    }
    xml += "</tabpage>\n";
    return xml;
}

//---------
ofxTouchOsc::ofxTouchOsc() {
    defaultColor = RED;
    customResolution = false;
}

//---------
ofxTouchOscPage* ofxTouchOsc::addPage(string name) {
    ofxTouchOscPage *newPage = new ofxTouchOscPage(name, defaultColor);
    pages.push_back(newPage);
    return newPage;
}

//---------
void ofxTouchOsc::addPage(ofxTouchOscPage* newPage) {
    pages.push_back(newPage);
}

//---------
string ofxTouchOsc::getXml() {
    string xml;
    xml += "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    if (customResolution)
        xml += "<layout version=\"13\" mode=\"3\" w=\""+ofToString((int)scaleX)+"\" h=\""+ofToString((int)scaleY)+"\" orientation=\"horizontal\">";
    else
        xml += "<layout version=\"13\" mode=\"0\" orientation=\"horizontal\">";
    for (int i=0; i<pages.size(); i++) {
        pages[i]->setScale(scaleX, scaleY);
        xml += pages[i]->getXml();
    }
    xml += "</layout>";
    return xml;
}

//---------
void ofxTouchOsc::setDefaultColor(TouchOscColor color) {
    this->defaultColor = color;
}

//---------
void ofxTouchOsc::setScale(float scaleX, float scaleY) {
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    customResolution = true;
}

//---------
void ofxTouchOsc::save(string name) {
    ofFile file("index.xml", ofFile::WriteOnly);
    file << getXml();
    file.close();
    string cmd;

#ifdef TARGET_OSX
    cmd += "cd "+ofToString(ofToDataPath("")) + "; ";
    cmd += "zip -r "+name+".touchosc index.xml; ";
    cmd += "rm index.xml; ";
    cmd += "open "+name+".touchosc; ";
    ofSystem(cmd);
#endif

#ifdef TARGET_WIN32
	//https://superuser.com/questions/201371/create-zip-folder-from-the-command-line-windows
	//https://stackoverflow.com/questions/18180060/how-to-zip-a-file-using-cmd-line
	//https://www.computerhope.com/issues/ch000549.htm#1
	// tar.exe -a -c -f out.zip in.txt
	// 7z a -tzip {yourfile.zip} {yourfolder}
	//cmd += getAbsolutePath("", false);
	cmd += "cd " + ofToString(ofToDataPath("", true));
	cout << endl << cmd << endl<< endl;
    ofSystem(cmd);
	
	cmd = "tar.exe -cvzf index.zip index.xml";
	//tar - cvzf archive.tar "C:\Users\fatiw\Desktop\My Account Info"
	cout << endl << cmd << endl<< endl;
    ofSystem(cmd);

	if (std::rename("index.zip", "index.touchosc")) {
		std::perror("Error renaming");
	}

	cout << endl << endl<< endl;
	//cmd += "powershell Compress-Archive .\index.xml : .\index.zip";
#endif

}

//---------
ofxTouchOscPage::~ofxTouchOscPage() {
    for (int i=0; i<widgets.size(); i++) {
        delete widgets[i];
    }
}

//---------
ofxTouchOsc::~ofxTouchOsc() {
    for (int i=0; i<pages.size(); i++) {
        delete pages[i];
    }
}