// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Math.h"
#include <vector>
#include <typeinfo>
class Actor//classe base de ator
{
public:
	enum State//possiveis estados do ator
	{
		EActive,
		EPaused,
		EDead
	};

	Actor(class Game* game);//construtor e destrutor
	virtual ~Actor();

	// fun��o de atualiza��o, n�o sobrescreva
	void Update(float deltaTime);
	// fun��o para atualizar os componentes, n�o sobreescreva
	void UpdateComponents(float deltaTime);
	// atualiza��o espec�fica do ator, deve ser sobreescrita
	virtual void UpdateActor(float deltaTime);

	// Getters/setters
	const Vector2& GetPosition() const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }
	float GetRotation() const { return mRotation; }
	float GetMidHeight() const { return mHeight / 2; }
	float GetMidWidth() const { return mWidth / 2; }
	void SetRotation(float rotation) { mRotation = rotation; }
	float GetHeight() const { return mHeight; }
	float GetWidth() const { return mWidth; }
	void SetHeight(float height) { mHeight = height; }
	void SetWidth(float width) { mWidth = width; }

	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }

	class Game* GetGame() { return mGame; }


	// insere e remove componentes
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);
	Component* GetComponent(Component* component);
//vari�veis do ator
protected:
	float mHeight;
	float mWidth;
private:
	// estado
	State mState;

	// coordenadas do ator, assim como sua escala e par�metro para rota��o
	Vector2 mPosition;
	float mScale;
	float mRotation;

	//vetor de componentes
	std::vector<class Component*> mComponents;
	class Game* mGame;
};
