void F1(int s, int a);
void F2(int s, int a);
int F3(int s, int a);
void F4(int s, int a);
void Out(int a, int b, const char* fmt, int v);
class K {
public:
	int pad[2];
	int state;
	bool Run(int a, int b, int c);
};
bool K::Run(int a, int b, int c)
{
	F1(state, a);
	F2(state, -2);
	int v = F3(state, -1);
	bool r = true;
	if (v == 0)
		r = false;
	else
		Out(b, c, "%s", v);
	F4(state, -2);
	return r;
}
