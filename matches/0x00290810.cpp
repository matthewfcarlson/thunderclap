class Item {
  public:
    char pad[8];
    int field;
    void Init();
    void Configure(Item*);
    void Finish(int);
};
Item* __cdecl FUN_00290810(Item* p, int count, Item* arg) {
    if (count != 0) {
        Item* q = p;
        int n = count;
        do {
            if (q != 0) {
                q->Init();
                q->field = 0;
                q->Configure(arg);
                q->Finish(arg->field);
            }
            q = (Item*)((char*)q + 0x10);
            n--;
        } while (n != 0);
        return q;
    }
    return p;
}
