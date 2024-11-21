#include "GameStateMachine.h"
#include "Game.h"

// Constructora
GameStateMachine::GameStateMachine() : game(nullptr) {}

// Destructora
GameStateMachine::~GameStateMachine() {
    clearStates();
    clearStatesToErase();
}

void GameStateMachine::init(Game* game_) {
    game = game_;
}

// Anade un estado a la pila
void GameStateMachine::pushState(Manager* newState) { 
    gameStates.push(newState); 
}

// Borra el estado de la cima de la pila
void GameStateMachine::popState() {
    gameStatesToErase.push(gameStates.top());
    gameStates.pop();
}

// Borra todos los estados de la pila
void GameStateMachine::clearStates() {
    while (!gameStates.empty()) popState();
}

// Devuelve el estado actual
Manager* GameStateMachine::currentState() { return gameStates.top(); }

// Borra la pila y anade un nuevo estado
void GameStateMachine::changeState(Manager* newState) {
    popState();
    pushState(newState);
}

// Borra los punteros de los estados a borrar
void GameStateMachine::clearStatesToErase() {
    while (!gameStatesToErase.empty()) {
        delete(gameStatesToErase.top());
        gameStatesToErase.pop();
    }
}

void GameStateMachine::quitGame() {
    game->exitGame();
}