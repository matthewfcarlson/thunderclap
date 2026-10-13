class Obj {
  public:
    char m[0x10];
    char Set(int a);
};
char Obj::Set(int a) {
    *(int*)((char*)this + 0x10) = a;
    return 1;
}
