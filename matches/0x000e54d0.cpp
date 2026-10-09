struct State {
    int value;
    void action();
};
struct Obj {
    char pad[0xe0];
    State state;
};
struct Host {
    char pad[0x44c];
    Obj* entries[0x80];
};
void __fastcall FUN_000e54d0(Host* self) {
    int i = 0;
    Obj** p = self->entries;
    do {
        Obj* o = *p;
        if (!o)
            return;
        State* s = &o->state;
        if (s->value == 3)
            s->action();
        ++i;
        ++p;
    } while (i < 0x80);
}