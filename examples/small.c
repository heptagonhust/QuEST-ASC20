#include "QuEST.h"
#include "stdio.h"
#include "mytimer.hpp"
#include "tool.h"

#define BIT_CNT 10

const double QFT_datas[] = {
    1.17033e-08,
    2.34067e-08,
    4.68134e-08,
    9.36268e-08,
    1.87254e-07,
    3.74507e-07,
    7.49014e-07,
    1.49803e-06,
    2.99606e-06,
    5.99211e-06,
    1.19842e-05,
    2.39684e-05,
    4.79369e-05,
    9.58738e-05,
    0.000191748,
    0.000383495,
    0.00076699,
    0.00153398,
    0.00306796,
    0.00613592,
    0.0122718,
    0.0245437,
    0.0490874,
    0.0981748,
    0.19635,
    0.392699,
    0.785398,
    1.5708,
};

int main (int narg, char *argv[]) {

    char probs_fname[256];
    char stateVector_fname[256];
    const char *dir = getOutputDir(narg, argv);
    if(filenameWithTime(probs_fname, sizeof(probs_fname), dir, "probs_GHZ_QFT_", ".dat") == NULL) {
        fprintf(stderr, "output probs_fname is too long\n");
        return 1;
    }
    if(filenameWithTime(stateVector_fname, sizeof(stateVector_fname), dir, "stateVector_GHZ_QFT_", ".dat") == NULL ){
        fprintf(stderr, "output stateVector_fname is too long\n");
        return 1;
    }

    QuESTEnv Env = createQuESTEnv();
    double t1 = get_wall_time();

    FILE *fp=fopen(probs_fname, "w");
    if(fp==NULL){
        printf("    open  %s failed, Bye!", probs_fname);
        return 0;
    }

    FILE *fvec=fopen(stateVector_fname, "w");
    if(fp==NULL){
        printf("    open %s failed, Bye!", stateVector_fname);
        return 0;
    }

    Qureg q = createQureg(BIT_CNT, Env);

    float q_measure[BIT_CNT];
    int c[BIT_CNT];
    for (int i = 0; i < BIT_CNT; i++)
        c[i] = 0;

	/* GHZ quantum circuit */
    // hadamard(q, 0);
    for (int i = 0; i < BIT_CNT-1; i++) {
        controlledNot(q, i, i+1);
    }
	/* end of GHZ circuit */

	/* QFT starts */
    // hadamard(q, 0);
    for (int i = 1; i < BIT_CNT-1; i++) {
        int start = BIT_CNT - 2 - i;
        for (int j = 0; j < i; j++) {
            controlledRotateZ(q, j, i, QFT_datas[j+start]);
        }
        hadamard(q, i);
    }
	/* end of QFT circuit */

    printf("\n");
    for(long long int i=0; i<BIT_CNT; ++i){
        q_measure[i] = calcProbOfOutcome(q,  i, 1);
        printf("  probability for q[%2lld]==1 : %lf    \n", i, q_measure[i]);
        fprintf(fp, "Probability for q[%2lld]==1 : %lf    \n", i, q_measure[i]);
    }
    fprintf(fp, "\n");
    printf("\n");

    int printNum = BIT_CNT < 10 ? BIT_CNT : 10;
    for(int i=0; i<printNum; ++i){
        Complex amp = getAmp(q, i);
        printf("Amplitude of %dth state vector: %12.6f,%12.6f\n", i, amp.real, amp.imag);
    	fprintf(fvec, "Amplitude of %dth state vector: %12.6f,%12.6f\n", i, amp.real, amp.imag);
    }

    double t2 = get_wall_time();
    printf("Complete the simulation takes time %12.6f seconds.", t2 - t1);
    printf("\n");
    destroyQureg(q, Env);
    destroyQuESTEnv(Env);

    return 0;
}