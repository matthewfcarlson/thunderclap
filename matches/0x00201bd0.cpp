class Obj {
  public:
    char pad[0x20];
    void Base();
    void Target();
};
void Obj::Target() {
    char* p = (char*)this;
    p += 0x20;
    ((Obj*)p)->Base();
}
