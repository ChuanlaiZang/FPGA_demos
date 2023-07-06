`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/14 14:58:41
// Design Name: 
// Module Name: tb_led
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
`define clk_cycle 10

module tb_led();
    reg clk;
    reg rst;
    wire [15:0] ledr;
    reg [7:0] sw;
    
   always #`clk_cycle clk = ~clk;
   initial begin
        #20
        clk = 0;
        rst = 1;
        #20
        rst=0;
   end

    led led(
        .clk(clk),
        .rst(rst),
        .sw(sw),
        .ledr(ledr));
endmodule
