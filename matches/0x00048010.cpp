class Obj {
  public:
    char pad[16];
    void* Get();
};
void* Obj::Get() {
    return (char*)this + 16;
}
