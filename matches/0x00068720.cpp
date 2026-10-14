class Obj_68720 {
  public:
    char pad[0x8c];
    int value;
    char Set(int v);
};

char Obj_68720::Set(int v) {
    value = v;
    return 1;
}
