`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Comsats University, Attock Campus
// Engineer: Muhammad Kaleem Ullah
// 
// Create Date:    22:22:15 09/29/2022 
// Design Name: 
// Module Name:    Com2Bit 
// Project Name: 2 bit Comperator
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
module Com2Bit(AgB, AlB, AeqB, A, B);

input [1:0]A, B;
output AgB, AlB, AeqB;

wire A0n, A1n, B0n, B1n;

wire AgBw1, AgBw2, AgBw3;
wire AlBw1, AlBw2, AlBw3;
wire AeBw1, AeBw2, AeBw3, AeBw4;


not(Aon, A[0]);
not(A1n, A[1]);
not(Bon, B[0]);
not(B1n, B[1]);

and A1(AgBw1, A[1], B1n), A2(AgBw2, A[1], A[0],Bon), A3(AgBw3, A[0], B1n, Bon), A4(AlBw1, A1n, Aon, B[0]), A5(AlBw2, Aon, B[1], B[0]), A6(AlBw3, A1n, B[1]), A7(AeBw1, Aon, A1n, Bon, B1n), A8(AeBw2, A[0], A[1], B[0], B[1]), A9(AeBw3, A[1], Aon, B[1], Bon), A10(AeBw4, A1n, A[0], B[0], B1n); 

or O1(AgB, AgBw1, AgBw2, AgBw3), O2(AlB, AlBw1, AlBw2, AlBw3), O3(AeqB, AeBw1, AeBw2, AeBw3, AeBw4);

endmodule
