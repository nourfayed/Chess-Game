#pragma once
#include "PositionStruct.h"
#include "Pieces.h"
#include <vector>
using namespace std;

class Feel : public Pieces
{
public:

	Feel(Position);
	virtual void Route(Position);

};