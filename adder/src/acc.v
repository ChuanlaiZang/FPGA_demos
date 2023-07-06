// 累加器

module acc # 
    (
        parameter width = 32,           // 32bits 累加器
        parameter len = 16
    )
    (
        input rst,
        input clk,
        input start,
        input data_rdy,
        input [width-1:0] indata,
        output reg [width+$clog2(len)-1:0] outdata,
        output reg cal_done
    );  
    reg [width-1:0] indata_r;
    reg [$clog2(len)-1:0] num;
    reg [1:0] st;
    reg data_rdy_r; 
    always@(posedge clk or posedge rst)
        if(rst) begin
            indata_r <= 0;
            data_rdy_r <= 0;
        end
        else begin
            data_rdy_r <= data_rdy;
            indata_r <= indata;
        end 
    always@(posedge clk or posedge rst)
        if(rst) begin
            outdata <= 0;
            num <= len;
            cal_done <= 1'b0;
            st <= 0;
        end
    else case(st)
    0:begin
    outdata <= 0;
    num <= len;
    cal_done <= 1'b0;   
    if(start)
    st <=1;

    1:begin
    if(data_rdy_r)begin
    outdata <= outdata + indata_r;
    num <= num - 1;
    end 
    if(num == 0) begin
    st <= 2;
    end
    end
    2:begin
    cal_done <= 1'b1;
    st <= 0;
    end
    default: st = 0;
    endcase 
endmodule