struct rdr {
	bool skip = false; // If set true, calculations for the next frame will be performed
	bool stop = false; // If set true, the draw loop stops and must be called again to draw content
	// Width and height of display, DO NOT SET DIRECTLY
	// Use size(w, h) to set these values
	int w = 320;
	int h = 200;
	// Background color red, green, and blue components
	int bgR = 0;
	int bgG = 0;
	int bgB = 0;
	// ----
	list<shape*> shps; // Buffer of shapes to be drawn
	clock_t t = 0;
	// Interval in number of microseconds between draws
	// Effectively controls refresh/frame rate
	// Example: value of 1,000,000 draws the frame every second, value of 16,666 draws the frame at 60 fps
	clock_t interval = 1000000;
	// Time in milliseconds since the previous refresh
	int since = 0;
	// Number of frames elapsed since program start
	// Loops after reaching 18,446,744,073,709,551,616
	unsigned long frame = 0;
	// Creates a display with the current width and height
	create_window(w,h);
	void size(int nw, int nh) {
		w = nw; h = nh;
		drawer::w = nw; drawer::h = nh;
	}
	// Called once at renderer initialization
	virtual void init() {
		create();
	}
	virtual void update() {} // Called at beginning of every loop
	virtual void draw() {} // Called every draw immediately after clearing screen to background
	void start() {
		// Starts the draw loop //
		renderer_init();
		init();
		t = clock() - interval;
		while (!stop) {
			clock_t since = clock() - t; // Get time elapsed since previous draw
			if (since >= interval) {
				t = clock();
				since = since - interval;
				frame++;
				update(); // Any user updates
				if (!skip) {
					clear(bgR, bgG, bgB); // Clears display to background color to prepare for drawing frame
					draw();
					flip(); // Draw the frame
				}
			}
		}
	}
};
