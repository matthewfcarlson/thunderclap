typedef unsigned int u32;
extern "C" int __cdecl alloc(int);
extern int movieVtable;
struct Inner { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(u32,u32); };
struct Made { char pad[0x10]; Inner *p; };
struct Factory { Made* make(); };
struct CRadMovieRenderLoop { u32 vptr; int state; int zero; Made *made; };
CRadMovieRenderLoop* __fastcall FUN_001b7740(CRadMovieRenderLoop *self) {
 self->vptr=(u32)&movieVtable; self->state=-2; self->zero=0;
 int t=alloc(32);
 Made *m;
 if(t) m=((Factory*)t)->make(); else m=0;
 self->made=m;
 m->p->g(0x444d4c42,1);
 return self;
}