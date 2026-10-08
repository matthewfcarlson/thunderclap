class B { public: int G(int); };
class C { public: char pad[4]; B* b; void F(int); void H(int); };
void C::F(int param) {
    int x = b->G(param);
    H(x);
}