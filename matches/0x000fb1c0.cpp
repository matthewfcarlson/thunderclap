extern "C" __int64 FUN_0027b020(int);
struct Caster {
    virtual void cast();
};
struct Inventory {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int get(Caster*, __int64);
    virtual void d();
    virtual void use(int);
};
extern Inventory* inventory;
inline int find(Inventory* inv, __int64 key) {
    Caster caster;
    return inv->get(&caster, key);
}
char FUN_000fb1c0(int id) {
    char result = 0;
    __int64 key = FUN_0027b020(id);
    int item = find(inventory, key);
    if (item) {
        inventory->use(item);
        result = 1;
    }
    return result;
}