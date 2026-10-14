// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000b3bc0 @ 0x000b3bc0
struct Sample { unsigned int words[17]; };
struct Vector3 { unsigned int x,y,z; };
struct Block { Vector3 vectors[13]; char rest[112]; };
struct Source {
 void FUN_000ada90(Sample*);
 void FUN_000adad0(Sample*);
};
extern unsigned char DAT_004e222c;
struct Object {
 char pad[8];
 Source* source;
 Block first;
 Block second;
 void FUN_000b36d0(Block*, Sample, unsigned int);
 void FUN_000b3bc0(unsigned int arg);
};
void Object::FUN_000b3bc0(unsigned int arg) {
 Sample sample;
 source->FUN_000ada90(&sample);
 FUN_000b36d0(&first,sample,arg);
 source->FUN_000adad0(&sample);
 FUN_000b36d0(&second,sample,arg);
 if (DAT_004e222c) {
  for (int i=0;i<13;++i) { first.vectors[i].x=0; first.vectors[i].y=0; first.vectors[i].z=0; }
  for (int j=0;j<13;++j) { second.vectors[j].x=0; second.vectors[j].y=0; second.vectors[j].z=0; }
 }
}
