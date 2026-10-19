// STATUS: equivalent (tools/equiv.py level 3: 15806 inputs, branch coverage 2/2)
// FUN_00251ad0 @ 0x00251ad0
// FUN_00251ad0 @ 0x00251ad0
struct Block { float values[16]; }; struct Object { char pad[0x3c]; Block *block; int FUN_00251ad0(); }; int FUN_002477f0(); Block * __cdecl FUN_00247530(int); int Object::FUN_00251ad0() { Block *p = FUN_00247530(FUN_002477f0()); if (p) { for (int i=0;i<16;++i) p->values[i]=1.0f; } block=p;     return (int)(block);
}
