typedef unsigned int size_t;
extern "C" char* __cdecl strncpy(char*, const char*, size_t);
extern int DAT_0042c0f8;
class RDLObject {
  public:
    void init();
    int* vp;
    char pad[12];
    int a;
    int b;
    char rest[0x37 - 0x18];
    char flag;
    RDLObject(const char*);
};
RDLObject::RDLObject(const char* p) {
    init();
    a = 0;
    b = 0;
    flag = 0;
    vp = &DAT_0042c0f8;
    strncpy((char*)this + 0x18, p, 0x1f);
}