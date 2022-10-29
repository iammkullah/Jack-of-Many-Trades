	import java.util.*;
    class StackImpl {
	  public String infixToPostfix(String s) {
	    Stack<Character> st = new Stack<Character>();
	    String postfix = "";
	    char ch[] = s.toCharArray();
	    for(char c: ch) {
	        //1st condition
	      if(c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')'){
	          postfix = postfix + c;
	          } 
	       //2st condition
	      else if (c == '(') {
	          st.push(c);
	      } 
	       //3 condition
	      else if (c == ')') {
	        while(!st.isEmpty()) {
	          char t = st.pop();
	             if(t != '(') {
	            postfix = postfix + t;} 
	                 else {}
	             }}
	       //4 condition
	      else if(c == '+' ||c == '-' ||c == '*' ||c == '/') {
	           if(st.isEmpty()) {
	            st.push(c);
	        } 
	            else {
	            while(!st.isEmpty()) {
	            char t = st.pop();
	            
	            if(t == '(') {
	              st.push(t);
	              break;
	            } 
	      else if(t == '+' || t == '-' || t == '*' || t == '/') {
 	             if(getPriority(t) <  getPriority(c)) {
	                st.push(t);
	                break;
	              } else {
	                postfix = postfix + t;
	              }
	            }
	          }
	          st.push(c);
	        }
	      }
	    }
	    while(!st.isEmpty()) {
	      postfix = postfix + st.pop();
	    }
	    return postfix;
	  }
	  
	  public int getPriority(char c) {
	    if(c == '+' || c == '-') {
	      return 1;
	    } else {
	      return 2;
	    } 
	  }
	  
	}
	public class infixToPostfix {
    public static void main(String[] args) {
	    StackImpl a = new StackImpl();
  	    String s3 = a.infixToPostfix("A + B * C + D");
	    System.out.print(s3);
	    System.out.println();
	 }}
