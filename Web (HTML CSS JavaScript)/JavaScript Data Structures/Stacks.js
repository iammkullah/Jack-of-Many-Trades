/**
 * Implemented Stack using JavaScript without Built-in Stack Class
 * 
 * By Taimoor Khan 
 * 
 * Contribute More to make it better 
 * PS: Please Add Comments to make it more understandable
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
  

}