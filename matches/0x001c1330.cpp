class D { public: void f(); };
class C { public: char pad[0xbc]; D *member; void g(); };
void C::g() { member->f(); }