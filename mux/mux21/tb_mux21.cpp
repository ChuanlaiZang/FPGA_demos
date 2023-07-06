#include "verilated.h"							//Verilator头文件包括常用API，routines
#include "verilated_vcd_c.h"				//VCD(value change dump),波形写入VCD
#include "obj_dir/Vmux21.h"										//modify here,Verilator转换后的模块顶层的头文件

//#include "Vmux21___024unit.h"				//包含一些自定义数据类型typedef，并经过Verilator转换后的头文件
//#include <stdlib.h>								//C++ standard library标准库头文件，里面定义了五种类型，一些宏和通用工具函数
//#include <iostream>								//iostream库，输入输出流,例如<<

#define SIM_TIME 20									//仿真总时钟边缘数

VerilatedContext* contextp = NULL;	//contextp变量声明，并为指针变量赋一个NULL值
VerilatedVcdC* tfp = NULL;					//tfp变量声明，并为指针变量赋一个NULL值
Vmux21* top =NULL;

void step_and_dump_wave(){
	top->eval();											//eval()函数更新top模块的所有信号状态，可以理解为仿真top模块中的所有信号
	contextp->timeInc(1);							//仿真时间（时钟边缘数）增加1
	tfp->dump(contextp->time());			//将所追踪的信号并写入waveform dump文件
}

void sim_init(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	top = new Vmux21;										
	contextp->traceEverOn(true);
	top->trace(tfp, 1);								//将tfp传递给top，参数1(--trace-depth)表示跟踪深度限制再top的1级子模块
	tfp->open("waveform.vcd");					//将tfp保存到"waveform.vcd"中
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
	//while(contextp->time() < SIM_TIME && !contextp->gotFinish()){
	//	step_and_dump_wave();
	//}


	//对于组合逻辑，需要列出不同激励观察响应，下面的示例假设三输入
	top->s=0; top->a=0; top->b=0; step_and_dump_wave();
	top->s=0; top->a=0; top->b=1; step_and_dump_wave();
	top->s=0; top->a=1; top->b=0; step_and_dump_wave();
	top->s=0; top->a=1; top->b=1; step_and_dump_wave();
	top->s=1; top->a=0; top->b=0; step_and_dump_wave();
	top->s=1; top->a=0; top->b=1; step_and_dump_wave();
	top->s=1; top->a=1; top->b=0; step_and_dump_wave();
	top->s=1; top->a=1; top->b=1; step_and_dump_wave();
	
	sim_exit();
}
