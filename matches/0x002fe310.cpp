struct HairMap {
    char padding[0x20];
    int handle;
    int FUN_00304cb0(int handle, int index);
};
struct HairData {
    char padding[0x1c];
    char* base;
};
namespace physics {
struct SimStateHairclub {
    char padding[0x10];
    char fallback[0x64];
    HairMap* map;
    char padding2[0x10];
    HairData* data;
    void* vfunc_4(int index);
};
} // namespace physics
void* physics::SimStateHairclub::vfunc_4(int index) {
    if (index >= 0) {
        int handle = map->handle;
        int item = map->FUN_00304cb0(handle, index);
        if (item >= 0)
            return data->base + item * 64;
    }
    return fallback;
}