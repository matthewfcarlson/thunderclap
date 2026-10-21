// The PNG reader's free callback (0x002adba0 passes it to the png_create_read_struct_2-shaped 0x002d6f10 after the
// malloc one): `__cdecl (png, pointer)`, forwarding to the cdecl 0x00266f00 (the allocator table 0x00527c60's
// fifth virtual) with allocator 1: the original stores 1 over its first word and jumps. native15: was spelled as a
// thiscall member calling a thiscall member, which pops 4 bytes natively where both functions pop none (check 7).
int __cdecl FUN_00266f00(int allocator, void* pointer);
void __cdecl FUN_002ad7f0(void* png, void* pointer) {
    FUN_00266f00(1, pointer);
}
