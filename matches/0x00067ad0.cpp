class C_67ad0 {
  public:
    char pad[8];
    unsigned int slots[256];
    void* f(unsigned int x);
};
void* C_67ad0::f(unsigned int x) {
    if (x == 0)
        return 0;
    int i = (int)(x & 255);
    if (slots[i] != x)
        return 0;
    if (i < 0)
        return 0;
    return (char*)this + i * 32 + 0x108;
}
