class Obj_47a60 {
  public:
    char pad[0x10];
    int mValue;
    unsigned char Set(int x);
};

unsigned char Obj_47a60::Set(int x) {
    mValue = x;
    return 1;
}
