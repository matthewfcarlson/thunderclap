// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 26/26)
// FUN_002ff3f0 @ 0x002ff3f0
struct Body {
    char pad0[0x7c];
    float limit;
};

struct Actor {
    char pad0[0x18];
    Body *body;
    char pad1c[0x4c];
    char hit68;
    char hit69;
};

struct Link {
    Actor *a;
    Actor *b;
    int f8;
    float maxLimit;
    char active;
    char pad11[3];
};

extern char DAT_00555480;
extern float DAT_004d2f14;

class ActorSet {
public:
    Actor **begin;
    Actor **end;
    char pad8[0x28];
    Link *linkBegin;
    Link *linkEnd;

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
        Actor *a = begin[i];
        a->hit69 = 0;
        a->hit68 = 0;
        a->body->limit = DAT_004d2f14;
    }
    for (j = 0; j < (unsigned)(linkEnd - linkBegin); j++) {
        Link *l = &linkBegin[j];
        if (l->active != 0) {
            Body *p = l->a->body;
            p->limit = (p->limit < l->maxLimit) ? p->limit : l->maxLimit;
            l = &linkBegin[j];
            p = l->b->body;
            p->limit = (p->limit < l->maxLimit) ? p->limit : l->maxLimit;
        }
    }
}
