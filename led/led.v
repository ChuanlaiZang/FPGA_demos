module led(
	input clk,
	input rst,
	input [7:0] sw,
	output reg [15:0] ledr
);

	reg [31:0] count;
	reg [7:0] led;
	always @(posedge clk) begin
		if (rst) begin
			led <= 8'd1;
			count <= 0;
		end
		else begin
			if (count == 0)
				led <= {led[6:0], led[7]};
			count <= (count >= 5000 ? 32'b0 : count + 1);
			end
	end
	assign ledr = {led, sw};
endmodule

