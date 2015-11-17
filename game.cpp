#include "game.h"

Game* Game::s_pInstance = 0;

Game::Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	running = false;
	m_pGameStateMachine = new GameStateMachine();
}

Game::~Game() {

}

bool Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen) {
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		// if succeeded create our window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, 0);

		// if the window creation succeeded create our renderer
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		
			m_pGameStateMachine->pushState(new MenuState());
		}
		
		//app starts
		running = true;
		return 0;
	}
	else {
		return 1; // sdl could not initialize
	}
}

void Game::render() {
	//set color background
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

	//clean screen
	SDL_RenderClear(m_pRenderer);

	m_pGameStateMachine->render();

	//show print buffer
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {

	m_pGameStateMachine->update();
}

void Game::handleEvents() {

}

void Game::clean() { 
	running = false;
	SDL_RenderClear(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}

SDL_Renderer* Game::getRender() {
	return m_pRenderer;
}

int Game::getTicks() {
	return (int) (SDL_GetTicks());
}

int Game::getWindowWidth() {
	return (SDL_GetWindowSurface(m_pWindow)->w);
}

int Game::getWindowHeight() {
	return (SDL_GetWindowSurface(m_pWindow)->h);
}

void Game::setIsRunning(bool run) {
	running = run;
}

GameStateMachine* Game::getGameStateMachine() {
	return m_pGameStateMachine;
}