class B { public: void g(int); };
class A { public: char pad[12]; B *member; void *f(int); };
class C { public: char pad[12]; A *member; void run(int, int); };
void C::run(int a, int b) {
    B *p = (B*)member->f(a);
    if (p) p->g(b);
}