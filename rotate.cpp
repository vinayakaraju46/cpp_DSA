   /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) 
{
    if(B == 0)
    {
        return A;
    }
    ListNode *curr = A;
    ListNode *p=A;
    int count=0;
    int c=1;
    while(curr != NULL)
    {   count++;
        curr = curr->next;
        
    }
    if(count%B == 0)
    {
        return A;
    }
    else
    {
       while( c < (int)count/B && p!=NULL)
        {
            p = p->next;
            c++;
        }
        if(p == NULL)
        {
            return A;
        }
        
        
        ListNode *kthNode = p;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = A;
        A = kthNode->next;
        kthNode->next = NULL;
        
        
    }
        
    return A; 
    
}
