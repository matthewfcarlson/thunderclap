class Obj_12da0 {
  public:
    char pad[0x30];
    char data;
    char* Get();
};
char* Obj_12da0::Get() {
    return &data;
}