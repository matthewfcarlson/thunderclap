// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 18/18)
// FUN_00338710 @ 0x00338710
// 0x00338710: true if str (of length len, or its strlen when len <= 0) ends with suffix
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcmp(const char*, const char*);

bool __stdcall FUN_00338710(const char* str, const char* suffix, int len)
{
    if (len <= 0)
        len = (int)strlen(str);
    int suffixLen = (int)strlen(suffix);
    if (suffixLen > len)
        return false;
    return strcmp(suffix, str + (len - suffixLen)) == 0;
}
