class Obj_201bd0 {
  public:
    char pad[0x20];
    void Base(int);
    void Target(int);
};
void Obj_201bd0::Target(int a0) {
    char* p = (char*)this;
    p += 0x20;
    ((Obj_201bd0*)p)->Base(a0);
}
