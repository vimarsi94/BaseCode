#pragma once

#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

class LoaderParams {
	public:
		LoaderParams(int x, int y, int width, int height, const char* textureID, int numSprite, float speedX, float speedY, float maxSpeed, float friction, int callbackID) {
			m_x = x;
			m_y = y;
			m_width = width;
			m_height = height;
			m_textureID = textureID;
			m_numSprite = numSprite;
			m_speedX = speedX;
			m_speedY = speedY;
			m_maxSpeed = maxSpeed;
			m_friction = friction;
			m_callbackID = callbackID;
		}
		int getX() const { return m_x;  }
		int getY() const { return m_y;  }
		int getWidth() const { return m_width; }
		int getHeight() const { return m_height; }
		const char* getTextureID() const { return m_textureID; }
		int getNumSprite() const { return m_numSprite; }
		float getSpeedX() const { return m_speedX; }
		float getSpeedY() const { return m_speedY; }
		float getMaxSpeed() const { return m_maxSpeed; }
		float getFrictionCo() const { return m_friction; }
		int getCallbackID() const { return m_callbackID; }
		
	private:
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		const char* m_textureID;
		int m_numSprite;
		float m_speedX;
		float m_speedY;
		float m_maxSpeed;
		float m_friction;
		int m_callbackID;
};

#endif
