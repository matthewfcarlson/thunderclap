// STATUS: equivalent (tools/equiv.py level 3: 62 inputs, branch coverage 60/62, incomplete)
// FUN_001e4490 @ 0x001e4490
struct Elem {
    char pad0[0xc];
    float key;
    char pad1[4];
};

struct ElemPair {
    Elem* first;
    Elem* second;
};

void FUN_001e4210(Elem* a, Elem* b, Elem* c);
void FUN_001e0fc0(Elem* a, Elem* b);

ElemPair* FUN_001e4490(ElemPair* out, Elem* first, Elem* last)
{
    Elem* mid = first + (last - first) / 2;
    FUN_001e4210(first, mid, last - 1);

    Elem* pfirst = mid;
    Elem* plast = mid + 1;
    while (first < pfirst && !(pfirst[-1].key < pfirst->key) && !(pfirst->key < pfirst[-1].key))
        --pfirst;
    while (plast < last && !(plast->key < pfirst->key) && !(pfirst->key < plast->key))
        ++plast;

    Elem* gfirst = plast;
    Elem* glast = pfirst;
    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (pfirst->key < gfirst->key) {
            } else if (gfirst->key < pfirst->key) {
                break;
            } else {
                FUN_001e0fc0(plast++, gfirst);
            }
        }
        for (; first < glast; --glast) {
            if (glast[-1].key < pfirst->key) {
            } else if (pfirst->key < glast[-1].key) {
                break;
            } else {
                FUN_001e0fc0(--pfirst, glast - 1);
            }
        }
        if (glast == first) {
            if (gfirst == last) {
                out->second = plast;
                out->first = pfirst;
                return out;
            }
            if (plast != gfirst)
                FUN_001e0fc0(pfirst, plast);
            ++plast;
            FUN_001e0fc0(pfirst, gfirst);
            ++pfirst;
            ++gfirst;
        } else {
            --glast;
            if (gfirst == last) {
                --pfirst;
                if (glast != pfirst)
                    FUN_001e0fc0(glast, pfirst);
                --plast;
                FUN_001e0fc0(pfirst, plast);
            } else {
                FUN_001e0fc0(gfirst, glast);
                ++gfirst;
            }
        }
    }
}
