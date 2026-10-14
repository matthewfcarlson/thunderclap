class Obj_5a350 {
  public:
    char pad[0x1c];
    void* Get();
};
void* Obj_5a350::Get() {
    return (char*)this + 0x1c;
}