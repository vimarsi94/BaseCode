#pragma once

#ifndef TILELAYER_H
#define TILELAYER_H

#include <vector>
#include <string>
#include "Vector2D.h"
#include "Level.h"
/*
struct Tileset  {
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
};*/

class TileLayer : public Layer {
	public:
		TileLayer(int tileWidth, int tileHeight, const std::vector< Tileset> & tilesets);
		virtual ~TileLayer(void);
		virtual void update();
		virtual void render();
		void setTileIDs(const std::vector< std::vector< int > >& data);
		Tileset getTilesetByID(int tileID);

	private:
		int m_tileWidth; // Ancho de un patr�n
		int m_tileHeight; // Alto de un patr�n
		int m_numRow;
		int m_numCol;
		Vector2D m_position; // Posici�n del mapa
		Vector2D m_velocity;
		static std::vector< Tileset > m_tilesets; // tilesets utilizados en esta capa
		std::vector< std::vector< int > > m_tileIDs; // ids de los tiles en cada posici�n
};

#endif