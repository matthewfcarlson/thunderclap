class Builder {
  public:
    void Init();
    void Add(const char*);
    void Finish();
};
class Runner {
  public:
    void Run(void*, void*, const char*, float);
};
class State {
  public:
    Runner* runner;
    char pad[4];
    char enabled;
};
extern State* gState;
extern const char sObjects[];
extern const char sDialogue[];
extern const char sCow[];
void __stdcall target(void* param1, const char* param2) {
    char local[72];
    if (!param1)
        return;
    if (!param2)
        return;
    if (!*param2)
        return;
    Builder* b = (Builder*)local;
    b->Init();
    b->Add(sObjects);
    b->Add(sDialogue);
    b->Add(sCow);
    State* s = gState;
    if (s->enabled)
        s->runner->Run(local, (char*)param1 + 8, param2, 100.0f);
    b->Finish();
}