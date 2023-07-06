#Makefile template for Verilator
#Makefile template for NVBoard

#生成的可执行文件名称
#!!!!!!!修改这里!!!!!!!!
TOPNAME = top



#构建目录、verilator目标目录、可执行文件存放路径
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

#在指定文件夹中按扩展名查找所有源文件
VSRC = $(shell find $(abspath ./vsrc) -name "*.v")
CSRC = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
 
$(shell mkdir -p $(BUILD_DIR))

#传递给verilator的参数：以c++形式输出调试信息，并自动依据makefile进行构建
VERIARG = -Wall --cc -MMD --build -j 8 --trace
VERIAGE += -03 --x-assign fast --x-initial fast --noassert


include $(NVBOARD_HOME)/scripts/nvboard.mk

#默认的构建对象
sim:  $(CSRC) $(VSRC) 
#提交当前存储区，提交信息为sim RTL
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

#rules for verilator 	
#运行verilator，传递给其编译参数
#指定top模块名称
#添加所有源文件和nvbroad库
#传递所有preproject连接器参数，加前缀
#传递所有编译器参数，加前缀
#指定生成对象目录，生成可执行文件，输出路径为预先指定的可执行文件存储路径
	@echo
	@echo "### VERILATING ###"	
	
	verilator $(VERIARG) \
		-top $(TOPNAME) \
		$^ \
		--Mdir $(OBJ_DIR)  --exe -o $(abspath $(BIN))

	@echo
	@echo "### SIMULATING ###"
	$(BUILD_DIR)/$(TOPNAME) #+verilator+rand_reset+2
	#运行转译好的可执行文件进行仿真
	@echo "### FINISH: SIMULATE + TRACE GENERATE ###"

.PHONY: run
run:
	@echo
	@echo "### SHOW WAVES ###"
	$(BIN)
	#用NVBoard运行仿真文件

.PHONY: wave
wave:
	@echo
	@echo "### SHOW WAVES ###"
	gtkwave waveform.vcd #-a gtkwave_setup.gtkw
	#用gtkwave查看波形
	
.PHONY: clean	
clean:
	rm -rf $(BUILD_DIR)
	rm -rf waveform.vcd

.PHONY: default all clean run

include ../../Makefile

