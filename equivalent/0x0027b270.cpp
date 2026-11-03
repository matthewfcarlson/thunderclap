// STATUS: equivalent (tools/equiv.py level 3: 147 inputs, branch coverage 4/4)
// FUN_0027b270 @ 0x0027b270
#include "gen/owners.h"
struct Matrix { unsigned int words[16];   };
struct Local_27b270 { unsigned int words[4];  };
struct Object { char pad[16]; unsigned int count; Local_27b270* locals; Matrix* localMatrices; Matrix* worldMatrices; Matrix* inverseMatrices; unsigned int unknown24; unsigned short* parents; void update(); };
void Object::update() {
 ((owners::Quat_22b370 *)locals)->FUN_0022b370((const float *)(Matrix *)localMatrices);
 Matrix* src=localMatrices;
 Matrix* dst=worldMatrices;
 for(unsigned int j=0;j<16;++j) dst->words[j]=src->words[j];
 Matrix* inv=inverseMatrices;
 src=localMatrices;
 for(unsigned int k=0;k<16;++k) inv->words[k]=src->words[k];
 ((owners::Matrix_22c120 *)inv)->FUN_0022c120();
 for(unsigned int i=1;i<count;++i) {
 unsigned short parent=parents[i];
 ((owners::Quat_22b370 *)&(locals[i]))->FUN_0022b370((const float *)(Matrix *)(localMatrices+i));
 ((owners::Matrix_22ca90 *)&(worldMatrices[i]))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(localMatrices+i), (const owners::Matrix_22ca90 *)(Matrix *)(worldMatrices+parent));
 Matrix* out=inverseMatrices+i;
 src=worldMatrices+i;
 for(unsigned int n=0;n<16;++n) out->words[n]=src->words[n];
 ((owners::Matrix_22c120 *)out)->FUN_0022c120();
 }
}