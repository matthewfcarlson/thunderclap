// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_002e9ac0 @ 0x002e9ac0
struct Png_2e9ac0 { char pad[0x60]; unsigned flags; };
struct Info_2e9ac0 { char pad[8]; unsigned flags; };
struct Time { unsigned short year; unsigned char month, day, hour, minute, second; };
extern void __cdecl FUN_002e69a0(Png_2e9ac0*, const char*);
extern void __cdecl FUN_002e69d0(Png_2e9ac0*, const char*);
extern int __cdecl FUN_002e81e0(Png_2e9ac0*, unsigned);
extern void __cdecl FUN_002e7580(Png_2e9ac0*, unsigned char*, unsigned);
extern unsigned short __cdecl FUN_002e7560(const unsigned char*);
extern int __cdecl FUN_002eb6f0(Png_2e9ac0*, Info_2e9ac0*, Time*);
int __cdecl FUN_002e9ac0(Png_2e9ac0* png, Info_2e9ac0* info, unsigned length) {
 if (!(png->flags & 1)) FUN_002e69a0(png, "Out of place tIME chunk");
 else if (info && (info->flags & 0x200)) {
  FUN_002e69d0(png, "Duplicate tIME chunk");
  return FUN_002e81e0(png,length);
 }
 if (png->flags & 4) png->flags |= 8;
 if (length != 7) {
  FUN_002e69d0(png,"Incorrect tIME chunk length");
  return FUN_002e81e0(png,length);
 }
 unsigned char data[8];
 Time t;
 FUN_002e7580(png,data,7);
 int result=FUN_002e81e0(png,0);
 if (result) return result;
 t.hour=data[4]; t.minute=data[5]; t.second=data[6];
 t.day=data[3]; t.month=data[2];
 t.year=FUN_002e7560(data);
 return FUN_002eb6f0(png,info,&t);
}
