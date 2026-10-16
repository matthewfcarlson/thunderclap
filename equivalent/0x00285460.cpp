// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 8/8)
// pure3d::FrameControllerLoader::vfunc_5 @ 0x00285460
#include "decls/address.h"
typedef unsigned int uint;
typedef unsigned __int64 uint64_285460;
struct Reader { void FUN_002647e0(void*,uint,uint,uint); };
struct Chunk { char pad[0x284]; Reader* reader; };
struct Handler_285460 {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual unsigned char accepts(uint);
 virtual void* load(char*,uint,uint,Chunk*,void*);
};
namespace pure3d {
struct FrameControllerLoader {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void vfunc_5(void**,uint64_285460*,Chunk*,void*);
 char pad[8]; uint failed; uint spare; uint count; Handler_285460* handlers[1];
};
void FrameControllerLoader::vfunc_5(void** output,uint64_285460* key,Chunk* chunk,void* context) {
 uint first, type; unsigned char length; char name[256];
 chunk->reader->FUN_002647e0(&first,1,4,1);
 chunk->reader->FUN_002647e0(&length,1,1,1);
 chunk->reader->FUN_002647e0(name,length,1,1);
 name[length]=0;
 chunk->reader->FUN_002647e0(&type,1,4,1);
 void* result=0;
 for(uint i=0;i<count;++i) {
 if(handlers[i]->accepts(type)==1) {
 result=handlers[i]->load(name,type,first,chunk,context);
 failed=result==0;
 }
 }
 *output=result;
 *key=FUN_002672f0(name,0,0);
}
}