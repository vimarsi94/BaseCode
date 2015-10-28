#pragma once

#include "string"

class GameObject{
	private: 
		std::string m_textureID;
		int m_width;
		int m_height;
		int m_currentFrame;
		int m_currentRow;
		int m_x;
		int m_y;
		int mov;
	public:
		GameObject();
		~GameObject();

		void load(int x, int y, int width, int height, std::string textureID);
		void draw();
		void update();
		void clean();
};