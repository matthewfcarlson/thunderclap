class Obj {
  public:
    void* Get();
};
void* Obj::Get() {
    return (char*)this + 0x38;
}