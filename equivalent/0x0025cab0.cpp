// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0025cab0 @ 0x0025cab0
struct Key { int w0, w1; char flags; char pad[7]; char data[1]; };
struct Tmp {
    int w[3];
    void* FUN_0023fb00();
    void FUN_00240060();
};
struct Holder { void* FUN_0023fb00(); };
void* __cdecl FUN_00240780();
void __cdecl FUN_0025c920(Tmp* out, int a1, Key* id, void* x);
Holder* __cdecl FUN_0024c710();
void* __cdecl FUN_002631f0(void* a, void* b, int c, int d, int e, void* f, int g);
void* LookupKey(int a1, Key* key, int a3, int a4) {
    struct Frame { int id[2]; Tmp t; } f;
    f.id[0] = key->w0;
    f.id[1] = key->w1;
    FUN_0025c920(&f.t, a1, (Key*)f.id, (key->flags & 1) ? FUN_00240780() : 0);
    void* r = FUN_002631f0(f.t.FUN_0023fb00(),
        FUN_0024c710()->FUN_0023fb00(), 0, 0, a3, (key->flags & 1) ? 0 : (void*)key->data, a4);
    f.t.FUN_00240060();
    return r;
}
