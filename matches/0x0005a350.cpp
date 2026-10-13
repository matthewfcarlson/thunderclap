class Obj {
  public:
    char pad[0x1c];
    void* Get();
};
void* Obj::Get() {
    return (char*)this + 0x1c;
}