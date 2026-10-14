typedef unsigned char BYTE;
struct Obj_25aa80 {
    bool Query(BYTE*, int, int, int);
};
bool __cdecl Target(unsigned int a, bool* out) {
    Obj_25aa80* o = *(Obj_25aa80**)a;
    BYTE* b = (BYTE*)&a;
    if (o->Query(b, 1, 1, 1)) {
        *out = *b != 0;
        return true;
    }
    return false;
}
