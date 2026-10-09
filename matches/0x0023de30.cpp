extern void* __cdecl alloc(unsigned int);
class CommentCondition {
  public:
    int vtable;
    char pad[8];
    int value;
    void Init(int);
};
class Factory {
  public:
    CommentCondition* vfunc_5();
};
CommentCondition* Factory::vfunc_5() {
    CommentCondition* p = (CommentCondition*)alloc(0x10);
    if (p) {
        p->Init(3);
        p->vtable = 0x428bf8;
        p->value = 0;
        return p;
    }
    return 0;
}