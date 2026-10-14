class Obj_15b620 {
  public:
    char pad[0x50];
    void* Get();
};

void* Obj_15b620::Get() {
    return (void*)((char*)this + 0x50);
}
