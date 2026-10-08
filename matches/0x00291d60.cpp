struct Arg { bool more(); void skip(); void finish(); };
class IgnoreLoader { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void vfunc_5(void*, void*, Arg*, void*); char pad[8]; int m; };
void IgnoreLoader::vfunc_5(void*, void*, Arg* arg, void*) { while (arg->more()) { arg->skip(); arg->finish(); } m=0; }