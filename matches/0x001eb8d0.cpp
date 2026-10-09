class Temp {
  public:
    char pad[0x48];
    void Init();
    void Add(const char*);
    void Finish();
};
class Manager {
  public:
    void* Lookup();
};
class Root {
  public:
    void Run(Temp*, int, int, float);
};
class Owner {
  public:
    Root* root;
    Manager* manager;
    unsigned char flag;
    void Target(int);
};
extern void __cdecl FUN_001eb440(void*, Temp*);
void Owner::Target(int arg) {
    Temp t;
    if (flag) {
        t.Init();
        t.Add("Objects");
        t.Add("Mix");
        void* p = manager->Lookup();
        if (p)
            FUN_001eb440(p, &t);
        if (flag)
            root->Run(&t, 0, arg, 100.0f);
        t.Finish();
    }
}