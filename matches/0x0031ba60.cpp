int gValue;
extern "C" int __cdecl Alloc(int);
extern "C" int __stdcall MakeArg(int);
struct Obj {
    int Init(int);
};
int Target(int a, int b, int* out) {
    if (a == 0x12 && b == 0xb) {
        int value = gValue;
        if (!value) {
            Obj* p = (Obj*)Alloc(0x14);
            if (p)
                value = p->Init(MakeArg(0));
            else
                value = 0;
            gValue = value;
        }
        *out = value;
        return 1;
    }
    *out = 0;
    return 100;
}