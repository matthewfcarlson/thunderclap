class Obj_16f5f0 {
    char pad[0x10];

  public:
    bool Set(int value);
};
bool Obj_16f5f0::Set(int value) {
    *(int*)((char*)this + 0x10) = value;
    return true;
}