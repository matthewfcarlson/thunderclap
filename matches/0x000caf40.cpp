class Obj_caf40 {
  public:
    void Call(int);
};

class Target_caf40 {
  public:
    void Fn(int);
    char pad[0x88];
    Obj_caf40* mObj;
};

void Target_caf40::Fn(int x) {
    Obj_caf40* p = mObj;
    if (p)
        p->Call(x);
}
