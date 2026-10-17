// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00029010 @ 0x00029010
struct Result { char pad[0x1ca0]; struct Node* node; };
struct Node { struct Entry* FUN_000fdc40(); };
struct Entry { int FUN_001035e0(); };
long long __cdecl FUN_002672f0(int value, int zero1, int zero2);
struct Owner { Result* FUN_00024280(unsigned int low, unsigned int high); int FUN_00029010(int value); };
int Owner::FUN_00029010(int value) {
    long long pair = FUN_002672f0(value, 0, 0);
    Result* result = FUN_00024280((unsigned int)pair, (unsigned int)(pair >> 32));
    if (!result || !result->node) return 0;
    Entry* entry = result->node->FUN_000fdc40();
    if (!entry) return 0;
    return entry->FUN_001035e0();
}