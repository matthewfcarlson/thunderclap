// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00245c50 @ 0x00245c50
extern "C" unsigned int __cdecl strlen(const char*);
class TextBuffer {
public:
    char pad0[0x94];
    unsigned int start;
    unsigned int end;
    char FUN_00245b70(unsigned int index);
};
bool __cdecl FUN_00245c50(TextBuffer* buf, const char* text) {
    unsigned int cur = buf->start;
    unsigned int i = cur;
    unsigned int len = strlen(text);
    while (i - cur < len) {
        if (cur >= buf->end)
            return false;
        if (buf->FUN_00245b70(i) != *text)
            return false;
        cur = buf->start;
        i++;
        text++;
    }
    return true;
}
