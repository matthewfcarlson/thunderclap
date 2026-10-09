// Same code shape as 0x000485e0 (propagated; names are from that function)
class CButtonUpCondition { public: static bool __stdcall vfunc_10(int *p, int *out); };
bool __stdcall CButtonUpCondition::vfunc_10(int *p, int *out) {
    int n = *p;
    if (n != 0) {
        if (n != 3) return false;
        *out = 0;
    } else {
        *out = p[1];
    }
    return true;
}
