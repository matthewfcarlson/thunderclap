class Obj {
  public:
    virtual void* Get();
    char pad[0x44];
    char member;
};
void* Obj::Get() {
    return &member;
}
