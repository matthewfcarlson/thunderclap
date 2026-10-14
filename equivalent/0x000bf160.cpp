// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// FUN_000bf160 @ 0x000bf160
class FEObject {
public:
    virtual void v0();
};

class TextButton : public FEObject {
public:
    char pad04[0x74 - 4];
    unsigned char f74;
    char pad75[0x141 - 0x75];
    unsigned char f141;
};

struct Item_bf160 {
    char pad0[0x14];
    int id;
};

class Panel_bf160 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void Select(int id);
};

class Manager_bf160 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Panel_bf160 *Find(const char *name);
};

struct Settings_bf160 {
    char pad0[0xabf];
    unsigned char difficulty;
    unsigned char FUN_000893c0();
};

Manager_bf160 *__cdecl FUN_000fc3d0();
Item_bf160 *__cdecl FUN_000fc260(const char *name);

class DifficultyScreen {
public:
    char pad0[0x34];
    Settings_bf160 *settings;
    void FUN_000bf160();
};

void DifficultyScreen::FUN_000bf160()
{
    Panel_bf160 *sel = FUN_000fc3d0()->Find("difficulty_select");
    if (sel != 0) {
        Item_bf160 *normal = FUN_000fc260("difficulty_normal");
        if (normal != 0)
            sel->Select(normal->id);
    }
    TextButton *hard = dynamic_cast<TextButton *>((FEObject *)FUN_000fc260("difficulty_hard"));
    if (hard != 0) {
        unsigned char v = settings->FUN_000893c0();
        hard->f141 = v;
        hard->f74 = v;
    }
}
