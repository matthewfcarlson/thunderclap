// STATUS: equivalent (tools/equiv.py level 3: 19788 inputs, branch coverage 14/14)
// core::FileOpenRequest::vfunc_1 @ 0x00273920
#include "gen/core.h"

struct FileData;
struct Match { FileData* FUN_00277cb0(); int FUN_00277cd0(); char bytes[0x30]; };
struct Candidate_273920 { bool FUN_00277b40(char*, Match*); };
struct Iterator_273920 { void FUN_002775f0(int); Candidate_273920* FUN_00277600(); };
struct Info_273920 { char pad[12]; int value; };
struct Backend_273920 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual int open(char*,int,unsigned int,int*,int*); Iterator_273920* FUN_00272bc0(); Info_273920* FUN_002728d0(); int FUN_00272880(); };
struct Lock_273920 { virtual void acquire(); virtual void release(); };
struct FileData { int unknown; Lock_273920 lock; int field8; Backend_273920* backend; int field10; int result; char pad18[4]; unsigned char opened; char pad1d; char name[0x10a]; int size; Match match; int handle; int field160; int metadata; };
namespace core {  }
int core::FileOpenRequest::vfunc_1() {
 Backend_273920* backend=(*(FileData * *)&this->f_08)->backend;
 Iterator_273920* it=backend->FUN_00272bc0();
 it->FUN_002775f0(0);
 Candidate_273920* candidate=it->FUN_00277600();
 bool found=false;
 while(candidate) { if(candidate->FUN_00277b40((*(FileData * *)&this->f_08)->name,&(*(FileData * *)&this->f_08)->match)) { found=true; break; } candidate=it->FUN_00277600(); }
 int status=1;
 if(!found) {
 status=backend->open((*(FileData * *)&this->f_08)->name,this->f_0c,(*(unsigned char *)&this->f_10),&(*(FileData * *)&this->f_08)->handle,&(*(FileData * *)&this->f_08)->size);
 if(status==1) { (*(FileData * *)&this->f_08)->opened=1; Info_273920* info=backend->FUN_002728d0(); (*(FileData * *)&this->f_08)->metadata=info->value; int result=backend->FUN_00272880(); (&(*(FileData * *)&this->f_08)->lock)->acquire(); (*(FileData * *)&this->f_08)->result=result; (&(*(FileData * *)&this->f_08)->lock)->release(); return 1; }
 it->FUN_002775f0(1);
 candidate=it->FUN_00277600();
 while(candidate) { if(candidate->FUN_00277b40((*(FileData * *)&this->f_08)->name,&(*(FileData * *)&this->f_08)->match)) { found=true; break; } candidate=it->FUN_00277600(); }
 if(!found) { int result=backend->FUN_00272880(); (&(*(FileData * *)&this->f_08)->lock)->acquire(); (*(FileData * *)&this->f_08)->result=result; (&(*(FileData * *)&this->f_08)->lock)->release(); return status; }
 }
 FileData* source=(*(FileData * *)&this->f_08)->match.FUN_00277cb0();
 (*(FileData * *)&this->f_08)->handle=source->handle;
 int size=(*(FileData * *)&this->f_08)->match.FUN_00277cd0(); (*(FileData * *)&this->f_08)->size=size;
 (*(FileData * *)&this->f_08)->opened=1;
 (*(FileData * *)&this->f_08)->metadata=source->metadata;
 (&(*(FileData * *)&this->f_08)->lock)->acquire(); (*(FileData * *)&this->f_08)->result=0; (&(*(FileData * *)&this->f_08)->lock)->release(); return 1;
}
