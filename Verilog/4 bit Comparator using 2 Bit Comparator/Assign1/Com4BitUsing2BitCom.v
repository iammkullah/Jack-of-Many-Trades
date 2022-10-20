`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Comsats University, Attock Campus
// Engineer: Muhammad Kaleem Ullah
// 
// Create Date:    23:17:10 09/29/2022 
// Design Name: 
// Module Name:    Com4BitUsing2BitCom 
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
module Com4BitUsing2BitCom(AgB, AlB, AeqB, A, B);
input [3:0]A, B;
output AgB, AlB, AeqB;

wire AgB1w, AlB1w, AeqB1w;
wire AgB2w, AlB2w, AeqB2w;
wire w1, w2;

Com2Bit Com2Bit1(AgB1w, AlB1w, AeqB1w, A[1:0], B[1:0]), Com2Bit2(AgB2w, AlB2w, AeqB2w, A[3:2], B[3:2]);
and AgBA1(w1, AeqB1w, AgB2w), AgBA2(w2, AeqB1w, AlB2w), AgBA3(AeqB, AeqB1w, AeqB2w);
or AgBo1(AgB, w1, AgB1w), AgB02(AlB, w2, AlB1w);

endmodule
