// cl-flags: /O1
typedef unsigned int uint_20c180;
typedef unsigned long long U64_20c180;
typedef long long I64_20c180;

I64_20c180* __stdcall FUN_0020c180(I64_20c180* out, uint_20c180 value) {
    I64_20c180* result;
    if (value == 0xffffffffu) {
        result = 0;
    } else {
        I64_20c180 n;
        n = (I64_20c180)((U64_20c180)value * 10000ULL);
        *(volatile I64_20c180*)out = n;
        *out = -n;
        result = out;
    }
    return result;
}
