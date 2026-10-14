class Obj_e3f20 {
  public:
    char pad[0x2aC];
    void Base(Obj_e3f20*);
    void CopyFrom(Obj_e3f20*);
};
extern "C" void* memcpy(void*, const void*, unsigned int);
void Obj_e3f20::CopyFrom(Obj_e3f20* other) {
    Base(other);
    memcpy((char*)this + 0x118, (char*)other + 0x118, 40);
    int* d = (int*)((char*)this + 0x290);
    int* s = (int*)((char*)other + 0x290);
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    d[4] = s[4];
    d[5] = s[5];
    d[6] = s[6];
}