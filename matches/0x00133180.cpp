class Obj {
    char pad[0x20];

  public:
    char Set(int v);
};
char Obj::Set(int v) {
    *(int*)((char*)this + 0x20) = v;
    return 1;
}
