class Obj_11bfe0 {
  public:
    char pad[0x10];
    int mVal;
    char Set(int x);
};

char Obj_11bfe0::Set(int x) {
    mVal = x;
    return 1;
}
