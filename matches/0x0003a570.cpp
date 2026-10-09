class A { public: virtual void f(); virtual void g(); };
class B { char pad[0x128]; A* p; public: void run(); };
void B::run() { if (p) { p->g(); p = 0; } }