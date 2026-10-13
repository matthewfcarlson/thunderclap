class Obj {
  public:
    char pad[0x20];
    void* member;
    void* Get();
};
void* Obj::Get() {
    return &member;
}