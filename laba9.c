#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "abiturient.h"
#include "generator.h"

typedef struct BTNode {
    Abiturient data;
    struct BTNode *left, *right;
} BTNode;

typedef struct RBNode {
    Abiturient data;
    char color; // 'R' - красный, 'B' - черный
    struct RBNode *left, *right, *parent;
} RBNode;

// Функции линейного поиска
void add_to_array(Abiturient *array, int *size, Abiturient elem) {
    array[*size] = elem;
    (*size)++;
}

int linear_search(Abiturient *array, int size, char *key) {
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i].name, key) == 0) {
            return i;
        }
    }
    return -1;
}

// Функции бинарного дерева
BTNode* create_bt_node(Abiturient data) {
    BTNode *node = (BTNode*)malloc(sizeof(BTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void bt_insert(BTNode **root, Abiturient data) {
    if (*root == NULL) {
        *root = create_bt_node(data);
        return;
    }

    if (strcmp(data.name, (*root)->data.name) < 0) {
        bt_insert(&(*root)->left, data);
    } else {
        bt_insert(&(*root)->right, data);
    }
}

BTNode* bt_search(BTNode *root, char *key) {
    if (root == NULL) return NULL;

    int cmp = strcmp(key, root->data.name);
    if (cmp == 0) return root;

    if (cmp < 0) {
        return bt_search(root->left, key);
    } else {
        return bt_search(root->right, key);
    }
}

void free_bst(BTNode *root) {
    if (root == NULL) return;
    free_bst(root->left);
    free_bst(root->right);
    free(root);
}

// Функции для красно-черного дерева
RBNode* create_rb_node(Abiturient data) {
    RBNode *node = (RBNode*)malloc(sizeof(RBNode));
    node->data = data;
    node->color = 'R';
    node->left = node->right = node->parent = NULL;
    return node;
}

void left_rotate(RBNode **root, RBNode *x) {
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void right_rotate(RBNode **root, RBNode *y) {
    RBNode *x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void rb_insert_fixup(RBNode **root, RBNode *z) {
    while (z->parent != NULL && z->parent->color == 'R') {
        if (z->parent == z->parent->parent->left) {
            RBNode *y = z->parent->parent->right;
            if (y != NULL && y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    left_rotate(root, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                right_rotate(root, z->parent->parent);
            }
        } else {
            RBNode *y = z->parent->parent->left;
            if (y != NULL && y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    right_rotate(root, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                left_rotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = 'B';
}

void rb_insert(RBNode **root, Abiturient data) {
    RBNode *z = create_rb_node(data);
    RBNode *y = NULL;
    RBNode *x = *root;

    while (x != NULL) {
        y = x;
        if (strcmp(z->data.name, x->data.name) < 0) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NULL) {
        *root = z;
    } else if (strcmp(z->data.name, y->data.name) < 0) {
        y->left = z;
    } else {
        y->right = z;
    }

    rb_insert_fixup(root, z);
}

RBNode* rb_search(RBNode *root, char *key) {
    if (root == NULL) return NULL;

    int cmp = strcmp(key, root->data.name);
    if (cmp == 0) return root;

    if (cmp < 0) {
        return rb_search(root->left, key);
    } else {
        return rb_search(root->right, key);
    }
}

void free_rbt(RBNode *root) {
    if (root == NULL) return;
    free_rbt(root->left);
    free_rbt(root->right);
    free(root);
}

void test_search_algorithms(int data_size) {
    Abiturient *array = (Abiturient*)malloc(data_size * sizeof(Abiturient));
    BTNode *bst_root = NULL;
    RBNode *rbt_root = NULL;
    int actual_size = 0;

    for (int i = 0; i < data_size; i++) {
        Abiturient a = generate_abiturient(false);
        add_to_array(array, &actual_size, a);
        bt_insert(&bst_root, a);
        rb_insert(&rbt_root, a);
    }

    char search_key[MAX_NAME_LENGTH];
    strcpy(search_key, array[rand() % actual_size].name);
    printf("Generated data size: %d\n", actual_size);
    printf("Suggested search key: %s\n", search_key);
    printf("Do you want to use this key? ('1' - yes/'0' - no): ");

    int choice;
    scanf(" %d", &choice);
    if (choice == 0) {
        printf("Enter your search key (full name): ");
        getchar();
        fgets(search_key, MAX_NAME_LENGTH, stdin);
        search_key[strcspn(search_key, "\n")] = '\0';
    }

    clock_t start = clock();
    int linear_result = linear_search(array, actual_size, search_key);
    clock_t linear_time = clock() - start;

    start = clock();
    BTNode *bt_result = bt_search(bst_root, search_key);
    clock_t bst_time = clock() - start;

    start = clock();
    RBNode *rbt_result = rb_search(rbt_root, search_key);
    clock_t rbt_time = clock() - start;

    printf("\nSearch results for key: %s\n", search_key);
    printf("Linear search: time = %f ms, result = %s\n",
           (double)linear_time * 1000 / CLOCKS_PER_SEC,
           linear_result != -1 ? "FOUND" : "NOT FOUND");
    printf("BST search: time = %f ms, result = %s\n",
           (double)bst_time * 1000 / CLOCKS_PER_SEC,
           bt_result != NULL ? "FOUND" : "NOT FOUND");
    printf("RBT search: time = %f ms, result = %s\n",
           (double)rbt_time * 1000 / CLOCKS_PER_SEC,
           rbt_result != NULL ? "FOUND" : "NOT FOUND");
    printf("\n");

    free(array);
    free_bst(bst_root);
    free_rbt(rbt_root);
}

int main() {
    srand(time(NULL));

    int option;
    do {
        printf("\nMenu:\n");
        printf("1. Test with data size 100\n");
        printf("2. Test with data size 1,000\n");
        printf("3. Test with data size 10,000\n");
        printf("4. Test with data size 50,000\n");
        printf("5. Test with data size 100,000\n");
        printf("6. Test with data size 200,000\n");
        printf("7. Test with data size 300,000\n");
        printf("8. Run all tests sequentially\n");
        printf("9. Generate and print sample data\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: test_search_algorithms(100); break;
            case 2: test_search_algorithms(1000); break;
            case 3: test_search_algorithms(10000); break;
            case 4: test_search_algorithms(50000); break;
            case 5: test_search_algorithms(100000); break;
            case 6: test_search_algorithms(200000); break;
            case 7: test_search_algorithms(300000); break;
            case 8:
                test_search_algorithms(100);
                test_search_algorithms(1000);
                test_search_algorithms(10000);
                test_search_algorithms(50000);
                test_search_algorithms(100000);
                test_search_algorithms(200000);
                test_search_algorithms(300000);
                break;
            case 9:
                printf("\nSample data:\n");
                printf("%-50s %-20s %-5s %-5s %s\n",
                       "Name", "Speciality", "Score", "Rank", "Original");
                for (int i = 0; i < 5; i++) {
                    generate_abiturient(true);
                }
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default: printf("Invalid option!\n");
        }
    } while (option != 0);

    return 0;
}