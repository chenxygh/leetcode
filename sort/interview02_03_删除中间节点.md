# interview02_03_删除中间节点

---

实现一种算法，删除单向链表中间的某个节点（除了第一个和最后一个节点，不一定是中间节点），假定你只能访问该节点。

 

示例：

输入：单向链表a->b->c->d->e->f中的节点c
结果：不返回任何数据，但该链表变为a->b->d->e->f


解题思路:

题目有歧义， 还以为删除中间节点

事实上， 一般的链表的删除或者插入操作， 要求获得前驱节点

当然， 也有直接访问该节点， 无须前驱节点辅助的方法

对于插入:
p 为当前节点， q 为插入节点， 插入 p 之前
则， 
```
    q->next = p->next;
    p->next = q;
    int temp = p->val;
    p->val = q->val;
    q->val = temp;
```

对于删除:
p 为当前节点
则， 
```
    q = p->next;
    p->val = q->val;
    p->next = q->next;
    free(q);
```

注意， 无须前驱的这种删除方式， 要求复制后继节点的值， 而尾无后继， 所以 p 不可以为尾节点


[src](https://leetcode-cn.com/problems/delete-middle-node-lcci/) <br>
[code](code/interview02_03.c) <br>
