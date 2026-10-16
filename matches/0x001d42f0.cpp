class ScriptHandler {
  public:
    void Call(const char*, const char*, const char*, const char*);
};
class Closure4 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(void*, const char**, void*);
    char pad[24];
    void (ScriptHandler::*fn)(const char*, const char*, const char*, const char*);
    ScriptHandler* obj;
};
void Closure4::v2(void* a, const char** args, void* b) {
    const char** p = args;
    const char* x = *p++;
    const char* y = *p++;
    const char* z = *p++;
    const char* w = *p++;
    (obj->*fn)(x, y, z, w);
}