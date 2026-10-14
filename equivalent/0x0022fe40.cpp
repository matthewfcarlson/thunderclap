// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0022fe40 @ 0x0022fe40
// 0x0022fe40: write the component-wise normalised (min, max) corners of an axis aligned box
struct Box {
    float v[6];
    Box* FUN_0022fe40(Box* out);
};

Box* Box::FUN_0022fe40(Box* out)
{
    float lo[3];
    float hi[3];
    for (int i = 2; i >= 0; i--) {
        float a = v[i];
        float b = v[i + 3];
        if (a < b) {
            lo[i] = a;
            hi[i] = b;
        } else {
            lo[i] = b;
            hi[i] = a;
        }
    }
    out->v[0] = lo[0];
    out->v[1] = lo[1];
    out->v[2] = lo[2];
    out->v[3] = hi[0];
    out->v[4] = hi[1];
    out->v[5] = hi[2];
    return out;
}
