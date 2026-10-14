class C_222e20 {
  public:
    char pad[0x68];
    unsigned count;
    unsigned char rest[1];
    unsigned f(unsigned i);
};
unsigned C_222e20::f(unsigned i) {
    if (i < count)
        return *(unsigned*)(rest + i * 0x28);
    return 0;
}