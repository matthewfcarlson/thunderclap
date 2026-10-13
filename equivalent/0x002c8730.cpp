// STATUS: equivalent (tools/equiv.py level 3: 41 inputs, branch coverage 30/30)
// FUN_002c8730 @ 0x002c8730
namespace pure3d {
struct VertexList {
 virtual void slot0();
 unsigned state, format, count, flags;
 void* streams[18];
 VertexList(const VertexList& source);
 void FUN_002c7340(unsigned,unsigned,unsigned);
};
VertexList::VertexList(const VertexList& source) {
 state=0; format=source.format; count=source.count; flags=source.flags;
 for(unsigned i=0;i<18;++i) streams[i]=0;
 FUN_002c7340(format,count,flags);
 for(unsigned i=0;i<17;++i) {
  unsigned char* dest=(unsigned char*)streams[i];
  if(dest) {
   const unsigned char* src=(const unsigned char*)source.streams[i];
   unsigned size;
   if(i==0) size=count*2;
   else if(i<9 || i==16) size=count*12;
   else if(i<13) size=count*8;
   else size=count*4;
   unsigned words=size/4;
   for(unsigned j=0;j<words;++j) ((unsigned*)dest)[j]=((const unsigned*)src)[j];
   for(unsigned k=words*4;k<size;++k) dest[k]=src[k];
  }
 }
}
}
