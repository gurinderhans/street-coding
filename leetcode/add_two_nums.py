# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
  def addTwoNumbers(self, l1, l2):
    A=l1
    B=l2

    r=A.val+B.val
    carry = 1 if r>9 else 0
    res=ListNode(r%10)
    reshead=res
    A=A.next
    B=B.next

    while 1:
      if not any([A,B]):
        break

      r=((A and A.val) or 0) + ((B and B.val) or 0) + carry
      carry = 1 if r>9 else 0
      res.next = ListNode(r%10)
      
      res = res.next
      A=(A and A.next) or None
      B=(B and B.next) or None

    if carry == 1: # if there is still a carry that just gets added with 0
      res.next = ListNode(1)

    return reshead

a=ListNode(3)
a1=ListNode(2)
a2 = ListNode(7)
a3 = ListNode(8)
a.next=a1;a1.next=a2;a2.next=a3

b=ListNode(5)
b1=ListNode(3)
b2=ListNode(2)
b.next=b1;b1.next=b2

res=Solution().addTwoNumbers(a,b)
while res:
  print(res.val)
  res=res.next
