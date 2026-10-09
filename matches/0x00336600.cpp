typedef unsigned int U;
struct Inner { U call(U,U,U,U); };
struct Obj { int pad; Inner* p; U second(U); void target(U,U,U,U); };
void Obj::target(U a,U b,U c,U d) { U x=p->call(a,b,c,d); second(x); }