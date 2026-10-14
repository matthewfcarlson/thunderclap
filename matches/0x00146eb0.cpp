class Obj_146eb0 {
  public:
    char pad[0x20];
    void* Get();
};
void* Obj_146eb0::Get() {
    return (void*)((char*)this + 0x20);
}