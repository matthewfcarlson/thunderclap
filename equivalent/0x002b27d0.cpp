// STATUS: equivalent (tools/equiv.py level 3: 153 inputs, branch coverage 12/12)
// FUN_002b27d0 @ 0x002b27d0
#include "compat/ptr.h"
void* __cdecl FUN_0008d6d0(hulk_uintptr);
struct Item_2b27d0 {
 virtual void retain();
 virtual void release();
 virtual void slot2();
 virtual void slot3();
 virtual Item_2b27d0* clone();
};
namespace pure3d {
struct MultiController;
}
struct FUN_00284a90 {
 virtual void slot0();
 char baseData[20];
 FUN_00284a90(const pure3d::MultiController&);
};
namespace pure3d {
struct MultiController : FUN_00284a90 {
 unsigned int fields[10];
 unsigned char flag;
 char padding[3];
 unsigned int count;
 Item_2b27d0** begin;
 Item_2b27d0** end;
 virtual void slot0();
 MultiController(const MultiController& source);
};
MultiController::MultiController(const MultiController& source) : FUN_00284a90(source) {
 for(unsigned int j=0;j<10;++j) fields[j]=source.fields[j];
 flag=source.flag;
 count=source.count;
 unsigned int n=(unsigned int)((int)((hulk_uintptr)source.end-(hulk_uintptr)source.begin)>>2);
 if(n>0) {
 begin=(Item_2b27d0**)FUN_0008d6d0(n*4);
 if(begin) end=begin+n;
 else {begin=0;end=0;}
 } else {begin=0;end=0;}
 for(unsigned int i=0;i<count;++i) {
 begin[i]=0;
 Item_2b27d0* value=source.begin[i]->clone();
 Item_2b27d0** slot=begin+i;
 if(value) value->retain();
 if(*slot) (*slot)->release();
 *slot=value;
 }
}
}
