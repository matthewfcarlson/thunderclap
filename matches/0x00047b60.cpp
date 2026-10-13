class Obj {
  public:
    char Set(int x);
    char pad[0x1c];
    int mVal;
};

char Obj::Set(int x) {
    mVal = x;
    return 1;
}
