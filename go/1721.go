// Swapping Nodes in a Linked List
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
package main

func swapNodes(head *ListNode, k int) *ListNode {
	var curNode, targetHead, targetTail *ListNode

	var cnt = 0
	var targetTailCnt = 0
	for curNode = head; curNode != nil; curNode = curNode.Next {
		cnt++
	}
	targetTailCnt = cnt - k + 1
	cnt = 0
	for curNode = head; curNode != nil; curNode = curNode.Next {
		cnt++
		if cnt == k {
			targetHead = curNode

		}
		if cnt == targetTailCnt {
			targetTail = curNode

		}
	}

	if targetHead == targetTail {
		return head
	}

	var temp int
	temp = targetHead.Val
	targetHead.Val = targetTail.Val
	targetTail.Val = temp
	return head

}
