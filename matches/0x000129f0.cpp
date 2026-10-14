class Obj_129f0 {
  public:
    char pad[0x18];
    void* GetPtr();
};

void* Obj_129f0::GetPtr() {
    return (char*)this + 0x18;
}
