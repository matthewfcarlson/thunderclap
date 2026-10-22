struct Obj {
    char pad[0x19c];
    float val;
};
struct Item {
    char pad[0x18];
    Obj* ptr;
    char gap[6];
    short index;
    char rest[4];
};
class CSPManager_1ddda0 {
  public:
    char flags[0x608];
    Item items[1];
    float get(int x);
    int find(int);
};
float CSPManager_1ddda0::get(int x) {
    int i = find(x);
    if (i >= 0) {
        Item* p = &items[i];
        int n = p->index + 0x104e;
        if (flags[n * 20] & 1) {
            Obj* o = p->ptr;
            if (o)
                return o->val;
        }
    }
    return 0.0f;
}