struct Track;
struct Channel {
    Track* FUN_00288960();
};
struct Animation {
    Channel* FUN_00288a10(int, unsigned int, unsigned int);
};
struct Track {
    int unused;
    int count;
    void FUN_00289f80(float, int*, int*);
    void FUN_0028a080(int, float*, void**);
};
struct Geometry {
    void FUN_002d0d20(void*, int);
    void FUN_002d0da0(void*, float, int);
};
namespace pure3d {
struct VertexAnimController {
    char pad[0x34];
    float frame;
    char pad38[4];
    Animation* animation;
    Geometry* geometry;
    void vfunc_7();
};
void VertexAnimController::vfunc_7() {
    Track* track = animation->FUN_00288a10(0, 0x58545256, 0x544e49)->FUN_00288960();
    if (track) {
        int first, second;
        float firstTime, secondTime;
        void* firstData;
        void* secondData;
        track->FUN_00289f80(frame, &first, &second);
        track->FUN_0028a080(first, &firstTime, &firstData);
        geometry->FUN_002d0d20(firstData, 1);
        if (first != second) {
            track->FUN_0028a080(second, &secondTime, &secondData);
            geometry->FUN_002d0da0(secondData, (frame - firstTime) / (secondTime - firstTime), track->count);
        }
    }
}
} // namespace pure3d