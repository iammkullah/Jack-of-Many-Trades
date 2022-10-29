`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:06:59 01/15/2022
// Design Name:   Moore_4
// Module Name:   E:/Xilinx/Moore_4Bit/TestMoore_4.v
// Project Name:  Moore_4Bit
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Moore_4
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TestMoore_4;

	// Inputs
	reg Clk;
	reg Rst;
	reg Input;

	// Outputs
	wire Output;

	// Instantiate the Unit Under Test (UUT)
	Moore_4 uut (
		.Clk(Clk), 
		.Rst(Rst), 
		.Input(Input), 
		.Output(Output)
	);
	
	always #30 Clk=~Clk;

	initial begin
		// Initialize Inputs
		Clk = 0;
		Rst = 0;
		Input = 0;
		#30;
		Rst=1;
		#30;
		Rst=0;
		Input=0;
		#30;
		Input=0;
		#30;
		Input=1;
		#30;
		Input=0;
		#30;
		Input=1;
		#30;
		Input=1;
		#30;
		Input=0;
		#30;
		Input=0;
		#30;
		Input=1;
		#30;
		Input=0;
		#30;
		Input=1;
		#30;
		Input=1;
		#30;
		Input=0;
		#30;
		Input=0;
		#30;
		Input=1;
		#30;
		Input=1;
		#30;
		Input=1;
		#30;
		Input=0;
		#30;
		Input=0;
		#30;
		Input=1;
		#30;
		Input=0;
		#30;
		Input=1;
		#30;
		Input=1;
		#30;
		Input=0;
		
        
		// Add stimulus here

	end
endmodule

