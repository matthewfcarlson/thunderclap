class Obj_15aa40 {
  public:
    char pad[0x68];
    void* Get();
};

void* Obj_15aa40::Get() {
    return (char*)this + 0x68;
}
