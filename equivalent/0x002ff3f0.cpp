// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 26/26)
// FUN_002ff3f0 @ 0x002ff3f0
#include "decls/data/engine/unknown.h"

struct Body_2ff3f0 {
    char pad0[0x7c];
    float limit;
};

struct Actor_2ff3f0 {
    char pad0[0x18];
    Body_2ff3f0 *body;
    char pad1c[0x4c];
    char hit68;
    char hit69;
};

struct Link_2ff3f0 {
    Actor_2ff3f0 *a;
    Actor_2ff3f0 *b;
    int f8;
    float maxLimit;
    char active;
    char pad11[3];
};


class ActorSet {
public:
    Actor_2ff3f0 **begin;
    Actor_2ff3f0 **end;
    char pad8[0x28];
    Link_2ff3f0 *linkBegin;
    Link_2ff3f0 *linkEnd;

    void FUN_002ff3f0(unsigned char flags);
};

void ActorSet::FUN_002ff3f0(unsigned char flags)
{
    unsigned i;
    unsigned j;

    if (flags & 4) {
        for (i = 0; i < (unsigned)(end - begin); i++) {
            begin[i]->hit69 = 0;
            begin[i]->hit68 = 0;
        }
        return;
    }
    if (DAT_00555480 == 0) {
        for (i = 0; i < (unsigned)(end - begin); i++) {
            begin[i]->hit69 = 0;
            begin[i]->hit68 = 0;
        }
        return;
    }
    for (i = 0; i < (unsigned)(end - begin); i++) {
        Actor_2ff3f0 *a = begin[i];
        a->hit69 = 0;
        a->hit68 = 0;
        a->body->limit = DAT_004d2f14;
    }
    for (j = 0; j < (unsigned)(linkEnd - linkBegin); j++) {
        Link_2ff3f0 *l = &linkBegin[j];
        if (l->active != 0) {
            Body_2ff3f0 *p = l->a->body;
            p->limit = (p->limit < l->maxLimit) ? p->limit : l->maxLimit;
            l = &linkBegin[j];
            p = l->b->body;
            p->limit = (p->limit < l->maxLimit) ? p->limit : l->maxLimit;
        }
    }
}
