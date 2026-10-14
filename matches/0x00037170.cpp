class Obj {
  public:
    char pad[0x22dc];
    void Set(int x);
};
void Obj::Set(int x) {
    *(int*)((char*)this + 0x22dc) = x;
}
