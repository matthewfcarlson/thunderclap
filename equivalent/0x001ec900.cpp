// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ec900 @ 0x001ec900
// equiv-map: ??0Name@@QAE@PBD@Z = 0x0027b0e0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
struct Name {
    char d[8];
    Name(const char *s) throw();
    ~Name() throw();
};

struct V3 {
    float x, y, z;
};

class Camera {
public:
    void FUN_001eb7e0(Name *a, Name *b, V3 *p, V3 *q, V3 *r, V3 zero, int z) throw();
    void FUN_001ec900(V3 a, V3 b, V3 c);
};

void Camera::FUN_001ec900(V3 a, V3 b, V3 c)
{
    Name name("vo_camera");
    V3 zero;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    FUN_001eb7e0(&name, &name, &a, &b, &c, zero, 0);
}
