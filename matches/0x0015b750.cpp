class Obj_15b750 {
  public:
    char pad[0x48];
    char flag;
    char Set(int a);
};

char Obj_15b750::Set(int a) {
    *(int*)((char*)this + 0x48) = a;
    return 1;
}
