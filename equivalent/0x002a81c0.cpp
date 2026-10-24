// STATUS: equivalent (tools/equiv.py level 3: 11844 inputs, branch coverage 16/16)
// FUN_002a81c0 @ 0x002a81c0
#include "gen/pure3d.h"

struct Key_2a81c0 { unsigned a,b; };
struct Item_2a81c0 { char pad[8]; Key_2a81c0 key; unsigned FUN_00288960(unsigned, unsigned); };
struct Source_2a81c0 { char pad[0x28]; int count; Item_2a81c0* FUN_00288a10(int); };
struct Lookup_2a81c0 { unsigned char FUN_00298960(Key_2a81c0*); };
struct Context_2a81c0 { char pad[0x44]; Lookup_2a81c0* lookup; };
void __cdecl FUN_0008d340(void*);
struct ByteArray { unsigned char* data; unsigned size; void FUN_002a8060(int, unsigned char*); };
struct WordArray { unsigned* data; unsigned size; void FUN_002a8000(int, unsigned*); };

void pure3d::CompDrawVisibilityAnimationController::FUN_002a81c0() {
 if ((*(Source_2a81c0 * *)&this->f_3c) && (*(Context_2a81c0 * *)&this->f_40)) {
  struct Frame {          // (the original's slot order)
   char pad[3];
   unsigned char zeroByte;
   union { unsigned zeroWord; Key_2a81c0 key; } u;
   int count;
  } f;
  f.count=(*(Source_2a81c0 * *)&this->f_3c)->count;
  if((*(ByteArray *)&this->f_50).data) FUN_0008d340((*(ByteArray *)&this->f_50).data);
  (*(ByteArray *)&this->f_50).data=0; (*(ByteArray *)&this->f_50).size=0;
  f.zeroByte=0;
  (*(ByteArray *)&this->f_50).FUN_002a8060(f.count,&f.zeroByte);
  if((*(WordArray *)&this->f_44).data) FUN_0008d340((*(WordArray *)&this->f_44).data);
  (*(WordArray *)&this->f_44).data=0; (*(WordArray *)&this->f_44).size=0;
  f.u.zeroWord=0;
  (*(WordArray *)&this->f_44).FUN_002a8000(f.count,&f.u.zeroWord);
  for(int i=0;i<f.count;++i) {
   Item_2a81c0* item=(*(Source_2a81c0 * *)&this->f_3c)->FUN_00288a10(i);
   f.u.key=item->key;
   unsigned char* dest=(*(ByteArray *)&this->f_50).data+i;
   unsigned char result=(*(Context_2a81c0 * *)&this->f_40)->lookup->FUN_00298960(&f.u.key);
   *dest=result;
   unsigned* out=(*(WordArray *)&this->f_44).data+i;
   item=(*(Source_2a81c0 * *)&this->f_3c)->FUN_00288a10(i);
   *out=item->FUN_00288960(0x534956,0x4c4f4f42);
  }
 } else {
  if((*(ByteArray *)&this->f_50).data) FUN_0008d340((*(ByteArray *)&this->f_50).data);
  (*(ByteArray *)&this->f_50).data=0; (*(ByteArray *)&this->f_50).size=0;
  if((*(WordArray *)&this->f_44).data) FUN_0008d340((*(WordArray *)&this->f_44).data);
  (*(WordArray *)&this->f_44).data=0; (*(WordArray *)&this->f_44).size=0;
 }
}
