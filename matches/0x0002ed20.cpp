extern "C" char DAT_003f410c[];
extern "C" char DAT_003f442c[];
extern "C" char DAT_0048e0f0[];
extern "C" char DAT_0048e100[];
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
    vt = ((int)DAT_003f410c);
    p1c = cm;
    b18 = GetName((const char*)((int)DAT_0048e100));
    b10 = GetName((const char*)((int)DAT_0048e0f0));
    vt = ((int)DAT_003f442c);
    p20 = p;
}