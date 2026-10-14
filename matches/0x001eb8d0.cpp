class Temp_1eb8d0 {
  public:
    char pad[0x48];
    void Init();
    void Add(const char*);
    void Finish();
};
class Manager_1eb8d0 {
  public:
    void* Lookup();
};
class Root_1eb8d0 {
  public:
    void Run(Temp_1eb8d0*, int, int, float);
};
class Owner_1eb8d0 {
  public:
    Root_1eb8d0* root;
    Manager_1eb8d0* manager;
    unsigned char flag;
    void Target(int);
};
extern void __cdecl FUN_001eb440(void*, Temp_1eb8d0*);
void Owner_1eb8d0::Target(int arg) {
    Temp_1eb8d0 t;
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