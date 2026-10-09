struct B { void x(int); };
struct C { void y(int); };
struct A { int pad; B* b; C* c; void run(int); };
void A::run(int v) { b->x(v); c->y(v); }
