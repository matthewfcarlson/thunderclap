typedef unsigned char u8_92940;
struct Obj_92940 {
    char pad[32];
    u8_92940 value;
};
extern void* Cast(void*, int, const void*, const void*, int);
extern char TypeUnlockable[];
extern char TypeCheat[];
extern char TypeMove[];
class Container_92940 {
  public:
    Obj_92940* items[1];
    u8_92940 Get(int index);
};
u8_92940 Container_92940::Get(int index) {
    Obj_92940* r = (Obj_92940*)Cast(items[index], 0, TypeUnlockable, TypeCheat, 0);
    if (!r)
        r = (Obj_92940*)Cast(items[index], 0, TypeUnlockable, TypeMove, 0);
    if (r)
        return r->value;
    return 0;
}