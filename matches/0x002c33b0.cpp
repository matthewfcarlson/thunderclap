// Same code shape as 0x00293a90 (propagated; names are from that function)
class C_2c33b0 {
    char pad[0xcc];
    unsigned char flag;
    char pad2[0xf];
    int a;
    int b;
    int c;

  public:
    void f(int* p);
};
void C_2c33b0::f(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    flag = 0;
}