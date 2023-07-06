
module sub 
#( parameter WIDTH = 32)
(
    input ci,                   //
    input [WIDTH-1:0] a, 
    input [WIDTH-1:0] b,
    output [WIDTH-1:0] sub,
    output co                   //
 ); 
    
    wire [WIDTH-1:0] com_b;     //
    assign com_b = ~b + 1;      // 
    assign com_ci = {WIDTH {ci}};
    // com_ci = ~{(WIDTH-1){1’b0}, ci} + 1
    // 如果ci==0;      com_ci =  {WIDTH-1{1’b1}, 1’b1} + 1 = {WIDTH{1’b1}} + 1 = {WIDTH{1’b0}} = {WIDTH{ci}};
    // 如果ci==1’b1;   com_ci =  {WIDTH-1{1’b1}, 1’b0} + 1 = {WIDTH{1’b1}} = {WIDTH{ci}};
    
    // 全减器采用补码的方式实现，二进制补码对变量取反加一
    // a-b-ci 取补码之后， a + com_b + com_ci
    assign {co, sub} = a + com_b + com_ci;
 endmodule