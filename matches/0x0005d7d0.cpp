class Obj {
  public:
    char Set(int v);
    char pad[0x18];
    int mVal;
};
char Obj::Set(int v) {
    mVal = v;
    return 1;
}