// FUN_001f7120 @ 0x001f7120
// FUN_001f7120 @ 0x001f7120
struct Obj { void FUN_001c3830(void*, void*); };
Obj* __cdecl FUN_001c3d90();  // 0-argument singleton getter
void __cdecl FUN_001f7120(void* first, void* second) {
    FUN_001c3d90()->FUN_001c3830(first, second);
}
