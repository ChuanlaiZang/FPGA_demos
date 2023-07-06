module top(a,b,alu_sel,alu_out,carry_out);
    
    input [DATAWIDTH - 1:0] rs1, rs2;
    input [2:0] op;
    output [7:0] rd;
    output overflow;

    reg [DATAWIDTH - 1 : 0] rd;


    parameter DATAWIDTH = 8;

    wire signed [ DATAWIDTH - 1 :0 ] signed_rs1;
    wire signed [ DATAWIDTH - 1 :0 ] signed_rs2;
    reg [63:0] rs_sra;

    reg [32:0] rdata;

    assign rd = rdata[31:0];

    assign signed_rs1 = rs1;
    assign signed_rs2 = rs2;
    assign overflow = rdata[32];

    localparam ADD =    4'000;
    localparam SUB =    4'001;
    localparam NOT =    4'010;
    localparam AND =    4'011;
    localparam OR  =    4'100;
    localparam XOR =    4'101;
    localparam COMP =   4'110;
    localparam EQU =    4'111;
    
/*
`define A_NOP 5'd00 //nop
`define A_ADD 5'd01 //signed_add
`define A_SUB 5'd02 //signed_sub
`define A_AND 5'd03 //and
`define A_OR  5'd04 //or
`define A_XOR 5'd05 //xor
`define A_NOR 5'd06 //nor
`define A_ADDU 5'd07 //unsigned_add
`define A_SUBU 5'd08 //unsigned_sub
`define A_SLT 5'd09 //slt
`define A_SLTU 5'd10 //unsigned_slt
`define A_SLL 5'd11 //sll
`define A_SRL 5'd12 //srl
`define A_SRA 5'd13 //sra
`define A_MOV 5'd14 //movz,movn
`define A_LUI 5'd15 //lui

localparam SLL  = 4'b0001;//rd=rs1<<rs2
localparam SrL  = 4'b0010;//rd=rs1>>rs2
localparam SrA  = 4'b0011;//rd=rs1>>rs2(arithmetic)
localparam add  = 4'b0100;//rd=rs1+rs2
localparam Sub  = 4'b0101;//rd=rs1-rs2
localparam Lui  = 4'b0110;//rd={20 bit Imm,12'd0}
localparam Slt  = 4'b0111;//rd=(signed rs1 < signed rs2)?1:0
localparam Sltu = 4'b1000;//rd=(unsigned rs1 < unsigned rs2)?1:0
localparam Xor  = 4'b1001;//rd=rs1^rs2
localparam Or   = 4'b1010;//rd=rs1|rs2
localparam And  = 4'b1011;//rd=rs1&rs2
localparam Mul  = 4'b1100;//rd=(rs1*rs2)[31:0]

parameter       HLT  = 4'b0000,
                SKZ  = 4'b0001,
			    ADD  = 4'b0010,
			    SUB  = 4'b0011,
			    MUL  = 4'b0100,
			    OR   = 4'b0101,
			    AND  = 4'b0110,
			    XOR  = 4'b0111,
			    NOT  = 4'b1000,
			    STO  = 4'b1001,
			    LDA  = 4'b1010,
			    RL   = 4'b1011,
			    RR   = 4'b1100,
			    JMP  = 4'b1101,
			    POP  = 4'b1110,
			    PUSH = 4'b1111;
*/

always @(*) 

 		begin
 			case(op)
			SLL :		rdata = rs1 << rs2;
			SrL :		rdata = rs1 >> rs2[4:0];
			SrA :		if (rs1[31] == 1)
						 	begin
								rs_sra = {32'hffff_ffff,rs1[31:0]};
								rdata = rs_sra >> rs2[4:0];
							end
						else 
							begin
								rdata = rs1 >> rs2[4:0];
							end
			add :		rdata = rs1 + rs2;
			Sub :		rdata = rs1 - rs2;
			Lui :		rdata = { rs2[31:12],12'h000 };
			Slt :		rdata = ( signed_rs1 < signed_rs2 ) ? 1 : 0;
			Sltu: 		rdata = ( rs1 < rs2 ) ? 1 : 0;
			Xor :		rdata = rs1 ^ rs2;
			Or  :		rdata = rs1 | rs2;
			And :		rdata = rs1 & rs2;
			Mul :		rdata = rs1 * rs2;
			default:	rdata = rs1 + rs2;
			endcase
		end

/*
always @ (*)      
    case(ex_ir[15:11])
        `LOAD   : {cfout, ALUo} <= reg_A + reg_B;
        `STORE  : {cfout, ALUo} <= reg_A + reg_B;
        `LDIH   : {cfout, ALUo} <= reg_A + reg_B; 
        `ADD    : {cfout, ALUo} <= reg_A + reg_B;
        `ADDI   : {cfout, ALUo} <= reg_A + reg_B;
        `ADDC   : {cfout, ALUo} <= reg_A + reg_B + cfin;
        `SUB    : {cfout, ALUo} <= reg_A - reg_B;
        `SUBI   : {cfout, ALUo} <= reg_A - reg_B;
        `SUBC   : {cfout, ALUo} <= reg_A - reg_B - cfin;
        `CMP    : {cfout, ALUo} <= reg_A - reg_B;
        `AND    : {cfout, ALUo} <= reg_A & reg_B;
        `OR     : {cfout, ALUo} <= reg_A | reg_B;
        `XOR    : {cfout, ALUo} <= reg_A ^ reg_B;
        `SLL    : {cfout, ALUo} <= reg_A << reg_B[3:0];
        `SRL    : {cfout, ALUo} <= reg_A >> reg_B[3:0];
        `SLA    : {cfout, ALUo} <= $signed(reg_A) <<< reg_B[3:0];
        `SRA    : {cfout, ALUo} <= $signed(reg_A) >>> reg_B[3:0];
        `JMPR   : {cfout, ALUo} <= reg_A + reg_B;
        `BZ     : {cfout, ALUo} <= reg_A + reg_B;
        `BNZ    : {cfout, ALUo} <= reg_A + reg_B;
        `BN     : {cfout, ALUo} <= reg_A + reg_B;
        `BNN    : {cfout, ALUo} <= reg_A + reg_B;
        `BC     : {cfout, ALUo} <= reg_A + reg_B;
        `BNC    : {cfout, ALUo} <= reg_A + reg_B;
        default : {cfout, ALUo} <= {cfin, ALUi};
     endcase

always @(posedge alu_clk)
	begin
     casex(opcode)
	    HLT:  alu_out <= accum;
	    SKZ:  alu_out <= accum;
	    ADD:  alu_out <= data + accum;
	    SUB:  alu_out <= accum - data;
	    MUL:  alu_out <= accum * data;
	    OR :  alu_out <= accum | data;
	    AND: alu_out  <= data & accum;
	    XOR: alu_out  <= data ^ accum;
	    NOT: alu_out  <= ~ data;
	    LDA:  alu_out <= data;
	    STO:  alu_out <= accum;
	    RL :  alu_out <= data << 1;
	    RR :  alu_out <= data >> 1;
	    JMP:  alu_out <= accum;
	    POP:  alu_out <= spbuf;  
	    PUSH: spbuf <= accum;
	    default: alu_out <= 16'hxxxx;
	 endcase 
	end

   always @( * ) begin
      case ( ALUOp )
         `ALUOp_nop  :C=A;
         `ALUOp_lui  :C=B;
         `ALUOp_auipc:C=PC+B;
         
         `ALUOp_add:C=A+B;
         `ALUOp_sub:C=A-B;
         `ALUOp_xor:C=A^B;
         `ALUOp_or :C=A|B;
         `ALUOp_and:C=A&B;
         `ALUOp_sll:C=A<<B;
         `ALUOp_srl:C=A>>B;
         `ALUOp_sra:C=A>>>B;

         `ALUOp_bne :C={31'b0,(A==B)};
         `ALUOp_blt :C={31'b0,(A>=B)};
         `ALUOp_bge :C={31'b0,(A<B)};
         `ALUOp_bltu:C={31'b0,($unsigned(A)>=$unsigned(B))};
         `ALUOp_bgeu:C={31'b0,($unsigned(A)<$unsigned(B))};
         `ALUOp_slt :C={31'b0,(A<B)};
         `ALUOp_sltu:C={31'b0,($unsigned(A)<$unsigned(B))};
      endcase
   end
*/

// Determine the overflow and carry flags
always_comb begin
  V[0] = (A[3] == B[3]) && (A[3] != result[3]);
  V[1] = (A[3] != B[3]) && (A[3] == result[3]);
  carry = (result[3:0] != 0) && (result[3:0] + 1 == 16);
end

// Determine if the result is zero
always_comb begin
  zero = (result == 0);
end


endmodule


// 4-bit ALU with signed 2's complement representation
module ALU(
  input signed [3:0] A,
  input signed [3:0] B,
  input [2:0] op,
  output signed [3:0] R,
  output [1:0] V,
  output carry,
  output zero
);

// Internal wire to hold the result of the operation
wire signed [3:0] result;

// Determine the operation to perform
always_comb begin
  case (op)
    3'b000: result = A + B;
    3'b001: result = A - B;
    3'b010: result = A & B;
    3'b011: result = A | B;
    3'b100: result = A ^ B;
    default: result = 0;
  endcase
end

// Determine the overflow and carry flags
always_comb begin
  V[0] = (A[3] == B[3]) && (A[3] != result[3]);
  V[1] = (A[3] != B[3]) && (A[3] == result[3]);
  carry = (result[3:0] != 0) && (result[3:0] + 1 == 16);
end

// Determine if the result is zero
always_comb begin
  zero = (result == 0);
end

// Assign the output to the result of the operation
assign R = result;

endmodule