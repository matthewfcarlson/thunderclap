class Obj {
  public:
    char Pad[0x18];
    int mVal;
    char Set(int v);
};

char Obj::Set(int v) {
    mVal = v;
    return 1;
}
