class Obj_193850 {
  public:
    char pad[0x28];
    int mValue;
    char Set(int x);
};

char Obj_193850::Set(int x) {
    mValue = x;
    return 1;
}
