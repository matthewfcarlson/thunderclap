// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00228720 @ 0x00228720
struct V3 {
    float x, y, z;
};

extern float DAT_004c9e90;
extern float DAT_004c9e94;
extern float DAT_004c9e98;

void __cdecl FUN_00224d70(void *transform, V3 *vec);

class Emitter {
public:
    void FUN_00228720(V3 *out);

    char pad0[0x8ac];
    void *transform;    // +0x8ac
    float speed;        // +0x8b0
};

// Transforms the default direction by the emitter's transform and scales it by its speed.
void Emitter::FUN_00228720(V3 *out) {
    V3 dir;
    dir.x = DAT_004c9e90;
    dir.y = DAT_004c9e94;
    dir.z = DAT_004c9e98;
    FUN_00224d70(transform, &dir);
    float s = speed;
    dir.x = dir.x * s;
    out->x = dir.x;
    dir.y = dir.y * s;
    out->y = dir.y;
    dir.z = dir.z * s;
    out->z = dir.z;
}
