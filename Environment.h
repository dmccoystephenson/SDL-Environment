// goal: build a self-contained environment so I don't have to
//		 do all this stuff every time.

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>

#include "objects/Text.h"

class Environment {
  public:
	// tors
	Environment(); // constructor
	~Environment(); // dtor
	
	// primary methods
	void init(); // initializer
	void loadMedia(); // media loader
	void cleanUp(); // clean up method
	
	// secondary methods
	bool isRunning();
	bool pollEvent();
	SDL_Event getEvent();
	
	// setters
	void setRunning(bool b);
	void setScreenWidth(int w);
	void setScreenHeight(int h);
	void setTitle(std::string newTitle);
	void setFontSize(int size);
	
	// getters
	int getW();
	int getH();
	
	// rendering methods
	void setRenderColor(int r, int g, int b, int a);
	void clear();
	void present();
	void addText(int x, int y, std::string text);
	void renderAllText();
	
	// drawing methods
	void drawRectangle(int x, int y, int w, int h);
	
  private:
	int screenWidth;
	int screenHeight;
  
	SDL_Window* window = NULL; // our window
	SDL_Renderer* renderer = NULL; // our renderer	
	
	// font
	TTF_Font* font = NULL;
	int fontSize = 16;
	
	// the text object vector
	std::vector<Text> textObjects;
	
	std::string title;
	
	// event holder
	SDL_Event event;
	
	// flags
	bool running;
};