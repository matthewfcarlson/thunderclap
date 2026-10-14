class Obj_139d90 {
  public:
    char pad[0x18];
    int mValue;
    void* Get();
};

void* Obj_139d90::Get() {
    return (void*)&mValue;
}
