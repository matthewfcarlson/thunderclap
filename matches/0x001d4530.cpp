struct A { char pad[8]; };
struct R { void Middle(); };
struct Obj { char pad[0x1064]; unsigned char flag; void Init(A*); void Run(); };
struct H { R* First(); };
struct T { char pad[12]; R* r; };
struct End { void Finish(); };
extern H* g1;
extern T* g2;
void __fastcall target(Obj* self) {
 if (!self->flag) {
  self->flag=1;
  self->Init((A*)((char*)self+8));
  self->Run();
  g1->First()->Middle();
  ((End*)g2->r)->Finish();
 }
}