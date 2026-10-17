// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002146c0 @ 0x002146c0
struct Entry { int kind; char* data; };
struct Object { char padding[8]; Entry* entries; };
extern char DAT_00426608;
// equiv-conv: FUN_002146c0 eax ecx
void* FUN_002146c0(int id, Object* object)
{
    int index = id - 250;
    if (index >= 0 && object->entries[index].kind == 4)
        return object->entries[index].data + 16;
    return &DAT_00426608;
}
