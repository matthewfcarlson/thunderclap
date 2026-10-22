class Item_2a68b0 {
  public:
    virtual void A();
    virtual void Release();
};
void Free(void*);
class ProceduralVertexAnimController_2a68b0 {
  public:
    char pad[0x40];
    int x40;
    int x44;
    unsigned int count;
    Item_2a68b0** items;
    void Run();
};
void ProceduralVertexAnimController_2a68b0::Run() {
    unsigned int i = 0;
    if (0 < count) {
        do {
            Item_2a68b0** slot = &items[i];
            Item_2a68b0* p = *slot;
            if (p) {
                p->Release();
                *slot = 0;
            }
            ++i;
        } while (i < count);
    }
    Free(items);
    items = 0;
    x40 = 0;
    x44 = 0;
}
