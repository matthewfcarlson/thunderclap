// STATUS: equivalent (tools/equiv.py level 3: 111 inputs, branch coverage 18/22, incomplete)
// FUN_00333de0 @ 0x00333de0
#include "decls/data/platform/xbox/movie.h"

struct Data_333de0 { char pad[8]; int count; int index; };
struct Reader { virtual void f0(); virtual void f1(); virtual void f2(); virtual void FUN_slot3(); virtual unsigned int FUN_slot4(int* values); virtual void FUN_slot5(); };
struct Listener_333de0 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void FUN_slot3(void*); };
struct Obj_333de0 {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void FUN_slot7();
 int field4; int field8; int fieldc; Listener_333de0* listener; Reader* reader; int state; Data_333de0* data; int field20; unsigned char flag24; unsigned char busy;
 void FUN_00333de0();
};
extern int __stdcall FUN_00366940(Data_333de0*);
extern int __stdcall FUN_00367bc0(Data_333de0*);
extern int __stdcall FUN_00365f30(Data_333de0*,int,int,int,int,int,int,int,int,int,int);
extern void __stdcall FUN_003681d0(Data_333de0*);
void Obj_333de0::FUN_00333de0() {
 if (busy) return;
 busy=1;
 if (state==4) {
  DAT_00555ba0=field8;
  if (!FUN_00366940(data)) {
   bool failed=false;
   if (!flag24 && !FUN_00367bc0(data)) {
    reader->FUN_slot3();
    int values[8];
    while (reader->FUN_slot4(values)>0) {
     int start=values[0];
     int stride=values[1];
     if (stride<0) start+=(values[7]-1)*stride;
     int result=FUN_00365f30(data,start,stride,values[7],0,0,values[4],values[5],values[6],values[7],3);
     if (!result) failed=true;
     else failed=false;
     reader->FUN_slot5();
     if (result) break;
    }
   }
   if (data->index==data->count-1) { FUN_slot7(); busy=0; return; }
   FUN_003681d0(data);
   if (failed) { flag24=1; if (listener) listener->FUN_slot3(this); }
  }
 }
 busy=0;
}