class B { public: int f(int, int); };
class C { public: void g(); };
class Obj { public: char pad[0x150]; B* member; void target(int a, int b); };
void Obj::target(int a, int b) { int x = member->f(a, b); ((C*)x)->g(); }