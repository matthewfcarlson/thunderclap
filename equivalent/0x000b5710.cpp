// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 5/6, incomplete)
// FUN_000b5710 @ 0x000b5710
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

struct Head {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    char pad04[0x14];
};
struct Body { char data[0x5c]; };
struct Entry : public Head, public Body {
    char done;
};
Entry* __cdecl FUN_000fc260(const char* name);

struct Menu {
    void FUN_000b5250(Body* body, const char* name, int a2, int a3, int a4, int a5, int a6, int a7);
    void FUN_000b5710(const char* name, int a2, int a3, int a4, int a5, int a6, int a7);
};

void Menu::FUN_000b5710(const char* name, int a2, int a3, int a4, int a5, int a6, int a7) {
    Entry* entry = FUN_000fc260("side_mission_success_new_record");
    if (entry == 0)
        return;
    if (memcmp(name, "", 1) == 0) {
        entry->done = 0;
        return;
    }
    FUN_000b5250(static_cast<Body*>(entry), name, a2, a3, a4, a5, a6, a7);
    entry->done = 1;
    entry->v3();
}
