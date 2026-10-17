// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 10/10)
// FUN_003357e0 @ 0x003357e0
struct Entry { char pad[8]; int type; };
struct Container { char pad[0x44]; int count; Entry* FUN_00337090(int index); };
struct Owner { char pad[4]; Container* container; char** strings; bool FUN_003357e0(int index, int* length); };
bool Owner::FUN_003357e0(int index, int* length) {
    if (index < 0 || index >= container->count || container->FUN_00337090(index)->type != 10)
        return false;
    const char* text = strings[index];
    if (!text) { *length = 0; return true; }
    int n = 0;
    while (text[n]) ++n;
    *length = n;
    return true;
}