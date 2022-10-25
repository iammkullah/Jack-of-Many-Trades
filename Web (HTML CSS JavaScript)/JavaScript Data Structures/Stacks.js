/**
 * Implemented Stack using JavaScript without Built-in Stack Class
 * 
 * By Taimoor Khan 
 * 
 * Contribute More to make it better 
 * PS: Please Add Comments to make it more understandable and ADD YOUR nAME IN File Header
 */
Stack = function () { 
  //Creating Stack
  this.count = 0;
  this.data = {};

/**
 * Push and  Pop Functions
 */
  this.push = function (value) { 
    this.data[this.count] = value;
    this.count++;
  };
  this.pop = function () {
    // if Condition to check if Stack is Empty if yes then return Stack is Empty
    if (this.count == 0) {
      return "Stack is Empty";
    }
    // other wise decrease the count and return the value
    this.count--;
    var result = this.data[this.count];
    delete this.data[this.count];
    return result;
  }
  //  Checking Length/Size of Stack 
  this.size = function () {
     // if Condition to check if Stack is Empty if yes then return Stack is Empty
    if (this.count == 0) {
      return "Stack is Empty";
    }
    return this.count;
  };

}