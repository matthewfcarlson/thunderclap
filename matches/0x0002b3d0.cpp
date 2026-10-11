class Ret {
  public:
    void B(int);
    void D(int);
    void E();
    char pad[0x20a8];
    int m;
};
class Prov {
  public:
    Ret* get(int);
};
class Sub {
  public:
    char pad[0x44];
    Prov* prov;
    Ret* Get(int id) { return prov->get(id); }
};
class Obj {
  public:
    Sub* sub;
    int pad4[2];
    int count;
    int items[0x124 / 4 - 4];
    Ret* current;
    void removeAt(int, int);
    void run();
};
void Obj::run() {
    int i = count - 1;
    if (i >= 0) {
        int* p = &items[i];
        do {
            Prov* pr = sub->prov;
            Ret* r = pr->get(*p);
            if (r && r != current) {
                r->B(0);
                removeAt(i, 0);
            }
            --i;
            --p;
        } while (i >= 0);
    }
    if (current) {
        current->D(1);
        current->E();
        current->m = 0;
    }
}
