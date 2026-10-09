extern int g;
struct R { void finish(); };
struct A { R* call(int,int,int); };
struct Obj { char pad[0x150]; A* ptr; void target(int,int); };
void Obj::target(int a,int b) {
  R* r=ptr->call(a,b,g);
  r->finish();
}
