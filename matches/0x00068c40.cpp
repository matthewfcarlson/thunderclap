class Obj_68c40 {
  public:
    char pad[0x2c];
    unsigned char Set(int x);
};

unsigned char Obj_68c40::Set(int x) {
    *(int*)((char*)this + 0x2c) = x;
    return 1;
}
