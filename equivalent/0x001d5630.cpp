// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 6/6)
// FUN_001d5630 @ 0x001d5630
#include "compat/ptr.h"
#include "gen/global.h"
struct Query_1d5630 { void FUN_0008ced0(int,int,unsigned*,int,int,int); };
extern "C" Query_1d5630* __cdecl FUN_0008ceb0();
extern "C" unsigned __cdecl FUN_00266da0(hulk_uintptr);
struct Owner_1d5630;
struct Entry_1d5630;
struct CSPHulkPropInstance_nv_1d5630 {
    CSPHulkPropInstance* FUN_001d7890(Owner_1d5630*,int);
    void FUN_001d7490(Entry_1d5630*);
};
extern "C" CSPHulkPropInstance* __cdecl FUN_00263ea0(unsigned);
struct Entry_1d5630 { char pad[0x1c]; CSPHulkPropInstance* object; char pad20[2]; unsigned char enabled; char pad23[0xa9-0x23]; unsigned char flag; };
struct Table_1d5630 { Entry_1d5630* FUN_001c59d0(unsigned); };
struct Manager_1d5630 { char pad[12]; Table_1d5630* table; void FUN_001c3a40(unsigned,unsigned); };
extern "C" Manager_1d5630* __cdecl FUN_001c3d90();
struct Owner_1d5630 { char pad[0xb0]; unsigned char flag; CSPHulkPropInstance* target(unsigned,unsigned); };
CSPHulkPropInstance* Owner_1d5630::target(unsigned a,unsigned b) {
 unsigned size;
 FUN_0008ceb0()->FUN_0008ced0(10,0,&size,0,0,0);
 if(size<0xc800) return 0;
 unsigned old=FUN_00266da0(10);
 CSPHulkPropInstance* obj=FUN_00263ea0(0x278);
 if(obj) obj=((CSPHulkPropInstance_nv_1d5630*)(((CSPHulkPropInstance*)(obj))))->FUN_001d7890(this,0);
 FUN_00266da0(old);
 unsigned v=(*(unsigned int *)&obj->f_9c);
 FUN_001c3d90()->FUN_001c3a40(a,v);
 Entry_1d5630* entry=FUN_001c3d90()->table->FUN_001c59d0(a);
 if(entry) { entry->enabled=1; entry->object=obj; entry->flag=flag; ((CSPHulkPropInstance_nv_1d5630*)(((CSPHulkPropInstance*)(obj))))->FUN_001d7490(entry); }
 return obj;
}