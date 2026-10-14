class Obj_16ec60 {
  public:
    char Pad[0xc];
    int mVal;
    char Set(int v);
};
char Obj_16ec60::Set(int v) {
    mVal = v;
    return 1;
}