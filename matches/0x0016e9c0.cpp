class Obj_16e9c0 {
  public:
    char pad[0x10];
    int* mPtr;
    char Set(int* p);
};

char Obj_16e9c0::Set(int* p) {
    mPtr = p;
    return 1;
}
