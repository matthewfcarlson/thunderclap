class Temp {
  public:
    void Init();
    void Add(const char*);
    void Finish();
};
class Manager {
  public:
    void Run(char*, int, const char*, float);
};
class Owner {
  public:
    void Go(const char*, const char*);
};
extern Manager* gManager;
void Owner::Go(const char* a, const char* b) {
    if (!a || !*a)
        return;
    if (!b || !*b)
        return;
    char storage[0x48];
    Temp* t = (Temp*)storage;
    t->Init();
    t->Add("Objects");
    t->Add("FE");
    t->Add(a);
    if (*(char*)((char*)gManager + 8))
        ((Manager*)*(void**)gManager)->Run((char*)t, 0, b, 100.0f);
    t->Finish();
}