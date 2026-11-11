// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00329430..0x0032b0a0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dSimpleShader
// (tree_prelude.h: not needed)


// 0x00329c90 FUN_00329c90 (93 B): equivalent/0x00329c90.cpp [isolated: conflict: DAT_0039db08; on include/gen/ and not mergeable]
// sym: ?FUN_00329c90@Obj_329c90@owners@@QAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 2/2)
// FUN_00329c90 @ 0x00329c90
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"

struct Entry_329c90 { int a,b,c; };  struct Slot_329c90 { int b,a,c; char rest[116]; }; extern Slot_329c90 DAT_0039db1c[]; extern int DAT_0039db08;  void owners::Obj_329c90::FUN_00329c90(int index, int value) { if (choices[index] != value) { choices[index] = value; DAT_0039db1c[index].a = ((Entry_329c90*)&DAT_004d4e10)[value].a; DAT_0039db1c[index].b = ((Entry_329c90*)&DAT_004d4e10)[value].b; DAT_0039db1c[index].c = ((Entry_329c90*)&DAT_004d4e10)[value].c; DAT_0039db08 |= 1 << index; } }

