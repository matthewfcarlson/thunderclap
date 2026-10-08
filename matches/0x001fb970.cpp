class Thing { public: char pad[0x10]; int a; int b; int c; int d; unsigned char e; void Init(); };
void Thing::Init() { c = 0; b = 0; a = 0; d = 0; e = 0; }