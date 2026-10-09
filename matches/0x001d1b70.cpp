typedef unsigned int U32;
extern int __cdecl Check(U32, int);
extern void __cdecl Fail(U32, int);
extern U32 __cdecl Make(U32, int);
class Obj { public: char pad[8]; U32 value; bool Target(U32* out); };
bool Obj::Target(U32* out) {
    bool r = true;
    if (Check(value, -1) != 6) {
        r = false;
        Fail(value, -2);
    } else {
        *out = Make(value, -10000);
    }
    return r;
}