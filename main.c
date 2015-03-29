#include <stdio.h>
#include <stdlib.h>

#include "instrumentation.h"

#define DEG 20

int main()
{
    // ========================================================================
    // Variable Definitions
    // ========================================================================

    int d, A[DEG][DEG], B[DEG][DEG], M[DEG*DEG][DEG*DEG];
    int i, j, rowa, colb;

    int TMP0, TMP1, TMP2;

    // ========================================================================
    // Read d
    // ========================================================================

    store_scanf("%d", &d);

    // ========================================================================
    // Block A
    // ========================================================================

    i = add(0,0);
    A1: if(compare(i,d,'l'))
    {
        j = add(0,0);
        A2: if(compare(j,d,'l'))
        {
            store_scanf("%d",&A[i][j]);
            j = add(j,1);
            jump(A2)
        }
        i = add(i,1);
        jump(A1);
    }

    // ========================================================================
    // Block B
    // ========================================================================

    i = add(0,0);
    B1: if(compare(i,d,'l'))
    {
        j = add(0,0);
        B2: if(compare(j,d,'l'))
        {
            store_scanf("%d",&B[i][j]);
            j = add(j,1);
            jump(B2)
        }
        i = add(i,1);
        jump(B1);
    }

    // ========================================================================
    // Block C
    // ========================================================================

    i = add(0,0);
    TMP0 = d*d;
    C1: if(compare(i,TMP0,'l'))
    {
        j = add(0,0);
        TMP1 = d*d;
        C2: if(compare(j,TMP1,'l'))
        {
            M[i][j] = add(0,0);
            j = add(j,1);
            jump(C2);
        }
        i = add(i,1);
        jump(C1);
    }

    // ========================================================================
    // Block D
    // ========================================================================

    rowa = add(0,0);
    D1: if(compare(rowa,d,'l'))
    {
        colb = add(0,0);
        D2: if(compare(colb,d,'l'))
        {
            j = add(0,0);
            D3: if(compare(j,d,'l'))
            {
                TMP0 = load(A[rowa][j]);
                if(compare(TMP0,0,'g'))
                {
                    TMP1 = mult(rowa,d);
                    TMP1 = add(TMP0,colb);
                    TMP2 = mult(j,d);
                    TMP2 = add(TMP1,colb);
                    TMP0 = load(M[TMP0][TMP1]);

                    if(compare(TMP0,0,'n'))
                    {
                        M[TMP1][TMP2] = store(0);
                    }
                    if(compare(TMP0,0,'e'))
                    {
                        M[TMP1][TMP2] = store(1);
                    }
                }
                j = add(j,1);
                jump(D3);
            }
            colb = add(colb,1);
            jump(D2);
        }
        rowa = add(rowa,1);
        jump(D1);
    }

    // ========================================================================
    // Block E
    // ========================================================================

    rowa = add(0,0);
    E1: if(compare(rowa,d,'l'))
    {
        colb = add(0,0);
        E2: if(compare(colb,d,'l'))
        {
            j = add(0,0);
            E3: if(compare(j,d,'l'))
            {
                TMP0 = load(B[j][colb]);
                if(compare(TMP0,0,'g'))
                {
                    TMP1 = mult(rowa,d);
                    TMP1 = add(TMP0,colb);
                    TMP2 = mult(rowa,d);
                    TMP2 = add(TMP1,j);
                    TMP0 = load(M[TMP0][TMP1]);

                    if(compare(TMP0,0,'n'))
                    {
                        M[TMP1][TMP2] = store(0);
                    }
                    if(compare(TMP0,0,'e'))
                    {
                        M[TMP1][TMP2] = store(1);
                    }
                }
                j = add(j,1);
                jump(E3);
            }
            colb = add(colb,1);
            jump(E2);
        }
        rowa = add(rowa,1);
        jump(E1);
    }

    // ========================================================================
    // Block F
    // ========================================================================

    load_printf_one("\n");
    i = add(0,0);
    TMP0 = d*d;
    F1: if(compare(i,TMP0,'l'))
    {
        j = add(0,0);
        TMP1 = d*d;
        F2: if(compare(j,TMP1,'l'))
        {
            load_printf_two("%d ", &M[i][j]);
            j = add(j,1);
            jump(F2);
        }
        load_printf_one("\n");
        i = add(i,1);
        jump(F1);
    }

    // ========================================================================
    // Print Report and Exit
    // ========================================================================

    print_counters(d);
    return 0;
}
