extern "C" void _ReadWriteBarrier();
extern void Free(void*);
extern void* g_vftable;
class Item {
  public:
    virtual void Release(int);
};
class ScriptHandler {
  public:
    void* vptr;
    char pad[4];
    void* p8;
    Item* items[1024];
    int count;
    ~ScriptHandler();
};
ScriptHandler::~ScriptHandler() {
    vptr = &g_vftable;
    _ReadWriteBarrier();
    if (p8) {
        Free(p8);
        p8 = 0;
    }
    for (int i = 0; i < count; ++i) {
        Item* p = items[i];
        if (p)
            p->Release(1);
    }
    count = 0;
}
