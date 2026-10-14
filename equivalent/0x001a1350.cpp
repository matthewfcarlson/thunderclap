// STATUS: equivalent (tools/equiv.py level 3: 186 inputs, branch coverage 4/4)
// FUN_001a1350 @ 0x001a1350
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void thunk_FUN_00267090(void*);
extern "C" char* __cdecl FUN_0008d6d0(unsigned int);
class StrHolder {
public:
    char pad[12];
    char* text;
    int length;
    bool FUN_001a1350(const char* src, int len);
};
bool StrHolder::FUN_001a1350(const char* src, int len) {
    thunk_FUN_00267090(text);
    if (src != 0 && len > 0) {
        text = FUN_0008d6d0(len + 1);
        memcpy(text, src, len);
        text[len] = 0;
        length = len;
        return true;
    }
    text = 0;
    length = 0;
    return true;
}
