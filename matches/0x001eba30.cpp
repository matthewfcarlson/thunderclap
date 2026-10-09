struct Deep { void Run(float); };
struct Inner { Deep* d; };
struct Obj { Inner* inner; char pad[12]; float value; void set(float); };
void Obj::set(float v) {
    if (v < 0.0f || v > 100.0f) return;
    value = v;
    inner->d->Run(v);
}
