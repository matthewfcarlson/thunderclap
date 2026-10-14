class Obj_1331a0 {
  public:
    char pad[0x24];
    bool Set(int v);
};

bool Obj_1331a0::Set(int v) {
    *(int*)((char*)this + 0x24) = v;
    return true;
}
