struct Obj_21b080 {
    char pad[0x1c];
    int* mValue;
    int mContext;
};
extern int __cdecl FUN_00219430(int, int, int);
extern int* __cdecl FUN_0021a500(int, int, int);
int __cdecl FUN_0021b080(Obj_21b080* self, int a, int b) {
    int context = self->mContext;
    int result = FUN_00219430(context, a, b);
    int* p = FUN_0021a500(context, self->mValue[1], result);
    if (*p == 0) {
        p[1] = 1;
        p[0] = 1;
    }
    return result;
}