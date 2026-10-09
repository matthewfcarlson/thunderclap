struct Vec3 {
    float x, y, z;
};

struct Inner {
    void GetVec(Vec3* out);
};

struct Holder {
    char pad[0x10];
    Inner in;
};

struct Sub {
    Holder* Find();
};

struct Vec3q : Vec3 {
    char Query(Vec3* v, unsigned int id);
};

struct Obj {
    char pad0[0x10];
    Sub* mSub;
    char pad1[0x2074 - 0x14];
    float a, b, c;
    void Get(Vec3q* out);
};

void Obj::Get(Vec3q* out) {
    out->x = a;
    out->y = b;
    out->z = c;
    Vec3 t;
    t.x = 0;
    t.y = 0;
    t.z = 0;
    if (out->Query(&t, 0x3727c5ac)) {
        Holder* h = mSub->Find();
        if (h) {
            h->in.GetVec(&t);
            out->x = t.x;
            out->y = t.y;
            out->z = t.z;
        }
    }
}
