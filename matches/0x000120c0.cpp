class Obj {
    char pad[0x30];

  public:
    void* Get();
};
void* Obj::Get() {
    return (char*)this + 0x30;
}
