class Obj_16efb0 {
  public:
    char pad[0x40];
    void* field;
    char Set(void* x);
};

char Obj_16efb0::Set(void* x) {
    field = x;
    return 1;
}
