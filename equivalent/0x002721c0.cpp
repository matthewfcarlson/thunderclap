// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 28/28)
// FUN_002721c0 @ 0x002721c0
#include "decls/data/engine/core.h"

extern short DAT_004cdbf4[];

// equiv-conv: FUN_002721c0 eax
short FUN_002721c0(char ch)
{
    if (ch >= ' ' && ch <= '/')
        return DAT_004cdc70[ch];
    if (ch >= '0' && ch <= '9')
        return (short)(ch + 0x821f);
    if (ch >= ':' && ch <= '@')
        return DAT_004cdc5c[ch];
    if (ch >= 'A' && ch <= 'Z')
        return (short)(ch + 0x821f);
    if (ch >= '[' && ch <= '`')
        return DAT_004cdc28[ch];
    if (ch >= 'a' && ch <= 'z')
        return (short)(ch + 0x8220);
    if (ch >= '{' && ch <= '~')
        return DAT_004cdbf4[ch];
    return 0;
}