class Obj_192850 {
  public:
    char pad[0x18];
    Obj_192850* Get();
};
Obj_192850* Obj_192850::Get() {
    return (Obj_192850*)((char*)this + 0x18);
}
