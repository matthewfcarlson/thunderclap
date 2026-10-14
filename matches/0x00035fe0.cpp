class Context {
  public:
    int Query(int);
};
class Obj_35fe0 {
  public:
    char pad[0x40];
    int arg;
    char pad2[0xa8];
    Context* ctx;
};
struct Slot_35fe0 {
    Obj_35fe0* p;
    char pad[0x4c];
};
class Owner_35fe0 {
  public:
    char pad[0x3a8];
    Slot_35fe0 items[8];
    int Find();
};
int Owner_35fe0::Find() {
    for (int i = 0; i < 8; ++i) {
        Obj_35fe0* p = items[i].p;
        if (p) {
            int a = p->arg;
            Context* c = p->ctx;
            if (c->Query(a) == 2)
                return i;
        }
    }
    return -1;
}
