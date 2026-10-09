extern int gCount;
extern void Init();
class Obj { public: char pad[0x48]; int id; int a4c; int a50; char gap[0x0c]; int a60; char gap2[8]; int a6c; int a70; char gap3[0x10]; int a84; };
Obj* __fastcall Target(Obj* self) {
 self->a4c=0; self->a50=0; self->a60=0; self->a6c=0; self->a70=0; self->a84=0;
 Init(); self->id=gCount; ++gCount; if(gCount==0) gCount=1; return self;
}