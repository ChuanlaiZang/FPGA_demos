#Makefile template for Verilator
#Makefile template for NVBoard

#生成的可执行文件名称
#!!!!!!!修改这里!!!!!!!!
TOPNAME = top

#nvbroad约束文件
CONSTR = constr/top.nxdc


#构建目录、verilator目标目录、可执行文件存放路径
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

#新建构建build目录，防止出现无法新建autobind.cpp的错误
$(shell mkdir -p $(BUILD_DIR))

#在指定文件夹中按扩展名查找所有源文件
VSRC = $(shell find $(abspath ./vsrc) -name "*.v")
CSRC = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRC += $(SRC_AUTO_BIND)

#nvbroad自动绑定源文件，注意，如果没有$(BUILD_DIR)目录，将无法正确的生成该文件
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
#自动绑定文件，由于其被可执行文件依赖，会先生成该文件。
#调用python执行nvbroad自带的.py文件，输入约束文件，输出自动绑定文件
$(SRC_AUTO_BIND): $(CONSTR) 
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py  $^ $@


#传递给verilator的参数：以c++形式输出调试信息，并自动依据makefile进行构建
VERIARG = -Wall --cc -MMD --build -j 8 --trace
VERIAGE += -03 --x-assign fast --x-initial fast --noassert

#传递给preproject连接器的信息，添加SDL2库信息
LDFLAGS += -lSDL2 -lSDL2_image

#包含文件路径，加前缀-I传递给g++，INC_PATH在nvbroad.mk中定义
INCFLAGS = $(addprefix -I, $(INC_PATH))

#传递给g++的编译参数，包括包含路径和TOP_NAME的定义
CFLAGS += $(INCFLAGS)  -DTOP_NAME="\"V$(TOPNAME)\""

#包含nvbroad.mk, rule for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

#默认的构建对象
sim:  $(CSRC) $(VSRC) $(NVBOARD_ARCHIVE)
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
		$(addprefix -LDFLAGS , $(LDFLAGS)) \
		$(addprefix -CFLAGS , $(CFLAGS)) \
		--Mdir $(OBJ_DIR)  --exe -o $(abspath $(BIN)) \
	
	@echo
	@echo "### SIMULATING ###"
	$(BUILD_DIR)/$(TOPNAME) #+verilator+rand_reset+2
	#运行转译好的可执行文件进行仿真
	@echo "### FINISH: SIMULATE + TRACE GENERATE ###"


.PHONY: run
run:
	@echo
	@echo "### SHOW NVBoard ###"
	$(BIN)

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
