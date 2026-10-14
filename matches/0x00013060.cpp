class Obj_13060 {
  public:
    char pad[0x40];
    void* Get();
};

void* Obj_13060::Get() {
    return (char*)this + 0x40;
}
