//MERIMI Mohammed
#include <stdio.h>
#include <mpi.h>
#include <math.h>

double calculerPi(float a,float b) {
        double x= 4*atan(a);
        double y= 4*atan(b);
        return (y-x);
}

int main (int argc, char* argv[]) {
        int n, id;
        float a,b;
        double pi,somme;
        MPI_Init(&argc, &argv);
        MPI_Comm_size(MPI_COMM_WORLD, &n);
        MPI_Comm_rank(MPI_COMM_WORLD, &id);
        a= id*(1.0/n);
        b= id*(1.0/n)+(1.0/n);
        pi=calculerPi(a,b);
        somme=pi;
        
if (id == 0) {
        printf("je suis processus master");
        double debut, fin;
        debut = MPI_Wtime();
        for(int i=1;i<n;i++) {
        MPI_Recv(&pi, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        somme=somme+pi;
        }
        printf("PI = %f\n",somme); 
        fin = MPI_Wtime();
        double m;
        m=fin-debut;
        printf ( "le temps est  = %f \n", m );  
        } 
        
else {
	    printf("je suis l'un des processus fils'");
        MPI_Send(&pi, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD); 
     }
        MPI_Finalize();
     }
