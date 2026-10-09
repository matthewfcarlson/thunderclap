struct B {
    void Init(int, int);
};
extern char ReadValue(const char*);
class CWorldStreamManager {
  public:
    int vptr;
    char p04[12];
    char b10, b11, b12;
    char p13[5];
    char b18;
    char p19[3];
    int value1c;
    CWorldStreamManager(int a, int b);
};
CWorldStreamManager::CWorldStreamManager(int a, int b) {
    ((B*)this)->Init(a, 3);
    vptr = 0x425b64;
    value1c = b;
    b18 = ReadValue((const char*)0x48e134);
    b10 = ReadValue((const char*)0x48e128);
    b11 = ReadValue((const char*)0x48e128);
    b12 = ReadValue((const char*)0x48e128);
}