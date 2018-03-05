#include <iostream>

using namespace std;

struct Node
{
        int data;
        Node *left;
        Node *right;
};

void Menu()
{
        cout << "Operations:" << endl;
        cout << "1. To show the Tree" << endl;
        cout << "2. To show list of nodes" << endl;
        cout << "3. To add" << endl;
        cout << "4. To delete" << endl;
        cout << "5. To save" << endl;
        cout << "6. To download" << endl;
        cout << "7. To check" << endl;
        cout << "8. To finish" << endl;
}

void Show(Node *&Tree)
{
        if (Tree != nullptr)
        {
                Show(Tree->left);
                cout << Tree->data << ' ';
                Show(Tree->right);
        }
}

void Clear(Node *&Tree)
{
        if (Tree != nullptr)
        {
                Clear(Tree->left);
                Clear(Tree->right);
                delete Tree;
                Tree = nullptr;
        }
}

void Add(int data, Node *&SoTree)
{
        if (nullptr == SoTree)
        {
                SoTree = new Node;
                SoTree->data = data;
                SoTree->left = SoTree->right = nullptr;
        }
        if (data < SoTree->data)
        {
                if (SoTree->left != nullptr)
                        Add(data, SoTree->left);
                else
                {
                        SoTree->left = new Node;
                        SoTree->left->left = SoTree->left->right = nullptr;
                        SoTree->left->data = data;
                }
        }
        if (data > SoTree->data)
        {
                if (SoTree->right != nullptr)
                        Add(data, SoTree->right);
                else
                {
                        SoTree->right = new Node;
                        SoTree->right->left = SoTree->right->right = nullptr;
                        SoTree->right->data = data;
                }
        }
}

int main(int argc, char *argv[])
{
        int *array = new int[argc - 1];
        for (int i = 1; i < argc; i++)
                array[i] = atoi(argv[i]);
        Node *Tree = nullptr;
        for (int i = 1; i < argc; i++)
                Add(array[i], Tree);
        Show(Tree);
        cout << '\n';
        Clear(Tree);
        return 0;
}
