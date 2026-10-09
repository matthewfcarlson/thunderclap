class Inner { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void g(); virtual void f(float, int); };
class Target { public: char pad[0x44]; float value; char pad2[0x54]; Inner* obj; void run(float x); };
void Target::run(float x) { value = x; obj->f(x * 33.3333f, 0); }
