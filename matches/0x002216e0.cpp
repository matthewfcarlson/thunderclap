extern "C" int __cdecl FUN_00221200(int, int);

struct Output_2216e0 {
    int pad[2];
    int value;
};

void __cdecl target(int a, Output_2216e0* out, int c) {
    out->value = FUN_00221200(a, c);
    *(int*)out = 8;
}