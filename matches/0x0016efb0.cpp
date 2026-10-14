class Obj {
  public:
    char pad[0x40];
    void* field;
    char Set(void* x);
};

char Obj::Set(void* x) {
    field = x;
    return 1;
}
