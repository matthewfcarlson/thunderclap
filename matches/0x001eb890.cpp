// Same code shape as 0x001eb870 (propagated; names are from that function)
class B { public: void F(); };
class A { public: void* v; char pad[4]; char flag; };
void __fastcall target(A* p) { if (p->flag) ((B*)**(void***)p)->F(); }