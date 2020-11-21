# 线索二叉树

规定 
- 若无左子树, 令`lchild`指向其前驱结点；
- 若无右子树 , 令`rchild`指向其后继结点。  

二叉树的线索化

- 将二叉链表中的空指针改为指向前驱或后继的线索。而前驱或后继的信息只有在遍历时才能得到，因此线索化的实质就是遍历一次二叉树。  

# 中序线索二叉树
<img src="images/Tree/Threaded Binary Tree/01.png" alt="01" style="zoom:50%;" />

# 先序线索二叉树和后序线索二叉树
<img src="images/Tree/Threaded Binary Tree/02.png" alt="02" style="zoom: 67%;" />