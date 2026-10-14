class Obj_123800 {
  public:
    char pad[0x10];
    int value;
    char Set(int v);
};

char Obj_123800::Set(int v) {
    value = v;
    return 1;
}