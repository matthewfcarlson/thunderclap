class Obj {
  public:
    char pad[0x80];
    void Helper();
    void Target();
};
void Obj::Target() {
    ((Obj*)((char*)this + 0x80))->Helper();
}
