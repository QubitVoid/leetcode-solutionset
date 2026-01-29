#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };


struct ListNode* mergeInBetween(struct ListNode* list1,
								int a, int b,
								struct ListNode* list2)
{
	struct ListNode *l1 = list1;
	struct ListNode *l2 = list2;
	struct ListNode *entryNode = list1;
	struct ListNode *exitNode;
	bool removed = false;

	for (int i=0; l1 != NULL; i++) {
		if (i+1 == a) {
			entryNode = l1;
		} else if (i >= a && i <= b) {
			struct ListNode *tmp = l1->next;
			free(l1);
			l1 = tmp;
			exitNode = l1;
			removed = true;
			continue;
		}

		if (removed) break;

		l1 = l1->next;
	}

	entryNode->next = list2;
	while (l2 != NULL) {
		if (!(entryNode && exitNode)) break;
		
		if (l2->next == NULL) {
			l2->next = exitNode;
			break;
		}

		l2 = l2->next;
	}

	return list1;
}
