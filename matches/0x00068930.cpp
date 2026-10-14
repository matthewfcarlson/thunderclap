class Obj_68930 {
  public:
    char pad[12];
    int m;
    unsigned char Set(int v);
};

unsigned char Obj_68930::Set(int v) {
    m = v;
    return 1;
}
