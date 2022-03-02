*
Name - Usha sree alekhya siddi

Roll no - 25062

Div - A

Batch - C
*/
#include<iostream>


using namespace std;

class TreeNode {
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode() {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};

class BST {
  public:
    TreeNode * root;
  BST() {
    root = NULL;
  }
  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }

  void insertNode(TreeNode * new_node) {
    if (root == NULL) {
      root = new_node;
      cout << "Value Inserted as root node!" << endl;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (new_node -> value == temp -> value) {
          cout << "Value Already exist," <<
            "Insert another value!" << endl;
          return;
        } else if ((new_node -> value < temp -> value) && (temp -> left == NULL)) {
          temp -> left = new_node;
          cout << "Value Inserted to the left!" << endl;
          break;
        } else if (new_node -> value < temp -> value) {
          temp = temp -> left;
        } else if ((new_node -> value > temp -> value) && (temp -> right == NULL)) {
          temp -> right = new_node;
          cout << "Value Inserted to the right!" << endl;
          break;
        } else {
          temp = temp -> right;
        }
      }
    }
  }
  

  
  void printPreorder(TreeNode * r) //(current node, Left, Right) 
  {
    if (r == NULL)
      return;
    /* first print data of node */
    cout << r -> value << " ";
    /* then recur on left sutree */
    printPreorder(r -> left);
    /* now recur on right subtree */
    printPreorder(r -> right);
  }

  void printInorder(TreeNode * r) //  (Left, current node, Right)
  {
    if (r == NULL)
      return;
    /* first recur on left child */
    printInorder(r -> left);
    /* then print the data of node */
    cout << r -> value << " ";
    /* now recur on right child */
    printInorder(r -> right);
  }
  void printPostorder(TreeNode * r) //(Left, Right, Root)
  {
    if (r == NULL)
      return;
    // first recur on left subtree 
    printPostorder(r -> left);
    // then recur on right subtree 
    printPostorder(r -> right);
    // now deal with the node 
    cout << r -> value << " ";
  }

  TreeNode * iterativeSearch(int v) {
    if (root == NULL) {
      return root;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> value) {
          return temp;
        } else if (v < temp -> value) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }
      }
      return NULL;
    }
  }

 

  int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      /* compute the height of each subtree */
      int lheight = height(r -> left);
      int rheight = height(r -> right);

      /* use the larger one */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }

  /* Print nodes at a given level */
  void printGivenLevel(TreeNode * r, int level) {
    if (r == NULL)
      return;
    else if (level == 0)
      cout << r -> value << " ";
    else // level > 0  
    {
      printGivenLevel(r -> left, level - 1);
      printGivenLevel(r -> right, level - 1);
    }
  }
  void printLevelOrderBFS(TreeNode * r) {
    int h = height(r);
    for (int i = 0; i <= h; i++)
      printGivenLevel(r, i);
  }

  TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }

  TreeNode * deleteNode(TreeNode * r, int v) {
    // base case 
    if (r == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    else if (v < r -> value) {
      r -> left = deleteNode(r -> left, v);
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (v > r -> value) {
      r -> right = deleteNode(r -> right, v);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
      // node with only one child or no child 
      if (r -> left == NULL) {
        TreeNode * temp = r -> right;
        delete r;
        return temp;
      } else if (r -> right == NULL) {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        TreeNode * temp = minValueNode(r -> right);
        // Copy the inorder successor's content to this node 
        r -> value = temp -> value;
        // Delete the inorder successor 
        r -> right = deleteNode(r -> right, temp -> value);
        //deleteNode(r->right, temp->value); 
      }
    }
    return r;
  }

};

int main()
{
    BST obj;
    int option, val;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Height of the tree is" << endl;
        cout << "6. leaf node of the tree " << endl;
        cout << "7. copy of the tree"<<endl;
        cout << "8. Display tree level wise" << endl;
        cout << "9. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        
        TreeNode *new_node = new TreeNode();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter the value to insert in BST :  ";
            cin >> val;
            new_node->value = val;

            obj.insertNode(new_node);
            cout << endl;
            break;

        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter the value that you want to search in the BST : ";
            cin >> val;
            new_node = obj.iterativeSearch(val);

            if (new_node != NULL)
            {
                cout << "Value found" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            cout << "Enter value that you want to delete from BST : ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node != NULL)
            {
                obj.deleteNode(obj.root, val);
                cout << "Value Deleted" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 4:

            cout << "PRE-ORDER: ";
            obj.printPreorder(obj.root);
            cout << endl;
            cout << "IN-ORDER: ";
            obj.printInorder(obj.root);
            cout << endl;
            cout << "POST-ORDER: ";
            obj.printPostorder(obj.root);
            break;

        case 5:
            cout << "TREE HEIGHT" << endl;
            cout << "Height of BST is : " << obj.height(obj.root) << endl;
            break;

        // case 6:
        // cout<<"leaf node :"<<obj.leafnode(obj.root)<<endl;
        
        case 7:
            cout<<"Copy of the tree is : "<<endl;
            cout << "PRE-ORDER: ";
            obj.printPreorder(obj.root);
            cout << endl;
            cout << "IN-ORDER: ";
            obj.printInorder(obj.root);
            cout << endl;
            cout << "POST-ORDER: ";
            obj.printPostorder(obj.root);
            break;

        case 8:
            cout << "Print Level Order BFS: \n";
            obj.printLevelOrderBFS(obj.root);
            cout << endl;
            break;

        case 9:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}

/*
output:-

What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
1
INSERT
Enter the value to insert in BST :  66
Value Inserted as root node!

What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
1
INSERT
Enter the value to insert in BST :  55
Value Inserted to the left!

What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
1
INSERT
Enter the value to insert in BST :  44
Value Inserted to the left!

What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
1
INSERT
Enter the value to insert in BST :  88
Value Inserted to the right!

What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
1
INSERT
Enter the value to insert in BST :  99
Value Inserted to the right!

What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
4
PRE-ORDER: 66 55 44 88 99 
IN-ORDER: 44 55 66 88 99 
POST-ORDER: 44 55 99 88 66 What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
2
SEARCH
Enter the value that you want to search in the BST : 66
Value found
What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
3
DELETE
Enter value that you want to delete from BST : 55
Value Deleted
What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
4
PRE-ORDER: 66 44 88 99 
IN-ORDER: 44 66 88 99 
POST-ORDER: 44 99 88 66 What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
5
TREE HEIGHT
Height of BST is : 2
What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
7
Copy of the tree is : 
PRE-ORDER: 66 44 88 99 
IN-ORDER: 44 66 88 99 
POST-ORDER: 44 99 88 66 What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
8
Print Level Order BFS: 
66 44 88 99 
What operation do you want to perform?  Select Option number. Enter 0 to exit.
1. Insert Node
2. Search Node
3. Delete Node
4. Print/Traversal BST values
5. Height of the tree is
6. leaf node of the tree 
7. copy of the tree
8. Display tree level wise
9. Clear Screen
0. Exit Program
0


...Program finished with exit code 0
Press ENTER to exit console.

*/