class Item_290810 {
  public:
    char pad[8];
    int field;
    void Init();
    void Configure(Item_290810*);
    void Finish(int);
};
Item_290810* __cdecl FUN_00290810(Item_290810* p, int count, Item_290810* arg) {
    if (count != 0) {
        Item_290810* q = p;
        int n = count;
        do {
            if (q != 0) {
                q->Init();
                q->field = 0;
                q->Configure(arg);
                q->Finish(arg->field);
            }
            q = (Item_290810*)((char*)q + 0x10);
            n--;
        } while (n != 0);
        return q;
    }
    return p;
}
