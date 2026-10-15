struct V {
    float x, y;
};
int __cdecl FUN_002a18a0(const V* a, const V* b) {
    if (a->x != b->x)
        return a->x > b->x;
    return a->y > b->y;
}