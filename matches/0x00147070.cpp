class Obj {
  public:
    char m[0x20];
    char Set(void* x);
};

char Obj::Set(void* x) {
    *(void**)(m + 0x20) = x;
    return 1;
}
