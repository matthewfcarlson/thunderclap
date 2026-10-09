class Base { public: void Fin(); };
class Member { public: void Rel(); int pad[2]; };
class GrappleLocomotionSteerTrack {
public:
 void Kill();
 int vf;
 char pad[0x14];
 Member a; Member b; Member c; Member d; Member e;
};
void GrappleLocomotionSteerTrack::Kill() {
 vf = 0x415ad0;
 e.Rel(); d.Rel(); c.Rel(); b.Rel(); a.Rel();
 ((Base*)this)->Fin();
}
