class Obj {
  public:
    char pad[0xc];
    int mValue;
    char Set(int x);
};

char Obj::Set(int x) {
    mValue = x;
    return 1;
}