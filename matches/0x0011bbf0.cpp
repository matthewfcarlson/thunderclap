class Obj_11bbf0 {
  public:
    char pad[0x14];
    int mVal;
    char Set(int v);
};

char Obj_11bbf0::Set(int v) {
    mVal = v;
    return 1;
}
