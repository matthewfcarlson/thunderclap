class Temp_1ebd00 {
  public:
    void Init();
    void Add(const char*);
    void Finish();
};
class Manager_1ebd00 {
  public:
    void Run(char*, int, const char*, float);
};
class Owner_1ebd00 {
  public:
    void Go(const char*, const char*);
};
extern Manager_1ebd00* gManager_1ebd00;
void Owner_1ebd00::Go(const char* a, const char* b) {
    if (!a || !*a)
        return;
    if (!b || !*b)
        return;
    char storage[0x48];
    Temp_1ebd00* t = (Temp_1ebd00*)storage;
    t->Init();
    t->Add("Objects");
    t->Add("FE");
    t->Add(a);
    if (*(char*)((char*)gManager_1ebd00 + 8))
        ((Manager_1ebd00*)*(void**)gManager_1ebd00)->Run((char*)t, 0, b, 100.0f);
    t->Finish();
}