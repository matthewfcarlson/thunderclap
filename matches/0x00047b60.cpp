class Obj_47b60 {
  public:
    char Set(int x);
    char pad[0x1c];
    int mVal;
};

char Obj_47b60::Set(int x) {
    mVal = x;
    return 1;
}
