#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode * m_pNext;
    /* data */
};

ListNode* FindKthToTail( ListNode * pListHead , unsigned int k);


int main()
{
    ListNode *head = NULL;
    ListNode *curren = NULL;
    ListNode *pre = NULL; 

    int N;
    int fnum;

    cin >> N;

    for(int i=0; i<N ;i++)
    {
        int t;
        cin >> t;
        curren = (ListNode* ) malloc(sizeof(ListNode));
        curren->m_nKey = t;
        curren->m_pNext =NULL; 
        if(head == NULL)
        {
            head = curren;
            pre = curren;
        }
        else
        {
            pre->m_pNext = curren;
            pre = curren;
        }
    }

    cin >> fnum;


    auto ans=FindKthToTail( head , fnum);

    if(ans != NULL)
        cout << ans->m_nKey << endl;
    else
    {
        cout << 0 << endl;
    }
    
    system("pause");

    return 0;
}



ListNode* FindKthToTail( ListNode * pListHead , unsigned int k)
{
    if(pListHead == NULL )
        return NULL;
    int count=0;

    ListNode *f = pListHead;
    ListNode *s = pListHead;

    while( f->m_pNext!=NULL )
    {
        f = f->m_pNext;
        ++count;
        if( count > k-1)
            s = s->m_pNext;
    }

    if( count < k)
        return NULL;
    else
    {
        return s;
    }    

}

