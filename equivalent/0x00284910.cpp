// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00284910 @ 0x00284910
void* __cdecl FUN_0008d6d0(unsigned int);
struct Skeleton { virtual void retain(); char pad[12]; unsigned int count; };
namespace pure3d {
struct Pose {
 virtual void slot0();
 unsigned int refs;
 Skeleton* skeleton;
 unsigned int count;
 char* data;
 char* matrices;
 char* extra;
 char* matrices2;
 char pad[2];
 unsigned char flag1, flag2;
 unsigned int revision;
 void* allocation;
 Pose(Skeleton*, char);
 void FUN_002845a0();
 void FUN_00284410(int);
 void FUN_002843c0(int);
 void FUN_00284460(int);
 void FUN_002844f0(int);
};
Pose::Pose(Skeleton* s, char optional) {
 refs=0; skeleton=s; extra=0; flag1=1; flag2=1; revision=0;
 s->retain();
 unsigned int n=skeleton->count;
 count=n;
 unsigned int bytes=n*144;
 if(optional) bytes+=n*16;
 char* p=(char*)FUN_0008d6d0(bytes);
 allocation=p; matrices=p;
 p+=count*64; matrices2=p;
 p+=count*64; data=p;
 extra=optional ? p+count*16 : 0;
 FUN_002845a0(); FUN_00284410(0); FUN_002843c0(0); FUN_00284460(0); FUN_002844f0(0);
 ++revision;
}
}
