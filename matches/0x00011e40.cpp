class Obj_11e40 {
  public:
    char pad[0x60];
    void* Get();
};

void* Obj_11e40::Get() {
    return (char*)pad + 0x60;
}
