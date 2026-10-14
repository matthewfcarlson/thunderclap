// STATUS: equivalent (tools/equiv.py level 3: 135 inputs, branch coverage 6/6)
// FUN_002845a0 @ 0x002845a0
struct Vector { unsigned int x,y,z,w; };
struct Matrix { unsigned int words[16]; void FUN_0022b980(); };
struct Source { char pad[20]; Vector* vectors; Matrix* matrices; };
struct Object { char pad[8]; Source* source; unsigned int count; Vector* vectors; Matrix* matrices; Vector* optionalVectors; Matrix* resetMatrices; char pad20[2]; unsigned char flag22,flag23; unsigned int generation; void target(); };
void Object::target() {
 for(unsigned int i=0;i<count;++i) {
  const volatile Vector* src=source->vectors+i;
  volatile Vector* dst=vectors+i;
  dst->x=src->x; dst->y=src->y; dst->z=src->z; dst->w=src->w;
  const volatile unsigned int* ms=source->matrices[i].words;
  volatile unsigned int* md=matrices[i].words;
  for(unsigned int j=0;j<16;++j) md[j]=ms[j];
  resetMatrices[i].FUN_0022b980();
  Vector* v=optionalVectors;
  if(v) { v[i].z=0; v[i].y=0; v[i].x=0; v[i].w=0x3f800000; }
 }
 unsigned int next=generation+1;
 flag22=0; flag23=1; generation=next;
}
