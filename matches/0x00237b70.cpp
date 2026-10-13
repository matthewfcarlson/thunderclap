class Obj {
  public:
    char pad[12];
    void* Get();
};
void* Obj::Get() {
    return (char*)this + 12;
}
