#pragma once
#include "Board.h"
#include "PositionStruct.h"
#include "Hossan.h"
#include "Feel.h"
#include "Wazer.h"
#include "Pieces.h"
#include "Empty.h"
#include "TabiaParent.h"
#include "Askary.h"
#include "Malek.h"
#include <iostream>
#include <vector>
using namespace std;
//constructor:SHAKL L BOARD F AWL L GAME.
Board::Board()
{
	for (int y = 0; y < 8; y++){
		int x = 1, h = 6;
		Position Initial = { x, y };
		board[x][y] = new Askary(Initial);
		board[x][y]->SetScore(100);
		Initial = { h, y };
		board[h][y] = new Askary(Initial);
		board[h][y]->SetScore(-100);
	}
	Position Initial = { 0, 0 };
	board[0][0] = new TabiaParent(Initial);
	board[0][0]->SetScore(200);
	Initial = { 0, 7 };
	board[0][7] = new TabiaParent(Initial);
	board[0][7]->SetScore(200);
	Initial = { 7, 0 };
	board[7][0] = new TabiaParent(Initial);
	board[7][0]->SetScore(-200);
	Initial = { 7, 7 };
	board[7][7] = new TabiaParent(Initial);
	board[7][7]->SetScore(-200);
	Initial = { 0, 1 };
	board[0][1] = new Hossan(Initial);
	board[0][1]->SetScore(400);
	Initial = { 0, 6 };
	board[0][6] = new Hossan(Initial);
	board[0][6]->SetScore(400);
	Initial = { 7, 1 };
	board[7][1] = new Hossan(Initial);
	board[7][1]->SetScore(-400);
	Initial = { 7, 6 };
	board[7][6] = new Hossan(Initial);
	board[7][6]->SetScore(-400);
	Initial = { 0, 5 };
	board[0][5] = new Feel(Initial);
	board[0][5]->SetScore(300);
	Initial = { 0, 2 };
	board[0][2] = new Feel(Initial);
	board[0][2]->SetScore(300);
	Initial = { 7, 5 };
	board[7][5] = new Feel(Initial);
	board[7][5]->SetScore(-300);
	Initial = { 7, 2 };
	board[7][2] = new Feel(Initial);
	board[7][2]->SetScore(-300);
	Initial = { 0, 3 };
	board[0][3] = new Wazer(Initial);
	board[0][3]->SetScore(500);
	Initial = { 7, 3 };
	board[7][3] = new Wazer(Initial);
	board[7][3]->SetScore(-500);
	Initial = { 0, 4 };
	board[0][4] = new Malek(Initial);
	board[0][4]->SetScore(1000);
	Initial = { 7, 4 };
	board[7][4] = new Malek(Initial);
	board[7][4]->SetScore(-1000);
	for (int i = 2; i < 6; i++){
		for (int j = 0; j < 8; j++){
			Position Initial = { i, j };
			board[i][j] = new Empty(Initial);
		}
	}
}

//IsVali:Check wether the destenation position is valid or not.
bool Board::IsValid(Position CurPosition, Position DestPosition){
	UpdateTheVector(CurPosition);
	for (int i = 0; i < board[CurPosition.X][CurPosition.Y]->ValidMoves.size(); i++){
		if (DestPosition.X == board[CurPosition.X][CurPosition.Y]->ValidMoves[i].X
			&& DestPosition.Y == board[CurPosition.X][CurPosition.Y]->ValidMoves[i].Y){
			return 1;
		}
	}
	return 0;
}

//Warning:bishoof lw l malek mohadad wla la.
bool Board::Warning(Position CurPosition){
	if (CurPosition.X == -1){
		return 0;
	}
	int ScoreMalek = board[CurPosition.X][CurPosition.Y]->CheckScore(); 
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			int PieceScore = board[i][j]->CheckScore();
			if (PieceScore*ScoreMalek == -1){
				Position temp = { i, j };
				board[i][j]->Route(temp);
				UpdateTheVector(temp);
				for (int k = 0; k < board[i][j]->ValidMoves.size(); k++){
					if (CurPosition.X == board[i][j]->ValidMoves[k].X
						&& CurPosition.Y == board[i][j]->ValidMoves[k].Y){
						//cout << temp.X << "toot " << temp.Y << endl;
						//cout << "HENA FI DANGER" << endl;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

//MalekPosition:this function returns the king's position.
Position Board::MalekPosition(int x){
	Position temp = { -1, -1 };
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (x == 1 && board[i][j]->GetScore() == 1000){
				temp = { i, j };
				return temp;
			}
			else if (x == -1 && board[i][j]->GetScore() == -1000){
				temp = { i, j };
				return temp;
			}
		}
	}
	return temp;
} 

//getGameState:btshooof lw had kesb wl la.
int Board::GetGameState(){
	int c = 0;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			int x = board[i][j]->GetScore();
			if (x == 1000){
				c++;
			}
			if (x == -1000){
				c--;
			}
		}
	}
	return c;
}

//UpdateTheVector:Updates the Vector of the valid moves.
void Board::UpdateTheVector(Position CurPosition){
	bool test = 0;
	int PieceScore = board[CurPosition.X][CurPosition.Y]->CheckScore();
	board[CurPosition.X][CurPosition.Y]->Route(CurPosition);
	board[CurPosition.X][CurPosition.Y]->ValidMoves.clear();
	int CheckAskary = board[CurPosition.X][CurPosition.Y]->GetScore();
	for (int i = 0; i < board[CurPosition.X][CurPosition.Y]->AvailableMoves.size(); i++){
		Position tempo = board[CurPosition.X][CurPosition.Y]->AvailableMoves[i];
		int VectorScore = 0;
		if (CheckAskary == 100 || CheckAskary == -100){
			if (tempo.X != -1){
				VectorScore = board[tempo.X][tempo.Y]->CheckScore();
			}
			if (VectorScore*PieceScore == 0 && tempo.Y == CurPosition.Y && test == 0){
				board[CurPosition.X][CurPosition.Y]->ValidMoves.push_back(tempo);
			}
			else if (VectorScore*PieceScore != 0 && VectorScore*PieceScore!=1 && tempo.Y != CurPosition.Y){
				board[CurPosition.X][CurPosition.Y]->ValidMoves.push_back(tempo);
			}
		}
		else {

			if (board[CurPosition.X][CurPosition.Y]->AvailableMoves[i].X == -1){
				test = 0;
			}
			else {
				//cout << tempo.X << "*" << tempo.Y << endl;
				VectorScore = board[tempo.X][tempo.Y]->CheckScore();
				//cout << "Vector Score " << endl;
				if (VectorScore*PieceScore > 0 && test==0){
					test = 1;

				}
				else if (VectorScore*PieceScore < 0 && test==0){
					test = 1;
					Position temp;
					temp = board[CurPosition.X][CurPosition.Y]->AvailableMoves[i];
					//cout << temp.X << "--push--" << temp.Y << endl;
					board[CurPosition.X][CurPosition.Y]->ValidMoves.push_back(temp);
				}
				if (test == 0){
					Position temp;
					temp = board[CurPosition.X][CurPosition.Y]->AvailableMoves[i];
					//cout << temp.X << "--push--" << temp.Y << endl;
					board[CurPosition.X][CurPosition.Y]->ValidMoves.push_back(temp);
				}
			}
		}
	}
	//cout << "UPDATED" << endl;
}

void Board::ChangePosition(Position CurPosition, Position DestPosition){
	if (board[DestPosition.X][DestPosition.Y]->CheckScore() != 0){
		board[DestPosition.X][DestPosition.Y] = new Empty(DestPosition);
	}
	swap(board[CurPosition.X][CurPosition.Y], board[DestPosition.X][DestPosition.Y]);

}
//CheckTurn:checks the turn by returning the score.
int Board::CheckTurn(Position CurPosition){
	return board[CurPosition.X][CurPosition.Y]->CheckScore();
}

//ReturnVector:returns the vector of valid moves.
vector <Position> Board::ReturnVector(Position CurPosition){
	UpdateTheVector(CurPosition);
	return board[CurPosition.X][CurPosition.Y]->ValidMoves;
}
//DESTRUCTOR.
Board:: ~Board(){
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			delete board[i][j];
}