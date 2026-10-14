struct V {
    int x, y, z;
};
extern void fn(V*, int, int, V);
void target(V* begin, V* end, V* out, V a) {
    *out = *begin;
    fn(begin, 0, end - begin, a);
}