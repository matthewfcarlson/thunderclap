int gValue_31ba60;
extern "C" int __cdecl Alloc(int);
extern "C" int __stdcall MakeArg(int);
struct Obj_31ba60 {
    int Init(int);
};
int Target(int a, int b, int* out) {
    if (a == 0x12 && b == 0xb) {
        int value = gValue_31ba60;
        if (!value) {
            Obj_31ba60* p = (Obj_31ba60*)Alloc(0x14);
            if (p)
                value = p->Init(MakeArg(0));
            else
                value = 0;
            gValue_31ba60 = value;
        }
        *out = value;
        return 1;
    }
    *out = 0;
    return 100;
}