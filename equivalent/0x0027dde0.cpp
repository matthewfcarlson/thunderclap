// STATUS: equivalent (tools/equiv.py level 3: 376 inputs, branch coverage 6/6)
// FUN_0027dde0 @ 0x0027dde0
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct Target_27dde0 {
    void FUN_002f39e0(void* matrix);
};
struct Elem_27dde0 {
    char pad[0x10];
    Target_27dde0* target;
};
struct Group_27dde0 {
    char pad[0x1c];
    int begin;
    int end;
};
class Obj_27dde0 {
  public:
    char pad00[0x48];
    char matrix[0x40];
    char pad88[0x98 - 0x88];
    Group_27dde0* group;
    char pad9c[0xac - 0x9c];
    Elem_27dde0** elems;
    int* FUN_0027dde0(const void* src);
};
int* Obj_27dde0::FUN_0027dde0(const void* src) {
    int* range = &group->begin;
    memcpy(matrix, src, 0x40);
    int i = 0;
    if (0 < (int)((range[1] - range[0]) & 0xfffffffc)) {
        do {
            if (elems[i] != 0)
                elems[i]->target->FUN_002f39e0(matrix);
            range = &group->begin;
            i++;
        } while (i < (range[1] - range[0]) >> 2);
    }
    return range;
}
