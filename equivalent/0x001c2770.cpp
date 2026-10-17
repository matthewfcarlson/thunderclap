// STATUS: equivalent (tools/equiv.py level 3: 144 inputs, branch coverage 6/6)
// FUN_001c2770 @ 0x001c2770
typedef unsigned int uint;
struct Entry { uint a,b,c,d; };
struct Target { uint count; Entry entries[1]; void FUN_001c2770(uint n, const Entry *source); };
void Target::FUN_001c2770(uint n, const Entry *source)
{
    count = n;
    if (source) {
        for (uint i = 0; i < count; ++i) {
            entries[i].a = source[i].a;
            entries[i].b = source[i].b;
            entries[i].c = source[i].c;
            entries[i].d = source[i].d;
            entries[i].d = source[i].d;
        }
    }
}