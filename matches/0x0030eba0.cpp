typedef unsigned int u32_30eba0;
struct Child_30eba0 {
    char data[0x54];
    Child_30eba0();
};
struct T_30eba0 {
    u32_30eba0 a0;
    u32_30eba0 a1;
    u32_30eba0 a2;
    u32_30eba0 a3;
    u32_30eba0 a4;
    Child_30eba0 c1;
    Child_30eba0 c2;
    u32_30eba0 last;
    T_30eba0();
};
T_30eba0::T_30eba0() : a0(0), a1(0), a2(0), a3(0), a4(0), c1(), c2(), last(0) {}
