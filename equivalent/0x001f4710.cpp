// STATUS: equivalent (tools/equiv.py level 3: 2135 inputs, branch coverage 12/12)
// FUN_001f4710 @ 0x001f4710
struct Handle;
bool __cdecl FUN_00249b40(Handle* h);
struct Fade { int a; int b; };
void __cdecl FUN_00249a90(Handle* h, Fade* f);
void __cdecl FUN_0024a800(Handle* h, int n);
void __cdecl FUN_002497e0(void* p);

struct Item { int pad0; Handle* handle; char pad8[0x10]; void* extra; };

class Player {
public:
    char pad0[8];
    Item* items[32];
    int count;
    bool FUN_001f4710();
};

bool Player::FUN_001f4710()
{
    for (int i = 0; i < count; i++) {
        if (items[i]->handle != 0 && !FUN_00249b40(items[i]->handle)) {
            Item* it = items[i];
            if (it->handle != 0) {
                Fade f;
                f.a = 0;
                f.b = 0xfa;
                FUN_00249a90(it->handle, &f);
                FUN_0024a800(it->handle, 0x32);
                if (it->extra != 0) {
                    FUN_002497e0(it->extra);
                    it->extra = 0;
                }
            }
            return true;
        }
    }
    return false;
}
