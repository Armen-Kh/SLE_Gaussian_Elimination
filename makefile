SOURCES = $(wildcard Sources/*.cpp)
HEADERS = $(patsubst Sources/%.cpp,Headers/%.hpp, $(SOURCES))

TARGET = Bin/solution.exe

$(TARGET) : $(SOURCES)
	@mkdir -pv Bin
	g++ $^ -o $@ -I Headers
