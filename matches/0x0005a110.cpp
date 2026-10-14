class Obj_5a110 {
  public:
    char pad[0x78];
    int m78;
    char Set(int v);
};

char Obj_5a110::Set(int v) {
    m78 = v;
    return 1;
}