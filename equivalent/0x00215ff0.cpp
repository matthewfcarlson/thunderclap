// STATUS: equivalent (tools/equiv.py level 3: 192 inputs, branch coverage 8/8)
// FUN_00215ff0 @ 0x00215ff0
extern "C" int __cdecl _isspace(int);
double __cdecl FUN_003472cb(const char*, const char**);
int FUN_00215ff0(const char* str, float* out) {
    const char* end = str;
    float value = (float)FUN_003472cb(str, &end);
    if (end != str) {
        while (_isspace((unsigned char)*end))
            end++;
        if (*end == 0) {
            *out = value;
            return 1;
        }
    }
    return 0;
}
