class Obj {
  public:
    int Get();
    char pad[0x9c];
    int m9c;
};
int Obj::Get() {
    return m9c;
}
