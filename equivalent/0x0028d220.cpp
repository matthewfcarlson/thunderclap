// STATUS: equivalent (tools/equiv.py level 3: 15723 inputs, branch coverage 0/0)
// FUN_0028d220 @ 0x0028d220
// FUN_0028d220 @ 0x0028d220
struct Quat16 {
    short x, y, z, w;
    float* FUN_0028d220(float* out);
};

// Converts four signed 16-bit components to floats scaled by 1/32767.
float* Quat16::FUN_0028d220(float* out) {
    const float scale = 3.0518509447574615e-05f;
    out[0] = (float)x * scale;
    out[1] = (float)y * scale;
    out[2] = (float)z * scale;
    out[3] = (float)w * scale;
    return out;
}
