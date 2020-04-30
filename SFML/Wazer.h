#pragma once
#include "PositionStruct.h"
#include "Pieces.h"
#include <vector>
using namespace std;

class Wazer : public Pieces
{
public:

	Wazer(Position);

	virtual void Route(Position);
};