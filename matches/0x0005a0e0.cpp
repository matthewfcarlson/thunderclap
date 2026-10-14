class Obj_5a0e0 {
  public:
    char m[0x10];
    char Set(int a);
};
char Obj_5a0e0::Set(int a) {
    *(int*)((char*)this + 0x10) = a;
    return 1;
}
