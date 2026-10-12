// STATUS: equivalent (tools/equiv.py level 3: 31 inputs, branch coverage 34/34)
// FUN_00312440 @ 0x00312440
extern "C" void* memset(void*, int, unsigned int);
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat4 {
    char pad00[0x30];
    Vec3 pos;
    float w;
    void FUN_0022c3b0(Vec3* in, Vec3* out);
};

struct NameHolder {
    char pad[8];
    void FUN_0027af70(NameHolder* src);
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0();
    char pad04[4];
    NameHolder nameHolder;
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

struct Bone {
    Vec3 pos;
    Vec3 axis;
    float len;
};

struct SkeletonSrc {
    char pad00[8];
    NameHolder nameHolder;
    int count;
    char pad14[0x1c - 0x14];
    Mat4* local;
    Mat4* world;
    char pad24[4];
    unsigned short* parent;
};

void* FUN_0008d6d0(unsigned int size);
void* FUN_00266e00(int kind, unsigned int size);
void FUN_00267090(void* p);

namespace physics {

class SkeletonInfo : public pure3d::Entity {
public:
    Bone* bones;
    int count;
    virtual void vfunc_0();
    SkeletonInfo(SkeletonSrc* src);
};

SkeletonInfo::SkeletonInfo(SkeletonSrc* src)
{
    int n = src->count;
    count = n;
    Bone* arr = 0;
    int* mem = (int*)FUN_0008d6d0(n * 0x1c + 4);
    if (mem) {
        *mem = n;
        arr = (Bone*)(mem + 1);
        for (int i = 0; i < n; i++) {
            arr[i].pos.x = 0;
            arr[i].pos.y = 0;
            arr[i].pos.z = 0;
            arr[i].axis.x = 0;
            arr[i].axis.y = 0;
            arr[i].axis.z = 0;
            arr[i].len = 0;
        }
    }
    bones = arr;
    nameHolder.FUN_0027af70(&src->nameHolder);

    int* counts = (int*)FUN_00266e00(1, count * 4);
    memset(counts, 0, count * 4);

    for (int i = 1; i < count; i++) {
        int j = src->parent[i];
        if (counts[j] == 0) {
            Vec3* p = &src->local[i].pos;
            Bone* b = &bones[j];
            b->pos.x = p->x + b->pos.x;
            b->pos.y = p->y + b->pos.y;
            b->pos.z = p->z + b->pos.z;
            Vec3* q = &src->local[j].pos;
            b = &bones[j];
            b->pos.x = b->pos.x - q->x;
            b->pos.y = b->pos.y - q->y;
            b->pos.z = b->pos.z - q->z;
            counts[j] = counts[j] + 1;
        }
    }

    for (int k = 0; k < count; k++) {
        if (counts[k] > 0)
            bones[k].len = bones[k].pos.FUN_0022d110() / counts[k];
    }

    for (int k = 0; k < count; k++) {
        Bone* parent = &bones[src->parent[k]];
        Bone* b = &bones[k];
        b->axis.x = parent->pos.y * b->pos.z - parent->pos.z * b->pos.y;
        b->axis.y = parent->pos.z * b->pos.x - b->pos.z * parent->pos.x;
        b->axis.z = b->pos.y * parent->pos.x - parent->pos.y * b->pos.x;
        bones[k].axis.FUN_0022d110();
        b = &bones[k];
        double X = b->axis.y * b->pos.z - b->axis.z * b->pos.y;
        double Y = b->pos.x * b->axis.z - b->pos.z * b->axis.x;
        double Z = b->pos.y * b->axis.x - b->pos.x * b->axis.y;
        double len = sqrt(Z * Z + Y * Y + X * X);
        if (len < 0.8f) {
            b->axis.z = 0;
            b->axis.y = 0;
            b->axis.x = 0;
        }
    }

    for (int k = 0; k < count; k++) {
        if (counts[k] > 0) {
            Bone* b = &bones[k];
            Vec3 v = b->pos;
            src->world[k].FUN_0022c3b0(&v, &b->pos);
        } else {
            Bone* from = &bones[src->parent[k]];
            Bone* to = &bones[k];
            *to = *from;
            to = &bones[k];
            to->axis.x = 1.0f;
            to->axis.y = 0;
            to->axis.z = 0;
        }
    }

    for (int k = 1; k < count; k++) {
        Bone* b = &bones[k];
        unsigned int j = src->parent[k];
        Vec3 v = b->axis;
        src->world[j].FUN_0022c3b0(&v, &b->axis);
    }

    FUN_00267090(counts);
}

}
