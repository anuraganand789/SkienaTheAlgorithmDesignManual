#include "util.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct item_type {
  int age;
} item_type;

typedef struct tree {
  item_type item;
  struct tree *parent;
  struct tree *left;
  struct tree *right;
} tree;

tree *search(tree *root, const int age) {
  if (root == NULL)
    return NULL;

  const int curr_age = root->item.age;
  if (curr_age == age)
    return root;

  return curr_age > age ? search(root->right, age) : search(root->left, age);
}

tree *find_minimum(tree *root) {
	if(root == NULL) NULL;
	return (root->left == NULL) ? root : find_minimum(root->left);
	
}

void in_order(tree *root) {
	if(root == NULL) return;
	in_order(root->left);
	//Print Data
	printf("%d", root->item.age);
	in_order(root->right);
}

void pre_order(tree *root) {
	if(root == NULL) return;
	//Print Data
	printf("%d", root->item.age);
	in_order(root->left);
	in_order(root->right);
}
void post_order(tree *root) {
	if(root == NULL) return;
	in_order(root->left);
	in_order(root->right);
	//Print Data
	printf("%d", root->item.age);
}

tree *insert(tree *root, item_type item) {
	if(root == NULL) {
		tree *new_node;
		new_node = malloc(sizeof(tree));
		new_node->item = item;
		new_node->left = new_node->right = NULL;
		return new_node;
	}

	if(root->item.age > item.age) {
		root->left = insert(root->left, item);
		return root;
	} 

	root->right = insert(root->right, item);
	return root;
}

tree *delete(tree *root){
  if(root == NULL) return NULL;
  //Delete Leaf Node, free the memory and just return the null 
  if(root->left == NULL && root->right == NULL) {
    free(root);
    return NULL;
  }
  //Having one child
  if(root->right || root->left) {
    tree *temp = root;
    root = root->right ? root->right : root->left;
    temp->left = temp->right = NULL;
    free(temp);
    return root;
  }
  //Having two child
  //Find the leftmost child in the right tree
  tree *successor = root;
  //Find successor
  while(successor->left) successor = successor->left;
  root->item_type = successor->item_type;
  root->right = rightdelete(successor);
  return root;
  
}

void main() { 
	//printf(""); 
}
 
