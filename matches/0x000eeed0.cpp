#define V(n) virtual void f##n();
class Obj {
  public:
    void Attach(Obj* o);
};
class Child {
  public:
    V(0)
    V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
        V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
            V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52)
                V(53) V(54) V(55) V(56) V(57) V(58) V(59) virtual Obj* f60(int);
    Obj* g(int);
};
class FEContainer {
  public:
    V(0)
    V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
        V(20) V(21) V(22) virtual void f23(Obj*, int);
    V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) virtual Obj* f32(int, int);
    V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) virtual Obj* f46(int);
    V(47) V(48) V(49) V(50) V(51) V(52) Child* child;
};
Obj* FEContainer::f32(int a, int b) {
    Obj* r = child->f60(a);
    f23(r, a);
    if (b) {
        Obj* q = f46(b);
        if (!q)
            q = child->g(b);
        if (q)
            r->Attach(q);
    }
    return r;
}
