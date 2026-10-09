extern char s1[];
extern char s2[];
extern char s3[];
extern char s4[];
extern char __cdecl Convert(const char*);
class CCameraManager {
  public:
    void Init(void*, int);
    CCameraManager(void*, int);
    char a[0x10];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int field1c;
};
CCameraManager::CCameraManager(void* p, int value) {
    Init(p, 3);
    *(int*)this = 0x404c20;
    field1c = value;
    b18 = Convert(s1);
    b10 = Convert(s2);
    b11 = Convert(s3);
    b12 = Convert(s4);
}