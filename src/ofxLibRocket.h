#ifndef OFXLIBROCKET_H
#define OFXLIBROCKET_H

#include "ofxLibRocketDocument.h"
#include "ofxLibRocketControls.h"
#include "ofxLibRocketSystemInterface.h"
#include "ofxLibRocketRenderInterface.h"
#include "Rocket/Core.h"
#include "Rocket/Debugger.h"
#include <Rocket/Controls.h>
#include "ofxlibrocketslider2d.h"
#include "ofxLibRocketVideo.h"
#include "ofxLibRocketCustomElement.h"
#include "ofMain.h"

#define OFX_LIBROCKET_MAX_KEYS 1024
#define OFX_LIBROCKET_LOG "ofxLibRocket"

class ofxLibRocket: private Rocket::Core::Plugin{

public:
	ofxLibRocket();
	~ofxLibRocket();

	void setup(string contextname="main");
	void update(ofEventArgs& e);
	void update();
	void draw(ofEventArgs& e);
	void draw();

	//always load font before calling setup
	void loadFont(string file);
  void loadFont(string file, string family, Rocket::Core::Font::Style style, Rocket::Core::Font::Weight weight);
	
	ofxLibRocketDocument* loadDocument(string docPath);
  void unloadAllDocuments();
	
	void keyPressed  (ofKeyEventArgs& e);
	void keyReleased(ofKeyEventArgs& e);
	void mouseMoved(ofMouseEventArgs& e);
	void mouseDragged(ofMouseEventArgs& e);
	void mousePressed(ofMouseEventArgs& e);
	void mouseReleased(ofMouseEventArgs& e);
	void resize(ofResizeEventArgs& e);

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void scrolled(float deltaX, float deltaY);

	void resize(int w, int h);

	void registerOfEvents();
	void unregisterOfEvents();
	
	void initialiseKeyMap();
	
	void toggleDebugger();
	void showDebugger();
	void hideDebugger();
	
	template <class T>
	void addCustomElement(string tagName){
		ofxLibRocketCustomElementHandler::addCustomElement<T>(tagName);
	}
	
	static ofxLibRocketDocument* getDocumentFromRocket(Rocket::Core::ElementDocument* doc);
	
private:
	void OnDocumentLoad(Rocket::Core::ElementDocument* document);
	void OnElementCreate(Rocket::Core::Element* element);
	

	int getKeyModifier();
	bool keyState[OFX_LIBROCKET_MAX_KEYS];

	static std::map<Rocket::Core::ElementDocument*, ofxLibRocketDocument*> rocketDocuments;

	ofxLibRocketRenderInterface renderer;
	ofxLibRocketSystemInterface systemInterface;
	Rocket::Core::Context* context;
	
};

#endif // OFXLIBROCKET_H
