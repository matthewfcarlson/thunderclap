class Obj_68790 {
  public:
    char pad[0x14];
    int value;
    char Set(int v);
};

char Obj_68790::Set(int v) {
    value = v;
    return 1;
}
