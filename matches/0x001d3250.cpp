extern const char text100[];
extern const char text0f0[];
extern char FUN_001d04d0(const char*);
class ScriptHandler {
  public:
    int vft;
    char pad4[0x0c];
    char b10, b11, b12, b13;
    char pad14[4];
    char b18;
    char pad19[3];
    void* p1c;
    void Init(const char*, int);
    ScriptHandler* Create(const char*, const char*);
};
ScriptHandler* ScriptHandler::Create(const char* a, const char* b) {
    Init(a, 4);
    vft = 0x422654;
    p1c = (void*)b;
    b18 = FUN_001d04d0(text100);
    b10 = FUN_001d04d0(text0f0);
    b11 = FUN_001d04d0(text0f0);
    b12 = FUN_001d04d0(text0f0);
    b13 = FUN_001d04d0(text0f0);
    return this;
}