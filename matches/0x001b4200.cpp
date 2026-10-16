struct Arg {
    char pad[0x74];
    void* p;
};
class Mgr {
  public:
    void Act(void*);
};
class Obj {
  public:
    char pad[8];
    Mgr* mgr;
    bool Run(Arg* a);
};
bool Obj::Run(Arg* a) {
    void* p = a->p;
    bool r = true;
    if (p)
        mgr->Act(p);
    else
        r = false;
    return r;
}