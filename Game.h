// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "SDL/SDL.h"
#include <unordered_map>
#include <string>
#include <vector>
#include "Enemy.h"

using namespace std;

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	int GetGameWidth() const { return GameWidth; }
	int GetGameHeight() const { return GameHeight; }

	SDL_Texture* GetTexture(const string& fileName);
	
	SDL_Texture* GetTexture(const std::string& fileName);

	int GetWindowWidth();
	int GetWindowHeight();

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();
	int GameWidth;
	int GameHeight;
	
	// Map of textures loaded
	unordered_map<string, SDL_Texture*> mTextures;

	// All the actors in the game
	vector<class Actor*> mActors;
	// Any pending actors
	vector<class Actor*> mPendingActors;

	// All the sprite components drawn
	vector<class SpriteComponent*> mSprites;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Uint32 mTicksCount;
	bool mIsRunning;
	// Track if we're updating actors right now
	bool mUpdatingActors;

	// Game-specific
	class Ship* mShip; // Player's ship
	int enemiesAmount;
	vector<class Enemy*> enemies;
};
