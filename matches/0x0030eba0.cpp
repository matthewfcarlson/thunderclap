typedef unsigned int u32;
struct Child {
    char data[0x54];
    Child();
};
struct T {
    u32 a0;
    u32 a1;
    u32 a2;
    u32 a3;
    u32 a4;
    Child c1;
    Child c2;
    u32 last;
    T();
};
T::T() : a0(0), a1(0), a2(0), a3(0), a4(0), c1(), c2(), last(0) {}
