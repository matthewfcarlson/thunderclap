class Obj {
  public:
    char pad[0x498];
    int value;
    void Set(int x);
};
void Obj::Set(int x) {
    *(int*)((char*)this + 0x498) = x;
}
