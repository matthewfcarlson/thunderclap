// Same code shape as 0x00086340 (propagated; names are from that function)
class A_2b1920 {
    char pad[0x3c];

  public:
    unsigned int value;
    unsigned int f();
};
unsigned int A_2b1920::f() {
    return value;
}