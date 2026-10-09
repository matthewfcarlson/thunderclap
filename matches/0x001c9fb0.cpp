class Obj {
  public:
    bool valid();
    void set(const char*, void*);
    void finish();
};
class This {
  public:
    char pad[0x14];
    int a;
    char pad2[0x1c];
    int b;
    Obj* get();
};
bool __fastcall target(This* self) {
    Obj* o = self->get();
    if (!o)
        return false;
    if (!o->valid())
        return false;
    o->set("eg", &self->a);
    o->set("locator", &self->b);
    o->finish();
    return true;
}