
struct pt {
	int x, y;
	pt() { x = 0; y = 0; }
	pt(int dx, int dy) { x = dx; y = dy; }
};

namespace geom {
	// Takes two points and returns the distance between them
	double dist(pt a, pt b) {
		int dxSq = pow(b.x-a.x, 2);
		int dySq = pow(b.y-a.y, 2);
		return sqrt(abs(dxSq + dySq));
	}
	// Takes three side lengths of a triangle and returns the angle corresponding to c
	double angle(double a, double b, double c) {
		double numerator = pow(c,2) - pow(a,2) - pow(b,2);
		double denominator = -2 * a * b;
		double ang = acos(round(numerator) / round(denominator));
		return ang;
	}
	template <class T>
	int min(T* itms, int length){
		int idx = 0;
		for(int i = 0; i < length; i++) {
			if (*(itms + i) < *(itms + idx)) {
				idx = i;
			}
		}
		return idx;
	}
	template <class T>
	int max(T* itms, int length){
		int idx = 0;
		for(int i = 0; i < length; i++) {
			if (*(itms + i) > *(itms + idx)) {
				idx = i;
			}
		}
		return idx;
	}
	template <class T>
	int aGTb(const void* a, const void* b) { // a greater than b?
		T A = *( (T*) a);
		T B = *( (T*) b);
		if (A > B) return 1;
		else return -1;
	}
	template <class T>
	int aLTb(const void* a, const void* b) {
		return (-1 * aGTb<T>(a, b));
	}
	template <class T>
	void swap(T* a, T* b) {
		T temp = *a;
		*a = *b;
		*b = temp;
	}
	void sortTriByX(pt* pts) {
		pt* a = &(*(pts + 0));
		pt* b = &(*(pts + 1));
		pt* c = &(*(pts + 2));
		if (b->x < a->x) swap(b, a);
		if (c->x < a->x) swap(c, a);
		if (c->x < b->x) swap(c, b);
	}
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

struct tri {
	pt a, b, c;
	bool hasPoint(pt d) {
		double l, m, n;
		l = geom::dist(d,a);
		m = geom::dist(d,b);
		n = geom::dist(a,b);
		double adab = geom::angle(l,m,n);
		l = geom::dist(d,b);
		m = geom::dist(d,c);
		n = geom::dist(b,c);
		double adbc = geom::angle(l,m,n);
		l = geom::dist(d,a);
		m = geom::dist(d,c);
		n = geom::dist(a,c);
		double adac = geom::angle(l,m,n);
		return (adab + adbc + adac == 2 * M_PI);
	}
};