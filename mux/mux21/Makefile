#Makefile template for Verilator


TOP = mux21
all:sim
	@echo
	@echo "### simulating and generating the trace ###"
	@echo "### FINISH! ###"

sim: $(TOP).v tb_$(TOP).cpp
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo
	@echo "### VERILATING ###"
	verilator --cc --exe --build -j 8 --trace --Wall $(TOP).v tb_$(TOP).cpp
	#--cc:将v/sv转换为C++输出
	#--exe:根据后面指定的testbench生成用于仿真的可执行文件
	#-build:自己调用make
	#--trace:表示开启波形跟踪
	#--Wall:表示开启C++所有警告
	#-j 0:参数0表示用机器一样多的的CPU线程进行验证

	#上一步如果有bulid这里可以不用，但似乎有点问题	
	#@echo
	#@echo "### BUILDING SIM ###"
	#make -C obj_dir -f V$(TOP).mk V$(TOP)
	#-C:告诉make工作目录为obj_dir
	#-f:指定Makefile文件
	#V$(TOP):目标文件名，也就是编译生成的testbench可执行文件的名字

	@echo
	@echo "### SIMULATING ###"
	./obj_dir/V$(TOP) #+verilator+rand_reset+2
	#运行转译好的可执行文件进行仿真
	@echo "### FINISH: SIMULATE + TRACE GENERATE ###"

.PHONY:wave
wave:sim
	@echo
	@echo "### SHOW WAVES ###"
	gtkwave waveform.vcd -a gtkwave_setup.gtkw
	#用gtkwave查看波形
	
.PHONY: clean
clean:
	rm -rf ./obj_dir
	rm -rf waveform.vcd

include ../../../Makefile
