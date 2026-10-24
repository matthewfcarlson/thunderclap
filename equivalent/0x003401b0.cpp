// STATUS: equivalent (tools/equiv.py level 3: 3103 inputs, branch coverage 4/4; Wine build 582 inputs)
// FUN_003401b0 @ 0x003401b0
// FUN_003401b0: radix-four complex FFT pass over interleaved samples. Intermediates the original rounds to
// float through a stack slot are hulk_fslot locals.
#if defined(_MSC_VER) && !defined(__clang__)
typedef volatile float hulk_fslot; // forces the store-and-reload MSVC 7.1 would otherwise skip
#else
typedef float hulk_fslot;
#endif
// equiv-conv: FUN_003401b0 eax ecx stack
void FUN_003401b0(float* d, int n, float* tw) {
    const int quarter = n >> 3;
    const int half = 2 * quarter;
    const int full = 4 * quarter;
    const int threeHalf = 6 * quarter;

    double a = d[0];
    double b = d[half];
    double c = d[full];
    double e = d[threeHalf];
    double ai = d[1];
    double ci = d[full + 1];
    hulk_fslot sumImag = d[half + 1] + d[threeHalf + 1];
    hulk_fslot diffReal = d[half] - d[threeHalf];
    hulk_fslot diffImag = d[half + 1] - d[threeHalf + 1];
    hulk_fslot deltaReal = d[0] - d[full];
    hulk_fslot deltaImag = d[1] - d[full + 1];
    d[0] = (b + e) + (c + a);
    d[1] = sumImag + (ci + ai);
    d[half] = (c + a) - (b + e);
    d[half + 1] = (ci + ai) - sumImag;
    d[full] = deltaReal - diffImag;
    d[full + 1] = diffReal + deltaImag;
    d[threeHalf] = diffImag + deltaReal;
    d[threeHalf + 1] = deltaImag - diffReal;

    const double diagonal = tw[1];
    const double scale = tw[2];
    const double otherScale = tw[3];
    double prevReal = 0.0f;
    double prevImag = 1.0f;
    double prevNegative = 0.0f;
    double carry = 1.0f;

    if (quarter > 4) {
        float* front0 = d + 4;
        float* front1 = d + full + 4;
        float* front2 = d + half + 4;
        float* front3 = d + threeHalf + 4;
        float* back0 = d + half - 4;
        float* back1 = d + full - 4;
        float* back2 = d + threeHalf - 4;
        float* back3 = d + 2 * full - 4;
        float* factors = tw + 2;

        for (int iteration = 0; iteration < (quarter - 5) / 4 + 1; ++iteration) {
            hulk_fslot wA = (carry + factors[2]) * scale;
            hulk_fslot wB = (prevReal + factors[3]) * scale;
            hulk_fslot wC = (prevImag + factors[4]) * otherScale;
            hulk_fslot wD = (prevNegative - factors[5]) * otherScale;
            double currentImag = factors[2];
            prevReal = factors[3];
            prevImag = factors[4];
            prevNegative = -factors[5];
            factors += 4;

            double x0 = front0[-2];
            double y0 = front1[-2];
            double x1 = front0[-1];
            double y1 = front1[-1];
            hulk_fslot dx0 = front0[-2] - front1[-2];
            hulk_fslot dx1 = front0[-1] - front1[-1];
            hulk_fslot sx2 = front0[0] + front1[0];
            hulk_fslot sy2 = front0[1] + front1[1];
            hulk_fslot dx2 = front0[0] - front1[0];
            hulk_fslot dy2 = front0[1] - front1[1];
            double u0 = front3[-2];
            double v0 = front2[-2];
            hulk_fslot su1 = front3[-1] + front2[-1];
            hulk_fslot du0 = front2[-2] - front3[-2];
            hulk_fslot du1 = front2[-1] - front3[-1];
            hulk_fslot su2 = front3[0] + front2[0];
            hulk_fslot sv2 = front3[1] + front2[1];
            hulk_fslot du2 = front2[0] - front3[0];
            hulk_fslot dv2 = front2[1] - front3[1];
            front0[-2] = (u0 + v0) + (x0 + y0);
            front0[-1] = su1 + (y1 + x1);
            front0[0] = su2 + sx2;
            front0[1] = sv2 + sy2;
            front2[-2] = (x0 + y0) - (u0 + v0);
            front2[-1] = (y1 + x1) - su1;
            front2[0] = sx2 - su2;
            front2[1] = sy2 - sv2;
            front1[-2] = wA * (dx0 - du1) - wB * (du0 + dx1);
            front1[-1] = wA * (du0 + dx1) + wB * (dx0 - du1);
            front1[0] = currentImag * (dx2 - dv2) - prevReal * (du2 + dy2);
            front1[1] = currentImag * (du2 + dy2) + prevReal * (dx2 - dv2);
            front3[-2] = wD * (dx1 - du0) + wC * (du1 + dx0);
            front3[-1] = wC * (dx1 - du0) - wD * (du1 + dx0);
            front3[0] = prevNegative * (dy2 - du2) + prevImag * (dv2 + dx2);
            front3[1] = prevImag * (dy2 - du2) - prevNegative * (dv2 + dx2);

            double p0 = back0[2];
            double q0 = back2[2];
            double p1 = back0[3];
            double q1 = back2[3];
            hulk_fslot dp0 = back0[2] - back2[2];
            hulk_fslot dp1 = back0[3] - back2[3];
            hulk_fslot sp2 = back0[0] + back2[0];
            hulk_fslot sq2 = back0[1] + back2[1];
            hulk_fslot dp2 = back0[0] - back2[0];
            hulk_fslot dq2 = back0[1] - back2[1];
            double t0 = back1[2];
            double v3 = back3[2];
            hulk_fslot st1 = back3[3] + back1[3];
            hulk_fslot dt0 = back1[2] - back3[2];
            hulk_fslot dt1 = back1[3] - back3[3];
            hulk_fslot st2 = back3[0] + back1[0];
            hulk_fslot sv3 = back1[1] + back3[1];
            hulk_fslot dt2 = back1[0] - back3[0];
            hulk_fslot dv3 = back1[1] - back3[1];
            back0[2] = (t0 + v3) + (p0 + q0);
            back0[3] = st1 + (p1 + q1);
            back0[0] = st2 + sp2;
            back0[1] = sv3 + sq2;
            back1[2] = (p0 + q0) - (t0 + v3);
            back1[3] = (p1 + q1) - st1;
            back1[0] = sp2 - st2;
            back1[1] = sq2 - sv3;
            back2[2] = wB * (dp0 - dt1) - wA * (dt0 + dp1);
            back2[3] = wB * (dt0 + dp1) + wA * (dp0 - dt1);
            back2[0] = prevReal * (dp2 - dv3) - currentImag * (dt2 + dq2);
            back2[1] = prevReal * (dt2 + dq2) + currentImag * (dp2 - dv3);
            back3[2] = wC * (dp1 - dt0) + wD * (dt1 + dp0);
            back3[3] = wD * (dp1 - dt0) - wC * (dt1 + dp0);
            back3[0] = prevImag * (dq2 - dt2) + prevNegative * (dv3 + dp2);
            back3[1] = prevNegative * (dq2 - dt2) - prevImag * (dv3 + dp2);

            front0 += 4;
            front1 += 4;
            front2 += 4;
            front3 += 4;
            back0 -= 4;
            back1 -= 4;
            back2 -= 4;
            back3 -= 4;
            carry = currentImag;
        }
    }

    const int q1 = quarter;
    const int q3 = quarter * 3;
    const int q5 = quarter * 5;
    const int q7 = quarter * 7;
    hulk_fslot finalC = (prevImag - diagonal) * otherScale;
    hulk_fslot finalD = (prevNegative - diagonal) * otherScale;

    hulk_fslot a0 = d[q1 - 2];
    hulk_fslot b0 = d[q5 - 2];
    hulk_fslot ai0 = d[q1 - 1];
    hulk_fslot bi0 = d[q5 - 1];
    hulk_fslot dr0 = d[q1 - 2] - d[q5 - 2];
    hulk_fslot di0 = d[q1 - 1] - d[q5 - 1];
    hulk_fslot c0 = d[q7 - 2];
    hulk_fslot e0 = d[q3 - 2];
    hulk_fslot ci0 = d[q3 - 1] + d[q7 - 1];
    hulk_fslot er0 = d[q3 - 2] - d[q7 - 2];
    hulk_fslot ei0 = d[q3 - 1] - d[q7 - 1];
    d[q1 - 2] = (c0 + e0) + (a0 + b0);
    d[q1 - 1] = ci0 + (bi0 + ai0);
    d[q3 - 2] = (a0 + b0) - (c0 + e0);
    d[q3 - 1] = (bi0 + ai0) - ci0;
    d[q5 - 2] = ((carry + diagonal) * scale) * (dr0 - ei0) - ((prevReal + diagonal) * scale) * (er0 + di0);
    d[q5 - 1] = ((carry + diagonal) * scale) * (er0 + di0) + ((prevReal + diagonal) * scale) * (dr0 - ei0);
    d[q7 - 2] = finalD * (di0 - er0) + finalC * (ei0 + dr0);
    d[q7 - 1] = finalC * (di0 - er0) - finalD * (ei0 + dr0);

    double a1 = d[q1];
    double b1 = d[q5];
    double ai1 = d[q1 + 1];
    double bi1 = d[q5 + 1];
    hulk_fslot dr1 = d[q1] - d[q5];
    hulk_fslot di1 = d[q1 + 1] - d[q5 + 1];
    double c1 = d[q3];
    double e1 = d[q7];
    hulk_fslot ci1 = d[q3 + 1] + d[q7 + 1];
    hulk_fslot er1 = d[q3] - d[q7];
    hulk_fslot ei1 = d[q3 + 1] - d[q7 + 1];
    d[q1] = (c1 + e1) + (a1 + b1);
    d[q1 + 1] = ci1 + (bi1 + ai1);
    d[q3] = (a1 + b1) - (c1 + e1);
    d[q3 + 1] = (bi1 + ai1) - ci1;
    d[q5] = ((dr1 - ei1) - (er1 + di1)) * diagonal;
    d[q5 + 1] = ((er1 + di1) + (dr1 - ei1)) * diagonal;
    d[q7] = -(((di1 - er1) + (ei1 + dr1)) * diagonal);
    d[q7 + 1] = -(((di1 - er1) - (ei1 + dr1)) * diagonal);

    double a2 = d[q1 + 2];
    double b2 = d[q5 + 2];
    double ai2 = d[q1 + 3];
    double bi2 = d[q5 + 3];
    hulk_fslot dr2 = d[q1 + 2] - d[q5 + 2];
    hulk_fslot di2 = d[q1 + 3] - d[q5 + 3];
    double c2 = d[q7 + 2];
    double e2 = d[q3 + 2];
    hulk_fslot ci2 = d[q7 + 3] + d[q3 + 3];
    hulk_fslot er2 = d[q3 + 2] - d[q7 + 2];
    hulk_fslot ei2 = d[q3 + 3] - d[q7 + 3];
    d[q1 + 2] = (c2 + e2) + (a2 + b2);
    d[q1 + 3] = ci2 + (ai2 + bi2);
    d[q3 + 2] = (a2 + b2) - (c2 + e2);
    d[q3 + 3] = (ai2 + bi2) - ci2;
    d[q5 + 2] = ((prevReal + diagonal) * scale) * (dr2 - ei2) - ((carry + diagonal) * scale) * (er2 + di2);
    d[q5 + 3] = ((prevReal + diagonal) * scale) * (er2 + di2) + ((carry + diagonal) * scale) * (dr2 - ei2);
    d[q7 + 2] = finalC * (di2 - er2) + finalD * (ei2 + dr2);
    d[q7 + 3] = finalD * (di2 - er2) - finalC * (ei2 + dr2);
}
