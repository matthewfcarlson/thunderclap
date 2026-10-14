class Ret_2b3d0 {
  public:
    void B(int);
    void D(int);
    void E();
    char pad[0x20a8];
    int m;
};
class Prov_2b3d0 {
  public:
    Ret_2b3d0* get(int);
};
class Sub_2b3d0 {
  public:
    char pad[0x44];
    Prov_2b3d0* prov;
    Ret_2b3d0* Get(int id) { return prov->get(id); }
};
class Obj_2b3d0 {
  public:
    Sub_2b3d0* sub;
    int pad4[2];
    int count;
    int items[0x124 / 4 - 4];
    Ret_2b3d0* current;
    void removeAt(int, int);
    void run();
};
void Obj_2b3d0::run() {
    int i = count - 1;
    if (i >= 0) {
        int* p = &items[i];
        do {
            Prov_2b3d0* pr = sub->prov;
            Ret_2b3d0* r = pr->get(*p);
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
