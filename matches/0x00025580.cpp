class Obj {
  public:
    char pad[0x32c];
    int m32c;
    int GetX();
};

int Obj::GetX() {
    return m32c;
}
