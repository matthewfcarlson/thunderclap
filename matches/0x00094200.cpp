extern void __stdcall Init(int, int);
extern char __cdecl Query(const char*);
extern char s0;
extern char s1;
extern char s2;
extern char s3;
class CUnlockablesManager {
  public:
    int v;
    char pad4[12];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int value;
    CUnlockablesManager(int a, int b);
};
CUnlockablesManager::CUnlockablesManager(int a, int b) {
    Init(a, 3);
    v = 0x4046dc;
    value = b;
    b18 = Query(&s0);
    b10 = Query(&s1);
    b11 = Query(&s2);
    b12 = Query(&s3);
}