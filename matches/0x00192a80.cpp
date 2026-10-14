class Obj_192a80 {
  public:
    char pad[0x84];
    char* Get();
};

char* Obj_192a80::Get() {
    return (char*)this + 0x84;
}
