class Obj_13eab0 {
  public:
    char Pad[0x20];
    char Set(int v);
};
char Obj_13eab0::Set(int v) {
    *(int*)((char*)this + 0x20) = v;
    return 1;
}
