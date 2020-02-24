/** @file 
 * A demo of QuEST
 *
 * @author Ania Brown
 * @author Tyson Jones
 */

#include <stdio.h>
#include "QuEST.h"

int main (int narg, char *varg[]) {



    /*
     * PREPARE QuEST environment
     * (Required only once per program)
     */

    QuESTEnv env = createQuESTEnv();

    printf("-------------------------------------------------------\n");
    printf("Running QuEST tutorial:\n\t Basic circuit involving a system of 3 qubits.\n");
    printf("-------------------------------------------------------\n");



    /*
     * PREPARE QUBIT SYSTEM
     */

    Qureg qubits = createQureg(24, env);
    initZeroState(qubits);



    /*
     * REPORT SYSTEM AND ENVIRONMENT
     */
    printf("\nThis is our environment:\n");
    reportQuregParams(qubits);
    reportQuESTEnv(env);



    /*
     * APPLY CIRCUIT
     */

    hadamard(qubits, 0);
    controlledNot(qubits, 0, 1);
    rotateY(qubits, 2, .1);

    int targs[] = {0,1,2};
    multiControlledPhaseFlip(qubits, targs, 3);

    ComplexMatrix2 u = {
        .real={{.5,.5},{.5,.5}},
        .imag={{.5,-.5},{-.5,.5}}
    };
    unitary(qubits, 0, u);

    Complex a, b;
    a.real = .5; a.imag =  .5;
    b.real = .5; b.imag = -.5;
    compactUnitary(qubits, 1, a, b);

    Vector v;
    v.x = 1; v.y = 0; v.z = 0;
    hadamard(qubits, 0);
    controlledRotateZ(qubits, 0, 1, 1.5708);
    hadamard(qubits, 1);
    controlledRotateZ(qubits, 0, 2, 0.785398);
    controlledRotateZ(qubits, 1, 2, 1.5708);
    hadamard(qubits, 2);
    controlledRotateZ(qubits, 0, 3, 0.392699);
    controlledRotateZ(qubits, 1, 3, 0.785398);
    controlledRotateZ(qubits, 2, 3, 1.5708);
    hadamard(qubits, 3);
    controlledRotateZ(qubits, 0, 4, 0.19635);
    controlledRotateZ(qubits, 1, 4, 0.392699);
    controlledRotateZ(qubits, 2, 4, 0.785398);
    controlledRotateZ(qubits, 3, 4, 1.5708);
    hadamard(qubits, 4);
    controlledRotateZ(qubits, 0, 5, 0.0981748);
    controlledRotateZ(qubits, 1, 5, 0.19635);
    controlledRotateZ(qubits, 2, 5, 0.392699);
    controlledRotateZ(qubits, 3, 5, 0.785398);
    controlledRotateZ(qubits, 4, 5, 1.5708);
    hadamard(qubits, 5);
    controlledRotateZ(qubits, 0, 6, 0.0490874);
    controlledRotateZ(qubits, 1, 6, 0.0981748);
    controlledRotateZ(qubits, 2, 6, 0.19635);
    controlledRotateZ(qubits, 3, 6, 0.392699);
    controlledRotateZ(qubits, 4, 6, 0.785398);
    controlledRotateZ(qubits, 5, 6, 1.5708);
    hadamard(qubits, 6);
    controlledRotateZ(qubits, 0, 7, 0.0245437);
    controlledRotateZ(qubits, 1, 7, 0.0490874);
    controlledRotateZ(qubits, 2, 7, 0.0981748);
    controlledRotateZ(qubits, 3, 7, 0.19635);
    controlledRotateZ(qubits, 4, 7, 0.392699);
    controlledRotateZ(qubits, 5, 7, 0.785398);
    controlledRotateZ(qubits, 6, 7, 1.5708);
    hadamard(qubits, 7);
    controlledRotateZ(qubits, 0, 8, 0.0122718);
    controlledRotateZ(qubits, 1, 8, 0.0245437);
    controlledRotateZ(qubits, 2, 8, 0.0490874);
    controlledRotateZ(qubits, 3, 8, 0.0981748);
    controlledRotateZ(qubits, 4, 8, 0.19635);
    controlledRotateZ(qubits, 5, 8, 0.392699);
    controlledRotateZ(qubits, 6, 8, 0.785398);
    controlledRotateZ(qubits, 7, 8, 1.5708);
    hadamard(qubits, 8);
    controlledRotateZ(qubits, 0, 9, 0.00613592);
    controlledRotateZ(qubits, 1, 9, 0.0122718);
    controlledRotateZ(qubits, 2, 9, 0.0245437);
    controlledRotateZ(qubits, 3, 9, 0.0490874);
    controlledRotateZ(qubits, 4, 9, 0.0981748);
    controlledRotateZ(qubits, 5, 9, 0.19635);
    controlledRotateZ(qubits, 6, 9, 0.392699);
    controlledRotateZ(qubits, 7, 9, 0.785398);
    controlledRotateZ(qubits, 8, 9, 1.5708);
    hadamard(qubits, 9);
    controlledRotateZ(qubits, 0, 10, 0.00306796);
    controlledRotateZ(qubits, 1, 10, 0.00613592);
    controlledRotateZ(qubits, 2, 10, 0.0122718);
    controlledRotateZ(qubits, 3, 10, 0.0245437);
    controlledRotateZ(qubits, 4, 10, 0.0490874);
    controlledRotateZ(qubits, 5, 10, 0.0981748);
    controlledRotateZ(qubits, 6, 10, 0.19635);
    controlledRotateZ(qubits, 7, 10, 0.392699);
    controlledRotateZ(qubits, 8, 10, 0.785398);
    controlledRotateZ(qubits, 9, 10, 1.5708);
    hadamard(qubits, 10);
    controlledRotateZ(qubits, 0, 11, 0.00153398);
    controlledRotateZ(qubits, 1, 11, 0.00306796);
    controlledRotateZ(qubits, 2, 11, 0.00613592);
    controlledRotateZ(qubits, 3, 11, 0.0122718);
    controlledRotateZ(qubits, 4, 11, 0.0245437);
    controlledRotateZ(qubits, 5, 11, 0.0490874);
    controlledRotateZ(qubits, 6, 11, 0.0981748);
    controlledRotateZ(qubits, 7, 11, 0.19635);
    controlledRotateZ(qubits, 8, 11, 0.392699);
    controlledRotateZ(qubits, 9, 11, 0.785398);
    controlledRotateZ(qubits, 10, 11, 1.5708);
    hadamard(qubits, 11);
    controlledRotateZ(qubits, 0, 12, 0.00076699);
    controlledRotateZ(qubits, 1, 12, 0.00153398);
    controlledRotateZ(qubits, 2, 12, 0.00306796);
    controlledRotateZ(qubits, 3, 12, 0.00613592);
    controlledRotateZ(qubits, 4, 12, 0.0122718);
    controlledRotateZ(qubits, 5, 12, 0.0245437);
    controlledRotateZ(qubits, 6, 12, 0.0490874);
    controlledRotateZ(qubits, 7, 12, 0.0981748);
    controlledRotateZ(qubits, 8, 12, 0.19635);
    controlledRotateZ(qubits, 9, 12, 0.392699);
    controlledRotateZ(qubits, 10, 12, 0.785398);
    controlledRotateZ(qubits, 11, 12, 1.5708);
    hadamard(qubits, 12);
    controlledRotateZ(qubits, 0, 13, 0.000383495);
    controlledRotateZ(qubits, 1, 13, 0.00076699);
    controlledRotateZ(qubits, 2, 13, 0.00153398);
    controlledRotateZ(qubits, 3, 13, 0.00306796);
    controlledRotateZ(qubits, 4, 13, 0.00613592);
    controlledRotateZ(qubits, 5, 13, 0.0122718);
    controlledRotateZ(qubits, 6, 13, 0.0245437);
    controlledRotateZ(qubits, 7, 13, 0.0490874);
    controlledRotateZ(qubits, 8, 13, 0.0981748);
    controlledRotateZ(qubits, 9, 13, 0.19635);
    controlledRotateZ(qubits, 10, 13, 0.392699);
    controlledRotateZ(qubits, 11, 13, 0.785398);
    controlledRotateZ(qubits, 12, 13, 1.5708);
    hadamard(qubits, 13);
    controlledRotateZ(qubits, 0, 14, 0.000191748);
    controlledRotateZ(qubits, 1, 14, 0.000383495);
    controlledRotateZ(qubits, 2, 14, 0.00076699);
    controlledRotateZ(qubits, 3, 14, 0.00153398);
    controlledRotateZ(qubits, 4, 14, 0.00306796);
    controlledRotateZ(qubits, 5, 14, 0.00613592);
    controlledRotateZ(qubits, 6, 14, 0.0122718);
    controlledRotateZ(qubits, 7, 14, 0.0245437);
    controlledRotateZ(qubits, 8, 14, 0.0490874);
    controlledRotateZ(qubits, 9, 14, 0.0981748);
    controlledRotateZ(qubits, 10, 14, 0.19635);
    controlledRotateZ(qubits, 11, 14, 0.392699);
    controlledRotateZ(qubits, 12, 14, 0.785398);
    controlledRotateZ(qubits, 13, 14, 1.5708);
    hadamard(qubits, 14);
    controlledRotateZ(qubits, 0, 15, 9.58738e-05);
    controlledRotateZ(qubits, 1, 15, 0.000191748);
    controlledRotateZ(qubits, 2, 15, 0.000383495);
    controlledRotateZ(qubits, 3, 15, 0.00076699);
    controlledRotateZ(qubits, 4, 15, 0.00153398);
    controlledRotateZ(qubits, 5, 15, 0.00306796);
    controlledRotateZ(qubits, 6, 15, 0.00613592);
    controlledRotateZ(qubits, 7, 15, 0.0122718);
    controlledRotateZ(qubits, 8, 15, 0.0245437);
    controlledRotateZ(qubits, 9, 15, 0.0490874);
    controlledRotateZ(qubits, 10, 15, 0.0981748);
    controlledRotateZ(qubits, 11, 15, 0.19635);
    controlledRotateZ(qubits, 12, 15, 0.392699);
    controlledRotateZ(qubits, 13, 15, 0.785398);
    controlledRotateZ(qubits, 14, 15, 1.5708);
    hadamard(qubits, 15);
    controlledRotateZ(qubits, 0, 16, 4.79369e-05);
    controlledRotateZ(qubits, 1, 16, 9.58738e-05);
    controlledRotateZ(qubits, 2, 16, 0.000191748);
    controlledRotateZ(qubits, 3, 16, 0.000383495);
    controlledRotateZ(qubits, 4, 16, 0.00076699);
    controlledRotateZ(qubits, 5, 16, 0.00153398);
    controlledRotateZ(qubits, 6, 16, 0.00306796);
    controlledRotateZ(qubits, 7, 16, 0.00613592);
    controlledRotateZ(qubits, 8, 16, 0.0122718);
    controlledRotateZ(qubits, 9, 16, 0.0245437);
    controlledRotateZ(qubits, 10, 16, 0.0490874);
    controlledRotateZ(qubits, 11, 16, 0.0981748);
    controlledRotateZ(qubits, 12, 16, 0.19635);
    controlledRotateZ(qubits, 13, 16, 0.392699);
    controlledRotateZ(qubits, 14, 16, 0.785398);
    controlledRotateZ(qubits, 15, 16, 1.5708);
    hadamard(qubits, 16);
    controlledRotateZ(qubits, 0, 17, 2.39684e-05);
    controlledRotateZ(qubits, 1, 17, 4.79369e-05);
    controlledRotateZ(qubits, 2, 17, 9.58738e-05);
    controlledRotateZ(qubits, 3, 17, 0.000191748);
    controlledRotateZ(qubits, 4, 17, 0.000383495);
    controlledRotateZ(qubits, 5, 17, 0.00076699);
    controlledRotateZ(qubits, 6, 17, 0.00153398);
    controlledRotateZ(qubits, 7, 17, 0.00306796);
    controlledRotateZ(qubits, 8, 17, 0.00613592);
    controlledRotateZ(qubits, 9, 17, 0.0122718);
    controlledRotateZ(qubits, 10, 17, 0.0245437);
    controlledRotateZ(qubits, 11, 17, 0.0490874);
    controlledRotateZ(qubits, 12, 17, 0.0981748);
    controlledRotateZ(qubits, 13, 17, 0.19635);
    controlledRotateZ(qubits, 14, 17, 0.392699);
    controlledRotateZ(qubits, 15, 17, 0.785398);
    controlledRotateZ(qubits, 16, 17, 1.5708);
    hadamard(qubits, 17);
    controlledRotateZ(qubits, 0, 18, 1.19842e-05);
    controlledRotateZ(qubits, 1, 18, 2.39684e-05);
    controlledRotateZ(qubits, 2, 18, 4.79369e-05);
    controlledRotateZ(qubits, 3, 18, 9.58738e-05);
    controlledRotateZ(qubits, 4, 18, 0.000191748);
    controlledRotateZ(qubits, 5, 18, 0.000383495);
    controlledRotateZ(qubits, 6, 18, 0.00076699);
    controlledRotateZ(qubits, 7, 18, 0.00153398);
    controlledRotateZ(qubits, 8, 18, 0.00306796);
    controlledRotateZ(qubits, 9, 18, 0.00613592);
    controlledRotateZ(qubits, 10, 18, 0.0122718);
    controlledRotateZ(qubits, 11, 18, 0.0245437);
    controlledRotateZ(qubits, 12, 18, 0.0490874);
    controlledRotateZ(qubits, 13, 18, 0.0981748);
    controlledRotateZ(qubits, 14, 18, 0.19635);
    controlledRotateZ(qubits, 15, 18, 0.392699);
    controlledRotateZ(qubits, 16, 18, 0.785398);
    controlledRotateZ(qubits, 17, 18, 1.5708);

    controlledCompactUnitary(qubits, 0, 1, a, b);

    int ctrls[] = {0,1};
    multiControlledUnitary(qubits, ctrls, 2, 2, u);
    
    ComplexMatrixN toff = createComplexMatrixN(3);
    toff.real[6][7] = 1;
    toff.real[7][6] = 1;
    for (int i=0; i<6; i++)
        toff.real[i][i] = 1;
    multiQubitUnitary(qubits, targs, 3, toff);
    
    
    
    /*
     * STUDY QUANTUM STATE
     */

    printf("\nCircuit output:\n");


    for(int i=0; i<10; ++i){
    Complex amp = getAmp(qubits, i);
        //printf("Amplitude of %dth state vector: %f\n", i, prob);
	printf("Amplitude of %dth state vector: %12.6f,%12.6f\n", i, amp.real, amp.imag);
    }

    qreal prob;
    prob = getProbAmp(qubits, 7);
    printf("Probability amplitude of |111>: %f\n", prob);

    prob = calcProbOfOutcome(qubits, 2, 1);
    printf("Probability of qubit 2 being in state 1: %f\n", prob);

    int outcome = measure(qubits, 0);
    printf("Qubit 0 was measured in state %d\n", outcome);

    outcome = measureWithStats(qubits, 2, &prob);
    printf("Qubit 2 collapsed to %d with probability %f\n", outcome, prob);



    /*
     * FREE MEMORY
     */

    destroyQureg(qubits, env); 
    destroyComplexMatrixN(toff);



    /*
     * CLOSE QUEST ENVIRONMET
     * (Required once at end of program)
     */
    destroyQuESTEnv(env);
    return 0;
}
