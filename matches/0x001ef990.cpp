class Sub_1ef990 {
  public:
    void Cleanup();
};
class Obj_1ef990 {
    char pad[0xa0];

  public:
    Sub_1ef990 sub;
    void* Run(int flags);
};
extern void __cdecl thunk(Obj_1ef990*);
void* Obj_1ef990::Run(int flags) {
    sub.Cleanup();
    if (flags & 1)
        thunk(this);
    return this;
}