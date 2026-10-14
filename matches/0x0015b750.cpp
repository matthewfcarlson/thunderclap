class Obj {
  public:
    char pad[0x48];
    char flag;
    char Set(int a);
};

char Obj::Set(int a) {
    *(int*)((char*)this + 0x48) = a;
    return 1;
}
