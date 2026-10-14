class Obj_1a2a60 {
  public:
    char pad[0x138];
    char mVal;
    char Set(char v);
};

char Obj_1a2a60::Set(char v) {
    mVal = v;
    return 1;
}
