#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
///Punto de entrada a la aplicación///
using namespace std;
Sprite puntosrojos[1000];
Sprite puntosazules[1000];
int contadordesprites = 0;
int contadordespritesazules = 0;

Sprite cursor;

Texture TextureCursor;
Texture Texturered;
Texture Textureblue;
int main() {
	Event evt;

	Texturered.loadFromFile("rcircle.png");
	TextureCursor.loadFromFile("cursor.png");
	Textureblue.loadFromFile("rcircleb.png");

	cursor.setTexture(TextureCursor);

	cursor.setPosition(0, 0);
	cursor.setScale(0.1f, 0.1f);


	bool mouseizq = false;
	bool mouseder = false;
	

	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Que ventana horrible");
	App.setMouseCursorVisible(false);

	// Loop principal
	while (App.isOpen()) {
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type) {
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;
			case sf::Event::MouseMoved:
				/////Actualizamos la posición del sprite con/////
				/////la informacion del evento del mouse/////
				cursor.setPosition(evt.mouseMove.x, evt.mouseMove.y);

			}
			if (evt.type == Event::MouseButtonPressed)
			{
				if (evt.mouseButton.button == Mouse::Left)
				{
					mouseizq = true;
				}
			}
			if (evt.type == Event::MouseButtonReleased) { mouseizq = false; }



			Vector2i cursorPosition = Mouse::getPosition(App);

			
			if (mouseizq)

			{
				Sprite NewPuntoRojo;
				NewPuntoRojo.setTexture(Texturered);
				NewPuntoRojo.setPosition(cursorPosition.x -40, cursorPosition.y-40);
				puntosrojos[contadordesprites] = NewPuntoRojo; 				
				contadordesprites++;

				
			}

			if (evt.type == Event::MouseButtonPressed)
			{
				if (evt.mouseButton.button == Mouse::Right)
				{
					mouseder = true;
				}
			}
			if (evt.type == Event::MouseButtonReleased) { mouseder = false; }

// puntoazul


			if (mouseder)

			{
				Sprite NewPuntoAzul;
				NewPuntoAzul.setTexture(Textureblue);
				NewPuntoAzul.setPosition(cursorPosition.x - 40, cursorPosition.y - 40);
				puntosazules[contadordespritesazules] = NewPuntoAzul;
				contadordespritesazules++;


			}
			
		}
		App.clear();
		for(int i =0; i < contadordesprites; i++)
		{App.draw(puntosrojos[i]); }
		for (int i = 0; i < contadordespritesazules; i++)
		{
			App.draw(puntosazules[i]);
		}
		
		
		App.draw(cursor);
		// Mostramos la ventana
		App.display();
	}

	return 0;
}