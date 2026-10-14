class Obj {
  public:
    char pad[0x138];
    char mVal;
    char Set(char v);
};

char Obj::Set(char v) {
    mVal = v;
    return 1;
}
