class Obj_333410 {
  public:
    char pad[0x60];
    void Set(int v);
};
void Obj_333410::Set(int v) {
    *(int*)((char*)this + 0x60) = v;
}
