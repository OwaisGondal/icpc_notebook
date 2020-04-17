#include <bits/stdc++.h>

#define MAX_SIZE (1 << 20)
#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)

int n; // numero de elementos do array
int myArray[MAX_SIZE]; // array que armazena os elementos
int segmentTree[MAX_SIZE]; // array para armazenar a segment tree

using namespace std;

int buildRec(int i, int j, int p) {
	if(i == j) {
		segmentTree[p] = myArray[i];
	} else {
		int rLeft = buildRec(i, (i+j)/2, left(p));
		int rRight = buildRec((i+j)/2+1, j, right(p));
		segmentTree[p] = rLeft + rRight;
	}
	return segmentTree[p];
}

void build() {
	buildRec(0,n-1,1);
}

int queryRec(int i, int j, int &l, int &r, int p) {
	if(j < l || i > r) { // totalmente fora
		return 0;
	} else if(j <= r && i >= l) { // totalmente dentro
		return segmentTree[p];
	} else { // parcialmente dentro
		int sumLeft = queryRec(i, (i+j)/2, l, r, left(p));
		int sumRight = queryRec((i+j)/2+1, j, l, r, right(p));
		return sumLeft + sumRight;
	}
}

int query(int l, int r) {
	return queryRec(0, n-1, l, r, 1);
}

void updateRec(int i, int j, int &pos, int p) {
	if(i == j) { // chegou em uma folha
		if(i == pos) { // eh a folha a ser atualizada
			segmentTree[p] = myArray[pos];
		}
		return ;
	} else if(pos <= (i+j)/2) { // caminha para esquerda
		updateRec(i, (i+j)/2, pos, left(p));
	} else { // caminha para direita
		updateRec((i+j)/2+1, j, pos, right(p));
	}
	segmentTree[p] = segmentTree[left(p)] + segmentTree[right(p)];
}

void update(int pos, int v) {
	myArray[pos] = v;
	updateRec(0, n-1, pos, 1);
}

void testQueryFull() {
	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			int verification = 0;
			for(int k=i; k<=j; k++) {
				verification += myArray[k];
			}
			assert(verification == query(i,j));
		}
	}
}

int test() {
	/* initialize random seed: */
  	srand (time(NULL));

	for(n=1; n<=64; n++) {
		printf("testing for n = %d... ",n);
		for(int i=0; i<n; i++) {
			myArray[i] = rand() % 100;
		}
		
		build();

		testQueryFull();

		for(int c=0; c<100; c++) {
			int pos = rand() % n;
			int value = rand() % 100;
			update(pos, value);
			testQueryFull();
		}

		printf("OK!\n");
	}
}

int main() {
	test();
	
	printf("All tests passed!\n");

	return 0;
}