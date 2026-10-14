// STATUS: equivalent (tools/equiv.py level 3: 741 inputs, branch coverage 32/32)
// FUN_000c7f50 @ 0x000c7f50
struct Item_c7f50 { int FUN_00204200(int, int, int); };
struct Manager_c7f50 { Item_c7f50* __cdecl FUN_000862a0(int, int, int); };
struct Global_c7f50 { char pad[0x54]; Manager_c7f50* manager; };
extern Global_c7f50* DAT_004dd700;
struct Entry_c7f50 { int active; int x; int y; int z; char pad[0x24]; int value; char tail[8]; };
struct Object { char pad[0x258]; Entry_c7f50 entries[128]; int target(unsigned char flag, int value); };
int Object::target(unsigned char flag, int value) {
 int result;
 for(int i=0;i<128;++i) {
  Entry_c7f50& e=entries[i];
  result=e.active;
  if(result>0) {
   int x=e.x,y=e.y,z=e.z;
   Item_c7f50* item=DAT_004dd700->manager->FUN_000862a0(x,y,z);
   result=item->FUN_00204200(x,y,z);
   unsigned char selected=0;
   switch(result) {
    case 0x1e2: case 0x1ff: case 0x200: case 0x201: case 0x21d: case 0x21e: case 0x21f: case 0x220: case 0x23b: case 0x23c: case 0x23d: case 0x23e: case 0x25b: selected=1;
   }
   if(flag!=selected) { result=value; e.value=value; }
   else e.value=0;
  }
 }
 return result;
}