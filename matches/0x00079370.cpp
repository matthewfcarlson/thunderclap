// cl-flags: /O2
int gValue;
void __stdcall Set(int v) {
    if (v <= 0x14)
        gValue = v;
}