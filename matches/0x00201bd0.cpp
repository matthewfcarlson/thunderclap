class Obj_201bd0 {
  public:
    char pad[0x20];
    void Base();
    void Target();
};
void Obj_201bd0::Target() {
    char* p = (char*)this;
    p += 0x20;
    ((Obj_201bd0*)p)->Base();
}
