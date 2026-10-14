// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 2/2)
// FUN_002172c0 @ 0x002172c0
struct Node;
struct Node2 { unsigned char pad4; unsigned char flags; };
struct State;
struct Object { char pad[16]; State *state; };

struct Marker { char pad[5]; unsigned char flags; };

struct State {
    char pad00[0x14];
    unsigned int mode;
    Node *head;
    int f1c;
    Node **tail;
    int f24;
    char pad28[0x5c - 0x28];
    Marker *marker;
};

// equiv-conv: FUN_00216e10 ebx stack stack
int __cdecl FUN_00216e10(Object *object, int flag, int amount);
Node **__cdecl FUN_002171c0(Object *object, Node **link, int mode, int *budget, int *count);
void __cdecl FUN_002164b0(State *state, Marker *marker);

void __cdecl FUN_002172c0(Object *object)
{
    State *s = object->state;
    int budget = 0x7fffffff;
    FUN_00216e10(object, 0, 0x7fffffff);
    FUN_002171c0(object, &s->head, 0, &budget, 0);
    Marker *marker = s->marker;
    if (marker->flags & 3)
        FUN_002164b0(s, marker);
    s->mode ^= 3;
    s->tail = &s->head;
    s->f24 = 0;
    FUN_00216e10(object, 0, 0x7fffffff);
    FUN_002171c0(object, &s->head, 0, &budget, 0);
}
