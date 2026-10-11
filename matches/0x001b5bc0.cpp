extern "C" char DAT_0041da1c[];
extern int __stdcall FUN_001d0480(const char*, int);
extern char FUN_001d04d0(const char*);
extern char str1, str2;
class CCollisionManager {
  public:
    int vtable;
    char pad04[12];
    char value10, value11, value12;
    char pad13[5];
    char value18;
    char pad19[3];
    int value1c;
    CCollisionManager(int, int);
};
CCollisionManager::CCollisionManager(int a, int b) {
    FUN_001d0480((const char*)a, 3);
    vtable = ((int)DAT_0041da1c);
    value1c = b;
    value18 = FUN_001d04d0(&str1);
    value10 = FUN_001d04d0(&str2);
    value11 = FUN_001d04d0(&str2);
    value12 = FUN_001d04d0(&str2);
}