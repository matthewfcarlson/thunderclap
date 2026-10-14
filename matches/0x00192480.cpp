class Obj_192480 {
  public:
    char pad[0x88];
    char* Get();
};

char* Obj_192480::Get() {
    return (char*)((char*)this + 0x88);
}
