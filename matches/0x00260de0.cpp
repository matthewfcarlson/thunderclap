typedef unsigned int U;
struct H { void* vt; char pad[0x44]; void f(void*,void*,int,int); void g(); };
extern U __cdecl f2475(void*);
extern char vft[];
U __cdecl target(){ H h; h.f((void*)0x4e58d0,(void*)0x4e58c8,0x24,4); h.vt=vft; U r=f2475(&h); h.g(); return r; }
