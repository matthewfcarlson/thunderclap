// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ec900 @ 0x001ec900
// equiv-map: ??0Name@@QAE@PBD@Z = 0x0027b0e0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
struct Name {
    char d[8];
    Name(const char *s) throw();
    ~Name() throw();
};

struct V3_1ec900 {
    float x, y, z;
};

class Camera {
public:
    void FUN_001eb7e0(Name *a, Name *b, V3_1ec900 *p, V3_1ec900 *q, V3_1ec900 *r, V3_1ec900 zero, int z) throw();
    void FUN_001ec900(V3_1ec900 a, V3_1ec900 b, V3_1ec900 c);
};

void Camera::FUN_001ec900(V3_1ec900 a, V3_1ec900 b, V3_1ec900 c)
{
    Name name("vo_camera");
    V3_1ec900 zero;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    FUN_001eb7e0(&name, &name, &a, &b, &c, zero, 0);
}
