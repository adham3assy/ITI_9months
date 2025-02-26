class node:
    def __init__(self,id,name,position):
        self.id = id
        self.name = name
        self.position = position
        self.next = None

class Stack():
    def __init__(self):
        self.tos = None

    def Push(self,id,name,position):
        new_node = node(id,name,position)
        if self.tos == None:
            self.tos = new_node
        else:
            new_node.next = self.tos
            self.tos = new_node
    
    def Pop(self):
        if self.tos == None:
            print("The Stack is empty!")
        else:
            curr = self.tos
            self.tos = self.tos.next
            return curr
        

if __name__ == "__main__":
    ss = Stack()
    ss.Push(11,'Omar','developer')
    ss.Push(22,'yahia','Assistant')
    ss.Push(30,'Adham','CEO')
    ss.Push(50,'Shady','UI/UX')
    delet1 = ss.Pop() 
    print("Popped name :",delet1.name)
    print("Popped position :",delet1.position)
    print("Popped id :",delet1.id)
    