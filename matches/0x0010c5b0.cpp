class Obj {
  public:
    char Set(int x);
    char pad[0x18];
    int mValue;
};

char Obj::Set(int x) {
    mValue = x;
    return 1;
}
