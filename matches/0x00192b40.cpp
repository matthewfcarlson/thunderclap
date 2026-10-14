class Obj_192b40 {
  public:
    char pad[0xa4];
    int mValue;
    char Set(int v);
};

char Obj_192b40::Set(int v) {
    mValue = v;
    return 1;
}
