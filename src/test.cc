#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "zhsr.h"

color drawer::modColor(int x, int y, color c) {
	c.r = clock() % 150; c.g = clock() % 150; c.b = x * clock() % 150;
	return c;
}

struct engine: rdr {
	pt* pt1;
	pt* pt2;
	color c;
	int dir = 1;
	void init() {
		size(640,480);
		this->bgR = 0; this->bgG = 20; this->bgB = 50;
		interval = 17;
		create();
		pt1 = new pt;
		*pt1 = pt(400,400);
		pt2 = new pt;
		*pt2 = pt(260,20);
		c = rgb(155,255,255);
	}
	void draw() {
		tri t,u;
		t.a = pt(50,200); t.b = pt(350,60); t.c = pt(500,450);
		drawer::drawTri(t, c);
		drawer::drawCircle(300,400,10,c);
		drawer::drawCircle(700,800,10,c);
	}
};

int main(int argc, char** argv) {
	printf("Started ZHSR\n");
	engine rend;
	rend.start();
	return 0;
}
