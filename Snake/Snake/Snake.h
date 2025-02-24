#pragma once
#include <list>
#include "segment.h"

class Snake
{
public:

	int Length = 1;
	int PosX = 10;
	int PosY = 10;

	std::list<Segment> Segments;

	void AddSegment();
	void MoveSnake(int Dir); //Direction given clockwise, 1-4.
	
};