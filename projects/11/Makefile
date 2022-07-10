# (1)コンパイラ
#CC  = g++-11
CC  = g++
# (2)コンパイルオプション
CFLAGS    = -D_GLIBCXX_DEBUG -ftrapv -std=c++17 -Wall -Wextra -g
#CFLAGS    = -std=c++11
# (3)実行ファイル名
TARGET  = VMtranslator
# (4)コンパイル対象のソースコード
SRCS    = CompilationEngine.cpp JackTokenizer.cpp JackAnalyzer.cpp SymbolTable.cpp VMWriter.cpp
# (5)オブジェクトファイル名
OBJS    = $(SRCS:.cpp=.o)

all: $(TARGET)

# (9)ターゲットファイル生成
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)

# (10)オブジェクトファイル生成
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)

# (12).oファイル、実行ファイル、.dファイルを削除
clean:
	-rm -f $(OBJS) $(TARGET) *.d
