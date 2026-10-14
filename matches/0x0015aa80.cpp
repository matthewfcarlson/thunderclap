class Obj_15aa80 {
  public:
    char pad[0x88];
    Obj_15aa80* Get();
};

Obj_15aa80* Obj_15aa80::Get() {
    return (Obj_15aa80*)((char*)this + 0x88);
}
