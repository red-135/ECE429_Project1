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

    #ifdef DEBUG
        //Debug statements do not count towards ICi or IC
        printf("d: ");
    #endif /* DEBUG */

    load_scanf("%d", &d);

    // ========================================================================
    // Block A
    // ========================================================================

    add(i,0,0);
    A1: if(compare(i,d,'l'))
    {
        add(j,0,0);
        A2: if(compare(j,d,'l'))
        {
            #ifdef DEBUG
                //Debug statements do not count towards ICi or IC
                printf("A[%d][%d]: ",i,j);
            #endif /* DEBUG */

            load_scanf("%d",&TMP0);
            store(A[i][j],TMP0);
            add(j,j,1);
            jump(A2);
        }
        add(i,i,1);
        jump(A1);
    }

    // ========================================================================
    // Block B
    // ========================================================================

    add(i,0,0);
    B1: if(compare(i,d,'l'))
    {
        add(j,0,0);
        B2: if(compare(j,d,'l'))
        {
            #ifdef DEBUG
                //Debug statements do not count towards ICi or IC
                printf("B[%d][%d]: ",i,j);
            #endif /* DEBUG */

            load_scanf("%d",&TMP0);
            store(B[i][j],TMP0);
            add(j,j,1);
            jump(B2);
        }
        add(i,i,1);
        jump(B1);
    }

    // ========================================================================
    // Block C
    // ========================================================================

    add(i,0,0);
    C1: mult(TMP0,d,d);
    if(compare(i,TMP0,'l'))
    {
        add(j,0,0);
        C2: mult(TMP1,d,d);
        if(compare(j,TMP1,'l'))
        {
            add(TMP2,0,0);
            store(M[i][j],TMP2)
            add(j,j,1);
            jump(C2);
        }
        add(i,i,1);
        jump(C1);
    }

    // ========================================================================
    // Block D
    // ========================================================================

    add(rowa,0,0);
    D1: if(compare(rowa,d,'l'))
    {
        add(colb,0,0);
        D2: if(compare(colb,d,'l'))
        {
            add(j,0,0);
            D3: if(compare(j,d,'l'))
            {
                load(TMP0, A[rowa][j]);
                if(compare(TMP0,0,'n'))
                {
                    mult(TMP1,rowa,d);
                    add(TMP1,TMP1,colb);
                    mult(TMP2,j,d);
                    add(TMP2,TMP2,colb);
                    load(TMP0,M[TMP1][TMP2]);

                    if(compare(TMP0,0,'n'))
                    {
                        add(TMP0,0,0);
                        store(M[TMP1][TMP2], TMP0);
                        jump(D4);
                    }
                    add(TMP0,0,1);
                    store(M[TMP1][TMP2], TMP0);
                }
                D4: add(j,j,1);
                jump(D3);
            }
            add(colb,colb,1);
            jump(D2);
        }
        add(rowa,rowa,1);
        jump(D1);
    }

    // ========================================================================
    // Block E
    // ========================================================================

    add(rowa,0,0);
    E1: if(compare(rowa,d,'l'))
    {
        add(colb,0,0);
        E2: if(compare(colb,d,'l'))
        {
            add(j,0,0);
            E3: if(compare(j,d,'l'))
            {
                load(TMP0, B[j][colb]);
                if(compare(TMP0,0,'n'))
                {
                    mult(TMP1,rowa,d);
                    add(TMP1,TMP1,colb);
                    mult(TMP2,rowa,d);
                    add(TMP2,TMP2,j);
                    load(TMP0,M[TMP1][TMP2]);

                    if(compare(TMP0,0,'n'))
                    {
                        add(TMP0,0,0);
                        store(M[TMP1][TMP2], TMP0);
                        jump(E4);
                    }
                    add(TMP0,0,1);
                    store(M[TMP1][TMP2], TMP0);
                }
                E4: add(j,j,1);
                jump(E3);
            }
            add(colb,colb,1);
            jump(E2);
        }
        add(rowa,rowa,1);
        jump(E1);
    }

    // ========================================================================
    // Block F
    // ========================================================================

    store_printfo("\n");
    add(i,0,0);
    F1: mult(TMP0,d,d);
    if(compare(i,TMP0,'l'))
    {
        add(j,0,0);
        F2: mult(TMP1,d,d);
        if(compare(j,TMP1,'l'))
        {
            load(TMP2,M[i][j])
            store_printft("%d ", &TMP2);
            add(j,j,1);
            jump(F2);
        }
        store_printfo("\n");
        add(i,i,1);
        jump(F1);
    }

    // ========================================================================
    // Print Report and Exit
    // ========================================================================

    print_counters(d);
    return 0;
}
