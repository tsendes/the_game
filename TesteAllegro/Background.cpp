#include "Background.h"

Background::Background()
{
	//nothing
}
Background::~Background()
{
	al_destroy_bitmap(image);
}
void Background::create_background()
{
	image = al_load_bitmap("Desert.png"); ///Background.png
}