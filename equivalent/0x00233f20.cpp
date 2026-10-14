// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 12/12)
// FUN_00233f20 @ 0x00233f20
class Owned {
public:
    virtual void v0();
    virtual void Release();
};

void FUN_00267090(char *p);
void *FUN_00238190(int kind);
char *FUN_00266e00(void *pool, int size);

class NameHolder {
public:
    bool FUN_00233f20(const char *name);

    Owned *owner;
    char *text;
};

bool NameHolder::FUN_00233f20(const char *name) {
    if (text != name) {
        FUN_00267090(text);
        int len = 0;
        if (name != 0) {
            const char *p = name;
            while (*p++) {
            }
            len = (int)(p - name) - 1;
        }
        if (len > 0) {
            text = FUN_00266e00(FUN_00238190(2), len + 1);
            const char *src = name;
            char *dst = text;
            char c;
            do {
                c = *src++;
                *dst++ = c;
            } while (c);
        } else {
            text = 0;
        }
        if (owner != 0) {
            owner->Release();
        }
        owner = 0;
    }
    return true;
}
