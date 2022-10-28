`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:50:20 01/15/2022 
// Design Name: 
// Module Name:    Moore_4 
// Project Name: 
// Target Devices: 
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
module Moore_4(Clk,Rst,Input,Output);
input Clk,Rst,Input;
output reg Output;

parameter
State_1=3'b000,
State_2=3'b001,
State_3=3'b010,
State_4=3'b011,
State_5=3'b100;

reg[2:0] CS,NX;

always @ (Clk)        //Starter Loop
begin 
	if(Rst==1)
	CS<=State_1;
	else
	CS<=NX;
end

always @ (CS,Input)
begin
	case(CS)
	
State_1:    //State_1
			begin
			if(Input==1)
			NX<=State_2;
			else
			NX<=State_1;
			end

State_2:   //State_2
			begin
			if(Input==1)
			NX<=State_2;
			else
			NX<=State_3;
			end

State_3:    //State_3
			begin
			if(Input==1)
			NX<=State_4;
			else
			NX<=State_1;
			end

State_4:   //State_4
			begin
			if(Input==1)
			NX<=State_5;
			else
			NX<=State_3;
			end

State_5:   //State_5
			begin
			if(Input==1)
			NX<=State_2;
			else
			NX<=State_3;
			end
endcase
end


always @(CS)
begin
	case(CS)
	State_1:Output<=0;
	State_2:Output<=0;
	State_3:Output<=0;
	State_4:Output<=0;
	State_5:Output<=1;
	default:  Output<=0;
	endcase
end

endmodule
