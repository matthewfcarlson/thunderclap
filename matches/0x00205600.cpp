class InitBase {
  public:
    void Init(const char*, int);
};
class CWorldStreamManager {
  public:
    CWorldStreamManager(const char*, int);
    int vptr;
    char p[12];
    char f10, f11, f12;
    char p2[5];
    char f18;
    char p3[3];
    int f1c;
};
extern char* __cdecl FUN_001d04d0(const char*);
extern char str1[], str2[], str3[], str4[];
CWorldStreamManager::CWorldStreamManager(const char* a, int b) {
    ((InitBase*)this)->Init(a, 3);
    vptr = 0x425be4;
    f1c = b;
    f18 = (char)FUN_001d04d0(str1);
    f10 = (char)FUN_001d04d0(str2);
    f11 = (char)FUN_001d04d0(str3);
    f12 = (char)FUN_001d04d0(str4);
}