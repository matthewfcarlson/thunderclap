typedef unsigned int u32_23b950;
struct DataReader {
    char pad[8];
    struct Helper_23b950* member;
};
struct Helper_23b950 {
    u32_23b950 call(u32_23b950, u32_23b950, u32_23b950, u32_23b950);
};
struct StreamDataReader : DataReader {
    u32_23b950 vfunc_4(u32_23b950 a, u32_23b950 b);
};
u32_23b950 StreamDataReader::vfunc_4(u32_23b950 a, u32_23b950 b) {
    member->call(a, b, 1, 1);
    return b;
}
