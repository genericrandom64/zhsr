#include <math.h>
#include <sys/time.h>

// backend-specific
#define color ALLEGRO_COLOR
#define rgb(R, G, B) al_map_rgb(R,G,B)

#define ptr(A,B) (*(A+B))
#define ui8 uint8_t