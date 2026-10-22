struct Obj {
    void Fn(int);
};
struct Item {
    char pad[0x18];
    Obj* obj;
    char gap[6];
    short a;
    char tail[4];
};
class CSPManager_1ddbd0 {
  public:
    int Find(int);
    void Run(int, int);
    char pad[0x608];
    Item items[1];
};
void CSPManager_1ddbd0::Run(int id, int v) {
    int n = Find(id);
    if (n >= 0) {
        Item* p = &items[n];
        int k = p->a + 0x104e;
        if (((char*)this)[k * 20] & 1) {
            Obj* o = p->obj;
            if (o)
                o->Fn(v);
        }
    }
}