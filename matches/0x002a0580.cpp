class Obj { public: int get(); void last(int, void *); };
class A { char pad[0x10]; int field; char padx[0x30]; Obj *p; char pad2[0x100]; public: void f(int, int); void mid(int,int,int); };
void A::f(int x,int y) { int t=p->get(); mid(t,x,y); p->last(t,&field); }