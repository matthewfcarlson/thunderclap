class Obj_16f570 {
  public:
    char pad[0x50];
    int value;
    char ret;
    char Set(int v);
};

char Obj_16f570::Set(int v) {
    value = v;
    return 1;
}