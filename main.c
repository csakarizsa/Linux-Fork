#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {

//    printf ("Hello main.c-bÅ‘l. \n");
//    printf("A program ezzel lett meghÃ­vva: \"%s\".\n",argv[0]);
//    printf("ParamÃ©terek [argc] szÃ¡ma: %d \n",argc-1);

    int count, N;

    if (argc > 1) {
//	for (count = 1; count < argc; count++)
//	    printf ("ParamÃ©ter[%d] = %s\n",count,argv[count]);
	N = atoi(argv[1]);
	if (N < 1) {
	    fprintf (stderr,"Hiba: A paramÃ©ter kisebb, mint 1.\n");
	    return -1;
	}
    } else {
	fprintf(stderr,"Hiba: Nincs paramÃ©ter.\n");
	return -1;
    }
    
    float *A = malloc (N * sizeof(float));
    float *B = malloc (N * sizeof(float));
    
    int i;
    for (i = 0; i < N; i++) {
//	printf ("Add meg az A tÃ¶mb %i. elemÃ©t:\n",i);
	scanf ("%f", &A[i]);
    }

    for (i = 0; i < N; i++) {
//	printf ("Add meg a B tÃ¶mb %i. elemÃ©t:\n",i);
	scanf ("%f", &B[i]);
    }
    
//    for (i = 0; i < N; i++) { printf ("%f %f \n", A[i], B[i]); }
    
    pid_t pid;
    sleep (2);
    
    for (i=0; i<N && fork()>0; i++);
    
    if (i == N) {
//	printf ("SzÃ¼lÅ‘ pid: %i, cpid: %i\n",getpid(),pid);
	sleep(2);
    } else {
//	printf ("%d. Gyermek pid: %i, ppid: %i\n",i+1,getpid(),getppid());
	printf ("%d:%f \n",i+1,A[i]*B[i]);
	sleep(1);
    }
//    printf ("Program vÃ©ge.\n");
    free(A); free(B);
    return 0;
}
