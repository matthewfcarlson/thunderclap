class Obj {
  public:
    char m[0x14];
    int mVal;
    char Set(int v);
};

char Obj::Set(int v) {
    mVal = v;
    return 1;
}
