#include <allegro5/allegro.h>
#define create_window(W,H) 	\
	ALLEGRO_DISPLAY* display; \
	void create() { \
		display = al_create_display(W,H); \
	}
	// allegro just autosets the bitmap so this is the only place display is ever used

#define clear(R, G, B) al_clear_to_color(rgb(R,G,B))
#define putp(X, Y, C) al_put_pixel(X,Y,C)
#define flip() al_flip_display()
#define renderer_init() al_init();