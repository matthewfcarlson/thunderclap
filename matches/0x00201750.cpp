class Callee { public: void f(unsigned short*, int, int, int); };
class Obj { public: char pad[0x284]; Callee* member; unsigned short f(); };
unsigned short Obj::f() {
    unsigned short local;
    member->f(&local, 1, 2, 1);
    return local;
}
