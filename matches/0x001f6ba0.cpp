class Obj {
  public:
    char pad[8];
    int field;
    void work();
};
class Owner {
  public:
    char pad[0xc8];
    Obj* member;
};
bool __fastcall run(Owner* self) {
    Obj* p = self->member;
    if (p && p->field) {
        p->work();
        return true;
    }
    return false;
}
