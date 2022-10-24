`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Comsats University, Attock Campus
// Engineer: Muhammad Kaleem Ullah
// 
// Create Date:    22:20:03 05/12/2022 
// Design Name:    Lab1
// Module Name:    andGate 
// Project Name:   Digital System Design 
// Target Devices: Spartan6
// Tool versions:  
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module andGate(c, a, b);

input a,b;
output c;

// and function where c is the output, a, b input 
and(c,a,b);

endmodule
