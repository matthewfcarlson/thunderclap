// Same code shape as 0x000862b0 (propagated; names are from that function)
class C_2a0850 {
    char pad[0x2c];

  public:
    unsigned int f();
};
unsigned int C_2a0850::f() {
    return *(unsigned int*)((char*)this + 0x2c);
}