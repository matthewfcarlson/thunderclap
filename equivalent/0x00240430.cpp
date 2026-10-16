// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 7/8, incomplete)
// FUN_00240430 @ 0x00240430
#include "decls/data/engine/audio.h"

extern "C" int __cdecl sprintf(char *, const char *, ...);
struct Text_240430 { char *data; unsigned int flags; unsigned short length; unsigned short spare; };
extern "C" void __cdecl FUN_0023fa40(char **, const char *, int, int);
extern "C" void __cdecl FUN_00247570(void *);
struct Object { Object *format(float); void FUN_0023ff50(Text_240430 *); };
Object *Object::format(float value) {
 char buffer[64];
 int count=sprintf(buffer,"%f",value);
 Text_240430 text;
 text.flags=(text.flags & 0xffff0002U)|2;
 text.length=(unsigned short)count;
 char *data;
 FUN_0023fa40(&data,buffer,count,count);
 text.data=data;
 FUN_0023ff50(&text);
 if ((unsigned short)text.flags==2) {
  unsigned short *refs=(unsigned short *)(data-4);
  if (*refs==1) {
   if(data!=(*(char**)&DAT_004cc02c)) FUN_00247570(data-8);
  } else --*refs;
 }
 return this;
}