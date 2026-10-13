struct Vec {
    float x, y, z;
};
struct State {
    char pad[0x14];
    int kind;
};
struct Flag {
    char pad[0x72];
    unsigned char enabled;
};
struct Result {
    char pad[0x74];
    Flag* flag;
};
struct Link {
    Result* FUN_001d72e0();
};
bool __cdecl FUN_002027c0(Vec*, Vec*, int, int, Vec*, Vec*, int, int);
struct Object {
    char pad[0x11c];
    State* state;
    char gap[8];
    Link* link;
    bool FUN_000352b0(Vec*);
    void FUN_00035fa0(int);
    bool target(int unused, Object* other);
};
bool Object::target(int unused, Object* other) {
    if (state && state->kind == 3)
        return true;
    if (other->state && other->state->kind == 5)
        return true;
    Vec a, b, c, d;
    if (!FUN_000352b0(&a))
        return false;
    if (!other->FUN_000352b0(&b))
        return false;
    other->FUN_00035fa0(0);
    Flag* flag = 0;
    if (other->link) {
        Result* result = other->link->FUN_001d72e0();
        if (result) {
            flag = result->flag;
            if (flag)
                flag->enabled = 0;
        }
    }
    FUN_00035fa0(0);
    bool hit = FUN_002027c0(&a, &b, 0, 0, &d, &c, 0, 0);
    FUN_00035fa0(1);
    bool answer = !hit;
    if (flag)
        flag->enabled = 1;
    other->FUN_00035fa0(1);
    return answer;
}