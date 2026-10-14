struct B_b3660 {
    unsigned int x[0x43];
};
class C_b3660 {
  public:
    char pad[0xc];
    B_b3660 b;
    void Copy(B_b3660* dst);
};
void C_b3660::Copy(B_b3660* dst) {
    *dst = b;
}