// Forward declarations
void* __fastcall FUN_00212bb0(void* a, void* b);
void* __cdecl FUN_00219e90(void* src, void* dest);

void __cdecl FUN_00213600(void* p1, void* p2) {
    void* result = FUN_00212bb0(p2, p1);
    void* pair = FUN_00219e90(*(void**)((char*)result + 4), (void*)(*(int*)((char*)p1 + 8) - 8));
    int* dest = (int*)(*(int*)((char*)p1 + 8) - 8);
    int* pair_int = (int*)pair;
    dest[0] = pair_int[0];
    dest[1] = pair_int[1];
}