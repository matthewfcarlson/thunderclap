// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 5/6, incomplete)
// FUN_00029a50 @ 0x00029a50
struct Inner { char reserved[0x9d]; unsigned char flag; };
struct Node { char reserved[0x1ca0]; Inner *inner; };
long long __cdecl FUN_002672f0(void *, int, int);
struct Owner { Node *FUN_00024280(long long); unsigned char FUN_00029a50(void *); };
unsigned char Owner::FUN_00029a50(void *value)
{
    long long result = FUN_002672f0(value, 0, 0);
    Node *node = FUN_00024280(result);
    if (node == 0 || node->inner == 0)
        return 0;
    return node->inner->flag;
}