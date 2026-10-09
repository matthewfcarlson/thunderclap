struct H2; struct H3;
struct H1 { H2* first(int); };
struct H2 { H3* second(); };
struct H3 { struct SimStateArticulated* third(); };
struct SimState { virtual void a(); virtual void b(); virtual void c(); virtual void d(); };
struct SimStateArticulated : SimState {
 virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void n(); virtual void o();
 char pad[0x84]; H1* member;
 SimStateArticulated* vfunc_4(int);
};
SimStateArticulated* SimStateArticulated::vfunc_4(int p) {
 if (p >= 0 && member) return member->first(p)->second()->third();
 return (SimStateArticulated*)((char*)this + 0x10);
}