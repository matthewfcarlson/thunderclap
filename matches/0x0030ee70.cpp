struct B { void F(int); };
struct A { char pad[0xBC]; void Init(); void Finish(); void Target(int); };
void A::Target(int x) { Init(); ((B*)((char*)this + 0x68))->F(x); *(int*)((char*)this + 0xbc) = 1; Finish(); }