class Obj {
  public:
    char pad[0x30];
    char data;
    char* Get();
};
char* Obj::Get() {
    return &data;
}