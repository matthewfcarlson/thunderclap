class Obj_12890 {
  public:
    char pad[0x10];
    void* Get();
};
void* Obj_12890::Get() {
    return *(void**)((char*)this + 0x10);
}