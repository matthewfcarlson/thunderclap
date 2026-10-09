class ScriptHandler {
  public:
    virtual void V();
    void Init(const char*, int);
    char pad[0x0c];
    char m10;
    char pad11[7];
    char m18;
    char pad19[3];
    int m1c;
    int m20;
    ScriptHandler* Run(const char*, const char*, const char*);
};
extern char __cdecl FUN_001d04d0(const char*);
ScriptHandler* ScriptHandler::Run(const char* a, const char* b, const char* c) {
    Init(a, 1);
    *(int*)this = 0x422644;
    m1c = (int)c;
    m18 = FUN_001d04d0((const char*)0x48e0f0);
    m10 = FUN_001d04d0((const char*)0x48e0f0);
    *(int*)this = 0x422800;
    m20 = (int)b;
    return this;
}