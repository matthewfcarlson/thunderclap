struct Obj { virtual void f0(); virtual void f1(int); };
extern Obj* g;
void target(int x) { if (g) g->f1(x); }