// STATUS: equivalent (tools/equiv.py level 3: 147 inputs, branch coverage 4/4)
// FUN_0027b270 @ 0x0027b270
struct Matrix { unsigned int words[16]; void FUN_0022c120(); void FUN_0022ca90(Matrix*,Matrix*); };
struct Local { unsigned int words[4]; void FUN_0022b370(Matrix*); };
struct Object { char pad[16]; unsigned int count; Local* locals; Matrix* localMatrices; Matrix* worldMatrices; Matrix* inverseMatrices; unsigned int unknown24; unsigned short* parents; void update(); };
void Object::update() {
 locals->FUN_0022b370(localMatrices);
 Matrix* src=localMatrices;
 Matrix* dst=worldMatrices;
 for(unsigned int j=0;j<16;++j) dst->words[j]=src->words[j];
 Matrix* inv=inverseMatrices;
 src=localMatrices;
 for(unsigned int k=0;k<16;++k) inv->words[k]=src->words[k];
 inv->FUN_0022c120();
 for(unsigned int i=1;i<count;++i) {
 unsigned short parent=parents[i];
 locals[i].FUN_0022b370(localMatrices+i);
 worldMatrices[i].FUN_0022ca90(localMatrices+i,worldMatrices+parent);
 Matrix* out=inverseMatrices+i;
 src=worldMatrices+i;
 for(unsigned int n=0;n<16;++n) out->words[n]=src->words[n];
 out->FUN_0022c120();
 }
}