class MessageOverlay {
  public:
    void Method(const char*, const char*, const char*, const char*, const char*, const char*, const char*);
};
class Closure7 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, const char**, void*);
    char pad[24];
    void (MessageOverlay::*fn)(const char*, const char*, const char*, const char*, const char*, const char*,
                               const char*);
    MessageOverlay* obj;
};
void Closure7::vfunc_2(void*, const char** a, void*) {
    const char* first = *a;
    const char* b = *++a;
    const char* c = *++a;
    const char* d = *++a;
    const char* e = *++a;
    const char* f = *++a;
    const char* g = *++a;
    (obj->*fn)(first, b, c, d, e, f, g);
}