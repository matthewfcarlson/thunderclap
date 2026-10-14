class Obj {
  public:
    char pad[0xe];
    char mVal;
    char Set(char v);
};

char Obj::Set(char v) {
    mVal = v;
    return 1;
}
