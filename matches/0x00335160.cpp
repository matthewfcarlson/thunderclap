typedef unsigned char u8;
extern char refvt, basevt;
extern int g;
void __cdecl cleanup(int, void*);
class BinkCallback { public: void* vptr; int m; void* refptr; BinkCallback* vfunc_0(u8 flag); };
BinkCallback* BinkCallback::vfunc_0(u8 flag) {
 BinkCallback* p = this;
 if (p) p = (BinkCallback*)((char*)p + 8); else p = (BinkCallback*)0;
 p->vptr = &refvt;
 g = m;
 vptr = &basevt;
 if (flag & 1) cleanup(g, this);
 return this;
}