class O_16ea20 {
    char pad[0x1c];

  public:
    unsigned char Set(unsigned int x);
};

unsigned char O_16ea20::Set(unsigned int x) {
    *(unsigned int*)(&pad[0x1c]) = x;
    return 1;
}
