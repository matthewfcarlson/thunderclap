class Obj_68390 {
  public:
    char pad[0x1c];
    int mValue;
    char Set(int x);
};
char Obj_68390::Set(int x) {
    mValue = x;
    return 1;
}
