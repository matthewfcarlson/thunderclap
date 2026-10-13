class Obj {
  public:
    char pad[0x14];
    int mVal;
    char Set(int v);
};

char Obj::Set(int v) {
    mVal = v;
    return 1;
}
