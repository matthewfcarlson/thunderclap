struct InitBase { void init(int); };
struct Sub { void setup(); };
struct Obj { unsigned vptr; char pad[12]; Sub sub; char pad2[4]; int x; unsigned char flag; };
void* __cdecl Alloc(unsigned int);
struct Factory { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual Obj* vfunc_5(); };
Obj* Factory::vfunc_5() {
 Obj* p=(Obj*)Alloc(0x20);
 if (p) {
   ((InitBase*)p)->init(0);
   p->vptr=0x415970;
   p->sub.setup();
   p->x=0; p->flag=1;
   return p;
 }
 return 0;
}