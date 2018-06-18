#include "Background.h"

Background::Background()
{
	create_background();
}
Background::~Background()
{
	al_destroy_bitmap(image2);
	al_destroy_bitmap(image3);
	al_destroy_bitmap(image4);
	al_destroy_bitmap(image5);
	al_destroy_bitmap(image6);
	al_destroy_bitmap(image7);
}
void Background::create_background()
{
	image1 = al_load_bitmap("Desert.png"); ///Background.png
	image2 = al_load_bitmap("Desert_2.png"); ///Background.png
	image3 = al_load_bitmap("Desert_3.png"); ///Background.png

	image4 = al_load_bitmap("Forest_1.png"); ///Background.png
	image5 = al_load_bitmap("Forest_2.png"); ///Background.png
	image6 = al_load_bitmap("Forest_3.png"); ///Background.png

	image7 = al_load_bitmap("Boss_Arena.png"); ///Background.png

	imagev1 = image1;
	imagev2 = image2;
	imagev3 = image3;
	w = 1920;
	h = 1080;

}