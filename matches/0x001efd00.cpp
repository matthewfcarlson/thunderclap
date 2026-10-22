typedef unsigned int size_t;
void* __cdecl operator new(size_t, int);
class CSoundCommand_1efd00 {
  public:
    virtual void Run();
    int a;
    int b;
    int id;
    CSoundCommand_1efd00(int n) : a(0), b(0), id(n) {}
};
class CSoundCommand_StopNISEvent_1efd00 : public CSoundCommand_1efd00 {
  public:
    CSoundCommand_StopNISEvent_1efd00(int n) : CSoundCommand_1efd00(n) {}
    virtual void Run();
};
class Manager {
  public:
    void Add(CSoundCommand_1efd00*);
};
extern Manager* gManager;
void __stdcall FUN_001efd00(int id) {
    Manager* m = gManager;
    if (gManager) {
        CSoundCommand_StopNISEvent_1efd00* cmd = new (6) CSoundCommand_StopNISEvent_1efd00(id);
        m->Add(cmd);
    }
}