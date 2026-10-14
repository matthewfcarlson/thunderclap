// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 12/12)
// FUN_002e96a0 @ 0x002e96a0
struct Png_2e96a0 { char pad[0x60]; unsigned flags; };
struct Info_2e96a0 { char pad[8]; signed char flags; };
struct PhysData { unsigned char x[4]; unsigned char y[4]; unsigned char unit; };
extern "C" void __cdecl FUN_002e69a0(Png_2e96a0*, const char*);
extern "C" void __cdecl FUN_002e69d0(Png_2e96a0*, const char*);
extern "C" int __cdecl FUN_002e81e0(Png_2e96a0*, unsigned);
extern "C" void __cdecl FUN_002e7580(Png_2e96a0*, void*, unsigned);
extern "C" unsigned __cdecl FUN_002e7500(unsigned char*);
extern "C" int __cdecl FUN_002eb480(Png_2e96a0*, Info_2e96a0*, unsigned, unsigned, unsigned);
int __cdecl FUN_002e96a0(Png_2e96a0* png, Info_2e96a0* info, unsigned length) {
    unsigned flags = png->flags;
    if (!(flags & 1)) {
        FUN_002e69a0(png, "Missing IHDR before pHYS");
    } else if (flags & 4) {
        FUN_002e69d0(png, "Invalid pHYS after IDAT");
        return FUN_002e81e0(png, length);
    } else if (info && info->flags < 0) {
        FUN_002e69d0(png, "Duplicate pHYS chunk");
        return FUN_002e81e0(png, length);
    }
    if (length != 9) {
        FUN_002e69d0(png, "Incorrect pHYs chunk length");
        return FUN_002e81e0(png, length);
    }
    PhysData data;
    FUN_002e7580(png, &data, 9);
    int result = FUN_002e81e0(png, 0);
    if (result) return result;
    unsigned unit = data.unit;
    unsigned y = FUN_002e7500(data.y);
    unsigned x = FUN_002e7500(data.x);
    return FUN_002eb480(png, info, x, y, unit);
}