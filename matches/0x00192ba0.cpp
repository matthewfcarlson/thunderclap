class Obj_192ba0 {
  public:
    char pad[0xc0];
    void* Get();
};

void* Obj_192ba0::Get() {
    return (char*)this + 0xc0;
}
