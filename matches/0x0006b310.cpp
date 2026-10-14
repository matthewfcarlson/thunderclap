class Obj_6b310 {
  public:
    char Pad[0x18];
    int mVal;
    char Set(int v);
};

char Obj_6b310::Set(int v) {
    mVal = v;
    return 1;
}
