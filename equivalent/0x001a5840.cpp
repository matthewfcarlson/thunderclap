// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001a5840 @ 0x001a5840
struct Matrix {
 unsigned int data[16];
 void FUN_0022b980();
 void FUN_0022ca90(const Matrix* a, const Matrix* b);
};
struct Source_1a5840 {
 char pad[0x1c];
 Matrix* matrices;
 unsigned int FUN_002843a0(unsigned int a, unsigned int b);
};
struct Transform_1a5840 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual Matrix* slot17();
};
struct Object {
 char pad[0x28]; Transform_1a5840* transform;
 void target(Source_1a5840* source, unsigned int a, unsigned int b, Matrix* output);
};
void Object::target(Source_1a5840* source, unsigned int a, unsigned int b, Matrix* output) {
 if (!source) { output->FUN_0022b980(); return; }
 unsigned int index=0;
 if (a || b) { index=source->FUN_002843a0(a,b); if(index==0xffff) index=0; }
 Matrix* selected=&source->matrices[index];
 for(int i=0;i<16;++i) output->data[i]=selected->data[i];
 if(transform) {
 Matrix first;
 for(int j=0;j<16;++j) first.data[j]=selected->data[j];
 Matrix* other=transform->slot17();
 Matrix second;
 for(int k=0;k<16;++k) second.data[k]=other->data[k];
 output->FUN_0022ca90(&first,&second);
 }
}
