struct State_e54d0 {
    int value;
    void action();
};
struct Obj_e54d0 {
    char pad[0xe0];
    State_e54d0 state;
};
struct Host_e54d0 {
    char pad[0x44c];
    Obj_e54d0* entries[0x80];
};
void __fastcall FUN_000e54d0(Host_e54d0* self) {
    int i = 0;
    Obj_e54d0** p = self->entries;
    do {
        Obj_e54d0* o = *p;
        if (!o)
            return;
        State_e54d0* s = &o->state;
        if (s->value == 3)
            s->action();
        ++i;
        ++p;
    } while (i < 0x80);
}