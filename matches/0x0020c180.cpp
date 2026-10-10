// cl-flags: /O1
typedef unsigned int uint;
typedef unsigned long long U64;
typedef long long I64;

I64* __stdcall FUN_0020c180(I64* out, uint value) {
    I64* result;
    if (value == 0xffffffffu) {
        result = 0;
    } else {
        I64 n;
        n = (I64)((U64)value * 10000ULL);
        *(volatile I64*)out = n;
        *out = -n;
        result = out;
    }
    return result;
}
