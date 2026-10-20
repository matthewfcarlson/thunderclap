struct Part {
    char reserved[0x45];
    unsigned char flag;
};
struct Inner {
    char reserved[0x58];
    Part part;
};
struct Node {
    char reserved[0x1ca0];
    Inner* inner;
};
long long __cdecl FUN_002672f0(void*, int, int);
struct Owner {
    Node* FUN_00024280(long long);
    unsigned char FUN_00029a50(void*);
};
unsigned char Owner::FUN_00029a50(void* value) {
    long long result = FUN_002672f0(value, 0, 0);
    Node* node = FUN_00024280(result);
    if (!node)
        return 0;
    Inner* inner = node->inner;
    if (!inner)
        return 0;
    Part* part = &inner->part;
    if (!part)
        return 0;
    return part->flag;
}