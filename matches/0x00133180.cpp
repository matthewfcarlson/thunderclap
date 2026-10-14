class Obj_133180 {
    char pad[0x20];

  public:
    char Set(int v);
};
char Obj_133180::Set(int v) {
    *(int*)((char*)this + 0x20) = v;
    return 1;
}
