class Obj {
  public:
    char pad[0xb4];
    int mVal;
    char Set(int val);
};

char Obj::Set(int val) {
    mVal = val;
    return 1;
}
