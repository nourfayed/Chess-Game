#pragma once
#include <SFML\Graphics.hpp>
#include "Askary.h"
#include "Board.h"
#include "Empty.h"
#include "Feel.h"
#include "Hossan.h"
#include "Malek.h"
#include "Pieces.h"
#include "PositionStruct.h"
#include "TabiaParent.h"
#include "Wazer.h"
#include <iostream>
#include "GUI.h"
using namespace std;
using namespace sf;

int main(){
		
		while (window.isOpen())
			{
				Load();
				Event Event, MouseEvent;
				Board CurBoard;
				Position Cur, Des;
				int counter = 0, Player = 0;
				bool cur = 0, des = 0;
				while (CurBoard.GetGameState() == 0){

					while (window.pollEvent(Event))
					{

						switch (Event.type)
						{
						case Event::Closed:
							window.close();
							break;
						case Event::MouseButtonPressed:
							switch (Event.key.code){
							case Mouse::Left:
								if (counter == 1){
									Des = { (Mouse::getPosition(window).y - 15) / 75, (Mouse::getPosition(window).x - 15) / 75 };
									cout << "DESTINATION" << endl;
									cout << Des.X << " " << Des.Y << endl;
									des = 1;
								}
								if (counter == 0){
									Cur = { (Mouse::getPosition(window).y - 15) / 75, (Mouse::getPosition(window).x - 15) / 75 };
									cout << "CURRENT" << endl;
									cout << Cur.X << " " << Cur.Y << endl;
									ShowValid(CurBoard.ReturnVector(Cur));

									counter++;
									cur = 1;
								}
								break;
								//	case Keyboard::N:
								//		test = 'n';
								//		window.close();
								//		break;
								//	case Keyboard::Y:
								//		cout << "y" << endl;
								//		test = 'y';
								//		break;
								//	}
								//case Event::MouseMoved:
								//	//cout << Event.mouseMove.x << " " << Event.mouseMove.y << endl;
								//	break;
							}
						}
						if (cur == 1 && des == 1){
							if ((Player % 2 == 0 && CurBoard.CheckTurn(Cur) == 1) || (Player % 2 != 0 && CurBoard.CheckTurn(Cur) == -1)){
								if (CurBoard.IsValid(Cur, Des)){
									setpeice(Cur, Des);
									CurBoard.ChangePosition(Cur, Des);
									if (CurBoard.Warning(CurBoard.MalekPosition(1))){
										cout << "WHITE KING IN DANGER" << endl;
									}
									if (CurBoard.Warning(CurBoard.MalekPosition(-1))){
										cout << "BLACK KING IN DANGER" << endl;
									}
									Player++;
								}
								else{
									ErrorMessage();
								}
								cur = 0, des = 0;
								counter = 0;

								ValidMovesSprite.clear();
							}
							else if (CurBoard.CheckTurn(Cur) == 0){
								ErrorMessage();
								cur = 0, des = 0;
								counter = 0;
							}
							else{
								TurnMessage();
								cur = 0, des = 0;
								counter = 0;
								ValidMovesSprite.clear();
							}
						}
						DrawBoard();
					}
				}
				WinnerDisplay(CurBoard.GetGameState());
				break;
		}
		window.close();
	}
