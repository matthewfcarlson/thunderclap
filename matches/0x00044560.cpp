struct Result {
    char pad[0x14];
    int value;
};
struct Inner {
    char pad[0x11c];
    Result* result;
};
struct CCharacter_44560 {
    char pad[0x148];
    Inner* inner;
};
struct Param {
    char pad[8];
    CCharacter_44560* node;
    int type;
};
int FUN_00044560(Param* p) {
    if (!p)
        return 6;
    Inner* i;
    switch (p->type) {
    case 1:
        i = (Inner*)p->node;
        break;
    case 5:
        if (!p->node)
            return 6;
        i = p->node->inner;
        break;
    default:
        return 6;
    }
    if (!i)
        return 6;
    Result* r = i->result;
    if (!r)
        return 6;
    return r->value;
}