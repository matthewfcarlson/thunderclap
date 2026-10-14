// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00026f30 @ 0x00026f30
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

struct Name {
    unsigned int lo, hi;
    Name *FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};

struct Link {
    char pad0[0x118];
    unsigned int nameLo;
    unsigned int nameHi;
};

struct Pawn {
    char pad0[0x1ca0];
    Link *link;
};

struct Group {
    Pawn *FUN_00024280(unsigned __int64 key);
    bool FUN_00026f30(const char *pawnName, const char *linkName);
};

// True when the pawn's link carries the given name.
bool Group::FUN_00026f30(const char *pawnName, const char *linkName)
{
    Pawn *pawn = FUN_00024280(FUN_002672f0(pawnName, 0, 0));
    if (!pawn)
        return false;
    Name key;
    key.FUN_0027b0e0(linkName);
    Link *link = pawn->link;
    if (link && key.lo == link->nameLo && key.hi == link->nameHi) {
        key.FUN_0027af50();
        return true;
    }
    key.FUN_0027af50();
    return false;
}
