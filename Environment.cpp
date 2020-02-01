#include "Environment.h"

// tors
Environment::Environment() { // constructor
	title = "Environment Default Title";   
	screenWidth = 640;
	screenHeight = 480;
}

Environment::~Environment() { // dtor
	cleanUp();
}

// primary methods
void Environment::init() { // initializer            

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	running = true;
}
	
void Environment::loadMedia() { // media loader
	
}

void Environment::cleanUp() { // clean up method
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

// secondary methods
bool Environment::isRunning() {
	return running;
}

bool Environment::pollEvent() {
	return SDL_PollEvent(&event);
}

SDL_Event Environment::getEvent() {
	return event;
}

// setters 
void Environment::setRunning(bool b) {
	running = b;
}

void Environment::setScreenWidth(int w) {
	screenWidth = w;
}

void Environment::setScreenHeight(int h) {
	screenHeight = h;
}

void Environment::setTitle(std::string newTitle) {
	title = newTitle;
}

// getters
int Environment::getW() {
	return screenWidth;
}

int Environment::getH() {
	return screenHeight;
}

// rendering methods
void Environment::setRenderColor(int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Environment::clear() {
	SDL_RenderClear(renderer);
}

void Environment::present() {
	SDL_RenderPresent(renderer);
}

// drawing methods
void Environment::drawRectangle(int x, int y, int w, int h) {
	SDL_Rect fillRect = {x, y, w, h};		
	SDL_RenderFillRect( renderer, &fillRect ); // draw color using rect
}