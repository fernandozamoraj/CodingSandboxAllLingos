import java.lang.reflect.Constructor;

public class DequeProject {
  public static void main(String[] args) {
    System.out.println("Hello world!");
    Deque<Integer> deque = new Deque<Integer>(-1);

    deque.addFront(1);
    deque.addBack(2);
    deque.addBack(3);
    deque.addFront(0);
    print(deque);
    System.out.println("Removing: " + deque.removeFront());
      System.out.println("Removing: " + deque.removeBack());
    print(deque);
    System.out.println("Removing: " + deque.removeBack());
    System.out.println("Removing: " + deque.removeBack());
    print(deque);

  }

  static void print(Deque<Integer> dek){
    Node<Integer> current = dek.next(null);
    System.out.println("\n*****Deque********\n");
    while(current != null){
      System.out.print(" " + current.Data);
      current = dek.next(current);
    }
    System.out.println("\n");
  }

}

class Node<T>{
  public Node Left;
  public Node Right;
  public T Data;
  public Node(){
    Left = null;
    Right = null;
  }

  public Node(T data){
     Left = Right = null;
     Data = data;
  }
}

class Deque<T>{

  private Node<T> Head;
  private Node<T> Tail;

  private T defaultValue;

  public Deque(T defaultValue){
    this.defaultValue = defaultValue;
        
    Head = Tail = null;
  }

  public Node<T> next(Node<T> current){
    if(current == null){
      return Head;
    }
    return current.Right;
  }

  public void addFront(T data){
      if(Head == null){
        Head = new Node(data);
        Head.Right = Head.Left= null;
        Tail = Head;
      }
      else{
        Node temp = Head;
        Head.Left = new Node(data);
        Head = Head.Left;
        Head.Right = temp;
      }
  }

  public void addBack(T data){
      if(Tail == null){
        Tail = new Node(data);
        Tail.Left = Tail.Right = null;
        Head = Tail;
      }
      else{
        Node temp = Tail;
        Tail.Right = new Node(data);
        Tail = Tail.Right;
        Tail.Left = temp;
      }
  }

  public T removeFront(){
    if(Head != null){
      Node<T> temp = Head;
      Head = Head.Right;
      if(Head != null)
        Head.Left = null;
      else
        Head = Tail = null;
      return temp.Data;
    }
    return defaultValue;
  }

  public T removeBack(){
    if(Tail != null){
      Node<T> temp = Tail;
      Tail = Tail.Left;
      if(Tail != null)
        Tail.Right = null;
      else
        Head = Tail = null;
      return temp.Data;
    }
    return defaultValue;
  }
}
