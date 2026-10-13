class Obj {
  public:
    char pad[0x50];
    void* Get();
};

void* Obj::Get() {
    return (void*)((char*)this + 0x50);
}
