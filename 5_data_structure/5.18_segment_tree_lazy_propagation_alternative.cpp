#include <bits/stdc++.h>

#define MAX_SIZE (1 << 20)
#define INF 0x3f3f3f3f // constante para indicar que nao há lazy
#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)

int n; // numero de elementos do array
int myArray[MAX_SIZE]; // array que armazena os elementos
int segmentTree[MAX_SIZE]; // array para armazenar a segment tree
int lazy[MAX_SIZE]; // array para armazenar a lazy

using namespace std;

int buildRec(int i, int j, int p) {
	if(i == j) {
		segmentTree[p] = myArray[i];
	} else {
		int rLeft = buildRec(i, (i+j)/2, left(p));
		int rRight = buildRec((i+j)/2+1, j, right(p));
		segmentTree[p] = rLeft + rRight;
	}
	lazy[p] = INF;
	return segmentTree[p];
}

void build() {
	buildRec(0,n-1,1);
}

void propagate(int i, int j, int p) {
	if(lazy[p] != INF) {
		if(i != j) {
			lazy[left(p)] = lazy[p];
			segmentTree[left(p)] += (((i+j)/2) - i + 1) * lazy[p];

			lazy[right(p)] = lazy[p];
			segmentTree[right(p)] += (j - ((i+j)/2 + 1) + 1) * lazy[p];
		}

		lazy[p] = INF;
	}
}

int queryRec(int i, int j, int &l, int &r, int p) {
	if(j < l || i > r) { // totalmente fora
		return 0;
	} else if(j <= r && i >= l) { // totalmente dentro
		return segmentTree[p];
	} else { // parcialmente dentro
		propagate(i, j, p);
		int sumLeft = queryRec(i, (i+j)/2, l, r, left(p));
		int sumRight = queryRec((i+j)/2+1, j, l, r, right(p));
		return sumLeft + sumRight;
	}
}

int query(int l, int r) {
	return queryRec(0, n-1, l, r, 1);
}

void updateRec(int i, int j, int &pos, int p) {
	propagate(i, j, p);
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

int incrementIntervalRec(int i, int j, int &l, int &r, int &inc, int p) {
	if(j < l || i > r) { // totalmente fora
		return segmentTree[p];
	} else if(j <= r && i >= l) { // totalmente dentro
		propagate(i, j, p);
		segmentTree[p] += (j-i+1) * inc;
		lazy[p] = inc;
		return segmentTree[p];
	} else { // parcialmente dentro
		propagate(i, j, p);
		int sumLeft = incrementIntervalRec(i, (i+j)/2, l, r, inc, left(p));
		int sumRight = incrementIntervalRec((i+j)/2 + 1, j, l, r, inc, right(p));
		segmentTree[p] = sumLeft + sumRight;
		return segmentTree[p];
	}
}

void incrementInterval(int l, int r, int inc) {
	incrementIntervalRec(0, n-1, l, r, inc, 1);
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

		for(int c=0; c<10; c++) {
			int pos = rand() % n;
			int value = rand() % 100;
			update(pos, value);
			testQueryFull();
		}

		for(int c=0; c<10; c++) {
			int l = rand() % n;
			int r = rand() % n;
			
			if(l > r) {
				swap(l,r);
			}

			int inc = rand() % 10;

			incrementInterval(l, r, inc);

			for(int i=l; i<=r; i++) {
				myArray[i] += inc;
			}

			testQueryFull();

			for(int d=0; d<10; d++) {
				int pos = rand() % n;
				int value = rand() % 100;
				update(pos, value);
				testQueryFull();
			}
		}

		printf("OK!\n");
	}
}

int main() {
	test();
	
	printf("All tests passed!\n");

	return 0;
}