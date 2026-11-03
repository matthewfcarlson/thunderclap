// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 31/38, incomplete)
// FUN_0027acf0 @ 0x0027acf0
#include "gen/owners.h"
int __cdecl FUN_00345804(const char* src, const char* fmt, ...);
bool owners::ConfigParser_27acf0::FUN_0027acf0(char** outKey, char** outValue) {
    if (!source)
        return false;
    while (buf[pos] <= ' ' && pos != end)
        pos++;
    int p = pos;
    if (p == end || buf[p] == '[')
        return false;
    while (buf[p] != '\r' && buf[p] != '\n' && p != end)
        p++;
    if (p != end)
        buf[p] = 0;
    value[0] = 0;
    FUN_00345804(buf + pos, " %s = %[^\r\n]", key, value);
    pos = p;
    int len = 0;
    while (value[len])
        len++;
    for (int i = len - 1; i > 0 && value[i] <= ' '; i--)
        value[i] = 0;
    *outKey = key;
    *outValue = value;
    return true;
}
