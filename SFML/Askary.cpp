#include "Askary.h"
#include "PositionStruct.h"
#include "Pieces.h"
#include <iostream>
using namespace std;

Askary::Askary(Position CurP) :Pieces(CurP){};

void Askary::Route(Position CurP){
	Position CurPosition = { CurP.X, CurP.Y };
	AvailableMoves.clear();
	Position cells = { -1, -1 };
	if (CurPosition.X == Intial.X && CurPosition.Y == Intial.Y){
		if (CheckScore() == 1){
			//cout << "IN ASKARY" << endl;
			CurPosition.X++;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			CurPosition.X++;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			AvailableMoves.push_back(cells);
			CurPosition.X--;
			CurPosition.Y--;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			AvailableMoves.push_back(cells);
			CurPosition.Y += 2;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			AvailableMoves.push_back(cells);
		}
		else{
			//cout << "IN ASKARY" << endl;
			CurPosition.X--;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			CurPosition.X--;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			AvailableMoves.push_back(cells);
			CurPosition.X++;
			CurPosition.Y++;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			AvailableMoves.push_back(cells);
			CurPosition.Y -= 2;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			AvailableMoves.push_back(cells);
		}
	}
	else{
		//cout << "IN ASKARY 2" << endl;
		if (CheckScore() == 1){
			CurPosition.X++;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			AvailableMoves.push_back(cells);
			CurPosition.Y--;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			AvailableMoves.push_back(cells);
			CurPosition.Y += 2;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			AvailableMoves.push_back(cells);
			//cout << "Dont't forget the under attack case" << endl;
			//han check el 3askry men 3al board w push corner lw fi enemy 
		}
		else{
			CurPosition.X--;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			AvailableMoves.push_back(cells);
			CurPosition.Y++;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			AvailableMoves.push_back(cells);
			CurPosition.Y -= 2;
			//cout << CurPosition.X << " " << CurPosition.Y << endl;
			if (CurPosition.X >= 0 && CurPosition.X<8 && CurPosition.Y >= 0 && CurPosition.Y<8)
				AvailableMoves.push_back(CurPosition);
			AvailableMoves.push_back(cells);
			//cout << "Dont't forget the under attack case" << endl;
			//han check el 3askry men 3al board w push corner lw fi enemy 

		}
	}
}


