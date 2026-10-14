// cl-flags: /O1
typedef unsigned short ushort_20d30e;
ushort_20d30e* __stdcall FUN_0020d30e(ushort_20d30e* p) {
    return (((unsigned char*)p)[5] & 8) ? (p - 12) : (p + (unsigned int)*p * 8 - 8);
}
