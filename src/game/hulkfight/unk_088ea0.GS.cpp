// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00088ea0..0x00089400 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_faa011cc {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_faa011cc {} using namespace fn_faa011cc;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_faa011cc {
struct Record_890a0 { unsigned int words[0x2fa]; };
struct Loader_890a0 { int FUN_0008ca70(unsigned int source, int index, Record_890a0* record, int size, void* scratch); };
extern "C" void __cdecl FUN_000fb690(void* destination, const void* source, int size);
struct Manager_890a0 {
 char padding[0xac4];
 Loader_890a0* loader;
 Record_890a0* records;
 int FUN_000890a0(unsigned int source, int index);
};


// 0x000890a0 FUN_000890a0 (183 B): equivalent/0x000890a0.cpp
// sym: ?FUN_000890a0@Manager_890a0@fn_faa011cc@@QAEHIH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3420 inputs, branch coverage 6/6)
// FUN_000890a0 @ 0x000890a0
int Manager_890a0::FUN_000890a0(unsigned int source, int index) {
 char scratch[128];
 Record_890a0* record = records + index;
 for (int i=0; i<0x2fa; ++i) record->words[i]=0;
 int result=loader->FUN_0008ca70(source,index,records+index,0xbe8,scratch);
 FUN_000fb690(&records[index].words[0xb68/4],scratch,0x40);
 if(index>=0 && result==0 && records[index].words[0] != (unsigned int)DAT_0049c294) result=12;
 return result;
}

} // namespace fn_faa011cc
