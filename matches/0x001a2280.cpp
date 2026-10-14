class C_1a2280 {
  public:
    char pad[0x40];
    int value;
    unsigned char Set(int arg);
};

unsigned char C_1a2280::Set(int arg) {
    value = arg;
    return 1;
}
