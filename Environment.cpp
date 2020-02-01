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
	TTF_Init();
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	running = true;
}
	
void Environment::loadMedia() { // media loader
	font = TTF_OpenFont("lazy.ttf", fontSize);
	if (font == NULL) {
		cleanUp(); // end immediately
	}
}

void Environment::cleanUp() { // clean up method
	// clear all text objects
	for (size_t i = 0; i < textObjects.size(); i++) {
		textObjects[i].free();
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
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

void Environment::setFontSize(int size) {
	fontSize = size;
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

void Environment::addText(int x, int y, std::string text) {
	Text newText;
	textObjects.push_back(newText);
	SDL_Color textColor = {0x00, 0x00, 0x00, 0xFF};
	textObjects[textObjects.size() - 1].init(x, y, font, renderer, text, textColor);
}

void Environment::renderAllText() {
	for (size_t i = 0; i < textObjects.size(); i++) {
		textObjects[i].render();
	}
}

// drawing methods
void Environment::drawRectangle(int x, int y, int w, int h) {
	SDL_Rect fillRect = {x, y, w, h};		
	SDL_RenderFillRect( renderer, &fillRect ); // draw color using rect
}