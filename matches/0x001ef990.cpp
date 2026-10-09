class Sub {
  public:
    void Cleanup();
};
class Obj {
    char pad[0xa0];

  public:
    Sub sub;
    void* Run(int flags);
};
extern void __cdecl thunk(Obj*);
void* Obj::Run(int flags) {
    sub.Cleanup();
    if (flags & 1)
        thunk(this);
    return this;
}