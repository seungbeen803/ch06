#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* llink;
	char data;
	struct node* rlink;
};

struct node* createNode(char data) {
	struct node* p = (struct node*)malloc(sizeof(struct node));

	p->llink = NULL;
	p->data = data;
	p->rlink = NULL;
	return p;
}

void delete(struct node* p) {
	if (p != NULL) {
		delete(p->llink);
		delete(p->rlink);
		free(p);
	}
}

void preOrder(struct node* p) {
	if (p != NULL) {
		printf("%c  ", p->data);
		preOrder(p->llink);
		preOrder(p->rlink);
	}
}

void inOrder(struct node* p) {
	if (p != NULL) {
		inOrder(p->llink);
		printf("%c  ", p->data);
		inOrder(p->rlink);
	}
}

void postOrder(struct node* p) {
	if (p != NULL) {
		postOrder(p->llink);
		postOrder(p->rlink);
		printf("%c  ", p->data);
	}
}

int main(void)
{
	struct node* root = createNode('A');
	root->llink = createNode('B');
	root->rlink = createNode('C');
	root->llink->llink = createNode('D');
	root->llink->rlink = createNode('E');
	root->rlink->llink = createNode('F');
	root->rlink->rlink = createNode('G');
	root->llink->rlink->llink = createNode('H');
	root->llink->rlink->rlink = createNode('I');
	root->rlink->rlink->llink = createNode('J');
	root->rlink->rlink->rlink = createNode('K');
	root->llink->rlink->llink->rlink = createNode('L');
	printf("傈困 款青 : ");
	preOrder(root);printf("\n");
	printf("吝困 款青 : "); inOrder(root); printf("\n");
	printf("饶困 款青 : "); postOrder(root); printf("\n");
	return 0;
}