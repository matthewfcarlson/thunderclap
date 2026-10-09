struct Triple { unsigned a,b,c; };
class Target { char pad[0x90]; unsigned x,y,z; public: bool Copy(Triple* out); };
bool Target::Copy(Triple* out) { out->a=x; out->b=y; out->c=z; return true; }