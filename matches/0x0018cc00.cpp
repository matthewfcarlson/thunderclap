class Obj {
  public:
    char pad[0x18];
    int mValue;
    unsigned char Set(int value);
};

unsigned char Obj::Set(int value) {
    mValue = value;
    return 1;
}
