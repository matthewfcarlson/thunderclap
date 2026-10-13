class Obj {
  public:
    char pad[8];
    void* Get();
};

void* Obj::Get() {
    return (char*)this + 8;
}
