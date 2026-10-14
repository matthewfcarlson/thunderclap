class Obj_139bb0 {
  public:
    virtual void V();
    char pad[0x14];
    int field;
    void* Get();
};
void* Obj_139bb0::Get() {
    return &field;
}
