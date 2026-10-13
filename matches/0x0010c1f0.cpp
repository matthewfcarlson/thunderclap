class Obj {
  public:
    char pad[12];
    char mByte;
    char Set(char b);
};

char Obj::Set(char b) {
    mByte = b;
    return 1;
}
