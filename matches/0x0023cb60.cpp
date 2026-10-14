class Obj_23cb60 {
  public:
    char pad[0xe];
    char mVal;
    char Set(char v);
};

char Obj_23cb60::Set(char v) {
    mVal = v;
    return 1;
}
