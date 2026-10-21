// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0025c490 @ 0x0025c490
struct Reader;
extern bool __cdecl FUN_0025aad0(Reader*, signed char*);
extern bool __cdecl FUN_0025abd0(Reader*, unsigned int*);
bool __cdecl FUN_0025c490(Reader* reader, unsigned int* result)
{
    signed char kind;
    unsigned int first = 0, second = 0, third = 0;
    if (!FUN_0025aad0(reader, &kind)) return false;
    int savedKind = kind;
    if (!FUN_0025abd0(reader, &first)) return false;
    if (!FUN_0025abd0(reader, &second)) return false;
    if (!FUN_0025abd0(reader, &third)) return false;
    unsigned int packed = ((third & 31u) << 17) | (second & 0x1ffffu);
    packed = (packed << 5) | (first & 31u);
    *result = (packed << 4) | (*result & 0x80000000u) | (savedKind & 7);
    return true;
}