class Obj_147070 {
  public:
    char m[0x20];
    char Set(void* x);
};

char Obj_147070::Set(void* x) {
    *(void**)(m + 0x20) = x;
    return 1;
}
