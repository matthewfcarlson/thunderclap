class Obj_cac40 {
  public:
    char pad[0x498];
    int value;
    void Set(int x);
};
void Obj_cac40::Set(int x) {
    *(int*)((char*)this + 0x498) = x;
}
