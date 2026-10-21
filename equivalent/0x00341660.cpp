// STATUS: equivalent (tools/equiv.py level 3: 9235 inputs, branch coverage 4/4)
// FUN_00341660 @ 0x00341660
// Radix-4 butterfly pass of a float FFT over the array a (n = 8 * l floats), using the twiddle
// table w. The first and last butterflies use the sqrt(1/2) twiddle directly; the loop handles the
// pairs in between from both ends. Intermediates the original rounds to float through a stack slot
// are volatile floats; values it keeps on the FPU stack stay inline extended expressions.
// equiv-conv: FUN_00341660 eax stack stack
void FUN_00341660(float *a, int n, float *w)
{
    int l = n >> 3;
    {
        double v1 = w[1];
        double v2 = a[0];
        double v3 = a[4 * l + 1];
        double v4 = a[4 * l];
        double v5 = a[1];
        double v6 = a[4 * l + 1];
        double v7 = a[0];
        volatile float t8 = (v6 + v7);
        double v9 = a[1];
        double v10 = a[4 * l];
        volatile float t11 = (v9 - v10);
        double v12 = a[2 * l];
        double v13 = a[6 * l + 1];
        double v14 = a[6 * l];
        double v15 = a[2 * l + 1];
        double v16 = a[6 * l + 1];
        double v17 = a[2 * l];
        volatile float t18 = (v16 + v17);
        double v19 = a[2 * l + 1];
        double v20 = a[6 * l];
        volatile float t21 = (v19 - v20);
        volatile float t22 = (((v12 - v13) - (v14 + v15)) * v1);
        a[0] = (t22 + (v2 - v3));
        a[1] = ((((v12 - v13) + (v14 + v15)) * v1) + (v4 + v5));
        a[2 * l] = ((v2 - v3) - t22);
        a[2 * l + 1] = ((v4 + v5) - (((v12 - v13) + (v14 + v15)) * v1));
        a[4 * l] = (t8 - ((t21 + t18) * v1));
        a[4 * l + 1] = (((t18 - t21) * v1) + t11);
        a[6 * l] = (((t21 + t18) * v1) + t8);
        a[6 * l + 1] = (t11 - ((t18 - t21) * v1));
    }
    if (l > 2) {
        for (int j = 2; j < l; j += 2) {
            double v1 = w[2 * j];
            double v2 = w[2 * j + 1];
            double v3 = w[2 * j + 2];
            double v4 = w[2 * j + 3];
            volatile float t5 = (-v4);
            double v6 = w[-2 * j + 4 * l];
            double v7 = w[-2 * j + 4 * l + 1];
            double v8 = w[-2 * j + 4 * l + 2];
            double v9 = w[-2 * j + 4 * l + 3];
            volatile float t10 = (-v9);
            double v11 = a[j];
            double v12 = a[j + 4 * l + 1];
            double v13 = a[j + 1];
            double v14 = a[j + 4 * l];
            double v15 = a[j];
            double v16 = a[j + 4 * l + 1];
            volatile float t17 = (v15 + v16);
            double v18 = a[j + 1];
            double v19 = a[j + 4 * l];
            volatile float t20 = (v18 - v19);
            double v21 = a[j + 2 * l];
            double v22 = a[j + 6 * l + 1];
            volatile float t23 = (v21 - v22);
            double v24 = a[j + 6 * l];
            double v25 = a[j + 2 * l + 1];
            volatile float t26 = (v24 + v25);
            double v27 = a[j + 2 * l];
            double v28 = a[j + 6 * l + 1];
            volatile float t29 = (v27 + v28);
            double v30 = a[j + 2 * l + 1];
            double v31 = a[j + 6 * l];
            volatile float t32 = (v30 - v31);
            volatile float t33 = ((v1 * (v11 - v12)) - (v2 * (v13 + v14)));
            volatile float t34 = ((v1 * (v13 + v14)) + (v2 * (v11 - v12)));
            a[j] = (((t23 * v7) - (v6 * t26)) + t33);
            a[j + 1] = (t34 + ((v7 * t26) + (v6 * t23)));
            a[j + 2 * l] = (t33 - ((t23 * v7) - (v6 * t26)));
            a[j + 2 * l + 1] = (t34 - ((v7 * t26) + (v6 * t23)));
            volatile float t35 = ((v8 * t32) + (t10 * t29));
            volatile float t36 = ((t10 * t32) - (v8 * t29));
            a[j + 4 * l] = (t35 + ((t5 * t20) + (v3 * t17)));
            a[j + 4 * l + 1] = (t36 + ((v3 * t20) - (t5 * t17)));
            a[j + 6 * l] = (((t5 * t20) + (v3 * t17)) - t35);
            a[j + 6 * l + 1] = (((v3 * t20) - (t5 * t17)) - t36);
            double v37 = a[-j + 2 * l];
            double v38 = a[-j + 6 * l + 1];
            double v39 = a[-j + 6 * l];
            double v40 = a[-j + 2 * l + 1];
            double v41 = a[-j + 2 * l];
            double v42 = a[-j + 6 * l + 1];
            volatile float t43 = (v41 + v42);
            double v44 = a[-j + 2 * l + 1];
            double v45 = a[-j + 6 * l];
            volatile float t46 = (v44 - v45);
            double v47 = a[-j + 4 * l];
            double v48 = a[-j + 8 * l + 1];
            volatile float t49 = (v47 - v48);
            double v50 = a[-j + 8 * l];
            double v51 = a[-j + 4 * l + 1];
            volatile float t52 = (v50 + v51);
            double v53 = a[-j + 4 * l];
            double v54 = a[-j + 8 * l + 1];
            volatile float t55 = (v53 + v54);
            double v56 = a[-j + 4 * l + 1];
            double v57 = a[-j + 8 * l];
            volatile float t58 = (v56 - v57);
            volatile float t59 = ((v6 * (v37 - v38)) - (v7 * (v39 + v40)));
            volatile float t60 = ((v6 * (v39 + v40)) + (v7 * (v37 - v38)));
            volatile float t61 = ((t49 * v2) - (v1 * t52));
            a[-j + 2 * l] = (t61 + t59);
            a[-j + 2 * l + 1] = (t60 + ((v2 * t52) + (v1 * t49)));
            a[-j + 4 * l] = (t59 - t61);
            a[-j + 4 * l + 1] = (t60 - ((v2 * t52) + (v1 * t49)));
            volatile float t62 = ((t5 * t58) - (v3 * t55));
            a[-j + 6 * l] = (((v3 * t58) + (t5 * t55)) + ((t10 * t46) + (v8 * t43)));
            a[-j + 6 * l + 1] = (t62 + ((v8 * t46) - (t10 * t43)));
            a[-j + 8 * l] = (((t10 * t46) + (v8 * t43)) - ((v3 * t58) + (t5 * t55)));
            a[-j + 8 * l + 1] = (((v8 * t46) - (t10 * t43)) - t62);
        }
    }
    {
        double v1 = w[2 * l];
        double v2 = w[2 * l + 1];
        double v3 = a[l];
        double v4 = a[5 * l + 1];
        double v5 = a[5 * l];
        double v6 = a[l + 1];
        double v7 = a[5 * l + 1];
        double v8 = a[l];
        volatile float t9 = (v7 + v8);
        double v10 = a[l + 1];
        double v11 = a[5 * l];
        volatile float t12 = (v10 - v11);
        double v13 = a[3 * l];
        double v14 = a[7 * l + 1];
        volatile float t15 = (v13 - v14);
        double v16 = a[3 * l + 1];
        double v17 = a[7 * l];
        volatile float t18 = (v16 + v17);
        double v19 = a[7 * l + 1];
        double v20 = a[3 * l];
        volatile float t21 = (v19 + v20);
        double v22 = a[3 * l + 1];
        double v23 = a[7 * l];
        volatile float t24 = (v22 - v23);
        volatile float t25 = ((v1 * (v3 - v4)) - (v2 * (v5 + v6)));
        volatile float t26 = ((v2 * t18) + (v1 * t15));
        a[l] = (t25 + ((v2 * t15) - (v1 * t18)));
        a[l + 1] = (t26 + ((v1 * (v5 + v6)) + (v2 * (v3 - v4))));
        a[3 * l] = (t25 - ((v2 * t15) - (v1 * t18)));
        a[3 * l + 1] = (((v1 * (v5 + v6)) + (v2 * (v3 - v4))) - t26);
        volatile float t27 = ((t9 * v2) - (v1 * t12));
        volatile float t28 = ((t12 * v2) + (v1 * t9));
        volatile float t29 = ((v1 * t21) - (v2 * t24));
        a[5 * l] = (t27 - t29);
        a[5 * l + 1] = (t28 - ((v1 * t24) + (v2 * t21)));
        a[7 * l] = (t29 + t27);
        a[7 * l + 1] = (((v1 * t24) + (v2 * t21)) + t28);
    }
}
