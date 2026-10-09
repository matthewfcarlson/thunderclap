struct Caster { int* v; };
struct Host { virtual void a(); virtual void b(); virtual void c(); virtual void d(Caster*, int, int); void run(int, int); };
void Host::run(int x, int y) { Caster c; c.v = (int*)0x3f3e88; d(&c, x, y); }