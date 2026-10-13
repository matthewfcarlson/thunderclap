class Obj {
  public:
    char pad[0x2c];
    unsigned char Set(int x);
};

unsigned char Obj::Set(int x) {
    *(int*)((char*)this + 0x2c) = x;
    return 1;
}
