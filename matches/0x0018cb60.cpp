class Obj {
    char pad[0x18];

  public:
    char Set(int v);
};
char Obj::Set(int v) {
    *(int*)((char*)this + 0x18) = v;
    return 1;
}
