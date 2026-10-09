struct V { float x,y,z; float length2(); };
float V::length2() { return x*x + y*y + z*z; }