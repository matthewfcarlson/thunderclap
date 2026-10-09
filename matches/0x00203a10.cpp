extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Obj {
  public:
    bool A(int);
    bool B(int);
};
class Manager {
  public:
    Obj* Get();
};
class Root {
  public:
    char pad[0x54];
    Manager* mgr;
};
extern Root* gRoot;
class C {
  public:
    char pad[0xaa4];
    char name[0x20];
    void Apply(int);
    void Run();
};
void C::Run() {
    strncpy(name, "hulk", 0x20);
    Obj* o = gRoot->mgr->Get();
    if (o != 0) {
        int i = 0;
        while (o->A(i) || !o->B(i)) {
            ++i;
            if (i > 12)
                return;
        }
        if (i != -1)
            Apply(i);
    }
}
