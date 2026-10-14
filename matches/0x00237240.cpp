class Obj_237240 {
  public:
    char Set(int v);
    char pad[0x10];
};
char Obj_237240::Set(int v) {
    *(int*)((char*)this + 0x10) = v;
    return 1;
}
