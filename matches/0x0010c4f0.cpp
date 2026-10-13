class Obj {
  public:
    char pad[0x18];
    void* m18;
    void* Get();
};
void* Obj::Get() {
    return &m18;
}