// STATUS: equivalent (tools/equiv.py level 3: 21 inputs, branch coverage 18/18)
// FUN_002c84a0 @ 0x002c84a0
#include "compat/ptr.h"
void* __cdecl FUN_0008d6d0(hulk_uintptr);
namespace pure3d {
struct VertexOffsetList {
 virtual void destroy();
 unsigned int refs, flags, count;
 unsigned int *positions, *normals;
 unsigned int *texcoords[4];
 unsigned int *packed[2];
 void FUN_002c7120();
 void FUN_002c71b0();
 VertexOffsetList(const VertexOffsetList& source);
};
VertexOffsetList::VertexOffsetList(const VertexOffsetList& source) {
 refs=0;
 flags=source.flags;
 count=source.count;
 positions=0; normals=0;
 if(source.positions) {
  FUN_002c7120();
  unsigned int n=(count*12u)>>2;
  unsigned int* dst=positions; const unsigned int* src=source.positions;
  for(unsigned int j=0;j<n;++j) dst[j]=src[j];
 }
 if(source.normals) {
  FUN_002c71b0();
  unsigned int n=(count*12u)>>2;
  unsigned int* dst=normals; const unsigned int* src=source.normals;
  for(unsigned int j=0;j<n;++j) dst[j]=src[j];
 }
 for(unsigned int i=0;i<4;++i) {
  texcoords[i]=0;
  if(source.texcoords[i]) {
   texcoords[i]=(unsigned int*)FUN_0008d6d0(count*8u);
   flags |= 1u<<i;
   unsigned int n=(count*8u)>>2;
   unsigned int* dst=texcoords[i]; const unsigned int* src=source.texcoords[i];
   for(unsigned int j=0;j<n;++j) dst[j]=src[j];
  }
 }
 for(unsigned int i=0;i<2;++i) {
  packed[i]=0;
  if(source.packed[i]) {
   unsigned int savedCount=count;
   unsigned int* allocation=(unsigned int*)FUN_0008d6d0(savedCount*8u+4u);
   unsigned int* data=0;
   if(allocation) {
    allocation[0]=savedCount;
    data=allocation+1;
    if((int)(savedCount-1u)>=0) {
     unsigned short* p=(unsigned short*)data;
     for(unsigned int j=0;j<savedCount;++j) {
      p[0]=0;p[1]=0;p[2]=0;p[3]=0;p+=4;
     }
    }
   }
   packed[i]=data;
   flags |= 0x40u<<i;
   unsigned int n=(count*8u)>>2;
   unsigned int* dst=packed[i]; const unsigned int* src=source.packed[i];
   for(unsigned int j=0;j<n;++j) dst[j]=src[j];
  }
 }
}
}
