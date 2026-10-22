// STATUS: equivalent (tools/equiv.py level 3: 19955 inputs, branch coverage 5/5)
// FUN_000b5710 @ 0x000b5710

struct Head_b5710 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    char pad04[0x14];
};
struct Body_b5710 { char data[0x5c]; };
struct Entry_b5710 : public Head_b5710, public Body_b5710 {
    char done;
};
Entry_b5710* __cdecl FUN_000fc260(const char* name);

struct Menu_b5710 {
    void FUN_000b5250(Body_b5710* body, const char* name, int a2, int a3, int a4, int a5, int a6, int a7);
    void FUN_000b5710(const char* name, int a2, int a3, int a4, int a5, int a6, int a7);
};

void Menu_b5710::FUN_000b5710(const char* name, int a2, int a3, int a4, int a5, int a6, int a7) {
    Entry_b5710* entry = FUN_000fc260("side_mission_success_new_record");
    if (entry == 0)
        return;
    if (name[0] == 0) {
        entry->done = 0;
        return;
    }
    FUN_000b5250(static_cast<Body_b5710*>(entry), name, a2, a3, a4, a5, a6, a7);
    entry->done = 1;
    entry->v3();
}
