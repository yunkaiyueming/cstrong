##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=cstrong
ConfigurationName      :=Debug
WorkspacePath          :=E:/C/cdemo
ProjectPath            :=E:/C/cdemo/cstrong
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Rsy
Date                   :=2017/4/13
CodeLitePath           :=d:/CodeLite
LinkerName             :="d:/Haskell Platform/8.0.1/mingw/bin/g++.exe"
SharedObjectLinkerName :="d:/Haskell Platform/8.0.1/mingw/bin/g++.exe" -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g -fexec-charset=GBK -finput-charset=UTF-8
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c -fexec-charset=GBK -finput-charset=UTF-8
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="cstrong.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :="d:/Haskell Platform/8.0.1/mingw/bin/windres.exe"
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := "d:/Haskell Platform/8.0.1/mingw/bin/ar.exe" rcu
CXX      := "d:/Haskell Platform/8.0.1/mingw/bin/g++.exe"
CC       := "d:/Haskell Platform/8.0.1/mingw/bin/gcc.exe"
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall -fexec-charset=GBK $(Preprocessors)
ASFLAGS  := 
AS       := "d:/Haskell Platform/8.0.1/mingw/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=d:\CodeLite
Objects0=$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IntermediateDirectory)/src_input_input_1.c$(ObjectSuffix) $(IntermediateDirectory)/src_builtin_struct_hello_world.c$(ObjectSuffix) $(IntermediateDirectory)/src_builtin_struct_arr_test.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c $(IntermediateDirectory)/src_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/C/cdemo/cstrong/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(DependSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.c$(DependSuffix) -MM src/main.c

$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) src/main.c

$(IntermediateDirectory)/src_input_input_1.c$(ObjectSuffix): src/input/input_1.c $(IntermediateDirectory)/src_input_input_1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/C/cdemo/cstrong/src/input/input_1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_input_input_1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_input_input_1.c$(DependSuffix): src/input/input_1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_input_input_1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_input_input_1.c$(DependSuffix) -MM src/input/input_1.c

$(IntermediateDirectory)/src_input_input_1.c$(PreprocessSuffix): src/input/input_1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_input_input_1.c$(PreprocessSuffix) src/input/input_1.c

$(IntermediateDirectory)/src_builtin_struct_hello_world.c$(ObjectSuffix): src/builtin_struct/hello_world.c $(IntermediateDirectory)/src_builtin_struct_hello_world.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/C/cdemo/cstrong/src/builtin_struct/hello_world.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_builtin_struct_hello_world.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_builtin_struct_hello_world.c$(DependSuffix): src/builtin_struct/hello_world.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_builtin_struct_hello_world.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_builtin_struct_hello_world.c$(DependSuffix) -MM src/builtin_struct/hello_world.c

$(IntermediateDirectory)/src_builtin_struct_hello_world.c$(PreprocessSuffix): src/builtin_struct/hello_world.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_builtin_struct_hello_world.c$(PreprocessSuffix) src/builtin_struct/hello_world.c

$(IntermediateDirectory)/src_builtin_struct_arr_test.c$(ObjectSuffix): src/builtin_struct/arr_test.c $(IntermediateDirectory)/src_builtin_struct_arr_test.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/C/cdemo/cstrong/src/builtin_struct/arr_test.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_builtin_struct_arr_test.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_builtin_struct_arr_test.c$(DependSuffix): src/builtin_struct/arr_test.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_builtin_struct_arr_test.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_builtin_struct_arr_test.c$(DependSuffix) -MM src/builtin_struct/arr_test.c

$(IntermediateDirectory)/src_builtin_struct_arr_test.c$(PreprocessSuffix): src/builtin_struct/arr_test.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_builtin_struct_arr_test.c$(PreprocessSuffix) src/builtin_struct/arr_test.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


