class Obj_14c870 {
  public:
    char Set(int v);
    char pad[0x28];
    int m28;
};

char Obj_14c870::Set(int v) {
    m28 = v;
    return 1;
}
