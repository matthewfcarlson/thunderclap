class Obj {
  public:
    virtual void v0();
    char pad[0x14];
    void* Get();
};

void* Obj::Get() {
    return (char*)this + 0x18;
}
