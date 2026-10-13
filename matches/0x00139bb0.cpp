class Obj {
  public:
    virtual void V();
    char pad[0x14];
    int field;
    void* Get();
};
void* Obj::Get() {
    return &field;
}
