// goal: build a self-contained environment so I don't have to
//		 do all this stuff every time.

#include <SDL.h>
#include <string>

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
	
	// getters
	int getW();
	int getH();
	
	// rendering methods
	void setRenderColor(int r, int g, int b, int a);
	void clear();
	void present();
	
	
	// drawing methods
	void drawRectangle(int x, int y, int w, int h);
	
  private:
	int screenWidth;
	int screenHeight;
  
	SDL_Window* window; // our window
	SDL_Renderer* renderer; // our renderer	
	
	std::string title;
	
	// event holder
	SDL_Event event;
	
	// flags
	bool running;
};