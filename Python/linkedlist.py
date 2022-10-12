#iterate the linklist in reverse manner 
def linklist(head):
    if head is None:
        return
    linklist(head.next)
    print(head.data)