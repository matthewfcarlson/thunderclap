class Obj_237280 {
  public:
    char pad[0x28];
    char* Get();
};

char* Obj_237280::Get() {
    return (char*)((char*)pad + 0x28);
}
