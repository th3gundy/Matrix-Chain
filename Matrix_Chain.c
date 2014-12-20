#include <stdio.h>
#include <limits.h>

int **memoryAllocate(int size){ // matris i�in memory allocation yapan fonksiyon
    int **tmp, i;

    if ( NULL == ( tmp = (int**)malloc((size+1) * sizeof(int*)) ) ){
        printf("Malloc failed!\n");
        exit(0);
    }

    for(i = 0; i < size+1; i++){
        tmp[i] = (int*)malloc((size+1) * sizeof(int));
        if ( tmp[i] == NULL ){
            printf("Malloc failed!\n");
            exit(0);
        }
    }
    return tmp;
}

void printParenthes(int **solution, int i, int j){ // solution dizisinin i�eri�ine g�re matris �arp�m s�ras�n� yazd�ran fonk.

    if (i == j){
		printf("A%d",i);
    }
    else {
        printf("(");
        printParenthes(solution, i, solution[i][j]);
        printf("x");
		printParenthes(solution, solution[i][j]+1, j);
		printf(")");
    }
}

void matrixChainOrder(int p[], int n){
	int **costs,**solution; // dynamic programlamada kullan�lacak olan matrisler
	int i,j,k,l,q;

    costs = memoryAllocate(n+1);
    solution  = memoryAllocate(n);

	for(i=1;i<=n;i++)
		costs[i][i] = 0;
    // matrix chain order algoritmas�na uygun yaz�lan kodlar
	for(l=2;l<=n;l++){
		for(i=1;i<=(n-l+1);i++){
			j= i + l - 1;
			costs[i][j] = INT_MAX;
			for(k=i;k<=(j-1);k++){
				q = costs[i][k] + costs[k+1][j] + p[i-1]*p[k]*p[j];
				if(q < costs[i][j]){
					costs[i][j] = q;
					solution[i][j] = k;
				}
			}
		}
	}

	printf("\nMinimum multiplication cost: %d",costs[1][n]);
    printf("\n\ncost array \n\n");
	for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d\t",costs[i][j]);
        printf("\n");
	}
    printf("\nsolution array \n\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d ",solution[i][j]);
        printf("\n");
	}
	printf("\n");
	printf("Optimal Parenthesization:\n");
	printParenthes(solution, 1, n);
}

void inputAndEdit(){
	int i,size;
    int matrix[2][10]; //kullan�c�n�n girece�i matris boyutlar�
    int *sequence; // matrixChainOrder fonksiyonuna g�nderilecek olan matrislerin boyutlar�n�n d�zenlece�i dizi

    printf("Matris sayisini giriniz : ");
    scanf("%d",&size);

    for(i=0;i<size;i++){
        printf("%d. matrisin\n",i+1);
        printf("\tsatir sayisi : "); scanf("%d",&matrix[0][i]);
        printf("\tsutun sayisi : "); scanf("%d",&matrix[1][i]);
    }
    if ( NULL == (sequence = malloc((size+1)*sizeof(int))) ) {
        printf("Malloc failed!\n");
        exit(0);
    }
    // kullan�c�dan al�nan input do�rultusunda memory allocation yap�l�yor.
    sequence[0] = matrix[0][0];
    for(i=1;i<size;i++){
        sequence[i] = matrix[0][i]; // fonksiyona g�nderilecek sequence dizisi d�zenleniyor
    }
    sequence[size] = matrix[1][size-1];

	matrixChainOrder(sequence,size); // hesaplama ve s�ralama i�ini yapacak olan fonksiyon
}

int main(){
	printf("*** Optimal Matrix Chain Multiplication ***\n\n");
	inputAndEdit(); //kullan�c�dan matris bilgilerini al�p d�zenleyen fonksiyon
	return 0;
}
