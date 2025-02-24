#include "Snake.h"
#include "Segment.h"

void Snake::AddSegment()
{

	Segment NewSegment;
	NewSegment.PosX = Segments.begin()

	Segments.resize(Segments.size() + 1);
	Segments.push_back(NewSegment);
	Length++;

}

void Snake::MoveSnake(int Dir)
{

	switch (Dir)
	{

	case 1:
		
		PosY = PosY--;

		for (int i = 1; Segments.size(); i++)
		{

		}
	}
}