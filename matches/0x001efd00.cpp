typedef unsigned int size_t;
void* __cdecl operator new(size_t, int);
class Command {
  public:
    virtual void Run();
    int a;
    int b;
    int id;
    Command(int n) : a(0), b(0), id(n) {}
};
class StopCommand : public Command {
  public:
    StopCommand(int n) : Command(n) {}
    virtual void Run();
};
class Manager {
  public:
    void Add(Command*);
};
extern Manager* gManager;
void __stdcall FUN_001efd00(int id) {
    Manager* m = gManager;
    if (gManager) {
        StopCommand* cmd = new (6) StopCommand(id);
        m->Add(cmd);
    }
}