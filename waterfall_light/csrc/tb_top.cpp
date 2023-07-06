#include "verilated.h"							//Verilator头文件包括常用API，routines
#include "verilated_vcd_c.h"				//VCD(value change dump),波形写入VCD
#include "Vtop.h"										//!!!!!!modify here!!!!!!!,Verilator转换后的模块顶层的头文件
#include <nvboard.h>
//#include "Vxxx___024unit.h"				//包含一些自定义数据类型typedef，并经过Verilator转换后的头文件
#include <stdlib.h>									//C++ standard library标准库头文件，里面定义了五种类型，一些宏和通用工具函数
#include <stdio.h>									//标准输入输出库，例如printf
#include <iostream>									//iostream库，输入输出流,例如<<
#include <assert.h>									//断言宏定义库
#include <time.h>


#define SIM_TIME 200000									//仿真总时钟边缘数

VerilatedContext* contextp = NULL;	//contextp变量声明，并为指针变量赋一个NULL值
VerilatedVcdC* tfp = NULL;					//tfp变量声明，并为指针变量赋一个NULL值
Vtop* top = NULL;										//顶层模块top变量声明，并为指针变量赋NULL值
//static TOP_NAME dut;

//#ifdef NVBOARD
void nvboard_bind_all_pins(Vtop* top);

void step_and_dump_wave(){
	top->clk = 0;
	top->eval();											//eval()函数更新top模块的所有信号状态，可以理解为仿真top模块中的所有信号
	tfp->dump(contextp->time());
	top->clk = 1;
	top->eval();	
	tfp->dump(contextp->time());			//将所追踪的信号并写入waveform dump文件
	contextp->timeInc(1);							//仿真时间（时钟边缘数）增加1

}

void sim_init(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;					//设置波形存储为vcd文件
	top = new Vtop;										//!!!!!!!modify here!!!!!!!!,例化转化后的top模块
	contextp->traceEverOn(true);
	top->trace(tfp, 5);								//将tfp传递给top，参数1(--trace-depth)表示跟踪深度限制再top的1级子模块
	tfp->open("waveform.vcd");
}

static void reset(int n) {
  top->rst = 1;
  while (n -- > 0) step_and_dump_wave();
  top->rst = 0;
}

void sim_exit(){
	step_and_dump_wave();
	tfp->close();
	delete top;
}

int main(int argc, char** argv, char** env){
	sim_init();

	nvboard_bind_all_pins(top);
	nvboard_init();
	reset(5);											//延迟十个时钟周期，看情况需要

	//对于时序逻辑，指定仿真时间不断更新状态
	while(contextp->time() < SIM_TIME && !contextp->gotFinish()){
	//while(true){
		//top->clk ^= 1;										//clk与1亦或，翻转时钟	
		nvboard_update();
		step_and_dump_wave();
    	
	}

	//对于组合逻辑，需要列出不同激励观察响应，下面的示例假设三输入
	//top->s=0; top->a=0; top->b=0; step_and_dump_wave();
	//top->s=0; top->a=0; top->b=1; step_and_dump_wave();
	//top->s=0; top->a=1; top->b=0; step_and_dump_wave();
	//top->s=0; top->a=1; top->b=1; step_and_dump_wave();
	//top->s=1; top->a=0; top->b=0; step_and_dump_wave();
	//top->s=1; top->a=0; top->b=1; step_and_dump_wave();
	//top->s=1; top->a=1; top->b=0; step_and_dump_wave();
	//top->s=1; top->a=1; top->b=1; step_and_dump_wave();
	
	//除了看波形，也可也选择通过断言来对输出结果进行检查
	//printf("a = %d, b = %d, s = %d\n", top->a, top->b, top->s);
	//assert(top->s == (top->a + top->b));

	sim_exit();
	nvboard_quit();
}
