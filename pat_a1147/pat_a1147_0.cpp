#include <cstdio>
#include <cstdlib>
#include <list>
#include <vector>

using namespace std;

typedef struct Node *TREE;
typedef struct Node {
	int data;
	TREE l;
	TREE r;
}Node;

int M, N;
int sz[100010];
Node *T;
vector<int>v1;

int isHeap(TREE t) {
	if ((!t->l) && (!t->r)) {
		v1.push_back(t->data);
		return 3;
	}
	if (!t->r) {
		int f = isHeap(t->l);
		v1.push_back(t->data);
		return t->data > t->l->data ? 1 : 2;
	}
	if (t->data > t->l->data&&t->data > t->r->data) {
		int ll = isHeap(t->l);
		int rr = isHeap(t->r);
		v1.push_back(t->data);
		if (ll == 0 || rr == 0 || ll == 2 || rr == 2)return 0;
		return 1;
	}
	else if (t->data < t->l->data&&t->data < t->r->data) {
		int ll = isHeap(t->l);
		int rr = isHeap(t->r);
		v1.push_back(t->data);
		if (ll == 0 || rr == 0 || ll == 1 || rr == 1)return 0;
		return 2;
	}
	else {
		int ll = isHeap(t->l);
		int rr = isHeap(t->r);
		v1.push_back(t->data);
		return 0;
	}
}

void pf() {
	int n = v1.size();
	for (int i = 0; i < n; i++) {
		printf("%d%c", v1[i], i == n - 1 ? '\n' : ' ');
	}
}

void checkk() {
	v1.clear();
	int f = T->data > T->l->data ? 1 : 2;//0:Not Heap  1:Max Heap  2:Min Heap  3:All
	f = isHeap(T);
	if (f == 1) {
		printf("Max Heap\n");
	}
	else if (f == 2) {
		printf("Min Heap\n");
	}
	else {
		printf("Not Heap\n");
	}
	pf();
}

int main() {
	scanf("%d %d\n", &M, &N);
	for (int i = 0; i < M; i++) {
		int t;
		list<TREE>ls;
		TREE rot = NULL;
		for (int j = 0; j < N; j++) {
			scanf("%d", &t);
			TREE tt = (TREE)malloc(sizeof(Node));
			tt->data = t;
			tt->l = NULL;
			tt->r = NULL;
			ls.push_back(tt);
			if (!rot) {
				rot = tt;
			}
			else {
				if ((ls.front())->l) {
					(ls.front())->r = tt;
					ls.pop_front();
				}
				else {
					(ls.front())->l = tt;
				}
			}
		}
		T = rot;
		checkk();
	}
	return 0;
}
