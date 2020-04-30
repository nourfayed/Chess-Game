#include <SFML\Graphics.hpp>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace sf;

//the window on which or game is displayed 
sf::RenderWindow window(sf::VideoMode(600, 600), "chess");

//THE PICS
sf::Texture texture, texture1, texture2, texture3, texture4, texture5, texture6, texture7, texture8, texture9, texture10, texture11, texture12,
texture13, texture14, texture15, texture16, texture17, texture18, texture19, texture20, texture21, texture22, texture23, texture24,
texture25, texture26, texture27, texture28, texture29, texture30, texture31, texture32, texture33,error1,emptyTexture,turnTexture,ValidTexture,
winner1Texture,winner2Texture;

//Pointer to the pics
sf::Sprite myPieces[8][8], SpriteBoard,error,turnSprite,Valid,winner1,winner2;

//The vector which has the valid moves
vector <Sprite> ValidMovesSprite;

void Load(){
	//here we load the pics and if they weren't loaded an error message is displayed
	if (((!texture.loadFromFile("ChessBoard.png")) || (!texture1.loadFromFile("whiteRook.png"))) || (!texture2.loadFromFile("whiteKnight.png"))
		|| (!texture3.loadFromFile("whiteBishop.png")) ||(!winner2Texture.loadFromFile("winner2.jpg"))||(!winner1Texture.loadFromFile("winner1.jpg"))||(!ValidTexture.loadFromFile("Valid.png"))|| (!texture4.loadFromFile("whiteKing.png")) || (!texture5.loadFromFile("whiteQueen.png")) ||
		(!texture6.loadFromFile("whiteBishop.png")) ||(!turnTexture.loadFromFile("Not your turn.png")) ||(!emptyTexture.loadFromFile("Empty.png"))|| (!error1.loadFromFile("Not.png"))|| (!texture7.loadFromFile("whiteKnight.png")) || (!texture8.loadFromFile("whiteRook.png")) ||
		(!texture9.loadFromFile("whitePawn.png")) || (!texture10.loadFromFile("whitePawn.png")) || (!texture11.loadFromFile("whitePawn.png")) ||
		(!texture12.loadFromFile("whitePawn.png")) || (!texture13.loadFromFile("whitePawn.png")) || (!texture14.loadFromFile("whitePawn.png")) ||
		(!texture15.loadFromFile("whitePawn.png")) || (!texture16.loadFromFile("whitePawn.png")) || (!texture17.loadFromFile("blackRook.png")) ||
		(!texture18.loadFromFile("blackKnight.png") || (!texture19.loadFromFile("blackBishop.png")) || (!texture20.loadFromFile("blackKing.png")) ||
		(!texture21.loadFromFile("blackQueen.png")) || (!texture22.loadFromFile("blackBishop.png")) || (!texture23.loadFromFile("blackKnight.png")) ||
		(!texture24.loadFromFile("blackRook.png")) || (!texture25.loadFromFile("blackPawn.png")) || (!texture26.loadFromFile("blackPawn.png")) ||
		(!texture27.loadFromFile("blackPawn.png")) || (!texture28.loadFromFile("blackPawn.png")) || (!texture29.loadFromFile("blackPawn.png")) ||
		(!texture30.loadFromFile("blackPawn.png")) || (!texture31.loadFromFile("blackPawn.png")) || (!texture32.loadFromFile("blackPawn.png")) || (!texture33.loadFromFile("ValidMove.png"))))
	{
		cout << "Error loading chess texture" << endl;
	}
	//here we set the position of the pics on the board
	myPieces[0][0].move(Vector2f(15, 15));
	myPieces[1][0].move(Vector2f(90, 15));
	myPieces[2][0].move(Vector2f(165, 15));
	myPieces[3][0].move(Vector2f(240, 15));
	myPieces[4][0].move(Vector2f(315, 15));
	myPieces[5][0].move(Vector2f(390, 15));
	myPieces[6][0].move(Vector2f(465, 15));
	myPieces[7][0].move(Vector2f(540, 15));
	myPieces[0][1].move(Vector2f(15, 90));
	myPieces[1][1].move(Vector2f(90, 90));
	myPieces[2][1].move(Vector2f(165, 90));
	myPieces[3][1].move(Vector2f(240, 90));
	myPieces[4][1].move(Vector2f(315, 90));
	myPieces[5][1].move(Vector2f(390, 90));
	myPieces[6][1].move(Vector2f(465, 90));
	myPieces[7][1].move(Vector2f(540, 90));
	myPieces[0][7].move(Vector2f(15, 540));
	myPieces[1][7].move(Vector2f(90, 540));
	myPieces[2][7].move(Vector2f(165, 540));
	myPieces[3][7].move(Vector2f(240, 540));
	myPieces[4][7].move(Vector2f(315, 540));
	myPieces[5][7].move(Vector2f(390, 540));
	myPieces[6][7].move(Vector2f(465, 540));
	myPieces[7][7].move(Vector2f(540, 540));
	myPieces[0][6].move(Vector2f(15, 465));
	myPieces[1][6].move(Vector2f(90, 465));
	myPieces[2][6].move(Vector2f(165, 465));
	myPieces[3][6].move(Vector2f(240, 465));
	myPieces[4][6].move(Vector2f(315, 465));
	myPieces[5][6].move(Vector2f(390, 465));
	myPieces[6][6].move(Vector2f(465, 465));
	myPieces[7][6].move(Vector2f(540, 465));
	//set the postion of the messages
	turnSprite.move(Vector2f(35, 50));
	error.move(Vector2f(100, 150));
	Valid.move(Vector2f(150,150));

	//make every pointer points to a pic
	winner1.setTexture(winner1Texture);
	winner2.setTexture(winner2Texture);
	turnSprite.setTexture(turnTexture);
	error.setTexture(error1);
	SpriteBoard.setTexture(texture);
	myPieces[0][0].setTexture(texture1);
	myPieces[1][0].setTexture(texture2);
	myPieces[2][0].setTexture(texture3);
	myPieces[3][0].setTexture(texture5);
	myPieces[4][0].setTexture(texture4);
	myPieces[5][0].setTexture(texture6);
	myPieces[6][0].setTexture(texture7);
	myPieces[7][0].setTexture(texture8);
	myPieces[0][1].setTexture(texture9);
	myPieces[1][1].setTexture(texture10);
	myPieces[2][1].setTexture(texture11);
	myPieces[3][1].setTexture(texture12);
	myPieces[4][1].setTexture(texture13);
	myPieces[5][1].setTexture(texture14);
	myPieces[6][1].setTexture(texture15);
	myPieces[7][1].setTexture(texture16);
	myPieces[0][7].setTexture(texture17);
	myPieces[1][7].setTexture(texture18);
	myPieces[2][7].setTexture(texture19);
	myPieces[3][7].setTexture(texture21);
	myPieces[4][7].setTexture(texture20);
	myPieces[5][7].setTexture(texture22);
	myPieces[6][7].setTexture(texture23);
	myPieces[7][7].setTexture(texture24);
	myPieces[0][6].setTexture(texture25);
	myPieces[1][6].setTexture(texture26);
	myPieces[2][6].setTexture(texture27);
	myPieces[3][6].setTexture(texture28);
	myPieces[4][6].setTexture(texture29);
	myPieces[5][6].setTexture(texture30);
	myPieces[6][6].setTexture(texture31);
	myPieces[7][6].setTexture(texture32);
	
}

void DrawBoard(){

	//here we draw the board
	window.display();
	window.draw(SpriteBoard); //the board sprite
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//to draw all pics
			if (myPieces[i][j].getTexture() != NULL)
			{
				window.draw(myPieces[i][j]);
			}
		}

	}
	//to draw all valid moves
	for (int i = 0; i < ValidMovesSprite.size(); i++){
			window.draw(ValidMovesSprite[i]);
	}
}

void setpeice(Position Cur, Position Des)
{
	//hena ben swap lel amken w lw el Destination msh fadya bafdeha (bakol el pieces)
	if (myPieces[Des.Y][Des.X].getTexture() != 0){
		myPieces[Des.Y][Des.X].setTexture(emptyTexture);
	}
	//el swap be swap fel array nafs-ha laken msh b3'yar position fa kan lazm a3'yro be nafsy 
	myPieces[Cur.Y][Cur.X].setPosition((Des.Y * 75) + 15, (Des.X * 75) + 15);
	myPieces[Des.Y][Des.X].setPosition((Cur.Y * 75) + 15, (Cur.X * 75) + 15);
	swap(myPieces[Cur.Y][Cur.X], myPieces[Des.Y][Des.X]);
}

void ErrorMessage(){
	//if not valid we dispaly an error message
	for (int i = 0; i < 1500; i++){  //hena 3amlen looop 3shan el error message tefdal shoaya 3al window
		window.display();
		window.draw(error);
	}
	window.clear();
}

void TurnMessage(){
	for (int i = 0; i < 1500; i++){
		window.display();
		window.draw(turnSprite);
	}
	window.clear();
}

void ShowValid(vector<Position> CurValid){
	//ben push el Valid moves w amkenha
	ValidMovesSprite.clear();
	for (int i = 0; i < CurValid.size(); i++){
		Sprite temp;
		Position ValidPosition = { CurValid[i].X, CurValid[i].Y }; //da kda el makan el rage3 men el vector
		temp.setTexture(ValidTexture); //ba7to fel pointer
		temp.move(Vector2f((ValidPosition.Y * 75), (ValidPosition.X * 75))); //bazbt makno 
		ValidMovesSprite.push_back(temp); //ben push 
	}
	
}

void WinnerDisplay(int x){
	window.clear();
	
	for (int i = 0; i < 5000; i++){
		
		if (x == 1){
			window.display();
			window.draw(winner1);
		}
		if (x == -1)
		{
			window.display();
			window.draw(winner2);
		}
	}

	window.clear();
}