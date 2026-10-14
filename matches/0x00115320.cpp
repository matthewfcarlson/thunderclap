class Obj_115320 {
  public:
    char Pad[0x20];
    int m20;
    char Set(int v);
};

char Obj_115320::Set(int v) {
    m20 = v;
    return 1;
}
