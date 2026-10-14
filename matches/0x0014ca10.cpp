class Obj_14ca10 {
  public:
    char pad[0x40];
    int mVal;
    char Set(int v);
};

char Obj_14ca10::Set(int v) {
    mVal = v;
    return 1;
}