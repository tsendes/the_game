#include "Background.h"

Background::Background()
{
	image = al_load_bitmap("Desert.png");
}
Background::~Background()
{
	al_destroy_bitmap(image);
}