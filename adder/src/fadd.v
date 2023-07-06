
module fadd
#(parameter WIDTH = 32)
(
    input ci,                   // 进位输入
    input [WIDTH-1:0] a,
    input [WIDTH-1:0] b
    output [WIDTH-1:0] sum,
    output co                   // 进位输出
);

    assign {co, sum} = a + b + ci;
endmodule
