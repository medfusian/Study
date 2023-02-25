#include <iostream>

using namespace std;

struct node {
    int inf; 
    node* left, * right;
}*tree = NULL;

void tree_pram_obxod(node* tree, int*mas1)
{
    if (tree != NULL) {
        cout << mas1[tree->inf-1] << "  ";
        tree_pram_obxod(tree->left, mas1);
        tree_pram_obxod(tree->right, mas1);
    }
}

void tree_obr_obxod(node* tree, int* mas1)
{
    if (tree != NULL) {
        tree_obr_obxod(tree->left, mas1);
        tree_obr_obxod(tree->right, mas1); 
        cout << mas1[tree->inf-1] << "  "; 
    }
}

void tree_sim_obxod(node* tree, int*mas1) { 
    if (tree != NULL) { 
        tree_sim_obxod(tree->left, mas1);
        cout << mas1[tree->inf-1] << "  "; 
        tree_sim_obxod(tree->right, mas1); 
    }
}

void print_Tree(node* p, int level, int* mas1)
{
    if (p)
    {
        print_Tree(p->left, level + 1, mas1);
        for (int i = 0; i < level; i++) cout << "   ";
        cout << mas1[p->inf-1] << endl;
        print_Tree(p->right, level + 1, mas1);
    }
}

node* addtree(int L, int R, int* mas) {
    int m; node* tree;
    if (L > R) return NULL;
    m = (L + R) / 2;
    tree = new node;
    tree->inf = mas[m-1];
    tree->left = addtree(L, m - 1, mas);
    tree->right = addtree(m + 1, R, mas);
    return tree;
}

node* delete_node(node* tree, int val)
{
    if (tree == NULL)
        return tree;
    if (val == tree->inf) {
        node* tmp;
        if (tree->right == NULL)
            tmp = tree->left;
        else {
            node* ptr = tree->right;
            if (ptr->left == NULL) {
                ptr->left = tree->left;
                tmp = ptr;
            }
            else {
                node* pmin = ptr->left;
                while (pmin->left != NULL) {
                    ptr = pmin;
                    pmin = ptr->left;
                }
                ptr->left = pmin->right;
                pmin->left = tree->left;
                pmin->right = tree->right;
                tmp = pmin;
            }
        }
        delete tree;
        return tmp;
    }
    else if (val < tree->inf)
        tree->left = delete_node(tree->left, val);
    else
        tree->right = delete_node(tree->right, val);
    return tree;
}

void ClearNode(node* tree) {
    if (tree != NULL) {
        if (tree->left != NULL)
            ClearNode(tree->left);
        if (tree->right != NULL)
            ClearNode(tree->right);
        delete tree;
    }
}

int main()
{
    int n, x;
    cout << "Vvedite kolichestvo uzlov: "; cin >> n;
    int *mas = new int[n];
    int* mas1 = new int[n];
    for (int i = 0; i < n; i++) mas[i] = i + 1;

    cout << "Vvedite elementi: ";
    for (int i = 0; i < n; i++) cin >> mas1[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mas1[i] < mas1[j]) swap(mas1[i], mas1[j]);
        }
    }

    for (int i = 0; i < n; i++)
        tree = addtree(mas[0], n, mas);

    cout << "Derevo:" << endl;
    print_Tree(tree, 5, mas1); cout << endl;

    cout << "Pramoy obxod:         ";
    tree_pram_obxod(tree, mas1); cout << endl;
    cout << "Obratniy obxod:       ";
    tree_obr_obxod(tree, mas1); cout << endl;
    cout << "Simmetrichniy obxod:  ";
    tree_sim_obxod(tree, mas1); cout << endl << endl;

    int val; cout << "Vvedite elem dla udalenia: "; cin >> val;
    for (int i = 0; i < n; i++) if (mas1[i] == val) val = i+1;
    delete_node(tree, val);

    cout << "Derevo:" << endl;
    print_Tree(tree, n-1, mas1); cout << endl;

    tree_sim_obxod(tree, mas1);
    ClearNode(tree);
    delete[] mas;
    delete[] mas1;
    return 0;
}