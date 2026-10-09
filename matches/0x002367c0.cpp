class Source { public: virtual void V(); int pad; int b; int a; };
class Sub { public: void H(int, int, Source*); };
class Owner { public: char pad[0x38]; Sub sub; bool F(Source*); };
bool Owner::F(Source* src) { int b=src->b; int a=src->a; src->V(); sub.H(b,a,src); return true; }