module dual_control_switch(
	input a,
	input b,
	output f
);
	assign f = a ^ b;
endmodule
