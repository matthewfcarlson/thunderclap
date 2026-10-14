class C_34d80 {
  public:
    char pad[0x14];
    char* base;
    void f(int index, unsigned int* src);
};
void C_34d80::f(int index, unsigned int* src) {
    unsigned int* dst = (unsigned int*)(base + index * 0x40 + 0x30);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}