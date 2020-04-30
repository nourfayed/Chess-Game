#pragma once
#include "PositionStruct.h"
#include "Pieces.h"
#include <vector>
using namespace std;

class Hossan : public Pieces
{
public:

	Hossan(Position);

	virtual void Route(Position);

};
