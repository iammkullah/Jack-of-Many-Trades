`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:39:15 09/29/2022
// Design Name:   Com4BitUsing2BitCom
// Module Name:   E:/CE-7/Digital System Design - DSD/Lab/Xilinx Projects/Assign1/BbitComTest.v
// Project Name:  Assign1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Com4BitUsing2BitCom
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module BbitComTest;

	// Inputs
	reg [3:0] A;
	reg [3:0] B;

	// Outputs
	wire AgB;
	wire AlB;
	wire AeqB;

	// Instantiate the Unit Under Test (UUT)
	Com4BitUsing2BitCom uut (
		.AgB(AgB), 
		.AlB(AlB), 
		.AeqB(AeqB), 
		.A(A), 
		.B(B)
	);

	initial begin
		// Initialize Inputs
		A = 4'b0000;
		B = 4'b0000;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		
		// Initialize Inputs
		A = 4'b1111;
		B = 4'b1010;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		// Initialize Inputs
		A = 4'b0010;
		B = 4'b0111;

		// Wait 100 ns for global reset to finish
        
		// Add stimulus here

	end
      
endmodule

