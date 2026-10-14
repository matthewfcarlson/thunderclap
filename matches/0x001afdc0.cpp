struct Candidate;
struct Owner;
struct Group {
    char pad[0x1b0];
    unsigned id;
};
struct Link {
    Candidate* FUN_001d72e0();
};
struct Entity {
    char p0[0x114];
    unsigned identity;
    char p118[4];
    Group* group;
    char p120[8];
    Link* link;
    unsigned relatedIdentity;
    char p130[0x18];
    Entity* parent;
    char p14c[0x1e8];
    Entity* related;
    void FUN_001d82d0();
};
struct Candidate {
    char p0[8];
    Entity* entity;
    unsigned type;
};
struct Owner {
    float FUN_00015a20();
    Entity* FUN_00015a30();
    void FUN_00015a40(Candidate*, unsigned, unsigned);
};
struct Context {
    char pad[8];
    Owner* owner;
};
int __stdcall FUN_001afdc0(Context* context, Candidate* candidate, unsigned a, unsigned b, float threshold) {
    if (candidate->type == 5) {
        Owner* owner = context->owner;
        if (!(owner->FUN_00015a20() < threshold)) {
            Entity* source = owner->FUN_00015a30();
            if (source->link && source->link->FUN_001d72e0() == candidate)
                return 1;
            Entity* target = candidate->entity;
            if (target->parent && source->group->id == target->parent->group->id)
                return 1;
            unsigned identity = target->identity;
            if (identity == source->relatedIdentity)
                return 1;
            Entity* related = source->related;
            if (related && identity == related->relatedIdentity)
                return 1;
            target->FUN_001d82d0();
            owner->FUN_00015a40(candidate, a, b);
        }
    }
    return 1;
}