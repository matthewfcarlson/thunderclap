// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// pure3d::OldFrameControllerLoader::vfunc_5 @ 0x00285570
#include "decls/address.h"
struct Reader { void FUN_002647e0(void*, unsigned, unsigned, unsigned); };
struct Chunk { char pad[0x284]; Reader* reader; };
namespace pure3d {
struct OldFrameControllerLoader {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
 virtual void vfunc_5(void** output, unsigned __int64* nameId, Chunk* chunk, void* context);
 virtual unsigned char vfunc_6(unsigned type);
 virtual void* vfunc_7(char* name, unsigned type, Chunk* chunk, void* context);
};
void OldFrameControllerLoader::vfunc_5(void** output, unsigned __int64* nameId, Chunk* chunk, void* context) {
 unsigned type; unsigned char length; char name[256];
 chunk->reader->FUN_002647e0(&type,1,4,1);
 chunk->reader->FUN_002647e0(&length,1,1,1);
 unsigned n=length;
 chunk->reader->FUN_002647e0(name,n,1,1);
 name[n]=0;
 chunk->reader->FUN_002647e0(&type,1,4,1);
 unsigned savedType=type;
 void* result=0;
 if(vfunc_6(savedType)==1) result=vfunc_7(name,savedType,chunk,context);
 *output=result;
 *nameId=FUN_002672f0(name,0,0);
}
}