class RangeSearch{

		public: static int height(struct node *N)
		{
		    if (N == NULL)
			return 0;
		    return N->height;
		}

		/** A utility function to get maximum of two integers
		 */
		static int max(int a, int b)
		{
		    return (a > b)? a : b;
		}

		/** Helper function that allocates a new node with the given key and
		 NULL left and right pointers. */
		static struct node* newNode(int key)
		{
		    struct node* node = (struct node*)
		    malloc(sizeof(struct node));
		    node->key   = key;
		    node->Llink  = NULL;
		    node->Rlink  = NULL;
		    node->height = 1;  // new node is initially added at leaf
		    node->parent = NULL;
		    return(node);
		}

		/**A utility function to right rotate subtree rooted with y
		 */
		static struct node * rightRotate(struct node *y)
		{
		    struct node *x = y->Llink;
		    struct node *T2 = x->Rlink;
		    
		    // Perform rotation
		    x->Rlink = y;
		    y->Llink = T2;
		    
		    // Update heights
		    y->height = max(height(y->Llink), height(y->Rlink))+1;
		    x->height = max(height(x->Llink), height(x->Rlink))+1;
		    
		    // Return new root
		    return x;
		}

		/**A utility function to left rotate subtree rooted with x
		 */
		static struct node * leftRotate(struct node *x)
		{
		    struct node *y = x->Rlink;
		    struct node *T2 = y->Llink;
		    
		    // Perform rotation
		    y->Llink = x;
		    x->Rlink = T2;
		    
		    //  Update heights
		    x->height = max(height(x->Llink), height(x->Rlink))+1;
		    y->height = max(height(y->Llink), height(y->Rlink))+1;
		    
		    // Return new root
		    return y;
		}

		/** Get Balance factor of node N
		 */
		static int getBalance(struct node *N)
		{
		    if (N == NULL)
			return 0;
		    return height(N->Llink) - height(N->Rlink);
		}

		static struct node* insert(struct node* node, int key)
		{
		    /* 1.  Perform the normal BST rotation */
		    if (node == NULL)
			return(newNode(key));
		    
		    if (key < node->key)
			node->Llink  = insert(node->Llink, key);
		    else
			node->Rlink = insert(node->Rlink, key);

		    /*node->height = max(height(node->left), height(node->right)) + 1;
		    
		    

		    int balance = getBalance(node);
		    
		   
		    if (balance > 1 && key < node->left->key)
			return rightRotate(node);
		    
		   
		    if (balance < -1 && key > node->right->key)
			return leftRotate(node);
		    
		   
		    if (balance > 1 && key > node->left->key)
		    {
			node->left =  leftRotate(node->left);
			return rightRotate(node);
		    }
		    
		   
		    if (balance < -1 && key < node->right->key)
		    {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		    }*/
		    
		    
		    node->thread = false;
		    return node;
		}
		static void inorder(nd *n){
		    if(n==NULL) return;
		    inorder(n->Llink);
		    inorder(n->Rlink);
		    printf("%d ",n->key);
		}
		static int leaf(nd *t){
		    if(t->Llink==NULL&&t->Rlink==NULL) return 1;
		    return 0;
		}
		static nd * find_sv(nd * root,int x,int y){
		    nd* t= root;
		    while(!leaf(t)&&(t->key<x||t->key>y)){
			if(t->key>y) t=t->Llink;
			else t=t->Rlink;
		    }
		    return t;
		}
		static void rsearch(nd * root,int x,int y){
		    nd *sp = RangeSearch::find_sv(root,x,y);
		    nd *t = sp->Llink;
		    if(leaf(sp)){
			if(sp->key>=x&&sp->key<=y) printf("%d ",sp->key);
		    }
		    else{
			while(t!=NULL){
			    if(t->key>=x){
				printf("%d ",t->key);
				inorder(t->Rlink);
				t=t->Llink;
			    }
			    else t=t->Rlink;
			}
			printf("%d ",sp->key);
			t = sp->Rlink;
			while(t!=NULL){
			    if(t->key<=y){
				printf("%d ",t->key);
				inorder(t->Llink);
				t=t->Rlink;
			    }
			    else t=t->Llink;
			}
		    }
		}
};

