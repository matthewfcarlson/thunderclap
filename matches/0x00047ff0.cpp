class Obj_47ff0 {
  public:
    char pad[0x10];
    void* Get();
};
void* Obj_47ff0::Get() {
    char* p = (char*)this + 0x10;
    return p;
}
