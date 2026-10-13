class Obj {
  public:
    char pad[0x60];
    void Set(int v);
};
void Obj::Set(int v) {
    *(int*)((char*)this + 0x60) = v;
}
