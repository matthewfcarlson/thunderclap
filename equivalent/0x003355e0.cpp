// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 10/10)
// FUN_003355e0 @ 0x003355e0
struct Entry { char pad[8]; int type; };
struct Collection { char pad[0x44]; int count; Entry* FUN_00337090(int index); };
struct Owner { char pad[4]; Collection* collection; char** strings; bool FUN_003355e0(int index, char* destination); };
bool Owner::FUN_003355e0(int index, char* destination) {
    if (index < 0 || index >= collection->count || collection->FUN_00337090(index)->type != 4)
        return false;
    const char* source = strings[index];
    if (source) {
        while ((*destination++ = *source++) != 0) {}
    } else {
        *destination = 0;
    }
    return true;
}