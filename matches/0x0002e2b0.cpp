extern "C" char DAT_003f431c[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e134[];
class Base {
  public:
    Base(int, int);
};
class CActorManager : public Base {
  public:
    int v;
    char pad[0x18];
    int m1c;
    CActorManager(int, int);
};
extern char __cdecl ReadValue(const char*);
CActorManager::CActorManager(int a, int b) : Base(a, 3) {
    v = ((int)DAT_003f431c);
    m1c = b;
    *((char*)this + 0x18) = ReadValue((const char*)((int)DAT_0048e100));
    *((char*)this + 0x10) = ReadValue((const char*)((int)DAT_0048e134));
    *((char*)this + 0x11) = ReadValue((const char*)((int)DAT_0048e134));
    *((char*)this + 0x12) = ReadValue((const char*)((int)DAT_0048e134));
}