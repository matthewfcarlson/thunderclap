class Obj_1c9fb0 {
  public:
    bool valid();
    void set(const char*, void*);
    void finish();
};
class This_1c9fb0 {
  public:
    char pad[0x14];
    int a;
    char pad2[0x1c];
    int b;
    Obj_1c9fb0* get();
};
bool __fastcall target(This_1c9fb0* self) {
    Obj_1c9fb0* o = self->get();
    if (!o)
        return false;
    if (!o->valid())
        return false;
    o->set("eg", &self->a);
    o->set("locator", &self->b);
    o->finish();
    return true;
}