class Item_290810 {
  public:
    char pad[8];
    int field;
    void Init();
    void Configure(Item_290810*);
    void Finish(int);
};
extern "C" void * __cdecl FUN_00290810(void * p, int count, void * arg) {
    if (count != 0) {
        Item_290810* q = ((Item_290810 *)p);
        int n = count;
        do {
            if (q != 0) {
                q->Init();
                q->field = 0;
                q->Configure(((Item_290810 *)arg));
                q->Finish(((Item_290810 *)arg)->field);
            }
            q = (Item_290810*)((char*)q + 0x10);
            n--;
        } while (n != 0);
        return (Item_290810 *)q;
    }
    return (Item_290810 *)((Item_290810 *)p);
}
