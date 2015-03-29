#include <stdio.h>
#define DEG 20

int main()
{
    int d, A[DEG][DEG], B[DEG][DEG], M[DEG*DEG][DEG*DEG];
    int i, j, rowa, colb;

    scanf("%d", &d);

    for(i=0; i<d; i++)
        for(j=0; j<d; j++)
            scanf("%d", &A[i][j]);

    for(i=0; i<d; i++)
        for(j=0; j<d; j++)
            scanf("%d", &B[i][j]);

    for(i=0; i<d*d; i++)
        for(j=0; j<d*d; j++)
            M[i][j] = 0;

    for(rowa=0; rowa<d; rowa++)
        for(colb=0; colb<d; colb++)
            for(j=0; j<d; j++)
                if(A[rowa][j])
                {
                    if(M[rowa*d+colb][j*d+colb])
                    {
                        M[rowa*d+colb][j*d+colb] = 0;
                    }
                    else
                    {
                        M[rowa*d+colb][j*d+colb]=1;
                    }
                }

    for(rowa=0; rowa<d; rowa++)
        for(colb=0; colb<d; colb++)
            for(j=0; j<d; j++)
                if(B[j][colb])
                {
                    if(M[rowa*d+colb][rowa*d+j])
                    {
                        M[rowa*d+colb][rowa*d+j] = 0;
                    }
                    else
                    {
                        M[rowa*d+colb][rowa*d+j]=1;
                    }
                }

    printf("\n");
    for(i=0; i<d*d; i++)
    {
        for(j=0; j<d*d; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}
