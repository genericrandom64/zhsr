
namespace geom {
	double dist(pt a, pt b) {
		return sqrt(abs(pow(b.x - a.x, 2), pow(b.x - a.x, 2)));
	}
	double angle(double a, double b, double c)
}

struct pt {
	int x, y;
	pt() { x = 0; y = 0; }
	pt(int dx, int dy) { x = dx; y = dy; }
};

struct shape {
	pt pos;
	list<pt*> path;
	color fill;
	bool draw = true;
	shape() {
		pos = pt(0,0);
		fill = rgb(255,255,255);
		draw = true;
	}
};

class tri {
	pt A, B, C;
	bool hasPoint(pt D) {
		double l, m, n;
		l = geom::dist(D,A);
		m = geom::dist(D,B);
		n = geom::dist(A,B);
		double adab = geom::angle(l,m,n);
		l = geom::dist(D,B);
		m = geom::dist(D,C);
		n = geom::dist(B,C);
		double adbc = geom::angle(l,m,n);
		l = geom::dist(D,A);
		m = geom::dist(D,C);
		n = geom::dist(A,C);
		double adac = geom::angle(l,m,n);
		double total = adab + adbc + adac;
		return (total == 360);
	}
	void drawTri(pt A, pt B, pt C, color c) {
		int xs[] = {A.x,B.x,C.x};
		int ys[] = {A.y,B.y,C.y};
		int minx = min(xs, 3);
		int maxx = max(xs, 3);
		int miny = min(ys, 3);
		int maxy = max(ys, 3);
		for (int x = minx; x < maxx; x++) {
			for (int y = miny; y < maxy; y++) {
				bool inTri = pointInTri(A, B, C, pt(x,y));
			}
		}
	}
}