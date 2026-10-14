class Obj_139a50 {
  public:
    virtual void v0();
    char pad[0x14];
    void* Get();
};

void* Obj_139a50::Get() {
    return (char*)this + 0x18;
}
