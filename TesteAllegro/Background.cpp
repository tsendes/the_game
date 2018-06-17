#include "Background.h"

Background::Background()
{
	create_background();
}
Background::~Background()
{
	al_destroy_bitmap(image);
	al_destroy_bitmap(image2);
	al_destroy_bitmap(image3);
	al_destroy_bitmap(image4);
	al_destroy_bitmap(image5);
}
void Background::create_background()
{
	image = al_load_bitmap("Desert.png"); ///Background.png
	image2 = al_load_bitmap("Desert_2.png"); ///Background.png

	image3 = al_load_bitmap("Fundo.png"); ///Background.png
	image4 = al_load_bitmap("Desert_2.png"); ///Background.png

	image5 = al_load_bitmap("Desert_2.png"); ///Background.png

}