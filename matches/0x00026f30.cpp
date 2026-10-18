// FUN_00026f30 @ 0x00026f30
#include "decls/address.h"

struct Name_26f30 {
    unsigned int lo, hi;
    Name_26f30 *FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};

struct Link_26f30 {
    char pad0[0x118];
    unsigned int nameLo;
    unsigned int nameHi;
};

struct Pawn_26f30 {
    char pad0[0x1ca0];
    Link_26f30 *link;
};

struct Group_26f30 {
    Pawn_26f30 *FUN_00024280(unsigned __int64 key);
    bool FUN_00026f30(const char *pawnName, const char *linkName);
};

// True when the pawn's link carries the given name.
bool Group_26f30::FUN_00026f30(const char *pawnName, const char *linkName)
{
    Pawn_26f30 *pawn = FUN_00024280(FUN_002672f0(pawnName, 0, 0));
    if (!pawn)
        return false;
    Name_26f30 key;
    key.FUN_0027b0e0(linkName);
    Link_26f30 *link = pawn->link;
    if (link && key.lo == link->nameLo && key.hi == link->nameHi) {
        key.FUN_0027af50();
        return true;
    }
    key.FUN_0027af50();
    return false;
}
