#pragma once

#ifndef LAYER_H
#define LAYER_H

class Layer {
	public:
		virtual void update() = 0;
		virtual void render()= 0;

	protected:
		virtual ~Layer() {}

};

#endif