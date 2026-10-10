// STATUS: equivalent (tools/equiv.py level 3: 112 inputs, branch coverage 42/42)
// FUN_00271a30 @ 0x00271a30
extern const unsigned char DAT_004bdce7[];
extern const unsigned short DAT_004adcc8[];
extern const unsigned short DAT_004adcd8[];
bool FUN_00271a30(unsigned int ch, unsigned int* out) {
    if (ch >= 0xff01 && ch <= 0xff5e) {
        *out = ch - 0xfee0;
        return true;
    }
    if (ch >= 0xff5f && ch <= 0xff60) {
        *out = ch - 0xd5da;
        return true;
    }
    if (ch >= 0xff61 && ch <= 0xff9f) {
        *out = DAT_004bdce7[ch] + 0x3000;
        return true;
    }
    if (ch == 0xffa0) {
        *out = 0x3164;
        return true;
    }
    if (ch >= 0xffa1 && ch <= 0xffbe) {
        *out = ch - 0xce70;
        return true;
    }
    if (ch >= 0xffc2 && ch <= 0xffc7) {
        *out = ch - 0xce73;
        return true;
    }
    if (ch >= 0xffca && ch <= 0xffcf) {
        *out = ch - 0xce75;
        return true;
    }
    if (ch >= 0xffd2 && ch <= 0xffd7) {
        *out = ch - 0xce77;
        return true;
    }
    if (ch >= 0xffda && ch <= 0xffdc) {
        *out = ch - 0xce79;
        return true;
    }
    if (ch >= 0xffe0 && ch <= 0xffe6) {
        *out = DAT_004adcc8[ch];
        return true;
    }
    if (ch >= 0xffe8 && ch <= 0xffee) {
        *out = DAT_004adcd8[ch];
        return true;
    }
    return false;
}
