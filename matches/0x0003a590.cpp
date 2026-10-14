struct Vec_3a590 {
    float x, y, z;
};
struct State_3a590 {
    char pad[0x14];
    int kind;
};
struct Flag_3a590 {
    char pad[0x72];
    unsigned char enabled;
};
struct Result_3a590 {
    char pad[0x74];
    Flag_3a590* flag;
};
struct Link_3a590 {
    Result_3a590* FUN_001d72e0();
};
bool __cdecl FUN_002027c0(Vec_3a590*, Vec_3a590*, int, int, Vec_3a590*, Vec_3a590*, int, int);
struct Object {
    char pad[0x11c];
    State_3a590* state;
    char gap[8];
    Link_3a590* link;
    bool FUN_000352b0(Vec_3a590*);
    void FUN_00035fa0(int);
    bool target(int unused, Object* other);
};
bool Object::target(int unused, Object* other) {
    if (state && state->kind == 3)
        return true;
    if (other->state && other->state->kind == 5)
        return true;
    Vec_3a590 a, b, c, d;
    if (!FUN_000352b0(&a))
        return false;
    if (!other->FUN_000352b0(&b))
        return false;
    other->FUN_00035fa0(0);
    Flag_3a590* flag = 0;
    if (other->link) {
        Result_3a590* result = other->link->FUN_001d72e0();
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