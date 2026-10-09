typedef unsigned int U;
struct Triple { U x,y,z; };
struct Helper { void A(int); U B(U,U); void C(U,int,Triple*); };
struct Obj { Helper* h; U pad; U c; U d; Triple* Go(Triple* out); };
Triple* Obj::Go(Triple* out) { Triple t; h->A(0); U r=h->B(c,d); h->C(r,0,&t); *out = t; return out; }
