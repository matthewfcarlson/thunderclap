extern "C" void _ReadWriteBarrier();
extern void Free(void*);
extern void* g_vftable_1d3410;
class Item_1d3410 {
  public:
    virtual void Release(int);
};
class ScriptHandler {
  public:
    void* vptr;
    char pad[4];
    void* p8;
    Item_1d3410* items[1024];
    int count;
    ~ScriptHandler();
};
ScriptHandler::~ScriptHandler() {
    vptr = &g_vftable_1d3410;
    _ReadWriteBarrier();
    if (p8) {
        Free(p8);
        p8 = 0;
    }
    for (int i = 0; i < count; ++i) {
        Item_1d3410* p = items[i];
        if (p)
            p->Release(1);
    }
    count = 0;
}
