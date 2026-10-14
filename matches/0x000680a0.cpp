class Obj_680a0 {
  public:
    char pad[0x48];
    int mValue;
    char Fn(int v);
};

char Obj_680a0::Fn(int v) {
    mValue = v;
    return 1;
}
