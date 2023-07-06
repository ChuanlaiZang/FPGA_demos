#include "verilated.h"							//Verilator头文件包括常用API，routines
#include "verilated_vcd_c.h"				//VCD(value change dump),波形写入VCD
#include "Vdual_control_switch.h"										//!!!!!!modify here!!!!!!!,Verilator转换后的模块顶层的头文件

//#include "Vxxx___024unit.h"				//包含一些自定义数据类型typedef，并经过Verilator转换后的头文件
#include <stdlib.h>									//C++ standard library标准库头文件，里面定义了五种类型，一些宏和通用工具函数
#include <stdio.h>									//标准输入输出库，例如printf
#include <iostream>									//iostream库，输入输出流,例如<<
#include <assert.h>									//断言宏定义库

#define SIM_TIME 20									//仿真总时钟边缘数

VerilatedContext* contextp = NULL;	//contextp变量声明，并为指针变量赋一个NULL值
VerilatedVcdC* tfp = NULL;					//tfp变量声明，并为指针变量赋一个NULL值
Vdual_control_switch* top = NULL;										//顶层模块top变量声明，并为指针变量赋NULL值

void step_and_dump_wave(){
	top->eval();											//eval()函数更新top模块的所有信号状态，可以理解为仿真top模块中的所有信号
	contextp->timeInc(1);							//仿真时间（时钟边缘数）增加1
	tfp->dump(contextp->time());			//将所追踪的信号并写入waveform dump文件
}

void sim_init(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;					//设置波形存储为vcd文件
	top = new Vdual_control_switch;										//!!!!!!!modify here!!!!!!!!,例化转化后的top模块
	contextp->traceEverOn(true);
	top->trace(tfp, 1);								//将tfp传递给top，参数1(--trace-depth)表示跟踪深度限制再top的1级子模块
	tfp->open("waveform.vcd");
}

void sim_exit(){
	step_and_dump_wave();
	tfp->close();
	delete top;
}

int main(int argc, char** argv, char** env){
	sim_init();

	//top->clk ^= 1;										//clk与1亦或，翻转时钟
	//对于时序逻辑，指定仿真时间不断更新状态
	while(contextp->time() < SIM_TIME && !contextp->gotFinish()){
		int a = rand() & 1;
		int b = rand() & 1;
		top->a = a;
		top->b = b;
		step_and_dump_wave();

		printf("a = %d, b = %d, f = %d\n", a, b, top->f);
		assert(top->f == (a ^ b));
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
}
