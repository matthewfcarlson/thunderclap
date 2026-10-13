class Obj {
  public:
    char pad[0x10];
    int mValue;
    unsigned char Set(int x);
};

unsigned char Obj::Set(int x) {
    mValue = x;
    return 1;
}
