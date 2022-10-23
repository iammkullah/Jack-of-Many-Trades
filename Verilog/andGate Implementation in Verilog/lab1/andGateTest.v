`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: Comsats University, Attock Campus
// Engineer: Muhammad Kaleem Ullah
//
// Create Date:   22:27:25 05/12/2022
// Design Name:   andGate
// Module Name:   C:/Users/Student/Desktop/iammkullah -  DSD/lab1/andGateTest.v
// Project Name:  lab1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: andGate
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module andGateTest;

	// Inputs
	reg a;
	reg b;

	// Outputs
	wire c;

	// Instantiate the Unit Under Test (UUT)
	andGate uut (
		.c(c), 
		.a(a), 
		.b(b)
	);

	initial begin
		// Initialize Inputs
		a = 0;
		b = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
        
		// Add stimulus here
		// Initialize Inputs
		a = 0;
		b = 1;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		
		// Initialize Inputs
		a = 1;
		b = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		// Initialize Inputs
		a = 1;
		b = 1;

		// Wait 100 ns for global reset to finish
		// #100;
        
	end
      
endmodule

