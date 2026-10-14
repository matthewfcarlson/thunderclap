// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 13/14, incomplete)
// pure3d::ExpressionAnimationController::vfunc_26 @ 0x002a9e30
struct Elem {
    int FUN_002afe80(void* key);
};
struct Anim {
    char pad00[0x1c];
    int tag;
    char pad20[8];
    int count;
    void* FUN_00288a10(int i);
};
struct Inner {
    char pad[0x10];
    Elem* elem;
};
class ExprCtl {
  public:
    virtual void v0();
    char pad04[0x3c];
    Inner* inner;
    char FUN_002a9e30(Anim* a);
};
char ExprCtl::FUN_002a9e30(Anim* a) {
    if (a == 0)
        return 0;
    if (a->count <= 0)
        return 0;
    if (a->tag != 0x505845)
        return 0;
    if (inner != 0) {
        Elem* e = inner->elem;
        int i = 0;
        do {
            void* item = a->FUN_00288a10(i);
            if (e->FUN_002afe80((char*)item + 8) == -1)
                return 0;
            i++;
        } while (i < a->count);
    }
    return 1;
}
