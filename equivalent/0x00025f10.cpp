// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 20/20)
// FUN_00025f10 @ 0x00025f10
// 0x00025f10: set a flag on the controller(s) selected by name ("all" or one named entry)
int __cdecl FUN_00096600(const char* a, const char* b);
unsigned __int64 __cdecl FUN_002672f0(const char* name, int a, int b);

struct Pawn {
    char pad[0x1ca0];
    struct Ctl* ctl;
    char pad2[0];
    char FUN_00035ab0();
};
struct Ctl {
    char pad[0xf4];
    char flag;
};
struct Pawns {
    Pawn* FUN_00059c10(int id);
};
struct World {
    char pad[0x44];
    Pawns* pawns;
};

class Group {
public:
    World* world;
    int pad04[2];
    int count;
    int ids[16];
    Pawn* FUN_00024280(unsigned __int64 key);
    void SetFlag(const char* name, char flag);
};

void Group::SetFlag(const char* name, char flag)
{
    if (name == 0 || *name == 0)
        return;

    if (FUN_00096600(name, "all") == 0) {
        for (int i = 0; i < count; i++) {
            Pawn* p = world->pawns->FUN_00059c10(ids[i]);
            if (p == 0 || p->FUN_00035ab0() == 0) {
                Ctl* c = p->ctl;
                if (c != 0)
                    c->flag = flag;
            }
        }
    } else {
        Pawn* p = FUN_00024280(FUN_002672f0(name, 0, 0));
        if (p != 0) {
            Ctl* c = p->ctl;
            if (c != 0)
                c->flag = flag;
        }
    }
}
