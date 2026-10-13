class Obj {
  public:
    char pad[0x18];
    int mValue;
    void* Get();
};

void* Obj::Get() {
    return (void*)&mValue;
}
