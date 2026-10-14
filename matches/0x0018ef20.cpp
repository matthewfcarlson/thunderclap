class Obj {
    char pad[0x30];

  public:
    char Set(int value);
};
char Obj::Set(int value) {
    *((int*)((char*)this + 0x30)) = value;
    return 1;
}
