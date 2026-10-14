// STATUS: equivalent (tools/equiv.py level 3: 741 inputs, branch coverage 32/32)
// FUN_000c7f50 @ 0x000c7f50
struct Item { int FUN_00204200(int, int, int); };
struct Manager { Item* __cdecl FUN_000862a0(int, int, int); };
struct Global { char pad[0x54]; Manager* manager; };
extern Global* DAT_004dd700;
struct Entry { int active; int x; int y; int z; char pad[0x24]; int value; char tail[8]; };
struct Object { char pad[0x258]; Entry entries[128]; int target(unsigned char flag, int value); };
int Object::target(unsigned char flag, int value) {
 int result;
 for(int i=0;i<128;++i) {
  Entry& e=entries[i];
  result=e.active;
  if(result>0) {
   int x=e.x,y=e.y,z=e.z;
   Item* item=DAT_004dd700->manager->FUN_000862a0(x,y,z);
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