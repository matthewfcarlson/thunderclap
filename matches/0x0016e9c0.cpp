class Obj {
  public:
    char pad[0x10];
    int* mPtr;
    char Set(int* p);
};

char Obj::Set(int* p) {
    mPtr = p;
    return 1;
}
