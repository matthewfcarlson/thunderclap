double sin(double); double cos(double); double atan2(double, double); double pow(double, double);
float k1(float y, float x) { return (float)(atan2(y, x) * 57.29577951308232); }
double k2(float a, float r) { return r * sin(a) + 1.0; }
double k3(float a, float b) { return sin(a) * cos(b); }
float k4(float a) { return (float)sin(a); }
int k5(float a, float t) { return sin(a) > t; }
double k6(float a) { return 1.0 / cos(a); }
double k7(float a, float b) { return b - pow(a, 0.75); }
