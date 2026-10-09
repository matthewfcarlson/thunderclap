typedef unsigned char u8;
struct Obj {
    char pad[32];
    u8 value;
};
extern void* Cast(void*, int, const void*, const void*, int);
extern char TypeUnlockable[];
extern char TypeCheat[];
extern char TypeMove[];
class Container {
  public:
    Obj* items[1];
    u8 Get(int index);
};
u8 Container::Get(int index) {
    Obj* r = (Obj*)Cast(items[index], 0, TypeUnlockable, TypeCheat, 0);
    if (!r)
        r = (Obj*)Cast(items[index], 0, TypeUnlockable, TypeMove, 0);
    if (r)
        return r->value;
    return 0;
}