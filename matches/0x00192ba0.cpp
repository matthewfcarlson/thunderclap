class Obj {
  public:
    char pad[0xc0];
    void* Get();
};

void* Obj::Get() {
    return (char*)this + 0xc0;
}
