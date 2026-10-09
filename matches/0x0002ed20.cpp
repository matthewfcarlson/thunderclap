struct CActorManager {};
extern char GetName(const char*);
class Obj {
  public:
    int vt;
    char pad4[0x0c];
    char b10;
    char pad11[7];
    char b18;
    char pad19[3];
    CActorManager* p1c;
    void* p20;
    void Init(const char*, int);
    Obj(const char*, void*, CActorManager*);
};
Obj::Obj(const char* arg, void* p, CActorManager* cm) {
    Init(arg, 1);
    vt = 0x3f410c;
    p1c = cm;
    b18 = GetName((const char*)0x48e100);
    b10 = GetName((const char*)0x48e0f0);
    vt = 0x3f442c;
    p20 = p;
}