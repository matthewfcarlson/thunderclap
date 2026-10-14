class O {
    char pad[0x1c];

  public:
    unsigned char Set(unsigned int x);
};

unsigned char O::Set(unsigned int x) {
    *(unsigned int*)(&pad[0x1c]) = x;
    return 1;
}
