// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 6/6)
// FUN_00096e50 @ 0x00096e50
struct Id64 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    Id64* FUN_0027af10(unsigned int lo, unsigned int hi);
    void FUN_0027af30(Id64* src);
    void FUN_0027af50();
    void FUN_0027af70(Id64* src);
    Id64* FUN_0027b0e0(const char* name);
};

unsigned __int64 __cdecl FUN_00096d80(const char* hex);

// Builds an Id64 from a name, or from a "0x..." literal.
Id64* FUN_00096e50(Id64* result, const char* text)
{
    Id64 id;
    Id64 tmp;
    id.FUN_0027af00();
    if (text != 0) {
        Id64* parsed;
        if (text[0] == '0' && text[1] == 'x') {
            unsigned __int64 v = FUN_00096d80(text);
            parsed = tmp.FUN_0027af10((unsigned int)v, (unsigned int)(v >> 32));
        } else {
            parsed = tmp.FUN_0027b0e0(text);
        }
        id.FUN_0027af70(parsed);
        tmp.FUN_0027af50();
    }
    result->FUN_0027af30(&id);
    id.FUN_0027af50();
    return result;
}
