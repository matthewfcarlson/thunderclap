class Ref { public: virtual void f0(); virtual void f1(); };
extern char vtLoad[]; extern char vtRef[];
class LoadRequest { public: int vt; char p[0x14]; Ref *a; Ref *c; char q[0x104]; Ref *b; LoadRequest *vfunc_2(bool); };
void thunk(LoadRequest*);
LoadRequest *LoadRequest::vfunc_2(bool d) { vt=(int)vtLoad; if(a) a->f1(); if(b) b->f1(); if(c) c->f1(); vt=(int)vtRef; if(d & 1) thunk(this); return this; }