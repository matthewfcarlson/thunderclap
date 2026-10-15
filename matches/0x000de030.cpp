class Item {
  public:
    char pad[16];
    int size;
    int count;
    void** values;
};
class Manager {
  public:
    void Apply(void*);
};
class FEThings {
  public:
    virtual void vfunc_42(Item*);
    char pad[0x2220];
    Manager* mgr;
};
void FEThings::vfunc_42(Item* p) {
    int n = p->count;
    for (int i = 0; i < n; ++i) {
        void* v = i < p->size ? p->values[i] : 0;
        mgr->Apply(v);
    }
}