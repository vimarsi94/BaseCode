#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "LoaderParams.h"
#include "Vector2D.h"
#include "SDL.h"

class GameObject {
	public:
		virtual void load(const LoaderParams* pParams) = 0;
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void clean() = 0;
		virtual void onCollision(GameObject* other) = 0;

		Vector2D getVelocity() {
			return m_velocity;
		}
		Vector2D getPosition() {
			return m_position;
		}
		int getWidth() {
			return m_width;
		}
		int getHeight() {
			return m_height;
		}
		const char* getId() {
			return m_textureID;
		}
		SDL_Rect getBoundingBox() {
			return m_pBoundingBox;
		}

	protected:
		Vector2D m_position;
		Vector2D m_velocity;
		Vector2D m_acceleration;
		Vector2D m_friction;
		int m_width;
		int m_height;
		int m_currentFrame;
		int m_currentRow;
		const char* m_textureID;
		int m_numSprite;
		float m_maxVelocity;
		float m_frictionCo;
		SDL_Rect m_pBoundingBox;

};

#endif