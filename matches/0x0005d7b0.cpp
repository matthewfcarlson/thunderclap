class Thing {
  public:
    char mField[0x4d + 1];
    unsigned char Set(unsigned char v);
};

unsigned char Thing::Set(unsigned char v) {
    mField[0x4c] = v;
    return 1;
}
