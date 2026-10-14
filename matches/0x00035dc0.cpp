struct Vec3_35dc0 {
    float x, y, z;
};

struct Inner_35dc0 {
    void GetVec(Vec3_35dc0* out);
};

struct Holder_35dc0 {
    char pad[0x10];
    Inner_35dc0 in;
};

struct Sub_35dc0 {
    Holder_35dc0* Find();
};

struct Vec3q : Vec3_35dc0 {
    char Query(Vec3_35dc0* v, unsigned int id);
};

struct Obj_35dc0 {
    char pad0[0x10];
    Sub_35dc0* mSub;
    char pad1[0x2074 - 0x14];
    float a, b, c;
    void Get(Vec3q* out);
};

void Obj_35dc0::Get(Vec3q* out) {
    out->x = a;
    out->y = b;
    out->z = c;
    Vec3_35dc0 t;
    t.x = 0;
    t.y = 0;
    t.z = 0;
    if (out->Query(&t, 0x3727c5ac)) {
        Holder_35dc0* h = mSub->Find();
        if (h) {
            h->in.GetVec(&t);
            out->x = t.x;
            out->y = t.y;
            out->z = t.z;
        }
    }
}
