class C {
  public:
    char pad[0x40];
    int value;
    unsigned char Set(int arg);
};

unsigned char C::Set(int arg) {
    value = arg;
    return 1;
}
