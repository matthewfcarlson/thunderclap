// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000c5e60 @ 0x000c5e60
struct Entry { int key; int b, c; };
struct Registry {
    void FUN_000af0f0(Entry* out);
};
struct Owner { Registry* FUN_000af3a0(int id); };
bool __cdecl HasEntry(Owner* owner, int id, int key, int i0, int i1, int i2, int i3) {
    struct Frame { int idx[4]; int buf[41]; } f;
    f.idx[0] = i0; f.idx[1] = i1; f.idx[2] = i2; f.idx[3] = i3;
    owner->FUN_000af3a0(id)->FUN_000af0f0((Entry*)f.buf);
    for (int i = 0; i < 4; i++) {
        int k = f.idx[i];
        if (k != -1 && f.buf[k * 3] == key) return true;
    }
    return false;
}
