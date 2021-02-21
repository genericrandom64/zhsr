namespace drawer {
	int w; int h;
	void confineToDisplay(pt* p) {
		if (p->x > w) p->x = w;
		if (p->x < 0) p->x = 0;
		if (p->y > h) p->y = h;
		if (p->y < 0) p->y = 0;
	}
	color modColor(int x, int y, color c);
	void drawTri(tri t, color c) {
		pt pts[] = {t.a, t.b, t.c};
		geom::sortTriByX(pts);
		int minx = ptr(pts,0).x;
		int maxx = ptr(pts,2).x;
		pt p1 = ptr(pts,0);
		pt p2 = ptr(pts,1);
		pt p3 = ptr(pts,2);
		double dx, dy, m1, m2;
		dy = p3.y - p1.y;
		dx = p3.x - p1.x;
		m1 = dy / dx;
		int b1 = p1.y - (m1 * p1.x);
		dy = p2.y - p1.y;
		dx = p2.x - p1.x;
		m2 = dy / dx;
		int b2 = p2.y - (m2 * p2.x);
		for (int x = p1.x; x < p2.x; x++) {
			int y1 = round(m1 * x) + b1;
			int y2 = round(m2 * x) + b2;
			int ys[] = {y1, y2};
			int miny = ptr(ys, geom::min(ys, 2));
			int maxy = ptr(ys, geom::max(ys, 2));
			for (int y = miny; y < maxy; y++) {
				color col = modColor(x, y, c);
				putp(x, y, col);
			}
		}
		dy = p3.y - p2.y;
		dx = p3.x - p2.x;
		m2 = dy / dx;
		b2 = p2.y - (m2 * p2.x);
		for (int x = p2.x; x < p3.x; x++) {
			int y1 = round(m1 * x) + b1;
			int y2 = round(m2 * x) + b2;
			int ys[] = {y1, y2};
			int miny = ptr(ys, geom::min(ys, 2));
			int maxy = ptr(ys, geom::max(ys, 2));
			for (int y = miny; y < maxy; y++) {
				color col = modColor(x, y, c);
				putp(x, y, col);
			}
		}
	}
	void drawRect(int rx, int ry, int rw, int rh, color c) {
		// Don't calculate the rect if it's offscreen
		if(rx+rw <= 0 or rx >= w or ry+rh <= 0 or ry >= h) return;
		for (int x = 0; x < rw; x++) {
			for (int y = 0; y < rh; y++) {
				if(x+rx > w or x+rx <= 0 or y+ry > h or y+ry >= 0) {
					putp(x + rx, y + ry, c);
				}
			}
		}
	}
	void drawCircle(int cx, int cy, double r, color c) {
		// Don't calculate the circle if it's offscreen
		if(cy - r < 0 or cy + r > h or cx + r < 0 or cx-r > w) return;
		for (int x = -r; x < r; x++) {
			int yBound = round(sqrt(abs(pow(r,2) - pow(x,2))));
			for (int y = -yBound; y < yBound; y++) {
				if(cx + x <= 0 or cx + x > w or cy + y <= 0 or cy + y > h) return;
				putp(cx + x, cy + y, c);
			}
		}
	}
	void drawLine(pt* p1, pt* p2, color* c) {
		confineToDisplay(p1);
		confineToDisplay(p2);
		double dy = p2->y - p1->y;
		double dx = p2->x - p1->x;
		if (dy == 0 and dx == 0) return;
		if (dy == 0) {
			int move = 1;
			if (dx < 0) move = -1;
			for (int x = 0; abs(x) < abs(dx); x += move) {
			putp(x + p1->x, p1->y, *c);
			}
			return;
		}
		if (dx == 0) {
			int move = 1;
			if (dy < 0) move = -1;
			for (int y = 0; abs(y) < abs(dy); y += move) {
				putp(p1->x, y + p1->y, *c);
			}
			return;
		}
		double m = dy / dx;
		int move = 1;
		if (dx < 0) move = -1;
		int dir = 1;
		if (m < 0) dir = -1;
		int slope;
		int vert = ceil(abs(m)) * dir;
		for (int x = 0; abs(x) < abs(dx); x += move) {
			int y = round(m * x);
			int move = 1;
			if (vert < 0) move = -1;
			for (int n = 0; abs(n) < abs(vert); n += move) {
				putp(x + p1->x, n + y + p1->y, *c);
			}
		}
	}
};
