class Obj_15aa10 {
  public:
    char pad[0x50];
    char* Get();
};
char* Obj_15aa10::Get() {
    return (char*)this + 0x50;
}