class Obj_12b330 {
  public:
    char pad[0x30];
    char* Get();
};
char* Obj_12b330::Get() {
    return (char*)this + 0x30;
}