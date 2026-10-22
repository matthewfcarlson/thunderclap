extern "C" char DAT_00444152[];
struct Owner_2d2bd0 {
    int pad;
    int Find(int, int);
};
extern int vtab;
struct GeneratorBlendState_2d2bd0 {
    int* vptr;
    int a, b, c;
    GeneratorBlendState_2d2bd0(Owner_2d2bd0*);
};
GeneratorBlendState_2d2bd0::GeneratorBlendState_2d2bd0(Owner_2d2bd0* arg) {
    a = 0;
    vptr = &vtab;
    b = 0;
    c = 0;
    if (arg) {
        b = arg->Find(((int)0x444152), 0x31544c46);
        c = arg->Find(0x41564452, 0x31544c46);
    }
}