typedef unsigned int u32_213b60;
struct Obj_213b60 {
    char pad[8];
    char* p;
};
extern int FUN_0021ad80(Obj_213b60*, u32_213b60, u32_213b60, u32_213b60, u32_213b60);
int FUN_00213b60(Obj_213b60* self, u32_213b60 a, u32_213b60 b) {
    char* base = self->p - 8;
    if (*(int*)base == 6) {
        char* item = *(char**)(base + 4);
        if (item[6] == 0)
            return FUN_0021ad80(self, *(u32_213b60*)(item + 12), a, b, 0);
    }
    return 0;
}
