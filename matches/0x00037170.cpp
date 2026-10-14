class Obj_37170 {
  public:
    char pad[0x22dc];
    void Set(int x);
};
void Obj_37170::Set(int x) {
    *(int*)((char*)this + 0x22dc) = x;
}
