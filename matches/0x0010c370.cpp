class Obj_10c370 {
  public:
    char pad[12];
    char mValue;
    char Set(unsigned char x);
};

char Obj_10c370::Set(unsigned char x) {
    mValue = x;
    return 1;
}
