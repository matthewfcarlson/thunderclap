class Obj_133010 {
  public:
    char pad[0xc];
    int mValue;
    char Set(int v);
};

char Obj_133010::Set(int v) {
    mValue = v;
    return 1;
}
