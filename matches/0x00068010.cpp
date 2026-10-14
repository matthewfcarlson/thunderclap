class Obj_68010 {
  public:
    char pad[0x18];
    int m18;
    char Set(int v);
};

char Obj_68010::Set(int v) {
    m18 = v;
    return 1;
}
