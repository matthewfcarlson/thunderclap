extern "C" char DAT_00428bf8[];
extern void* __cdecl alloc(unsigned int);
class CommentCondition {
  public:
    int vtable;
    char pad[8];
    int value;
    void Init(int);
};
class Factory_23de30 {
  public:
    CommentCondition* vfunc_5();
};
CommentCondition* Factory_23de30::vfunc_5() {
    CommentCondition* p = (CommentCondition*)alloc(0x10);
    if (p) {
        p->Init(3);
        p->vtable = ((int)DAT_00428bf8);
        p->value = 0;
        return p;
    }
    return 0;
}