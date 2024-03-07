#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void getDataf(int *dim, float ***A, float **b, float **x, int **p);
void displayResult(float *x, int dim, float *b, float **A, int *p);
void gauss(float **A, float *b, float *x, int *p, int dim);
void cleanup(float *b, float *x, float **A, int dim);
int main(){
	printf("Résolution de A.x=b par meth de Gauss\n");
	
///Entrer de données
	int dim=1;
	float **A=NULL;
	float *b=NULL;
	float *x=NULL;
	int *p=NULL;
	getDataf(&dim, &A, &b, &x, &p);		//donner l'addresse de x (créer)

///Calcul: methode de Gauss
	gauss(A, b, x, p, dim);			//s'addresse aux addresse dans getData
	
///Sorties de résultat
	displayResult(x, dim, b, A, p);

///Nettoyage
	cleanup(b, x, A, dim);
	
	return 0;
}

void gauss(float **A, float *b, float *x, int *p, int dim){
	printf("Methode de Gauss effectuer\n");
///Triangularisation de la matrice
	float piv=0;

	for(int k=0; k<dim-1; k++){
///Recherche de la ligne de plus  grand pivot
		int lpiv=0;
		
		
		for(int i=k; i<dim; i++){
			if(fabs(piv)<fabs(A[p[i]][k])){
				lpiv=i;
				piv=fabs(A[p[k]][k]);
///Inerversion de la ligne
				int t=p[k];
				p[k]=p[lpiv];
				p[lpiv]=t;
			}
		}
///Elimination
		for(int i=k+1; i<dim; i++){
			for(int j=k+1; j<dim; j++){
				A[p[i]][j]-=A[p[i]][k]/A[p[k]][k]*A[p[k]][j];
			}
			b[p[i]]-=A[p[i]][k]/A[p[k]][k]*b[p[k]];
			A[p[i]][k]=0;
		}
	}
///Résolution du système triangulaire
	float s=0;
	
	for(int i=dim-1; i>=0; i--){
		s=0;
		for(int j=i+1; j<dim; j++){
			s+=A[p[i]][j]*x[j];
		}
		x[i]=(b[p[i]]-s)/A[p[i]][i];
	}
}

void getDataf(int *dim, float ***A, float **b, float **x, int **p){
	printf("Voici les données\n");
	float *v=NULL,					//local à getData
			*s=NULL,
			**M=NULL;
	int *pt=NULL;					//pour le pointeur de ligne
	FILE *pf=NULL;
	
	pf=fopen("data0.txt", "r");
	if(pf==NULL){
		cleanup(*b, *x, *A, *dim);
		exit(1);
	}
	fscanf(pf , "%d", dim);
	
	M=(float**)malloc(*dim*sizeof(float*));
	for(int i=0; i<*dim; i++){
		M[i]=NULL;
		M[i]=malloc(*dim*sizeof(float));
		if(M==NULL){cleanup(*b, *x, *A, *dim);exit(1);}
	}
	for(int i=0; i<*dim; i++){
		for(int j=0; j<*dim; j++)
			fscanf(pf ,"%f", &M[i][j]);
	}
	v=malloc(*dim*sizeof(float));
	if(v==NULL){cleanup(*b, *x, *A, *dim);exit(1);}
	
	s=malloc(*dim*sizeof(float));
	if(s==NULL){cleanup(*b, *x, *A, *dim);exit(1);}
	for(int i=0; i<*dim; i++) fscanf(pf, "%f", &s[i]);
	
	pt=malloc(*dim*sizeof(int));
	if(pt==NULL){cleanup(*b, *x, *A, *dim);exit(1);}
	for(int i=0; i<*dim; i++)pt[i]=i;
	
	*x=v;							//passer le tableau à main
	*b=s;
	*A=M;
	*p=pt;
}

void cleanup(float *b, float *x, float **A, int dim){
	if(x!=NULL){
		printf("Je libere x\n");
		free(x);
	}
	if(b!=NULL){
		printf("je libere b\n");
		free(b);
	}
	if(A!=NULL){
		printf("je libere A\n");
		for(int i=0; i<dim; i++)free(A[i]);
		free(A);
	}
}


void displayResult(float *x, int dim, float *b, float **A, int *p){
	printf("DIM = %d\n", dim);
	printf("\nVoici le system triangulaire\n");
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++) printf("%g\t", A[p[i]][j]);
		printf("\n");
	}
	printf("\nVoici le second membre\n");
	for(int i=0; i<dim; i++) printf("b[%d]=%g\n", i, b[p[i]]);
	printf("\nVoici la solution\n");
	for(int i=0; i<dim; i++) printf("x[%d]=%g\n", i, x[i]);
	
	
}
