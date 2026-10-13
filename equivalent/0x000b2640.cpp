// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 36/36)
// FUN_000b2640 @ 0x000b2640
__declspec(nothrow) void __cdecl FUN_0008d330(void*);
__declspec(nothrow) void __stdcall FUN_000b0ff0(void*);
__declspec(nothrow) void __stdcall FUN_00013420(void*, int, int, void (__stdcall *)(void*));
namespace core { struct IRefCount { virtual void slot0(); ~IRefCount() {} }; }
struct Buffer { unsigned count; void* data; };
struct Block { Buffer entries[6]; };
struct CPhysicalController : core::IRefCount {
 virtual void slot0();
 char pad[0x58-4];
 Buffer first[11]; Block firstBlocks[2];
 Buffer second[11]; Block secondBlocks[2];
 Buffer third[13]; Block thirdBlocks[2];
 Buffer fourth[13]; Block fourthBlocks[2];
 void* fifth[11]; char gap[0x60]; void* sixth[13];
 char tail[0x60]; Buffer extraA, extraB;
 __declspec(nothrow) void FUN_000b0db0(); ~CPhysicalController();
};
CPhysicalController::~CPhysicalController() {
 FUN_000b0db0(); int i;
 for(i=0;i<11;++i) if(fifth[i]) { FUN_0008d330(fifth[i]); fifth[i]=0; }
 for(i=0;i<13;++i) if(sixth[i]) { FUN_0008d330(sixth[i]); sixth[i]=0; }
 if(extraB.data) { FUN_0008d330(extraB.data); extraB.count=0; extraB.data=0; }
 if(extraA.data) { FUN_0008d330(extraA.data); extraA.count=0; extraA.data=0; }
 for(i=1;i>=0;--i) FUN_00013420(&fourthBlocks[i],8,6,FUN_000b0ff0);
 for(i=12;i>=0;--i) if(fourth[i].data) { FUN_0008d330(fourth[i].data); fourth[i].count=0; fourth[i].data=0; }
 for(i=1;i>=0;--i) FUN_00013420(&thirdBlocks[i],8,6,FUN_000b0ff0);
 for(i=12;i>=0;--i) if(third[i].data) { FUN_0008d330(third[i].data); third[i].count=0; third[i].data=0; }
 for(i=1;i>=0;--i) FUN_00013420(&secondBlocks[i],8,6,FUN_000b0ff0);
 for(i=10;i>=0;--i) if(second[i].data) { FUN_0008d330(second[i].data); second[i].count=0; second[i].data=0; }
 for(i=1;i>=0;--i) FUN_00013420(&firstBlocks[i],8,6,FUN_000b0ff0);
 for(i=10;i>=0;--i) if(first[i].data) { FUN_0008d330(first[i].data); first[i].count=0; first[i].data=0; }
}