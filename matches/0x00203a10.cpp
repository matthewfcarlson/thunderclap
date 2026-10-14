extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Obj_203a10 {
  public:
    bool A(int);
    bool B(int);
};
class Manager_203a10 {
  public:
    Obj_203a10* Get();
};
class Root_203a10 {
  public:
    char pad[0x54];
    Manager_203a10* mgr;
};
extern Root_203a10* gRoot_203a10;
class C_203a10 {
  public:
    char pad[0xaa4];
    char name[0x20];
    void Apply(int);
    void Run();
};
void C_203a10::Run() {
    strncpy(name, "hulk", 0x20);
    Obj_203a10* o = gRoot_203a10->mgr->Get();
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
