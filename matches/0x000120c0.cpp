class Obj_120c0 {
    char pad[0x30];

  public:
    void* Get();
};
void* Obj_120c0::Get() {
    return (char*)this + 0x30;
}
