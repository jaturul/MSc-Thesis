

/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#ifndef GAME_H
#define GAME_H
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include < opencv2\opencv.hpp>  
#include < opencv2/core/core.hpp>  
#include < opencv2/video/tracking.hpp>
#include < opencv2/highgui/highgui.hpp>  
#include < opencv2/video/background_segm.hpp>  
#include "game_level.h"

const GLfloat PLAYER_VELOCITY(500.0f);
// Represents the current state of the game

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
	// Game state
	GameState              State;
	GLboolean              Keys[1024];
	glm::vec2			   CursorPosition;
	glm::vec2			   CursorPositionPrev;
	GLuint                 Width, Height;
	cv::Mat				   playerFrame, currentFrame;

	// Constructor/Destructor
	Game(GLuint width, GLuint height);
	~Game();

	// Initialize game state (load all shaders/textures/levels)
	void Init();

	// GameLoop
	void CheckCrosshair();
	void ActivateCrosshair();
	void DisactivateCrosshair();
	void CursorUpdate();
	void DoCollisions();
	void ProcessInput(GLfloat dt);
	void Render(cv::Mat &frame);
	void Update(GLfloat dt);
};

#endif

