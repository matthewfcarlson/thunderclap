class Obj_193b80 {
  public:
    char pad[0x98];
    void* Get();
};

void* Obj_193b80::Get() {
    return (char*)this + 0x98;
}
